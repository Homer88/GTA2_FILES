# Отчёт о переименовании функций транспорта GTA2

## Статус проекта
- **Дата**: 2024
- **Версия анализа**: gta2.exe
- **Иерархия**: S82 (BaseCar, 0x68) → S81 (PublicTransport, 0x7C)

## Критические исправления

### 1. Исправлена иерархия транспорта
**До**: S81 и S82 имели некорректную структуру
**После**: 
- S82 (BaseCar) = 0x68 байт, базовый класс физики
- S81 (PublicTransport) = 0x7C байт, наследник с логикой маршрутов
- Поле `RouteID` заменено на `RouteNodesPtr` (указатель на массив узлов)

### 2. Файлы с переименованными функциями

#### /src/entities/car.c
Функции класса Car с комментариями старых имён:

| Новое имя | Старое имя | Адрес | Описание |
|-----------|------------|-------|----------|
| `Car::CheckCarCondition` | `Car_FUN_00403820` | 0x00403820 | Проверка состояния автомобиля |
| `CarsPrefabs::InitializeCarPrefab` | `S5_FUN_0040f490` | 0x0040f490 | Инициализация префаба машины |
| `Car::IsCarUsable` | `FUN_004112a0` | 0x004112a0 | Проверка доступности авто |
| `Car::UpdateCarElectronics` | `FUN_00416bb0` | 0x00416bb0 | Обновление электроники |
| `CarDoor::ResetDoorState` | `Set_FUN_0041f6c0` | 0x0041f6c0 | Сброс состояния двери |
| `Car::UpdateCarMovement` | `FUN_0041f8f0` | 0x0041f8f0 | Обновление движения |
| `Car::ApplyHandbrake` | `Car_FUN_0041fab0` | 0x0041fab0 | Применение ручника |
| `Car::StartCarEngine` | `FUN_0041fac0` | 0x0041fac0 | Запуск двигателя |
| `Car::StopCarEngine` | `FUN_0041fbb0` | 0x0041fbb0 | Остановка двигателя |
| `Car::DamageCarFromImpact` | `Car_FUN_00420840` | 0x00420840 | Урон от столкновения |
| `CarSystemManager::GetCarByIndex` | `CarSystemManager_FUN_00420a10` | 0x00420a10 | Получить машину по индексу |
| `CarSystemManager::ResetCarSystem` | `CarSystemManager_FUN_00420c00` | 0x00420c00 | Сброс системы машин |
| `CarsPrefabs::ReleaseCarPrefab` | `S5_FUN_00420f20` | 0x00420f20 | Освобождение префаба |
| `CarsPrefabs::CloneCarPrefab` | `S5_FUN_00420f30` | 0x00420f30 | Клонирование префаба |
| `CarSystemManager::CleanupCarSystem` | `CarSystemManager_FUN_004212d0` | 0x004212d0 | Очистка системы |
| `CarDoor::InitDoor` | `S7` | 0xXXXXX | Инициализация двери |
| `Car::CheckCarOccupied` | `CheckCarOccupied` | 0xXXXXX | Проверка занятости |
| `Car::CountCarOccupants` | `CountCarOccupants` | 0xXXXXX | Подсчёт пассажиров |
| `Car::PrepareCarForEntry` | `Car_Set_FUN_00421460` | 0x00421460 | Подготовка к посадке |
| `Car::ValidateCarExit` | `ValidateCarExit` | 0xXXXXX | Проверка выхода |
| `Car::BoardCarAsDriver` | `FUN_00421490` | 0x00421490 | Посадка водителем |
| `Car::BoardCarAsPassenger` | `BoardCarAsPassenger` | 0xXXXXX | Посадка пассажиром |
| `Car::DisembarkCar` | `DisembarkCar` | 0xXXXXX | Высадка из машины |
| `Car::MakeCarDriveableAdvanced` | `CarMakeDriveable2` | 0xXXXXX | Сделать управляемой (расш.) |
| `Car::ReadCarDoorAngle` | `ReadCarDoorAngle` | 0xXXXXX | Чтение угла двери |
| `Car::WriteCarDoorAngle` | `WriteCarDoorAngle` | 0xXXXXX | Запись угла двери |
| `Car::MakeCarDriveableBasic` | `CarMakeDriveable1` | 0xXXXXX | Сделать управляемой (баз) |
| `Car::FixCarBrokenEngine` | `FixCarBrokenEngine` | 0xXXXXX | Ремонт двигателя |
| `Car::SwingCarDoorOpen` | `SwingCarDoorOpen` | 0xXXXXX | Открыть дверь |
| `Car::ShutCarDoor` | `ShutCarDoor` | 0xXXXXX | Закрыть дверь |
| `Car::EngageCarDoorLocks` | `EngageCarDoorLocks` | 0xXXXXX | Заблокировать двери |
| `Car::DisengageCarDoorLocks` | `DisengageCarDoorLocks` | 0xXXXXX | Разблокировать двери |
| `Car::InspectCarWheel` | `InspectCarWheel` | 0xXXXXX | Проверка колеса |
| `Car::RepairCarWheel` | `RepairCarWheel` | 0xXXXXX | Ремонт колеса |
| `Car::CheckCarLights` | `CheckCarLights` | 0xXXXXX | Проверка фар |
| `Car::ControlCarLights` | `ControlCarLights` | 0xXXXXX | Управление фарами |
| `Car::SetTaxiLightState` | `has_for_hire_lights` | 0xXXXXX | Такси-огонёк |
| `Car::FlashCarLights` | `FlashCarLights` | 0xXXXXX | Моргнуть фарами |
| `Car::UpdateCarAlarm` | `Car_FUN_00421700` | 0x00421700 | Обновление сигнализации |
| `Car::IsCarAlarmActive` | `Car_FUN_00421720` | 0x00421720 | Активна ли сигнализация |
| `Car::GetCarSirenState` | `Car_FUN_00421740` | 0x00421740 | Состояние сирены |
| `Car::GetCarHornState` | `Car_FUN_00421760` | 0x00421760 | Состояние гудка |
| `Car::UpdateCarRadar` | `Car_FUN_00421810` | 0x00421810 | Обновление радара |
| `Car::IsCarTargetable` | `Car_FUN_00421830` | 0x00421830 | Можно ли целиться |
| `Car::RequestCarDamage` | `Car_FUN_00420840` | 0x00420840 | Запрос ущерба (дубликат) |
| `Car::SetCarSpecialMode` | `Car_FUN_00421890` | 0x00421890 | Спецрежим |
| `Car::ResetCarWeapons` | `FUN_004218a0` | 0x004218a0 | Сброс оружия |
| `Car::UpdateCarTurret` | `Car_FUN_004218b0` | 0x004218b0 | Обновление турели |
| `Car::ClearCarPassengers` | `FUN_004218c0` | 0x004218c0 | Очистить пассажиров |
| `Car::ResetCarState` | `FUN_004218d0` | 0x004218d0 | Сброс состояния |
| `Car::RefreshCarVisuals` | `Car_FUN_004218e0` | 0x004218e0 | Обновить визуал |
| `Car::GetCarTransmissionState` | `Car_FUN_004218f0` | 0x004218f0 | Состояние трансмиссии |
| `Car::SetCarRadioStation` | `Car_FUN_00421900` | 0x00421900 | Установка радио |
| `Car::SetEngineSound` | `SetSound` | 0xXXXXX | Звук двигателя |
| `CarSystemManager::ProcessAllCars` | `CarSystemManager_FUN_00421960` | 0x00421960 | Обработка всех машин |
| `CarDoor::AttachTurret` | `FUN_00421a00` | 0x00421a00 | Прикрепить турель |
| `CarDoor::DetachTurret` | `FUN_00421a80` | 0x00421a80 | Открепить турель |
| `CarDoor::UpdateTurretPosition` | `FUN_00421af0` | 0x00421af0 | Обновить позицию турели |
| `Car::ProcessCarComponent` | `FUN_00421c40` | 0x00421c40 | Обработка компонента |
| `Car::CleanupCarExtras` | `Car_FUN_00421d80` | 0x00421d80 | Очистка дополнений |
| `Car::CopyCarData` | `Car_FUN_00421d90` | 0x00421d90 | Копирование данных |
| `Car::FinalizeCarInit` | `Car_FUN_00421df0` | 0x00421df0 | Завершение инициализации |
| `Car::GetCarTransformMatrix` | `FUN_00421e70` | 0x00421e70 | Матрица трансформации |
| `Car::GetCarGameObject` | `Car_FUN_00421ec0` | 0x00421ec0 | Получить игровой объект |
| `Car::SetCarRemapTexture` | `Car_FUN_00421f40` | 0x00421f40 | Текстура перекраски |
| `Car::SetCarPaintJobIndex` | `FUN_00421f80` | 0x00421f80 | Индекс краски |
| `Car::IsCarVisible` | `Car_FUN_004220a0` | 0x004220a0 | Видима ли машина |
| `Car::AssignPedToCar` | `Car_FUN_004221d0` | 0x004221d0 | Назначить педа машине |
| `Car::RemoveCarOccupants` | `Car_FUN_00422230` | 0x00422230 | Удалить occupants |
| `Car::EjectAllOccupants` | `Car_FUN_00422260` | 0x00422260 | Вышвырнуть всех |
| `Car::ExplodeCar` | `FUN_004222d0` | 0x004222d0 | Взорвать машину |
| `Car::IgniteCarFuel` | `FUN_004222f0` | 0x004222f0 | Поджечь топливо |
| `Car::CanPedEnterCar` | `Car_FUN_00422360` | 0x00422360 | Может ли пед сесть |
| `Car::UpdateCarAI` | `Car_FUN_00422670` | 0x00422670 | Обновление ИИ |
| `Car::SetCarDriver` | `Car_FUN_004226c0` | 0x004226c0 | Установить водителя |
| `Car::StartCarMission` | `Car_FUN_004228f0` | 0x004228f0 | Начать миссию |
| `Car::StopCarMission` | `Car_FUN_00422980` | 0x00422980 | Остановить миссию |
| `Car::UpdateCarPathfinding` | `Car_FUN_00422a40` | 0x00422a40 | Поиск пути |
| `Car::AvoidCarObstacles` | `Car_FUN_00422b70` | 0x00422b70 | Избегание препятствий |
| `Car::FollowCarRoute` | `Car_FUN_00422cb0` | 0x00422cb0 | Следование маршруту |
| `Car::ParkCar` | `Car_FUN_00422d20` | 0x00422d20 | Припарковать |
| `Car::UnparkCar` | `Car_FUN_00422d80` | 0x00422d80 | Выехать с парковки |
| `Car::FleeCarFromDanger` | `Car_FUN_00422de0` | 0x00422de0 | Побег от опасности |
| `Car::AimCarTurret` | `Car_FUN_00422e00` | 0x00422e00 | Прицелить турель |
| `Car::FireCarWeapon` | `Car_FUN_00422f00` | 0x00422f00 | Огонь из оружия |
| `Car::IsCarWeaponReady` | `Car_FUN_004230d0` | 0x004230d0 | Готово ли оружие |
| `Car::SpawnCarWithParams` | `Car_FUN_00423230` | 0x00423230 | Спавн с параметрами |
| `Car::DespawnCar` | `Car_FUN_00423290` | 0x00423290 | Деспавн |
| `Car::RespawnCar` | `Car_FUN_004232e0` | 0x004232e0 | Респавн |
| `Car::WarpCarToLocation` | `Car_FUN_004233b0` | 0x004233b0 | Телепортация |
| `Car::GetCarDriver` | `Car_FUN_00423480` | 0x00423480 | Получить водителя |
| `Car::RemovePedFromCar` | `Car_FUN_00423590` | 0x00423590 | Удалить педа |
| `Car::KillCarDriver` | `Car_FUN_004235d0` | 0x004235d0 | Убить водителя |
| `Car::GetCarSpeed` | `FUN_00423630` | 0x00423630 | Получить скорость |
| `Car::SetCarAlertState` | `Car_FUN_00423720` | 0x00423720 | Уровень тревоги |
| `Car::ResetCarAlert` | `Car_FUN_00423830` | 0x00423830 | Сброс тревоги |
| `Car::SetCarTarget` | `Car_FUN_00423940` | 0x00423940 | Установить цель |
| `Car::ClearCarTarget` | `Car_FUN_00423a50` | 0x00423a50 | Сброс цели |

#### Не переименованные функции (требуют анализа):
- `Car::Car_FUN_00423aa0` (0x00423aa0)
- `Car::FUN_00423b30` (0x00423b30)
- `Car::Car_FUN_00424010` (0x00424010)
- `Car::Car_FUN_00424090` (0x00424090)
- `Car::Car_FUN_004241c0` (0x004241c0)
- `Car::car_FUN_00424220` (0x00424220)
- `Car::Car_FUN_004243c0` (0x004243c0)

#### /src/structures/BusInfo.c
Функции работы с общественным транспортом:

| Новое имя | Старое имя | Адрес | Описание |
|-----------|------------|-------|----------|
| `BusInfo_UpdateScreenPosition` | `S285__FUN_00432c60` | 0x00432c60 | Обновление экранной позиции |
| `BusInfo_InitRoute` | (новая) | - | Инициализация маршрута |
| `BusInfo_GetCurrentNode` | (новая) | - | Получить текущий узел |
| `BusInfo_AdvanceToNextNode` | (новая) | - | Перейти к следующему узлу |
| `BusInfo_IsAtStop` | (новая) | - | Проверка остановки |

## Структуры данных

### S82_BaseCar (0x68 байт)
Базовый класс автомобиля. Содержит:
- Позицию и ориентацию (0x00-0x0F)
- Физику (0x10-0x1F)
- Состояние (0x20-0x2F)
- Управление и таймеры (0x30-0x3B)
- Дополнительные параметры (0x48-0x67)

### S81_PublicTransport (0x7C байт)
Наследник S82_BaseCar. Содержит:
- Все поля BaseCar (0x00-0x67)
- RouteNodesPtr (0x68) - указатель на маршрут
- CurrentRouteIndex/NextRouteIndex (0x6C-0x6E)
- StopTimer (0x70)
- RouteFlags/StopState/Priority (0x74-0x76)
- RouteID (0x78)

## Переменные с комментариями

При переносе переменных сохраняйте старые имена в комментариях:
```c
// Было: RouteID
// Стало: RouteNodesPtr
RouteNode* RouteNodesPtr;

// Было: field14_0x30
// Стало: CurrentRouteIndex
u16 CurrentRouteIndex;
```

## Следующие шаги
1. [ ] Переименовать оставшиеся функции FUN_XXXXXX
2. [ ] Исправить структуры в structures_s.h
3. [ ] Добавить комментарии ко всем переменным
4. [ ] Создать тесты для PublicTransport
5. [ ] Реализовать логику маршрутов
