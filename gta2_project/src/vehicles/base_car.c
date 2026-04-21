/**
 * @file base_car.c
 * @brief Реализация базового класса автомобиля (BaseCar) GTA2
 * 
 * Адреса функций в IDA Pro указаны в комментариях "// old_name: sub_XXXXXX"
 * Переменные имеют комментарии со старыми именами "// old_var: old_name -> new_name"
 * 
 * Структура: BaseCar (0x68 байт)
 */

#include "../../include/entities/vehicle_types.h"
#include <string.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif
#ifndef TWO_PI
#define TWO_PI 6.28318530717958647692f
#endif

// ============================================================================
// ФУНКЦИИ BASE CAR (бывший S82)
// ============================================================================

/**
 * @brief Инициализация базового автомобиля
 * @param self Указатель на экземпляр BaseCar
 * @param type Тип транспортного средства
 * 
 * old_name: sub_4B5500
 * Адрес: 0x004B5500
 * old_var: this -> a1
 * old_var: type -> a2
 */
void BaseCar_Init(BaseCar* self, VehicleType type) {
    // old_var: ARR_S82 -> BaseCarArray
    // old_var: ARR_S83 -> TrainComponentArray
    
    if (!self) return;
    
    // Сброс позиции в (0, 0, 0)
    self->x = 0.0f;
    self->y = 0.0f;
    self->z = 0.0f;
    self->angle = 0.0f;
    
    // Сброс скорости и ускорения в 0
    self->speed = 0.0f;
    self->acceleration = 0.0f;
    
    // Инициализация физики
    self->mass = 1000.0f;       // Стандартная масса
    self->friction = 0.8f;      // Коэффициент трения
    
    // Сброс статуса
    self->status = 0;
    self->sprite_id = (int16_t)type;
}

/**
 * @brief Обновление физики автомобиля (каждый кадр)
 * @param self Указатель на экземпляр BaseCar
 * 
 * old_name: sub_4B5620
 * Адрес: 0x004B5620
 * old_var: this -> a1
 * old_var: Acceleration -> Accel
 * old_var: Friction -> Drag
 */
void BaseCar_UpdatePhysics(BaseCar* self) {
    if (!self) return;
    
    // Применение ускорения к скорости
    if (self->acceleration != 0.0f) {
        self->speed += self->acceleration;
        
        // Ограничение скорости
        if (self->speed < -50.0f) self->speed = -50.0f;
        if (self->speed > 150.0f) self->speed = 150.0f;
    }
    
    // Применение трения
    if (self->speed != 0.0f) {
        float friction = self->friction * 0.1f;
        if (self->speed > 0) {
            self->speed -= friction;
            if (self->speed < 0) self->speed = 0;
        } else {
            self->speed += friction;
            if (self->speed > 0) self->speed = 0;
        }
    }
}

/**
 * @brief Применение силы к автомобилю
 * @param self Указатель на экземпляр BaseCar
 * @param fx Сила по оси X
 * @param fy Сила по оси Y
 * 
 * old_name: sub_4B5890
 * Адрес: 0x004B5890
 * old_var: this -> a1
 * old_var: fx -> a2
 * old_var: fy -> a3
 * old_var: Mass -> Weight
 */
void BaseCar_ApplyForce(BaseCar* self, float fx, float fy) {
    if (!self) return;
    
    // old_var: Mass -> Weight
    // Учёт массы автомобиля (F = ma => a = F/m)
    float invMass = 1.0f / self->mass;
    
    // Изменение скорости (упрощённо)
    self->speed += (fx * invMass);
}

/**
 * @brief Установка скорости автомобиля
 * @param self Указатель на экземпляр BaseCar
 * @param speed Новая скорость
 * 
 * old_name: sub_4B5A10
 * Адрес: 0x004B5A10
 * old_var: this -> a1
 * old_var: speed -> a2
 * old_var: Speed -> CurrentSpeed
 */
void BaseCar_SetSpeed(BaseCar* self, float speed) {
    if (!self) return;
    
    // Ограничение скорости
    if (speed < -50.0f) speed = -50.0f;
    if (speed > 150.0f) speed = 150.0f;
    
    self->speed = speed;
}

/**
 * @brief Поворот автомобиля на угол
 * @param self Указатель на экземпляр BaseCar
 * @param angle_delta Угол поворота
 * 
 * old_name: sub_4B5C40
 * Адрес: 0x004B5C40
 * old_var: this -> a1
 * old_var: angle_delta -> a2
 * old_var: angle -> RotationAngle
 * old_var: Heading -> Direction
 */
void BaseCar_Turn(BaseCar* self, float angle_delta) {
    if (!self) return;
    
    // Изменение угла
    self->angle += angle_delta;
    
    // Нормализация угла (0..2PI)
    while (self->angle > TWO_PI) {
        self->angle -= TWO_PI;
    }
    while (self->angle < 0.0f) {
        self->angle += TWO_PI;
    }
}

/**
 * @brief Проверка коллизий автомобиля
 * @param self Указатель на экземпляр BaseCar
 * @param other Другой автомобиль для проверки
 * @return true если есть коллизия, false если нет
 * 
 * old_name: sub_4B6000
 * Адрес: 0x004B6000
 * old_var: this -> a1
 * old_var: other -> a2
 * old_var: DamageFlags -> CollisionFlags
 * old_var: PositionX/Y/Z -> Pos.X/Y/Z
 */
bool BaseCar_CheckCollision(BaseCar* self, BaseCar* other) {
    if (!self || !other) return false;
    
    // old_var: DamageFlags -> CollisionFlags
    
    // Простая проверка расстояния (можно заменить на AABB или другую)
    float dx = self->x - other->x;
    float dy = self->y - other->y;
    float distance_sq = dx * dx + dy * dy;
    
    // Если расстояние меньше суммы радиусов (условно 2.0 единицы)
    if (distance_sq < 16.0f) {
        return true; // Коллизия
    }
    
    return false; // Нет коллизий
}
