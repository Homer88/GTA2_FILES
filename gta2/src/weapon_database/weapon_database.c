/*
 * File: weapon_database.c
 * Description: Реализация менеджера пула оружия
 * Original Name: Weapon1 -> WeaponDatabase
 * Size: 12252 bytes (0x2FDC)
 */

#include "../../include/entities/weapon_database.h"
#include <stdint.h>
#include <string.h>

// Внешняя функция Construct (из runtime библиотеки игры)
extern void Construct(void* arr, size_t elemSize, size_t count, 
                      void (*ctor)(void*), void (*dtor)(void*));

/**
 * Конструктор WeaponDatabase
 * Анализируется из кода:
 * Construct(this->sWeapon_Arr255, 0xBC, 306, Car::Car, Car::Car_Des);
 * Для оружия: Construct(this->sWeapon_Arr255, 48, 255, Weapon::Weapon, Weapon::Weapon_dec);
 */
WeaponDatabase* WeaponDatabase_Constructor(WeaponDatabase* this) {
    if (!this) return NULL;

    Weapon* sWeapon_Arr255 = this->sWeapon_Arr255;

    // Инициализация массива из 255 элементов оружия
    // Вызов конструктора для каждого элемента
    Construct(sWeapon_Arr255, sizeof(Weapon), 255,
              (void(*)(void*))Weapon_Constructor,
              (void(*)(void*))Weapon_Destructor);

    // Построение связного списка свободных элементов
    // Каждый элемент указывает на следующий через поле NextWeapon (смещение 0x14)
    Weapon* p_NextWeapon = (Weapon*)&sWeapon_Arr255[0].m_NextWeapon;
    int count = 254;

    do {
        // *(DWORD*)&p_NextWeapon->Ammo = &p_NextWeapon->NextWeapon;
        // В коде: *(_DWORD *)&p_NextWeapon->Ammo = &p_NextWeapon->NextWeapon;
        // Это значит: поле Ammo (которое идет после NextWeapon в памяти?) 
        // Нет, в структуре Weapon: NextWeapon по 0x14, Ammo по 0x00.
        // Код ассемблера:
        // p_NextWeapon = (Weapon *)&sWeapon_Arr255->NextWeapon;
        // Значит p_NextWeapon указывает на поле NextWeapon первого элемента.
        // Затем: *(_DWORD *)&p_NextWeapon->Ammo = &p_NextWeapon->NextWeapon;
        // Это странно, т.к. Ammo находится BEFORE NextWeapon.
        // Возможно, это запись адреса следующего элемента в поле, которое следует за NextWeapon?
        // Или это особенность компилятора/декомпилятора.
        
        // Интерпретация: мы создаем список, где каждый элемент указывает на следующий.
        // Используем поле m_NextWeapon для хранения ссылки.
        Weapon* current = (Weapon*)((char*)p_NextWeapon - offsetof(Weapon, m_NextWeapon));
        Weapon* next = current + 1; // Следующий элемент в массиве
        
        if (count > 0) {
            current->m_NextWeapon = next;
        }
        
        p_NextWeapon = (Weapon*)((char*)p_NextWeapon + sizeof(Weapon)); // Переход к NextWeapon след. элемента
        --count;
    } while (count >= 0); // Исправлено условие цикла

    // Последний элемент указывает на NULL
    sWeapon_Arr255[254].m_NextWeapon = 0;

    // Инициализация заголовков
    this->sWeapon = sWeapon_Arr255;          // Указатель на начало массива
    this->NextWeapon = sWeapon_Arr255;       // Голова списка свободных (первый элемент)
    this->field_2FD8 = 0;                    // Счетчик активных (пока 0)

    return this;
}

/**
 * Выделение оружия из пула
 * @param this Указатель на базу данных
 * @return Указатель на выделенное оружие или NULL
 */
Weapon* WeaponDatabase_Allocate(WeaponDatabase* this) {
    if (!this || !this->NextWeapon) return NULL;

    // Берем первый свободный элемент
    Weapon* weapon = this->NextWeapon;
    
    // Обновляем голову списка свободных
    this->NextWeapon = weapon->m_NextWeapon;
    weapon->m_NextWeapon = NULL; // Сброс ссылки

    // Увеличиваем счетчик активных
    this->field_2FD8++;

    // Возвращаем выделенное оружие (оно уже инициализировано конструктором)
    return weapon;
}

/**
 * Освобождение оружия обратно в пул
 * @param this Указатель на базу данных
 * @param weapon Указатель на освобождаемое оружие
 */
void WeaponDatabase_Free(WeaponDatabase* this, Weapon* weapon) {
    if (!this || !weapon) return;

    // Возвращаем в голову списка свободных
    weapon->m_NextWeapon = this->NextWeapon;
    this->NextWeapon = weapon;

    // Уменьшаем счетчик
    if (this->field_2FD8 > 0) {
        this->field_2FD8--;
    }
}

/**
 * Получение количества активных оружий
 * @param this Указатель на базу данных
 * @return Количество активных элементов
 */
int32_t WeaponDatabase_GetActiveCount(WeaponDatabase* this) {
    if (!this) return 0;
    return this->field_2FD8;
}
