 1	/**
     2	 * @file MissionManager.c
     3	 * @brief Реализация менеджера миссий GTA 2
     4	 * 
     5	 * Размер структуры: 0xC1EA8 (793,768 байт)
     6	 * Адрес глобального экземпляра: 0x006644BC
     7	 */
     8	
     9	#include "MissionManager.h"
    10	#include <string.h>
    11	#include <stdlib.h>
    12	
    13	// Глобальный экземпляр менеджера миссий
    14	MissionManager gMissionManager;
    15	MissionManager* pMissionManager = &gMissionManager;
    16	
    17	// ============================================================================
    18	// ВНУТРЕННИЕ ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ
    19	// ============================================================================
    20	
    21	/**
    22	 * @brief Внутренняя функция очистки пула объектов
    23	 */
    24	static void ClearObjectPool(MissionManager* self) {
    25	    for (int i = 0; i < MAX_MISSION_OBJECTS; i++) {
    26	        self->objects_pool[i].type = MISSION_OBJ_NONE;
    27	        self->objects_pool[i].is_active = 0;
    28	        self->objects_pool[i].flags = 0;
    29	    }
    30	}
    31	
    32	/**
    33	 * @brief Внутренняя функция очистки пула триггеров
    34	 */
    35	static void ClearTriggerPool(MissionManager* self) {
    36	    for (int i = 0; i < MAX_MISSION_TRIGGERS; i++) {
    37	        self->triggers_pool[i].type = TRIGGER_NONE;
    38	        self->triggers_pool[i].state = 0;
    39	    }
    40	}
    41	
    42	/**
    43	 * @brief Проверка границ индекса объекта
    44	 */
    45	static int IsValidObjectIndex(MissionManager* self, uint32_t index) {
    46	    return (index < MAX_MISSION_OBJECTS && self->objects_pool[index].type != MISSION_OBJ_NONE);
    47	}
    48	
    49	/**
    50	 * @brief Проверка границ индекса триггера
    51	 */
    52	static int IsValidTriggerIndex(MissionManager* self, uint32_t index) {
    53	    return (index < MAX_MISSION_TRIGGERS && self->triggers_pool[index].type != TRIGGER_NONE);
    54	}
    55	
    56	// ============================================================================
    57	// ИНИЦИАЛИЗАЦИЯ И ЖИЗНЕННЫЙ ЦИКЛ
    58	// ============================================================================
    59	
    60	void MissionManager__Constructor(MissionManager* self) {
    61	    if (!self) return;
    62	    
    63	    // Полное обнуление структуры
    64	    memset(self, 0, sizeof(MissionManager));
    65	    
    66	    // Установка начального состояния
    67	    self->state = MISSION_STATE_UNLOADED;
    68	    self->current_mission_id = 0xFFFFFFFF;
    69	    self->mission_status = 0;
    70	    
    71	    // Инициализация указателей
    72	    self->script_buffer_ptr = NULL;
    73	    self->script_size = 0;
    74	    self->script_cursor = 0;
    75	    
    76	    // Очистка пулов
    77	    ClearObjectPool(self);
    78	    ClearTriggerPool(self);
    79	    
    80	    // Инициализация путей пустыми строками
    81	    self->current_script_path[0] = '\0';
    82	    self->save_file_path[0] = '\0';
    83	}
    84	
    85	void MissionManager__Destructor(MissionManager* self) {
    86	    if (!self) return;
    87	    
    88	    // Освобождение буфера скрипта если выделен
    89	    if (self->script_buffer_ptr) {
    90	        free(self->script_buffer_ptr);
    91	        self->script_buffer_ptr = NULL;
    92	    }
    93	    
    94	    // Сброс состояния
    95	    self->state = MISSION_STATE_UNLOADED;
    96	    self->script_size = 0;
    97	    self->script_cursor = 0;
    98	    
    99	    // Очистка пулов
   100	    ClearObjectPool(self);
   101	    ClearTriggerPool(self);
   102	}
   103	
   104	void MissionManager__Reset(MissionManager* self) {
   105	    if (!self) return;
   106	    
   107	    // Сброс состояния миссии, но не освобождение глобальных ресурсов
   108	    self->state = MISSION_STATE_IDLE;
   109	    self->current_mission_id = 0xFFFFFFFF;
   110	    self->mission_status = 0;
   111	    self->total_objectives = 0;
   112	    self->completed_objectives = 0;
   113	    
   114	    // Сброс курсора скрипта
   115	    self->script_cursor = 0;
   116	    
   117	    // Сброс таймеров
   118	    self->timer_main = 0;
   119	    self->timer_secondary = 0;
   120	    
   121	    // Сброс наград
   122	    self->reward_money = 0.0f;
   123	    self->reward_respect = 0;
   124	    
   125	    // Очистка флагов целей
   126	    memset(self->objectives_flags, 0, sizeof(self->objectives_flags));
   127	    
   128	    // Очистка пулов
   129	    ClearObjectPool(self);
   130	    ClearTriggerPool(self);
   131	}
   132	
   133	// ============================================================================
   134	// УПРАВЛЕНИЕ ПОТОКОМ МИССИИ
   135	// ============================================================================
   136	
   137	int32_t MissionManager__StartMission(MissionManager* self, uint32_t missionId) {
   138	    if (!self) return -1;
   139	    
   140	    // Если уже запущена миссия - прерываем её
   141	    if (self->state == MISSION_STATE_RUNNING) {
   142	        MissionManager__AbortMission(self);
   143	    }
   144	    
   145	    // Установка ID миссии
   146	    self->current_mission_id = missionId;
   147	    
   148	    // Формирование имени файла скрипта (например, "mission_05.scr")
   149	    char scriptName[64];
   150	    snprintf(scriptName, sizeof(scriptName), "mission_%02d.scr", missionId);
   151	    
   152	    // Загрузка скрипта
   153	    if (MissionManager__LoadScript(self, scriptName) != 0) {
   154	        return -1; // Ошибка загрузки
   155	    }
   156	    
   157	    // Сброс прогресса
   158	    MissionManager__ResetProgress(self);
   159	    
   160	    // Переход в состояние выполнения
   161	    self->state = MISSION_STATE_RUNNING;
   162	    
   163	    // Спавн стартовых объектов
   164	    MissionManager__SpawnScriptObjects(self);
   165	    
   166	    return 0;
   167	}
   168	
   169	void MissionManager__EndMission(MissionManager* self, int32_t result) {
   170	    if (!self) return;
   171	    
   172	    // Остановка скрипта
   173	    self->script_cursor = self->script_size;
   174	    
   175	    if (result == 1) { // Успех
   176	        self->mission_status = 1;
   177	        
   178	        // Выдача награды
   179	        MissionManager__GiveReward(self);
   180	        
   181	        // Сохранение прогресса
   182	        MissionManager__SaveFile(self);
   183	        
   184	        // TODO: Показать сообщение об успехе
   185	    } else { // Провал
   186	        self->mission_status = 2;
   187	        
   188	        // Сброс наград
   189	        self->reward_money = 0.0f;
   190	        self->reward_respect = 0;
   191	        
   192	        // TODO: Показать сообщение о провале
   193	    }
   194	    
   195	    // Переход в завершенное состояние
   196	    self->state = MISSION_STATE_ENDED;
   197	}
   198	
   199	void MissionManager__FailMission(MissionManager* self) {
   200	    MissionManager__EndMission(self, 0);
   201	}
   202	
   203	void MissionManager__AbortMission(MissionManager* self) {
   204	    if (!self) return;
   205	    
   206	    // Деспавн всех объектов миссии
   207	    for (uint32_t i = 0; i < MAX_MISSION_OBJECTS; i++) {
   208	        if (self->objects_pool[i].is_active) {
   209	            MissionManager__DespawnObject(self, i);
   210	        }
   211	    }
   212	    
   213	    // Сброс состояния
   214	    self->state = MISSION_STATE_IDLE;
   215	    self->mission_status = 0;
   216	}
   217	
   218	void MissionManager__Update(MissionManager* self) {
   219	    if (!self || self->state != MISSION_STATE_RUNNING) return;
   220	    
   221	    // Инкремент таймеров
   222	    self->timer_main++;
   223	    self->timer_secondary++;
   224	    
   225	    // Обработка команд скрипта
   226	    MissionManager__ParseScriptCommand(self);
   227	    
   228	    // Проверка целей
   229	    MissionManager__CheckObjectives(self);
   230	    
   231	    // Обновление триггеров
   232	    MissionManager__UpdateTriggers(self);
   233	}
   234	
   235	void MissionManager__CheckObjectives(MissionManager* self) {
   236	    if (!self) return;
   237	    
   238	    // Подсчет выполненных целей по битовой маске
   239	    uint32_t completed = 0;
   240	    uint32_t totalBits = self->total_objectives;
   241	    
   242	    for (uint32_t i = 0; i < totalBits && i < 8192; i++) {
   243	        uint32_t byteIndex = i / 8;
   244	        uint32_t bitIndex = i % 8;
   245	        if (self->objectives_flags[byteIndex] & (1 << bitIndex)) {
   246	            completed++;
   247	        }
   248	    }
   249	    
   250	    self->completed_objectives = completed;
   251	    
   252	    // Проверка завершения миссии
   253	    if (completed >= self->total_objectives && self->total_objectives > 0) {
   254	        MissionManager__EndMission(self, 1);
   255	    }
   256	}
   257	
   258	int32_t MissionManager__IsMissionActive(MissionManager* self) {
   259	    return (self && self->state == MISSION_STATE_RUNNING) ? 1 : 0;
   260	}
   261	
   262	uint32_t MissionManager__GetCurrentMissionId(MissionManager* self) {
   263	    return self ? self->current_mission_id : 0xFFFFFFFF;
   264	}
   265	
   266	uint32_t MissionManager__GetMissionState(MissionManager* self) {
   267	    return self ? self->state : MISSION_STATE_UNLOADED;
   268	}
   269	
   270	void MissionManager__SetNextMission(MissionManager* self, uint32_t nextId) {
   271	    if (!self) return;
   272	    // Логика установки следующей миссии (может вызываться после завершения текущей)
   273	    self->current_mission_id = nextId;
   274	}
   275	
   276	void MissionManager__AbortAllMissions(MissionManager* self) {
   277	    MissionManager__AbortMission(self);
   278	    // Дополнительная очистка если нужно
   279	}
   280	
   281	// ============================================================================
   282	// РАБОТА СО СКРИПТАМИ И ФАЙЛАМИ
   283	// ============================================================================
   284	
   285	int32_t MissionManager__LoadScript(MissionManager* self, const char* filename) {
   286	    if (!self || !filename) return -1;
   287	    
   288	    // Формирование полного пути
   289	    // TODO: Использовать правильный путь к директории скриптов
   290	    strncpy(self->current_script_path, filename, sizeof(self->current_script_path) - 1);
   291	    self->current_script_path[sizeof(self->current_script_path) - 1] = '\0';
   292	    
   293	    // Открытие файла и чтение
   294	    // В реальной реализации здесь будет fopen/fread
   295	    // Для заглушки просто помечаем как загруженный
   296	    
   297	    self->script_size = 0; // Будет установлено при реальном чтении
   298	    self->script_cursor = 0;
   299	    self->state = MISSION_STATE_LOADED;
   300	    
   301	    return 0;
   302	}
   303	
   304	int32_t MissionManager__SaveFile(MissionManager* self) {
   305	    if (!self) return -1;
   306	    
   307	    // Сериализация ключевых данных
   308	    // В реальной реализации: fopen/fwrite структур состояния
   309	    
   310	    // Сохраняемые данные:
   311	    // - current_mission_id
   312	    // - objectives_flags
   313	    // - timer_main
   314	    // - reward_money/respect
   315	    
   316	    return 0;
   317	}
   318	
   319	int32_t MissionManager__LoadGame(MissionManager* self, const char* filename) {
   320	    if (!self || !filename) return -1;
   321	    
   322	    strncpy(self->save_file_path, filename, sizeof(self->save_file_path) - 1);
   323	    
   324	    // Загрузка данных сохранения
   325	    // TODO: Реализовать десериализацию
   326	    
   327	    return 0;
   328	}
   329	
   330	void MissionManager__ExtractFileNameWithoutExtension(const char* fullPath, char* outName) {
   331	    if (!fullPath || !outName) return;
   332	    
   333	    const char* lastSlash = strrchr(fullPath, '/');
   334	    const char* lastBackslash = strrchr(fullPath, '\\');
   335	    const char* fileName = (lastSlash > lastBackslash) ? lastSlash : lastBackslash;
   336	    fileName = fileName ? fileName + 1 : fullPath;
   337	    
   338	    strncpy(outName, fileName, 255);
   339	    outName[255] = '\0';
   340	    
   341	    // Удаление расширения
   342	    char* dot = strrchr(outName, '.');
   343	    if (dot) *dot = '\0';
   344	}
   345	
   346	int32_t MissionManager__ParseScriptCommand(MissionManager* self) {
   347	    if (!self || !self->script_text_buffer) return -1;
   348	    
   349	    // Чтение команды из буфера начиная с script_cursor
   350	    // Парсинг аргументов
   351	    // Выполнение команды
   352	    
   353	    // Пример псевдокода:
   354	    // char* line = GetLine(self->script_text_buffer + self->script_cursor);
   355	    // if (strcmp(line, "CREATE_CAR") == 0) { ... }
   356	    // else if (strcmp(line, "SET_OBJECTIVE") == 0) { ... }
   357	    
   358	    return 0;
   359	}
   360	
   361	void* MissionManager__GetMissionScript(MissionManager* self) {
   362	    return self ? self->script_buffer_ptr : NULL;
   363	}
   364	
   365	void MissionManager__InitScriptVariables(MissionManager* self) {
   366	    if (!self) return;
   367	    // Инициализация переменных скрипта по умолчанию
   368	}
   369	
   370	// ============================================================================
   371	// ЦЕЛИ И ПРОГРЕСС
   372	// ============================================================================
   373	
   374	void MissionManager__UpdateObjectives(MissionManager* self) {
   375	    MissionManager__CheckObjectives(self);
   376	}
   377	
   378	int32_t MissionManager__CheckCompletion(MissionManager* self) {
   379	    if (!self) return 0;
   380	    return (self->completed_objectives >= self->total_objectives) ? 1 : 0;
   381	}
   382	
   383	void MissionManager__GiveReward(MissionManager* self) {
   384	    if (!self) return;
   385	    
   386	    // TODO: Вызов функций добавления денег и репутации игроку
   387	    // PlayerAddMoney(self->reward_money);
   388	    // PlayerAddRespect(self->reward_respect);
   389	}
   390	
   391	void MissionManager__SetObjectiveFlag(MissionManager* self, uint32_t index, int32_t completed) {
   392	    if (!self || index >= 8192) return;
   393	    
   394	    uint32_t byteIndex = index / 8;
   395	    uint32_t bitIndex = index % 8;
   396	    
   397	    if (completed) {
   398	        self->objectives_flags[byteIndex] |= (1 << bitIndex);
   399	    } else {
   400	        self->objectives_flags[byteIndex] &= ~(1 << bitIndex);
   401	    }
   402	}
   403	
   404	uint32_t MissionManager__GetObjectiveCount(MissionManager* self) {
   405	    return self ? self->total_objectives : 0;
   406	}
   407	
   408	uint32_t MissionManager__GetCompletedObjectives(MissionManager* self) {
   409	    return self ? self->completed_objectives : 0;
   410	}
   411	
   412	void MissionManager__ResetProgress(MissionManager* self) {
   413	    if (!self) return;
   414	    
   415	    self->completed_objectives = 0;
   416	    memset(self->objectives_flags, 0, sizeof(self->objectives_flags));
   417	    self->timer_main = 0;
   418	    self->timer_secondary = 0;
   419	}
   420	
   421	// ============================================================================
   422	// УПРАВЛЕНИЕ ОБЪЕКТАМИ И ТРИГГЕРАМИ
   423	// ============================================================================
   424	
   425	MissionObject* MissionManager__GetObjectPtr(MissionManager* self, uint32_t index) {
   426	    if (!self || index >= MAX_MISSION_OBJECTS) return NULL;
   427	    return &self->objects_pool[index];
   428	}
   429	
   430	MissionTrigger* MissionManager__GetTriggerPtr(MissionManager* self, uint32_t index) {
   431	    if (!self || index >= MAX_MISSION_TRIGGERS) return NULL;
   432	    return &self->triggers_pool[index];
   433	}
   434	
   435	void MissionManager__SpawnScriptObjects(MissionManager* self) {
   436	    if (!self) return;
   437	    
   438	    // Проход по пулу объектов и спавн активных
   439	    for (uint32_t i = 0; i < MAX_MISSION_OBJECTS; i++) {
   440	        MissionObject* obj = &self->objects_pool[i];
   441	        if (obj->is_active && obj->type != MISSION_OBJ_NONE) {
   442	            // TODO: Вызов соответствующих функций спавна
   443	            // if (obj->type == MISSION_OBJ_CAR) SpawnCar(...);
   444	            // if (obj->type == MISSION_OBJ_PED) SpawnPed(...);
   445	        }
   446	    }
   447	}
   448	
   449	void MissionManager__DespawnObject(MissionManager* self, uint32_t objIndex) {
   450	    if (!self || objIndex >= MAX_MISSION_OBJECTS) return;
   451	    
   452	    MissionObject* obj = &self->objects_pool[objIndex];
   453	    obj->is_active = 0;
   454	    obj->type = MISSION_OBJ_NONE;
   455	    
   456	    // TODO: Вызов функции удаления сущности из мира
   457	}
   458	
   459	void MissionManager__ActivateTrigger(MissionManager* self, uint32_t trigIndex) {
   460	    if (!self || trigIndex >= MAX_MISSION_TRIGGERS) return;
   461	    
   462	    self->triggers_pool[trigIndex].state = 1; // Активирован
   463	}
   464	
   465	void MissionManager__UpdateTriggers(MissionManager* self) {
   466	    if (!self) return;
   467	    
   468	    for (uint32_t i = 0; i < MAX_MISSION_TRIGGERS; i++) {
   469	        MissionTrigger* trig = &self->triggers_pool[i];
   470	        if (trig->type == TRIGGER_NONE || trig->state == 2) continue; // Неактивен или выполнен
   471	        
   472	        // Проверка условий триггера
   473	        // TODO: Реализовать проверку зон, таймеров, событий
   474	    }
   475	}
   476	
   477	// ============================================================================
   478	// ВНУТРЕННИЕ УТИЛИТЫ
   479	// ============================================================================
   480	
   481	void MissionManager__ClampValues(MissionManager* self) {
   482	    if (!self) return;
   483	    // Ограничение значений в допустимых пределах
   484	}
   485	
   486	int32_t MissionManager__greater_than(MissionManager* self, int32_t a, int32_t b) {
   487	    (void)self;
   488	    return (a > b) ? 1 : 0;
   489	}
   490	
   491	int32_t MissionManager__less_or_equal(MissionManager* self, int32_t a, int32_t b) {
   492	    (void)self;
   493	    return (a <= b) ? 1 : 0;
   494	}
   495	
   496	int32_t MissionManager__NotEqual(MissionManager* self, int32_t a, int32_t b) {
   497	    (void)self;
   498	    return (a != b) ? 1 : 0;
   499	}
   500	
   501	int32_t MissionManager__less_than(MissionManager* self, int32_t a, int32_t b) {
   502	    (void)self;
   503	    return (a < b) ? 1 : 0;
   504	}
   505	
   506	void MissionManager__PrepareArray(MissionManager* self) {
   507	    if (!self) return;
   508	    // Подготовка массивов данных
   509	}
   510	
   511	void MissionManager__ClearMissionData(MissionManager* self) {
   512	    if (!self) return;
   513	    memset(self->mission_data_buffer, 0, sizeof(self->mission_data_buffer));
   514	}
   515	
   516	void MissionManager__AllocateMissionBuffer(MissionManager* self, uint32_t size) {
   517	    if (!self) return;
   518	    if (self->script_buffer_ptr) free(self->script_buffer_ptr);
   519	    self->script_buffer_ptr = malloc(size);
   520	    self->script_size = size;
   521	}
   522	
   523	void MissionManager__FreeMissionBuffer(MissionManager* self) {
   524	    if (!self) return;
   525	    if (self->script_buffer_ptr) {
   526	        free(self->script_buffer_ptr);
   527	        self->script_buffer_ptr = NULL;
   528	    }
   529	}
   530	
   531	// ============================================================================
   532	// СОХРАНЕНИЕ И ЗАГРУЗКА
   533	// =================================
