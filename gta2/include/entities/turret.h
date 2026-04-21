/**
 * @file turret.h
 * @brief Система наведения и стрельбы транспортных средств (Turret).
 * 
 * Старое имя: Turrel
 * Адрес конструктора: 0x00424620 (Turrel__sub_424620)
 * Размер: sizeof(CTurret) (встроена в начало CCar)
 */

#ifndef GTA2_TURRET_H
#define GTA2_TURRET_H

#include "../math/vector3d.h"
#include "../types.h"

#ifdef __cplusplus
extern "C" {
#endif

// Состояния турели
typedef enum ETurretState {
    TURRET_STATE_IDLE = 0,      // Бездействие
    TURRET_STATE_SEARCHING = 1, // Поиск цели
    TURRET_STATE_TRACKING = 2,  // Сопровождение цели
    TURRET_STATE_FIRING = 3     // Стрельба
} ETurretState;

// Флаги турели
typedef enum ETurretFlags {
    TURRET_FLAG_ACTIVE = 0x1,
    TURRET_FLAG_AUTO_FIRE = 0x2,
    TURRET_FLAG_LOCKED = 0x4
} ETurretFlags;

/**
 * @struct CTurret
 * @brief Компонент управления оружием транспортного средства.
 * 
 * Встраивается в начало структуры CCar (смещение 0x00).
 * Отвечает за вычисление углов поворота, выбор цели и контроль стрельбы.
 */
typedef struct CTurret {
    /* 0x00 */ Vector3D targetDir;        // Вектор направления на цель
    /* 0x0C */ float currentYaw;          // Текущий угол поворота (горизонталь)
    /* 0x10 */ float currentPitch;        // Текущий угол наклона (вертикаль)
    /* 0x14 */ int fireCooldownTimer;     // Таймер перезарядки
    /* 0x18 */ ETurretState state;        // Текущее состояние
    /* 0x1C */ void* pTarget;             // Указатель на цель (CPed* или CCar*)
    /* 0x20 */ uint32 flags;              // Флаги состояния
    /* 0x24 */ int ammoCount;             // Количество патронов (если ограничено)
    /* 0x28 */ float accuracy;            // Разброс стрельбы
    /* 0x2C */ int lockOnTimer;           // Таймер захвата цели
} CTurret;

// Проверка размера (предположительно 48 байт, требует уточнения по карте памяти)
// static_assert(sizeof(CTurret) == 0x30, "CTurret size mismatch");

/**
 * @brief Инициализация системы турели.
 * @param this Указатель на структуру CTurret.
 * 
 * Адрес: 0x00424620
 * Сбрасывает углы, таймеры и состояние в значения по умолчанию.
 */
void Turret__Init(CTurret* this);

/**
 * @brief Обновление логики наведения.
 * @param this Указатель на структуру CTurret.
 * @param dt Дельта времени.
 */
void Turret__Update(CTurret* this, float dt);

/**
 * @brief Попытка выстрела.
 * @param this Указатель на структуру CTurret.
 * @return 1 если выстрел произведен, 0 иначе.
 */
int Turret__Fire(CTurret* this);

/**
 * @brief Установка новой цели.
 * @param this Указатель на структуру CTurret.
 * @param target Указатель на объект цели.
 */
void Turret__SetTarget(CTurret* this, void* target);

#ifdef __cplusplus
}
#endif

#endif // GTA2_TURRET_H
