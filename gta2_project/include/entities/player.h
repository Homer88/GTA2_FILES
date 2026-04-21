/**
 * @file player.h
 * @brief Структуры и функции игрока (Player) для GTA2
 * 
 * old_file: gta2.exe.h / gta2.exe.c
 * Адреса функций соответствуют IDA Pro (sub_XXXXXX)
 * 
 * Примечание: Исходная структура Player имеет сложный layout с множеством
 * невыясненных полей. Ниже представлена интерпретация на основе анализа.
 */

#ifndef GTA2_PLAYER_H
#define GTA2_PLAYER_H

#include <stdint.h>
#include "ped.h"      // Ped
#include "vehicle_types.h" // BaseCar

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================================
// ПЕРЕЧИСЛЕНИЯ
// ============================================================================

/** Флаги состояния игрока */
typedef enum PlayerFlags {
    PLAYER_FLAG_NONE          = 0x00,
    PLAYER_FLAG_HAS_MISSION   = 0x01, /**< У игрока есть активная миссия */
    PLAYER_FLAG_WANTED        = 0x02, /**< Игрок в розыске */
    PLAYER_FLAG_CINEMATIC     = 0x04, /**< Активирован кинематографический режим */
    PLAYER_FLAG_DEAD          = 0x08, /**< Игрок мертв */
    PLAYER_FLAG_ARRESTED      = 0x10, /**< Игрок арестован */
    PLAYER_FLAG_IN_VEHICLE    = 0x20, /**< Игрок в транспорте */
    PLAYER_FLAG_HAS_WEAPON    = 0x40  /**< Игрок вооружен */
} PlayerFlags;

/** Причины смерти */
typedef enum DeathReason {
    DEATH_NONE           = 0,
    DEATH_SHOT           = 1, /**< Застрелен */
    DEATH_RUNOVER        = 2, /**< Сбит машиной */
    DEATH_EXPLOSION      = 3, /**< Взрыв */
    DEATH_DROWNED        = 4, /**< Утонул */
    DEATH_FALLEN         = 5, /**< Упал с высоты */
    DEATH_ELECTROCUTED   = 6, /**< Удар током */
    DEATH_CRUSHED        = 7  /**< Раздавлен */
} DeathReason;

/** Состояния игрока */
typedef enum PlayerState {
    PLAYER_STATE_NORMAL      = 0,
    PLAYER_STATE_DRIVING     = 1,
    PLAYER_STATE_DEAD        = 2,
    PLAYER_STATE_ARRESTED    = 3,
    PLAYER_STATE_CINEMATIC   = 4,
    PLAYER_STATE_SPECTATING  = 5
} PlayerState;

// ============================================================================
// СТРУКТУРЫ
// ============================================================================

/**
 * @brief Структура игрока
 * 
 * old_struct: struct Player (gta2.exe)
 * Примерный размер: 0x688+ байт (требует уточнения)
 */
typedef struct Player {
    /* 0x000 */ struct Player* CurrentPlayer;    /**< old_var: CurrentPlayer */
    /* 0x004 */ struct Player* Player;           /**< old_var: Player */
    /* 0x008 */ void* Rotate;                    /**< old_var: Rotate (KeyPlayer) */
    /* 0x00C */ void* FW;                        /**< old_var: FW */
    /* 0x010 */ void* S103;                      /**< old_var: S103 (неизвестная структура) */
    /* 0x014 */ int16_t Sw;                      /**< old_var: Sw (текущее оружие?) */
    /* 0x016 */ int16_t TypeWeapon;              /**< old_var: TypeWeapon */
    /* 0x018 */ void* S103_1;                    /**< old_var: S103_1 */
    /* 0x01C */ int16_t SelectWeaponNext;        /**< old_var: SelectWeaponNext */
    /* 0x01E */ char field_1E;                   /**< old_var: field_1E */
    /* 0x01F */ char field_1F;                   /**< old_var: field_1F */
    /* 0x020 */ void* pS103;                     /**< old_var: pS103 */
    /* 0x024 */ int32_t ID;                      /**< old_var: ID (уникальный ID игрока) */
    /* 0x028 */ void* S103_2;                    /**< old_var: S103_2 */
    /* 0x02C */ int16_t MoneyValue;              /**< old_var: MoneyValue */
    /* 0x02E */ uint8_t Ids;                     /**< old_var: Ids */
    /* 0x02F */ char field_2F;                   /**< old_var: field_2F */
    /* 0x030 */ void* S103_5;                    /**< old_var: S103_5 */
    /* 0x034 */ void* RESPECT;                   /**< old_var: RESPECT (Gangs*) */
    /* 0x038 */ void* field_38;                  /**< old_var: field_38 */
    /* 0x03C */ int32_t field_3C;                /**< old_var: field_3C */
    /* 0x040 */ void* S103_4;                    /**< old_var: S103_4 */
    /* 0x044 */ enum DeathReason DeathReason;    /**< old_var: DeathReason */
    /* 0x048 */ void* Tango1;                    /**< old_var: Tango1 */
    /* 0x04C */ int32_t Sound;                   /**< old_var: Sound */
    /* 0x050 */ int32_t field_50;                /**< old_var: field_50 */
    /* 0x054 */ int32_t field_54;                /**< old_var: field_54 */
    /* 0x058 */ int32_t field_58;                /**< old_var: field_58 */
    /* 0x05C */ struct BaseCar* sCar1;           /**< old_var: sCar1 (текущая машина 1) */
    /* 0x060 */ int32_t field_60;                /**< old_var: field_60 */
    /* 0x064 */ int32_t field_64;                /**< old_var: field_64 */
    /* 0x068 */ int32_t MultiPlayerMode;         /**< old_var: MultiPlayerMode */
    /* 0x06C */ int32_t field_6C;                /**< old_var: field_6C */
    /* 0x070 */ uint8_t Up;                      /**< old_var: Up (ввод) */
    /* 0x071 */ uint8_t Down;                    /**< old_var: Down */
    /* 0x072 */ uint8_t Left;                    /**< old_var: Left */
    /* 0x073 */ uint8_t Right;                   /**< old_var: Right */
    /* 0x074 */ uint8_t prevWeapon;              /**< old_var: prevWeapon */
    /* 0x075 */ uint8_t nextWeapon;              /**< old_var: nextWeapon */
    /* 0x076 */ uint8_t debugKey1;               /**< old_var: debugKey1 */
    /* 0x077 */ uint8_t debugKey2;               /**< old_var: debugKey2 */
    /* 0x078 */ bool Forward;                    /**< old_var: Forward */
    /* 0x079 */ bool Backward;                   /**< old_var: Backward */
    /* 0x07A */ bool RotateLeft;                 /**< old_var: RotateLeft */
    /* 0x07B */ bool RotateRight;                /**< old_var: RotateRight */
    /* 0x07C */ bool Attack;                     /**< old_var: Attack */
    /* 0x07D */ bool Enter;                      /**< old_var: Enter */
    /* 0x07E */ bool Jump;                       /**< old_var: Jump */
    /* 0x07F */ bool NextWeaponZ;                /**< old_var: NextWeaponZ */
    /* 0x080 */ bool PrevWeaponX;                /**< old_var: PrevWeaponX */
    /* 0x081 */ bool keySpecial;                 /**< old_var: keySpecial */
    /* 0x082 */ bool keySpecial2;                /**< old_var: keySpecial2 */
    /* 0x083 */ char field_83;                   /**< old_var: field_83 */
    /* 0x084 */ int32_t field_84;                /**< old_var: field_84 */
    /* 0x088 */ int32_t field_88;                /**< old_var: field_88 */
    /* 0x08C */ char AttackIsChanged;            /**< old_var: AttackIsChanged */
    /* 0x08D */ char field_8D;                   /**< old_var: field_8D */
    /* 0x08E */ uint8_t PlayerNext;              /**< old_var: PlayerNext */
    /* 0x08F */ char field_8F;                   /**< old_var: field_8F */
    /* 0x090 */ void* CameraOrPhysics1;          /**< old_var: CameraOrPhysics1 */
    /* 0x094 */ char field_94;                   /**< old_var: field_94 */
    /* 0x095 */ char field_95;                   /**< old_var: field_95 */
    /* 0x096 */ char field_96;                   /**< old_var: field_96 */
    /* 0x097 */ char field_97;                   /**< old_var: field_97 */
    /* 0x098 */ enum PlayerState State;          /**< old_var: State */
    /* 0x09C */ void* AudioManager;              /**< old_var: AudioManager */
    /* 0x0A0 */ int32_t field_A0;                /**< old_var: field_A0 */
    /* 0x0A4 */ char gapA4[3];                   /**< old_var: gapA4 */
    /* 0x0A7 */ char field_A7;                   /**< old_var: field_A7 */
    /* 0x0A8 */ char field_A8;                   /**< old_var: field_A8 */
    /* 0x0A9 */ char field_A9;                   /**< old_var: field_A9 */
    /* 0x0AA */ uint8_t sbw;                     /**< old_var: sbw */
    /* 0x0AB */ uint8_t tpa;                     /**< old_var: tpa */
    /* 0x0AC */ char field_AC;                   /**< old_var: field_AC */
    /* 0x0AD */ char gapAD[11];                  /**< old_var: gapAD */
    /* 0x0B8 */ void* S1__;                      /**< old_var: S1__ (S131*) */
    /* 0x0BC */ char gapBC[23];                  /**< old_var: gapBC */
    /* 0x0D3 */ char field_D3;                   /**< old_var: field_D3 */
    /* 0x0D4 */ char gapD4[7];                   /**< old_var: gapD4 */
    /* 0x0DB */ char field_DB;                   /**< old_var: field_DB */
    /* 0x0DC */ char gapDC[14];                  /**< old_var: gapDC */
    /* 0x0EA */ char field_EA;                   /**< old_var: field_EA */
    /* 0x0EB */ char gapEB[12];                  /**< old_var: gapEB */
    /* 0x0F7 */ char field_F7;                   /**< old_var: field_F7 */
    /* 0x0F8 */ char gapF8[10];                  /**< old_var: gapF8 */
    /* 0x102 */ char field_102;                  /**< old_var: field_102 */
    /* 0x103 */ char gap103[18];                 /**< old_var: gap103 */
    /* 0x115 */ char field_115;                  /**< old_var: field_115 */
    /* 0x116 */ char field_116;                  /**< old_var: field_116 */
    /* 0x117 */ char field_117;                  /**< old_var: field_117 */
    /* 0x118 */ int32_t field_118;               /**< old_var: field_118 */
    /* 0x11C */ int32_t field_11C;               /**< old_var: field_11C */
    /* 0x120 */ int32_t field_120;               /**< old_var: field_120 */
    /* 0x124 */ char field_124;                  /**< old_var: field_124 */
    /* 0x125 */ char field_125;                  /**< old_var: field_125 */
    /* 0x126 */ char field_126;                  /**< old_var: field_126 */
    /* 0x127 */ char field_127;                  /**< old_var: field_127 */
    /* 0x128 */ int32_t field_128;               /**< old_var: field_128 */
    /* 0x12C */ int32_t field_12C;               /**< old_var: field_12C */
    /* 0x130 */ int32_t field_130;               /**< old_var: field_130 */
    /* 0x134 */ char gap134[24];                 /**< old_var: gap134 */
    /* 0x14C */ void* CameraOrPhysics;           /**< old_var: CameraOrPhysics */
    /* 0x150 */ char gap150[4];                  /**< old_var: gap150 */
    /* 0x154 */ char field_154;                  /**< old_var: field_154 */
    /* 0x155 */ char gap155[62];                 /**< old_var: gap155 */
    /* 0x193 */ char field_193;                  /**< old_var: field_193 */
    /* 0x194 */ char gap194[18];                 /**< old_var: gap194 */
    /* 0x1A6 */ char field_1A6;                  /**< old_var: field_1A6 */
    /* 0x1A7 */ char gap1A7[32];                 /**< old_var: gap1A7 */
    /* 0x1C7 */ char field_1C7;                  /**< old_var: field_1C7 */
    /* 0x1C8 */ char gap1C8[9];                  /**< old_var: gap1C8 */
    /* 0x1D1 */ char field_1D1;                  /**< old_var: field_1D1 */
    /* 0x1D4 */ int32_t field_1D4;               /**< old_var: field_1D4 */
    /* 0x1D8 */ int32_t field_1D8;               /**< old_var: field_1D8 */
    /* 0x1DC */ int32_t field_1DC;               /**< old_var: field_1DC */
    /* 0x1E0 */ char gap1E0[4];                  /**< old_var: gap1E0 */
    /* 0x1E4 */ int32_t Camer_X_View;            /**< old_var: Camer_X_View */
    /* 0x1E8 */ int32_t Camer_Y_View;            /**< old_var: Camer_Y_View */
    /* 0x1EC */ int32_t Camer_Z_View;            /**< old_var: Camer_Z_View */
    /* 0x1F0 */ char gap1F0[3];                  /**< old_var: gap1F0 */
    /* 0x1F3 */ char field_1F3;                  /**< old_var: field_1F3 */
    /* 0x1F4 */ char gap1F4[6];                  /**< old_var: gap1F4 */
    /* 0x1FA */ char field_1FA;                  /**< old_var: field_1FA */
    /* 0x1FB */ char gap1FB[7];                  /**< old_var: gap1FB */
    /* 0x202 */ char field_202;                  /**< old_var: field_202 */
    /* 0x203 */ char gap203[5];                  /**< old_var: gap203 */
    /* 0x208 */ void* CameraOrPhysics2;          /**< old_var: CameraOrPhysics2 */
    /* 0x20C */ char field_20C;                  /**< old_var: field_20C */
    /* 0x20D */ char gap20D[28];                 /**< old_var: gap20D */
    /* 0x229 */ char field_229;                  /**< old_var: field_229 */
    /* 0x22A */ char gap22A[35];                 /**< old_var: gap22A */
    /* 0x24D */ char field_24D;                  /**< old_var: field_24D */
    /* 0x24E */ char gap24E[11];                 /**< old_var: gap24E */
    /* 0x259 */ char field_259;                  /**< old_var: field_259 */
    /* 0x25A */ char gap25A[17];                 /**< old_var: gap25A */
    /* 0x26B */ char field_26B;                  /**< old_var: field_26B */
    /* 0x26C */ char gap26C[32];                 /**< old_var: gap26C */
    /* 0x28C */ char field_28C;                  /**< old_var: field_28C */
    /* 0x28D */ char gap28D[11];                 /**< old_var: gap28D */
    /* 0x298 */ char field_298;                  /**< old_var: field_298 */
    /* 0x299 */ char gap299[5];                  /**< old_var: gap299 */
    /* 0x29E */ char field_29E;                  /**< old_var: field_29E */
    /* 0x29F */ char field_29F;                  /**< old_var: field_29F */
    /* 0x2A0 */ int32_t AuxGameCameraX;          /**< old_var: AuxGameCameraX */
    /* 0x2A4 */ int32_t AuxGameCameraY;          /**< old_var: AuxGameCameraY */
    /* 0x2A8 */ int32_t AuxGameCameraZ;          /**< old_var: AuxGameCameraZ */
    /* 0x2AC */ char gap2AC[24];                 /**< old_var: gap2AC */
    /* 0x2C4 */ struct Ped* MainPed;             /**< old_var: MainPed (основной пешеход) */
    /* 0x2C8 */ struct Ped* pPassenger;          /**< old_var: pPassenger */
    /* 0x2CC */ struct BaseCar* sCar2;           /**< old_var: sCar2 (текущая машина 2) */
    /* 0x2D0 */ char field_2D0;                  /**< old_var: field_2D0 */
    /* 0x2D1 */ void* Money;                     /**< old_var: Money (S161*) */
    /* 0x2D8 */ char gap2D8[107];                /**< old_var: gap2D8 */
    /* 0x343 */ char field_343;                  /**< old_var: field_343 */
    /* 0x344 */ char gap344[160];                /**< old_var: gap344 */
    /* 0x3E4 */ char field_3E4;                  /**< old_var: field_3E4 */
    /* 0x3E5 */ char gap3E5[53];                 /**< old_var: gap3E5 */
    /* 0x41A */ char field_41A;                  /**< old_var: field_41A */
    /* 0x41B */ char gap41B[46];                 /**< old_var: gap41B */
    /* 0x449 */ char field_449;                  /**< old_var: field_449 */
    /* 0x44A */ char gap44A[31];                 /**< old_var: gap44A */
    /* 0x469 */ char field_469;                  /**< old_var: field_469 */
    /* 0x46A */ char field_46A;                  /**< old_var: field_46A */
    /* 0x46B */ char field_46B;                  /**< old_var: field_46B */
    /* 0x46C */ char field_46C;                  /**< old_var: field_46C */
    /* 0x46D */ char field_46D;                  /**< old_var: field_46D */
    /* 0x46E */ char field_46E;                  /**< old_var: field_46E */
    /* 0x46F */ char field_46F;                  /**< old_var: field_46F */
    /* 0x470 */ char field_470;                  /**< old_var: field_470 */
    /* 0x471 */ char field_471;                  /**< old_var: field_471 */
    /* 0x472 */ char field_472;                  /**< old_var: field_472 */
    /* 0x473 */ char field_473;                  /**< old_var: field_473 */
    /* 0x474 */ char field_474;                  /**< old_var: field_474 */
    /* 0x475 */ char field_475;                  /**< old_var: field_475 */
    /* 0x476 */ char field_476;                  /**< old_var: field_476 */
    /* 0x477 */ char field_477;                  /**< old_var: field_477 */
    /* 0x478 */ char field_478;                  /**< old_var: field_478 */
    /* 0x479 */ char field_479;                  /**< old_var: field_479 */
    /* 0x47A */ char field_47A;                  /**< old_var: field_47A */
    /* 0x47B */ char field_47B;                  /**< old_var: field_47B */
    /* 0x47C */ char field_47C;                  /**< old_var: field_47C */
    /* 0x47D */ char field_47D;                  /**< old_var: field_47D */
    /* 0x47E */ char field_47E;                  /**< old_var: field_47E */
    /* 0x47F */ char field_47F;                  /**< old_var: field_47F */
    /* 0x480 */ char field_480;                  /**< old_var: field_480 */
    /* 0x481 */ char gap481[9];                  /**< old_var: gap481 */
    /* 0x48A */ char field_48A;                  /**< old_var: field_48A */
    /* 0x48B */ char gap48B[437];                /**< old_var: gap48B */
    /* 0x640 */ char field_640;                  /**< old_var: field_640 */
    /* 0x644 */ int32_t field_644;               /**< old_var: field_644 */
    /* 0x648 */ char gap648[48];                 /**< old_var: gap648 */
    /* 0x678 */ int32_t field_678;               /**< old_var: field_678 */
    /* 0x67C */ int32_t field_67C;               /**< old_var: field_67C */
    /* 0x680 */ uint16_t field_680;              /**< old_var: field_680 */
    /* 0x682 */ int16_t field_682;               /**< old_var: field_682 */
    /* 0x684 */ void* Lives;                     /**< old_var: Lives (S161*) */
    /* 0x688 */ char gap688[52];                 /**< old_var: gap688 */
    /* 0x6BC */ void* MultiPlayer;               /**< old_var: MultiPlayer (S161*) */
} Player;

// ============================================================================
// ПРОТОТИПЫ ФУНКЦИЙ
// ============================================================================

/**
 * @brief Инициализация структуры игрока
 * @param player Указатель на структуру Player
 * @param ped_ptr Указатель на начального пешехода
 * old_name: sub_004A1200
 */
void Player_Init(Player* player, struct Ped* ped_ptr);

/**
 * @brief Обновление состояния игрока (вызывается каждый кадр)
 * @param player Указатель на структуру Player
 * old_name: sub_004A1250
 */
void Player_Update(Player* player);

/**
 * @brief Посадка игрока в транспорт
 * @param player Указатель на структуру Player
 * @param vehicle Указатель на транспорт
 * old_name: sub_004A1300
 */
void Player_EnterVehicle(Player* player, struct BaseCar* vehicle);

/**
 * @brief Выход игрока из транспорта
 * @param player Указатель на структуру Player
 * old_name: sub_004A1380
 */
void Player_ExitVehicle(Player* player);

/**
 * @brief Нанесение урона игроку
 * @param player Указатель на структуру Player
 * @param damageAmount Количество урона
 * old_name: sub_004A1400
 */
void Player_TakeDamage(Player* player, int32_t damageAmount);

/**
 * @brief Добавление денег игроку
 * @param player Указатель на структуру Player
 * @param amount Сумма
 * old_name: sub_004A1480
 */
void Player_AddMoney(Player* player, int32_t amount);

/**
 * @brief Изменение уровня розыска
 * @param player Указатель на структуру Player
 * @param level Новый уровень (0-9)
 * old_name: sub_004A1500
 */
void Player_SetWantedLevel(Player* player, int32_t level);

/**
 * @brief Проверка смерти игрока
 * @param player Указатель на структуру Player
 * @return 1 если мертв, 0 иначе
 * old_name: sub_004A1580
 */
int32_t Player_IsDead(Player* player);

/**
 * @brief Возрождение игрока в точке спавна
 * @param player Указатель на структуру Player
 * old_name: sub_004A1600
 */
void Player_Respawn(Player* player);

/**
 * @brief Получение текущего здоровья игрока
 * @param player Указатель на структуру Player
 * @return Здоровье
 * old_name: sub_004A1680
 */
int32_t Player_GetHealth(Player* player);

/**
 * @brief Установка текущей миссии
 * @param player Указатель на структуру Player
 * @param mission_id ID миссии
 * old_name: sub_004A1700
 */
void Player_SetMission(Player* player, int32_t mission_id);

/**
 * @brief Обработка ввода для игрока
 * @param player Указатель на структуру Player
 * old_name: sub_004A1880
 */
void Player_ProcessInput(Player* player);

/**
 * @brief Переключение оружия у игрока
 * @param player Указатель на структуру Player
 * @param weapon_index Индекс оружия
 * old_name: sub_004A1900
 */
void Player_SwitchWeapon(Player* player, uint8_t weapon_index);

/**
 * @brief Основная функция обновления игрока (Game__Game_FUN_003f11a8)
 * @param this Указатель на игровой объект (Game*)
 * @return Указатель на Player
 * old_name: sub_003F11A8
 */
Player* Game_Game_FUN_003f11a8(void* this);

#ifdef __cplusplus
}
#endif

#endif // GTA2_PLAYER_H
