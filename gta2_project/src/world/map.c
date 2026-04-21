/**
 * @file map.c
 * @brief Реализация функций карты и мира GTA 2
 * 
 * old_file: gta2.exe.c (World/Map section)
 * 
 * Функции управления картой, зонами, объектами и спавном сущностей.
 * Все адреса соответствуют оригинальному gta2.exe.
 */

#include "entities/map.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>

/* ============================================================================
 * ГЛОБАЛЬНЫЕ ДАННЫЕ (симуляция)
 * ============================================================================ */

// Статическая таблица зон (пример)
static Zone g_ZoneTable[MAX_ZONES];
static SpawnPoint g_SpawnPoints[MAX_PED_SPAWNS + MAX_CAR_SPAWNS];

/* ============================================================================
 * ИНИЦИАЛИЗАЦИЯ МИРА
 * ============================================================================ */

/**
 * @brief Инициализация структуры мира
 * old_name: sub_WorldInit_004A1000
 * @param pWorld Указатель на структуру World
 */
void World_Init(World* pWorld) {
    // old_var: pWorld = ecx
    // old_var: zero_memory = eax
    
    if (!pWorld) return;
    
    // Обнуление структуры
    memset(pWorld, 0, sizeof(World));
    
    // old_var: pWorld->pTileArray = malloc(MAP_WIDTH * MAP_HEIGHT * sizeof(Tile))
    pWorld->pTileArray = NULL; // Будет выделено при загрузке карты
    pWorld->pZoneArray = g_ZoneTable;
    pWorld->pObjectArray = NULL;
    pWorld->pSpawnPoints = g_SpawnPoints;
    
    // old_var: pWorld->tileCount = 0
    pWorld->tileCount = 0;
    pWorld->zoneCount = 0;
    pWorld->objectCount = 0;
    pWorld->spawnPointCount = 0;
    
    // old_var: pWorld->currentTime = 0
    pWorld->currentTime = 0;
    pWorld->weather = 0;      // Ясно
    pWorld->timeOfDay = 12;   // Полдень
    pWorld->flags = 0;
    
    // old_var: pWorld->cameraX = 0.0f
    pWorld->cameraX = 0.0f;
    pWorld->cameraY = 0.0f;
    pWorld->cameraZ = 100.0f;
    pWorld->cameraAngle = 0.0f;
    
    // old_var: pWorld->activeCarCount = 0
    pWorld->activeCarCount = 0;
    pWorld->activePedCount = 0;
}

/**
 * @brief Загрузка карты по имени
 * old_name: sub_LoadMap_004A1200
 * @param pWorld Указатель на структуру World
 * @param mapName Имя файла карты
 */
void World_LoadMap(World* pWorld, const char* mapName) {
    // old_var: pWorld = ecx
    // old_var: mapName = stack[0x4]
    // old_var: file_handle = eax
    // old_var: tile_data_ptr = ebx
    
    if (!pWorld || !mapName) return;
    
    // Выделение памяти под тайлы
    size_t tileSize = sizeof(Tile);
    size_t totalTiles = MAP_WIDTH * MAP_HEIGHT;
    
    // old_var: pWorld->pTileArray = malloc(totalTiles * tileSize)
    pWorld->pTileArray = malloc(totalTiles * tileSize);
    
    if (pWorld->pTileArray) {
        // old_var: memset(pWorld->pTileArray, 0, totalTiles * tileSize)
        memset(pWorld->pTileArray, 0, totalTiles * tileSize);
        
        // old_var: pWorld->tileCount = totalTiles
        pWorld->tileCount = totalTiles;
        
        // Здесь должна быть логика чтения файла карты
        // sub_ReadMapFile(mapName, pWorld->pTileArray)
    }
    
    // Инициализация зон для этой карты
    // sub_InitZonesForMap(pWorld)
}

/**
 * @brief Выгрузка карты из памяти
 * old_name: sub_UnloadMap_004A1500
 * @param pWorld Указатель на структуру World
 */
void World_UnloadMap(World* pWorld) {
    // old_var: pWorld = ecx
    // old_var: tile_array = eax
    
    if (!pWorld) return;
    
    // old_var: if (pWorld->pTileArray) free(pWorld->pTileArray)
    if (pWorld->pTileArray) {
        free(pWorld->pTileArray);
        pWorld->pTileArray = NULL;
    }
    
    // old_var: pWorld->tileCount = 0
    pWorld->tileCount = 0;
    pWorld->objectCount = 0;
    
    // Очистка всех объектов
    // sub_DestroyAllObjects(pWorld)
}

/* ============================================================================
 * РАБОТА С ТАЙЛАМИ
 * ============================================================================ */

/**
 * @brief Получить тайл по координатам
 * old_name: sub_GetTile_004A1800
 * @param pWorld Указатель на структуру World
 * @param x Координата X в тайлах
 * @param y Координата Y в тайлах
 * @return Указатель на Tile или NULL
 */
Tile* World_GetTileAt(World* pWorld, int x, int y) {
    // old_var: pWorld = ecx
    // old_var: x = stack[0x4]
    // old_var: y = stack[0x8]
    // old_var: tile_array = eax
    // old_var: index = edx
    
    if (!pWorld || !pWorld->pTileArray) return NULL;
    
    // Проверка границ
    if (x < 0 || x >= MAP_WIDTH || y < 0 || y >= MAP_HEIGHT) {
        return NULL;
    }
    
    // old_var: index = y * MAP_WIDTH + x
    int index = y * MAP_WIDTH + x;
    
    // old_var: return &((Tile*)pWorld->pTileArray)[index]
    Tile* tiles = (Tile*)pWorld->pTileArray;
    return &tiles[index];
}

/**
 * @brief Проверка проходимости тайла
 * old_name: sub_IsWalkable_004A1900
 * @param pWorld Указатель на структуру World
 * @param x Координата X в тайлах
 * @param y Координата Y в тайлах
 * @return true если можно пройти
 */
bool World_IsTileWalkable(World* pWorld, int x, int y) {
    // old_var: pWorld = ecx
    // old_var: x = stack[0x4]
    // old_var: y = stack[0x8]
    // old_var: tile = eax
    // old_var: flags = dl
    
    Tile* pTile = World_GetTileAt(pWorld, x, y);
    
    if (!pTile) return false;
    
    // old_var: if (tile->flags & TILE_FLAG_COLLISION) return false
    if (pTile->flags & TILE_FLAG_COLLISION) {
        return false;
    }
    
    // old_var: if (tile->type == TILE_WATER) return false
    if (pTile->type == TILE_WATER) {
        return false;
    }
    
    // old_var: if (tile->type == TILE_BUILDING) return false
    if (pTile->type == TILE_BUILDING) {
        return false;
    }
    
    return true;
}

/**
 * @brief Установить флаг тайла
 * old_name: sub_SetTileFlag_004A1A00
 * @param pWorld Указатель на структуру World
 * @param x Координата X в тайлах
 * @param y Координата Y в тайлах
 * @param flag Флаг для установки
 */
void World_SetTileFlag(World* pWorld, int x, int y, uint8_t flag) {
    // old_var: pWorld = ecx
    // old_var: x = stack[0x4]
    // old_var: y = stack[0x8]
    // old_var: flag = stack[0xC]
    // old_var: tile = eax
    
    Tile* pTile = World_GetTileAt(pWorld, x, y);
    
    if (pTile) {
        // old_var: tile->flags |= flag
        pTile->flags |= flag;
    }
}

/* ============================================================================
 * РАБОТА С ОБЪЕКТАМИ
 * ============================================================================ */

/**
 * @brief Создание объекта на карте
 * old_name: sub_CreateObj_004A2000
 * @param pWorld Указатель на структуру World
 * @param typeId Тип объекта
 * @param x Позиция X
 * @param y Позиция Y
 * @param z Позиция Z
 * @return Указатель на созданный MapObject
 */
MapObject* World_CreateObject(World* pWorld, uint16_t typeId, 
                              float x, float y, float z) {
    // old_var: pWorld = ecx
    // old_var: typeId = stack[0x4]
    // old_var: x = stack[0x8]
    // old_var: y = stack[0xC]
    // old_var: z = stack[0x10]
    // old_var: new_object = eax
    
    if (!pWorld) return NULL;
    
    // Выделение памяти под объект
    MapObject* pObj = (MapObject*)malloc(sizeof(MapObject));
    
    if (pObj) {
        // old_var: pObj->id = pWorld->objectCount
        pObj->id = pWorld->objectCount;
        
        // old_var: pObj->typeId = typeId
        pObj->typeId = typeId;
        
        // old_var: pObj->posX = x
        pObj->posX = x;
        pObj->posY = y;
        pObj->posZ = z;
        
        // old_var: pObj->rotation = 0.0f
        pObj->rotation = 0.0f;
        
        // old_var: pObj->state = OBJ_STATE_ACTIVE
        pObj->state = OBJ_STATE_ACTIVE;
        
        // old_var: pObj->health = 100
        pObj->health = 100;
        
        // old_var: pObj->flags = 0
        pObj->flags = 0;
        
        // old_var: pObj->pInteractionScript = NULL
        pObj->pInteractionScript = NULL;
        
        // old_var: pObj->timer = 0
        pObj->timer = 0;
        
        // old_var: pObj->pNextInSector = NULL
        pObj->pNextInSector = NULL;
        
        // old_var: pWorld->objectCount++
        pWorld->objectCount++;
    }
    
    return pObj;
}

/**
 * @brief Удаление объекта
 * old_name: sub_DestroyObj_004A2300
 * @param pWorld Указатель на структуру World
 * @param pObj Указатель на объект
 */
void World_DestroyObject(World* pWorld, MapObject* pObj) {
    // old_var: pWorld = ecx
    // old_var: pObj = stack[0x4]
    
    if (!pObj) return;
    
    // old_var: pObj->state = OBJ_STATE_DESTROYED
    pObj->state = OBJ_STATE_DESTROYED;
    
    // old_var: free(pObj)
    free(pObj);
    
    // old_var: pWorld->objectCount--
    if (pWorld && pWorld->objectCount > 0) {
        pWorld->objectCount--;
    }
}

/**
 * @brief Обновление всех объектов
 * old_name: sub_UpdateObjects_004A2500
 * @param pWorld Указатель на структуру World
 */
void World_UpdateObjects(World* pWorld) {
    // old_var: pWorld = ecx
    // old_var: object_array = eax
    // old_var: i = ebx (counter)
    
    if (!pWorld || !pWorld->pObjectArray) return;
    
    // Проход по всем объектам и обновление их состояния
    // sub_UpdateEachObject(pWorld)
    
    // old_var: for (i = 0; i < pWorld->objectCount; i++)
    //     sub_ObjectUpdateLogic(object_array[i])
}

/* ============================================================================
 * РАБОТА С ЗОНАМИ
 * ============================================================================ */

/**
 * @brief Получить зону по координатам
 * old_name: sub_GetZone_004A3000
 * @param pWorld Указатель на структуру World
 * @param x Координата X в мире
 * @param y Координата Y в мире
 * @return Указатель на Zone или NULL
 */
Zone* World_GetZoneAt(World* pWorld, float x, float y) {
    // old_var: pWorld = ecx
    // old_var: x = stack[0x4]
    // old_var: y = stack[0x8]
    // old_var: zone_array = eax
    // old_var: i = ebx (counter)
    
    if (!pWorld || !pWorld->pZoneArray) return NULL;
    
    Zone* zones = (Zone*)pWorld->pZoneArray;
    
    // old_var: for (i = 0; i < pWorld->zoneCount; i++)
    for (uint32_t i = 0; i < pWorld->zoneCount; i++) {
        Zone* pZone = &zones[i];
        
        // old_var: if (x >= zone->minX && x <= zone->maxX)
        if (x >= pZone->minX && x <= pZone->maxX) {
            // old_var: if (y >= zone->minY && y <= zone->maxY)
            if (y >= pZone->minY && y <= pZone->maxY) {
                // old_var: return zone
                return pZone;
            }
        }
    }
    
    return NULL;
}

/**
 * @brief Обновление контроля зон (банды, полиция)
 * old_name: sub_UpdateZones_004A3200
 * @param pWorld Указатель на структуру World
 */
void World_UpdateZoneControl(World* pWorld) {
    // old_var: pWorld = ecx
    // old_var: zone_array = eax
    
    if (!pWorld || !pWorld->pZoneArray) return;
    
    // Логика смены контроля над зонами
    // sub_CalculateZoneControl(pWorld)
}

/* ============================================================================
 * СПАВН СУЩНОСТЕЙ
 * ============================================================================ */

/**
 * @brief Спавн пешеходов
 * old_name: sub_SpawnPeds_004A4000
 * @param pWorld Указатель на структуру World
 */
void World_SpawnPeds(World* pWorld) {
    // old_var: pWorld = ecx
    // old_var: spawn_points = eax
    // old_var: current_time = ebx
    
    if (!pWorld) return;
    
    // old_var: current_time = pWorld->currentTime
    uint32_t currentTime = pWorld->currentTime;
    
    // Проход по точкам спавна пешеходов
    // sub_SpawnPedAtPoint(pWorld, spawnPoint)
}

/**
 * @brief Спавн автомобилей
 * old_name: sub_SpawnCars_004A4200
 * @param pWorld Указатель на структуру World
 */
void World_SpawnCars(World* pWorld) {
    // old_var: pWorld = ecx
    // old_var: spawn_points = eax
    
    if (!pWorld) return;
    
    // Проход по точкам спавна машин
    // sub_SpawnCarAtPoint(pWorld, spawnPoint)
}

/**
 * @brief Обработка всех точек спавна
 * old_name: sub_ProcessSpawns_004A4500
 * @param pWorld Указатель на структуру World
 */
void World_ProcessSpawnPoints(World* pWorld) {
    // old_var: pWorld = ecx
    // old_var: spawn_points = eax
    // old_var: i = ebx (counter)
    
    if (!pWorld || !pWorld->pSpawnPoints) return;
    
    SpawnPoint* points = (SpawnPoint*)pWorld->pSpawnPoints;
    uint32_t currentTime = pWorld->currentTime;
    
    // old_var: for (i = 0; i < pWorld->spawnPointCount; i++)
    for (uint32_t i = 0; i < pWorld->spawnPointCount; i++) {
        SpawnPoint* pPoint = &points[i];
        
        // old_var: if (currentTime - pPoint->lastSpawnTime >= pPoint->spawnDelay)
        if (currentTime - pPoint->lastSpawnTime >= pPoint->spawnDelay) {
            // old_var: sub_SpawnEntity(pWorld, pPoint)
            // old_var: pPoint->lastSpawnTime = currentTime
            pPoint->lastSpawnTime = currentTime;
        }
    }
}

/* ============================================================================
 * НАВИГАЦИЯ
 * ============================================================================ */

/**
 * @brief Поиск пути между двумя точками
 * old_name: sub_FindPath_004A5000
 * @param pWorld Указатель на структуру World
 * @param startX Начальная X
 * @param startY Начальная Y
 * @param endX Конечная X
 * @param endY Конечная Y
 * @return Указатель на структуру пути или NULL
 */
void* World_FindPath(World* pWorld, float startX, float startY,
                     float endX, float endY) {
    // old_var: pWorld = ecx
    // old_var: startX = stack[0x4]
    // old_var: startY = stack[0x8]
    // old_var: endX = stack[0xC]
    // old_var: endY = stack[0x10]
    // old_var: path_grid = eax
    
    if (!pWorld || !pWorld->pPathGrid) return NULL;
    
    // A* поиск пути по сетке
    // sub_AStarSearch(pWorld, startX, startY, endX, endY)
    
    return NULL; // Заглушка
}

/**
 * @brief Проверка принадлежности точки зоне
 * old_name: sub_InZone_004A5500
 * @param pWorld Указатель на структуру World
 * @param x Координата X
 * @param y Координата Y
 * @param zoneId ID зоны
 * @return true если точка в зоне
 */
bool World_IsPointInZone(World* pWorld, float x, float y, uint8_t zoneId) {
    // old_var: pWorld = ecx
    // old_var: x = stack[0x4]
    // old_var: y = stack[0x8]
    // old_var: zoneId = stack[0xC]
    // old_var: zone = eax
    
    Zone* pZone = World_GetZoneAt(pWorld, x, y);
    
    // old_var: return (pZone != NULL && pZone->id == zoneId)
    return (pZone != NULL && pZone->id == zoneId);
}

/* ============================================================================
 * КАМЕРА И РЕНДЕРИНГ
 * ============================================================================ */

/**
 * @brief Установка позиции камеры
 * old_name: sub_SetCamera_004A6000
 * @param pWorld Указатель на структуру World
 * @param x Позиция X
 * @param y Позиция Y
 * @param z Позиция Z
 * @param angle Угол поворота
 */
void World_SetCamera(World* pWorld, float x, float y, float z, float angle) {
    // old_var: pWorld = ecx
    // old_var: x = stack[0x4]
    // old_var: y = stack[0x8]
    // old_var: z = stack[0xC]
    // old_var: angle = stack[0x10]
    
    if (!pWorld) return;
    
    // old_var: pWorld->cameraX = x
    pWorld->cameraX = x;
    pWorld->cameraY = y;
    pWorld->cameraZ = z;
    pWorld->cameraAngle = angle;
}

/**
 * @brief Обновление видимых объектов
 * old_name: sub_UpdateVis_004A6200
 * @param pWorld Указатель на структуру World
 */
void World_UpdateVisibility(World* pWorld) {
    // old_var: pWorld = ecx
    // old_var: camera_x = pWorld->cameraX
    // old_var: camera_y = pWorld->cameraY
    
    if (!pWorld) return;
    
    // Определение видимых тайлов и объектов с учетом позиции камеры
    // sub_CalculateVisibleTiles(pWorld)
    // sub_CullObjects(pWorld)
}

/* ============================================================================
 * ВРЕМЯ И ПОГОДА
 * ============================================================================ */

/**
 * @brief Установка времени суток
 * old_name: sub_SetTime_004A7000
 * @param pWorld Указатель на структуру World
 * @param hour Час (0-23)
 */
void World_SetTime(World* pWorld, uint8_t hour) {
    // old_var: pWorld = ecx
    // old_var: hour = stack[0x4]
    
    if (!pWorld) return;
    
    // old_var: if (hour > 23) hour = 0
    if (hour > 23) hour = 0;
    
    // old_var: pWorld->timeOfDay = hour
    pWorld->timeOfDay = hour;
}

/**
 * @brief Установка погоды
 * old_name: sub_SetWeather_004A7100
 * @param pWorld Указатель на структуру World
 * @param weather Тип погоды (0=ясно, 1=дождь, 2=туман)
 */
void World_SetWeather(World* pWorld, uint8_t weather) {
    // old_var: pWorld = ecx
    // old_var: weather = stack[0x4]
    
    if (!pWorld) return;
    
    // old_var: if (weather > 2) weather = 0
    if (weather > 2) weather = 0;
    
    // old_var: pWorld->weather = weather
    pWorld->weather = weather;
}

/**
 * @brief Обновление игрового времени
 * old_name: sub_UpdateTime_004A7200
 * @param pWorld Указатель на структуру World
 */
void World_UpdateTime(World* pWorld) {
    // old_var: pWorld = ecx
    // old_var: delta_time = eax
    // old_var: time_scale = ebx
    
    if (!pWorld) return;
    
    // old_var: delta_time = GetDeltaTime()
    // old_var: time_scale = 1.0f (normal speed)
    
    // old_var: pWorld->currentTime += delta_time * time_scale
    pWorld->currentTime += 16; // Примерно 60 FPS
    
    // old_var: if (pWorld->currentTime >= 24 * 60 * 60 * 1000)
    if (pWorld->currentTime >= 86400000) { // 24 часа в мс
        // old_var: pWorld->currentTime = 0
        pWorld->currentTime = 0;
        // old_var: pWorld->timeOfDay = 0
        pWorld->timeOfDay = 0;
    } else {
        // old_var: pWorld->timeOfDay = pWorld->currentTime / (60 * 60 * 1000)
        pWorld->timeOfDay = (pWorld->currentTime / 3600000) % 24;
    }
}
