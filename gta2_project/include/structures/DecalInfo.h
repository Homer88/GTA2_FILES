// Структура: DecalInfo
// Оригинал: S112
// Размер: ~49 байт

#ifndef DECALINFO_H
#define DECALINFO_H

// Structure definition for S112
// Found in original gta2.exe.h

S112 {
byte a;
    undefined field1_0x1;
    byte field2_0x2;
    byte field3_0x3;
    byte field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined4 field8_0x8;
    undefined4 field9_0xc;
    struct S110 *s110;
    int field11_0x14;
    undefined2 field12_0x18;
    undefined field13_0x1a;
    undefined field14_0x1b;
    undefined4 field15_0x1c;
    undefined4 field16_0x20;
    undefined4 select;
    undefined field18_0x28;
    byte field19_0x29;
    undefined2 field20_0x2a;
    undefined2 field21_0x2c;
    undefined field22_0x2e;
    undefined field23_0x2f;
    undefined4 field24_0x30;
    byte field25_0x34;
    undefined field26_0x35;
    undefined field27_0x36;
    undefined field28_0x37;
};

#endif // DECALINFO_H
