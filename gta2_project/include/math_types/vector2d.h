#ifndef VECTOR2D_H
#define VECTOR2D_H

#include "../types.h"

/**
 * @brief 2D вектор для физики и математики
 */
typedef struct Vector2D {
    f32 X;
    f32 Y;
} Vector2D;

/**
 * @brief 2D точка (алиас на Vector2D)
 */
typedef Vector2D Point2D;

// Операции с векторами
Vector2D Vec2_Add(Vector2D a, Vector2D b);
Vector2D Vec2_Sub(Vector2D a, Vector2D b);
Vector2D Vec2_Mul(Vector2D v, f32 scalar);
Vector2D Vec2_Div(Vector2D v, f32 scalar);
f32 Vec2_Dot(Vector2D a, Vector2D b);
f32 Vec2_Length(Vector2D v);
f32 Vec2_LengthSq(Vector2D v);
Vector2D Vec2_Normalize(Vector2D v);
Vector2D Vec2_Lerp(Vector2D a, Vector2D b, f32 t);

// Вращение вектора
Vector2D Vec2_Rotate(Vector2D v, f32 angleRadians);

#endif // VECTOR2D_H
