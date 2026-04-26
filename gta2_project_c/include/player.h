#ifndef PLAYER_H
#define PLAYER_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// Предварительные объявления структур
typedef struct Car Car;
typedef struct WeaponInfo WeaponInfo;
typedef struct Vector3 Vector3;

// Перечисление состояний игрока
typedef enum PlayerState {
    PLAYER_STATE_IDLE = 0,
    PLAYER_STATE_WALK = 1,
    PLAYER_STATE_RUN = 2,
    PLAYER_STATE_SPRINT = 3,
    PLAYER_STATE_DUCK = 4,
    PLAYER_STATE_JUMP = 5,
    PLAYER_STATE_FALL = 6,
    PLAYER_STATE_DEAD = 7,
    PLAYER_STATE_IN_CAR = 8,
    PLAYER_STATE_SWIMMING = 9,
    PLAYER_STATE_AIMING = 10,
    PLAYER_STATE_FIRING = 11
} PlayerState;

// Перечисление типов оружия
typedef enum WeaponType {
    WEAPON_NONE = 0,
    WEAPON_PISTOL = 1,
    WEAPON_SHOTGUN = 2,
    WEAPON_UZI = 3,
    WEAPON_RIFLE = 4,
    WEAPON_ROCKET_LAUNCHER = 5,
    WEAPON_FLAMETHROWER = 6,
    WEAPON_GRENADE = 7,
    WEAPON_MOLOTOV = 8,
    WEAPON_KNIFE = 9,
    WEAPON_BASEBALL_BAT = 10
} WeaponType;

// Структура Player (размер требует уточнения, предположительно > 0x500 байт)
typedef struct Player {
    // Базовые данные (смещения требуют уточнения по asm)
    uint32_t flags;                 // Флаги состояния
    PlayerState state;              // Текущее состояние
    Vector3 position;               // Позиция в мире (x, y, z)
    float heading;                  // Направление (угол)
    float velocity_x;               // Скорость по X
    float velocity_y;               // Скорость по Y
    float velocity_z;               // Скорость по Z
    
    // Здоровье и характеристики
    int16_t health;                 // Здоровье
    int16_t armour;                 // Броня
    int16_t max_health;             // Максимальное здоровье
    uint8_t wanted_level;           // Уровень розыска
    uint8_t pad_0;                  // Выравнивание
    
    // Оружие и инвентарь
    WeaponType current_weapon;      // Текущее оружие
    uint8_t weapon_ammo[12];        // Патроны для каждого типа оружия
    uint32_t money;                 // Деньги игрока
    uint32_t score;                 // Очки
    
    // Транспорт
    Car* current_car;               // Указатель на текущую машину (если внутри)
    int8_t car_seat;                // Место в машине (водитель/пассажир)
    uint8_t pad_1[2];               // Выравнивание
    
    // Анимации и модель
    uint32_t model_index;           // Индекс модели персонажа
    uint32_t anim_index;            // Текущая анимация
    float anim_timer;               // Таймер анимации
    uint8_t colours[4];             // Цвета одежды/тела (R, G, B, A?)
    
    // Временные эффекты
    uint32_t effect_flags;          // Флаги эффектов (огонь, электрошок и т.д.)
    float effect_timer;             // Таймер эффектов
    
    // Резерв для будущих полей (чтобы достичь предполагаемого размера)
    uint8_t reserved[0x400];        // Заглушка, размер требует точного анализа
} Player;

// ============================================================================
// Функции жизненного цикла
// ============================================================================

// Player__Player (Конструктор) - Адрес: TODO, Размер: TODO
void Player_Init(Player* player);

// Player__~Player (Деструктор) - Адрес: TODO, Размер: TODO
void Player_Destroy(Player* player);

// Player__Init - Адрес: TODO, Размер: TODO
void Player_ResetState(Player* player);

// Player__Reset - Адрес: TODO, Размер: TODO
void Player_FullReset(Player* player);

// ============================================================================
// Движение и Физика
// ============================================================================

// Player__ProcessMovement - Адрес: TODO, Размер: TODO
void Player_ProcessMovement(Player* player);

// Player__ApplyGravity - Адрес: TODO, Размер: TODO
void Player_ApplyGravity(Player* player);

// Player__Jump - Адрес: TODO, Размер: TODO
void Player_Jump(Player* player);

// Player__Fall - Адрес: TODO, Размер: TODO
void Player_Fall(Player* player);

// Player__CollideWithWorld - Адрес: TODO, Размер: TODO
bool Player_CollideWithWorld(Player* player, Vector3* pos);

// Player__SetPosition - Адрес: TODO, Размер: TODO
void Player_SetPosition(Player* player, float x, float y, float z);

// Player__GetPosition - Адрес: TODO, Размер: TODO
void Player_GetPosition(Player* player, Vector3* out_pos);

// Player__SetHeading - Адрес: TODO, Размер: TODO
void Player_SetHeading(Player* player, float heading);

// Player__Stop - Адрес: TODO, Размер: TODO
void Player_Stop(Player* player);

// Player__Duck - Адрес: TODO, Размер: TODO
void Player_Duck(Player* player);

// Player__Sprint - Адрес: TODO, Размер: TODO
void Player_Sprint(Player* player);

// ============================================================================
// Бой и Оружие
// ============================================================================

// Player__FireWeapon - Адрес: TODO, Размер: TODO
void Player_FireWeapon(Player* player);

// Player__ReloadWeapon - Адрес: TODO, Размер: TODO
void Player_ReloadWeapon(Player* player);

// Player__SelectWeapon - Адрес: TODO, Размер: TODO
void Player_SelectWeapon(Player* player, WeaponType weapon);

// Player__GiveWeapon - Адрес: TODO, Размер: TODO
void Player_GiveWeapon(Player* player, WeaponType weapon, uint8_t ammo);

// Player__RemoveWeapon - Адрес: TODO, Размер: TODO
void Player_RemoveWeapon(Player* player, WeaponType weapon);

// Player__ThrowGrenade - Адрес: TODO, Размер: TODO
void Player_ThrowGrenade(Player* player);

// Player__MeleeAttack - Адрес: TODO, Размер: TODO
void Player_MeleeAttack(Player* player);

// Player__AimWeapon - Адрес: TODO, Размер: TODO
void Player_AimWeapon(Player* player, float target_x, float target_y);

// Player__GetWeaponType - Адрес: TODO, Размер: TODO
WeaponType Player_GetCurrentWeapon(Player* player);

// ============================================================================
// Здоровье и Состояние
// ============================================================================

// Player__TakeDamage - Адрес: TODO, Размер: TODO
void Player_TakeDamage(Player* player, int16_t damage, uint8_t type);

// Player__Heal - Адрес: TODO, Размер: TODO
void Player_Heal(Player* player, int16_t amount);

// Player__Die - Адрес: TODO, Размер: TODO
void Player_Die(Player* player, uint8_t cause);

// Player__Respawn - Адрес: TODO, Размер: TODO
void Player_Respawn(Player* player, float x, float y, float z);

// Player__SetHealth - Адрес: TODO, Размер: TODO
void Player_SetHealth(Player* player, int16_t health);

// Player__GetHealth - Адрес: TODO, Размер: TODO
int16_t Player_GetHealth(Player* player);

// Player__SetArmour - Адрес: TODO, Размер: TODO
void Player_SetArmour(Player* player, int16_t armour);

// Player__IsDead - Адрес: TODO, Размер: TODO
bool Player_IsDead(Player* player);

// Player__IsInAir - Адрес: TODO, Размер: TODO
bool Player_IsInAir(Player* player);

// Player__IsOnGround - Адрес: TODO, Размер: TODO
bool Player_IsOnGround(Player* player);

// Player__IsSwimming - Адрес: TODO, Размер: TODO
bool Player_IsSwimming(Player* player);

// Player__SetWantedLevel - Адрес: TODO, Размер: TODO
void Player_SetWantedLevel(Player* player, uint8_t level);

// ============================================================================
// Транспорт
// ============================================================================

// Player__EnterCar - Адрес: TODO, Размер: TODO
void Player_EnterCar(Player* player, Car* car, int8_t seat);

// Player__ExitCar - Адрес: TODO, Размер: TODO
void Player_ExitCar(Player* player);

// Player__IsInCar - Адрес: TODO, Размер: TODO
bool Player_IsInCar(Player* player);

// Player__DraggedOutOfCar - Адрес: TODO, Размер: TODO
void Player_DraggedOutOfCar(Player* player);

// Player__GetCarPointer - Адрес: TODO, Размер: TODO
Car* Player_GetCurrentCar(Player* player);

// ============================================================================
// Анимации и Визуал
// ============================================================================

// Player__SetAnim - Адрес: TODO, Размер: TODO
void Player_SetAnimation(Player* player, uint32_t anim_index);

// Player__UpdateAnim - Адрес: TODO, Размер: TODO
void Player_UpdateAnimation(Player* player);

// Player__Draw - Адрес: TODO, Размер: TODO
void Player_Draw(Player* player);

// Player__SetColours - Адрес: TODO, Размер: TODO
void Player_SetColours(Player* player, uint8_t r, uint8_t g, uint8_t b, uint8_t a);

// Player__SetModel - Адрес: TODO, Размер: TODO
void Player_SetModel(Player* player, uint32_t model_index);

// ============================================================================
// Специфичные для GTA 2
// ============================================================================

// Player__UsePowerup - Адрес: TODO, Размер: TODO
void Player_UsePowerup(Player* player, uint8_t powerup_id);

// Player__CommitCrime - Адрес: TODO, Размер: TODO
void Player_CommitCrime(Player* player, uint8_t crime_type, float x, float y);

// Player__BribeCops - Адрес: TODO, Размер: TODO
void Player_BribeCops(Player* player, uint32_t amount);

// Player__GetMoney - Адрес: TODO, Размер: TODO
uint32_t Player_GetMoney(Player* player);

// Player__SpendMoney - Адрес: TODO, Размер: TODO
bool Player_SpendMoney(Player* player, uint32_t amount);

#ifdef __cplusplus
}
#endif

#endif // PLAYER_H
