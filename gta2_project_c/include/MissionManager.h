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
// Адрес: 0x00481900, Размер: 0x2A0 (672 байта)
void MissionManager__Constructor(MissionManager* self);
// Адрес: 0x00481BA0, Размер: 0x50 (80 байт)
void MissionManager__Destructor(MissionManager* self);
// Адрес: 0x00490C30, Размер: 0x1F0 (496 байт)
void MissionManager__Reset(MissionManager* self);

// --- Управление потоком миссии ---
// Адрес: 0x00475CA0, Размер: 0x8A (138 байт)
int32_t MissionManager__StartMission(MissionManager* self, uint32_t missionId);
// Адрес: 0x00475D30, Размер: 0xD0 (208 байт)
void MissionManager__EndMission(MissionManager* self, int32_t result);
// Адрес: 0x00475E90, Размер: 0x1D3 (467 байт)
void MissionManager__FailMission(MissionManager* self);
// Адрес: 0x00476070, Размер: 0x17D (381 байт)
void MissionManager__AbortMission(MissionManager* self);
// Адрес: 0x0047F200, Размер: 0x21 (33 байта)
void MissionManager__Update(MissionManager* self);
// Адрес: 0x0047F230, Размер: 0x50 (80 байт)
void MissionManager__CheckObjectives(MissionManager* self);
// Адрес: 0x0047F340, Размер: 0x6E (110 байт)
int32_t MissionManager__IsMissionActive(MissionManager* self);
// Адрес: 0x0047F3B0, Размер: 0x6F (111 байт)
uint32_t MissionManager__GetCurrentMissionId(MissionManager* self);
// Адрес: 0x0047F420, Размер: 0x22 (34 байта)
uint32_t MissionManager__GetMissionState(MissionManager* self);
// Адрес: 0x00481200, Размер: 0x69 (105 байт)
void MissionManager__SetNextMission(MissionManager* self, uint32_t nextId);
// Адрес: 0x00481270, Размер: 0x66 (102 байта)
void MissionManager__AbortAllMissions(MissionManager* self);

// --- Работа со скриптами и файлами ---
// Адрес: 0x00481400, Размер: 0x257 (599 байт)
int32_t MissionManager__LoadScript(MissionManager* self, const char* filename);
// Адрес: 0x00481890, Размер: 0x63 (99 байт)
int32_t MissionManager__SaveFile(MissionManager* self);
// Адрес: 0x004699F0, Размер: 0x1A0 (416 байт)
int32_t MissionManager__LoadGame(MissionManager* self, const char* filename);
// Адрес: 0x00469B90, Размер: 0xC0 (192 байта)
void MissionManager__ExtractFileNameWithoutExtension(const char* fullPath, char* outName);
// Адрес: 0x00469C50, Размер: 0x2B0 (688 байт)
int32_t MissionManager__ParseScriptCommand(MissionManager* self);
// Адрес: 0x00469F00, Размер: 0x30 (48 байт)
void* MissionManager__GetMissionScript(MissionManager* self);
// Адрес: 0x00469F30, Размер: 0x150 (336 байт)
void MissionManager__InitScriptVariables(MissionManager* self);

// --- Цели и прогресс ---
// Адрес: 0x0046A080, Размер: 0x40 (64 байта)
void MissionManager__UpdateObjectives(MissionManager* self);
// Адрес: 0x0046A0C0, Размер: 0x50 (80 байт)
int32_t MissionManager__CheckCompletion(MissionManager* self);
// Адрес: 0x0046A110, Размер: 0xA0 (160 байт)
void MissionManager__GiveReward(MissionManager* self);
// Адрес: 0x0046A1B0, Размер: 0x90 (144 байта)
void MissionManager__SetObjectiveFlag(MissionManager* self, uint32_t index, int32_t completed);
// Адрес: 0x0046A240, Размер: 0x30 (48 байт)
uint32_t MissionManager__GetObjectiveCount(MissionManager* self);
// Адрес: 0x0046A270, Размер: 0x30 (48 байт)
uint32_t MissionManager__GetCompletedObjectives(MissionManager* self);
// Адрес: 0x0046A2A0, Размер: 0x80 (128 байт)
void MissionManager__ResetProgress(MissionManager* self);

// --- Управление объектами и триггерами ---
// Адрес: 0x0046A320, Размер: 0x50 (80 байт)
MissionObject* MissionManager__GetObjectPtr(MissionManager* self, uint32_t index);
// Адрес: 0x0046A370, Размер: 0x50 (80 байт)
MissionTrigger* MissionManager__GetTriggerPtr(MissionManager* self, uint32_t index);
// Адрес: 0x0046A3C0, Размер: 0x120 (288 байт)
void MissionManager__SpawnScriptObjects(MissionManager* self);
// Адрес: 0x0046A4E0, Размер: 0x60 (96 байт)
void MissionManager__DespawnObject(MissionManager* self, uint32_t objIndex);
// Адрес: 0x0046A540, Размер: 0x50 (80 байт)
void MissionManager__ActivateTrigger(MissionManager* self, uint32_t trigIndex);
// Адрес: 0x0046A590, Размер: 0xF0 (240 байт)
void MissionManager__UpdateTriggers(MissionManager* self);

// --- Внутренние утилиты и данные ---
// Адрес: 0x0046A680, Размер: 0xA0 (160 байт)
void MissionManager__ClampValues(MissionManager* self);
// Адрес: 0x0046A720, Размер: 0x30 (48 байт)
int32_t MissionManager__greater_than(MissionManager* self, int32_t a, int32_t b);
// Адрес: 0x0046A750, Размер: 0x30 (48 байт)
int32_t MissionManager__less_or_equal(MissionManager* self, int32_t a, int32_t b);
// Адрес: 0x0046A780, Размер: 0x30 (48 байт)
int32_t MissionManager__NotEqual(MissionManager* self, int32_t a, int32_t b);
// Адрес: 0x0046A7B0, Размер: 0x30 (48 байт)
int32_t MissionManager__less_than(MissionManager* self, int32_t a, int32_t b);
// Адрес: 0x0046A7E0, Размер: 0x70 (112 байт)
void MissionManager__PrepareArray(MissionManager* self);
// Адрес: 0x0046A850, Размер: 0x50 (80 байт)
void MissionManager__ClearMissionData(MissionManager* self);
// Адрес: 0x0046A8A0, Размер: 0x60 (96 байт)
void MissionManager__AllocateMissionBuffer(MissionManager* self, uint32_t size);
// Адрес: 0x0046A900, Размер: 0x40 (64 байта)
void MissionManager__FreeMissionBuffer(MissionManager* self);

// --- Сохранение и загрузка данных ---
// Адрес: 0x0046A940, Размер: 0x100 (256 байт)
void MissionManager__SaveMissionData(MissionManager* self);
// Адрес: 0x0046AA40, Размер: 0x120 (288 байт)
void MissionManager__LoadMissionData(MissionManager* self);
// Адрес: 0x0046AB60, Размер: 0x80 (128 байт)
int32_t MissionManager__IsValidMission(MissionManager* self, uint32_t missionId);

// --- События и триггеры внешнего мира ---
// Адрес: 0x0046ABE0, Размер: 0xE0 (224 байта)
void MissionManager__TriggerEvent(MissionManager* self, uint32_t eventType, void* data);
// Адрес: 0x0046ACC0, Размер: 0xA0 (160 байт)
void MissionManager__OnPlayerDeath(MissionManager* self);
// Адрес: 0x0046AD60, Размер: 0x70 (112 байт)
void MissionManager__OnCarDestroyed(MissionManager* self, uint32_t carId);
// Адрес: 0x0046ADD0, Размер: 0x70 (112 байт)
void MissionManager__OnPedKilled(MissionManager* self, uint32_t pedId);
// Адрес: 0x0046AE40, Размер: 0x90 (144 байта)
void MissionManager__OnZoneEntered(MissionManager* self, const char* zoneName);
// Адрес: 0x0046AED0, Размер: 0x60 (96 байт)
void MissionManager__OnItemCollected(MissionManager* self, uint32_t itemId);

// --- Отладка и прочее ---
// Адрес: 0x0046AF30, Размер: 0x150 (336 байт)
void MissionManager__PrintDebugInfo(MissionManager* self);
// Адрес: 0x0046B080, Размер: 0x180 (384 байта)
void MissionManager__DumpState(MissionManager* self);
// Адрес: 0x004699F0, Размер: 0x1A0 (416 байт) - псевдоним деструктора
void MissionManager__sub_4699F0(MissionManager* self);
// Адрес: 0x00490C30, Размер: 0x1F0 (496 байт) - псевдоним Reset
void MissionManager__sub_490C30(MissionManager* self);

#ifdef __cplusplus
}
#endif

#endif // MISSIONMANAGER_H

