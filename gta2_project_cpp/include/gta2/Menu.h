#pragma once

#include <windows.h>
#include <dinput.h>
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
    MenuEntry MenuEntry[10];            // Элементы меню
    GUI GUI[15];                        // GUI элементы
    MenuItem MenuItem[10];              // Пункты меню
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
    FrontendState FrontendState;                // 0x108 - Состояние фронтенда
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

// Работа с текстурами и фоном
void Menu__LoadTexture(Menu* this_ptr, const char* texture_name); // 0x00452D50 - Загрузка текстуры
void Menu__LoadTexturesFromTable(Menu* this_ptr);          // 0x00452E20 - Загрузка текстур из таблицы
void Menu__FindBackground(Menu* this_ptr);                 // 0x00452E80 - Поиск фона
void Menu__DrawMenuBackground(Menu* this_ptr);             // 0x00453020 - Отрисовка фона меню

// Работа с текстом и именем игрока
void Menu__SetPlayerName(Menu* this_ptr, const wchar_t* name); // 0x00452490 - Установка имени игрока
void Menu__SetPlayerNameFromMenu(Menu* this_ptr);          // 0x00459540 - Установка имени из меню
wchar_t* Menu__getPlayerProfileName(Menu* this_ptr);       // 0x00452500 - Получение имени профиля
void Menu__PrintCentr(Menu* this_ptr, const wchar_t* text, int x, int y); // 0x004521B0 - Печать центрированного текста

// Работа с сохранениями
void* Menu__GettingSaveFile(Menu* this_ptr, int slot);     // 0x004528A0 - Получение файла сохранения
void* Menu__GetSaveFile(Menu* this_ptr, int slot);         // 0x00452940 - Получение файла сохранения (альтернатива)

// Видео и интро
void Menu__Intro_BIK(Menu* this_ptr);                      // 0x00452990 - Воспроизведение BIK видео интро
void Menu__PreIntro(Menu* this_ptr);                       // 0x004529C0 - Предварительное интро
void Menu__CloseBinkResources(Menu* this_ptr);             // 0x00481D30 - Закрытие ресурсов Bink

// Меню и страницы
void Menu__LoadTextMenu(Menu* this_ptr);                   // 0x00453E20 - Загрузка текстового меню
void Menu__MenuShowJapanText(Menu* this_ptr);              // 0x00453D40 - Показ японского текста меню
int Menu__FindLastActiveArenaSlot(Menu* this_ptr);         // 0x00453430 - Поиск последнего активного слота арены

// Читы и специальные функции
void Menu__ApplyMoneyCheatIfApplicable(Menu* this_ptr);    // 0x00452200 - Применение чита на деньги
void Menu__PlayerCheat(Menu* this_ptr);                    // 0x004590F0 - Чит игрока

// Внутренние функции (требуют анализа)
void Menu__sub_452050(Menu* this_ptr);                     // 0x00452050 - Обработка ввода
void Menu__sub_452380(Menu* this_ptr);                     // 0x00452380 - Обновление состояния
void Menu__sub_4524C0(Menu* this_ptr);                     // 0x004524C0 - Валидация имени
void Menu__sub_452530(Menu* this_ptr);                     // 0x00452530 - Загрузка профиля
void Menu__sub_4527A0(Menu* this_ptr);                     // 0x004527A0 - Сохранение настроек
void Menu__sub_452810(Menu* this_ptr);                     // 0x00452810 - Проверка сохранения
void Menu__sub_4531E0(Menu* this_ptr);                     // 0x004531E0 - Отрисовка элементов
void Menu__sub_453230(Menu* this_ptr);                     // 0x00453230 - Обновление GUI
void Menu__sub_4532B0(Menu* this_ptr);                     // 0x004532B0 - Обработка нажатий
void Menu__sub_4532E0(Menu* this_ptr);                     // 0x004532E0 - Переключение страниц
void Menu__sub_453310(Menu* this_ptr);                     // 0x00453310 - Активация элемента
void Menu__sub_453480(Menu* this_ptr);                     // 0x00453480 - Выбор слота
void Menu__sub_453590(Menu* this_ptr);                     // 0x00453590 - Настройка сложности
void Menu__sub_453870(Menu* this_ptr);                     // 0x00453870 - Выбор персонажа
void Menu__sub_4538F0(Menu* this_ptr);                     // 0x004538F0 - Настройка управления
void Menu__sub_453930(Menu* this_ptr);                     // 0x00453930 - Аудио настройки
void Menu__sub_453960(Menu* this_ptr);                     // 0x00453960 - Видео настройки
void Menu__sub_455340(Menu* this_ptr);                     // 0x00456340 - Главное меню логика
void Menu__sub_4556A0(Menu* this_ptr);                     // 0x004566A0 - Пауза меню
void Menu__sub_455850(Menu* this_ptr);                     // 0x00456850 - Опции меню
void Menu__sub_455C20(Menu* this_ptr);                     // 0x00456C20 - Загрузка игры
void Menu__sub_455C90(Menu* this_ptr);                     // 0x00456C90 - Сохранение игры
void Menu__sub_455F90(Menu* this_ptr);                     // 0x00456F90 - Новая игра
void Menu__sub_456110(Menu* this_ptr);                     // 0x00457110 - Выбор миссии
void Menu__sub_456180(Menu* this_ptr);                     // 0x00457180 - Карта мира
void Menu__sub_456280(Menu* this_ptr);                     // 0x00457280 - Статистика
void Menu__sub_4562F0(Menu* this_ptr);                     // 0x004572F0 - Награды
void Menu__sub_456430(Menu* this_ptr);                     // 0x00457430 - Галерея
void Menu__sub_456460(Menu* this_ptr);                     // 0x00457460 - Титры
void Menu__sub_456490(Menu* this_ptr);                     // 0x00457490 - Выход подтверждение
void Menu__sub_4565E0(Menu* this_ptr);                     // 0x004575E0 - Многопользовательская игра
void Menu__sub_456820(Menu* this_ptr);                     // 0x00457820 - Настройки сервера
void Menu__sub_4568C0(Menu* this_ptr);                     // 0x004578C0 - Список игроков
void Menu__sub_456E80(Menu* this_ptr);                     // 0x00457E80 - Обновление кадра меню
void Menu__sub_456FB0(Menu* this_ptr);                     // 0x00457FB0 - Рендер меню
void Menu__sub_457140(Menu* this_ptr);                     // 0x00458140 - Обработка событий меню
void Menu__sub_457750(Menu* this_ptr);                     // 0x00458750 - Переход между страницами
void Menu__sub_4577C0(Menu* this_ptr);                     // 0x004587C0 - Возврат назад
void Menu__sub_457920(Menu* this_ptr);                     // 0x00458920 - Очистка ресурсов
void Menu__sub_458590(Menu* this_ptr);                     // 0x00459590 - Проверка условий
void Menu__sub_4585F0(Menu* this_ptr);                     // 0x004595F0 - Применение настроек
void Menu__sub_458650(Menu* this_ptr);                     // 0x00459650 - Сброс настроек
void Menu__sub_459590(Menu* this_ptr);                     // 0x0045A590 - Специальная функция 1
void Menu__sub_459660(Menu* this_ptr);                     // 0x0045A660 - Специальная функция 2
void Menu__sub_4597C0(Menu* this_ptr);                     // 0x0045A7C0 - Специальная функция 3
void Menu__sub_459E30(Menu* this_ptr);                     // 0x0045AE30 - Специальная функция 4
void Menu__sub_45A010(Menu* this_ptr);                     // 0x0045B010 - Специальная функция 5
void Menu__sub_45A250(Menu* this_ptr);                     // 0x0045B250 - Специальная функция 6
void Menu__sub_45A320(Menu* this_ptr);                     // 0x0045B320 - Специальная функция 7

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
void MenuEntry__sub_452BD0(MenuEntry* this_ptr);           // 0x00452BD0 - Внутренняя функция

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
