#include "WeatherManager.h"
#include <string.h>
#include <stdlib.h>

// Глобальные переменные
WeatherManager gWeatherManager;
WeatherManager* pWeatherManager = &gWeatherManager;

/**
 * @brief Конструктор WeatherManager
 */
void WeatherManager__Constructor(WeatherManager* self) {
    if (!self) return;
    
    // Обнуление всей структуры
    memset(self, 0, sizeof(WeatherManager));
    
    // Установка значений по умолчанию
    self->current_hour = 12;          // Полдень
    self->current_minute = 0;
    self->weather_type = 0;           // Ясно
    self->precipitation_intensity = 0;
    self->ambient_light = 1.0f;
    self->sun_brightness = 1.0f;
    self->field_78 = 0;
    self->field_7C = 0;
}

/**
 * @brief Деструктор WeatherManager
 */
void WeatherManager__Destructor(WeatherManager* self) {
    if (!self) return;
    
    // Очистка ресурсов (если необходимо)
    // В данной структуре динамическая память не используется
}

/**
 * @brief Инициализация менеджера погоды
 */
void WeatherManager__Initialize(WeatherManager* self) {
    if (!self) return;
    
    WeatherManager__Constructor(self);
}

/**
 * @brief Обновление состояния погоды
 */
void WeatherManager__Update(WeatherManager* self) {
    if (!self) return;
    
    // TODO: Реализация обновления времени
    // Увеличение минут, проверка перехода часа
    // Вызов WeatherManager__CalculateLighting для обновления освещения
    
    // Примерная логика:
    // self->current_minute++;
    // if (self->current_minute >= 60) {
    //     self->current_minute = 0;
    //     self->current_hour++;
    //     if (self->current_hour >= 24) {
    //         self->current_hour = 0;
    //     }
    // }
}

/**
 * @brief Установка текущего времени
 */
void WeatherManager__SetTime(WeatherManager* self, uint8_t hour, uint8_t minute) {
    if (!self) return;
    
    if (hour < 24) self->current_hour = hour;
    if (minute < 60) self->current_minute = minute;
    
    // Пересчитать освещение после изменения времени
    WeatherManager__CalculateLighting(self);
}

/**
 * @brief Установка типа погоды
 */
void WeatherManager__SetWeatherType(WeatherManager* self, int32_t type) {
    if (!self) return;
    
    self->weather_type = type;
    
    // Сохранить в историю
    WeatherManager__SaveToHistory(self);
}

/**
 * @brief Установка интенсивности осадков
 */
void WeatherManager__SetPrecipitationIntensity(WeatherManager* self, uint8_t intensity) {
    if (!self) return;
    
    self->precipitation_intensity = intensity;
}

/**
 * @brief Расчет уровня освещения
 */
float WeatherManager__CalculateLighting(WeatherManager* self) {
    if (!self) return 1.0f;
    
    // TODO: Реализация расчета освещения на основе времени суток и погоды
    // Ночь: низкое освещение
    // День: высокое освещение
    // Дождь/облачность: снижение освещения
    
    float base_light = 1.0f;
    
    // Простая эвристика по времени
    if (self->current_hour >= 6 && self->current_hour <= 18) {
        base_light = 1.0f;  // День
    } else if (self->current_hour >= 20 || self->current_hour <= 4) {
        base_light = 0.2f;  // Ночь
    } else {
        base_light = 0.5f;  // Рассвет/закат
    }
    
    // Коррекция на погоду
    if (self->weather_type == 1) { // Дождь
        base_light *= 0.7f;
    } else if (self->weather_type == 2) { // Снег
        base_light *= 0.8f;
    }
    
    self->ambient_light = base_light;
    self->sun_brightness = base_light;
    
    return base_light;
}

/**
 * @brief Интерполяция между типами погоды
 */
void WeatherManager__InterpolateWeather(WeatherManager* self, int32_t target_type, int32_t duration) {
    if (!self || duration <= 0) return;
    
    // TODO: Реализация плавного перехода между типами погоды
    // Постепенное изменение precipitation_intensity
    // Постепенное изменение weather_type
}

/**
 * @brief Сохранение текущего состояния погоды в историю
 */
void WeatherManager__SaveToHistory(WeatherManager* self) {
    if (!self) return;
    
    // Сдвиг истории (удаление самой старой записи)
    // Добавление новой записи в конец
    // Использование field_7C как индекса текущей записи
    
    int32_t index = self->field_7C;
    if (index < 0 || index >= 30) {
        index = 0;
    }
    
    self->weather_history[index].hour = self->current_hour;
    self->weather_history[index].minute = self->current_minute;
    self->weather_history[index].weather = (uint8_t)self->weather_type;
    self->weather_history[index].intensity = self->precipitation_intensity;
    
    self->field_7C = (index + 1) % 30;
}

/**
 * @brief Загрузка состояния погоды из истории
 */
void WeatherManager__LoadFromHistory(WeatherManager* self, int32_t index) {
    if (!self || index < 0 || index >= 30) return;
    
    self->current_hour = self->weather_history[index].hour;
    self->current_minute = self->weather_history[index].minute;
    self->weather_type = self->weather_history[index].weather;
    self->precipitation_intensity = self->weather_history[index].intensity;
    
    WeatherManager__CalculateLighting(self);
}

/**
 * @brief Генерация случайной погоды
 */
void WeatherManager__GenerateRandomWeather(WeatherManager* self) {
    if (!self) return;
    
    // TODO: Генерация случайного типа погоды и интенсивности
    // srand(time(NULL)); // Если используется
    // self->weather_type = rand() % 3; // 0-2
    // self->precipitation_intensity = rand() % 256;
    
    WeatherManager__SaveToHistory(self);
}

/**
 * @brief Получение текущего типа погоды
 */
int32_t WeatherManager__GetWeatherType(WeatherManager* self) {
    if (!self) return 0;
    return self->weather_type;
}

/**
 * @brief Получение текущей интенсивности осадков
 */
uint8_t WeatherManager__GetPrecipitationIntensity(WeatherManager* self) {
    if (!self) return 0;
    return self->precipitation_intensity;
}

/**
 * @brief Проверка, идет ли дождь
 */
int32_t WeatherManager__IsRaining(WeatherManager* self) {
    if (!self) return 0;
    return (self->weather_type == 1 && self->precipitation_intensity > 0);
}

/**
 * @brief Проверка, идет ли снег
 */
int32_t WeatherManager__IsSnowing(WeatherManager* self) {
    if (!self) return 0;
    return (self->weather_type == 2 && self->precipitation_intensity > 0);
}
