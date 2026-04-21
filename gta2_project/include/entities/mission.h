/**
 * @file mission.h
 * @brief Структуры и функции системы миссий и скриптов GTA2
 * 
 * old_file: gta2.exe.h (секция миссий)
 * Адреса функций соответствуют IDA Pro (sub_XXXXXX)
 */

#ifndef GTA2_MISSION_H
#define GTA2_MISSION_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// -----------------------------------------------------------------------------
// Перечисления
// -----------------------------------------------------------------------------

/**
 * @brief Флаги состояния миссии
 * old_var: MissionFlags
 */
typedef enum {
    MISSION_FLAG_NONE       = 0x00,
    MISSION_FLAG_ACTIVE     = 0x01, // Миссия активна
    MISSION_FLAG_COMPLETED  = 0x02, // Миссия завершена успешно
    MISSION_FLAG_FAILED     = 0x04, // Миссия провалена
    MISSION_FLAG_PAUSE      = 0x08, // Миссия на паузе (скрипт ожидает)
    MISSION_FLAG_CUTSCENE   = 0x10  // Активна катсцена
} MissionFlags;

/**
 * @brief Типы целей в миссии
 * old_var: ObjectiveType
 */
typedef enum {
    OBJ_NONE            = 0,
    OBJ_KILL_PED        = 1, // Убить пешехода/группу
    OBJ_STEAL_CAR       = 2, // Украсть машину
    OBJ_DELIVER_ITEM    = 3, // Доставить предмет/пассажира
    OBJ_REACH_LOCATION  = 4, // Достичь точки
    OBJ_SURVIVE_TIME    = 5, // Выжить время
    OBJ_COLLECT_ITEMS   = 6, // Собрать предметы
    OBJ_PROTECT_PED     = 7  // Защитить пешехода
} ObjectiveType;

/**
 * @brief Типы триггеров событий
 * old_var: TriggerType
 */
typedef enum {
    TRIG_NONE           = 0,
    TRIG_ENTER_ZONE     = 1, // Вход в зону
    TRIG_LEAVE_ZONE     = 2, // Выход из зоны
    TRIG_KILL_TARGET    = 3, // Убийство цели
    TRIG_TIMER_EXPIRED  = 4, // Истечение времени
    TRIG_PLAYER_DEATH   = 5, // Смерть игрока
    TRIG_VEHICLE_DESTROY= 6, // Уничтожение транспорта
    TRIG_CUSTOM_SCRIPT  = 7  // Кастомное скриптовое событие
} TriggerType;

/**
 * @brief Состояние скриптового движка
 * old_var: ScriptState
 */
typedef enum {
    SCRIPT_IDLE         = 0, // Бездействие
    SCRIPT_RUNNING      = 1, // Выполнение
    SCRIPT_WAITING      = 2, // Ожидание (таймер/событие)
    SCRIPT_FINISHED     = 3  // Завершено
} ScriptState;

// -----------------------------------------------------------------------------
// Структуры данных
// -----------------------------------------------------------------------------

/**
 * @brief Цель миссии
 * old_struct: S95_Objective (предположительно)
 * size: 0x14 байт
 */
typedef struct {
    ObjectiveType Type;       // +0x00: Тип цели
    int32_t TargetID;         // +0x04: ID цели (Ped, Car, Zone)
    int32_t CurrentCount;     // +0x08: Текущий прогресс (сколько убито/собрано)
    int32_t RequiredCount;    // +0x0C: Требуемое количество
    uint32_t Flags;           // +0x10: Флаги цели (скрыта, обязательна и т.д.)
    // old_var: ObjType, ObjTarget, ObjProgress, ObjRequired, ObjFlags
} Objective;

/**
 * @brief Триггер события миссии
 * old_struct: S96_Trigger
 * size: 0x10 байт
 */
typedef struct {
    TriggerType Type;         // +0x00: Тип триггера
    int32_t LinkedID;         // +0x04: Связанный объект (ZoneID, PedID)
    bool IsActive;            // +0x08: Активен ли триггер
    bool IsOneShot;           // +0x09: Срабатывает один раз
    uint16_t Padding;         // +0x0A: Выравнивание
    int32_t ActionScriptIdx;  // +0x0C: Индекс скрипта действия при срабатывании
    // old_var: TrigType, TrigLink, TrigActive, TrigOneShot, TrigAction
} MissionTrigger;

/**
 * @brief Основная структура миссии
 * old_struct: S94_Mission
 * size: 0x40 байт (примерно)
 */
typedef struct {
    int32_t MissionID;        // +0x00: Уникальный ID миссии
    char Name[32];            // +0x04: Название миссии (текст из файла)
    MissionFlags Flags;       // +0x24: Флаги состояния
    int32_t CurrentObjective; // +0x28: Индекс текущей цели
    int32_t TotalObjectives;  // +0x2C: Всего целей
    Objective* Objectives;    // +0x30: Массив целей
    int32_t Timer;            // +0x34: Таймер миссии (в тиках)
    int32_t Difficulty;       // +0x38: Уровень сложности
    void* ScriptData;         // +0x3C: Указатель на данные скрипта (байт-код или указатели)
    // old_var: MissID, MissName, MissFlags, MissCurObj, MissTotObj, MissObjPtr, MissTimer, MissDiff, MissScript
} Mission;

/**
 * @brief Глобальный менеджер миссий
 * old_struct: S97_MissionManager
 * size: 0x200 байт (контейнер)
 */
typedef struct {
    Mission* ActiveMission;   // +0x00: Активная миссия
    MissionTrigger Triggers[32]; // +0x04: Массив глобальных триггеров
    int32_t TriggerCount;     // +0x104: Количество триггеров
    ScriptState State;        // +0x108: Состояние скриптового движка
    int32_t WaitTimer;        // +0x10C: Таймер ожидания (для SCRIPT_WAITING)
    int32_t LastCheckedFrame; // +0x110: Последний обработанный кадр (защита от дублей)
    // old_var: MM_Active, MM_Triggers, MM_TrigCount, MM_State, MM_WaitTimer, MM_LastFrame
} MissionManager;

// -----------------------------------------------------------------------------
// Прототипы функций
// -----------------------------------------------------------------------------

/**
 * @brief Инициализация менеджера миссий
 * old_name: sub_00401000
 * @param manager Указатель на менеджер
 */
void MissionManager_Init(MissionManager* manager);

/**
 * @brief Обновление логики миссий (вызывается каждый кадр)
 * old_name: sub_00401050
 * @param manager Указатель на менеджер
 * @param player_ptr Указатель на игрока (для проверок)
 */
void MissionManager_Update(MissionManager* manager, void* player_ptr);

/**
 * @brief Запуск конкретной миссии
 * old_name: sub_00401120
 * @param manager Указатель на менеджер
 * @param mission_id ID миссии для запуска
 * @return true если запуск успешен
 */
bool Mission_Start(MissionManager* manager, int32_t mission_id);

/**
 * @brief Завершение текущей миссии (успех/провал)
 * old_name: sub_00401180
 * @param manager Указатель на менеджер
 * @param success true для успеха, false для провала
 */
void Mission_Finish(MissionManager* manager, bool success);

/**
 * @brief Проверка выполнения текущей цели
 * old_name: sub_00401200
 * @param mission Указатель на миссию
 * @return true если цель выполнена
 */
bool Mission_CheckObjective(Mission* mission);

/**
 * @brief Обработка триггеров
 * old_name: sub_00401280
 * @param manager Указатель на менеджер
 * @param event_type Тип произошедшего события
 * @param event_data Данные события (ID объекта и т.д.)
 */
void Mission_ProcessTrigger(MissionManager* manager, int32_t event_type, int32_t event_data);

/**
 * @brief Установка таймера ожидания в скрипте
 * old_name: sub_00401300
 * @param manager Указатель на менеджер
 * @param ticks Время ожидания в тиках
 */
void Script_Wait(MissionManager* manager, int32_t ticks);

/**
 * @brief Печать сообщения о миссии на экран
 * old_name: sub_00401350
 * @param text_id ID текста из строкового ресурса
 * @param duration Длительность отображения (мс)
 */
void Mission_ShowMessage(int32_t text_id, int32_t duration);

/**
 * @brief Добавление новой цели в активную миссию
 * old_name: sub_004013C0
 * @param mission Указатель на миссию
 * @param type Тип цели
 * @param target_id ID цели
 * @param required Требуемое количество
 */
void Mission_AddObjective(Mission* mission, ObjectiveType type, int32_t target_id, int32_t required);

/**
 * @brief Создание триггера зоны
 * old_name: sub_00401420
 * @param manager Указатель на менеджер
 * @param zone_id ID зоны на карте
 * @param is_enter_trigger true если срабатывает на вход, false на выход
 * @param script_idx Индекс скрипта действия
 */
void Mission_CreateZoneTrigger(MissionManager* manager, int32_t zone_id, bool is_enter_trigger, int32_t script_idx);

/**
 * @brief Получение статуса активной миссии
 * old_name: sub_00401480
 * @param manager Указатель на менеджер
 * @return Флаги миссии
 */
MissionFlags Mission_GetStatus(MissionManager* manager);

/**
 * @brief Сброс всех миссий и триггеров (при загрузке игры / рестарте)
 * old_name: sub_004014D0
 * @param manager Указатель на менеджер
 */
void MissionManager_Reset(MissionManager* manager);

/**
 * @brief Выполнение команды скрипта (интерпретатор)
 * old_name: sub_00401550
 * @param manager Указатель на менеджер
 * @param command_code Код команды
 * @param param_a Параметр А
 * @param param_b Параметр Б
 */
void Script_ExecuteCommand(MissionManager* manager, int32_t command_code, int32_t param_a, int32_t param_b);

#ifdef __cplusplus
}
#endif

#endif // GTA2_MISSION_H
