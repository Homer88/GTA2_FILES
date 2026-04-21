/**
 * @file ui.h
 * @brief Структуры и функции пользовательского интерфейса (HUD, Меню, Радар)
 * 
 * Проект: GTA2 Reverse Engineering
 * Соответствует: gta2.exe (IDA Pro symbols: sub_XXXXXX)
 * 
 * Старые имена функций/переменных сохранены в комментариях для импорта в IDA Pro.
 */

#ifndef GTA2_UI_H
#define GTA2_UI_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================================
// ENUMS & CONSTANTS
// ============================================================================

/**
 * @brief Типы элементов интерфейса
 * old_name: enum InterfaceElementType
 */
typedef enum UIElementType {
    UI_ELEMENT_TEXT = 0,
    UI_ELEMENT_NUMBER = 1,
    UI_ELEMENT_RADAR = 2,
    UI_ELEMENT_HEALTH_BAR = 3,
    UI_ELEMENT_WANTED_STARS = 4,
    UI_ELEMENT_WEAPON_ICON = 5,
    UI_ELEMENT_MESSAGE_BOX = 6,
    UI_ELEMENT_MENU = 7
} UIElementType;

/**
 * @brief Состояния меню паузы
 * old_name: enum MenuState
 */
typedef enum MenuState {
    MENU_STATE_CLOSED = 0,
    MENU_STATE_PAUSE = 1,
    MENU_STATE_OPTIONS = 2,
    MENU_STATE_MAP = 3,
    MENU_STATE_STATS = 4
} MenuState;

/**
 * @brief Флаги отображения HUD
 * old_var: HUD_Flags
 */
typedef enum HUDFlags {
    HUD_FLAG_SHOW_MONEY = 0x01,
    HUD_FLAG_SHOW_HEALTH = 0x02,
    HUD_FLAG_SHOW_RADAR = 0x04,
    HUD_FLAG_SHOW_WANTED = 0x08,
    HUD_FLAG_SHOW_WEAPON = 0x10,
    HUD_FLAG_SHOW_MESSAGES = 0x20,
    HUD_FLAG_FULLSCREEN = 0x80
} HUDFlags;

// ============================================================================
// STRUCTURES
// ============================================================================

/**
 * @brief Позиция и размеры элемента UI
 * old_name: struct UIRect
 */
typedef struct UIRect {
    int16_t x;          // old_var: field_0_x
    int16_t y;          // old_var: field_2_y
    uint16_t width;     // old_var: field_4_w
    uint16_t height;    // old_var: field_6_h
} UIRect;

/**
 * @brief Цвет в формате RGBA или индекс палитры
 * old_name: struct UIColor
 */
typedef struct UIColor {
    uint8_t r;          // old_var: field_0_r
    uint8_t g;          // old_var: field_1_g
    uint8_t b;          // old_var: field_2_b
    uint8_t a;          // old_var: field_3_a
} UIColor;

/**
 * @brief Элемент интерфейса (текст, число, иконка)
 * old_name: struct UIElement
 * Size: 0x30 bytes (примерно)
 */
typedef struct UIElement {
    UIElementType type;         // old_var: field_0_type
    bool visible;               // old_var: field_4_visible
    uint8_t padding[3];         // Выравнивание
    UIRect rect;                // old_var: field_8_rect
    UIColor color;              // old_var: field_10_color
    int32_t value;              // old_var: field_14_value (для чисел)
    char text_buffer[64];       // old_var: field_18_text
    void* font_ptr;             // old_var: field_58_font (указатель на шрифт)
    void* texture_ptr;          // old_var: field_5C_texture (для иконок)
} UIElement;

/**
 * @brief Сообщение на экране (временное уведомление)
 * old_name: struct UIMessage
 */
typedef struct UIMessage {
    char text[128];             // old_var: field_0_text
    int32_t timer;              // old_var: field_80_timer (фреймы до исчезновения)
    UIColor color;              // old_var: field_84_color
    bool active;                // old_var: field_88_active
    uint8_t priority;           // old_var: field_89_priority
    uint8_t padding[2];         // Выравнивание
} UIMessage;

/**
 * @brief Радар (мини-карта)
 * old_name: struct Radar
 */
typedef struct Radar {
    UIRect rect;                // old_var: field_0_rect
    float zoom_level;           // old_var: field_10_zoom
    int32_t rotation_angle;     // old_var: field_14_rotation (градусы)
    bool rotate_with_player;    // old_var: field_18_rotate_flag
    uint8_t padding[3];
    void* map_texture_ptr;      // old_var: field_1C_texture
    int32_t blip_count;         // old_var: field_20_blips
    void* blips_array;          // old_var: field_24_blips_ptr (массив меток)
} Radar;

/**
 * @brief Основной контекст HUD (Heads-Up Display)
 * old_name: struct HUDContext
 * Global instance likely at fixed address
 */
typedef struct HUDContext {
    HUDFlags flags;             // old_var: field_0_flags
    uint8_t padding[3];
    
    // Элементы
    UIElement money_element;    // old_var: field_4_money
    UIElement health_element;   // old_var: field_34_health
    UIElement weapon_element;   // old_var: field_64_weapon
    UIElement wanted_element;   // old_var: field_94_wanted
    
    // Радар
    Radar radar;                // old_var: field_C4_radar
    
    // Сообщения
    UIMessage messages[4];      // old_var: field_100_messages (очередь из 4 сообщений)
    int32_t active_message_idx; // old_var: field_240_msg_index
    
    // Меню
    MenuState menu_state;       // old_var: field_244_menu_state
    int32_t selected_item;      // old_var: field_248_selected
} HUDContext;

// Глобальный экземпляр (адрес нужно уточнить в дампе)
// old_name: g_HUD_Context
extern HUDContext g_HUD;

// ============================================================================
// FUNCTION PROTOTYPES
// ============================================================================

/**
 * @brief Инициализация системы интерфейса
 * @param hud_ptr Указатель на контекст HUD
 * old_name: sub_004A1000 (UI_Init)
 */
void UI_Init(HUDContext* hud_ptr);

/**
 * @brief Обновление состояния интерфейса (вызывается каждый кадр)
 * @param hud_ptr Указатель на контекст HUD
 * @param player_ptr Указатель на игрока (для получения данных)
 * old_name: sub_004A1150 (UI_Update)
 */
void UI_Update(HUDContext* hud_ptr, void* player_ptr);

/**
 * @brief Отрисовка всех видимых элементов HUD
 * @param hud_ptr Указатель на контекст HUD
 * old_name: sub_004A1380 (UI_Draw)
 */
void UI_Draw(HUDContext* hud_ptr);

/**
 * @brief Отрисовка конкретного элемента
 * @param element Указатель на элемент
 * old_name: sub_004A1500 (UI_DrawElement)
 */
void UI_DrawElement(UIElement* element);

/**
 * @brief Обновление отображения денег
 * @param hud_ptr Указатель на контекст HUD
 * @param amount Новое значение денег
 * old_name: sub_004A1620 (UI_UpdateMoney)
 */
void UI_UpdateMoney(HUDContext* hud_ptr, int32_t amount);

/**
 * @brief Обновление полоски здоровья
 * @param hud_ptr Указатель на контекст HUD
 * @param current_health Текущее здоровье
 * @param max_health Максимальное здоровье
 * old_name: sub_004A1700 (UI_UpdateHealth)
 */
void UI_UpdateHealth(HUDContext* hud_ptr, int32_t current_health, int32_t max_health);

/**
 * @brief Обновление уровня розыска (звезды)
 * @param hud_ptr Указатель на контекст HUD
 * @param level Уровень розыска (0-6)
 * old_name: sub_004A1850 (UI_UpdateWantedLevel)
 */
void UI_UpdateWantedLevel(HUDContext* hud_ptr, int32_t level);

/**
 * @brief Показать временное сообщение на экране
 * @param hud_ptr Указатель на контекст HUD
 * @param text Текст сообщения
 * @param duration Длительность в кадрах
 * @param color Цвет текста
 * old_name: sub_004A1980 (UI_ShowMessage)
 */
void UI_ShowMessage(HUDContext* hud_ptr, const char* text, int32_t duration, UIColor color);

/**
 * @brief Обновление иконки оружия
 * @param hud_ptr Указатель на контекст HUD
 * @param weapon_id ID текущего оружия
 * @param ammo_count Количество патронов
 * old_name: sub_004A1B00 (UI_UpdateWeapon)
 */
void UI_UpdateWeapon(HUDContext* hud_ptr, int32_t weapon_id, int32_t ammo_count);

/**
 * @brief Открытие меню паузы
 * @param hud_ptr Указатель на контекст HUD
 * old_name: sub_004A1C80 (UI_OpenPauseMenu)
 */
void UI_OpenPauseMenu(HUDContext* hud_ptr);

/**
 * @brief Закрытие меню паузы
 * @param hud_ptr Указатель на контекст HUD
 * old_name: sub_004A1D20 (UI_ClosePauseMenu)
 */
void UI_ClosePauseMenu(HUDContext* hud_ptr);

/**
 * @brief Обработка ввода в меню
 * @param hud_ptr Указатель на контекст HUD
 * @param input_flags Флаги нажатых кнопок
 * old_name: sub_004A1E00 (UI_ProcessMenuInput)
 */
void UI_ProcessMenuInput(HUDContext* hud_ptr, uint32_t input_flags);

/**
 * @brief Отрисовка радара
 * @param radar_ptr Указатель на структуру радара
 * @param player_x Позиция игрока X
 * @param player_y Позиция игрока Y
 * old_name: sub_004A2000 (UI_DrawRadar)
 */
void UI_DrawRadar(Radar* radar_ptr, float player_x, float player_y);

/**
 * @brief Добавление метки (blip) на радар
 * @param radar_ptr Указатель на радар
 * @param x Координата X
 * @param y Координата Y
 * @param type Тип метки (враг, цель, магазин)
 * old_name: sub_004A2250 (UI_AddRadarBlip)
 */
void UI_AddRadarBlip(Radar* radar_ptr, float x, float y, int32_t type);

/**
 * @brief Очистка всех меток на радаре
 * @param radar_ptr Указатель на радар
 * old_name: sub_004A2380 (UI_ClearRadarBlips)
 */
void UI_ClearRadarBlips(Radar* radar_ptr);

/**
 * @brief Установка цвета элемента
 * @param element Указатель на элемент
 * @param r Красный
 * @param g Зеленый
 * @param b Синий
 * @param a Альфа
 * old_name: sub_004A2400 (UI_SetColor)
 */
void UI_SetColor(UIElement* element, uint8_t r, uint8_t g, uint8_t b, uint8_t a);

/**
 * @brief Сброс HUD к значениям по умолчанию
 * @param hud_ptr Указатель на контекст HUD
 * old_name: sub_004A2500 (UI_Reset)
 */
void UI_Reset(HUDContext* hud_ptr);

#ifdef __cplusplus
}
#endif

#endif // GTA2_UI_H
