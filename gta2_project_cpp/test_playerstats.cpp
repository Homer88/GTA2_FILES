/**
 * @file test_playerstats.cpp
 * @brief Тесты для структуры PlayerStats (S161)
 * 
 * Проверяет:
 * - Размер структуры
 * - Смещения полей
 * - Работу методов: reset(), updateAccuracy(), addMoney(), getTotalScore()
 */

#include "gta2/PlayerStats.h"
#include "gta2/Player.h"
#include <iostream>
#include <cassert>
#include <cstring>

// Глобальные счётчики тестов
static int tests_passed = 0;
static int tests_failed = 0;

#define TEST_ASSERT(condition, message) \
    do { \
        if (condition) { \
            std::cout << "[PASS] " << message << std::endl; \
            tests_passed++; \
        } else { \
            std::cout << "[FAIL] " << message << std::endl; \
            tests_failed++; \
        } \
    } while(0)

// ============================================================================
// ТЕСТ 1: Проверка размера структуры
// ============================================================================
void test_struct_size()
{
    std::cout << "\n=== ТЕСТ 1: Размер структуры ===" << std::endl;
    
    // Минимальный размер на основе известных полей
    size_t min_size = 0x1B0 + 1 + 658 + 1; // до field_5FF
    
    TEST_ASSERT(sizeof(PlayerStats) >= 0x1B0, 
                "Размер структуры >= 0x1B0");
    
    std::cout << "sizeof(PlayerStats) = " << sizeof(PlayerStats) << " байт" << std::endl;
}

// ============================================================================
// ТЕСТ 2: Проверка смещений ключевых полей
// ============================================================================
void test_field_offsets()
{
    std::cout << "\n=== ТЕСТ 2: Смещения полей ===" << std::endl;
    
    PlayerStats stats;
    std::memset(&stats, 0, sizeof(PlayerStats));
    
    // Проверка смещения money (должно быть 0x00)
    TEST_ASSERT(reinterpret_cast<char*>(&stats.money) - reinterpret_cast<char*>(&stats) == 0,
                "money: смещение 0x00");
    
    // Проверка смещения reverseCount (должно быть 0x14)
    TEST_ASSERT(reinterpret_cast<char*>(&stats.reverseCount) - reinterpret_cast<char*>(&stats) == 0x14,
                "reverseCount: смещение 0x14");
    
    // Проверка смещения policeKilled (должно быть 0x88)
    TEST_ASSERT(reinterpret_cast<char*>(&stats.policeKilled) - reinterpret_cast<char*>(&stats) == 0x88,
                "policeKilled: смещение 0x88");
    
    // Проверка смещения accuracy (должно быть 0x198)
    TEST_ASSERT(reinterpret_cast<char*>(&stats.accuracy) - reinterpret_cast<char*>(&stats) == 0x198,
                "accuracy: смещение 0x198");
    
    std::cout << "money offset: " << (reinterpret_cast<char*>(&stats.money) - reinterpret_cast<char*>(&stats)) << std::endl;
    std::cout << "reverseCount offset: " << (reinterpret_cast<char*>(&stats.reverseCount) - reinterpret_cast<char*>(&stats)) << std::endl;
    std::cout << "policeKilled offset: " << (reinterpret_cast<char*>(&stats.policeKilled) - reinterpret_cast<char*>(&stats)) << std::endl;
    std::cout << "accuracy offset: " << (reinterpret_cast<char*>(&stats.accuracy) - reinterpret_cast<char*>(&stats)) << std::endl;
}

// ============================================================================
// ТЕСТ 3: Инициализация и reset()
// ============================================================================
void test_init_and_reset()
{
    std::cout << "\n=== ТЕСТ 3: Инициализация и reset() ===" << std::endl;
    
    PlayerStats stats;
    
    // Инициализация
    PlayerStats_Init(&stats);
    
    TEST_ASSERT(stats.money == 0, "После Init: money == 0");
    TEST_ASSERT(stats.policeKilled == 0, "После Init: policeKilled == 0");
    TEST_ASSERT(stats.accuracy == 0, "После Init: accuracy == 0");
    TEST_ASSERT(stats.id == -1, "После Init: id == -1");
    
    // Устанавливаем некоторые значения
    stats.money = 1000;
    stats.policeKilled = 50;
    stats.civiliansKilled = 100;
    stats.accuracy = 75;
    
    // Сброс
    PlayerStats_reset(&stats);
    
    TEST_ASSERT(stats.money == 0, "После reset: money == 0");
    TEST_ASSERT(stats.policeKilled == 0, "После reset: policeKilled == 0");
    TEST_ASSERT(stats.accuracy == 0, "После reset: accuracy == 0");
    TEST_ASSERT(stats.id == -1, "После reset: id сохранён (-1)");
}

// ============================================================================
// ТЕСТ 4: addMoney()
// ============================================================================
void test_add_money()
{
    std::cout << "\n=== ТЕСТ 4: addMoney() ===" << std::endl;
    
    PlayerStats stats;
    PlayerStats_Init(&stats);
    
    // Добавление положительной суммы
    PlayerStats_addMoney(&stats, 500);
    TEST_ASSERT(stats.money == 500, "addMoney(500): money == 500");
    
    // Добавление ещё
    PlayerStats_addMoney(&stats, 300);
    TEST_ASSERT(stats.money == 800, "addMoney(300): money == 800");
    
    // Вычитание
    PlayerStats_addMoney(&stats, -200);
    TEST_ASSERT(stats.money == 600, "addMoney(-200): money == 600");
    
    // Попытка уйти в минус (должно ограничиться 0)
    PlayerStats_addMoney(&stats, -1000);
    TEST_ASSERT(stats.money == 0, "addMoney(-1000): money == 0 (не отрицательное)");
    
    // Проверка ограничения maxValue
    stats.maxValue = 1000;
    stats.money = 900;
    PlayerStats_addMoney(&stats, 200);
    TEST_ASSERT(stats.money == 1000, "addMoney: ограничение maxValue (1000)");
}

// ============================================================================
// ТЕСТ 5: updateAccuracy()
// ============================================================================
void test_update_accuracy()
{
    std::cout << "\n=== ТЕСТ 5: updateAccuracy() ===" << std::endl;
    
    PlayerStats stats;
    PlayerStats_Init(&stats);
    
    // 50 попаданий из 100 выстрелов = 50%
    PlayerStats_updateAccuracy(&stats, 50, 100);
    TEST_ASSERT(stats.accuracy == 50, "updateAccuracy(50, 100): accuracy == 50");
    
    // 75 попаданий из 100 выстрелов = 75%
    PlayerStats_updateAccuracy(&stats, 75, 100);
    TEST_ASSERT(stats.accuracy == 75, "updateAccuracy(75, 100): accuracy == 75");
    
    // 0 выстрелов = 0%
    PlayerStats_updateAccuracy(&stats, 0, 0);
    TEST_ASSERT(stats.accuracy == 0, "updateAccuracy(0, 0): accuracy == 0");
    
    // 100% точность
    PlayerStats_updateAccuracy(&stats, 100, 100);
    TEST_ASSERT(stats.accuracy == 100, "updateAccuracy(100, 100): accuracy == 100");
    
    // Больше 100% невозможно
    PlayerStats_updateAccuracy(&stats, 150, 100);
    TEST_ASSERT(stats.accuracy == 100, "updateAccuracy(150, 100): accuracy == 100 (ограничение)");
}

// ============================================================================
// ТЕСТ 6: getTotalScore()
// ============================================================================
void test_get_total_score()
{
    std::cout << "\n=== ТЕСТ 6: getTotalScore() ===" << std::endl;
    
    PlayerStats stats;
    PlayerStats_Init(&stats);
    
    // Базовый счет (все нули)
    int32_t score = PlayerStats_getTotalScore(&stats);
    TEST_ASSERT(score == 0, "getTotalScore(): начальный счет == 0");
    
    // Убито 10 гражданских (1 очко каждый)
    stats.civiliansKilled = 10;
    score = PlayerStats_getTotalScore(&stats);
    TEST_ASSERT(score == 10, "getTotalScore(): 10 гражданских == 10 очков");
    
    // Убито 5 полицейских (5 очков каждый) = 25
    stats.policeKilled = 5;
    score = PlayerStats_getTotalScore(&stats);
    TEST_ASSERT(score == 35, "getTotalScore(): +5 полицейских == 35 очков");
    
    // Убито 2 Elvis (10 очков каждый) = 20
    stats.elvisKilled = 2;
    score = PlayerStats_getTotalScore(&stats);
    TEST_ASSERT(score == 55, "getTotalScore(): +2 Elvis == 55 очков");
    
    // Угнано 3 машины (2 очка каждая) = 6
    stats.carsStolen = 3;
    score = PlayerStats_getTotalScore(&stats);
    TEST_ASSERT(score == 61, "getTotalScore(): +3 машины == 61 очков");
    
    // Точность > 50% (бонус 50 очков)
    stats.accuracy = 75;
    score = PlayerStats_getTotalScore(&stats);
    TEST_ASSERT(score == 111, "getTotalScore(): точность > 50% == 111 очков");
    
    // Уничтожено 2 летающие машины (25 очков каждая) = 50
    stats.flyingCarsDestroyed = 2;
    score = PlayerStats_getTotalScore(&stats);
    TEST_ASSERT(score == 161, "getTotalScore(): +2 летающие машины == 161 очков");
}

// ============================================================================
// ТЕСТ 7: Комплексный тест
// ============================================================================
void test_comprehensive()
{
    std::cout << "\n=== ТЕСТ 7: Комплексный тест ===" << std::endl;
    
    PlayerStats stats;
    PlayerStats_Init(&stats);
    
    // Симуляция игровой сессии
    PlayerStats_addMoney(&stats, 5000);      // Начальные деньги
    TEST_ASSERT(stats.money == 5000, "Начальные деньги: 5000");
    
    // Игрок совершает действия
    stats.policeKilled = 10;
    stats.civiliansKilled = 20;
    stats.carsStolen = 5;
    PlayerStats_updateAccuracy(&stats, 150, 200);  // 75% точность
    
    // Проверка счета
    int32_t expectedScore = (20 * 1) + (10 * 5) + (5 * 2) + 50;  // 130
    TEST_ASSERT(PlayerStats_getTotalScore(&stats) == expectedScore, 
                "Комплексный счет: " << expectedScore);
    
    // Игрок тратит деньги
    PlayerStats_addMoney(&stats, -2000);
    TEST_ASSERT(stats.money == 3000, "После трат: 3000");
    
    // Сброс статистики
    PlayerStats_reset(&stats);
    TEST_ASSERT(stats.money == 0, "После reset: money == 0");
    TEST_ASSERT(stats.policeKilled == 0, "После reset: policeKilled == 0");
    TEST_ASSERT(stats.accuracy == 0, "После reset: accuracy == 0");
}

// ============================================================================
// MAIN
// ============================================================================
int main(int argc, char* argv[])
{
    std::cout << "============================================" << std::endl;
    std::cout << "Тесты структуры PlayerStats (S161)" << std::endl;
    std::cout << "============================================" << std::endl;
    
    // Запуск всех тестов
    test_struct_size();
    test_field_offsets();
    test_init_and_reset();
    test_add_money();
    test_update_accuracy();
    test_get_total_score();
    test_comprehensive();
    
    // Итоги
    std::cout << "\n============================================" << std::endl;
    std::cout << "ИТОГИ:" << std::endl;
    std::cout << "  Пройдено: " << tests_passed << std::endl;
    std::cout << "  Провалено: " << tests_failed << std::endl;
    std::cout << "============================================" << std::endl;
    
    return tests_failed > 0 ? 1 : 0;
}
