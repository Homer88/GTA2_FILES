/**
 * @file cars_prefabs.h
 * @brief Менеджер префабов (шаблонов) автомобилей GTA 2.
 * 
 * Адрес глобальной переменной: gCarsPrefabs (требует уточнения по map)
 * Размер структуры: 0xE0C4 (57540 байт)
 * Конструктор: 0x004254F0 (CarsPrefabs::CarsPrefabs)
 * Деструктор: 0x00426AA0 (CarsPrefabs::CarsPrefabs_des)
 * 
 * Эта структура хранит шаблоны машин для спавна, включая их параметры,
 * модели, цвета и другие предустановленные значения.
 */

#ifndef GTA2_CARS_PREFABS_H
#define GTA2_CARS_PREFABS_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Глобальный экземпляр менеджера префабов.
 */
extern CarsPrefabs* gCarsPrefabs;

/**
 * @brief Структура менеджера префабов машин.
 * Размер: 0xE0C4 (57540 байт)
 */
typedef struct CarsPrefabs {
    /* 0x0000 */ uint8_t data[0xE0C4];   // Внутренние данные префабов
                                        // Требуется дополнительный анализ для разбивки на поля
} CarsPrefabs;

// Проверка размера структуры
#ifdef __cplusplus
static_assert(sizeof(CarsPrefabs) == 0xE0C4, "CarsPrefabs size must be 0xE0C4");
#endif

/**
 * @brief Конструктор CarsPrefabs.
 * @param this Указатель на экземпляр структуры.
 * @return Указатель на инициализированный экземпляр.
 * 
 * Адрес функции: 0x004254F0
 */
CarsPrefabs* CarsPrefabs__ctor(CarsPrefabs* this);

/**
 * @brief Деструктор CarsPrefabs.
 * @param this Указатель на экземпляр структуры.
 * 
 * Адрес функции: 0x00426AA0
 */
void CarsPrefabs__dtor(CarsPrefabs* this);

/**
 * @brief Получение машины из префаба.
 * @param this Указатель на экземпляр.
 * @param index Индекс машины.
 * @return Указатель на данные машины или NULL.
 * 
 * Адрес функции: 0x00420F04 (CarsPrefabs::GetCar)
 */
void* CarsPrefabs__GetCar(CarsPrefabs* this, int index);

/**
 * @brief Вставка машины в начало списка.
 * @param this Указатель на экземпляр.
 * @param carData Данные машины.
 * 
 * Адрес функции: 0x00401C7B (CarsPrefabs::InsertCarAtFront)
 */
void CarsPrefabs__InsertCarAtFront(CarsPrefabs* this, void* carData);

/**
 * @brief Получение количества машин.
 * @param this Указатель на экземпляр.
 * @return Количество машин.
 * 
 * Адрес функции: 0x00427D88 (CarsPrefabs::GetCarsCount)
 */
int CarsPrefabs__GetCarsCount(CarsPrefabs* this);

#ifdef __cplusplus
}
#endif

#endif // GTA2_CARS_PREFABS_H
