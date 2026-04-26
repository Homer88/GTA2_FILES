#ifndef DMAUDIO_H
#define DMAUDIO_H

#include <cstdint>
#include <string>

// Класс DMAudio - обертка над DirectSound для GTA 2
class DMAudio {
public:
    // Поля структуры (требуют уточнения по методу Initialise)
    void* direct_sound;           // IDirectSound* (смещение 0x0)
    void* direct_sound_buffer;    // IDirectSoundBuffer* (смещение 0x4)
    void* listener;               // IDirectSound3DListener* (смещение 0x8)
    uint32_t flags;               // Флаги состояния (смещение 0xC)
    uint32_t sample_rate;         // Частота дискретизации (смещение 0x10)
    uint32_t bits_per_sample;     // Бит на сэмпл (смещение 0x14)
    uint32_t channels_count;      // Количество каналов (смещение 0x18)
    uint32_t buffer_size;         // Размер буфера (смещение 0x1C)
    bool is_initialized;          // Флаг инициализации (смещение 0x20)
    bool is_paused;               // Флаг паузы (смещение 0x21)
    uint8_t reserved[0xE0];       // Заполнитель до точного размера

    // Конструктор/Деструктор
    DMAudio();                                                            // 0x0041C240 (0x104 bytes)
    virtual ~DMAudio();                                                   // 0x0041C600 (0x634 bytes)

    // Инициализация и завершение
    bool Initialise();                                                    // 0x0041C350 (0x191 bytes)
    void Service();                                                       // 0x0041C000 (0xC9 bytes)
    void Reset();                                                         // 0x0041C200 (0x35 bytes)
    void Resume();                                                        // 0x0041C150 (0x8D bytes)
    void Pause();                                                         // 0x0041B7B0 (0x774 bytes)
    void StopAllSounds();                                                 // 0x0041B0D0 (0x648 bytes)

    // Управление буферами
    void* CreateSoundBuffer(uint32_t size);                               // 0x0041A3C0 (0xB51 bytes)
    void DestroySoundBuffer(void* buffer);                                // 0x004181E0 (0x20B4 bytes)
    bool LoadSoundBank(const char* path);                                 // 0x00417CE0 (0x9A bytes)
    void UnloadSoundBank();                                               // 0x00417DB0 (0xEE bytes)

    // Воспроизведение
    int PlayOneShot(uint32_t sound_id);                                   // 0x00417410 (0x8CC bytes)
    int PlayLoop(uint32_t sound_id);                                      // 0x00417260 (0x1AC bytes)
    void StopLoop(int channel_id);                                        // 0x004171A0 (0xB2 bytes)
    void SetVolume(int channel_id, int volume);                           // 0x00417030 (0x16D bytes)
    void SetPan(int channel_id, int pan);                                 // 0x00416F20 (0x106 bytes)
    void SetFrequency(int channel_id, uint32_t freq);                     // 0x00416DA0 (0xA3 bytes)
    int GetVolume(int channel_id);                                        // 0x00416C10 (0x11A bytes)
    bool IsPlaying(int channel_id);                                       // 0x00416B20 (0x1D bytes)

    // 3D Звук
    void Set3DPosition(int channel_id, float x, float y, float z);        // 0x004169E0 (0x13C bytes)
    void Set3DListener(float x, float y, float z, float vx, float vy, float vz); // 0x004168E0 (0x5C bytes)
    void Update3DListeners();                                             // 0x00416890 (0x45 bytes)
    void Calculate3DAttributes(int channel_id);                           // 0x004167C0 (0xBD bytes)

    // Управление каналами
    int GetFreeChannel();                                                 // 0x004166E0 (0x67 bytes)
    int AllocateChannel();                                                // 0x00416570 (0x69 bytes)
    void ReleaseChannel(int channel_id);                                  // 0x004163A0 (0xB5 bytes)
    void ResetChannel(int channel_id);                                    // 0x004162C0 (0xDD bytes)

    // Обработка событий
    void ProcessCollision(int type, float intensity);                     // 0x00415F90 (0x328 bytes)
    void ProcessVehicleSound(int vehicle_id);                             // 0x00415EF0 (0x6C bytes)
    void ProcessPedestrianSound(int ped_id);                              // 0x00415DF0 (0xA9 bytes)
    void ProcessWeatherSound(int weather_type);                           // 0x00415D20 (0xC6 bytes)

    // Утилиты
    void* LockBuffer(void* buffer, uint32_t* size);                       // 0x00415CC0 (0x56 bytes)
    void UnlockBuffer(void* buffer);                                      // 0x00415C70 (0x4D bytes)
    void FillBufferWithSilence(void* buffer);                             // 0x00415C30 (0x35 bytes)
    void CopyDataToBuffer(void* dest, const void* src, uint32_t size);    // 0x00415BF0 (0x35 bytes)
    bool CheckHardwareSupport();                                          // 0x00415BE0 (0xF bytes)

    // Специфичные для GTA 2
    void PlayMissionSpeech(int speech_id);                                // 0x00415A90 (0x150 bytes)
    void PlayRadioTrack(int station_id);                                  // 0x00415880 (0x205 bytes)
    void StopRadioTrack();                                                // 0x004156C0 (0x1BB bytes)
    void SetRadioStation(int station_id);                                 // 0x00415520 (0x53 bytes)
    void PlayAmbientSound(int ambient_id);                                // 0x004150E0 (0x307 bytes)

    // Дополнительные
    void nullsub_5();                                                     // 0x00414FA0 (0xEB bytes)
    void nullsub_6();                                                     // 0x00414E50 (0xCF bytes)
    void DebugPrint(const char* format, ...);                             // 0x00414BC0 (0x25D bytes)
    void LogError(int error_code);                                        // 0x004148D0 (0x2E8 bytes)
    bool GetDriverInfo(void* info);                                       // 0x00414780 (0x145 bytes)
    void SetBufferSize(uint32_t size);                                    // 0x004143B0 (0x3C8 bytes)
    void SetSampleRate(uint32_t rate);                                    // 0x00414200 (0x1AA bytes)
    void SetBitsPerSample(uint32_t bits);                                 // 0x00414030 (0x16B bytes)
    void SetChannelsCount(uint32_t count);                                // 0x00413EB0 (0x172 bytes)
};

#endif // DMAUDIO_H
