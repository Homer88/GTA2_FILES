// Структура: GameObject
// Оригинал: S6
// Размер: ~105 байт

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

// Structure definition for S6
// Found in original gta2.exe.h

S6 {
    struct S46 *Pool;
    undefined4 ObjectId;
    undefined4 ModelId;
    struct CarDoor S7[4];
    struct Car *Car;
    struct SpriteS1 *s38;
    undefined4 Health;
    undefined4 MaxHealth;
    undefined4 Armor;
    undefined4 Speed;
    undefined4 Mass;
    undefined *CollisionData;
    undefined4 PhysicsFlags;
    undefined4 BehaviorFlags;
    undefined2 AnimationId;
    undefined2 AnimationFrame;
    undefined2 AnimationSpeed;
    undefined AnimLoop;
    undefined AnimBlend;
    undefined4 ScriptRef;
    undefined1 AIState;
    undefined AISubState;
    undefined AITarget;
    undefined AITimer;
    byte AIFlags;
    undefined PathNode;
    undefined RouteId;
    undefined FormationSlot;
    undefined4 WeaponId;
    undefined1 AmmoCount;
    undefined1 WeaponState;
    undefined1 FireMode;
    undefined ReloadTimer;
    undefined4 DamageTaken;
    undefined1 LastDamageType;
    undefined1 LastAttacker;
    undefined InvulnTimer;
    undefined RespawnDelay;
    undefined4 SpawnX;
    undefined4 SpawnY;
    undefined4 SpawnZ;
    undefined1 SpawnAngle;
    undefined1 SpawnFlags;
    undefined1 DespawnDist;
    byte _byte;
    undefined LodDistance;
    undefined CullDistance;
    undefined ShadowType;
    undefined LightType;
    undefined SoundType;
    undefined ParticleType;
    undefined DecalType;
    undefined EffectFlags;
    undefined4 UpdateTime;
    undefined4 LastUpdate;
    undefined NetworkId;
    undefined SyncFlags;
    undefined RpcCount;
    undefined Priority;
};

#endif // GAMEOBJECT_H
