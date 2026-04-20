/**
 * @file vehicle_physics_ext.h
 * @brief Расширенные структуры физики автомобилей (колеса, подвеска, повреждения).
 * 
 * Детализация внутренней физики, которая в базовой структуре Car представлена
 * упрощенно. Используется для более точного моделирования поведения.
 */

#ifndef VEHICLE_PHYSICS_EXT_H
#define VEHICLE_PHYSICS_EXT_H

#include "types.h"
#include "math_types/vector2d.h"

#pragma pack(push, 1)

/**
 * @brief Состояние одного колеса.
 * Оригинал IDA: Вложено в `Car` или `struct WheelState` / `WHEEL_STAT`
 * Размер: 24 байта на колесо.
 * В машине 4 таких структуры (LF, RF, LR, RR).
 */
typedef struct WheelState {
    f32 RotationAngle;        // 0x00: Угол вращения колеса (радианы)
    f32 RotationalVelocity;   // 0x04: Угловая скорость вращения
    f32 SteeringAngle;        // 0x08: Угол поворота руля (для передних)
    bool IsOnGround;          // 0x0C: Контакт с землей
    bool IsBraking;           // 0x0D: Нажат ли тормоз
    bool IsHandbrake;         // 0x0E: Ручной тормоз
    u8  FrictionCoeff;        // 0x0F: Коэффициент трения поверхности
    f32 SuspensionCompression;// 0x10: Текущее сжатие амортизатора
    f32 LastHitHeight;        // 0x14: Высота последнего препятствия
} WheelState;

/**
 * @brief Параметры подвески.
 * Оригинал IDA: `struct SuspensionData` / `SUSP_DATA`
 * Определяет жесткость и поведение пружин.
 */
typedef struct SuspensionData {
    f32 SpringStiffness;      // 0x00: Жесткость пружины
    f32 DampingRatio;         // 0x04: Коэффициент демпфирования (гашение колебаний)
    f32 MaxTravel;            // 0x08: Максимальный ход подвески
    f32 RestLength;           // 0x0C: Длина в покое
    u8  Type;                 // 0x10: Тип (мягкая, спортивная, грузовая)
    u8  Flags;                // 0x11: Флаги (полный привод, блокировка)
    u16 Reserved;             // 0x12: Выравнивание
} SuspensionData;

/**
 * @brief Зона повреждений кузова.
 * Оригинал IDA: Массив в `Car` или `struct DamageZone` / `DMG_ZONE`
 * Машина делится на зоны: Перед, Зад, Лево, Право, Крыша, Дно.
 */
typedef struct DamageZone {
    u16 Health;               // 0x00: Здоровье зоны (0 = разрушено)
    u16 MaxHealth;            // 0x02: Максимальное здоровье
    u8  State;                // 0x04: Состояние (0=OK, 1=Dented, 2=Broken, 3=Missing)
    u8  VisualFlag;           // 0x05: Флаг визуального повреждения (спрайт)
    u8  AffectedSystem;       // 0x06: Затронутая система (двигатель, бак, руль)
    u8  Padding;              // 0x07: Выравнивание
} DamageZone;

/**
 * @brief Данные передачи КПП.
 * Оригинал IDA: `struct TransmissionGear` / `TRANS_GEAR`
 */
typedef struct TransmissionGear {
    f32 Ratio;                // 0x00: Передаточное число
    f32 MaxSpeed;             // 0x04: Максимальная скорость на этой передаче
    f32 Acceleration;         // 0x08: Коэффициент ускорения
} TransmissionGear;

/**
 * @brief Полный расширенный контекст физики авто.
 * Объединяет все вышеперечисленное для удобного доступа.
 */
typedef struct VehiclePhysicsExt {
    WheelState Wheels[4];         // Массив из 4 колес
    SuspensionData Suspension;    // Общие параметры подвески
    DamageZone Zones[6];          // 6 зон повреждений
    TransmissionGear Gears[6];    // 6 передач (включая заднюю)
    u8 CurrentGear;               // Текущая передача
    u8 DriveType;                 // Тип привода (FWD, RWD, AWD)
    u16 Flags;                    // Флаги физики (дрифт, инерция)
} VehiclePhysicsExt;

#pragma pack(pop)

#endif // VEHICLE_PHYSICS_EXT_H
