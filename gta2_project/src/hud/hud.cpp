/**
 * @file hud.cpp
 * @brief C++ обертки для функций HUD интерфейса GTA 2.
 * 
 * Восстановлено на основе дизассемблера gta2.exe (IDA Pro)
 * 
 * Примечание: Используем структуры вместо классов, как требуется.
 */

#include "entities/hud.h"

namespace GTA2 {
namespace UI {

// ============================================================================
// WRAPPER FUNCTIONS - HUD MAIN
// ============================================================================

Hud* Hud_Constructor_Wrapper(Hud* self) {
    // old_name: Hud::Hud, address: 0x4CAD30
    // Wrapper for: Hud_Constructor
    return Hud_Constructor(self);
}

void Hud_Constructor1_Wrapper(Hud* self) {
    // old_name: Hud::Hud1, address: 0x4C6940
    // Wrapper for: Hud_Constructor1
    Hud_Constructor1(self);
}

void Hud_Destructor_Wrapper(Hud* self, char flags) {
    // old_name: Hud::Hud_des, address: 0x45D3A0
    // Wrapper for: Hud_Destructor
    Hud_Destructor(self, flags);
}

void Hud_sub_4C6960_Wrapper(Hud* self, void* pInfoByTypeCar) {
    // old_name: Hud::sub_4C6960, address: 0x4C6960
    // Wrapper for: Hud_sub_4C6960
    Hud_sub_4C6960(self, pInfoByTypeCar);
}

void Hud_Init_Wrapper(Hud* self) {
    // old_name: Hud::sub_4CAB50, address: 0x4CAB50
    // Wrapper for: Hud_Init
    Hud_Init(self);
}

void Hud_Update_Wrapper(Hud* self) {
    // old_name: Hud::sub_4CAC30, address: 0x4CAC30
    // Wrapper for: Hud_Update
    Hud_Update(self);
}

void Hud_DrawUI_Wrapper(Hud* self) {
    // old_name: Hud::sub_4CA520, address: 0x4CA520
    // Wrapper for: Hud_DrawUI
    Hud_DrawUI(self);
}

void Hud_SetSpeedText_Wrapper(Hud* self) {
    // old_name: Hud::sub_4CABE0, address: 0x4CABE0
    // Wrapper for: Hud_SetSpeedText
    Hud_SetSpeedText(self);
}

int Hud_DrawSprite_Wrapper(Hud* self, int id1, int id2, int X, int Y, char style, const int* mode, int enableAlpha, int alpha) {
    // old_name: Hud::DrawSprite, address: 0x4C94F0
    // Wrapper for: Hud_DrawSprite
    return Hud_DrawSprite(self, id1, id2, X, Y, style, mode, enableAlpha, alpha);
}

int Hud_sub_4C6DE0_Wrapper(Hud* self, void* pButton) {
    // old_name: Hud::sub_4C6DE0, address: 0x4C6DE0
    // Wrapper for: Hud_sub_4C6DE0
    return Hud_sub_4C6DE0(self, pButton);
}

int Hud_HandleKeyboard_Wrapper(Hud* self, int pKeyCode) {
    // old_name: Hud::sub_4C6E20, address: 0x4C6E20
    // Wrapper for: Hud_HandleKeyboard
    return Hud_HandleKeyboard(self, pKeyCode);
}

void Hud_Init_s_Wrapper(Hud* self) {
    // old_name: Hud::sub_4C6D90, address: 0x4C6D90
    // Wrapper for: Hud_Init_s
    Hud_Init_s(self);
}

void Hud_sub_4C6DA0_Wrapper(Hud* self) {
    // old_name: Hud::sub_4C6DA0, address: 0x4C6DA0
    // Wrapper for: Hud_sub_4C6DA0
    Hud_sub_4C6DA0(self);
}

void Hud_Update2_Wrapper(Hud* self) {
    // old_name: Hud::sub_4CA5D0, address: 0x4CA5D0
    // Wrapper for: Hud_Update2
    Hud_Update2(self);
}

// ============================================================================
// WRAPPER FUNCTIONS - HUD ARROW
// ============================================================================

HudArrow* HudArrow_Constructor_Wrapper(HudArrow* self) {
    // old_name: HudArrow::HudArrow, address: 0x4C7080
    // Wrapper for: HudArrow_Constructor
    return HudArrow_Constructor(self);
}

HudArrow* HudArrow_GetHudArrow_Wrapper(HudArrow* self) {
    // old_name: HudArrow::GetHudArrow, address: 0x4CA610
    // Wrapper for: HudArrow_GetHudArrow
    return HudArrow_GetHudArrow(self);
}

void HudArrow_Update_Wrapper(HudArrow* self, int player) {
    // old_name: HudArrow::sub_4CA910, address: 0x4CA910
    // Wrapper for: HudArrow_Update
    HudArrow_Update(self, player);
}

void HudArrow_SetArrowType_Wrapper(HudArrow* self, int type) {
    // old_name: HudArrow::sub_4C5E60, address: 0x4C5E60
    // Wrapper for: HudArrow_SetArrowType
    HudArrow_SetArrowType(self, type);
}

void HudArrow_sub_4C5E70_Wrapper(HudArrow* self, int a2) {
    // old_name: HudArrow::sub_4C5E70, address: 0x4C5E70
    // Wrapper for: HudArrow_sub_4C5E70
    HudArrow_sub_4C5E70(self, a2);
}

void HudArrow_ToggleVisibility_Wrapper(HudArrow* self, int visible) {
    // old_name: HudArrow::sub_4C5EA0, address: 0x4C5EA0
    // Wrapper for: HudArrow_ToggleVisibility
    HudArrow_ToggleVisibility(self, visible);
}

void HudArrow_UpdatePosition_Wrapper(HudArrow* self) {
    // old_name: HudArrow::sub_4C6FB0, address: 0x4C6FB0
    // Wrapper for: HudArrow_UpdatePosition
    HudArrow_UpdatePosition(self);
}

void HudArrow_Init_Wrapper(HudArrow* self) {
    // old_name: HudArrow::sub_4C7040, address: 0x4C7040
    // Wrapper for: HudArrow_Init
    HudArrow_Init(self);
}

void HudArrow_sub_4C7060_Wrapper(HudArrow* self) {
    // old_name: HudArrow::sub_4C7060, address: 0x4C7060
    // Wrapper for: HudArrow_sub_4C7060
    HudArrow_sub_4C7060(self);
}

void HudArrow_Clear_Wrapper(HudArrow* self) {
    // old_name: HudArrow::sub_4C70B0, address: 0x4C70B0
    // Wrapper for: HudArrow_Clear
    HudArrow_Clear(self);
}

void HudArrow_MainLogic_Wrapper(HudArrow* self) {
    // old_name: HudArrow::sub_4C7E60, address: 0x4C7E60
    // Wrapper for: HudArrow_MainLogic
    HudArrow_MainLogic(self);
}

void HudArrow_Draw_Wrapper(HudArrow* self) {
    // old_name: HudArrow::sub_4C7FC0, address: 0x4C7FC0
    // Wrapper for: HudArrow_Draw
    HudArrow_Draw(self);
}

void HudArrow_UpdateRadar_Wrapper(HudArrow* self) {
    // old_name: HudArrow::sub_4C82C0, address: 0x4C82C0
    // Wrapper for: HudArrow_UpdateRadar
    HudArrow_UpdateRadar(self);
}

void HudArrow_ArrowTrace_Wrapper(HudArrow* self) {
    // old_name: HudArrow::sub_4C83D0, address: 0x4C83D0
    // Wrapper for: HudArrow_ArrowTrace
    HudArrow_ArrowTrace(self);
}

void HudArrow_sub_4C8470_Wrapper(HudArrow* self) {
    // old_name: HudArrow::sub_4C8470, address: 0x4C8470
    // Wrapper for: HudArrow_sub_4C8470
    HudArrow_sub_4C8470(self);
}

void HudArrow_sub_4C84C0_Wrapper(HudArrow* self) {
    // old_name: HudArrow::sub_4C84C0, address: 0x4C84C0
    // Wrapper for: HudArrow_sub_4C84C0
    HudArrow_sub_4C84C0(self);
}

void HudArrow_sub_4C8540_Wrapper(HudArrow* self) {
    // old_name: HudArrow::sub_4C8540, address: 0x4C8540
    // Wrapper for: HudArrow_sub_4C8540
    HudArrow_sub_4C8540(self);
}

void HudArrow_sub_4C8590_Wrapper(HudArrow* self) {
    // old_name: HudArrow::sub_4C8590, address: 0x4C8590
    // Wrapper for: HudArrow_sub_4C8590
    HudArrow_sub_4C8590(self);
}

void HudArrow_sub_4C85D0_Wrapper(HudArrow* self) {
    // old_name: HudArrow::sub_4C85D0, address: 0x4C85D0
    // Wrapper for: HudArrow_sub_4C85D0
    HudArrow_sub_4C85D0(self);
}

void HudArrow_sub_4C8620_Wrapper(HudArrow* self) {
    // old_name: HudArrow::sub_4C8620, address: 0x4C8620
    // Wrapper for: HudArrow_sub_4C8620
    HudArrow_sub_4C8620(self);
}

void HudArrow_sub_4C8650_Wrapper(HudArrow* self) {
    // old_name: HudArrow::sub_4C8650, address: 0x4C8650
    // Wrapper for: HudArrow_sub_4C8650
    HudArrow_sub_4C8650(self);
}

void HudArrow_sub_4CA650_Wrapper(HudArrow* self) {
    // old_name: HudArrow::sub_4CA650, address: 0x4CA650
    // Wrapper for: HudArrow_sub_4CA650
    HudArrow_sub_4CA650(self);
}

void HudArrow_Update2_Wrapper(HudArrow* self) {
    // old_name: HudArrow::sub_4CA860, address: 0x4CA860
    // Wrapper for: HudArrow_Update2
    HudArrow_Update2(self);
}

void HudArrow_Update3_Wrapper(HudArrow* self) {
    // old_name: HudArrow::sub_4CA890, address: 0x4CA890
    // Wrapper for: HudArrow_Update3
    HudArrow_Update3(self);
}

int HudArrow_PlayerHandler_Wrapper(HudArrow* self, int a2, int a3, int a4) {
    // old_name: HudArrow::sub_476840, address: 0x476840
    // Wrapper for: HudArrow_PlayerHandler
    return HudArrow_PlayerHandler(self, a2, a3, a4);
}

void HudArrow_SetParam_Wrapper(HudArrow* self, int a2) {
    // old_name: HudArrow::sub_476850, address: 0x476850
    // Wrapper for: HudArrow_SetParam
    HudArrow_SetParam(self, a2);
}

int HudArrow_GetParam_Wrapper(HudArrow* self, int a2) {
    // old_name: HudArrow::sub_476860, address: 0x476860
    // Wrapper for: HudArrow_GetParam
    return HudArrow_GetParam(self, a2);
}

void HudArrow_ResetParam_Wrapper(HudArrow* self, int a2) {
    // old_name: HudArrow::sub_476870, address: 0x476870
    // Wrapper for: HudArrow_ResetParam
    HudArrow_ResetParam(self, a2);
}

// ============================================================================
// WRAPPER FUNCTIONS - ARROW TRACE
// ============================================================================

void ArrowTrace_sub_4C7CC0_Wrapper(ArrowTrace* self) {
    // old_name: ArrowTrace::sub_4C7CC0, address: 0x4C7CC0
    // Wrapper for: ArrowTrace_sub_4C7CC0
    ArrowTrace_sub_4C7CC0(self);
}

void ArrowTrace_MainLogic_Wrapper(ArrowTrace* self) {
    // old_name: ArrowTrace::sub_4C7CF0, address: 0x4C7CF0
    // Wrapper for: ArrowTrace_MainLogic
    ArrowTrace_MainLogic(self);
}

// ============================================================================
// WRAPPER FUNCTIONS - HUD MESSAGE
// ============================================================================

HudMessage* HudMessage_Constructor_Wrapper(HudMessage* self) {
    // old_name: HudMessage::HudMessage, address: 0x4C60A0
    // Wrapper for: HudMessage_Constructor
    return HudMessage_Constructor(self);
}

int HudMessage_ShowBigOnScreenLabel_Wrapper(HudMessage* self, const wchar_t* message, int type) {
    // old_name: HudMessage::ShowBigOnScreenLabel, address: 0x4C5FE0
    // Wrapper for: HudMessage_ShowBigOnScreenLabel
    return HudMessage_ShowBigOnScreenLabel(self, message, type);
}

void HudMessage_sub_4C8A40_Wrapper(HudMessage* self) {
    // old_name: HudMessage::sub_4C8A40, address: 0x4C8A40
    // Wrapper for: HudMessage_sub_4C8A40
    HudMessage_sub_4C8A40(self);
}

// ============================================================================
// WRAPPER FUNCTIONS - HUD BRIEF
// ============================================================================

HudBrief* HudBrief_Constructor_Wrapper(HudBrief* self) {
    // old_name: HudBrief::HudBrief, address: 0x4C6590
    // Wrapper for: HudBrief_Constructor
    return HudBrief_Constructor(self);
}

int HudBrief_ShowMessageToPlayer_Wrapper(HudBrief* self, int timeInSeconds, const char* messageCode) {
    // old_name: HudBrief::ShowMessageToPlayer, address: 0x4C62D0
    // Wrapper for: HudBrief_ShowMessageToPlayer
    return HudBrief_ShowMessageToPlayer(self, timeInSeconds, messageCode);
}

void HudBrief_sub_4C6340_Wrapper(HudBrief* self) {
    // old_name: HudBrief::sub_4C6340, address: 0x4C6340
    // Wrapper for: HudBrief_sub_4C6340
    HudBrief_sub_4C6340(self);
}

void HudBrief_sub_4C6380_Wrapper(HudBrief* self) {
    // old_name: HudBrief::sub_4C6380, address: 0x4C6380
    // Wrapper for: HudBrief_sub_4C6380
    HudBrief_sub_4C6380(self);
}

void HudBrief_MainLogic_Wrapper(HudBrief* self) {
    // old_name: HudBrief::sub_4C6470, address: 0x4C6470
    // Wrapper for: HudBrief_MainLogic
    HudBrief_MainLogic(self);
}

void HudBrief_sub_4C6640_Wrapper(HudBrief* self) {
    // old_name: HudBrief::sub_4C6640, address: 0x4C6640
    // Wrapper for: HudBrief_sub_4C6640
    HudBrief_sub_4C6640(self);
}

int HudBrief_ShowMessageWithParam_Wrapper(HudBrief* self, int type, const char* messageCode, int param) {
    // old_name: HudBrief::sub_4C6690, address: 0x4C6690
    // Wrapper for: HudBrief_ShowMessageWithParam
    return HudBrief_ShowMessageWithParam(self, type, messageCode, param);
}

void HudBrief_sub_4C6770_Wrapper(HudBrief* self) {
    // old_name: HudBrief::sub_4C6770, address: 0x4C6770
    // Wrapper for: HudBrief_sub_4C6770
    HudBrief_sub_4C6770(self);
}

void HudBrief_CheckQueue_Wrapper(HudBrief* self) {
    // old_name: HudBrief::sub_4C6830, address: 0x4C6830
    // Wrapper for: HudBrief_CheckQueue
    HudBrief_CheckQueue(self);
}

void HudBrief_sub_4C9430_Wrapper(HudBrief* self) {
    // old_name: HudBrief::sub_4C9430, address: 0x4C9430
    // Wrapper for: HudBrief_sub_4C9430
    HudBrief_sub_4C9430(self);
}

bool HudBrief_IsMessageVisible_Wrapper(HudBrief* self) {
    // old_name: HudBrief::sub_4768A0, address: 0x4768A0
    // Wrapper for: HudBrief_IsMessageVisible
    return HudBrief_IsMessageVisible(self);
}

// ============================================================================
// WRAPPER FUNCTIONS - S86_7
// ============================================================================

S86_7* S86_7_Constructor_Wrapper(S86_7* self) {
    // old_name: S86_7::S86_7, address: 0x4C6250
    // Wrapper for: S86_7_Constructor
    return S86_7_Constructor(self);
}

int S86_7_PrintText_Wrapper(S86_7* self, const wchar_t* text, int color, int duration, int style, int unknown) {
    // old_name: S86_7::PrintText, address: 0x4C6E70
    // Wrapper for: S86_7_PrintText
    return S86_7_PrintText(self, text, color, duration, style, unknown);
}

// ============================================================================
// WRAPPER FUNCTIONS - OTHER CONSTRUCTORS
// ============================================================================

S86_8* S86_8_Constructor_Wrapper(S86_8* self) {
    // old_name: S86_8::S86_8, address: 0x4C6C70
    // Wrapper for: S86_8_Constructor
    return S86_8_Constructor(self);
}

S86_4* S86_4_Constructor_Wrapper(S86_4* self) {
    // old_name: S86_4::S86_4, address: 0x4C6EE0
    // Wrapper for: S86_4_Constructor
    return S86_4_Constructor(self);
}

S86_5* S86_5_Constructor_Wrapper(S86_5* self) {
    // old_name: S86_5::S86_5, address: 0x4C7350
    // Wrapper for: S86_5_Constructor
    return S86_5_Constructor(self);
}

void S86_5_MainLogic_Wrapper(S86_5* self) {
    // old_name: S86_5::sub_4C73A0, address: 0x4C73A0
    // Wrapper for: S86_5_MainLogic
    S86_5_MainLogic(self);
}

S86_10* S86_10_Constructor_Wrapper(S86_10* self) {
    // old_name: S86_10::S86_10, address: 0x4C7120
    // Wrapper for: S86_10_Constructor
    return S86_10_Constructor(self);
}

void S86_9_sub_4C6A80_Wrapper(void* self, const wchar_t* text) {
    // old_name: S86_9::sub_4C6A80, address: 0x4C6A80
    // Wrapper for: S86_9_sub_4C6A80
    S86_9_sub_4C6A80(self, text);
}

void S86_9_sub_4C9750_Wrapper(void* self, void* player, void* target) {
    // old_name: S86_9::sub_4C9750, address: 0x4C9750
    // Wrapper for: S86_9_sub_4C9750
    S86_9_sub_4C9750(self, player, target);
}

S166* S166_Constructor_Wrapper(S166* self) {
    // old_name: S166::S166, address: 0x4CA660
    // Wrapper for: S166_Constructor
    return S166_Constructor(self);
}

int S166_sub_4C9310_Wrapper(S166* self, int value) {
    // old_name: S166::sub_4C9310, address: 0x4C9310
    // Wrapper for: S166_sub_4C9310
    return S166_sub_4C9310(self, value);
}

int S166_sub_4C93B0_Wrapper(S166* self, int value) {
    // old_name: S166::sub_4C93B0, address: 0x4C93B0
    // Wrapper for: S166_sub_4C93B0
    return S166_sub_4C93B0(self, value);
}

// ============================================================================
// WRAPPER FUNCTIONS - HELPERS
// ============================================================================

void InitField27B8_Wrapper(void* field27B8, char value) {
    // old_name: sub_4C69F0, address: 0x4C69F0
    // Wrapper for: InitField27B8
    InitField27B8(field27B8, value);
}

void sub_4C6A50_Wrapper(void* field27B8) {
    // old_name: sub_4C6A50, address: 0x4C6A50
    // Wrapper for: sub_4C6A50
    sub_4C6A50(field27B8);
}

void sub_4C6AC0_Wrapper(void* data) {
    // old_name: sub_4C6AC0, address: 0x4C6AC0
    // Wrapper for: sub_4C6AC0
    sub_4C6AC0(data);
}

} // namespace UI
} // namespace GTA2
