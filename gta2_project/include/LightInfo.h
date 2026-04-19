// Структура: LightInfo
// Оригинал: S32
// Размер: ~12 байт

#ifndef LIGHTINFO_H
#define LIGHTINFO_H

// Structure definition for S32
// Found in original gta2.exe.h

S32 {
uint8_t current_field; // 1 байт  по смещению 0
    uint8_t padding[3]; // 3 байта для выравнивания (неиспользуемые)
    uint32_t prev_field; //  4 байта по смещению -4
    uint32_t next_field; // 4 байта по смещению +4
};

#endif // LIGHTINFO_H
