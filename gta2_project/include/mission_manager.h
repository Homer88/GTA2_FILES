#ifndef MISSION_MANAGER_H
#define MISSION_MANAGER_H

#include "../types.h"
#include "mission_types.h"
#include "forward_declarations.h"

#define MAX_MISSION_OBJECTIVES 10
#define MAX_ACTIVE_MISSIONS 5
#define MAX_MISSION_SCRIPT_SIZE 256

/**
 * Структура миссии
 * Размер: ~400 байт
 */
typedef struct Mission {
    u32 Id;                         // 0x0 - Уникальный ID миссии
    MissionType Type;               // 0x4 - Тип миссии
    MissionStatus Status;           // 0x8 - Статус выполнения
    
    char Name[64];                  // 0xC - Название миссии
    char Description[256];          // 0x4C - Полное описание
    
    // Цели
    MissionObjective Objectives[MAX_MISSION_OBJECTIVES]; // 0x14C - Массив целей
    u8 ObjectiveCount;              // 0x30C - Количество целей
    u8 CurrentObjectiveIndex;       // 0x30D - Текущая активная цель
    u8 CompletedObjectives;         // 0x30E - Выполнено целей
    u8 Padding1;                    // 0x30F - Выравнивание
    
    // Награда
    s32 MoneyReward;                // 0x310 - Награда деньгами
    s32 RespectReward;              // 0x314 - Награда уважением
    u8 WeaponReward;                // 0x318 - Награда оружием (тип)
    u8 Padding2[3];                 // Выравнивание
    
    // Таймеры
    f32 TimeLimit;                  // 0x31C - Общее ограничение времени
    f32 Timer;                      // 0x320 - Текущий таймер миссии
    f32 ElapsedTime;                // 0x324 - Прошедшее время
    
    // Связи
    struct Ped* ClientPed;          // 0x328 - Заказчик (кто дал миссию)
    struct Ped* TargetPed;          // 0x32C - Цель миссии (если есть)
    struct Car* TargetCar;          // 0x330 - Цель машина (если есть)
    
    // Зоны
    f32 StartZoneX;                 // 0x334 - Зона начала миссии
    f32 StartZoneY;                 
    f32 StartZoneRadius;            
    f32 EndZoneX;                   // 0x340 - Зона завершения
    f32 EndZoneY;                   
    f32 EndZoneRadius;              
    
    // Флаги и скрипт
    u32 Flags;                      // 0x34C - Флаги миссии
    u8 ScriptData[MAX_MISSION_SCRIPT_SIZE]; // 0x350 - Данные скрипта
    u16 ScriptSize;                 // 0x450 - Размер скрипта
    u8 Priority;                    // 0x452 - Приоритет миссии
    u8 Padding3;                    // Выравнивание
} Mission;

// Флаги миссии
#define MISS_FLAG_REPEATABLE        0x01    // Можно повторить
#define MISS_FLAG_TIMED             0x02    // Ограничена по времени
#define MISS_FLAG_FAIL_ON_DEATH     0x04    // Провал при смерти игрока
#define MISS_FLAG_HIDDEN            0x08    // Скрытая миссия
#define MISS_FLAG_CUTSCENE          0x10    // Есть катсцена

/**
 * Менеджер миссий
 * Размер: ~2 КБ
 */
typedef struct MissionManager {
    Mission ActiveMissions[MAX_ACTIVE_MISSIONS];  // Активные миссии
    u8 ActiveCount;                   // Количество активных миссий
    u8 PendingCount;                  // Количество ожидающих
    u16 TotalCompleted;               // Всего выполнено за игру
    u16 TotalFailed;                  // Всего провалено
    
    Mission* CurrentMission;          // Указатель на текущую приоритетную
    void* MissionPool;                // Пул памяти для миссий
    
    // Триггеры
    u8 CheckTriggers;                 // Проверять триггеры
    u8 Padding[3];                    
    f32 TriggerCheckTimer;            // Таймер проверки триггеров
} MissionManager;

/**
 * Инициализация менеджера миссий
 * @param manager Указатель на менеджер
 */
void MissionManager_Init(MissionManager* manager);

/**
 * Обновление менеджера (каждый кадр)
 * @param manager Указатель на менеджер
 * @param dt Delta time
 */
void MissionManager_Update(MissionManager* manager, f32 dt);

/**
 * Начало новой миссии
 * @param manager Указатель на менеджер
 * @param mission Данные миссии
 * @return ID миссии или -1 если ошибка
 */
s32 MissionManager_StartMission(MissionManager* manager, Mission* mission);

/**
 * Завершение миссии
 * @param manager Указатель на менеджер
 * @param missionId ID миссии
 * @param success true если успешно, false если провал
 */
void MissionManager_EndMission(MissionManager* manager, u32 missionId, bool success);

/**
 * Обновление прогресса цели
 * @param manager Указатель на менеджер
 * @param missionId ID миссии
 * @param objectiveIndex Индекс цели
 * @param progress Новый прогресс
 */
void MissionManager_UpdateObjective(MissionManager* manager, u32 missionId, 
                                    u8 objectiveIndex, s32 progress);

/**
 * Проверка условий миссии
 * @param manager Указатель на менеджер
 * @param missionId ID миссии
 * @return true если все условия выполнены
 */
bool MissionManager_CheckCompletion(MissionManager* manager, u32 missionId);

/**
 * Получение активной миссии по ID
 * @param manager Указатель на менеджер
 * @param missionId ID миссии
 * @return Указатель на миссию или NULL
 */
Mission* MissionManager_GetMission(MissionManager* manager, u32 missionId);

/**
 * Отмена всех миссий
 * @param manager Указатель на менеджер
 */
void MissionManager_CancelAll(MissionManager* manager);

/**
 * Создание стандартной миссии убийства
 * @param mission Указатель на структуру миссии
 * @param targetPed Целевой пешеход
 * @param reward Награда деньгами
 */
void Mission_CreateKillTarget(Mission* mission, struct Ped* targetPed, s32 reward);

/**
 * Создание миссии доставки машины
 * @param mission Указатель на структуру миссии
 * @param carType Требуемый тип машины
 * @param deliverX Точка доставки X
 * @param deliverY Точка доставки Y
 * @param reward Награда
 */
void Mission_CreateDeliverCar(Mission* mission, u8 carType, 
                              f32 deliverX, f32 deliverY, s32 reward);

#endif // MISSION_MANAGER_H
