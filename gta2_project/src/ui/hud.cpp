/**
 * @file hud.cpp
 * @brief C++ обертки для функций HUD.
 * 
 * Оригинальный файл: gta2.exe
 * Архитектура: x86 (32-bit)
 * 
 * Примечание: Используем структуры вместо классов.
 */

#include "entities/hud.h"

namespace GTA2 {
namespace UI {

// ============================================================================
// WRAPPER FUNCTIONS
// ============================================================================

void Hud_Init_Wrapper(Hud* self) {
    // old_name: sub_0040XXXX
    // Wrapper for: Hud_Init
    Hud_Init(self);
}

void Hud_Update_Wrapper(Hud* self, int money, int health, int armor) {
    // old_name: sub_0040YYYY
    // Wrapper for: Hud_Update
    Hud_Update(self, money, health, armor);
}

void Hud_AddMessage_Wrapper(Hud* self, const char* text, HudColor color, int lifetime) {
    // old_name: sub_0040ZZZZ
    // Wrapper for: Hud_AddMessage
    Hud_AddMessage(self, text, color, lifetime);
}

void Hud_Draw_Wrapper(Hud* self) {
    // old_name: sub_0041AAAA
    // Wrapper for: Hud_Draw
    Hud_Draw(self);
}

void Hud_SetVisible_Wrapper(Hud* self, bool visible) {
    // old_name: sub_0041BBBB
    // Wrapper for: Hud_SetVisible
    Hud_SetVisible(self, visible);
}

void Hud_UpdateRadar_Wrapper(Hud* self, float zoom, float angle) {
    // old_name: sub_0041CCCC
    // Wrapper for: Hud_UpdateRadar
    Hud_UpdateRadar(self, zoom, angle);
}

void Hud_ClearMessages_Wrapper(Hud* self) {
    // old_name: sub_0041DDDD
    // Wrapper for: Hud_ClearMessages
    Hud_ClearMessages(self);
}

void Hud_SetWantedLevel_Wrapper(Hud* self, int level) {
    // old_name: sub_0041EEEE
    // Wrapper for: Hud_SetWantedLevel
    Hud_SetWantedLevel(self, level);
}

void Hud_UpdateWeapon_Wrapper(Hud* self, int weaponId, int ammo) {
    // old_name: sub_0041FFFF
    // Wrapper for: Hud_UpdateWeapon
    Hud_UpdateWeapon(self, weaponId, ammo);
}

void Hud_Flash_Wrapper(Hud* self, int duration) {
    // old_name: sub_00420000
    // Wrapper for: Hud_Flash
    Hud_Flash(self, duration);
}

bool Hud_IsVisible_Wrapper(Hud* self) {
    // old_name: sub_00420111
    // Wrapper for: Hud_IsVisible
    return Hud_IsVisible(self);
}

const char* Hud_GetCurrentMessage_Wrapper(Hud* self) {
    // old_name: sub_00420222
    // Wrapper for: Hud_GetCurrentMessage
    return Hud_GetCurrentMessage(self);
}

void Hud_SetTextColor_Wrapper(Hud* self, HudColor color) {
    // old_name: sub_00420333
    // Wrapper for: Hud_SetTextColor
    Hud_SetTextColor(self, color);
}

void Hud_Reset_Wrapper(Hud* self) {
    // old_name: sub_00420444
    // Wrapper for: Hud_Reset
    Hud_Reset(self);
}

} // namespace UI
} // namespace GTA2
