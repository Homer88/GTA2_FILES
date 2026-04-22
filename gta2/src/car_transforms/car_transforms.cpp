/**
 * @file car_transforms.cpp
 * @brief C++-реализация матриц трансформации автомобилей GTA 2.
 * 
 * Размер: 0x3C (60 байт)
 * Старое имя: S3
 */

#include "entities/car_transforms.h"
#include <cstring>

CarTransforms* gCarTransforms = nullptr;

extern "C" {

CarTransforms* CarTransforms__ctor(CarTransforms* this) {
    if (!this) return nullptr;
    std::memset(this->data, 0, sizeof(this->data));
    return this;
}

void CarTransforms__dtor(CarTransforms* this) {
    (void)this;
}

} /* extern "C" */
