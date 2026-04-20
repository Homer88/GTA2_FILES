# Статус компиляции проекта GTA 2 Reversing

## Дата: 2024-04-20

### Выполненные изменения:

#### 1. Критическое исправление структуры S82 (BusInfo)

**Файл:** `include/structures_s.h`
- Добавлен `#include "RouteNode.h"` в начало файла
- Структура `S82` исправлена: поле `RouteID` заменено на `RouteNode* RouteNodesPtr`
- Добавлены комментарии к полям структуры для лучшей читаемости

**Новый файл:** `include/RouteNode.h`
```c
typedef struct RouteNode {
    float X;              // 0x0 - Координата X
    float Y;              // 0x4 - Координата Y
    uint16_t Flags;       // 0x8 - Флаги узла
    uint16_t NextNodeIdx; // 0xA - Индекс следующего узла
} RouteNode, *PRouteNode;

typedef struct RouteNodesArray {
    RouteNode* Nodes;     // Указатель на массив узлов
    uint16_t NodeCount;   // Количество узлов
    uint16_t CurrentNode; // Текущий узел
} RouteNodesArray, *PRouteNodesArray;
```

**Файл:** `include/BusInfo.h`
- Полностью переписан для использования S82 вместо S285
- Добавлен typedef `typedef struct S82 BusInfo;`

#### 2. Обновление реализации функций BusInfo

**Файл:** `src/structures/BusInfo.c`
- Переименована функция: `S285__FUN_00432c60` → `BusInfo_UpdateScreenPosition`
- Добавлены новые функции:
  - `BusInfo_InitRoute()` - инициализация маршрута
  - `BusInfo_GetCurrentNode()` - получение текущего узла
  - `BusInfo_AdvanceToNextNode()` - переход к следующему узлу
  - `BusInfo_IsAtStop()` - проверка достижения остановки

### Структура проекта для модульной компиляции:

```
gta2_project/
├── include/           # Заголовочные файлы
│   ├── core/          # Базовые типы и определения
│   ├── entities/      # Сущности (игроки, транспорт, пешеходы)
│   ├── world/         # Игровой мир
│   ├── systems/       # Системы (рендер, звук, ввод)
│   ├── ai/            # Искусственный интеллект
│   ├── ui/            # Пользовательский интерфейс
│   └── math_types/    # Математические типы
├── src/               # Исходный код
│   ├── structures/    # Реализации структур
│   ├── core/
│   ├── entities/
│   ├── world/
│   └── ...
├── lib/               # Скомпилированные библиотеки
├── obj/               # Объектные файлы
└── Makefile           # Сборка через make
```

### Модульные библиотеки (Makefile):

- `libcore.a` - базовые системы
- `libentities.a` - сущности игры
- `libworld.a` - игровой мир и трафик
- `libsystems.a` - системные функции
- `libui.a` - интерфейс
- `libai.a` - ИИ
- `libmath.a` - математика
- `libnetwork.a` - сетевые функции

### Следующие шаги:

1. **Массовое переименование функций FUN_XXXXXX**
   - Использовать скрипт `rename_functions.py`
   - Фокус на файлах в `src/systems/`, `src/world/`, `src/ai/`

2. **Проверка компиляции**
   ```bash
   cd gta2_project
   make clean
   make dirs
   make libs
   ```

3. **Добавление недостающих заголовков**
   - Проверить все `#include` в `.c` файлах
   - Создать missing header files при необходимости

### Известные проблемы:

- Некоторые функции используют синтаксис C++ (`__thiscall`, `Class::Method`)
- Требуется адаптация под чистый C или использование совместимого компилятора (MSVC, Clang с расширениями)
- Отсутствуют определения некоторых глобальных переменных (DAT_XXXXXXXX)

