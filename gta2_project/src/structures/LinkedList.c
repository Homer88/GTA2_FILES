// Module: S1
// Functions working with structure S1
// Generated from gta2.exe.c

#include "common.h"

void * __thiscall S1__S1_FUN_0041e1e0(S1 *this)

{
  S1 *pSVar1;
  S1 *local_4;
  
  local_4 = this;
  Decoder_ShiftLeft(&local_4,(void *)0x0);
  this->CurrentElement = local_4;
  pSVar1 = local_4;
  Decoder_ShiftLeft(&local_4,(void *)0x0);
  this->S1_ = local_4;
  return pSVar1;
}


void __thiscall S1__S1_FUN_00447f60(S1 *this,undefined4 param_1)

{
  this[1].field39_0x98 = param_1;
  return;
}


void __thiscall S1__S1_FUN_0049def0(S1 *this)

{
  void *pvVar1;
  int iVar2;
  
  _DAT_0066acd0 = this->S103;
  _DAT_0066acd4 = this->field6_0x34;
  _DAT_0066ac88 = this->field22_0x6c;
  _DAT_0066ac54 = this->special_buffer;
  _DAT_0066ac8c = this->S103_1;
  _DAT_0066ac90 = this->field8_0x3c;
  _DAT_0066abc4 = this->field23_0x70;
  _DAT_0066abc8 = this->field21_0x68;
  pvVar1 = this->Car_2->S___;
  if (pvVar1 != (void *)0x0) {
    iVar2 = *(int *)(*(int *)((int)pvVar1 + 0xc) + 0x58);
    _DAT_0066ad68 = *(undefined4 *)(iVar2 + 0x30);
    _DAT_0066ad6c = *(undefined4 *)(iVar2 + 0x34);
    _DAT_0066ab98 = *(undefined4 *)(iVar2 + 0x6c);
    _DAT_0066ae44 = *(undefined2 *)(iVar2 + 0x58);
    _DAT_0066ae54 = *(undefined4 *)(iVar2 + 0x38);
    _DAT_0066ae58 = *(undefined4 *)(iVar2 + 0x3c);
    _DAT_0066ac7c = *(undefined4 *)(iVar2 + 0x70);
    _DAT_0066ac0c = *(undefined4 *)(iVar2 + 0x68);
  }
  return;
}


byte __thiscall S1__S1_FUN_0049e270(S1 *this)

{
  void *pvVar1;
  byte bVar2;
  byte bVar3;
  
  gCarSystemManager->field46_0x68 = false;
  bVar2 = S56::S56_FUN_00447480(gS56_ARR1,this->Car_2->CarSprite);
  pvVar1 = this->Car_2->S___;
  if (pvVar1 != (void *)0x0) {
    bVar3 = S56::S56_FUN_00447480
                      (gS56_ARR1,
                       *(SpriteS1 **)(*(int *)((int)pvVar1 + 0xc) + 0x50));
    bVar2 = bVar2 | bVar3;
  }
  return bVar2;
}


void __thiscall S1__S1_FUN_0049edc0(S1 *this)

{
  undefined4 *puVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined1 local_8 [8];
  
  local_10 = *(undefined4 *)(_DAT_0066ab78 + 0xc);
  local_c = *(undefined4 *)(_DAT_0066ab78 + 0x10);
  FUN_0040f6b0(&local_10,(S110 *)&this->special_buffer);
  puVar1 = (undefined4 *)FUN_0040f5c0(local_8,&local_10);
  this->S103 = (S1 *)*puVar1;
  this->field6_0x34 = puVar1[1];
  return;
}


void __thiscall S1__S1_FUN_0049f350(S1 *this)

{
  Ped *pPVar1;
  byte bVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  S169 *this_00;
  undefined3 extraout_var;
  int *piVar9;
  Car *local_4;
  Car *pCar;
  
  local_4 = (Car *)this->field22_0x6c;
  iVar5 = Decoder_DecodeFloat(&local_4);
  iVar6 = Decoder_DecodeFloat(&this->field8_0x3c);
  iVar7 = Decoder_DecodeFloat(&this->S103_1);
  bVar2 = MapRelatedStruct::S16_FUN_00466cf0
                    (_gMapRelatedStruct,iVar7,iVar6,iVar5);
  if (bVar2 == 0) {
    puVar8 = (undefined4 *)
             Decoder_ProcessData(&this->field22_0x6c,(S110 *)&local_4,
                               &DAT_0066ac4c);
    local_4 = (Car *)*puVar8;
  }
  iVar5 = Decoder_DecodeFloat(&local_4);
  iVar6 = Decoder_DecodeFloat(&this->field8_0x3c);
  iVar7 = Decoder_DecodeFloat(&this->S103_1);
  iVar5 = MapRelatedStruct::S16_FUN_004653c0
                    (_gMapRelatedStruct,iVar7,iVar6,iVar5);
  if ((iVar5 != 0) &&
     ((bVar2 = *(byte *)(iVar5 + 0xb) & 3, bVar2 == 2 || (bVar2 == 3)))) {
    pCar = this->Car_2;
    pPVar1 = pCar->Driver;
    if (pPVar1 != (Ped *)0x0) {
      bVar3 = Car::IsTrainOrTrainCarriage(pCar);
      if (!bVar3) {
        piVar9 = (int *)&DAT_0066af5c;
        this_00 = (S169 *)GetSpeed(this,&local_4);
        bVar3 = S169::FUN_00403800(this_00,piVar9);
        if (CONCAT31(extraout_var,bVar3) == 0) {
          bVar2 = Car::Car_FUN_00411970(pCar);
          if (bVar2 == 0) goto LAB_0049f420;
        }
        FUN_004350a0(pPVar1);
      }
    }
  }
LAB_0049f420:
  if (((0 < (int)this->aasss) && ((int)this->aasss < 3)) &&
     (cVar4 = *(char *)&this->NextElement + -1,
     *(char *)&this->NextElement = cVar4, cVar4 == '\0')) {
    local_4 = (Car *)0x0;
    Player::cPlayer_FUN_0049dd20((Player *)this,&local_4);
  }
  return;
}


void __thiscall S1__S1_FUN_004a0290(S1 *this)

{
  int iVar1;
  char cVar2;
  bool bVar3;
  void *this_00;
  undefined4 *puVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined4 *puVar5;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  S1 *this_01;
  int iVar6;
  int *piVar7;
  int iVar8;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c [4];
  undefined1 local_8 [8];
  
  cVar2 = FUN_0041f940(this->Car_2);
  if (cVar2 == '\0') {
    S1_FUN_0041e1e0((S1 *)this->ARR4_S41);
    S1_FUN_0041e1e0((S1 *)(this->ARR4_S41 + 1));
    S1_FUN_0041e1e0((S1 *)(this->ARR4_S41 + 2));
    this_01 = (S1 *)(this->ARR4_S41 + 3);
  }
  else {
    if ((this->field40_0x9c == 2) || (this->field40_0x9c == 10)) {
      iVar6 = 2;
    }
    else {
      iVar6 = 0;
    }
    puVar4 = &local_10;
    piVar7 = (int *)&DAT_0066adf0;
    this_00 = (void *)FUN_0048a930(&local_14);
    puVar4 = (undefined4 *)WorldCoordinateToScreenCoord(this_00,puVar4,piVar7);
    iVar1 = _DAT_0066ab78;
    local_18 = *puVar4;
    puVar4 = (undefined4 *)
             FUN_00421910(&local_10,*(undefined4 *)(_DAT_0066ab78 + 8));
    local_14 = *puVar4;
    puVar4 = (undefined4 *)FUN_00421910(&local_10,*(undefined4 *)(iVar1 + 4));
    iVar8 = this->field39_0x98;
    local_10 = *puVar4;
    if (((iVar8 == 7) || (iVar8 == 8)) || (iVar8 == 9)) {
      puVar4 = &local_14;
      puVar5 = (undefined4 *)Texture_Find(&local_18,local_c);
      String_ParseLine(local_8,puVar5,puVar4);
      FUN_004a0120(this,0,(S110 *)*puVar5,(Ped *)puVar5[1],3);
      puVar4 = &local_14;
      String_ParseLine(local_8,&local_18,puVar4);
      iVar8 = 3;
LAB_004a0408:
      FUN_004a0120(this,1,(S110 *)*puVar4,(Ped *)puVar4[1],iVar8);
    }
    else {
      bVar3 = Player::FUN_0040ce70
                        ((Player *)&this->field29_0x88,(int *)(iVar1 + 0x28));
      if (CONCAT31(extraout_var,bVar3) == 0) {
        if (this->field_0xac != '\0') {
          bVar3 = S169::FUN_00403800((S169 *)(iVar1 + 0x20),(int *)&DAT_0066acdc
                                    );
          if (CONCAT31(extraout_var_00,bVar3) != 0) goto LAB_004a0369;
        }
      }
      else {
LAB_004a0369:
        if (iVar8 != 6) {
          puVar4 = &local_14;
          puVar5 = (undefined4 *)Texture_Find(&local_18,local_c);
          String_ParseLine(local_8,puVar5,puVar4);
          FUN_004a0120(this,0,(S110 *)*puVar5,(Ped *)puVar5[1],iVar6);
          puVar4 = &local_14;
          String_ParseLine(local_8,&local_18,puVar4);
          iVar8 = iVar6;
          goto LAB_004a0408;
        }
      }
      S1_FUN_0041e1e0((S1 *)this->ARR4_S41);
      S1_FUN_0041e1e0((S1 *)(this->ARR4_S41 + 1));
    }
    iVar8 = this->field39_0x98;
    if (((iVar8 == 7) || (iVar8 == 8)) || (iVar8 == 9)) {
      puVar4 = &local_10;
      puVar5 = (undefined4 *)Texture_Find(&local_18,local_c);
      String_ParseLine(local_8,puVar5,puVar4);
      FUN_004a0120(this,3,(S110 *)*puVar5,(Ped *)puVar5[1],3);
      puVar4 = &local_10;
      String_ParseLine(local_8,&local_18,puVar4);
      iVar6 = 3;
LAB_004a04bb:
      FUN_004a0120(this,2,(S110 *)*puVar4,(Ped *)puVar4[1],iVar6);
      goto LAB_004a0540;
    }
    bVar3 = Player::FUN_0040ce70
                      ((Player *)&this->field28_0x84,
                       (int *)(_DAT_0066ab78 + 0x24));
    if (CONCAT31(extraout_var_01,bVar3) == 0) {
      if (this->field_0xac != '\0') {
        bVar3 = S169::FUN_00403800((S169 *)(_DAT_0066ab70 + 8),
                                   (int *)&DAT_0066acdc);
        if (CONCAT31(extraout_var_02,bVar3) != 0) goto LAB_004a0474;
      }
    }
    else {
LAB_004a0474:
      if (iVar8 != 6) {
        puVar4 = &local_10;
        puVar5 = (undefined4 *)Texture_Find(&local_18,local_c);
        String_ParseLine(local_8,puVar5,puVar4);
        FUN_004a0120(this,3,(S110 *)*puVar5,(Ped *)puVar5[1],iVar6);
        puVar4 = &local_10;
        String_ParseLine(local_8,&local_18,puVar4);
        goto LAB_004a04bb;
      }
    }
    S1_FUN_0041e1e0((S1 *)(this->ARR4_S41 + 3));
    this_01 = (S1 *)(this->ARR4_S41 + 2);
  }
  S1_FUN_0041e1e0(this_01);
LAB_004a0540:
  if (this->field_0xac != '\0') {
    this->field_0xac = this->field_0xac + -1;
  }
  return;
}


void __thiscall S1__S1_FUN_004a0560(S1 *this)

{
  void *pvVar1;
  Player *this_00;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  
  if (!gSkipSkidMarks) {
    S1_FUN_004a0290(this);
    pvVar1 = this->Car_2->S___;
    if (pvVar1 != (void *)0x0) {
      this_00 = *(Player **)(*(int *)((int)pvVar1 + 0xc) + 0x58);
      Player::cPlayer_FUN_0049ecc0(this_00);
      uVar3 = DAT_0066acdc_1;
      uVar2 = uRam0066acdf;
      this_00->field67_0x84 = DAT_0066acdc;
      *(undefined2 *)&this_00->field_0x85 = uVar3;
      this_00->field70_0x87 = uVar2;
      uVar2 = (undefined1)DAT_0066acdc_1;
      uVar4 = DAT_0066acdc_1._1_1_;
      uVar5 = uRam0066acdf;
      this_00->field71_0x88 = DAT_0066acdc;
      this_00->field72_0x89 = uVar2;
      this_00->field73_0x8a = uVar4;
      this_00->field74_0x8b = uVar5;
      S1_FUN_004a0290((S1 *)this_00);
      Player::cPlayer_FUN_0049ecc0((Player *)this);
      return;
    }
  }
  return;
}


void __thiscall S1__S1_FUN_004a0930(S1 *this)

{
  void *pvVar1;
  int iVar2;
  undefined1 local_c [4];
  undefined1 local_8 [8];
  
  pvVar1 = Player::cPlayer_FUN_0049f660((Player *)this,local_c);
  iVar2 = FUN_0041e1a0(local_8,pvVar1);
  FUN_0040f680(&this->field11_0x48,iVar2);
  return;
}


void __thiscall S1__S1_FUN_004a1be0(S1 *this)

{
  undefined4 uVar1;
  S1 *local_4;
  
  local_4 = this;
  S1_FUN_0041e1e0((S1 *)&this->S1_5);
  Decoder_ShiftLeft(&local_4,(void *)0x0);
  this->field24_0x74 = local_4;
  this->field23_0x70 = _DAT_0066acdc;
  Player::cPlayer_FUN_0049fac0((Player *)this);
  this->field32_0x91 = 0;
  this->field33_0x92 = 0;
  this->byte = 0;
  this->field35_0x94 = 0;
  this->field36_0x95 = 0;
  this->field48_0xad = 0;
  this->field44_0xa9 = 0xff;
  this->field43_0xa8 = 0;
  this->field31_0x90 = 0;
  local_4 = (S1 *)0x0;
  Player::cPlayer_FUN_0049dd20((Player *)this,&local_4);
  *(undefined1 *)&this->NextElement = 0;
  this->field39_0x98 = 0;
  this->field40_0x9c = 0;
  *(undefined1 *)((int)&this->NextElement + 1) = 0;
  *(undefined1 *)((int)&this->NextElement + 2) = 0;
  S1_FUN_0041e1e0((S1 *)this->ARR4_S41);
  S1_FUN_0041e1e0((S1 *)(this->ARR4_S41 + 1));
  S1_FUN_0041e1e0((S1 *)(this->ARR4_S41 + 2));
  S1_FUN_0041e1e0((S1 *)(this->ARR4_S41 + 3));
  this->S1 = (S1 *)0x1;
  this->SS = 0;
  uVar1 = _DAT_0066ae74;
  this->field_0xac = 0;
  this->field19_0x60 = uVar1;
  this->field20_0x64 = _DAT_0066abe4;
  this->field21_0x68 = _DAT_0066acdc;
  this->field28_0x84 = _DAT_0066acdc;
  this->field29_0x88 = _DAT_0066acdc;
  this->field_0xaa = 0;
  this->field_0xab = 0;
  return;
}


void __thiscall S1__S1_dop(S1 *this)

{
  S1_FUN_0041e1e0((S1 *)&this->S103);
  this->special_buffer = _DAT_0066ac08;
  S1_FUN_0041e1e0((S1 *)&this->S103_1);
  this->Car_2 = (Car *)0x0;
  S1_FUN_004a1be0(this);
  S1_FUN_0041e1e0(this);
  return;
}


S1 * __thiscall S1__S1(S1 *this)

{
  _eh_vector_constructor_iterator_
            (this->ARR4_S41,8,4,S41::S41,(_func_void_void_ptr *)&S41::~S41);
  CarSystemManager::SetIndexDefautCarManager
            ((CarSystemManager *)&this->special_buffer);
  this->FistElement = (S1 *)0x0;
  S1_dop(this);
  return this;
}


void __fastcall S1__FUN_004a20e0(S1 *param_1)

{
  bool bVar1;
  int *piVar2;
  void *pvVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  undefined1 local_30 [4];
  undefined1 local_2c [4];
  undefined1 local_28 [4];
  undefined1 local_24 [4];
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  undefined1 local_18 [4];
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  undefined1 local_c [4];
  undefined4 local_8;
  undefined4 local_4;
  
  if ((((*(char *)((int)&param_1->NextElement + 1) == '\x01') &&
       (param_1->field33_0x92 == 0)) && (param_1->field32_0x91 == 0)) &&
     (bVar1 = Car::IsTrainOrTrainCarriage(param_1->Car_2), !bVar1)) {
    switch(param_1->field39_0x98) {
    case 1:
      local_8 = _DAT_0066acdc;
      piVar2 = (int *)FUN_004634e0(local_30,1);
      puVar4 = (undefined4 *)
               WorldCoordinateToScreenCoord(&DAT_0066b044,local_2c,piVar2);
      local_4 = *puVar4;
      S1::S1_FUN_004a0930(param_1);
      return;
    case 2:
      local_8 = _DAT_0066acdc;
      piVar2 = (int *)FUN_004634e0(local_28,1);
      puVar5 = local_24;
      pvVar3 = Texture_Find(&DAT_0066b044,local_20);
      puVar4 = (undefined4 *)WorldCoordinateToScreenCoord(pvVar3,puVar5,piVar2);
      local_4 = *puVar4;
      break;
    case 3:
      piVar2 = (int *)FUN_004634e0(local_1c,1);
      puVar4 = (undefined4 *)
               WorldCoordinateToScreenCoord(&DAT_0066b044,local_18,piVar2);
      local_8 = *puVar4;
      local_4 = _DAT_0066acdc;
      S1::S1_FUN_004a0930(param_1);
      return;
    case 4:
      piVar2 = (int *)FUN_004634e0(local_14,1);
      puVar5 = local_10;
      pvVar3 = Texture_Find(&DAT_0066b044,local_c);
      puVar4 = (undefined4 *)WorldCoordinateToScreenCoord(pvVar3,puVar5,piVar2);
      local_8 = *puVar4;
      local_4 = _DAT_0066acdc;
      break;
    default:
      goto switchD_004a212f_caseD_4;
    }
    S1::S1_FUN_004a0930(param_1);
  }
switchD_004a212f_caseD_4:
  return;
}


void __thiscall S1__S1_FUN_004a2980(S1 *this)

{
  void *pvVar1;
  Player *this_00;
  char cVar2;
  char cVar3;
  undefined4 local_8;
  undefined4 local_4;
  
  cVar2 = FUN_004a26c0(&local_8);
  pvVar1 = this->Car_2->S___;
  if (pvVar1 == (void *)0x0) {
    if (cVar2 != '\0') {
      FUN_0049ff80(local_8);
    }
  }
  else {
    this_00 = *(Player **)(*(int *)((int)pvVar1 + 0xc) + 0x58);
    Player::cPlayer_FUN_0049ecc0(this_00);
    cVar3 = FUN_004a26c0(&local_4);
    if ((cVar3 != '\0') && ((cVar2 != '\0' || (this->field39_0x98 == 6)))) {
      FUN_0049ff80(local_4);
    }
    Player::cPlayer_FUN_0049ecc0((Player *)this);
    if (((cVar3 != '\0') || (this_00->State == 6)) && (cVar2 != '\0')) {
      FUN_0049ff80(local_8);
      return;
    }
  }
  return;
}


void __fastcall S1__FUN_004a2a30(S1 *param_1)

{
  bool bVar1;
  uint16_t *puVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined4 *puVar3;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  void *unaff_ESI;
  undefined4 uVar4;
  undefined *puVar5;
  short *in_stack_ffffffec;
  uint16_t local_10 [4];
  undefined1 local_8 [8];
  
  CarSystemManager::SetIndexDefautCarManager((CarSystemManager *)local_10);
  if (param_1->field35_0x94 == 0) {
    local_10[0] = param_1->special_buffer;
  }
  else {
    puVar2 = (uint16_t *)
             FUN_0040e5a0(&param_1->special_buffer,(short *)&stack0xffffffee,
                          (short *)&DAT_0066ae50,unaff_ESI,in_stack_ffffffec);
    local_10[0] = *puVar2;
  }
  bVar1 = S169::FUN_00403800((S169 *)&DAT_0066afb4,(int *)&DAT_0066acdc);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    bVar1 = FUN_0041e0f0((CarSystemManager *)local_10,(short *)&DAT_0066afac);
    if (CONCAT31(extraout_var_02,bVar1) == 0) {
      bVar1 = FUN_0041e0f0(local_10,(short *)&DAT_0066ae50);
      uVar4 = _DAT_0066ae3c;
      if (CONCAT31(extraout_var_03,bVar1) == 0) goto LAB_004a2b02;
    }
    else {
      puVar3 = (undefined4 *)Texture_Find(&DAT_0066ae3c,local_10);
      uVar4 = *puVar3;
    }
  }
  else {
    bVar1 = CarSystemManager::greater_than
                      ((CarSystemManager *)local_10,(short *)&DAT_0066ad38);
    uVar4 = _DAT_0066ae3c;
    if (CONCAT31(extraout_var_00,bVar1) == 0) {
      bVar1 = CarSystemManager::greater_than
                        ((CarSystemManager *)local_10,(short *)&DAT_0066ae50);
      if (CONCAT31(extraout_var_01,bVar1) == 0) goto LAB_004a2b02;
      puVar3 = (undefined4 *)Texture_Find(&DAT_0066ae3c,local_10);
      uVar4 = *puVar3;
    }
  }
  FUN_0049e330(uVar4);
LAB_004a2b02:
  puVar2 = local_10;
  puVar5 = &DAT_0066aea8;
  FUN_00420390(local_8);
  FUN_0041e1a0(puVar2,puVar5);
  S1::S1_FUN_004a0930(param_1);
  param_1->field_0xaa = 1;
  return;
}


void __fastcall S1__FUN_004a2b40(S1 *param_1)

{
  bool bVar1;
  uint16_t *puVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined4 *puVar3;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined3 extraout_var_05;
  void *unaff_ESI;
  undefined4 uVar4;
  undefined *puVar5;
  short *in_stack_ffffffec;
  uint16_t local_10 [4];
  undefined1 local_8 [8];
  
  CarSystemManager::SetIndexDefautCarManager((CarSystemManager *)local_10);
  if (param_1->field35_0x94 == 0) {
    local_10[0] = param_1->special_buffer;
  }
  else {
    puVar2 = (uint16_t *)
             FUN_0040e5a0(&param_1->special_buffer,(short *)&stack0xffffffee,
                          (short *)&DAT_0066ae50,unaff_ESI,in_stack_ffffffec);
    local_10[0] = *puVar2;
  }
  bVar1 = S169::FUN_00403800((S169 *)&DAT_0066afb8,(int *)&DAT_0066acdc);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    bVar1 = FUN_0041e0f0((CarSystemManager *)local_10,(short *)&DAT_0066afac);
    uVar4 = _DAT_0066ae3c;
    if (CONCAT31(extraout_var_04,bVar1) == 0) {
      bVar1 = CarSystemManager::greater_than
                        ((CarSystemManager *)local_10,(short *)&DAT_0066ad38);
      if (CONCAT31(extraout_var_05,bVar1) == 0) goto LAB_004a2c31;
      puVar3 = (undefined4 *)Texture_Find(&DAT_0066ae3c,local_10);
      uVar4 = *puVar3;
    }
  }
  else {
    bVar1 = CarSystemManager::greater_than
                      ((CarSystemManager *)local_10,(short *)&DAT_0066afac);
    if ((CONCAT31(extraout_var_00,bVar1) == 0) ||
       (bVar1 = FUN_0041e0f0(local_10,(short *)&DAT_0066ae50),
       CONCAT31(extraout_var_01,bVar1) == 0)) {
      bVar1 = CarSystemManager::greater_than
                        ((CarSystemManager *)local_10,(short *)&DAT_0066ae50);
      if ((CONCAT31(extraout_var_02,bVar1) == 0) ||
         (bVar1 = FUN_0041e0f0(local_10,(short *)&DAT_0066ad38),
         uVar4 = _DAT_0066ae3c, CONCAT31(extraout_var_03,bVar1) == 0))
      goto LAB_004a2c31;
    }
    else {
      puVar3 = (undefined4 *)Texture_Find(&DAT_0066ae3c,local_10);
      uVar4 = *puVar3;
    }
  }
  FUN_0049e330(uVar4);
LAB_004a2c31:
  puVar2 = local_10;
  puVar5 = &DAT_0066aea8;
  FUN_00420390(local_8);
  FUN_0041e1a0(puVar2,puVar5);
  S1::S1_FUN_004a0930(param_1);
  param_1->field_0xaa = 1;
  return;
}


void __fastcall S1__FUN_004a2c70(S1 *param_1)

{
  byte bVar1;
  bool bVar2;
  S63 *pSVar3;
  undefined4 *puVar4;
  S110 *pSVar5;
  undefined3 extraout_var;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined1 local_1c [8];
  undefined4 local_14 [2];
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  pSVar3 = SpriteS1::SpriteS1_FUN_0040fec0(DAT_005e6894);
  if ((pSVar3 == (S63 *)0x0) || (pSVar3->DamageType != 0xa6)) {
    bVar1 = Car::IsDriverPlayer(param_1->Car_2);
    if (bVar1 == 0) {
      local_c = _DAT_0066abcc;
      uVar6 = _DAT_0066ae40;
    }
    else {
      local_c = _DAT_0066af80;
      uVar6 = _DAT_0066acf8;
    }
  }
  else {
    local_c = _DAT_0066aea8;
    uVar6 = _DAT_0066ae3c;
  }
  local_14[0] = uVar6;
  puVar4 = (undefined4 *)
           FUN_0040f600(&param_1->S103_1,local_1c,(S110 *)&DAT_0066ad08);
  local_8 = *puVar4;
  local_4 = puVar4[1];
  pSVar5 = (S110 *)PedPool_Get(&param_1->special_buffer,local_1c);
  FUN_0040f6b0(&local_8,pSVar5);
  bVar2 = FUN_004037e0(&local_8,(SpriteS1 *)&DAT_0066acdc);
  if (CONCAT31(extraout_var,bVar2) == 0) {
    puVar4 = (undefined4 *)Texture_Find(local_14,local_1c);
    uVar6 = *puVar4;
  }
  FUN_0049e330(uVar6);
  puVar4 = &local_c;
  puVar7 = &local_8;
  FUN_00420390(local_14);
  FUN_0041e1a0(puVar7,puVar4);
  S1::S1_FUN_004a0930(param_1);
  return;
}


void __thiscall S1__S1_FUN_004a3120(S1 *this)

{
  int iVar1;
  
  iVar1 = _DAT_0066ac4c;
  _DAT_0066afc0 = _DAT_0066ac4c;
  S1_FUN_0049def0(this);
  Player::cPlayer_FUN_004a2e30((Player *)this,iVar1);
  return;
}


undefined4 __thiscall S1__S1_FUN_004a4570(S1 *this)

{
  int iVar1;
  byte bVar2;
  undefined4 uVar3;
  uint3 uVar4;
  byte local_1;
  
  Player::cPlayer_FUN_0049ecc0((Player *)this);
  bVar2 = Car::Car_FUN_004220a0(this->Car_2);
  if (bVar2 != this->field44_0xa9) {
    this->field44_0xa9 = bVar2;
    S1_FUN_0049edc0(this);
  }
  this->field28_0x84 = _DAT_0066acdc;
  this->field29_0x88 = _DAT_0066acdc;
  switch(this->S1) {
  case (S1 *)0x0:
    bVar2 = S1_FUN_0049e270(this);
    S1_FUN_0049f350(this);
    uVar3 = FUN_004a4490(&this->CurrentElement);
    local_1 = FUN_004a2db0();
    local_1 = bVar2 | (byte)uVar3 | local_1;
    break;
  case (S1 *)0x1:
    FUN_0049f500();
    bVar2 = S1_FUN_0049e270(this);
    FUN_0049dd30();
    goto LAB_004a45db;
  case (S1 *)0x2:
    FUN_0049f500();
    bVar2 = S1_FUN_0049e270(this);
LAB_004a45db:
    FUN_0049f280();
    FUN_004a16b0();
    FUN_004a2f20();
    FUN_0049ea70();
    FUN_004a1b20();
    FUN_0049f4e0();
    FUN_004a17c0();
    S1_FUN_0049f350(this);
    uVar3 = FUN_004a4490(&this->CurrentElement);
    local_1 = FUN_004a2db0();
    local_1 = bVar2 | (byte)uVar3 | local_1;
    S1_FUN_004a0560(this);
    FUN_0049f4f0();
    FUN_0049ea60();
    goto LAB_004a46ff;
  case (S1 *)0x3:
    bVar2 = S1_FUN_0049e270(this);
    FUN_004a2f20();
    S1_FUN_0049f350(this);
    FUN_004a2db0();
    uVar3 = FUN_004a4490(&this->CurrentElement);
    local_1 = FUN_004a2db0();
    local_1 = bVar2 | (byte)uVar3 | local_1;
    S1_FUN_004a0560(this);
    bVar2 = Car::IsDriverPlayer(this->Car_2);
    if (bVar2 != 0) {
      Player::Player_FUN_004212b0((Player *)this);
      goto LAB_004a46ff;
    }
    goto LAB_004a46f4;
  case (S1 *)0x4:
    local_1 = S1_FUN_0049e270(this);
    S1_FUN_004a3120(this);
    S1_FUN_004a2980(this);
    break;
  default:
    local_1 = (byte)((uint)this >> 0x18);
    goto LAB_004a46ff;
  }
  S1_FUN_004a0560(this);
  bVar2 = Car::IsDriverPlayer(this->Car_2);
  if (bVar2 == 0) {
LAB_004a46f4:
    Player::SetAttackChanged((Player *)this);
  }
  else {
    Player::Player_FUN_004212b0((Player *)this);
  }
LAB_004a46ff:
  uVar3 = FUN_004a1ba0();
  uVar4 = (uint3)((uint)uVar3 >> 8);
  if (((((char)uVar3 != '\0') && (local_1 == 0)) &&
      (iVar1 = this->field39_0x98, iVar1 != 7)) &&
     ((iVar1 != 8 && (iVar1 != 6)))) {
    return CONCAT31(uVar4,1);
  }
  return (uint)uVar4 << 8;
}


