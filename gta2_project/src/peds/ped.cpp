/**
 * @file ped.cpp
 * @brief C++ wrapper-функции для пешеходов (Ped) в GTA 2.
 * 
 * old_name: gta2.exe/ida pro/gta2.exe.cpp (Ped wrappers)
 * 
 * Использует структуры вместо классов.
 * Все функции находятся в пространстве имен GTA2::Peds.
 * Обертки вызывают соответствующие C функции из ped.c.
 */

#include "entities/ped.h"
#include <cstdint>

extern "C" {
    // Подключаем C функции
    #include "entities/ped.h"
}

namespace GTA2 {
namespace Peds {

// ============================================================================
// Ped - Wrapper функции для C++ кода
// ============================================================================

/**
 * @brief Установка типа поиска для пешехода.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * 
 * @param ped Указатель на структуру Ped.
 * @param type Тип поиска.
 */
void SetSearchType(Ped* ped, SearchType type) {
    Ped__SetSearchType(ped, type);
}

/**
 * @brief Получение типа поиска.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * 
 * @param ped Указатель на структуру Ped.
 * @return Текущий тип поиска.
 */
SearchType GetSearchType(Ped* ped) {
    return Ped__GetSearchType(ped);
}

/**
 * @brief Установка профессии пешехода.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * 
 * @param ped Указатель на структуру Ped.
 * @param occupation Профессия.
 */
void SetOccupation(Ped* ped, ALL_PED occupation) {
    Ped__SetOccupation(ped, occupation);
}

/**
 * @brief Получение профессии.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * 
 * @param ped Указатель на структуру Ped.
 * @return Текущая профессия.
 */
ALL_PED GetOccupation(Ped* ped) {
    return Ped__GetOccupation(ped);
}

/**
 * @brief Получение текущего состояния.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * 
 * @param ped Указатель на структуру Ped.
 * @return Текущее состояние.
 */
PedState GetCurrentState(Ped* ped) {
    return Ped__GetCurrentState(ped);
}

/**
 * @brief Установка текущего состояния.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * 
 * @param ped Указатель на структуру Ped.
 * @param state Новое состояние.
 */
void SetCurrentState(Ped* ped, PedState state) {
    Ped__SetCurrentState(ped, state);
}

/**
 * @brief Получение сохраненного состояния.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * 
 * @param ped Указатель на структуру Ped.
 * @return Сохраненное состояние.
 */
PedState GetSavedState(Ped* ped) {
    return Ped__GetSavedState(ped);
}

/**
 * @brief Установка сохраненного состояния.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * 
 * @param ped Указатель на структуру Ped.
 * @param state Сохраняемое состояние.
 */
void SetSavedState(Ped* ped, PedState state) {
    Ped__SetSavedState(ped, state);
}

/**
 * @brief Установка здоровья пешехода.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * 
 * @param ped Указатель на структуру Ped.
 * @param health Значение здоровья.
 */
void SetHealth(Ped* ped, int16_t health) {
    Ped__SetHealth(ped, health);
}

/**
 * @brief Получение здоровья пешехода.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * 
 * @param ped Указатель на структуру Ped.
 * @return Текущее здоровье.
 */
int16_t GetHealth(Ped* ped) {
    return Ped__GetHealth(ped);
}

/**
 * @brief Проверка, мертв ли пешеход.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * 
 * @param ped Указатель на структуру Ped.
 * @return true если мертв, false если жив.
 */
bool IsDead(Ped* ped) {
    return Ped__IsDead(ped) != 0;
}

/**
 * @brief Получение текущей машины пешехода.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * 
 * @param ped Указатель на структуру Ped.
 * @return Указатель на машину или nullptr.
 */
Car* GetCurrentCar(Ped* ped) {
    return Ped__GetCurrentCar(ped);
}

/**
 * @brief Установка связи с машиной.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * 
 * @param ped Указатель на структуру Ped.
 * @param car Указатель на машину.
 */
void SetCar(Ped* ped, Car* car) {
    Ped__SetCar(ped, car);
}

/**
 * @brief Получение целевой машины для входа.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * 
 * @param ped Указатель на структуру Ped.
 * @return Указатель на целевую машину.
 */
Car* GetTargetCarForEnter(Ped* ped) {
    return Ped__GetTargetCarForEnter(ped);
}

/**
 * @brief Установка ремэппинга текстур.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * 
 * @param ped Указатель на структуру Ped.
 * @param remap Тип ремэппинга.
 */
void SetRemap(Ped* ped, Remap remap) {
    Ped__SetRemap(ped, remap);
}

/**
 * @brief Получение ремэппинга текстур.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * 
 * @param ped Указатель на структуру Ped.
 * @return Текущий ремэппинг.
 */
Remap GetRemap(Ped* ped) {
    return Ped__GetRemap(ped);
}

/**
 * @brief Получение выбранного оружия.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * 
 * @param ped Указатель на структуру Ped.
 * @return Указатель на выбранное оружие.
 */
Weapon* GetSelectedWeapon(Ped* ped) {
    return Ped__GetSelectedWeapon(ped);
}

/**
 * @brief Инициализация пешехода (базовая).
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * 
 * @param ped Указатель на структуру Ped.
 */
void Init(Ped* ped) {
    Ped__Init(ped);
}

/**
 * @brief Обновление логики пешехода (AI tick).
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * 
 * @param ped Указатель на структуру Ped.
 */
void Update(Ped* ped) {
    Ped__Update(ped);
}

/**
 * @brief Добавление задачи в очередь пешехода.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * 
 * @param ped Указатель на структуру Ped.
 * @param x Координата X цели.
 * @param y Координата Y цели.
 * @param param Дополнительный параметр.
 * @return true если успешно, false если очередь полна.
 */
bool AddObjective(Ped* ped, uint8_t x, uint8_t y, uint8_t param) {
    return Ped__AddObjective(ped, x, y, param) != 0;
}

/**
 * @brief Очистка очереди задач пешехода.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * 
 * @param ped Указатель на структуру Ped.
 */
void ClearObjectives(Ped* ped) {
    Ped__ClearObjectives(ped);
}

/**
 * @brief Получение следующей задачи из очереди.
 * 
 * Адрес в IDA Pro: sub_XXXXXX
 * old_name: sub_XXXXXX
 * 
 * @param ped Указатель на структуру Ped.
 * @param out_task Указатель на структуру для вывода задачи.
 * @return true если задача получена, false если очередь пуста.
 */
bool GetNextObjective(Ped* ped, S200* out_task) {
    return Ped__GetNextObjective(ped, out_task) != 0;
}

} // namespace Peds
} // namespace GTA2
