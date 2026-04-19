// Структура: SoundInfo
// Оригинал: S28
// Размер: ~24 байт

#ifndef SOUNDINFO_H
#define SOUNDINFO_H

// Structure definition for S28
// Found in original gta2.exe.h

S28 {
struct S28 *NextElement;
    short field1_0x4;
    undefined field2_0x6;
    undefined field3_0x7;
    int field4_0x8;
    undefined field5_0xc;
    undefined field6_0xd;
    short field7_0xe;
    undefined field8_0x10;
    undefined field9_0x11;
    short field10_0x12;
    struct S30 S30[63];
    short field12_0x110;
    byte field13_0x112;
    byte field14_0x113;
    struct S29 *S29;
    byte field16_0x118;
    byte field17_0x119;
    short field18_0x11a;
};

#endif // SOUNDINFO_H
