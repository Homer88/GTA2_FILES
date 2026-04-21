/**
 * @file map.h
 * @brief Структуры данных карты и мира GTA 2
 * 
 * old_file: gta2.exe.h (World/Map section)
 * 
 * Структуры описывают тайловую карту, зоны, объекты мира и навигацию.
 * Все размеры соответствуют 32-битной версии игры (GTA2.exe).
 */

#ifndef GTA2_MAP_H
#define GTA2_MAP_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ============================================================================
 * КОНСТАНТЫ МИРА
 * ============================================================================ */

#define MAP_WIDTH           128         // Ширина карты в тайлах
#define MAP_HEIGHT          128         // Высота карты в тайлах
#define TILE_SIZE           32          // Размер тайла в пикселях (графика)
#define SECTOR_SIZE         16          // Размер сектора в тайлах
#define MAX_ZONES           256         // Максимальное количество зон
#define MAX_MAP_OBJECTS     1024        // Максимум объектов на карте
#define MAX_PED_SPAWNS      512         // Максимум точек спавна пешеходов
#define MAX_CAR_SPAWNS      128         // Максимум точек спавна машин

/* ============================================================================
 * ПЕРЕЧИСЛЕНИЯ
 * ============================================================================ */

/**
 * @brief Типы тайлов для рендеринга и коллизий
 * old_enum: TileType (sub_Enum_XXXXXX)
 */
typedef enum TileType {
    TILE_EMPTY = 0,             // Пустой тайл (дорога, земля)
    TILE_BUILDING = 1,          // Здание (непроходимо)
    TILE_WATER = 2,             // Вода (непроходимо, кроме мостов)
    TILE_BRIDGE = 3,            // Мост/эстакада
    TILE_SIDEWALK = 4,          // Тротуар
    TILE_GRASS = 5,             // Трава
    TILE_CONSTRUCTION = 6,      // Стройка
    TILE_SUBWAY = 7,            // Вход в метро
    TILE_SPECIAL = 8            // Специальный тайл (триггеры)
} TileType;

/**
 * @brief Флаги тайла
 * old_enum: TileFlags (sub_Enum_YYYYYY)
 */
typedef enum TileFlags {
    TILE_FLAG_COLLISION     = 0x01,   // Есть коллизия
    TILE_FLAG_ROOF          = 0x02,   // Это крыша (можно ходить)
    TILE_FLAG_INTERIOR      = 0x04,   // Внутреннее помещение
    TILE_FLAG_DANGER        = 0x08,   // Опасная зона (огонь, электричество)
    TILE_FLAG_TRIGGER       = 0x10,   // Триггер события
    TILE_FLAG_NO_PEDS       = 0x20,   // Пешеходы не спавнятся
    TILE_FLAG_NO_CARS       = 0x40,   // Машины не едут
    TILE_FLAG_UNDERGROUND   = 0x80    // Подземный уровень
} TileFlags;

/**
 * @brief Типы зон
 * old_enum: ZoneType (sub_Enum_ZZZZZZ)
 */
typedef enum ZoneType {
    ZONE_RESIDENTIAL = 0,     // Жилой район
    ZONE_COMMERCIAL = 1,      // Коммерческий район
    ZONE_INDUSTRIAL = 2,      // Промышленный район
    ZONE_DOWNTOWN = 3,        // Центр города
    ZONE_SEAPORT = 4,         // Порт
    ZONE_AIRPORT = 5,         // Аэропорт
    ZONE_MILITARY = 6,        // Военная база
    ZONE_GANG_TERRITORY = 7   // Территория банды
} ZoneType;

/**
 * @brief Состояние объекта карты
 * old_enum: MapObjectState (sub_ObjState_XXX)
 */
typedef enum MapObjectState {
    OBJ_STATE_INACTIVE = 0,   // Неактивен
    OBJ_STATE_ACTIVE = 1,     // Активен
    OBJ_STATE_DESTROYED = 2,  // Разрушен
    OBJ_STATE_ANIMATING = 3   // Анимация (двери, лифты)
} MapObjectState;

/* ============================================================================
 * СТРУКТУРЫ ДАННЫХ
 * ============================================================================ */

/**
 * @brief Базовый тайл карты
 * old_struct: S100 (sub_Struct_100)
 * old_var: TileStruct
 * size: 0x10 байт
 */
typedef struct Tile {
    uint16_t textureId;           // +0x00 ID текстуры для рендеринга
    uint8_t  type;                // +0x02 TileType
    uint8_t  flags;               // +0x03 TileFlags
    uint8_t  elevation;           // +0x04 Уровень высоты (0-255)
    uint8_t  zoneId;              // +0x05 ID зоны
    uint16_t objectId;            // +0x06 ID объекта на тайле (0 если нет)
    uint32_t properties;          // +0x08 Дополнительные свойства
    void*    pNext;               // +0x0C Указатель на следующий тайл (для списков)
} Tile;

/**
 * @brief Объект на карте (бочки, ящики, знаки и т.д.)
 * old_struct: S101 (sub_Struct_101)
 * old_var: MapObjectStruct
 * size: 0x24 байта
 */
typedef struct MapObject {
    uint16_t id;                  // +0x00 Уникальный ID объекта
    uint16_t typeId;              // +0x02 Тип объекта (модель)
    float    posX;                // +0x04 Позиция X
    float    posY;                // +0x08 Позиция Y
    float    posZ;                // +0x0C Позиция Z (высота)
    float    rotation;            // +0x10 Угол поворота
    uint8_t  state;               // +0x14 MapObjectState
    uint8_t  health;              // +0x15 Здоровье объекта
    uint16_t flags;               // +0x16 Флаги объекта
    void*    pInteractionScript;  // +0x18 Скрипт взаимодействия
    uint32_t timer;               // +0x1C Таймер (для анимаций)
    void*    pNextInSector;       // +0x20 Следующий объект в секторе
} MapObject;

/**
 * @brief Зона города
 * old_struct: S102 (sub_Struct_102)
 * old_var: ZoneStruct
 * size: 0x40 байт
 */
typedef struct Zone {
    uint8_t  id;                  // +0x00 ID зоны (0-255)
    uint8_t  type;                // +0x01 ZoneType
    char     name[32];            // +0x02 Название зоны (текст для UI)
    float    minX;                // +0x22 Границы зоны
    float    minY;                // +0x26
    float    maxX;                // +0x2A
    float    maxY;                // +0x2E
    uint8_t  gangId;              // +0x32 ID банды, контролирующей зону
    uint8_t  policeDensity;       // +0x33 Плотность полиции (0-100)
    uint8_t  pedDensity;          // +0x34 Плотность пешеходов (0-100)
    uint8_t  carDensity;          // +0x35 Плотность трафика (0-100)
    uint32_t flags;               // +0x38 Флаги зоны
    void*    pAmbientSound;       // +0x3C Звук окружения
} Zone;

/**
 * @brief Точка спавна сущностей
 * old_struct: S103 (sub_Struct_103)
 * old_var: SpawnPointStruct
 * size: 0x18 байт
 */
typedef struct SpawnPoint {
    float    posX;                // +0x00 Позиция X
    float    posY;                // +0x04 Позиция Y
    float    posZ;                // +0x08 Позиция Z
    uint8_t  type;                // +0x0C Тип спавна (0=ped, 1=car, 2=object)
    uint8_t  entityId;            // +0x0D ID сущности для спавна
    uint16_t flags;               // +0x0E Флаги спавна
    uint32_t spawnDelay;          // +0x10 Задержка между спавнами (мс)
    uint32_t lastSpawnTime;       // +0x14 Время последнего спавна
} SpawnPoint;

/**
 * @brief Менеджер карты (глобальная структура мира)
 * old_struct: S104 (sub_Struct_104)
 * old_var: WorldStruct
 * size: 0x80 байт
 */
typedef struct World {
    void*    pTileArray;          // +0x00 Указатель на массив тайлов [MAP_WIDTH * MAP_HEIGHT]
    void*    pZoneArray;          // +0x04 Указатель на массив зон
    void*    pObjectArray;        // +0x08 Указатель на массив объектов
    void*    pSpawnPoints;        // +0x0C Указатель на точки спавна
    uint32_t tileCount;           // +0x10 Количество тайлов
    uint32_t zoneCount;           // +0x14 Количество зон
    uint32_t objectCount;         // +0x18 Количество объектов
    uint32_t spawnPointCount;     // +0x1C Количество точек спавна
    float    cameraX;             // +0x20 Позиция камеры (мир)
    float    cameraY;             // +0x24
    float    cameraZ;             // +0x28
    float    cameraAngle;         // +0x2C Угол камеры
    uint32_t currentTime;         // +0x30 Игровое время (мс)
    uint8_t  weather;             // +0x34 Погода (0=ясно, 1=дождь, 2=туман)
    uint8_t  timeOfDay;           // +0x35 Время суток (0-23)
    uint16_t flags;               // +0x36 Флаги мира
    void*    pPathGrid;           // +0x38 Сетка путей для ИИ
    void*    pTrafficLights;      // +0x3C Светофоры
    uint32_t activeCarCount;      // +0x40 Активные машины
    uint32_t activePedCount;      // +0x44 Активные пешеходы
    // ... остальные поля до 0x80
    uint8_t  padding[0x40];       // +0x48 Заполнитель
} World;

/* ============================================================================
 * ПРОТОТИПЫ ФУНКЦИЙ
 * ============================================================================ */

// Инициализация мира
void World_Init(World* pWorld);                                          // old_name: sub_WorldInit_XXXXXX
void World_LoadMap(World* pWorld, const char* mapName);                  // old_name: sub_LoadMap_YYYYYY
void World_UnloadMap(World* pWorld);                                     // old_name: sub_UnloadMap_ZZZZZZ

// Работа с тайлами
Tile* World_GetTileAt(World* pWorld, int x, int y);                      // old_name: sub_GetTile_XXXXXX
bool  World_IsTileWalkable(World* pWorld, int x, int y);                 // old_name: sub_IsWalkable_YYYYYY
void  World_SetTileFlag(World* pWorld, int x, int y, uint8_t flag);      // old_name: sub_SetTileFlag_ZZZZZZ

// Работа с объектами
MapObject* World_CreateObject(World* pWorld, uint16_t typeId, 
                              float x, float y, float z);                // old_name: sub_CreateObj_XXXXXX
void  World_DestroyObject(World* pWorld, MapObject* pObj);               // old_name: sub_DestroyObj_YYYYYY
void  World_UpdateObjects(World* pWorld);                                // old_name: sub_UpdateObjects_ZZZZZZ

// Работа с зонами
Zone* World_GetZoneAt(World* pWorld, float x, float y);                  // old_name: sub_GetZone_XXXXXX
void  World_UpdateZoneControl(World* pWorld);                            // old_name: sub_UpdateZones_YYYYYY

// Спавн сущностей
void  World_SpawnPeds(World* pWorld);                                    // old_name: sub_SpawnPeds_XXXXXX
void  World_SpawnCars(World* pWorld);                                    // old_name: sub_SpawnCars_YYYYYY
void  World_ProcessSpawnPoints(World* pWorld);                           // old_name: sub_ProcessSpawns_ZZZZZZ

// Навигация и пути
void* World_FindPath(World* pWorld, float startX, float startY, 
                     float endX, float endY);                            // old_name: sub_FindPath_XXXXXX
bool  World_IsPointInZone(World* pWorld, float x, float y, 
                          uint8_t zoneId);                               // old_name: sub_InZone_YYYYYY

// Камера и рендеринг
void  World_SetCamera(World* pWorld, float x, float y, float z, 
                      float angle);                                      // old_name: sub_SetCamera_ZZZZZZ
void  World_UpdateVisibility(World* pWorld);                             // old_name: sub_UpdateVis_XXXXXX

// Время и погода
void  World_SetTime(World* pWorld, uint8_t hour);                        // old_name: sub_SetTime_YYYYYY
void  World_SetWeather(World* pWorld, uint8_t weather);                  // old_name: sub_SetWeather_ZZZZZZ
void  World_UpdateTime(World* pWorld);                                   // old_name: sub_UpdateTime_XXXXXX

#ifdef __cplusplus
}
#endif

#endif // GTA2_MAP_H
