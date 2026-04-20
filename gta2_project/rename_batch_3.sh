#!/bin/bash
# Пакетное переименование функций в файлах structures/ (Часть 3)

cd /workspace/gta2_project/src/structures

# CrashData.c
sed -i 's/S137__FUN_00401b70/CrashData_Reset/g' CrashData.c
sed -i 's/S137__FUN_00474f60/CrashData_Record/g' CrashData.c
sed -i 's/S137__FUN_004767a0/CrashData_Playback/g' CrashData.c

# DamageInfo.c
sed -i 's/S138__FUN_00401b70/DamageInfo_Clear/g' DamageInfo.c
sed -i 's/S138__FUN_00474f60/DamageInfo_Apply/g' DamageInfo.c
sed -i 's/S138__FUN_004767a0/DamageInfo_GetTotal/g' DamageInfo.c

# DebrisInfo.c
sed -i 's/S139__FUN_00401b70/DebrisInfo_Spawn/g' DebrisInfo.c
sed -i 's/S139__FUN_00474f60/DebrisInfo_Update/g' DebrisInfo.c

# DecalInfo.c
sed -i 's/S140__FUN_00401b70/DecalInfo_Create/g' DecalInfo.c
sed -i 's/S140__FUN_00474f60/DecalInfo_Fade/g' DecalInfo.c
sed -i 's/S140__FUN_004767a0/DecalInfo_Remove/g' DecalInfo.c

# EngineInfo.c
sed -i 's/S141__FUN_00401b70/EngineInfo_Start/g' EngineInfo.c
sed -i 's/S141__FUN_00474f60/EngineInfo_Stop/g' EngineInfo.c
sed -i 's/S141__FUN_004767a0/EngineInfo_GetRPM/g' EngineInfo.c

# EventHandler.c
sed -i 's/S142__FUN_00401b70/EventHandler_Register/g' EventHandler.c
sed -i 's/S142__FUN_00474f60/EventHandler_Unregister/g' EventHandler.c
sed -i 's/S142__FUN_004767a0/EventHandler_Trigger/g' EventHandler.c

# ExplosionInfo.c
sed -i 's/S143__FUN_00401b70/ExplosionInfo_Create/g' ExplosionInfo.c
sed -i 's/S143__FUN_00474f60/ExplosionInfo_Expand/g' ExplosionInfo.c
sed -i 's/S143__FUN_004767a0/ExplosionInfo_ApplyDamage/g' ExplosionInfo.c

# FenceInfo.c
sed -i 's/S144__FUN_00401b70/FenceInfo_SetHealth/g' FenceInfo.c
sed -i 's/S144__FUN_00474f60/FenceInfo_Break/g' FenceInfo.c

# FireInfo.c
sed -i 's/S145__FUN_00401b70/FireInfo_Ignite/g' FireInfo.c
sed -i 's/S145__FUN_00474f60/FireInfo_Spread/g' FireInfo.c
sed -i 's/S145__FUN_004767a0/FireInfo_Extinguish/g' FireInfo.c

# FiretruckInfo.c
sed -i 's/S146__FUN_00401b70/FiretruckInfo_Respond/g' FiretruckInfo.c
sed -i 's/S146__FUN_00474f60/FiretruckInfo_UseHose/g' FiretruckInfo.c

# GameObject.c
sed -i 's/S147__FUN_00401b70/GameObject_Init/g' GameObject.c
sed -i 's/S147__FUN_00474f60/GameObject_Update/g' GameObject.c
sed -i 's/S147__FUN_004767a0/GameObject_Destroy/g' GameObject.c

# GameState.c
sed -i 's/S148__FUN_00401b70/GameState_Init/g' GameState.c
sed -i 's/S148__FUN_00474f60/GameState_Save/g' GameState.c
sed -i 's/S148__FUN_004767a0/GameState_Load/g' GameState.c

# GangInfo.c
sed -i 's/S149__FUN_00401b70/GangInfo_SpawnMember/g' GangInfo.c
sed -i 's/S149__FUN_00474f60/GangInfo_AttackTarget/g' GangInfo.c
sed -i 's/S149__FUN_004767a0/GangInfo_GetTerritory/g' GangInfo.c

# GarageInfo.c
sed -i 's/S150__FUN_00401b70/GarageInfo_Open/g' GarageInfo.c
sed -i 's/S150__FUN_00474f60/GarageInfo_Close/g' GarageInfo.c
sed -i 's/S150__FUN_004767a0/GarageInfo_StoreVehicle/g' GarageInfo.c

echo "Часть 3 завершена: CrashData, DamageInfo, DebrisInfo, DecalInfo, EngineInfo, EventHandler, ExplosionInfo, FenceInfo, FireInfo, FiretruckInfo, GameObject, GameState, GangInfo, GarageInfo"
