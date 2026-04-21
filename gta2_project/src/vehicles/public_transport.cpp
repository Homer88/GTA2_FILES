/**
 * @file public_transport.cpp
 * @brief C++ обёртки для PublicTransport (GTA2)
 * 
 * Использует структуры вместо классов.
 * old_name: sub_XXXXXX (соответствует адресам в IDA Pro)
 */

#include "../../include/entities/vehicle_types.h"

namespace GTA2 {
namespace Vehicles {

extern "C" {
    // Объявления C функций
    void PublicTransport_Init(PublicTransport* self, RouteNode* nodes, int count);
    void PublicTransport_Update(PublicTransport* self);
    void PublicTransport_SetRoute(PublicTransport* self, RouteNode* nodes, int count);
    void PublicTransport_StopAtNode(PublicTransport* self);
    int PublicTransport_GetNextNodeIndex(PublicTransport* self);
    void PublicTransport_Depart(PublicTransport* self);
}

// ============================================================================
// C++ WRAPPER FUNCTIONS
// ============================================================================

/**
 * @brief Инициализация PublicTransport (обёртка)
 * old_name: sub_4A1000
 */
void PublicTransport_Init_Wrapper(PublicTransport* pt, RouteNode* nodes, int count) {
    PublicTransport_Init(pt, nodes, count);
}

/**
 * @brief Обновление логики (обёртка)
 * old_name: sub_4A1150
 */
void PublicTransport_Update_Wrapper(PublicTransport* pt) {
    PublicTransport_Update(pt);
}

/**
 * @brief Установка маршрута (обёртка)
 * old_name: sub_4A1280
 */
void PublicTransport_SetRoute_Wrapper(PublicTransport* pt, RouteNode* nodes, int count) {
    PublicTransport_SetRoute(pt, nodes, count);
}

/**
 * @brief Остановка на узле (обёртка)
 * old_name: sub_4A1340
 */
void PublicTransport_StopAtNode_Wrapper(PublicTransport* pt) {
    PublicTransport_StopAtNode(pt);
}

/**
 * @brief Получение индекса следующего узла (обёртка)
 * old_name: sub_4A1450
 */
int PublicTransport_GetNextNodeIndex_Wrapper(PublicTransport* pt) {
    return PublicTransport_GetNextNodeIndex(pt);
}

/**
 * @brief Отправление (обёртка)
 * old_name: sub_4A1520
 */
void PublicTransport_Depart_Wrapper(PublicTransport* pt) {
    PublicTransport_Depart(pt);
}

} // namespace Vehicles
} // namespace GTA2
