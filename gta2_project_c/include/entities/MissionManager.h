#ifndef MISSIONMANAGER_H
#define MISSIONMANAGER_H

#include "../types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Структура: MissionManager (S27)
 * Описание: Менеджер миссий. Отвечает за активацию, выполнение, провал миссий,
 *           отслеживание целей, выдачу наград и управление скриптами миссий.
 * Размер: 512 байт (ТРЕБУЕТ УТОЧНЕНИЯ ПО ДАМПУ)
 * Адреса: Требуется привязка к MAP-файлу
 */

typedef struct MissionManager {
    // Основные данные о текущей миссии
    int32_t current_mission_id;       // 0x00: ID текущей активной миссии
    int32_t mission_state;            // 0x04: Состояние миссии (0: нет, 1: активна, 2: завершена, 3: провалена)
    
    // Цели миссии
    int32_t total_objectives;         // 0x08: Общее количество целей
    int32_t completed_objectives;     // 0x0C: Количество выполненных целей
    uint8_t objectives_mask[32];      // 0x10: Битовая маска выполненных целей (до 256 целей)
    
    // Награды и скрипты
    int32_t reward_pending;           // 0x30: Ожидающая выдачи награда (деньги/очки)
    int32_t script_thread_id;         // 0x34: ID потока скрипта миссии
    void* script_pointer;             // 0x38: Указатель на данные скрипта миссии
    
    // Целевые объекты и локации
    int32_t target_ped_id;            // 0x3C: ID целевого персонажа (если есть)
    int32_t target_car_id;            // 0x40: ID целевой машины (если есть)
    float target_location_x;          // 0x44: Координата X цели
    float target_location_y;          // 0x48: Координата Y цели
    float target_location_z;          // 0x4C: Координата Z цели (если используется)
    
    // Таймеры и флаги
    int32_t timer;                    // 0x50: Таймер миссии (тикани или секунды)
    int32_t time_limit;               // 0x54: Лимит времени на миссию
    uint32_t flags;                   // 0x58: Флаги состояния (битовое поле)
    
    // Буфер данных (заглушка до полного восстановления полей)
    uint8_t data_padding[444];        // 0x5C - 0x1FF: Дополнительные данные (заглушка)
} MissionManager;

// Глобальные переменные
extern MissionManager gMissionManager;
extern MissionManager* pMissionManager;

// ============================================================================
// Методы MissionManager
// ============================================================================

// Конструктор и деструктор
void MissionManager__Constructor(MissionManager* self);
void MissionManager__Destructor(MissionManager* self);

// Управление жизненным циклом миссии
void MissionManager__StartMission(MissionManager* self, int32_t mission_id);
void MissionManager__EndMission(MissionManager* self);
void MissionManager__FailMission(MissionManager* self);
void MissionManager__AbortAllMissions(MissionManager* self);

// Получение информации о миссии
int32_t MissionManager__GetCurrentMissionId(const MissionManager* self);
int32_t MissionManager__GetMissionState(const MissionManager* self);
uint8_t MissionManager__IsMissionActive(const MissionManager* self);
void* MissionManager__GetMissionScriptPointer(const MissionManager* self);

// Управление целями
void MissionManager__UpdateObjectives(MissionManager* self);
uint8_t MissionManager__CheckCompletion(const MissionManager* self);
int32_t MissionManager__GetObjectiveCount(const MissionManager* self);
int32_t MissionManager__GetCompletedObjectivesCount(const MissionManager* self);
void MissionManager__SetObjectiveCompleted(MissionManager* self, int32_t objective_index);
uint8_t MissionManager__IsObjectiveCompleted(const MissionManager* self, int32_t objective_index);

// Награды и прогресс
void MissionManager__GiveReward(MissionManager* self);
void MissionManager__SetNextMission(MissionManager* self, int32_t next_mission_id);
void MissionManager__ResetProgress(MissionManager* self);

// События и триггеры
void MissionManager__TriggerEvent(MissionManager* self, int32_t event_type, void* event_data);

// Загрузка/Сохранение
void MissionManager__LoadMissionData(MissionManager* self, const void* data_ptr);
void MissionManager__SaveMissionData(const MissionManager* self, void* data_ptr);

// Установка целей и локаций
void MissionManager__SetTargetPed(MissionManager* self, int32_t ped_id);
void MissionManager__SetTargetCar(MissionManager* self, int32_t car_id);
void MissionManager__SetTargetLocation(MissionManager* self, float x, float y, float z);
void MissionManager__SetTimer(MissionManager* self, int32_t time_limit);

#ifdef __cplusplus
}
#endif

#endif // MISSIONMANAGER_H
