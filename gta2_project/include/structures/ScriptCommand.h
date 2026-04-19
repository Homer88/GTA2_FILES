// Структура: ScriptCommand
// Оригинал: S71
// Размер: ~15 байт

#ifndef SCRIPTCOMMAND_H
#define SCRIPTCOMMAND_H

// Structure definition for S71
// Found in original gta2.exe.h

S71 {
ushort field0_0x0;
    undefined2 field1_0x2;
    undefined2 field2_0x4;
    undefined2 field3_0x6;
    ushort count1;
    short count;
    undefined4 field6_0xc;
    undefined2 field7_0x10;
    undefined2 field8_0x12;
    struct S71 *S71;
};

#endif // SCRIPTCOMMAND_H
