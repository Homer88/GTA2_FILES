/**
 * @file car_transforms.h
 * @brief Матрицы трансформации автомобилей GTA 2.
 * 
 * Адрес глобальной переменной: gCarTransforms (требует уточнения)
 * Размер структуры: 0x3C (60 байт)
 * Конструктор: 0x00??? (S3::S3, требует уточнения)
 * 
 * Старое имя: S3
 * Новое имя: CarTransforms
 */

#ifndef GTA2_CAR_TRANSFORMS_H
#define GTA2_CAR_TRANSFORMS_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

extern CarTransforms* gCarTransforms;

typedef struct CarTransforms {
    /* 0x00 */ uint8_t data[0x3C];   // Внутренние данные матриц трансформации
} CarTransforms;

#ifdef __cplusplus
static_assert(sizeof(CarTransforms) == 0x3C, "CarTransforms size must be 0x3C");
#endif

CarTransforms* CarTransforms__ctor(CarTransforms* this);
void CarTransforms__dtor(CarTransforms* this);

#ifdef __cplusplus
}
#endif

#endif // GTA2_CAR_TRANSFORMS_H
