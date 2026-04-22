// Game.h
// Структура: Game
// Адрес в дампе: 0x??? (строка 6270 в gta2.exe.h)
// Размер: 0x40 (64 байта) - требует проверки
// Описание: Основная структура управления игрой, состоянием, игроками и полицией

#pragma once

#include "Player.h"

#pragma pack(push, 1)

struct Game
{
    unsigned int Status;                    // 0x0000 - Статус игры
    Player *pPlayer[6];                     // 0x0004 - Массив указателей на игроков (6 шт)
    Player *CurentPlayer;                   // 0x001C - Текущий активный игрок
    unsigned __int8 CurrentPlayerCopy;      // 0x0020 - Копия текущего игрока
    unsigned __int8 Index;                  // 0x0021 - Индекс
    char field_22;                          // 0x0022
    unsigned __int8 MaxIdx;                 // 0x0023 - Максимальный индекс
    unsigned __int8 PlayerInFocus;          // 0x0024 - Игрок в фокусе
    char field_25;                          // 0x0025
    char field_26;                          // 0x0026
    char field_27;                          // 0x0027
    int isDead;                             // 0x0028 - Флаг смерти
    int State;                              // 0x002C - Состояние игры
    int field_30;                           // 0x0030
    int SkipPolice;                         // 0x0034 - Пропустить полицию
    Player *Player;                         // 0x0038 - Указатель на игрока
    char gSkilPolice;                       // 0x003C - Навык полиции
    char field_3D;                          // 0x003D
    char field_3E;                          // 0x003E
    char field_3F;                          // 0x003F
};

#pragma pack(pop)

// Проверка размера структуры (должна быть 0x40 = 64 байта)
static_assert(sizeof(Game) == 0x40, "Game structure size mismatch");
