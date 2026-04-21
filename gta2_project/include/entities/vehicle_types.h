#ifndef VEHICLE_TYPES_H
#define VEHICLE_TYPES_H

#include "../core/types.h"
#include "../core/forward_declarations.h"

// ============================================================================
// ПРИМЕЧАНИЕ: Структуры определены для 32-битной архитектуры (x86)
// - Указатели занимают 4 байта (не 8!)
// - Выравнивание по 4 байтам
// ============================================================================

// ============================================================================
// ИЕРАРХИЯ ТРАНСПОРТНЫХ СРЕДСТВ GTA2
// ============================================================================
// 
// BaseCar (S82, 0x68 байт) - БАЗОВЫЙ КЛАСС
//   └── Общая логика физики автомобилей
//       - Позиция, скорость, ускорение
//       - Коллизии, трение, гравитация
//       - Базовые состояния (движение, остановка)
//
// PublicTransport (S81, 0x7C байт) - НАСЛЕДНИК BaseCar
//   └── Логика общественного транспорта
//       - Маршруты (RouteNodesPtr)
//       - Остановки, таймеры остановок
//       - Пассажиры, посадка/высадка
//       - Специфичные флаги маршрута
//
// Car (производный от BaseCar) - Конкретные автомобили
//   └── Легковые, грузовые, спецмашины
//
// ============================================================================

// ----------------------------------------------------------------------------
// S82: BaseCar - Базовый класс автомобиля (0x68 байт)
// ----------------------------------------------------------------------------
// Адрес в IDA: 0xXXXXX (указать после анализа)
// Размер: 0x68 (104 байта)
// ----------------------------------------------------------------------------
struct S82_BaseCar {
    // === Блок 1: Позиция и ориентация (0x00 - 0x0F) ===
    f32 PositionX;          // 0x00 - Координата X
    f32 PositionY;          // 0x04 - Координата Y
    f32 PositionZ;          // 0x08 - Координата Z (высота)
    f32 Heading;            // 0x0C - Угол поворота (радианы)

    // === Блок 2: Физика (0x10 - 0x1F) ===
    f32 Speed;              // 0x10 - Текущая скорость
    f32 Acceleration;       // 0x14 - Ускорение
    f32 Mass;               // 0x18 - Масса транспортного средства
    f32 Friction;           // 0x1C - Коэффициент трения

    // === Блок 3: Состояние (0x20 - 0x2F) ===
    u32 VehicleType;        // 0x20 - Тип ТС (enum VehicleType)
    s32 Health;             // 0x24 - Здоровье (0 = уничтожено)
    s32 MaxHealth;          // 0x28 - Максимальное здоровье
    u32 Flags;              // 0x2C - Флаги состояния (битовая маска)

    // === Блок 4: Управление и таймеры (0x30 - 0x3B) ===
    u32 State;              // 0x30 - Состояние (активен, без водителя, etc)
    u32 Timer;              // 0x34 - Универсальный таймер/задержка
    u16 PassengerCount;     // 0x38 - Количество пассажиров
    u8 TrafficLightState;   // 0x3A - Состояние светофора
    u8 DoorState;           // 0x3B - Состояние дверей
    // Выравнивание не требуется, следующее поле f32 начинается с 0x3C

    // === Блок 5: Физика (0x3C - 0x47) ===
    f32 VelocityX;          // 0x3C - Вектор скорости X
    f32 VelocityY;          // 0x40 - Вектор скорости Y
    f32 AngularVelocity;    // 0x44 - Угловая скорость (поворот)
    // Примечание: DragCoefficient удалён для соответствия размеру 0x68

    // === Блок 6: Дополнительные параметры (0x48 - 0x67) ===
    u32 DamageFlags;        // 0x48 - Флаги повреждений
    u32 LightState;         // 0x4C - Состояние освещения (фары, поворотники)
    u8 EngineOn;            // 0x50 - Двигатель заведён (0/1)
    u8 Handbrake;           // 0x51 - Ручной тормоз (0/1)
    u8 Reserved1;           // 0x52 - Выравнивание
    u8 Reserved2;           // 0x53 - Выравнивание
    f32 SuspensionHeight;   // 0x54 - Высота подвески
    u32 WheelRotation[2];   // 0x58 - Вращение колёс [передние, задние]
    u8 Padding[8];          // 0x60 - Резерв/выравнивание до 0x68
    // === Конец структуры: 0x68 ===
};

// ----------------------------------------------------------------------------
// S81: PublicTransport - Общественный транспорт (0x7C байт)
// ----------------------------------------------------------------------------
// Адрес в IDA: 0xXXXXX (указать после анализа)
// Размер: 0x7C (124 байта)
// Наследует: S82_BaseCar (первые 0x68 байт идентичны)
// ----------------------------------------------------------------------------
struct S81_PublicTransport {
    // === УНАСЛЕДОВАНО ОТ BaseCar (0x00 - 0x67) ===
    struct S82_BaseCar Base;    // 0x00 - Базовый класс (0x68 байт)

    // === СПЕЦИФИКА PUBLIC TRANSPORT (0x68 - 0x7B) ===
    struct RouteNode* RouteNodesPtr;  // 0x68 - Указатель на массив узлов маршрута
    u16 CurrentRouteIndex;            // 0x6C - Текущий индекс узла маршрута
    u16 NextRouteIndex;               // 0x6E - Следующий индекс узла маршрута
    u32 StopTimer;                    // 0x70 - Таймер остановки (кадры)
    u8 RouteFlags;                    // 0x74 - Флаги маршрута
                                      //   Бит 0: следует маршруту
                                      //   Бит 1: на остановке
                                      //   Бит 2: ожидает пассажиров
                                      //   Бит 3: специальный рейс
    u8 StopState;                     // 0x75 - Состояние остановки
                                      //   0: движение
                                      //   1: прибытие
                                      //   2: посадка/высадка
                                      //   3: отправление
    u8 Priority;                      // 0x76 - Приоритет транспорта (для ИИ)
    u8 Reserved;                      // 0x77 - Выравнивание
    u32 RouteID;                      // 0x78 - ID текущего маршрута
    // === Конец структуры: 0x7C ===
};

// ----------------------------------------------------------------------------
// Вспомогательные типы для работы с транспортом
// ----------------------------------------------------------------------------

// Типы транспортных средств (VehicleType)
enum VehicleType {
    VEHICLE_TYPE_CAR = 0,           // Легковой автомобиль
    VEHICLE_TYPE_TRUCK = 1,         // Грузовик
    VEHICLE_TYPE_BUS = 2,           // Автобус (PublicTransport)
    VEHICLE_TYPE_TAXI = 3,          // Такси
    VEHICLE_TYPE_POLICE = 4,        // Полиция
    VEHICLE_TYPE_AMBULANCE = 5,     // Скорая помощь
    VEHICLE_TYPE_FIRETRUCK = 6,     // Пожарная машина
    VEHICLE_TYPE_MILITARY = 7,      // Военный транспорт
    VEHICLE_TYPE_TRAIN = 8,         // Поезд
    VEHICLE_TYPE_BOAT = 9,          // Лодка
    VEHICLE_TYPE_HELICOPTER = 10,   // Вертолёт
    VEHICLE_TYPE_PLANE = 11,        // Самолёт
    VEHICLE_TYPE_BIKE = 12,         // Мотоцикл
    VEHICLE_TYPE_SPECIAL = 15       // Специальный транспорт
};

// Состояния общественного транспорта
enum PublicTransportState {
    PT_STATE_IDLE = 0,              // Бездействует
    PT_STATE_MOVING = 1,            // Движение по маршруту
    PT_STATE_APPROACHING_STOP = 2,  // Приближение к остановке
    PT_STATE_AT_STOP = 3,           // На остановке
    PT_STATE_BOARDING = 4,          // Посадка/высадка
    PT_STATE_DEPARTING = 5,         // Отправление
    PT_STATE_DEToured = 6           // Изменённый маршрут
};

// Флаги маршрута (RouteFlags)
enum RouteFlags {
    ROUTE_FLAG_FOLLOW_PATH = 0x01,  // Следует по маршруту
    ROUTE_FLAG_AT_STOP = 0x02,      // Находится на остановке
    ROUTE_FLAG_WAITING = 0x04,      // Ожидает пассажиров
    ROUTE_FLAG_SPECIAL = 0x08,      // Специальный рейс
    ROUTE_FLAG_NIGHT = 0x10,        // Ночной маршрут
    ROUTE_FLAG_EXPRESS = 0x20       // Экспресс (минует некоторые остановки)
};

// ----------------------------------------------------------------------------
// Глобальные переменные (адреса для IDA Pro)
// ----------------------------------------------------------------------------
// extern struct S81_PublicTransport* _gPublicTransport;  // Адрес: 0xXXXXX
// extern struct S82_BaseCar* _gBaseCarPool;              // Адрес: 0xXXXXX

// ----------------------------------------------------------------------------
// Прототипы функций PublicTransport (S81)
// ----------------------------------------------------------------------------

// Инициализация общественного транспорта
// old_name: FUN_0045dd20
void S81_Init(struct S81_PublicTransport* this);

// Поиск свободного слота в массиве ARR_S82
// old_name: FUN_004af420
int S81_FindFreeSlot(struct S81_PublicTransport* this);

// Добавление транспортного средства в маршрут (поезд/трамвай)
// old_name: FUN_004af460
void S81_AddToRoute(struct S81_PublicTransport* this, u32* routeData);

// Обновление маршрутов (циклический сдвиг)
// old_name: FUN_004af4a0
void S81_UpdateRoutes(struct S81_PublicTransport* this);

// Обработка данных маршрута (узлы, пути)
// old_name: FUN_004af500
void S81_ProcessRouteData(struct S81_PublicTransport* this);

// Проверка: является ли автомобиль этим автобусом/поездом
// old_name: FUN_004af5a0
bool S81_IsThisBus(struct S81_PublicTransport* this, struct Car* pCar);

// Получение количества пропущенных ТС (лимит)
// old_name: FUN_004af5a0 (частично)
bool S81_HasReachedBusSkipLimit(struct S81_PublicTransport* this);

// Увеличение счётчика пропусков
// old_name: FUN_004af5e0
void S81_IncrementSkipCount(struct S81_PublicTransport* this);

// Сброс счётчика пропусков и очистка пассажира
// old_name: FUN_004af5f0
void S81_ResetSkipCount(struct S81_PublicTransport* this);

// Поиск по индексу в ARR_S82
// old_name: FUN_004af660
struct S81_PublicTransport* S81_FindByIndex(struct S81_PublicTransport* this, int index);

// Поиск автомобиля в компонентах поезда (возвращает S83*)
// old_name: FUN_004af680
int S81_FindCarInTrain(struct S81_PublicTransport* this, struct Car* pCar);

// Обновление логики общественного транспорта (каждый кадр)
// old_name: FUN_004af700
void S81_Update(struct S81_PublicTransport* this);

// Поиск автомобиля в массиве ARR_S83 (возвращает индекс или S83*)
// old_name: FUN_004af700 (частично)
int S81_FindCarIndex(struct S81_PublicTransport* this, struct Car* pCar);

// Установка маршрута для общественного транспорта
// old_name: FUN_004af8a0
void S81_SetRoute(struct S81_PublicTransport* this, struct RouteNode* route, int nodeCount);

// Переход к следующей остановке маршрута
// old_name: FUN_004af9c0
void S81_NextStop(struct S81_PublicTransport* this);

// Проверка, является ли автомобиль автобусом (общественным транспортом)
// old_name: FUN_004afb20
int S81_IsThisBus_Global(struct S81_PublicTransport* this, struct Car* car);

// Проверка, достигнут ли лимит пропущенных остановок
// old_name: FUN_004afc80
int S81_HasReachedBusSkipLimit_Check(struct S81_PublicTransport* this);

// Отрисовка индикаторов маршрута (поезда/трамваи)
// old_name: FUN_004afe20
void S81_RenderRouteIndicators(struct S81_PublicTransport* this);

// Инициализация маршрутов из карты (trak0-trak4, bus stops)
// old_name: FUN_004b08a0
void S81_InitializeRoutesFromMap(struct S81_PublicTransport* this);

// Обработка взаимодействия с автомобилем (автобус/поезд)
// old_name: FUN_004b0d70
int S81_ProcessCarInteraction(struct S81_PublicTransport* this, struct Car* pCar);

// Обновление состояния всех компонентов поезда/автобуса
// old_name: FUN_004b1560
void S81_UpdateAllComponents(struct S81_PublicTransport* this);

// Поиск головного вагона/автобуса для данного автомобиля
// old_name: FUN_004b1b40
struct Car* S81_FindCarField(struct S81_PublicTransport* this, struct Car* pCar);

// Проверка: являются ли два автомобиля частью одного поезда (разные вагоны)
// old_name: FUN_004b1b80
bool S81_AreSameTrain(struct S81_PublicTransport* this, struct Car* pCar1, struct Car* pCar2);

// ----------------------------------------------------------------------------
// Прототипы функций BaseCar (S82)
// ----------------------------------------------------------------------------

// Инициализация базового автомобиля
// old_name: FUN_004e5a10
void S82_Init(struct S82_BaseCar* this);

// Обновление физики автомобиля (каждый кадр)
// old_name: FUN_004e5b30
void S82_UpdatePhysics(struct S82_BaseCar* this);

// Применение силы к автомобилю
// old_name: FUN_004e5c50
void S82_ApplyForce(struct S82_BaseCar* this, f32 forceX, f32 forceY);

// Установка скорости автомобиля
// old_name: FUN_004e5d70
void S82_SetSpeed(struct S82_BaseCar* this, f32 speed);

// Поворот автомобиля на угол
// old_name: FUN_004e5e90
void S82_Turn(struct S82_BaseCar* this, f32 angle);

// Проверка коллизий автомобиля
// old_name: FUN_004e5fb0
int S82_CheckCollision(struct S82_BaseCar* this);

// ----------------------------------------------------------------------------
// Прототипы функций TrainComponent (S83)
// ----------------------------------------------------------------------------

// Обновление состояния компонента поезда
// old_name: FUN_004af9a0
void S83_Update(struct S83_TrainComponent* this);

// Связывание вагонов в состав поезда
// old_name: FUN_004afa10
void S83_LinkCarriages(struct S83_TrainComponent* this);

// Отсоединение вагонов от поезда
// old_name: FUN_004afa80
void S83_UnlinkCarriages(struct S83_TrainComponent* this);

#endif // VEHICLE_TYPES_H
