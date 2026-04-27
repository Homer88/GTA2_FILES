#ifndef PLAYER_H
#define PLAYER_H

#include <stdint.h>
#include <stdbool.h>

// Предварительные объявления структур
struct Car;
struct Vector3;

// Перечисление состояний игрока
enum class PlayerState : uint8_t {
    IDLE = 0,
    WALK = 1,
    RUN = 2,
    SPRINT = 3,
    DUCK = 4,
    JUMP = 5,
    FALL = 6,
    DEAD = 7,
    IN_CAR = 8,
    SWIMMING = 9,
    AIMING = 10,
    FIRING = 11
};

// Перечисление типов оружия
enum class WeaponType : uint8_t {
    NONE = 0,
    PISTOL = 1,
    SHOTGUN = 2,
    UZI = 3,
    RIFLE = 4,
    ROCKET_LAUNCHER = 5,
    FLAMETHROWER = 6,
    GRENADE = 7,
    MOLOTOV = 8,
    KNIFE = 9,
    BASEBALL_BAT = 10
};

// Структура Player (размер требует уточнения, предположительно > 0x500 байт)
class Player {
public:
    // Базовые данные (смещения требуют уточнения по asm)
    uint32_t flags;                 // Флаги состояния - offset 0x0
    PlayerState state;              // Текущее состояние - offset 0x4
    // Vector3 position;            // Позиция в мире (x, y, z) - offset 0x8
    float pos_x;                    // Позиция X
    float pos_y;                    // Позиция Y
    float pos_z;                    // Позиция Z
    float heading;                  // Направление (угол) - offset 0x14
    float velocity_x;               // Скорость по X - offset 0x18
    float velocity_y;               // Скорость по Y - offset 0x1C
    float velocity_z;               // Скорость по Z - offset 0x20
    
    // Здоровье и характеристики
    int16_t health;                 // Здоровье - offset 0x24
    int16_t armour;                 // Броня - offset 0x26
    int16_t max_health;             // Максимальное здоровье - offset 0x28
    uint8_t wanted_level;           // Уровень розыска - offset 0x2A
    uint8_t pad_0;                  // Выравнивание - offset 0x2B
    
    // Оружие и инвентарь
    WeaponType current_weapon;      // Текущее оружие - offset 0x2C
    uint8_t weapon_ammo[12];        // Патроны для каждого типа оружия - offset 0x2D
    uint32_t money;                 // Деньги игрока - offset 0x39
    uint32_t score;                 // Очки - offset 0x3D
    
    // Транспорт
    struct Car* current_car;        // Указатель на текущую машину - offset 0x41
    int8_t car_seat;                // Место в машине - offset 0x45
    uint8_t pad_1[2];               // Выравнивание - offset 0x46
    
    // Анимации и модель
    uint32_t model_index;           // Индекс модели персонажа - offset 0x48
    uint32_t anim_index;            // Текущая анимация - offset 0x4C
    float anim_timer;               // Таймер анимации - offset 0x50
    uint8_t colours[4];             // Цвета одежды/тела - offset 0x54
    
    // Временные эффекты
    uint32_t effect_flags;          // Флаги эффектов - offset 0x58
    float effect_timer;             // Таймер эффектов - offset 0x5C
    
    // Резерв для будущих полей
    uint8_t reserved[0x400];        // Заглушка - offset 0x60

public:
    // ========================================================================
    // Жизненный цикл
    // ========================================================================
    
    // Player__Player (Конструктор) - Адрес: TODO, Размер: TODO
    Player();
    
    // Player__~Player (Деструктор) - Адрес: TODO, Размер: TODO
    ~Player();
    
    // Player__Init - Адрес: TODO, Размер: TODO
    void Init();
    
    // Player__Reset - Адрес: TODO, Размер: TODO
    void Reset();
    
    // ========================================================================
    // Движение и Физика
    // ========================================================================
    
    // Player__ProcessMovement - Адрес: TODO, Размер: TODO
    void ProcessMovement();
    
    // Player__ApplyGravity - Адрес: TODO, Размер: TODO
    void ApplyGravity();
    
    // Player__Jump - Адрес: TODO, Размер: TODO
    void Jump();
    
    // Player__Fall - Адрес: TODO, Размер: TODO
    void Fall();
    
    // Player__CollideWithWorld - Адрес: TODO, Размер: TODO
    bool CollideWithWorld(struct Vector3* pos);
    
    // Player__SetPosition - Адрес: TODO, Размер: TODO
    void SetPosition(float x, float y, float z);
    
    // Player__GetPosition - Адрес: TODO, Размер: TODO
    void GetPosition(struct Vector3* out_pos);
    
    // Player__SetHeading - Адрес: TODO, Размер: TODO
    void SetHeading(float heading);
    
    // Player__Stop - Адрес: TODO, Размер: TODO
    void Stop();
    
    // Player__Duck - Адрес: TODO, Размер: TODO
    void Duck();
    
    // Player__Sprint - Адрес: TODO, Размер: TODO
    void Sprint();
    
    // ========================================================================
    // Бой и Оружие
    // ========================================================================
    
    // Player__FireWeapon - Адрес: TODO, Размер: TODO
    void FireWeapon();
    
    // Player__ReloadWeapon - Адрес: TODO, Размер: TODO
    void ReloadWeapon();
    
    // Player__SelectWeapon - Адрес: TODO, Размер: TODO
    void SelectWeapon(WeaponType weapon);
    
    // Player__GiveWeapon - Адрес: TODO, Размер: TODO
    void GiveWeapon(WeaponType weapon, uint8_t ammo);
    
    // Player__RemoveWeapon - Адрес: TODO, Размер: TODO
    void RemoveWeapon(WeaponType weapon);
    
    // Player__ThrowGrenade - Адрес: TODO, Размер: TODO
    void ThrowGrenade();
    
    // Player__MeleeAttack - Адрес: TODO, Размер: TODO
    void MeleeAttack();
    
    // Player__AimWeapon - Адрес: TODO, Размер: TODO
    void AimWeapon(float target_x, float target_y);
    
    // Player__GetWeaponType - Адрес: TODO, Размер: TODO
    WeaponType GetWeaponType() const;
    
    // ========================================================================
    // Здоровье и Состояние
    // ========================================================================
    
    // Player__TakeDamage - Адрес: TODO, Размер: TODO
    void TakeDamage(int16_t damage, uint8_t type);
    
    // Player__Heal - Адрес: TODO, Размер: TODO
    void Heal(int16_t amount);
    
    // Player__Die - Адрес: TODO, Размер: TODO
    void Die(uint8_t cause);
    
    // Player__Respawn - Адрес: TODO, Размер: TODO
    void Respawn(float x, float y, float z);
    
    // Player__SetHealth - Адрес: TODO, Размер: TODO
    void SetHealth(int16_t health);
    
    // Player__GetHealth - Адрес: TODO, Размер: TODO
    int16_t GetHealth() const;
    
    // Player__SetArmour - Адрес: TODO, Размер: TODO
    void SetArmour(int16_t armour);
    
    // Player__IsDead - Адрес: TODO, Размер: TODO
    bool IsDead() const;
    
    // Player__IsInAir - Адрес: TODO, Размер: TODO
    bool IsInAir() const;
    
    // Player__IsOnGround - Адрес: TODO, Размер: TODO
    bool IsOnGround() const;
    
    // Player__IsSwimming - Адрес: TODO, Размер: TODO
    bool IsSwimming() const;
    
    // Player__SetWantedLevel - Адрес: TODO, Размер: TODO
    void SetWantedLevel(uint8_t level);
    
    // ========================================================================
    // Транспорт
    // ========================================================================
    
    // Player__EnterCar - Адрес: TODO, Размер: TODO
    void EnterCar(struct Car* car, int8_t seat);
    
    // Player__ExitCar - Адрес: TODO, Размер: TODO
    void ExitCar();
    
    // Player__IsInCar - Адрес: TODO, Размер: TODO
    bool IsInCar() const;
    
    // Player__DraggedOutOfCar - Адрес: TODO, Размер: TODO
    void DraggedOutOfCar();
    
    // Player__GetCarPointer - Адрес: TODO, Размер: TODO
    struct Car* GetCarPointer() const;
    
    // ========================================================================
    // Анимации и Визуал
    // ========================================================================
    
    // Player__SetAnim - Адрес: TODO, Размер: TODO
    void SetAnim(uint32_t anim_index);
    
    // Player__UpdateAnim - Адрес: TODO, Размер: TODO
    void UpdateAnim();
    
    // Player__Draw - Адрес: TODO, Размер: TODO
    void Draw();
    
    // Player__SetColours - Адрес: TODO, Размер: TODO
    void SetColours(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
    
    // Player__SetModel - Адрес: TODO, Размер: TODO
    void SetModel(uint32_t model_index);
    
    // ========================================================================
    // Специфичные для GTA 2
    // ========================================================================
    
    // Player__UsePowerup - Адрес: TODO, Размер: TODO
    void UsePowerup(uint8_t powerup_id);
    
    // Player__CommitCrime - Адрес: TODO, Размер: TODO
    void CommitCrime(uint8_t crime_type, float x, float y);
    
    // Player__BribeCops - Адрес: TODO, Размер: TODO
    void BribeCops(uint32_t amount);
    
    // Player__GetMoney - Адрес: TODO, Размер: TODO
    uint32_t GetMoney() const;
    
    // Player__SpendMoney - Адрес: TODO, Размер: TODO
    bool SpendMoney(uint32_t amount);
};

#endif // PLAYER_H
