/**
 * @file map.cpp
 * @brief C++ обертки для функций карты и мира GTA 2
 * 
 * old_file: gta2.exe.cpp (World/Map section)
 * 
 * Обертки используют структуры вместо классов, находятся в пространстве имен GTA2::World.
 * Все функции вызывают соответствующие C-функции из map.c.
 */

#include "entities/map.h"

#ifdef __cplusplus
extern "C" {
#endif

// Подключение C функций
#include <stdbool.h>

#ifdef __cplusplus
}
#endif

namespace GTA2 {
namespace World {

/* ============================================================================
 * WORLD MANAGEMENT
 * ============================================================================ */

/**
 * @brief Инициализация мира
 * old_name: sub_WorldInit_004A1000
 */
void Init(World* pWorld) {
    World_Init(pWorld);
}

/**
 * @brief Загрузка карты
 * old_name: sub_LoadMap_004A1200
 */
void LoadMap(World* pWorld, const char* mapName) {
    World_LoadMap(pWorld, mapName);
}

/**
 * @brief Выгрузка карты
 * old_name: sub_UnloadMap_004A1500
 */
void UnloadMap(World* pWorld) {
    World_UnloadMap(pWorld);
}

/* ============================================================================
 * TILE OPERATIONS
 * ============================================================================ */

/**
 * @brief Получить тайл по координатам
 * old_name: sub_GetTile_004A1800
 */
Tile* GetTileAt(World* pWorld, int x, int y) {
    return World_GetTileAt(pWorld, x, y);
}

/**
 * @brief Проверка проходимости
 * old_name: sub_IsWalkable_004A1900
 */
bool IsTileWalkable(World* pWorld, int x, int y) {
    return World_IsTileWalkable(pWorld, x, y);
}

/**
 * @brief Установить флаг тайла
 * old_name: sub_SetTileFlag_004A1A00
 */
void SetTileFlag(World* pWorld, int x, int y, uint8_t flag) {
    World_SetTileFlag(pWorld, x, y, flag);
}

/* ============================================================================
 * OBJECT OPERATIONS
 * ============================================================================ */

/**
 * @brief Создание объекта
 * old_name: sub_CreateObj_004A2000
 */
MapObject* CreateObject(World* pWorld, uint16_t typeId, float x, float y, float z) {
    return World_CreateObject(pWorld, typeId, x, y, z);
}

/**
 * @brief Удаление объекта
 * old_name: sub_DestroyObj_004A2300
 */
void DestroyObject(World* pWorld, MapObject* pObj) {
    World_DestroyObject(pWorld, pObj);
}

/**
 * @brief Обновление объектов
 * old_name: sub_UpdateObjects_004A2500
 */
void UpdateObjects(World* pWorld) {
    World_UpdateObjects(pWorld);
}

/* ============================================================================
 * ZONE OPERATIONS
 * ============================================================================ */

/**
 * @brief Получить зону по координатам
 * old_name: sub_GetZone_004A3000
 */
Zone* GetZoneAt(World* pWorld, float x, float y) {
    return World_GetZoneAt(pWorld, x, y);
}

/**
 * @brief Обновление контроля зон
 * old_name: sub_UpdateZones_004A3200
 */
void UpdateZoneControl(World* pWorld) {
    World_UpdateZoneControl(pWorld);
}

/* ============================================================================
 * SPAWNING
 * ============================================================================ */

/**
 * @brief Спавн пешеходов
 * old_name: sub_SpawnPeds_004A4000
 */
void SpawnPeds(World* pWorld) {
    World_SpawnPeds(pWorld);
}

/**
 * @brief Спавн автомобилей
 * old_name: sub_SpawnCars_004A4200
 */
void SpawnCars(World* pWorld) {
    World_SpawnCars(pWorld);
}

/**
 * @brief Обработка точек спавна
 * old_name: sub_ProcessSpawns_004A4500
 */
void ProcessSpawnPoints(World* pWorld) {
    World_ProcessSpawnPoints(pWorld);
}

/* ============================================================================
 * NAVIGATION
 * ============================================================================ */

/**
 * @brief Поиск пути
 * old_name: sub_FindPath_004A5000
 */
void* FindPath(World* pWorld, float startX, float startY, float endX, float endY) {
    return World_FindPath(pWorld, startX, startY, endX, endY);
}

/**
 * @brief Проверка точки в зоне
 * old_name: sub_InZone_004A5500
 */
bool IsPointInZone(World* pWorld, float x, float y, uint8_t zoneId) {
    return World_IsPointInZone(pWorld, x, y, zoneId);
}

/* ============================================================================
 * CAMERA & RENDERING
 * ============================================================================ */

/**
 * @brief Установка камеры
 * old_name: sub_SetCamera_004A6000
 */
void SetCamera(World* pWorld, float x, float y, float z, float angle) {
    World_SetCamera(pWorld, x, y, z, angle);
}

/**
 * @brief Обновление видимости
 * old_name: sub_UpdateVis_004A6200
 */
void UpdateVisibility(World* pWorld) {
    World_UpdateVisibility(pWorld);
}

/* ============================================================================
 * TIME & WEATHER
 * ============================================================================ */

/**
 * @brief Установка времени
 * old_name: sub_SetTime_004A7000
 */
void SetTime(World* pWorld, uint8_t hour) {
    World_SetTime(pWorld, hour);
}

/**
 * @brief Установка погоды
 * old_name: sub_SetWeather_004A7100
 */
void SetWeather(World* pWorld, uint8_t weather) {
    World_SetWeather(pWorld, weather);
}

/**
 * @brief Обновление времени
 * old_name: sub_UpdateTime_004A7200
 */
void UpdateTime(World* pWorld) {
    World_UpdateTime(pWorld);
}

} // namespace World
} // namespace GTA2
