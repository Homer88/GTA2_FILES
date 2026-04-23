#ifndef MISSIONMANAGER_H
#define MISSIONMANAGER_H
     4	#include "types.h"
     5	#include "MissionTypes.h"
     6	
     7	#ifdef __cplusplus
     8	extern "C" {
     9	#endif
    10	
    11	// Точный размер структуры из MAP-файла
    12	#define MISSION_MANAGER_SIZE 0xC1EA8
    13	
    14	// Адрес глобальной переменной из MAP-файла
    15	#define MISSION_MANAGER_ADDR 0x006644BC
    16	
    17	/**
    18	 * @brief Состояния менеджера миссий
    19	 */
    20	typedef enum {
    21	    MISSION_STATE_UNLOADED = 0,
    22	    MISSION_STATE_IDLE,
    23	    MISSION_STATE_LOADING,
    24	    MISSION_STATE_RUNNING,
    25	    MISSION_STATE_PAUSED,
    26	    MISSION_STATE_ENDED,
    27	    MISSION_STATE_FAILED
    28	} MissionState;
    29	
    30	/**
    31	 * @brief Основная структура MissionManager
    32	 * Размер: 0xC1EA8 (793,768 байт)
    33	 * Адрес глобального экземпляра: 0x006644BC
    34	 * 
    35	 * Отвечает за загрузку, выполнение и сохранение миссий.
    36	 * Содержит скриптовый движок, пулы объектов и триггеров.
    37	 */
    38	typedef struct {
    39	    // === Блок состояния (0x00 - 0x20) ===
    40	    uint32_t state;                     // 0x00: Текущее состояние (MissionState)
    41	    uint32_t current_mission_id;        // 0x04: ID текущей активной миссии
    42	    uint32_t mission_status;            // 0x08: Статус выполнения (0=None, 1=Success, 2=Failed)
    43	    uint32_t total_objectives;          // 0x0C: Общее количество целей в текущей миссии
    44	    uint32_t completed_objectives;      // 0x10: Количество выполненных целей
    45	    void* script_buffer_ptr;            // 0x14: Указатель на загруженный буфер скрипта
    46	    uint32_t script_size;               // 0x18: Размер загруженного скрипта в байтах
    47	    uint32_t script_cursor;             // 0x1C: Текущая позиция чтения в скрипте
    48	    
    49	    // === Буферы путей (0x20 - 0x220) ===
    50	    char current_script_path[256];      // 0x20: Путь к текущему файлу скрипта миссии
    51	    char save_file_path[256];           // 0x120: Путь к файлу сохранения
    52	    
    53	    // === Таймеры и награды (0x220 - 0x230) ===
    54	    uint32_t timer_main;                // 0x220: Главный таймер миссии
    55	    uint32_t timer_secondary;           // 0x224: Вторичный таймер для конкретных целей
    56	    float reward_money;                 // 0x228: Сумма награды за текущую миссию
    57	    uint32_t reward_respect;            // 0x22C: Очки уважения/репутации за миссию
    58	    
    59	    // === Флаги целей (0x230 - 0x630) ===
    60	    uint8_t objectives_flags[1024];     // 0x230: Битовая маска выполнения целей (до 8192 целей)
    61	    
    62	    // === Внутренние буферы (0x630 - 0x1630) ===
    63	    uint8_t mission_data_buffer[4096];  // 0x630: Буфер для временных данных миссии
    64	    
    65	    // === Основной текстовый буфер скрипта (0x1630 - 0x11630) ===
    66	    char script_text_buffer[65536];     // 0x1630: Сырой текст скрипта миссии после загрузки
    67	    
    68	    // === Пул объектов миссии (0x11630 - 0x91630) ===
    69	    // ~524288 байт / sizeof(MissionObject) ≈ 4096 объектов (если размер 128 байт)
    70	    MissionObject objects_pool[MAX_MISSION_OBJECTS]; 
    71	    
    72	    // === Пул триггеров (0x91630 - 0xC1630) ===
    73	    // ~200000 байт / sizeof(MissionTrigger) ≈ 3125 триггеров (если размер 64 байта)
    74	    MissionTrigger triggers_pool[MAX_MISSION_TRIGGERS];
    75	    
    76	    // === Зарезервировано / Выравнивание (0xC1630 - 0xC1EA8) ===
    77	    uint8_t reserved[0xC1EA8 - 0xC1630 - (sizeof(MissionObject) * MAX_MISSION_OBJECTS) - (sizeof(MissionTrigger) * MAX_MISSION_TRIGGERS)];
    78	    
    79	} MissionManager;
    80	
    81	// Глобальная переменная (экземпляр менеджера)
    82	extern MissionManager gMissionManager;
    83	extern MissionManager* pMissionManager; // Указатель для удобного доступа
    84	
    85	// ============================================================================
    86	// МЕТОДЫ МИССИОННОГО МЕНЕДЖЕРА (71 функция)
    87	// ============================================================================
    88	
    89	// --- Инициализация и жизненный цикл ---
    90	void MissionManager__Constructor(MissionManager* self);
    91	void MissionManager__Destructor(MissionManager* self);
    92	void MissionManager__Reset(MissionManager* self);
    93	
    94	// --- Управление потоком миссии ---
    95	int32_t MissionManager__StartMission(MissionManager* self, uint32_t missionId);
    96	void MissionManager__EndMission(MissionManager* self, int32_t result);
    97	void MissionManager__FailMission(MissionManager* self);
    98	void MissionManager__AbortMission(MissionManager* self);
    99	void MissionManager__Update(MissionManager* self);
   100	void MissionManager__CheckObjectives(MissionManager* self);
   101	int32_t MissionManager__IsMissionActive(MissionManager* self);
   102	uint32_t MissionManager__GetCurrentMissionId(MissionManager* self);
   103	uint32_t MissionManager__GetMissionState(MissionManager* self);
   104	void MissionManager__SetNextMission(MissionManager* self, uint32_t nextId);
   105	void MissionManager__AbortAllMissions(MissionManager* self);
   106	
   107	// --- Работа со скриптами и файлами ---
   108	int32_t MissionManager__LoadScript(MissionManager* self, const char* filename);
   109	int32_t MissionManager__SaveFile(MissionManager* self);
   110	int32_t MissionManager__LoadGame(MissionManager* self, const char* filename);
   111	void MissionManager__ExtractFileNameWithoutExtension(const char* fullPath, char* outName);
   112	int32_t MissionManager__ParseScriptCommand(MissionManager* self);
   113	void* MissionManager__GetMissionScript(MissionManager* self);
   114	void MissionManager__InitScriptVariables(MissionManager* self);
   115	
   116	// --- Цели и прогресс ---
   117	void MissionManager__UpdateObjectives(MissionManager* self);
   118	int32_t MissionManager__CheckCompletion(MissionManager* self);
   119	void MissionManager__GiveReward(MissionManager* self);
   120	void MissionManager__SetObjectiveFlag(MissionManager* self, uint32_t index, int32_t completed);
   121	uint32_t MissionManager__GetObjectiveCount(MissionManager* self);
   122	uint32_t MissionManager__GetCompletedObjectives(MissionManager* self);
   123	void MissionManager__ResetProgress(MissionManager* self);
   124	
   125	// --- Управление объектами и триггерами ---
   126	MissionObject* MissionManager__GetObjectPtr(MissionManager* self, uint32_t index);
   127	MissionTrigger* MissionManager__GetTriggerPtr(MissionManager* self, uint32_t index);
   128	void MissionManager__SpawnScriptObjects(MissionManager* self);
   129	void MissionManager__DespawnObject(MissionManager* self, uint32_t objIndex);
   130	void MissionManager__ActivateTrigger(MissionManager* self, uint32_t trigIndex);
   131	void MissionManager__UpdateTriggers(MissionManager* self);
   132	
   133	// --- Внутренние утилиты и данные ---
   134	void MissionManager__ClampValues(MissionManager* self);
   135	int32_t MissionManager__greater_than(MissionManager* self, int32_t a, int32_t b);
   136	int32_t MissionManager__less_or_equal(MissionManager* self, int32_t a, int32_t b);
   137	int32_t MissionManager__NotEqual(MissionManager* self, int32_t a, int32_t b);
   138	int32_t MissionManager__less_than(MissionManager* self, int32_t a, int32_t b);
   139	void MissionManager__PrepareArray(MissionManager* self);
   140	void MissionManager__ClearMissionData(MissionManager* self);
   141	void MissionManager__AllocateMissionBuffer(MissionManager* self, uint32_t size);
   142	void MissionManager__FreeMissionBuffer(MissionManager* self);
   143	
   144	// --- Сохранение и загрузка данных ---
   145	void MissionManager__SaveMissionData(MissionManager* self);
   146	void MissionManager__LoadMissionData(MissionManager* self);
   147	int32_t MissionManager__IsValidMission(MissionManager* self, uint32_t missionId);
   148	
   149	// --- События и триггеры внешнего мира ---
   150	void MissionManager__TriggerEvent(MissionManager* self, uint32_t eventType, void* data);
   151	void MissionManager__OnPlayerDeath(MissionManager* self);
   152	void MissionManager__OnCarDestroyed(MissionManager* self, uint32_t carId);
   153	void MissionManager__OnPedKilled(MissionManager* self, uint32_t pedId);
   154	void MissionManager__OnZoneEntered(MissionManager* self, const char* zoneName);
   155	void MissionManager__OnItemCollected(MissionManager* self, uint32_t itemId);
   156	
   157	// --- Отладка и прочее ---
   158	void MissionManager__PrintDebugInfo(MissionManager* self);
   159	void MissionManager__DumpState(MissionManager* self);
   160	void MissionManager__sub_4699F0(MissionManager* self); // Destructor alias
   161	void MissionManager__sub_490C30(MissionManager* self); // Reset alias
   162	// ... остальные методы sub_XXXXXXXX будут добавлены по мере анализа ...
   163	
   164	#ifdef __cplusplus
   165	}
   166	#endif
   167	
   168	#endif // MISSIONMANAGER_H
   169	
