/**
 * @file car_audio_settings.cpp
 * @brief C++-реализация настроек аудио автомобилей GTA 2.
 * 
 * Размер: 0x14 (20 байт)
 * Старое имя: S8
 */

#include "entities/car_audio_settings.h"
#include <cstring>

CarAudioSettings* gCarAudioSettings = nullptr;

extern "C" {

CarAudioSettings* CarAudioSettings__ctor(CarAudioSettings* this) {
    if (!this) return nullptr;
    std::memset(this->data, 0, sizeof(this->data));
    return this;
}

void CarAudioSettings__dtor(CarAudioSettings* this) {
    (void)this;
}

} /* extern "C" */
