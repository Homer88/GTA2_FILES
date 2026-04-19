// Структура: VehiclePool
// Оригинал: S46
// Размер: ~8 байт

#ifndef VEHICLEPOOL_H
#define VEHICLEPOOL_H

// Structure definition for S46
// Found in original gta2.exe.h

S46 {
    struct S46 *Head;
    struct S46 *NextElement;
    undefined field2_0x8;
    undefined field3_0x9;
    undefined field4_0xa;
    undefined field5_0xb;
    undefined field6_0xc;
    undefined field7_0xd;
    undefined field8_0xe;
    undefined field9_0xf;
    struct CarSystemManager *CarSystemManager;
    struct S46 *Tail;
};

#endif // VEHICLEPOOL_H
