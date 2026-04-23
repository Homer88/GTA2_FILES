/**
 * @file PlayerStats.cpp
 * @brief Реализация методов структуры PlayerStats (S161)
 * 
 * Основано на: structures_dump/S161.txt
 * Адреса функций: TBD (будут определены из ассемблера)
 */

#include "gta2/PlayerStats.h"
#include <cstring>

// ============================================================================
// КОНСТРУКТОР / ДЕСТРУКТОР
// ============================================================================

/**
 * @brief Конструктор PlayerStats
 * Инициализирует все поля значениями по умолчанию
 */
void PlayerStats_Init(PlayerStats* stats)
{
    if (!stats) return;
    
    // Обнуляем всю структуру
    std::memset(stats, 0, sizeof(PlayerStats));
    
    // Устанавливаем ID в -1 (признак неинициализированной статистики)
    stats->id = -1;
    
    // Поля по умолчанию
    stats->money = 0;
    stats->maxValue = 999999;           // Максимальное значение денег
    stats->maxDigitsInValue = 6;        // 6 цифр для отображения
    stats->minValue = 0;
    stats->accuracy = 0;
    stats->reverseCount = 0;
    stats->cycle = 0;
    stats->cycle1 = 0;
}

/**
 * @brief Деструктор PlayerStats
 * Очищает ресурсы (в данной версии просто обнуляет указатели)
 */
void PlayerStats_Destroy(PlayerStats* stats)
{
    if (!stats) return;
    
    // Обнуляем указатели
    stats->toSaveSlot = nullptr;
    stats->next = nullptr;
    stats->player = nullptr;
    
    // В будущей реализации здесь может быть освобождение памяти S165
}

// ============================================================================
// МЕТОДЫ РАБОТЫ СО СТАТИСТИКОЙ
// ============================================================================

/**
 * @brief Сброс всей статистики к начальным значениям
 * Сохраняет ID и указатели, сбрасывает счётчики
 */
void PlayerStats_reset(PlayerStats* stats)
{
    if (!stats) return;
    
    // Сохраняем важные поля
    int16_t savedId = stats->id;
    Player* savedToSaveSlot = stats->toSaveSlot;
    PlayerStats* savedNext = stats->next;
    Player* savedPlayer = stats->player;
    
    // Обнуляем статистику
    stats->money = 0;
    stats->reverseCount = 0;
    stats->field_4 = 0;
    stats->field_8 = 0;
    std::memset(stats->gapA, 0, sizeof(stats->gapA));
    std::memset(stats->gap24, 0, sizeof(stats->gap24));
    stats->field_26 = 0;
    stats->field_27 = 0;
    stats->field_28 = 0;
    stats->maxDigitsInValue = 6;
    stats->minValue = 0;
    stats->digitOffsetForAnimation = 0;
    stats->maxValue = 999999;
    stats->field_34 = 0;
    std::memset(stats->flagsBlock, 0, sizeof(stats->flagsBlock));
    stats->field_70 = 0;
    stats->field_74 = 0;
    stats->field_75 = 0;
    stats->field_76 = 0;
    stats->field_77 = 0;
    stats->cycle1 = 0;
    stats->executions = 0;
    stats->field_7E = 0;
    stats->field_7F = 0;
    stats->field_80 = 0;
    stats->elvisKilled = 0;
    stats->civiliansKilled = 0;
    stats->policeKilled = 0;
    stats->carsStolen = 0;
    std::memset(stats->statsArray, 0, sizeof(stats->statsArray));
    stats->field_18C = 0;
    stats->flyingCarsDestroyed = 0;
    stats->field_194 = 0;
    stats->accuracy = 0;
    stats->field_199 = 0;
    stats->field_19A = 0;
    stats->field_19B = 0;
    stats->wrongWayDriving = 0;
    stats->cycle = 0;
    stats->enemiesDestroyed = 0;
    stats->field_1A5 = 0;
    stats->field_1A6 = 0;
    stats->field_1A7 = 0;
    std::memset(stats->s165Placeholder, 0, sizeof(stats->s165Placeholder));
    stats->field_1AC = 0;
    std::memset(stats->gap36D, 0, sizeof(stats->gap36D));
    stats->field_5FF = 0;
    
    // Восстанавливаем важные поля
    stats->id = savedId;
    stats->toSaveSlot = savedToSaveSlot;
    stats->next = savedNext;
    stats->player = savedPlayer;
}

/**
 * @brief Обновление процента точности
 * @param hits Количество попаданий
 * @param shots Количество выстрелов
 */
void PlayerStats_updateAccuracy(PlayerStats* stats, int hits, int shots)
{
    if (!stats) return;
    
    if (shots == 0) {
        stats->accuracy = 0;
        return;
    }
    
    // Вычисляем процент точности (0-100)
    int accuracyPercent = (hits * 100) / shots;
    
    // Ограничиваем диапазон 0-100
    if (accuracyPercent < 0) {
        accuracyPercent = 0;
    } else if (accuracyPercent > 100) {
        accuracyPercent = 100;
    }
    
    stats->accuracy = static_cast<uint8_t>(accuracyPercent);
}

/**
 * @brief Добавление денег
 * @param amount Сумма для добавления (может быть отрицательной)
 */
void PlayerStats_addMoney(PlayerStats* stats, int32_t amount)
{
    if (!stats) return;
    
    int32_t newMoney = stats->money + amount;
    
    // Ограничиваем минимальное значение (0)
    if (newMoney < 0) {
        newMoney = 0;
    }
    
    // Ограничиваем максимальное значение
    if (newMoney > stats->maxValue) {
        newMoney = stats->maxValue;
    }
    
    stats->money = newMoney;
}

/**
 * @brief Получение общего счета игрока
 * @return Общий счет на основе статистики
 * 
 * Формула подсчета:
 * - Гражданские: 1 очко за каждого
 * - Полицейские: 5 очков за каждого
 * - Elvis: 10 очков за каждого
 * - Угнанные машины: 2 очка за каждую
 * - Летающие машины: 25 очков за каждую
 * - Точность > 50%: бонус 50 очков
 */
int32_t PlayerStats_getTotalScore(const PlayerStats* stats)
{
    if (!stats) return 0;
    
    int32_t score = 0;
    
    // Убитые гражданские (1 очко)
    score += static_cast<int32_t>(stats->civiliansKilled) * 1;
    
    // Убитые полицейские (5 очков)
    score += static_cast<int32_t>(stats->policeKilled) * 5;
    
    // Убитые Elvis (10 очков)
    score += static_cast<int32_t>(stats->elvisKilled) * 10;
    
    // Угнанные машины (2 очка)
    score += static_cast<int32_t>(stats->carsStolen) * 2;
    
    // Уничтоженные летающие машины (25 очков)
    score += static_cast<int32_t>(stats->flyingCarsDestroyed) * 25;
    
    // Бонус за точность > 50%
    if (stats->accuracy > 50) {
        score += 50;
    }
    
    return score;
}
