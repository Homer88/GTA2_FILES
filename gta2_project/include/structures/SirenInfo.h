// Структура: SirenInfo
// Оригинал: S132
// Размер: ~12 байт

#ifndef SIRENINFO_H
#define SIRENINFO_H

// Structure definition for S132
// Found in original gta2.exe.h

S132 {
struct S132 *S132_1;
    undefined4 a;
    struct CameraOrPhysicsCameraOrPhysics *S131; // ?
    undefined4 Sound;
    struct S132 *S132_2;
    undefined4 field5_0x14;
    struct CameraOrPhysicsCameraOrPhysics *S131*; // Created by retype action
    struct S1 *s1;
    struct CameraOrPhysicsCameraOrPhysics *field8_0x20;
    struct CameraOrPhysicsCameraOrPhysics *field9_0x24;
};

#endif // SIRENINFO_H
