/**
 * @file audio.c
 * @brief Реализация аудио-системы GTA2
 * 
 * Оригинальный файл: gta2.exe/ida pro/gta2.exe.c
 * Модуль: Audio System
 */

#include "audio.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>

// Глобальный экземпляр менеджера (если используется в игре)
// AudioManager g_AudioManager;

/**
 * @brief Инициализация аудио системы
 * old_name: sub_00401000
 * old_var: Manager, Channels, MasterVolume
 */
void Audio_Init(AudioManager* manager) {
    if (!manager) return;

    // old_var: i
    for (int i = 0; i < MAX_SOUND_CHANNELS; i++) {
        manager->Channels[i].Id = -1;
        manager->Channels[i].State = AUDIO_STOPPED;
        manager->Channels[i].SoundId = -1;
        manager->Channels[i].IsLoaded = false;
        manager->Channels[i].BufferPtr = NULL;
    }

    // old_var: j
    for (int j = 0; j < MAX_MUSIC_TRACKS; j++) {
        manager->MusicTracks[j].Id = -1;
        manager->MusicTracks[j].State = AUDIO_STOPPED;
        manager->MusicTracks[j].Volume = 0.0f;
        memset(manager->MusicTracks[j].Name, 0, sizeof(manager->MusicTracks[j].Name));
    }

    manager->MasterVolume = 80;   // Default 80%
    manager->SfxVolume = 100;
    manager->MusicVolume = 100;
    manager->VoiceVolume = 100;
    manager->IsMuted = false;
    manager->IsInitialised = true;
    manager->ActiveChannelCount = 0;
    manager->LastPlayedVoiceId = -1;
    manager->CameraX = 0.0f;
    manager->CameraY = 0.0f;
    manager->CameraZ = 0.0f;

    // Здесь мог бы быть вызов API инициализации DirectSound/WaveOut
    // old_name: sub_00401050 (Audio_InitDevice)
}

/**
 * @brief Обновление аудио системы (каждый кадр)
 * old_name: sub_00401150
 * old_var: i, channel, elapsed
 */
void Audio_Update(AudioManager* manager) {
    if (!manager || !manager->IsInitialised) return;

    // old_var: i
    for (int i = 0; i < MAX_SOUND_CHANNELS; i++) {
        AudioChannel* channel = &manager->Channels[i];
        
        if (channel->State == AUDIO_PLAYING) {
            // Проверка завершения воспроизведения
            // old_var: elapsed
            int elapsed = 0; // Здесь должно быть реальное время от начала
            if (channel->Duration > 0 && elapsed >= channel->Duration) {
                if (channel->LoopCount != 0) {
                    // Перезапуск если зациклен
                    if (channel->LoopCount > 0) {
                        channel->LoopCount--;
                    }
                    // Restart sound logic here
                } else {
                    // Остановка если не зациклен
                    channel->State = AUDIO_STOPPED;
                    channel->SoundId = -1;
                    manager->ActiveChannelCount--;
                }
            }

            // Обновление 3D параметров
            if (channel->Params.Is3D) {
                // Расчет дистанции до камеры
                // old_var: dx, dy, dz, dist
                float dx = channel->Params.PositionX - manager->CameraX;
                float dy = channel->Params.PositionY - manager->CameraY;
                float dz = channel->Params.PositionZ - manager->CameraZ;
                float dist = sqrtf(dx*dx + dy*dy + dz*dz);

                // Затухание с расстоянием
                if (dist > channel->Params.MaxDistance) {
                    // Сделать тише или остановить
                }
            }
        }
    }

    // Обновление музыки (фейды)
    // old_var: t
    for (int t = 0; t < MAX_MUSIC_TRACKS; t++) {
        MusicTrack* track = &manager->MusicTracks[t];
        if (track->State == AUDIO_FADING_IN || track->State == AUDIO_FADING_OUT) {
            // Логика фейда громкости
            if (track->Volume >= track->FadeTarget) {
                track->Volume -= 0.01f; // Пример скорости
                if (track->Volume <= track->FadeTarget) {
                    track->Volume = track->FadeTarget;
                    track->State = (track->FadeTarget > 0.0f) ? AUDIO_PLAYING : AUDIO_STOPPED;
                }
            } else {
                track->Volume += 0.01f;
                if (track->Volume >= track->FadeTarget) {
                    track->Volume = track->FadeTarget;
                    track->State = AUDIO_PLAYING;
                }
            }
        }
    }
}

/**
 * @brief Воспроизведение звукового эффекта
 * old_name: sub_00401300
 * old_var: slot, params
 */
int Audio_PlaySFX(AudioManager* manager, int soundId, AudioSoundParams* params) {
    if (!manager) return -1;

    // Поиск свободного канала
    // old_var: i, slot
    int slot = -1;
    for (int i = 0; i < MAX_SOUND_CHANNELS; i++) {
        if (manager->Channels[i].State == AUDIO_STOPPED) {
            slot = i;
            break;
        }
    }

    if (slot == -1) {
        // Все каналы заняты, возможно вытеснить низкоприоритетный
        return -1;
    }

    AudioChannel* channel = &manager->Channels[slot];
    channel->Id = slot;
    channel->SoundId = soundId;
    channel->Type = CHANNEL_SFX;
    channel->State = AUDIO_PLAYING;
    channel->TimeStarted = 0; // Текущее время
    channel->LoopCount = 0;
    
    if (params) {
        memcpy(&channel->Params, params, sizeof(AudioSoundParams));
    }

    manager->ActiveChannelCount++;
    return slot;
}

/**
 * @brief Остановка звука на канале
 * old_name: sub_00401450
 * old_var: channel
 */
void Audio_StopChannel(AudioManager* manager, int channelId) {
    if (!manager || channelId < 0 || channelId >= MAX_SOUND_CHANNELS) return;

    AudioChannel* channel = &manager->Channels[channelId];
    if (channel->State != AUDIO_STOPPED) {
        channel->State = AUDIO_STOPPED;
        channel->SoundId = -1;
        if (manager->ActiveChannelCount > 0) {
            manager->ActiveChannelCount--;
        }
    }
}

/**
 * @brief Установка позиции слушателя (камеры) для 3D звука
 * old_name: sub_00401500
 * old_var: x, y, z
 */
void Audio_SetListenerPos(AudioManager* manager, float x, float y, float z) {
    if (!manager) return;
    manager->CameraX = x;
    manager->CameraY = y;
    manager->CameraZ = z;
}

/**
 * @brief Воспроизведение голосовой реплики
 * old_name: sub_00401600
 * old_var: voiceSlot, priority
 */
int Audio_PlayVoice(AudioManager* manager, int voiceId, AudioPriority priority) {
    if (!manager) return -1;

    // Приоритетная логика: если критично, прервать текущий голос
    if (priority == PRIORITY_CRITICAL) {
        if (manager->LastPlayedVoiceId != -1) {
            Audio_StopChannel(manager, manager->LastPlayedVoiceId);
        }
    }

    AudioSoundParams params = {0};
    params.Is3D = false;
    params.Volume = 1.0f;
    params.Priority = priority;

    int slot = Audio_PlaySFX(manager, voiceId, &params);
    if (slot != -1) {
        manager->Channels[slot].Type = CHANNEL_VOICE;
        manager->LastPlayedVoiceId = slot;
    }
    return slot;
}

/**
 * @brief Старт музыкального трека
 * old_name: sub_00401750
 * old_var: trackIdx, fade
 */
void Audio_PlayMusic(AudioManager* manager, int trackId, int fadeTime) {
    if (!manager) return;

    // Найти трек или свободный слот
    // old_var: i
    int slot = -1;
    for (int i = 0; i < MAX_MUSIC_TRACKS; i++) {
        if (manager->MusicTracks[i].Id == trackId) {
            slot = i;
            break;
        }
        if (manager->MusicTracks[i].State == AUDIO_STOPPED && slot == -1) {
            slot = i;
        }
    }

    if (slot != -1) {
        MusicTrack* track = &manager->MusicTracks[slot];
        track->Id = trackId;
        track->State = AUDIO_FADING_IN;
        track->FadeTarget = 1.0f;
        track->FadeSpeed = (fadeTime > 0) ? (1.0f / fadeTime) : 1.0f;
        track->IsLooping = true;
    }
}

/**
 * @brief Остановка музыки с затуханием
 * old_name: sub_00401850
 * old_var: i, fade
 */
void Audio_StopMusic(AudioManager* manager, int fadeTime) {
    if (!manager) return;

    // old_var: i
    for (int i = 0; i < MAX_MUSIC_TRACKS; i++) {
        MusicTrack* track = &manager->MusicTracks[i];
        if (track->State == AUDIO_PLAYING || track->State == AUDIO_FADING_IN) {
            track->State = AUDIO_FADING_OUT;
            track->FadeTarget = 0.0f;
            track->FadeSpeed = (fadeTime > 0) ? (1.0f / fadeTime) : 0.1f;
        }
    }
}

/**
 * @brief Установка громкости мастер-канала
 * old_name: sub_00401900
 * old_var: vol
 */
void Audio_SetMasterVolume(AudioManager* manager, int volume) {
    if (!manager) return;
    if (volume < 0) volume = 0;
    if (volume > 100) volume = 100;
    manager->MasterVolume = volume;
}

/**
 * @brief Обработка звуков транспорта (двигатель, клаксон)
 * old_name: sub_00401A00
 * old_var: vehicle, engineSound, hornSound, speed
 */
void Audio_UpdateVehicleSounds(AudioManager* manager, void* vehiclePtr) {
    if (!manager || !vehiclePtr) return;

    // Здесь должна быть логика casts к S82_BaseCar*
    // old_var: car, speedRatio, pitch
    // float speedRatio = car->Speed / car->MaxSpeed;
    // float pitch = 0.5f + (speedRatio * 0.5f); // Изменение тона от скорости
    
    // Обновление существующего звука двигателя или создание нового
    // Проверка нажатия клаксона
}

/**
 * @brief Воспроизведение звука выстрела
 * old_name: sub_00401B50
 * old_var: wpnId, px, py, pz
 */
void Audio_PlayGunshot(AudioManager* manager, int weaponId, float x, float y, float z) {
    if (!manager) return;

    AudioSoundParams params = {0};
    params.PositionX = x;
    params.PositionY = y;
    params.PositionZ = z;
    params.Is3D = true;
    params.Volume = 1.0f;
    params.MinDistance = 5.0f;
    params.MaxDistance = 100.0f;

    // Разные звуки для разного оружия
    int soundId = weaponId; // Упрощенно
    Audio_PlaySFX(manager, soundId, &params);
}

/**
 * @brief Проверка видимости источника звука (для заглушения стенами)
 * old_name: sub_00401C50
 * old_var: chan, rayHit
 */
float Audio_CheckOcclusion(AudioManager* manager, AudioChannel* channel) {
    if (!manager || !channel) return 1.0f;

    // old_var: hit
    // Логика Raycast от камеры до источника звука
    // Если попадание в стену -> вернуть 0.3f (приглушить)
    return 1.0f;
}

/**
 * @brief Загрузка звукового банка из файла
 * old_name: sub_00401D50
 * old_var: file, buffer
 */
bool Audio_LoadBank(AudioManager* manager, const char* filename) {
    if (!manager || !filename) return false;
    
    // Логика загрузки файла .BANK или .DAT
    // Парсинг заголовков, заполнение буферов
    return true;
}

/**
 * @brief Выгрузка всех звуковых ресурсов
 * old_name: sub_00401E50
 * old_var: i
 */
void Audio_Shutdown(AudioManager* manager) {
    if (!manager) return;

    // old_var: i
    for (int i = 0; i < MAX_SOUND_CHANNELS; i++) {
        Audio_StopChannel(manager, i);
        manager->Channels[i].BufferPtr = NULL;
    }

    manager->IsInitialised = false;
}

/**
 * @brief Получение статуса канала
 * old_name: sub_00401F00
 * old_var: ch
 */
AudioState Audio_GetChannelState(AudioManager* manager, int channelId) {
    if (!manager || channelId < 0 || channelId >= MAX_SOUND_CHANNELS) {
        return AUDIO_STOPPED;
    }
    return manager->Channels[channelId].State;
}

/**
 * @brief Настройка параметров активного канала
 * old_name: sub_00401F80
 * old_var: ch, vol, pit
 */
void Audio_SetChannelParams(AudioManager* manager, int channelId, float volume, float pitch) {
    if (!manager || channelId < 0 || channelId >= MAX_SOUND_CHANNELS) return;

    AudioChannel* channel = &manager->Channels[channelId];
    channel->Params.Volume = volume;
    channel->Params.Pitch = pitch;
}
