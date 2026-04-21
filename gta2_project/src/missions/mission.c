/**
 * @file mission.c
 * @brief Реализация системы миссий и скриптов GTA2
 * 
 * old_file: gta2.exe.c (секция миссий)
 * Адреса функций соответствуют IDA Pro (sub_XXXXXX)
 */

#include "mission.h"
#include <string.h>
#include <stdio.h>

// -----------------------------------------------------------------------------
// Глобальные данные (симуляция)
// -----------------------------------------------------------------------------

// old_var: g_MissionTextTable
static const char* s_mission_messages[] = {
    "Mission Start",
    "Mission Complete",
    "Mission Failed",
    "Objective Updated",
    "New Target Marked"
};

// -----------------------------------------------------------------------------
// Реализация функций
// -----------------------------------------------------------------------------

/**
 * old_name: sub_00401000
 * old_var: manager, i
 */
void MissionManager_Init(MissionManager* manager) {
    if (!manager) return;

    manager->ActiveMission = 0; // NULL
    manager->TriggerCount = 0;
    manager->State = SCRIPT_IDLE;
    manager->WaitTimer = 0;
    manager->LastCheckedFrame = 0;

    // Очистка массива триггеров
    // old_var: trig_ptr
    for (int i = 0; i < 32; i++) {
        manager->Triggers[i].Type = TRIG_NONE;
        manager->Triggers[i].IsActive = false;
        manager->Triggers[i].IsOneShot = false;
        manager->Triggers[i].LinkedID = -1;
        manager->Triggers[i].ActionScriptIdx = -1;
    }
}

/**
 * old_name: sub_00401050
 * old_var: manager, player_ptr, mission, trig, frame
 */
void MissionManager_Update(MissionManager* manager, void* player_ptr) {
    if (!manager) return;

    // Проверка состояния ожидания
    if (manager->State == SCRIPT_WAITING) {
        manager->WaitTimer--;
        if (manager->WaitTimer <= 0) {
            manager->State = SCRIPT_RUNNING;
        }
        return; // Пропускаем кадр пока ждем
    }

    if (!manager->ActiveMission) return;

    Mission* mission = manager->ActiveMission;
    
    // Обновление таймера миссии
    // old_var: timer_val
    if (mission->Flags & MISSION_FLAG_ACTIVE) {
        mission->Timer++;
        
        // Проверка текущей цели
        if (Mission_CheckObjective(mission)) {
            mission->CurrentObjective++;
            // Тут могла быть логика переключения целей
        }

        // Проверка условий провала/успеха
        if (mission->CurrentObjective >= mission->TotalObjectives) {
            Mission_Finish(manager, true);
        }
    }

    // Обработка триггеров (упрощенно)
    // old_var: trig_idx
    for (int i = 0; i < manager->TriggerCount; i++) {
        // Логика проверки триггеров вынесена в ProcessTrigger обычно,
        // но здесь может быть поллинг для некоторых типов
    }
}

/**
 * old_name: sub_00401120
 * old_var: manager, mid, m_ptr
 */
bool Mission_Start(MissionManager* manager, int32_t mission_id) {
    if (!manager) return false;

    // Сброс предыдущей миссии если есть
    if (manager->ActiveMission) {
        Mission_Finish(manager, false); // Принудительный провал старой
    }

    // Здесь должна быть логика загрузки данных миссии из файла/памяти
    // old_var: temp_mission
    static Mission temp_mission; // Статика для примера
    
    memset(&temp_mission, 0, sizeof(Mission));
    temp_mission.MissionID = mission_id;
    sprintf(temp_mission.Name, "Mission_%d", mission_id);
    temp_mission.Flags = MISSION_FLAG_ACTIVE;
    temp_mission.TotalObjectives = 1; // Заглушка
    temp_mission.CurrentObjective = 0;
    temp_mission.Timer = 0;
    
    manager->ActiveMission = &temp_mission;
    manager->State = SCRIPT_RUNNING;

    Mission_ShowMessage(0, 3000); // "Mission Start"

    return true;
}

/**
 * old_name: sub_00401180
 * old_var: manager, success, msg_id
 */
void Mission_Finish(MissionManager* manager, bool success) {
    if (!manager || !manager->ActiveMission) return;

    if (success) {
        manager->ActiveMission->Flags |= MISSION_FLAG_COMPLETED;
        manager->ActiveMission->Flags &= ~MISSION_FLAG_ACTIVE;
        Mission_ShowMessage(1, 4000); // "Mission Complete"
    } else {
        manager->ActiveMission->Flags |= MISSION_FLAG_FAILED;
        manager->ActiveMission->Flags &= ~MISSION_FLAG_ACTIVE;
        Mission_ShowMessage(2, 4000); // "Mission Failed"
    }

    // Сброс указателя через небольшой промежуток или сразу
    // old_var: cleanup_flag
    manager->ActiveMission = 0; 
    manager->State = SCRIPT_IDLE;
}

/**
 * old_name: sub_00401200
 * old_var: mission, obj, curr, req
 */
bool Mission_CheckObjective(Mission* mission) {
    if (!mission || !mission->Objectives) return false;

    // old_var: cur_obj_idx
    Objective* obj = &mission->Objectives[mission->CurrentObjective];

    if (obj->CurrentCount >= obj->RequiredCount) {
        return true;
    }

    // Специфическая логика по типам целей могла быть здесь
    // old_var: check_res
    switch (obj->Type) {
        case OBJ_SURVIVE_TIME:
            // Проверка таймера
            break;
        case OBJ_REACH_LOCATION:
            // Проверка координат игрока
            break;
        default:
            break;
    }

    return false;
}

/**
 * old_name: sub_00401280
 * old_var: manager, evt_type, evt_data, t_idx, trig_ptr
 */
void Mission_ProcessTrigger(MissionManager* manager, int32_t event_type, int32_t event_data) {
    if (!manager) return;

    // old_var: i
    for (int i = 0; i < manager->TriggerCount; i++) {
        MissionTrigger* trig = &manager->Triggers[i];

        if (!trig->IsActive) continue;

        bool triggered = false;

        // old_var: match
        if ((int)trig->Type == event_type) {
            if (trig->LinkedID == -1 || trig->LinkedID == event_data) {
                triggered = true;
            }
        }

        if (triggered) {
            // Выполнение действия
            Script_ExecuteCommand(manager, trig->ActionScriptIdx, event_data, 0);

            if (trig->IsOneShot) {
                trig->IsActive = false;
            }
        }
    }
}

/**
 * old_name: sub_00401300
 * old_var: manager, ticks
 */
void Script_Wait(MissionManager* manager, int32_t ticks) {
    if (!manager) return;
    
    manager->WaitTimer = ticks;
    manager->State = SCRIPT_WAITING;
}

/**
 * old_name: sub_00401350
 * old_var: text_id, duration, msg_ptr
 */
void Mission_ShowMessage(int32_t text_id, int32_t duration) {
    // В реальной игре здесь вызов UI функции
    // old_var: str_buf
    const char* msg = "Unknown Message";
    if (text_id >= 0 && text_id < 5) {
        msg = s_mission_messages[text_id];
    }

    // printf("[UI] Message %d: %s (%d ms)\n", text_id, msg, duration);
    // Здесь должен быть вызов функции рендеринга текста
}

/**
 * old_name: sub_004013C0
 * old_var: mission, type, target, req, new_obj
 */
void Mission_AddObjective(Mission* mission, ObjectiveType type, int32_t target_id, int32_t required) {
    if (!mission || !mission->Objectives) return;
    
    // old_var: idx
    int idx = mission->TotalObjectives;
    if (idx >= 10) return; // Лимит на количество целей (предположительно)

    Objective* obj = &mission->Objectives[idx];
    obj->Type = type;
    obj->TargetID = target_id;
    obj->CurrentCount = 0;
    obj->RequiredCount = required;
    obj->Flags = 0;

    mission->TotalObjectives++;
    
    Mission_ShowMessage(3, 2000); // "Objective Updated"
}

/**
 * old_name: sub_00401420
 * old_var: manager, zone_id, is_enter, script_idx, t_idx
 */
void Mission_CreateZoneTrigger(MissionManager* manager, int32_t zone_id, bool is_enter_trigger, int32_t script_idx) {
    if (!manager || manager->TriggerCount >= 32) return;

    MissionTrigger* trig = &manager->Triggers[manager->TriggerCount];
    
    trig->Type = is_enter_trigger ? TRIG_ENTER_ZONE : TRIG_LEAVE_ZONE;
    trig->LinkedID = zone_id;
    trig->IsActive = true;
    trig->IsOneShot = false; // По умолчанию многоразовый
    trig->ActionScriptIdx = script_idx;

    manager->TriggerCount++;
}

/**
 * old_name: sub_00401480
 * old_var: manager
 */
MissionFlags Mission_GetStatus(MissionManager* manager) {
    if (!manager || !manager->ActiveMission) {
        return MISSION_FLAG_NONE;
    }
    return manager->ActiveMission->Flags;
}

/**
 * old_name: sub_004014D0
 * old_var: manager, i
 */
void MissionManager_Reset(MissionManager* manager) {
    if (!manager) return;

    if (manager->ActiveMission) {
        manager->ActiveMission->Flags = MISSION_FLAG_NONE;
        manager->ActiveMission = 0;
    }

    manager->State = SCRIPT_IDLE;
    manager->WaitTimer = 0;
    manager->TriggerCount = 0;
    
    // Очистка триггеров
    for (int i = 0; i < 32; i++) {
        manager->Triggers[i].IsActive = false;
    }
}

/**
 * old_name: sub_00401550
 * old_var: manager, cmd, p1, p2, res
 * 
 * Интерпретатор скриптовых команд.
 * В GTA2 это мог быть байт-код или набор hardcoded функций.
 */
void Script_ExecuteCommand(MissionManager* manager, int32_t command_code, int32_t param_a, int32_t param_b) {
    if (!manager) return;

    // old_var: op_code
    switch (command_code) {
        case 0: // NOP
            break;
        case 1: // WAIT
            Script_Wait(manager, param_a);
            break;
        case 2: // SPAWN_PED
            // Вызов функции спавна пешехода
            // Ped_Spawn(param_a, param_b);
            break;
        case 3: // SPAWN_CAR
            // Вызов функции спавна машины
            break;
        case 4: // SHOW_TEXT
            Mission_ShowMessage(param_a, param_b);
            break;
        case 5: // FAIL_MISSION
            Mission_Finish(manager, false);
            break;
        case 6: // PASS_MISSION
            Mission_Finish(manager, true);
            break;
        default:
            // Неизвестная команда
            break;
    }
}
