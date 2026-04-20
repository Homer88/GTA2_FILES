#ifndef MISSION_TYPES_H
#define MISSION_TYPES_H

#include "../types.h"

/**
 * Типы миссий в GTA 2
 */
typedef enum MissionType {
    MISSION_NONE = 0,
    MISSION_KILL_TARGET = 1,        // Убить цель
    MISSION_DELIVER_PACKAGE = 2,    // Доставить посылку
    MISSION_ESCORT = 3,             // Сопровождение
    MISSION_STEAL_CAR = 4,          // Украсть машину
    MISSION_TAXI_DRIVER = 5,        // Такси (перевезти пассажира)
    MISSION_RACE = 6,               // Гонка на время
    MISSION_DEFEND_AREA = 7,        // Защитить зону
    MISSION_COLLECT_ITEMS = 8,      // Сбор предметов
    MISSION_ASSASSINATE = 9,        // Заказное убийство
    MISSION_SURVIVAL = 10,          // Выживание (волны врагов)
    MISSION_CUTSCENE = 11           // Катсцена
} MissionType;

/**
 * Статус выполнения миссии
 */
typedef enum MissionStatus {
    STATUS_NOT_STARTED = 0,
    STATUS_ACTIVE = 1,
    STATUS_COMPLETED = 2,
    STATUS_FAILED = 3,
    STATUS_CANCELLED = 4
} MissionStatus;

/**
 * Типы целей миссии
 */
typedef enum ObjectiveType {
    OBJ_NONE = 0,
    OBJ_GOTO_LOCATION = 1,      // Идти к точке
    OBJ_KILL_PED = 2,           // Убить пешехода
    OBJ_KILL_ALL_IN_AREA = 3,   // Убить всех в зоне
    OBJ_ENTER_VEHICLE = 4,      // Сесть в машину
    OBJ_EXIT_VEHICLE = 5,       // Выйти из машины
    OBJ_DELIVER_VEHICLE = 6,    // Доставить машину
    OBJ_WAIT_TIME = 7,          // Ждать время
    OBJ_PROTECT_PED = 8,        // Защитить пешехода
    OBJ_COLLECT_ITEM = 9,       // Подобрать предмет
    OBJ_SHOOT_FROM_CAR = 10,    // Стрелять из машины
    OBJ_REACH_CHECKPOINT = 11,  // Достичь чекпоинта
    OBJ_TRIGGER_CUTSCENE = 12   // Запустить катсцену
} ObjectiveType;

/**
 * Структура цели миссии
 * Размер: ~48 байт
 */
typedef struct MissionObjective {
    ObjectiveType Type;         // 0x0 - Тип цели
    u32 TargetId;               // 0x4 - ID цели (Ped, Car, и т.д.)
    f32 TargetX;                // 0x8 - Координата X цели/зоны
    f32 TargetY;                // 0xC - Координата Y цели/зоны
    f32 Radius;                 // 0x10 - Радиус зоны (если применимо)
    s32 RequiredCount;          // 0x14 - Требуемое количество (убить N, собрать N)
    s32 CurrentCount;           // 0x18 - Текущее выполнение
    f32 TimeLimit;              // 0x1C - Ограничение по времени (0 = нет)
    f32 Timer;                  // 0x20 - Текущий таймер
    u8 Status;                  // 0x24 - Статус цели (выполнена/активна)
    u8 Flags;                   // 0x25 - Флаги
    u16 Padding;                // 0x26 - Выравнивание
    void* TargetPtr;            // 0x28 - Указатель на цель (Ped*, Car*)
    char Description[32];       // 0x2C - Описание цели
} MissionObjective;

// Флаги цели
#define OBJ_FLAG_OPTIONAL       0x01    // Необязательная цель
#define OBJ_FLAG_HIDDEN         0x02    // Скрытая цель
#define OBJ_FLAG_TIMED          0x04    // Есть ограничение по времени
#define OBJ_FLAG_SEQUENTIAL     0x08    // Должна выполняться после предыдущей

/**
 * Триггер миссии
 */
typedef enum TriggerType {
    TRIG_NONE = 0,
    TRIG_ENTER_ZONE = 1,        // Вход в зону
    TRIG_EXIT_ZONE = 2,         // Выход из зоны
    TRIG_KILL_PED = 3,          // Убийство конкретного Ped
    TRIG_TIME_OF_DAY = 4,       // Время суток
    TRIG_HAVE_ITEM = 5,         // Наличие предмета
    TRIG_HAVE_MONEY = 6,        // Наличие денег
    TRIG_WANTED_LEVEL = 7,      // Уровень розыска
    TRIG_VEHICLE_TYPE = 8       // Владение типом транспорта
} TriggerType;

#endif // MISSION_TYPES_H
