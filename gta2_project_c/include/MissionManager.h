#ifndef MISSIONMANAGER_H
#define MISSIONMANAGER_H
#include "types.h"
#include "MissionTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

// Точный размер структуры из MAP-файла
#define MISSION_MANAGER_SIZE 0xC1EA8

// Адрес глобальной переменной из MAP-файла
#define MISSION_MANAGER_ADDR 0x006644BC

/**
 * @brief Состояния менеджера миссий
 */
typedef enum {
    MISSION_STATE_UNLOADED = 0,
    MISSION_STATE_IDLE,
    MISSION_STATE_LOADING,
    MISSION_STATE_RUNNING,
    MISSION_STATE_PAUSED,
    MISSION_STATE_ENDED,
    MISSION_STATE_FAILED
} MissionState;

/**
 * @brief Основная структура MissionManager
 * Размер: 0xC1EA8 (793,768 байт)
 * Адрес глобального экземпляра: 0x006644BC
 * 
 * Отвечает за загрузку, выполнение и сохранение миссий.
 * Содержит скриптовый движок, пулы объектов и триггеров.
 */
typedef struct {
    // === Блок состояния (0x00 - 0x20) ===
    uint32_t state;                     // 0x00: Текущее состояние (MissionState)
    uint32_t current_mission_id;        // 0x04: ID текущей активной миссии
    uint32_t mission_status;            // 0x08: Статус выполнения (0=None, 1=Success, 2=Failed)
    uint32_t total_objectives;          // 0x0C: Общее количество целей в текущей миссии
    uint32_t completed_objectives;      // 0x10: Количество выполненных целей
    void* script_buffer_ptr;            // 0x14: Указатель на загруженный буфер скрипта
    uint32_t script_size;               // 0x18: Размер загруженного скрипта в байтах
    uint32_t script_cursor;             // 0x1C: Текущая позиция чтения в скрипте
    
    // === Буферы путей (0x20 - 0x220) ===
    char current_script_path[256];      // 0x20: Путь к текущему файлу скрипта миссии
    char save_file_path[256];           // 0x120: Путь к файлу сохранения
    
    // === Таймеры и награды (0x220 - 0x230) ===
    uint32_t timer_main;                // 0x220: Главный таймер миссии
    uint32_t timer_secondary;           // 0x224: Вторичный таймер для конкретных целей
    float reward_money;                 // 0x228: Сумма награды за текущую миссию
    uint32_t reward_respect;            // 0x22C: Очки уважения/репутации за миссию
    
    // === Флаги целей (0x230 - 0x630) ===
    uint8_t objectives_flags[1024];     // 0x230: Битовая маска выполнения целей (до 8192 целей)
    
    // === Внутренние буферы (0x630 - 0x1630) ===
    uint8_t mission_data_buffer[4096];  // 0x630: Буфер для временных данных миссии
    
    // === Основной текстовый буфер скрипта (0x1630 - 0x11630) ===
    char script_text_buffer[65536];     // 0x1630: Сырой текст скрипта миссии после загрузки
    
    // === Пул объектов миссии (0x11630 - 0x91630) ===
    // ~524288 байт / sizeof(MissionObject) ≈ 4096 объектов (если размер 128 байт)
    MissionObject objects_pool[MAX_MISSION_OBJECTS]; 
    
    // === Пул триггеров (0x91630 - 0xC1630) ===
    // ~200000 байт / sizeof(MissionTrigger) ≈ 3125 триггеров (если размер 64 байта)
    MissionTrigger triggers_pool[MAX_MISSION_TRIGGERS];
    
    // === Зарезервировано / Выравнивание (0xC1630 - 0xC1EA8) ===
    uint8_t reserved[0xC1EA8 - 0xC1630 - (sizeof(MissionObject) * MAX_MISSION_OBJECTS) - (sizeof(MissionTrigger) * MAX_MISSION_TRIGGERS)];
    
} MissionManager;

// Глобальная переменная (экземпляр менеджера)
extern MissionManager gMissionManager;
extern MissionManager* pMissionManager; // Указатель для удобного доступа

// ============================================================================
// МЕТОДЫ МИССИОННОГО МЕНЕДЖЕРА (71 функция)
// ============================================================================

// --- Инициализация и жизненный цикл ---
void MissionManager__Constructor(MissionManager* self);
void MissionManager__Destructor(MissionManager* self);
void MissionManager__Reset(MissionManager* self);

// --- Управление потоком миссии ---
int32_t MissionManager__StartMission(MissionManager* self, uint32_t missionId);
void MissionManager__EndMission(MissionManager* self, int32_t result);
void MissionManager__FailMission(MissionManager* self);
void MissionManager__AbortMission(MissionManager* self);
void MissionManager__Update(MissionManager* self);
void MissionManager__CheckObjectives(MissionManager* self);
int32_t MissionManager__IsMissionActive(MissionManager* self);
uint32_t MissionManager__GetCurrentMissionId(MissionManager* self);
uint32_t MissionManager__GetMissionState(MissionManager* self);
void MissionManager__SetNextMission(MissionManager* self, uint32_t nextId);
void MissionManager__AbortAllMissions(MissionManager* self);

// --- Работа со скриптами и файлами ---
int32_t MissionManager__LoadScript(MissionManager* self, const char* filename);
int32_t MissionManager__SaveFile(MissionManager* self);
int32_t MissionManager__LoadGame(MissionManager* self, const char* filename);
void MissionManager__ExtractFileNameWithoutExtension(const char* fullPath, char* outName);
int32_t MissionManager__ParseScriptCommand(MissionManager* self);
void* MissionManager__GetMissionScript(MissionManager* self);
void MissionManager__InitScriptVariables(MissionManager* self);

// --- Цели и прогресс ---
void MissionManager__UpdateObjectives(MissionManager* self);
int32_t MissionManager__CheckCompletion(MissionManager* self);
void MissionManager__GiveReward(MissionManager* self);
void MissionManager__SetObjectiveFlag(MissionManager* self, uint32_t index, int32_t completed);
uint32_t MissionManager__GetObjectiveCount(MissionManager* self);
uint32_t MissionManager__GetCompletedObjectives(MissionManager* self);
void MissionManager__ResetProgress(MissionManager* self);

// --- Управление объектами и триггерами ---
MissionObject* MissionManager__GetObjectPtr(MissionManager* self, uint32_t index);
MissionTrigger* MissionManager__GetTriggerPtr(MissionManager* self, uint32_t index);
void MissionManager__SpawnScriptObjects(MissionManager* self);
void MissionManager__DespawnObject(MissionManager* self, uint32_t objIndex);
void MissionManager__ActivateTrigger(MissionManager* self, uint32_t trigIndex);
void MissionManager__UpdateTriggers(MissionManager* self);

// --- Внутренние утилиты и данные ---
void MissionManager__ClampValues(MissionManager* self);
int32_t MissionManager__greater_than(MissionManager* self, int32_t a, int32_t b);
int32_t MissionManager__less_or_equal(MissionManager* self, int32_t a, int32_t b);
int32_t MissionManager__NotEqual(MissionManager* self, int32_t a, int32_t b);
int32_t MissionManager__less_than(MissionManager* self, int32_t a, int32_t b);
void MissionManager__PrepareArray(MissionManager* self);
void MissionManager__ClearMissionData(MissionManager* self);
void MissionManager__AllocateMissionBuffer(MissionManager* self, uint32_t size);
void MissionManager__FreeMissionBuffer(MissionManager* self);

// --- Сохранение и загрузка данных ---
void MissionManager__SaveMissionData(MissionManager* self);
void MissionManager__LoadMissionData(MissionManager* self);
int32_t MissionManager__IsValidMission(MissionManager* self, uint32_t missionId);

// --- События и триггеры внешнего мира ---
void MissionManager__TriggerEvent(MissionManager* self, uint32_t eventType, void* data);
void MissionManager__OnPlayerDeath(MissionManager* self);
void MissionManager__OnCarDestroyed(MissionManager* self, uint32_t carId);
void MissionManager__OnPedKilled(MissionManager* self, uint32_t pedId);
void MissionManager__OnZoneEntered(MissionManager* self, const char* zoneName);
void MissionManager__OnItemCollected(MissionManager* self, uint32_t itemId);

// --- Отладка и прочее ---
void MissionManager__PrintDebugInfo(MissionManager* self);
void MissionManager__DumpState(MissionManager* self);
void MissionManager__sub_4699F0(MissionManager* self); // Destructor alias
void MissionManager__sub_490C30(MissionManager* self); // Reset alias
// ... остальные методы sub_XXXXXXXX будут добавлены по мере анализа ...

#ifdef __cplusplus
}
#endif

#endif // MISSIONMANAGER_H

