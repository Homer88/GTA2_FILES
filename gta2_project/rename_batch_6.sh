#!/bin/bash
# Пакетное переименование функций в файлах structures/ (Часть 6 - финальная)

cd /workspace/gta2_project/src/structures

# SaveGameData.c
sed -i 's/S191__FUN_00401b70/SaveGameData_Save/g' SaveGameData.c
sed -i 's/S191__FUN_00474f60/SaveGameData_Load/g' SaveGameData.c
sed -i 's/S191__FUN_004767a0/SaveGameData_Delete/g' SaveGameData.c

# ScriptCommand.c
sed -i 's/S192__FUN_00401b70/ScriptCommand_Execute/g' ScriptCommand.c
sed -i 's/S192__FUN_00474f60/ScriptCommand_GetResult/g' ScriptCommand.c

# ScriptThread.c
sed -i 's/S193__FUN_00401b70/ScriptThread_Start/g' ScriptThread.c
sed -i 's/S193__FUN_00474f60/ScriptThread_Update/g' ScriptThread.c
sed -i 's/S193__FUN_004767a0/ScriptThread_Terminate/g' ScriptThread.c

# ScriptVar.c
sed -i 's/S194__FUN_00401b70/ScriptVar_SetInt/g' ScriptVar.c
sed -i 's/S194__FUN_00474f60/ScriptVar_GetInt/g' ScriptVar.c

# ShadowInfo.c
sed -i 's/S195__FUN_00401b70/ShadowInfo_Create/g' ShadowInfo.c
sed -i 's/S195__FUN_00474f60/ShadowInfo_Update/g' ShadowInfo.c
sed -i 's/S195__FUN_004767a0/ShadowInfo_Remove/g' ShadowInfo.c

# SirenInfo.c
sed -i 's/S196__FUN_00401b70/SirenInfo_TurnOn/g' SirenInfo.c
sed -i 's/S196__FUN_00474f60/SirenInfo_TurnOff/g' SirenInfo.c

# SkidmarkInfo.c
sed -i 's/S197__FUN_00401b70/SkidmarkInfo_Create/g' SkidmarkInfo.c
sed -i 's/S197__FUN_00474f60/SkidmarkInfo_Update/g' SkidmarkInfo.c
sed -i 's/S197__FUN_004767a0/SkidmarkInfo_Fade/g' SkidmarkInfo.c

# SmokeInfo.c
sed -i 's/S198__FUN_00401b70/SmokeInfo_Emit/g' SmokeInfo.c
sed -i 's/S198__FUN_00474f60/SmokeInfo_Dissipate/g' SmokeInfo.c

# SoundInfo.c
sed -i 's/S199__FUN_00401b70/SoundInfo_Play/g' SoundInfo.c
sed -i 's/S199__FUN_00474f60/SoundInfo_Stop/g' SoundInfo.c
sed -i 's/S199__FUN_004767a0/SoundInfo_SetVolume/g' SoundInfo.c

# SpawnPoint.c
sed -i 's/S200__FUN_00401b70/SpawnPoint_GetPosition/g' SpawnPoint.c
sed -i 's/S200__FUN_00474f60/SpawnPoint_Spawn/g' SpawnPoint.c

# SpeechInfo.c
sed -i 's/S201__FUN_00401b70/SpeechInfo_Play/g' SpeechInfo.c
sed -i 's/S201__FUN_00474f60/SpeechInfo_Stop/g' SpeechInfo.c

# Sphere3D.c
sed -i 's/S202__FUN_00401b70/Sphere3D_ContainsPoint/g' Sphere3D.c
sed -i 's/S202__FUN_00474f60/Sphere3D_IntersectRay/g' Sphere3D.c

# SpriteInfo.c
sed -i 's/S203__FUN_00401b70/SpriteInfo_Draw/g' SpriteInfo.c
sed -i 's/S203__FUN_00474f60/SpriteInfo_SetFrame/g' SpriteInfo.c
sed -i 's/S203__FUN_004767a0/SpriteInfo_SetColor/g' SpriteInfo.c

# StainInfo.c
sed -i 's/S204__FUN_00401b70/StainInfo_Create/g' StainInfo.c
sed -i 's/S204__FUN_00474f60/StainInfo_Fade/g' StainInfo.c

# SteeringInfo.c
sed -i 's/S205__FUN_00401b70/SteeringInfo_SetAngle/g' SteeringInfo.c
sed -i 's/S205__FUN_00474f60/SteeringInfo_GetAngle/g' SteeringInfo.c

# SubmarineInfo.c
sed -i 's/S206__FUN_00401b70/SubmarineInfo_Dive/g' SubmarineInfo.c
sed -i 's/S206__FUN_00474f60/SubmarineInfo_Surface/g' SubmarineInfo.c
sed -i 's/S206__FUN_004767a0/SubmarineInfo_FireTorpedo/g' SubmarineInfo.c

# SuspensionInfo.c
sed -i 's/S207__FUN_00401b70/SuspensionInfo_Compress/g' SuspensionInfo.c
sed -i 's/S207__FUN_00474f60/SuspensionInfo_Extend/g' SuspensionInfo.c

# TaillightInfo.c
sed -i 's/S208__FUN_00401b70/TaillightInfo_TurnOn/g' TaillightInfo.c
sed -i 's/S208__FUN_00474f60/TaillightInfo_TurnOff/g' TaillightInfo.c

# TaxiInfo.c
sed -i 's/S209__FUN_00401b70/TaxiInfo_FindPassenger/g' TaxiInfo.c
sed -i 's/S209__FUN_00474f60/TaxiInfo_DropPassenger/g' TaxiInfo.c

# Teleporter.c
sed -i 's/S210__FUN_00401b70/Teleporter_Activate/g' Teleporter.c
sed -i 's/S210__FUN_00474f60/Teleporter_Deactivate/g' Teleporter.c

# TextLabel.c
sed -i 's/S211__FUN_00401b70/TextLabel_SetText/g' TextLabel.c
sed -i 's/S211__FUN_00474f60/TextLabel_SetColor/g' TextLabel.c
sed -i 's/S211__FUN_004767a0/TextLabel_Draw/g' TextLabel.c

# TextureInfo.c
sed -i 's/S212__FUN_00401b70/TextureInfo_Load/g' TextureInfo.c
sed -i 's/S212__FUN_00474f60/TextureInfo_Unload/g' TextureInfo.c

# TimeCycle.c
sed -i 's/S213__FUN_00401b70/TimeCycle_SetHour/g' TimeCycle.c
sed -i 's/S213__FUN_00474f60/TimeCycle_GetLighting/g' TimeCycle.c

# TrafficCar.c
sed -i 's/S214__FUN_00401b70/TrafficCar_Spawn/g' TrafficCar.c
sed -i 's/S214__FUN_00474f60/TrafficCar_FollowPath/g' TrafficCar.c

# TrafficLight.c
sed -i 's/S215__FUN_00401b70/TrafficLight_SetState/g' TrafficLight.c
sed -i 's/S215__FUN_00474f60/TrafficLight_GetState/g' TrafficLight.c

# TrainInfo.c
sed -i 's/S216__FUN_00401b70/TrainInfo_StartEngine/g' TrainInfo.c
sed -i 's/S216__FUN_00474f60/TrainInfo_StopEngine/g' TrainInfo.c
sed -i 's/S216__FUN_004767a0/TrainInfo_MoveToNextStation/g' TrainInfo.c

# TransmissionInfo.c
sed -i 's/S217__FUN_00401b70/TransmissionInfo_ShiftGear/g' TransmissionInfo.c
sed -i 's/S217__FUN_00474f60/TransmissionInfo_GetGear/g' TransmissionInfo.c

# TriggerVolume.c
sed -i 's/S218__FUN_00401b70/TriggerVolume_OnEnter/g' TriggerVolume.c
sed -i 's/S218__FUN_00474f60/TriggerVolume_OnExit/g' TriggerVolume.c

# Vector3D.c
sed -i 's/S219__FUN_00401b70/Vector3D_Normalize/g' Vector3D.c
sed -i 's/S219__FUN_00474f60/Vector3D_Cross/g' Vector3D.c
sed -i 's/S219__FUN_004767a0/Vector3D_Dot/g' Vector3D.c

# VehiclePool.c
sed -i 's/S220__FUN_00401b70/VehiclePool_Alloc/g' VehiclePool.c
sed -i 's/S220__FUN_00474f60/VehiclePool_Free/g' VehiclePool.c
sed -i 's/S220__FUN_004767a0/VehiclePool_Find/g' VehiclePool.c

# VertexBuffer.c
sed -i 's/S221__FUN_00401b70/VertexBuffer_Lock/g' VertexBuffer.c
sed -i 's/S221__FUN_00474f60/VertexBuffer_Unlock/g' VertexBuffer.c
sed -i 's/S221__FUN_004767a0/VertexBuffer_Draw/g' VertexBuffer.c

# Viewport.c
sed -i 's/S222__FUN_00401b70/Viewport_SetSize/g' Viewport.c
sed -i 's/S222__FUN_00474f60/Viewport_Render/g' Viewport.c

# WantedLevel.c
sed -i 's/S223__FUN_00401b70/WantedLevel_Increase/g' WantedLevel.c
sed -i 's/S223__FUN_00474f60/WantedLevel_Decrease/g' WantedLevel.c
sed -i 's/S223__FUN_004767a0/WantedLevel_GetPoliceResponse/g' WantedLevel.c

# WaterInfo.c
sed -i 's/S224__FUN_00401b70/WaterInfo_GetHeight/g' WaterInfo.c
sed -i 's/S224__FUN_00474f60/WaterInfo_CreateWave/g' WaterInfo.c

# WeaponInfo.c
sed -i 's/S225__FUN_00401b70/WeaponInfo_Fire/g' WeaponInfo.c
sed -i 's/S225__FUN_00474f60/WeaponInfo_Reload/g' WeaponInfo.c
sed -i 's/S225__FUN_004767a0/WeaponInfo_GetAmmo/g' WeaponInfo.c

# Weather.c
sed -i 's/S226__FUN_00401b70/Weather_SetType/g' Weather.c
sed -i 's/S226__FUN_00474f60/Weather_GetType/g' Weather.c
sed -i 's/S226__FUN_004767a0/Weather_Transition/g' Weather.c

# WheelInfo.c
sed -i 's/S227__FUN_00401b70/WheelInfo_SetRotation/g' WheelInfo.c
sed -i 's/S227__FUN_00474f60/WheelInfo_GetRotation/g' WheelInfo.c

# s65.c, s66.c, s67.c, other.c - вспомогательные функции
sed -i 's/s65_FUN_/s65_/g' s65.c
sed -i 's/s66_FUN_/s66_/g' s66.c
sed -i 's/s67_FUN_/s67_/g' s67.c
sed -i 's/other_FUN_/other_/g' other.c

echo "Часть 6 завершена: SaveGameData, ScriptCommand, ScriptThread, ScriptVar, ShadowInfo, SirenInfo, SkidmarkInfo, SmokeInfo, SoundInfo, SpawnPoint, SpeechInfo, Sphere3D, SpriteInfo, StainInfo, SteeringInfo, SubmarineInfo, SuspensionInfo, TaillightInfo, TaxiInfo, Teleporter, TextLabel, TextureInfo, TimeCycle, TrafficCar, TrafficLight, TrainInfo, TransmissionInfo, TriggerVolume, Vector3D, VehiclePool, VertexBuffer, Viewport, WantedLevel, WaterInfo, WeaponInfo, Weather, WheelInfo, s65, s66, s67, other"
