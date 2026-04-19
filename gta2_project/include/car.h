#ifndef CAR_H
#define CAR_H

#include "types.h"
#include "enums.h"
#include "forward_declarations.h"

struct Turrel {
    void *void1;
    undefined2 count;
    undefined field2_0x6;
    undefined field3_0x7;
};

struct Passenger {
    // Add passenger fields as needed
};

struct CarDoor {
    undefined4 field0_0x0;
    undefined4 field1_0x4;
    undefined4 field2_0x8;
    undefined4 field3_0xc;
};

struct EngineStruct {
    undefined4 field0_0x0;
    undefined4 field1_0x4;
    undefined4 field2_0x8;
    undefined4 field3_0xc;
    undefined4 field4_0x10;
    undefined4 field5_0x14;
    undefined4 field6_0x18;
    undefined4 field7_0x1c;
    undefined4 field8_0x20;
    undefined4 field9_0x24;
    undefined4 field10_0x28;
    undefined4 field11_0x2c;
    undefined4 field12_0x30;
    undefined4 field13_0x34;
    undefined4 field14_0x38;
    undefined4 field15_0x3c;
};

struct Model {
    int ModelCar;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    undefined4 field5_0x8;
    int field6_0xc;
    undefined field7_0x10;
    undefined field8_0x11;
    undefined field9_0x12;
    undefined field10_0x13;
    int field11_0x14;
    int field12_0x18;
    int field13_0x1c;
    byte field14_0x20;
    undefined field15_0x21;
    undefined field16_0x22;
    undefined field17_0x23;
    undefined field18_0x24;
    undefined field19_0x25;
    undefined field20_0x26;
    undefined field21_0x27;
    undefined field22_0x28;
    undefined field23_0x29;
    ushort field24_0x2a;
    short field25_0x2c;
    short field26_0x2e;
    struct Ped *Ped;
    undefined field28_0x34;
};

struct Car {
    struct Turrel *s72;
    struct Passenger *Passenger;
    int carLights;
    struct CarDoor CarDoor[4];
    struct Car *LastCar;
    struct SpriteS1 *CarSprite;
    struct Ped *Driver;
    struct Player *Player;
    struct EngineStruct *EngineStruct;
    struct Model *Model;
    void *S???; 
    undefined4 field11_0x68;
    int ID_Object;
    struct Ped *lastDamagingPed;
    short Damage;
    short field15_0x76;
    ushort bitMask;
    undefined field17_0x7a;
    undefined field18_0x7b;
    int field19_0x7c;
    undefined field20_0x80;
    undefined field21_0x81;
    undefined field22_0x82;
    undefined field23_0x83;
    enum CarType CarType;
    int TEST;
    byte FireState;
    undefined field27_0x8d;
    undefined field28_0x8e;
    undefined field29_0x8f;
    undefined4 DamageType;
    byte DamageShotTimer;
    byte PlayerId;
    undefined field33_0x96;
    undefined field34_0x97;
    int LocksDoor;
    int engineState;
    enum TRAFFIC_CAR_TYPE trafficCarType;
    char sirenState;
    byte sirenPhase;
    undefined field40_0xa6;
    byte horn;
    undefined field42_0xa8;
    byte FireTimer;
    undefined field44_0xaa;
    undefined field45_0xab;
    undefined field46_0xac;
    undefined field47_0xad;
    undefined field48_0xae;
    undefined field49_0xaf;
    undefined4 field50_0xb0;
    undefined4 currentUpgradeSound;
    undefined field52_0xb8;
    undefined field53_0xb9;
    undefined field54_0xba;
    undefined field55_0xbb;
};

// Car function declarations
bool Car__Car_FUN_00403820(Car *this, int *param_1);

#endif // CAR_H
