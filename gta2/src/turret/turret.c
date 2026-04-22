/**
 * @file turret.c
 * @brief Реализация системы турели на C.
 */

#include "turret.h"
#include <string.h>

void Turret__Init(CTurret* this) {
    if (!this) return;

    // Сброс вектора направления
    memset(&this->targetDir, 0, sizeof(Vector3D));
    
    // Сброс углов
    this->currentYaw = 0.0f;
    this->currentPitch = 0.0f;
    
    // Сброс таймеров
    this->fireCooldownTimer = 0;
    this->lockOnTimer = 0;
    
    // Сброс состояния
    this->state = TURRET_STATE_IDLE;
    this->pTarget = NULL;
    this->flags = 0;
    this->ammoCount = -1; // -1 означает бесконечные патроны
    this->accuracy = 1.0f;
}

void Turret__Update(CTurret* this, float dt) {
    if (!this) return;
    
    // TODO: Реализовать логику обновления
    // 1. Проверка времени перезарядки
    // 2. Обновление углов поворота к цели
    // 3. Проверка видимости цели
}

int Turret__Fire(CTurret* this) {
    if (!this) return 0;
    
    // Проверка готовности к стрельбе
    if (this->state != TURRET_STATE_FIRING && this->state != TURRET_STATE_TRACKING) {
        return 0;
    }
    
    if (this->fireCooldownTimer > 0) {
        return 0;
    }
    
    if (this->ammoCount == 0) {
        return 0;
    }
    
    // TODO: Логика выстрела (спавн пули, нанесение урона)
    
    if (this->ammoCount > 0) {
        this->ammoCount--;
    }
    
    // Запуск таймера перезарядки
    this->fireCooldownTimer = 500; // Примерное значение (мс)
    
    return 1;
}

void Turret__SetTarget(CTurret* this, void* target) {
    if (!this) return;
    
    this->pTarget = target;
    
    if (target != NULL) {
        this->state = TURRET_STATE_TRACKING;
        this->lockOnTimer = 0;
    } else {
        this->state = TURRET_STATE_IDLE;
    }
}
