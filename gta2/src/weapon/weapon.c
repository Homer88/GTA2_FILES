/*
 * File: weapon.c
 * Description: Реализация структуры Weapon
 * Original Name: Weapon
 * Size: 48 bytes (0x30)
 * Constructor Address: 0x00426760
 */

#include "../../include/entities/weapon.h"
#include <stdint.h>
#include <string.h>

/**
 * Конструктор Weapon
 * Адрес: 0x00426760
 */
Weapon* Weapon_Constructor(Weapon* this) {
    if (!this) return NULL;

    // Инициализация полей согласно конструктору из ассемблера
    this->m_Ammo = 0;
    this->m_Ped = 0;
    this->m_Car = 0;
    this->m_TimeToReload = 0;
    this->m_SMG = 0;
    this->m_NextWeapon = 0;
    this->m_TypeWeapon = Pistolet; // По умолчанию пистолет
    this->m_ShortVal = 0;
    this->m_field_1C = 0;
    this->m_field_20 = -1; // Инициализируется в -1
    this->m_flags1 = 0;
    this->m_flags2 = 0;
    // m_pad26 не инициализируется явно
    this->m_field28 = 0;
    this->m_SoundWeapon = 0;

    return this;
}

/**
 * Деструктор Weapon
 * Заглушка, т.к. в структуре нет динамических полей
 */
void Weapon_Destructor(Weapon* this) {
    if (!this) return;
    
    // Сброс указателей
    this->m_Ped = 0;
    this->m_Car = 0;
    this->m_NextWeapon = 0;
}

/**
 * Установка владельца оружия
 * @param this Указатель на экземпляр Weapon
 * @param ped Указатель на персонажа (Ped*)
 * @param car Указатель на машину (Car*)
 */
void Weapon_SetOwner(Weapon* this, void* ped, void* car) {
    if (!this) return;
    
    this->m_Ped = ped;
    this->m_Car = car;
}

/**
 * Перезарядка оружия
 * @param this Указатель на экземпляр Weapon
 */
void Weapon_Reload(Weapon* this) {
    if (!this) return;
    
    // Установка таймера перезарядки (значение зависит от типа оружия)
    this->m_TimeToReload = 100; // Пример значения
    // TODO: Реализовать логику установки времени в зависимости от m_TypeWeapon
}

/**
 * Получение текущего количества патронов
 * @param this Указатель на экземпляр Weapon
 * @return Количество патронов
 */
int32_t Weapon_GetAmmo(Weapon* this) {
    if (!this) return 0;
    return this->m_Ammo;
}

/**
 * Установка количества патронов
 * @param this Указатель на экземпляр Weapon
 * @param ammo Новое количество патронов
 */
void Weapon_SetAmmo(Weapon* this, int32_t ammo) {
    if (!this) return;
    this->m_Ammo = ammo;
}
