#ifndef TURREL_H
#define TURREL_H

#include "types.h"

/**
 * @brief Структура турели (пулемёт на крыше автомобиля)
 * 
 * Используется для автомобилей с установленной турелью (Roof Tank Turret).
 * Размер: 8 байт
 * 
 * Поля из IDA Pro:
 * - void* void1 (0x0) - указатель на цель или флаги
 * - undefined2 count (0x4) - счётчик/таймер (значение 45 = полное)
 * - undefined field2_0x6 (0x6) - состояние/флаг
 * - undefined field3_0x7 (0x7) - дополнительные данные/выравнивание
 * 
 * Функции турели:
 * - S72_FUN_00420350: установка таймера/счётчика (значение 45)
 * - Turrel_FUN_004207e0: сброс указателя владельца
 * - FUN_00420de0: работа с битами флагов
 */
typedef struct Turrel {
    void* TargetPtr;            // 0x0 - Указатель на цель или битовые флаги состояния (void1 в IDA)
    u16 Counter;                // 0x4 - Счётчик/таймер турели (45 = полное значение) (count в IDA)
    u8 State;                   // 0x6 - Состояние турели (field2_0x6 в IDA)
    u8 Padding;                 // 0x7 - Выравнивание/доп. данные (field3_0x7 в IDA)
} Turrel, *PTurrel;

// Проверка размера (должно быть 8 байт)
// static_assert(sizeof(Turrel) == 8, "Turrel size mismatch");

#endif // TURREL_H
