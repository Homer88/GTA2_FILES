#!/bin/bash
# Пакетное переименование функций в файлах structures/ (Часть 4)

cd /workspace/gta2_project/src/structures

# GlassInfo.c
sed -i 's/S151__FUN_00401b70/GlassInfo_Break/g' GlassInfo.c
sed -i 's/S151__FUN_00474f60/GlassInfo_Shatter/g' GlassInfo.c

# HeadlightInfo.c
sed -i 's/S152__FUN_00401b70/HeadlightInfo_TurnOn/g' HeadlightInfo.c
sed -i 's/S152__FUN_00474f60/HeadlightInfo_TurnOff/g' HeadlightInfo.c

# HelicopterInfo.c
sed -i 's/S153__FUN_00401b70/HelicopterInfo_Takeoff/g' HelicopterInfo.c
sed -i 's/S153__FUN_00474f60/HelicopterInfo_Land/g' HelicopterInfo.c
sed -i 's/S153__FUN_004767a0/HelicopterInfo_Hover/g' HelicopterInfo.c

# HudElement.c
sed -i 's/S154__FUN_00401b70/HudElement_Show/g' HudElement.c
sed -i 's/S154__FUN_00474f60/HudElement_Hide/g' HudElement.c
sed -i 's/S154__FUN_004767a0/HudElement_UpdateText/g' HudElement.c

# ImpactInfo.c
sed -i 's/S155__FUN_00401b70/ImpactInfo_Create/g' ImpactInfo.c
sed -i 's/S155__FUN_00474f60/ImpactInfo_ApplyForce/g' ImpactInfo.c

# JetInfo.c
sed -i 's/S156__FUN_00401b70/JetInfo_Takeoff/g' JetInfo.c
sed -i 's/S156__FUN_00474f60/JetInfo_Land/g' JetInfo.c
sed -i 's/S156__FUN_004767a0/JetInfo_FireWeapon/g' JetInfo.c

# LevelInfo.c
sed -i 's/S157__FUN_00401b70/LevelInfo_Load/g' LevelInfo.c
sed -i 's/S157__FUN_00474f60/LevelInfo_Unload/g' LevelInfo.c
sed -i 's/S157__FUN_004767a0/LevelInfo_GetSpawnPoint/g' LevelInfo.c

# LightInfo.c
sed -i 's/S158__FUN_00401b70/LightInfo_SetColor/g' LightInfo.c
sed -i 's/S158__FUN_00474f60/LightInfo_SetIntensity/g' LightInfo.c

# LinkedList.c
sed -i 's/S159__FUN_00401b70/LinkedList_Init/g' LinkedList.c
sed -i 's/S159__FUN_00474f60/LinkedList_Add/g' LinkedList.c
sed -i 's/S159__FUN_004767a0/LinkedList_Remove/g' LinkedList.c

# LoadScreen.c
sed -i 's/S160__FUN_00401b70/LoadScreen_Show/g' LoadScreen.c
sed -i 's/S160__FUN_00474f60/LoadScreen_Hide/g' LoadScreen.c
sed -i 's/S160__FUN_004767a0/LoadScreen_UpdateProgress/g' LoadScreen.c

# Matrix3D.c
sed -i 's/S161__FUN_00401b70/Matrix3D_Identity/g' Matrix3D.c
sed -i 's/S161__FUN_00474f60/Matrix3D_Multiply/g' Matrix3D.c
sed -i 's/S161__FUN_004767a0/Matrix3D_Transpose/g' Matrix3D.c

# MemoryBlock.c
sed -i 's/S162__FUN_00401b70/MemoryBlock_Alloc/g' MemoryBlock.c
sed -i 's/S162__FUN_00474f60/MemoryBlock_Free/g' MemoryBlock.c

# MenuInfo.c
sed -i 's/S163__FUN_00401b70/MenuInfo_Open/g' MenuInfo.c
sed -i 's/S163__FUN_00474f60/MenuInfo_Close/g' MenuInfo.c
sed -i 's/S163__FUN_004767a0/MenuInfo_SelectItem/g' MenuInfo.c

# MissionData.c
sed -i 's/S164__FUN_00401b70/MissionData_Start/g' MissionData.c
sed -i 's/S164__FUN_00474f60/MissionData_Complete/g' MissionData.c
sed -i 's/S164__FUN_004767a0/MissionData_Fail/g' MissionData.c

# ModelIndex.c
sed -i 's/S165__FUN_00401b70/ModelIndex_GetById/g' ModelIndex.c
sed -i 's/S165__FUN_00474f60/ModelIndex_GetByName/g' ModelIndex.c

# MusicTrack.c
sed -i 's/S166__FUN_00401b70/MusicTrack_Play/g' MusicTrack.c
sed -i 's/S166__FUN_00474f60/MusicTrack_Stop/g' MusicTrack.c
sed -i 's/S166__FUN_004767a0/MusicTrack_Pause/g' MusicTrack.c

echo "Часть 4 завершена: GlassInfo, HeadlightInfo, HelicopterInfo, HudElement, ImpactInfo, JetInfo, LevelInfo, LightInfo, LinkedList, LoadScreen, Matrix3D, MemoryBlock, MenuInfo, MissionData, ModelIndex, MusicTrack"
