// S65: Структура данных (обновлено из structures_s.h)
// Размер: ~4 байт, 3 полей
// Статус: Частично определена

#ifndef S65_H
#define S65_H

#include "types.h"

#pragma pack(push, 1)
typedef struct S65 {
    struct S65 *s65;
    short _short;
    byte _byte;
    byte _byte1;
} S65;
#pragma pack(pop)

#endif // S65_H
