// Структура: MenuItem (Элемент меню - позиция)
// Оригинал: S247
// Размер: 8 байт
// Описание: Позиция и действие элемента меню

#ifndef MENUITEM_H
#define MENUITEM_H

#include <stdint.h>
#include <stdbool.h>

// Элемент меню (позиция)
typedef struct MenuItem {
    int16_t x;                     // 0x00 - Позиция X
    int16_t y;                     // 0x02 - Позиция Y
    bool actionIndex;              // 0x04 - Индекс действия меню
    uint8_t field_5;               // 0x05 - Дополнительный параметр
} MenuItem;

#endif // MENUITEM_H
