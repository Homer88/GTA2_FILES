#ifndef POLICE_H
#define POLICE_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// Структура Police (размер требует уточнения)
typedef struct Police {
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
} Police;

// Глобальная переменная (адрес требует уточнения)
// extern Police gPoliceManager; 

// --- Прототипы функций (Адреса требуют подтверждения в gta2.map) ---

// Инициализация и жизненный цикл
// Адрес: TODO_FIND_ADDRESS
void Police__Init(Police* self);

// Адрес: TODO_FIND_ADDRESS
void Police__Update(Police* self);

// Адрес: TODO_FIND_ADDRESS
void Police__Reset(Police* self);

// Управление уровнем розыска
// Адрес: TODO_FIND_ADDRESS
void Police__SetWantedLevel(Police* self, uint8_t level);

// Адрес: TODO_FIND_ADDRESS
uint8_t Police__GetWantedLevel(Police* self);

// Адрес: TODO_FIND_ADDRESS
void Police__AddWantedLevel(Police* self, uint8_t amount);

// Адрес: TODO_FIND_ADDRESS
void Police__ClearWantedLevel(Police* self);

// Преступления
// Адрес: TODO_FIND_ADDRESS
void Police__AddCrime(Police* self, int crimeType, void* pTarget);

// Адрес: TODO_FIND_ADDRESS
void Police__ClearCrimes(Police* self);

// Спавн и управление юнитами
// Адрес: TODO_FIND_ADDRESS
void Police__SpawnCops(Police* self, float x, float y, int count);

// Адрес: TODO_FIND_ADDRESS
void Police__DispatchUnits(Police* self);

// Адрес: TODO_FIND_ADDRESS
void Police__StartChase(Police* self, void* pTarget);

// Адрес: TODO_FIND_ADDRESS
void Police__EndChase(Police* self);

// Взаимодействие
// Адрес: TODO_FIND_ADDRESS
bool Police__Bribe(Police* self, int money);

// Адрес: TODO_FIND_ADDRESS
void Police__ArrestPlayer(Police* self, void* pPlayer);

// Адрес: TODO_FIND_ADDRESS
void Police__KillSuspect(Police* self, void* pSuspect);

// Утилиты
// Адрес: TODO_FIND_ADDRESS
bool Police__IsPlayerWanted(Police* self);

// Адрес: TODO_FIND_ADDRESS
void Police__PlaySiren(Police* self);

// Адрес: TODO_FIND_ADDRESS
void Police__StopSiren(Police* self);

#ifdef __cplusplus
}
#endif

#endif // POLICE_H
