/**
 * @file PlayerStats.cpp
 * @brief Реализация методов структуры PlayerStats (S161)
 * 
 * Основано на: structures_dump/S161.txt
 * Все адреса функций будут добавлены после анализа ассемблера
 */

#include "gta2/PlayerStats.h"
#include <cstring>

// ============================================================================
// КОНСТРУКТОР / ДЕСТРУКТОР
// ============================================================================

/**
 * @brief Конструктор PlayerStats
 * Адрес: TBD (будет определен из ассемблера)
 * 
 * Инициализирует все поля значениями по умолчанию
 */
void PlayerStats_Init(PlayerStats* stats)
{
    if (!stats) return;
    
    // Обнуляем всю структуру
    std::memset(stats, 0, sizeof(PlayerStats));
    
    // Устанавливаем значения по умолчанию
    stats->money = 0;
    stats->field_4 = 0;
    stats->field_8 = 0;
    stats->reverseCount = 0;
    stats->toSaveSlot = nullptr;
    stats->maxDigitsInValue = 10;  // По умолчанию до 10 цифр
    stats->minValue = 0;
    stats->digitOffsetForAnimation = 0;
    stats->maxValue = 999999999;
    stats->id = -1;
    stats->next = nullptr;
    stats->accuracy = 0;
    stats->player = nullptr;
}

/**
 * @brief Деструктор PlayerStats
 * Адрес: TBD
 * 
 * Очищает ресурсы (если есть)
 */
void PlayerStats_Destroy(PlayerStats* stats)
{
    if (!stats) return;
    
    // В текущей реализации динамических ресурсов нет
    // Функция оставлена для совместимости с оригиналом
}

// ============================================================================
// МЕТОДЫ УПРАВЛЕНИЯ СТАТИСТИКОЙ
// ============================================================================

/**
 * @brief Сброс всей статистики к начальным значениям
 * 
 * Сбрасывает все счётчики, деньги и статистику убийств
 */
void PlayerStats_reset(PlayerStats* stats)
{
    if (!stats) return;
    
    // Сохраняем указатели и идентификаторы
    Player* savedPlayer = stats->player;
    PlayerStats* savedNext = stats->next;
    Player* savedToSaveSlot = stats->toSaveSlot;
    int16_t savedId = stats->id;
    
    // Обнуляем статистику
    stats->money = 0;
    stats->field_4 = 0;
    stats->reverseCount = 0;
    stats->executions = 0;
    stats->elvisKilled = 0;
    stats->civiliansKilled = 0;
    stats->policeKilled = 0;
    stats->carsStolen = 0;
    stats->flyingCarsDestroyed = 0;
    stats->accuracy = 0;
    stats->wrongWayDriving = 0;
    stats->cycle = 0;
    stats->cycle1 = 0;
    stats->enemiesDestroyed = 0;
    
    // Очищаем массив статистики
    std::memset(stats->statsArray, 0, sizeof(stats->statsArray));
    
    // Восстанавливаем указатели
    stats->player = savedPlayer;
    stats->next = savedNext;
    stats->toSaveSlot = savedToSaveSlot;
    stats->id = savedId;
}

/**
 * @brief Обновление процента точности
 * @param hits Количество попаданий
 * @param shots Количество выстрелов
 * 
 * Вычисляет процент точности (0-100) и сохраняет в поле accuracy
 */
void PlayerStats_updateAccuracy(PlayerStats* stats, int hits, int shots)
{
    if (!stats) return;
    
    if (shots <= 0) {
        stats->accuracy = 0;
        return;
    }
    
    // Вычисляем процент точности
    int accuracyPercent = (hits * 100) / shots;
    
    // Ограничиваем диапазон 0-100
    if (accuracyPercent < 0) accuracyPercent = 0;
    if (accuracyPercent > 100) accuracyPercent = 100;
    
    stats->accuracy = static_cast<uint8_t>(accuracyPercent);
}

/**
 * @brief Добавление денег
 * @param amount Сумма для добавления (может быть отрицательной)
 * 
 * Изменяет количество денег на указанную сумму
 * Проверка на выход за пределы диапазона выполняется через maxValue/minValue
 */
void PlayerStats_addMoney(PlayerStats* stats, int32_t amount)
{
    if (!stats) return;
    
    int32_t newMoney = stats->money + amount;
    
    // Проверка на максимальное значение
    if (newMoney > stats->maxValue) {
        newMoney = stats->maxValue;
    }
    
    // Проверка на минимальное значение (не меньше 0)
    if (newMoney < 0) {
        newMoney = 0;
    }
    
    stats->money = newMoney;
}

/**
 * @brief Получение общего счета игрока
 * @return Общий счет на основе статистики
 * 
 * Формула расчёта:
 * - Убийства гражданских: 1 очко
 * - Убийства полицейских: 5 очков
 * - Убийства Elvis: 10 очков
 * - Угон машин: 2 очка
 * - Точность > 50%: бонус 50 очков
 */
int32_t PlayerStats_getTotalScore(const PlayerStats* stats)
{
    if (!stats) return 0;
    
    int32_t totalScore = 0;
    
    // Базовые очки за убийства
    totalScore += stats->civiliansKilled * 1;
    totalScore += stats->policeKilled * 5;
    totalScore += stats->elvisKilled * 10;
    
    // Очки за угон машин
    totalScore += stats->carsStolen * 2;
    
    // Бонус за точность
    if (stats->accuracy >= 50) {
        totalScore += 50;
    }
    
    // Бонус за уничтожение летающих машин (редкое достижение)
    totalScore += stats->flyingCarsDestroyed * 25;
    
    return totalScore;
}

// ============================================================================
// ПРИМЕЧАНИЯ ДЛЯ РАЗРАБОТЧИКОВ
// ============================================================================
// 
// Адреса функций из gta2.exe.map (требуют уточнения):
// - Конструктор: TBD
// - Деструктор: TBD
// - reset: TBD
// - updateAccuracy: TBD
// - addMoney: TBD
// - getTotalScore: TBD
//
// Размер структуры: требует проверки через static_assert после полной реализации
// Смещения полей: сверить с оригинальным дампом S161.txt
// ============================================================================
