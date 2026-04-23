#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief CameraManager (ранее структура S21)
 * 
 * Стек целых чисел размером 4004 байта.
 * Используется для управления списком объектов (возможно, камер или сущностей).
 * 
 * Адрес в памяти: определяется по MAP-файлу
 * Размер: 4004 байта
 */
typedef struct {
    int32_t field_0;              // Смещение 0x00: Начальное поле (возможно, счетчик или флаг)
    uint8_t gap1[3999];           // Смещение 0x04 - 0xF9B: Резерв/данные стека
    int32_t stack_pointer;        // Смещение 0xFA0: Указатель стека
} CameraManager;

// Проверка размера структуры
// static_assert(sizeof(CameraManager) == 4004, "Размер CameraManager должен быть 4004 байта");

/**
 * @brief Конструктор CameraManager
 * Инициализирует структуру, устанавливая указатель на самого себя (или в начальное состояние).
 * Адрес: 0x004C4B60 (предположительно)
 */
void CameraManager__Constructor(CameraManager* self);

/**
 * @brief Деструктор CameraManager
 * Освобождает ресурсы, если необходимо.
 * Адрес: 0x004C4DA0 (предположительно)
 */
void CameraManager__Destructor(CameraManager* self);

/**
 * @brief Добавить элемент в стек (Push)
 * @param value Значение для добавления
 * Адрес: 0x004C4B80
 */
void CameraManager__Push(CameraManager* self, int32_t value);

/**
 * @brief Извлечь элемент из стека (Pop)
 * @return Извлеченное значение
 * Адрес: 0x004C4BA0
 */
int32_t CameraManager__Pop(CameraManager* self);

/**
 * @brief Проверить, пуст ли стек
 * @return 1 если пуст, 0 иначе
 * Адрес: 0x004C4BC0
 */
int32_t CameraManager__IsEmpty(CameraManager* self);

// Глобальные переменные
extern CameraManager gCameraManager;      // Глобальный экземпляр (ранее gS21)
extern CameraManager* pCameraManager;     // Указатель на экземпляр

#ifdef __cplusplus
}
#endif

#endif // CAMERAMANAGER_H
