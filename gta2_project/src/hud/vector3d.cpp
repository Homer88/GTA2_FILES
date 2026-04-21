// vector3d.cpp - C++ обертки для работы с Vector3D
// Адрес глобальной переменной: 0x0066AB7C

extern "C" {
    #include "../../include/common/vector3d.h"
    
    // Глобальная переменная gVector3D по адресу 0x0066AB7C
    extern volatile Vector3D* const gVector3D_ptr;
}

namespace GTA2 {
namespace Vector {

/**
 * Установить координаты глобального вектора
 * old_name: sub_XXXXXX (если существует)
 */
void SetGlobal(float x, float y, float z) {
    ::Vector3D_SetGlobal(x, y, z);
}

/**
 * Получить координаты из глобального вектора
 * old_name: sub_XXXXXX (если существует)
 */
Vector3D GetGlobal() {
    Vector3D result = {0.0f, 0.0f, 0.0f};
    ::Vector3D_CopyFromGlobal(&result);
    return result;
}

/**
 * Скопировать вектор в глобальную переменную
 * old_name: sub_XXXXXX (если существует)
 */
void CopyToGlobal(const Vector3D& src) {
    ::Vector3D_CopyToGlobal(&src);
}

/**
 * Инициализировать глобальный вектор нулями
 * old_name: sub_XXXXXX (если существует)
 */
void InitGlobalZero() {
    ::Vector3D_InitGlobalZero();
}

/**
 * Класс-обертка для работы с глобальным вектором
 */
class GlobalVector3D {
public:
    // old_var: gVector3D
    static Vector3D Get() {
        Vector3D result;
        ::Vector3D_CopyFromGlobal(&result);
        return result;
    }
    
    static void Set(float x, float y, float z) {
        ::Vector3D_SetGlobal(x, y, z);
    }
    
    static void Set(const Vector3D& v) {
        ::Vector3D_CopyToGlobal(&v);
    }
    
    static void Zero() {
        ::Vector3D_InitGlobalZero();
    }
    
    // Прямой доступ к памяти (осторожно!)
    static Vector3D* GetPtr() {
        return const_cast<Vector3D*>(::gVector3D_ptr);
    }
};

} // namespace Vector
} // namespace GTA2
