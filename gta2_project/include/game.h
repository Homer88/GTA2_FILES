#ifndef GAME_H
#define GAME_H

#include "types.h"
#include "enums.h"
#include "forward_declarations.h"
#include "player.h"

struct Game {
    int Status;
    struct Player *cPlayer[6];
    struct Player *cPlayer_1;
    byte CurrentPlayer;
    byte IndexPlayer;
    undefined field5_0x22;
    byte byte_;
    undefined1 IDs;
    undefined field8_0x25;
    undefined field9_0x26;
    undefined field10_0x27;
    int GameOver;
    int field12_0x2c;
    byte field13_0x30;
    undefined field14_0x31;
    undefined field15_0x32;
    undefined field16_0x33;
    int SkipPolice;
    struct Player *PlayerMain;
    byte gSkipPolice;
    undefined field20_0x3d;
    undefined field21_0x3e;
    undefined field22_0x3f;
};

// Global game pointer
extern Game* gGame;

// Game function declarations
int Game__Game_FUN_003f113c(Game *this);
int Game__Game_FUN_003f1208(Game *this);
undefined4 Game__Game_FUN_003f12a8(Game *this);

#endif // GAME_H
