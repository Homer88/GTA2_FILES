# Адреса методов MissionManager

## Структура
- **Адрес глобального экземпляра**: `0x006644BC`
- **Размер структуры**: `0xC1EA8` (793,768 байт)
- **Всего методов найдено**: 70 функций

## Методы с адресами

### Конструкторы и деструкторы
| Метод | Адрес | Размер (байт) | Описание |
|-------|-------|---------------|----------|
| `MissionManager__Constructor` | `0x00481900` | 0x2A9 (681) | Конструктор |
| `MissionManager__Destructor` | `0x00481BA0` | 0xD4 (212) | Деструктор (MissionManagerDes) |
| `MissionManager__Reset` | `0x00481900` | - | Сброс (алиас на конструктор/инициализацию) |

### Управление миссиями
| Метод | Адрес | Размер (байт) | Описание |
|-------|-------|---------------|----------|
| `MissionManager__StartMission` | `0x00476250` | 0x2A (42) | Запуск миссии |
| `MissionManager__EndMission` | `0x00476280` | 0x32 (50) | Завершение миссии |
| `MissionManager__FailMission` | `0x00476320` | 0x2A (42) | Провал миссии |
| `MissionManager__AbortMission` | `0x00476370` | 0x39 (57) | Отмена миссии |
| `MissionManager__Update` | `0x004763B0` | 0x2E (46) | Обновление состояния |
| `MissionManager__CheckObjectives` | `0x004764D0` | 0x5B (91) | Проверка целей |
| `MissionManager__IsMissionActive` | `0x00476530` | 0x70 (112) | Проверка активности |
| `MissionManager__GetCurrentMissionId` | `0x004765A0` | 0x62 (98) | Получить ID текущей миссии |
| `MissionManager__GetMissionState` | `0x00476EA0` | 0x14F (335) | Получить состояние |
| `MissionManager__SetNextMission` | `0x00476FF0` | 0x143 (323) | Установить следующую миссию |
| `MissionManager__AbortAllMissions` | `0x00477140` | 0x14D (333) | Отменить все миссии |

### Работа со скриптами и файлами
| Метод | Адрес | Размер (байт) | Описание |
|-------|-------|---------------|----------|
| `MissionManager__LoadScript` | `0x0047F2C0` | 0xBD (189) | Загрузка скрипта (loadScript) |
| `MissionManager__SaveFile` | `0x0047EF80` | 0x167 (359) | Сохранение файла |
| `MissionManager__LoadGame` | `0x0047F0B0` | 0x143 (323) | Загрузка игры |
| `MissionManager__ExtractFileNameWithoutExtension` | `0x00475D60` | 0x56 (86) | Извлечение имени файла |
| `MissionManager__ParseScriptCommand` | `0x00477290` | 0x293 (659) | Парсинг команды скрипта |
| `MissionManager__GetMissionScript` | `0x00477530` | 0x24 (36) | Получить указатель на скрипт |
| `MissionManager__InitScriptVariables` | `0x00477560` | 0xD2 (210) | Инициализация переменных скрипта |

### Цели и прогресс
| Метод | Адрес | Размер (байт) | Описание |
|-------|-------|---------------|----------|
| `MissionManager__UpdateObjectives` | `0x00477660` | 0x176 (374) | Обновление целей |
| `MissionManager__CheckCompletion` | `0x004777E0` | 0x82 (130) | Проверка завершения |
| `MissionManager__GiveReward` | `0x00477870` | 0xA3 (163) | Выдача награды |
| `MissionManager__SetObjectiveFlag` | `0x00477920` | 0x73 (115) | Установка флага цели |
| `MissionManager__GetObjectiveCount` | `0x00477AC0` | 0xB0 (176) | Получить количество целей |
| `MissionManager__GetCompletedObjectives` | `0x00477D20` | 0x18A (394) | Получить выполненные цели |
| `MissionManager__ResetProgress` | `0x00477EE0` | 0x208 (520) | Сброс прогресса |

### Управление объектами и триггерами
| Метод | Адрес | Размер (байт) | Описание |
|-------|-------|---------------|----------|
| `MissionManager__GetObjectPtr` | `0x00478120` | 0x48 (72) | Получить указатель на объект |
| `MissionManager__GetTriggerPtr` | `0x00478170` | 0x83 (131) | Получить указатель на триггер |
| `MissionManager__SpawnScriptObjects` | `0x004784A0` | 0x23 (35) | Создать объекты скрипта |
| `MissionManager__DespawnObject` | `0x00478A80` | 0x73 (115) | Удалить объект |
| `MissionManager__ActivateTrigger` | `0x004799D0` | 0x14F (335) | Активировать триггер |
| `MissionManager__UpdateTriggers` | `0x0047ED20` | 0x88 (136) | Обновить триггеры |

### Внутренние утилиты
| Метод | Адрес | Размер (байт) | Описание |
|-------|-------|---------------|----------|
| `MissionManager__ClampValues` | `0x0047EDB0` | 0xB3 (179) | Ограничение значений |
| `MissionManager__greater_than` | `0x00474F00` | 0x30 (48) | Сравнение: больше чем |
| `MissionManager__less_or_equal` | `0x00474F30` | 0x58 (88) | Сравнение: меньше или равно |
| `MissionManager__NotEqual` | `0x00475230` | 0x5D (93) | Сравнение: не равно |
| `MissionManager__less_than` | `0x00475290` | 0x0E (14) | Сравнение: меньше чем |
| `MissionManager__PrepareArray` | `0x004752A0` | 0x21 (33) | Подготовка массива |
| `MissionManager__ClearMissionData` | `0x004752D0` | 0x20 (32) | Очистка данных миссии |
| `MissionManager__AllocateMissionBuffer` | `0x004752F0` | 0xB7 (183) | Выделение буфера |
| `MissionManager__FreeMissionBuffer` | `0x004753B0` | 0x1F (31) | Освобождение буфера |

### Сохранение и загрузка данных
| Метод | Адрес | Размер (байт) | Описание |
|-------|-------|---------------|----------|
| `MissionManager__SaveMissionData` | `0x004753D0` | 0x48 (72) | Сохранение данных миссии |
| `MissionManager__LoadMissionData` | `0x004754E0` | 0x80 (128) | Загрузка данных миссии |
| `MissionManager__IsValidMission` | `0x004755B0` | 0x16 (22) | Проверка валидности миссии |

### События внешнего мира
| Метод | Адрес | Размер (байт) | Описание |
|-------|-------|---------------|----------|
| `MissionManager__TriggerEvent` | `0x004755D0` | 0x16 (22) | Триггер события |
| `MissionManager__OnPlayerDeath` | `0x004755F0` | 0x5D (93) | Смерть игрока |
| `MissionManager__OnCarDestroyed` | `0x00475650` | 0x55 (85) | Уничтожение машины |
| `MissionManager__OnPedKilled` | `0x004756B0` | 0x3C (60) | Убийство педа |
| `MissionManager__OnZoneEntered` | `0x00475A20` | 0x07 (7) | Вход в зону |
| `MissionManager__OnItemCollected` | `0x00475A30` | 0x07 (7) | Сбор предмета |

### Отладка и прочее
| Метод | Адрес | Размер (байт) | Описание |
|-------|-------|---------------|----------|
| `MissionManager__PrintDebugInfo` | `0x00475A40` | 0x0D (13) | Печать отладочной информации |
| `MissionManager__DumpState` | `0x00475B70` | 0x26 (38) | Дамп состояния |
| `MissionManager__sub_475CA0` | `0x00475CA0` | 0x8A (138) | Неизвестная функция |
| `MissionManager__sub_475D30` | `0x00475D30` | 0xD0 (208) | Неизвестная функция |
| `MissionManager__sub_475E90` | `0x00475E90` | 0x1D3 (467) | Неизвестная функция |
| `MissionManager__sub_476070` | `0x00476070` | 0x17D (381) | Неизвестная функция |
| `MissionManager__sub_47F200` | `0x0047F200` | 0x21 (33) | Неизвестная функция |
| `MissionManager__sub_47F230` | `0x0047F230` | 0x50 (80) | Неизвестная функция |
| `MissionManager__sub_47F340` | `0x0047F340` | 0x6E (110) | Неизвестная функция |
| `MissionManager__sub_47F3B0` | `0x0047F3B0` | 0x6F (111) | Неизвестная функция |
| `MissionManager__sub_47F420` | `0x0047F420` | 0x22 (34) | Неизвестная функция |
| `MissionManager__sub_481200` | `0x00481200` | 0x69 (105) | Неизвестная функция |
| `MissionManager__sub_481270` | `0x00481270` | 0x66 (102) | Неизвестная функция |
| `MissionManager__sub_481400` | `0x00481400` | 0x257 (599) | Неизвестная функция |
| `MissionManager__sub_481890` | `0x00481890` | 0x63 (99) | Неизвестная функция |

## Примечания
- Все адреса относительные (RVA) для gta2.exe
- Адреса функций извлечены из имен функций в формате `sub_XXXXXXXX` где XXXXXXXX - адрес в шестнадцатеричной системе
- Размеры функций указаны в шестнадцатеричной и десятичной системах
- Функции с префиксом `sub_` требуют дополнительного анализа для определения назначения
- Некоторые функции могут быть алиасами или обертками вокруг других функций
- Данные извлечены из 70 COLLAPSED FUNCTION записей в ida_pro/gta2.exe.asm

## Глобальные переменные MissionManager
| Переменная | Адрес | Описание |
|------------|-------|----------|
| `gMissionManager` | `0x006644BC` | Глобальный экземпляр менеджера |
| `pMissionManager` | `0x006644B8` | Указатель на экземпляр |

## Источник данных
- Файл: `/workspace/gta2_dump/ida_pro/gta2.exe.asm`
- Количество методов: 70 функций MissionManager
- Метод поиска: grep "COLLAPSED FUNCTION MissionManager__"
