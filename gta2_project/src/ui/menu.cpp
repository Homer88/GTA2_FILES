/**
 * @file menu.cpp
 * @brief C++ обертки для функций Menu.
 * 
 * Оригинальный файл: gta2.exe
 * Архитектура: x86 (32-bit)
 * 
 * Примечание: Используем структуры вместо классов.
 */

#include "entities/menu.h"

namespace GTA2 {
namespace UI {

// ============================================================================
// WRAPPER FUNCTIONS
// ============================================================================

void Menu_Init_Wrapper(Menu* self) {
    // old_name: sub_00430000
    // Wrapper for: Menu_Init
    Menu_Init(self);
}

void Menu_Update_Wrapper(Menu* self) {
    // old_name: sub_00430111
    // Wrapper for: Menu_Update
    Menu_Update(self);
}

void Menu_Draw_Wrapper(Menu* self) {
    // old_name: sub_00430222
    // Wrapper for: Menu_Draw
    Menu_Draw(self);
}

void Menu_Open_Wrapper(Menu* self, MenuState state) {
    // old_name: sub_00430333
    // Wrapper for: Menu_Open
    Menu_Open(self, state);
}

void Menu_Close_Wrapper(Menu* self) {
    // old_name: sub_00430444
    // Wrapper for: Menu_Close
    Menu_Close(self);
}

void Menu_AddItem_Wrapper(Menu* self, const char* text, MenuItemType type) {
    // old_name: sub_00430555
    // Wrapper for: Menu_AddItem
    Menu_AddItem(self, text, type);
}

void Menu_ProcessInput_Wrapper(Menu* self, int key, int action) {
    // old_name: sub_00430666
    // Wrapper for: Menu_ProcessInput
    Menu_ProcessInput(self, key, action);
}

void Menu_MoveUp_Wrapper(Menu* self) {
    // old_name: sub_00430777
    // Wrapper for: Menu_MoveUp
    Menu_MoveUp(self);
}

void Menu_MoveDown_Wrapper(Menu* self) {
    // old_name: sub_00430888
    // Wrapper for: Menu_MoveDown
    Menu_MoveDown(self);
}

void Menu_Select_Wrapper(Menu* self) {
    // old_name: sub_00430999
    // Wrapper for: Menu_Select
    Menu_Select(self);
}

void Menu_ChangeValue_Wrapper(Menu* self, int delta) {
    // old_name: sub_00430AAA
    // Wrapper for: Menu_ChangeValue
    Menu_ChangeValue(self, delta);
}

void Menu_Toggle_Wrapper(Menu* self) {
    // old_name: sub_00430BBB
    // Wrapper for: Menu_Toggle
    Menu_Toggle(self);
}

bool Menu_IsOpen_Wrapper(Menu* self) {
    // old_name: sub_00430CCC
    // Wrapper for: Menu_IsOpen
    return Menu_IsOpen(self);
}

MenuItem* Menu_GetSelectedItem_Wrapper(Menu* self) {
    // old_name: sub_00430DDD
    // Wrapper for: Menu_GetSelectedItem
    return Menu_GetSelectedItem(self);
}

void Menu_ClearItems_Wrapper(Menu* self) {
    // old_name: sub_00430EEE
    // Wrapper for: Menu_ClearItems
    Menu_ClearItems(self);
}

void Menu_SetTitle_Wrapper(Menu* self, const char* title) {
    // old_name: sub_00430FFF
    // Wrapper for: Menu_SetTitle
    Menu_SetTitle(self, title);
}

} // namespace UI
} // namespace GTA2
