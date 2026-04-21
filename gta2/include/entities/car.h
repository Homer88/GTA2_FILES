/**
 * @file car.h
 * @brief Определение структуры автомобиля (CCar) и связанных типов.
 * 
 * Анализ:
 * - Размер: 0xBC (188 байт)
 * - Конструктор: 0x00421A50 (Car::Car)
 * - Деструктор: 0x00421B20 (Car::Car_Des)
 * - Поле связи (pNext/LastCar): Смещение 0x4C (76 байт)
 * 
 * История имен:
 * - S1 (временное)
 * - Car (старое)
 * - CCar (текущее)
 */

#ifndef GTA2_ENTITIES_CAR_H
#define GTA2_ENTITIES_CAR_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

// Прямое объявление структур для избежания циклических зависимостей
struct CCar;
struct CarsPrefabs;

/**
 * @brief Структура автомобиля в пуле.
 * 
 * Эта структура используется как элемент массива в CarsPrefabs.
 * Поле pNext (LastCar) используется для организации свободного списка (Free List).
 */
typedef struct CCar {
    /* 0x00 */ uint8_t  data_head[76];   ///< Данные заголовка (флаги, ID, состояние). Точная раскладка требует дальнейшего анализа.
    /* 0x4C */ struct CCar* pNext;       ///< Указатель на следующий автомобиль в списке (ранее LastCar). Смещение подтверждено циклом инициализации пула.
    /* 0x50 */ uint8_t  data_tail[108];  ///< Остальные данные автомобиля (физика, владелец, таймеры).
} CCar;

// Проверка размера структуры
#ifdef __cplusplus
static_assert(sizeof(CCar) == 0xBC, "CCar size must be 0xBC (188 bytes)");
static_assert(offsetof(CCar, pNext) == 0x4C, "CCar::pNext offset must be 0x4C");
#endif

/**
 * @brief Менеджер пула префабов автомобилей.
 * 
 * Управляет массивом из 306 объектов CCar.
 * Инициализирует свободный список при создании.
 */
typedef struct CarsPrefabs {
    /* 0x0000 */ CCar carPool[306];     ///< Статический массив автомобилей. Размер: 306 * 188 = 57528 байт.
    /* 0xE3E8 */ CCar* pFreeListHead;   ///< Голова списка свободных автомобилей (sCar2 в листинге).
    /* 0xE3EC */ CCar* pActiveListHead; ///< Голова списка активных автомобилей (Car3 в листинге).
    /* 0xE3F0 */ int32_t carsCount;     ///< Количество активных автомобилей (CarsCount).
    /* 0xE3F4 */ uint8_t padding[4];    ///< Выравнивание (если необходимо, общий размер ~57540 байт).
} CarsPrefabs;

// Проверка размера CarsPrefabs (приблизительно, зависит от выравнивания)
// 306 * 188 = 57528. + 12 байт поля = 57540. Совпадает с new(57540u).
#ifdef __cplusplus
static_assert(sizeof(CarsPrefabs) >= 57540, "CarsPrefabs size mismatch");
#endif

// ============================================================================
// C API (car.c)
// ============================================================================

/**
 * @brief Конструктор CCar (заглушка).
 * @param self Указатель на объект.
 * @return Указатель на инициализированный объект.
 */
CCar* CCar_Constructor(CCar* self);

/**
 * @brief Деструктор CCar (заглушка).
 * @param self Указатель на объект.
 */
void CCar_Destructor(CCar* self);

/**
 * @brief Конструктор CarsPrefabs.
 * @param self Указатель на менеджер пула.
 * @return Указатель на инициализированный менеджер.
 */
CarsPrefabs* CarsPrefabs_Constructor(CarsPrefabs* self);

// ============================================================================
// C++ API (car.cpp)
// ============================================================================

#ifdef __cplusplus

class CCarClass {
public:
    // Конструктор / Деструктор (оригинальные адреса: 0x00421A50 / 0x00421B20)
    CCarClass();
    ~CCarClass();

    // Поля (доступ через union или наследование от CCar)
    // uint8_t data_head[76];
    // CCarClass* pNext; // 0x4C
    // uint8_t data_tail[108];
};

class CarsPrefabsClass {
public:
    // Конструктор (оригинальный адрес: 0x004254F0)
    CarsPrefabsClass();
    ~CarsPrefabsClass();

    // Методы
    // CCar* GetFreeCar();
    // void ReturnCar(CCar* car);

private:
    CCar carPool[306];
    CCar* pFreeListHead;
    CCar* pActiveListHead;
    int32_t carsCount;
};

#endif // __cplusplus

#ifdef __cplusplus
}
#endif

#endif // GTA2_ENTITIES_CAR_H
