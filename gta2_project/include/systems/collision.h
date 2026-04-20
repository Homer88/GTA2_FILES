#ifndef COLLISION_H
#define COLLISION_H

#include "types.h"
#include "math_types/vector2d.h"
#include "math_types/rect2d.h"

// Предварительное объявление структуры Car
struct Car;
struct VehiclePool;

// Типы объектов для коллизий
typedef enum {
    COLLISION_NONE = 0,
    COLLISION_WALL = 1,
    COLLISION_CAR = 2,
    COLLISION_PED = 3,
    COLLISION_BUILDING = 4,
    COLLISION_OBJECT = 5
} CollisionType;

/**
 * @brief Результат проверки столкновения
 */
typedef struct CollisionResult {
    bool HasCollision;          // Флаг наличия столкновения
    f32 PenetrationDepth;       // Глубина проникновения
    Vector2D ContactNormal;     // Нормаль контакта (направление удара)
    Vector2D ContactPoint;      // Точка контакта в мировых координатах
    f32 ImpulseMagnitude;       // Сила импульса (для расчета урона/отскока)
    u8 CollisionType;           // Тип объекта: 0=Нет, 1=Стена, 2=Машина, 3=Пешеход
    u8 Padding[3];              // Выравнивание
} CollisionResult;

/**
 * @brief Информация о последнем столкновении автомобиля
 * Встраивается в структуру Car
 */
typedef struct CollisionInfo {
    CollisionResult LastHit;    // Данные последнего удара
    u32 FrameCount;             // Сколько кадров назад произошло столкновение
    bool IsCrashed;             // Флаг серьезной аварии (машина не управляется)
    u8 Padding[3];              // Выравнивание
} CollisionInfo;

/**
 * @brief Основная функция проверки коллизий для автомобиля
 * Проверяет столкновения с картой, другими машинами и объектами.
 * 
 * @param car Указатель на проверяемый автомобиль
 * @param vehicle_pool Указатель на пул автомобилей (для проверки других машин)
 * @return CollisionResult Результат проверки (если было столкновение)
 */
CollisionResult Car_CheckCollision(struct Car* car, struct VehiclePool* vehicle_pool);

/**
 * @brief Расчет физики столкновения двух автомобилей
 * Вызывается внутри Car_CheckCollision для каждой пары машин.
 * 
 * @param carA Первый автомобиль
 * @param carB Второй автомобиль
 * @return CollisionResult Параметры взаимодействия (импульс, направление)
 */
CollisionResult Car_CollisionOnCar(struct Car* carA, struct Car* carB);

/**
 * @brief Применение импульса от столкновения к автомобилю
 * Изменяет скорость и угловую скорость машины.
 * 
 * @param car Автомобиль
 * @param impulse Вектор импульса
 * @param contactPoint Точка приложения силы (в мировых координатах)
 */
void Car_ApplyImpulse(struct Car* car, Vector2D impulse, Vector2D contactPoint);

/**
 * @brief Расчет урона автомобилю при столкновении
 * 
 * @param car Автомобиль
 * @param impactForce Сила удара
 */
void Car_ApplyDamage(struct Car* car, f32 impactForce);

/**
 * @brief Проверка столкновения со стенами уровня
 * 
 * @param car Автомобиль
 * @param collisionBox Менеджер коллизий уровня
 * @return CollisionResult Результат проверки стен
 */
CollisionResult Car_CheckWallCollision(struct Car* car, void* collisionBox);

#endif // COLLISION_H
