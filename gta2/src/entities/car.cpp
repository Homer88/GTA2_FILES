/**
 * @file car.cpp
 * @brief C++ реализация методов автомобиля (CCar)
 * 
 * Старые имена функций:
 * - Car::Car (0x00426760) -> CCar::CCar()
 * - Car::~Car (0x00426860) -> CCar::~CCar()
 * - Car::SetHornDefault -> CCar::SetHornDefault()
 * - Car::sub_4BF000 (0x004BF000) -> CCar::sub_4BF000()
 */

#include "entities/car.h"
#include <cstring>
#include <cstdint>

// ============================================================================
// ВНЕШНИЕ ФУНКЦИИ (заглушки, требуют реализации из ассемблера)
// ============================================================================

extern "C" {
    void Turrel_sub_424620(void* this);
    void Passenger_sub_425450(void* this);
    void CarLights_Init(void* this);  // sub_420D80
    void CarDoor_Constructor(void* this);
    void CarDoor_Destructor(void* this);
    
    /**
     * @brief Универсальная функция Construct для массивов
     */
    void Construct(void* array, size_t elemSize, size_t count, 
                   void (*constructor)(void*), void (*destructor)(void*));
    
    /**
     * @brief Операция битового сдвига влево
     */
    void bitShiftLeft1(void** pPtr, int shift);
}

// ============================================================================
// КЛАСС CCar - РЕАЛИЗАЦИЯ МЕТОДОВ
// ============================================================================

/**
 * @brief Конструктор по умолчанию
 * @return Указатель на инициализированный экземпляр
 * 
 * Адрес: 0x00426760
 */
CCar::CCar() {
    CCar* pCar = this;
    
    // 1. Инициализация базового класса Turrel
    Turrel_sub_424620(this);
    
    // 2. Инициализация компонента Passenger
    Passenger_sub_425450(&this->passenger_base);
    
    // 3. Инициализация огней
    CarLights_Init(&this->carLights);
    
    // 4. Создание массива из 4 дверей
    ::Construct(this->doors, 16, 4, 
                CarDoor_Constructor, 
                CarDoor_Destructor);
    
    // 5. Обнуление полей
    this->Driver = nullptr;
    this->Damage = 0;
    this->FireState = 0;
    this->locksDoor = 0;
    this->engineState = BROKEN_DOESNT_WORK;
    this->SearchType = SEARCHTYPE_NO_THREATS;
    this->field_76 = 0;
    this->sirenState = 0;
    this->sirenPhase = 0;
    this->field_A6 = 0;
    this->LastCar = nullptr;
    this->CarType = -1;  // MODEL_NUM_CAR_MODELS
    this->CarSprite = nullptr;
    this->Player = nullptr;
    this->EngineStruct = nullptr;
    this->Mask = 0;
    this->ID = 0xFFFF;
    this->TrailerCtrl = 0;
    this->PhysicsBitmask = 0;
    
    // 6. Вызов вспомогательных функций
    this->sub_4BF000();
    this->SetHornDefault();
    
    this->field_80 = 0;
    this->trafficCarType = TRAFFIC_0;
    this->field_8D = 0;
    this->lastDamagingPed = nullptr;
    this->DamageType = DAMAGE_NONE;
    this->DamageShotTimer = 0;
    this->PlayerId = 0;
    
    // 7. Вычисление field_68 через bitShiftLeft1
    ::bitShiftLeft1(reinterpret_cast<void**>(&pCar), 1);
    this->field_68 = static_cast<int32_t>(reinterpret_cast<uintptr_t>(pCar));
}

/**
 * @brief Деструктор
 * 
 * Адрес: 0x00426860
 */
CCar::~CCar() {
    // Вызов деструкторов дверей
    for (int i = 0; i < 4; ++i) {
        CarDoor_Destructor(&this->doors[i]);
    }
    
    // Очистка указателей
    this->Driver = nullptr;
    this->CarSprite = nullptr;
    this->Player = nullptr;
    this->EngineStruct = nullptr;
    this->LastCar = nullptr;
    this->lastDamagingPed = nullptr;
}

/**
 * @brief Внутренняя функция инициализации
 * 
 * Адрес: 0x004BF000
 */
void CCar::sub_4BF000() {
    // TODO: Реализовать логику из ассемблера
    // Функция содержит switch/case (jpt_4BF01A)
}

/**
 * @brief Установка параметров гудка по умолчанию
 */
void CCar::SetHornDefault() {
    // TODO: Реализовать логику из ассемблера
}

// ============================================================================
// СТАТИЧЕСКАЯ ПРОВЕРКА РАЗМЕРА
// ============================================================================

static_assert(sizeof(CCar) == 0xBC, "CCar size must be 0xBC (188 bytes)");
