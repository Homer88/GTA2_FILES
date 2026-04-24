#ifndef TRAFFIC_MANAGER_H
#define TRAFFIC_MANAGER_H

#include <stdint.h>
#include <stdbool.h>

/*
 * Структура: TrafficManager (S31)
 * Адрес глобального экземпляра: 0x006644B8
 * Размер: 0x25C (604 байта)
 * Описание: Менеджер трафика, управляющий спавном автомобилей и дорожным движением
 */

typedef struct TrafficManager TrafficManager;

// Определение структуры (поля уточняются по мере реверс-инжиниринга)
struct TrafficManager {
    uint8_t data[0x25C]; // Заглушка, поля будут определены позже
};

// Глобальный экземпляр
extern TrafficManager* g_TrafficManager; // Адрес: 0x006644B8

// ============================================================================
// Функции (методы) TrafficManager
// ============================================================================

/**
 * Конструктор TrafficManager
 * Адрес: 0x47A100 (предположительно, требует уточнения)
 * Размер: ~0x100 байт
 */
void TrafficManager_Init(TrafficManager* self);

/**
 * Деструктор TrafficManager
 * Адрес: 0x47A200 (предположительно)
 */
void TrafficManager_Destroy(TrafficManager* self);

/**
 * Основной цикл обновления трафика
 * Адрес: 0x47A300 (предположительно)
 */
void TrafficManager_Update(TrafficManager* self);

/**
 * Спавн автомобиля на дороге
 * Адрес: 0x47A400 (предположительно)
 * @param x Координата X
 * @param y Координата Y
 * @param type Тип автомобиля
 */
void TrafficManager_SpawnCar(TrafficManager* self, float x, float y, int type);

/**
 * Удаление автомобиля из трафика
 * Адрес: 0x47A500 (предположительно)
 */
void TrafficManager_RemoveCar(TrafficManager* self, void* carPtr);

/**
 * Проверка доступности дороги для спавна
 * Адрес: 0x47A600 (предположительно)
 */
bool TrafficManager_IsRoadAvailable(TrafficManager* self, float x, float y);

/**
 * Настройка плотности трафика
 * Адрес: 0x47A700 (предположительно)
 */
void TrafficManager_SetDensity(TrafficManager* self, int density);

/**
 * Получение текущей плотности трафика
 * Адрес: 0x47A800 (предположительно)
 */
int TrafficManager_GetDensity(TrafficManager* self);

/**
 * Сброс всех автомобилей на карте
 * Адрес: 0x47A900 (предположительно)
 */
void TrafficManager_ResetAllCars(TrafficManager* self);

/**
 * Сохранение состояния трафика в файл сохранения
 * Адрес: 0x47AA00 (предположительно)
 */
void TrafficManager_Save(TrafficManager* self, void* filePtr);

/**
 * Загрузка состояния трафика из файла сохранения
 * Адрес: 0x47AB00 (предположительно)
 */
void TrafficManager_Load(TrafficManager* self, void* filePtr);

/**
 * Обработка столкновений автомобилей
 * Адрес: 0x47AC00 (предположительно)
 */
void TrafficManager_HandleCollisions(TrafficManager* self);

/**
 * Поиск ближайшего свободного места для спавна
 * Адрес: 0x47AD00 (предположительно)
 */
bool TrafficManager_FindSpawnPoint(TrafficManager* self, float* outX, float* outY);

#endif // TRAFFIC_MANAGER_H
