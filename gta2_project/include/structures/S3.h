#ifndef S3_H
#define S3_H

// Structure definition for S3
// Found in original gta2.exe.h

S3 {
struct SpriteS1 *SpriteS1;
    struct Car *Car;
    struct SpriteS3 *SpriteS3;
    struct S3 *NextElement;
    undefined4 PositionX;
    undefined4 PositionY;
    undefined4 PositionZ;
    undefined4 field7_0x1c;
    short Remap;
    undefined2 field9_0x22;
    short field10_0x24;
    undefined field11_0x26;
    undefined field12_0x27;
    undefined4 field13_0x28;
    byte field14_0x2c;
    undefined field15_0x2d;
    undefined field16_0x2e;
    undefined field17_0x2f;
    struct S3 *field18_0x30;
    undefined4 field19_0x34;
    undefined1 field20_0x38;
    undefined1 field21_0x39;
    undefined field22_0x3a;
    undefined field23_0x3b;
};

#endif // S3_H
