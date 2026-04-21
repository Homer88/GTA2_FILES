/**
 * @file train_component.c
 * @brief Реализация компонентов поезда/трамвая (TrainComponent) GTA2
 * 
 * Адреса функций в IDA Pro указаны в комментариях "// old_name: sub_XXXXXX"
 * Переменные имеют комментарии со старыми именами "// old_var: old_name -> new_name"
 * 
 * Структура: TrainComponent (наследует BaseCar + сцепка)
 */

#include "../../include/entities/vehicle_types.h"
#include <string.h>

// ============================================================================
// ФУНКЦИИ TRAIN COMPONENT (бывший S83)
// ============================================================================

/**
 * @brief Инициализация компонента поезда
 * @param self Указатель на экземпляр TrainComponent
 * @param is_engine true если это локомотив, false если вагон
 * 
 * old_name: sub_4C2000
 * Адрес: 0x004C2000
 * old_var: this -> a1
 * old_var: is_engine -> a2
 */
void TrainComponent_Init(TrainComponent* self, int is_engine) {
    if (!self) return;
    
    // Инициализация базового класса
    BaseCar_Init(&self->base, VEHICLE_TRAIN);
    
    // Сброс связей
    self->next = 0;
    self->prev = 0;
    self->track_offset = 0.0f;
    self->train_id = 0;
}

/**
 * @brief Сцепка двух компонентов поезда
 * @param self Ведущий компонент (локомотив или предыдущий вагон)
 * @param other Ведомый компонент (следующий вагон)
 * 
 * old_name: sub_4C2150
 * Адрес: 0x004C2150
 * old_var: this -> a1
 * old_var: other -> a2
 * old_var: next -> LinkedCar
 * old_var: prev -> ParentCar
 */
void TrainComponent_Link(TrainComponent* self, TrainComponent* other) {
    if (!self || !other) return;
    
    // old_var: next -> LinkedCar
    self->next = other;
    
    // old_var: prev -> ParentCar
    other->prev = self;
    
    // Установка одинакового train_id
    other->train_id = self->train_id;
}

/**
 * @brief Обновление всей цепочки поезда
 * @param head Головной компонент (локомотив)
 * 
 * old_name: sub_4C2280
 * Адрес: 0x004C2280
 * old_var: head -> a1
 * old_var: track_offset -> RailPosition
 */
void TrainComponent_UpdateChain(TrainComponent* head) {
    if (!head) return;
    
    TrainComponent* current = head;
    TrainComponent* prev_car = 0;
    
    // Проход по всей цепочке
    while (current != 0) {
        // old_var: track_offset -> RailPosition
        
        // Если есть предыдущий вагон, корректируем позицию
        if (prev_car != 0) {
            // Вычисление расстояния между вагонами
            float dx = current->base.x - prev_car->base.x;
            float dy = current->base.y - prev_car->base.y;
            float distance = sqrtf(dx * dx + dy * dy);
            
            // Константа длины сцепки (условно 3.0 единицы)
            const float COUPLING_DISTANCE = 3.0f;
            
            // Корректировка позиции для поддержания дистанции
            if (distance > 0.0f) {
                float scale = (distance - COUPLING_DISTANCE) / distance;
                current->base.x -= dx * scale * 0.1f; // Плавная коррекция
                current->base.y -= dy * scale * 0.1f;
            }
            
            // Копирование направления от предыдущего вагона
            current->base.angle = prev_car->base.angle;
        }
        
        // Обновление физики базового класса
        BaseCar_UpdatePhysics(&current->base);
        
        // Переход к следующему вагону
        prev_car = current;
        current = current->next;
    }
}

/**
 * @brief Расцепка компонента поезда
 * @param self Компонент для расцепки
 * 
 * old_name: sub_4C2450
 * Адрес: 0x004C2450
 * old_var: this -> a1
 * old_var: next -> NextCar
 * old_var: prev -> PrevCar
 */
void TrainComponent_Unlink(TrainComponent* self) {
    if (!self) return;
    
    // old_var: next -> NextCar
    if (self->next != 0) {
        self->next->prev = 0;
    }
    
    // old_var: prev -> PrevCar
    if (self->prev != 0) {
        self->prev->next = 0;
    }
    
    // Очистка связей
    self->next = 0;
    self->prev = 0;
}

/**
 * @brief Получение длины состава поезда
 * @param head Головной компонент (локомотив)
 * @return Количество компонентов в составе
 * 
 * old_name: sub_4C2520
 * Адрес: 0x004C2520
 * old_var: head -> a1
 * old_var: count -> TrainLength
 */
int TrainComponent_GetLength(TrainComponent* head) {
    if (!head) return 0;
    
    int count = 0;
    TrainComponent* current = head;
    
    // old_var: count -> TrainLength
    while (current != 0) {
        count++;
        current = current->next;
    }
    
    return count;
}
