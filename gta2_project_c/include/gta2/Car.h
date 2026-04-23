/**
 * @file Car.h
 * @brief Структура автомобиля и связанные типы данных
 * 
 * Адрес структуры в дампе: 0x403800 (line 3283 в gta2.exe.h)
 * Размер: 0xC0 (192 байта)
 * Основано на: gta2.exe/ida_pro/gta2.exe.h, gta2.exe.map
 */

#pragma once

#include <cstdint>

// Forward declarations
struct Ped;
struct Player;
struct EngineStruct;
struct Model;
struct SpriteS1;
struct Passenger;
struct CarDoor;
struct Car;

// Enum из дампа
enum class CAR_LIGHTS_AND_DOORS_BITSTATE : uint32_t {};
enum class SearchType : uint8_t {};
enum class CarModel : int32_t {};
enum class DamageType : uint8_t {};
enum class CAR_ENGINE_STATE : uint8_t {};
enum class TRAFFIC_CAR_TYPE : uint8_t {};

#pragma pack(push, 1)

struct Car
{
    void* vtable;                       // 0x0000 - Указатель на таблицу виртуальных методов
    Passenger* Passenger;               // 0x0004 - Пассажиры
    CAR_LIGHTS_AND_DOORS_BITSTATE carLights; // 0x0008 - Состояние огней и дверей
    CarDoor CarDoor[4];                 // 0x000C - Двери автомобиля (4 шт)
    Car* LastCar;                       // 0x003C - Последний автомобиль
    SpriteS1* CarSprite;                // 0x0040 - Спрайт автомобиля
    Ped* Driver;                        // 0x0044 - Водитель
    Player* pPlayer;                    // 0x0048 - Игрок
    EngineStruct* EngineStruct;         // 0x004C - Структура двигателя
    Model* Model;                       // 0x0050 - Модель
    void* TrailerCtrl;                  // 0x0054 - Управление прицепом
    int field_58;                       // 0x0058
    int ID;                             // 0x005C - Идентификатор автомобиля
    Ped* lastDamagingPed;               // 0x0060 - Последний повредивший пешеход
    int16_t Damage;                     // 0x0064 - Повреждения
    int16_t field_66;                   // 0x0066
    int16_t PhysicsBitmask;             // 0x0068 - Физическая битовая маска
    char field_6A;                      // 0x006A
    char field_6B;                      // 0x006B
    SearchType SearchType;              // 0x006C - Тип поиска
    char field_70;                      // 0x0070
    char field_71;                      // 0x0071
    char field_72;                      // 0x0072
    char field_73;                      // 0x0073
    CarModel CarType;                   // 0x0074 - Тип автомобиля
    int Mask;                           // 0x0078 - Маска
    char FireState;                     // 0x007C - Состояние огня
    char field_7D;                      // 0x007D
    char AlarmTime;                     // 0x007E - Время сигнализации
    char field_7F;                      // 0x007F
    DamageType DamageType;              // 0x0080 - Тип повреждения
    char DamageShotTimer;               // 0x0081 - Таймер выстрела
    char PlayerId;                      // 0x0082 - ID игрока
    char field_83;                      // 0x0083
    int locksDoor;                      // 0x0084 - Блокировка дверей
    CAR_ENGINE_STATE engineState;       // 0x0088 - Состояние двигателя
    TRAFFIC_CAR_TYPE trafficCarType;    // 0x0089 - Тип трафика
    char sirenState;                    // 0x008A - Состояние сирены
    char sirenPhase;                    // 0x008B - Фаза сирены
    char field_8E;                      // 0x008E
    char horn;                          // 0x008F - Гудок
    char field_90;                      // 0x0090
    char FireTimer;                     // 0x0091 - Таймер огня
    char field_92;                      // 0x0092
    char field_93;                      // 0x0093
    int field_94;                       // 0x0094
    int field_98;                       // 0x0098
    void* currentUpgradeSound;          // 0x009C - Текущий звук улучшения
    char field_A0;                      // 0x00A0
    char field_A1;                      // 0x00A1
    char field_A2;                      // 0x00A2
    char field_A3;                      // 0x00A3
};

#pragma pack(pop)

static_assert(sizeof(Car) == 0xA4, "Car structure size mismatch");

// ============================================================================
// ФУНКЦИИ CAR (адреса из gta2.exe.map)
// ============================================================================

#ifdef __cplusplus
extern "C" {
#endif

// Адрес: 0x00403800 - Car__sub_403800
void Car__sub_403800(Car* car);

// Адрес: 0x00403820 - Car__sub_403820  
void Car__sub_403820(Car* car);

// Адрес: 0x00412BA0 - Car__IsTrainOrTrainCarriage
bool Car__IsTrainOrTrainCarriage(Car* car);

// Адрес: 0x00412BC0 - Car__IsSpecialVehicle
bool Car__IsSpecialVehicle(Car* car);

// Адрес: 0x0041E890 - Car__GetFullDamage
int Car__GetFullDamage(Car* car);

// Адрес: 0x004202A0 - Car__HasEmergencyLights
bool Car__HasEmergencyLights(Car* car);

// Адрес: 0x004208B0 - Car__GetDriver
Ped* Car__GetDriver(Car* car);

// Адрес: 0x004208C0 - Car__IsEngineOn
bool Car__IsEngineOn(Car* car);

// Адрес: 0x004208D0 - Car__IsDriverPlayer
bool Car__IsDriverPlayer(Car* car);

// Адрес: 0x004208F0 - Car__isFileTruck
bool Car__isFileTruck(Car* car);

// Адрес: 0x00420900 - Car__isTank
bool Car__isTank(Car* car);

// Адрес: 0x00420910 - Car__isGunJeep
bool Car__isGunJeep(Car* car);

// Адрес: 0x00420920 - Car__isEDSELFBI
bool Car__isEDSELFBI(Car* car);

// Адрес: 0x00420930 - Car__sub_411930
void Car__sub_411930(Car* car);

// Адрес: 0x00420940 - Car__GetModelCar
CarModel Car__GetModelCar(Car* car);

// Адрес: 0x00423F20 - Car__IsEmergencyOrFbiCar
bool Car__IsEmergencyOrFbiCar(Car* car);

// Адрес: 0x0042D430 - Car__GetX
float Car__GetX(Car* car);

// Адрес: 0x0042D440 - Car__GetY
float Car__GetY(Car* car);

// Адрес: 0x0042D450 - Car__GetZ
float Car__GetZ(Car* car);

// Адрес: 0x0042E6E0 - Car__IsCopCar
bool Car__IsCopCar(Car* car);

// Адрес: 0x0042E700 - Car__GetInfoByTypeCar
void* Car__GetInfoByTypeCar(Car* car, CarModel model);

// Адрес: 0x0042E750 - Car__IsCurrentCarBus
bool Car__IsCurrentCarBus(Car* car);

// Адрес: 0x0042E860 - Car__GetCarDoor
CarDoor* Car__GetCarDoor(Car* car, int index);

// Адрес: 0x0042ED50 - Car__AddRoofWaterGun
void Car__AddRoofWaterGun(Car* car);

// Адрес: 0x0042EDA0 - Car__AddRoofTankTurret
void Car__AddRoofTankTurret(Car* car);

// Адрес: 0x0042EDF0 - Car__AddRoofGun
void Car__AddRoofGun(Car* car);

// Адрес: 0x0042EF00 - Car__CanDriverOverCars
bool Car__CanDriverOverCars(Car* car);

// Адрес: 0x0042F330 - Car__DecrementHorn
void Car__DecrementHorn(Car* car);

// Адрес: 0x0042F7F0 - Car__SetPosition
void Car__SetPosition(Car* car, float x, float y, float z);

// Адрес: 0x0042F8F0 - Car__TransformToRecycledType
void Car__TransformToRecycledType(Car* car);

// Адрес: 0x0042F9F0 - Car__UpdateDamageCooldown
void Car__UpdateDamageCooldown(Car* car);

// Адрес: 0x00430460 - Car__SetHornDefault
void Car__SetHornDefault(Car* car);

// Адрес: 0x00430470 - Car__isMask4
bool Car__isMask4(Car* car);

// Адрес: 0x00430490 - Car__isMask3
bool Car__isMask3(Car* car);

// Адрес: 0x004304B0 - Car__isMask
bool Car__isMask(Car* car);

// Адрес: 0x004304D0 - Car__GetMask7
int Car__GetMask7(Car* car);

// Адрес: 0x004304E0 - Car__SetMask7
void Car__SetMask7(Car* car, int mask);

// Адрес: 0x004304F0 - Car__IsDriverActive
bool Car__IsDriverActive(Car* car);

// Адрес: 0x00430510 - Car__CarMakeDriveable2
void Car__CarMakeDriveable2(Car* car);

// Адрес: 0x00430560 - Car__CarMakeDriveable1
void Car__CarMakeDriveable1(Car* car);

// Адрес: 0x00430570 - Car__FixCarBrokenEngine
void Car__FixCarBrokenEngine(Car* car);

// Адрес: 0x004305B0 - Car__GetMask
int Car__GetMask(Car* car);

// Адрес: 0x004305F0 - Car__SetMask
void Car__SetMask(Car* car, int mask);

// Адрес: 0x00430610 - Car__is_train
bool Car__is_train(Car* car);

// Адрес: 0x00430620 - Car__IsCar
bool Car__IsCar(Car* car);

// Адрес: 0x00430640 - Car__is_trailer
bool Car__is_trailer(Car* car);

// Адрес: 0x004306C0 - Car__has_for_hire_lights
bool Car__has_for_hire_lights(Car* car);

#ifdef __cplusplus
}
#endif

#endif // CAR_H
