#ifndef RENDER_TYPES_H
#define RENDER_TYPES_H

#include "../types.h"

/**
 * Режимы рендеринга
 */
typedef enum RenderMode {
    RENDER_MODE_2D = 0,             // Плоский 2D (GTA 1)
    RENDER_MODE_ISOMETRIC = 1,      // Изометрия (GTA 2)
    RENDER_MODE_TOP_DOWN = 2        // Строго сверху
} RenderMode;

/**
 * Слои отрисовки (порядок важен!)
 */
typedef enum RenderLayer {
    LAYER_GROUND = 0,           // Земля, тайлы
    LAYER_WATER = 1,            // Водные поверхности
    LAYER_DECALS = 2,           // Декали (пятна, следы)
    LAYER_OBJECTS_LOW = 3,      // Низкие объекты (бордюры)
    LAYER_VEHICLES = 4,         // Машины
    LAYER_PEDS = 5,             // Пешеходы
    LAYER_OBJECTS_HIGH = 6,     // Высокие объекты (здания)
    LAYER_PARTICLES = 7,        // Частицы
    LAYER_UI = 8,               // Интерфейс
    LAYER_DEBUG = 9,            // Отладочная информация
    LAYER_COUNT = 10
} RenderLayer;

/**
 * Спрайт для отрисовки
 * Размер: ~32 байта
 */
typedef struct Sprite {
    void* TexturePtr;         // 0x0 - Указатель на текстуру/данные
    u16 Width;                // 0x4 - Ширина спрайта
    u16 Height;               // 0x6 - Высота спрайта
    u16 PivotX;               // 0x8 - Точка привязки X (центр)
    u16 PivotY;               // 0xA - Точка привязки Y (центр)
    f32 Rotation;             // 0xC - Угол поворота
    f32 ScaleX;               // 0x10 - Масштаб по X
    f32 ScaleY;               // 0x14 - Масштаб по Y
    u8 Red;                   // 0x18 - Цвет R (0-255)
    u8 Green;                 // 0x19 - Цвет G
    u8 Blue;                  // 0x1A - Цвет B
    u8 Alpha;                 // 0x1B - Прозрачность (0-255)
    u8 Flags;                 // 0x1C - Флаги спрайта
    u8 Layer;                 // 0x1D - Слой отрисовки
    u16 FrameIndex;           // 0x1E - Индекс кадра (для анимации)
} Sprite;

// Флаги спрайта
#define SPRITE_FLAG_FLIP_H    0x01    // Отразить по горизонтали
#define SPRITE_FLAG_FLIP_V    0x02    // Отразить по вертикали
#define SPRITE_FLAG_ADDITIVE  0x04    // Аддитивное смешивание
#define SPRITE_FLAG_ANIMATED  0x08    // Анимированный
#define SPRITE_FLAG_VISIBLE   0x10    // Видимый

/**
 * Камера для рендеринга (упрощенная версия)
 */
typedef struct RenderCamera {
    f32 X;                    // Позиция камеры X
    f32 Y;                    // Позиция камеры Y
    f32 Zoom;                 // Зум
    f32 Angle;                // Угол поворота
    s32 ViewportX;            // Начало области просмотра (экран)
    s32 ViewportY;
    s32 ViewportWidth;
    s32 ViewportHeight;
} RenderCamera;

/**
 * Прямоугольник отсечения (клиппинг)
 */
typedef struct ClipRect {
    s32 Left;
    s32 Top;
    s32 Right;
    s32 Bottom;
} ClipRect;

/**
 * Настройки рендеринга
 */
typedef struct RenderSettings {
    RenderMode Mode;              // Режим рендеринга
    u8 Fullscreen;                // Полноэкранный режим
    u8 VSync;                     // Вертикальная синхронизация
    u8 ShowDebug;                 // Показывать отладку
    u8 AntiAliasing;              // Сглаживание
    u16 ScreenWidth;              // Ширина экрана
    u16 ScreenHeight;             // Высота экрана
    f32 Brightness;               // Яркость (0.5-2.0)
    f32 Contrast;                 // Контрастность
} RenderSettings;

#endif // RENDER_TYPES_H
