// S20_01: Неизвестная структура
// Размер: ~12 байт, 3 полей
// Статус: Требуется обратная разработка

#ifndef S20_01_H
#define S20_01_H

#include "types.h"

#pragma pack(push, 1)
typedef struct S20_01 {
    // Структура требует дальнейшего анализа
    // Предварительный размер: 12 байт
    byte field0_0x0;
    byte field1_0x1;
    byte field2_0x2;
    byte _reserved[9];
} S20_01;
#pragma pack(pop)

#endif // S20_01_H
