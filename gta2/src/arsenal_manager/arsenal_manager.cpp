/*
 * File: arsenal_manager.cpp
 * Description: C++ реализация менеджера арсенала (Weapon1)
 * Original Name: Weapon1
 * Size: 0x2FDC (12252 bytes)
 * Constructor Address: 0x00424620
 */

#include "../../include/entities/arsenal_manager.h"
#include <cstring>
#include <new>

// Глобальный указатель (объявление, определение в линковщике)
// CArsenalManager* gWeapon1 = nullptr;

/**
 * Конструктор (метод класса)
 * Соответствует ассемблерной функции по адресу 0x00424620
 */
CArsenalManagerCpp* CArsenalManagerCpp::Constructor() {
    // Инициализация памяти нулями (аналог memset в C версии)
    std::memset(this, 0, sizeof(CArsenalManagerCpp));
    
    // Сброс счетчиков и указателей
    this->totalWeapons = 0;
    this->maxWeapons = 0;
    this->pWeapons = nullptr;
    this->pAmmoTable = nullptr;
    this->pEffectTable = nullptr;
    
    // rawData уже очищена через memset
    
    // TODO: Здесь должна быть логика загрузки таблиц оружия из файлов
    // В оригинальном exe это может быть вызов парсера ресурсов
    
    return this;
}

/**
 * Деструктор
 */
CArsenalManagerCpp::~CArsenalManagerCpp() {
    if (this->pWeapons) {
        delete[] this->pWeapons;
        this->pWeapons = nullptr;
    }
    
    this->totalWeapons = 0;
    this->maxWeapons = 0;
    this->pAmmoTable = nullptr;
    this->pEffectTable = nullptr;
}

/**
 * Получить определение оружия по ID
 */
CWeaponDefinition* CArsenalManagerCpp::GetWeaponDef(uint32_t id) {
    if (id < this->totalWeapons && this->pWeapons != nullptr) {
        return &this->pWeapons[id];
    }
    return nullptr;
}

/**
 * Статический метод создания экземпляра
 * Эмулирует логику: operator_new + Constructor
 */
CArsenalManagerCpp* CArsenalManagerCpp::CreateInstance() {
    void* mem = operator new(sizeof(CArsenalManagerCpp));
    if (mem) {
        return reinterpret_cast<CArsenalManagerCpp*>(mem)->Constructor();
    }
    return nullptr;
}

// -----------------------------------------------------------------------------
// C-обертки для совместимости с кодом на C
// -----------------------------------------------------------------------------

extern "C" {

CArsenalManager* CArsenalManager_Constructor(CArsenalManager* this_ptr) {
    // Приводим к C++ классу и вызываем метод
    return reinterpret_cast<CArsenalManager*>(
        reinterpret_cast<CArsenalManagerCpp*>(this_ptr)->Constructor()
    );
}

void CArsenalManager_Destructor(CArsenalManager* this_ptr) {
    reinterpret_cast<CArsenalManagerCpp*>(this_ptr)->~CArsenalManagerCpp();
}

CWeaponDefinition* CArsenalManager_GetWeaponDef(CArsenalManager* manager, uint32_t id) {
    return reinterpret_cast<CArsenalManagerCpp*>(manager)->GetWeaponDef(id);
}

} // extern "C"
