// ============================================================================
// FILE: Rect2D.h
// DESCRIPTION: Прямоугольная область для коллизий и зон
// ORIGINAL: S8
// SIZE: 16 байт
// ============================================================================

#ifndef RECT2D_H
#define RECT2D_H

#include "types.h"
#include "Vector3D.h"  // Для Vector2D

/**
 * @struct Rect2D
 * @brief Прямоугольник в 2D пространстве
 * @original S8
 * 
 * Используется для:
 * - Ограничивающих коробок (bounding box) объектов
 * - Зон триггеров на карте
 * - Проверки пересечений AABB
 */
typedef struct Rect2D {
    Vector2D Min;         // 0x0 - Левый нижний угол (MinX, MinY)
    Vector2D Max;         // 0x8 - Правый верхний угол (MaxX, MaxY)
    u8 Flags;             // 0x10 - Флаги (активность, тип коллизии)
    u8 Type;              // 0x11 - Тип объекта (статичный/динамичный)
    u16 Padding;          // 0x12 - Выравнивание
} Rect2D;

// ============================================================================
// Inline функции для работы с Rect2D
// ============================================================================

/**
 * @brief Создать прямоугольник из двух точек
 */
static inline Rect2D Rect2D_Create(Vector2D min, Vector2D max) {
    Rect2D r;
    r.Min = min;
    r.Max = max;
    r.Flags = 0;
    r.Type = 0;
    r.Padding = 0;
    return r;
}

/**
 * @brief Проверить, содержит ли прямоугольник точку
 */
static inline bool Rect2D_ContainsPoint(Rect2D* rect, Vector2D point) {
    return (point.X >= rect->Min.X && point.X <= rect->Max.X &&
            point.Y >= rect->Min.Y && point.Y <= rect->Max.Y);
}

/**
 * @brief Проверить пересечение двух прямоугольников
 */
static inline bool Rect2D_Intersects(Rect2D* a, Rect2D* b) {
    return (a->Min.X <= b->Max.X && a->Max.X >= b->Min.X &&
            a->Min.Y <= b->Max.Y && a->MaxY >= b->Min.Y);
}

/**
 * @brief Получить ширину прямоугольника
 */
static inline float Rect2D_GetWidth(Rect2D* rect) {
    return rect->Max.X - rect->Min.X;
}

/**
 * @brief Получить высоту прямоугольника
 */
static inline float Rect2D_GetHeight(Rect2D* rect) {
    return rect->Max.Y - rect->Min.Y;
}

/**
 * @brief Получить центр прямоугольника
 */
static inline Vector2D Rect2D_GetCenter(Rect2D* rect) {
    Vector2D center;
    center.X = (rect->Min.X + rect->Max.X) * 0.5f;
    center.Y = (rect->Min.Y + rect->Max.Y) * 0.5f;
    return center;
}

#endif // RECT2D_H
