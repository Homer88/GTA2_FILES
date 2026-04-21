/**
 * @file car_colors_palette.c
 * @brief C-реализация палитры цветов автомобилей GTA 2.
 * 
 * Размер: 0xA4 (164 байт)
 * Старое имя: S4
 */

#include "entities/car_colors_palette.h"
#include <stdlib.h>
#include <string.h>

CarColorsPalette* gCarColorsPalette = NULL;

CarColorsPalette* CarColorsPalette__ctor(CarColorsPalette* this) {
    if (!this) return NULL;
    memset(this->data, 0, sizeof(this->data));
    return this;
}

void CarColorsPalette__dtor(CarColorsPalette* this) {
    (void)this;
}
