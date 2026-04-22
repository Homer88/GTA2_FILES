/**
 * @file car_colors_palette.h
 * @brief Палитра цветов автомобилей GTA 2.
 * 
 * Адрес глобальной переменной: gCarColorsPalette (требует уточнения)
 * Размер структуры: 0xA4 (164 байт)
 * Конструктор: 0x00??? (S4::S4, требует уточнения)
 * 
 * Старое имя: S4
 * Новое имя: CarColorsPalette
 */

#ifndef GTA2_CAR_COLORS_PALETTE_H
#define GTA2_CAR_COLORS_PALETTE_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

extern CarColorsPalette* gCarColorsPalette;

typedef struct CarColorsPalette {
    /* 0x00 */ uint8_t data[0xA4];   // Внутренние данные палитры цветов
} CarColorsPalette;

#ifdef __cplusplus
static_assert(sizeof(CarColorsPalette) == 0xA4, "CarColorsPalette size must be 0xA4");
#endif

CarColorsPalette* CarColorsPalette__ctor(CarColorsPalette* this);
void CarColorsPalette__dtor(CarColorsPalette* this);

#ifdef __cplusplus
}
#endif

#endif // GTA2_CAR_COLORS_PALETTE_H
