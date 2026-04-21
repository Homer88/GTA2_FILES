/**
 * @file base_car.c
 * @brief Реализация базового класса автомобиля (S82) GTA2
 * 
 * Адреса функций в IDA Pro указаны в комментариях "// old_name: FUN_XXXXXX"
 * Переменные имеют комментарии со старыми именами "// old_var: old_name -> new_name"
 * 
 * Структура: S82_BaseCar (0x68 байт)
 */

#include "../../include/entities/vehicle_types.h"
#include <string.h>

// ============================================================================
// ФУНКЦИИ BASE CAR (S82)
// ============================================================================

/**
 * @brief Инициализация базового автомобиля
 * @param this Указатель на экземпляр S82_BaseCar
 * 
 * old_name: FUN_004e5a10
 * Адрес: 0x004E5A10
 * old_var: PositionX/Y/Z -> Pos.X/Y/Z
 * old_var: VelocityX/Y -> Vel.X/Y
 */
void S82_Init(struct S82_BaseCar* this) {
    // old_var: ARR_S82 -> BaseCarArray
    // old_var: ARR_S83 -> TrainComponentArray
    
    // Сброс позиции в (0, 0, 0)
    this->PositionX = 0.0f;
    this->PositionY = 0.0f;
    this->PositionZ = 0.0f;
    this->Heading = 0.0f;
    
    // Сброс скорости и ускорения в 0
    this->Speed = 0.0f;
    this->Acceleration = 0.0f;
    this->VelocityX = 0.0f;
    this->VelocityY = 0.0f;
    this->AngularVelocity = 0.0f;
    
    // Инициализация физики
    this->Mass = 1000.0f;       // Стандартная масса
    this->Friction = 0.8f;      // Коэффициент трения
    
    // Сброс здоровья и флагов
    this->Health = 100;
    this->MaxHealth = 100;
    this->Flags = 0;
    this->DamageFlags = 0;
    
    // Сброс состояния
    this->State = 0;
    this->Timer = 0;
    this->PassengerCount = 0;
    this->TrafficLightState = 0;
    this->DoorState = 0;
    
    // Сброс освещения и двигателя
    this->LightState = 0;
    this->EngineOn = 0;
    this->Handbrake = 0;
    
    // Подвеска и колёса
    this->SuspensionHeight = 0.0f;
    this->WheelRotation[0] = 0;
    this->WheelRotation[1] = 0;
}

/**
 * @brief Обновление физики автомобиля (каждый кадр)
 * @param this Указатель на экземпляр S82_BaseCar
 * 
 * old_name: FUN_004e5b30
 * Адрес: 0x004E5B30
 * old_var: Acceleration -> Accel
 * old_var: Friction -> Drag
 * old_var: AngularVelocity -> RotVel
 */
void S82_UpdatePhysics(struct S82_BaseCar* this) {
    // Применение ускорения к скорости
    if (this->Acceleration != 0.0f) {
        this->Speed += this->Acceleration;
        
        // Ограничение скорости
        if (this->Speed < -50.0f) this->Speed = -50.0f;
        if (this->Speed > 150.0f) this->Speed = 150.0f;
    }
    
    // Применение трения
    if (this->Speed != 0.0f) {
        f32 friction = this->Friction * 0.1f;
        if (this->Speed > 0) {
            this->Speed -= friction;
            if (this->Speed < 0) this->Speed = 0;
        } else {
            this->Speed += friction;
            if (this->Speed > 0) this->Speed = 0;
        }
    }
    
    // Обновление вектора скорости на основе направления
    if (this->Speed != 0.0f) {
        // old_var: Heading -> Direction
        this->VelocityX = this->Speed * cosf(this->Heading);
        this->VelocityY = this->Speed * sinf(this->Heading);
    }
    
    // Обновление позиции
    this->PositionX += this->VelocityX;
    this->PositionY += this->VelocityY;
    
    // Обновление угла поворота от угловой скорости
    if (this->AngularVelocity != 0.0f) {
        this->Heading += this->AngularVelocity;
        
        // Нормализация угла
        if (this->Heading > 6.283185f) this->Heading -= 6.283185f;
        if (this->Heading < 0.0f) this->Heading += 6.283185f;
    }
}

/**
 * @brief Применение силы к автомобилю
 * @param this Указатель на экземпляр S82_BaseCar
 * @param forceX Сила по оси X
 * @param forceY Сила по оси Y
 * 
 * old_name: FUN_004e5c50
 * Адрес: 0x004E5C50
 * old_var: forceX -> Force.X
 * old_var: forceY -> Force.Y
 * old_var: Mass -> Weight
 */
void S82_ApplyForce(struct S82_BaseCar* this, f32 forceX, f32 forceY) {
    // old_var: Mass -> Weight
    // Учёт массы автомобиля (F = ma => a = F/m)
    f32 invMass = 1.0f / this->Mass;
    
    // Изменение VelocityX и VelocityY
    this->VelocityX += forceX * invMass;
    this->VelocityY += forceY * invMass;
    
    // Пересчёт скорости из вектора
    this->Speed = sqrtf(this->VelocityX * this->VelocityX + 
                        this->VelocityY * this->VelocityY);
}

/**
 * @brief Установка скорости автомобиля
 * @param this Указатель на экземпляр S82_BaseCar
 * @param speed Новая скорость
 * 
 * old_name: FUN_004e5d70
 * Адрес: 0x004E5D70
 * old_var: speed -> Velocity
 * old_var: Speed -> CurrentSpeed
 */
void S82_SetSpeed(struct S82_BaseCar* this, f32 speed) {
    // Ограничение скорости
    if (speed < -50.0f) speed = -50.0f;
    if (speed > 150.0f) speed = 150.0f;
    
    // Нормализация вектора скорости
    f32 currentSpeed = this->Speed;
    if (currentSpeed != 0.0f) {
        f32 scale = speed / currentSpeed;
        this->VelocityX *= scale;
        this->VelocityY *= scale;
    } else {
        // Если текущая скорость 0, устанавливаем по направлению
        this->VelocityX = speed * cosf(this->Heading);
        this->VelocityY = speed * sinf(this->Heading);
    }
    
    this->Speed = speed;
}

/**
 * @brief Поворот автомобиля на угол
 * @param this Указатель на экземпляр S82_BaseCar
 * @param angle Угол поворота
 * 
 * old_name: FUN_004e5e90
 * Адрес: 0x004E5E90
 * old_var: angle -> RotationAngle
 * old_var: Heading -> Direction
 * old_var: AngularVelocity -> TurnRate
 */
void S82_Turn(struct S82_BaseCar* this, f32 angle) {
    // Изменение Heading
    this->Heading += angle;
    
    // Нормализация угла (0..2PI)
    while (this->Heading > 6.283185f) {
        this->Heading -= 6.283185f;
    }
    while (this->Heading < 0.0f) {
        this->Heading += 6.283185f;
    }
    
    // Обновление AngularVelocity для плавности
    this->AngularVelocity = angle;
}

/**
 * @brief Проверка коллизий автомобиля
 * @param this Указатель на экземпляр S82_BaseCar
 * @return 1 если есть коллизия, 0 если нет
 * 
 * old_name: FUN_004e5fb0
 * Адрес: 0x004E5FB0
 * old_var: DamageFlags -> CollisionFlags
 * old_var: PositionX/Y/Z -> Pos.X/Y/Z
 */
int S82_CheckCollision(struct S82_BaseCar* this) {
    // old_var: DamageFlags -> CollisionFlags
    
    // Проверка пересечений с другими объектами
    // (реализация зависит от системы коллизий)
    
    // Проверка границ карты
    const f32 MAP_BOUNDARY = 10000.0f;
    if (this->PositionX < -MAP_BOUNDARY || this->PositionX > MAP_BOUNDARY ||
        this->PositionY < -MAP_BOUNDARY || this->PositionY > MAP_BOUNDARY) {
        return 1; // Коллизия с границей
    }
    
    // Проверка Z-координаты (не провалился ли под землю)
    if (this->PositionZ < -100.0f) {
        return 1; // Коллизия с "дном мира"
    }
    
    return 0; // Нет коллизий
}
