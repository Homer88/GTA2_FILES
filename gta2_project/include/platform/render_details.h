/**
 * @file render_details.h
 * @brief Детальные структуры рендеринга (спрайты, палитры, шрифты, свет).
 * 
 * Эти структуры описывают низкоуровневые данные для отрисовки.
 * В оригинале они часто лежат в архивах (.gci, .spr) или в сегменте данных.
 */

#ifndef RENDER_DETAILS_H
#define RENDER_DETAILS_H

#include "types.h"
#include "math_types/vector2d.h"

#pragma pack(push, 1)

/**
 * @brief Заголовок спрайта.
 * Оригинал IDA: `struct SpriteHeader` / `SPRITE_HEAD`
 * Размер: 16-32 байта (зависит от версии)
 */
typedef struct SpriteHeader {
    u16 Width;          // 0x00: Ширина изображения
    u16 Height;         // 0x02: Высота изображения
    s16 HotspotX;       // 0x04: Смещение точки привязки по X (центр машины/педа)
    s16 HotspotY;       // 0x06: Смещение точки привязки по Y
    u32 DataOffset;     // 0x08: Смещение к данным пикселей в файле
    u32 PaletteOffset;  // 0x0C: Смещение к палитре (если есть)
    u8  Flags;          // 0x10: Флаги (прозрачность, сжатие)
    u8  MipmapCount;    // 0x11: Количество уровней детализации
    u16 Reserved;       // 0x12: Резерв
} SpriteHeader;

/**
 * @brief Кадр анимации спрайта.
 * Оригинал IDA: `struct SpriteFrame`
 */
typedef struct SpriteFrame {
    u16 FrameIndex;     // 0x00: Индекс кадра в последовательности
    u16 Duration;       // 0x02: Длительность кадра (в тиках)
    s16 OffsetX;        // 0x04: Смещение относительно центра
    s16 OffsetY;        // 0x06: Смещение по Y
} SpriteFrame;

/**
 * @brief Палитра цветов (RGB + Alpha).
 * Оригинал IDA: `struct Palette` / `DAT_Palette`
 * Размер: 1024 байта (256 * 4)
 */
typedef struct Palette {
    u8 R;               // 0x00: Красный
    u8 G;               // 0x01: Зеленый
    u8 B;               // 0x02: Синий
    u8 A;               // 0x03: Альфа (часто 0 или 255)
} PaletteEntry;

typedef struct Palette {
    PaletteEntry Colors[256]; // Массив из 256 цветов
    u32 Version;              // Версия палитры
    bool IsDirty;             // Флаг изменения (нужно обновить текстуру)
} Palette;

/**
 * @brief Данные символа шрифта.
 * Оригинал IDA: `struct FontChar` / `FNT_CHAR`
 */
typedef struct FontChar {
    u8 CharCode;        // 0x00: ASCII код символа
    u8 Width;           // 0x01: Ширина символа в пикселях
    u16 UVX;            // 0x02: Координата U в текстуре шрифта
    u16 UVY;            // 0x04: Координата V в текстуре
    u16 UVW;            // 0x06: Ширина в текстуре
    u16 UVH;            // 0x08: Высота в текстуре
} FontChar;

/**
 * @brief Динамический источник света.
 * Оригинал IDA: `struct Light` / `LIGHT_SRC`
 * Используется для фар машин, фонарей, взрывов.
 */
typedef struct LightSource {
    Vector3D Position;      // 0x00: Позиция в мире
    f32 Radius;             // 0x0C: Радиус освещения
    u8 Red;                 // 0x10: Цвет R (0-255)
    u8 Green;               // 0x11: Цвет G
    u8 Blue;                // 0x12: Цвет B
    u8 Intensity;           // 0x13: Интенсивность (0-255)
    u8 Type;                // 0x14: Тип (Point, Spot, Directional)
    u8 Enabled;             // 0x15: Активен ли свет
    u16 Reserved;           // 0x16: Выравнивание
} LightSource;

/**
 * @brief Пакет отрисовки (Batch).
 * Оригинал IDA: `struct RenderBatch`
 * Группирует спрайты для минимизации переключений текстур.
 */
typedef struct RenderBatch {
    void* TexturePtr;       // 0x00: Указатель на текстуру
    u32 Count;              // 0x04: Количество элементов в пакете
    u32 MaxCount;           // 0x08: Максимальная емкость
    void* VertexBuffer;     // 0x0C: Буфер вершин (x, y, u, v, color)
} RenderBatch;

#pragma pack(pop)

#endif // RENDER_DETAILS_H
