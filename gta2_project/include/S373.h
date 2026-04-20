// Структура: S373 (Элемент данных меню)
// Оригинал: S373
// Размер: 16 байт
// Описание: Вспомогательная структура для данных меню

#ifndef S373_H
#define S373_H

#include <stdint.h>

// Элемент данных меню
typedef struct S373 {
    uint8_t nextElement;      // 0x0 - Следующий элемент
    uint8_t field_1;          // 0x1 - Поле 1
    uint8_t field_2;          // 0x2 - Поле 2
    uint8_t field_3;          // 0x3 - Поле 3
    uint8_t nextElement1;     // 0x4 - Следующий элемент 1
    uint8_t field_5;          // 0x5 - Поле 5
    uint8_t field_6;          // 0x6 - Поле 6
    uint8_t field_7;          // 0x7 - Поле 7
    uint8_t field_8;          // 0x8 - Поле 8
    uint8_t field_9;          // 0x9 - Поле 9
    uint8_t field_A;          // 0xA - Поле A
    uint8_t field_B;          // 0xB - Поле B
    uint8_t field_C;          // 0xC - Поле C
    uint8_t field_D;          // 0xD - Поле D
    uint8_t field_E;          // 0xE - Поле E
    uint8_t field_F;          // 0xF - Поле F
} S373;

#endif // S373_H
