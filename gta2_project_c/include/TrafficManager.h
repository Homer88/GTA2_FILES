#ifndef TRAFFIC_MANAGER_H
#define TRAFFIC_MANAGER_H

#include <stdint.h>
#include <stdbool.h>

// Структура S31: TrafficManager
// Адрес глобального экземпляра: 0x006644B8
// Размер: 0x25C (604 байта)
// Назначение: Управление трафиком, спавном автомобилей и дорожным движением
typedef struct {
    // Поля требуют детального анализа по ассемблеру
    // Предположительно: массивы машин, флаги дорог, настройки плотности
    uint8_t data[0x25C]; 
} TrafficManager;

// Глобальный экземпляр
extern TrafficManager* g_TrafficManager; // Адрес: 0x006644B8

// --- Методы ---

// Конструктор / Инициализация
void TrafficManager_Init(TrafficManager* self);

// Деструктор / Очистка
void TrafficManager_Destroy(TrafficManager* self);

// Основной цикл обновления трафика
void TrafficManager_Update(TrafficManager* self);

// Спавн автомобиля определенного типа
// Возвращает ID созданного авто или -1 при ошибке
int TrafficManager_SpawnCar(TrafficManager* self, int carType, float x, float y, float z);

// Удаление автомобиля по ID
void TrafficManager_RemoveCar(TrafficManager* self, int carId);

// Проверка доступности дороги в точке
bool TrafficManager_IsRoadAvailable(TrafficManager* self, float x, float y);

// Установка плотности трафика (0.0 - 1.0)
void TrafficManager_SetDensity(TrafficManager* self, float density);

// Получение текущей плотности
float TrafficManager_GetDensity(TrafficManager* self);

// Сброс всех автомобилей на карте
void TrafficManager_ResetAllCars(TrafficManager* self);

// Сохранение состояния трафика
void TrafficManager_Save(TrafficManager* self, void* saveData);

// Загрузка состояния трафика
void TrafficManager_Load(TrafficManager* self, void* saveData);

// Обработка столкновений
void TrafficManager_HandleCollisions(TrafficManager* self);

// Поиск точки спавна
bool TrafficManager_FindSpawnPoint(TrafficManager* self, float* outX, float* outY);

#endif // TRAFFIC_MANAGER_H
