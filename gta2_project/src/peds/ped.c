/**
 * @file ped.c
 * @brief Реализация функций пешеходов (Ped) для GTA 2.
 * 
 * old_name: gta2.exe/ida pro/gta2.exe.c (Ped functions)
 * 
 * Все функции используют структуры вместо классов.
 * Для использования в C++ см. ped.cpp (wrapper-функции).
 */

#include "entities/ped.h"
#include <stdint.h>
#include <string.h>

// ============================================================================
// Ped - Функции управления состоянием и свойствами
// ============================================================================

/**
 * @brief Установка типа поиска для пешехода.
 * 
 * Адрес в IDA Pro: sub_XXXXXX (требуется уточнение)
 * old_name: sub_XXXXXX
 * old_var: this, type
 * 
 * @param this Указатель на структуру Ped.
 * @param type Тип поиска (SEARCH_NONE, SEARCH_ENEMY, etc).
 */
void Ped__SetSearchType(struct Ped* this, SearchType type) {
    if (!this) return;
    // old_var: this->SearchType
    this->SearchType = type;
}

/**
 * @brief Получение типа поиска.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * 
 * @param this Указатель на структуру Ped.
 * @return Текущий тип поиска.
 */
SearchType Ped__GetSearchType(struct Ped* this) {
    if (!this) return SEARCH_NONE;
    // old_var: this->SearchType
    return this->SearchType;
}

/**
 * @brief Установка профессии пешехода.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * old_var: this, occupation
 * 
 * @param this Указатель на структуру Ped.
 * @param occupation Профессия (OCCUPATION_CIVILIAN, OCCUPATION_COP, etc).
 */
void Ped__SetOccupation(struct Ped* this, ALL_PED occupation) {
    if (!this) return;
    // old_var: this->Occupation
    this->Occupation = occupation;
}

/**
 * @brief Получение профессии.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * 
 * @param this Указатель на структуру Ped.
 * @return Текущая профессия.
 */
ALL_PED Ped__GetOccupation(struct Ped* this) {
    if (!this) return OCCUPATION_CIVILIAN;
    // old_var: this->Occupation
    return this->Occupation;
}

/**
 * @brief Получение текущего состояния.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * 
 * @param this Указатель на структуру Ped.
 * @return Текущее состояние (PED_STATE_IDLE, PED_STATE_WALK, etc).
 */
PedState Ped__GetCurrentState(struct Ped* this) {
    if (!this) return PED_STATE_IDLE;
    // old_var: this->CurrentState
    return this->CurrentState;
}

/**
 * @brief Установка текущего состояния.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * old_var: this, state
 * 
 * @param this Указатель на структуру Ped.
 * @param state Новое состояние.
 */
void Ped__SetCurrentState(struct Ped* this, PedState state) {
    if (!this) return;
    // old_var: this->CurrentState
    this->CurrentState = state;
}

/**
 * @brief Получение сохраненного состояния.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * 
 * @param this Указатель на структуру Ped.
 * @return Сохраненное состояние.
 */
PedState Ped__GetSavedState(struct Ped* this) {
    if (!this) return PED_STATE_IDLE;
    // old_var: this->SavedState
    return this->SavedState;
}

/**
 * @brief Установка сохраненного состояния.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * old_var: this, state
 * 
 * @param this Указатель на структуру Ped.
 * @param state Сохраняемое состояние.
 */
void Ped__SetSavedState(struct Ped* this, PedState state) {
    if (!this) return;
    // old_var: this->SavedState
    this->SavedState = state;
}

/**
 * @brief Установка здоровья пешехода.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * old_var: this, health
 * 
 * @param this Указатель на структуру Ped.
 * @param health Значение здоровья.
 */
void Ped__SetHealth(struct Ped* this, int16_t health) {
    if (!this) return;
    // old_var: this->Health
    this->Health = health;
}

/**
 * @brief Получение здоровья пешехода.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * 
 * @param this Указатель на структуру Ped.
 * @return Текущее здоровье.
 */
int16_t Ped__GetHealth(struct Ped* this) {
    if (!this) return 0;
    // old_var: this->Health
    return this->Health;
}

/**
 * @brief Проверка, мертв ли пешеход.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * 
 * @param this Указатель на структуру Ped.
 * @return 1 если мертв, 0 если жив.
 */
int Ped__IsDead(struct Ped* this) {
    if (!this) return 0;
    // old_var: this->Flags & PED_FLAG_IS_DEAD
    return (this->Flags & PED_FLAG_IS_DEAD) ? 1 : 0;
}

/**
 * @brief Получение текущей машины пешехода.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * 
 * @param this Указатель на структуру Ped.
 * @return Указатель на машину или NULL.
 */
struct Car* Ped__GetCurrentCar(struct Ped* this) {
    if (!this) return NULL;
    // old_var: this->CarCurrent
    return this->CarCurrent;
}

/**
 * @brief Установка связи с машиной.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * old_var: this, car
 * 
 * @param this Указатель на структуру Ped.
 * @param car Указатель на машину.
 */
void Ped__SetCar(struct Ped* this, struct Car* car) {
    if (!this) return;
    // old_var: this->Car
    this->Car = car;
}

/**
 * @brief Получение целевой машины для входа.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * 
 * @param this Указатель на структуру Ped.
 * @return Указатель на целевую машину.
 */
struct Car* Ped__GetTargetCarForEnter(struct Ped* this) {
    if (!this) return NULL;
    // old_var: this->TargetCarForEnter
    return this->TargetCarForEnter;
}

/**
 * @brief Установка ремэппинга текстур.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * old_var: this, remap
 * 
 * @param this Указатель на структуру Ped.
 * @param remap Тип ремэппинга (REMAP_NONE, REMAP_RED, etc).
 */
void Ped__SetRemap(struct Ped* this, Remap remap) {
    if (!this) return;
    // old_var: this->Remap
    this->Remap = remap;
}

/**
 * @brief Получение ремэппинга текстур.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * 
 * @param this Указатель на структуру Ped.
 * @return Текущий ремэппинг.
 */
Remap Ped__GetRemap(struct Ped* this) {
    if (!this) return REMAP_NONE;
    // old_var: this->Remap
    return this->Remap;
}

/**
 * @brief Получение выбранного оружия.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * 
 * @param this Указатель на структуру Ped.
 * @return Указатель на выбранное оружие.
 */
struct Weapon* Ped__GetSelectedWeapon(struct Ped* this) {
    if (!this) return NULL;
    // old_var: this->SelectedWeapon
    return this->SelectedWeapon;
}

/**
 * @brief Инициализация пешехода (базовая).
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * old_var: this
 * 
 * @param this Указатель на структуру Ped.
 */
void Ped__Init(struct Ped* this) {
    if (!this) return;
    
    // old_var: memset(this, 0, sizeof(Ped))
    memset(this, 0, sizeof(Ped));
    
    // old_var: this->Health = 100
    this->Health = 100;
    
    // old_var: this->State = PED_STATE_IDLE
    this->State = PED_STATE_IDLE;
    
    // old_var: this->CurrentState = PED_STATE_IDLE
    this->CurrentState = PED_STATE_IDLE;
    
    // old_var: this->SavedState = PED_STATE_IDLE
    this->SavedState = PED_STATE_IDLE;
    
    // old_var: this->Occupation = OCCUPATION_CIVILIAN
    this->Occupation = OCCUPATION_CIVILIAN;
    
    // old_var: this->SearchType = SEARCH_NONE
    this->SearchType = SEARCH_NONE;
    
    // old_var: this->Remap = REMAP_NONE
    this->Remap = REMAP_NONE;
    
    // old_var: this->Flags = PED_FLAG_NONE
    this->Flags = PED_FLAG_NONE;
    
    // old_var: this->Counter = 0
    this->Counter = 0;
    
    // old_var: this->ID = -1
    this->ID = -1;
    
    // old_var: this->PedID = -1
    this->PedID = -1;
}

/**
 * @brief Обновление логики пешехода (AI tick).
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * old_var: this
 * 
 * @param this Указатель на структуру Ped.
 */
void Ped__Update(struct Ped* this) {
    if (!this) return;
    
    // old_var: if (this->Flags & PED_FLAG_IS_DEAD) return
    if (this->Flags & PED_FLAG_IS_DEAD) {
        return;
    }
    
    // Здесь будет основная логика AI
    // old_var: switch (this->CurrentState)
    switch (this->CurrentState) {
        case PED_STATE_IDLE:
            // Логика бездействия
            break;
            
        case PED_STATE_WALK:
            // Логика ходьбы
            break;
            
        case PED_STATE_RUN:
            // Логика бега
            break;
            
        case PED_STATE_SHOOT:
            // Логика стрельбы
            break;
            
        case PED_STATE_ENTER_CAR:
            // Логика входа в машину
            break;
            
        case PED_STATE_EXIT_CAR:
            // Логика выхода из машины
            break;
            
        case PED_STATE_FLEE:
            // Логика бегства
            break;
            
        default:
            break;
    }
}

/**
 * @brief Добавление задачи в очередь пешехода.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * old_var: this, x, y, param
 * 
 * @param this Указатель на структуру Ped.
 * @param x Координата X цели.
 * @param y Координата Y цели.
 * @param param Дополнительный параметр.
 * @return 1 если успешно, 0 если очередь полна.
 */
int Ped__AddObjective(struct Ped* this, uint8_t x, uint8_t y, uint8_t param) {
    if (!this) return 0;
    
    // old_var: if (this->Counter >= 50) return 0
    if (this->Counter >= 50) {
        return 0;
    }
    
    // old_var: S200* task = &this->ObjectiveQueue[this->Counter]
    S200* task = &this->ObjectiveQueue[this->Counter];
    
    // old_var: task->X = x
    task->X = x;
    
    // old_var: task->Y = y
    task->Y = y;
    
    // old_var: task->Param = param
    task->Param = param;
    
    // old_var: this->Counter++
    this->Counter++;
    
    return 1;
}

/**
 * @brief Очистка очереди задач пешехода.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * old_var: this
 * 
 * @param this Указатель на структуру Ped.
 */
void Ped__ClearObjectives(struct Ped* this) {
    if (!this) return;
    
    // old_var: memset(this->ObjectiveQueue, 0, sizeof(S200) * 50)
    memset(this->ObjectiveQueue, 0, sizeof(S200) * 50);
    
    // old_var: this->Counter = 0
    this->Counter = 0;
}

/**
 * @brief Получение следующей задачи из очереди.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * 
 * @param this Указатель на структуру Ped.
 * @param out_task Указатель на структуру для вывода задачи.
 * @return 1 если задача получена, 0 если очередь пуста.
 */
int Ped__GetNextObjective(struct Ped* this, S200* out_task) {
    if (!this || !out_task || this->Counter <= 0) {
        return 0;
    }
    
    // old_var: this->Counter--
    this->Counter--;
    
    // old_var: *out_task = this->ObjectiveQueue[this->Counter]
    *out_task = this->ObjectiveQueue[this->Counter];
    
    return 1;
}
