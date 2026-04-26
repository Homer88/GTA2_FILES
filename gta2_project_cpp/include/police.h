#ifndef POLICE_H
#define POLICE_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
// Структура Police (размер требует уточнения)
class Police {
public:
    // Поля (смещения требуют уточнения)
    uint8_t  m_nWantedLevel;        // Уровень розыска (0-6)
    uint8_t  m_nPadding1[3];        // Выравнивание
    int32_t  m_nCrimesCount;        // Количество преступлений
    int32_t  m_nCopKilledTimer;     // Таймер после убийства копа
    int32_t  m_nNumCopsKilled;      // Счетчик убитых копов
    bool     m_bIsChasing;          // Флаг преследования
    bool     m_bSirenActive;        // Флаг сирены
    uint8_t  m_nPadding2[2];        // Выравнивание
    float    m_fSearchRadius;       // Радиус поиска
    void*    m_pTargetPlayer;       // Указатель на цель (игрока)
    // ... другие поля требуют анализа

public:
    // Конструктор / Деструктор
    // Адрес: TODO_FIND_ADDRESS
    Police();

    // Адрес: TODO_FIND_ADDRESS
    ~Police();

    // Инициализация и жизненный цикл
    // Адрес: TODO_FIND_ADDRESS
    void Init();

    // Адрес: TODO_FIND_ADDRESS
    void Update();

    // Адрес: TODO_FIND_ADDRESS
    void Reset();

    // Управление уровнем розыска
    // Адрес: TODO_FIND_ADDRESS
    void SetWantedLevel(uint8_t level);

    // Адрес: TODO_FIND_ADDRESS
    uint8_t GetWantedLevel();

    // Адрес: TODO_FIND_ADDRESS
    void AddWantedLevel(uint8_t amount);

    // Адрес: TODO_FIND_ADDRESS
    void ClearWantedLevel();

    // Преступления
    // Адрес: TODO_FIND_ADDRESS
    void AddCrime(int crimeType, void* pTarget);

    // Адрес: TODO_FIND_ADDRESS
    void ClearCrimes();

    // Спавн и управление юнитами
    // Адрес: TODO_FIND_ADDRESS
    void SpawnCops(float x, float y, int count);

    // Адрес: TODO_FIND_ADDRESS
    void DispatchUnits();

    // Адрес: TODO_FIND_ADDRESS
    void StartChase(void* pTarget);

    // Адрес: TODO_FIND_ADDRESS
    void EndChase();

    // Взаимодействие
    // Адрес: TODO_FIND_ADDRESS
    bool Bribe(int money);

    // Адрес: TODO_FIND_ADDRESS
    void ArrestPlayer(void* pPlayer);

    // Адрес: TODO_FIND_ADDRESS
    void KillSuspect(void* pSuspect);

    // Утилиты
    // Адрес: TODO_FIND_ADDRESS
    bool IsPlayerWanted();

    // Адрес: TODO_FIND_ADDRESS
    void PlaySiren();

    // Адрес: TODO_FIND_ADDRESS
    void StopSiren();
};

#endif // __cplusplus

#endif // POLICE_H
