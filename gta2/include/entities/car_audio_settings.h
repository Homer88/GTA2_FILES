/**
 * @file car_audio_settings.h
 * @brief Структуры аудиосистемы автомобилей (S8, S9)
 * 
 * Старые имена:
 *   S8 -> CarAudioSettings
 *   S9 -> CAudioSourceParams (ранее ошибочно Point2D)
 * 
 * Адрес глобальной переменной: gCarAudioSettings (0x005E4878 - требует уточнения)
 * Размер структуры: 0x14 (20 байт)
 * Конструктор: 0x004254F0 (S8::S8)
 */

#ifndef GTA2_CAR_AUDIO_SETTINGS_H
#define GTA2_CAR_AUDIO_SETTINGS_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

// Forward declarations
struct CarAudioSettings;
struct CAudioSourceParams;

/**
 * @brief Параметры звукового источника (бывшая S9)
 * Размер: 24 байта (0x18)
 * 
 * Ранее ошибочно считалась Point2D. На самом деле содержит
 * расширенные параметры звука (ID, громкость, позиция 3D).
 * Конструктор: S9::S9 (адрес требует уточнения)
 */
typedef struct CAudioSourceParams {
    int32_t soundId;          // 0x00 - ID звука (сирена, двигатель и т.д.)
    float volumeBase;         // 0x04 - Базовая громкость
    int32_t priority;         // 0x08 - Приоритет воспроизведения
    float posX;               // 0x0C - Смещение по X
    float posY;               // 0x10 - Смещение по Y
    float posZ;               // 0x14 - Смещение по Z
} CAudioSourceParams;

// Проверка размера
#ifdef __cplusplus
static_assert(sizeof(CAudioSourceParams) == 24, "CAudioSourceParams size must be 24 bytes");
#endif

/**
 * @brief Настройки аудио автомобиля (бывшая S8)
 * Размер: 20 байт (0x14)
 * 
 * Содержит флаги состояния и указатель на параметры источника.
 */
typedef struct CarAudioSettings {
    uint8_t  flags;           // 0x00 - Общие флаги активности
    uint8_t  sirenActive;     // 0x01 - Флаг активной сирены
    uint8_t  hornActive;      // 0x02 - Флаг активного клаксона
    uint8_t  padding;         // 0x03 - Выравнивание
    int32_t  field_04;        // 0x04 - Неизвестное поле (таймер?)
    void*    pPlayer;         // 0x08 - Указатель на игрока (для расчета дистанции)
    int32_t  currentSoundId;  // 0x0C - Текущий проигрываемый ID
    CAudioSourceParams* pSourceParams; // 0x10 - Указатель на S9 (CAudioSourceParams)
} CarAudioSettings;

// Проверка размера
#ifdef __cplusplus
static_assert(sizeof(CarAudioSettings) == 20, "CarAudioSettings size must be 20 bytes");
#endif

// Глобальная переменная
extern CarAudioSettings* gCarAudioSettings;

// Function prototypes
CarAudioSettings* CarAudioSettings__ctor(CarAudioSettings* this_ptr);
CAudioSourceParams* CAudioSourceParams__ctor(CAudioSourceParams* this_ptr);

#ifdef __cplusplus
}
#endif

#endif // GTA2_CAR_AUDIO_SETTINGS_H
