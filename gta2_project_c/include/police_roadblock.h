#ifndef POLICE_ROADBLOCK_H
#define POLICE_ROADBLOCK_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Структура: PoliceRoadblock (Полицейский кордон)
 * Размер: предположительно 0x3C - 0x50 байт (требует уточнения)
 * Описание: Блокировка дороги полицией при высоком уровне розыска.
 */
typedef struct PoliceRoadblock {
    uint8_t     m_bActive;          // 0x00: Активен ли кордон
    uint8_t     pad_01[3];          // 0x01: Выравнивание
    float       m_fPosX;            // 0x04: Координата X центра блокировки
    float       m_fPosY;            // 0x08: Координата Y центра блокировки
    float       m_fHeading;         // 0x0C: Направление перекрытия дороги
    int32_t     m_nWantedLevelTrigger; // 0x10: Уровень розыска для активации
    void*       m_pCar1;            // 0x14: Указатель на первую полицейскую машину
    void*       m_pCar2;            // 0x18: Указатель на вторую полицейскую машину
    void*       m_pCop1;            // 0x1C: Указатель на первого офицера
    void*       m_pCop2;            // 0x20: Указатель на второго офицера
    int32_t     m_nState;           // 0x24: Состояние (Setup, Active, Dismantling)
    int32_t     m_nTimer;           // 0x28: Таймер существования или задержки
    // Поля после 0x28 требуют уточнения по дампу
} PoliceRoadblock;

// Глобальный массив кордонов (адрес требует уточнения)
// extern PoliceRoadblock g_Roadblocks[MAX_ROADBLOCKS];

/**
 * Инициализация параметров блока
 * Адрес: TODO_FIND_ADDRESS (0x00000000)
 */
void PoliceRoadblock__Init(PoliceRoadblock* self);

/**
 * Создание объектов на сцене (спавн машин и копов)
 * Адрес: TODO_FIND_ADDRESS (0x00000000)
 */
void PoliceRoadblock__Create(PoliceRoadblock* self);

/**
 * Обновление состояния (проверка игрока, огонь, удаление)
 * Адрес: TODO_FIND_ADDRESS (0x00000000)
 */
void PoliceRoadblock__Update(PoliceRoadblock* self);

/**
 * Удаление кордона (очистка юнитов)
 * Адрес: TODO_FIND_ADDRESS (0x00000000)
 */
void PoliceRoadblock__Remove(PoliceRoadblock* self);

/**
 * Поиск подходящего места на дороге для установки блока
 * Адрес: TODO_FIND_ADDRESS (0x00000000)
 * Возвращает: 1 если найдено, 0 если нет
 */
int Police__FindNearestRoadBlockSpot(float x, float y, float* outX, float* outY, float* outHeading);

/**
 * Главная функция вызова создания блока при повышении уровня розыска
 * Адрес: TODO_FIND_ADDRESS (0x00000000)
 */
void Police__SetupRoadBlock(void);

/**
 * Проверка, блокирует ли данный кордон путь игроку
 * Адрес: TODO_FIND_ADDRESS (0x00000000)
 */
int PoliceRoadblock__IsCrossingBlocked(PoliceRoadblock* self, float playerX, float playerY);

#ifdef __cplusplus
}
#endif

#endif // POLICE_ROADBLOCK_H
