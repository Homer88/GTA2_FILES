/**
 * @file time_manager.c
 * @brief Реализация системы игрового времени
 * 
 * Старые имена из IDA:
 * - FUN_00403000 -> Time_Init
 * - FUN_00403100 -> Time_Update
 * - FUN_00403200 -> Time_GetHours
 * - DAT_00500200 -> g_game_time
 */

#include "core/time_manager.h"

// Глобальное время
GameTime g_game_time = {0};

// -----------------------------------------------------------------------------
// Инициализация
// IDA: FUN_00403000
// -----------------------------------------------------------------------------

void Time_Init(GameTime* time, u32 start_hour, u32 start_minute) {
    if (!time) return;
    
    time->total_ticks = 0;
    time->frame_count = 0;
    time->time_scale = 1.0f;
    time->paused = false;
    time->day_number = 1;
    
    // Устанавливаем начальное время
    Time_Set(time, start_hour, start_minute);
}

// -----------------------------------------------------------------------------
// Обновление
// IDA: FUN_00403100
// -----------------------------------------------------------------------------

void Time_Update(GameTime* time, f32 delta_seconds) {
    if (!time || time->paused) {
        return;
    }
    
    // Применяем масштаб времени
    f32 scaled_delta = delta_seconds * time->time_scale;
    
    // Преобразуем в минуты (1 минута игры = X секунд реального времени)
    // В GTA 2: 1 час игры = 2 минуты реального времени (масштаб 1:30)
    f32 game_minutes = scaled_delta * 30.0f; // 30 игровых минут в секунду
    
    time->total_ticks += (u32)(scaled_delta * TICKS_PER_SECOND);
    time->frame_count++;
    
    // Добавляем минуты
    u32 total_minutes = time->hours * MINUTES_PER_HOUR + time->minutes;
    total_minutes += (u32)game_minutes;
    
    // Пересчитываем часы и дни
    while (total_minutes >= MINUTES_PER_HOUR * HOURS_PER_DAY) {
        total_minutes -= MINUTES_PER_HOUR * HOURS_PER_DAY;
        time->day_number++;
    }
    
    time->hours = total_minutes / MINUTES_PER_HOUR;
    time->minutes = total_minutes % MINUTES_PER_HOUR;
    time->seconds = (u32)(game_minutes * SECONDS_PER_MINUTE) % SECONDS_PER_MINUTE;
    
    // Обновляем период суток
    if (time->hours >= 0 && time->hours < 6) {
        time->period = TIME_NIGHT;
    } else if (time->hours >= 6 && time->hours < 8) {
        time->period = TIME_DAWN;
    } else if (time->hours >= 8 && time->hours < 18) {
        time->period = TIME_DAY;
    } else if (time->hours >= 18 && time->hours < 20) {
        time->period = TIME_DUSK;
    } else {
        time->period = TIME_EVENING;
    }
}

// -----------------------------------------------------------------------------
// Получение часа
// IDA: FUN_00403200
// -----------------------------------------------------------------------------

u32 Time_GetHours(const GameTime* time) {
    if (!time) return 0;
    return time->hours;
}

// -----------------------------------------------------------------------------
// Получение минут
// -----------------------------------------------------------------------------

u32 Time_GetMinutes(const GameTime* time) {
    if (!time) return 0;
    return time->minutes;
}

// -----------------------------------------------------------------------------
// Получение периода
// -----------------------------------------------------------------------------

TimeOfDay Time_GetPeriod(const GameTime* time) {
    if (!time) return TIME_DAY;
    return time->period;
}

// -----------------------------------------------------------------------------
// Проверка на ночь
// -----------------------------------------------------------------------------

bool Time_IsNight(const GameTime* time) {
    if (!time) return false;
    return (time->period == TIME_NIGHT || time->period == TIME_EVENING);
}

// -----------------------------------------------------------------------------
// Установка времени
// -----------------------------------------------------------------------------

void Time_Set(GameTime* time, u32 hours, u32 minutes) {
    if (!time) return;
    
    // Нормализуем
    hours = hours % HOURS_PER_DAY;
    minutes = minutes % MINUTES_PER_HOUR;
    
    time->hours = hours;
    time->minutes = minutes;
    time->seconds = 0;
    
    // Обновляем период
    if (hours >= 0 && hours < 6) {
        time->period = TIME_NIGHT;
    } else if (hours >= 6 && hours < 8) {
        time->period = TIME_DAWN;
    } else if (hours >= 8 && hours < 18) {
        time->period = TIME_DAY;
    } else if (hours >= 18 && hours < 20) {
        time->period = TIME_DUSK;
    } else {
        time->period = TIME_EVENING;
    }
}

// -----------------------------------------------------------------------------
// Добавление минут
// -----------------------------------------------------------------------------

void Time_AddMinutes(GameTime* time, u32 minutes) {
    if (!time) return;
    
    u32 total = time->hours * MINUTES_PER_HOUR + time->minutes + minutes;
    
    while (total >= MINUTES_PER_HOUR * HOURS_PER_DAY) {
        total -= MINUTES_PER_HOUR * HOURS_PER_DAY;
        time->day_number++;
    }
    
    time->hours = total / MINUTES_PER_HOUR;
    time->minutes = total % MINUTES_PER_HOUR;
    
    // Обновляем период (через Set для переиспользования логики)
    Time_Set(time, time->hours, time->minutes);
}

// -----------------------------------------------------------------------------
// Пауза
// -----------------------------------------------------------------------------

void Time_SetPaused(GameTime* time, bool paused) {
    if (!time) return;
    time->paused = paused;
}

// -----------------------------------------------------------------------------
// Масштаб времени
// -----------------------------------------------------------------------------

void Time_SetScale(GameTime* time, f32 scale) {
    if (!time || scale <= 0.0f) return;
    time->time_scale = scale;
}
