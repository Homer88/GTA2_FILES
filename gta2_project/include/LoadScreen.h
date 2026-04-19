// Структура: LoadScreen
// Оригинал: S83
// Размер: ~75 байт

#ifndef LOADSCREEN_H
#define LOADSCREEN_H

// Structure definition for S83
// Found in original gta2.exe.h

S83 {
byte field0_0x0;
    undefined1 field1_0x1;
    undefined1 field2_0x2;
    undefined field3_0x3;
    undefined2 field4_0x4;
    undefined field5_0x6;
    undefined field6_0x7;
    undefined4 field7_0x8;
    struct Car *Car;
    struct TrainComponent trainComponents[2];
    undefined field10_0x18;
    undefined field11_0x19;
    undefined field12_0x1a;
    undefined field13_0x1b;
    undefined field14_0x1c;
    undefined field15_0x1d;
    undefined field16_0x1e;
    undefined field17_0x1f;
    undefined field18_0x20;
    undefined field19_0x21;
    undefined field20_0x22;
    undefined field21_0x23;
    undefined field22_0x24;
    undefined field23_0x25;
    undefined field24_0x26;
    undefined field25_0x27;
    undefined field26_0x28;
    undefined field27_0x29;
    undefined field28_0x2a;
    undefined field29_0x2b;
    undefined field30_0x2c;
    undefined field31_0x2d;
    undefined field32_0x2e;
    undefined field33_0x2f;
    undefined field34_0x30;
    undefined field35_0x31;
    undefined field36_0x32;
    undefined field37_0x33;
    undefined field38_0x34;
    undefined field39_0x35;
    undefined field40_0x36;
    undefined field41_0x37;
    undefined1 field42_0x38;
    undefined field43_0x39;
    undefined field44_0x3a;
    undefined field45_0x3b;
    undefined field46_0x3c;
    undefined field47_0x3d;
    undefined field48_0x3e;
    undefined field49_0x3f;
    undefined field50_0x40;
    undefined field51_0x41;
    undefined1 field52_0x42;
    byte field53_0x43;
    undefined1 field54_0x44;
    undefined field55_0x45;
    undefined field56_0x46;
    undefined field57_0x47;
    undefined4 field58_0x48;
    undefined4 field59_0x4c;
    int field60_0x50;
    undefined1 field61_0x54;
    undefined1 field62_0x55;
    byte SkipCount;
    undefined1 field64_0x57;
};

#endif // LOADSCREEN_H
