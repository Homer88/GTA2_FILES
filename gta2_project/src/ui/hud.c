/**
 * @file hud.c
 * @brief Реализация функций HUD (Heads-Up Display).
 * 
 * Оригинальный файл: gta2.exe
 * Архитектура: x86 (32-bit)
 */

#include "entities/hud.h"
#include <string.h>
#include <stdio.h>

// ============================================================================
// IMPLEMENTATION
// ============================================================================

void Hud_Init(Hud* self) {
    // old_name: sub_0040XXXX
    // old_var: this = self
    if (!self) return;
    
    self->Money = 0;              // old_var: CashAmount = 0
    self->Health = 100;           // old_var: PlayerHealth = 100
    self->Armor = 0;              // old_var: ArmorValue = 0
    self->WantedLevel = 0;        // old_var: StarsCount = 0
    self->CurrentWeapon = 0;      // old_var: WeaponId = 0
    self->Ammo = 0;               // old_var: AmmoCount = 0
    
    self->ShowMoney = true;       // old_var: bDrawCash = true
    self->ShowHealth = true;      // old_var: bDrawHealth = true
    self->ShowRadar = true;       // old_var: bDrawRadar = true
    self->ShowWanted = true;      // old_var: bDrawStars = true
    
    self->FontPtr = NULL;         // old_var: pFont = NULL
    self->TexturePtr = NULL;      // old_var: pTexture = NULL
    self->RadarZoom = 1.0f;       // old_var: RadarScale = 1.0
    self->RadarAngle = 0.0f;      // old_var: RadarRotation = 0.0
    self->FlashTimer = 0;         // old_var: FlashTime = 0
    self->MessageTimer = 0;       // old_var: MsgDuration = 0
    
    // Очистка очереди сообщений
    Hud_ClearMessages(self);      // old_var: ClearQueue()
}

void Hud_Update(Hud* self, int money, int health, int armor) {
    // old_name: sub_0040YYYY
    // old_var: this = self, a1 = money, a2 = health, a3 = armor
    if (!self) return;
    
    self->Money = money;          // old_var: CashAmount = a1
    self->Health = health;        // old_var: PlayerHealth = a2
    self->Armor = armor;          // old_var: ArmorValue = a3
    
    // Проверка на смерть
    if (self->Health <= 0) {      // old_var: if (PlayerHealth <= 0)
        self->ShowHealth = false; // old_var: bDrawHealth = false
    }
}

void Hud_AddMessage(Hud* self, const char* text, HudColor color, int lifetime) {
    // old_name: sub_0040ZZZZ
    // old_var: this = self, a1 = text, a2 = color, a3 = lifetime
    if (!self || !text) return;   // old_var: if (!this || !a1) return
    
    // Поиск свободного слота
    for (int i = 0; i < 8; i++) { // old_var: for (i = 0; i < 8; i++)
        if (!self->Messages[i].Visible) { // old_var: if (!MessageQueue[i].bVisible)
            strncpy(self->Messages[i].Text, text, 63); // old_var: strcpy(TextBuffer, a1)
            self->Messages[i].Text[63] = '\0';
            self->Messages[i].Color = color;           // old_var: TextColor = a2
            self->Messages[i].Lifetime = lifetime;     // old_var: FramesLeft = a3
            self->Messages[i].Visible = true;          // old_var: bVisible = true
            self->Messages[i].Type = HUD_TEXT_NORMAL;  // old_var: Style = NORMAL
            break;
        }
    }
}

void Hud_Draw(Hud* self) {
    // old_name: sub_0041AAAA
    // old_var: this = self
    if (!self) return;
    
    // Отрисовка денег
    if (self->ShowMoney) {        // old_var: if (bDrawCash)
        // printf("Money: $%d\n", self->Money); // old_var: DrawCash(CashAmount)
    }
    
    // Отрисовка здоровья
    if (self->ShowHealth) {       // old_var: if (bDrawHealth)
        // printf("Health: %d\n", self->Health); // old_var: DrawHealth(PlayerHealth)
    }
    
    // Отрисовка сообщений
    for (int i = 0; i < 8; i++) { // old_var: for (i = 0; i < 8; i++)
        if (self->Messages[i].Visible) { // old_var: if (MessageQueue[i].bVisible)
            // printf("%s\n", self->Messages[i].Text); // old_var: DrawText(MessageQueue[i])
            self->Messages[i].Lifetime--; // old_var: FramesLeft--
            if (self->Messages[i].Lifetime <= 0) { // old_var: if (FramesLeft <= 0)
                self->Messages[i].Visible = false; // old_var: bVisible = false
            }
        }
    }
}

void Hud_SetVisible(Hud* self, bool visible) {
    // old_name: sub_0041BBBB
    // old_var: this = self, a1 = visible
    if (!self) return;
    
    self->ShowMoney = visible;    // old_var: bDrawCash = a1
    self->ShowHealth = visible;   // old_var: bDrawHealth = a1
    self->ShowRadar = visible;    // old_var: bDrawRadar = a1
    self->ShowWanted = visible;   // old_var: bDrawStars = a1
}

void Hud_UpdateRadar(Hud* self, float zoom, float angle) {
    // old_name: sub_0041CCCC
    // old_var: this = self, a1 = zoom, a2 = angle
    if (!self) return;
    
    self->RadarZoom = zoom;       // old_var: RadarScale = a1
    self->RadarAngle = angle;     // old_var: RadarRotation = a2
}

void Hud_ClearMessages(Hud* self) {
    // old_name: sub_0041DDDD
    // old_var: this = self
    if (!self) return;
    
    for (int i = 0; i < 8; i++) { // old_var: for (i = 0; i < 8; i++)
        memset(self->Messages[i].Text, 0, 64); // old_var: memset(TextBuffer, 0)
        self->Messages[i].Visible = false;     // old_var: bVisible = false
        self->Messages[i].Lifetime = 0;        // old_var: FramesLeft = 0
    }
}

void Hud_SetWantedLevel(Hud* self, int level) {
    // old_name: sub_0041EEEE
    // old_var: this = self, a1 = level
    if (!self) return;
    
    if (level < 0) level = 0;     // old_var: if (a1 < 0) a1 = 0
    if (level > 5) level = 5;     // old_var: if (a1 > 5) a1 = 5
    
    self->WantedLevel = level;    // old_var: StarsCount = a1
    self->ShowWanted = (level > 0); // old_var: bDrawStars = (a1 > 0)
}

void Hud_UpdateWeapon(Hud* self, int weaponId, int ammo) {
    // old_name: sub_0041FFFF
    // old_var: this = self, a1 = weaponId, a2 = ammo
    if (!self) return;
    
    self->CurrentWeapon = weaponId; // old_var: WeaponId = a1
    self->Ammo = ammo;              // old_var: AmmoCount = a2
}

void Hud_Flash(Hud* self, int duration) {
    // old_name: sub_00420000
    // old_var: this = self, a1 = duration
    if (!self) return;
    
    self->FlashTimer = duration;  // old_var: FlashTime = a1
}

bool Hud_IsVisible(Hud* self) {
    // old_name: sub_00420111
    // old_var: this = self
    if (!self) return false;
    
    return self->ShowMoney || self->ShowHealth || self->ShowRadar;
    // old_var: return (bDrawCash || bDrawHealth || bDrawRadar)
}

const char* Hud_GetCurrentMessage(Hud* self) {
    // old_name: sub_00420222
    // old_var: this = self
    if (!self) return NULL;
    
    for (int i = 0; i < 8; i++) { // old_var: for (i = 0; i < 8; i++)
        if (self->Messages[i].Visible) { // old_var: if (MessageQueue[i].bVisible)
            return self->Messages[i].Text; // old_var: return MessageQueue[i].TextBuffer
        }
    }
    
    return NULL;
}

void Hud_SetTextColor(Hud* self, HudColor color) {
    // old_name: sub_00420333
    // old_var: this = self, a1 = color
    if (!self) return;
    
    // Установка цвета для следующего сообщения
    // В реальной реализации может быть глобальная переменная или контекст
}

void Hud_Reset(Hud* self) {
    // old_name: sub_00420444
    // old_var: this = self
    if (!self) return;
    
    Hud_Init(self); // old_var: call Init()
}
