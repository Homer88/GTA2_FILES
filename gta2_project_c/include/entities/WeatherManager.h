#ifndef WEATHERMANAGER_H
#define WEATHERMANAGER_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief WeatherManager (ранее структура S24)
 * 
 * Менеджер погоды и времени суток.
 * Размер: 128 байт
 * 
 * Содержит поля для текущего времени, типа погоды, интенсивности осадков,
 * освещения и буфера истории изменений погоды.
 */
typedef struct {
    // Время суток (0-23 часа или фиксированное значение)
    uint8_t current_hour;           // 0x00: Текущий час
    uint8_t current_minute;         // 0x01: Текущая минута
    uint8_t pad0[2];                // 0x02-0x03: Выравнивание
    
    // Тип погоды
    int32_t weather_type;           // 0x04: Тип погоды (0=ясно, 1=дождь, 2=снег и т.д.)
    
    // Интенсивность осадков (0-255)
    uint8_t precipitation_intensity; // 0x08: Интенсивность осадков
    
    // Освещение/яркость
    float ambient_light;            // 0x0C: Уровень окружающего освещения
    float sun_brightness;           // 0x10: Яркость солнца
    
    // Буфер истории погоды (30 записей по 4 байта = 120 байт)
    struct {
        uint8_t hour;               // Час записи
        uint8_t minute;             // Минута записи
        uint8_t weather;            // Тип погоды в момент записи
        uint8_t intensity;          // Интенсивность в момент записи
    } weather_history[30];          // 0x14 - 0x8B: История погоды
    
    // Дополнительные поля
    int32_t field_78;               // 0x8C: Неизвестное поле (возможно, флаг или таймер)
    int32_t field_7C;               // 0x90: Неизвестное поле (возможно, индекс или счетчик)
    
    // Заполнитель до 128 байт (если требуется точный размер)
    uint8_t padding[56];            // 0x94 - 0xCC: Резерв
} WeatherManager;

// Проверка размера структуры
// static_assert(sizeof(WeatherManager) == 128, "Размер WeatherManager должен быть 128 байт");

/**
 * @brief Конструктор WeatherManager
 * Инициализирует структуру значениями по умолчанию.
 */
void WeatherManager__Constructor(WeatherManager* self);

/**
 * @brief Деструктор WeatherManager
 */
void WeatherManager__Destructor(WeatherManager* self);

/**
 * @brief Инициализация менеджера погоды
 * @param self Указатель на структуру
 */
void WeatherManager__Initialize(WeatherManager* self);

/**
 * @brief Обновление состояния погоды
 * Вызывается каждый кадр для обновления времени и погодных эффектов.
 */
void WeatherManager__Update(WeatherManager* self);

/**
 * @brief Установка текущего времени
 * @param hour Час (0-23)
 * @param minute Минута (0-59)
 */
void WeatherManager__SetTime(WeatherManager* self, uint8_t hour, uint8_t minute);

/**
 * @brief Установка типа погоды
 * @param type Тип погоды (0=ясно, 1=дождь, 2=снег, etc.)
 */
void WeatherManager__SetWeatherType(WeatherManager* self, int32_t type);

/**
 * @brief Установка интенсивности осадков
 * @param intensity Интенсивность (0-255)
 */
void WeatherManager__SetPrecipitationIntensity(WeatherManager* self, uint8_t intensity);

/**
 * @brief Расчет уровня освещения на основе времени и погоды
 * @return Уровень освещения
 */
float WeatherManager__CalculateLighting(WeatherManager* self);

/**
 * @brief Интерполяция между типами погоды (плавный переход)
 * @param target_type Целевой тип погоды
 * @param duration Длительность перехода в кадрах
 */
void WeatherManager__InterpolateWeather(WeatherManager* self, int32_t target_type, int32_t duration);

/**
 * @brief Сохранение текущего состояния погоды в историю
 */
void WeatherManager__SaveToHistory(WeatherManager* self);

/**
 * @brief Загрузка состояния погоды из истории
 * @param index Индекс записи в истории (0-29)
 */
void WeatherManager__LoadFromHistory(WeatherManager* self, int32_t index);

/**
 * @brief Генерация случайной погоды
 */
void WeatherManager__GenerateRandomWeather(WeatherManager* self);

/**
 * @brief Получение текущего типа погоды
 * @return Тип погоды
 */
int32_t WeatherManager__GetWeatherType(WeatherManager* self);

/**
 * @brief Получение текущей интенсивности осадков
 * @return Интенсивность
 */
uint8_t WeatherManager__GetPrecipitationIntensity(WeatherManager* self);

/**
 * @brief Проверка, идет ли дождь
 * @return 1 если дождь, 0 иначе
 */
int32_t WeatherManager__IsRaining(WeatherManager* self);

/**
 * @brief Проверка, идет ли снег
 * @return 1 если снег, 0 иначе
 */
int32_t WeatherManager__IsSnowing(WeatherManager* self);

// Глобальные переменные
extern WeatherManager gWeatherManager;      // Глобальный экземпляр
extern WeatherManager* pWeatherManager;     // Указатель на экземпляр

#ifdef __cplusplus
}
#endif

#endif // WEATHERMANAGER_H
