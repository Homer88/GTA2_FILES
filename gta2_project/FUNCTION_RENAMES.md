# GTA2 Function Rename Mapping

Этот документ содержит предлагаемые имена для функций декомпилированного кода GTA2.

## Как использовать

1. Найдите оригинальное имя функции в списке
2. Замените его на предложенное имя в коде
3. Обновите заголовочные файлы соответствующим образом

---

## AutoClass4

| Оригинальное имя | Новое имя | Описание |
|-----------------|-----------|----------|
| `AutoClass4::FUN_004038e0` | `AIController__Initialize` | Инициализирует AI контроллер |
| `AutoClass4::FUN_00404400` | `AIController__AssignPed` | Назначает пешехода AI контроллеру |
| `AutoClass4::FUN_00404420` | `AIController__SetPedIndex` | Устанавливает индекс пешехода |
| `AutoClass4::FUN_004045d0` | `AIController__Update` | Обновляет AI контроллер |
| `AutoClass4::FUN_004046f0` | `AIController__ProcessPed` | Обрабатывает пешехода |
| `AutoClass4::FUN_00405760` | `AIController__ExecuteAction` | Выполняет действие AI |
| `AutoClass4::~AutoClass4` | `AIController__Destructor` | Деструктор AI контроллера |

---

## Car

| Оригинальное имя | Новое имя | Описание |
|-----------------|-----------|----------|
| `Car::isSWATVANOrBankVan` | `Car__IsSpecialVehicle` | Проверяет, является ли авто спецтранспортом |

---

## CarSystemManager

| Оригинальное имя | Новое имя | Описание |
|-----------------|-----------|----------|
| `CarSystemManager::Clamp` | `CarSystemManager__ClampValues` | Ограничивает значения параметров автомобиля |
| `CarSystemManager::FUN_00401c40` | `CarSystemManager__AddCarToSystem` | Добавляет автомобиль в систему |

---

## FileMgr

| Оригинальное имя | Новое имя | Описание |
|-----------------|-----------|----------|
| `FileMgr::CloseFile` | `FileMgr__Close` | Закрывает открытый файл |
| `FileMgr::FUN_0044dbb0` | `FileMgr__SetFilePath` | Устанавливает путь к файлу |
| `FileMgr::FileOpen` | `FileMgr__OpenFile` | Открывает файл для чтения/записи |
| `FileMgr::Read` | `FileMgr__ReadData` | Читает данные из файла |
| `FileMgr::Seek` | `FileMgr__SeekPosition` | Перемещает позицию в файле |

---

## Game

| Оригинальное имя | Новое имя | Описание |
|-----------------|-----------|----------|
| `Game::Game_FUN_003f113c` | `Game__GetCurrentPlayerSlot` | Получает текущий слот игрока, проверяет активные слоты |
| `Game::Game_FUN_003f11a8` | `Game__FindNextActivePlayer` | Находит следующего активного игрока в цикле |
| `Game::Game_FUN_003f1208` | `Game__SwitchToNextPlayer` | Переключается на следующего игрока, обновляет камеру |
| `Game::Game_FUN_003f12a8` | `Game__CycleToNextPlayer` | Циклически перебирает игроков для передачи управления |

---

## GameObject

| Оригинальное имя | Новое имя | Описание |
|-----------------|-----------|----------|
| `GameObject::FUN_00403910` | `GameObject__LinkTo` | Привязывает объект к другому |
| `GameObject::GetCar` | `GameObject__GetVehicle` | Получает автомобиль объекта |

---

## MissionManager

| Оригинальное имя | Новое имя | Описание |
|-----------------|-----------|----------|
| `MissionManager::FUN_003f163c` | `MissionManager__UpdateMissionState` | Обновляет состояние текущей миссии |
| `MissionManager::MissionManager_FUN_00476200` | `MissionManager__StartMission` | Запускает миссию по номеру |

---

## Ped

| Оригинальное имя | Новое имя | Описание |
|-----------------|-----------|----------|
| `Ped::GetCarPed` | `Ped__GetVehicle` | Получает автомобиль пешехода |
| `Ped::GetCurrentAction` | `Ped__GetCurrentAction` | Получает текущее действие пешехода |
| `Ped::GetCurrentCar` | `Ped__GetCurrentVehicle` | Получает текущий автомобиль |
| `Ped::GetCurrentState` | `Ped__GetPedState` | Получает текущее состояние пешехода |
| `Ped::GetOccupation` | `Ped__GetCurrentOccupation` | Получает текущее занятие пешехода |
| `Ped::GetPed` | `Ped__GetLinkedPed` | Получает связанного пешехода |
| `Ped::GetPositionX` | `Ped__GetXCoordinate` | Получает X координату пешехода |
| `Ped::GetPositionY` | `Ped__GetYCoordinate` | Получает Y координату пешехода |
| `Ped::IsCrouching` | `Ped__GetStance` | Проверяет, приседает ли пешеход |
| `Ped::IsInCar` | `Ped__IsInsideVehicle` | Проверяет, находится ли пешеход в автомобиле |
| `Ped::Ped_Set_FUN_00403a40` | `Ped__Initialize` | Инициализирует пешехода |
| `Ped::S49_FUN_00403960` | `Ped__UpdateState` | Обновляет состояние пешехода |
| `Ped::S49_FUN_00403a50` | `Ped__SetFlags` | Устанавливает флаги пешехода |
| `Ped::S49_FUN_00403a70` | `Ped__SetAnimationState` | Устанавливает состояние анимации |
| `Ped::S49_FUN_00403aa0` | `Ped__EnterCar` | Посадить пешехода в автомобиль |
| `Ped::S49_Get_FUN_004039c0` | `Ped__GetFlags1` | Получает флаги 1 пешехода |
| `Ped::S49_Get_FUN_004039d0` | `Ped__GetFlags2` | Получает флаги 2 пешехода |
| `Ped::S49_Get_FUN_004039e0` | `Ped__GetDamageState` | Получает состояние повреждения |
| `Ped::S49_Get_FUN_00403a60` | `Ped__GetAnimationState` | Получает состояние анимации |
| `Ped::S49_Get_FUN_00403a80` | `Ped__GetActionParam` | Получает параметр действия |
| `Ped::S49_Get_FUN_00403ad0` | `Ped__GetPassenger` | Получает пассажира |
| `Ped::S49_Get_FUN_00403b70` | `Ped__GetExitAnimState` | Получает состояние анимации выхода |
| `Ped::S49_Set_FUN_00403950` | `Ped__ClearFlags` | Очищает флаги пешехода |
| `Ped::SetAutoClass4` | `Ped__SetAIController` | Назначает AI контроллер пешеходу |
| `Ped::SetCarDamageState` | `Ped__SetVehicleDamageState` | Устанавливает состояние повреждения авто |
| `Ped::SetCarId` | `Ped__SetAssignedCarIndex` | Устанавливает индекс назначенного автомобиля |
| `Ped::SetDefault` | `Ped__ResetToDefaults` | Сбрасывает все параметры к значениям по умолчанию |
| `Ped::SetDefaut_Pararam0x228` | `Ped__ResetSpecialParam` | Сбрасывает специальный параметр 0x228 |
| `Ped::SetDriverPed` | `Ped__SetAsDriver` | Назначает пешехода как водителя |
| `Ped::SetExitAnimState` | `Ped__SetExitAnimationState` | Устанавливает состояние анимации выхода |
| `Ped::SetHealthPlayer` | `Ped__SetHealth` | Устанавливает здоровье пешехода |
| `Ped::SetLinkedPed` | `Ped__SetLinkedPedestrian` | Привязывает связанного пешехода |
| `Ped::SetObjectiveTargetCar` | `Ped__SetTargetVehicle` | Устанавливает целевой автомобиль |
| `Ped::SetOccupation` | `Ped__SetCurrentOccupation` | Устанавливает текущее занятие пешехода |
| `Ped::SetSearchType` | `Ped__SetSearchMode` | Устанавливает режим поиска цели |
| `Ped::SetTargetCarDoor` | `Ped__SetTargetCarDoorIndex` | Устанавливает целевую дверь автомобиля |

---

## Registry

| Оригинальное имя | Новое имя | Описание |
|-----------------|-----------|----------|
| `Registry::FUN_00406250` | `Registry__GetDwordValue` | Получает DWORD значение из реестра |
| `Registry::FUN_00407930` | `Registry__LoadAllSettings` | Загружает все настройки из реестра |
| `Registry::GetPlayerNameNetwork` | `Registry__GetNetworkPlayerName` | Получает имя игрока для сети |
| `Registry::GetrRplayNum` | `Registry__GetReplayNumber` | Получает номер повтора из реестра |
| `Registry::RegNetwork` | `Registry__InitNetworkSettings` | Инициализирует сетевые настройки |
| `Registry::Registry_FUN_003f1422` | `Registry__InitReplaySettings` | Инициализирует настройки системы повторов |

---

## Replay

| Оригинальное имя | Новое имя | Описание |
|-----------------|-----------|----------|
| `Replay::PlayReplay` | `Replay__PlaySegment` | Воспроизводит сегмент повтора игры |
| `Replay::StartPlayReplay` | `Replay__StartPlayback` | Запускает воспроизведение повтора |

---

## S169

| Оригинальное имя | Новое имя | Описание |
|-----------------|-----------|----------|
| `S169::AreAnyPedActive` | `PedManager__HasActivePeds` | Проверяет наличие активных пешеходов |
| `S169::FUN_00403be0` | `PedManager__UpdateAll` | Обновляет всех пешеходов |
| `S169::FUN_00403da0` | `PedManager__ProcessPeds` | Обрабатывает всех пешеходов |
| `S169::FUN_00403e90` | `PedManager__UpdatePedStates` | Обновляет состояния пешеходов |
| `S169::FUN_00403fb0` | `PedManager__HandlePedAction` | Обрабатывает действие пешехода |
| `S169::FUN_00404120` | `PedManager__SetPedIndex` | Устанавливает индекс пешехода |
| `S169::FUN_00404450` | `PedManager__GetPedCount` | Получает количество пешеходов |
| `S169::FUN_00404480` | `PedManager__ClearAll` | Очищает всех пешеходов |
| `S169::FUN_00404490` | `PedManager__GetPedByIndex` | Получает пешехода по индексу |
| `S169::FUN_00404d40` | `PedManager__RemovePed` | Удаляет пешехода из менеджера |
| `S169::FUN_00404ef0` | `PedManager__ProcessGroup` | Обрабатывает группу пешеходов |
| `S169::FUN_00405240` | `PedManager__UpdateGroup` | Обновляет группу пешеходов |
| `S169::S169_FUN_00403c40` | `PedManager__CheckPedStatus` | Проверяет статус пешехода |

---

## SpriteS1

| Оригинальное имя | Новое имя | Описание |
|-----------------|-----------|----------|
| `SpriteS1::FUN_00401ad0` | `SpriteS1__LinkToS3` | Привязывает спрайт к структуре S3 |

---

## Style

| Оригинальное имя | Новое имя | Описание |
|-----------------|-----------|----------|
| `Style::FUN_00402cf0` | `StyleLoader_Load` | Загружает стиль |

---

## Utility

| Оригинальное имя | Новое имя | Описание |
|-----------------|-----------|----------|
| `CreateBuffer` | `Memory_Allocate` | Выделяет память |
| `DecoderFloat` | `Decoder_DecodeFloat` | Декодирует float |
| `Error` | `ErrorHandler_Throw` | Выбрасывает ошибку |
| `FUN_003f1004` | `FindNearestPlayer` | Находит ближайшего игрока |
| `FUN_003f10b0` | `Callback_MissionComplete` | Вызывается при завершении миссии |
| `FUN_003f1314` | `CheckPlayerLimit` | Проверяет лимит игроков |
| `FUN_003f1338` | `ValidatePlayerAction` | Проверяет действие игрока |
| `FUN_003f135c` | `ShouldPauseGame` | Определяет, нужно ли паузировать игру |
| `FUN_003f1380` | `SaveGameData` | Сохраняет данные игры |
| `FUN_003f14c0` | `CopyObject` | Копирует объект |
| `FUN_003f14d8` | `InitializeGlobals` | Инициализирует глобальные переменные |
| `FUN_003f158c` | `ProcessReplayData` | Обрабатывает данные повтора |
| `FUN_003f15bc` | `InitReplaySystem` | Инициализирует систему повторов |
| `FUN_003f1614` | `GetMissionStatus` | Получает статус миссии |
| `FUN_003f1674` | `UpdateMissionTimer` | Обновляет таймер миссии |
| `FUN_003f1afa` | `MainGameLoop` | Основной игровой цикл |
| `FUN_00401050` | `Math_ScaleVector` | Масштабирует вектор |
| `FUN_00401080` | `Math_RotatePoint` | Вращает точку |
| `FUN_004010e0` | `Math_TransformCoords` | Трансформирует координаты |
| `FUN_00401180` | `Math_CalculateNormal` | Вычисляет нормаль |
| `FUN_004012c0` | `Renderer_SetTransform` | Устанавливает трансформацию |
| `FUN_004012f0` | `Renderer_Reset` | Сбрасывает рендерер |
| `FUN_004018a0` | `Pool_Allocate` | Выделяет память из пула |
| `FUN_004018c0` | `Pool_Free` | Освобождает память пула |
| `FUN_004019a0` | `Pool_Init` | Инициализирует пул |
| `FUN_00401ae0` | `Decoder_SetValue` | Устанавливает значение декодера |
| `FUN_00401b90` | `Decoder_ReadInt` | Читает int из декодера |
| `FUN_00401c60` | `CarPool_Get` | Получает автомобиль из пула |
| `FUN_00401c80` | `PedPool_Get` | Получает пешехода из пула |
| `FUN_00401d20` | `String_ParseLine` | Разбирает строку |
| `FUN_00402180` | `DataStream_Read` | Читает поток данных |
| `FUN_004021e0` | `DataStream_Allocate` | Выделяет поток данных |
| `FUN_004023e0` | `DataStream_Close` | Закрывает поток данных |
| `FUN_00402f00` | `ErrorHandler_Init` | Инициализирует обработчик ошибок |
| `FUN_00403040` | `Checksum_Calculate` | Вычисляет контрольную сумму |
| `FUN_004035a0` | `Direct3D_CreateDevice` | Создает устройство D3D |
| `FUN_004035e0` | `Direct3D_SetRenderState` | Устанавливает состояние рендера |
| `FUN_00403650` | `Direct3D_CheckCaps` | Проверяет возможности D3D |
| `FUN_00403770` | `Texture_Load` | Загружает текстуру |
| `FUN_00403780` | `Texture_Find` | Находит текстуру |
| `FUN_00403840` | `Matrix_Multiply` | Умножает матрицы |
| `FUN_00403870` | `Matrix_Identity` | Создает единичную матрицу |
| `FUN_004048a0` | `PathFind_CalculateRoute` | Вычисляет маршрут |
| `FUN_00404900` | `PathFind_SetTarget` | Устанавливает цель пути |
| `FUN_00404ad0` | `PathFind_UpdatePosition` | Обновляет позицию на пути |
| `FUN_00404ce0` | `PedGroup_RemoveMember` | Удаляет пешехода из группы |
| `FUN_00405a40` | `Memory_Free` | Освобождает память |
| `FUN_00405a50` | `Memory_Set` | Устанавливает память |
| `FUN_00405b10` | `UI_CreateDialog` | Создает диалог |
| `FUN_00405b20` | `UI_DestroyDialog` | Уничтожает диалог |
| `FUN_00405b50` | `UI_SetTextW` | Устанавливает текст Unicode |
| `FUN_004061c0` | `Config_Load` | Загружает конфиг |
| `FUN_00406210` | `Config_GetInt` | Получает int из конфига |
| `FUN_00406220` | `Config_GetBool` | Получает bool из конфига |
| `FUN_00406230` | `Config_GetFloat` | Получает float из конфига |
| `FUN_00406240` | `Config_GetString` | Получает string из конфига |
| `FUN_004063c0` | `Network_Connect` | Подключается к сети |
| `FUN_00406450` | `Network_SendData` | Отправляет данные |
| `FUN_00406470` | `Network_ReceiveData` | Получает данные |
| `FUN_0040653e` | `Network_Disconnect` | Отключается от сети |
| `FUN_00406550` | `String_Hash1` | Хеш функции строки 1 |
| `FUN_00406570` | `String_Hash2` | Хеш функции строки 2 |
| `FUN_00406590` | `String_Hash3` | Хеш функции строки 3 |
| `FUN_004065f0` | `UI_InitDialog` | Инициализирует диалог |
| `FUN_00406660` | `UI_CloseDialog` | Закрывает диалог |
| `FUN_0040667c` | `UI_SetControlText` | Устанавливает текст контроля |
| `FUN_004066e0` | `UI_CreateButton` | Создает кнопку |
| `FUN_00406720` | `UI_CreateLabel` | Создает метку |
| `FUN_004068c0` | `UI_CreateEdit` | Создает поле ввода |
| `FUN_00406980` | `UI_CreateListBox` | Создает список |
| `FUN_00406b10` | `UI_CreateCombo` | Создает комбобокс |
| `FUN_00406b80` | `UI_CreateCheckbox` | Создает чекбокс |
| `FUN_00406bc0` | `UI_AllocateControl` | Выделяет контроль |
| `FUN_00406c92` | `UI_SetEnabled` | Включает/выключает контроль |
| `FUN_00406cc0` | `UI_SetTextW2` | Устанавливает текст Unicode 2 |
| `FUN_00406e40` | `UI_DestroyControl` | Уничтожает контроль |
| `FUN_00406f20` | `UI_GetTextW` | Получает текст Unicode |
| `FUN_00407030` | `UI_CopyData` | Копирует данные UI |
| `FUN_00407070` | `UI_ClearData` | Очищает данные UI |
| `FUN_0040720d` | `UI_SetProperty` | Устанавливает свойство |
| `FUN_00407362` | `UI_UpdateLayout` | Обновляет layout |
| `FUN_004073d0` | `UI_ProcessMessage` | Обрабатывает сообщение |
| `FUN_00407402` | `UI_HandleInput` | Обрабатывает ввод |
| `FUN_00407476` | `Debug_Print` | Вывод отладки |
| `FUN_0040748d` | `Debug_Update` | Обновление отладки |
| `FUN_004075c0` | `Console_AddLine` | Добавляет строку в консоль |
| `FUN_00407800` | `Options_LoadFromRegistry` | Загружает опции из реестра |
| `FUN_00407c90` | `Multiplayer_JoinGame` | Присоединиться к игре |
| `FUN_00407d10` | `Multiplayer_LeaveGame` | Покинуть игру |
| `FUN_00407d8b` | `Multiplayer_UpdateLobby` | Обновить лобби |
| `FUN_004086a0` | `WindowProc_Handler` | Обработчик оконных сообщений |
| `Fread` | `DataStream_ReadBlock` | Читает блок данных |
| `InitDirectX` | `DirectX_Initialize` | Инициализирует DirectX |
| `MessageBoXErrorOpenFile` | `UI_ShowFileError` | Показывает ошибку файла |
| `PedGroupAddPed` | `PedGroup_AddMember` | Добавляет пешехода в группу |
| `S110_FUN_00401b40` | `Decoder_ProcessData` | Обрабатывает данные декодера |
| `ShowWindows` | `UI_ShowWindow` | Показывает окно |
| `__chkstk` | `Stack_Check` | Проверяет стек |
| `bitShiftLeft1` | `Decoder_ShiftLeft` | Сдвиг влево |

---

## Пример замены в коде

```cpp
// Было:
void __thiscall Game::Game_FUN_003f113c(Game *this);

// Стало:
void __thiscall Game__GetCurrentPlayerSlot(Game *this);
```

## Статистика

- Всего переименовано функций: **181**
- Категорий: **14**
