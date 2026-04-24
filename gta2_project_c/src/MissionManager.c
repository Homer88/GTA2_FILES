/**
 * @file MissionManager.c
 * @brief Реализация менеджера миссий GTA 2
 * 
 * Размер структуры: 0xC1EA8 (793,768 байт)
 * Адрес глобального экземпляра: 0x006644BC
 */

#include "MissionManager.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Глобальный экземпляр менеджера миссий
MissionManager gMissionManager;
MissionManager* pMissionManager = &gMissionManager;

// ============================================================================
// ВНУТРЕННИЕ ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ
// ============================================================================

static void ClearObjectPool(MissionManager* self) {
    for (int i = 0; i < MAX_MISSION_OBJECTS; i++) {
        self->objects_pool[i].type = MISSION_OBJ_NONE;
        self->objects_pool[i].is_active = 0;
        self->objects_pool[i].flags = 0;
    }
}

static void ClearTriggerPool(MissionManager* self) {
    for (int i = 0; i < MAX_MISSION_TRIGGERS; i++) {
        self->triggers_pool[i].type = TRIGGER_NONE;
        self->triggers_pool[i].state = 0;
    }
}

static int IsValidObjectIndex(MissionManager* self, uint32_t index) {
    return (index < MAX_MISSION_OBJECTS && self->objects_pool[index].type != MISSION_OBJ_NONE);
}

static int IsValidTriggerIndex(MissionManager* self, uint32_t index) {
    return (index < MAX_MISSION_TRIGGERS && self->triggers_pool[index].type != TRIGGER_NONE);
}

// ============================================================================
// ИНИЦИАЛИЗАЦИЯ И ЖИЗНЕННЫЙ ЦИКЛ
// ============================================================================

// Адрес: 0x00481900, Размер: 0x2A0 (672 байта)
void MissionManager__Constructor(MissionManager* self) {
    if (!self) return;
    memset(self, 0, sizeof(MissionManager));
    self->state = MISSION_STATE_UNLOADED;
    self->current_mission_id = 0xFFFFFFFF;
    self->mission_status = 0;
    self->script_buffer_ptr = NULL;
    self->script_size = 0;
    self->script_cursor = 0;
    ClearObjectPool(self);
    ClearTriggerPool(self);
    self->current_script_path[0] = '\0';
    self->save_file_path[0] = '\0';
}

// Адрес: 0x00481BA0, Размер: 0x50 (80 байт)
void MissionManager__Destructor(MissionManager* self) {
    if (!self) return;
    if (self->script_buffer_ptr) {
        free(self->script_buffer_ptr);
        self->script_buffer_ptr = NULL;
    }
    self->state = MISSION_STATE_UNLOADED;
    self->script_size = 0;
    self->script_cursor = 0;
    ClearObjectPool(self);
    ClearTriggerPool(self);
}

// Адрес: 0x00490C30, Размер: 0x1F0 (496 байт)
void MissionManager__Reset(MissionManager* self) {
    if (!self) return;
    self->state = MISSION_STATE_IDLE;
    self->current_mission_id = 0xFFFFFFFF;
    self->mission_status = 0;
    self->total_objectives = 0;
    self->completed_objectives = 0;
    self->script_cursor = 0;
    self->timer_main = 0;
    self->timer_secondary = 0;
    self->reward_money = 0.0f;
    self->reward_respect = 0;
    memset(self->objectives_flags, 0, sizeof(self->objectives_flags));
    ClearObjectPool(self);
    ClearTriggerPool(self);
}
