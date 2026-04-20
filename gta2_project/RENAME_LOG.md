# Лог переименования функций GTA 2 Reversing

## Статус на: $(date)

### Обработанные файлы:

#### 1. systems/replay.c (25 функций)
Переименованы функции управления системой повторов:
- `FUN_0044aa80` → `Replay_InitBuffer`
- `FUN_0045ad90` → `Replay_ResetState`
- `cInput_FUN_0045ed00` → `Replay_ProcessInput`
- `Replay_FUN_0045eec0` → `Replay_StopPlayback`
- `cInput_FUN_0045f270` → `Replay_SetInputActive`
- `Input_FUN_0045f640` → `Replay_StoreInput`
- `FUN_0045f900` → `Replay_EndRecording`
- `Replay_FUN_0045f970` → `Replay_CheckStatus`
- `FUN_0045f990` → `Replay_ClearData`
- `FUN_0045fa00` → `Replay_GetDataPtr`
- `FUN_0045fa50` → `Replay_SetFrame`
- `Replay_FUN_0045fb10` → `Replay_FlushData`
- `FUN_0045fba0` → `Replay_ReadInputs`
- `FUN_0045fc20` → `Replay_WriteInputs`
- `FUN_0045fd10` → `Replay_GetCurrentFrame`
- `Set_FUN_004d09b0` → `Replay_SetMode`
- И другие...

#### 2. systems/mission.c (66 функций)
Переименованы функции системы миссий:
- `FUN_003f163c` → `MissionManager_UpdateMissionState`
- `FUN_004751d0` → `MissionManager_InitSubsystems`
- `FUN_004751e0` → `MissionManager_ResetCounters`
- `MissionManager_FUN_00475230` → `MissionManager_SetPlayerTarget`
- `MissionManager_FUN_00475290` → `MissionManager_SetVehicleType`
- `MissionManager_FUN_004752a0` → `MissionManager_SetWeaponType`
- `MissionManager_FUN_004752d0` → `MissionManager_SetGangAlly`
- `MissionManager_FUN_004752f0` → `MissionManager_SetGangEnemy`
- `MissionManager_FUN_004753b0` → `MissionManager_SetSpawnLocation`
- `MissionManager_FUN_004753d0` → `MissionManager_SetTimeLimit`
- `MissionManager_FUN_00475420` → `MissionManager_SetScoreGoal`
- `MissionManager_FUN_00475460` → `MissionManager_SetHealthBonus`
- `MissionManager_FUN_004754e0` → `MissionManager_SetWantedLevel`
- `MissionManager_FUN_004755b0` → `MissionManager_SetTrafficDensity`
- `MissionManager_FUN_004755d0` → `MissionManager_SetPedestrianDensity`
- `MissionManager_FUN_004755f0` → `MissionManager_SetWeatherType`
- `MissionManager_FUN_00475650` → `MissionManager_SetSpecialFlag`
- `FUN_00475700` → `MissionManager_CheckObjectiveComplete`
- `MissionManager_FUN_00475a20` → `MissionManager_GetCurrentMissionId`
- `FUN_00475a30` → `MissionManager_GetMissionState`
- `MissionManager_FUN_00475ca0` → `MissionManager_Shutdown`
- `MissionManager_FUN_00476200` → `MissionManager_StartMission`
- `FUN_00476e50` → `MissionManager_IsMissionActive`
- `MissionManager_FUN_00476ff0` → `MissionManager_SetupMissionParams`
- `MissionManager_FUN_00477140` → `MissionManager_ProcessEntityInteraction`
- `MissionManager_FUN_00477290` → `MissionManager_TriggerEvent`
- `MissionManager_FUN_00477530` → `MissionManager_UpdateObjectiveProgress`
- `MissionManager_FUN_00477560` → `MissionManager_SpawnEnemyWave`
- `MissionManager_FUN_00477660` → `MissionManager_SetCutsceneTrigger`
- `MissionManager_FUN_004777e0` → `MissionManager_EnableVehicleSpawner`
- `MissionManager_FUN_00477870` → `MissionManager_SetPickupRespawnTime`
- `MissionManager_FUN_00477920` → `MissionManager_SetExplosionDamageMultiplier`
- `MissionManager_FUN_004779a0` → `MissionManager_SetBulletDamageMultiplier`
- `MissionManager_FUN_00477a00` → `MissionManager_SetPoliceAggressionLevel`
- `MissionManager_FUN_00477ac0` → `MissionManager_SetGangTerritoryControl`
- `MissionManager_FUN_00477b70` → `MissionManager_SetSafehouseLocation`
- `MissionManager_FUN_00477bd0` → `MissionManager_SetBonusObjective`
- `MissionManager_FUN_00477d20` → `MissionManager_SetHiddenPackageCount`
- `MissionManager_FUN_00477ee0` → `MissionManager_SetRampageKillTarget`
- `MissionManager_FUN_00478120` → `MissionManager_SetTimerDisplayStyle`
- `MissionManager_FUN_00478170` → `MissionManager_SetRadioStationLock`
- `FUN_00478240` → `MissionManager_SetCheckpointReached`
- `FUN_00478450` → `MissionManager_BroadcastMessage`
- `MissionManager_FUN_004784e0` → `MissionManager_StartMapPlaySound`
- `FUN_004785d0` → `MissionManager_FadeScreenIn`
- `FUN_00478610` → `MissionManager_FadeScreenOut`
- `FUN_0047c7d0` → `MissionManager_UpdateHUD`
- `FUN_0047d650` → `MissionManager_ProcessMissionTimers`
- `FUN_0047d860` → `MissionManager_CheckPlayerDeath`
- `FUN_0047d960` → `MissionManager_CheckVehicleDestroyed`
- `FUN_0047e1f0` → `MissionManager_ProcessGangRelations`
- `FUN_0047eab0` → `MissionManager_UpdateWantedLevel`
- `MissionManager_FUN_0047ee70` → `MissionManager_GetTotalMissionsCompleted`
- `FUN_0047f0b0` → `MissionManager_DisplayBriefText`
- `MissionManager_FUN_0047f420` → `MissionManager_SetScriptVariable`
- `MissionManager_FUN_0047f710` → `MissionManager_CallScriptFunction`
- `FUN_0047f760` → `MissionManager_SetMissionResult`
- `FUN_0047f890` → `MissionManager_CleanupFinishedMissions`
- `MissionManager_FUN_00481200` → `MissionManager_GetHighestPassingRank`
- `MissionManager_FUN_00481270` → `MissionManager_GetLowestFailingRank`
- `MissionManager_FUN_00481400` → `MissionManager_GetAverageScore`
- `MissionManager_FUN_00481890` → `MissionManager_GetBonusProgress`
- `MissionManager_FUN_00481900` → `MissionManager_GetSecretProgress`
- `MissionManager_FUN_00481970` → `MissionManager_ctor`
- `MissionManager_FUN_00481a20` → `MissionManager_dtor`
- `MissionManager_FUN_004c7350` → `MissionManager_DebugDump`

#### 3. ai/gang.c (21 функция)
Переименованы функции системы банд:
- `Get_Pararam0x111` → `Gang_GetMood`
- `Gang::Gang` → `Gang_ctor`
- `Gangs::Gangs` → `Gangs_ctor`
- `FUN_0045d960` → `Gang_ResetState`
- `FUN_0045da20` → `Gang_SetPrestige`
- `FUN_0045da40` → `Gang_SetRelations`
- `FUN_0045da80` → `Gang_InitFromPreset`
- `CopeNameGangFUN_0045db40` → `Gang_GetName`
- `Gangs_FUN_0045dbb0` → `Gangs_FindByName`
- `Gangs_FUN_0045dc20` → `Gangs_GetRandomGang`
- `SetGang` → `Gangs_SelectGang`
- `Gangs_FUN_0045dc90` → `Gangs_RegisterGang`
- `FUN_0045dcc0` → `Gangs_GetIndexByName`
- `Gangs_FUN_0045dce0` → `Gangs_GetPreferredCarType`
- `GetVisibleGang` → `Gang_IsVisible`
- `Gangs_FUN_0045dd60` → `Gangs_GetGangData`
- `S117_FUN_0045ddb0` → `Gangs_GetActiveGang`
- `FUN_0045de10` → `Gang_SetColor`
- `FUN_0045dea0` → `Gang_SetWeaponPreference`
- `FUN_0045df30` → `Gangs_SetGangPresence`
- `FUN_00475900` → `Gang_UpdateInfluence`

### Всего переименовано функций: 112

### Осталось переименовать: ~16500 функций

## Следующие шаги:
1. Продолжить переименование в файлах world/*.c
2. Обработать файлы structures/*.c
3. Переименовать функции в platform/*.c
4. Завершить работу с ui/*.c и network/*.c

## Конвенции именования:
- Конструкторы: `ClassName_ctor`
- Деструкторы: `ClassName_dtor`
- Геттеры: `ClassName_GetPropertyName`
- Сеттеры: `ClassName_SetPropertyName`
- Методы действия: `ClassName_ActionName`
- Вспомогательные: `ClassName_HelperName`
