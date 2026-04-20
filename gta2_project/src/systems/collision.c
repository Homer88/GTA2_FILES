#include "collision.h"
#include "car.h"
#include <math.h>

// Константы для физики столкновений
#define COLLISION_EPSILON 0.001f
#define MIN_IMPULSE_THRESHOLD 0.5f
#define DAMAGE_MULTIPLIER 2.5f

/**
 * @brief Вспомогательная функция: проекция точки на ось
 */
static f32 ProjectPointOnAxis(Vector2D point, Vector2D axis) {
    return Vec2_Dot(point, axis);
}

/**
 * @brief Вспомогательная функция: поиск минимального проникновения по осям (SAT)
 */
static bool FindSeparatingAxis(const Rect2D* a, const Rect2D* b, Vector2D* outNormal, f32* outDepth) {
    Vector2D axes[4] = {a->AxisX, a->AxisY, b->AxisX, b->AxisY};
    f32 minDepth = FLT_MAX;
    Vector2D minAxis = (Vector2D){0, 0};
    
    for (int i = 0; i < 4; i++) {
        Vector2D axis = axes[i];
        
        // Проекция прямоугольника A на ось
        f32 projA = ProjectPointOnAxis(a->Center, axis);
        f32 radiusA = a->HalfSize.X * fabsf(Vec2_Dot(a->AxisX, axis)) + 
                      a->HalfSize.Y * fabsf(Vec2_Dot(a->AxisY, axis));
        
        // Проекция прямоугольника B на ось
        f32 projB = ProjectPointOnAxis(b->Center, axis);
        f32 radiusB = b->HalfSize.X * fabsf(Vec2_Dot(b->AxisX, axis)) + 
                      b->HalfSize.Y * fabsf(Vec2_Dot(b->AxisY, axis));
        
        // Расстояние между центрами проекций
        f32 distance = fabsf(projA - projB);
        f32 combinedRadius = radiusA + radiusB;
        
        // Если есть зазор - нет пересечения
        if (distance > combinedRadius) {
            return false;
        }
        
        // Глубина проникновения по этой оси
        f32 depth = combinedRadius - distance;
        if (depth < minDepth) {
            minDepth = depth;
            minAxis = axis;
            
            // Инвертируем нормаль если нужно
            if (Vec2_Dot(minAxis, Vec2_Sub(b->Center, a->Center)) < 0) {
                minAxis = Vec2_Mul(minAxis, -1.0f);
            }
        }
    }
    
    *outNormal = minAxis;
    *outDepth = minDepth;
    return true;
}

/**
 * @brief Инициализация результата столкновения
 */
static void CollisionResult_Init(CollisionResult* result) {
    result->HasCollision = false;
    result->PenetrationDepth = 0.0f;
    result->ContactNormal = (Vector2D){0, 0};
    result->ContactPoint = (Vector2D){0, 0};
    result->ImpulseMagnitude = 0.0f;
    result->CollisionType = COLLISION_NONE;
}

/**
 * @brief Проверка пересечения двух OBB с данными о столкновении
 */
bool Rect2D_Collision(const Rect2D* a, const Rect2D* b, CollisionResult* out) {
    CollisionResult_Init(out);
    
    Vector2D normal;
    f32 depth;
    
    if (!FindSeparatingAxis(a, b, &normal, &depth)) {
        return false; // Нет пересечения
    }
    
    // Есть пересечение - заполняем результат
    out->HasCollision = true;
    out->PenetrationDepth = depth;
    out->ContactNormal = normal;
    
    // Вычисляем точку контакта (приблизительно)
    out->ContactPoint = Vec2_Lerp(a->Center, b->Center, 0.5f);
    
    return true;
}

/**
 * @brief Расчет относительной скорости в точке контакта
 */
static f32 CalculateRelativeVelocity(struct Car* carA, struct Car* carB, Vector2D contactPoint) {
    // Скорость точки на машине A (линейная + угловая)
    Vector2D rA = Vec2_Sub(contactPoint, (Vector2D){carA->PositionX, carA->PositionY});
    Vector2D velA = Vec2_Add(
        (Vector2D){carA->VelocityX, carA->VelocityY},
        Vec2_Rotate(rA, carA->AngularVelocity * 0.01745329f) // Перевод градусов в радианы
    );
    
    // Скорость точки на машине B
    Vector2D rB = Vec2_Sub(contactPoint, (Vector2D){carB->PositionX, carB->PositionY});
    Vector2D velB = Vec2_Add(
        (Vector2D){carB->VelocityX, carB->VelocityY},
        Vec2_Rotate(rB, carB->AngularVelocity * 0.01745329f)
    );
    
    // Относительная скорость
    Vector2D relVel = Vec2_Sub(velA, velB);
    
    return Vec2_Dot(relVel, (Vector2D){1, 0}); // Скалярная величина
}

/**
 * @brief Применение импульса к автомобилю
 */
void Car_ApplyImpulse(struct Car* car, Vector2D impulse, Vector2D contactPoint) {
    // Применяем линейный импульс
    car->VelocityX += impulse.X / car->Mass;
    car->VelocityY += impulse.Y / car->Mass;
    
    // Вычисляем момент силы от удара
    Vector2D r = Vec2_Sub(contactPoint, (Vector2D){car->PositionX, car->PositionY});
    f32 torque = r.X * impulse.Y - r.Y * impulse.X;
    
    // Применяем угловой импульс
    car->AngularVelocity += torque / car->MomentOfInertia;
}

/**
 * @brief Применение урона автомобилю
 */
void Car_ApplyDamage(struct Car* car, f32 impactForce) {
    if (impactForce < MIN_IMPULSE_THRESHOLD) {
        return; // Слишком слабый удар
    }
    
    f32 damage = impactForce * DAMAGE_MULTIPLIER;
    
    // Вычитаем здоровье
    if (car->Health > damage) {
        car->Health -= damage;
    } else {
        car->Health = 0;
        car->IsWrecked = true; // Машина уничтожена
    }
    
    // Проверяем состояние двигателя
    if (damage > 50.0f && car->Engine.State != 2) { // 2 = заглушен
        car->Engine.State = 2; // Заглохнуть при сильном ударе
        car->Engine.Temperature = 100.0f; // Перегрев
    }
}

/**
 * @brief Столкновение двух автомобилей
 */
CollisionResult Car_CollisionOnCar(struct Car* carA, struct Car* carB) {
    CollisionResult result;
    CollisionResult_Init(&result);
    
    // Получаем bounding box обеих машин
    Rect2D boxA = carA->BoundingBox;
    Rect2D boxB = carB->BoundingBox;
    
    // Проверяем пересечение
    if (!Rect2D_Collision(&boxA, &boxB, &result)) {
        return result; // Нет столкновения
    }
    
    result.CollisionType = COLLISION_CAR;
    
    // Вычисляем относительную скорость
    f32 relVel = CalculateRelativeVelocity(carA, carB, result.ContactPoint);
    
    // Если машины удаляются друг от друга - не применяем физику
    if (relVel < 0) {
        result.HasCollision = false;
        return result;
    }
    
    result.ImpulseMagnitude = relVel;
    
    // Вычисляем импульс с учетом масс и упругости
    f32 e = 0.3f; // Коэффициент упругости (0 = полностью неупругое, 1 = упругое)
    f32 totalMass = carA->Mass + carB->Mass;
    f32 j = -(1.0f + e) * relVel / totalMass;
    
    Vector2D impulse = Vec2_Mul(result.ContactNormal, j);
    
    // Применяем импульсы к обеим машинам (третий закон Ньютона)
    Car_ApplyImpulse(carA, impulse, result.ContactPoint);
    Car_ApplyImpulse(carB, Vec2_Mul(impulse, -1.0f), result.ContactPoint);
    
    // Применяем урон
    Car_ApplyDamage(carA, fabsf(j));
    Car_ApplyDamage(carB, fabsf(j));
    
    return result;
}

/**
 * @brief Проверка столкновения со стенами (заглушка)
 */
CollisionResult Car_CheckWallCollision(struct Car* car, void* collisionBox) {
    CollisionResult result;
    CollisionResult_Init(&result);
    
    // TODO: Реализовать проверку с картой тайлов
    // Использовать collisionBox для проверки тайлов
    
    return result;
}

/**
 * @brief Основная функция проверки всех коллизий автомобиля
 */
CollisionResult Car_CheckCollision(struct Car* car, struct VehiclePool* vehicle_pool) {
    CollisionResult finalResult;
    CollisionResult_Init(&finalResult);
    
    // 1. Проверка со стенами
    // CollisionResult wallResult = Car_CheckWallCollision(car, NULL);
    // if (wallResult.HasCollision) {
    //     finalResult = wallResult;
    // }
    
    // 2. Проверка с другими машинами
    if (vehicle_pool != NULL) {
        for (int i = 0; i < vehicle_pool->ActiveCount; i++) {
            struct Car* other = &vehicle_pool->Cars[i];
            
            // Пропускаем саму себя и неактивные машины
            if (other == car || !other->IsActive) {
                continue;
            }
            
            // Быстрая проверка расстояния (оптимизация)
            f32 dx = car->PositionX - other->PositionX;
            f32 dy = car->PositionY - other->PositionY;
            f32 distSq = dx*dx + dy*dy;
            f32 minDist = car->Length + other->Length;
            
            if (distSq > minDist * minDist) {
                continue; // Слишком далеко
            }
            
            // Полная проверка
            CollisionResult carResult = Car_CollisionOnCar(car, other);
            if (carResult.HasCollision) {
                finalResult = carResult;
            }
        }
    }
    
    // Сохраняем последнее столкновение в структуре машины
    if (finalResult.HasCollision) {
        car->LastCollision.LastHit = finalResult;
        car->LastCollision.FrameCount = 0;
        
        // Проверяем на серьезную аварию
        if (finalResult.ImpulseMagnitude > 15.0f) {
            car->LastCollision.IsCrashed = true;
        }
    } else {
        car->LastCollision.FrameCount++;
        if (car->LastCollision.FrameCount > 10) {
            car->LastCollision.IsCrashed = false;
        }
    }
    
    return finalResult;
}
