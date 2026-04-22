/**
 * @file gta2_types.h
 * @brief Главный заголовочный файл, связывающий все структуры GTA 2
 * 
 * Основано на дампе IDA Pro (gta2.exe/ida_pro/gta2.exe.h)
 * Адреса функций взяты из gta2.exe.map
 * DirectX версия: 6.1 (НЕ 9!)
 * 
 * ВАЖНО: Порядок включения файлов критичен для корректной компиляции
 */

#pragma once

#ifdef _WIN32
    #include <windows.h>
#endif
#include <cstdint>

// ============================================================================
// FORWARD DECLARATIONS - предотвращаем циклические зависимости
// ============================================================================

struct Ped;
struct Car;
struct Player;
struct Weapon;
struct Gang;
struct GameObject;
struct Gangs;
struct SpriteS1;
struct SpriteS3;
struct EngineStruct;
struct Model;
struct Passenger;
struct CarDoor;
struct CarSystemManager;
struct CarTransforms;
struct S103;
struct S104;
struct S169;
struct S94;
struct S200;
struct S161;
struct Tango;
struct CameraOrPhysics;
struct AudioManager;
struct Arsenal;
struct EventHandler;

// ============================================================================
// ENUMS - типы перечислений из дампа
// ============================================================================

enum class SearchType : uint8_t {};
enum class CarModel : int32_t {};
enum class DamageType : uint8_t {};
enum class CAR_ENGINE_STATE : uint8_t {};
enum class TRAFFIC_CAR_TYPE : uint8_t {};
enum class GANG : uint8_t {
    Yakuza = 0,
    Zaibatsu_Corporation = 1,
    Loonies = 2,
    GANG_3 = 3,
    GANG_4 = 4,
    GANG_5 = 5,
    GANG_6 = 6,
    GANG_7 = 7,
    GANG_8 = 8,
    GANG_9 = 9,
    GANG_10 = 10
};

enum class ALL_PED : int32_t {
    PLAYER = 0,
    EMPTY = 1,
    DUMMY = 3,
    DRIVER = 5,
    PSYCHO = 14,
    MUGGER = 15,
    CARTHIEF = 16,
    BANK_ROBBER = 17,
    ELVIS = 22,
    POLICE = 24,
    SWAT = 25,
    FBI = 26,
    ARMYARMY = 27,
    GUARD = 28,
    FIREMAN = 38,
    DRONE = 41,
    ANY_GANG_MEMBER = 48,
    NO_OCCUPATION = 51
};

enum class Remap : int8_t {
    REMAP_COP = 0,
    REMAP_GREEN_COP = 1,
    REMAP_RED_COP = 2,
    REMAP_YELLOW_COP = 3,
    REMAP_ARMY = 4,
    REMAP_ZAIBATSU = 8,
    REMAP_KRISHNA = 9,
    REMAP_RUSSIAN = 10,
    REMAP_ELVIS = 12,
    REMAP_YAKUZA = 13,
    REMAP_PLAYER = 25
};

enum class PedState : int32_t {
    PEDSTATE_MOVE_TURN = 0,
    PEDSTATE_ENTER_CAR = 3,
    PEDSTATE_EXIT_CAR = 4,
    PEDSTATE_IDLE = 7,
    PEDSTATE_FALL = 8,
    PEDSTATE_DEAD = 9,
    PEDSTATE_IN_CAR = 10
};

enum class GraphicType : int32_t {
    GRAPHIC_DUMMY = 0,
    GRAPHIC_EMERG = 1,
    GRAPHIC_GANG = 2
};

enum class DEATH_REASON : int32_t {
    WASTED0 = 0,
    WASTED = 1,
    FRIED = 2,
    NICKED = 3,
    SHOCKED = 4
};

enum class POWERUP_TYPE : int16_t {
    POWERUP_TYPE_MULTIPLIER = 0,
    POWERUP_TYPE_LIFE = 1,
    POWERUP_TYPE_HEALTH = 2,
    POWERUP_TYPE_ARMOR = 3,
    POWERUP_TYPE_GET_OUTTA_JAIL_FREE_CARD = 4,
    POWERUP_TYPE_COP_BRIBE = 5,
    POWERUP_TYPE_INVULNERABILITY = 6,
    POWERUP_TYPE_DOUBLE_DAMAGE = 7,
    POWERUP_TYPE_FAST_RELOAD = 8,
    POWERUP_TYPE_ELECTROFINGERS = 9,
    POWERUP_TYPE_RESPECT = 10,
    POWERUP_TYPE_INVISIBILITY = 11,
    POWERUP_TYPE_INSTANT_GANG = 12
};

enum class KeyPlayer : int16_t {
    Rotate_Left = 48,
    Rotate_Right = 1392
};

enum class FW : int16_t {
    FW_Forward = 16384,
    FW_Backward = -16384
};

enum class WeaponType : int32_t {};

// Типы для совместимости с MSVC
typedef short __int16;
typedef int __int32;
#ifdef _MSC_VER
typedef __int64 __int64;
#else
typedef long long __int64;
#endif

#endif // GTA2_TYPES_H
