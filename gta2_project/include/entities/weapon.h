#ifndef WEAPON_H
#define WEAPON_H

#include "../types.h"
#include "../enums.h"
#include "math_types/vector2d.h"

/**
 * Типы оружия в GTA 2
 */
typedef enum WeaponType {
    WEAPON_NONE = 0,
    WEAPON_FIST = 1,            // Кулаки
    WEAPON_KNIFE = 2,           // Нож
    WEAPON_BASEBALL_BAT = 3,    // Бита
    WEAPON_CHAINSAW = 4,        // Бензопила
    WEAPON_PISTOL = 5,          // Пистолет
    WEAPON_UZI = 6,             // Узи
    WEAPON_SHOTGUN = 7,         // Дробовик
    WEAPON_AK47 = 8,            // Автомат
    WEAPON_SNIPER = 9,          // Снайперка
    WEAPON_FLAMETHROWER = 10,   // Огнемёт
    WEAPON_ROCKET_LAUNCHER = 11,// РПГ
    WEAPON_GRENADE = 12,        // Граната
    WEAPON_MOLOTOV = 13,        // Коктейль Молотова
    WEAPON_MINE = 14,           // Мина
    WEAPON_TESLA = 15           // Тесла-пушка (секретное)
} WeaponType;

/**
 * Состояние оружия
 */
typedef enum WeaponState {
    WSTATE_IDLE = 0,            // Бездействие
    WSTATE_AIMING = 1,          // Прицеливание
    WSTATE_FIRING = 2,          // Стрельба
    WSTATE_RELOADING = 3,       // Перезарядка
    WSTATE_COOLDOWN = 4,        // Перезарядка/остывание
    WSTATE_JAMMED = 5           // Заклинило (редко)
} WeaponState;

/**
 * Структура пули/снаряда
 * Размер: ~48 байт
 */
typedef struct Projectile {
    Vector2D Position;          // 0x0 - Позиция
    Vector2D Velocity;          // 0x8 - Вектор скорости
    f32 Damage;                 // 0x10 - Урон
    f32 Radius;                 // 0x14 - Радиус взрыва (для гранат)
    u8 Type;                    // 0x18 - Тип снаряда (пуля, граната, ракета)
    u8 State;                   // 0x19 - Состояние (активен, взорван)
    u16 OwnerId;                // 0x1A - ID владельца (кто выстрелил)
    f32 Timer;                  // 0x1C - Таймер жизни
    f32 Gravity;                // 0x20 - Гравитация (для гранат)
    u8 Padding[12];             // Выравнивание
} Projectile;

/**
 * Структура оружия
 * Размер: ~64 байта
 */
typedef struct Weapon {
    // Основное
    WeaponType Type;            // 0x0 - Тип оружия
    WeaponState State;          // 0x4 - Текущее состояние
    
    // Патроны
    u16 AmmoCurrent;            // 0x8 - Текущие патроны в магазине
    u16 AmmoReserve;            // 0xA - Запасные патроны
    u16 MaxAmmoClip;            // 0xC - Вместимость магазина
    u16 MaxAmmoReserve;         // 0xE - Максимум запаса
    
    // Таймеры
    f32 FireTimer;              // 0x10 - Таймер между выстрелами
    f32 ReloadTimer;            // 0x14 - Таймер перезарядки
    f32 CooldownTimer;          // 0x18 - Таймер остывания
    
    // Параметры стрельбы
    f32 FireRate;               // 0x1C - Скорострельность (выстрелов/сек)
    f32 Damage;                 // 0x20 - Базовый урон
    f32 Range;                  // 0x24 - Дальность
    f32 Accuracy;               // 0x28 - Точность (0.0-1.0)
    f32 Spread;                 // 0x2C - Разброс
    
    // Отдача и эффекты
    f32 Recoil;                 // 0x30 - Сила отдачи
    f32 OverheatTimer;          // 0x34 - Таймер перегрева
    f32 OverheatThreshold;      // 0x38 - Порог перегрева
    
    // Владелец и звуки
    void* Owner;                // 0x3C - Указатель на владельца (Ped*)
    u8 SoundId;                 // 0x40 - ID звука выстрела
    u8 Flags;                   // 0x41 - Флаги оружия
    u16 Padding;                // 0x42 - Выравнивание
    
    // Дополнительно
    f32 ChargeTimer;            // 0x44 - Таймер зарядки (для огнемёта, теслы)
    u8 JamChance;               // 0x48 - Шанс заклинивания (0-100%)
    u8 Padding2[3];             // Выравнивание
} Weapon;

// Флаги оружия
#define WFLAG_AUTO_FIRE         0x01    // Автоматический огонь
#define WFLAG_SEMI_AUTO         0x02    // Полуавтомат
#define WFLAG_EXPLOSIVE         0x04    // Взрывчатое
#define WFLAG_FLAME             0x08    // Огонь
#define WFLAG_SILENCED          0x10    // Глушитель
#define WFLAG_JAMMED            0x20    // Заклинило

/**
 * Инициализация оружия
 * @param weapon Указатель на структуру оружия
 * @param type Тип оружия
 */
void Weapon_Init(Weapon* weapon, WeaponType type);

/**
 * Обновление оружия (таймеры, перезарядка)
 * @param weapon Указатель на оружие
 * @param dt Delta time
 */
void Weapon_Update(Weapon* weapon, f32 dt);

/**
 * Попытка выстрела
 * @param weapon Указатель на оружие
 * @param targetX Целевая позиция X
 * @param targetY Целевая позиция Y
 * @return true если выстрел успешен
 */
bool Weapon_Fire(Weapon* weapon, f32 targetX, f32 targetY);

/**
 * Перезарядка
 * @param weapon Указатель на оружие
 * @return true если началась перезарядка
 */
bool Weapon_Reload(Weapon* weapon);

/**
 * Добавление патронов
 * @param weapon Указатель на оружие
 * @param amount Количество патронов
 */
void Weapon_AddAmmo(Weapon* weapon, u16 amount);

/**
 * Проверка доступности огня
 * @param weapon Указатель на оружие
 * @return true если можно стрелять
 */
bool Weapon_CanFire(Weapon* weapon);

/**
 * Создание снаряда
 * @param proj Указатель на структуру снаряда
 * @param weapon Исходное оружие
 * @param startX Начальная позиция X
 * @param startY Начальная позиция Y
 * @param dirX Вектор направления X
 * @param dirY Вектор направления Y
 */
void Projectile_Spawn(Projectile* proj, Weapon* weapon, 
                      f32 startX, f32 startY, f32 dirX, f32 dirY);

/**
 * Обновление снаряда
 * @param proj Указатель на снаряд
 * @param dt Delta time
 * @return false если снаряд уничтожен
 */
bool Projectile_Update(Projectile* proj, f32 dt);

#endif // WEAPON_H
