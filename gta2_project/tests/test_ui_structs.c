/**
 * @file test_ui_structs.c
 * @brief Тест размеров структур UI (HUD и Menu).
 * 
 * Важно: GTA2 - 32-битная игра, поэтому указатели = 4 байта.
 * На 64-битной системе размеры будут отличаться!
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

// Включаем структуры напрямую для теста
#include "entities/hud.h"
#include "entities/menu.h"

// ============================================================================
// MACROS FOR 32-BIT EMULATION
// ============================================================================

// На 64-битной системе sizeof(void*) = 8, но в GTA2 (x86) = 4
// Для точного теста нужно эмулировать 32-битное выравнивание
#ifdef _WIN64
    #warning "Building on 64-bit system. Sizes may differ from GTA2 (32-bit)."
#endif

// ============================================================================
// TEST FUNCTIONS
// ============================================================================

void print_separator() {
    printf("============================================================\n");
}

void test_hud_structs() {
    print_separator();
    printf("HUD STRUCTURES SIZE TEST\n");
    print_separator();
    
    printf("Sizeof(HudColor): %zu bytes\n", sizeof(HudColor));
    printf("Sizeof(HudTextType): %zu bytes\n", sizeof(HudTextType));
    printf("Sizeof(HudTextElement): %zu bytes (expected: 0x60 = 96)\n", sizeof(HudTextElement));
    printf("Sizeof(Hud): %zu bytes\n", sizeof(Hud));
    
    // Проверка смещений полей HudTextElement
    printf("\nHudTextElement Offsets:\n");
    printf("  Text: %zu (expected: 0x00)\n", offsetof(HudTextElement, Text));
    printf("  X: %zu (expected: 0x40)\n", offsetof(HudTextElement, X));
    printf("  Y: %zu (expected: 0x44)\n", offsetof(HudTextElement, Y));
    printf("  Color: %zu (expected: 0x48)\n", offsetof(HudTextElement, Color));
    printf("  Type: %zu (expected: 0x4C)\n", offsetof(HudTextElement, Type));
    printf("  Lifetime: %zu (expected: 0x50)\n", offsetof(HudTextElement, Lifetime));
    printf("  Visible: %zu (expected: 0x54)\n", offsetof(HudTextElement, Visible));
    
    // Проверка смещений полей Hud
    printf("\nHud Offsets:\n");
    printf("  Money: %zu (expected: 0x00)\n", offsetof(Hud, Money));
    printf("  Health: %zu (expected: 0x04)\n", offsetof(Hud, Health));
    printf("  Armor: %zu (expected: 0x08)\n", offsetof(Hud, Armor));
    printf("  WantedLevel: %zu (expected: 0x0C)\n", offsetof(Hud, WantedLevel));
    printf("  CurrentWeapon: %zu (expected: 0x10)\n", offsetof(Hud, CurrentWeapon));
    printf("  Ammo: %zu (expected: 0x14)\n", offsetof(Hud, Ammo));
    printf("  ShowMoney: %zu (expected: 0x18)\n", offsetof(Hud, ShowMoney));
    printf("  ShowHealth: %zu (expected: 0x19)\n", offsetof(Hud, ShowHealth));
    printf("  ShowRadar: %zu (expected: 0x1A)\n", offsetof(Hud, ShowRadar));
    printf("  ShowWanted: %zu (expected: 0x1B)\n", offsetof(Hud, ShowWanted));
    printf("  Messages: %zu\n", offsetof(Hud, Messages));
    printf("  FontPtr: %zu\n", offsetof(Hud, FontPtr));
    printf("  TexturePtr: %zu\n", offsetof(Hud, TexturePtr));
    printf("  RadarZoom: %zu\n", offsetof(Hud, RadarZoom));
    printf("  RadarAngle: %zu\n", offsetof(Hud, RadarAngle));
}

void test_menu_structs() {
    print_separator();
    printf("MENU STRUCTURES SIZE TEST\n");
    print_separator();
    
    printf("Sizeof(MenuState): %zu bytes\n", sizeof(MenuState));
    printf("Sizeof(MenuItemType): %zu bytes\n", sizeof(MenuItemType));
    printf("Sizeof(MenuItem): %zu bytes (expected: 0x34 = 52)\n", sizeof(MenuItem));
    printf("Sizeof(Menu): %zu bytes\n", sizeof(Menu));
    
    // Проверка смещений полей MenuItem
    printf("\nMenuItem Offsets:\n");
    printf("  Text: %zu (expected: 0x00)\n", offsetof(MenuItem, Text));
    printf("  Type: %zu (expected: 0x20)\n", offsetof(MenuItem, Type));
    printf("  Value: %zu (expected: 0x24)\n", offsetof(MenuItem, Value));
    printf("  MinValue: %zu (expected: 0x28)\n", offsetof(MenuItem, MinValue));
    printf("  MaxValue: %zu (expected: 0x2C)\n", offsetof(MenuItem, MaxValue));
    printf("  Enabled: %zu (expected: 0x30)\n", offsetof(MenuItem, Enabled));
    printf("  Selected: %zu (expected: 0x31)\n", offsetof(MenuItem, Selected));
    
    // Проверка смещений полей Menu
    printf("\nMenu Offsets:\n");
    printf("  State: %zu (expected: 0x00)\n", offsetof(Menu, State));
    printf("  SelectedIndex: %zu (expected: 0x04)\n", offsetof(Menu, SelectedIndex));
    printf("  TotalItems: %zu (expected: 0x08)\n", offsetof(Menu, TotalItems));
    printf("  Items: %zu\n", offsetof(Menu, Items));
    printf("  IsOpen: %zu\n", offsetof(Menu, IsOpen));
    printf("  IsPaused: %zu\n", offsetof(Menu, IsPaused));
    printf("  ScrollTimer: %zu\n", offsetof(Menu, ScrollTimer));
    printf("  AnimTimer: %zu\n", offsetof(Menu, AnimTimer));
    printf("  TexturePtr: %zu\n", offsetof(Menu, TexturePtr));
    printf("  FontPtr: %zu\n", offsetof(Menu, FontPtr));
}

void test_function_pointers() {
    print_separator();
    printf("FUNCTION POINTER SIZE TEST\n");
    print_separator();
    
    printf("Sizeof(void*): %zu bytes (GTA2 x86 expects 4)\n", sizeof(void*));
    printf("Sizeof(function pointer): %zu bytes\n", sizeof((void(*)())0));
    
    if (sizeof(void*) == 8) {
        printf("\n[WARNING] Running on 64-bit system!\n");
        printf("GTA2 is a 32-bit game. Pointer sizes will be doubled.\n");
        printf("Structures with pointers will be larger than in original game.\n");
    }
}

// ============================================================================
// MAIN
// ============================================================================

int main() {
    printf("GTA2 UI Structures Size Test\n");
    printf("Testing HUD and Menu structures for accuracy\n\n");
    
    test_function_pointers();
    printf("\n");
    test_hud_structs();
    printf("\n");
    test_menu_structs();
    
    print_separator();
    printf("TEST COMPLETE\n");
    print_separator();
    
    return 0;
}
