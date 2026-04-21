/**
 * @file ui.cpp
 * @brief C++ обертки для системы пользовательского интерфейса (HUD, Меню, Радар)
 * 
 * Проект: GTA2 Reverse Engineering
 * Соответствует: gta2.exe (IDA Pro symbols: sub_XXXXXX)
 * 
 * Используются структуры вместо классов.
 * Все функции имеют комментарии со старыми именами (sub_XXXXXX) для импорта в IDA Pro.
 */

#include "ui.h"

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================================
// C++ WRAPPER FUNCTIONS
// Пространство имен для изоляции кода GTA2
// ============================================================================

namespace GTA2 {
namespace UI {

    /**
     * @brief Инициализация HUD
     * old_name: sub_004A1000 (UI_Init_Wrapper)
     */
    void Init(HUDContext* hud) {
        // old_var: arg_hud
        UI_Init(hud);
    }

    /**
     * @brief Обновление HUD
     * old_name: sub_004A1150 (UI_Update_Wrapper)
     */
    void Update(HUDContext* hud, void* player) {
        // old_var: arg_hud
        // old_var: arg_player
        UI_Update(hud, player);
    }

    /**
     * @brief Отрисовка HUD
     * old_name: sub_004A1380 (UI_Draw_Wrapper)
     */
    void Draw(HUDContext* hud) {
        // old_var: arg_hud
        UI_Draw(hud);
    }

    /**
     * @brief Обновление денег
     * old_name: sub_004A1620 (UI_UpdateMoney_Wrapper)
     */
    void UpdateMoney(HUDContext* hud, int32_t amount) {
        // old_var: arg_hud
        // old_var: arg_amount
        UI_UpdateMoney(hud, amount);
    }

    /**
     * @brief Обновление здоровья
     * old_name: sub_004A1700 (UI_UpdateHealth_Wrapper)
     */
    void UpdateHealth(HUDContext* hud, int32_t current, int32_t max) {
        // old_var: arg_hud
        // old_var: arg_cur
        // old_var: arg_max
        UI_UpdateHealth(hud, current, max);
    }

    /**
     * @brief Обновление уровня розыска
     * old_name: sub_004A1850 (UI_UpdateWantedLevel_Wrapper)
     */
    void UpdateWantedLevel(HUDContext* hud, int32_t level) {
        // old_var: arg_hud
        // old_var: arg_level
        UI_UpdateWantedLevel(hud, level);
    }

    /**
     * @brief Показать сообщение
     * old_name: sub_004A1980 (UI_ShowMessage_Wrapper)
     */
    void ShowMessage(HUDContext* hud, const char* text, int32_t duration, UIColor color) {
        // old_var: arg_hud
        // old_var: arg_text
        // old_var: arg_duration
        // old_var: arg_color
        UI_ShowMessage(hud, text, duration, color);
    }

    /**
     * @brief Обновление оружия
     * old_name: sub_004A1B00 (UI_UpdateWeapon_Wrapper)
     */
    void UpdateWeapon(HUDContext* hud, int32_t weaponId, int32_t ammo) {
        // old_var: arg_hud
        // old_var: arg_weapon
        // old_var: arg_ammo
        UI_UpdateWeapon(hud, weaponId, ammo);
    }

    /**
     * @brief Открыть меню паузы
     * old_name: sub_004A1C80 (UI_OpenPauseMenu_Wrapper)
     */
    void OpenPauseMenu(HUDContext* hud) {
        // old_var: arg_hud
        UI_OpenPauseMenu(hud);
    }

    /**
     * @brief Закрыть меню паузы
     * old_name: sub_004A1D20 (UI_ClosePauseMenu_Wrapper)
     */
    void ClosePauseMenu(HUDContext* hud) {
        // old_var: arg_hud
        UI_ClosePauseMenu(hud);
    }

    /**
     * @brief Обработка ввода в меню
     * old_name: sub_004A1E00 (UI_ProcessMenuInput_Wrapper)
     */
    void ProcessMenuInput(HUDContext* hud, uint32_t flags) {
        // old_var: arg_hud
        // old_var: arg_flags
        UI_ProcessMenuInput(hud, flags);
    }

    /**
     * @brief Добавить метку на радар
     * old_name: sub_004A2250 (UI_AddRadarBlip_Wrapper)
     */
    void AddRadarBlip(Radar* radar, float x, float y, int32_t type) {
        // old_var: arg_radar
        // old_var: arg_x
        // old_var: arg_y
        // old_var: arg_type
        UI_AddRadarBlip(radar, x, y, type);
    }

    /**
     * @brief Очистить метки радара
     * old_name: sub_004A2380 (UI_ClearRadarBlips_Wrapper)
     */
    void ClearRadarBlips(Radar* radar) {
        // old_var: arg_radar
        UI_ClearRadarBlips(radar);
    }

    /**
     * @brief Сброс HUD
     * old_name: sub_004A2500 (UI_Reset_Wrapper)
     */
    void Reset(HUDContext* hud) {
        // old_var: arg_hud
        UI_Reset(hud);
    }

} // namespace UI
} // namespace GTA2

#ifdef __cplusplus
}
#endif
