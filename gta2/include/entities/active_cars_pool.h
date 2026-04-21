/**
 * @file active_cars_pool.h
 * @brief Пул активных автомобилей GTA 2.
 * 
 * Адрес глобальной переменной: 0x0066AB7C (ранее ошибочно gVector3D)
 * Размер структуры: 0xD264 (53860 байт)
 * Конструктор: 0x00420F80 (S2::S2)
 * 
 * Эта структура управляет массивом активных машин в игре.
 * Содержит данные о позициях, состояниях и параметрах всех спавненных машин.
 */

#ifndef GTA2_ACTIVE_CARS_POOL_H
#define GTA2_ACTIVE_CARS_POOL_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Глобальный экземпляр пула активных машин.
 */
extern ActiveCarsPool* gActiveCarsPool;

/**
 * @brief Структура пула активных машин.
 * Размер: 0xD264 (53860 байт)
 * 
 * Старое имя: S2, gVector3D (ошибочное)
 * Новое имя: ActiveCarsPool
 */
typedef struct ActiveCarsPool {
    /* 0x0000 */ uint8_t data[0xD264];   // Внутренние данные пула
                                        // Требуется дополнительный анализ для разбивки на поля
} ActiveCarsPool;

// Проверка размера структуры
#ifdef __cplusplus
static_assert(sizeof(ActiveCarsPool) == 0xD264, "ActiveCarsPool size must be 0xD264");
#endif

/**
 * @brief Конструктор ActiveCarsPool.
 * @param this Указатель на экземпляр структуры.
 * @return Указатель на инициализированный экземпляр.
 * 
 * Адрес функции: 0x00420F80 (старое имя: S2::S2)
 */
ActiveCarsPool* ActiveCarsPool__ctor(ActiveCarsPool* this);

/**
 * @brief Деструктор ActiveCarsPool.
 * @param this Указатель на экземпляр структуры.
 * 
 * Адрес функции: Требуется найти (старое имя: S2::S2_Des)
 */
void ActiveCarsPool__dtor(ActiveCarsPool* this);

#ifdef __cplusplus
}
#endif

#endif // GTA2_ACTIVE_CARS_POOL_H
