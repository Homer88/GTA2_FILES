/**
 * @file car.c
 * @brief C-реализация методов автомобиля (CCar)
 * 
 * Старые имена функций:
 * - Car__Car (0x00426760) -> CCar_Constructor
 * - Car__Car_Des (0x00426860) -> CCar_Destructor
 * - Car__SetHornDefault -> CCar_SetHornDefault
 * - Car__sub_4BF000 (0x004BF000) -> CCar_sub_4BF000
 */

#include "entities/car.h"
#include <string.h>
#include <stdint.h>

// ============================================================================
// ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ (заглушки, требуют реализации)
// ============================================================================

// Внешние функции из других модулей
extern void Turrel_sub_424620(void* this);
extern void Passenger_sub_425450(void* this);
extern void CarLights_Init(void* this);  // sub_420D80
extern void CarDoor_Constructor(void* this);
extern void CarDoor_Destructor(void* this);

/**
 * @brief Универсальная функция Construct для массивов
 * @param array Указатель на массив
 * @param elemSize Размер элемента
 * @param count Количество элементов
 * @param constructor Конструктор
 * @param destructor Деструктор
 */
typedef void (*Constructor_t)(void*);
typedef void (*Destructor_t)(void*);

void Construct(void* array, size_t elemSize, size_t count, 
               Constructor_t constructor, Destructor_t destructor) {
    (void)destructor;  // Не используется в конструкторе
    uint8_t* ptr = (uint8_t*)array;
    for (size_t i = 0; i < count; ++i) {
        constructor(ptr);
        ptr += elemSize;
    }
}

/**
 * @brief Операция битового сдвига влево (bitShiftLeft1)
 * @param pPtr Указатель на указатель
 * @param shift Сдвиг
 */
void bitShiftLeft1(void** pPtr, int shift) {
    if (pPtr && *pPtr) {
        uintptr_t val = (uintptr_t)*pPtr;
        val <<= shift;
        *pPtr = (void*)val;
    }
}

// ============================================================================
// МЕТОДЫ CCar
// ============================================================================

/**
 * @brief Конструктор автомобиля
 * @param this Указатель на экземпляр CCar
 * @return Указатель на инициализированный экземпляр
 * 
 * Адрес: 0x00426760
 */
CCar* CCar_Constructor(CCar* this) {
    if (!this) return NULL;
    
    CCar* pCar = this;
    
    // 1. Инициализация базового класса Turrel
    Turrel_sub_424620(this);
    
    // 2. Инициализация компонента Passenger
    Passenger_sub_425450(&this->passenger_base);
    
    // 3. Инициализация огней
    CarLights_Init(&this->carLights);
    
    // 4. Создание массива из 4 дверей
    Construct(this->doors, 16, 4, 
              (Constructor_t)CarDoor_Constructor, 
              (Destructor_t)CarDoor_Destructor);
    
    // 5. Обнуление полей
    this->Driver = NULL;
    this->Damage = 0;
    this->FireState = 0;
    this->locksDoor = 0;
    this->engineState = BROKEN_DOESNT_WORK;
    this->SearchType = SEARCHTYPE_NO_THREATS;
    this->field_76 = 0;
    this->sirenState = 0;
    this->sirenPhase = 0;
    this->field_A6 = 0;
    this->LastCar = NULL;
    this->CarType = -1;  // MODEL_NUM_CAR_MODELS
    this->CarSprite = NULL;
    this->Player = NULL;
    this->EngineStruct = NULL;
    this->Mask = 0;
    this->ID = 0xFFFF;
    this->TrailerCtrl = 0;
    this->PhysicsBitmask = 0;
    
    // 6. Вызов вспомогательных функций
    CCar_sub_4BF000(this);
    CCar_SetHornDefault(this);
    
    this->field_80 = 0;
    this->trafficCarType = TRAFFIC_0;
    this->field_8D = 0;
    this->lastDamagingPed = NULL;
    this->DamageType = DAMAGE_NONE;
    this->DamageShotTimer = 0;
    this->PlayerId = 0;
    
    // 7. Вычисление field_68 через bitShiftLeft1
    bitShiftLeft1((void**)&pCar, 1);
    this->field_68 = (int32_t)(uintptr_t)pCar;
    
    return this;
}

/**
 * @brief Деструктор автомобиля
 * @param this Указатель на экземпляр CCar
 * @return Указатель на экземпляр
 * 
 * Адрес: 0x00426860
 */
CCar* CCar_Destructor(CCar* this) {
    if (!this) return NULL;
    
    // Вызов деструкторов дверей
    for (int i = 0; i < 4; ++i) {
        CarDoor_Destructor(&this->doors[i]);
    }
    
    // Очистка указателей
    this->Driver = NULL;
    this->CarSprite = NULL;
    this->Player = NULL;
    this->EngineStruct = NULL;
    this->LastCar = NULL;
    this->lastDamagingPed = NULL;
    
    return this;
}

/**
 * @brief Внутренняя функция инициализации
 * @param this Указатель на экземпляр CCar
 * 
 * Адрес: 0x004BF000
 */
void CCar_sub_4BF000(CCar* this) {
    if (!this) return;
    // TODO: Реализовать логику из ассемблера
    // Функция содержит switch/case (jpt_4BF01A)
}

/**
 * @brief Установка параметров гудка по умолчанию
 * @param this Указатель на экземпляр CCar
 */
void CCar_SetHornDefault(CCar* this) {
    if (!this) return;
    // TODO: Реализовать логику из ассемблера
}
