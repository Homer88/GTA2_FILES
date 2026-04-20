#include "traffic_system.h"
#include "car.h"
#include <string.h>

// Глобальный менеджер трафика
static TrafficManager g_trafficManager;

// ============================================================================
// TRAFFIC LIGHT FUNCTIONS
// ============================================================================

void TrafficLight_Init(TrafficLight* tl, u16 nodeId, u16 groupId) {
    if (!tl) return;
    memset(tl, 0, sizeof(TrafficLight));
    tl->State = LIGHT_RED;
    tl->Timer = 30; // 30 секунд красный по умолчанию
    tl->LinkedNodeID = nodeId;
    tl->GroupID = groupId;
    tl->BlinkRate = 2;
    tl->Flags = 1; // Активен ночью
}

void TrafficLight_Update(TrafficLight* tl, f32 dt) {
    if (!tl || (tl->Flags & 2)) return; // Сломан
    
    // Уменьшаем таймер
    if (tl->Timer > 0) {
        tl->Timer -= (u8)(dt * 10); // Примерное уменьшение
    } else {
        // Переключение состояния
        switch (tl->State) {
            case LIGHT_RED:
                tl->State = LIGHT_GREEN;
                tl->Timer = 25; // Зеленый горит 25 сек
                g_trafficManager.CarsPassedGreenLight = 0; // Сброс счетчика
                break;
                
            case LIGHT_GREEN:
                tl->State = LIGHT_YELLOW;
                tl->Timer = 5; // Желтый 5 сек
                break;
                
            case LIGHT_YELLOW:
                tl->State = LIGHT_RED;
                tl->Timer = 30; // Красный 30 сек
                break;
                
            case LIGHT_BLINK_YELLOW:
                // Мигание (ночной режим)
                tl->Timer = tl->BlinkRate;
                break;
        }
    }
    
    // Проверка ночного режима (например, с 23 до 6)
    if (g_trafficManager.CurrentHour >= 23 || g_trafficManager.CurrentHour <= 6) {
        if (tl->Flags & 1) {
            tl->State = LIGHT_BLINK_YELLOW;
        }
    }
}

bool TrafficLight_IsGreen(TrafficLight* tl, Car* car) {
    if (!tl) return true; // Нет светофора - едем
    if (tl->State == LIGHT_GREEN) return true;
    if (tl->State == LIGHT_YELLOW) {
        // Если машина близко - можно проскочить
        // TODO: Проверка дистанции до светофора
        return true; 
    }
    return false;
}

void TrafficLight_SyncGroup(TrafficLight* lights, u16 groupId) {
    // Синхронизация светофоров в группе
    // Чтобы на пересекающихся дорогах был разный цвет
    for (int i = 0; i < MAX_TRAFFIC_LIGHTS; i++) {
        if (!(g_trafficManager.LightActiveMap[i / 8] & (1 << (i % 8)))) continue;
        
        if (lights[i].GroupID == groupId) {
            // Логика синхронизации
            // Например, инвертировать состояние для пересекающих направлений
        }
    }
}

// ============================================================================
// PARKING SPOT FUNCTIONS
// ============================================================================

void ParkingSpot_Init(ParkingSpot* ps, Vector2D pos, f32 angle, ParkingType type) {
    if (!ps) return;
    memset(ps, 0, sizeof(ParkingSpot));
    ps->Position = pos;
    ps->Angle = angle;
    ps->IsOccupied = 0;
    ps->Type = type;
    ps->OccupantCarPtr = NULL;
    ps->ZoneID = 0;
}

ParkingSpot* Parking_FindFreeSpot(Vector2D pos, f32 radius) {
    ParkingSpot* nearest = NULL;
    f32 minDist = radius;
    
    for (int i = 0; i < MAX_PARKING_SPOTS; i++) {
        if (!(g_trafficManager.ParkingActiveMap[i / 8] & (1 << (i % 8)))) continue;
        
        ParkingSpot* ps = &g_trafficManager.ParkingSpots[i];
        if (ps->IsOccupied || ps->Type == PARKING_DISABLED) continue;
        
        f32 dx = ps->Position.X - pos.X;
        f32 dy = ps->Position.Y - pos.Y;
        f32 dist = dx*dx + dy*dy;
        
        if (dist < minDist*minDist) {
            minDist = dist;
            nearest = ps;
        }
    }
    
    return nearest;
}

bool Parking_TryPark(Car* car, ParkingSpot* spot) {
    if (!car || !spot || spot->IsOccupied) return false;
    
    // Проверка типа парковки
    if (spot->Type == PARKING_POLICE) {
        // Только полицейские машины могут парковаться
        // TODO: Проверка типа машины
    }
    
    // Парковка успешна
    spot->IsOccupied = 1;
    spot->OccupantCarPtr = car;
    
    // Машина теперь припаркована
    // TODO: Установить флаг parked в car
    return true;
}

void Parking_Release(Car* car) {
    if (!car) return;
    
    // Освобождение места парковки
    for (int i = 0; i < MAX_PARKING_SPOTS; i++) {
        if (!(g_trafficManager.ParkingActiveMap[i / 8] & (1 << (i % 8)))) continue;
        
        if (g_trafficManager.ParkingSpots[i].OccupantCarPtr == car) {
            g_trafficManager.ParkingSpots[i].IsOccupied = 0;
            g_trafficManager.ParkingSpots[i].OccupantCarPtr = NULL;
            return;
        }
    }
}

// ============================================================================
// SIREN FUNCTIONS
// ============================================================================

void Siren_Init(SirenContext* sc) {
    if (!sc) return;
    memset(sc, 0, sizeof(SirenContext));
    sc->SirenOn = 0;
    sc->LightsFlashing = 0;
    sc->PriorityMode = 0;
    sc->EmergencyTarget = NULL;
    sc->SirenTimer = 0;
}

void Siren_Toggle(SirenContext* sc) {
    if (!sc) return;
    sc->SirenOn = !sc->SirenOn;
    sc->LightsFlashing = sc->SirenOn;
    sc->PriorityMode = sc->SirenOn;
}

bool Siren_HasPriority(SirenContext* sc) {
    return sc && sc->PriorityMode;
}

void Traffic_YieldToSiren(Car* trafficCar, Car* policeCar) {
    if (!trafficCar || !policeCar) return;
    
    // Логика уступки дороги спецтранспорту
    // 1. Проверить дистанцию
    // 2. Если близко - снизить скорость или остановиться
    // 3. Сдвинуться в сторону если возможно
    
    // TODO: Реализация физики уступки
}

// ============================================================================
// ROAD FUNCTIONS
// ============================================================================

f32 Road_GetSpeedLimit(RoadSegment* rs) {
    if (!rs) return 50.0f; // Дефолтное ограничение
    return rs->SpeedLimit;
}

bool Road_IsOneWay(RoadSegment* rs) {
    return rs && (rs->Direction == 1);
}

// ============================================================================
// MANAGER FUNCTIONS
// ============================================================================

void TrafficManager_Init(void) {
    memset(&g_trafficManager, 0, sizeof(TrafficManager));
    
    // Инициализация битовых карт
    for (int i = 0; i < MAX_TRAFFIC_LIGHTS / 8; i++) {
        g_trafficManager.LightActiveMap[i] = 0;
    }
    for (int i = 0; i < MAX_PARKING_SPOTS / 8; i++) {
        g_trafficManager.ParkingActiveMap[i] = 0;
    }
    
    g_trafficManager.GlobalDensity = TRAFFIC_NORMAL;
    g_trafficManager.CurrentHour = 12;
    g_trafficManager.GlobalSpeedMultiplier = 1.0f;
    g_trafficManager.TotalRoads = 0;
}

void TrafficManager_UpdateAll(f32 dt, u8 currentHour) {
    g_trafficManager.CurrentHour = currentHour;
    
    // Обновление светофоров
    for (int i = 0; i < MAX_TRAFFIC_LIGHTS; i++) {
        if (g_trafficManager.LightActiveMap[i / 8] & (1 << (i % 8))) {
            TrafficLight_Update(&g_trafficManager.Lights[i], dt);
        }
    }
    
    // Адаптация плотности трафика от времени суток
    if (currentHour >= 7 && currentHour <= 9) {
        g_trafficManager.GlobalDensity = TRAFFIC_HEAVY; // Утренний час пик
        g_trafficManager.GlobalSpeedMultiplier = 0.7f;
    } else if (currentHour >= 17 && currentHour <= 19) {
        g_trafficManager.GlobalDensity = TRAFFIC_HEAVY; // Вечерний час пик
        g_trafficManager.GlobalSpeedMultiplier = 0.7f;
    } else {
        g_trafficManager.GlobalDensity = TRAFFIC_NORMAL;
        g_trafficManager.GlobalSpeedMultiplier = 1.0f;
    }
}

TrafficLight* TrafficManager_GetLightAtNode(u16 nodeId) {
    for (int i = 0; i < MAX_TRAFFIC_LIGHTS; i++) {
        if (!(g_trafficManager.LightActiveMap[i / 8] & (1 << (i % 8)))) continue;
        
        if (g_trafficManager.Lights[i].LinkedNodeID == nodeId) {
            return &g_trafficManager.Lights[i];
        }
    }
    return NULL;
}

ParkingSpot* TrafficManager_FindNearestParking(Vector2D pos, f32 radius) {
    return Parking_FindFreeSpot(pos, radius);
}
