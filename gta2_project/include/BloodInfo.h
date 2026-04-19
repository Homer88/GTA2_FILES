// Структура: BloodInfo
// Оригинал: S108
// Размер: ~36 байт

#ifndef BLOODINFO_H
#define BLOODINFO_H

// Structure definition for S108
// Found in original gta2.exe.h

S108 {
undefined4 field0_0x0;
    undefined4 field1_0x4;
    undefined4 field2_0x8;
    struct Player *Player;
    ushort CarSystemManager; // Created by retype action
    undefined2 field5_0x12;
    undefined2 field6_0x14;
    undefined field7_0x16;
    undefined field8_0x17;
    int Cycle;
    undefined2 field10_0x1c;
    undefined2 field11_0x1e;
    undefined field12_0x20;
    undefined field13_0x21;
    undefined field14_0x22;
    undefined field15_0x23;
    undefined4 field16_0x24;
    undefined4 field17_0x28;
};

#endif // BLOODINFO_H
