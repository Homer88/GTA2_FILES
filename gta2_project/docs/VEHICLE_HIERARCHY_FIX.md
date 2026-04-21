# Исправление иерархии транспорта GTA2

## Дата: 2024
## Статус: ✅ ЗАВЕРШЕНО

---

## 📋 ОБЗОР ИЗМЕНЕНИЙ

Критическая ошибка в иерархии транспортных средств была исправлена. Ранее структуры S81 и S82 были перепутаны, что приводило к некорректной работе физики и логики маршрутов.

---

## 🔍 ПРОБЛЕМА

### Исходное состояние (НЕВЕРНО):
```
S81 (0x7C байт) = BaseCar ❌
S82 (0x68 байт) = PublicTransport ❌
```

**Последствия:**
- Неправильные смещения полей в коде
- Ошибки при доступе к RouteNodesPtr
- Некорректная работа физики автомобилей
- Проблемы с наследованием в декомпилированном коде

---

## ✅ РЕШЕНИЕ

### Исправленная иерархия (ВЕРНО):
```
S82 (0x68 байт) = BaseCar (БАЗОВЫЙ КЛАСС)
  └── Физика, позиция, скорость, коллизии
  
S81 (0x7C байт) = PublicTransport (НАСЛЕДНИК)
  └── Маршруты, остановки, пассажиры
  └── Наследует первые 0x68 байт от S82
```

### Структуры:

#### S82_BaseCar (0x68 байт)
```c
struct S82_BaseCar {
    f32 PositionX, Y, Z;      // 0x00-0x08
    f32 Heading;              // 0x0C
    f32 Speed, Acceleration;  // 0x10-0x14
    f32 Mass, Friction;       // 0x18-0x1C
    u32 VehicleType;          // 0x20
    s32 Health, MaxHealth;    // 0x24-0x28
    u32 Flags, State;         // 0x2C-0x30
    u32 Timer;                // 0x34
    u16 PassengerCount;       // 0x38
    u8 TrafficLightState;     // 0x3A
    u8 DoorState;             // 0x3B
    f32 VelocityX, Y;         // 0x3C-0x40
    f32 AngularVelocity;      // 0x44
    u32 DamageFlags;          // 0x48
    u32 LightState;           // 0x4C
    u8 EngineOn, Handbrake;   // 0x50-0x51
    u8 Reserved[2];           // 0x52-0x53
    f32 SuspensionHeight;     // 0x54
    u32 WheelRotation[2];     // 0x58-0x5C
    u8 Padding[8];            // 0x60-0x67
};                            // === 0x68 байт ===
```

#### S81_PublicTransport (0x7C байт)
```c
struct S81_PublicTransport {
    struct S82_BaseCar Base;        // 0x00-0x67 (наследование)
    
    // Специфика общественного транспорта
    struct RouteNode* RouteNodesPtr;// 0x68 - маршрут
    u16 CurrentRouteIndex;          // 0x6C
    u16 NextRouteIndex;             // 0x6E
    u32 StopTimer;                  // 0x70
    u8 RouteFlags;                  // 0x74
    u8 StopState;                   // 0x75
    u8 Priority;                    // 0x76
    u8 Reserved;                    // 0x77
    u32 RouteID;                    // 0x78
};                                  // === 0x7C байт ===
```

---

## 📁 ИЗМЕНЁННЫЕ ФАЙЛЫ

### 1. `/include/entities/vehicle_types.h`
- ✅ Исправлено определение S82 как BaseCar
- ✅ Исправлено определение S81 как PublicTransport
- ✅ Добавлены комментарии о наследовании
- ✅ Обновлены прототипы функций

### 2. `/include/entities/public_transport.h` (НОВЫЙ)
- ✅ Полная структура PublicTransport с расширениями
- ✅ Структура S83_TrainComponent для поездов
- ✅ Прототипы всех функций S81 с комментариями адресов

### 3. `/src/vehicles/public_transport.c` (НОВЫЙ)
- ✅ Реализация ключевых функций PublicTransport
- ✅ Комментарии "// Было: FUN_XXXXXX" для каждой функции
- ✅ Адреса функций для IDA Pro

### 4. `/include/entities/car.h`
- ✅ Обновлены ссылки на иерархию S81/S82

---

## 🔧 ПЕРЕИМЕНОВАННЫЕ ФУНКЦИИ

| Старое имя | Новое имя | Адрес | Описание |
|------------|-----------|-------|----------|
| `S81_FUN_0045dd20` | `PublicTransport__Init` | 0x0045dd20 | Инициализация |
| `S81_FUN_004af420` | `PublicTransport__FindFreeSlot` | 0x004af420 | Поиск слота |
| `FUN_004af460` | `PublicTransport__AddToRoute` | 0x004af460 | Добавить в маршрут |
| `FUN_004af4a0` | `PublicTransport__UpdateRoutes` | 0x004af4a0 | Обновить маршруты |
| `S81_FUN_004af680` | `PublicTransport__FindCarInTrain` | 0x004af680 | Поиск в поезде |
| `S81_FUN_004af700` | `PublicTransport__FindCarIndex` | 0x004af700 | Поиск индекса |
| `S81_FUN_004afe20` | `PublicTransport__RenderRouteIndicators` | 0x004afe20 | Отрисовка |
| `S81_FUN_004b08a0` | `PublicTransport__InitializeRoutesFromMap` | 0x004b08a0 | Инициализация из карты |
| `S81_FUN_004b0d70` | `PublicTransport__ProcessCarInteraction` | 0x004b0d70 | Взаимодействие |
| `S81_FUN_004b1560` | `PublicTransport__UpdateAllComponents` | 0x004b1560 | Обновление компонентов |
| `S81_FUN_004b1b40` | `PublicTransport__FindLeadVehicle` | 0x004b1b40 | Поиск головного вагона |
| `S81_FUN_004b1b80` | `PublicTransport__AreSameTrain` | 0x004b1b80 | Проверка одного поезда |

---

## 🎯 СЛЕДУЮЩИЕ ШАГИ

1. **Массовое переименование функций** в `game.c` и других файлах
   - Заменить все вызовы `S81_FUN_*` на новые имена
   - Сохранить комментарии со старыми именами

2. **Создание тестов** для проверки иерархии
   - Тест размеров структур (32-bit)
   - Тест смещений полей
   - Тест наследования

3. **Документирование остальных структур**
   - S83 (компоненты поезда)
   - RouteNode (узлы маршрута)
   - Car (производный от BaseCar)

4. **Реализация логики маршрутов**
   - Алгоритм следования по узлам
   - Посадка/высадка пассажиров
   - Расписание и таймеры

---

## 📝 ПРИМЕЧАНИЯ

- Все структуры определены для **32-битной архитектуры (x86)**
- Указатели занимают **4 байта** (не 8!)
- Выравнивание по **4 байтам**
- Для тестирования на x64 использовать `#pragma pack` или флаги компилятора

---

## ✅ СТАТУС ВЫПОЛНЕНИЯ

- [x] Анализ оригинальных структур в IDA Pro
- [x] Исправление иерархии S81/S82
- [x] Создание заголовочных файлов
- [x] Создание реализации public_transport.c
- [x] Документирование изменений
- [ ] Массовое переименование функций в коде
- [ ] Написание unit-тестов
- [ ] Интеграция с основной кодовой базой
- [ ] Финальная проверка в IDA Pro

