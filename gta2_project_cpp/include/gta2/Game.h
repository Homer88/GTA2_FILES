/**
 * @file Game.h
 * @brief Основная структура управления игрой (Game)
 * 
 * Адрес структуры в дампе: line 6270 в gta2.exe.h
 * Размер: 0x40 (64 байта)
 * Основано на: gta2.exe/ida_pro/gta2.exe.h, gta2.exe.map
 * 
 * Функции: 51 функция из gta2.exe.map
 */

#pragma once

#include <cstdint>

// Forward declarations
struct Player;

#pragma pack(push, 1)

struct Game
{
    uint32_t Status;                    // 0x0000 - Статус игры
    Player* pPlayer[6];                 // 0x0004 - Массив указателей на игроков (6 шт)
    Player* CurentPlayer;               // 0x001C - Текущий активный игрок
    uint8_t CurrentPlayerCopy;          // 0x0020 - Копия текущего игрока
    uint8_t Index;                      // 0x0021 - Индекс
    uint8_t field_22;                   // 0x0022
    uint8_t MaxIdx;                     // 0x0023 - Максимальный индекс
    uint8_t PlayerInFocus;              // 0x0024 - Игрок в фокусе
    uint8_t field_25;                   // 0x0025
    uint8_t field_26;                   // 0x0026
    uint8_t field_27;                   // 0x0027
    int32_t isDead;                     // 0x0028 - Флаг смерти
    int32_t State;                      // 0x002C - Состояние игры
    int32_t field_30;                   // 0x0030
    int32_t SkipPolice;                 // 0x0034 - Пропустить полицию
    Player* pCurrentPlayer;                     // 0x0038 - Указатель на текущего игрока
    char gSkilPolice;                   // 0x003C - Навык полиции
    char field_3D;                      // 0x003D
    char field_3E;                      // 0x003E
    char field_3F;                      // 0x003F
};

#pragma pack(pop)


// ============================================================================
// ФУНКЦИИ GAME (адреса из gta2.exe.map)
// Всего: 51 функция
// ============================================================================


// === Основные функции управления игрой ===
#ifdef __cplusplus
extern "C" {
#endif
// Адрес: 0x0040013C - Game__GetCurrentPlayerSlot
int Game__GetCurrentPlayerSlot();

// Адрес: 0x004001A8 - Game__FindNextActivePlayer
Player* Game__FindNextActivePlayer();

// Адрес: 0x00400208 - Game__SwitchToNextPlayer
void Game__SwitchToNextPlayer();

// Адрес: 0x004002A8 - Game__CycleToNextPlayer
void Game__CycleToNextPlayer();

// Адрес: 0x0040135C - Game__sub_3F135C
void Game__sub_3F135C();

// Адрес: 0x00410B00 - Game__ShiftId
void Game__ShiftId();

// Адрес: 0x00425BC0 - Game__GetIsUserPaused
bool Game__GetIsUserPaused();

// Адрес: 0x004309E0 - Game__GetPlayerSlotByIndex
Player* Game__GetPlayerSlotByIndex(int index);

// Адрес: 0x0045A460 - Game__sub_45A460
void Game__sub_45A460();

// Адрес: 0x0045A480 - Game__sub_45A480
void Game__sub_45A480();

// Адрес: 0x0045A4B0 - Game__SetState
void Game__SetState(int state);

// Адрес: 0x0045A4D0 - Game__sub_45A4D0
void Game__sub_45A4D0();

// Адрес: 0x0045A4F0 - Game__sub_45A4F0
void Game__sub_45A4F0();

// Адрес: 0x0045A540 - Game__sub_45A540
void Game__sub_45A540();

// Адрес: 0x0045A5A0 - Game__sub_45A5A0
void Game__sub_45A5A0();

// Адрес: 0x0045A650 - Game__sub_45A650
void Game__sub_45A650();

// Адрес: 0x0045A690 - Game__sub_45A690
void Game__sub_45A690();

// Адрес: 0x0045A6F0 - Game__sub_45A6F0
void Game__sub_45A6F0();

// Адрес: 0x0045A7A0 - Game__EndGameSession
void Game__EndGameSession();

// Адрес: 0x0045A7A0 - Game__sub_45A7A0
void Game__sub_45A7A0();

// Адрес: 0x0045A800 - Game__sub_45A800
void Game__sub_45A800();

// Адрес: 0x0045A850 - Game__sub_45A850
void Game__sub_45A850();

// Адрес: 0x0045A8D0 - Game__GetPlayer1
Player* Game__GetPlayer1();

// Адрес: 0x0045A910 - Game__GetPlayer
Player* Game__GetPlayer(int index);

// Адрес: 0x0045ACF0 - Game__is1
bool Game__is1();

// Адрес: 0x0045B469 - Game__sub_45B469
void Game__sub_45B469();

// Адрес: 0x0045B5F0 - Game__sub_45B5F0
void Game__sub_45B5F0();

// Адрес: 0x0045B750 - Game__sub_45B750
void Game__sub_45B750();

// Адрес: 0x0045BA10 - Game__sub_45BA10
void Game__sub_45BA10();

// Адрес: 0x0045BAA0 - Game__45BAA0
void Game__45BAA0();

// Адрес: 0x0045BAB0 - Game__GetNextInactivePlayer
Player* Game__GetNextInactivePlayer();

// Адрес: 0x0045BB00 - Game__sub_45BB00
void Game__sub_45BB00();

// Адрес: 0x0045BB50 - Game__sub_45BB50
void Game__sub_45BB50();

// Адрес: 0x0045BBA0 - Game__sub_45BBA0
void Game__sub_45BBA0();

// Адрес: 0x0045BC10 - Game__sub_45BC10
void Game__sub_45BC10();

// Адрес: 0x0045BC90 - Game__sub_45BC90
void Game__sub_45BC90();

// Адрес: 0x0045BD00 - Game__sub_45BD00
void Game__sub_45BD00();

// Адрес: 0x0045BD40 - Game__sub_45BD40
void Game__sub_45BD40();

// Адрес: 0x0045C1F0 - Game__GameTick
void Game__GameTick();

// Адрес: 0x0045C3B0 - Game__sub_45C3B0
void Game__sub_45C3B0();

// Адрес: 0x0045C420 - Game__sub_45C420
void Game__sub_45C420();

// Адрес: 0x0045C470 - Game__sub_45C470
void Game__sub_45C470();

// Адрес: 0x0045C4D0 - Game__Game (конструктор)
void Game__Game(Game* game);

// Адрес: 0x0045D3D0 - Game__Destructor
void Game__Destructor(Game* game);

// Адрес: 0x00461910 - Game__Game_Des (деструктор)
void Game__Game_Des(Game* game);

// Адрес: 0x00476790 - Game__sub_476790
void Game__sub_476790();

// Адрес: 0x004A4750 - Game__sub_4A4750
void Game__sub_4A4750();

// Адрес: 0x004B7590 - Game__IsDeadPlayer
bool Game__IsDeadPlayer(Player* player);

// Адрес: 0x004B92B0 - Game__sub_4B92B0
void Game__sub_4B92B0();

// Адрес: 0x004B94B0 - Game__sub_4B94B0
void Game__sub_4B94B0();

// Адрес: 0x004C09C0 - Game__GetState
int Game__GetState();

#ifdef __cplusplus
}
#endif

#endif // GAME_H
