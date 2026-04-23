/**
 * @file PlayerStats.h
 * @brief Структура статистики игрока (PlayerStats, ранее S161)
 * 
 * Адрес структуры в дампе: line 4793-4898 в structures_dump/S161.txt
 * Размер: 0x600 (1536 байт) - требует проверки через static_assert
 * Основано на: structures_dump/S161.txt
 * 
 * Статистика игрока: деньги, убийства, точность, достижения
 */

#pragma once

#ifndef PLAYER_STATS_H
#define PLAYER_STATS_H

#include <cstdint>

// Forward declaration
struct Player;

#pragma pack(push, 1)

struct PlayerStats
{
    // === Базовые значения ===
    // Смещение 0x00
    int32_t money;                          // MoneyValue - деньги игрока
    
    // Смещение 0x04
    int32_t field_4;                        // Неизвестное поле, резерв
    
    // Смещение 0x08
    uint8_t field_8;                        // Флаг состояния
    
    // Смещение 0x09
    uint8_t gapA[11];                       // gapA[1] + gap[10] = 11 байт
    
    // === Счётчики ===
    // Смещение 0x14
    int32_t reverseCount;                   // Количество разворотов/откатов
    
    // Смещение 0x18 (выровнено по 16)
    Player* toSaveSlot;                     // ToSaveSlot - указатель на слот сохранения
    
    // Смещение 0x1C
    uint8_t gap24[2];                       // Выравнивание
    
    // Смещение 0x1E
    uint8_t field_26;                       // Флаг
    
    // Смещение 0x1F
    uint8_t field_27;                       // Флаг
    
    // Смещение 0x20
    uint8_t field_28;                       // Флаг
    
    // Смещение 0x21
    int16_t maxDigitsInValue;               // MaxDigitsInValue - макс. цифр в значении
    
    // Смещение 0x23
    int16_t minValue;                       // Min - минимальное значение
    
    // Смещение 0x25
    uint16_t digitOffsetForAnimation;       // DigitOffsetForAnimationOfChange - смещение для анимации
    
    // Смещение 0x27
    int32_t maxValue;                       // Max - максимальное значение
    
    // Смещение 0x2B
    int16_t field_34;                       // Неизвестное поле
    
    // Смещение 0x2D
    int16_t id;                             // ID - идентификатор
    
    // Смещение 0x2F
    PlayerStats* next;                      // S161_1 - указатель на следующую статистику
    
    // Смещение 0x33
    uint8_t field_3C;                       // Флаг
    
    // Смещение 0x34-0x6F (заполнитель)
    uint8_t flagsBlock[52];                 // field_3D ... field_6F - блок флагов
    
    // === Игровая статистика ===
    // Смещение 0x70
    int32_t field_70;                       // Неизвестное поле
    
    // Смещение 0x74
    uint8_t field_74;                       // Флаг
    
    // Смещение 0x75
    uint8_t field_75;                       // Флаг
    
    // Смещение 0x76
    uint8_t field_76;                       // Флаг
    
    // Смещение 0x77
    uint8_t field_77;                       // Флаг
    
    // Смещение 0x78
    uint32_t cycle1;                        // Cycle1 - цикл 1
    
    // Смещение 0x7C
    int16_t executions;                     // excutin - казни
    
    // Смещение 0x7E
    uint8_t field_7E;                       // Флаг
    
    // Смещение 0x7F
    uint8_t field_7F;                       // Флаг
    
    // Смещение 0x80
    int32_t field_80;                       // Неизвестное поле
    
    // === Статистика убийств ===
    // Смещение 0x84
    int16_t elvisKilled;                    // elvis_d - убито Elvis (особые цели)
    
    // Смещение 0x86
    int16_t civiliansKilled;                // gencide - убито гражданских
    
    // Смещение 0x88
    int16_t policeKilled;                   // copkill - убито полицейских
    
    // Смещение 0x8A
    int16_t carsStolen;                     // carjaka - угнано машин
    
    // Смещение 0x8C
    uint8_t statsArray[256];                // Arr_int_64 - массив статистики (256 байт)
    
    // Смещение 0x18C
    int32_t field_18C;                      // Неизвестное поле
    
    // Смещение 0x190
    int32_t flyingCarsDestroyed;            // fly_car - уничтожено летающих машин
    
    // Смещение 0x194
    int32_t field_194;                      // Неизвестное поле
    
    // Смещение 0x198
    uint8_t accuracy;                       // accurcy - точность стрельбы (0-100)
    
    // Смещение 0x199
    uint8_t field_199;                      // Резерв
    
    // Смещение 0x19A
    uint8_t field_19A;                      // Резерв
    
    // Смещение 0x19B
    uint8_t field_19B;                      // Резерв
    
    // Смещение 0x19C
    int32_t wrongWayDriving;                // wrngway - езда против движения
    
    // Смещение 0x1A0
    int32_t cycle;                          // Cycle - текущий цикл
    
    // Смещение 0x1A4
    uint8_t enemiesDestroyed;               // em_dest - уничтожено врагов
    
    // Смещение 0x1A5
    uint8_t field_1A5;                      // Резерв
    
    // Смещение 0x1A6
    uint8_t field_1A6;                      // Резерв
    
    // Смещение 0x1A7
    uint8_t field_1A7;                      // Резерв
    
    // Смещение 0x1A8
    // S165 S165;                           // Вложенная структура S165 (требуется отдельная реализация)
    uint8_t s165Placeholder[4];             // Заглушка для S165
    
    // Смещение 0x1AC
    Player* player;                         // sPlayer - указатель на игрока
    
    // Смещение 0x1B0
    uint8_t field_1AC;                      // Флаг
    
    // Смещение 0x1B1
    uint8_t gap36D[658];                    // Большой блок данных (658 байт)
    
    // Смещение 0x5FF (конец)
    uint8_t field_5FF;                      // Последний байт
};

#pragma pack(pop)

// Проверка размера структуры (предварительная оценка: ~1536 байт)
// Точный размер будет определен после компиляции и сверки с оригиналом
static_assert(sizeof(PlayerStats) >= 0x1B0, "PlayerStats size check");

// ============================================================================
// МЕТОДЫ PLAYERSTATS
// ============================================================================

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Конструктор PlayerStats
 * Адрес: TBD (будет определен из ассемблера)
 */
void PlayerStats_Init(PlayerStats* stats);

/**
 * @brief Деструктор PlayerStats
 * Адрес: TBD
 */
void PlayerStats_Destroy(PlayerStats* stats);

/**
 * @brief Сброс всей статистики к начальным значениям
 */
void PlayerStats_reset(PlayerStats* stats);

/**
 * @brief Обновление процента точности
 * @param hits Количество попаданий
 * @param shots Количество выстрелов
 */
void PlayerStats_updateAccuracy(PlayerStats* stats, int hits, int shots);

/**
 * @brief Добавление денег
 * @param amount Сумма для добавления (может быть отрицательной)
 */
void PlayerStats_addMoney(PlayerStats* stats, int32_t amount);

/**
 * @brief Получение общего счета игрока
 * @return Общий счет на основе статистики
 */
int32_t PlayerStats_getTotalScore(const PlayerStats* stats);

#ifdef __cplusplus
}
#endif

// C++ обёртки для удобства
#ifdef __cplusplus
struct PlayerStatsCpp {
    PlayerStats* ptr;
    
    PlayerStatsCpp(PlayerStats* p = nullptr) : ptr(p) {}
    
    void reset() { PlayerStats_reset(ptr); }
    void updateAccuracy(int hits, int shots) { PlayerStats_updateAccuracy(ptr, hits, shots); }
    void addMoney(int32_t amount) { PlayerStats_addMoney(ptr, amount); }
    int32_t getTotalScore() const { return PlayerStats_getTotalScore(ptr); }
};
#endif

#endif // PLAYER_STATS_H
