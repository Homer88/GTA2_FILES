/**
 * @file hud.h
 * @brief Структуры и функции HUD (Heads-Up Display) - текст, деньги, здоровье, радар.
 * 
 * Оригинальный файл: gta2.exe
 * Архитектура: x86 (32-bit)
 */

#ifndef GTA2_HUD_H
#define GTA2_HUD_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================================
// ENUMS
// ============================================================================

typedef enum HudTextType {
    HUD_TEXT_NORMAL = 0,
    HUD_TEXT_BIG = 1,
    HUD_TEXT_STYLISH = 2,
    HUD_TEXT_NUMBER = 3
} HudTextType; // old_name: eHudTextType

typedef enum HudColor {
    HUD_COLOR_WHITE = 0,
    HUD_COLOR_RED = 1,
    HUD_COLOR_GREEN = 2,
    HUD_COLOR_BLUE = 3,
    HUD_COLOR_YELLOW = 4,
    HUD_COLOR_PURPLE = 5
} HudColor; // old_name: eHudColor

// ============================================================================
// STRUCTS
// ============================================================================

/**
 * @brief Элемент текста на экране
 * Размер: 0x40 байт (предположительно)
 */
typedef struct HudTextElement {
    char Text[64];              // 0x00 - old_var: TextBuffer
    float X;                    // 0x40 - old_var: PosX
    float Y;                    // 0x44 - old_var: PosY
    HudColor Color;             // 0x48 - old_var: TextColor
    HudTextType Type;           // 0x4C - old_var: Style
    int Lifetime;               // 0x50 - old_var: FramesLeft
    bool Visible;               // 0x54 - old_var: bVisible
    // Выравнивание до 0x60 (96 байт) или 0x40? Уточним в тесте.
    // Для GTA 2 часто структуры выровнены по 4 байтам.
    // Пусть будет 0x60 для запаса, если есть скрытые поля.
    char Padding[12];           // 0x55-0x60
} HudTextElement; // old_name: sHudText, old_size: 0x60

/**
 * @brief Основная структура HUD
 * Содержит состояние интерфейса, деньги, здоровье, сообщения.
 * Размер: 0x200 байт (предположительно)
 */
typedef struct Hud {
    int Money;                  // 0x00 - old_var: CashAmount
    int Health;                 // 0x04 - old_var: PlayerHealth
    int Armor;                  // 0x08 - old_var: ArmorValue
    int WantedLevel;            // 0x0C - old_var: StarsCount
    int CurrentWeapon;          // 0x10 - old_var: WeaponId
    int Ammo;                   // 0x14 - old_var: AmmoCount
    
    // Флаги отображения
    bool ShowMoney;             // 0x18 - old_var: bDrawCash
    bool ShowHealth;            // 0x19 - old_var: bDrawHealth
    bool ShowRadar;             // 0x1A - old_var: bDrawRadar
    bool ShowWanted;            // 0x1B - old_var: bDrawStars
    char Padding1[4];           // 0x1C - Выравнивание

    // Сообщения
    HudTextElement Messages[8]; // 0x20 - old_var: MessageQueue (8 * 0x60 = 0x300)
                                // Если структура больше, уменьшим кол-во или размер элемента.
                                // Допустим, тут всего 2 сообщения для экономии места, или указатель.
                                // Попробуем вариант с фиксированным буфером.
    
    // Указатель на шрифт или ресурсы
    void* FontPtr;              // old_var: pFont
    void* TexturePtr;           // old_var: pTexture
    
    // Координаты радара
    float RadarZoom;            // old_var: RadarScale
    float RadarAngle;           // old_var: RadarRotation

    // Временные данные
    int FlashTimer;             // old_var: FlashTime
    int MessageTimer;           // old_var: MsgDuration
} Hud; // old_name: sHud, old_size: 0x??? (будет уточнено в тесте)

// Примечание: Реальный размер структуры зависит от количества сообщений и выравнивания.
// В GTA2 структуры часто упакованы плотно.

// ============================================================================
// FUNCTION PROTOTYPES
// ============================================================================

/**
 * @brief Инициализация HUD
 * old_name: sub_0040XXXX
 */
void Hud_Init(Hud* self);

/**
 * @brief Обновление состояния HUD (деньги, здоровье)
 * old_name: sub_0040YYYY
 */
void Hud_Update(Hud* self, int money, int health, int armor);

/**
 * @brief Добавление текстового сообщения
 * old_name: sub_0040ZZZZ
 */
void Hud_AddMessage(Hud* self, const char* text, HudColor color, int lifetime);

/**
 * @brief Отрисовка HUD
 * old_name: sub_0041AAAA
 */
void Hud_Draw(Hud* self);

/**
 * @brief Скрытие/показ элементов
 * old_name: sub_0041BBBB
 */
void Hud_SetVisible(Hud* self, bool visible);

/**
 * @brief Обновление радара
 * old_name: sub_0041CCCC
 */
void Hud_UpdateRadar(Hud* self, float zoom, float angle);

/**
 * @brief Очистка очереди сообщений
 * old_name: sub_0041DDDD
 */
void Hud_ClearMessages(Hud* self);

/**
 * @brief Установка уровня розыска
 * old_name: sub_0041EEEE
 */
void Hud_SetWantedLevel(Hud* self, int level);

/**
 * @brief Обновление оружия и патронов
 * old_name: sub_0041FFFF
 */
void Hud_UpdateWeapon(Hud* self, int weaponId, int ammo);

/**
 * @brief Мигание элемента (например, при получении урона)
 * old_name: sub_00420000
 */
void Hud_Flash(Hud* self, int duration);

/**
 * @brief Проверка видимости HUD
 * old_name: sub_00420111
 */
bool Hud_IsVisible(Hud* self);

/**
 * @brief Получение текущего сообщения
 * old_name: sub_00420222
 */
const char* Hud_GetCurrentMessage(Hud* self);

/**
 * @brief Настройка цвета текста
 * old_name: sub_00420333
 */
void Hud_SetTextColor(Hud* self, HudColor color);

/**
 * @brief Сброс HUD к значениям по умолчанию
 * old_name: sub_00420444
 */
void Hud_Reset(Hud* self);

#ifdef __cplusplus
}
#endif

#endif // GTA2_HUD_H
