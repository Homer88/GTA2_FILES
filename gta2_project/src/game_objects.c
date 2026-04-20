#include "game_objects.h"
#include "ped.h"
#include "player.h"
#include <string.h>

// Глобальный менеджер объектов (единственный экземпляр)
static WorldObjectsManager g_worldObjects;

// ============================================================================
// PICKUP FUNCTIONS
// ============================================================================

void Pickup_Init(Pickup* p, PickupType type, Vector2D pos, u32 value) {
    if (!p) return;
    memset(p, 0, sizeof(Pickup));
    p->Position = pos;
    p->Height = 0.0f;
    p->Type = type;
    p->State = 1; // Активен
    p->RotationAngle = 0;
    p->RespawnTimer = 0;
    p->Value = value;
    p->IsActive = 1;
}

void Pickup_Update(Pickup* p, f32 dt) {
    if (!p || !p->IsActive) return;

    if (p->State == 2) { // Поднят
        p->RespawnTimer -= (u32)(dt * 1000);
        if (p->RespawnTimer == 0) {
            p->State = 1; // Возрожден
            p->Height = 0.0f;
        }
    } else {
        // Анимация парения и вращения
        p->Height = 0.3f + 0.1f * (f32)((p->RespawnTimer / 100) % 10) / 10.0f;
        p->RotationAngle = (p->RotationAngle + (u8)(dt * 100)) % 256;
    }
}

bool Pickup_TryCollect(Pickup* p, void* collector) {
    if (!p || !p->IsActive || p->State != 1) return false;
    
    // Здесь должна быть проверка дистанции между collector и p->Position
    // Для упрощения считаем что коллектор уже в радиусе
    
    p->State = 2; // Поднят
    p->IsActive = 0;
    p->RespawnTimer = 30000; // 30 секунд до возрождения
    
    // Логика применения эффекта
    if (collector) {
        // Если это игрок или пешеход - применить бонус
        // TODO: Вызов функций Player_AddMoney, Ped_AddWeapon и т.д.
    }
    
    return true;
}

void Pickup_Spawn(PickupType type, Vector2D pos, u32 value) {
    for (int i = 0; i < MAX_PICKUPS; i++) {
        if (!g_worldObjects.PickupActiveMap[i / 8] & (1 << (i % 8))) {
            Pickup_Init(&g_worldObjects.Pickups[i], type, pos, value);
            g_worldObjects.PickupActiveMap[i / 8] |= (1 << (i % 8));
            g_worldObjects.TotalPickupsSpawned++;
            return;
        }
    }
}

// ============================================================================
// CHECKPOINT FUNCTIONS
// ============================================================================

void Checkpoint_Init(Checkpoint* c, CheckpointType type, Vector2D pos, f32 radius) {
    if (!c) return;
    memset(c, 0, sizeof(Checkpoint));
    c->Position = pos;
    c->Radius = radius;
    c->Type = type;
    c->IsActivated = 0;
    c->ZoneID = 0;
    c->MissionID = 0;
    c->BonusMoney = 0;
}

bool Checkpoint_Trigger(Checkpoint* c, void* entity) {
    if (!c || c->IsActivated) return false;
    
    // Проверка типа и активация
    c->IsActivated = 1;
    g_worldObjects.TotalCheckpointsTriggered++;
    
    // Логика в зависимости от типа
    switch (c->Type) {
        case CHECKPOINT_RACE:
            // Обновить прогресс гонки
            break;
        case CHECKPOINT_SAVE:
            // Сохранить игру
            break;
        case CHECKPOINT_MISSION_TRIGGER:
            // Начать миссию
            break;
        case CHECKPOINT_HIDDEN_PACKAGE:
            // Добавить деньги/бонус
            break;
    }
    
    return true;
}

// ============================================================================
// PHONE_BOOTH FUNCTIONS
// ============================================================================

void PhoneBooth_Init(PhoneBooth* ph, Vector2D pos, u16 missionId) {
    if (!ph) return;
    memset(ph, 0, sizeof(PhoneBooth));
    ph->Position = pos;
    ph->State = PHONE_FREE;
    ph->MissionID = missionId;
    ph->CurrentUser = NULL;
    ph->UsageTimer = 0;
    ph->IsAvailable = 1;
}

bool PhoneBooth_Use(PhoneBooth* ph, Ped* user) {
    if (!ph || ph->State != PHONE_FREE || !ph->IsAvailable) return false;
    
    ph->State = PHONE_IN_USE;
    ph->CurrentUser = user;
    ph->UsageTimer = 5000; // 5 секунд на разговор
    
    // Запуск миссии
    // TODO: Mission_Start(ph->MissionID);
    
    return true;
}

void PhoneBooth_Update(PhoneBooth* ph, f32 dt) {
    if (!ph) return;
    
    if (ph->State == PHONE_IN_USE) {
        ph->UsageTimer -= (u32)(dt * 1000);
        if (ph->UsageTimer == 0) {
            ph->State = PHONE_FREE;
            ph->CurrentUser = NULL;
            ph->UsageTimer = 10000; // 10 секунд блокировки после использования
        }
    } else if (ph->State == PHONE_BROKEN) {
        // Сломан навсегда или до ремонта
    }
}

// ============================================================================
// SHOP FUNCTIONS
// ============================================================================

bool Shop_IsOpen(Shop* s, u8 currentHour) {
    if (!s) return false;
    if (!s->IsOpen) return false;
    
    if (s->HourOpen <= s->HourClose) {
        return (currentHour >= s->HourOpen && currentHour < s->HourClose);
    } else {
        // Работает через полночь (например, 22:00 - 06:00)
        return (currentHour >= s->HourOpen || currentHour < s->HourClose);
    }
}

bool Shop_TryBuy(Shop* s, u8 itemIndex, u32* money) {
    if (!s || !money || itemIndex >= 4) return false;
    if (!Shop_IsOpen(s, 12)) return false; // Пример: текущий час 12
    if (s->Stock[itemIndex] == 0) return false;
    
    if (*money >= s->Prices[itemIndex]) {
        *money -= s->Prices[itemIndex];
        s->Stock[itemIndex]--;
        // TODO: Выдать товар игроку
        return true;
    }
    
    return false;
}

// ============================================================================
// MOVING_PLATFORM FUNCTIONS
// ============================================================================

void MovingPlatform_Init(MovingPlatform* mp, Vector2D start, Vector2D end, f32 speed) {
    if (!mp) return;
    memset(mp, 0, sizeof(MovingPlatform));
    mp->StartPos = start;
    mp->EndPos = end;
    mp->Speed = speed;
    mp->CurrentPos = 0.0f;
    mp->State = PLATFORM_IDLE;
    mp->WaitTimer = 0;
    mp->DamageOnCrush = 100;
}

void MovingPlatform_Update(MovingPlatform* mp, f32 dt) {
    if (!mp) return;
    
    switch (mp->State) {
        case PLATFORM_IDLE:
            // Ждем триггера
            break;
            
        case PLATFORM_MOVING_FWD:
            mp->CurrentPos += mp->Speed * dt;
            if (mp->CurrentPos >= 1.0f) {
                mp->CurrentPos = 1.0f;
                mp->State = PLATFORM_WAITING;
                mp->WaitTimer = 3000; // 3 секунды等待
            }
            break;
            
        case PLATFORM_MOVING_BACK:
            mp->CurrentPos -= mp->Speed * dt;
            if (mp->CurrentPos <= 0.0f) {
                mp->CurrentPos = 0.0f;
                mp->State = PLATFORM_IDLE;
            }
            break;
            
        case PLATFORM_WAITING:
            mp->WaitTimer -= (u32)(dt * 1000);
            if (mp->WaitTimer == 0) {
                mp->State = PLATFORM_MOVING_BACK;
            }
            break;
    }
}

bool MovingPlatform_CheckCrush(MovingPlatform* mp, void* entity) {
    // Проверка попадания объекта под платформу
    // Упрощенно: если платформа движется и объект в зоне
    if (!mp || !entity) return false;
    if (mp->State != PLATFORM_MOVING_FWD && mp->State != PLATFORM_MOVING_BACK) return false;
    
    // TODO: Реальная проверка коллизий
    // Если раздавил - нанести урон
    return false;
}

// ============================================================================
// MANAGER FUNCTIONS
// ============================================================================

void WorldObjects_Init(void) {
    memset(&g_worldObjects, 0, sizeof(WorldObjectsManager));
    
    // Инициализация всех пулов
    for (int i = 0; i < MAX_PICKUPS; i++) {
        g_worldObjects.PickupActiveMap[i / 8] &= ~(1 << (i % 8));
    }
    
    g_worldObjects.TotalPickupsSpawned = 0;
    g_worldObjects.TotalCheckpointsTriggered = 0;
}

void WorldObjects_UpdateAll(f32 dt, u8 currentHour) {
    // Обновление pickups
    for (int i = 0; i < MAX_PICKUPS; i++) {
        if (g_worldObjects.PickupActiveMap[i / 8] & (1 << (i % 8))) {
            Pickup_Update(&g_worldObjects.Pickups[i], dt);
        }
    }
    
    // Обновление phone booths
    for (int i = 0; i < MAX_PHONES; i++) {
        PhoneBooth_Update(&g_worldObjects.Phones[i], dt);
    }
    
    // Обновление platforms
    for (int i = 0; i < MAX_PLATFORMS; i++) {
        MovingPlatform_Update(&g_worldObjects.Platforms[i], dt);
    }
}

Pickup* WorldObjects_FindNearestPickup(Vector2D pos, f32 radius) {
    Pickup* nearest = NULL;
    f32 minDist = radius;
    
    for (int i = 0; i < MAX_PICKUPS; i++) {
        if (!(g_worldObjects.PickupActiveMap[i / 8] & (1 << (i % 8)))) continue;
        
        Pickup* p = &g_worldObjects.Pickups[i];
        if (!p->IsActive || p->State != 1) continue;
        
        f32 dx = p->Position.X - pos.X;
        f32 dy = p->Position.Y - pos.Y;
        f32 dist = dx*dx + dy*dy;
        
        if (dist < minDist*minDist) {
            minDist = dist;
            nearest = p;
        }
    }
    
    return nearest;
}
