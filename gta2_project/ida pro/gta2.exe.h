// ============================================================================
// GTA2 Reverse Engineering - Структуры для IDA Pro
// Файл: gta2.exe.h
// Описание: Заголовочный файл с определениями структур и прототипами функций
// Архитектура: x86 (32-бит), выравнивание по 4 байта
// ============================================================================
// 
// ИНСТРУКЦИЯ ПО ИМПОРТУ В IDA Pro:
// 1. File -> Load file -> Parse C header file...
// 2. Выберите этот файл
// 3. Структуры появятся в окне Structures (Shift+F1)
// 4. Примените типы к функциям через Local Types (Ctrl+F9)
// ============================================================================

#ifndef GTA2_EXE_H
#define GTA2_EXE_H

#include <stdint.h>

// ============================================================================
// БАЗОВЫЕ ТИПЫ
// ============================================================================
typedef uint8_t     byte;
typedef uint16_t    word;
typedef uint32_t    dword;
typedef int8_t      s8;
typedef int16_t     s16;
typedef int32_t     s32;
typedef uint8_t     u8;
typedef uint16_t    u16;
typedef uint32_t    u32;
typedef float       f32;
typedef double      f64;
typedef void        undefined;
typedef uintptr_t   undefined4;  // 32-битное значение (указатель или int)

// ============================================================================
// ПРЕДОБЪЯВЛЕНИЯ СТРУКТУР
// ============================================================================
struct RouteNode;
struct Car;
struct S3;
struct SpriteS1;
struct SpriteS3;

// ============================================================================
// S82: BaseCar - Базовый класс автомобиля (0x68 байт = 104 байта)
// ============================================================================
// Адрес в IDA: [указать после анализа]
// Размер: 0x68
// Описание: Базовая физика всех транспортных средств
// ============================================================================
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
    
    // === Блок 5: Физика (0x3C - 0x47) ===
    f32 VelocityX;          // 0x3C - Вектор скорости X
    f32 VelocityY;          // 0x40 - Вектор скорости Y
    f32 AngularVelocity;    // 0x44 - Угловая скорость (поворот)
    
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
    // === Конец структуры: 0x68 (104 байта) ===
};

// ============================================================================
// S81: PublicTransport - Общественный транспорт (0x7C байт = 124 байта)
// ============================================================================
// Адрес в IDA: [указать после анализа]
// Размер: 0x7C
// Наследует: S82_BaseCar (первые 0x68 байт идентичны)
// Описание: Логика общественного транспорта (автобусы, такси, трамваи)
// ============================================================================
struct S81_PublicTransport {
    // === УНАСЛЕДОВАНО ОТ S82_BaseCar (0x00 - 0x67) ===
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
    // === Конец структуры: 0x7C (124 байта) ===
};

// ============================================================================
// S3: Элемент рендеринга (связывает спрайты и объекты)
// ============================================================================
struct S3 {
    struct SpriteS1 *SpriteS1;        // 0x00 - Спрайт
    struct Car *Car;                  // 0x04 - Ссылка на автомобиль
    struct SpriteS3 *SpriteS3;        // 0x08 - Дополнительный спрайт
    struct S3 *NextElement;           // 0x0C - Следующий элемент в списке
    f32 PositionX;                    // 0x10 - Позиция X
    f32 PositionY;                    // 0x14 - Позиция Y
    f32 PositionZ;                    // 0x18 - Позиция Z
    f32 Rotation;                     // 0x1C - Поворот
    s16 Remap;                        // 0x20 - Цветовая палитра
    u16 Scale;                        // 0x22 - Масштаб
    s16 FrameIndex;                   // 0x24 - Индекс кадра анимации
    u8 AnimState;                     // 0x26 - Состояние анимации
    u8 BlendMode;                     // 0x27 - Режим смешивания
    u32 TextureId;                    // 0x28 - ID текстуры
    u8 RenderFlags;                   // 0x2C - Флаги рендеринга
    u8 SortKey;                       // 0x2D - Ключ сортировки
    u8 ClipRegion;                    // 0x2E - Регион обрезки
    u8 EffectType;                    // 0x2F - Тип эффекта
    struct S3 *PrevElement;           // 0x30 - Предыдущий элемент
    f32 FadeValue;                    // 0x34 - Значение затухания
    u8 RedTint;                       // 0x38 - Красный оттенок
    u8 GreenTint;                     // 0x39 - Зелёный оттенок
    u8 BlueTint;                      // 0x3A - Синий оттенок
    u8 AlphaTint;                     // 0x3B - Альфа-оттенок
    // Размер: 0x3C (60 байт)
};

// ============================================================================
// RouteNode: Узел маршрута общественного транспорта
// ============================================================================
struct RouteNode {
    f32 X;                    // 0x00 - Координата X остановки
    f32 Y;                    // 0x04 - Координата Y остановки
    f32 Z;                    // 0x08 - Координата Z остановки
    f32 Radius;               // 0x0C - Радиус остановки
    u32 WaitTime;             // 0x10 - Время ожидания (кадры)
    u32 Flags;                // 0x14 - Флаги узла
    struct RouteNode* Next;   // 0x18 - Следующий узел
    struct RouteNode* Prev;   // 0x1C - Предыдущий узел
    // Размер: 0x20 (32 байта)
};

// ============================================================================
// Car: Автомобиль (производный от BaseCar)
// ============================================================================
struct Car {
    struct S82_BaseCar Base;      // 0x00 - Базовый класс
    u32 ModelId;                  // 0x68 - ID модели
    u32 Color;                    // 0x6C - Цвет
    u32 Owner;                    // 0x70 - Владелец (игрок, ИИ)
    f32 SteeringAngle;            // 0x74 - Угол поворота руля
    u32 Gear;                     // 0x78 - Передача
    f32 BrakeForce;               // 0x7C - Сила торможения
    u32 HeadlightsOn;             // 0x80 - Фары включены
    u32 SirenOn;                  // 0x84 - Сирена включена
    // ... дополнительные поля
};

// ============================================================================
// enum VehicleType: Типы транспортных средств
// ============================================================================
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

// ============================================================================
// enum PublicTransportState: Состояния общественного транспорта
// ============================================================================
enum PublicTransportState {
    PT_STATE_IDLE = 0,              // Бездействует
    PT_STATE_MOVING = 1,            // Движение по маршруту
    PT_STATE_APPROACHING_STOP = 2,  // Приближение к остановке
    PT_STATE_AT_STOP = 3,           // На остановке
    PT_STATE_BOARDING = 4,          // Посадка/высадка
    PT_STATE_DEPARTING = 5,         // Отправление
    PT_STATE_DETOURED = 6           // Изменённый маршрут
};

// ============================================================================
// enum RouteFlags: Флаги маршрута
// ============================================================================
enum RouteFlags {
    ROUTE_FLAG_FOLLOW_PATH = 0x01,  // Следует по маршруту
    ROUTE_FLAG_AT_STOP = 0x02,      // Находится на остановке
    ROUTE_FLAG_WAITING = 0x04,      // Ожидает пассажиров
    ROUTE_FLAG_SPECIAL = 0x08,      // Специальный рейс
    ROUTE_FLAG_NIGHT = 0x10,        // Ночной маршрут
    ROUTE_FLAG_EXPRESS = 0x20       // Экспресс (минует некоторые остановки)
};

// ============================================================================
// ПРОТОТИПЫ ФУНКЦИЙ S81 (PublicTransport)
// ============================================================================

// Инициализация общественного транспорта
// old_name: FUN_004af640
void __stdcall S81_Init(struct S81_PublicTransport* this);

// Обновление логики общественного транспорта
// old_name: FUN_004af700
void __stdcall S81_Update(struct S81_PublicTransport* this);

// Установка маршрута
// old_name: FUN_004af8a0
void __stdcall S81_SetRoute(struct S81_PublicTransport* this, struct RouteNode* route, int nodeCount);

// Переход к следующей остановке
// old_name: FUN_004af9c0
void __stdcall S81_NextStop(struct S81_PublicTransport* this);

// Проверка: является ли автомобиль автобусом
// old_name: FUN_004afb20
int __stdcall S81_IsThisBus(struct S81_PublicTransport* this, struct Car* car);

// Поиск поля S3 для автомобиля
// old_name: FUN_004b1b40
struct S3* __stdcall S81_FindCarField(struct S81_PublicTransport* this, struct Car* car);

// Обработка взаимодействия с автомобилем
// old_name: FUN_004b0d70
void __stdcall S81_ProcessCarInteraction(struct S81_PublicTransport* this, struct Car* car);

// Проверка лимита пропущенных остановок
// old_name: FUN_004afc80
int __stdcall S81_HasReachedBusSkipLimit(struct S81_PublicTransport* this);

// ============================================================================
// ПРОТОТИПЫ ФУНКЦИЙ S82 (BaseCar)
// ============================================================================

// Инициализация базового автомобиля
// old_name: FUN_004e5a10
void __stdcall S82_Init(struct S82_BaseCar* this);

// Обновление физики
// old_name: FUN_004e5b30
void __stdcall S82_UpdatePhysics(struct S82_BaseCar* this);

// Применение силы
// old_name: FUN_004e5c50
void __stdcall S82_ApplyForce(struct S82_BaseCar* this, f32 forceX, f32 forceY);

// Установка скорости
// old_name: FUN_004e5d70
void __stdcall S82_SetSpeed(struct S82_BaseCar* this, f32 speed);

// Поворот
// old_name: FUN_004e5e90
void __stdcall S82_Turn(struct S82_BaseCar* this, f32 angle);

// Проверка коллизий
// old_name: FUN_004e5fb0
int __stdcall S82_CheckCollision(struct S82_BaseCar* this);

// ============================================================================
// ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ (адреса указать после анализа)
// ============================================================================
// extern struct S81_PublicTransport* gPublicTransportPool;  // Адрес: 0xXXXXX
// extern struct S82_BaseCar* gBaseCarPool;                  // Адрес: 0xXXXXX
// extern struct Car* gCarPool;                              // Адрес: 0xXXXXX

#endif // GTA2_EXE_H
