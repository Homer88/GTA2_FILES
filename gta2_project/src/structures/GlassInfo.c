// Module: S110
// Functions working with structure S110
// Generated from gta2.exe.c

#include "common.h"

void * __thiscall S110__S110_FUN_00401b40(void *this,S110 *param_1,void *param_2)

{
                              // WARNING: Load size is inaccurate
                              // WARNING: Load size is inaccurate
  SpriteS1__LinkToS3((SpriteS1 *)param_1,(S3 *)(*this - *param_2));
  return param_1;
}


int * __thiscall S110__FUN_00403840(void *this,int *param_1,S110 *pS110)

{
  if (0 < (int)pS110->car) {
    *param_1 = (int)pS110->car;
    return param_1;
  }
  Texture_Find(pS110,param_1);
  return param_1;
}


void * __thiscall S110__FUN_0040f600(void *this,void *param_1,S110 *param_2)

{
  S110 *pSVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  Car *local_4;
  
  pSVar1 = param_2;
  local_4 = (Car *)this;
  puVar2 = (undefined4 *)
           Decoder_ProcessData((void *)((int)this + 4),(S110 *)&param_2,
                             &param_2->pPed);
  puVar3 = (undefined4 *)Decoder_ProcessData(this,(S110 *)&local_4,pSVar1);
  String_ParseLine(param_1,puVar3,puVar2);
  return param_1;
}


void __thiscall S110__FUN_0040f6b0(void *this,S110 *param_1)

{
  undefined4 *this_00;
  S110 *pSVar1;
  int *piVar2;
  S9 *pSVar3;
  SpriteS1 *pSVar4;
  int *piVar5;
  void *this_01;
  S110 **pS110;
  int local_18;
  undefined4 local_14;
  undefined1 local_10 [4];
  undefined1 local_c [4];
  undefined1 local_8 [8];
  
  pSVar1 = param_1;
  FUN_0040f500(&local_18,param_1);
  FUN_0040f520(&param_1,pSVar1);
                              // WARNING: Load size is inaccurate
  local_14 = *this;
  this_00 = (undefined4 *)((int)this + 4);
  piVar2 = (int *)WorldCoordinateToScreenCoord(this_00,local_10,&local_18);
  pSVar4 = (SpriteS1 *)local_c;
  pSVar3 = (S9 *)WorldCoordinateToScreenCoord(this,local_8,(int *)&param_1);
  pSVar4 = S9::S9_FUN_00401b20(pSVar3,pSVar4,piVar2);
  *(SpriteS1 **)this = pSVar4->FirstElement;
  piVar5 = (int *)WorldCoordinateToScreenCoord(this_00,local_8,(int *)&param_1);
  pSVar4 = (SpriteS1 *)(local_8 + 4);
  piVar2 = &local_18;
  pS110 = &param_1;
  this_01 = Texture_Find(&local_14,local_c);
  pSVar3 = (S9 *)WorldCoordinateToScreenCoord(this_01,pS110,piVar2);
  pSVar4 = S9::S9_FUN_00401b20(pSVar3,pSVar4,piVar5);
  *this_00 = pSVar4->FirstElement;
  return;
}


void __thiscall S110__FUN_0041e210(void *this,S110 *param_1,Ped *param_2)

{
  S110 *this_00;
  Ped *pPVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  pPVar1 = param_2;
  piVar2 = (int *)FUN_0040f500(&param_2,param_2);
  this_00 = param_1;
  puVar3 = (undefined4 *)WorldCoordinateToScreenCoord(param_1,&param_1,piVar2);
  *(undefined4 *)this = *puVar3;
  piVar2 = (int *)FUN_0040f520(&param_2,pPVar1);
  puVar3 = (undefined4 *)WorldCoordinateToScreenCoord(this_00,&param_1,piVar2);
  *(undefined4 *)((int)this + 4) = *puVar3;
  return;
}


S110 * __thiscall S110__FUN_0041ff60(void *this,S110 *param_1)

{
  WorldCoordinateToScreenCoord
            (&DAT_006639a0 + (uint)*(byte *)((int)this + 2) * 4,param_1,
             (int *)&DAT_005e4fb4);
  return param_1;
}


void __thiscall S110__Car_FUN_00426580(Car *this,S110 *param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  void *pvVar3;
  int *piVar4;
  undefined3 extraout_var;
  S110 *pSVar5;
  undefined4 *puVar6;
  S169 **ppSVar7;
  Car *local_28 [2];
  S169 *local_20;
  Player *local_1c;
  undefined1 local_18 [8];
  S169 *local_10;
  undefined4 local_c;
  undefined4 local_8 [2];
  
  bVar1 = Car_FUN_004214d0(this);
  if (!bVar1) {
    CarMakeDriveable4(this);
    puVar2 = (undefined4 *)SpriteS1::FUN_004207b0(this->CarSprite,&local_20);
    local_10 = (S169 *)*puVar2;
    local_c = puVar2[1];
    pSVar5 = (S110 *)local_28;
    puVar2 = &gCarSystemManager->field18_0x1c;
    puVar6 = &DAT_005e4f38;
    pvVar3 = (void *)FUN_00401bd0(&DAT_005e4f40,&local_20,puVar2);
    piVar4 = (int *)Decoder_ProcessData(pvVar3,pSVar5,puVar6);
    FUN_0040e530(&local_10,piVar4);
    pSVar5 = (S110 *)local_18;
    puVar6 = &DAT_005e4f38;
    pvVar3 = (void *)FUN_00401bd0(&DAT_005e4f40,&local_20,puVar2);
    piVar4 = (int *)Decoder_ProcessData(pvVar3,pSVar5,puVar6);
    FUN_0040e530(&local_c,piVar4);
    puVar2 = (undefined4 *)FUN_0040f600(&local_10,local_18,param_1);
    local_20 = (S169 *)*puVar2;
    local_1c = (Player *)puVar2[1];
    piVar4 = Player::FUN_0041e260((Player *)&local_20,(int *)&param_1);
    param_1 = (S110 *)*piVar4;
    bVar1 = Car_FUN_00403820((Car *)&param_1,(int *)&gSpriteS1_0);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      local_28[0] = (Car *)0x4;
      piVar4 = (int *)FUN_00401bd0(&param_1,local_18,(int *)local_28);
      ppSVar7 = &local_20;
      pvVar3 = (void *)FUN_00420390(local_28);
      puVar2 = (undefined4 *)FUN_004202e0(pvVar3,ppSVar7,piVar4);
      local_8[0] = *puVar2;
      local_8[1] = puVar2[1];
      Player::cPlayer_FUN_0049ecc0(this->Player);
      FUN_004a31b0(&param_1,&local_10,local_8,10);
    }
  }
  gCarSystemManager->field18_0x1c = gCarSystemManager->field18_0x1c + 1;
  if (4 < (int)gCarSystemManager->field18_0x1c) {
    gCarSystemManager->field18_0x1c = 0;
  }
  return;
}


byte __thiscall S110__FUN_0045aea0(void *this,S110 *param_1,undefined4 param_2)

{
  undefined1 *this_00;
  S110 *pSVar1;
  bool bVar2;
  int *piVar3;
  undefined3 extraout_var;
  SpriteS1 *pSVar4;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  
  pSVar1 = param_1;
  this_00 = &param_1->field_0x14;
  piVar3 = (int *)Decoder_ProcessData((void *)((int)this + 0x20),(S110 *)&param_1,
                                    &param_2);
  bVar2 = Player::FUN_0040ce70((Player *)this_00,piVar3);
  if (CONCAT31(extraout_var,bVar2) != 0) {
    pSVar4 = S9::S9_FUN_00401b20((S9 *)((int)this + 0x24),
                                 (SpriteS1 *)&stack0xfffffff4,&param_2);
    bVar2 = Player::CheckCondition((Player *)this_00,(int *)pSVar4);
    if (CONCAT31(extraout_var_00,bVar2) != 0) {
      piVar3 = (int *)Decoder_ProcessData((void *)((int)this + 0x28),
                                        (S110 *)&stack0xfffffff8,&param_2);
      bVar2 = Player::FUN_0040ce70((Player *)&pSVar1->field15_0x18,piVar3);
      if (CONCAT31(extraout_var_01,bVar2) != 0) {
        pSVar4 = S9::S9_FUN_00401b20((S9 *)((int)this + 0x2c),
                                     (SpriteS1 *)&stack0xfffffffc,&param_2);
        bVar2 = Player::CheckCondition
                          ((Player *)&pSVar1->field15_0x18,(int *)pSVar4);
        if (CONCAT31(extraout_var_02,bVar2) != 0) {
          return 1;
        }
      }
    }
  }
  return 0;
}


S110 * __thiscall S110__S110(S110 *this)

{
  S110_FUN_004c5480(this);
  return this;
}


S110 * __thiscall S110__FUN_00482510(void *this,S110 *param_1)

{
  S3 *pS3;
  
                              // WARNING: Load size is inaccurate
  pS3 = *this;
  *(undefined1 **)this = &pS3[-0x112].field20_0x38;
  SpriteS1__LinkToS3((SpriteS1 *)param_1,pS3);
  return param_1;
}


void __thiscall S110__FUN_00482730(void *param_1,undefined4 *param_2,S110 *param_3)

{
  S110 *pSVar1;
  bool bVar2;
  int *this;
  undefined3 extraout_var;
  SpriteS1 *pSpriteS1;
  
  pSVar1 = param_3;
  pSpriteS1 = (SpriteS1 *)&DAT_006658dc;
  this = Matrix_Multiply(param_1,(int *)&param_3,param_3);
  bVar2 = FUN_004037e0(this,pSpriteS1);
  if (CONCAT31(extraout_var,bVar2) != 0) {
    *param_2 = _DAT_00665894;
    return;
  }
  *param_2 = pSVar1->car;
  return;
}


void __thiscall S110__FUN_00486580(void *this,int param_1,S110 *param_2)

{
  Player *pPVar1;
  char cVar2;
  bool bVar3;
  undefined4 *puVar4;
  S110 *pSVar5;
  void *pvVar6;
  undefined4 *puVar7;
  int *piVar8;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined1 *puVar9;
  short *psVar10;
  undefined1 local_60 [8];
  short local_58 [2];
  undefined1 local_54 [4];
  Player *local_50;
  Player *local_4c;
  Player *local_48;
  Player *local_44;
  S46 *local_40;
  S46 *local_3c;
  undefined1 local_38 [8];
  undefined1 local_30 [8];
  undefined1 local_28 [8];
  undefined1 local_20 [8];
  undefined1 local_18 [8];
  undefined1 local_10 [12];
  
  FUN_00482c30(local_30);
  FUN_00482c30(local_38);
  CarSystemManager::SetIndexDefautCarManager((CarSystemManager *)local_58);
  puVar4 = (undefined4 *)FUN_0040f600(local_38,&local_40,param_2);
  local_50 = (Player *)*puVar4;
  local_4c = (Player *)puVar4[1];
  cVar2 = FUN_00482c90();
  if (cVar2 == '\0') {
    puVar4 = (undefined4 *)FUN_00482c50(local_10);
    pPVar1 = (Player *)*puVar4;
    local_44 = (Player *)puVar4[1];
    local_48 = pPVar1;
    bVar3 = Player::IsCurrentPlayer((Player *)&local_50,(Player *)&DAT_00665894)
    ;
    if (CONCAT31(extraout_var,bVar3) != 0) {
      bVar3 = Player::IsCurrentPlayer
                        ((Player *)&local_4c,(Player *)&DAT_00665894);
      if (CONCAT31(extraout_var_00,bVar3) != 0) {
        local_4c = local_44;
        local_50 = pPVar1;
      }
    }
    puVar4 = (undefined4 *)FUN_00482c80(local_54);
    puVar4 = (undefined4 *)
             FUN_004a05c0(local_10,*puVar4,_DAT_0066583c,&local_48,&local_50,
                          param_2,local_38,local_30,_DAT_00665ae4,_DAT_00665ae4,
                          _DAT_00665a3c);
    local_40 = (S46 *)*puVar4;
    local_3c = (S46 *)puVar4[1];
  }
  else {
    pSVar5 = (S110 *)FUN_00482c50(&local_40);
    puVar9 = local_60;
    pvVar6 = (void *)FUN_00482c50(local_28);
    puVar4 = (undefined4 *)FUN_0040f600(pvVar6,puVar9,pSVar5);
    local_48 = (Player *)*puVar4;
    local_44 = (Player *)puVar4[1];
    puVar4 = (undefined4 *)FUN_00482c80(local_60);
    puVar7 = (undefined4 *)FUN_00482c80(local_54);
    puVar4 = (undefined4 *)
             FUN_004a05c0(local_20,*puVar7,*puVar4,&local_48,&local_50,param_2,
                          local_38,local_30,_DAT_00665ae4,_DAT_00665ae4,
                          _DAT_006659f0);
    local_40 = (S46 *)*puVar4;
    local_3c = (S46 *)puVar4[1];
    piVar8 = (int *)FUN_00482c80(local_54);
    puVar9 = local_18;
    pvVar6 = (void *)FUN_0040f640(local_10);
    pvVar6 = FUN_004202e0(pvVar6,puVar9,piVar8);
    FUN_00484a40(pvVar6);
  }
  if (*(int *)((int)this + 0x10) != 0) {
    local_58[0] = *(short *)(*(int *)((int)this + 0x10) + 4);
  }
  piVar8 = (int *)FUN_00482c80(local_54);
  pvVar6 = FUN_004202e0(&local_40,local_10,piVar8);
  FUN_00484a40(pvVar6);
  if ((DAT_00665798 != '\0') && (*(int *)((int)this + 0x10) != 0)) {
    psVar10 = (short *)&DAT_00665ad0;
    pvVar6 = (void *)FUN_0040eab0(local_60,(CarSystemManager *)
                                           (*(int *)((int)this + 0x10) + 4),
                                  local_58);
    bVar3 = FUN_0041e0f0(pvVar6,psVar10);
    if (CONCAT31(extraout_var_01,bVar3) != 0) {
      FUN_0041fa70(&DAT_006659a4);
    }
  }
  FUN_00486410((void *)param_1,*(S46 **)((int)this + 4));
  FUN_00486410(this,*(S46 **)(param_1 + 4));
  return;
}


void __thiscall S110__FUN_004867e0(void *param_1,int param_2,S110 *param_3)

{
  Ped *this;
  Passenger *pPVar1;
  bool bVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 uVar6;
  void *pvVar7;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  S46 *pSVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 *local_50;
  undefined4 local_4c;
  Passenger *local_48;
  Passenger *local_44;
  undefined1 local_40 [8];
  int local_38;
  Ped *local_34;
  undefined1 local_30 [8];
  undefined1 local_28 [8];
  undefined1 local_20 [8];
  undefined1 local_18 [8];
  undefined1 local_10 [12];
  
  this = *(Ped **)(param_2 + 0x7c);
  puVar3 = (undefined4 *)Ped__GetYCoordinate(this,(int)&local_50);
  puVar4 = (undefined4 *)Ped__GetXCoordinate(this,(int)&local_48);
  String_ParseLine(local_30,puVar4,puVar3);
  FUN_00482c30(local_40);
  piVar5 = (int *)FUN_0040f600(local_40,&local_48,param_3);
  local_38 = *piVar5;
  local_34 = (Ped *)piVar5[1];
  local_50 = (undefined4 *)FUN_00482c80(&local_48);
  puVar10 = local_30;
  puVar9 = local_40;
  piVar5 = &local_38;
  uVar11 = _DAT_00665ae4;
  uVar12 = _DAT_006659ec;
  uVar13 = _DAT_006659d4;
  uVar6 = FUN_00493780(local_28);
  puVar3 = (undefined4 *)
           FUN_004a05c0(local_20,*local_50,_DAT_00665824,uVar6,piVar5,param_3,
                        puVar9,puVar10,uVar11,uVar12,uVar13);
  local_50 = (undefined4 *)*puVar3;
  local_4c = puVar3[1];
  piVar5 = (int *)FUN_00482c80(&local_48);
  pvVar7 = FUN_004202e0(&local_50,local_18,piVar5);
  FUN_00484a40(pvVar7);
  piVar5 = (int *)&DAT_00665824;
  puVar10 = local_10;
  pvVar7 = (void *)FUN_0040f640(local_18);
  FUN_004202e0(pvVar7,puVar10,piVar5);
  pPVar1 = _DAT_00665894;
  local_48 = _DAT_00665894;
  local_44 = _DAT_00665894;
  bVar2 = Car::Car_FUN_00403820((Car *)&local_48,(int *)&DAT_00665894);
  if (CONCAT31(extraout_var,bVar2) == 0) {
    bVar2 = Car::Car_FUN_00403820((Car *)&local_44,(int *)&DAT_00665894);
    if (CONCAT31(extraout_var_00,bVar2) == 0) goto LAB_00486936;
  }
  FUN_00497570(0,0,pPVar1,pPVar1);
LAB_00486936:
  pSVar8 = (S46 *)FUN_004338d0(param_2);
  FUN_00486410(param_1,pSVar8);
  return;
}


void __thiscall S110__S97_FUN_0048d4e0(Particles *this,S110 *param_1)

{
  S169 *this_00;
  char cVar1;
  void *pvVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  SpriteS1 *pSVar6;
  int iVar7;
  int *piVar8;
  undefined2 *puVar9;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  short *unaff_ESI;
  void *unaff_EDI;
  int z;
  short rot;
  undefined1 local_30 [12];
  undefined1 local_24 [4];
  SpriteS1 *local_20 [2];
  SpriteS1 *local_18;
  SpriteS1 *local_14;
  S3 *local_10;
  SpriteS1 *local_c [2];
  
  CarSystemManager::SetIndexDefautCarManager((CarSystemManager *)(local_30 + 4))
  ;
  if (gSkipParticles == false) {
    if (this->field0_0x0 == 0) {
      local_24 = (undefined1  [4])&stack0xffffffb8;
      z = extraout_ECX;
      rot = _DAT_00669ee0;
      Decoder_ShiftLeft(&stack0xffffffb8,(void *)0x0);
      local_24 = (undefined1  [4])&stack0xffffffb4;
      iVar7 = extraout_ECX_00;
      Decoder_ShiftLeft(&stack0xffffffb4,(void *)0x0);
      local_24 = (undefined1  [4])&stack0xffffffb0;
      iVar3 = extraout_ECX_01;
      Decoder_ShiftLeft(&stack0xffffffb0,(void *)0x0);
      pvVar2 = Object::SpawnObject(_gObject,0xc2,iVar3,iVar7,z,rot);
      this->field0_0x0 = pvVar2;
    }
    Decoder_ShiftLeft(local_30,(void *)0x0);
    Decoder_ShiftLeft(local_24,(void *)0x0);
    local_20[0] = (SpriteS1 *)&stack0xffffffbc;
    Decoder_ShiftLeft(&stack0xffffffbc,(void *)0x0);
    local_20[0] = (SpriteS1 *)&stack0xffffffb8;
    Decoder_ShiftLeft(&stack0xffffffb8,(void *)0x0);
    local_20[0] = (SpriteS1 *)&stack0xffffffb4;
    Decoder_ShiftLeft(&stack0xffffffb4,(void *)0x0);
    iVar3 = FUN_0048c930(local_30._0_4_,local_24);
    if (iVar3 != 0) {
      *(uint *)(iVar3 + 4) = *(uint *)(iVar3 + 4) | 1;
      SpriteS1::S38_FUN_004206f0(*(SpriteS1 **)(iVar3 + 0x30),8);
      SpriteS1::S38_FUN_004206c0
                (*(SpriteS1 **)(iVar3 + 0x30),*(short *)(_gS57 + 0x8ca4) + 0x49)
      ;
      puVar4 = (undefined4 *)
               WorldCoordinateToScreenCoord
                         (&DAT_00669ee4,local_20,(int *)&DAT_00669f78);
      puVar5 = (undefined4 *)
               WorldCoordinateToScreenCoord
                         (&DAT_00669ee4,local_24,(int *)&DAT_00669f78);
      SpriteS1::S38_FUN_004bcb90
                (*(SpriteS1 **)(iVar3 + 0x30),*puVar5,*puVar4,_DAT_0066a0f4);
      *(undefined4 *)(iVar3 + 0x34) = 0;
      *(undefined4 *)(iVar3 + 0x38) = 0x1f;
      FUN_0041fc20(local_24,param_1,(S110 *)&DAT_00669e94,(Ped *)local_24,
                   (Ped *)local_30);
      *(undefined2 *)(iVar3 + 0x2c) = 100;
      *(undefined1 *)(iVar3 + 0x46) = 0;
      *(undefined1 *)(iVar3 + 0x48) = 0;
      pSVar6 = S9::S9_FUN_00401b20((S9 *)local_24,(SpriteS1 *)local_20,
                                   (int *)&param_1->field_0x14);
      _DAT_00669f80 = pSVar6->FirstElement;
      pSVar6 = S9::S9_FUN_00401b20((S9 *)local_30,(SpriteS1 *)local_20,
                                   (int *)&param_1->field15_0x18);
      _DAT_0066a1ec = pSVar6->FirstElement;
      local_24 = *(undefined1 (*) [4])&param_1->count;
      iVar7 = SpriteS1::FUN_00416b40((SpriteS1 *)param_1);
      if (iVar7 == 2) {
        this_00 = param_1->S169;
        piVar8 = Car::Car_FUN_004be980((Car *)this_00,0x72);
        if (piVar8 == (int *)0x0) {
          piVar8 = Car::Car_FUN_004be980((Car *)this_00,0xf8);
          local_30._4_2_ = *(undefined2 *)*piVar8;
          Decoder_ShiftLeft(local_30,(void *)0x0);
          FUN_00432860(&local_18,(undefined4 *)local_30,
                       (undefined4 *)&DAT_00669f34);
          FUN_0040f6b0(&local_18,(S110 *)(local_30 + 4));
          Decoder_ShiftLeft(local_30,(void *)0x0);
          puVar4 = (undefined4 *)&DAT_0066a1c0;
        }
        else {
          puVar9 = (undefined2 *)
                   FUN_0040e5a0((void *)*piVar8,(short *)local_30,
                                (short *)&DAT_0066a090,unaff_EDI,unaff_ESI);
          local_30._4_2_ = *puVar9;
          Decoder_ShiftLeft(local_30,(void *)0x0);
          FUN_00432860(&local_18,(undefined4 *)local_30,
                       (undefined4 *)&DAT_00669ff8);
          FUN_0040f6b0(&local_18,(S110 *)(local_30 + 4));
          Decoder_ShiftLeft(local_30,(void *)0x0);
          puVar4 = (undefined4 *)&DAT_0066a06c;
        }
        FUN_00432860(&local_10,(undefined4 *)local_30,puVar4);
        SpriteS1::SetRotation
                  (*(SpriteS1 **)(iVar3 + 0x30),(short)local_30._4_4_);
        FUN_0040f6b0(&local_10,param_1);
        SpriteS1::FUN_004207b0((SpriteS1 *)param_1,local_20);
        iVar7 = FUN_0040f5c0();
        FUN_0040f680(&local_18,iVar7);
        FUN_004a0d10();
      }
      else {
        puVar4 = (undefined4 *)Texture_Find(&DAT_0066a180,local_20);
        local_10 = (S3 *)*puVar4;
        pSVar6 = S9::S9_FUN_00401b20((S9 *)&DAT_00669e94,(SpriteS1 *)local_20,
                                     (int *)&DAT_0066a150);
        local_c[0] = pSVar6->FirstElement;
        FUN_0040f6b0(&local_10,param_1);
        puVar4 = (undefined4 *)FUN_0040f5c0();
        local_10 = (S3 *)*puVar4;
        local_c[0] = *(SpriteS1 **)(puVar4 + 1);
        SpriteS1::SetRotation
                  (*(SpriteS1 **)(iVar3 + 0x30),*(short *)&param_1->car);
        local_30._4_4_ =
             S9::S9_FUN_00401b20((S9 *)&param_1->field15_0x18,
                                 (SpriteS1 *)local_20,(int *)local_c);
        pSVar6 = S9::S9_FUN_00401b20((S9 *)&param_1->field_0x14,
                                     (SpriteS1 *)local_30,(int *)&local_10);
        local_14 = *(SpriteS1 **)local_30._4_4_;
        local_18 = pSVar6->FirstElement;
      }
      SpriteS1::SetPosition
                (*(SpriteS1 **)(iVar3 + 0x30),(int)local_18,(int)local_14,
                 (int)local_24);
      *(S110 **)(iVar3 + 0x28) = param_1;
      cVar1 = SpriteS1::S38_FUN_004bd670(*(SpriteS1 **)(iVar3 + 0x30));
      if (cVar1 != '\0') {
        *(undefined2 *)(iVar3 + 0x2c) = 0;
      }
      S56::S56_FUN_00447ba0(gS56_ARR2,*(SpriteS1 **)(iVar3 + 0x30));
      FUN_004337f0(*(int *)(iVar3 + 0x30));
    }
  }
  return;
}


void __fastcall S110__FUN_0049e3c0(S110 *param_1)

{
  bool bVar1;
  int *piVar2;
  S9 *this;
  SpriteS1 *pSVar3;
  undefined3 extraout_var;
  SpriteS1 *pSpriteS1;
  int local_c [2];
  int local_4;
  
  pSpriteS1 = (SpriteS1 *)&DAT_0066ad48;
  piVar2 = Matrix_Multiply(param_1,local_c,(S110 *)&param_1->pPed);
  pSVar3 = (SpriteS1 *)(local_c + 1);
  this = (S9 *)Matrix_Multiply(pSVar3,&local_4,param_1);
  pSVar3 = S9::S9_FUN_00401b20(this,pSVar3,piVar2);
  bVar1 = FUN_004037e0(pSVar3,pSpriteS1);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    param_1->car = (Car *)_DAT_0066acdc;
    param_1->pPed = _DAT_0066acdc;
  }
  return;
}


void * __thiscall S110__FUN_004a0d10(Player *param_1,void *param_2,S110 *param_3)

{
  FUN_0049eca0(param_1);
  Player::cPlayer_FUN_0049e5a0(param_1,param_2,param_3);
  return param_2;
}


S110 * __thiscall S110__FUN_004b3110(int param_1,S110 *param_2)

{
  Decoder_ProcessData((void *)(param_1 + 0x24),param_2,(void *)(param_1 + 0x20));
  return param_2;
}


S110 * __thiscall S110__FUN_004b3130(int param_1,S110 *param_2)

{
  Decoder_ProcessData((void *)(param_1 + 0x2c),param_2,(void *)(param_1 + 0x28));
  return param_2;
}


void __thiscall S110__S110_FUN_004c5480(S110 *this)

{
  this->field16_0x1a = 150;
  this->field18_0x1e = 0;
  this->field20_0x20 = 0;
  this->field21_0x24 = 0;
  this->car = (Car *)0x0;
  this->pPed = (Ped *)0x0;
  this->field22_0x28 = 0;
  this->S169 = (S169 *)0x0;
  this->field23_0x2c = 0;
  this->count = 0;
  return;
}


void __thiscall S110__S110_FUN_004c5480(S110 *this)

{
  this->field16_0x1a = 0x96;
  this->field18_0x1e = 0;
  this->field20_0x20 = 0;
  this->field21_0x24 = 0;
  this->car = (Car *)0x0;
  this->pPed = (Ped *)0x0;
  this->field22_0x28 = 0;
  this->S169 = (S169 *)0x0;
  this->field23_0x2c = 0;
  this->count = 0;
  return;
}


