#ifndef GANGS_H
#define GANGS_H

#include "gang.h"

#ifdef __cplusplus
extern "C" {
#endif

// Менеджер всех банд в игре (Gang Pool)
// Размер: предположительно ~0x1000 байт (зависит от макс. количества банд)
typedef struct Gangs {
    Gang* gangsArray;      // 0x00 - Массив указателей на банды (или сами структуры)
    int maxGangs;          // 0x04 - Максимальное количество банд
    int activeCount;       // 0x08 - Количество активных банд
    int selectedGangId;    // 0x0C - ID выбранной банды
    // ... другие поля менеджера
} Gangs;

// Глобальный экземпляр менеджера банд
// Адрес из gta2.map: 0x0046F898 (предположительно)
extern Gangs* gGangs; 

/**
 * Инициализация менеджера банд
 * Адрес: 0x00469E60 (Gangs__Gangs - конструктор)
 */
void Gangs_Init(Gangs* this_ptr);

/**
 * Деструктор менеджера банд
 * Адрес: 0x00469E80 (Gangs__Gangs_Des)
 */
void Gangs_Destroy(Gangs* this_ptr);

/**
 * Получение указателя на банду по ID
 * Адрес: 0x0046CC20 (Gangs__GetGang)
 * @param id ID банды
 * @return Указатель на структуру Gang или NULL
 */
Gang* Gangs_GetGang(int id);

/**
 * Добавление новой банды
 * Адрес: 0x0046CC90 (Gangs__AddNewGang)
 */
int Gangs_AddNewGang(const char* name);

/**
 * Поиск банды по имени
 * Адрес: 0x0046CBB0 (Gangs__FindByName)
 */
Gang* Gangs_FindByName(const char* name);

/**
 * Выбор текущей банды
 * Адрес: 0x0046CC70 (Gangs__SelectGang)
 */
void Gangs_SelectGang(int id);

/**
 * Получение позиции спавна банды по имени
 * Адрес: 0x0046CCC0 (Gangs__GetGangPositionByName)
 */
void Gangs_GetGangPositionByName(const char* name, float* x, float* y, float* z);

/**
 * Поиск банды по модели автомобиля
 * Адрес: 0x0046CCE0 (Gangs__FindGangByCarModel)
 */
Gang* Gangs_FindGangByCarModel(int carModelId);

/**
 * Получение первой используемой банды (для итерации)
 * Адрес: 0x0046CD60 (Gangs__GetFirstUsedGang)
 */
Gang* Gangs_GetFirstUsedGang();

/**
 * Получение следующей используемой банды (для итерации)
 * Адрес: 0x0046CDB0 (Gangs__GetNextUsedGang)
 */
Gang* Gangs_GetNextUsedGang(Gang* current);

/**
 * Увеличение уважения к игроку для всех банд (или конкретной)
 * Адрес: 0x0046CA40 (Gangs__IncreaseRespectForPlayer)
 */
void Gangs_IncreaseRespectForPlayer(int playerId, int amount);

/**
 * Установка банды на карте (MapGm__SetGang)
 * Адрес: 0x0046D4B0
 */
void MapGm_SetGang(int mapId, int gangId);

/**
 * Получение банды с карты (MapGm__GetGang)
 * Адрес: 0x0046D540
 */
int MapGm_GetGang(int mapId);

#ifdef __cplusplus
}
#endif

#endif // GANGS_H
