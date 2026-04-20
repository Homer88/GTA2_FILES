/**
 * @file random.h
 * @brief Генератор псевдослучайных чисел (PRNG)
 * 
 * В GTA 2 используется линейный конгруэнтный генератор (LCG) для скорости.
 * 
 * Старые имена из IDA:
 * - FUN_00402000 -> Random_Init
 * - FUN_00402050 -> Random_Next
 * - FUN_00402100 -> Random_Range
 * - DAT_00500100 -> g_random_seed
 */

#ifndef RANDOM_H
#define RANDOM_H

#include "types.h"

/**
 * @struct RandomGenerator
 * @brief Состояние генератора случайных чисел
 */
typedef struct RandomGenerator {
    u32 seed;           // 0x00: Текущее зерно
    u32 calls;          // 0x04: Счетчик вызовов (для отладки)
} RandomGenerator;

// --- Функции ---

/**
 * @brief Инициализация генератора начальным значением
 * @param rng Указатель на генератор
 * @param seed Начальное зерно
 * 
 * IDA: FUN_00402000 (Random_Init)
 */
void Random_Init(RandomGenerator* rng, u32 seed);

/**
 * @brief Получение следующего случайного числа (0..MAX_UINT)
 * @param rng Указатель на генератор
 * @return Случайное число
 * 
 * IDA: FUN_00402050 (Random_Next)
 */
u32 Random_Next(RandomGenerator* rng);

/**
 * @brief Получение случайного числа в диапазоне [min, max]
 * @param rng Указатель на генератор
 * @param min Минимум (включительно)
 * @param max Максимум (включительно)
 * @return Случайное число в диапазоне
 * 
 * IDA: FUN_00402100 (Random_Range)
 */
u32 Random_Range(RandomGenerator* rng, u32 min, u32 max);

/**
 * @brief Получение случайного float в диапазоне [0.0, 1.0]
 * @param rng Указатель на генератор
 * @return Случайное float число
 */
f32 Random_Float(RandomGenerator* rng);

/**
 * @brief Получение случайного bool с вероятностью true = chance_percent%
 * @param rng Указатель на генератор
 * @param chance_percent Шанс от 0 до 100
 * @return true или false
 */
bool Random_Chance(RandomGenerator* rng, u32 chance_percent);

/**
 * @brief Глобальный генератор (удобно для быстрого доступа)
 */
extern RandomGenerator g_random;

/**
 * @brief Быстрые функции для глобального генератора
 */
#define RandInit(seed) Random_Init(&g_random, seed)
#define RandNext() Random_Next(&g_random)
#define RandRange(min, max) Random_Range(&g_random, min, max)
#define RandFloat() Random_Float(&g_random)
#define RandChance(percent) Random_Chance(&g_random, percent)

#endif // RANDOM_H
