/**
 * @file player.cpp
 * @brief C++ обертки для функций игрока (Player) GTA2
 * 
 * old_file: gta2.exe.c
 * Использует структуры вместо классов, extern "C" для линковки с C
 */

#include <cstdint>

extern "C" {
#include "player.h"
}

namespace GTA2 {
namespace Player {

// ============================================================================
// C++ ОБЕРТКИ ДЛЯ ФУНКЦИЙ ИГРОКА
// ============================================================================

/**
 * @brief Инициализация игрока
 * old_name: sub_004A1200
 */
void Init(struct Player* player, struct Ped* ped_ptr) {
    Player_Init(player, ped_ptr);
}

/**
 * @brief Обновление состояния игрока
 * old_name: sub_004A1250
 */
void Update(struct Player* player) {
    Player_Update(player);
}

/**
 * @brief Посадка в транспорт
 * old_name: sub_004A1300
 */
void EnterVehicle(struct Player* player, struct BaseCar* vehicle) {
    Player_EnterVehicle(player, vehicle);
}

/**
 * @brief Выход из транспорта
 * old_name: sub_004A1380
 */
void ExitVehicle(struct Player* player) {
    Player_ExitVehicle(player);
}

/**
 * @brief Нанесение урона
 * old_name: sub_004A1400
 */
void TakeDamage(struct Player* player, int32_t damageAmount) {
    Player_TakeDamage(player, damageAmount);
}

/**
 * @brief Добавление денег
 * old_name: sub_004A1480
 */
void AddMoney(struct Player* player, int32_t amount) {
    Player_AddMoney(player, amount);
}

/**
 * @brief Установка уровня розыска
 * old_name: sub_004A1500
 */
void SetWantedLevel(struct Player* player, int32_t level) {
    Player_SetWantedLevel(player, level);
}

/**
 * @brief Проверка смерти
 * old_name: sub_004A1580
 */
bool IsDead(struct Player* player) {
    return Player_IsDead(player) != 0;
}

/**
 * @brief Возрождение
 * old_name: sub_004A1600
 */
void Respawn(struct Player* player) {
    Player_Respawn(player);
}

/**
 * @brief Получение здоровья
 * old_name: sub_004A1680
 */
int32_t GetHealth(struct Player* player) {
    return Player_GetHealth(player);
}

/**
 * @brief Установка миссии
 * old_name: sub_004A1700
 */
void SetMission(struct Player* player, int32_t mission_id) {
    Player_SetMission(player, mission_id);
}

/**
 * @brief Обработка ввода
 * old_name: sub_004A1880
 */
void ProcessInput(struct Player* player) {
    Player_ProcessInput(player);
}

/**
 * @brief Переключение оружия
 * old_name: sub_004A1900
 */
void SwitchWeapon(struct Player* player, uint8_t weapon_index) {
    Player_SwitchWeapon(player, weapon_index);
}

/**
 * @brief Основная функция обновления (Game контекст)
 * old_name: sub_003F11A8
 */
struct Player* GameUpdate(void* game_instance) {
    return Game_Game_FUN_003f11a8(game_instance);
}

} // namespace Player
} // namespace GTA2
