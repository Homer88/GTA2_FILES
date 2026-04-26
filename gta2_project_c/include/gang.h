#ifndef GANG_H
#define GANG_H

#include <stdint.h>
#include <stdbool.h>

// Структура банды Gang
// Размер: ~0x40 байт (предположительно)
typedef struct {
    char name[24];          // 0x00 - Название банды
    uint8_t primaryColor;   // 0x18 - Основной цвет
    uint8_t secondaryColor; // 0x19 - Вторичный цвет
    uint8_t modelId;        // 0x1A - ID модели пешехода
    uint8_t pad0;           // 0x1B - Выравнивание
    int32_t relations[8];   // 0x1C - Отношения с другими бандами (8 штук)
    int32_t strength;       // 0x3C - Сила банды
    int32_t weaponSet;      // 0x40 - Набор оружия
    float territoryX;       // 0x44 - Территория X
    float territoryY;       // 0x48 - Территория Y
    float territoryRadius;  // 0x4C - Радиус территории
} Gang;

// Методы с адресами из дампа

// 1. Инициализация банды
// Адрес: 0x0044A100, Размер: 0x38 байт
void Gang__Init(Gang* gang, const char* name, int id);

// 2. Получение указателя на банду по ID
// Адрес: 0x0044A140, Размер: 0x24 байта
Gang* Gang__GetGangPointer(int id);

// 3. Получение названия банды
// Адрес: 0x0044A170, Размер: 0x1E байт
const char* Gang__GetGangName(Gang* gang);

// 4. Установка отношения к другой банде
// Адрес: 0x0044A190, Размер: 0x32 байта
void Gang__SetRelation(Gang* gang, int targetGangId, int relationValue);

// 5. Получение отношения к другой банде
// Адрес: 0x0044A1D0, Размер: 0x2A байт
int Gang__GetRelation(Gang* gang, int targetGangId);

// 6. Проверка: союзник?
// Адрес: 0x0044A200, Размер: 0x22 байта
bool Gang__IsAlly(Gang* gang, int targetGangId);

// 7. Проверка: враг?
// Адрес: 0x0044A230, Размер: 0x22 байта
bool Gang__IsEnemy(Gang* gang, int targetGangId);

// 8. Получение силы банды
// Адрес: 0x0044A260, Размер: 0x1A байт
int Gang__GetStrength(Gang* gang);

// 9. Установка силы банды
// Адрес: 0x0044A280, Размер: 0x26 байт
void Gang__SetStrength(Gang* gang, int strength);

// 10. Получение набора оружия
// Адрес: 0x0044A2B0, Размер: 0x20 байт
int Gang__GetWeaponSet(Gang* gang);

// 11. Спавн члена банды
// Адрес: 0x0044A2E0, Размер: 0x8C байт
void* Gang__SpawnMember(Gang* gang, float x, float y, float z);

// 12. Обновление территории
// Адрес: 0x0044A370, Размер: 0x54 байта
void Gang__UpdateTerritory(Gang* gang, float x, float y, float radius);

#endif // GANG_H
