/**
 * @file public_transport.c
 * @brief Реализация логики общественного транспорта (PublicTransport) GTA2
 * 
 * Адреса функций в IDA Pro указаны в комментариях "// old_name: sub_XXXXXX"
 * Переменные имеют комментарии со старыми именами "// old_var: old_name -> new_name"
 * 
 * Структура: PublicTransport (0x7C байт) = BaseCar (0x68) + RouteData (0x14)
 */

#include "../../include/entities/vehicle_types.h"
#include <string.h>

// ============================================================================
// ФУНКЦИИ PUBLIC TRANSPORT (бывший S81)
// ============================================================================

/**
 * @brief Инициализация общественного транспорта
 * @param self Указатель на экземпляр PublicTransport
 * @param nodes Массив узлов маршрута
 * @param count Количество узлов
 * 
 * old_name: sub_4A1000
 * Адрес: 0x004A1000
 * old_var: this -> a1
 * old_var: nodes -> a2
 * old_var: count -> a3
 */
void PublicTransport_Init(PublicTransport* self, RouteNode* nodes, int count) {
    // old_var: ARR_S82 -> BaseCarArray
    // old_var: ARR_S83 -> TrainComponentArray
    
    if (!self) return;
    
    // Инициализация базового класса
    BaseCar_Init(&self->base, VEHICLE_PUBLIC_TRANSPORT);
    
    // Установка маршрута
    self->route_nodes = nodes;
    self->node_count = count;
    self->current_node = 0;
    
    // Сброс состояния
    self->state = PT_STATE_IDLE;
    self->wait_timer = 0;
    self->route_flags = ROUTE_FLAG_LOOP;
}

/**
 * @brief Обновление логики общественного транспорта (каждый кадр)
 * @param self Указатель на экземпляр PublicTransport
 * 
 * old_name: sub_4A1150
 * Адрес: 0x004A1150
 * old_var: this -> a1
 * old_var: state -> AI_State
 * old_var: wait_timer -> StopTimer
 */
void PublicTransport_Update(PublicTransport* self) {
    if (!self) return;
    
    // old_var: state -> AI_State
    switch (self->state) {
        case PT_STATE_IDLE:
            // Ожидание начала движения
            if (self->route_nodes && self->node_count > 0) {
                self->state = PT_STATE_MOVING_TO_STOP;
            }
            break;
            
        case PT_STATE_MOVING_TO_STOP:
            // Движение к следующей остановке
            if (self->current_node < self->node_count) {
                RouteNode* target = &self->route_nodes[self->current_node];
                
                // Вычисление направления к цели
                float dx = target->x - self->base.x;
                float dy = target->y - self->base.y;
                
                // Проверка достижения цели (дистанция < 1.0)
                if (dx * dx + dy * dy < 1.0f) {
                    self->state = PT_STATE_WAITING;
                    self->wait_timer = 180; // 3 секунды при 60 FPS
                }
            }
            break;
            
        case PT_STATE_WAITING:
            // Ожидание на остановке
            if (self->wait_timer > 0) {
                self->wait_timer--;
            } else {
                self->state = PT_STATE_DEPARTING;
            }
            break;
            
        case PT_STATE_DEPARTING:
            // Отправление от остановки
            self->current_node++;
            if (self->current_node >= self->node_count) {
                // Маршрут завершён
                if (self->route_flags & ROUTE_FLAG_LOOP) {
                    self->current_node = 0; // Зациклить
                } else {
                    self->state = PT_STATE_IDLE;
                }
            } else {
                self->state = PT_STATE_MOVING_TO_STOP;
            }
            break;
    }
    
    // Обновление физики базового класса
    BaseCar_UpdatePhysics(&self->base);
}

/**
 * @brief Установка нового маршрута
 * @param self Указатель на экземпляр PublicTransport
 * @param nodes Массив узлов маршрута
 * @param count Количество узлов
 * 
 * old_name: sub_4A1280
 * Адрес: 0x004A1280
 * old_var: this -> a1
 * old_var: nodes -> a2
 * old_var: count -> a3
 * old_var: route_nodes -> PathPoints
 */
void PublicTransport_SetRoute(PublicTransport* self, RouteNode* nodes, int count) {
    if (!self) return;
    
    // old_var: route_nodes -> PathPoints
    self->route_nodes = nodes;
    self->node_count = count;
    self->current_node = 0;
    self->state = PT_STATE_MOVING_TO_STOP;
}

/**
 * @brief Остановка на текущем узле маршрута
 * @param self Указатель на экземпляр PublicTransport
 * 
 * old_name: sub_4A1340
 * Адрес: 0x004A1340
 * old_var: this -> a1
 * old_var: wait_timer -> DoorOpenTime
 */
void PublicTransport_StopAtNode(PublicTransport* self) {
    if (!self) return;
    
    // old_var: wait_timer -> DoorOpenTime
    self->state = PT_STATE_WAITING;
    self->wait_timer = 300; // 5 секунд при 60 FPS
}

/**
 * @brief Получение индекса следующего узла маршрута
 * @param self Указатель на экземпляр PublicTransport
 * @return Индекс следующего узла
 * 
 * old_name: sub_4A1450
 * Адрес: 0x004A1450
 * old_var: this -> a1
 * old_var: current_node -> NextWaypoint
 */
int PublicTransport_GetNextNodeIndex(PublicTransport* self) {
    if (!self) return -1;
    
    // old_var: current_node -> NextWaypoint
    return self->current_node;
}

/**
 * @brief Отправление от остановки
 * @param self Указатель на экземпляр PublicTransport
 * 
 * old_name: sub_4A1520
 * Адрес: 0x004A1520
 * old_var: this -> a1
 * old_var: state -> DepartureFlag
 */
void PublicTransport_Depart(PublicTransport* self) {
    if (!self) return;
    
    // old_var: state -> DepartureFlag
    self->state = PT_STATE_DEPARTING;
    self->wait_timer = 0;
}
    }
