// Module: S25
// Functions working with structure S25
// Generated from gta2.exe.c

#include "../../include/common.h"

void __thiscall S25__S25_FUN_004768c0(S25 *this,byte param_1,int param_2)

{
  this->arr_22[(uint)param_1 * 6 + 3] = param_2;
  return;
}


void __thiscall S25__S25_FUN_004c4ee0(S25 *this)

{
  int *piVar1;
  byte bVar2;
  
  this->field441_0x210 = 0;
  piVar1 = this->arr_22;
  bVar2 = 0;
  do {
    *(byte *)(piVar1 + 2) = bVar2;
    *piVar1 = 0;
    piVar1[1] = 0;
    *(undefined4 *)(piVar1 + -2) = 0;
    piVar1[3] = 1;
    piVar1 = piVar1 + 6;
    bVar2 = bVar2 + 1;
  } while (bVar2 < 22);
  return;
}


void __thiscall S25__S25_FUN_004c4fe0(S25 *this,byte param_1,S46 *param_2)

{
  int *piVar1;
  S46 *this_00;
  bool bVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  int iVar3;
  GameObject *this_01;
  Ped *pPVar4;
  void *pvVar5;
  Player *pPVar6;
  undefined3 extraout_var_02;
  undefined4 uVar7;
  undefined3 in_stack_00000005;
  ushort uVar8;
  Player *pPVar9;
  undefined1 local_8 [4];
  undefined1 local_4 [4];
  
  this_00 = param_2;
  piVar1 = this->arr_22 + (uint)param_1 * 6 + -2;
  if (this->arr_22[(uint)param_1 * 6 + 3] != 1) {
    return;
  }
  if (piVar1[1] == 0) {
    return;
  }
  this_01 = (GameObject *)param_2;
  switch(piVar1[2]) {
  case 1:
    iVar3 = SpriteS1::FUN_00416b40((SpriteS1 *)param_2);
    this_01 = (GameObject *)param_2;
    if (iVar3 == 2) {
      piVar1[5] = 0;
      this_01 = SpriteS1::GetObject((SpriteS1 *)this_00);
    }
    break;
  case 2:
    iVar3 = SpriteS1::FUN_00416b40((SpriteS1 *)param_2);
    this_01 = (GameObject *)param_2;
    if (iVar3 == 2) {
      this_01 = SpriteS1::GetObject((SpriteS1 *)this_00);
      pvVar5 = MissionManager::MissionManager_FUN_00476200
                         (_gMissionManager,*(ushort *)(*piVar1 + 8));
      if (this_01->field63_0x6c == *(int *)(*(int *)((int)pvVar5 + 8) + 0x6c)) {
        piVar1[5] = 0;
      }
    }
    break;
  case 3:
    iVar3 = SpriteS1::FUN_00416b40((SpriteS1 *)param_2);
    if (iVar3 != 3) {
      iVar3 = SpriteS1::FUN_00416b40((SpriteS1 *)this_00);
      this_01 = (GameObject *)param_2;
      if (iVar3 != 2) break;
      this_01 = SpriteS1::GetObject((SpriteS1 *)this_00);
      pPVar4 = Get_FUN_004118b0(this_01);
      if (pPVar4 == (Ped *)0x0) break;
      iVar3 = *piVar1;
      if (*(short *)(iVar3 + 2) != 0x1b2) goto LAB_004c51b2;
      pvVar5 = MissionManager::MissionManager_FUN_00476200
                         (_gMissionManager,*(ushort *)(iVar3 + 0x24));
      goto LAB_004c53bd;
    }
    pvVar5 = (void *)SpriteS1::SpriteS1_FUN_0040fea0((SpriteS1 *)this_00);
    pPVar4 = FUN_00433a20(pvVar5);
    this_01 = (GameObject *)param_2;
    if (pPVar4 == (Ped *)0x0) break;
    iVar3 = *piVar1;
    if (*(short *)(iVar3 + 2) == 0x1b2) {
      uVar8 = *(ushort *)(iVar3 + 0x24);
    }
    else {
LAB_004c50d9:
      uVar8 = *(ushort *)(iVar3 + 8);
    }
    goto LAB_004c50de;
  case 4:
    iVar3 = SpriteS1::FUN_00416b40((SpriteS1 *)param_2);
    this_01 = (GameObject *)param_2;
    if (iVar3 != 3) break;
    pvVar5 = (void *)SpriteS1::SpriteS1_FUN_0040fea0((SpriteS1 *)this_00);
    FUN_00433a20(pvVar5);
    iVar3 = *piVar1;
    if (*(short *)(iVar3 + 2) == 0xd4) {
      uVar8 = *(ushort *)(iVar3 + 0x10);
    }
    else {
      if (*(short *)(iVar3 + 2) != 0xd6) goto LAB_004c50d9;
      uVar8 = *(ushort *)(iVar3 + 0x24);
    }
LAB_004c50de:
    pvVar5 = MissionManager::MissionManager_FUN_00476200(_gMissionManager,uVar8)
    ;
    iVar3 = FUN_004c4f20();
    bVar2 = iVar3 == *(int *)(*(int *)((int)pvVar5 + 8) + 0x200);
LAB_004c522d:
    this_01 = (GameObject *)param_2;
    if (bVar2) {
      piVar1[5] = 0;
    }
    break;
  case 5:
    iVar3 = SpriteS1::FUN_00416b40((SpriteS1 *)param_2);
    this_01 = (GameObject *)param_2;
    if (iVar3 != 2) break;
    this_01 = SpriteS1::GetObject((SpriteS1 *)this_00);
    pPVar4 = Get_FUN_004118b0(this_01);
    if (pPVar4 == (Ped *)0x0) break;
    iVar3 = *piVar1;
LAB_004c51b2:
    pvVar5 = MissionManager::MissionManager_FUN_00476200
                       (_gMissionManager,*(ushort *)(iVar3 + 8));
    goto LAB_004c53bd;
  case 6:
    iVar3 = SpriteS1::FUN_00416b40((SpriteS1 *)param_2);
    if (iVar3 == 3) {
      pvVar5 = (void *)SpriteS1::SpriteS1_FUN_0040fea0((SpriteS1 *)this_00);
      pPVar4 = FUN_00433a20(pvVar5);
      this_01 = (GameObject *)param_2;
      if (pPVar4 == (Ped *)0x0) break;
      pvVar5 = MissionManager::MissionManager_FUN_00476200
                         (_gMissionManager,*(ushort *)(*piVar1 + 8));
      pPVar9 = (Player *)&DAT_00672900;
      pPVar6 = (Player *)FUN_00433c20(pPVar4,&param_1);
      bVar2 = Player::IsCurrentPlayer(pPVar6,pPVar9);
      this_01 = (GameObject *)param_2;
      if (CONCAT31(extraout_var_00,bVar2) == 0) break;
      iVar3 = FUN_004c4f20();
      bVar2 = iVar3 == *(int *)(*(int *)((int)pvVar5 + 8) + 0x200);
      goto LAB_004c522d;
    }
    iVar3 = SpriteS1::FUN_00416b40((SpriteS1 *)this_00);
    this_01 = (GameObject *)param_2;
    if (iVar3 != 2) break;
    this_01 = SpriteS1::GetObject((SpriteS1 *)this_00);
    pPVar4 = Get_FUN_004118b0(this_01);
    if (pPVar4 == (Ped *)0x0) break;
    pvVar5 = MissionManager::MissionManager_FUN_00476200
                       (_gMissionManager,*(ushort *)(*piVar1 + 8));
    pPVar9 = (Player *)&DAT_00672900;
    pPVar6 = (Player *)Ped::FUN_00436160(pPVar4,local_8);
    bVar2 = Player::IsCurrentPlayer(pPVar6,pPVar9);
    if (CONCAT31(extraout_var_01,bVar2) == 0) break;
    iVar3 = FUN_004c4f20();
    bVar2 = iVar3 == *(int *)(*(int *)((int)pvVar5 + 8) + 0x200);
    goto LAB_004c53cd;
  case 7:
    iVar3 = SpriteS1::FUN_00416b40((SpriteS1 *)param_2);
    this_01 = (GameObject *)param_2;
    if (iVar3 != 3) break;
    pvVar5 = (void *)SpriteS1::SpriteS1_FUN_0040fea0((SpriteS1 *)this_00);
    pPVar4 = FUN_00433a20(pvVar5);
    this_01 = (GameObject *)param_2;
    if (pPVar4 == (Ped *)0x0) break;
    pvVar5 = MissionManager::MissionManager_FUN_00476200
                       (_gMissionManager,*(ushort *)(*piVar1 + 8));
    pPVar9 = (Player *)&DAT_00672900;
    pPVar6 = (Player *)FUN_00433c20(pPVar4,&param_2);
    bVar2 = Player::IsCurrentPlayer(pPVar6,pPVar9);
    this_01 = (GameObject *)param_2;
    if (CONCAT31(extraout_var,bVar2) == 0) break;
    iVar3 = FUN_004c4f20();
    bVar2 = iVar3 == *(int *)(*(int *)((int)pvVar5 + 8) + 0x200);
    goto LAB_004c522d;
  case 8:
    iVar3 = SpriteS1::FUN_00416b40((SpriteS1 *)param_2);
    this_01 = (GameObject *)param_2;
    if (iVar3 != 2) break;
    this_01 = SpriteS1::GetObject((SpriteS1 *)this_00);
    pPVar4 = Get_FUN_004118b0(this_01);
    if (pPVar4 == (Ped *)0x0) break;
    pvVar5 = MissionManager::MissionManager_FUN_00476200
                       (_gMissionManager,*(ushort *)(*piVar1 + 8));
    pPVar9 = (Player *)&DAT_00672900;
    pPVar6 = (Player *)Ped::FUN_00436160(pPVar4,local_4);
    bVar2 = Player::IsCurrentPlayer(pPVar6,pPVar9);
    if (CONCAT31(extraout_var_02,bVar2) == 0) break;
LAB_004c53bd:
    iVar3 = FUN_004c4f20();
    bVar2 = iVar3 == *(int *)(*(int *)((int)pvVar5 + 8) + 0x200);
LAB_004c53cd:
    if (bVar2) {
      piVar1[5] = 0;
    }
  }
  if (piVar1[5] == 0) {
    if (piVar1[3] == 2) {
      iVar3 = *piVar1;
      uVar7 = FUN_0047f200(*(undefined2 *)(iVar3 + 0xe),0);
      *(undefined4 *)(iVar3 + 8) = uVar7;
    }
    else if (piVar1[3] == 3) {
      FUN_0047ed20(this_01->Car_1,*piVar1);
      FUN_004c4ea0((char)piVar1[4]);
      return;
    }
  }
  return;
}


