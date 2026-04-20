#!/bin/bash
# Пакетное переименование функций в файлах structures/ (Часть 1)
# Фиксируем изменения на диск через sed

cd /workspace/gta2_project/src/structures

# Animation.c
sed -i 's/S27__S27_FUN_004767a0/S27_RemoveFirstElement/g' Animation.c
sed -i 's/S27__S27_FUN_0047f4d0/S27_DestroyAllElements/g' Animation.c
sed -i 's/S27__S27/S27_ctor/g' Animation.c
sed -i 's/S27__S27_FUN_00481380/S27_ReorderActiveElements/g' Animation.c
sed -i 's/FUN_004751b0/S28_dtor/g' Animation.c
sed -i 's/FUN_00476e10/S28_reset/g' Animation.c
sed -i 's/FUN_00481120/S28_isActive/g' Animation.c
sed -i 's/S28::S28/S28_ctor/g' Animation.c
sed -i 's/S28::~S28/S28_dtor/g' Animation.c

# BrakeInfo.c
sed -i 's/S124__GetS125/BrakeInfo_GetCurrent/g' BrakeInfo.c
sed -i 's/S124__FUN_004b8fe0/BrakeInfo_PopFront/g' BrakeInfo.c
sed -i 's/S124__FUN_004b9000/BrakeInfo_MoveToActive/g' BrakeInfo.c
sed -i 's/S124__S124_FUN_004b9050/BrakeInfo_ReorderActive/g' BrakeInfo.c
sed -i 's/S124__S124/BrakeInfo_ctor/g' BrakeInfo.c
sed -i 's/S125::S125_FUN_004b8f70/S125_isActive/g' BrakeInfo.c
sed -i 's/S125::S125/S125_ctor/g' BrakeInfo.c
sed -i 's/S125::~S125/S125_dtor/g' BrakeInfo.c

# BuildingModel.c
sed -i 's/S23__S23_FUN_0045b0e0/BuildingModel_Clear/g' BuildingModel.c
sed -i 's/S23__S23/BuildingModel_ctor/g' BuildingModel.c
sed -i 's/S23_FUN_0045b0e0/BuildingModel_Clear/g' BuildingModel.c

# BusInfo.c - уже переименовано ранее, пропускаем

# Camera.c
sed -i 's/S30__FUN_00474f60/Camera_UpdateMatrix/g' Camera.c
sed -i 's/S30__FUN_004767a0/Camera_RemoveFromList/g' Camera.c

# CarGenerator.c
sed -i 's/S102__FUN_0045af50/CarGenerator_SpawnVehicle/g' CarGenerator.c
sed -i 's/S102__FUN_0045b0e0/CarGenerator_Reset/g' CarGenerator.c

# CarModel.c
sed -i 's/S131__FUN_004c4b70/CarModel_GetDamageState/g' CarModel.c

echo "Часть 1 завершена: Animation, BrakeInfo, BuildingModel, BusInfo, Camera, CarGenerator, CarModel"
