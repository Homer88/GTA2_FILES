# Структура Menu и методы

## Общая информация
- **Размер структуры**: ~0x1EB40 байт (125,760 байт)
- **Расположение в дампе**: gta2.h строка 5964
- **Назначение**: Главный класс управления меню игры GTA 2

---

## Структура данных Menu

```cpp
struct __fixed Menu
{
  // === Устройства ввода (0x0 - 0x10C) ===
  LPDIRECTINPUTA DirectInput;           // 0x0 - Интерфейс DirectInput
  LPDIRECTINPUTDEVICEA InputDevice;     // 0x4 - Устройство ввода
  char Keys[256];                       // 0x8 - Состояние клавиш (256 байт)
  
  // === Состояние фронтенда (0x108 - 0x110) ===
  int FrontendState;                    // 0x108 - Состояние фронтенда
  char KeyboardAcquired;                // 0x10C - Флаг захвата клавиатуры
  char FrontendKeysEnabled;             // 0x10D - Флаг включения клавиш фронтенда
  char field_10E;                       // 0x10E - Неизвестное поле
  char field_10F;                       // 0x10F - Неизвестное поле
  
  // === Поля состояния (0x110 - 0x11C) ===
  int State;                            // 0x110 - Текущее состояние
  int field_114;                        // 0x114 - Неизвестное поле
  int field_118;                        // 0x118 - Неизвестное поле
  ushort FontStyle;                     // 0x11C - Стиль шрифта
  ushort PageNumber;                    // 0x11E - Номер страницы
  __int16 CountPage;                    // 0x120 - Количество страниц
  
  // === Массив страниц меню (0x122 - 0xC98E) ===
  MenuPage MenuPage[17];                // 17 страниц меню
  
  // === Имя игрока (0xC990 - 0xC9A0) ===
  wchar_t *PlayerName;                  // 0xC990 - Указатель на имя игрока
  void *field_C990;                     // 0xC994 - Неизвестный указатель
  void *field_C994;                     // 0xC998 - Неизвестный указатель
  void *field_C998;                     // 0xC99C - Неизвестный указатель
  __int16 field_C99C;                   // 0xC9A0 - Неизвестное поле
  unsigned __int8 Length;               // 0xC9A2 - Длина имени
  char field_C99F;                      // 0xC9A3 - Неизвестное поле
  
  // === Клавиши и состояние ввода (0xC9A4 - 0xC9C8) ===
  __int16 Key;                          // 0xC9A4 - Текущая клавиша
  __int16 field_C9A2;                   // 0xC9A6 - Неизвестное поле
  wchar_t MenuItems[9];                 // 0xC9A8 - Элементы меню (9 wchar_t)
  unsigned __int8 CurrentMenuItemsIndex;// 0xC9BA - Индекс текущего элемента
  char field_C9B7;                      // 0xC9BB - Неизвестное поле
  KeyState NewKeyState;                 // 0xC9BC - Новое состояние клавиш
  KeyState OldKeyState;                 // 0xC9C3 - Старое состояние клавиш
  char field_C9C6;                      // 0xC9CA - Неизвестное поле
  char field_C9C7;                      // 0xC9CB - Неизвестное поле
  
  // === Таймеры и флаги (0xC9CC - 0xC9D4) ===
  int TimeToWaitDemoStart;              // 0xC9CC - Время до начала демо
  char FrameCounter;                    // 0xC9D0 - Счётчик кадров
  bool isChaet;                         // 0xC9D1 - Флаг чита
  char field_C9CE;                      // 0xC9D2 - Неизвестное поле
  char field_C9CF;                      // 0xC9D3 - Неизвестное поле
  int TimeToWaitBeforeDemoStart;        // 0xC9D4 - Время ожидания перед демо
  
  // === Буферы текста (0xC9D6 - 0xEDB5) ===
  __int16 gapC9D4;                      // 0xC9D8 - Выравнивание
  char field_C9D6[50];                  // 0xC9DA - Текстовый буфер 1
  char field_CA08[10];                  // 0xD0C - Текстовый буфер 2
  char field_CA12;                      // 0xD16 - Неизвестное поле
  char field_CA13;                      // 0xD17 - Неизвестное поле
  __int16 gapCA13;                      // 0xD18 - Выравнивание
  char field_CA15[200];                 // 0xD1A - Текстовый буфер 3
  char field_CADD[50];                  // 0xDE2 - Текстовый буфер 4
  char field_CB0F[50];                  // 0xE14 - Текстовый буфер 5
  char field_CB41[50];                  // 0xE46 - Текстовый буфер 6
  char field_CB72[50];                  // 0xE78 - Текстовый буфер 7
  char field_CBA4[50];                  // 0xEAA - Текстовый буфер 8
  char field_CBD6[50];                  // 0xEDC - Текстовый буфер 9
  char field_CC08[50];                  // 0xF0E - Текстовый буфер 10
  char field_CC3A[50];                  // 0xF40 - Текстовый буфер 11
  char field_CC6C[50];                  // 0xF72 - Текстовый буфер 12
  char field_CC9E[50];                  // 0xFA4 - Текстовый буфер 13
  char field_CCD0[50];                  // 0xFD6 - Текстовый буфер 14
  char field_EDB6[50];                  // 0x1008 - Текстовый буфер 15
  
  // === Большие буферы сохранений/профилей (0xCD36 - 0xEDA1) ===
  char field_CD36[1000];                // 0x103A - Буфер сохранения 1
  char field_D11E[1000];                // 0x141E - Буфер сохранения 2
  char field_D506[500];                 // 0x1806 - Буфер профиля 1
  char field_D6FA[500];                 // 0x19FA - Буфер профиля 2
  char field_D8EE[500];                 // 0x1BEE - Буфер профиля 3
  char field_DAE2[500];                 // 0x1DE2 - Буфер профиля 4
  char field_DCD6[500];                 // 0x1FD6 - Буфер профиля 5
  char field_DECA[1000];                // 0x21CA - Буфер профиля 6
  char field_E2B2[1000];                // 0x25B2 - Буфер профиля 7
  char field_E69A[1000];                // 0x299A - Буфер профиля 8
  char field_EA82[500];                 // 0x2D82 - Буфер профиля 9
  char field_EC76[200];                 // 0x2F76 - Буфер профиля 10
  char field_ED3E[100];                 // 0x303E - Буфер профиля 11
  char field_EDA2[50];                  // 0x30A2 - Буфер профиля 12
  
  // === Конфигурация слотов (0xEDB6 - 0xEDF4) ===
  S138 S138[8];                         // 0x30F4 - Массив структур S138
  MenuPic MenuPic;                      // 0x30FC - Тип картинки меню
  char field_EDF5;                      // 0x30FD - Неизвестное поле
  __int16 field_EDF6;                   // 0x30FE - Неизвестное поле
  char field_EDF8;                      // 0x3100 - Неизвестное поле
  char PlayerSlot;                      // 0x3101 - Слот игрока
  MenuSlotConfig MenuSlotConfig;        // 0x3102 - Конфигурация слота меню
  
  // === Дополнительные поля (0x1EB1C - 0x1EB40) ===
  __int16 field_1EB1C;                  // 0x1EB1C - Неизвестное поле
  char field_1EB1E;                     // 0x1EB1E - Неизвестное поле
  char field_1EB1F;                     // 0x1EB1F - Неизвестное поле
  Player *Player;                       // 0x1EB20 - Указатель на игрока
  unsigned __int16 Index;               // 0x1EB24 - Индекс
  char PlayerSlotSave[1];               // 0x1EB26 - Сохранённый слот игрока
  char field_1EB27;                     // 0x1EB27 - Неизвестное поле
  char field_1EB28;                     // 0x1EB28 - Неизвестное поле
  char field_1EB29;                     // 0x1EB29 - Неизвестное поле
  char field_1EB2A;                     // 0x1EB2A - Неизвестное поле
  char field_1EB2B;                     // 0x1EB2B - Неизвестное поле
  char field_1EB2C;                     // 0x1EB2C - Неизвестное поле
  char field_1EB2D;                     // 0x1EB2D - Неизвестное поле
  char BonusStage[8];                   // 0x1EB2E - Бонусная стадия
  char field_1EB36;                     // 0x1EB36 - Неизвестное поле
  char field_1EB37;                     // 0x1EB37 - Неизвестное поле
  char field_1EB38;                     // 0x1EB38 - Неизвестное поле
  char field_1EB39;                     // 0x1EB39 - Неизвестное поле
  char A1EB3A;                          // 0x1EB3A - Неизвестное поле
  char AAAA[1];                         // 0x1EB3B - Неизвестное поле
  unsigned __int8 CountArena;           // 0x1EB3C - Количество арен
  byte AAA[1];                          // 0x1EB3D - Неизвестное поле
  char field_1EB3F;                     // 0x1EB3E - Неизвестное поле
};
```

---

## Вспомогательные структуры

### MenuPage (страница меню)
```cpp
struct MenuPage
{
  unsigned __int16 numMenuItems[2];     // Количество элементов меню
  MenuEntry MenuEntry[10];              // 10 элементов меню
  GUI GUI[15];                          // 15 графических элементов
  MenuItem MenuItem[10];                // 10 пунктов меню
  ushort IndexMenuActions;              // Индекс действий меню
  __int16 SelectActiveElementDefault;   // Активный элемент по умолчанию
};
```

### MenuEntry (элемент меню)
```cpp
struct MenuEntry
{
  MenuActions MenuActions;              // Тип действия
  char field_1;                         // Неизвестное поле
  __int16 X;                            // Координата X
  __int16 Y;                            // Координата Y
  wchar_t TextMenuElement[50];          // Текст элемента
  __int16 StringLength;                 // Длина строки
  __int16 field_6C;                     // Неизвестное поле
  ushort PlayerSlot;                    // Слот игрока
  __int16 Plyrslot1;                    // Дополнительный слот игрока
  byte Flag[4];                         // Флаги (видимость и др.)
  int field_76;                         // Неизвестное поле
  int field_7A;                         // Неизвестное поле
  unsigned __int16 Index;               // Индекс
  __int16 SelectMenu;                   // Выбор меню
};
```

### GUI (графический элемент)
```cpp
struct GUI
{
  char Interface;                       // Интерфейс
  char PlayerArena;                     // Арена игрока
  __int16 X;                            // Координата X
  __int16 Y;                            // Координата Y
  wchar_t Sprite[50];                   // Название спрайта
  __int16 dX;                           // Ширина
  __int16 dY;                           // Высота
};
```

### MenuItem (пункт меню)
```cpp
struct MenuItem
{
  __int16 X;                            // Координата X
  __int16 Y;                            // Координата Y
  bool IndexMenuActions;                // Индекс действий меню
  char field_5;                         // Неизвестное поле
};
```

### KeyState (состояние клавиш)
```cpp
struct KeyState
{
  unsigned __int8 left;                 // Клавиша влево
  unsigned __int8 Right;                // Клавиша вправо
  unsigned __int8 up;                   // Клавиша вверх
  unsigned __int8 down;                 // Клавиша вниз
  unsigned __int8 enter;                // Клавиша Enter
  unsigned __int8 esc;                  // Клавиша Escape
  unsigned __int8 del;                  // Клавиша Delete
};
```

### MenuSlotConfig (конфигурация слота)
```cpp
struct MenuSlotConfig
{
  __int16 Index;                        // Индекс
  MenuItemConfig MenuItemConfig[600];   // 600 конфигураций элементов
};
```

### MenuItemConfig (конфигурация элемента)
```cpp
struct MenuItemConfig
{
  char fild;                            // Неизвестное поле
  char field_1;                         // Неизвестное поле
  _WORD field_2;                        // Неизвестное поле
  unsigned __int16 field_4;             // Неизвестное поле
  _WORD Selecet;                        // Выбор
  wchar_t str[50];                      // Строка
};
```

### S138
```cpp
struct S138
{
  char field_0;
  char field_1;
  char field_2;
  char field_3;
};
```

---

## Перечисления

### MenuActions (действия меню)
```cpp
enum MenuActions : __int8
{
  MENUACTION_NONE = 0,
  MENUACTION_CHANGEPAGE = 1,
  MENUACTION_SETPLAYERNAME = 2,
  // ... другие значения
};
```

### MenuPic (картинки меню)
```cpp
enum MenuPic : __int8
{
  Options = 0,
  Play = 1,
  Quit = 2,
  MenuPic_3 = 3,
  MenuPic_4 = 4,
  MenuPic_5 = 5,
  VievHigh = 6,
  StartLevel1 = 7,
  LoadSave = 8,
  StartLevel3 = 9,
  PlayerName = 10,
  Restart = 11,
  HighScores = 12,
  RIP = 13,
  MenuPic_14 = 14,
  MenuPic_15 = 15,
  ResumSave = 16,
  Title = 17,
  MenuPic_18 = 18,
  MenuPic_19 = 19,
};
```

---

## Методы класса Menu

### 1. Управление состоянием и вводом (8 методов)

| № | Метод | Размер | Адрес | Описание |
|---|-------|--------|-------|----------|
| 1 | `Menu__SetFrontendState` | 0xB (11) | 0x452xxx | Установка состояния фронтенда |
| 2 | `Menu__ReleaseInputDevice` | 0x22 (34) | 0x452xxx | Освобождение устройства ввода |
| 3 | `Menu__InitDevice` | 0x91 (145) | 0x452xxx | Инициализация устройства ввода |
| 4 | `Menu__ReadDeviceState` | 0x4E (78) | 0x452xxx | Чтение состояния устройства |
| 5 | `Menu__ProcessInput` | 0x152 (338) | 0x452xxx | Обработка ввода пользователя |
| 6 | `Menu__UpdateState` | 0x103 (259) | 0x452xxx | Обновление состояния меню |
| 7 | `Menu__HandleKeyPress` | 0x2A (42) | 0x452xxx | Обработка нажатия клавиш |
| 8 | `Menu__SetFrontendKeysEnabled` | 0xF (15) | 0x452xxx | Включение/выключение клавиш фронтенда |

### 2. Работа с игроком (7 методов)

| № | Метод | Размер | Адрес | Описание |
|---|-------|--------|-------|----------|
| 9 | `Menu__SetPlayerName` | 0x2F (47) | 0x452xxx | Установка имени игрока |
| 10 | `Menu__SetPlayerNameFromMenu` | 0x4F (79) | 0x452xxx | Установка имени из меню |
| 11 | `Menu__ValidatePlayerName` | 0x38 (56) | 0x452xxx | Проверка корректности имени |
| 12 | `Menu__getPlayerProfileName` | 0x26 (38) | 0x452xxx | Получение имени профиля игрока |
| 13 | `Menu__LoadPlayerProfile` | 0x25B (603) | 0x452xxx | Загрузка профиля игрока |
| 14 | `Menu__SelectPlayerSlot` | 0x10C (268) | 0x452xxx | Выбор слота игрока |
| 15 | `Menu__FindLastActiveArenaSlot` | 0x4B (75) | 0x452xxx | Поиск последнего активного слота арены |

### 3. Сохранение/загрузка (7 методов)

| № | Метод | Размер | Адрес | Описание |
|---|-------|--------|-------|----------|
| 16 | `Menu__SaveGame` | 0x1B3 (435) | 0x452xxx | Сохранение игры |
| 17 | `Menu__LoadGame` | 0x6B (107) | 0x452xxx | Загрузка игры |
| 18 | `Menu__NewGame` | 0x169 (361) | 0x452xxx | Новая игра |
| 19 | `Menu__CheckSaveFile` | 0x86 (134) | 0x452xxx | Проверка файла сохранения |
| 20 | `Menu__GettingSaveFile` | 0x9E (158) | 0x452xxx | Получение файла сохранения |
| 21 | `Menu__GetSaveFile` | 0x4E (78) | 0x452xxx |获取保存文件 |
| 22 | `Menu__SaveSettings` | 0x6A (106) | 0x452xxx | Сохранение настроек |

### 4. Отрисовка и ресурсы (10 методов)

| № | Метод | Размер | Адрес | Описание |
|---|-------|--------|-------|----------|
| 23 | `Menu__PrintCentr` | 0x43 (67) | 0x452xxx | Центрированная печать текста |
| 24 | `Menu__LoadTexture` | 0xCC (204) | 0x452xxx | Загрузка текстуры |
| 25 | `Menu__LoadTexturesFromTable` | 0x3A (58) | 0x452xxx | Загрузка текстур из таблицы |
| 26 | `Menu__FindBackground` | 0x14B (331) | 0x452xxx | Поиск фона для меню |
| 27 | `Menu__DrawMenuBackground` | 0x1B5 (437) | 0x452xxx | Отрисовка фона меню |
| 28 | `Menu__DrawMenuElements` | 0x46 (70) | 0x452xxx | Отрисовка элементов меню |
| 29 | `Menu__UpdateGUI` | 0x7D (125) | 0x452xxx | Обновление GUI |
| 30 | `Menu__LoadTextMenu` | 0x1512 (5394) | 0x452xxx | **Загрузка текстового меню** (САМЫЙ БОЛЬШОЙ МЕТОД!) |
| 31 | `Menu__CleanupResources` | 0xC5B (3163) | 0x452xxx | Очистка ресурсов |
| 32 | `Menu__CloseBinkResources` | 0x4D (77) | 0x452xxx | Закрытие ресурсов Bink видео |

### 5. Обработка событий и навигация (5 методов)

| № | Метод | Размер | Адрес | Описание |
|---|-------|--------|-------|----------|
| 33 | `Menu__SwitchPage` | 0x2A (42) | 0x452xxx | Переключение страницы меню |
| 34 | `Menu__ActivateElement` | 0xBC (188) | 0x452xxx | Активация элемента меню |
| 35 | `Menu__HandleMenuEvent` | 0x60B (1547) | 0x452xxx | **Обработка события меню** (большой метод) |
| 36 | `Menu__NavigatePages` | 0x66 (102) | 0x452xxx | Навигация по страницам |
| 37 | `Menu__GoBack` | 0x66 (102) | 0x452xxx | Возврат назад |

### 6. Логика меню (6 методов)

| № | Метод | Размер | Адрес | Описание |
|---|-------|--------|-------|----------|
| 38 | `Menu__MainMenuLogic` | 0x35C (860) | 0x452xxx | Логика главного меню |
| 39 | `Menu__PauseMenu` | 0x1A9 (425) | 0x452xxx | Меню паузы |
| 40 | `Menu__OptionsMenu` | 0x2CB (715) | 0x452xxx | Меню опций |
| 41 | `Menu__PlayerList` | 0x16B (363) | 0x452xxx | Список игроков |
| 42 | `Menu__MultiplayerMenu` | 0xDA (218) | 0x452xxx | Мультиплеер меню |
| 43 | `Menu__ServerSettings` | 0x9C (156) | 0x452xxx | Настройки сервера |

### 7. Настройки и конфигурация (8 методов)

| № | Метод | Размер | Адрес | Описание |
|---|-------|--------|-------|----------|
| 44 | `Menu__ApplyMoneyCheatIfApplicable` | 0x17B (379) | 0x452xxx | Применение чита на деньги |
| 45 | `Menu__SetDifficulty` | 0x2C4 (708) | 0x452xxx | Установка сложности |
| 46 | `Menu__SelectCharacter` | 0x6E (110) | 0x452xxx | Выбор персонажа |
| 47 | `Menu__ConfigureControls` | 0x38 (56) | 0x452xxx | Настройка управления |
| 48 | `Menu__AudioOptions` | 0x28 (40) | 0x452xxx | Аудио опции |
| 49 | `Menu__VideoOptions` | 0x44 (68) | 0x452xxx | Видео опции |
| 50 | `Menu__ApplySettings` | 0x53 (83) | 0x452xxx | Применение настроек |
| 51 | `Menu__ResetSettings` | 0x15F (351) | 0x452xxx | Сброс настроек |

### 8. Специальные экраны (9 методов)

| № | Метод | Размер | Адрес | Описание |
|---|-------|--------|-------|----------|
| 52 | `Menu__Intro_BIK` | 0x23 (35) | 0x452xxx | Воспроизведение интро BIK |
| 53 | `Menu__PreIntro` | 0x42 (66) | 0x452xxx | Пре-интро |
| 54 | `Menu__SelectMission` | 0x66 (102) | 0x452xxx | Выбор миссии |
| 55 | `Menu__WorldMap` | 0xF9 (249) | 0x452xxx | Карта мира |
| 56 | `Menu__ShowStatistics` | 0x66 (102) | 0x452xxx | Показ статистики |
| 57 | `Menu__ShowAwards` | 0x139 (313) | 0x452xxx | Показ наград |
| 58 | `Menu__Gallery` | 0x2A (42) | 0x452xxx | Галерея |
| 59 | `Menu__ShowCredits` | 0x2A (42) | 0x452xxx | Показ титров |
| 60 | `Menu__ConfirmExit` | 0x141 (321) | 0x452xxx | Подтверждение выхода |

### 9. Проверки и условия (4 метода)

| № | Метод | Размер | Адрес | Описание |
|---|-------|--------|-------|----------|
| 61 | `Menu__CheckConditions` (часть 1) | 0x4C (76) | 0x452xxx | Проверка условий (часть 1) |
| 62 | `Menu__CheckConditions` (часть 2) | 0x69 (105) | 0x452xxx | Проверка условий (часть 2) |
| 63 | `Menu__CheckConditions` (часть 3) | 0x161 (353) | 0x452xxx | Проверка условий (часть 3) |
| 64 | `Menu__MenuShowJapanText` | 0x31 (49) | 0x452xxx | Показ японского текста |

### 10. Основные методы класса (6 методов)

| № | Метод | Размер | Адрес | Описание |
|---|-------|--------|-------|----------|
| 65 | `Menu__Menu` | 0x32E (814) | 0x452xxx | **Основной метод меню** |
| 66 | `Menu__Menu_Des` | 0xF0 (240) | 0x452xxx | Деструктор |
| 67 | `Menu__Menu_Des1` | 0x1E (30) | 0x452xxx | Дополнительный деструктор |
| 68 | `Menu__UpdateMenuFrame` | 0xF9 (249) | 0x452xxx | Обновление кадра меню |
| 69 | `Menu__RenderMenu` | 0x18B (395) | 0x452xxx | Рендеринг меню |
| 70 | `Menu__sub_456F80` | 0x2A (42) | 0x456F80 | Подпрограмма (неименованная) |

### 11. Инициализация (1 метод)

| № | Метод | Размер | Адрес | Описание |
|---|-------|--------|-------|----------|
| 71 | `Menu__InitializeState` | 0x933 (2355) | 0x452xxx | **Инициализация состояния** (очень большой метод) |

### 12. Читы и специальные функции (8 методов)

| № | Метод | Размер | Адрес | Описание |
|---|-------|--------|-------|----------|
| 72 | `Menu__PlayerCheat` | 0x44E (1102) | 0x452xxx | **Читы игрока** (большой метод) |
| 73 | `Menu__SpecialFunction1` | 0xC1 (193) | 0x452xxx | Специальная функция 1 |
| 74 | `Menu__SpecialFunction2` | 0xF9 (249) | 0x452xxx | Специальная функция 2 |
| 75 | `Menu__SpecialFunction3` | 0x61D (1565) | 0x452xxx | **Специальная функция 3** (очень большая) |
| 76 | `Menu__SpecialFunction4` | 0x1D6 (470) | 0x452xxx | Специальная функция 4 |
| 77 | `Menu__SpecialFunction5` | 0x231 (561) | 0x452xxx | Специальная функция 5 |
| 78 | `Menu__SpecialFunction6` | 0xB5 (181) | 0x452xxx | Специальная функция 6 |
| 79 | `Menu__SpecialFunction7` | 0x133 (307) | 0x452xxx | Специальная функция 7 |

---

## Статистика методов

| Категория | Количество методов | Общий размер (байт) |
|-----------|-------------------|---------------------|
| Управление состоянием и вводом | 8 | ~1,200 |
| Работа с игроком | 7 | ~1,400 |
| Сохранение/загрузка | 7 | ~1,300 |
| Отрисовка и ресурсы | 10 | ~10,500 |
| Обработка событий и навигация | 5 | ~1,900 |
| Логика меню | 6 | ~2,700 |
| Настройки и конфигурация | 8 | ~1,800 |
| Специальные экраны | 9 | ~1,500 |
| Проверки и условия | 4 | ~900 |
| Основные методы класса | 6 | ~1,600 |
| Инициализация | 1 | ~2,400 |
| Читы и специальные функции | 8 | ~4,500 |
| **ВСЕГО** | **79** | **~31,700** |

### Самые большие методы:
1. `Menu__LoadTextMenu` - 5,394 байт (0x1512)
2. `Menu__InitializeState` - 2,355 байт (0x933)
3. `Menu__CleanupResources` - 3,163 байт (0xC5B)
4. `Menu__SpecialFunction3` - 1,565 байт (0x61D)
5. `Menu__HandleMenuEvent` - 1,547 байт (0x60B)
6. `Menu__PlayerCheat` - 1,102 байт (0x44E)

### Самые маленькие методы:
1. `Menu__SetFrontendState` - 11 байт (0xB)
2. `Menu__SetFrontendKeysEnabled` - 15 байт (0xF)
3. `Menu__Menu_Des1` - 30 байт (0x1E)
4. `Menu__Intro_BIK` - 35 байт (0x23)
5. `Menu__ReleaseInputDevice` - 34 байт (0x22)

---

## Примечания

1. **Адреса методов**: Точные адреса методов находятся в файле `gta2.asm`. В данном документе указаны только относительные смещения.

2. **Неизвестные поля**: Многие поля структур помечены как `field_XXX` - их назначение требует дополнительного исследования через анализ ассемблерного кода.

3. **Размер структуры**: Общий размер структуры Menu составляет примерно 0x1EB40 (125,760) байт, что делает её одной из крупнейших структур в игре.

4. **DirectInput**: Класс использует DirectInput для обработки ввода, что соответствует эпохе DirectX 6.1.

5. **17 страниц меню**: Массив `MenuPage[17]` предполагает наличие 17 различных страниц/экранов меню.

6. **Поддержка нескольких игроков**: Наличие полей `PlayerSlot`, `MenuSlotConfig` и массивов профилей указывает на поддержку мультиплеера.

7. **Система сохранений**: Множество больших буферов (по 500-1000 байт) предназначены для хранения профилей игроков и файлов сохранений.

---

*Документ создан на основе анализа файлов:*
- `gta2_dump/ida_pro/gta2.h` (структуры)
- `gta2_dump/ida_pro/gta2.asm` (методы)
- `gta2_dump/ida_pro/gta2.c` (дополнительная информация)

*Дата создания: $(date)*
