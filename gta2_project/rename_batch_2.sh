#!/bin/bash
# Пакетное переименование функций в файлах structures/ (Часть 2)

cd /workspace/gta2_project/src/structures

# Checkpoint.c - много функций
sed -i 's/S105__FUN_00401b70/Checkpoint_Reset/g' Checkpoint.c
sed -i 's/S105__FUN_00446740/Checkpoint_Activate/g' Checkpoint.c
sed -i 's/S105__FUN_00446810/Checkpoint_Deactivate/g' Checkpoint.c
sed -i 's/S105__FUN_00446b20/Checkpoint_IsActive/g' Checkpoint.c
sed -i 's/S105__FUN_00446c30/Checkpoint_SetTarget/g' Checkpoint.c
sed -i 's/S105__FUN_00446d40/Checkpoint_ClearTarget/g' Checkpoint.c
sed -i 's/S105__FUN_00446f50/Checkpoint_GetDistance/g' Checkpoint.c
sed -i 's/S105__FUN_004473a0/Checkpoint_NextInChain/g' Checkpoint.c
sed -i 's/S105__FUN_004474b0/Checkpoint_PrevInChain/g' Checkpoint.c
sed -i 's/S105__FUN_004478c0/Checkpoint_SetReward/g' Checkpoint.c
sed -i 's/S105__FUN_004479d0/Checkpoint_SetTimeLimit/g' Checkpoint.c
sed -i 's/S105__FUN_00447ae0/Checkpoint_SetVehicleType/g' Checkpoint.c
sed -i 's/S105__FUN_00447bf0/Checkpoint_SetRequiredSpeed/g' Checkpoint.c
sed -i 's/S105__FUN_00447d00/Checkpoint_SetDirection/g' Checkpoint.c
sed -i 's/S105__FUN_00447e10/Checkpoint_TriggerEffect/g' Checkpoint.c
sed -i 's/S105__FUN_004bc5a0/Checkpoint_Load/g' Checkpoint.c
sed -i 's/S105__FUN_004bcb60/Checkpoint_Save/g' Checkpoint.c

# CollisionBox.c - основные функции коллизий
sed -i 's/S106__FUN_00401b70/CollisionBox_Reset/g' CollisionBox.c
sed -i 's/S106__FUN_004037a0/CollisionBox_SetBounds/g' CollisionBox.c
sed -i 's/S106__FUN_0040e5c0/CollisionBox_TestPoint/g' CollisionBox.c
sed -i 's/S106__FUN_0040fe20/CollisionBox_TestBox/g' CollisionBox.c
sed -i 's/S106__FUN_00416b30/CollisionBox_TestSphere/g' CollisionBox.c
sed -i 's/S106__FUN_0041fa40/CollisionBox_GetIntersection/g' CollisionBox.c
sed -i 's/S106__FUN_004207d0/CollisionBox_GetClosestPoint/g' ClosestBox.c
sed -i 's/S106__FUN_00420fd0/CollisionBox_ClampPoint/g' CollisionBox.c
sed -i 's/S106__FUN_004210a0/CollisionBox_Expand/g' CollisionBox.c
sed -i 's/S106__FUN_004214e0/CollisionBox_Shrink/g' CollisionBox.c
sed -i 's/S106__FUN_004215f0/CollisionBox_Translate/g' CollisionBox.c
sed -i 's/S106__FUN_004234a0/CollisionBox_Rotate/g' CollisionBox.c
sed -i 's/S106__FUN_004244b0/CollisionBox_IntersectRay/g' CollisionBox.c
sed -i 's/S106__FUN_00427c80/CollisionBox_GetVolume/g' CollisionBox.c
sed -i 's/S106__FUN_00427d90/CollisionBox_GetSurfaceArea/g' CollisionBox.c
sed -i 's/S106__FUN_004293a0/CollisionBox_GetCentroid/g' CollisionBox.c
sed -i 's/S106__FUN_004340b0/CollisionBox_ProjectOnAxis/g' CollisionBox.c
sed -i 's/S106__FUN_00434bc0/CollisionBox_SeparatingAxis/g' CollisionBox.c
sed -i 's/S106__FUN_0043e5d0/CollisionBox_Merge/g' CollisionBox.c

# ColorRGBA.c
sed -i 's/S133__FUN_00401b70/ColorRGBA_Clear/g' ColorRGBA.c
sed -i 's/S133__FUN_00474f60/ColorRGBA_Interpolate/g' ColorRGBA.c

# Controller.c
sed -i 's/S135__FUN_00401b70/Controller_Reset/g' Controller.c
sed -i 's/S135__FUN_00474f60/Controller_UpdateState/g' Controller.c
sed -i 's/S135__FUN_004767a0/Controller_ReadInput/g' Controller.c

echo "Часть 2 завершена: Checkpoint, CollisionBox, ColorRGBA, Controller"
