#!/bin/bash
# Пакетное переименование функций в файлах structures/ (Часть 5 - последняя)

cd /workspace/gta2_project/src/structures

# NetworkPlayer.c
sed -i 's/S167__FUN_00401b70/NetworkPlayer_Connect/g' NetworkPlayer.c
sed -i 's/S167__FUN_00474f60/NetworkPlayer_Disconnect/g' NetworkPlayer.c
sed -i 's/S167__FUN_004767a0/NetworkPlayer_SendPacket/g' NetworkPlayer.c

# ObjectModel.c
sed -i 's/S168__FUN_00401b70/ObjectModel_Load/g' ObjectModel.c
sed -i 's/S168__FUN_00474f60/ObjectModel_Unload/g' ObjectModel.c

# ObjectPool.c
sed -i 's/S169__FUN_00401b70/ObjectPool_Alloc/g' ObjectPool.c
sed -i 's/S169__FUN_00474f60/ObjectPool_Free/g' ObjectPool.c
sed -i 's/S169__FUN_004767a0/ObjectPool_Find/g' ObjectPool.c

# PacketInfo.c
sed -i 's/S170__FUN_00401b70/PacketInfo_Create/g' PacketInfo.c
sed -i 's/S170__FUN_00474f60/PacketInfo_Send/g' PacketInfo.c

# ParkingSpot.c
sed -i 's/S171__FUN_00401b70/ParkingSpot_Reserve/g' ParkingSpot.c
sed -i 's/S171__FUN_00474f60/ParkingSpot_Release/g' ParkingSpot.c

# Particle.c
sed -i 's/S172__FUN_00401b70/Particle_Emit/g' Particle.c
sed -i 's/S172__FUN_00474f60/Particle_Update/g' Particle.c
sed -i 's/S172__FUN_004767a0/Particle_Kill/g' Particle.c

# PathNode.c
sed -i 's/S173__FUN_00401b70/PathNode_GetNext/g' PathNode.c
sed -i 's/S173__FUN_00474f60/PathNode_GetDistance/g' PathNode.c

# PedGenerator.c
sed -i 's/S174__FUN_00401b70/PedGenerator_Spawn/g' PedGenerator.c
sed -i 's/S174__FUN_00474f60/PedGenerator_SetDensity/g' PedGenerator.c

# PedModel.c
sed -i 's/S175__FUN_00401b70/PedModel_Load/g' PedModel.c
sed -i 's/S175__FUN_00474f60/PedModel_GetAnimation/g' PedModel.c

# PedPool.c
sed -i 's/S176__FUN_00401b70/PedPool_Alloc/g' PedPool.c
sed -i 's/S176__FUN_00474f60/PedPool_Free/g' PedPool.c

# PedStats.c
sed -i 's/S177__FUN_00401b70/PedStats_GetStrength/g' PedStats.c
sed -i 's/S177__FUN_00474f60/PedStats_GetHealth/g' PedStats.c

# PhoneCall.c
sed -i 's/S178__FUN_00401b70/PhoneCall_Start/g' PhoneCall.c
sed -i 's/S178__FUN_00474f60/PhoneCall_End/g' PhoneCall.c
sed -i 's/S178__FUN_004767a0/PhoneCall_PlayMessage/g' PhoneCall.c

# PickupInfo.c
sed -i 's/S179__FUN_00401b70/PickupInfo_Spawn/g' PickupInfo.c
sed -i 's/S179__FUN_00474f60/PickupInfo_Collect/g' PickupInfo.c

# Plane3D.c
sed -i 's/S180__FUN_00401b70/Plane3D_FromPoints/g' Plane3D.c
sed -i 's/S180__FUN_00474f60/Plane3D_DistanceToPoint/g' Plane3D.c

# PlaneInfo.c
sed -i 's/S181__FUN_00401b70/PlaneInfo_Takeoff/g' PlaneInfo.c
sed -i 's/S181__FUN_00474f60/PlaneInfo_Land/g' PlaneInfo.c
sed -i 's/S181__FUN_004767a0/PlaneInfo_FireWeapon/g' PlaneInfo.c

# Point2D.c
sed -i 's/S182__FUN_00401b70/Point2D_Distance/g' Point2D.c
sed -i 's/S182__FUN_00474f60/Point2D_Lerp/g' Point2D.c

# PoliceInfo.c
sed -i 's/S183__FUN_00401b70/PoliceInfo_PursueTarget/g' PoliceInfo.c
sed -i 's/S183__FUN_00474f60/PoliceInfo_CallBackup/g' PoliceInfo.c
sed -i 's/S183__FUN_004767a0/PoliceInfo_Arrest/g' PoliceInfo.c

# Powerup.c
sed -i 's/S184__FUN_00401b70/Powerup_Activate/g' Powerup.c
sed -i 's/S184__FUN_00474f60/Powerup_Deactivate/g' Powerup.c

# Radar.c
sed -i 's/S185__FUN_00401b70/Radar_AddBlip/g' Radar.c
sed -i 's/S185__FUN_00474f60/Radar_RemoveBlip/g' Radar.c
sed -i 's/S185__FUN_004767a0/Radar_UpdateBlip/g' Radar.c

# RadioStation.c
sed -i 's/S186__FUN_00401b70/RadioStation_PlayTrack/g' RadioStation.c
sed -i 's/S186__FUN_00474f60/RadioStation_Stop/g' RadioStation.c
sed -i 's/S186__FUN_004767a0/RadioStation_NextTrack/g' RadioStation.c

# Rect2D.c
sed -i 's/S187__FUN_00401b70/Rect2D_Contains/g' Rect2D.c
sed -i 's/S187__FUN_00474f60/Rect2D_Intersect/g' Rect2D.c

# ReflectionInfo.c
sed -i 's/S188__FUN_00401b70/ReflectionInfo_Create/g' ReflectionInfo.c
sed -i 's/S188__FUN_00474f60/ReflectionInfo_Update/g' ReflectionInfo.c

# RenderQueue.c
sed -i 's/S189__FUN_00401b70/RenderQueue_Add/g' RenderQueue.c
sed -i 's/S189__FUN_00474f60/RenderQueue_Submit/g' RenderQueue.c
sed -i 's/S189__FUN_004767a0/RenderQueue_Clear/g' RenderQueue.c

# RouteInfo.c
sed -i 's/S190__FUN_00401b70/RouteInfo_GetNode/g' RouteInfo.c
sed -i 's/S190__FUN_00474f60/RouteInfo_GetLength/g' RouteInfo.c

echo "Часть 5 завершена: NetworkPlayer, ObjectModel, ObjectPool, PacketInfo, ParkingSpot, Particle, PathNode, PedGenerator, PedModel, PedPool, PedStats, PhoneCall, PickupInfo, Plane3D, PlaneInfo, Point2D, PoliceInfo, Powerup, Radar, RadioStation, Rect2D, ReflectionInfo, RenderQueue, RouteInfo"
