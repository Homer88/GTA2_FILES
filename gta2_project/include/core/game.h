#ifndef GAME_H
#define GAME_H

#include "types.h"
#include "enums.h"
#include "forward_declarations.h"
#include "player.h"

struct Game {
    unsigned int Status;
    struct Player *pPlayer[6];
    struct Player *CurentPlayer;
    byte CurentPlayer__;
    byte Index;
    char field_22;
    byte MaxIdx;
    byte PlayerInFocus;
    char field_25;
    char field_26;
    char field_27;
    int isDead;
    int State;
    int field_30;
    int SkipPolice;
    struct Player *Player;
    char gSkilPolice;
    char field_3D;
    char field_3E;
    char field_3F;
};

// Global game pointer
extern Game* gGame;

// Game function declarations
int Game__Game_FUN_003f113c(Game *this);
int Game__Game_FUN_003f1208(Game *this);
undefined4 Game__Game_FUN_003f12a8(Game *this);

#endif // GAME_H
