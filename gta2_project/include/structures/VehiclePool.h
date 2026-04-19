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
    undefined Flags;
    undefined LockState;
    undefined AccessType;
    undefined PoolType;
    undefined Reserved1;
    undefined Reserved2;
    undefined Reserved3;
    undefined Reserved4;
    struct CarSystemManager *CarSystemManager;
    struct S46 *Tail;
};

#endif // VEHICLEPOOL_H
