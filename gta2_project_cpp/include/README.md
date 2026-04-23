# GTA 2 Project Headers

## Описание проекта

Проект reverse engineering игры GTA 2 (gta2.exe) для восстановления структур данных и функций.

**Версия DirectX:** 6.1 (1998 год)

## Структуры

| Файл | Структура | Размер | Функции |
|------|-----------|--------|---------|
| GameObject.h | GameObject | 0x40 | 60 |
| Weapon.h | Weapon | 0x30 | 45 |
| Gang.h | Gang | 0xA8 | 26 |
| Car.h | Car | 0xA4 | 301 |
| Ped.h | Ped | 0x5F0 | 251 |
| Player.h | Player | 0x8B0 | 232 |
| Game.h | Game | 0x40 | 51 |

## Источники данных

- `gta2.exe.map` - файл карты символов с адресами функций
- `gta2.exe/ida_pro/gta2.exe.h` - заголовочный файл из IDA Pro
- `gta2.exe/ida_pro/gta2.exe.asm` - дизассемблированный код

## Важные замечания

1. **НЕ использовать структуры DirectX 9** из старых дампов IDA
2. Все адреса функций взяты из `gta2.exe.map`
3. Размеры структур требуют проверки по бинарнику
4. Использовать `#pragma pack(push, 1)` для всех структур

## Подключение

```cpp
#include "include/gta2/gta2_types.h"
// Или отдельные файлы:
#include "include/gta2/Game.h"
#include "include/gta2/Player.h"
#include "include/gta2/Ped.h"
#include "include/gta2/Car.h"
#include "include/gta2/Weapon.h"
#include "include/gta2/Gang.h"
#include "include/gta2/GameObject.h"
```

## Статус восстановления

- ✅ gta2_types.h - главный заголовок создан
- ✅ GameObject.h - структура и функции обновлены
- ✅ Weapon.h - структура и функции готовы
- ✅ Gang.h - структура и функции готовы
- ✅ Car.h - структура и функции готовы
- ✅ Ped.h - структура и функции обновлены
- ✅ Player.h - структура и функции обновлены
- ✅ Game.h - структура и функции обновлены

## TODO

- [ ] Проверить размеры всех структур по бинарнику
- [ ] Добавить реализации функций в .cpp файлах
- [ ] Восстановить все 966 функций из map-файла
- [ ] Добавить статические_assert для проверки размеров
- [ ] Создать C-версии заголовков в gta2_project_c
