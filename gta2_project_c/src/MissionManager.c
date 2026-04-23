/**
 * @file MissionManager.c
 * @brief Реализация менеджера миссий GTA 2
 * 
 * Размер структуры: 0xC1EA8 (793,768 байт)
 * Адрес глобального экземпляра: 0x006644BC
 */

#include "MissionManager.h"
#include <string.h>
#include <stdlib.h>

// Глобальный экземпляр менеджера миссий
MissionManager gMissionManager;
MissionManager* pMissionManager = &gMissionManager;

// ============================================================================
// ВНУТРЕННИЕ ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ
// ============================================================================

/**
 * @brief Внутренняя функция очистки пула объектов
 */
static void ClearObjectPool(MissionManager* self) {
    for (int i = 0; i < MAX_MISSION_OBJECTS; i++) {
        self->objects_pool[i].type = MISSION_OBJ_NONE;
        self->objects_pool[i].is_active = 0;
        self->objects_pool[i].flags = 0;
    }
}

/**
 * @brief Внутренняя функция очистки пула триггеров
 */
static void ClearTriggerPool(MissionManager* self) {
    for (int i = 0; i < MAX_MISSION_TRIGGERS; i++) {
        self->triggers_pool[i].type = TRIGGER_NONE;
        self->triggers_pool[i].state = 0;
    }
}

/**
 * @brief Проверка границ индекса объекта
 */
static int IsValidObjectIndex(MissionManager* self, uint32_t index) {
    return (index < MAX_MISSION_OBJECTS && self->objects_pool[index].type != MISSION_OBJ_NONE);
}

/**
 * @brief Проверка границ индекса триггера
 */
static int IsValidTriggerIndex(MissionManager* self, uint32_t index) {
    return (index < MAX_MISSION_TRIGGERS && self->triggers_pool[index].type != TRIGGER_NONE);
}

// ============================================================================
// ИНИЦИАЛИЗАЦИЯ И ЖИЗНЕННЫЙ ЦИКЛ
// ============================================================================

void MissionManager__Constructor(MissionManager* self) {
    if (!self) return;
    
    // Полное обнуление структуры
    memset(self, 0, sizeof(MissionManager));
    
    // Установка начального состояния
    self->state = MISSION_STATE_UNLOADED;
    self->current_mission_id = 0xFFFFFFFF;
    self->mission_status = 0;
    
    // Инициализация указателей
    self->script_buffer_ptr = NULL;
    self->script_size = 0;
    self->script_cursor = 0;
    
    // Очистка пулов
    ClearObjectPool(self);
    ClearTriggerPool(self);
    
    // Инициализация путей пустыми строками
    self->current_script_path[0] = '\0';
    self->save_file_path[0] = '\0';
}

void MissionManager__Destructor(MissionManager* self) {
    if (!self) return;
    
    // Освобождение буфера скрипта если выделен
    if (self->script_buffer_ptr) {
        free(self->script_buffer_ptr);
        self->script_buffer_ptr = NULL;
    }
    
    // Сброс состояния
    self->state = MISSION_STATE_UNLOADED;
    self->script_size = 0;
    self->script_cursor = 0;
    
    // Очистка пулов
    ClearObjectPool(self);
    ClearTriggerPool(self);
}

void MissionManager__Reset(MissionManager* self) {
    if (!self) return;
    
    // Сброс состояния миссии, но не освобождение глобальных ресурсов
    self->state = MISSION_STATE_IDLE;
    self->current_mission_id = 0xFFFFFFFF;
    self->mission_status = 0;
    self->total_objectives = 0;
    self->completed_objectives = 0;
    
    // Сброс курсора скрипта
    self->script_cursor = 0;
    
    // Сброс таймеров
    self->timer_main = 0;
    self->timer_secondary = 0;
    
    // Сброс наград
    self->reward_money = 0.0f;
    self->reward_respect = 0;
    
    // Очистка флагов целей
    memset(self->objectives_flags, 0, sizeof(self->objectives_flags));
    
    // Очистка пулов
    ClearObjectPool(self);
    ClearTriggerPool(self);
}

// ============================================================================
// УПРАВЛЕНИЕ ПОТОКОМ МИССИИ
// ============================================================================

int32_t MissionManager__StartMission(MissionManager* self, uint32_t missionId) {
    if (!self) return -1;
    
    // Если уже запущена миссия - прерываем её
    if (self->state == MISSION_STATE_RUNNING) {
        MissionManager__AbortMission(self);
    }
    
    // Установка ID миссии
    self->current_mission_id = missionId;
    
    // Формирование имени файла скрипта (например, "mission_05.scr")
    char scriptName[64];
    snprintf(scriptName, sizeof(scriptName), "mission_%02d.scr", missionId);
    
    // Загрузка скрипта
    if (MissionManager__LoadScript(self, scriptName) != 0) {
        return -1; // Ошибка загрузки
    }
    
    // Сброс прогресса
    MissionManager__ResetProgress(self);
    
    // Переход в состояние выполнения
    self->state = MISSION_STATE_RUNNING;
    
    // Спавн стартовых объектов
    MissionManager__SpawnScriptObjects(self);
    
    return 0;
}

void MissionManager__EndMission(MissionManager* self, int32_t result) {
    if (!self) return;
    
    // Остановка скрипта
    self->script_cursor = self->script_size;
    
    if (result == 1) { // Успех
        self->mission_status = 1;
        
        // Выдача награды
        MissionManager__GiveReward(self);
        
        // Сохранение прогресса
        MissionManager__SaveFile(self);
        
        // TODO: Показать сообщение об успехе
    } else { // Провал
        self->mission_status = 2;
        
        // Сброс наград
        self->reward_money = 0.0f;
        self->reward_respect = 0;
        
        // TODO: Показать сообщение о провале
    }
    
    // Переход в завершенное состояние
    self->state = MISSION_STATE_ENDED;
}

void MissionManager__FailMission(MissionManager* self) {
    MissionManager__EndMission(self, 0);
}

void MissionManager__AbortMission(MissionManager* self) {
    if (!self) return;
    
    // Деспавн всех объектов миссии
    for (uint32_t i = 0; i < MAX_MISSION_OBJECTS; i++) {
        if (self->objects_pool[i].is_active) {
            MissionManager__DespawnObject(self, i);
        }
    }
    
    // Сброс состояния
    self->state = MISSION_STATE_IDLE;
    self->mission_status = 0;
}

void MissionManager__Update(MissionManager* self) {
    if (!self || self->state != MISSION_STATE_RUNNING) return;
    
    // Инкремент таймеров
    self->timer_main++;
    self->timer_secondary++;
    
    // Обработка команд скрипта
    MissionManager__ParseScriptCommand(self);
    
    // Проверка целей
    MissionManager__CheckObjectives(self);
    
    // Обновление триггеров
    MissionManager__UpdateTriggers(self);
}

void MissionManager__CheckObjectives(MissionManager* self) {
    if (!self) return;
    
    // Подсчет выполненных целей по битовой маске
    uint32_t completed = 0;
    uint32_t totalBits = self->total_objectives;
    
    for (uint32_t i = 0; i < totalBits && i < 8192; i++) {
        uint32_t byteIndex = i / 8;
        uint32_t bitIndex = i % 8;
        if (self->objectives_flags[byteIndex] & (1 << bitIndex)) {
            completed++;
        }
    }
    
    self->completed_objectives = completed;
    
    // Проверка завершения миссии
    if (completed >= self->total_objectives && self->total_objectives > 0) {
        MissionManager__EndMission(self, 1);
    }
}

int32_t MissionManager__IsMissionActive(MissionManager* self) {
    return (self && self->state == MISSION_STATE_RUNNING) ? 1 : 0;
}

uint32_t MissionManager__GetCurrentMissionId(MissionManager* self) {
    return self ? self->current_mission_id : 0xFFFFFFFF;
}

uint32_t MissionManager__GetMissionState(MissionManager* self) {
    return self ? self->state : MISSION_STATE_UNLOADED;
}

void MissionManager__SetNextMission(MissionManager* self, uint32_t nextId) {
    if (!self) return;
    // Логика установки следующей миссии (может вызываться после завершения текущей)
    self->current_mission_id = nextId;
}

void MissionManager__AbortAllMissions(MissionManager* self) {
    MissionManager__AbortMission(self);
    // Дополнительная очистка если нужно
}

// ============================================================================
// РАБОТА СО СКРИПТАМИ И ФАЙЛАМИ
// ============================================================================

int32_t MissionManager__LoadScript(MissionManager* self, const char* filename) {
    if (!self || !filename) return -1;
    
    // Формирование полного пути
    // TODO: Использовать правильный путь к директории скриптов
    strncpy(self->current_script_path, filename, sizeof(self->current_script_path) - 1);
    self->current_script_path[sizeof(self->current_script_path) - 1] = '\0';
    
    // Открытие файла и чтение
    // В реальной реализации здесь будет fopen/fread
    // Для заглушки просто помечаем как загруженный
    
    self->script_size = 0; // Будет установлено при реальном чтении
    self->script_cursor = 0;
    self->state = MISSION_STATE_LOADED;
    
    return 0;
}

int32_t MissionManager__SaveFile(MissionManager* self) {
    if (!self) return -1;
    
    // Сериализация ключевых данных
    // В реальной реализации: fopen/fwrite структур состояния
    
    // Сохраняемые данные:
    // - current_mission_id
    // - objectives_flags
    // - timer_main
    // - reward_money/respect
    
    return 0;
}

int32_t MissionManager__LoadGame(MissionManager* self, const char* filename) {
    if (!self || !filename) return -1;
    
    strncpy(self->save_file_path, filename, sizeof(self->save_file_path) - 1);
    
    // Загрузка данных сохранения
    // TODO: Реализовать десериализацию
    
    return 0;
}

void MissionManager__ExtractFileNameWithoutExtension(const char* fullPath, char* outName) {
    if (!fullPath || !outName) return;
    
    const char* lastSlash = strrchr(fullPath, '/');
    const char* lastBackslash = strrchr(fullPath, '\\');
    const char* fileName = (lastSlash > lastBackslash) ? lastSlash : lastBackslash;
    fileName = fileName ? fileName + 1 : fullPath;
    
    strncpy(outName, fileName, 255);
    outName[255] = '\0';
    
    // Удаление расширения
    char* dot = strrchr(outName, '.');
    if (dot) *dot = '\0';
}

int32_t MissionManager__ParseScriptCommand(MissionManager* self) {
    if (!self || !self->script_text_buffer) return -1;
    
    // Чтение команды из буфера начиная с script_cursor
    // Парсинг аргументов
    // Выполнение команды
    
    // Пример псевдокода:
    // char* line = GetLine(self->script_text_buffer + self->script_cursor);
    // if (strcmp(line, "CREATE_CAR") == 0) { ... }
    // else if (strcmp(line, "SET_OBJECTIVE") == 0) { ... }
    
    return 0;
}

void* MissionManager__GetMissionScript(MissionManager* self) {
    return self ? self->script_buffer_ptr : NULL;
}

void MissionManager__InitScriptVariables(MissionManager* self) {
    if (!self) return;
    // Инициализация переменных скрипта по умолчанию
}

// ============================================================================
// ЦЕЛИ И ПРОГРЕСС
// ============================================================================

void MissionManager__UpdateObjectives(MissionManager* self) {
    MissionManager__CheckObjectives(self);
}

int32_t MissionManager__CheckCompletion(MissionManager* self) {
    if (!self) return 0;
    return (self->completed_objectives >= self->total_objectives) ? 1 : 0;
}

void MissionManager__GiveReward(MissionManager* self) {
    if (!self) return;
    
    // TODO: Вызов функций добавления денег и репутации игроку
    // PlayerAddMoney(self->reward_money);
    // PlayerAddRespect(self->reward_respect);
}

void MissionManager__SetObjectiveFlag(MissionManager* self, uint32_t index, int32_t completed) {
    if (!self || index >= 8192) return;
    
    uint32_t byteIndex = index / 8;
    uint32_t bitIndex = index % 8;
    
    if (completed) {
        self->objectives_flags[byteIndex] |= (1 << bitIndex);
    } else {
        self->objectives_flags[byteIndex] &= ~(1 << bitIndex);
    }
}

uint32_t MissionManager__GetObjectiveCount(MissionManager* self) {
    return self ? self->total_objectives : 0;
}

uint32_t MissionManager__GetCompletedObjectives(MissionManager* self) {
    return self ? self->completed_objectives : 0;
}

void MissionManager__ResetProgress(MissionManager* self) {
    if (!self) return;
    
    self->completed_objectives = 0;
    memset(self->objectives_flags, 0, sizeof(self->objectives_flags));
    self->timer_main = 0;
    self->timer_secondary = 0;
}

// ============================================================================
// УПРАВЛЕНИЕ ОБЪЕКТАМИ И ТРИГГЕРАМИ
// ============================================================================

MissionObject* MissionManager__GetObjectPtr(MissionManager* self, uint32_t index) {
    if (!self || index >= MAX_MISSION_OBJECTS) return NULL;
    return &self->objects_pool[index];
}

MissionTrigger* MissionManager__GetTriggerPtr(MissionManager* self, uint32_t index) {
    if (!self || index >= MAX_MISSION_TRIGGERS) return NULL;
    return &self->triggers_pool[index];
}

void MissionManager__SpawnScriptObjects(MissionManager* self) {
    if (!self) return;
    
    // Проход по пулу объектов и спавн активных
    for (uint32_t i = 0; i < MAX_MISSION_OBJECTS; i++) {
        MissionObject* obj = &self->objects_pool[i];
        if (obj->is_active && obj->type != MISSION_OBJ_NONE) {
            // TODO: Вызов соответствующих функций спавна
            // if (obj->type == MISSION_OBJ_CAR) SpawnCar(...);
            // if (obj->type == MISSION_OBJ_PED) SpawnPed(...);
        }
    }
}

void MissionManager__DespawnObject(MissionManager* self, uint32_t objIndex) {
    if (!self || objIndex >= MAX_MISSION_OBJECTS) return;
    
    MissionObject* obj = &self->objects_pool[objIndex];
    obj->is_active = 0;
    obj->type = MISSION_OBJ_NONE;
    
    // TODO: Вызов функции удаления сущности из мира
}

void MissionManager__ActivateTrigger(MissionManager* self, uint32_t trigIndex) {
    if (!self || trigIndex >= MAX_MISSION_TRIGGERS) return;
    
    self->triggers_pool[trigIndex].state = 1; // Активирован
}

void MissionManager__UpdateTriggers(MissionManager* self) {
    if (!self) return;
    
    for (uint32_t i = 0; i < MAX_MISSION_TRIGGERS; i++) {
        MissionTrigger* trig = &self->triggers_pool[i];
        if (trig->type == TRIGGER_NONE || trig->state == 2) continue; // Неактивен или выполнен
        
        // Проверка условий триггера
        // TODO: Реализовать проверку зон, таймеров, событий
    }
}

// ============================================================================
// ВНУТРЕННИЕ УТИЛИТЫ
// ============================================================================

void MissionManager__ClampValues(MissionManager* self) {
    if (!self) return;
    // Ограничение значений в допустимых пределах
}

int32_t MissionManager__greater_than(MissionManager* self, int32_t a, int32_t b) {
    (void)self;
    return (a > b) ? 1 : 0;
}

int32_t MissionManager__less_or_equal(MissionManager* self, int32_t a, int32_t b) {
    (void)self;
    return (a <= b) ? 1 : 0;
}

int32_t MissionManager__NotEqual(MissionManager* self, int32_t a, int32_t b) {
    (void)self;
    return (a != b) ? 1 : 0;
}

int32_t MissionManager__less_than(MissionManager* self, int32_t a, int32_t b) {
    (void)self;
    return (a < b) ? 1 : 0;
}

void MissionManager__PrepareArray(MissionManager* self) {
    if (!self) return;
    // Подготовка массивов данных
}

void MissionManager__ClearMissionData(MissionManager* self) {
    if (!self) return;
    memset(self->mission_data_buffer, 0, sizeof(self->mission_data_buffer));
}

void MissionManager__AllocateMissionBuffer(MissionManager* self, uint32_t size) {
    if (!self) return;
    if (self->script_buffer_ptr) free(self->script_buffer_ptr);
    self->script_buffer_ptr = malloc(size);
    self->script_size = size;
}

void MissionManager__FreeMissionBuffer(MissionManager* self) {
    if (!self) return;
    if (self->script_buffer_ptr) {
        free(self->script_buffer_ptr);
        self->script_buffer_ptr = NULL;
    }
}

// ============================================================================
// СОХРАНЕНИЕ И ЗАГРУЗКА
// =================================
