// Структура: GUI (Графический интерфейс)
// Оригинал: S246
// Размер: ~108 байт
// Описание: Элемент графического интерфейса (спрайт, позиция, размеры)

#ifndef GUI_H
#define GUI_H

#include <stdint.h>
#include <wchar.h>

// Элемент графического интерфейса
typedef struct GUI {
    uint8_t interfaceType;    // 0x00 - Тип интерфейса
    uint8_t playerArena;      // 0x01 - Арена игрока
    int16_t x;                // 0x02 - Позиция X
    int16_t y;                // 0x04 - Позиция Y
    wchar_t sprite[50];       // 0x06 - Имя спрайта (Unicode)
    int16_t dX;               // 0x6A - Ширина/смещение по X
    int16_t dY;               // 0x6C - Высота/смещение по Y
} GUI;

#endif // GUI_H
