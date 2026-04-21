/**
 * @file menu.c
 * @brief Реализация функций Menu - главное меню, пауза, настройки.
 * 
 * Оригинальный файл: gta2.exe
 * Архитектура: x86 (32-bit)
 */

#include "entities/menu.h"
#include <string.h>
#include <stdio.h>

// ============================================================================
// IMPLEMENTATION
// ============================================================================

void Menu_Init(Menu* self) {
    // old_name: sub_00430000
    // old_var: this = self
    if (!self) return;
    
    self->State = MENU_STATE_CLOSED;  // old_var: CurrentState = CLOSED
    self->SelectedIndex = 0;          // old_var: CursorPos = 0
    self->TotalItems = 0;             // old_var: ItemCount = 0
    
    self->IsOpen = false;             // old_var: bVisible = false
    self->IsPaused = false;           // old_var: bGamePaused = false
    
    self->ScrollTimer = 0;            // old_var: ScrollDelay = 0
    self->AnimTimer = 0;              // old_var: AnimationFrame = 0
    
    self->TexturePtr = NULL;          // old_var: pBackground = NULL
    self->FontPtr = NULL;             // old_var: pFont = NULL
    
    Menu_ClearItems(self);            // old_var: call ClearItems()
}

void Menu_Update(Menu* self) {
    // old_name: sub_00430111
    // old_var: this = self
    if (!self || !self->IsOpen) return; // old_var: if (!this || !bVisible) return
    
    // Обновление таймеров
    if (self->ScrollTimer > 0) {    // old_var: if (ScrollDelay > 0)
        self->ScrollTimer--;        // old_var: ScrollDelay--
    }
    
    if (self->AnimTimer > 0) {      // old_var: if (AnimationFrame > 0)
        self->AnimTimer--;          // old_var: AnimationFrame--
    }
}

void Menu_Draw(Menu* self) {
    // old_name: sub_00430222
    // old_var: this = self
    if (!self || !self->IsOpen) return; // old_var: if (!this || !bVisible) return
    
    // Отрисовка фона
    // if (self->TexturePtr) { ... } // old_var: if (pBackground) DrawBackground()
    
    // Отрисовка элементов
    for (int i = 0; i < self->TotalItems; i++) { // old_var: for (i = 0; i < ItemCount; i++)
        MenuItem* item = &self->Items[i];        // old_var: item = &ItemArray[i]
        
        if (item->Enabled) {                     // old_var: if (item.bActive)
            // Выделение выбранного элемента
            if (i == self->SelectedIndex) {      // old_var: if (i == CursorPos)
                // printf("> %s\n", item->Text); // old_var: DrawHighlighted(item.Label)
            } else {
                // printf("  %s\n", item->Text); // old_var: DrawText(item.Label)
            }
            
            // Отрисовка значения для слайдеров
            if (item->Type == MENU_ITEM_SLIDER) { // old_var: if (ItemType == SLIDER)
                // printf("[%d/%d]\n", item->Value, item->MaxValue); // old_var: DrawSlider(item)
            }
        }
    }
}

void Menu_Open(Menu* self, MenuState state) {
    // old_name: sub_00430333
    // old_var: this = self, a1 = state
    if (!self) return;
    
    self->State = state;            // old_var: CurrentState = a1
    self->IsOpen = true;            // old_var: bVisible = true
    self->SelectedIndex = 0;        // old_var: CursorPos = 0
    
    if (state == MENU_STATE_PAUSE) { // old_var: if (CurrentState == PAUSE)
        self->IsPaused = true;       // old_var: bGamePaused = true
    }
}

void Menu_Close(Menu* self) {
    // old_name: sub_00430444
    // old_var: this = self
    if (!self) return;
    
    self->IsOpen = false;           // old_var: bVisible = false
    self->IsPaused = false;         // old_var: bGamePaused = false
    self->State = MENU_STATE_CLOSED; // old_var: CurrentState = CLOSED
}

void Menu_AddItem(Menu* self, const char* text, MenuItemType type) {
    // old_name: sub_00430555
    // old_var: this = self, a1 = text, a2 = type
    if (!self || self->TotalItems >= 16) return; // old_var: if (!this || ItemCount >= 16) return
    
    MenuItem* item = &self->Items[self->TotalItems]; // old_var: item = &ItemArray[ItemCount]
    
    strncpy(item->Text, text, 31);  // old_var: strcpy(item.Label, a1)
    item->Text[31] = '\0';
    item->Type = type;              // old_var: item.ItemType = a2
    item->Value = 0;                // old_var: item.CurrentValue = 0
    item->MinValue = 0;             // old_var: item.Min = 0
    item->MaxValue = 100;           // old_var: item.Max = 100
    item->Enabled = true;           // old_var: item.bActive = true
    item->Selected = false;         // old_var: item.bHighlighted = false
    
    self->TotalItems++;             // old_var: ItemCount++
}

void Menu_ProcessInput(Menu* self, int key, int action) {
    // old_name: sub_00430666
    // old_var: this = self, a1 = key, a2 = action
    if (!self || !self->IsOpen) return; // old_var: if (!this || !bVisible) return
    
    // Обработка навигации
    if (action == 1) {              // old_var: if (a2 == KEY_UP)
        Menu_MoveUp(self);          // old_var: call MoveUp()
    } else if (action == 2) {       // old_var: else if (a2 == KEY_DOWN)
        Menu_MoveDown(self);        // old_var: call MoveDown()
    } else if (action == 3) {       // old_var: else if (a2 == KEY_ENTER)
        Menu_Select(self);          // old_var: call Select()
    } else if (action == 4) {       // old_var: else if (a2 == KEY_LEFT)
        Menu_ChangeValue(self, -1); // old_var: call ChangeValue(-1)
    } else if (action == 5) {       // old_var: else if (a2 == KEY_RIGHT)
        Menu_ChangeValue(self, 1);  // old_var: call ChangeValue(1)
    }
}

void Menu_MoveUp(Menu* self) {
    // old_name: sub_00430777
    // old_var: this = self
    if (!self || self->ScrollTimer > 0) return; // old_var: if (!this || ScrollDelay > 0) return
    
    if (self->SelectedIndex > 0) {  // old_var: if (CursorPos > 0)
        self->SelectedIndex--;      // old_var: CursorPos--
    } else {
        self->SelectedIndex = self->TotalItems - 1; // old_var: CursorPos = ItemCount - 1
    }
    
    self->ScrollTimer = 10;         // old_var: ScrollDelay = 10
}

void Menu_MoveDown(Menu* self) {
    // old_name: sub_00430888
    // old_var: this = self
    if (!self || self->ScrollTimer > 0) return; // old_var: if (!this || ScrollDelay > 0) return
    
    if (self->SelectedIndex < self->TotalItems - 1) { // old_var: if (CursorPos < ItemCount - 1)
        self->SelectedIndex++;      // old_var: CursorPos++
    } else {
        self->SelectedIndex = 0;    // old_var: CursorPos = 0
    }
    
    self->ScrollTimer = 10;         // old_var: ScrollDelay = 10
}

void Menu_Select(Menu* self) {
    // old_name: sub_00430999
    // old_var: this = self
    if (!self || self->SelectedIndex >= self->TotalItems) return; // old_var: if (!this || CursorPos >= ItemCount) return
    
    MenuItem* item = &self->Items[self->SelectedIndex]; // old_var: item = &ItemArray[CursorPos]
    
    if (!item->Enabled) return;     // old_var: if (!item.bActive) return
    
    if (item->Type == MENU_ITEM_TOGGLE) { // old_var: if (ItemType == TOGGLE)
        Menu_Toggle(self);          // old_var: call Toggle()
    } else if (item->Type == MENU_ITEM_ACTION) { // old_var: else if (ItemType == ACTION)
        // Выполнение действия
        // old_var: ExecuteAction(item)
    }
}

void Menu_ChangeValue(Menu* self, int delta) {
    // old_name: sub_00430AAA
    // old_var: this = self, a1 = delta
    if (!self || self->SelectedIndex >= self->TotalItems) return; // old_var: if (!this || CursorPos >= ItemCount) return
    
    MenuItem* item = &self->Items[self->SelectedIndex]; // old_var: item = &ItemArray[CursorPos]
    
    if (item->Type != MENU_ITEM_SLIDER) return; // old_var: if (ItemType != SLIDER) return
    
    item->Value += delta;           // old_var: CurrentValue += a1
    
    // Ограничение диапазона
    if (item->Value < item->MinValue) { // old_var: if (CurrentValue < Min)
        item->Value = item->MinValue;   // old_var: CurrentValue = Min
    }
    if (item->Value > item->MaxValue) { // old_var: if (CurrentValue > Max)
        item->Value = item->MaxValue;   // old_var: CurrentValue = Max
    }
}

void Menu_Toggle(Menu* self) {
    // old_name: sub_00430BBB
    // old_var: this = self
    if (!self || self->SelectedIndex >= self->TotalItems) return; // old_var: if (!this || CursorPos >= ItemCount) return
    
    MenuItem* item = &self->Items[self->SelectedIndex]; // old_var: item = &ItemArray[CursorPos]
    
    if (item->Type != MENU_ITEM_TOGGLE) return; // old_var: if (ItemType != TOGGLE) return
    
    item->Value = !item->Value;     // old_var: CurrentValue = !CurrentValue
}

bool Menu_IsOpen(Menu* self) {
    // old_name: sub_00430CCC
    // old_var: this = self
    if (!self) return false;
    
    return self->IsOpen;            // old_var: return bVisible
}

MenuItem* Menu_GetSelectedItem(Menu* self) {
    // old_name: sub_00430DDD
    // old_var: this = self
    if (!self || self->SelectedIndex >= self->TotalItems) return NULL; // old_var: if (!this || CursorPos >= ItemCount) return NULL
    
    return &self->Items[self->SelectedIndex]; // old_var: return &ItemArray[CursorPos]
}

void Menu_ClearItems(Menu* self) {
    // old_name: sub_00430EEE
    // old_var: this = self
    if (!self) return;
    
    for (int i = 0; i < 16; i++) {  // old_var: for (i = 0; i < 16; i++)
        memset(self->Items[i].Text, 0, 32); // old_var: memset(item.Label, 0)
        self->Items[i].Enabled = false;     // old_var: item.bActive = false
        self->Items[i].Selected = false;    // old_var: item.bHighlighted = false
    }
    
    self->TotalItems = 0;           // old_var: ItemCount = 0
    self->SelectedIndex = 0;        // old_var: CursorPos = 0
}

void Menu_SetTitle(Menu* self, const char* title) {
    // old_name: sub_00430FFF
    // old_var: this = self, a1 = title
    if (!self || !title) return;    // old_var: if (!this || !a1) return
    
    // В реальной реализации может быть отдельное поле для заголовка
    // old_var: SetWindowTitle(a1) или DrawTitle(a1)
}
