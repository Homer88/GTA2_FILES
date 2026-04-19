// Структура: SuspensionInfo
// Оригинал: S125
// Размер: ~24 байт

#ifndef SUSPENSIONINFO_H
#define SUSPENSIONINFO_H

// Structure definition for S125
// Found in original gta2.exe.h

S125 {
int field0_0x0;
    int Arr[9];
    struct Car *Car1;
    struct Car *Car2;
    struct Car *Car3;
    undefined2 ArrElement;
    byte field6_0x36;
    byte reserv;
    int field8_0x38;
    undefined4 count;
    undefined4 count1;
    struct S125 *s125;
    undefined2 field12_0x48;
    byte field13_0x4a[2];
    uint MultiPlayer;
};

#endif // SUSPENSIONINFO_H
