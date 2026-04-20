#include "ped_ai.h"
#include "../systems/vector2d.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

// ============================================================================
// Вспомогательные функции
// ============================================================================

static const char* StateNames[] = {
    "IDLE", "WALK", "RUN", "FLEE", "ATTACK",
    "ENTER_CAR", "EXIT_CAR", "DRIVE", "PASSENGER",
    "DIE", "DEAD", "STUNNED", "HANDSUP", "WATCH", "TALK"
};

static const char* TaskNames[] = {
    "NONE", "GOTO_XY", "GOTO_OBJ", "WAIT", "ATTACK_PED",
    "ATTACK_CAR", "ENTER_CAR", "EXIT_CAR", "FLEE_FROM",
    "WANDER", "FOLLOW_ROUTE", "PLAY_ANIM", "SAY_LINE"
};

const char* PedAI_GetStateName(PedState state) {
    if (state >= 0 && state <= PED_STATE_TALK) {
        return StateNames[state];
    }
    return "UNKNOWN";
}

const char* PedAI_GetTaskName(TaskType task) {
    if (task >= 0 && task <= TASK_SAY_LINE) {
        return TaskNames[task];
    }
    return "UNKNOWN";
}

// ============================================================================
// Инициализация
// ============================================================================

void PedAI_Init(struct Ped* ped, PedPersonality personality) {
    if (!ped) return;
    
    // Настраиваем личность
    switch (personality) {
        case PERSONALITY_COWARD:
            ped->AI.Aggression = 0.2f;
            ped->AI.Courage = 0.3f;
            ped->AI.ViewDistance = 15.0f;
            ped->AI.MaxWalkSpeed = 1.5f;
            ped->AI.MaxRunSpeed = 4.0f;
            break;
            
        case PERSONALITY_NORMAL:
            ped->AI.Aggression = 0.5f;
            ped->AI.Courage = 0.5f;
            ped->AI.ViewDistance = 20.0f;
            ped->AI.MaxWalkSpeed = 2.0f;
            ped->AI.MaxRunSpeed = 5.0f;
            break;
            
        case PERSONALITY_BRAVE:
            ped->AI.Aggression = 0.6f;
            ped->AI.Courage = 0.8f;
            ped->AI.ViewDistance = 25.0f;
            ped->AI.MaxWalkSpeed = 2.2f;
            ped->AI.MaxRunSpeed = 5.5f;
            break;
            
        case PERSONALITY_AGGRESSIVE:
            ped->AI.Aggression = 0.9f;
            ped->AI.Courage = 0.7f;
            ped->AI.ViewDistance = 22.0f;
            ped->AI.MaxWalkSpeed = 2.5f;
            ped->AI.MaxRunSpeed = 6.0f;
            break;
            
        case PERSONALITY_POLICE:
            ped->AI.Aggression = 0.7f;
            ped->AI.Courage = 0.9f;
            ped->AI.ViewDistance = 30.0f;
            ped->AI.MaxWalkSpeed = 2.3f;
            ped->AI.MaxRunSpeed = 5.8f;
            break;
    }
    
    ped->AI.Personality = personality;
    ped->AI.StressLevel = 0.0f;
    ped->AI.StateTimer = 0;
    ped->AI.AttackCooldown = 0;
    ped->AI.DecisionTimer = 0;
    ped->AI.IsFollowingOrders = false;
    ped->AI.IsInCombat = false;
    ped->AI.IsSearching = false;
    ped->AI.HasLineOfSight = false;
    ped->AI.TargetPed = NULL;
    ped->AI.TargetCar = NULL;
    ped->AI.TargetPosition = VEC2_ZERO;
    ped->AI.TargetRadius = 0.5f;
    ped->AI.CurrentDirection = VEC2_ZERO;
    ped->AI.MoveSpeed = 0.0f;
    ped->AI.PathProgress = 0.0f;
    ped->AI.LastSeenThreatTime = 0;
    ped->AI.LastHeardSoundTime = 0;
    ped->AI.FOV = M_PI; // 180 градусов
    
    // Очищаем очередь задач
    PedAI_ClearTasks(ped);
    
    // Устанавливаем начальное состояние
    ped->CurrentState = PED_STATE_IDLE;
}

// ============================================================================
// Управление задачами
// ============================================================================

bool PedAI_AddTask(struct Ped* ped, TaskType type, TaskPriority priority, void* data) {
    if (!ped || ped->ObjectiveCounter >= 50) {
        return false;
    }
    
    // Добавляем задачу в конец очереди
    int index = ped->ObjectiveCounter;
    ped->ObjectiveQueue[index].Param = (int)(intptr_t)data; // Упрощённое хранение
    ped->ObjectiveCounter++;
    
    return true;
}

void PedAI_InterruptTask(struct Ped* ped, TaskPriority newPriority) {
    if (!ped) return;
    
    // Прерываем только если новый приоритет выше текущего
    // В упрощённой версии просто очищаем очередь для высоких приоритетов
    if (newPriority >= PRIORITY_HIGH) {
        PedAI_ClearTasks(ped);
    }
}

void PedAI_ClearTasks(struct Ped* ped) {
    if (!ped) return;
    
    ped->ObjectiveCounter = 0;
    // Обнуляем массив задач
    memset(ped->ObjectiveQueue, 0, sizeof(ped->ObjectiveQueue));
}

// ============================================================================
// Восприятие
// ============================================================================

bool PedAI_CanSee(struct Ped* ped, float targetX, float targetY) {
    if (!ped) return false;
    
    float dx = targetX - ped->PositionX;
    float dy = targetY - ped->PositionY;
    float distance = sqrtf(dx * dx + dy * dy);
    
    // Проверка дистанции
    if (distance > ped->AI.ViewDistance) {
        return false;
    }
    
    // Проверка угла обзора (упрощённо)
    float angleToTarget = atan2f(dy, dx);
    float pedAngle = 0.0f; // TODO: взять из ped->Rotation
    float angleDiff = fabsf(angleToTarget - pedAngle);
    
    // Нормализация угла
    while (angleDiff > M_PI) angleDiff -= 2.0f * M_PI;
    while (angleDiff < -M_PI) angleDiff += 2.0f * M_PI;
    
    if (fabsf(angleDiff) > ped->AI.FOV / 2.0f) {
        return false;
    }
    
    // TODO: Проверка линии видимости (raycast против стен)
    
    ped->AI.HasLineOfSight = true;
    return true;
}

bool PedAI_CanHear(struct Ped* ped, float soundX, float soundY, float volume) {
    if (!ped) return false;
    
    float dx = soundX - ped->PositionX;
    float dy = soundY - ped->PositionY;
    float distance = sqrtf(dx * dx + dy * dy);
    
    // Громкость затухает с расстоянием
    float heardVolume = volume * (1.0f - distance / ped->AI.HearingDistance);
    
    return heardVolume > 0.1f; // Порог слышимости
}

// ============================================================================
// Установка целей
// ============================================================================

void PedAI_SetTargetPosition(struct Ped* ped, float x, float y, float radius) {
    if (!ped) return;
    
    ped->AI.TargetPosition.x = x;
    ped->AI.TargetPosition.y = y;
    ped->AI.TargetRadius = radius;
}

void PedAI_SetTargetPed(struct Ped* ped, struct Ped* target) {
    if (!ped) return;
    
    ped->AI.TargetPed = target;
    ped->AI.TargetCar = NULL;
}

void PedAI_SetTargetCar(struct Ped* ped, struct Car* target) {
    if (!ped) return;
    
    ped->AI.TargetCar = target;
    ped->AI.TargetPed = NULL;
}

void PedAI_ForceState(struct Ped* ped, PedState state) {
    if (!ped) return;
    
    ped->CurrentState = state;
    ped->AI.StateTimer = 0;
}

// ============================================================================
// Обработка событий
// ============================================================================

void PedAI_OnDamage(struct Ped* ped, struct Ped* attacker, float damageAmount) {
    if (!ped || !attacker) return;
    
    // Повышаем уровень стресса
    ped->AI.StressLevel += damageAmount / 100.0f;
    if (ped->AI.StressLevel > 1.0f) ped->AI.StressLevel = 1.0f;
    
    // Реакция зависит от личности
    if (ped->AI.Courage < ped->AI.StressLevel) {
        // Трус бежит
        PedAI_ForceState(ped, PED_STATE_FLEE);
        PedAI_SetTargetPed(ped, NULL);
    } else if (ped->AI.Aggression > 0.5f) {
        // Агрессивный атакует в ответ
        PedAI_ForceState(ped, PED_STATE_ATTACK);
        PedAI_SetTargetPed(ped, attacker);
    }
    
    ped->AI.IsInCombat = true;
    ped->AI.LastSeenThreatTime = 0; // Сброс таймера
}

void PedAI_OnDeath(struct Ped* ped, struct Ped* killer) {
    if (!ped) return;
    
    PedAI_ForceState(ped, PED_STATE_DEAD);
    PedAI_ClearTasks(ped);
    
    // TODO: Уведомить банду о смерти
}

// ============================================================================
// Действия
// ============================================================================

bool PedAI_TryEnterCar(struct Ped* ped, struct Car* car, int doorIndex) {
    if (!ped || !car) return false;
    
    // Проверка: машина рядом?
    float dx = car->PositionX - ped->PositionX;
    float dy = car->PositionY - ped->PositionY;
    float distance = sqrtf(dx * dx + dy * dy);
    
    if (distance > 3.0f) {
        // Идти к машине
        PedAI_SetTargetPosition(ped, car->PositionX, car->PositionY, 2.0f);
        PedAI_ForceState(ped, PED_STATE_WALK);
        return false;
    }
    
    // Начать анимацию посадки
    PedAI_ForceState(ped, PED_STATE_ENTER_CAR);
    // TODO: Запустить анимацию, обновить Passenger структуру
    
    return true;
}

bool PedAI_TryExitCar(struct Ped* ped) {
    if (!ped) return false;
    
    // Проверка: пешеход в машине?
    if (!ped->Car) return false;
    
    // Начать анимацию выхода
    PedAI_ForceState(ped, PED_STATE_EXIT_CAR);
    // TODO: Запустить анимацию, обновить Passenger структуру
    
    return true;
}

bool PedAI_PerformAttack(struct Ped* ped) {
    if (!ped || ped->AI.AttackCooldown > 0) return false;
    
    struct Ped* target = ped->AI.TargetPed;
    if (!target) return false;
    
    // Проверка дистанции атаки
    float dx = target->PositionX - ped->PositionX;
    float dy = target->PositionY - ped->PositionY;
    float distance = sqrtf(dx * dx + dy * dy);
    
    if (distance > 2.0f) {
        // Подойти ближе
        return false;
    }
    
    // Атака!
    // TODO: Нанести урон через Weapon систему
    ped->AI.AttackCooldown = 60; // 1 секунда при 60 FPS
    
    return true;
}

// ============================================================================
// Поведения
// ============================================================================

void PedAI_Wander(struct Ped* ped, float dt) {
    if (!ped) return;
    
    // Случайное изменение направления каждые несколько секунд
    ped->AI.DecisionTimer += (u32)(dt * 60);
    if (ped->AI.DecisionTimer > 180) { // 3 секунды
        ped->AI.DecisionTimer = 0;
        
        // Случайный угол
        float angle = ((float)rand() / RAND_MAX) * 2.0f * M_PI;
        ped->AI.CurrentDirection.x = cosf(angle);
        ped->AI.CurrentDirection.y = sinf(angle);
    }
    
    // Движение в текущем направлении
    ped->PositionX += ped->AI.CurrentDirection.x * ped->AI.MaxWalkSpeed * dt;
    ped->PositionY += ped->AI.CurrentDirection.y * ped->AI.MaxWalkSpeed * dt;
}

void PedAI_Flee(struct Ped* ped, float threatX, float threatY, float dt) {
    if (!ped) return;
    
    // Вектор от угрозы
    float dx = ped->PositionX - threatX;
    float dy = ped->PositionY - threatY;
    float distance = sqrtf(dx * dx + dy * dy);
    
    if (distance < 0.1f) {
        // Угроза слишком близко, случайное направление
        float angle = ((float)rand() / RAND_MAX) * 2.0f * M_PI;
        dx = cosf(angle);
        dy = sinf(angle);
    } else {
        // Нормализация
        dx /= distance;
        dy /= distance;
    }
    
    // Бежать на полной скорости
    ped->PositionX += dx * ped->AI.MaxRunSpeed * dt;
    ped->PositionY += dy * ped->AI.MaxRunSpeed * dt;
}

// ============================================================================
// Главный цикл обновления
// ============================================================================

void PedAI_Update(struct Ped* ped, float dt) {
    if (!ped) return;
    
    // Обновление таймеров
    if (ped->AI.AttackCooldown > 0) {
        ped->AI.AttackCooldown--;
    }
    ped->AI.StateTimer += (u32)(dt * 60);
    
    // Снижение стресса со временем
    if (ped->AI.StressLevel > 0) {
        ped->AI.StressLevel -= dt * 0.1f;
        if (ped->AI.StressLevel < 0) ped->AI.StressLevel = 0;
    }
    
    // Машина состояний
    switch (ped->CurrentState) {
        case PED_STATE_IDLE:
            // Проверка очереди задач
            if (ped->ObjectiveCounter > 0) {
                // Выполнить первую задачу
                // TODO: Парсинг задачи из ObjectiveQueue
            } else {
                // Блуждать
                PedAI_Wander(ped, dt);
            }
            break;
            
        case PED_STATE_WALK:
        case PED_STATE_RUN: {
            // Движение к цели
            float dx = ped->AI.TargetPosition.x - ped->PositionX;
            float dy = ped->AI.TargetPosition.y - ped->PositionY;
            float distance = sqrtf(dx * dx + dy * dy);
            
            if (distance < ped->AI.TargetRadius) {
                // Достиг цели
                PedAI_ForceState(ped, PED_STATE_IDLE);
            } else {
                // Нормализация и движение
                dx /= distance;
                dy /= distance;
                float speed = (ped->CurrentState == PED_STATE_RUN) 
                    ? ped->AI.MaxRunSpeed 
                    : ped->AI.MaxWalkSpeed;
                
                ped->PositionX += dx * speed * dt;
                ped->PositionY += dy * speed * dt;
                
                // Обновление направления
                ped->AI.CurrentDirection.x = dx;
                ped->AI.CurrentDirection.y = dy;
            }
            break;
        }
        
        case PED_STATE_FLEE:
            if (ped->AI.TargetPed) {
                PedAI_Flee(ped, ped->AI.TargetPed->PositionX, ped->AI.TargetPed->PositionY, dt);
            } else {
                PedAI_ForceState(ped, PED_STATE_IDLE);
            }
            break;
            
        case PED_STATE_ATTACK:
            PedAI_PerformAttack(ped);
            break;
            
        case PED_STATE_ENTER_CAR:
            // TODO: Анимация посадки, обновление состояния машины
            break;
            
        case PED_STATE_EXIT_CAR:
            // TODO: Анимация выхода, обновление состояния машины
            break;
            
        case PED_STATE_DEAD:
        case PED_STATE_DIE:
            // Никаких действий
            break;
            
        default:
            break;
    }
    
    // Проверка окружения (угрозы, звуки)
    // TODO: Сканирование ближайших педов и машин
}
