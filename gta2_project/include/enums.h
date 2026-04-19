#ifndef ENUMS_H
#define ENUMS_H

#include "types.h"

// PowerUp types
typedef enum PowerUp {
    POWERUP_TYPE_MULTIPLIER=0,
    POWERUP_TYPE_LIFE=1,
    POWERUP_TYPE_HEALTH =2,
    POWERUP_TYPE_ARMOR=3,
    POWERUP_TYPE_GET_OUTTA_JAIL_FREE_CARD=4,
    POWERUP_TYPE_COP_BRIBE=5,
    POWERUP_TYPE_INVULNERABILITY=6,
    POWERUP_TYPE_DOUBLE_DAMAGE=7,
    POWERUP_TYPE_FAST_RELOAD =8,
    POWERUP_TYPE_ELECTROFINGERS =9,
    POWERUP_TYPE_RESPECT=10,
    POWERUP_TYPE_INVISIBILITY=11,
    POWERUP_TYPE_INSTANT_GANG=12
} PowerUp;

// CarType
typedef enum CarType {
    APC=3,
    BANKVAN=4,
    BOXCAR=6,
    COPCAR=12,
    FileTruck=17,
    GT24640=19,
    GunJeep=22,
    Jeep=30,
    Medic=34,
    STYPECAB=51,
    SWATVAN=52,
    Tank=54,
    Taxi=56,
    TRAIN=59,
    TRAINCAB=60,
    TRAINFB=61,
    TVVAN=67,
    EDSELFB=84
} CarType;

// TRAFFIC_CAR_TYPE
typedef enum TRAFFIC_CAR_TYPE {
    TRAFFIC_REGULAR=1,
    TRAFFIC_PROT_RECYCLED_CAR=2
} TRAFFIC_CAR_TYPE;

// PedFlags
typedef enum PedFlags {
    PED_FLAG_CROUCHING=2,
    DAMAGE_ANIMATION_LOCKED=4
} PedFlags;

// CarDamageState
typedef enum CarDamageState {
    CAR_INTACT=0,
    CAR_CRITICAL_DAMAGE=1,
    CAR_DESTROYED=2
} CarDamageState;

// SearchType
typedef enum SearchType {
    SEARCHTYPE_NO_THREATS=0,
    SEARCHTYPE_LINE_OF_SIGHT=1,
    SEARCHTYPE_LINE_OF_SIGHT_PLAYER_ONLY=2,
    SEARCHTYPE_AREA=3,
    SEARCHTYPE_AREA_PLAYER_ONLY=4
} SearchType;

// PedState
typedef enum PedState {
    PEDSTATE_MOVE_TURN=0,
    PEDSTATE_UNKNOWN_1=1,
    PEDSTATE_UNKNOWN_2=2,
    PEDSTATE_ENTER_CAR=3,
    PEDSTATE_EXIT_CAR=4,
    PEDSTATE_IDLE1=5,
    PEDSTATE_UNKNOWN_6=6,
    PEDSTATE_IDLE=7,
    PEDSTATE_FALL=8,
    PEDSTATE_DEAD=9,
    PEDSTATE_IN_CAR=10
} PedState;

// GANG
typedef enum GANG {
    Yakuza=0,
    Zaibatsu_Corporation=1,
    Loonies=2
} GANG;

// WeaponType
typedef enum WeaponType {
    Pistol=0,
    SNG=1,
    RPG=2,
    ElctoGan=3,
    Molotov=4,
    Granata=5,
    ShotGun=6,
    Shoker=7,
    FireGun=8,
    SMG_S=9,
    DualPistol=10,
    CAR_BOMB=14
} WeaponType;

// SectionFlags
typedef enum SectionFlags {
    IMAGE_SCN_TYPE_NO_PAD=8,
    IMAGE_SCN_RESERVED_0001=16,
    IMAGE_SCN_CNT_CODE=32,
    IMAGE_SCN_CNT_INITIALIZED_DATA=64,
    IMAGE_SCN_CNT_UNINITIALIZED_DATA=128,
    IMAGE_SCN_LNK_OTHER=256,
    IMAGE_SCN_LNK_INFO=512,
    IMAGE_SCN_LNK_REMOVE=2048,
    IMAGE_SCN_LNK_COMDAT=4096,
    IMAGE_SCN_GPREL=32768,
    IMAGE_SCN_ALIGN_1BYTES=1048576,
    IMAGE_SCN_ALIGN_2BYTES=2097152,
    IMAGE_SCN_ALIGN_4BYTES=3145728
} SectionFlags;

#endif // ENUMS_H
