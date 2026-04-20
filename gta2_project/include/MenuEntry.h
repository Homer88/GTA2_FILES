// Структура: MenuEntry (Элемент меню)
// Оригинал: S245
// Размер: ~128 байт
// Описание: Представляет один элемент меню с текстом, позицией и действием

#ifndef MENUENTRY_H
#define MENUENTRY_H

#include <stdint.h>
#include <wchar.h>
#include "enums.h"

// Элемент меню
typedef struct MenuEntry {
    int8_t action;                 // 0x00 - Действие меню (MenuActions)
    int8_t field_1;                // 0x01 - Флаг/параметр
    int16_t x;                     // 0x02 - Позиция X
    int16_t y;                     // 0x04 - Позиция Y
    wchar_t text[50];              // 0x06 - Текст элемента меню (Unicode)
    int16_t textLength;            // 0x6A - Длина текста
    int16_t field_6C;              // 0x6C - Дополнительное поле
    uint16_t playerSlot;           // 0x6E - Слот игрока
    int16_t playerSlot1;           // 0x70 - Слот игрока 1 (дублирующее?)
    uint8_t flags[4];              // 0x72 - Флаги элемента
    int32_t field_76;              // 0x76 - Параметр 1
    int32_t field_7A;              // 0x7A - Параметр 2
    uint16_t index;                // 0x7E - Индекс элемента
    int16_t selectMenu;            // 0x80 - Индекс выбираемого меню
} MenuEntry;

#endif // MENUENTRY_H
