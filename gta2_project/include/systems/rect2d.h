#ifndef RECT2D_H
#define RECT2D_H

#include "vector2d.h"

/**
 * @brief Ориентированный прямоугольник (OBB - Oriented Bounding Box)
 * Используется для коллизий автомобилей и объектов
 */
typedef struct Rect2D {
    Point2D Center;       // Центр прямоугольника
    Vector2D HalfSize;    // Половина ширины и высоты
    f32 Angle;            // Угол поворота в радианах
    Vector2D AxisX;       // Локальная ось X (единичный вектор)
    Vector2D AxisY;       // Локальная ось Y (единичный вектор)
} Rect2D;

/**
 * @brief Инициализация OBB из центра, размеров и угла
 */
void Rect2D_Init(Rect2D* rect, f32 x, f32 y, f32 width, f32 height, f32 angle);

/**
 * @brief Обновление осей прямоугольника при изменении угла
 */
void Rect2D_UpdateAxes(Rect2D* rect);

/**
 * @brief Проверка пересечения двух OBB
 * @return true если есть пересечение
 */
bool Rect2D_Intersects(const Rect2D* a, const Rect2D* b);

/**
 * @brief Глубокая проверка пересечения с данными о столкновении
 * @param out Результат столкновения (заполняется при пересечении)
 * @return true если есть пересечение
 */
bool Rect2D_Collision(const Rect2D* a, const Rect2D* b, struct CollisionResult* out);

/**
 * @brief Проверка точки внутри прямоугольника
 */
bool Rect2D_ContainsPoint(const Rect2D* rect, Point2D point);

/**
 * @brief Получение 4 вершин прямоугольника
 */
void Rect2D_GetVertices(const Rect2D* rect, Point2D* outVertices);

#endif // RECT2D_H
