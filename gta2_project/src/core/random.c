/**
 * @file random.c
 * @brief Реализация генератора псевдослучайных чисел (LCG)
 * 
 * Старые имена из IDA:
 * - FUN_00402000 -> Random_Init
 * - FUN_00402050 -> Random_Next
 * - FUN_00402100 -> Random_Range
 * - DAT_00500100 -> g_random_seed
 */

#include "core/random.h"

// Глобальный генератор
RandomGenerator g_random = {0};

// Параметры LCG (как в glibc / многих играх)
// Formula: next = (a * current + c) % m
#define LCG_A 1103515245u
#define LCG_C 12345u
#define LCG_M 2147483648u // 2^31

// -----------------------------------------------------------------------------
// Инициализация
// IDA: FUN_00402000
// -----------------------------------------------------------------------------

void Random_Init(RandomGenerator* rng, u32 seed) {
    if (!rng) return;
    
    rng->seed = seed ? seed : 1; // seed=0 не допускается
    rng->calls = 0;
}

// -----------------------------------------------------------------------------
// Следующее число
// IDA: FUN_00402050
// -----------------------------------------------------------------------------

u32 Random_Next(RandomGenerator* rng) {
    if (!rng) return 0;
    
    // LCG формула
    rng->seed = (LCG_A * rng->seed + LCG_C) % LCG_M;
    rng->calls++;
    
    return rng->seed;
}

// -----------------------------------------------------------------------------
// Диапазон [min, max]
// IDA: FUN_00402100
// -----------------------------------------------------------------------------

u32 Random_Range(RandomGenerator* rng, u32 min, u32 max) {
    if (!rng || min > max) {
        return min;
    }
    
    if (min == max) {
        return min;
    }
    
    u32 range = max - min + 1;
    u32 value = Random_Next(rng) % range;
    
    return min + value;
}

// -----------------------------------------------------------------------------
// Float [0.0, 1.0]
// -----------------------------------------------------------------------------

f32 Random_Float(RandomGenerator* rng) {
    if (!rng) return 0.0f;
    
    u32 value = Random_Next(rng);
    
    // Нормализуем в диапазон [0, 1]
    return (f32)value / (f32)LCG_M;
}

// -----------------------------------------------------------------------------
// Шанс (0-100%)
// -----------------------------------------------------------------------------

bool Random_Chance(RandomGenerator* rng, u32 chance_percent) {
    if (!rng) return false;
    
    if (chance_percent >= 100) {
        return true;
    }
    
    if (chance_percent == 0) {
        return false;
    }
    
    u32 roll = Random_Range(rng, 1, 100);
    
    return roll <= chance_percent;
}
