// Структура: PacketInfo
// Оригинал: S89
// Размер: ~13 байт

#ifndef PACKETINFO_H
#define PACKETINFO_H

// Structure definition for S89
// Found in original gta2.exe.h

S89 {
struct S89_2 *S89_2;
    ushort count;
    ushort param_2;
    undefined4 field3_0x8;
    undefined4 field4_0xc;
    undefined1 _byte;
    undefined reserv[3]; // Для выравнивания
};

#endif // PACKETINFO_H
