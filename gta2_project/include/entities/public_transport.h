#ifndef PUBLIC_TRANSPORT_H
#define PUBLIC_TRANSPORT_H

#include "../core/types.h"
#include "../entities/vehicle_types.h"
#include "../entities/car.h"

// ============================================================================
// PUBLIC TRANSPORT (S81) - ФУНКЦИИ И СТРУКТУРЫ
// ============================================================================
// Адрес в IDA: 0x0045dd20 - 0x004b1b80
// Размер структуры: 0x7C байт (наследуется от S82_BaseCar)
// ============================================================================

// ----------------------------------------------------------------------------
// Структура S83 - Компоненты поезда/трамвая (вспомогательная)
// ----------------------------------------------------------------------------
struct S83_TrainComponent {
    struct Car* Car;                    // 0x00 - Указатель на вагон/локомотив
    u8 field0_0x0;                      // 0x04 - Флаг активности
    u8 field53_0x43;                    // 0x05 - Количество связанных вагонов
    u8 field60_0x50;                    // 0x06 - Состояние (0-5)
    u8 field58_0x48;                    // 0x07 - Подсостояние
    int field59_0x4c;                   // 0x08 - Указатель на данные маршрута
    int trainComponents[8];             // 0x0C - Массив связанных вагонов
    u8 Padding[0x50 - 0x2C];            // Выравнивание до 0x50+
};

// ----------------------------------------------------------------------------
// Расширенная структура PublicTransport (S81)
// ----------------------------------------------------------------------------
struct PublicTransport {
    // === УНАСЛЕДОВАНО ОТ S82_BaseCar (0x00 - 0x67) ===
    struct S82_BaseCar Base;            // 0x00 - Базовый класс
    
    // === СПЕЦИФИКА PUBLIC TRANSPORT (0x68 - 0x7B) ===
    struct RouteNode* RouteNodesPtr;    // 0x68 - Указатель на массив узлов маршрута
    u16 CurrentRouteIndex;              // 0x6C - Текущий индекс узла маршрута
    u16 NextRouteIndex;                 // 0x6E - Следующий индекс узла маршрута
    u32 StopTimer;                      // 0x70 - Таймер остановки (кадры)
    u8 RouteFlags;                      // 0x74 - Флаги маршрута
    u8 StopState;                       // 0x75 - Состояние остановки
    u8 Priority;                        // 0x76 - Приоритет транспорта
    u8 Reserved;                        // 0x77 - Выравнивание
    u32 RouteID;                        // 0x78 - ID текущего маршрута
    
    // === ДОПОЛНИТЕЛЬНЫЕ ПОЛЯ (из анализа game.c) ===
    struct S82_BaseCar ARR_S82[10];     // Массив базовых автомобилей (поезда)
    struct S83_TrainComponent ARR_S83[10]; // Массив компонентов поездов
    struct {
        u32 field0_0x0;                 // Счётчик или флаг
        int field4_0x4;                 // Таймер или параметр
        u32 field58_0x48;               // Состояние автобуса
        u32 SkipCount;                  // Счётчик пропусков
    } BusMetrics;                       // Метрики автобуса
    
    u8 audioBuffers[32];                // Аудио буферы для сирен/звуков
    bool field1_0x1;                    // Флаг состояния
};

// Глобальная переменная
extern struct PublicTransport* _gPublicTransport;  // Адрес: 0xXXXXX (указать после анализа)

// ============================================================================
// ПРОТОТИПЫ ФУНКЦИЙ PUBLIC TRANSPORT (S81)
// ============================================================================

// Инициализация общественного транспорта
// Было: S81_FUN_0045dd20
void PublicTransport__Init(struct PublicTransport* this);

// Поиск свободного слота в массиве ARR_S82
// Было: S81_FUN_004af420
int PublicTransport__FindFreeSlot(struct PublicTransport* this);

// Добавление транспортного средства в маршрут (поезд/трамвай)
// Было: FUN_004af460
void PublicTransport__AddToRoute(struct PublicTransport* this, u32* routeData);

// Обновление маршрутов (циклический сдвиг)
// Было: FUN_004af4a0
void PublicTransport__UpdateRoutes(struct PublicTransport* this);

// Обработка данных маршрута (узлы, пути)
// Было: FUN_004af500
void PublicTransport__ProcessRouteData(struct PublicTransport* this);

// Проверка: является ли автомобиль этим автобусом/поездом
// Было: FUN_004af5a0 (частично), IsThisBus
bool PublicTransport__IsThisBus(struct PublicTransport* this, struct Car* pCar);

// Получение количества пропущенных ТС (лимит)
// Было: FUN_004af5a0 (частично), HasReachedBusSkipLimit
bool PublicTransport__HasReachedBusSkipLimit(struct PublicTransport* this);

// Увеличение счётчика пропусков
// Было: FUN_004af5e0
void PublicTransport__IncrementSkipCount(struct PublicTransport* this);

// Сброс счётчика пропусков и очистка пассажира
// Было: FUN_004af5f0
void PublicTransport__ResetSkipCount(struct PublicTransport* this);

// Поиск по индексу в ARR_S82
// Было: FUN_004af660
struct PublicTransport* PublicTransport__FindByIndex(struct PublicTransport* this, int index);

// Поиск автомобиля в компонентах поезда (возвращает S83*)
// Было: S81_FUN_004af680
int PublicTransport__FindCarInTrain(struct PublicTransport* this, struct Car* pCar);

// Поиск автомобиля в массиве ARR_S83 (возвращает индекс или S83*)
// Было: S81_FUN_004af700
int PublicTransport__FindCarIndex(struct PublicTransport* this, struct Car* pCar);

// Отрисовка индикаторов маршрута (поезда/трамваи)
// Было: S81_FUN_004afe20
void PublicTransport__RenderRouteIndicators(struct PublicTransport* this);

// Инициализация маршрутов из карты (trak0-trak4, bus stops)
// Было: S81_FUN_004b08a0
void PublicTransport__InitializeRoutesFromMap(struct PublicTransport* this);

// Обработка взаимодействия с автомобилем (автобус/поезд)
// Было: S81_FUN_004b0d70
int PublicTransport__ProcessCarInteraction(struct PublicTransport* this, struct Car* pCar);

// Обновление состояния всех компонентов поезда/автобуса
// Было: S81_FUN_004b1560
void PublicTransport__UpdateAllComponents(struct PublicTransport* this);

// Поиск головного вагона/автобуса для данного автомобиля
// Было: S81_FUN_004b1b40
struct Car* PublicTransport__FindLeadVehicle(struct PublicTransport* this, struct Car* pCar);

// Проверка: являются ли два автомобиля частью одного поезда (разные вагоны)
// Было: S81_FUN_004b1b80
bool PublicTransport__AreSameTrain(struct PublicTransport* this, struct Car* pCar1, struct Car* pCar2);

// Вспомогательные функции S83 (компоненты поезда)
void S83__Update(struct S83_TrainComponent* this);
void S83__FUN_004afa10(struct S83_TrainComponent* this);  // Было: FUN_004afa10
void S83__FUN_004af9a0(struct S83_TrainComponent* this);  // Было: FUN_004af9a0
void S83__FUN_004afa80(struct S83_TrainComponent* this);  // Было: FUN_004afa80

#endif // PUBLIC_TRANSPORT_H
