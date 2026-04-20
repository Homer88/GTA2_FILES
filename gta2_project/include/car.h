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
    // === Блок 1: Вооружение и пассажиры (0x00 - 0x0F) ===
    // Было: s72
    struct Turrel *Turret;                    // Указатель на структуру турели (для танков, джипов с пулемётом)
    
    // Было: Passenger
    struct Passenger *Passengers;             // Массив или указатель на пассажиров
    
    // Было: carLights
    int LightsState;                          // Состояние фар (битовая маска: ближний/дальний свет, стоп-сигналы)
    
    // Было: CarDoor
    struct CarDoor Doors[4];                  // Массив структур дверей (передние/задние, капот, багажник)
    
    // === Блок 2: Связи и визуализация (0x10 - 0x2F) ===
    // Было: LastCar
    struct Car *PreviousCar;                  // Предыдущая машина в связанном списке (для поездов, прицепов)
    
    // Было: CarSprite
    struct SpriteS1 *Sprite;                  // Спрайт для рендеринга машины
    
    // Было: Driver
    struct Ped *Driver;                       // Указатель на водителя (NULL если无人)
    
    // Было: Player
    struct Player *ControlledByPlayer;        // Игрок, управляющий машиной (если есть)
    
    // Было: EngineStruct
    struct EngineStruct *Engine;              // Параметры двигателя (мощность, износ, звук)
    
    // Было: Model
    struct Model *ModelData;                  // Статические данные модели (масса, габариты, текстуры)
    
    // Было: S???
    void *pVehicleStats;                      // Указатель на глобальные характеристики ТС (из конфига)
    
    // Было: field11_0x68
    undefined4 PhysicsFlags;                  // Флаги физики (коллизии, гравитация, трение)
    
    // === Блок 3: Идентификация и урон (0x30 - 0x4F) ===
    // Было: ID_Object
    int ObjectID;                             // Уникальный ID объекта в мире
    
    // Было: lastDamagingPed
    struct Ped *Attacker;                     // Последний пешеход, нанёсший урон (для мести ИИ)
    
    // Было: Damage
    short Health;                             // Текущее здоровье машины (0 = уничтожена)
    
    // Было: field15_0x76
    short VisibilityTimer;                    // Таймер невидимости (сбрасывается когда машину видят игроки)
    
    // Было: bitMask
    ushort StatusFlags;                       // Битовые флаги состояния (двигатель, сигнализация, угон)
    
    // Было: field17_0x7a, field18_0x7b
    undefined Reserved1[2];                   // Выравнивание / зарезервировано
    
    // Было: field19_0x7c
    int SpecialTimer;                         // Таймер специального события (например, время до взрыва)
    
    // === Блок 4: Состояние и тип (0x50 - 0x5F) ===
    // Было: field20_0x80 - field23_0x83
    undefined Reserved2[4];                   // Выравнивание
    
    // Было: CarType
    enum CarType Type;                        // Тип машины (гражданская, полиция, пожарная, военная)
    
    // Было: TEST
    int State;                                // Состояние машины: 0=неактивна, 1=активна, 5=уничтожена, 7=особое
    
    // Было: FireState
    byte FireFlags;                           // Флаги возгорания (бит 0: горит, бит 1: взрывается)
    
    // Было: field27_0x8d
    byte SirenFlags;                          // Флаги сирены (тип, приоритет)
    
    // Было: field28_0x8e
    byte SirenTimer;                          // Таймер сирены (кадры до следующего звука)
    
    // Было: field29_0x8f
    byte HornTimer;                           // Таймер гудка
    
    // === Блок 5: Повреждения и игрок (0x60 - 0x6F) ===
    // Было: DamageType
    undefined4 DamageSource;                  // Тип последнего повреждения (пуля, таран, взрыв)
    
    // Было: DamageShotTimer
    byte DamageCooldown;                      // Кулдаун получения урона (защита от спама)
    
    // Было: PlayerId
    byte OwnerPlayerId;                       // ID игрока-владельца (для мультиплеера)
    
    // Было: field33_0x96, field34_0x97
    undefined Reserved3[2];                   // Выравнивание
    
    // Было: LocksDoor
    int DoorLockState;                        // Состояние замков дверей (заблокировано/разблокировано)
    
    // Было: engineState
    int EngineStatus;                         // Состояние двигателя (0=выкл, 1=заведён, 2=сломан)
    
    // === Блок 6: Трафик и спецэффекты (0x70 - 0x7F) ===
    // Было: trafficCarType
    enum TRAFFIC_CAR_TYPE TrafficType;        // Тип для ИИ трафика (грузовик, такси, скорая)
    
    // Было: sirenState
    char SirenState;                          // Состояние сирены (выключена/включена/мигает)
    
    // Было: sirenPhase
    byte SirenPhase;                          // Фаза мигания сирены
    
    // Было: field40_0xa6
    undefined Reserved4;                      // Выравнивание
    
    // Было: horn
    byte HornActive;                          // Флаг активного гудка (0=тихо, >0=гудит)
    
    // Было: field42_0xa8
    undefined Reserved5;                      // Выравнивание
    
    // Было: FireTimer
    byte FireDuration;                        // Таймер горения (кадры до воспламенения/затухания)
    
    // Было: field44_0xaa - field49_0xaf
    undefined Reserved6[6];                   // Выравнивание / будущие расширения
    
    // Было: field50_0xb0
    undefined4 ExplosionTimer;                // Таймер до взрыва (если машина загорелась)
    
    // Было: currentUpgradeSound
    undefined4 UpgradeSoundID;                // ID звука апгрейда (турбо, нитро)
    
    // Было: field52_0xb8 - field55_0xbb
    undefined Reserved7[4];                   // Выравнивание до конца структуры
};

// Car function declarations
bool Car__Car_FUN_00403820(Car *this, int *param_1);

#endif // CAR_H
