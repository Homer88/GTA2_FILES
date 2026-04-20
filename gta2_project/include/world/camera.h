#ifndef CAMERA_H
#define CAMERA_H

#include "../types.h"
#include "math_types/vector2d.h"
#include "forward_declarations.h"

/**
 * Режимы работы камеры
 */
typedef enum CameraMode {
    CAM_FREE = 0,           // Свободное перемещение
    CAM_FOLLOW_PED = 1,     // Слежение за пешеходом
    CAM_FOLLOW_CAR = 2,     // Слежение за машиной
    CAM_CINEMATIC = 3,      // Кинематографическая (по пути)
    CAM_FIXED = 4,          // Фиксированная позиция
    CAM_TOP_DOWN = 5        // Вид строго сверху (GTA 1 стиль)
} CameraMode;

/**
 * Структура камеры
 * Размер: ~96 байт
 */
typedef struct Camera {
    // Позиция и ориентация
    Vector2D Position;          // 0x0 - Текущая позиция камеры (центр экрана)
    Vector2D TargetPosition;    // 0x8 - Целевая позиция для плавного движения
    f32 Angle;                  // 0x10 - Угол поворота камеры (в радианах)
    f32 TargetAngle;            // 0x14 - Целевой угол
    f32 Zoom;                   // 0x18 - Уровень зума (1.0 = стандарт)
    f32 TargetZoom;             // 0x1C - Целевой зум
    
    // Режим и цели
    CameraMode Mode;            // 0x20 - Текущий режим
    struct Ped* FollowPed;      // 0x24 - Пешеход для слежения
    struct Car* FollowCar;      // 0x28 - Машина для слежения
    
    // Параметры плавности
    f32 SmoothFactor;           // 0x2C - Коэффициент сглаживания позиции (0.0-1.0)
    f32 AngleSmooth;            // 0x30 - Сглаживание поворота
    f32 ZoomSmooth;             // 0x34 - Сглаживание зума
    
    // Границы карты
    f32 MinX, MaxX;             // 0x38-0x3C - Ограничения по X
    f32 MinY, MaxY;             // 0x40-0x44 - Ограничения по Y
    
    // Эффекты
    f32 ShakeIntensity;         // 0x48 - Сила тряски
    f32 ShakeTimer;             // 0x4C - Таймер затухания тряски
    Vector2D ShakeOffset;       // 0x50 - Текущее смещение от тряски
    
    // Кинематографические пути
    void* CurrentPath;          // 0x58 - Указатель на текущий путь
    f32 PathProgress;           // 0x5C - Прогресс движения по пути (0.0-1.0)
    f32 PathSpeed;              // 0x60 - Скорость движения по пути
    
    // Флаги
    u32 Flags;                  // 0x64 - Флаги (битовая маска)
    u8 Padding[12];             // 0x68 - Выравнивание до 80 байт + резерв
    
} Camera; // Размер: ~80-96 байт

// Флаги камеры
#define CAM_FLAG_SHAKE          0x01
#define CAM_FLAG_BOUNDARIES     0x02
#define CAM_FLAG_SMOOTH         0x04
#define CAM_FLAG_ROTATABLE      0x08
#define CAM_FLAG_ZOOMABLE       0x10

/**
 * Инициализация камеры
 * @param cam Указатель на структуру камеры
 * @param width Ширина экрана
 * @param height Высота экрана
 */
void Camera_Init(Camera* cam);

/**
 * Обновление камеры (вызывать каждый кадр)
 * @param cam Указатель на структуру камеры
 * @param dt Время с последнего кадра (delta time)
 */
void Camera_Update(Camera* cam, f32 dt);

/**
 * Установка режима слежения за пешеходом
 * @param cam Указатель на камеру
 * @param ped Указатель на пешехода
 */
void Camera_FollowPed(Camera* cam, struct Ped* ped);

/**
 * Установка режима слежения за машиной
 * @param cam Указатель на камеру
 * @param car Указатель на машину
 */
void Camera_FollowCar(Camera* cam, struct Car* car);

/**
 * Установка свободной камеры
 * @param cam Указатель на камеру
 * @param x Начальная позиция X
 * @param y Начальная позиция Y
 */
void Camera_SetFree(Camera* cam, f32 x, f32 y);

/**
 * Принудительная установка позиции
 * @param cam Указатель на камеру
 * @param x Позиция X
 * @param y Позиция Y
 */
void Camera_SetPosition(Camera* cam, f32 x, f32 y);

/**
 * Поворот камеры
 * @param cam Указатель на камеру
 * @param angle Угол в радианах
 */
void Camera_SetAngle(Camera* cam, f32 angle);

/**
 * Установка зума
 * @param cam Указатель на камеру
 * @param zoom Коэффициент зума (0.5 = далеко, 2.0 = близко)
 */
void Camera_SetZoom(Camera* cam, f32 zoom);

/**
 * Запуск эффекта тряски
 * @param cam Указатель на камеру
 * @param intensity Сила тряски (0.0-10.0)
 * @param duration Длительность в секундах
 */
void Camera_Shake(Camera* cam, f32 intensity, f32 duration);

/**
 * Преобразование координат мира в экранные
 * @param cam Указатель на камеру
 * @param worldX Мировая координата X
 * @param worldY Мировая координата Y
 * @param outScreenX Выходная экранная X
 * @param outScreenY Выходная экранная Y
 * @return true если точка видима, false если за пределами экрана
 */
bool Camera_WorldToScreen(Camera* cam, f32 worldX, f32 worldY, 
                          f32* outScreenX, f32* outScreenY);

/**
 * Преобразование экранных координат в мировые
 * @param cam Указатель на камеру
 * @param screenX Экранная координата X
 * @param screenY Экранная координата Y
 * @param outWorldX Выходная мировая X
 * @param outWorldY Выходная мировая Y
 */
void Camera_ScreenToWorld(Camera* cam, f32 screenX, f32 screenY,
                          f32* outWorldX, f32* outWorldY);

/**
 * Установка границ карты
 * @param cam Указатель на камеру
 * @param minX Минимальный X
 * @param maxX Максимальный X
 * @param minY Минимальный Y
 * @param maxY Максимальный Y
 */
void Camera_SetBounds(Camera* cam, f32 minX, f32 maxX, f32 minY, f32 maxY);

#endif // CAMERA_H
