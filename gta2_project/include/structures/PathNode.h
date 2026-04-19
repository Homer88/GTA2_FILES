// Структура: PathNode
// Оригинал: S57
// Размер: ~6 байт

#ifndef PATHNODE_H
#define PATHNODE_H

// Structure definition for S57
// Found in original gta2.exe.h

S57 {
undefined2 field0_0x0;
    undefined field1_0x2;
    undefined field2_0x3;
    struct S58 arr300[300];
    byte buffer_0x4B0[1200];
    undefined2 a; // 99
    undefined field6_0x8ca6;
    undefined field7_0x8ca7;
};

#endif // PATHNODE_H
