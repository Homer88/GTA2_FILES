/**
 * @file audio.cpp
 * @brief C++ обертки для аудио-системы GTA2
 * 
 * Оригинальный файл: gta2.exe/ida pro/gta2.exe.c
 * Модуль: Audio System
 * 
 * Примечание: Используются структуры вместо классов, как требуется для совместимости с C кодом.
 */

#include "audio.h"

namespace GTA2 {
namespace Audio {

    /**
     * @brief Инициализация аудио системы
     * old_name: sub_00401000 (Audio_Init)
     */
    void Init(AudioManager* manager) {
        ::Audio_Init(manager);
    }

    /**
     * @brief Обновление аудио системы (каждый кадр)
     * old_name: sub_00401150 (Audio_Update)
     */
    void Update(AudioManager* manager) {
        ::Audio_Update(manager);
    }

    /**
     * @brief Воспроизведение звукового эффекта
     * old_name: sub_00401300 (Audio_PlaySFX)
     */
    int PlaySFX(AudioManager* manager, int soundId, AudioSoundParams* params) {
        return ::Audio_PlaySFX(manager, soundId, params);
    }

    /**
     * @brief Остановка звука на канале
     * old_name: sub_00401450 (Audio_StopChannel)
     */
    void StopChannel(AudioManager* manager, int channelId) {
        ::Audio_StopChannel(manager, channelId);
    }

    /**
     * @brief Установка позиции слушателя (камеры) для 3D звука
     * old_name: sub_00401500 (Audio_SetListenerPos)
     */
    void SetListenerPos(AudioManager* manager, float x, float y, float z) {
        ::Audio_SetListenerPos(manager, x, y, z);
    }

    /**
     * @brief Воспроизведение голосовой реплики
     * old_name: sub_00401600 (Audio_PlayVoice)
     */
    int PlayVoice(AudioManager* manager, int voiceId, AudioPriority priority) {
        return ::Audio_PlayVoice(manager, voiceId, priority);
    }

    /**
     * @brief Старт музыкального трека
     * old_name: sub_00401750 (Audio_PlayMusic)
     */
    void PlayMusic(AudioManager* manager, int trackId, int fadeTime) {
        ::Audio_PlayMusic(manager, trackId, fadeTime);
    }

    /**
     * @brief Остановка музыки с затуханием
     * old_name: sub_00401850 (Audio_StopMusic)
     */
    void StopMusic(AudioManager* manager, int fadeTime) {
        ::Audio_StopMusic(manager, fadeTime);
    }

    /**
     * @brief Установка громкости мастер-канала
     * old_name: sub_00401900 (Audio_SetMasterVolume)
     */
    void SetMasterVolume(AudioManager* manager, int volume) {
        ::Audio_SetMasterVolume(manager, volume);
    }

    /**
     * @brief Обработка звуков транспорта (двигатель, клаксон)
     * old_name: sub_00401A00 (Audio_UpdateVehicleSounds)
     */
    void UpdateVehicleSounds(AudioManager* manager, void* vehiclePtr) {
        ::Audio_UpdateVehicleSounds(manager, vehiclePtr);
    }

    /**
     * @brief Воспроизведение звука выстрела
     * old_name: sub_00401B50 (Audio_PlayGunshot)
     */
    void PlayGunshot(AudioManager* manager, int weaponId, float x, float y, float z) {
        ::Audio_PlayGunshot(manager, weaponId, x, y, z);
    }

    /**
     * @brief Проверка видимости источника звука (для заглушения стенами)
     * old_name: sub_00401C50 (Audio_CheckOcclusion)
     */
    float CheckOcclusion(AudioManager* manager, AudioChannel* channel) {
        return ::Audio_CheckOcclusion(manager, channel);
    }

    /**
     * @brief Загрузка звукового банка из файла
     * old_name: sub_00401D50 (Audio_LoadBank)
     */
    bool LoadBank(AudioManager* manager, const char* filename) {
        return ::Audio_LoadBank(manager, filename);
    }

    /**
     * @brief Выгрузка всех звуковых ресурсов
     * old_name: sub_00401E50 (Audio_Shutdown)
     */
    void Shutdown(AudioManager* manager) {
        ::Audio_Shutdown(manager);
    }

    /**
     * @brief Получение статуса канала
     * old_name: sub_00401F00 (Audio_GetChannelState)
     */
    AudioState GetChannelState(AudioManager* manager, int channelId) {
        return ::Audio_GetChannelState(manager, channelId);
    }

    /**
     * @brief Настройка параметров активного канала
     * old_name: sub_00401F80 (Audio_SetChannelParams)
     */
    void SetChannelParams(AudioManager* manager, int channelId, float volume, float pitch) {
        ::Audio_SetChannelParams(manager, channelId, volume, pitch);
    }

} // namespace Audio
} // namespace GTA2
