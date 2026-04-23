#pragma once

#ifndef MENU_H
#define MENU_H

#ifndef _WIN32
    // Заглушки для Linux
    typedef void* HWND;
    typedef void* HINSTANCE;
    #define CALLBACK
    typedef int INT;
    typedef unsigned int UINT;
    typedef long LONG;
    typedef unsigned long DWORD;
    typedef long LPARAM;
    typedef long WPARAM;
    typedef long LRESULT;
    typedef unsigned short WORD;
    typedef void* HANDLE;
#else
#include <windows.h>
#endif
#ifndef _WIN32
    // Заглушки для DirectInput
    typedef struct IDirectInputA { void* vtable; } IDirectInputA;
    typedef struct IDirectInputDeviceA { void* vtable; } IDirectInputDeviceA;
    #define DIK_ESCAPE 1
    #define DIK_RETURN 28
    #define DIK_UP 200
    #define DIK_DOWN 208
    #define DIK_LEFT 203
    #define DIK_RIGHT 205
#else
#include <dinput.h>
#endif
#include "Player.h"

#pragma pack(push, 1)

// Forward declarations
struct Menu;
struct MenuPage;
struct MenuEntry;
struct GUI;
struct MenuItem;

/* 60990 */
enum class MenuActions : int8_t
{
    MENUACTION_NONE = 0,
    MENUACTION_CHANGEPAGE = 1,
    MENUACTION_SETPLAYERNAME = 2,
};

/* 61010 */
enum class MenuPic : int8_t
{
    Options = 0,
    Play = 1,
    Quit = 2,
};

/* 61001 */
enum class KeyCode : uint16_t
{
    Key_ESC = 1,
    Key_2 = 2,
    Key_3 = 3,
    Key_4 = 4,
    Key_5 = 5,
    Key_6 = 6,
    Key_7 = 7,
    Key_8 = 8,
    Key_9 = 9,
    Key_10 = 10,
    Key_11 = 11,
    Key_12 = 12,
    Key_13 = 13,
    Key_Backspace = 14,
    Key_Tab = 15,
    Key_Enter = 28,
    Key_Space = 57,
    Key_Up = 200,
    Key_Down = 208,
    Key_Left = 203,
    Key_Right = 205,
};

/* 60994 */
struct KeyState
{
    uint8_t left;
    uint8_t right;
    uint8_t up;
    uint8_t down;
    uint8_t enter;
    uint8_t esc;
    uint8_t del;
};

/* 246 */
struct GUI
{
    char Interface;
    char PlayerArena;
    int16_t X;
    int16_t Y;
    wchar_t Sprite[50];
    int16_t dX;
    int16_t dY;
};

/* 247 */
struct MenuItem
{
    int16_t X;
    int16_t Y;
    bool IndexMenuActions;
    char field_5;
};

/* 245 */
struct MenuEntry
{
    MenuActions MenuAction;      // Тип действия меню
    char field_1;
    int16_t X;                   // Позиция X
    int16_t Y;                   // Позиция Y
    wchar_t TextMenuElement[50]; // Текст элемента меню
    int16_t StringLength;        // Длина строки
    int16_t field_6C;
    uint16_t PlayerSlot;         // Слот игрока
    int16_t Plyrslot1;
    uint8_t Flag[4];             // Флаги
    int32_t field_76;
    int32_t field_7A;
    uint16_t Index;              // Индекс элемента
    int16_t SelectMenu;          // Выбранное меню
};

/* 244 */
struct MenuPage
{
    uint16_t numMenuItems[2];           // Количество элементов меню
    struct MenuEntry MenuEntryArr[10];  // Элементы меню (переименовано для избежания конфликта)
    struct GUI GUIMembers[15];          // GUI элементы (переименовано для избежания конфликта)
    struct MenuItem MenuItemArr[10];    // Пункты меню (переименовано для избежания конфликта)
    uint16_t IndexMenuActions;          // Индекс действий меню
    int16_t SelectActiveElementDefault; // Активный элемент по умолчанию
};

/* 60993 */
enum class FrontendState : int32_t
{
    FRONTEND_NONE = 0,
    FRONTEND_INTRO = 1,
    FRONTEND_MAIN_MENU = 2,
    FRONTEND_LOADING = 3,
    FRONTEND_GAME = 4,
    FRONTEND_PAUSE = 5,
    FRONTEND_OPTIONS = 6,
};

/* 142 */
struct Menu
{
    LPDIRECTINPUTA DirectInput;                 // 0x00 - DirectInput интерфейс
    LPDIRECTINPUTDEVICEA InputDevice;           // 0x04 - Устройство ввода
    char Keys[256];                             // 0x08 - Состояние клавиш
    FrontendState CurrentFrontendState;         // 0x108 - Состояние фронтенда (переименовано)
    char KeyboardAcquired;                      // 0x10C - Клавиатура захвачена
    char FrontendKeysEnabled;                   // 0x10D - Клавиши фронтенда включены
    char field_10E;
    char field_10F;
    int32_t State;                              // 0x110 - Текущее состояние
    int32_t field_114;
    int32_t field_118;
    uint16_t FontStyle;                         // 0x11C - Стиль шрифта
    uint16_t PageNumber;                        // 0x11E - Номер страницы
    int16_t CountPage;                          // 0x120 - Количество страниц
    MenuPage MenuPageArray[17];                 // 0x122 - Страницы меню (17 страниц)
    wchar_t* PlayerName;                        // 0xC990 - Имя игрока
    void* field_C990;
    void* field_C994;
    void* field_C998;
    int16_t field_C99C;
    uint8_t Length;                             // 0xC99E - Длина имени
    char field_C99F;
    int16_t Key;                                // 0xC9A0 - Нажатая клавиша
    int16_t field_C9A2;
    wchar_t MenuItems[9];                       // 0xC9A4 - Пункты меню
    uint8_t CurrentMenuItemsIndex;              // 0xC9B6 - Текущий индекс пунктов
    char field_C9B7;
    KeyState NewKeyState;                       // 0xC9B8 - Новое состояние клавиш
    KeyState OldKeyState;                       // 0xC9BF - Старое состояние клавиш
    char field_C9C6;
    char field_C9C7;
    int32_t TimeToWaitDemoStart;                // 0xC9C8 - Время до начала демо
    char FrameCounter;                          // 0xC9CC - Счетчик кадров
    bool isCheating;                            // 0xC9CD - Чит активен
    char field_C9CE;
    char field_C9CF;
    int32_t TimeToWaitBeforeDemoStart;          // 0xC9D0 - Время ожидания перед демо
    int16_t gapC9D4;
    char field_C9D6[50];                        // 0xC9D6 - Буфер имени профиля
    char field_CA08[10];
    char field_CA12;
    char field_CA13;
    int16_t gapCA13;
    char field_CA15[200];                       // 0xCA15 - Буфер текста
    char field_CADD[50];
    char field_CB0F[50];
    char field_CB41[50];
    char field_CB72[50];
    char field_CBA4[50];
    char field_CBD6[50];
    char field_CC08[50];
    char field_CC3A[50];
    char field_CC6C[50];
    char field_CC9E[50];
    char field_CCD0[50];
    char field_EDB6[50];
    char field_CD36[1000];                      // 0xCD36 - Буфер сохранений
    char field_D11E[1000];
    char field_D506[500];
    char field_D6FA[500];
    char field_D8EE[500];
    char field_DAE2[500];
    char field_DCD6[500];
    char field_DECA[1000];
    char field_E2B2[1000];
    char field_E69A[1000];
    char field_EA82[500];
    char field_EC76[200];
    char field_ED3E[100];
    char field_EDA2[50];
    // S138 S138[8];                            // Пропущено для краткости
    MenuPic MenuPic;                            // 0xEDF4 - Картинка меню
    char field_EDF5;
    int16_t field_EDF6;
    char field_EDF8;
    uint8_t PlayerSlot;                         // 0xEDF9 - Слот игрока
    // S139 S139;                               // Пропущено для краткости
    int16_t field_1EB1C;
    char field_1EB1E;
    char field_1EB1F;
    Player* PlayerPtr;                          // 0x1EB20 - Указатель на игрока
    uint16_t Index;                             // 0x1EB24 - Индекс
    uint8_t PlayerSlotSave[1];                  // 0x1EB26 - Сохраненный слот
    char field_1EB27;
    char field_1EB28;
    char field_1EB29;
    char field_1EB2A;
    char field_1EB2B;
    char field_1EB2C;
    char field_1EB2D;
    // ... остальные поля
};

#pragma pack(pop)

// Проверка размера структуры (примерный размер ~0x1EBxx байт)
// static_assert(sizeof(Menu) == 0x1EB30, "Menu structure size mismatch");

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================================
// Menu - основные функции (адреса из gta2.exe.map)
// ============================================================================

// Конструктор / Деструктор
void Menu__Menu(Menu* this_ptr);                           // 0x00456A60 - Конструктор Menu
void Menu__Menu_Des(Menu* this_ptr);                       // 0x00456D90 - Деструктор Menu
void Menu__Menu_Des1(Menu* this_ptr);                      // 0x00457900 - Альтернативный деструктор

// Инициализация и состояние
void Menu__InitializeState(Menu* this_ptr);                // 0x004587B0 - Инициализация состояния
void Menu__SetFrontendState(Menu* this_ptr, FrontendState state); // 0x00451F60 - Установка состояния фронтенда
void Menu__InitDevice(Menu* this_ptr);                     // 0x00453D80 - Инициализация устройства ввода

// Управление вводом
void Menu__ReleaseInputDevice(Menu* this_ptr);             // 0x00451FB0 - Освобождение устройства ввода
void Menu__ReadDeviceState(Menu* this_ptr);                // 0x00452000 - Чтение состояния устройства
void Menu__SetFrontendKeysEnabled(Menu* this_ptr, char enabled); // 0x00453A30 - Включение/выключение клавиш фронтенда

// Обработка ввода и событий
void Menu__ProcessInput(Menu* this_ptr);                   // 0x00452050 - Обработка ввода
void Menu__HandleKeyPress(Menu* this_ptr);                 // 0x004532B0 - Обработка нажатий клавиш
void Menu__HandleMenuEvent(Menu* this_ptr);                // 0x00457140 - Обработка событий меню
void Menu__ActivateElement(Menu* this_ptr);                // 0x00453310 - Активация элемента меню

// Обновление состояния
void Menu__UpdateState(Menu* this_ptr);                    // 0x00452380 - Обновление состояния меню
void Menu__UpdateGUI(Menu* this_ptr);                      // 0x00453230 - Обновление GUI элементов
void Menu__UpdateMenuFrame(Menu* this_ptr);                // 0x00456E80 - Обновление кадра меню

// Навигация по меню
void Menu__SwitchPage(Menu* this_ptr);                     // 0x004532E0 - Переключение страниц меню
void Menu__NavigatePages(Menu* this_ptr);                  // 0x00457750 - Навигация по страницам
void Menu__GoBack(Menu* this_ptr);                         // 0x004577C0 - Возврат назад

// Работа с текстурами и фоном
void Menu__LoadTexture(Menu* this_ptr, const char* texture_name); // 0x00452D50 - Загрузка текстуры
void Menu__LoadTexturesFromTable(Menu* this_ptr);          // 0x00452E20 - Загрузка текстур из таблицы
void Menu__FindBackground(Menu* this_ptr);                 // 0x00452E80 - Поиск фона
void Menu__DrawMenuBackground(Menu* this_ptr);             // 0x00453020 - Отрисовка фона меню
void Menu__RenderMenu(Menu* this_ptr);                     // 0x00456FB0 - Рендер меню
void Menu__DrawMenuElements(Menu* this_ptr);               // 0x004531E0 - Отрисовка элементов меню

// Работа с текстом и именем игрока
void Menu__SetPlayerName(Menu* this_ptr, const wchar_t* name); // 0x00452490 - Установка имени игрока
void Menu__SetPlayerNameFromMenu(Menu* this_ptr);          // 0x00459540 - Установка имени из меню
wchar_t* Menu__getPlayerProfileName(Menu* this_ptr);       // 0x00452500 - Получение имени профиля
void Menu__ValidatePlayerName(Menu* this_ptr);             // 0x004524C0 - Валидация имени игрока
void Menu__LoadPlayerProfile(Menu* this_ptr);              // 0x00452530 - Загрузка профиля игрока
void Menu__PrintCentr(Menu* this_ptr, const wchar_t* text, int x, int y); // 0x004521B0 - Печать центрированного текста

// Работа с сохранениями
void* Menu__GettingSaveFile(Menu* this_ptr, int slot);     // 0x004528A0 - Получение файла сохранения
void* Menu__GetSaveFile(Menu* this_ptr, int slot);         // 0x00452940 - Получение файла сохранения (альтернатива)
void Menu__CheckSaveFile(Menu* this_ptr);                  // 0x00452810 - Проверка файла сохранения
void Menu__SaveSettings(Menu* this_ptr);                   // 0x004527A0 - Сохранение настроек
void Menu__ApplySettings(Menu* this_ptr);                  // 0x004585F0 - Применение настроек
void Menu__ResetSettings(Menu* this_ptr);                  // 0x00458650 - Сброс настроек

// Видео и интро
void Menu__Intro_BIK(Menu* this_ptr);                      // 0x00452990 - Воспроизведение BIK видео интро
void Menu__PreIntro(Menu* this_ptr);                       // 0x004529C0 - Предварительное интро
void Menu__CloseBinkResources(Menu* this_ptr);             // 0x00481D30 - Закрытие ресурсов Bink

// Меню и страницы
void Menu__LoadTextMenu(Menu* this_ptr);                   // 0x00453E20 - Загрузка текстового меню
void Menu__MenuShowJapanText(Menu* this_ptr);              // 0x00453D40 - Показ японского текста меню
int Menu__FindLastActiveArenaSlot(Menu* this_ptr);         // 0x00453430 - Поиск последнего активного слота арены

// Выбор слота и персонажа
void Menu__SelectPlayerSlot(Menu* this_ptr);               // 0x00453480 - Выбор слота игрока
void Menu__SelectCharacter(Menu* this_ptr);                // 0x00453870 - Выбор персонажа

// Настройки игры
void Menu__SetDifficulty(Menu* this_ptr);                  // 0x00453590 - Настройка сложности
void Menu__ConfigureControls(Menu* this_ptr);              // 0x004538F0 - Настройка управления
void Menu__AudioOptions(Menu* this_ptr);                   // 0x00453930 - Аудио настройки
void Menu__VideoOptions(Menu* this_ptr);                   // 0x00453960 - Видео настройки

// Основное меню и игровые режимы
void Menu__MainMenuLogic(Menu* this_ptr);                  // 0x00455340 - Логика главного меню
void Menu__NewGame(Menu* this_ptr);                        // 0x00455F90 - Новая игра
void Menu__LoadGame(Menu* this_ptr);                       // 0x00455C20 - Загрузка игры
void Menu__SaveGame(Menu* this_ptr);                       // 0x00455C90 - Сохранение игры
void Menu__PauseMenu(Menu* this_ptr);                      // 0x004556A0 - Меню паузы
void Menu__OptionsMenu(Menu* this_ptr);                    // 0x00455850 - Меню опций

// Миссии и карта
void Menu__SelectMission(Menu* this_ptr);                  // 0x00456110 - Выбор миссии
void Menu__WorldMap(Menu* this_ptr);                       // 0x00456180 - Карта мира

// Статистика и награды
void Menu__ShowStatistics(Menu* this_ptr);                 // 0x00456280 - Показать статистику
void Menu__ShowAwards(Menu* this_ptr);                     // 0x004562F0 - Показать награды
void Menu__Gallery(Menu* this_ptr);                        // 0x00456430 - Галерея
void Menu__ShowCredits(Menu* this_ptr);                    // 0x00456460 - Показать титры

// Многопользовательская игра
void Menu__MultiplayerMenu(Menu* this_ptr);                // 0x004565E0 - Меню многопользовательской игры
void Menu__ServerSettings(Menu* this_ptr);                 // 0x00456820 - Настройки сервера
void Menu__PlayerList(Menu* this_ptr);                     // 0x004568C0 - Список игроков

// Выход и очистка
void Menu__ConfirmExit(Menu* this_ptr);                    // 0x00456490 - Подтверждение выхода
void Menu__CleanupResources(Menu* this_ptr);               // 0x00457920 - Очистка ресурсов
void Menu__CheckConditions(Menu* this_ptr);                // 0x00458590 - Проверка условий

// Читы и специальные функции
void Menu__ApplyMoneyCheatIfApplicable(Menu* this_ptr);    // 0x00452200 - Применение чита на деньги
void Menu__PlayerCheat(Menu* this_ptr);                    // 0x004590F0 - Чит игрока

// Специальные функции (требуют дополнительного анализа)
void Menu__SpecialFunction1(Menu* this_ptr);               // 0x00459590 - Специальная функция 1
void Menu__SpecialFunction2(Menu* this_ptr);               // 0x00459660 - Специальная функция 2
void Menu__SpecialFunction3(Menu* this_ptr);               // 0x004597C0 - Специальная функция 3
void Menu__SpecialFunction4(Menu* this_ptr);               // 0x00459E30 - Специальная функция 4
void Menu__SpecialFunction5(Menu* this_ptr);               // 0x0045A010 - Специальная функция 5
void Menu__SpecialFunction6(Menu* this_ptr);               // 0x0045A250 - Специальная функция 6
void Menu__SpecialFunction7(Menu* this_ptr);               // 0x0045A320 - Специальная функция 7

// ============================================================================
// MenuPage - функции страниц меню
// ============================================================================

void MenuPage__MenuPage(MenuPage* this_ptr);               // 0x00455E50 - Конструктор MenuPage
void MenuPage__MenuPage_Des(MenuPage* this_ptr);           // 0x00455EF0 - Деструктор MenuPage
void MenuPage__UpdateIndexToActive(MenuPage* this_ptr);    // 0x00452A50 - Обновление индекса активного элемента
void MenuPage__NextActiveItem(MenuPage* this_ptr);         // 0x00452AA0 - Переход к следующему активному элементу

// ============================================================================
// MenuEntry - функции элементов меню
// ============================================================================

void MenuEntry__MenuEntry(MenuEntry* this_ptr);            // 0x00452B30 - Конструктор MenuEntry
void MenuEntry__MenuEntry_Dec(MenuEntry* this_ptr);        // 0x00452B90 - Деструктор MenuEntry
void MenuEntry__UpdateToPreviousActive(MenuEntry* this_ptr); // 0x00452C30 - Обновление предыдущего активного
void MenuEntry__InitializeEntry(MenuEntry* this_ptr);      // 0x00452BD0 - Инициализация элемента меню

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
// C++ обертки для удобного использования
class CMenu
{
public:
    Menu* ptr;
    
    CMenu() : ptr(nullptr) {}
    explicit CMenu(Menu* p) : ptr(p) {}
    
    // Конструктор / Деструктор
    void Create() { Menu__Menu(ptr); }
    void Destroy() { Menu__Menu_Des(ptr); }
    
    // Инициализация
    void InitializeState() { Menu__InitializeState(ptr); }
    void SetFrontendState(FrontendState state) { Menu__SetFrontendState(ptr, state); }
    void InitDevice() { Menu__InitDevice(ptr); }
    
    // Ввод
    void ReleaseInputDevice() { Menu__ReleaseInputDevice(ptr); }
    void ReadDeviceState() { Menu__ReadDeviceState(ptr); }
    void SetFrontendKeysEnabled(char enabled) { Menu__SetFrontendKeysEnabled(ptr, enabled); }
    
    // Текстуры и фон
    void LoadTexture(const char* name) { Menu__LoadTexture(ptr, name); }
    void LoadTexturesFromTable() { Menu__LoadTexturesFromTable(ptr); }
    void FindBackground() { Menu__FindBackground(ptr); }
    void DrawMenuBackground() { Menu__DrawMenuBackground(ptr); }
    
    // Текст и имя
    void SetPlayerName(const wchar_t* name) { Menu__SetPlayerName(ptr, name); }
    void SetPlayerNameFromMenu() { Menu__SetPlayerNameFromMenu(ptr); }
    wchar_t* GetPlayerProfileName() { return Menu__getPlayerProfileName(ptr); }
    void PrintCentr(const wchar_t* text, int x, int y) { Menu__PrintCentr(ptr, text, x, y); }
    
    // Сохранения
    void* GettingSaveFile(int slot) { return Menu__GettingSaveFile(ptr, slot); }
    void* GetSaveFile(int slot) { return Menu__GetSaveFile(ptr, slot); }
    
    // Видео
    void IntroBIK() { Menu__Intro_BIK(ptr); }
    void PreIntro() { Menu__PreIntro(ptr); }
    void CloseBinkResources() { Menu__CloseBinkResources(ptr); }
    
    // Меню
    void LoadTextMenu() { Menu__LoadTextMenu(ptr); }
    void MenuShowJapanText() { Menu__MenuShowJapanText(ptr); }
    int FindLastActiveArenaSlot() { return Menu__FindLastActiveArenaSlot(ptr); }
    
    // Читы
    void ApplyMoneyCheatIfApplicable() { Menu__ApplyMoneyCheatIfApplicable(ptr); }
    void PlayerCheat() { Menu__PlayerCheat(ptr); }
};

class CMenuPage
{
public:
    MenuPage* ptr;
    
    CMenuPage() : ptr(nullptr) {}
    explicit CMenuPage(MenuPage* p) : ptr(p) {}
    
    void Create() { MenuPage__MenuPage(ptr); }
    void Destroy() { MenuPage__MenuPage_Des(ptr); }
    void UpdateIndexToActive() { MenuPage__UpdateIndexToActive(ptr); }
    void NextActiveItem() { MenuPage__NextActiveItem(ptr); }
};

class CMenuEntry
{
public:
    MenuEntry* ptr;
    
    CMenuEntry() : ptr(nullptr) {}
    explicit CMenuEntry(MenuEntry* p) : ptr(p) {}
    
    void Create() { MenuEntry__MenuEntry(ptr); }
    void Destroy() { MenuEntry__MenuEntry_Dec(ptr); }
    void UpdateToPreviousActive() { MenuEntry__UpdateToPreviousActive(ptr); }
};

#endif // __cplusplus

#endif // MENU_H
