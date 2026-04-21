/**
 * @file mission.cpp
 * @brief C++ обертки для системы миссий и скриптов GTA2
 * 
 * old_file: gta2.exe.cpp (секция миссий)
 * Использует структуры вместо классов.
 * Все функции находятся в пространстве имен GTA2::Missions.
 */

#include "mission.h"

namespace GTA2 {
namespace Missions {

// -----------------------------------------------------------------------------
// Wrapper функции для C++ кода
// -----------------------------------------------------------------------------

/**
 * @brief Инициализация менеджера миссий
 * old_name: sub_00401000
 */
void Init(MissionManager* manager) {
    MissionManager_Init(manager);
}

/**
 * @brief Обновление логики миссий
 * old_name: sub_00401050
 */
void Update(MissionManager* manager, void* player_ptr) {
    MissionManager_Update(manager, player_ptr);
}

/**
 * @brief Запуск миссии
 * old_name: sub_00401120
 */
bool StartMission(MissionManager* manager, int32_t mission_id) {
    return Mission_Start(manager, mission_id);
}

/**
 * @brief Завершение миссии
 * old_name: sub_00401180
 */
void FinishMission(MissionManager* manager, bool success) {
    Mission_Finish(manager, success);
}

/**
 * @brief Проверка цели
 * old_name: sub_00401200
 */
bool CheckObjective(Mission* mission) {
    return Mission_CheckObjective(mission);
}

/**
 * @brief Обработка триггера
 * old_name: sub_00401280
 */
void ProcessTrigger(MissionManager* manager, int32_t event_type, int32_t event_data) {
    Mission_ProcessTrigger(manager, event_type, event_data);
}

/**
 * @brief Ожидание в скрипте
 * old_name: sub_00401300
 */
void Wait(MissionManager* manager, int32_t ticks) {
    Script_Wait(manager, ticks);
}

/**
 * @brief Показ сообщения
 * old_name: sub_00401350
 */
void ShowMessage(int32_t text_id, int32_t duration) {
    Mission_ShowMessage(text_id, duration);
}

/**
 * @brief Добавление цели
 * old_name: sub_004013C0
 */
void AddObjective(Mission* mission, ObjectiveType type, int32_t target_id, int32_t required) {
    Mission_AddObjective(mission, type, target_id, required);
}

/**
 * @brief Создание триггера зоны
 * old_name: sub_00401420
 */
void CreateZoneTrigger(MissionManager* manager, int32_t zone_id, bool is_enter, int32_t script_idx) {
    Mission_CreateZoneTrigger(manager, zone_id, is_enter, script_idx);
}

/**
 * @brief Получение статуса
 * old_name: sub_00401480
 */
MissionFlags GetStatus(MissionManager* manager) {
    return Mission_GetStatus(manager);
}

/**
 * @brief Сброс менеджера
 * old_name: sub_004014D0
 */
void Reset(MissionManager* manager) {
    MissionManager_Reset(manager);
}

/**
 * @brief Выполнение команды скрипта
 * old_name: sub_00401550
 */
void ExecuteCommand(MissionManager* manager, int32_t cmd, int32_t p1, int32_t p2) {
    Script_ExecuteCommand(manager, cmd, p1, p2);
}

} // namespace Missions
} // namespace GTA2
