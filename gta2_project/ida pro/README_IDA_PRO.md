# IDA Pro Integration Guide / Руководство по интеграции с IDA Pro

## 📁 Файлы для IDA Pro / Files for IDA Pro

В папке `ida pro/` находятся три файла для работы с IDA Pro:

### 1. `gta2.exe.h` - Заголовочный файл со структурами
**Назначение:** Определения структур, enum и прототипы функций

**Как использовать:**
1. В IDA Pro: `File` → `Load file` → `Parse C header file...`
2. Выберите `gta2.exe.h`
3. Структуры появятся в окне Structures (Shift+F1)
4. Примените типы к функциям через Local Types (Ctrl+F9)

**Структуры:**
- `S82_BaseCar` (0x68 байт) - базовый класс автомобиля
- `S81_PublicTransport` (0x7C байт) - общественный транспорт
- `S3` - элемент рендеринга
- `RouteNode` - узел маршрута
- `Car` - автомобиль

**Enum:**
- `VehicleType` - типы транспортных средств
- `PublicTransportState` - состояния общественного транспорта
- `RouteFlags` - флаги маршрута

### 2. `gta2.exe.c` - Реализация функций с адресами
**Назначение:** Заглушки функций с комментариями адресов для переименования

**Формат комментариев:**
```c
// ----------------------------------------------------------------------------
// Адрес: 0x004AF640          <- Адрес в gta2.exe
// old_name: FUN_004af640     <- Старое имя (из IDA)
// new_name: S81_Init         <- Новое имя
// Описание: ...              <- Описание функции
// ----------------------------------------------------------------------------
```

**Как использовать:**
1. Откройте файл в текстовом редакторе
2. Найдите функцию по адресу или старому имени
3. В IDA Pro перейдите по адресу (G → ввести адрес)
4. Переименуйте функцию (N → ввести новое имя)

**Автоматизация через IDAPython:**
```python
import idaapi
import re

# Парсинг файла gta2.exe.c
with open("ida pro/gta2.exe.c", "r", encoding="utf-8") as f:
    content = f.read()

# Извлечение адресов и имён
pattern = r"// Адрес: (0x[0-9A-F]+)\n// old_name: (\w+)\n// new_name: (\w+)"
matches = re.findall(pattern, content)

for addr, old_name, new_name in matches:
    ea = int(addr, 16)
    # Переименование функции
    idaapi.set_name(ea, new_name, idaapi.SN_CHECK)
    print(f"Renamed {old_name} → {new_name} at {addr}")
```

### 3. `gta2.exe.cpp` - C++ обёртки
**Назначение:** Обёртки над C функциями для использования в C++ коде

**Особенности:**
- Используются структуры вместо классов (совместимость с C)
- Все функции являются свободными функциями
- Принимают указатель `this` как первый параметр
- Обёрнуты в namespace `GTA2`

**Пример использования:**
```cpp
#include "gta2.exe.h"
#include "gta2.exe.cpp"

void example() {
    using namespace GTA2;
    
    // Создание общественного транспорта
    S81_PublicTransport bus = {};
    
    // Инициализация
    S81_Init_Wrapper(&bus);
    
    // Установка маршрута
    RouteNode route[5] = {};
    S81_SetRoute_Wrapper(&bus, route, 5);
    
    // Обновление в игровом цикле
    S81_Update_Wrapper(&bus);
    
    // Проверка типа транспорта
    Car myCar = {};
    if (S81_IsThisBus_Wrapper(&bus, &myCar)) {
        // Это автобус
    }
}
```

---

## 🏗 Иерархия транспортных средств / Vehicle Hierarchy

```
S82_BaseCar (0x68 байт)
├── Позиция (X, Y, Z, Heading)
├── Физика (Speed, Acceleration, Mass, Friction)
├── Состояние (VehicleType, Health, Flags)
├── Управление (State, Timer, PassengerCount)
└── Параметры (Velocity, DamageFlags, LightState)

S81_PublicTransport (0x7C байт)
├── S82_BaseCar Base (0x68 байт) ← наследование
├── RouteNodesPtr (указатель на маршрут)
├── CurrentRouteIndex (текущий узел)
├── NextRouteIndex (следующий узел)
├── StopTimer (таймер остановки)
├── RouteFlags (флаги маршрута)
├── StopState (состояние остановки)
├── Priority (приоритет)
└── RouteID (ID маршрута)
```

---

## 📋 Чеклист переименования функций / Function Rename Checklist

### S81 (PublicTransport):
- [ ] `FUN_004af640` → `S81_Init`
- [ ] `FUN_004af700` → `S81_Update`
- [ ] `FUN_004af8a0` → `S81_SetRoute`
- [ ] `FUN_004af9c0` → `S81_NextStop`
- [ ] `FUN_004afb20` → `S81_IsThisBus`
- [ ] `FUN_004b1b40` → `S81_FindCarField`
- [ ] `FUN_004b0d70` → `S81_ProcessCarInteraction`
- [ ] `FUN_004afc80` → `S81_HasReachedBusSkipLimit`

### S82 (BaseCar):
- [ ] `FUN_004e5a10` → `S82_Init`
- [ ] `FUN_004e5b30` → `S82_UpdatePhysics`
- [ ] `FUN_004e5c50` → `S82_ApplyForce`
- [ ] `FUN_004e5d70` → `S82_SetSpeed`
- [ ] `FUN_004e5e90` → `S82_Turn`
- [ ] `FUN_004e5fb0` → `S82_CheckCollision`

---

## 🔧 Советы по работе с IDA Pro / Tips for IDA Pro

### Применение типов структур:
1. Откройте функцию в дизассемблере
2. Нажмите Y (Edit function type)
3. Введите тип: `void __stdcall S81_Init(S81_PublicTransport* this)`
4. IDA автоматически применит типы параметров

### Просмотр структур:
- Shift+F1 → Structures → Найти `S81_PublicTransport`
- Правая кнопка → Edit → Проверить поля

### Создание комментариев:
- Используйте формат: `old_name: FUN_XXXXXX` для поиска
- Добавляйте адреса: `Address: 0x004XXXXX`

---

## 📊 Размеры структур / Structure Sizes

| Структура | Размер (hex) | Размер (dec) | Описание |
|-----------|--------------|--------------|----------|
| S82_BaseCar | 0x68 | 104 | Базовый автомобиль |
| S81_PublicTransport | 0x7C | 124 | Общественный транспорт |
| S3 | 0x3C | 60 | Элемент рендеринга |
| RouteNode | 0x20 | 32 | Узел маршрута |
| Car | ~0x88 | ~136 | Автомобиль (приблизительно) |

---

## 📝 Примечания / Notes

1. **Архитектура:** x86 (32-бит), указатели = 4 байта
2. **Выравнивание:** по 4 байтам
3. **Calling convention:** `__stdcall` (параметры справа налево, очистка стека вызываемым)
4. **Старые имена:** сохраняются в комментариях для отслеживания истории
5. **Новые имена:** отражают назначение функции (Init, Update, SetRoute, etc.)

---

## 🚀 Следующие шаги / Next Steps

1. Импорт заголовочного файла в IDA Pro
2. Переименование функций по списку
3. Применение типов к функциям
4. Анализ перекрёстных ссылок (Xrefs)
5. Документирование обнаруженных алгоритмов

---

**Дата обновления:** 2024-04-21  
**Версия проекта:** GTA2 Reverse Engineering v2.0
