/**
 * @file car.cpp
 * @brief C++ реализация класса CCar (автомобиль) в GTA 2.
 * 
 * Адрес конструктора: 0x004E39E0
 * Старое имя: Car::Car
 */

#include "entities/car.h"

#ifdef __cplusplus

// ============================================================================
// КЛАСС CCar (C++ обёртка)
// ============================================================================

class CCarImpl : public CCar {
public:
    /**
     * @brief Конструктор автомобиля
     * 
     * Оригинал: 0x004E39E0 (Car::Car)
     */
    CCarImpl() {
        CCar_Constructor(this);
    }
    
    /**
     * @brief Деструктор автомобиля
     */
    ~CCarImpl() {
        CCar_Destructor(this);
    }
    
    // Методы-обёртки
    void InitSub4BF000() {
        CCar_sub_4BF000(this);
    }
    
    void SetHornDefault() {
        CCar_SetHornDefault(this);
    }
};

// ============================================================================
// C API ФУНКЦИИ (реализация через класс)
// ============================================================================

extern "C" {

CCar* CCar_Constructor(CCar* this_) {
    return new (this_) CCarImpl();
}

CCar* CCar_Destructor(CCar* this_) {
    CCarImpl* obj = reinterpret_cast<CCarImpl*>(this_);
    obj->~CCarImpl();
    return this_;
}

void CCar_sub_4BF000(CCar* this_) {
    reinterpret_cast<CCarImpl*>(this_)->InitSub4BF000();
}

void CCar_SetHornDefault(CCar* this_) {
    reinterpret_cast<CCarImpl*>(this_)->SetHornDefault();
}

} // extern "C"

#endif // __cplusplus
