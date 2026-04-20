#include "camera.h"
#include "systems/vector2d.h"
#include <math.h>
#include <string.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif

// Вспомогательная функция линейной интерполяции
static f32 Lerp(f32 a, f32 b, f32 t) {
    if (t < 0.0f) t = 0.0f;
    if (t > 1.0f) t = 1.0f;
    return a + (b - a) * t;
}

// Инициализация камеры
void Camera_Init(Camera* cam) {
    if (!cam) return;
    
    memset(cam, 0, sizeof(Camera));
    
    cam->Position.x = 0.0f;
    cam->Position.y = 0.0f;
    cam->TargetPosition.x = 0.0f;
    cam->TargetPosition.y = 0.0f;
    cam->Angle = 0.0f;
    cam->TargetAngle = 0.0f;
    cam->Zoom = 1.0f;
    cam->TargetZoom = 1.0f;
    cam->Mode = CAM_FREE;
    cam->FollowPed = NULL;
    cam->FollowCar = NULL;
    cam->SmoothFactor = 0.1f;
    cam->AngleSmooth = 0.1f;
    cam->ZoomSmooth = 0.1f;
    cam->MinX = -1000.0f;
    cam->MaxX = 1000.0f;
    cam->MinY = -1000.0f;
    cam->MaxY = 1000.0f;
    cam->ShakeIntensity = 0.0f;
    cam->ShakeTimer = 0.0f;
    cam->ShakeOffset.x = 0.0f;
    cam->ShakeOffset.y = 0.0f;
    cam->CurrentPath = NULL;
    cam->PathProgress = 0.0f;
    cam->PathSpeed = 1.0f;
    cam->Flags = CAM_FLAG_BOUNDARIES | CAM_FLAG_SMOOTH | CAM_FLAG_ROTATABLE | CAM_FLAG_ZOOMABLE;
}

// Обновление камеры
void Camera_Update(Camera* cam, f32 dt) {
    if (!cam) return;
    
    // 1. Обновление целевой позиции в зависимости от режима
    switch (cam->Mode) {
        case CAM_FOLLOW_PED:
            if (cam->FollowPed) {
                // Здесь должно быть получение позиции из Ped
                // Для заглушки используем текущую цель
                cam->TargetPosition.x = cam->FollowPed->PositionX;
                cam->TargetPosition.y = cam->FollowPed->PositionY;
            }
            break;
            
        case CAM_FOLLOW_CAR:
            if (cam->FollowCar) {
                // Получение позиции из Car
                cam->TargetPosition.x = cam->FollowCar->PositionX;
                cam->TargetPosition.y = cam->FollowCar->PositionY;
                
                // Небольшое смещение вперед по направлению машины
                f32 angle = cam->FollowCar->Rotation;
                f32 offset = 50.0f / cam->Zoom;
                cam->TargetPosition.x += cosf(angle) * offset;
                cam->TargetPosition.y += sinf(angle) * offset;
            }
            break;
            
        case CAM_CINEMATIC:
            if (cam->CurrentPath) {
                // Движение по пути (заглушка)
                cam->PathProgress += dt * cam->PathSpeed;
                if (cam->PathProgress > 1.0f) {
                    cam->PathProgress = 0.0f;
                }
                // Здесь должен быть расчет позиции по пути
            }
            break;
            
        default:
            // CAM_FREE, CAM_FIXED, CAM_TOP_DOWN - позиция не меняется автоматически
            break;
    }
    
    // 2. Плавное движение к целевой позиции
    if (cam->Flags & CAM_FLAG_SMOOTH) {
        cam->Position.x = Lerp(cam->Position.x, cam->TargetPosition.x, cam->SmoothFactor);
        cam->Position.y = Lerp(cam->Position.y, cam->TargetPosition.y, cam->SmoothFactor);
        cam->Angle = Lerp(cam->Angle, cam->TargetAngle, cam->AngleSmooth);
        cam->Zoom = Lerp(cam->Zoom, cam->TargetZoom, cam->ZoomSmooth);
    } else {
        cam->Position.x = cam->TargetPosition.x;
        cam->Position.y = cam->TargetPosition.y;
        cam->Angle = cam->TargetAngle;
        cam->Zoom = cam->TargetZoom;
    }
    
    // 3. Ограничение границами карты
    if (cam->Flags & CAM_FLAG_BOUNDARIES) {
        if (cam->Position.x < cam->MinX) cam->Position.x = cam->MinX;
        if (cam->Position.x > cam->MaxX) cam->Position.x = cam->MaxX;
        if (cam->Position.y < cam->MinY) cam->Position.y = cam->MinY;
        if (cam->Position.y > cam->MaxY) cam->Position.y = cam->MaxY;
    }
    
    // 4. Обновление тряски
    if (cam->ShakeTimer > 0.0f) {
        cam->ShakeTimer -= dt;
        if (cam->ShakeTimer <= 0.0f) {
            cam->ShakeTimer = 0.0f;
            cam->ShakeIntensity = 0.0f;
            cam->ShakeOffset.x = 0.0f;
            cam->ShakeOffset.y = 0.0f;
        } else {
            // Случайное смещение
            f32 intensity = cam->ShakeIntensity * (cam->ShakeTimer / 1.0f);
            cam->ShakeOffset.x = ((f32)rand() / RAND_MAX - 0.5f) * 2.0f * intensity;
            cam->ShakeOffset.y = ((f32)rand() / RAND_MAX - 0.5f) * 2.0f * intensity;
        }
    }
    
    // Применение тряски к позиции
    cam->Position.x += cam->ShakeOffset.x;
    cam->Position.y += cam->ShakeOffset.y;
}

// Установка слежения за пешеходом
void Camera_FollowPed(Camera* cam, struct Ped* ped) {
    if (!cam) return;
    cam->Mode = CAM_FOLLOW_PED;
    cam->FollowPed = ped;
    cam->FollowCar = NULL;
    if (ped) {
        cam->TargetPosition.x = ped->PositionX;
        cam->TargetPosition.y = ped->PositionY;
    }
}

// Установка слежения за машиной
void Camera_FollowCar(Camera* cam, struct Car* car) {
    if (!cam) return;
    cam->Mode = CAM_FOLLOW_CAR;
    cam->FollowCar = car;
    cam->FollowPed = NULL;
    if (car) {
        cam->TargetPosition.x = car->PositionX;
        cam->TargetPosition.y = car->PositionY;
    }
}

// Установка свободной камеры
void Camera_SetFree(Camera* cam, f32 x, f32 y) {
    if (!cam) return;
    cam->Mode = CAM_FREE;
    cam->FollowPed = NULL;
    cam->FollowCar = NULL;
    cam->TargetPosition.x = x;
    cam->TargetPosition.y = y;
    cam->Position.x = x;
    cam->Position.y = y;
}

// Принудительная установка позиции
void Camera_SetPosition(Camera* cam, f32 x, f32 y) {
    if (!cam) return;
    cam->TargetPosition.x = x;
    cam->TargetPosition.y = y;
    if (!(cam->Flags & CAM_FLAG_SMOOTH)) {
        cam->Position.x = x;
        cam->Position.y = y;
    }
}

// Поворот камеры
void Camera_SetAngle(Camera* cam, f32 angle) {
    if (!cam) return;
    // Нормализация угла к диапазону [0, 2π)
    while (angle < 0.0f) angle += 2.0f * M_PI;
    while (angle >= 2.0f * M_PI) angle -= 2.0f * M_PI;
    cam->TargetAngle = angle;
    if (!(cam->Flags & CAM_FLAG_SMOOTH)) {
        cam->Angle = angle;
    }
}

// Установка зума
void Camera_SetZoom(Camera* cam, f32 zoom) {
    if (!cam) return;
    if (zoom < 0.2f) zoom = 0.2f;
    if (zoom > 5.0f) zoom = 5.0f;
    cam->TargetZoom = zoom;
    if (!(cam->Flags & CAM_FLAG_SMOOTH)) {
        cam->Zoom = zoom;
    }
}

// Запуск тряски
void Camera_Shake(Camera* cam, f32 intensity, f32 duration) {
    if (!cam) return;
    cam->ShakeIntensity = intensity;
    cam->ShakeTimer = duration;
}

// Преобразование мировых координат в экранные
bool Camera_WorldToScreen(Camera* cam, f32 worldX, f32 worldY,
                          f32* outScreenX, f32* outScreenY) {
    if (!cam || !outScreenX || !outScreenY) return false;
    
    // Смещение относительно камеры
    f32 dx = worldX - cam->Position.x;
    f32 dy = worldY - cam->Position.y;
    
    // Поворот
    f32 cosA = cosf(-cam->Angle);
    f32 sinA = sinf(-cam->Angle);
    f32 rx = dx * cosA - dy * sinA;
    f32 ry = dx * sinA + dy * cosA;
    
    // Масштабирование и центрирование
    // Предполагаем экран 800x600 для примера
    f32 screenWidth = 800.0f;
    f32 screenHeight = 600.0f;
    
    *outScreenX = screenWidth / 2.0f + rx * cam->Zoom;
    *outScreenY = screenHeight / 2.0f - ry * cam->Zoom;
    
    // Проверка видимости
    bool visible = (*outScreenX >= 0 && *outScreenX <= screenWidth &&
                    *outScreenY >= 0 && *outScreenY <= screenHeight);
    
    return visible;
}

// Преобразование экранных координат в мировые
void Camera_ScreenToWorld(Camera* cam, f32 screenX, f32 screenY,
                          f32* outWorldX, f32* outWorldY) {
    if (!cam || !outWorldX || !outWorldY) return;
    
    f32 screenWidth = 800.0f;
    f32 screenHeight = 600.0f;
    
    // Обратное преобразование
    f32 rx = (screenX - screenWidth / 2.0f) / cam->Zoom;
    f32 ry = -(screenY - screenHeight / 2.0f) / cam->Zoom;
    
    // Обратный поворот
    f32 cosA = cosf(cam->Angle);
    f32 sinA = sinf(cam->Angle);
    f32 dx = rx * cosA - ry * sinA;
    f32 dy = rx * sinA + ry * cosA;
    
    *outWorldX = cam->Position.x + dx;
    *outWorldY = cam->Position.y + dy;
}

// Установка границ карты
void Camera_SetBounds(Camera* cam, f32 minX, f32 maxX, f32 minY, f32 maxY) {
    if (!cam) return;
    cam->MinX = minX;
    cam->MaxX = maxX;
    cam->MinY = minY;
    cam->MaxY = maxY;
}
