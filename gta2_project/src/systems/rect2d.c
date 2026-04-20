#include "math_types/rect2d.h"
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif

void Rect2D_Init(Rect2D* rect, f32 x, f32 y, f32 width, f32 height, f32 angle) {
    rect->Center = (Point2D){x, y};
    rect->HalfSize = (Vector2D){width / 2.0f, height / 2.0f};
    rect->Angle = angle;
    Rect2D_UpdateAxes(rect);
}

void Rect2D_UpdateAxes(Rect2D* rect) {
    // Вычисляем локальные оси из угла поворота
    rect->AxisX = (Vector2D){cosf(rect->Angle), sinf(rect->Angle)};
    rect->AxisY = (Vector2D){-sinf(rect->Angle), cosf(rect->Angle)};
}

bool Rect2D_Intersects(const Rect2D* a, const Rect2D* b) {
    Vector2D normal;
    f32 depth;
    
    // Используем алгоритм разделяющих осей (SAT)
    Vector2D axes[4] = {a->AxisX, a->AxisY, b->AxisX, b->AxisY};
    
    for (int i = 0; i < 4; i++) {
        Vector2D axis = axes[i];
        
        // Проекция центра A на ось
        f32 projA = a->Center.X * axis.X + a->Center.Y * axis.Y;
        f32 radiusA = a->HalfSize.X * fabsf(a->AxisX.X * axis.X + a->AxisX.Y * axis.Y) + 
                      a->HalfSize.Y * fabsf(a->AxisY.X * axis.X + a->AxisY.Y * axis.Y);
        
        // Проекция центра B на ось
        f32 projB = b->Center.X * axis.X + b->Center.Y * axis.Y;
        f32 radiusB = b->HalfSize.X * fabsf(b->AxisX.X * axis.X + b->AxisX.Y * axis.Y) + 
                      b->HalfSize.Y * fabsf(b->AxisY.X * axis.X + b->AxisY.Y * axis.Y);
        
        // Расстояние между проекциями центров
        f32 distance = fabsf(projA - projB);
        
        // Если расстояние больше суммы радиусов - нет пересечения
        if (distance > (radiusA + radiusB)) {
            return false;
        }
    }
    
    return true; // Пересечение по всем осям
}

bool Rect2D_ContainsPoint(const Rect2D* rect, Point2D point) {
    // Вектор от центра прямоугольника до точки
    Vector2D localPoint = Vec2_Sub(point, rect->Center);
    
    // Проецируем точку на локальные оси прямоугольника
    f32 projX = Vec2_Dot(localPoint, rect->AxisX);
    f32 projY = Vec2_Dot(localPoint, rect->AxisY);
    
    // Проверяем попадание в границы
    return (fabsf(projX) <= rect->HalfSize.X) && (fabsf(projY) <= rect->HalfSize.Y);
}

void Rect2D_GetVertices(const Rect2D* rect, Point2D* outVertices) {
    // 4 вершины: верх-право, верх-лево, низ-лево, низ-право (в локальных координатах)
    Vector2D corners[4] = {
        (Vector2D){ rect->HalfSize.X,  rect->HalfSize.Y},
        (Vector2D){-rect->HalfSize.X,  rect->HalfSize.Y},
        (Vector2D){-rect->HalfSize.X, -rect->HalfSize.Y},
        (Vector2D){ rect->HalfSize.X, -rect->HalfSize.Y}
    };
    
    for (int i = 0; i < 4; i++) {
        // Поворачиваем и смещаем вершину
        Vector2D rotated = Vec2_Rotate(corners[i], rect->Angle);
        outVertices[i] = Vec2_Add(rect->Center, rotated);
    }
}

// Объявление функции из collision.h для совместимости
struct CollisionResult;

bool Rect2D_Collision(const Rect2D* a, const Rect2D* b, struct CollisionResult* out);
