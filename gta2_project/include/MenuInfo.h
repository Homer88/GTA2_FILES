// Структура: MenuInfo (Информация о меню)
// Оригинал: S305 / MenuInfo
// Размер: ~708 байт (0x2C4)
// Описание: Основная структура информации о меню

#ifndef MENUINFO_H
#define MENUINFO_H

#include <stdint.h>
#include "S373.h"

// Информация о меню
typedef struct MenuInfo {
    void* field_0;              // 0x0 - Указатель (возможно, на текущую страницу)
    uint8_t field_4;            // 0x4 - Флаг/состояние 1
    uint8_t field_5;            // 0x5 - Флаг/состояние 2
    uint8_t field_6;            // 0x6 - Флаг/состояние 3
    uint8_t field_7;            // 0x7 - Флаг/состояние 4
    uint8_t field_8;            // 0x8 - Флаг/состояние 5
    uint8_t field_9;            // 0x9 - Флаг/состояние 6
    uint8_t field_A;            // 0xA - Флаг/состояние 7
    uint8_t field_B;            // 0xB - Флаг/состояние 8
    uint8_t field_C;            // 0xC - Флаг/состояние 9
    uint8_t field_D;            // 0xD - Флаг/состояние 10
    uint8_t field_E;            // 0xE - Флаг/состояние 11
    uint8_t field_F;            // 0xF - Флаг/состояние 12
    S373 menuData[43];          // 0x10 - Массив данных меню (43 x 16 байт = 688 байт)
    int32_t field_2C0;          // 0x2C0 - Дополнительное поле
} MenuInfo;

#endif // MENUINFO_H
