// vector3d.c - Реализация функций для работы с Vector3D
// Адрес глобальной переменной: 0x0066AB7C

#include "../../include/common/vector3d.h"

// Глобальная переменная gVector3D по адресу 0x0066AB7C
// old_name: gVector3D
// size: 12 bytes (0xC)
// DATA XREF: Car__sub_423A50+A, Car__sub_426120+A, AudioManager__sub_4148D0+B2
volatile Vector3D* const gVector3D_ptr = (volatile Vector3D*)0x0066AB7C;

// Экспорт символа для использования в других модулях
Vector3D gVector3D_66AB7C;

/**
 * Установить значения глобального вектора
 * old_name: sub_XXXXXX (если существует)
 */
void Vector3D_SetGlobal(float x, float y, float z) {
    if (gVector3D_ptr != NULL) {
        ((volatile float*)gVector3D_ptr)[0] = x;
        ((volatile float*)gVector3D_ptr)[1] = y;
        ((volatile float*)gVector3D_ptr)[2] = z;
    }
}

/**
 * Скопировать значения из глобального вектора
 * old_name: sub_XXXXXX (если существует)
 */
void Vector3D_CopyFromGlobal(Vector3D* dest) {
    if (gVector3D_ptr != NULL && dest != NULL) {
        dest->x = ((volatile float*)gVector3D_ptr)[0];
        dest->y = ((volatile float*)gVector3D_ptr)[1];
        dest->z = ((volatile float*)gVector3D_ptr)[2];
    }
}

/**
 * Скопировать значения в глобальный вектор
 * old_name: sub_XXXXXX (если существует)
 */
void Vector3D_CopyToGlobal(const Vector3D* src) {
    if (gVector3D_ptr != NULL && src != NULL) {
        ((volatile float*)gVector3D_ptr)[0] = src->x;
        ((volatile float*)gVector3D_ptr)[1] = src->y;
        ((volatile float*)gVector3D_ptr)[2] = src->z;
    }
}

/**
 * Инициализировать глобальный вектор нулями
 * old_name: sub_XXXXXX (если существует)
 */
void Vector3D_InitGlobalZero(void) {
    if (gVector3D_ptr != NULL) {
        ((volatile float*)gVector3D_ptr)[0] = 0.0f;
        ((volatile float*)gVector3D_ptr)[1] = 0.0f;
        ((volatile float*)gVector3D_ptr)[2] = 0.0f;
    }
}
