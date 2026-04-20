// ============================================================================
// FILE: CollisionBox.h
// DESCRIPTION: Система коллизий и обработки столкновений
// ORIGINAL: S61, EventHandler
// SIZE: ~61220 байт (массив из 3825 элементов)
// ============================================================================

#ifndef COLLISIONBOX_H
#define COLLISIONBOX_H

#include "types.h"
#include "enums.h"
#include "forward_declarations.h"

/**
 * @struct CollisionBox
 * @brief Менеджер коллизий уровня
 * @original S61
 * 
 * Глобальная система, управляющая всеми объектами с коллизиями на уровне.
 * Содержит массив EventHandler для каждого объекта.
 */
typedef struct CollisionBox {
    EventHandler* Begin;        // 0x0 - Указатель на первый EventHandler
    EventHandler* Index;        // 0x4 - Текущий индекс/указатель
    EventHandler Events[3825];  // 0x8 - Массив обработчиков событий (объекты уровня)
    short ActiveCount;          // Активное количество объектов
    byte Flags;                 // Флаги системы коллизий
    byte Padding;               // Выравнивание
} CollisionBox;

/**
 * @enum GameObjectType
 * @brief Типы игровых объектов для коллизий
 * 
 * Значения из IDA Pro (GameObject*)
 */
typedef enum GameObjectType {
    GAME_OBJECT_PLAYER_1    = 0x08,   // Игрок 1
    GAME_OBJECT_PLAYER_2    = 0x09,   // Игрок 2
    GAME_OBJECT_CAR         = 0x82,   // Автомобиль
    GAME_OBJECT_PED         = 0x8D,   // Пешеход
    GAME_OBJECT_PUBLIC_TRANS= 0x81,   // Общественный транспорт
    GAME_OBJECT_DOOR        = 0xA7,   // Дверь/ворота
    GAME_OBJECT_FIRE        = 0x8F,   // Огонь
    GAME_OBJECT_SPRITE      = 0xA1,   // Спрайт/декорация
    GAME_OBJECT_BUILDING    = 0x89,   // Здание/статичный объект
    GAME_OBJECT_PLAYER_PED  = 0x8B,   // Пешеход-игрок
    GAME_OBJECT_UNKNOWN     = 0x10A   // Неизвестный тип (специальный)
} GameObjectType;

// ============================================================================
// Прототипы функций CollisionBox
// ============================================================================

/**
 * @brief Инициализация системы коллизий
 * @param this Указатель на CollisionBox
 */
void CollisionBox_Init(CollisionBox* this);

/**
 * @brief Проверка активности объекта в коллизии
 * @param this Указатель на CollisionBox
 * @return true если активен
 */
bool CollisionBox_S61_FUN_00421060(CollisionBox* this);

/**
 * @brief Получить тип объекта из коллизии
 * @param this Указатель на CollisionBox
 * @return Тип объекта (байт)
 */
u8 CollisionBox_S61_FUN_00421050(CollisionBox* this);

/**
 * @brief Обработка столкновения с объектом
 * @param this Указатель на CollisionBox
 * @param param Параметры столкновения
 */
void CollisionBox_S61_FUN_004829e0(CollisionBox* this, u32* param);

/**
 * @brief Очистка системы коллизий
 * @param this Указатель на CollisionBox
 */
void CollisionBox_S61_FUN_00482f60(CollisionBox* this);

#endif // COLLISIONBOX_H
