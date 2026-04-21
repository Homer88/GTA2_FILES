/**
 * @file train_component.cpp
 * @brief C++ обёртки для TrainComponent (GTA2)
 * 
 * Использует структуры вместо классов.
 * old_name: sub_XXXXXX (соответствует адресам в IDA Pro)
 */

#include "../../include/entities/vehicle_types.h"

namespace GTA2 {
namespace Vehicles {

extern "C" {
    // Объявления C функций
    void TrainComponent_Init(TrainComponent* self, int is_engine);
    void TrainComponent_Link(TrainComponent* self, TrainComponent* other);
    void TrainComponent_UpdateChain(TrainComponent* head);
    void TrainComponent_Unlink(TrainComponent* self);
    int TrainComponent_GetLength(TrainComponent* head);
}

// ============================================================================
// C++ WRAPPER FUNCTIONS
// ============================================================================

/**
 * @brief Инициализация TrainComponent (обёртка)
 * old_name: sub_4C2000
 */
void TrainComponent_Init_Wrapper(TrainComponent* tc, int is_engine) {
    TrainComponent_Init(tc, is_engine);
}

/**
 * @brief Сцепка компонентов (обёртка)
 * old_name: sub_4C2150
 */
void TrainComponent_Link_Wrapper(TrainComponent* tc, TrainComponent* other) {
    TrainComponent_Link(tc, other);
}

/**
 * @brief Обновление цепочки (обёртка)
 * old_name: sub_4C2280
 */
void TrainComponent_UpdateChain_Wrapper(TrainComponent* head) {
    TrainComponent_UpdateChain(head);
}

/**
 * @brief Расцепка (обёртка)
 * old_name: sub_4C2450
 */
void TrainComponent_Unlink_Wrapper(TrainComponent* tc) {
    TrainComponent_Unlink(tc);
}

/**
 * @brief Получение длины состава (обёртка)
 * old_name: sub_4C2520
 */
int TrainComponent_GetLength_Wrapper(TrainComponent* head) {
    return TrainComponent_GetLength(head);
}

} // namespace Vehicles
} // namespace GTA2
