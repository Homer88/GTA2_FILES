#ifndef CAR_H
#define CAR_H

#include "types.h"
#include "enums.h"
#include "forward_declarations.h"

// ============================================================================
// Вспомогательные структуры
// ============================================================================

struct Turret {
    void *void1;              // Указатель на данные турели
    undefined2 count;         // Счётчик (возможно, боезапас или количество выстрелов)
    undefined field2_0x6;     // Выравнивание
    undefined field3_0x7;     // Выравнивание
};

struct Passenger {
    struct Passenger *Next;   // Следующий пассажир в списке
    struct Passenger *Prev;   // Предыдущий пассажир в списке
};

struct CarDoor {
    int AnimationFrame;       // Битовое поле: [0]=текущий кадр(0-4), [1]=таймер задержки, [2]=кол-во кадров
    int doorState;            // Состояние: 0=закрыта, 1=открыта, 2=открывается, 3=закрывается, 4=переход, 5=задержка, 6=принудительно закрыта
    struct Ped *PedInDoor;    // Пешеход, входящий/выходящий через дверь (обнуляется если мёртв)
    byte DoorTimer;           // Таймер задержки перед открытием (уменьшается в состоянии 5)
    byte AnimationFlags;      // Флаги анимации (байт 1 из AnimationFrame)
    byte TotalFrames;         // Общее количество кадров анимации (байт 2 из AnimationFrame)
    byte Padding;             // Выравнивание
};

struct EngineStruct {
    struct EngineStruct *ElementNext;         // Следующий элемент в списке двигателей
    undefined4 field1_0x4;                    // Звук двигателя или RPM
    undefined1 field2_0x8;                    // Флаги состояния
    undefined1 field3_0x9;                    // Фаза работы
    undefined1 field4_0xa;                    // Уровень повреждения
    undefined field5_0xb;                     // Выравнивание
    struct EngineStruct *FirstElement;        // Первый элемент в пуле
    struct CarSystemManager *sCarSystemManager; // Менеджер системы автомобилей
    undefined4 field8_0x14;                   // Параметр двигателя 1
    undefined4 field9_0x18;                   // Параметр двигателя 2
    undefined4 field10_0x1c;                  // Параметр двигателя 3
    undefined4 field11_0x20;                  // Параметр двигателя 4
    uint field12_0x24;                        // Обороты двигателя или нагрузка
    undefined field13_0x28;                   // Температура
    undefined field14_0x29;                   // Давление масла
    undefined field15_0x2a;                   // Топливо
    undefined field16_0x2b;                   // Износ
    undefined field17_0x2c;                   // Резерв
    undefined field18_0x2d;                   // Резерв
    undefined field19_0x2e;                   // Резерв
    undefined field20_0x2f;                   // Резерв
    undefined field21_0x30;                   // Резерв
    undefined field22_0x31;                   // Резерв
    undefined field23_0x32;                   // Резерв
    undefined field24_0x33;                   // Резерв
    undefined4 field25_0x34;                  // Звук холостого хода
    undefined4 field26_0x38;                  // Звук ускорения
    undefined4 field27_0x3c;                  // Звук замедления
    undefined4 field28_0x40;                  // Параметр выхлопа
    undefined4 field29_0x44;                  // Параметр трансмиссии
    undefined4 field30_0x48;                  // Параметр сцепления
    undefined4 field31_0x4c;                  // Параметр дифференциала
    undefined4 field32_0x50;                  // Параметр колёс
    undefined2 field33_0x54;                  // Передаточное число КПП
    undefined2 field34_0x56;                  // Текущая передача
    undefined2 field35_0x58;                  // Крутящий момент
    undefined2 field36_0x5a;                  // Мощность
    undefined4 field37_0x5c;                  // Общий параметр производительности
    undefined4 field_0x604;                   // Смещение или указатель
    undefined4 field39_0x64;                  // Таймер перегрева
    undefined4 field40_0x68;                  // Таймер поломки
    struct EngineStruct *NextElement;         // Следующий элемент в активном списке
    undefined4 field42_0x70;                  // Резерв
    undefined4 field43_0x74;                  // Резерв
};

struct Model {
    int ModelCar;             // ID модели автомобиля
    undefined field1_0x4;     // Флаги модели
    undefined field2_0x5;     // Тип кузова
    undefined field3_0x6;     // Класс автомобиля
    undefined field4_0x7;     // Приоритет рендеринга
    undefined4 field5_0x8;    // Масса автомобиля
    int field6_0xc;           // Длина (габарит X)
    undefined field7_0x10;    // Ширина (габарит Z)
    undefined field8_0x11;    // Высота (габарит Y)
    undefined field9_0x12;    // Центр масс X
    undefined field10_0x13;   // Центр масс Y
    int field11_0x14;         // Максимальная скорость
    int field12_0x18;         // Ускорение
    int field13_0x1c;         // Торможение
    byte field14_0x20;        // Количество дверей
    undefined field15_0x21;   // Тип привода (передний/задний/полный)
    undefined field16_0x22;   // Тип коробки передач
    undefined field17_0x23;   // Объём двигателя
    undefined field18_0x24;   // Расход топлива
    undefined field19_0x25;   // Вместимость багажника
    undefined field20_0x26;   // Вместимость пассажиров
    undefined field21_0x27;   // Уровень брони
    undefined field22_0x28;   // Стоимость
    undefined field23_0x29;   // Группа трафика
    ushort field24_0x2a;      // Флаги видимости
    short field25_0x2c;       // Смещение текстуры X
    short field26_0x2e;       // Смещение текстуры Y
    struct Ped *Ped;          // Связанный пешеход (для спец. автомобилей)
    undefined field28_0x34;   // Выравнивание
};

// ============================================================================
// Основная структура автомобиля
// ============================================================================

struct Car {
    // === Блок 1: Вооружение и пассажиры (0x00 - 0x0F) ===
    struct Turret *Turret;            // Указатель на структуру турели (для танков, джипов с пулемётом)
    struct Passenger *Passengers;     // Список пассажиров в автомобиле
    int LightsState;                  // Состояние фар (битовая маска: ближний/дальний свет, стоп-сигналы, поворотники)
    struct CarDoor Doors[4];          // Массив структур дверей [0]=капот, [1]=багажник, [2]=левая, [3]=правая

    // === Блок 2: Связи и визуализация (0x10 - 0x2F) ===
    struct Car *PreviousCar;          // Предыдущая машина в связанном списке (для поездов, прицепов)
    struct SpriteS1 *Sprite;          // Спрайт для рендеринга машины (цвет 24)
    struct Ped *Driver;               // Указатель на водителя (NULL если无人)
    struct Player *ControlledByPlayer;// Игрок, управляющий машиной (если есть)
    struct EngineStruct *Engine;      // Параметры двигателя (мощность, износ, звук)
    struct Model *ModelData;          // Статические данные модели (масса, габариты, текстуры)
    void *pVehicleStats;              // Указатель на глобальные характеристики ТС (из конфига)
    undefined4 PhysicsFlags;          // Флаги физики (коллизии, гравитация, трение) - значение 16384

    // === Блок 3: Идентификация и урон (0x30 - 0x4F) ===
    int ObjectID;                     // Уникальный ID объекта в мире
    struct Ped *Attacker;             // Последний пешеход, нанёсший урон (триггер засветки выстрела)
    short Health;                     // Здоровье машины (0 = уничтожена)
    short VisibilityTimer;            // Таймер невидимости (сбрасывается когда машину видят игроки)
    ushort StatusFlags;               // Битовые флаги состояния (двигатель, сигнализация, угон)
    undefined Reserved1[2];           // Выравнивание (field17_0x7a, field18_0x7b)
    int SpecialTimer;                 // Таймер специального события (например, время до взрыва)

    // === Блок 4: Состояние и тип (0x50 - 0x5F) ===
    undefined Reserved2[4];           // Выравнивание (field20_0x80 - field23_0x83)
    enum CarType Type;                // Тип машины (гражданская, полиция, пожарная, военная)
    int State;                        // Состояние машины: 0=неактивна, 1=активна, 5=уничтожена, 7=особое
    byte FireFlags;                   // Флаги возгорания (бит 0: горит, бит 1: взрывается)
    byte SirenFlags;                  // Флаги сирены (тип, приоритет)
    byte SirenTimer;                  // Таймер сирены (кадры до следующего звука)
    byte HornTimer;                   // Таймер гудка

    // === Блок 5: Повреждения и игрок (0x60 - 0x6F) ===
    undefined4 DamageSource;          // Тип последнего повреждения (пуля, таран, взрыв)
    byte DamageCooldown;              // Кулдаун получения урона (защита от спама)
    byte OwnerPlayerId;               // ID игрока-владельца (для мультиплеера)
    undefined Reserved3[2];           // Выравнивание (field33_0x96, field34_0x97)
    int DoorLockState;                // Состояние замков дверей (1=locked, 2=unlocked)
    int EngineStatus;                 // Состояние двигателя (0=выкл, 1=заведён, 2=сломан)

    // === Блок 6: Трафик и спецэффекты (0x70 - 0x7F) ===
    enum TRAFFIC_CAR_TYPE TrafficType;// Тип для ИИ трафика (грузовик, такси, скорая)
    char SirenState;                  // Состояние сирены (выключена/включена/мигает)
    byte SirenPhase;                  // Фаза мигания сирены
    undefined Reserved4;              // Выравнивание (field40_0xa6)
    byte HornActive;                  // Флаг активного гудка (0=тихо, >0=гудит)
    undefined Reserved5;              // Выравнивание (field42_0xa8)
    byte FireDuration;                // Таймер горения (кадры до воспламенения/затухания)
    undefined Reserved6[6];           // Выравнивание / будущие расширения (field44_0xaa - field49_0xaf)
    undefined4 ExplosionTimer;        // Таймер до взрыва (если машина загорелась)
    undefined4 UpgradeSoundID;        // ID звука апгрейда (турбо, нитро)
    undefined Reserved7[4];           // Выравнивание до конца структуры (field52_0xb8 - field55_0xbb)
};

// Car function declarations
bool Car__Car_FUN_00403820(Car *this, int *param_1);

#endif // CAR_H
