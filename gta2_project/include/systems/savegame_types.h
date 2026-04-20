#ifndef SAVEGAME_TYPES_H
#define SAVEGAME_TYPES_H

#include "core/types.h"

#define SAVE_MAGIC 0x47544132  // "GTA2" в little-endian
#define SAVE_VERSION 1
#define MAX_SAVE_SLOTS 10
#define PLAYER_NAME_LENGTH 32

/**
 * Статус сохранения
 */
typedef enum SaveStatus {
    SAVE_OK = 0,
    SAVE_ERROR = 1,
    SAVE_CORRUPTED = 2,
    SAVE_NOT_FOUND = 3,
    SAVE_INCOMPATIBLE = 4
} SaveStatus;

/**
 * Статистика игрока для сохранения
 * Размер: ~64 байта
 */
typedef struct PlayerStats {
    s32 Money;                  // 0x0 - Деньги
    s32 Respect;                // 0x4 - Уважение
    u32 Kills;                  // 0x8 - Всего убито
    u32 Deaths;                 // 0xC - Всего смертей
    u32 MissionsCompleted;      // 0x10 - Выполнено миссий
    u32 MissionsFailed;         // 0x14 - Провалено миссий
    u32 TimePlayed;             // 0x18 - Время игры (секунды)
    u32 DistanceTraveled;       // 0x1C - Пройдено метров
    u32 CarsStolen;             // 0x20 - Украдено машин
    u32 PeopleRunOver;          // 0x24 - Сбито пешеходов
    u16 HighestWantedLevel;     // 0x28 - Макс уровень розыска
    u16 Padding;                // 0x2A - Выравнивание
    u8 FavoriteWeapon;          // 0x2C - Любимое оружие
    u8 Padding2[3];             // Выравнивание
} PlayerStats;

/**
 * Состояние игрока
 * Размер: ~128 байт
 */
typedef struct PlayerState {
    char Name[PLAYER_NAME_LENGTH];  // 0x0 - Имя игрока
    f32 PositionX;                  // 0x20 - Позиция X
    f32 PositionY;                  // 0x24 - Позиция Y
    f32 Health;                     // 0x28 - Здоровье
    f32 Armor;                      // 0x2C - Броня
    u8 WantedLevel;                 // 0x30 - Уровень розыска
    u8 CurrentWeapon;               // 0x31 - Текущее оружие
    u8 PedType;                     // 0x32 - Тип персонажа
    u8 Padding1;                    // 0x33 - Выравнивание
    
    s32 Ammo[16];                   // 0x34 - Патроны для каждого типа оружия
    u8 HasWeapon[16];               // 0x74 - Флаги наличия оружия
    u8 Padding2[4];                 // Выравнивание
    
    PlayerStats Stats;              // 0x7C - Статистика
} PlayerState;

/**
 * Состояние мира
 * Размер: ~64 байта
 */
typedef struct WorldState {
    u32 CurrentMissionId;           // 0x0 - Текущая миссия
    u32 CompletedMissionsMask;      // 0x4 - Масшта выполненных миссий (битовая)
    f32 TimeOfDay;                  // 0x8 - Время суток (0.0-24.0)
    u8 Weather;                     // 0xC - Погода (0=ясно, 1=дождь, 2=туман)
    u8 DayNumber;                   // 0xD - Номер дня
    u16 Padding;                    // 0xE - Выравнивание
    
    u32 DestroyedBuildings;         // 0x10 - Разрушено зданий
    u32 SpawnedCars;                // 0x14 - Заспавнено машин
    u32 KilledPeds;                 // 0x18 - Убито NPC
    f32 LastSaveX;                  // 0x1C - Последнее сохранение X
    f32 LastSaveY;                  // 0x20 - Последнее сохранение Y
    u8 Padding2[8];                 // Резерв
} WorldState;

/**
 * Заголовок файла сохранения
 * Размер: 64 байта
 */
typedef struct SaveHeader {
    u32 Magic;                      // 0x0 - Магическое число "GTA2"
    u32 Version;                    // 0x4 - Версия формата
    u32 FileSize;                   // 0x8 - Размер файла
    u32 Checksum;                   // 0xC - Контрольная сумма
    
    char GameVersion[16];           // 0x10 - Версия игры
    u32 Timestamp;                  // 0x20 - Время сохранения (Unix time)
    
    u8 SlotIndex;                   // 0x24 - Индекс слота
    u8 IsValid;                     // 0x25 - Валидно ли сохранение
    u16 Padding;                    // 0x26 - Выравнивание
    
    char ScreenshotName[32];        // 0x28 - Имя файла скриншота
    u8 Padding2[4];                 // Выравнивание до 64 байт
} SaveHeader;

/**
 * Структура слота сохранения
 * Размер: ~256 байт + данные
 */
typedef struct SaveSlot {
    SaveHeader Header;              // 0x0 - Заголовок
    PlayerState Player;             // 0x40 - Состояние игрока
    WorldState World;               // 0xC0 - Состояние мира
    u8 Reserved[64];                // 0x100 - Резерв для будущих версий
    u32 ChecksumData;               // 0x140 - Контрольная сумма данных
    u8 Padding[12];                 // Выравнивание до 256 байт
} SaveSlot;

#endif // SAVEGAME_TYPES_H
