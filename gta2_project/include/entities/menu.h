/**
 * @file menu.h
 * @brief Структуры и функции Menu - главное меню, пауза, настройки.
 * 
 * Оригинальный файл: gta2.exe
 * Архитектура: x86 (32-bit)
 */

#ifndef GTA2_MENU_H
#define GTA2_MENU_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================================
// ENUMS
// ============================================================================

typedef enum MenuState {
    MENU_STATE_CLOSED = 0,
    MENU_STATE_MAIN = 1,
    MENU_STATE_PAUSE = 2,
    MENU_STATE_OPTIONS = 3,
    MENU_STATE_LOAD = 4,
    MENU_STATE_SAVE = 5
} MenuState; // old_name: eMenuState

typedef enum MenuItemType {
    MENU_ITEM_TEXT = 0,
    MENU_ITEM_SLIDER = 1,
    MENU_ITEM_TOGGLE = 2,
    MENU_ITEM_ACTION = 3
} MenuItemType; // old_name: eMenuItemType

// ============================================================================
// STRUCTS
// ============================================================================

/**
 * @brief Элемент меню
 * Размер: 0x30 байт (предположительно)
 */
typedef struct MenuItem {
    char Text[32];              // 0x00 - old_var: Label
    MenuItemType Type;          // 0x20 - old_var: ItemType
    int Value;                  // 0x24 - old_var: CurrentValue
    int MinValue;               // 0x28 - old_var: Min
    int MaxValue;               // 0x2C - old_var: Max
    bool Enabled;               // 0x30 - old_var: bActive
    bool Selected;              // 0x31 - old_var: bHighlighted
    char Padding[2];            // 0x32-0x34
} MenuItem; // old_name: sMenuItem, old_size: 0x34

/**
 * @brief Основная структура Menu
 * Содержит состояние меню, элементы, навигацию.
 * Размер: 0x100 байт (предположительно)
 */
typedef struct Menu {
    MenuState State;            // 0x00 - old_var: CurrentState
    int SelectedIndex;          // 0x04 - old_var: CursorPos
    int TotalItems;             // 0x08 - old_var: ItemCount
    
    // Элементы меню
    MenuItem Items[16];         // 0x0C - old_var: ItemArray (16 * 0x34 = 0x340)
                                // Если структура слишком большая, возможно это указатель.
                                // Для точности нужен тест размеров.
    
    // Навигация
    bool IsOpen;                // old_var: bVisible
    bool IsPaused;              // old_var: bGamePaused
    char Padding1[2];           // Выравнивание
    
    // Таймеры
    int ScrollTimer;            // old_var: ScrollDelay
    int AnimTimer;              // old_var: AnimationFrame
    
    // Указатели на ресурсы
    void* TexturePtr;           // old_var: pBackground
    void* FontPtr;              // old_var: pFont
} Menu; // old_name: sMenu, old_size: 0x??? (будет уточнено в тесте)

// ============================================================================
// FUNCTION PROTOTYPES
// ============================================================================

/**
 * @brief Инициализация Menu
 * old_name: sub_00430000
 */
void Menu_Init(Menu* self);

/**
 * @brief Обновление состояния Menu
 * old_name: sub_00430111
 */
void Menu_Update(Menu* self);

/**
 * @brief Отрисовка Menu
 * old_name: sub_00430222
 */
void Menu_Draw(Menu* self);

/**
 * @brief Открытие Menu
 * old_name: sub_00430333
 */
void Menu_Open(Menu* self, MenuState state);

/**
 * @brief Закрытие Menu
 * old_name: sub_00430444
 */
void Menu_Close(Menu* self);

/**
 * @brief Добавление элемента
 * old_name: sub_00430555
 */
void Menu_AddItem(Menu* self, const char* text, MenuItemType type);

/**
 * @brief Обработка ввода
 * old_name: sub_00430666
 */
void Menu_ProcessInput(Menu* self, int key, int action);

/**
 * @brief Перемещение курсора вверх
 * old_name: sub_00430777
 */
void Menu_MoveUp(Menu* self);

/**
 * @brief Перемещение курсора вниз
 * old_name: sub_00430888
 */
void Menu_MoveDown(Menu* self);

/**
 * @brief Выбор элемента
 * old_name: sub_00430999
 */
void Menu_Select(Menu* self);

/**
 * @brief Изменение значения (для слайдеров)
 * old_name: sub_00430AAA
 */
void Menu_ChangeValue(Menu* self, int delta);

/**
 * @brief Переключение toggle
 * old_name: sub_00430BBB
 */
void Menu_Toggle(Menu* self);

/**
 * @brief Проверка открытости меню
 * old_name: sub_00430CCC
 */
bool Menu_IsOpen(Menu* self);

/**
 * @brief Получение текущего элемента
 * old_name: sub_00430DDD
 */
MenuItem* Menu_GetSelectedItem(Menu* self);

/**
 * @brief Очистка элементов
 * old_name: sub_00430EEE
 */
void Menu_ClearItems(Menu* self);

/**
 * @brief Установка заголовка
 * old_name: sub_00430FFF
 */
void Menu_SetTitle(Menu* self, const char* title);

#ifdef __cplusplus
}
#endif

#endif // GTA2_MENU_H
