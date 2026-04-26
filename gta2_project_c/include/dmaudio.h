#ifndef DMAUDIO_H
#define DMAUDIO_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// Структура DMAudio - обертка над DirectSound
// Размер структуры определяется анализом метода конструктора (0x104 байта кода)
typedef struct DMAudio {
    // TODO: Добавить реальные поля после анализа метода Initialise (0x41C350)
    // Предполагаемые поля:
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
    // ... остальные поля будут добавлены после анализа
    uint8_t reserved[0x100];      // Заполнитель до точного размера
} DMAudio;

// Конструктор/Деструктор
void DMAudio__DMAudio(DMAudio* this);                           // 0x0041C240 (0x104 bytes)
void DMAudio__DMAudio_Des(DMAudio* this);                       // 0x0041C600 (0x634 bytes)

// Инициализация и завершение
bool DMAudio__Initialise(DMAudio* this);                        // 0x0041C350 (0x191 bytes)
void DMAudio__Service(DMAudio* this);                           // 0x0041C000 (0xC9 bytes)
void DMAudio__Reset(DMAudio* this);                             // 0x0041C200 (0x35 bytes)
void DMAudio__Resume(DMAudio* this);                            // 0x0041C150 (0x8D bytes)
void DMAudio__Pause(DMAudio* this);                             // 0x0041B7B0 (0x774 bytes)
void DMAudio__StopAllSounds(DMAudio* this);                     // 0x0041B0D0 (0x648 bytes)

// Управление буферами
void* DMAudio__CreateSoundBuffer(DMAudio* this, uint32_t size); // 0x0041A3C0 (0xB51 bytes)
void DMAudio__DestroySoundBuffer(DMAudio* this, void* buffer);  // 0x004181E0 (0x20B4 bytes)
bool DMAudio__LoadSoundBank(DMAudio* this, const char* path);   // 0x00417CE0 (0x9A bytes)
void DMAudio__UnloadSoundBank(DMAudio* this);                   // 0x00417DB0 (0xEE bytes)

// Воспроизведение
int DMAudio__PlayOneShot(DMAudio* this, uint32_t sound_id);     // 0x00417410 (0x8CC bytes)
int DMAudio__PlayLoop(DMAudio* this, uint32_t sound_id);        // 0x00417260 (0x1AC bytes)
void DMAudio__StopLoop(DMAudio* this, int channel_id);          // 0x004171A0 (0xB2 bytes)
void DMAudio__SetVolume(DMAudio* this, int channel_id, int volume); // 0x00417030 (0x16D bytes)
void DMAudio__SetPan(DMAudio* this, int channel_id, int pan);   // 0x00416F20 (0x106 bytes)
void DMAudio__SetFrequency(DMAudio* this, int channel_id, uint32_t freq); // 0x00416DA0 (0xA3 bytes)
int DMAudio__GetVolume(DMAudio* this, int channel_id);          // 0x00416C10 (0x11A bytes)
bool DMAudio__IsPlaying(DMAudio* this, int channel_id);         // 0x00416B20 (0x1D bytes)

// 3D Звук
void DMAudio__Set3DPosition(DMAudio* this, int channel_id, float x, float y, float z); // 0x004169E0 (0x13C bytes)
void DMAudio__Set3DListener(DMAudio* this, float x, float y, float z, float vx, float vy, float vz); // 0x004168E0 (0x5C bytes)
void DMAudio__Update3DListeners(DMAudio* this);                 // 0x00416890 (0x45 bytes)
void DMAudio__Calculate3DAttributes(DMAudio* this, int channel_id); // 0x004167C0 (0xBD bytes)

// Управление каналами
int DMAudio__GetFreeChannel(DMAudio* this);                     // 0x004166E0 (0x67 bytes)
int DMAudio__AllocateChannel(DMAudio* this);                    // 0x00416570 (0x69 bytes)
void DMAudio__ReleaseChannel(DMAudio* this, int channel_id);    // 0x004163A0 (0xB5 bytes)
void DMAudio__ResetChannel(DMAudio* this, int channel_id);      // 0x004162C0 (0xDD bytes)

// Обработка событий
void DMAudio__ProcessCollision(DMAudio* this, int type, float intensity); // 0x00415F90 (0x328 bytes)
void DMAudio__ProcessVehicleSound(DMAudio* this, int vehicle_id); // 0x00415EF0 (0x6C bytes)
void DMAudio__ProcessPedestrianSound(DMAudio* this, int ped_id); // 0x00415DF0 (0xA9 bytes)
void DMAudio__ProcessWeatherSound(DMAudio* this, int weather_type); // 0x00415D20 (0xC6 bytes)

// Утилиты
void* DMAudio__LockBuffer(DMAudio* this, void* buffer, uint32_t* size); // 0x00415CC0 (0x56 bytes)
void DMAudio__UnlockBuffer(DMAudio* this, void* buffer);        // 0x00415C70 (0x4D bytes)
void DMAudio__FillBufferWithSilence(DMAudio* this, void* buffer); // 0x00415C30 (0x35 bytes)
void DMAudio__CopyDataToBuffer(DMAudio* this, void* dest, const void* src, uint32_t size); // 0x00415BF0 (0x35 bytes)
bool DMAudio__CheckHardwareSupport(DMAudio* this);              // 0x00415BE0 (0xF bytes)

// Специфичные для GTA 2
void DMAudio__PlayMissionSpeech(DMAudio* this, int speech_id);  // 0x00415A90 (0x150 bytes)
void DMAudio__PlayRadioTrack(DMAudio* this, int station_id);    // 0x00415880 (0x205 bytes)
void DMAudio__StopRadioTrack(DMAudio* this);                    // 0x004156C0 (0x1BB bytes)
void DMAudio__SetRadioStation(DMAudio* this, int station_id);   // 0x00415520 (0x53 bytes)
void DMAudio__PlayAmbientSound(DMAudio* this, int ambient_id);  // 0x004150E0 (0x307 bytes)

// Дополнительные
void DMAudio__nullsub_5(DMAudio* this);                         // 0x00414FA0 (0xEB bytes)
void DMAudio__nullsub_6(DMAudio* this);                         // 0x00414E50 (0xCF bytes)
void DMAudio__DebugPrint(DMAudio* this, const char* format, ...); // 0x00414BC0 (0x25D bytes)
void DMAudio__LogError(DMAudio* this, int error_code);          // 0x004148D0 (0x2E8 bytes)
bool DMAudio__GetDriverInfo(DMAudio* this, void* info);         // 0x00414780 (0x145 bytes)
void DMAudio__SetBufferSize(DMAudio* this, uint32_t size);      // 0x004143B0 (0x3C8 bytes)
void DMAudio__SetSampleRate(DMAudio* this, uint32_t rate);      // 0x00414200 (0x1AA bytes)
void DMAudio__SetBitsPerSample(DMAudio* this, uint32_t bits);   // 0x00414030 (0x16B bytes)
void DMAudio__SetChannelsCount(DMAudio* this, uint32_t count);  // 0x00413EB0 (0x172 bytes)

#ifdef __cplusplus
}
#endif

#endif // DMAUDIO_H
