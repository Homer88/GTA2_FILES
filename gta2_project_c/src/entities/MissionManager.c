#include "MissionManager.h"
#include <string.h>

// Глобальные переменные
MissionManager gMissionManager;
MissionManager* pMissionManager = &gMissionManager;

// ============================================================================
// Конструктор и деструктор
// ============================================================================

void MissionManager__Constructor(MissionManager* self) {
    if (!self) return;
    
    // Инициализация всех полей нулями
    memset(self, 0, sizeof(MissionManager));
    
    // Установка начального состояния
    self->current_mission_id = -1;      // Нет активной миссии
    self->mission_state = 0;            // Состояние: нет миссии
    self->total_objectives = 0;
    self->completed_objectives = 0;
    self->reward_pending = 0;
    self->script_thread_id = -1;
    self->script_pointer = NULL;
    self->target_ped_id = -1;
    self->target_car_id = -1;
    self->timer = 0;
    self->time_limit = 0;
    self->flags = 0;
}

void MissionManager__Destructor(MissionManager* self) {
    if (!self) return;
    
    // Очистка указателей
    self->script_pointer = NULL;
    
    // Сброс состояния
    self->current_mission_id = -1;
    self->mission_state = 0;
}

// ============================================================================
// Управление жизненным циклом миссии
// ============================================================================

void MissionManager__StartMission(MissionManager* self, int32_t mission_id) {
    if (!self) return;
    
    self->current_mission_id = mission_id;
    self->mission_state = 1;  // Активна
    self->completed_objectives = 0;
    self->reward_pending = 0;
    // TODO: Загрузить данные миссии из скрипта
}

void MissionManager__EndMission(MissionManager* self) {
    if (!self) return;
    
    if (self->mission_state == 1) {  // Если активна
        self->mission_state = 2;  // Завершена
        MissionManager__GiveReward(self);
    }
}

void MissionManager__FailMission(MissionManager* self) {
    if (!self) return;
    
    if (self->mission_state == 1) {  // Если активна
        self->mission_state = 3;  // Провалена
        self->reward_pending = 0;
    }
}

void MissionManager__AbortAllMissions(MissionManager* self) {
    if (!self) return;
    
    self->current_mission_id = -1;
    self->mission_state = 0;
    self->completed_objectives = 0;
    self->reward_pending = 0;
    // TODO: Остановить все скрипты миссий
}

// ============================================================================
// Получение информации о миссии
// ============================================================================

int32_t MissionManager__GetCurrentMissionId(const MissionManager* self) {
    if (!self) return -1;
    return self->current_mission_id;
}

int32_t MissionManager__GetMissionState(const MissionManager* self) {
    if (!self) return 0;
    return self->mission_state;
}

uint8_t MissionManager__IsMissionActive(const MissionManager* self) {
    if (!self) return 0;
    return (self->mission_state == 1) ? 1 : 0;
}

void* MissionManager__GetMissionScriptPointer(const MissionManager* self) {
    if (!self) return NULL;
    return self->script_pointer;
}

// ============================================================================
// Управление целями
// ============================================================================

void MissionManager__UpdateObjectives(MissionManager* self) {
    if (!self) return;
    
    // TODO: Проверить выполнение целей на основе игровых событий
    // Вызывается каждый кадр или по триггеру
}

uint8_t MissionManager__CheckCompletion(const MissionManager* self) {
    if (!self) return 0;
    
    if (self->completed_objectives >= self->total_objectives && 
        self->total_objectives > 0) {
        return 1;  // Миссия завершена
    }
    return 0;
}

int32_t MissionManager__GetObjectiveCount(const MissionManager* self) {
    if (!self) return 0;
    return self->total_objectives;
}

int32_t MissionManager__GetCompletedObjectivesCount(const MissionManager* self) {
    if (!self) return 0;
    return self->completed_objectives;
}

void MissionManager__SetObjectiveCompleted(MissionManager* self, int32_t objective_index) {
    if (!self || objective_index < 0 || objective_index >= 256) return;
    
    // Установить бит в маске
    int byte_index = objective_index / 8;
    int bit_index = objective_index % 8;
    
    if (!(self->objectives_mask[byte_index] & (1 << bit_index))) {
        self->objectives_mask[byte_index] |= (1 << bit_index);
        self->completed_objectives++;
    }
}

uint8_t MissionManager__IsObjectiveCompleted(const MissionManager* self, int32_t objective_index) {
    if (!self || objective_index < 0 || objective_index >= 256) return 0;
    
    int byte_index = objective_index / 8;
    int bit_index = objective_index % 8;
    
    return (self->objectives_mask[byte_index] & (1 << bit_index)) ? 1 : 0;
}

// ============================================================================
// Награды и прогресс
// ============================================================================

void MissionManager__GiveReward(MissionManager* self) {
    if (!self) return;
    
    if (self->reward_pending > 0) {
        // TODO: Добавить награду игроку (деньги/очки)
        // Вызвать функцию добавления денег/очков
        self->reward_pending = 0;
    }
}

void MissionManager__SetNextMission(MissionManager* self, int32_t next_mission_id) {
    if (!self) return;
    
    // TODO: Установить следующую миссию в цепочке
    // Может запускаться автоматически после завершения текущей
}

void MissionManager__ResetProgress(MissionManager* self) {
    if (!self) return;
    
    memset(self->objectives_mask, 0, sizeof(self->objectives_mask));
    self->completed_objectives = 0;
    self->total_objectives = 0;
    self->timer = 0;
    self->flags = 0;
}

// ============================================================================
// События и триггеры
// ============================================================================

void MissionManager__TriggerEvent(MissionManager* self, int32_t event_type, void* event_data) {
    if (!self) return;
    
    // TODO: Обработать событие миссии
    // event_type: тип события (убийство, доставка, таймер и т.д.)
    // event_data: дополнительные данные события
    // Вызвать соответствующий обработчик в скрипте миссии
}

// ============================================================================
// Загрузка/Сохранение
// ============================================================================

void MissionManager__LoadMissionData(MissionManager* self, const void* data_ptr) {
    if (!self || !data_ptr) return;
    
    // TODO: Загрузить данные миссии из внешнего источника
    // Копирование данных в структуру
}

void MissionManager__SaveMissionData(const MissionManager* self, void* data_ptr) {
    if (!self || !data_ptr) return;
    
    // TODO: Сохранить текущее состояние миссии
    // Копирование данных из структуры
}

// ============================================================================
// Установка целей и локаций
// ============================================================================

void MissionManager__SetTargetPed(MissionManager* self, int32_t ped_id) {
    if (!self) return;
    self->target_ped_id = ped_id;
}

void MissionManager__SetTargetCar(MissionManager* self, int32_t car_id) {
    if (!self) return;
    self->target_car_id = car_id;
}

void MissionManager__SetTargetLocation(MissionManager* self, float x, float y, float z) {
    if (!self) return;
    self->target_location_x = x;
    self->target_location_y = y;
    self->target_location_z = z;
}

void MissionManager__SetTimer(MissionManager* self, int32_t time_limit) {
    if (!self) return;
    self->time_limit = time_limit;
    self->timer = time_limit;
}
