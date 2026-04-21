/**
 * @file car_colors_palette.cpp
 * @brief C++-реализация палитры цветов автомобилей GTA 2.
 * 
 * Размер: 0xA4 (164 байт)
 * Старое имя: S4
 */

#include "entities/car_colors_palette.h"
#include <cstring>

CarColorsPalette* gCarColorsPalette = nullptr;

extern "C" {

CarColorsPalette* CarColorsPalette__ctor(CarColorsPalette* this) {
    if (!this) return nullptr;
    std::memset(this->data, 0, sizeof(this->data));
    return this;
}

void CarColorsPalette__dtor(CarColorsPalette* this) {
    (void)this;
}

} /* extern "C" */
