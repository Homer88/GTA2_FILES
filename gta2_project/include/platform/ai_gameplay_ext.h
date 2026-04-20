/**
 * @file ai_gameplay_ext.h
 * @brief Расширенные структуры ИИ и геймплея (укрытия, построения, скрипты, триггеры).
 * 
 * Детализация поведения NPC и логики миссий.
 */

#ifndef AI_GAMEPLAY_EXT_H
#define AI_GAMEPLAY_EXT_H

#include "types.h"
#include "math_types/vector3d.h"

#pragma pack(push, 1)

/**
 * @brief Точка укрытия.
 * Оригинал IDA: `struct Cover` / `COVER_PNT`
 * Используется полицией и бандами для тактической стрельбы.
 */
typedef struct CoverPoint {
    Vector3D Position;      // 0x00: Позиция укрытия
    f32 Angle;              // 0x0C: Рекомендуемый угол обстрела
    u8  Quality;            // 0x10: Качество укрытия (1-10, 10=полное покрытие)
    u8  Type;               // 0x11: Тип (Стена, Машина, Угол, Забор)
    bool IsOccupied;        // 0x12: Занято ли сейчас
    u8  Reserved;           // 0x13: Выравнивание
    void* OccupantPedPtr;   // 0x14: Указатель на пешехода в укрытии
} CoverPoint;

/**
 * @brief Слот в групповом построении.
 * Оригинал IDA: `struct FormationSlot` / `FORM_SLT`
 * Определяет позицию бандита относительно лидера.
 */
typedef struct FormationSlot {
    f32 OffsetX;            // 0x00: Смещение по X от лидера
    f32 OffsetY;            // 0x04: Смещение по Y от лидера
    f32 OffsetZ;            // 0x08: Смещение по Z (этажность)
    u8  Role;               // 0x0C: Роль (Защитник, Атакующий, Медик)
    u8  Priority;           // 0x0D: Приоритет занятия слота
    u16 Reserved;           // 0x0E: Выравнивание
} FormationSlot;

/**
 * @brief Команда скрипта миссии.
 * Оригинал IDA: `struct ScriptCmd` / `SCR_CMD`
 * Массив таких команд образует сценарий миссии.
 */
typedef struct ScriptCommand {
    u16 Opcode;             // 0x00: Код операции (например, 0x01 = SpawnCar)
    u8  ParamCount;         // 0x02: Количество параметров
    u8  Flags;              // 0x03: Флаги (условие, цикл)
    s32 Params[4];          // 0x04: Параметры (ID, координаты, время)
} ScriptCommand;

/**
 * @brief Объем триггера.
 * Оригинал IDA: `struct Trigger` / `TRIG_VOL`
 * Активирует события при входе игрока в зону.
 */
typedef struct TriggerVolume {
    Vector3D Center;        // 0x00: Центр зоны
    f32 RadiusX;            // 0x0C: Радиус по X
    f32 RadiusY;            // 0x10: Радиус по Y
    f32 RadiusZ;            // 0x14: Радиус по Z
    u8  Type;               // 0x18: Тип (Enter, Exit, CameraShot, Damage)
    u8  TriggerCount;       // 0x19: Сколько раз срабатывает (0=бесконечно)
    u16 MissionID;          // 0x1A: ID связанной миссии
    u32 ActionData;         // 0x1C: Данные действия (сообщение, спавн ID)
} TriggerVolume;

/**
 * @brief Реплика пешехода.
 * Оригинал IDA: `struct PedSpeech` / `PED_SPCH`
 * Управление фразами, которые говорит NPC.
 */
typedef struct PedSpeech {
    u16 PhraseID;           // 0x00: ID фразы из банка звуков
    u8  Context;            // 0x02: Контекст (Атака, Боль, Приветствие)
    u8  Priority;           // 0x03: Приоритет воспроизведения
    u32 Timeout;            // 0x04: Задержка перед следующей фразой
    u8  LastSpokenFrame;    // 0x08: Кадр последней сказанной фразы
    u8  Reserved[3];        // 0x09: Выравнивание
} PedSpeech;

/**
 * @brief Таблица наград.
 * Оригинал IDA: `RewardTable` / `RWD_TBL`
 */
typedef struct RewardEntry {
    u8 ActionType;          // Тип действия (Kill, StealCar, CompleteMission)
    u8 TargetType;          // Тип цели (Civilian, Cop, GangMember)
    u16 MoneyReward;        // Награда деньгами
    s16 RespectChange;      // Изменение уважения банды
    u16 WantedStars;        // Добавление звезд розыска
} RewardEntry;

#pragma pack(pop)

#endif // AI_GAMEPLAY_EXT_H
