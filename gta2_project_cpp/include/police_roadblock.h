#ifndef POLICE_ROADBLOCK_H
#define POLICE_ROADBLOCK_H

#include <stdint.h>

/*
 * Класс: PoliceRoadblock (Полицейский кордон)
 * Размер: предположительно 0x3C - 0x50 байт (требует уточнения)
 * Описание: Блокировка дороги полицией при высоком уровне розыска.
 */
class PoliceRoadblock {
public:
    // Поля структуры (смещения требуют подтверждения по дампу)
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

public:
    // Конструктор / Деструктор (адреса TODO)
    // Адрес: TODO_FIND_ADDRESS
    PoliceRoadblock();
    
    // Адрес: TODO_FIND_ADDRESS
    ~PoliceRoadblock();

    // Методы
    
    /**
     * Инициализация параметров блока
     * Адрес: TODO_FIND_ADDRESS (0x00000000)
     */
    // Адрес: TODO_FIND_ADDRESS
    void Init();

    /**
     * Создание объектов на сцене (спавн машин и копов)
     * Адрес: TODO_FIND_ADDRESS (0x00000000)
     */
    // Адрес: TODO_FIND_ADDRESS
    void Create();

    /**
     * Обновление состояния (проверка игрока, огонь, удаление)
     * Адрес: TODO_FIND_ADDRESS (0x00000000)
     */
    // Адрес: TODO_FIND_ADDRESS
    void Update();

    /**
     * Удаление кордона (очистка юнитов)
     * Адрес: TODO_FIND_ADDRESS (0x00000000)
     */
    // Адрес: TODO_FIND_ADDRESS
    void Remove();

    /**
     * Проверка, блокирует ли данный кордон путь игроку
     * Адрес: TODO_FIND_ADDRESS (0x00000000)
     */
    // Адрес: TODO_FIND_ADDRESS
    int IsCrossingBlocked(float playerX, float playerY);
};

/*
 * Глобальные функции управления кордонами (вне класса)
 */

/**
 * Поиск подходящего места на дороге для установки блока
 * Адрес: TODO_FIND_ADDRESS (0x00000000)
 * Возвращает: 1 если найдено, 0 если нет
 */
// Адрес: TODO_FIND_ADDRESS
int Police__FindNearestRoadBlockSpot(float x, float y, float* outX, float* outY, float* outHeading);

/**
 * Главная функция вызова создания блока при повышении уровня розыска
 * Адрес: TODO_FIND_ADDRESS (0x00000000)
 */
// Адрес: TODO_FIND_ADDRESS
void Police__SetupRoadBlock(void);

#endif // POLICE_ROADBLOCK_H
