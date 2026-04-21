/**
 * @file car_audio_settings.h
 * @brief Настройки аудио автомобилей GTA 2.
 * 
 * Адрес глобальной переменной: gCarAudioSettings (требует уточнения)
 * Размер структуры: 0x14 (20 байт)
 * Конструктор: 0x00??? (S8::S8, требует уточнения)
 * 
 * Старое имя: S8
 * Новое имя: CarAudioSettings
 */

#ifndef GTA2_CAR_AUDIO_SETTINGS_H
#define GTA2_CAR_AUDIO_SETTINGS_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

extern CarAudioSettings* gCarAudioSettings;

typedef struct CarAudioSettings {
    /* 0x00 */ uint8_t data[0x14];   // Внутренние данные аудио настроек
} CarAudioSettings;

#ifdef __cplusplus
static_assert(sizeof(CarAudioSettings) == 0x14, "CarAudioSettings size must be 0x14");
#endif

CarAudioSettings* CarAudioSettings__ctor(CarAudioSettings* this);
void CarAudioSettings__dtor(CarAudioSettings* this);

#ifdef __cplusplus
}
#endif

#endif // GTA2_CAR_AUDIO_SETTINGS_H
