// S86_7: Неизвестная структура
// Размер: ~5884 байт, 5869 полей
// Статус: Требуется обратная разработка

#ifndef S86_7_H
#define S86_7_H

#include "types.h"

#pragma pack(push, 1)
typedef struct S86_7 {
    // Структура требует дальнейшего анализа
    // Предварительный размер: 5884 байт
    byte field0_0x0;
    byte field1_0x1;
    // ... 5867 полей требуют анализа
    byte _reserved[5882];
} S86_7;
#pragma pack(pop)

#endif // S86_7_H
