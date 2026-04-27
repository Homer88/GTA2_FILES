#ifndef GANGS_H
#define GANGS_H

#include "gang.h"

#ifdef __cplusplus

// Менеджер всех банд в игре (Gang Pool)
class Gangs {
public:
    // Конструктор
    // Адрес: 0x00469E60
    Gangs();

    // Деструктор
    // Адрес: 0x00469E80
    ~Gangs();

    // Получение указателя на банду по ID
    // Адрес: 0x0046CC20 (Gangs__GetGang)
    static Gang* GetGang(int id);

    // Добавление новой банды
    // Адрес: 0x0046CC90 (Gangs__AddNewGang)
    static int AddNewGang(const char* name);

    // Поиск банды по имени
    // Адрес: 0x0046CBB0 (Gangs__FindByName)
    static Gang* FindByName(const char* name);

    // Выбор текущей банды
    // Адрес: 0x0046CC70 (Gangs__SelectGang)
    static void SelectGang(int id);

    // Получение позиции спавна банды по имени
    // Адрес: 0x0046CCC0 (Gangs__GetGangPositionByName)
    static void GetGangPositionByName(const char* name, float* x, float* y, float* z);

    // Поиск банды по модели автомобиля
    // Адрес: 0x0046CCE0 (Gangs__FindGangByCarModel)
    static Gang* FindGangByCarModel(int carModelId);

    // Получение первой используемой банды (для итерации)
    // Адрес: 0x0046CD60 (Gangs__GetFirstUsedGang)
    static Gang* GetFirstUsedGang();

    // Получение следующей используемой банды (для итерации)
    // Адрес: 0x0046CDB0 (Gangs__GetNextUsedGang)
    static Gang* GetNextUsedGang(Gang* current);

    // Увеличение уважения к игроку
    // Адрес: 0x0046CA40 (Gangs__IncreaseRespectForPlayer)
    static void IncreaseRespectForPlayer(int playerId, int amount);

private:
    // Внутренние поля менеджера
    void* gangsArray;      // 0x00 - Массив банд
    int maxGangs;          // 0x04 - Макс. количество
    int activeCount;       // 0x08 - Активные
    int selectedGangId;    // 0x0C - Выбранный ID
    // ... другие поля
};

// Глобальный экземпляр (адрес из gta2.map: предположительно 0x0046F898)
extern Gangs* gGangs;

// Функции MapGm (возможно, отдельный класс, но связаны с Gangs)
// Адрес: 0x0046D4B0
void MapGm_SetGang(int mapId, int gangId);
// Адрес: 0x0046D540
int MapGm_GetGang(int mapId);

#endif // __cplusplus

#endif // GANGS_H
