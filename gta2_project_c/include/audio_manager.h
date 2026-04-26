#ifndef AUDIO_MANAGER_H
#define AUDIO_MANAGER_H

#include "gta2_types.h"

#ifdef __cplusplus
extern "C" {
#endif

// Структура AudioManager (размер пока неизвестен точно, требуется анализ)
// Адрес экземпляра класса: требуется уточнение
typedef struct AudioManager {
    // Поля-заглушки (требуют анализа метода Initialize 0x413160)
    tUInt8  placeholder[4]; // Временное поле
} AudioManager;

// ============================================================================
// 1. Жизненный цикл и инициализация
// ============================================================================

// Деструктор
// Адрес: 0x0041F7A0, Размер: 1 байт
void AudioManager__Destroy(AudioManager* this);

// Инициализация DirectSound, загрузка банков
// Адрес: 0x00422160 (sub_413160), Размер: 0x38D байт
void AudioManager__Initialize(AudioManager* this);

// Загрузка звуковых банков с диска
// Адрес: 0x004224F0 (sub_4134F0), Размер: 0x4A6 байт
void AudioManager__LoadBanks(AudioManager* this);

// Очистка ресурсов
// Адрес: 0x004229A0 (sub_4139A0), Размер: 0x12C байт
void AudioManager__Shutdown(AudioManager* this);

// ============================================================================
// 2. Воспроизведение и управление звуками (SFX)
// ============================================================================

// Поиск свободного канала
// Адрес: 0x0041F7B0 (sub_4107B0), Размер: 0x4E байт
tInt32 AudioManager__GetFreeChannel(AudioManager* this);

// Основной метод воспроизведения
// Адрес: 0x004200D0 (sub_4110D0), Размер: 0x4F байт
void AudioManager__PlaySound(AudioManager* this, tInt32 soundId);

// Остановка звука по ID
// Адрес: 0x00420250 (sub_411250), Размер: 0x4D байт
void AudioManager__StopSound(AudioManager* this, tInt32 soundId);

// Пауза
// Адрес: 0x004202F0 (sub_4112F0), Размер: 0x1F байт
void AudioManager__PauseSound(AudioManager* this, tInt32 soundId);

// Обновление позиций 3D звуков
// Адрес: 0x00420330 (sub_411330), Размер: 0x27C байт
void AudioManager__Update3DSounds(AudioManager* this);

// Установка громкости
// Адрес: 0x004206B0 (sub_4116B0), Размер: 0x40 байт
void AudioManager__SetVolume(AudioManager* this, tInt32 volume);

// Установка панорамирования
// Адрес: 0x004206F0 (sub_4116F0), Размер: 0x34 байт
void AudioManager__SetPan(AudioManager* this, tInt32 pan);

// Изменение частоты/питча
// Адрес: 0x00420730 (sub_411730), Размер: 0x76 байт
void AudioManager__SetFrequency(AudioManager* this, tInt32 frequency);

// Обработка аудио элементов (дополнительные методы)
// Адрес: 0x00420A50 (sub_411A50), Размер: 0x29F байт
void AudioManager__ProcessAudioElement1(AudioManager* this);

// Адрес: 0x00420D20 (sub_411D20), Размер: 0x2D2 байт
void AudioManager__ProcessAudioElement2(AudioManager* this);

// ============================================================================
// 3. Параметры звука и микширование
// ============================================================================

// Адрес: 0x00421010 (sub_412010), Размер: 0x1D8 байт
void AudioManager__SetupSoundParams1(AudioManager* this);

// Адрес: 0x004211F0 (sub_4121F0), Размер: 0x1B1 байт
void AudioManager__SetupSoundParams2(AudioManager* this);

// Адрес: 0x004213C0 (sub_4123C0), Размер: 0x260 байт
void AudioManager__SetupSoundParams3(AudioManager* this);

// Адрес: 0x00421680 (sub_412680), Размер: 0x1AC байт
void AudioManager__SetupSoundParams4(AudioManager* this);

// Адрес: 0x00421830 (sub_412830), Размер: 0x1A0 байт
void AudioManager__SetupSoundParams5(AudioManager* this);

// Адрес: 0x004219D0 (sub_4129D0), Размер: 0x42 байт
void AudioManager__SetupSoundParams6(AudioManager* this);

// Адрес: 0x00421A20 (sub_412A20), Размер: 0x1AA байт
void AudioManager__SetupSoundParams7(AudioManager* this);

// Адрес: 0x00421BD0 (sub_412BD0), Размер: 0x1AC байт
void AudioManager__SetupSoundParams8(AudioManager* this);

// Адрес: 0x00421D80 (sub_412D80), Размер: 0x12B байт
void AudioManager__SetupSoundParams9(AudioManager* this);

// Адрес: 0x00421EB0 (sub_412EB0), Размер: 0x121 байт
void AudioManager__SetupSoundParams10(AudioManager* this);

// Адрес: 0x00421FE0 (sub_412FE0), Размер: 0xD3 байт
void AudioManager__SetupSoundParams11(AudioManager* this);

// Адрес: 0x004220D0 (sub_4130D0), Размер: 0x89 байт
void AudioManager__SetupSoundParams12(AudioManager* this);

// ============================================================================
// 4. Специфические звуки (Машины, Окружение)
// ============================================================================

// Расчет звука двигателя
// Адрес: 0x00422DF0 (ComputeSoundIndexForCar), Размер: 0x54 байт
tInt32 AudioManager__ComputeCarEngineSound(AudioManager* this, void* carPtr);

// Проверка специальной модели авто
// Адрес: 0x004C1510 (IsSpecialCarModel), Размер: 0x2A байт
tBool AudioManager__IsSpecialCarModel(AudioManager* this, tInt32 modelId);

// Проверка типа транспорта
// Адрес: 0x004C15A0 (IsTransportOrCargo), Размер: 0x26 байт
tBool AudioManager__IsTransportOrCargo(AudioManager* this, tInt32 modelId);

// Обновление всех звуков авто
// Адрес: 0x004233B0 (sub_4143B0), Размер: 0x3C8 байт
void AudioManager__UpdateVehicleSounds(AudioManager* this);

// Звуки столкновений
// Адрес: 0x004238D0 (sub_4148D0), Размер: 0x2E8 байт
void AudioManager__ProcessCollisionSounds(AudioManager* this);

// Дополнительные методы обработки
// Адрес: 0x00422BD0 (sub_413BD0), Размер: 0x161 байт
void AudioManager__ProcessEnvironment1(AudioManager* this);

// Адрес: 0x00422D40 (sub_413D40), Размер: 0xB0 байт
void AudioManager__ProcessEnvironment2(AudioManager* this);

// Адрес: 0x00422EB0 (sub_413EB0), Размер: 0x172 байт
void AudioManager__ProcessEnvironment3(AudioManager* this);

// Адрес: 0x00423030 (sub_414030), Размер: 0x16B байт
void AudioManager__ProcessEnvironment4(AudioManager* this);

// Адрес: 0x00423200 (sub_414200), Размер: 0x1AA байт
void AudioManager__ProcessEnvironment5(AudioManager* this);

// Адрес: 0x004246B0 (sub_4143B0_0), Размер: 5 байт
void AudioManager__Sub_4143B0_0(AudioManager* this);

// Адрес: 0x00423780 (sub_414780), Размер: 0x145 байт
void AudioManager__ProcessEnvironment6(AudioManager* this);

// Адрес: 0x00423BC0 (sub_414BC0), Размер: 0x25D байт
void AudioManager__ProcessEnvironment7(AudioManager* this);

// Адрес: 0x00423E50 (sub_414E50), Размер: 0xCF байт
void AudioManager__ProcessEnvironment8(AudioManager* this);

// Адрес: 0x00423FA0 (sub_414FA0), Размер: 0xEB байт
void AudioManager__ProcessEnvironment9(AudioManager* this);

// ============================================================================
// 5. Потоковое аудио и Музыка
// ============================================================================

// Обновление потоковой музыки
// Адрес: 0x004240E0 (sub_4150E0), Размер: 0x307 байт
void AudioManager__UpdateStreaming(AudioManager* this);

// Запуск музыкального трека
// Адрес: 0x00424880 (sub_415880), Размер: 0x205 байт
void AudioManager__StartTrack(AudioManager* this, tInt32 trackId);

// Остановка музыки
// Адрес: 0x00424A90 (sub_415A90), Размер: 0x150 байт
void AudioManager__StopTrack(AudioManager* this);

// Дополнительные методы потокового аудио
// Адрес: 0x00424520 (sub_415520), Размер: 0x53 байт
void AudioManager__StreamSub1(AudioManager* this);

// Адрес: 0x004246C0 (sub_4156C0), Размер: 0x1BB байт
void AudioManager__StreamSub2(AudioManager* this);

// Адрес: 0x00424BE0 (sub_415BE0), Размер: 0xF байт
void AudioManager__StreamSub3(AudioManager* this);

// Адрес: 0x00424BF0 (sub_415BF0), Размер: 0x35 байт
void AudioManager__StreamSub4(AudioManager* this);

// Адрес: 0x00424C30 (sub_415C30), Размер: 0x35 байт
void AudioManager__StreamSub5(AudioManager* this);

// Адрес: 0x00424C70 (sub_415C70), Размер: 0x4D байт
void AudioManager__StreamSub6(AudioManager* this);

// Адрес: 0x00424CC0 (sub_415CC0), Размер: 0x56 байт
void AudioManager__StreamSub7(AudioManager* this);

// Адрес: 0x00424D20 (sub_415D20), Размер: 0xC6 байт
void AudioManager__StreamSub8(AudioManager* this);

// Адрес: 0x00424DF0 (sub_415DF0), Размер: 0xA9 байт
void AudioManager__StreamSub9(AudioManager* this);

// Адрес: 0x00424EF0 (sub_415EF0), Размер: 0x6C байт
void AudioManager__StreamSub10(AudioManager* this);

// Адрес: 0x00424F90 (sub_415F90), Размер: 0x328 байт
void AudioManager__StreamSub11(AudioManager* this);

// ============================================================================
// 6. Внутренние утилиты и сброс
// ============================================================================

// Сброс элемента звука
// Адрес: 0x00425750 (ResetElement), Размер: 0x2D байт
void AudioManager__ResetElement(AudioManager* this, tInt32 elementId);

// Полный сброс состояния
// Адрес: 0x004C0D80 (ResetAudioState), Размер: 0x71 байт
void AudioManager__ResetAudioState(AudioManager* this);

// Пустая заглушка
// Адрес: 0x0042B0F0 (nullsub_4), Размер: 1 байт
void AudioManager__NullSub(AudioManager* this);

// Дополнительные методы сброса и утилит
// Адрес: 0x004252C0 (sub_4162C0), Размер: 0xDD байт
void AudioManager__Utility1(AudioManager* this);

// Адрес: 0x004253A0 (sub_4163A0), Размер: 0xB5 байт
void AudioManager__Utility2(AudioManager* this);

// Адрес: 0x00425570 (sub_416570), Размер: 0x69 байт
void AudioManager__Utility3(AudioManager* this);

// Адрес: 0x004256E0 (sub_4166E0), Размер: 0x67 байт
void AudioManager__Utility4(AudioManager* this);

// Адрес: 0x004257C0 (sub_4167C0), Размер: 0xBD байт
void AudioManager__Utility5(AudioManager* this);

// Адрес: 0x00425890 (sub_416890), Размер: 0x45 байт
void AudioManager__Utility6(AudioManager* this);

// Адрес: 0x004258E0 (sub_4168E0), Размер: 0x5C байт
void AudioManager__Utility7(AudioManager* this);

// Адрес: 0x004259A0 (sub_4169A0), Размер: 0x40 байт
void AudioManager__Utility8(AudioManager* this);

// Адрес: 0x004259E0 (sub_4169E0), Размер: 0x13C байт
void AudioManager__Utility9(AudioManager* this);

// Адрес: 0x00425B20 (sub_416B20), Размер: 0x1D байт
void AudioManager__Utility10(AudioManager* this);

// Адрес: 0x00425C10 (sub_416C10), Размер: 0x11A байт
void AudioManager__Utility11(AudioManager* this);

// Адрес: 0x00425DA0 (sub_416DA0), Размер: 0xA3 байт
void AudioManager__Utility12(AudioManager* this);

// Адрес: 0x00425F20 (sub_416F20), Размер: 0x106 байт
void AudioManager__Utility13(AudioManager* this);

// Адрес: 0x00426030 (sub_417030), Размер: 0x16D байт
void AudioManager__Utility14(AudioManager* this);

// Адрес: 0x004261A0 (sub_4171A0), Размер: 0xB2 байт
void AudioManager__Utility15(AudioManager* this);

// Адрес: 0x00426260 (sub_417260), Размер: 0x1AC байт
void AudioManager__Utility16(AudioManager* this);

// ============================================================================
// 7. Огромные методы обработки (Complex Logic)
// ============================================================================

// Микширование каналов
// Адрес: 0x00426410 (sub_417410), Размер: 0x8CC байт
void AudioManager__MixChannels(AudioManager* this);

// Главный цикл обновления аудио - самый сложный метод
// Адрес: 0x004271E0 (sub_4181E0), Размер: 0x20B4 байт
void AudioManager__MainUpdateLoop(AudioManager* this);

// Загрузка данных звука в память
// Адрес: 0x0042A0D0 (sub_41B0D0), Размер: 0x648 байт
void AudioManager__LoadSoundData(AudioManager* this);

// Дополнительные большие методы
// Адрес: 0x00426CE0 (sub_417CE0), Размер: 0x9A байт
void AudioManager__ComplexSub1(AudioManager* this);

// Адрес: 0x00426DB0 (sub_417DB0), Размер: 0xEE байт
void AudioManager__ComplexSub2(AudioManager* this);

// Адрес: 0x00427100 (sub_418100), Размер: 0xB1 байт
void AudioManager__ComplexSub3(AudioManager* this);

// Адрес: 0x004293C0 (sub_41A3C0), Размер: 0xB51 байт
void AudioManager__ComplexSub4(AudioManager* this);

// Адрес: 0x0042A030 (sub_41B030), Размер: 0x2D байт
void AudioManager__ComplexSub5(AudioManager* this);

// Адрес: 0x0042A7B0 (sub_41B7B0), Размер: 0x774 байт
void AudioManager__ComplexSub6(AudioManager* this);

// Адрес: 0x0042AF60 (sub_41BF60), Размер: 0x25 байт
void AudioManager__ComplexSub7(AudioManager* this);

// Адрес: 0x0042AF90 (sub_41BF90), Размер: 0x6A байт
void AudioManager__ComplexSub8(AudioManager* this);

// Адрес: 0x0042B000 (sub_41C000), Размер: 0xC9 байт
void AudioManager__ComplexSub9(AudioManager* this);

// Адрес: 0x0042B0D0 (sub_41C0D0), Размер: 0x1A байт
void AudioManager__ComplexSub10(AudioManager* this);

// Адрес: 0x0042B150 (sub_41C150), Размер: 0x8D байт
void AudioManager__ComplexSub11(AudioManager* this);

// Адрес: 0x0042B200 (sub_41C200), Размер: 0x35 байт
void AudioManager__ComplexSub12(AudioManager* this);

// Адрес: 0x0042B240 (sub_41C240), Размер: 0x104 байт
void AudioManager__ComplexSub13(AudioManager* this);

// Адрес: 0x0042B350 (sub_41C350), Размер: 0x191 байт
void AudioManager__ComplexSub14(AudioManager* this);

// Адрес: 0x0042B5A0 (sub_41C5A0), Размер: 0x60 байт
void AudioManager__ComplexSub15(AudioManager* this);

// Адрес: 0x0042B600 (sub_41C600), Размер: 0x634 байт
void AudioManager__ComplexSub16(AudioManager* this);

// Адрес: 0x0042BCA0 (sub_41CCA0), Размер: 0x2B8 байт
void AudioManager__ComplexSub17(AudioManager* this);

// ============================================================================
// 8. Методы в конце адреса (0x4Bxxxx / 0x4Cxxxx)
// ============================================================================

// Адрес: 0x004C0D40 (sub_4B1D40), Размер: 0x3D байт
void AudioManager__FinalSub1(AudioManager* this);

// Адрес: 0x004C0E00 (sub_4B1E00), Размер: 0x3B байт
void AudioManager__FinalSub2(AudioManager* this);

// Адрес: 0x004C0E40 (sub_4B1E40), Размер: 0x332 байт
void AudioManager__FinalSub3(AudioManager* this);

// Адрес: 0x004C1180 (sub_4B2180), Размер: 0x126 байт
void AudioManager__FinalSub4(AudioManager* this);

// Адрес: 0x004C1350 (sub_4B2350), Размер: 0xC6 байт
void AudioManager__FinalSub5(AudioManager* this);

// Адрес: 0x004C1420 (sub_4B2420), Размер: 0xE9 байт
void AudioManager__FinalSub6(AudioManager* this);

// Адрес: 0x004C15D0 (sub_4B25D0), Размер: 0x253 байт
void AudioManager__FinalSub7(AudioManager* this);

// Адрес: 0x004C1830 (sub_4B2830), Размер: 0x21D байт
void AudioManager__FinalSub8(AudioManager* this);

// Адрес: 0x004C1AD0 (sub_4B2AD0), Размер: 0xEE байт
void AudioManager__FinalSub9(AudioManager* this);

// Адрес: 0x004C1BC0 (sub_4B2BC0), Размер: 0x107 байт
void AudioManager__FinalSub10(AudioManager* this);

// Адрес: 0x004C1D50 (sub_4B2D50), Размер: 0x1CC байт
void AudioManager__FinalSub11(AudioManager* this);

#ifdef __cplusplus
}
#endif

#endif // AUDIO_MANAGER_H
