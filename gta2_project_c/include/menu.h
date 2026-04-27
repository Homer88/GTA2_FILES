#ifndef MENU_H
#define MENU_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// Forward declarations
struct DirectInput;
struct InputDevice;
struct MenuPage;
struct TextMenuElement;
struct GUI;
struct MenuItem;

// Enum: FrontendState
typedef enum FrontendState {
    FRONTEND_NONE = 0,
    FRONTEND_INTRO = 1,
    FRONTEND_MAIN_MENU = 2,
    FRONTEND_PAUSE_MENU = 3,
    FRONTEND_OPTIONS_MENU = 4,
    FRONTEND_PLAYER_LIST = 5,
    FRONTEND_MULTIPLAYER_MENU = 6,
    FRONTEND_SERVER_SETTINGS = 7,
    FRONTEND_SELECT_MISSION = 8,
    FRONTEND_WORLD_MAP = 9,
    FRONTEND_SHOW_STATISTICS = 10,
    FRONTEND_SHOW_AWARDS = 11,
    FRONTEND_GALLERY = 12,
    FRONTEND_SHOW_CREDITS = 13,
    FRONTEND_CONFIRM_EXIT = 14,
    FRONTEND_PREINTRO = 15,
    FRONTEND_INTRO_BIK = 16
} FrontendState;

// Enum: MenuActions
typedef enum MenuActions {
    MENU_ACTION_NONE = 0,
    MENU_ACTION_CHANGEPAGE = 1,
    MENU_ACTION_SETPLAYERNAME = 2,
    MENU_ACTION_LOADGAME = 3,
    MENU_ACTION_SAVEGAME = 4,
    MENU_ACTION_NEWGAME = 5,
    MENU_ACTION_EXIT = 6,
    MENU_ACTION_OPTIONS = 7,
    MENU_ACTION_DIFFICULTY = 8,
    MENU_ACTION_CHARACTER = 9,
    MENU_ACTION_CONTROLS = 10,
    MENU_ACTION_AUDIO = 11,
    MENU_ACTION_VIDEO = 12,
    MENU_ACTION_APPLY = 13,
    MENU_ACTION_RESET = 14,
    MENU_ACTION_BACK = 15,
    MENU_ACTION_SELECT_SLOT = 16,
    MENU_ACTION_SELECT_MISSION = 17,
    MENU_ACTION_SHOW_STATISTICS = 18,
    MENU_ACTION_SHOW_AWARDS = 19,
    MENU_ACTION_GALLERY = 20,
    MENU_ACTION_CREDITS = 21,
    MENU_ACTION_MULTIPLAYER = 22,
    MENU_ACTION_SERVER_SETTINGS = 23,
    MENU_ACTION_CHEAT = 24
} MenuActions;

// Enum: KeyCode
typedef enum KeyCode {
    KEY_NONE = 0,
    KEY_ESCAPE = 1,
    KEY_ENTER = 2,
    KEY_UP = 3,
    KEY_DOWN = 4,
    KEY_LEFT = 5,
    KEY_RIGHT = 6,
    KEY_SPACE = 7,
    KEY_F1 = 8,
    KEY_F2 = 9,
    KEY_F3 = 10,
    // ... остальные клавиши
    KEY_MAX = 256
} KeyCode;

// Структура MenuEntry (элемент меню)
// Размер: предположительно 0x50 байт
typedef struct MenuEntry {
    MenuActions MenuAction;      // +0x00 - тип действия
    float X;                     // +0x04 - координата X
    float Y;                     // +0x08 - координата Y
    char TextMenuElement[50];    // +0x0C - текст надписи (50 байт)
    int PlayerSlot;              // +0x3E - слот игрока (выравнивание?)
    uint8_t Flag[4];             // +0x42 - флаги видимости (4 байта)
    // Возможно есть выравнивание до 0x50
} MenuEntry;

// Структура MenuPage (страница меню)
// Размер: предположительно 0x200 байт
typedef struct MenuPage {
    int numMenuItems;                    // +0x00 - количество элементов
    MenuEntry MenuEntryArray[10];        // +0x04 - элементы меню (10 * 0x50 = 0x320)
    struct GUI* GUIArray[15];            // +0x324 - графические элементы (15 * 4 = 0x3C)
    struct MenuItem* MenuItemArray[10];  // +0x360 - пункты меню (10 * 4 = 0x28)
    // Возможно есть дополнительные поля и выравнивание
} MenuPage;

// Основная структура Menu
// Размер: ~0x1EB40 байт
typedef struct Menu {
    // Устройства ввода (предположительно 0x0000 - 0x0100)
    struct DirectInput* pDirectInput;    // +0x0000 - указатель на DirectInput
    struct InputDevice* pInputDevice;    // +0x0004 - указатель на устройство ввода
    
    // Состояние клавиш (0x0100 - 0x0200)
    uint8_t Keys[256];                   // +0x0008 - состояние клавиш (256 байт)
    
    // Состояние фронтенда (0x0200 - 0x0210)
    FrontendState FrontendState;         // +0x0108 - текущее состояние
    FrontendState PreviousState;         // +0x010C - предыдущее состояние
    bool FrontendKeysEnabled;            // +0x0110 - включены ли клавиши фронтенда
    
    // Массив страниц меню (0x0210 - 0x3000)
    MenuPage MenuPageArray[17];          // +0x0114 - 17 страниц меню
    
    // Информация об игроке (0x3000 - 0x3100)
    char PlayerName[32];                 // +0x3000 - имя игрока (32 байта)
    char PlayerProfileName[64];          // +0x3020 - имя профиля (64 байта)
    int CurrentPlayerSlot;               // +0x3060 - текущий слот игрока
    
    // Буферы для текста и сохранений (0x3100 - 0x5000)
    char TextBuffer[256];                // +0x3064 - буфер для текста
    char SaveFilePath[260];              // +0x3164 - путь к файлу сохранения
    char SettingsBuffer[512];            // +0x3268 - буфер настроек
    
    // Ресурсы и текстуры (0x5000 - 0x10000)
    void* pTextureTable;                 // +0x5000 - таблица текстур
    void* pBackgroundTexture;            // +0x5004 - текстура фона
    int NumLoadedTextures;               // +0x5008 - количество загруженных текстур
    
    // Настройки игры (0x10000 - 0x15000)
    int Difficulty;                      // +0x10000 - сложность
    int CharacterIndex;                  // +0x10004 - индекс персонажа
    int ControlConfig;                   // +0x10008 - конфигурация управления
    float AudioVolume;                   // +0x1000C - громкость аудио
    int VideoResolution;                 // +0x10010 - разрешение видео
    bool WindowedMode;                   // +0x10014 - оконный режим
    
    // Статистика и награды (0x15000 - 0x1A000)
    int TotalScore;                      // +0x15000 - общий счет
    int MissionsCompleted;               // +0x15004 - выполнено миссий
    int AwardsCount;                     // +0x15008 - количество наград
    
    // Специальные флаги и состояния (0x1A000 - 0x1EB40)
    bool IsIntroPlaying;                 // +0x1A000 - воспроизводится ли интро
    bool IsBinkActive;                   // +0x1A004 - активен ли Bink
    int SpecialFlag1;                    // +0x1A008 - специальный флаг 1
    int SpecialFlag2;                    // +0x1A00C - специальный флаг 2
    // ... остальные поля до 0x1EB40
    
    // Выравнивание до общего размера 0x1EB40
    uint8_t Reserved[0x1EB40 - 0x1A010]; // Зарезервировано
} Menu;

// Проверка размеров структур (будет актуализирована после точного анализа)
// static_assert(sizeof(MenuEntry) == 0x50, "MenuEntry size mismatch");
// static_assert(sizeof(MenuPage) == 0x200, "MenuPage size mismatch");
// static_assert(sizeof(Menu) == 0x1EB40, "Menu size mismatch");

// Объявления функций (будут реализованы в .c/.cpp файлах)
// Формат: // Адрес: 0xXXXXXX - Размер: 0xXX байт

// Инициализация и очистка
// Адрес: 0x00456F80 - Размер: 0x933 байт
void Menu__InitializeState(Menu* self);
// Адрес: 0x004578B3 - Размер: 0xC5B байт
void Menu__CleanupResources(Menu* self);
// Адрес: 0x0045850E - Размер: 0x4D байт
void Menu__CloseBinkResources(Menu* self);

// Управление состоянием
// Адрес: 0x00456F50 - Размер: 0xB байт
void Menu__SetFrontendState(Menu* self, FrontendState state);
// Адрес: 0x00456F60 - Размер: 0x103 байт
void Menu__UpdateState(Menu* self);
// Адрес: 0x004570A0 - Размер: 0xF9 байт
void Menu__UpdateMenuFrame(Menu* self);
// Адрес: 0x00457199 - Размер: 0x18B байт
void Menu__RenderMenu(Menu* self);

// Ввод
// Адрес: 0x00456A00 - Размер: 0x91 байт
void Menu__InitDevice(Menu* self);
// Адрес: 0x00456A91 - Размер: 0x22 байт
void Menu__ReleaseInputDevice(Menu* self);
// Адрес: 0x00456AB3 - Размер: 0x4E байт
void Menu__ReadDeviceState(Menu* self);
// Адрес: 0x00456B01 - Размер: 0x152 байт
void Menu__ProcessInput(Menu* self);
// Адрес: 0x00456C53 - Размер: 0x2A байт
void Menu__HandleKeyPress(Menu* self, KeyCode key);
// Адрес: 0x00456C7D - Размер: 0xF байт
void Menu__SetFrontendKeysEnabled(Menu* self, bool enabled);

// Работа с игроком
// Адрес: 0x00458600 - Размер: 0x2F байт
void Menu__SetPlayerName(Menu* self, const char* name);
// Адрес: 0x0045862F - Размер: 0x4F байт
void Menu__SetPlayerNameFromMenu(Menu* self, const char* name);
// Адрес: 0x0045867E - Размер: 0x38 байт
bool Menu__ValidatePlayerName(Menu* self, const char* name);
// Адрес: 0x004586B6 - Размер: 0x26 байт
const char* Menu__getPlayerProfileName(Menu* self);
// Адрес: 0x004586DC - Размер: 0x25B байт
void Menu__LoadPlayerProfile(Menu* self, int slot);
// Адрес: 0x00458937 - Размер: 0x10C байт
void Menu__SelectPlayerSlot(Menu* self, int slot);
// Адрес: 0x00458A43 - Размер: 0x4B байт
int Menu__FindLastActiveArenaSlot(Menu* self);

// Сохранение/загрузка
// Адрес: 0x00458A8E - Размер: 0x1B3 байт
void Menu__SaveGame(Menu* self);
// Адрес: 0x00458C41 - Размер: 0x6B байт
void Menu__LoadGame(Menu* self);
// Адрес: 0x00458CAC - Размер: 0x169 байт
void Menu__NewGame(Menu* self);
// Адрес: 0x00458E15 - Размер: 0x86 байт
bool Menu__CheckSaveFile(Menu* self, const char* filename);
// Адрес: 0x00458E9B - Размер: 0x9E байт
const char* Menu__GettingSaveFile(Menu* self);
// Адрес: 0x00458F39 - Размер: 0x4E байт
const char* Menu__GetSaveFile(Menu* self);
// Адрес: 0x00458F87 - Размер: 0x6A байт
void Menu__SaveSettings(Menu* self);

// Отрисовка и ресурсы
// Адрес: 0x00457324 - Размер: 0x43 байт
void Menu__PrintCentr(Menu* self, const char* text, float x, float y);
// Адрес: 0x00457367 - Размер: 0xCC байт
void* Menu__LoadTexture(Menu* self, const char* filename);
// Адрес: 0x00457433 - Размер: 0x3A байт
void Menu__LoadTexturesFromTable(Menu* self, void* table);
// Адрес: 0x0045746D - Размер: 0x14B байт
void* Menu__FindBackground(Menu* self, int index);
// Адрес: 0x004575B8 - Размер: 0x1B5 байт
void Menu__DrawMenuBackground(Menu* self);
// Адрес: 0x0045776D - Размер: 0x46 байт
void Menu__DrawMenuElements(Menu* self);
// Адрес: 0x004577B3 - Размер: 0x7D байт
void Menu__UpdateGUI(Menu* self);
// Адрес: 0x00457830 - Размер: 0x1512 байт
void Menu__LoadTextMenu(Menu* self);

// Обработка событий и навигация
// Адрес: 0x00456D00 - Размер: 0x2A байт
void Menu__SwitchPage(Menu* self, int pageIndex);
// Адрес: 0x00456D2A - Размер: 0xBC байт
void Menu__ActivateElement(Menu* self, int elementIndex);
// Адрес: 0x00456DE6 - Размер: 0x60B байт
void Menu__HandleMenuEvent(Menu* self, int event);
// Адрес: 0x00456DF0 - Размер: 0x66 байт
void Menu__NavigatePages(Menu* self, int direction);
// Адрес: 0x00456E56 - Размер: 0x66 байт
void Menu__GoBack(Menu* self);

// Логика меню
// Адрес: 0x00457F00 - Размер: 0x35C байт
void Menu__MainMenuLogic(Menu* self);
// Адрес: 0x00458050 - Размер: 0x1A9 байт
void Menu__PauseMenu(Menu* self);
// Адрес: 0x004581F9 - Размер: 0x2CB байт
void Menu__OptionsMenu(Menu* self);
// Адрес: 0x004584C4 - Размер: 0x16B байт
void Menu__PlayerList(Menu* self);
// Адрес: 0x0045862F - Размер: 0xDA байт
void Menu__MultiplayerMenu(Menu* self);
// Адрес: 0x00458709 - Размер: 0x9C байт
void Menu__ServerSettings(Menu* self);

// Настройки и конфигурация
// Адрес: 0x00458800 - Размер: 0x17B байт
void Menu__ApplyMoneyCheatIfApplicable(Menu* self);
// Адрес: 0x0045897B - Размер: 0x2C4 байт
void Menu__SetDifficulty(Menu* self, int difficulty);
// Адрес: 0x00458C3F - Размер: 0x6E байт
void Menu__SelectCharacter(Menu* self, int characterIndex);
// Адрес: 0x00458CAD - Размер: 0x38 байт
void Menu__ConfigureControls(Menu* self, int config);
// Адрес: 0x00458CE5 - Размер: 0x28 байт
void Menu__AudioOptions(Menu* self);
// Адрес: 0x00458D0D - Размер: 0x44 байт
void Menu__VideoOptions(Menu* self);
// Адрес: 0x00458D51 - Размер: 0x53 байт
void Menu__ApplySettings(Menu* self);
// Адрес: 0x00458DA4 - Размер: 0x15F байт
void Menu__ResetSettings(Menu* self);

// Специальные экраны
// Адрес: 0x00458F03 - Размер: 0x23 байт
void Menu__Intro_BIK(Menu* self);
// Адрес: 0x00458F26 - Размер: 0x42 байт
void Menu__PreIntro(Menu* self);
// Адрес: 0x00458F68 - Размер: 0x66 байт
void Menu__SelectMission(Menu* self);
// Адрес: 0x00458FCE - Размер: 0xF9 байт
void Menu__WorldMap(Menu* self);
// Адрес: 0x004590C7 - Размер: 0x66 байт
void Menu__ShowStatistics(Menu* self);
// Адрес: 0x0045912D - Размер: 0x139 байт
void Menu__ShowAwards(Menu* self);
// Адрес: 0x00459266 - Размер: 0x2A байт
void Menu__Gallery(Menu* self);
// Адрес: 0x00459290 - Размер: 0x2A байт
void Menu__ShowCredits(Menu* self);
// Адрес: 0x004592BA - Размер: 0x141 байт
void Menu__ConfirmExit(Menu* self);

// Проверки и условия
// Адрес: 0x004593FB - Размер: 0x4C+0x69+0x161 байт
void Menu__CheckConditions(Menu* self);
// Адрес: 0x00459447 - Размер: 0x31 байт
void Menu__MenuShowJapanText(Menu* self);

// Читы и специальные функции
// Адрес: 0x00459478 - Размер: 0x44E байт
void Menu__PlayerCheat(Menu* self, int cheatCode);
// Адрес: 0x004598C6 - Размер: 0xC1 байт
void Menu__SpecialFunction1(Menu* self);
// Адрес: 0x00459987 - Размер: 0xF9 байт
void Menu__SpecialFunction2(Menu* self);
// Адрес: 0x00459A80 - Размер: 0x61D байт
void Menu__SpecialFunction3(Menu* self);
// Адрес: 0x0045A09D - Размер: 0x1D6 байт
void Menu__SpecialFunction4(Menu* self);
// Адрес: 0x0045A273 - Размер: 0x231 байт
void Menu__SpecialFunction5(Menu* self);
// Адрес: 0x0045A4A4 - Размер: 0xB5 байт
void Menu__SpecialFunction6(Menu* self);
// Адрес: 0x0045A559 - Размер: 0x133 байт
void Menu__SpecialFunction7(Menu* self);

// Основной метод меню
// Адрес: 0x00456F00 - Размер: 0x32E байт
void Menu__Menu(Menu* self);
// Адрес: 0x0045722E - Размер: 0xF0 байт
void Menu__Menu_Des(Menu* self);
// Адрес: 0x0045731E - Размер: 0x1E байт
void Menu__Menu_Des1(Menu* self);

// ============================================================================
// Структура CMenuDataBlock (ранее S138)
// Размер: 4 байта
// Адрес в памяти: уточнить по дампу
// ============================================================================

typedef struct CMenuDataBlock {
    uint8_t field_0; // смещение 0x0 - флаг состояния
    uint8_t field_1; // смещение 0x1
    uint8_t field_2; // смещение 0x2
    uint8_t field_3; // смещение 0x3
} CMenuDataBlock;

// Методы структуры CMenuDataBlock
// Конструктор: адрес 0x00061CE0
void CMenuDataBlock__CMenuDataBlock(CMenuDataBlock* self);

// Деструктор: адрес 0x00061CF0
void CMenuDataBlock__CMenuDataBlock_DEC(CMenuDataBlock* self);

// Загрузка данных: адрес 0x00061D00 (ранее sub_452D00)
void CMenuDataBlock__Load(CMenuDataBlock* self);

#ifdef __cplusplus
}
#endif

#endif // MENU_H
