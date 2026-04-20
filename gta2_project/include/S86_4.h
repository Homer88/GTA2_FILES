// S86_4: Неизвестная структура
// Размер: ~13 байт, 4 полей
// Статус: Требуется обратная разработка

#ifndef S86_4_H
#define S86_4_H

#include "types.h"

#pragma pack(push, 1)
typedef struct S86_4 {
    // Структура требует дальнейшего анализа
    // Предварительный размер: 13 байт
    byte field0_0x0;
    byte field1_0x1;
    byte field2_0x2;
    byte field3_0x3;
    byte _reserved[9];
} S86_4;
#pragma pack(pop)

#endif // S86_4_H
