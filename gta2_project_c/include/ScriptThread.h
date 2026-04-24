#ifndef SCRIPT_THREAD_H
#define SCRIPT_THREAD_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================================
// СТРУКТУРА S29 (ScriptThread)
// ============================================================================
// Размер: 0x468 (1128 байт)
// Назначение: Поток выполнения скрипта миссии
// Содержит состояние выполнения, локальные переменные, таймеры
// ============================================================================

#define S29_SIZE 0x468
#define MAX_SCRIPT_LOCALS 64   // Максимальное количество локальных переменных
#define MAX_THREAD_WAIT 1000   // Максимальное время ожидания (мс)

/**
 * @brief Структура S29 - ScriptThread
 * Поток выполнения скрипта миссии
 */
typedef struct ScriptThread {
    // === Блок управления выполнением (0x00 - 0x20) ===
    void* script_ptr;           // 0x00: Указатель на код скрипта
    void* current_instruction;  // 0x04: Текущая инструкция для выполнения
    uint32_t instruction_ptr;   // 0x08: Смещение текущей инструкции в скрипте
    uint32_t thread_id;         // 0x0C: ID потока
    uint32_t state;             // 0x10: Состояние потока (0=None, 1=Running, 2=Waiting, 3=Suspended)
    uint32_t wait_timer;        // 0x14: Таймер ожидания (мс)
    uint32_t sleep_timer;       // 0x18: Таймер сна/паузы
    uint32_t flags;             // 0x1C: Флаги состояния потока
    
    // === Координаты и позиция (0x20 - 0x30) ===
    float position_x;           // 0x20: Координата X текущей позиции
    float position_y;           // 0x24: Координата Y текущей позиции
    float position_z;           // 0x28: Координата Z текущей позиции
    uint32_t zone_id;           // 0x2C: ID текущей зоны
    
    // === Локальные переменные скрипта (0x30 - 0x130) ===
    // 64 переменных * 4 байта = 256 байт = 0x100
    int32_t local_vars[MAX_SCRIPT_LOCALS];  // 0x30: Массив локальных переменных
    
    // === Стек вызовов (0x130 - 0x1B0) ===
    // 16 уровней вложенности * 8 байт = 128 байт = 0x80
    uint32_t call_stack[16];    // 0x130: Стек адресов возврата для подпрограмм
    uint32_t stack_pointer;     // 0x1B0: Указатель вершины стека
    
    // === Таймеры и счетчики (0x1B4 - 0x1D0) ===
    uint32_t frame_counter;     // 0x1B4: Счетчик кадров выполнения
    uint32_t timer_1b8;         // 0x1B8: Дополнительный таймер 1
    uint32_t timer_1bc;         // 0x1BC: Дополнительный таймер 2
    uint32_t timer_1c0;         // 0x1C0: Дополнительный таймер 3
    uint32_t timer_1c4;         // 0x1C4: Дополнительный таймер 4
    uint32_t timer_1c8;         // 0x1C8: Дополнительный таймер 5
    uint32_t timer_1cc;         // 0x1CC: Дополнительный таймер 6
    uint32_t timer_1d0;         // 0x1D0: Дополнительный таймер 7
    
    // === Параметры и аргументы (0x1D4 - 0x250) ===
    uint32_t param_1d4;         // 0x1D4: Параметр 1
    uint32_t param_1d8;         // 0x1D8: Параметр 2
    uint32_t param_1dc;         // 0x1DC: Параметр 3
    uint32_t param_1e0;         // 0x1E0: Параметр 4
    uint32_t param_1e4;         // 0x1E4: Параметр 5
    uint32_t param_1e8;         // 0x1E8: Параметр 6
    uint32_t param_1ec;         // 0x1EC: Параметр 7
    uint32_t param_1f0;         // 0x1F0: Параметр 8
    // ... дополнительные поля до 0x250
    
    // === Связь с MissionScriptObject (S28) (0x250 - 0x260) ===
    void* mission_script_obj;   // 0x250: Указатель на родительский MissionScriptObject
    uint32_t script_object_id;  // 0x254: ID объекта скрипта
    
    // === Дополнительные данные (0x260 - 0x468) ===
    uint8_t reserved[0x208];    // 0x260: Зарезервировано для дополнительных данных
    
} ScriptThread;

// Проверка размера
// sizeof(ScriptThread) == 0x468

// Глобальные переменные (если есть)
// extern ScriptThread gS29;
// extern ScriptThread* pS29;

// ============================================================================
// КОНСТРУКТОРЫ И ДЕСТРУКТОРЫ
// ============================================================================

/**
 * @brief Конструктор S29
 * Адрес: 0x474FA0 (S29__S29)
 * Размер: 0x0D байт
 * Инициализирует структуру ScriptThread
 */
void ScriptThread_Init(ScriptThread* self);

/**
 * @brief Деструктор S29 (основной)
 * Адрес: 0x476DD0 (S29__S29_DEs)
 * Размер: 0x2B байт
 * Освобождает ресурсы потока
 */
void ScriptThread_Destroy(ScriptThread* self);

/**
 * @brief Деструктор S29 (альтернативный)
 * Адрес: 0x476E40 (S29__S29_Des)
 * Размер: 0x1E байт
 * Быстрая очистка потока
 */
void ScriptThread_DestroyAlt(ScriptThread* self);

// ============================================================================
// МЕТОДЫ УПРАВЛЕНИЯ ПОТОКОМ
// ============================================================================

/**
 * @brief sub_474FB0 - Запуск/возобновление потока
 * Адрес: 0x474FB0
 * Размер: 0x11 байт
 */
void ScriptThread_Start(ScriptThread* self);

/**
 * @brief sub_474FD0 - Приостановка потока
 * Адрес: 0x474FD0
 * Размер: 0x16 байт
 */
void ScriptThread_Suspend(ScriptThread* self);

/**
 * @brief sub_474FF0 - Обновление состояния потока
 * Адрес: 0x474FF0
 * Размер: 0x1A байт
 */
void ScriptThread_Update(ScriptThread* self);

/**
 * @brief sub_476DF0 - Основной цикл выполнения
 * Адрес: 0x476DF0
 * Размер: 0x0B байт (часть большей функции)
 */
void ScriptThread_MainLoop(ScriptThread* self);

// ============================================================================
// МЕТОДЫ РАБОТЫ СО СКРИПТАМИ
// ============================================================================

/**
 * @brief sub_4751B0 - Загрузка скрипта
 * Адрес: 0x4751B0
 * Размер: 0x1D байт
 */
int ScriptThread_LoadScript(ScriptThread* self, const char* script_name);

/**
 * @brief sub_4751E0 - Выгрузка скрипта
 * Адрес: 0x4751E0
 * Размер: 0x07 байт
 */
void ScriptThread_UnloadScript(ScriptThread* self);

/**
 * @brief sub_4751F0 - Переход к метке (Goto)
 * Адрес: 0x4751F0
 * Размер: 0x31 байт
 */
void ScriptThread_Goto(ScriptThread* self, uint32_t label_id);

/**
 * @brief sub_475420 - Вызов подпрограммы (Call)
 * Адрес: 0x475420
 * Размер: 0x35 байт
 */
void ScriptThread_CallSubroutine(ScriptThread* self, uint32_t subroutine_id);

/**
 * @brief sub_475460 - Возврат из подпрограммы (Return)
 * Адрес: 0x475460
 * Размер: 0x63 байт
 */
void ScriptThread_Return(ScriptThread* self);

// ============================================================================
// МЕТОДЫ РАБОТЫ С ВРЕМЕНЕМ
// ============================================================================

/**
 * @brief sub_476E50 - Установка таймера ожидания (Wait)
 * Адрес: 0x476E50
 * Размер: 0x2F байт
 */
void ScriptThread_Wait(ScriptThread* self, uint32_t milliseconds);

/**
 * @brief sub_476E80 - Проверка истечения таймера
 * Адрес: 0x476E80
 * Размер: 0x1A байт
 */
int ScriptThread_CheckTimer(ScriptThread* self);

// ============================================================================
// МЕТОДЫ РАБОТЫ С ПЕРЕМЕННЫМИ
// ============================================================================

/**
 * @brief sub_4779A0 - Установка переменной (SetVar)
 * Адрес: 0x4779A0
 * Размер: 0x5E байт
 */
void ScriptThread_SetVar(ScriptThread* self, uint32_t var_index, int32_t value);

/**
 * @brief sub_477A00 - Получение переменной (GetVar)
 * Адрес: 0x477A00
 * Размер: 0xB4 байт
 */
int32_t ScriptThread_GetVar(ScriptThread* self, uint32_t var_index);

/**
 * @brief sub_477B70 - Сравнение переменных (CompareVars)
 * Адрес: 0x477B70
 * Размер: 0x5F байт
 */
int ScriptThread_CompareVars(ScriptThread* self, uint32_t var1, uint32_t var2);

/**
 * @brief sub_477BD0 - Арифметическая операция над переменными
 * Адрес: 0x477BD0
 * Размер: 0x126 байт
 */
void ScriptThread_ArithmeticOp(ScriptThread* self, uint32_t op, uint32_t dest, uint32_t src1, uint32_t src2);

// ============================================================================
// МЕТОДЫ РАБОТЫ С УСЛОВИЯМИ
// ============================================================================

/**
 * @brief sub_478450 - Проверка условия (If)
 * Адрес: 0x478450
 * Размер: 0x4E байт
 */
int ScriptThread_CheckCondition(ScriptThread* self, uint32_t condition_id);

/**
 * @brief sub_478610 - Обработка ветвления (Else/ElseIf)
 * Адрес: 0x478610
 * Размер: 0x39 байт
 */
void ScriptThread_HandleBranch(ScriptThread* self, int condition_result);

// ============================================================================
// МЕТОДЫ РАБОТЫ С ОБЪЕКТАМИ МИССИИ
// ============================================================================

/**
 * @brief sub_479050 - Создание объекта миссии
 * Адрес: 0x479050
 * Размер: 0x42 байт
 */
int ScriptThread_CreateMissionObject(ScriptThread* self, uint32_t type, float x, float y, float z);

/**
 * @brief sub_479850 - Удаление объекта миссии
 * Адрес: 0x479850
 * Размер: 0x180 байт
 */
void ScriptThread_RemoveMissionObject(ScriptThread* self, uint32_t object_id);

/**
 * @brief sub_479B70 - Поиск объекта по параметрам
 * Адрес: 0x479B70
 * Размер: 0x74 байт
 */
int ScriptThread_FindObject(ScriptThread* self, uint32_t type, float x, float y, float radius);

/**
 * @brief sub_479CC0 - Получение параметров объекта
 * Адрес: 0x479CC0
 * Размер: 0x77 байт
 */
int ScriptThread_GetObjectParams(ScriptThread* self, uint32_t object_id, void* out_params);

/**
 * @brief sub_479F10 - Сохранение объектов миссии в файл
 * Адрес: 0x479F10
 * Размер: 0x2AE байт
 */
int ScriptThread_SaveObjectsToFile(ScriptThread* self, const char* filename);

/**
 * @brief sub_47A1E0 - Загрузка объектов миссии из файла
 * Адрес: 0x47A1E0
 * Размер: 0xF8 байт
 */
int ScriptThread_LoadObjectsFromFile(ScriptThread* self, const char* filename);

// ============================================================================
// МЕТОДЫ РАБОТЫ С ЦЕЛЯМИ
// ============================================================================

/**
 * @brief sub_47A330 - Добавление цели
 * Адрес: 0x47A330
 * Размер: 0x71 байт
 */
void ScriptThread_AddObjective(ScriptThread* self, uint32_t objective_id, const char* text);

/**
 * @brief sub_47A3B0 - Выполнение цели
 * Адрес: 0x47A3B0
 * Размер: 0xAD байт
 */
void ScriptThread_CompleteObjective(ScriptThread* self, uint32_t objective_id);

/**
 * @brief sub_47A620 - Проверка выполнения целей
 * Адрес: 0x47A620
 * Размер: 0x1A9 байт
 */
int ScriptThread_CheckObjectives(ScriptThread* self);

/**
 * @brief sub_47A860 - Обновление статуса цели
 * Адрес: 0x47A860
 * Размер: 0xF8 байт
 */
void ScriptThread_UpdateObjectiveStatus(ScriptThread* self, uint32_t objective_id, uint32_t status);

// ============================================================================
// ДОПОЛНИТЕЛЬНЫЕ МЕТОДЫ
// ============================================================================

/**
 * @brief sub_47ACC0 - Неинициализированный метод
 * Адрес: 0x47ACC0
 * Размер: 0x123 байт
 * Требуется дополнительный анализ
 */
void ScriptThread_sub_47ACC0(ScriptThread* self, uint32_t param1, uint32_t param2);

/**
 * @brief sub_47AF50 - Неинициализированный метод
 * Адрес: 0x47AF50
 * Размер: 0x73 байт
 * Требуется дополнительный анализ
 */
void ScriptThread_sub_47AF50(ScriptThread* self);

// ============================================================================
// ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ
// ============================================================================

/**
 * @brief Получить указатель на локальную переменную
 * @param self Указатель на экземпляр ScriptThread
 * @param index Индекс переменной (0..MAX_SCRIPT_LOCALS-1)
 * @return Указатель на переменную или NULL если индекс вне диапазона
 */
int32_t* ScriptThread_GetLocalVarPtr(ScriptThread* self, uint32_t index);

/**
 * @brief Проверить состояние потока
 * @param self Указатель на экземпляр ScriptThread
 * @return 1 если поток активен, 0 иначе
 */
int ScriptThread_IsActive(ScriptThread* self);

/**
 * @brief Сбросить состояние потока
 * @param self Указатель на экземпляр ScriptThread
 */
void ScriptThread_Reset(ScriptThread* self);

#ifdef __cplusplus
}
#endif

#endif // SCRIPT_THREAD_H
