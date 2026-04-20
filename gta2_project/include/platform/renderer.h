#ifndef RENDERER_H
#define RENDERER_H

#include "../types.h"
#include "render_types.h"
#include "camera.h"
#include "forward_declarations.h"

#define MAX_SPRITES_PER_FRAME 2048
#define MAX_BATCH_SIZE 512

/**
 * Структура рендерера
 * Размер: ~256 байт + буферы
 */
typedef struct Renderer {
    // Настройки
    RenderSettings Settings;          // 0x0 - Настройки рендеринга
    
    // Камера
    RenderCamera Camera;              // 0x20 - Камера рендеринга
    
    // Буферы
    void* SpriteBuffer;               // 0x50 - Буфер спрайтов
    u32 SpriteCount;                  // 0x54 - Количество спрайтов в кадре
    u32 MaxSprites;                   // 0x58 - Максимум спрайтов
    
    void* BatchBuffer;                // 0x5C - Буфер пакетной отрисовки
    u32 BatchSize;                    // 0x60 - Текущий размер пакета
    
    // Состояние
    u8 IsInitialized;                 // 0x64 - Инициализирован
    u8 IsRendering;                   // 0x65 - Сейчас рендерит
    u8 FrameCount;                    // 0x66 - Счетчик кадров
    u8 Padding1;                      // 0x67 - Выравнивание
    
    f32 FrameTime;                    // 0x68 - Время кадра (ms)
    u32 TotalDrawCalls;               // 0x6C - Всего вызовов отрисовки
    
    // Клиппинг
    ClipRect ClipRect;                // 0x70 - Прямоугольник отсечения
    
    // Палитра/цвета
    u32 Palette[256];                 // 0x80 - Цветовая палитра (для 8-бит)
    
    // Указатели на устройства (зависят от бэкенда)
    void* Device;                     // 0x480 - Графическое устройство
    void* Context;                    // 0x484 - Контекст рендеринга
    void* Window;                     // 0x488 - Окно
    
    // Статистика
    u32 FramesRendered;               // 0x48C - Отрисовано кадров
    u32 SpritesDrawn;                 // 0x490 - Отрисовано спрайтов
    f32 FPS;                          // 0x494 - Кадров в секунду
} Renderer;

/**
 * Инициализация рендерера
 * @param renderer Указатель на рендерер
 * @param width Ширина окна
 * @param height Высота окна
 * @param fullscreen Полноэкранный режим
 * @return true если успешно
 */
bool Renderer_Init(Renderer* renderer, u16 width, u16 height, bool fullscreen);

/**
 * Очистка рендерера
 * @param renderer Указатель на рендерер
 */
void Renderer_Shutdown(Renderer* renderer);

/**
 * Начало кадра
 * @param renderer Указатель на рендерер
 * @param clearColor Цвет очистки (RGBA)
 */
void Renderer_BeginFrame(Renderer* renderer, u32 clearColor);

/**
 * Конец кадра
 * @param renderer Указатель на рендерер
 */
void Renderer_EndFrame(Renderer* renderer);

/**
 * Установка камеры
 * @param renderer Указатель на рендерер
 * @param camera Указатель на камеру
 */
void Renderer_SetCamera(Renderer* renderer, Camera* camera);

/**
 * Отрисовка спрайта
 * @param renderer Указатель на рендерер
 * @param sprite Указатель на спрайт
 * @param x Позиция X в мире
 * @param y Позиция Y в мире
 */
void Renderer_DrawSprite(Renderer* renderer, Sprite* sprite, f32 x, f32 y);

/**
 * Отрисовка тайла карты
 * @param renderer Указатель на рендерер
 * @param tileIndex Индекс тайла
 * @param x Позиция X
 * @param y Позиция Y
 * @param layer Слой
 */
void Renderer_DrawTile(Renderer* renderer, u16 tileIndex, f32 x, f32 y, u8 layer);

/**
 * Отрисовка прямоугольника (для UI и отладки)
 * @param renderer Указатель на рендерер
 * @param x Позиция X
 * @param y Позиция Y
 * @param width Ширина
 * @param height Высота
 * @param color Цвет (RGBA)
 */
void Renderer_DrawRect(Renderer* renderer, f32 x, f32 y, 
                       f32 width, f32 height, u32 color);

/**
 * Отрисовка линии (для отладки)
 * @param renderer Указатель на рендерер
 * @param x1 Начальная X
 * @param y1 Начальная Y
 * @param x2 Конечная X
 * @param y2 Конечная Y
 * @param color Цвет
 */
void Renderer_DrawLine(Renderer* renderer, f32 x1, f32 y1, 
                       f32 x2, f32 y2, u32 color);

/**
 * Отрисовка текста
 * @param renderer Указатель на рендерер
 * @param text Текст
 * @param x Позиция X
 * @param y Позиция Y
 * @param color Цвет
 * @param scale Масштаб шрифта
 */
void Renderer_DrawText(Renderer* renderer, const char* text, 
                       f32 x, f32 y, u32 color, f32 scale);

/**
 * Преобразование мировых координат в экранные
 * @param renderer Указатель на рендерер
 * @param worldX Мировая X
 * @param worldY Мировая Y
 * @param outScreenX Выходная экранная X
 * @param outScreenY Выходная экранная Y
 * @return true если точка видима
 */
bool Renderer_WorldToScreen(Renderer* renderer, f32 worldX, f32 worldY,
                            f32* outScreenX, f32* outScreenY);

/**
 * Проверка видимости точки
 * @param renderer Указатель на рендерер
 * @param x Мировая X
 * @param y Мировая Y
 * @return true если точка в пределах экрана
 */
bool Renderer_IsVisible(Renderer* renderer, f32 x, f32 y);

/**
 * Установка цвета очистки
 * @param renderer Указатель на рендерер
 * @param r Красный (0-255)
 * @param g Зеленый (0-255)
 * @param b Синий (0-255)
 * @param a Альфа (0-255)
 */
void Renderer_SetClearColor(Renderer* renderer, u8 r, u8 g, u8 b, u8 a);

/**
 * Получение статистики рендеринга
 * @param renderer Указатель на рендерер
 * @return Строка со статистикой
 */
const char* Renderer_GetStats(Renderer* renderer);

#endif // RENDERER_H
