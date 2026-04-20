// ============================================================================
// FILE: Vector2D.h
// DESCRIPTION: Базовая 2D векторная математика для физики и коллизий
// ORIGINAL: S2 (частично), производные типы
// SIZE: 8 байт
// ============================================================================

#ifndef VECTOR2D_H
#define VECTOR2D_H

#include "types.h"

/**
 * @struct Vector2D
 * @brief Двумерный вектор для координат и направлений
 * 
 * Используется в:
 * - Позиции объектов на карте (X, Y)
 * - Векторах скорости
 * - Нормалях для коллизий
 */
typedef struct Vector2D {
    float X;    // 0x0 - Координата X или компонента вектора
    float Y;    // 0x4 - Координата Y или компонента вектора
} Vector2D;

/**
 * @struct Point2D
 * @brief Точка в 2D пространстве с дополнительными данными
 * @original S9
 * @size 24 байта
 * 
 * Расширенная структура точки, используется для:
 * - Прямоугольных областей (Rect2D)
 * - Проверки попадания в зону
 * - Хранения границ объектов
 */
typedef struct Point2D {
    float MinX;     // 0x0 - Минимальная X координата (левая граница)
    float MinY;     // 0x4 - Минимальная Y координата (нижняя граница)
    float MaxX;     // 0x8 - Максимальная X координата (правая граница)
    float MaxY;     // 0xC - Максимальная Y координата (верхняя граница)
    u8 Flags;       // 0x10 - Флаги состояния (активность, тип)
    u8 Type;        // 0x11 - Тип объекта (пешеход, машина, здание)
    u16 Padding;    // 0x12 - Выравнивание
    void* Parent;   // 0x14 - Указатель на родительский объект
} Point2D;

// ============================================================================
// Inline функции для работы с Vector2D
// ============================================================================

/**
 * @brief Создать вектор из компонент
 */
static inline Vector2D Vec2_Create(float x, float y) {
    Vector2D v = {x, y};
    return v;
}

/**
 * @brief Сложение двух векторов
 */
static inline Vector2D Vec2_Add(Vector2D a, Vector2D b) {
    Vector2D result = {a.X + b.X, a.Y + b.Y};
    return result;
}

/**
 * @brief Вычитание двух векторов
 */
static inline Vector2D Vec2_Sub(Vector2D a, Vector2D b) {
    Vector2D result = {a.X - b.X, a.Y - b.Y};
    return result;
}

/**
 * @brief Умножение вектора на скаляр
 */
static inline Vector2D Vec2_Mul(Vector2D v, float scalar) {
    Vector2D result = {v.X * scalar, v.Y * scalar};
    return result;
}

/**
 * @brief Длина вектора (квадрат)
 */
static inline float Vec2_LengthSq(Vector2D v) {
    return v.X * v.X + v.Y * v.Y;
}

#endif // VECTOR2D_H
