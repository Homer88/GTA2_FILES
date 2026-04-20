#ifndef TRAFFIC_SYSTEM_H
#define TRAFFIC_SYSTEM_H

#include "types.h"
#include "math_types/vector2d.h"

// Forward declarations
typedef struct Car Car;

// ============================================================================
// 1. TRAFFIC_LIGHT (Светофор)
// ============================================================================

typedef enum {
    LIGHT_RED = 0,
    LIGHT_GREEN = 1,
    LIGHT_YELLOW = 2,
    LIGHT_BLINK_YELLOW = 3 // Ночной режим
} TrafficLightState;

typedef struct {
    u8 State;           // 0x00 - Текущий цвет (TrafficLightState)
    u8 Timer;           // 0x01 - Таймер до переключения
    u8 DirectionMask;   // 0x02 - Активные направления (битовая маска)
    u8 Padding;         // 0x03 - Выравнивание
    u16 LinkedNodeID;   // 0x04 - ID узла навигации
    u16 GroupID;        // 0x06 - ID группы синхронизации
    u8 BlinkRate;       // 0x08 - Скорость мигания
    u8 Flags;           // 0x09 - Флаги (бит 0: активен ночью, бит 1: сломан)
    u8 Padding2[2];     // 0x0A - Выравнивание
} TrafficLight;         // Размер: 12 байт

typedef enum {
    TRAFFIC_NORMAL = 0,
    TRAFFIC_HEAVY = 1,
    TRAFFIC_LIGHT = 2,
    TRAFFIC_NONE = 3
} TrafficDensity;

// ============================================================================
// 2. PARKING_SPOT (Парковочное место)
// ============================================================================

typedef enum {
    PARKING_REGULAR = 0,
    PARKING_POLICE = 1,
    PARKING_MISSION = 2,
    PARKING_DISABLED = 3
} ParkingType;

typedef struct {
    Vector2D Position;      // 0x00 - Координаты центра
    f32 Angle;              // 0x08 - Угол заезда
    u8 IsOccupied;          // 0x0C - Занято ли
    u8 Type;                // 0x0D - Тип парковки
    u16 Reserved;           // 0x0E - Резерв
    Car* OccupantCarPtr;    // 0x10 - Указатель на машину
    u32 ZoneID;             // 0x14 - ID зоны
} ParkingSpot;              // Размер: 24 байта

// ============================================================================
// 3. SIREN_LOGIC (Логика спецтранспорта - контекст внутри Car)
// ============================================================================

typedef struct {
    u8 SirenOn : 1;         // Бит 0: Сирена включена
    u8 LightsFlashing : 1;  // Бит 1: Мигалки
    u8 PriorityMode : 1;    // Бит 2: Приоритетный режим (игнор светофоров)
    u8 Unused : 5;          // Биты 3-7: Не используются
    u8 Padding;             // Выравнивание
    void* EmergencyTarget;  // Указатель на цель преследования (Ped* или Car*)
    u32 SirenTimer;         // Таймер цикла сирены
} SirenContext;             // Размер: 12 байт

// ============================================================================
// 4. ROAD_SEGMENT (Дорожный сегмент)
// ============================================================================

typedef struct {
    Vector2D StartPoint;    // Начало сегмента
    Vector2D EndPoint;      // Конец сегмента
    f32 SpeedLimit;         // Ограничение скорости
    u8 LaneCount;           // Количество полос
    u8 Direction;           // Направление движения (0: два-way, 1: one-way)
    u8 Flags;               // Флаги (мост, тоннель, дорога)
    u8 SurfaceType;         // Тип покрытия
} RoadSegment;              // Размер: ~32 байта

// ============================================================================
// МЕНЕДЖЕР ТРАФИКА
// ============================================================================

#define MAX_TRAFFIC_LIGHTS 64
#define MAX_PARKING_SPOTS 128
#define MAX_ROAD_SEGMENTS 256

typedef struct {
    TrafficLight Lights[MAX_TRAFFIC_LIGHTS];
    u8 LightActiveMap[(MAX_TRAFFIC_LIGHTS + 7) / 8];
    
    ParkingSpot ParkingSpots[MAX_PARKING_SPOTS];
    u8 ParkingActiveMap[(MAX_PARKING_SPOTS + 7) / 8];
    
    RoadSegment Roads[MAX_ROAD_SEGMENTS];
    u32 TotalRoads;
    
    TrafficDensity GlobalDensity;
    u8 CurrentHour;
    f32 GlobalSpeedMultiplier;
    
    u32 CarsPassedGreenLight;
    u32 CarsStoppedAtRed;
} TrafficManager;

// ============================================================================
// ПРОТОТИПЫ ФУНКЦИЙ
// ============================================================================

// TrafficLight Functions
void TrafficLight_Init(TrafficLight* tl, u16 nodeId, u16 groupId);
void TrafficLight_Update(TrafficLight* tl, f32 dt);
bool TrafficLight_IsGreen(TrafficLight* tl, Car* car);
void TrafficLight_SyncGroup(TrafficLight* lights, u16 groupId);

// ParkingSpot Functions
void ParkingSpot_Init(ParkingSpot* ps, Vector2D pos, f32 angle, ParkingType type);
ParkingSpot* Parking_FindFreeSpot(Vector2D pos, f32 radius);
bool Parking_TryPark(Car* car, ParkingSpot* spot);
void Parking_Release(Car* car);

// Siren Functions
void Siren_Init(SirenContext* sc);
void Siren_Toggle(SirenContext* sc);
bool Siren_HasPriority(SirenContext* sc);
void Traffic_YieldToSiren(Car* trafficCar, Car* policeCar);

// Road Functions
f32 Road_GetSpeedLimit(RoadSegment* rs);
bool Road_IsOneWay(RoadSegment* rs);

// Manager Functions
void TrafficManager_Init(void);
void TrafficManager_UpdateAll(f32 dt, u8 currentHour);
TrafficLight* TrafficManager_GetLightAtNode(u16 nodeId);
ParkingSpot* TrafficManager_FindNearestParking(Vector2D pos, f32 radius);

#endif // TRAFFIC_SYSTEM_H
