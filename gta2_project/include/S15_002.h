// S15_002: Неизвестная структура
// Размер: ~19 байт, 10 полей
// Статус: Требуется обратная разработка

#ifndef S15_002_H
#define S15_002_H

#include "types.h"

#pragma pack(push, 1)
typedef struct S15_002 {
    // Структура требует дальнейшего анализа
    // Предварительный размер: 19 байт
    byte field0_0x0;
    byte field1_0x1;
    byte field2_0x2;
    byte field3_0x3;
    byte field4_0x4;
    byte field5_0x5;
    byte field6_0x6;
    byte field7_0x7;
    byte field8_0x8;
    byte field9_0x9;
    byte _reserved[9];
} S15_002;
#pragma pack(pop)

#endif // S15_002_H
