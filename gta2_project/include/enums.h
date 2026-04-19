#ifndef ENUMS_H
#define ENUMS_H

#include "types.h"

// PowerUp types
typedef enum PowerUpType {
    POWERUP_TYPE_MULTIPLIER = 0,
    POWERUP_TYPE_INVULNERABILITY = 0x6,
    POWERUP_TYPE_GET_OUTTA_JAIL_FREE_CARD = 0x4,
    POWERUP_TYPE_ELECTROFINGERS = 0x9,
    POWERUP_TYPE_INVISIBILITY = 0xb,
    POWERUP_TYPE_ARMOR = 0x3,
    POWERUP_TYPE_DOUBLE_DAMAGE = 0x7
} PowerUpType;

// CarType
typedef enum CarType {
    // Add car types as needed
} CarType;

// TRAFFIC_CAR_TYPE
typedef enum TRAFFIC_CAR_TYPE {
    // Add traffic car types as needed
} TRAFFIC_CAR_TYPE;

// PedFlags
typedef enum PedFlags {
    // Add ped flags as needed
} PedFlags;

// CarDamageState
typedef enum CarDamageState {
    // Add car damage states as needed
} CarDamageState;

// SearchType
typedef enum SearchType {
    // Add search types as needed
} SearchType;

// PedState
typedef enum PedState {
    // Add ped states as needed
} PedState;

// GANG
typedef enum GANG {
    // Add gang types as needed
} GANG;

// SectionFlags
typedef enum SectionFlags {
    // Add section flags as needed
} SectionFlags;

#endif // ENUMS_H
