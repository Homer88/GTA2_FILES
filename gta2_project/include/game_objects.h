#ifndef GAME_OBJECTS_H
#define GAME_OBJECTS_H

#include "types.h"
#include "math_types/vector2d.h"

// ============================================================================
// 1. PICKUP (Подбираемые предметы: аптечки, оружие, деньги, бонусы)
// ============================================================================

typedef enum {
    PICKUP_NONE = 0,
    PICKUP_HEALTH = 1,
    PICKUP_ARMOR = 2,
    PICKUP_WEAPON_PISTOL = 3,
    PICKUP_WEAPON_UZI = 4,
    PICKUP_WEAPON_SHOTGUN = 5,
    PICKUP_WEAPON_AK47 = 6,
    PICKUP_WEAPON_FLAME = 7,
    PICKUP_MONEY = 8,
    PICKUP_BONUS_MULTIPLIER = 9,
    PICKUP_KEYCARD = 10,
    PICKUP_INVISIBILITY = 11
} PickupType;

typedef struct {
    Vector2D Position;      // 0x00 - Координаты X, Y
    f32 Height;             // 0x08 - Высота над землей (для анимации парения)
    PickupType Type;        // 0x0C - Тип предмета
    u8 State;               // 0x0E - Состояние (0=скрыт, 1=активен, 2=поднят)
    u8 RotationAngle;       // 0x0F - Текущий угол вращения (визуал)
    u32 RespawnTimer;       // 0x10 - Таймер до повторного появления
    u32 Value;              // 0x14 - Значение (кол-во денег, патронов)
    u8 IsActive;            // 0x18 - Флаг активности
    u8 Padding[3];          // 0x19 - Выравнивание
} Pickup;                   // Размер: 24 байта

// ============================================================================
// 2. CHECKPOINT (Контрольные точки: гонки, сохранение, триггеры миссий)
// ============================================================================

typedef enum {
    CHECKPOINT_RACE = 0,
    CHECKPOINT_SAVE = 1,
    CHECKPOINT_MISSION_TRIGGER = 2,
    CHECKPOINT_HIDDEN_PACKAGE = 3
} CheckpointType;

typedef struct {
    Vector2D Position;      // 0x00 - Центр точки
    f32 Radius;             // 0x08 - Радиус активации
    CheckpointType Type;    // 0x0C - Тип контрольной точки
    u8 IsActivated;         // 0x0E - Была ли уже активирована
    u8 ZoneID;              // 0x0F - ID связанной зоны
    u16 MissionID;          // 0x10 - ID связанной миссии (если триггер)
    u32 BonusMoney;         // 0x12 - Награда за прохождение
} Checkpoint;               // Размер: ~20 байт

// ============================================================================
// 3. PHONE_BOOTH (Телефонные будки: прием миссий, связь)
// ============================================================================

typedef struct Ped Ped; // Forward declaration

typedef enum {
    PHONE_FREE = 0,
    PHONE_IN_USE = 1,
    PHONE_BROKEN = 2
} PhoneState;

typedef struct {
    Vector2D Position;      // 0x00 - Координаты будки
    PhoneState State;       // 0x08 - Состояние (свободен/занят/сломан)
    u8 Padding[3];          // 0x09 - Выравнивание
    u16 MissionID;          // 0x0C - ID миссии, которую дает этот телефон
    Ped* CurrentUser;       // 0x0E - Указатель на пешехода, который говорит по телефону
    u32 UsageTimer;         // 0x12 - Таймер использования (для блокировки)
    u8 IsAvailable;         // 0x16 - Доступен ли для игрока
    u8 Padding2[1];         // 0x17 - Выравнивание
} PhoneBooth;               // Размер: 24 байта

// ============================================================================
// 4. SHOP (Магазины: оружие, броня, лечение)
// ============================================================================

typedef enum {
    SHOP_WEAPONS = 0,
    SHOP_FOOD = 1,
    SHOP_CLOTHES = 2,
    SHOP_CAR_DEALER = 3,
    SHOP_HOSPITAL = 4
} ShopType;

typedef struct {
    Vector2D Position;      // 0x00 - Вход в магазин
    f32 EnterRadius;        // 0x08 - Радиус входа
    ShopType Type;          // 0x0C - Тип магазина
    u8 IsOpen;              // 0x0E - Открыт ли сейчас (время работы)
    u8 HourOpen;            // 0x0F - Час открытия
    u8 HourClose;           // 0x10 - Час закрытия
    u8 Padding;             // 0x11 - Выравнивание
    u32 Prices[4];          // 0x12 - Цены на товары (4 слота)
    u8 Stock[4];            // 0x22 - Наличие товаров (0-100%)
    u8 Padding2[2];         // 0x26 - Выравнивание
} Shop;                     // Размер: ~40 байт

// ============================================================================
// 5. MOVING_PLATFORM (Подвижные платформы, лифты)
// ============================================================================

typedef enum {
    PLATFORM_IDLE = 0,
    PLATFORM_MOVING_FWD = 1,
    PLATFORM_MOVING_BACK = 2,
    PLATFORM_WAITING = 3
} PlatformState;

typedef struct {
    Vector2D StartPos;      // 0x00 - Начальная точка
    Vector2D EndPos;        // 0x08 - Конечная точка
    f32 Speed;              // 0x10 - Скорость движения
    f32 CurrentPos;         // 0x14 - Текущее положение (0.0 - 1.0 между Start и End)
    PlatformState State;    // 0x18 - Текущее состояние
    u8 WaitTimer;           // 0x19 - Таймер ожидания перед движением
    u8 Padding[2];          // 0x1A - Выравнивание
    u32 DamageOnCrush;      // 0x1C - Урон при раздавливании
} MovingPlatform;           // Размер: 32 байта

// ============================================================================
// МЕНЕДЖЕР ОБЪЕКТОВ (Глобальный пул)
// ============================================================================

#define MAX_PICKUPS 256
#define MAX_CHECKPOINTS 64
#define MAX_PHONES 32
#define MAX_SHOPS 16
#define MAX_PLATFORMS 16

typedef struct {
    Pickup Pickups[MAX_PICKUPS];
    u8 PickupActiveMap[(MAX_PICKUPS + 7) / 8]; // Битовая карта
    
    Checkpoint Checkpoints[MAX_CHECKPOINTS];
    u8 CheckpointActiveMap[(MAX_CHECKPOINTS + 7) / 8];
    
    PhoneBooth Phones[MAX_PHONES];
    Shop Shops[MAX_SHOPS];
    MovingPlatform Platforms[MAX_PLATFORMS];
    
    u32 TotalPickupsSpawned;
    u32 TotalCheckpointsTriggered;
} WorldObjectsManager;

// ============================================================================
// ПРОТОТИПЫ ФУНКЦИЙ
// ============================================================================

// Pickup Functions
void Pickup_Init(Pickup* p, PickupType type, Vector2D pos, u32 value);
void Pickup_Update(Pickup* p, f32 dt);
bool Pickup_TryCollect(Pickup* p, void* collector); // collector может быть Ped* или Player*
void Pickup_Spawn(PickupType type, Vector2D pos, u32 value);

// Checkpoint Functions
void Checkpoint_Init(Checkpoint* c, CheckpointType type, Vector2D pos, f32 radius);
bool Checkpoint_Trigger(Checkpoint* c, void* entity);

// PhoneBooth Functions
void PhoneBooth_Init(PhoneBooth* ph, Vector2D pos, u16 missionId);
bool PhoneBooth_Use(PhoneBooth* ph, Ped* user);
void PhoneBooth_Update(PhoneBooth* ph, f32 dt);

// Shop Functions
bool Shop_IsOpen(Shop* s, u8 currentHour);
bool Shop_TryBuy(Shop* s, u8 itemIndex, u32* money);

// MovingPlatform Functions
void MovingPlatform_Init(MovingPlatform* mp, Vector2D start, Vector2D end, f32 speed);
void MovingPlatform_Update(MovingPlatform* mp, f32 dt);
bool MovingPlatform_CheckCrush(MovingPlatform* mp, void* entity);

// Manager Functions
void WorldObjects_Init(void);
void WorldObjects_UpdateAll(f32 dt, u8 currentHour);
Pickup* WorldObjects_FindNearestPickup(Vector2D pos, f32 radius);

#endif // GAME_OBJECTS_H
