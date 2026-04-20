// Структура: MenuPage (Страница меню)
// Оригинал: S248
// Размер: ~560 байт
// Описание: Страница меню, содержащая элементы меню, GUI и пункты

#ifndef MENUPAGE_H
#define MENUPAGE_H

#include <stdint.h>
#include "MenuEntry.h"
#include "GUI.h"
#include "MenuItem.h"

#define MAX_MENU_ENTRIES 10
#define MAX_GUI_ELEMENTS 15
#define MAX_MENU_ITEMS 10

// Страница меню
typedef struct MenuPage {
    uint16_t numMenuItems[2];              // 0x00 - Количество элементов меню (2 значения)
    MenuEntry menuEntries[MAX_MENU_ENTRIES]; // 0x04 - Массив элементов меню (10 x ~120 байт)
    GUI guiElements[MAX_GUI_ELEMENTS];       // ~0x4A4 - Массив GUI элементов (15 x ~108 байт)
    MenuItem menuItems[MAX_MENU_ITEMS];      // ~0x9D4 - Массив пунктов меню (10 x 8 байт)
    uint16_t actionIndex;                    // ~0x9F4 - Индекс действия меню
    int16_t selectActiveElementDefault;      // ~0x9F6 - Активный элемент по умолчанию
} MenuPage;

#endif // MENUPAGE_H
