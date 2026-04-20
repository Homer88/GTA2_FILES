#include "math_types/vector2d.h"
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif

Vector2D Vec2_Add(Vector2D a, Vector2D b) {
    return (Vector2D){a.X + b.X, a.Y + b.Y};
}

Vector2D Vec2_Sub(Vector2D a, Vector2D b) {
    return (Vector2D){a.X - b.X, a.Y - b.Y};
}

Vector2D Vec2_Mul(Vector2D v, f32 scalar) {
    return (Vector2D){v.X * scalar, v.Y * scalar};
}

Vector2D Vec2_Div(Vector2D v, f32 scalar) {
    if (scalar == 0.0f) return (Vector2D){0, 0};
    return (Vector2D){v.X / scalar, v.Y / scalar};
}

f32 Vec2_Dot(Vector2D a, Vector2D b) {
    return a.X * b.X + a.Y * b.Y;
}

f32 Vec2_Length(Vector2D v) {
    return sqrtf(v.X * v.X + v.Y * v.Y);
}

f32 Vec2_LengthSq(Vector2D v) {
    return v.X * v.X + v.Y * v.Y;
}

Vector2D Vec2_Normalize(Vector2D v) {
    f32 len = Vec2_Length(v);
    if (len == 0.0f) return (Vector2D){0, 0};
    return Vec2_Div(v, len);
}

Vector2D Vec2_Lerp(Vector2D a, Vector2D b, f32 t) {
    return (Vector2D){
        a.X + (b.X - a.X) * t,
        a.Y + (b.Y - a.Y) * t
    };
}

Vector2D Vec2_Rotate(Vector2D v, f32 angleRadians) {
    f32 cosA = cosf(angleRadians);
    f32 sinA = sinf(angleRadians);
    return (Vector2D){
        v.X * cosA - v.Y * sinA,
        v.X * sinA + v.Y * cosA
    };
}
