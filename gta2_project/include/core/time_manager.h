/**
 * @file time_manager.h
 * @brief Система игрового времени (тик, день/ночь, пауза)
 * 
 * Старые имена из IDA:
 * - FUN_00403000 -> Time_Init
 * - FUN_00403100 -> Time_Update
 * - FUN_00403200 -> Time_GetHours
 * - DAT_00500200 -> g_game_time
 */

#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H

#include "types.h"

#define SECONDS_PER_MINUTE 60
#define MINUTES_PER_HOUR 60
#define HOURS_PER_DAY 24
#define TICKS_PER_SECOND 60  // GTA 2 работает на 60 FPS

/**
 * @enum TimeOfDay
 * @brief Периоды суток для логики и освещения
 */
typedef enum TimeOfDay {
    TIME_NIGHT = 0,      // 00:00 - 05:59
    TIME_DAWN = 1,       // 06:00 - 07:59
    TIME_DAY = 2,        // 08:00 - 17:59
    TIME_DUSK = 3,       // 18:00 - 19:59
    TIME_EVENING = 4     // 20:00 - 23:59
} TimeOfDay;

/**
 * @struct GameTime
 * @brief Структура игрового времени
 */
typedef struct GameTime {
    u32 total_ticks;        // 0x00: Общее количество тиков с начала игры
    u32 hours;              // 0x04: Текущий час (0-23)
    u32 minutes;            // 0x08: Текущая минута (0-59)
    u32 seconds;            // 0x0C: Текущая секунда (0-59)
    f32 time_scale;         // 0x10: Множитель скорости времени (1.0 = норма)
    bool paused;            // 0x14: Игра на паузе
    TimeOfDay period;       // 0x15: Текущий период суток
    u32 day_number;         // 0x18: Номер дня (для долгосрочных событий)
    u32 frame_count;        // 0x1C: Счетчик кадров (для дельты)
} GameTime;

// --- Функции ---

/**
 * @brief Инициализация системы времени
 * @param time Указатель на структуру времени
 * @param start_hour Начальный час
 * @param start_minute Начальная минута
 * 
 * IDA: FUN_00403000 (Time_Init)
 */
void Time_Init(GameTime* time, u32 start_hour, u32 start_minute);

/**
 * @brief Обновление времени (вызывается каждый кадр)
 * @param time Указатель на структуру времени
 * @param delta_seconds Время, прошедшее с прошлого кадра (в секундах)
 * 
 * IDA: FUN_00403100 (Time_Update)
 */
void Time_Update(GameTime* time, f32 delta_seconds);

/**
 * @brief Получение текущего часа (0-23)
 * @param time Указатель на структуру времени
 * @return Час
 * 
 * IDA: FUN_00403200 (Time_GetHours)
 */
u32 Time_GetHours(const GameTime* time);

/**
 * @brief Получение текущих минут (0-59)
 */
u32 Time_GetMinutes(const GameTime* time);

/**
 * @brief Получение периода суток
 */
TimeOfDay Time_GetPeriod(const GameTime* time);

/**
 * @brief Проверка, ночь ли сейчас
 */
bool Time_IsNight(const GameTime* time);

/**
 * @brief Установка времени
 */
void Time_Set(GameTime* time, u32 hours, u32 minutes);

/**
 * @brief Добавление минут к текущему времени
 */
void Time_AddMinutes(GameTime* time, u32 minutes);

/**
 * @brief Установка паузы
 */
void Time_SetPaused(GameTime* time, bool paused);

/**
 * @brief Установка масштаба времени (замедление/ускорение)
 */
void Time_SetScale(GameTime* time, f32 scale);

/**
 * @brief Глобальная структура времени
 */
extern GameTime g_game_time;

// Быстрые макросы
#define TimeGetHours() Time_GetHours(&g_game_time)
#define TimeGetMinutes() Time_GetMinutes(&g_game_time)
#define TimeGetPeriod() Time_GetPeriod(&g_game_time)
#define TimeIsNight() Time_IsNight(&g_game_time)

#endif // TIME_MANAGER_H
