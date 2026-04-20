/**
 * @file audio_details.h
 * @brief Детальные структуры аудио системы (сэмплы, каналы, радио).
 * 
 * Описывает внутреннее представление звуковых данных и активных каналов.
 */

#ifndef AUDIO_DETAILS_H
#define AUDIO_DETAILS_H

#include "types.h"
#include "math_types/vector3d.h" // Предполагается наличие

#pragma pack(push, 1)

/**
 * @brief Описание звукового сэмпла.
 * Оригинал IDA: `struct Sample` / `SND_SAMPLE`
 * Хранится в звуковых банках (.bank, .wav в архивах).
 */
typedef struct SoundSample {
    u32 ID;                 // 0x00: Уникальный идентификатор звука
    u32 DataOffset;         // 0x04: Смещение к данным в файле/памяти
    u32 LengthBytes;        // 0x08: Длина в байтах
    u32 SampleRate;         // 0x0C: Частота дискретизации (Гц)
    u8  Channels;           // 0x10: Количество каналов (1=моно, 2=стерео)
    u8  CompressionType;    // 0x11: Тип сжатия (0=PCM, 1=IMA ADPCM)
    u16 Flags;              // 0x12: Флаги (зацикливание, 3D звук)
    f32 VolumeDefault;      // 0x14: Громкость по умолчанию
} SoundSample;

/**
 * @brief Активный аудиоканал.
 * Оригинал IDA: Массив `Channels` / `AUD_CHANNEL`
 * Управляет воспроизведением конкретного звука в данный момент.
 */
typedef struct AudioChannel {
    u32 SampleID;           // 0x00: ID проигрываемого сэмпла
    void* BufferPtr;        // 0x04: Указатель на буфер данных
    u32 Position;           // 0x08: Текущая позиция воспроизведения (байты)
    f32 Volume;             // 0x0C: Текущая громкость (0.0 - 1.0)
    f32 Pan;                // 0x10: Панорама (-1.0 лево, 1.0 право)
    f32 Pitch;              // 0x14: Высота тона (1.0 = норма)
    Vector3D Position3D;    // 0x18: Позиция источника в мире (для 3D звука)
    bool IsPlaying;         // 0x24: Статус воспроизведения
    bool IsLooping;         // 0x25: Зациклен ли звук
    bool Is3D;              // 0x26: Используется ли 3D позиционирование
    u8  Priority;           // 0x27: Приоритет канала (важные звуки не прерываются)
} AudioChannel;

/**
 * @brief Параметры реверберации (эха).
 * Оригинал IDA: `struct ReverbParams` / `RVB_PARAMS`
 * Применяется в туннелях, помещениях, под водой.
 */
typedef struct ReverbParams {
    f32 DecayTime;          // 0x00: Время затухания эха
    f32 EarlyDelay;         // 0x04: Задержка ранних отражений
    f32 LateDelay;          // 0x08: Задержка поздних отражений
    f32 Diffusion;          // 0x0C: Рассеивание
    f32 Density;            // 0x10: Плотность
    f32 LowFreqGain;        // 0x14: Усиление низких частот
    u8  Type;               // 0x18: Тип помещения (Туннель, Комната, Улица)
    u8  Enabled;            // 0x19: Активно ли
    u16 Reserved;           // 0x1A: Выравнивание
} ReverbParams;

/**
 * @brief Трек радио.
 * Оригинал IDA: `struct RadioTrack` / `RADIO_TRK`
 */
typedef struct RadioTrack {
    u32 SampleID;           // 0x00: ID аудиофайла трека
    u32 DurationSec;        // 0x04: Длительность в секундах
    u8  Genre;              // 0x08: Жанр (Рок, Поп, Техно)
    u8  Mood;               // 0x09: Настроение (Веселое, Агрессивное)
    u16 StationID;          // 0x0A: ID радиостанции
    char Title[32];         // 0x0C: Название трека
} RadioTrack;

/**
 * @brief Контекст звукового банка.
 * Объединяет список сэмплов.
 */
typedef struct SoundBank {
    u32 Magic;              // Сигнатура "GTAS"
    u32 SampleCount;        // Количество сэмплов
    SoundSample* Samples;   // Массив описаний сэмплов
    void* RawData;          // Указатель на сырые аудиоданные
} SoundBank;

#pragma pack(pop)

#endif // AUDIO_DETAILS_H
