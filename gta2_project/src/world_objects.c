#include "world_objects.h"
#include <string.h>
#include <math.h>

// Глобальный экземпляр мира
WorldManager g_world;

// Глобальный ветер для частиц
static f32 g_wind_x = 0.0f;
static f32 g_wind_y = 0.0f;

/* ============================================================================
   ИНИЦИАЛИЗАЦИЯ МИРА
   ============================================================================ */

void World_Init(WorldManager* world) {
    if (!world) return;
    
    memset(world, 0, sizeof(WorldManager));
    
    world->BuildingsList = NULL;
    world->ParticlesList = NULL;
    world->ZonesList = NULL;
    
    world->BuildingCount = 0;
    world->ParticleCount = 0;
    world->ZoneCount = 0;
    
    // Пулы уже обнулены memset, битовые карты тоже (0 = свободно)
}

void World_Clear(WorldManager* world) {
    if (!world) return;
    World_Init(world); // Полный сброс
}

/* ============================================================================
   ЗДАНИЯ
   ============================================================================ */

Building* World_CreateBuilding(WorldManager* world, u16 x, u16 y, u8 type, u16 sprite) {
    if (!world || world->BuildingCount >= MAX_BUILDINGS) return NULL;
    
    // Поиск свободного слота в пуле
    for (u32 i = 0; i < MAX_BUILDINGS; i++) {
        u8 byte_idx = i / 8;
        u8 bit_idx = i % 8;
        
        if (!(world->BuildingFreeMap[byte_idx] & (1 << bit_idx))) {
            // Слот свободен
            world->BuildingFreeMap[byte_idx] |= (1 << bit_idx); // Пометить как занятый
            
            Building* bld = &world->BuildingPool[i];
            memset(bld, 0, sizeof(Building));
            
            bld->TileX = x;
            bld->TileY = y;
            bld->SpriteIndex = sprite;
            bld->BaseSpriteIndex = sprite;
            bld->Health = 255; // Полное здоровье
            bld->Type = type;
            bld->Flags = BUILDING_FLAG_VISIBLE | BUILDING_FLAG_COLLISION;
            
            // Вычисление хитбокса (предполагаем тайл 32x32)
            bld->CollisionBox.X = (f32)x * 32.0f;
            bld->CollisionBox.Y = (f32)y * 32.0f;
            bld->CollisionBox.Width = 32.0f;
            bld->CollisionBox.Height = 32.0f;
            bld->CollisionBox.Angle = 0.0f;
            
            // Вставка в связный список
            bld->Next = world->BuildingsList;
            world->BuildingsList = bld;
            
            world->BuildingCount++;
            return bld;
        }
    }
    
    return NULL; // Нет свободных слотов
}

void World_DestroyBuilding(Building* bld) {
    if (!bld) return;
    
    bld->Flags |= BUILDING_FLAG_DESTROYED;
    bld->Flags &= ~BUILDING_FLAG_COLLISION; // Убрать коллизию
    bld->Health = 0;
    
    // Смена спрайта на разрушенный (если есть база данных спрайтов)
    // bld->SpriteIndex = GetDestroyedSprite(bld->BaseSpriteIndex);
    
    // Спавн частиц разрушения
    // World_SpawnParticle(&g_world, bld->CollisionBox.X, bld->CollisionBox.Y, PARTICLE_DEBRIS);
}

void World_DamageBuilding(Building* bld, u8 damage) {
    if (!bld || (bld->Flags & BUILDING_FLAG_DESTROYED)) return;
    
    if (bld->Type == BUILDING_WALL_SOLID) return; // Неразрушимые
    
    bld->Health -= damage;
    
    if (bld->Health <= 0) {
        World_DestroyBuilding(bld);
    } else if (bld->Health < 100 && !(bld->Flags & BUILDING_FLAG_SMOKING)) {
        bld->Flags |= BUILDING_FLAG_SMOKING;
        // Спавн дыма
        // World_SpawnParticle(&g_world, bld->CollisionBox.X + 16, bld->CollisionBox.Y + 16, PARTICLE_SMOKE);
    }
}

bool World_IsBuildingSolid(Building* bld) {
    if (!bld) return false;
    if (bld->Flags & BUILDING_FLAG_DESTROYED) return false;
    if (!(bld->Flags & BUILDING_FLAG_COLLISION)) return false;
    
    // Заборы и стекло пропускают пули, но не машины/пешеходов
    return (bld->Type == BUILDING_WALL_SOLID || 
            bld->Type == BUILDING_WALL_BREAKABLE ||
            bld->Type == BUILDING_FENCE);
}

/* ============================================================================
   ЧАСТИЦЫ
   ============================================================================ */

Particle* World_SpawnParticle(WorldManager* world, f32 x, f32 y, u8 type) {
    if (!world || world->ParticleCount >= MAX_PARTICLES) return NULL;
    
    for (u32 i = 0; i < MAX_PARTICLES; i++) {
        u8 byte_idx = i / 8;
        u8 bit_idx = i % 8;
        
        if (!(world->ParticleFreeMap[byte_idx] & (1 << bit_idx))) {
            world->ParticleFreeMap[byte_idx] |= (1 << bit_idx);
            
            Particle* p = &world->ParticlePool[i];
            memset(p, 0, sizeof(Particle));
            
            p->Pos.X = x;
            p->Pos.Y = y;
            p->Vel.X = 0.0f;
            p->Vel.Y = 0.0f;
            
            // Настройки по типу
            switch (type) {
                case PARTICLE_SMOKE:
                    p->MaxLifeTime = 120;
                    p->LifeTime = 120;
                    p->Size = 8;
                    p->Alpha = 180;
                    p->Flags = PARTICLE_FLAG_FADE | PARTICLE_FLAG_WIND;
                    break;
                case PARTICLE_FIRE:
                    p->MaxLifeTime = 40;
                    p->LifeTime = 40;
                    p->Size = 6;
                    p->Alpha = 255;
                    p->ColorR = 255; p->ColorG = 100; p->ColorB = 0;
                    p->Flags = PARTICLE_FLAG_GRAVITY; // Огонь вверх? Инверсия в рендере
                    break;
                case PARTICLE_SPARK:
                    p->MaxLifeTime = 20;
                    p->LifeTime = 20;
                    p->Size = 2;
                    p->Alpha = 255;
                    p->ColorR = 255; p->ColorG = 255; p->ColorB = 200;
                    // Случайная скорость
                    p->Vel.X = ((f32)(rand() % 100) - 50) / 10.0f;
                    p->Vel.Y = ((f32)(rand() % 100) - 50) / 10.0f;
                    p->Flags = PARTICLE_FLAG_GRAVITY | PARTICLE_FLAG_FADE;
                    break;
                case PARTICLE_BLOOD:
                    p->MaxLifeTime = 60;
                    p->LifeTime = 60;
                    p->Size = 4;
                    p->Alpha = 255;
                    p->ColorR = 200; p->ColorG = 0; p->ColorB = 0;
                    p->Flags = PARTICLE_FLAG_GRAVITY | PARTICLE_FLAG_FADE;
                    break;
                default:
                    p->MaxLifeTime = 30;
                    p->LifeTime = 30;
                    p->Size = 4;
                    p->Alpha = 255;
            }
            
            p->Type = type;
            p->SpriteIndex = 0; // Базовый спрайт частицы
            
            // Вставка в список
            p->Next = world->ParticlesList;
            world->ParticlesList = p;
            
            world->ParticleCount++;
            return p;
        }
    }
    
    return NULL;
}

void World_UpdateParticles(WorldManager* world) {
    if (!world) return;
    
    Particle* p = world->ParticlesList;
    Particle* prev = NULL;
    
    while (p) {
        p->LifeTime--;
        
        // Движение
        p->Pos.X += p->Vel.X;
        p->Pos.Y += p->Vel.Y;
        
        // Ветер
        if (p->Flags & PARTICLE_FLAG_WIND) {
            p->Vel.X += g_wind_x * 0.1f;
            p->Vel.Y += g_wind_y * 0.1f;
        }
        
        // Гравитация (в GTA 2 Y вниз положительный?)
        if (p->Flags & PARTICLE_FLAG_GRAVITY) {
            p->Vel.Y += 0.2f; 
        }
        
        // Трение
        p->Vel.X *= 0.95f;
        p->Vel.Y *= 0.95f;
        
        // Исчезновение
        if (p->Flags & PARTICLE_FLAG_FADE) {
            f32 ratio = (f32)p->LifeTime / (f32)p->MaxLifeTime;
            p->Alpha = (u8)(255.0f * ratio);
            p->Size = (u8)((f32)p->Size * ratio);
        }
        
        // Удаление мертвых частиц
        if (p->LifeTime <= 0) {
            Particle* to_remove = p;
            p = p->Next;
            
            // Удаление из списка
            if (prev) {
                prev->Next = p;
            } else {
                world->ParticlesList = p;
            }
            
            // Освобождение слота
            u32 idx = (u32)(to_remove - world->ParticlePool);
            u8 byte_idx = idx / 8;
            u8 bit_idx = idx % 8;
            world->ParticleFreeMap[byte_idx] &= ~(1 << bit_idx);
            
            world->ParticleCount--;
            continue;
        }
        
        prev = p;
        p = p->Next;
    }
}

void World_ClearParticles(WorldManager* world) {
    if (!world) return;
    
    memset(world->ParticleFreeMap, 0, sizeof(world->ParticleFreeMap));
    world->ParticlesList = NULL;
    world->ParticleCount = 0;
}

void World_SetParticleWind(f32 wx, f32 wy) {
    g_wind_x = wx;
    g_wind_y = wy;
}

/* ============================================================================
   СПЕЦИАЛЬНЫЕ ЗОНЫ
   ============================================================================ */

SpecialZone* World_CreateZone(WorldManager* world, u16 x, u16 y, u16 w, u16 h, u8 type) {
    if (!world || world->ZoneCount >= MAX_ZONES) return NULL;
    
    for (u32 i = 0; i < MAX_ZONES; i++) {
        u8 byte_idx = i / 8;
        u8 bit_idx = i % 8;
        
        if (!(world->ZoneFreeMap[byte_idx] & (1 << bit_idx))) {
            world->ZoneFreeMap[byte_idx] |= (1 << bit_idx);
            
            SpecialZone* zone = &world->ZonePool[i];
            memset(zone, 0, sizeof(SpecialZone));
            
            zone->X = x;
            zone->Y = y;
            zone->Width = w;
            zone->Height = h;
            zone->Type = type;
            zone->Flags = ZONE_FLAG_ACTIVE;
            
            // Настройки по типу
            switch (type) {
                case ZONE_WATER:
                    zone->DamagePerSec = 0;
                    zone->Flags |= ZONE_FLAG_SLOW;
                    break;
                case ZONE_LAVA:
                    zone->DamagePerSec = 20;
                    zone->Flags |= ZONE_FLAG_DAMAGE;
                    break;
                case ZONE_ICE:
                    zone->DamagePerSec = 0;
                    zone->Flags |= ZONE_FLAG_SLOW; // Скольжение
                    break;
                case ZONE_TRIGGER:
                    zone->Flags |= ZONE_FLAG_ONCE;
                    break;
            }
            
            // Вставка в список
            zone->Next = world->ZonesList;
            world->ZonesList = zone;
            
            world->ZoneCount++;
            return zone;
        }
    }
    
    return NULL;
}

bool World_CheckZoneCollision(SpecialZone* zone, f32 px, f32 py, f32 pw, f32 ph) {
    if (!zone || !(zone->Flags & ZONE_FLAG_ACTIVE)) return false;
    
    // AABB проверка
    f32 zx1 = (f32)zone->X;
    f32 zy1 = (f32)zone->Y;
    f32 zx2 = zx1 + (f32)zone->Width;
    f32 zy2 = zy1 + (f32)zone->Height;
    
    f32 px1 = px - pw / 2.0f;
    f32 py1 = py - ph / 2.0f;
    f32 px2 = px + pw / 2.0f;
    f32 py2 = py + ph / 2.0f;
    
    return (px1 < zx2 && px2 > zx1 && py1 < zy2 && py2 > zy1);
}

void World_ApplyZoneEffects(WorldManager* world, struct Ped* ped, struct Car* car) {
    if (!world) return;
    
    SpecialZone* zone = world->ZonesList;
    
    while (zone) {
        if (!(zone->Flags & ZONE_FLAG_ACTIVE)) {
            zone = zone->Next;
            continue;
        }
        
        bool ped_in_zone = false;
        bool car_in_zone = false;
        
        // Проверка пешехода
        if (ped) {
            // Предположим, что у Ped есть PositionX/Y
            // ped_in_zone = World_CheckZoneCollision(zone, ped->PositionX, ped->PositionY, 10.0f, 10.0f);
        }
        
        // Проверка машины
        if (car) {
            // car_in_zone = World_CheckZoneCollision(zone, car->PositionX, car->PositionY, 40.0f, 70.0f);
        }
        
        if (ped_in_zone || car_in_zone) {
            // Применение эффектов
            if (zone->Flags & ZONE_FLAG_DAMAGE) {
                // Нанесение урона
                if (ped) {
                    // ped->Health -= zone->DamagePerSec / 60; // 60 FPS
                }
                if (car) {
                    // car->Health -= zone->DamagePerSec / 60;
                }
            }
            
            if (zone->Flags & ZONE_FLAG_SLOW) {
                // Замедление
                if (car) {
                    // car->Speed *= 0.5f;
                }
            }
            
            if (zone->Flags & ZONE_FLAG_ONCE) {
                zone->Flags &= ~ZONE_FLAG_ACTIVE; // Деактивировать
            }
        }
        
        zone = zone->Next;
    }
}
