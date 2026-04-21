#ifndef GTA2_VECTOR3D_H
#define GTA2_VECTOR3D_H

#include <stdint.h>

// Структура Vector3D - используется для хранения 3D координат
// old_struct: Vector3D
typedef struct Vector3D {
    float x; // offset: 0x0
    float y; // offset: 0x4
    float z; // offset: 0x8
} Vector3D;

// Глобальная переменная gVector3D по адресу 0x0066AB7C
// old_name: gVector3D
// size: 12 bytes (0xC)
// DATA XREF: Car__sub_423A50+A, Car__sub_426120+A, AudioManager__sub_4148D0+B2
extern Vector3D gVector3D_66AB7C;

// Функции для работы с глобальным вектором
void Vector3D_SetGlobal(float x, float y, float z);
void Vector3D_CopyFromGlobal(Vector3D* dest);
void Vector3D_CopyToGlobal(const Vector3D* src);
void Vector3D_InitGlobalZero(void);

#endif // GTA2_VECTOR3D_H
