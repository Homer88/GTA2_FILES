#ifndef WORLD_OBJECTS_H
#define WORLD_OBJECTS_H

#include "types.h"
#include "systems/vector2d.h"
#include "systems/rect2d.h"

/* ============================================================================
   ЗДАНИЯ И СТАТИЧЕСКИЕ ОБЪЕКТЫ (Building)
   ----------------------------------------------------------------------------
   Статические объекты уровня: стены, заборы, декорации.
   Могут быть разрушены, меняют спрайт при повреждении.
   Размер: 16 байт
   ============================================================================ */

typedef enum BuildingType {
    BUILDING_WALL_SOLID = 0,      // Неразрушимая стена
    BUILDING_WALL_BREAKABLE = 1,  // Разрушимая стена
    BUILDING_FENCE = 2,           // Забор (можно прострелить)
    BUILDING_DECOR = 3,           // Декор (фонарь, урна)
    BUILDING_GLASS = 4            // Витрина (бьется от пуль)
} BuildingType;

typedef enum BuildingFlags {
    BUILDING_FLAG_VISIBLE = 0x01,
    BUILDING_FLAG_COLLISION = 0x02,
    BUILDING_FLAG_DESTROYED = 0x04,
    BUILDING_FLAG_SMOKING = 0x08  // Дымит при разрушении
} BuildingFlags;

typedef struct Building {
    u16 TileX;              // 0x0: Координата X в сетке тайлов
    u16 TileY;              // 0x2: Координата Y в сетке тайлов
    u16 SpriteIndex;        // 0x4: Текущий индекс спрайта
    u16 BaseSpriteIndex;    // 0x6: Исходный индекс (для респауна)
    u8  Health;             // 0x8: Прочность (0-255)
    u8  Type;               // 0x9: Тип здания (BuildingType)
    u8  Flags;              // 0xA: Флаги состояния
    u8  Padding;            // 0xB: Выравнивание
    struct Building* Next;  // 0xC: Следующее здание в списке
    Rect2D CollisionBox;    // 0x10: Хитбокс (вычисляется динамически)
} Building;

/* ============================================================================
   СИСТЕМА ЧАСТИЦ (Particle)
   ----------------------------------------------------------------------------
   Эффекты: дым, огонь, искры, кровь, осколки.
   Обновляются каждый кадр, живут ограниченное время.
   Размер: ~32 байта
   ============================================================================ */

typedef enum ParticleType {
    PARTICLE_SMOKE = 0,
    PARTICLE_FIRE = 1,
    PARTICLE_SPARK = 2,
    PARTICLE_BLOOD = 3,
    PARTICLE_DEBRIS = 4,
    PARTICLE_WATER_SPLASH = 5
} ParticleType;

typedef enum ParticleFlags {
    PARTICLE_FLAG_GRAVITY = 0x01,   // Подвержена гравитации
    PARTICLE_FLAG_FADE = 0x02,      // Исчезает постепенно
    PARTICLE_FLAG_WIND = 0x04       // Подвержена ветру
} ParticleFlags;

typedef struct Particle {
    Vector2D Pos;           // 0x0: Позиция
    Vector2D Vel;           // 0x8: Скорость
    u16 LifeTime;           // 0x10: Осталось жить (кадры)
    u16 MaxLifeTime;        // 0x12: Макс. время жизни
    u16 SpriteIndex;        // 0x14: Спрайт
    u8  Type;               // 0x16: Тип частицы
    u8  Flags;              // 0x17: Флаги поведения
    u8  ColorR, ColorG, ColorB; // 0x18-0x1A: Цвет (для мультипликатора)
    u8  Size;               // 0x1B: Текущий размер (может уменьшаться)
    u8  Alpha;              // 0x1C: Прозрачность
    u8  Padding[3];         // 0x1D: Выравнивание
    struct Particle* Next;  // 0x20: Следующая частица
} Particle;

/* ============================================================================
   СПЕЦИАЛЬНЫЕ ЗОНЫ (SpecialZone)
   ----------------------------------------------------------------------------
   Зоны влияния: вода, лава, лед, триггеры миссий, камеры.
   Привязаны к координатам мира, проверяются при входе сущности.
   Размер: 24 байта
   ============================================================================ */

typedef enum ZoneType {
    ZONE_WATER = 0,         // Вода (замедление, утонуть)
    ZONE_LAVA = 1,          // Лава (мгновенный урон)
    ZONE_ICE = 2,           // Лед (скольжение)
    ZONE_OIL = 3,           // Нефть (занос)
    ZONE_TRIGGER = 4,       // Скриптовый триггер
    ZONE_CAMERA = 5,        // Смена камеры
    ZONE_SAFEHOUSE = 6,     // Домой (лечение, сохранение)
    ZONE_TELEPORT = 7       // Телепорт
} ZoneType;

typedef enum ZoneFlags {
    ZONE_FLAG_ACTIVE = 0x01,
    ZONE_FLAG_ONCE = 0x02,      // Сработать один раз
    ZONE_FLAG_DAMAGE = 0x04,    // Наносит урон
    ZONE_FLAG_SLOW = 0x08       // Замедляет
} ZoneFlags;

typedef struct SpecialZone {
    u16 X;                  // 0x0: Координата X
    u16 Y;                  // 0x2: Координата Y
    u16 Width;              // 0x4: Ширина
    u16 Height;             // 0x6: Высота
    u8  Type;               // 0x8: Тип зоны
    u8  DamagePerSec;       // 0x9: Урон в секунду
    u16 TriggerID;          // 0xA: ID для скриптов
    u32 Flags;              // 0xC: Флаги
    void* Data;             // 0x10: Доп. данные (уровень воды, ID телепорта)
    struct SpecialZone* Next; // 0x14: Следующая зона
} SpecialZone;

/* ============================================================================
   МЕНЕДЖЕР МИРА (WorldManager)
   ----------------------------------------------------------------------------
   Глобальный контейнер для всех статических объектов и эффектов.
   ============================================================================ */

#define MAX_BUILDINGS 1024
#define MAX_PARTICLES 512
#define MAX_ZONES 256

typedef struct WorldManager {
    Building* BuildingsList;    // Список зданий
    Particle* ParticlesList;    // Список активных частиц
    SpecialZone* ZonesList;     // Список зон
    
    u32 BuildingCount;
    u32 ParticleCount;
    u32 ZoneCount;
    
    // Пулы памяти (оптимизация аллокации)
    Building BuildingPool[MAX_BUILDINGS];
    Particle ParticlePool[MAX_PARTICLES];
    SpecialZone ZonePool[MAX_ZONES];
    
    u8 BuildingFreeMap[(MAX_BUILDINGS + 7) / 8]; // Битовая карта свободных слотов
    u8 ParticleFreeMap[(MAX_PARTICLES + 7) / 8];
    u8 ZoneFreeMap[(MAX_ZONES + 7) / 8];
} WorldManager;

/* ============================================================================
   ФУНКЦИИ API
   ============================================================================ */

// --- Инициализация ---
void World_Init(WorldManager* world);
void World_Clear(WorldManager* world);

// --- Здания ---
Building* World_CreateBuilding(WorldManager* world, u16 x, u16 y, u8 type, u16 sprite);
void World_DestroyBuilding(Building* bld);
void World_DamageBuilding(Building* bld, u8 damage);
bool World_IsBuildingSolid(Building* bld);

// --- Частицы ---
Particle* World_SpawnParticle(WorldManager* world, f32 x, f32 y, u8 type);
void World_UpdateParticles(WorldManager* world);
void World_ClearParticles(WorldManager* world);
void World_SetParticleWind(f32 wx, f32 wy);

// --- Зоны ---
SpecialZone* World_CreateZone(WorldManager* world, u16 x, u16 y, u16 w, u16 h, u8 type);
bool World_CheckZoneCollision(SpecialZone* zone, f32 px, f32 py, f32 pw, f32 ph);
void World_ApplyZoneEffects(WorldManager* world, struct Ped* ped, struct Car* car);

// --- Глобальный экземпляр ---
extern WorldManager g_world;

#endif // WORLD_OBJECTS_H
