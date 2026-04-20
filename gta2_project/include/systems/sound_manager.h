#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#include "core/types.h"

/**
 * Типы звуков в GTA 2
 */
typedef enum SoundType {
    SOUND_NONE = 0,
    SOUND_SFX = 1,              // Звуковой эффект (выстрел, взрыв)
    SOUND_MUSIC = 2,            // Музыка
    SOUND_VOICE = 3,            // Голосовая реплика
    SOUND_AMBIENT = 4,          // Фоновый звук (город, ветер)
    SOUND_VEHICLE = 5,          // Звук транспорта
    SOUND_UI = 6                // Звук интерфейса
} SoundType;

/**
 * Приоритеты звуков
 */
typedef enum SoundPriority {
    PRIORITY_LOW = 0,           // Фоновые звуки
    PRIORITY_NORMAL = 1,        // Обычные эффекты
    PRIORITY_HIGH = 2,          // Важные события
    PRIORITY_CRITICAL = 3       // Критичные (сирены, предупреждения)
} SoundPriority;

/**
 * Структура звука
 * Размер: ~64 байта
 */
typedef struct Sound {
    u32 Id;                     // 0x0 - Уникальный ID
    SoundType Type;             // 0x4 - Тип звука
    SoundPriority Priority;     // 0x8 - Приоритет
    
    void* DataPtr;              // 0xC - Указатель на данные звука
    u32 DataSize;               // 0x10 - Размер данных
    f32 Duration;               // 0x14 - Длительность в секундах
    
    // Позиция и параметры
    f32 PositionX;              // 0x18 - Позиция X в мире (для 3D звука)
    f32 PositionY;              // 0x1C - Позиция Y в мире
    f32 Volume;                 // 0x20 - Громкость (0.0-1.0)
    f32 Pitch;                  // 0x24 - Высота тона (0.5-2.0)
    f32 Pan;                    // 0x28 - Панорама (-1.0 левый, 1.0 правый)
    
    // Состояние воспроизведения
    u8 IsPlaying;               // 0x2C - Воспроизводится
    u8 IsLooping;               // 0x2D - Зациклен
    u8 IsPaused;                // 0x2E - На паузе
    u8 Padding1;                // 0x2F - Выравнивание
    
    f32 PlayPosition;           // 0x30 - Текущая позиция воспроизведения
    f32 FadeVolume;             // 0x34 - Целевая громкость для фейда
    f32 FadeTimer;              // 0x38 - Таймер фейда
    
    // 3D параметры
    f32 MinDistance;            // 0x3C - Минимальная дистанция слышимости
    f32 MaxDistance;            // 0x40 - Максимальная дистанция
    u8 Channel;                 // 0x44 - Аудиоканал
    u8 Padding2[3];             // Выравнивание
} Sound;

/**
 * Каналы аудио
 */
typedef enum AudioChannel {
    CHANNEL_MASTER = 0,
    CHANNEL_MUSIC = 1,
    CHANNEL_SFX = 2,
    CHANNEL_VOICE = 3,
    CHANNEL_AMBIENT = 4,
    CHANNEL_COUNT = 5
} AudioChannel;

/**
 * Менеджер звука
 * Размер: ~1 КБ + пулы
 */
typedef struct SoundManager {
    // Пул звуков
    Sound SoundPool[64];        // 0x0 - Пул активных звуков
    u8 ActiveCount;             // 0x1000 - Количество активных звуков
    u8 MaxSounds;               // 0x1001 - Максимум звуков
    u16 NextId;                 // 0x1002 - Следующий ID
    
    // Громкость каналов
    f32 ChannelVolumes[CHANNEL_COUNT]; // 0x1004 - Громкость по каналам
    f32 MasterVolume;           // 0x1018 - Общая громкость
    
    // Музыка
    Sound* CurrentMusic;        // 0x101C - Текущий музыкальный трек
    Sound* NextMusic;           // 0x1020 - Следующий трек (для кроссфейда)
    f32 MusicFadeTimer;         // 0x1024 - Таймер кроссфейда
    
    // Позиция слушателя (камера/игрок)
    f32 ListenerX;              // 0x1028 - Позиция слушателя X
    f32 ListenerY;              // 0x102C - Позиция слушателя Y
    f32 ListenerAngle;          // 0x1030 - Угол слушателя
    
    // Настройки
    u8 IsInitialized;           // 0x1034 - Инициализирован
    u8 IsMuted;                 // 0x1035 - Заглушен
    u8 Use3DSound;              // 0x1036 - Использовать 3D звук
    u8 Padding;                 // 0x1037 - Выравнивание
    
    // Статистика
    u32 SoundsPlayed;           // 0x1038 - Всего воспроизведено
    u32 SoundsCulled;           // 0x103C - Отсечено по приоритету
} SoundManager;

/**
 * Инициализация менеджера звука
 * @param manager Указатель на менеджер
 * @return true если успешно
 */
bool SoundManager_Init(SoundManager* manager);

/**
 * Очистка менеджера звука
 * @param manager Указатель на менеджер
 */
void SoundManager_Shutdown(SoundManager* manager);

/**
 * Обновление менеджера (каждый кадр)
 * @param manager Указатель на менеджер
 * @param dt Delta time
 */
void SoundManager_Update(SoundManager* manager, f32 dt);

/**
 * Воспроизведение звука
 * @param manager Указатель на менеджер
 * @param soundData Данные звука
 * @param type Тип звука
 * @param priority Приоритет
 * @param looping Зациклить
 * @return ID звука или -1
 */
s32 SoundManager_Play(SoundManager* manager, void* soundData, 
                      SoundType type, SoundPriority priority, bool looping);

/**
 * Воспроизведение 3D звука
 * @param manager Указатель на менеджер
 * @param soundData Данные звука
 * @param x Позиция X
 * @param y Позиция Y
 * @param priority Приоритет
 * @return ID звука или -1
 */
s32 SoundManager_Play3D(SoundManager* manager, void* soundData, 
                        f32 x, f32 y, SoundPriority priority);

/**
 * Остановка звука
 * @param manager Указатель на менеджер
 * @param soundId ID звука
 */
void SoundManager_Stop(SoundManager* manager, s32 soundId);

/**
 * Остановка всех звуков типа
 * @param manager Указатель на менеджер
 * @param type Тип звуков для остановки
 */
void SoundManager_StopAllOfType(SoundManager* manager, SoundType type);

/**
 * Установка громкости канала
 * @param manager Указатель на менеджер
 * @param channel Канал
 * @param volume Громкость (0.0-1.0)
 */
void SoundManager_SetChannelVolume(SoundManager* manager, 
                                   AudioChannel channel, f32 volume);

/**
 * Установка общей громкости
 * @param manager Указатель на менеджер
 * @param volume Громкость (0.0-1.0)
 */
void SoundManager_SetMasterVolume(SoundManager* manager, f32 volume);

/**
 * Включение/выключение звука
 * @param manager Указатель на менеджер
 * @param muted true для отключения звука
 */
void SoundManager_SetMuted(SoundManager* manager, bool muted);

/**
 * Обновление позиции слушателя
 * @param manager Указатель на менеджер
 * @param x Позиция X
 * @param y Позиция Y
 * @param angle Угол
 */
void SoundManager_UpdateListener(SoundManager* manager, 
                                 f32 x, f32 y, f32 angle);

/**
 * Загрузка звука из файла
 * @param manager Указатель на менеджер
 * @param filename Путь к файлу
 * @return Указатель на данные звука или NULL
 */
void* SoundManager_LoadSound(SoundManager* manager, const char* filename);

/**
 * Выгрузка звука
 * @param manager Указатель на менеджер
 * @param soundData Данные звука
 */
void SoundManager_UnloadSound(SoundManager* manager, void* soundData);

#endif // SOUND_MANAGER_H
