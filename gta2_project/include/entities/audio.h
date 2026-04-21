/**
 * @file audio.h
 * @brief Структуры и функции аудио-системы GTA2
 * 
 * Оригинальный файл: gta2.exe/ida pro/gta2.exe.h
 * Модуль: Audio System
 */

#ifndef GTA2_AUDIO_H
#define GTA2_AUDIO_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// --- Константы ---
#define MAX_SOUND_CHANNELS 32
#define MAX_MUSIC_TRACKS 16
#define MAX_VOICE_SAMPLES 100
#define AUDIO_BUFFER_SIZE 4096

// --- Перечисления ---

/**
 * @brief Типы звуковых каналов
 * old_name: enum SoundChannelType
 */
typedef enum AudioChannelType {
    CHANNEL_AMBIENT = 0,    // Фоновые звуки
    CHANNEL_SFX = 1,        // Эффекты (выстрелы, удары)
    CHANNEL_VOICE = 2,      // Голоса/Реплики
    CHANNEL_MUSIC = 3,      // Музыка
    CHANNEL_VEHICLE = 4     // Звуки транспорта
} AudioChannelType;

/**
 * @brief Состояние аудиопотока
 * old_name: enum AudioState
 */
typedef enum AudioState {
    AUDIO_STOPPED = 0,
    AUDIO_PLAYING = 1,
    AUDIO_PAUSED = 2,
    AUDIO_FADING_OUT = 3,
    AUDIO_FADING_IN = 4
} AudioState;

/**
 * @brief Приоритеты звука
 */
typedef enum AudioPriority {
    PRIORITY_LOW = 0,
    PRIORITY_NORMAL = 1,
    PRIORITY_HIGH = 2,
    PRIORITY_CRITICAL = 3 // Важные сообщения миссий
} AudioPriority;

// --- Структуры ---

/**
 * @brief Параметры звука (3D позиция)
 * old_name: struct S95_SoundParams (предположительно)
 * old_var: X, Y, Z, Volume, Pan
 */
typedef struct AudioSoundParams {
    float PositionX;        // +0x00 Координата X источника
    float PositionY;        // +0x04 Координата Y источника
    float PositionZ;        // +0x08 Координата Z источника
    float Volume;           // +0x0C Громкость (0.0 - 1.0)
    float Pan;              // +0x10 Панорамирование (-1.0 левый, 1.0 правый)
    float Pitch;            // +0x14 Высота тона
    int Priority;           // +0x18 Приоритет воспроизведения
    bool Is3D;              // +0x1C Является ли 3D звуком
    float MinDistance;      // +0x20 Минимальная дистанция слышимости
    float MaxDistance;      // +0x24 Максимальная дистанция
} AudioSoundParams;

/**
 * @brief Активный звуковой канал
 * old_name: struct S96_SoundChannel
 */
typedef struct AudioChannel {
    int Id;                         // +0x00 Уникальный ID канала
    AudioChannelType Type;          // +0x04 Тип канала
    AudioState State;               // +0x08 Текущее состояние
    int SoundId;                    // +0x0C ID воспроизводимого звука
    AudioSoundParams Params;        // +0x10 Параметры звука
    int LoopCount;                  // +0x38 Количество повторений (-1 = бесконечно)
    int TimeStarted;                // +0x3C Время начала воспроизведения (мс)
    int Duration;                   // +0x40 Длительность звука (мс)
    bool IsLoaded;                  // +0x44 Загружен ли ресурс
    void* BufferPtr;                // +0x48 Указатель на буфер данных
} AudioChannel;

/**
 * @brief Трек музыки
 * old_name: struct S97_MusicTrack
 */
typedef struct MusicTrack {
    int Id;                         // +0x00 ID трека
    char Name[32];                  // +0x04 Имя файла/трека
    AudioState State;               // +0x24 Состояние
    float Volume;                   // +0x28 Громкость
    float FadeTarget;               // +0x2C Целевая громкость для фейда
    int FadeSpeed;                  // +0x30 Скорость фейда
    bool IsLooping;                 // +0x34 Зациклен ли трек
} MusicTrack;

/**
 * @brief Менеджер аудио системы
 * old_name: struct S98_AudioManager (Глобальная структура)
 */
typedef struct AudioManager {
    AudioChannel Channels[MAX_SOUND_CHANNELS]; // +0x00 Массив активных каналов
    MusicTrack MusicTracks[MAX_MUSIC_TRACKS];  // +0xXXX Массив музыкальных треков
    int MasterVolume;               // Громкость мастера (0-100)
    int SfxVolume;                  // Громкость эффектов
    int MusicVolume;                // Громкость музыки
    int VoiceVolume;                // Громкость голосов
    bool IsMuted;                   // Флаг отключения звука
    bool IsInitialised;             // Инициализирована ли система
    int ActiveChannelCount;         // Количество активных каналов
    int LastPlayedVoiceId;          // ID последнего воспроизведенного голоса
    float CameraX;                  // +0xXXX Позиция камеры для 3D звука
    float CameraY;                  
    float CameraZ;                  
} AudioManager;

// --- Прототипы функций ---

/**
 * @brief Инициализация аудио системы
 * @param manager Указатель на менеджер аудио
 * old_name: sub_00401000 (Audio_Init)
 */
void Audio_Init(AudioManager* manager);

/**
 * @brief Обновление аудио системы (каждый кадр)
 * @param manager Указатель на менеджер аудио
 * old_name: sub_00401150 (Audio_Update)
 */
void Audio_Update(AudioManager* manager);

/**
 * @brief Воспроизведение звукового эффекта
 * @param manager Менеджер аудио
 * @param soundId ID звука
 * @param params Параметры звука (позиция, громкость)
 * @return ID канала или -1 при ошибке
 * old_name: sub_00401300 (Audio_PlaySFX)
 */
int Audio_PlaySFX(AudioManager* manager, int soundId, AudioSoundParams* params);

/**
 * @brief Остановка звука на канале
 * @param manager Менеджер аудио
 * @param channelId ID канала
 * old_name: sub_00401450 (Audio_StopChannel)
 */
void Audio_StopChannel(AudioManager* manager, int channelId);

/**
 * @brief Установка позиции слушателя (камеры) для 3D звука
 * @param manager Менеджер аудио
 * @param x, y, z Координаты
 * old_name: sub_00401500 (Audio_SetListenerPos)
 */
void Audio_SetListenerPos(AudioManager* manager, float x, float y, float z);

/**
 * @brief Воспроизведение голосовой реплики
 * @param manager Менеджер аудио
 * @param voiceId ID реплики
 * @param priority Приоритет
 * old_name: sub_00401600 (Audio_PlayVoice)
 */
int Audio_PlayVoice(AudioManager* manager, int voiceId, AudioPriority priority);

/**
 * @brief Старт музыкального трека
 * @param manager Менеджер аудио
 * @param trackId ID трека
 * @param fadeTime Время затухания предыдущего трека
 * old_name: sub_00401750 (Audio_PlayMusic)
 */
void Audio_PlayMusic(AudioManager* manager, int trackId, int fadeTime);

/**
 * @brief Остановка музыки с затуханием
 * @param manager Менеджер аудио
 * @param fadeTime Время затухания
 * old_name: sub_00401850 (Audio_StopMusic)
 */
void Audio_StopMusic(AudioManager* manager, int fadeTime);

/**
 * @brief Установка громкости мастер-канала
 * @param manager Менеджер аудио
 * @param volume Уровень (0-100)
 * old_name: sub_00401900 (Audio_SetMasterVolume)
 */
void Audio_SetMasterVolume(AudioManager* manager, int volume);

/**
 * @brief Обработка звуков транспорта (двигатель, клаксон)
 * @param manager Менеджер аудио
 * @param vehiclePtr Указатель на транспортное средство (S82_BaseCar*)
 * old_name: sub_00401A00 (Audio_UpdateVehicleSounds)
 */
void Audio_UpdateVehicleSounds(AudioManager* manager, void* vehiclePtr);

/**
 * @brief Воспроизведение звука выстрела
 * @param manager Менеджер аудио
 * @param weaponId ID оружия
 * @param x, y, z Позиция выстрела
 * old_name: sub_00401B50 (Audio_PlayGunshot)
 */
void Audio_PlayGunshot(AudioManager* manager, int weaponId, float x, float y, float z);

/**
 * @brief Проверка видимости источника звука (для заглушения стенами)
 * @param manager Менеджер аудио
 * @param channel Канал звука
 * @return Множитель громкости (0.0 - 1.0)
 * old_name: sub_00401C50 (Audio_CheckOcclusion)
 */
float Audio_CheckOcclusion(AudioManager* manager, AudioChannel* channel);

/**
 * @brief Загрузка звукового банка из файла
 * @param manager Менеджер аудио
 * @param filename Имя файла банка
 * old_name: sub_00401D50 (Audio_LoadBank)
 */
bool Audio_LoadBank(AudioManager* manager, const char* filename);

/**
 * @brief Выгрузка всех звуковых ресурсов
 * @param manager Менеджер аудио
 * old_name: sub_00401E50 (Audio_Shutdown)
 */
void Audio_Shutdown(AudioManager* manager);

/**
 * @brief Получение статуса канала
 * @param manager Менеджер аудио
 * @param channelId ID канала
 * @return Состояние канала
 * old_name: sub_00401F00 (Audio_GetChannelState)
 */
AudioState Audio_GetChannelState(AudioManager* manager, int channelId);

/**
 * @brief Настройка параметров активного канала
 * @param manager Менеджер аудио
 * @param channelId ID канала
 * @param volume Новая громкость
 * @param pitch Новая высота тона
 * old_name: sub_00401F80 (Audio_SetChannelParams)
 */
void Audio_SetChannelParams(AudioManager* manager, int channelId, float volume, float pitch);

#ifdef __cplusplus
}
#endif

#endif // GTA2_AUDIO_H
