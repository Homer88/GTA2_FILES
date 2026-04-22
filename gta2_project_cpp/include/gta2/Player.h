/**
 * @file Player.h
 * @brief Структура игрока (Player) - управление, инвентарь, миссии
 * 
 * Адрес структуры в дампе: line 5807 в gta2.exe.h
 * Размер: 0x8B0 (2224 байта)
 * Основано на: gta2.exe/ida_pro/gta2.exe.h, gta2.exe.map
 * 
 * Функции: 232 функции из gta2.exe.map
 */

#pragma once

#include <cstdint>

// Forward declarations
struct Ped;
struct Car;
struct Weapon;
struct Gang;

#pragma pack(push, 1)

struct Player
{
    // === Базовые поля (наследуется от GameObject концептуально) ===
    void* vtable;                       // 0x0000 - VTable
    int ID;                             // 0x0004 - Идентификатор игрока
    int Flags;                          // 0x0008 - Флаги состояния
    
    // === Связанные объекты ===
    Ped* pMainPed;                      // 0x000C - Главный Ped игрока
    Ped* pCurrentPed;                   // 0x0010 - Текущий управляемый Ped
    Car* pCurrentCar;                   // 0x0014 - Текущий автомобиль
    Weapon* pCurrentWeapon;             // 0x0018 - Текущее оружие
    
    // === Деньги и репутация ===
    int Money;                          // 0x001C - Деньги
    int Respect;                        // 0x0020 - Репутация
    int MultiplayerScore;               // 0x0024 - Счет в мультиплеере
    
    // === Состояние игрока ===
    int PlayerState;                    // 0x0028 - Состояние игрока
    int AttackChanged;                  // 0x002C - Флаг изменения атаки
    int ActionAllowed;                  // 0x0030 - Разрешенные действия
    
    // === Power-ups ===
    int PowerUpCount;                   // 0x0034 - Количество power-up
    int MultiPlayerMode;                // 0x0038 - Режим мультиплеера
    
    // === Координаты и позиция ===
    float SpawnX;                       // 0x003C - Точка спавна X
    float SpawnY;                       // 0x0040 - Точка спавна Y
    float SpawnZ;                       // 0x0044 - Точка спавна Z
    
    // === Миссии и прогресс ===
    int CurrentMission;                 // 0x0048 - Текущая миссия
    int MissionProgress;                // 0x004C - Прогресс миссии
    int CompletedMissions;              // 0x0050 - Завершенные миссии
    
    // === Гангстерские отношения ===
    int GangRespect[8];                 // 0x0054 - Отношения с бандами (8 гангов)
    
    // === Инвентарь ===
    Weapon* Inventory[16];              // 0x0074 - Инвентарь оружия (16 слотов)
    int Ammo[16];                       // 0x00B4 - Патроны для каждого оружия
    
    // === Управление ===
    int ControlFlags;                   // 0x00F4 - Флаги управления
    int InputState;                     // 0x00F8 - Состояние ввода
    
    // === Камера и вид ===
    float CameraX;                      // 0x00FC - Позиция камеры X
    float CameraY;                      // 0x0100 - Позиция камеры Y
    float CameraZ;                      // 0x0104 - Позиция камеры Z
    float CameraAngle;                  // 0x0108 - Угол камеры
    
    // === Статистика ===
    int Kills;                          // 0x010C - Количество убийств
    int Deaths;                         // 0x0110 - Количество смертей
    int Arrests;                        // 0x0114 - Количество арестов
    int CarsStolen;                     // 0x0118 - Украденные машины
    int DistanceTraveled;               // 0x011C - Пройденное расстояние
    
    // === Прочие поля ===
    char reserved[0x8B0 - 0x120];       // Заполнитель до размера структуры
};

#pragma pack(pop)


// ============================================================================
// ФУНКЦИИ PLAYER (адреса из gta2.exe.map)
// Всего: 232 функции
// ============================================================================


// === Основные функции управления ===
#ifdef __cplusplus
extern "C" {
#endif
// Адрес: 0x00401B40 - Player__sub_401B40
void Player__sub_401B40(Player* player);

// Адрес: 0x0040BE50 - Player__CheckCondition
int Player__CheckCondition(Player* player);

// Адрес: 0x0040BE70 - Player__sub_40CE70
void Player__sub_40CE70(Player* player);

// Адрес: 0x0040E530 - Player__sub_40E530
void Player__sub_40E530(Player* player);

// Адрес: 0x0040E570 - Player__IsCurrentPlayer
bool Player__IsCurrentPlayer(Player* player);

// Адрес: 0x0040EC20 - Player__sub_40EC20
void Player__sub_40EC20(Player* player);

// Адрес: 0x0040F840 - Player__sub_40F840
void Player__sub_40F840(Player* player);

// Адрес: 0x00411810 - Player__sub_411810
void Player__sub_411810(Player* player);

// Адрес: 0x00411820 - Player__sub_411820
void Player__sub_411820(Player* player);

// Адрес: 0x00411830 - Player__sub_411830
void Player__sub_411830(Player* player);

// Адрес: 0x00411840 - Player__sub_411840
void Player__sub_411840(Player* player);

// Адрес: 0x00411850 - Player__sub_411850
void Player__sub_411850(Player* player);

// Адрес: 0x00411860 - Player__sub_411860
void Player__sub_411860(Player* player);

// Адрес: 0x0041D260 - Player__GetPed
Ped* Player__GetPed(Player* player);

// Адрес: 0x0041DC40 - Player__AddMoney
void Player__AddMoney(Player* player, int amount);

// Адрес: 0x0041DC70 - Player__GetCurrentPlayer
Player* Player__GetCurrentPlayer();

// Адрес: 0x0041E260 - Player__sub_41E260
void Player__sub_41E260(Player* player);

// Адрес: 0x0041E390 - Player__IsActionAllowed
bool Player__IsActionAllowed(Player* player, int action);

// Адрес: 0x00421100 - Player__sub_421100
void Player__sub_421100(Player* player);

// Адрес: 0x00421150 - Player__sub_421150
void Player__sub_421150(Player* player);

// Адрес: 0x004211A0 - Player__sub_4211A0
void Player__sub_4211A0(Player* player);

// Адрес: 0x004211C0 - Player__sub_4211C0
void Player__sub_4211C0(Player* player);

// Адрес: 0x00421260 - Player__sub_421260
void Player__sub_421260(Player* player);

// Адрес: 0x00421270 - Player__sub_421270
void Player__sub_421270(Player* player);

// Адрес: 0x004212A0 - Player__SetAttackChanged
void Player__SetAttackChanged(Player* player, int changed);

// Адрес: 0x004212B0 - Player__SetAttackIsChanged
void Player__SetAttackIsChanged(Player* player, int isChanged);

// Адрес: 0x00421980 - Player__GetMoneyPlayer
int Player__GetMoneyPlayer(Player* player);

// Адрес: 0x00421990 - Player__DecreaseInMoney
void Player__DecreaseInMoney(Player* player, int amount);

// Адрес: 0x004219A0 - Player__sub_4219A0
void Player__sub_4219A0(Player* player);

// Адрес: 0x004219D0 - Player__GetId
int Player__GetId(Player* player);

// Адрес: 0x00424470 - Player__NotMoney
bool Player__NotMoney(Player* player);

// Адрес: 0x004348F0 - Player__sub_4348F0
void Player__sub_4348F0(Player* player);

// Адрес: 0x00434900 - Player__GetMultiPlayerMode
int Player__GetMultiPlayerMode(Player* player);

// Адрес: 0x00434920 - Player__GetPowerUp
int Player__GetPowerUp(Player* player);

// Адрес: 0x00434940 - Player__DecrPowerUp
void Player__DecrPowerUp(Player* player);

// Адрес: 0x00434950 - Player__SetPlayerState
void Player__SetPlayerState(Player* player, int state);

// Адрес: 0x00434B20 - Player__sub_434B20
void Player__sub_434B20(Player* player);

// Адрес: 0x00453A90 - Player__sub_453A90
void Player__sub_453A90(Player* player);

// Адрес: 0x00453AB0 - Player__sub_453AB0
void Player__sub_453AB0(Player* player);

// Адрес: 0x0045A970 - Player__Player_Des (деструктор)
void Player__Player_Des(Player* player);

// Адрес: 0x0045B0C0 - Player__IsMainPedSet
bool Player__IsMainPedSet(Player* player);

// Адрес: 0x0045B0D0 - Player__sub_45B0D0
void Player__sub_45B0D0(Player* player);

// Адрес: 0x00461DB0 - Player__NextPlayer
void Player__NextPlayer();

// Адрес: 0x004766A0 - Player__GetMultiPlayer
int Player__GetMultiPlayer(Player* player);

// Адрес: 0x004766B0 - Player__SetMultiPlayer
void Player__SetMultiPlayer(Player* player, int mode);

// Адрес: 0x004766C0 - Player__getMoney
int Player__getMoney(Player* player);

// Адрес: 0x004766D0 - Player__GetRespect
int Player__GetRespect(Player* player);

// Адрес: 0x00476700 - Player__sub_476700
void Player__sub_476700(Player* player);

// Адрес: 0x00476730 - Player__sub_476730
void Player__sub_476730(Player* player);


#ifdef __cplusplus
}
#endif

#endif // PLAYER_H
