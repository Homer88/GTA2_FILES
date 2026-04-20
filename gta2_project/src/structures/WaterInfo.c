// Module: S103
// Functions working with structure S103
// Generated from gta2.exe.c

#include "common.h"

void __thiscall S103__S103_FUN_00447d40(S103 *this)

{
  CameraOrPhysics *pCVar1;
  Player *pPVar2;
  int iVar3;
  SpriteS1 *pSVar4;
  
  if (this->Arr_S104_10[0].field89_0x150 != 0) {
    pCVar1 = this->Arr_S104_10[0].CameraOrPhysics;
    pPVar2 = this->Arr_S104_10[0].Player1;
    iVar3 = this->Arr_S104_10[0].field40_0xa0;
    this->Arr_S104_10[0].field89_0x150 = 3;
    this->Arr_S104_10[0].CameraOrPhysics2 = pCVar1;
    this->Arr_S104_10[0].Player3 = pPVar2;
    this->Arr_S104_10[0].field70_0x118 = iVar3;
    pSVar4 = DAT_005e7824;
    this->Arr_S104_10[0].CameraOrPhysics1 = pCVar1;
    this->Arr_S104_10[0].field71_0x11c = pSVar4;
    this->Arr_S104_10[0].field45_0xb4 = iVar3;
    this->Arr_S104_10[0].Player2 = pPVar2;
    this->Arr_S104_10[0].SpriteS1_2 = pSVar4;
    this->Arr_S104_10[0].field86_0x14d = 0;
    return;
  }
  this->Arr_S104_10[0].CameraOrPhysics1 = DAT_005e7554;
  this->Arr_S104_10[0].Player2 = this->Arr_S104_10[0].Player4;
  this->Arr_S104_10[0].field45_0xb4 = DAT_005e7494;
  this->Arr_S104_10[0].SpriteS1_2 = DAT_005e7598;
  this->Arr_S104_10[0].field86_0x14d = 0;
  return;
}


void __thiscall S103__S103_FUN_00447f40(S103 *this)

{
  Player::IsCurrentPlayer
            ((Player *)&this->Arr_S104_10[0].Player1,
             (Player *)&this->Arr_S104_10[0].Player4);
  return;
}


byte __thiscall S103__S103_FUN_00448090(S103 *this)

{
  char cVar1;
  int *piVar2;
  short *psVar3;
  SpriteS1 *pSVar4;
  Car *local_c;
  Ped *local_8;
  S169 *local_4;
  
  FUN_0040f540(&local_c,(int)&this->Arr_S104_10[0].Player3);
  FUN_00447f90(this->Arr_S104_10[0].CameraOrPhysics2,local_c,&local_8);
  FUN_0040f680(&local_8,(int)&this->Arr_S104_10[0].field2_0x8);
  piVar2 = (int *)Decoder_ProcessData(&this->Arr_S104_10[0].field32_0x80,
                                    (S110 *)&local_c,
                                    &this->Arr_S104_10[0].field71_0x11c);
  SpriteS1::SetPosition
            (this->Arr_S104_10[0].SpriteS1_4,(int)local_8,(int)local_4,*piVar2);
  psVar3 = (short *)FUN_0040f540(&local_c,(int)&this->Arr_S104_10[0].
                                                field70_0x118);
  SpriteS1::SetRotation(this->Arr_S104_10[0].SpriteS1_4,*psVar3);
  pSVar4 = S56::S56_FUN_00447740(gS56,this->Arr_S104_10[0].SpriteS1_4,0);
  if (pSVar4 == (SpriteS1 *)0x0) {
    cVar1 = SpriteS1::S38_FUN_004bd670(this->Arr_S104_10[0].SpriteS1_4);
    if (cVar1 == '\0') {
      return 1;
    }
  }
  return 0;
}


void __thiscall S103__S103_FUN_004481f0(S103 *this)

{
  Car *pCar;
  SpriteS1 *pSprite;
  
  pSprite = this->Arr_S104_10[0].SpriteS1_1;
  pCar = (Car *)SpriteS1::GetObject(pSprite);
  S56::S56_FUN_00447c00(gS56,pSprite);
  Car::Car_FUN_00424400(pCar);
  Car::CarMakeDriveable4(pCar);
  CarsPrefabs::S5_FUN_00420f20(gCarsPrefabs,pCar);
  Car::Car_FUN_00447ea0(pCar);
  if (this->Arr_S104_10[0].field89_0x150 != 3) {
    if (this->Arr_S104_10[0].field83_0x144 == 2) {
      if (this->Arr_S104_10[0].field91_0x155 == 1) {
        this->Arr_S104_10[0].field91_0x155 = 2;
        goto LAB_00448272;
      }
      this->Arr_S104_10[0].field91_0x155 = 1;
      pSprite = this->Arr_S104_10[0].SpriteS1_1;
    }
    else {
      pSprite = this->Arr_S104_10[0].SpriteS1_1;
    }
    FUN_004bed60(&this->Arr_S104_10[0].Turrel,(S63 *)pSprite);
  }
LAB_00448272:
  this->Arr_S104_10[0].SpriteS1_1 = (SpriteS1 *)0x0;
  this->Arr_S104_10[0].field89_0x150 = 0;
  S103_FUN_00447d40(this);
  return;
}


void __thiscall S103__S103_FUN_00448290(S103 *this)

{
  Car *pCar;
  
  pCar = (Car *)SpriteS1::GetObject(this->Arr_S104_10[0].SpriteS1_1);
  CarsPrefabs::S5_FUN_00420f20(gCarsPrefabs,pCar);
  Car::Car_FUN_00447ea0(pCar);
  S56::S56_FUN_00447c00(gS56,this->Arr_S104_10[0].SpriteS1_1);
  SpriteS1::FUN_004b9d50
            (this->Arr_S104_10[0].SpriteS1,(int)this->Arr_S104_10[0].SpriteS1_1,
             DAT_005e7598,DAT_005e7598,DAT_005e74f4);
  FUN_004bed60(&this->Arr_S104_10[0].Turrel,(S63 *)this->Arr_S104_10[0].SpriteS1
              );
  this->Arr_S104_10[0].SpriteS1_1 = (SpriteS1 *)0x0;
  this->Arr_S104_10[0].field89_0x150 = 0;
  this->Arr_S104_10[0].SpriteS1 = (SpriteS1 *)0x0;
  S103_FUN_00447d40(this);
  return;
}


byte __thiscall S103__S103_FUN_00448730(S103 *this)

{
  SpriteS1 *this_00;
  bool bVar1;
  Car *pCVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  int *piVar3;
  undefined3 extraout_var_02;
  S103 *local_4;
  
  local_4 = this;
  pCVar2 = (Car *)SpriteS1::GetObject((SpriteS1 *)
                                      this->Arr_S104_10[0].field28_0x70);
  bVar1 = Car::IsMask5(pCVar2);
  if (bVar1) {
    return 0;
  }
  this_00 = (SpriteS1 *)this->Arr_S104_10[0].field27_0x6c;
  pCVar2 = (Car *)SpriteS1::GetObject(this_00);
  bVar1 = Car::IsMask5(pCVar2);
  if (!bVar1) {
    bVar1 = Car::Car_FUN_00403820
                      ((Car *)&this->Arr_S104_10[0].field63_0xfc,
                       &this_00->S3_arr5031[0].PositionX);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      bVar1 = Car::Car_FUN_00403820
                        ((Car *)&this->Arr_S104_10[0].field64_0x100,
                         &this_00->S3_arr5031[0].PositionY);
      if (CONCAT31(extraout_var_00,bVar1) == 0) {
        bVar1 = Car::Car_FUN_00403820
                          ((Car *)&this->Arr_S104_10[0].field65_0x104,
                           &this_00->S3_arr5031[0].PositionZ);
        if (CONCAT31(extraout_var_01,bVar1) == 0) {
          piVar3 = (int *)FUN_0040f580(&local_4,this_00);
          bVar1 = Car::Car_FUN_00403820
                            ((Car *)&this->Arr_S104_10[0].field66_0x108,piVar3);
          if (CONCAT31(extraout_var_02,bVar1) == 0) {
            return 1;
          }
        }
      }
    }
  }
  return 0;
}


byte __thiscall S103__S103_FUN_004487d0(S103 *this)

{
  SpriteS1 *this_00;
  bool bVar1;
  char cVar2;
  Car *this_01;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  int *piVar3;
  undefined3 extraout_var_02;
  S103 *local_4;
  
  this_00 = (SpriteS1 *)this->Arr_S104_10[0].field26_0x68;
  local_4 = this;
  this_01 = (Car *)SpriteS1::GetObject(this_00);
  bVar1 = Car::IsMask5(this_01);
  if (!bVar1) {
    bVar1 = Car::Car_FUN_00403820
                      ((Car *)&this->Arr_S104_10[0].field56_0xe0,
                       &this_00->S3_arr5031[0].PositionX);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      bVar1 = Car::Car_FUN_00403820
                        ((Car *)&this->Arr_S104_10[0].field57_0xe4,
                         &this_00->S3_arr5031[0].PositionY);
      if (CONCAT31(extraout_var_00,bVar1) == 0) {
        bVar1 = Car::Car_FUN_00403820
                          ((Car *)&this->Arr_S104_10[0].field58_0xe8,
                           &this_00->S3_arr5031[0].PositionZ);
        if (CONCAT31(extraout_var_01,bVar1) == 0) {
          piVar3 = (int *)FUN_0040f580(&local_4,this_00);
          bVar1 = Car::Car_FUN_00403820
                            ((Car *)&this->Arr_S104_10[0].field59_0xec,piVar3);
          if ((CONCAT31(extraout_var_02,bVar1) == 0) &&
             (this_01->Driver == (Ped *)0x0)) {
            cVar2 = FUN_00423a70();
            if (cVar2 != '\0') {
              return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}


bool __thiscall S103__S103_FUN_00448870(S103 *this)

{
  SpriteS1 *this_00;
  bool bVar1;
  Car *this_01;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  int *piVar2;
  undefined3 extraout_var_02;
  int iVar3;
  S103 *local_4;
  
  this_00 = this->Arr_S104_10[0].SpriteS1;
  local_4 = this;
  this_01 = (Car *)SpriteS1::GetObject(this_00);
  bVar1 = Car::IsMask5(this_01);
  if (!bVar1) {
    bVar1 = Car::Car_FUN_00403820
                      ((Car *)&this->Arr_S104_10[0].Car1,
                       &this_00->S3_arr5031[0].PositionX);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      bVar1 = Car::Car_FUN_00403820
                        ((Car *)&this->Arr_S104_10[0].Car2,
                         &this_00->S3_arr5031[0].PositionY);
      if (CONCAT31(extraout_var_00,bVar1) == 0) {
        bVar1 = Car::Car_FUN_00403820
                          ((Car *)&this->Arr_S104_10[0].Car3,
                           &this_00->S3_arr5031[0].PositionZ);
        if (CONCAT31(extraout_var_01,bVar1) == 0) {
          piVar2 = (int *)FUN_0040f580(&local_4,this_00);
          bVar1 = Car::Car_FUN_00403820
                            ((Car *)&this->Arr_S104_10[0].Car4,piVar2);
          if (CONCAT31(extraout_var_02,bVar1) == 0) {
            iVar3 = FUN_004bea90(this_01,2);
            return iVar3 == 0;
          }
        }
      }
    }
  }
  return false;
}


byte __thiscall S103__S103_FUN_00448c00(S103 *this)

{
  CameraOrPhysics **this_00;
  Player **this_01;
  CameraOrPhysics *pCVar1;
  bool bVar2;
  undefined3 extraout_var;
  SpriteS1 *pSVar3;
  undefined4 local_4;
  
  this_00 = &this->Arr_S104_10[0].CameraOrPhysics2;
  bVar2 = Player::IsCurrentPlayer((Player *)this_00,(Player *)&DAT_005e756c);
  pCVar1 = DAT_005e74ec;
  if (CONCAT31(extraout_var,bVar2) != 0) {
    *this_00 = DAT_005e74ec;
    return (byte)pCVar1;
  }
  *this_00 = DAT_005e756c;
  this_01 = &this->Arr_S104_10[0].Player3;
  pSVar3 = S9::S9_FUN_00401b20((S9 *)this_01,(SpriteS1 *)&stack0xfffffff8,
                               (int *)&DAT_005e7784);
  pSVar3 = pSVar3->FirstElement;
  FUN_0040e790(&local_4,pSVar3);
  *this_01 = (Player *)pSVar3->FirstElement;
  return (byte)pSVar3;
}


void __thiscall S103__S103_FUN_00448df0(S103 *this)

{
  ushort uVar1;
  int iVar2;
  undefined4 in_EAX;
  
  uVar1 = this->Arr_S104_10[0].field80_0x140;
  if (uVar1 != 0) {
    MissionManager::MissionManager_FUN_0047edb0
              (_gMissionManager,CONCAT22((short)((uint)in_EAX >> 0x10),uVar1));
  }
  iVar2 = this->Arr_S104_10[0].field89_0x150;
  if (iVar2 != 1) {
    if ((1 < iVar2) && (iVar2 < 5)) {
      S103_FUN_004481f0(this);
      return;
    }
    return;
  }
  S103_FUN_00448290(this);
  return;
}


byte __thiscall S103__S103_FUN_00449880(S103 *this)

{
  int iVar1;
  SpriteS1 *pSVar2;
  uint uVar3;
  Player *pPVar4;
  byte bVar5;
  bool bVar6;
  
  if (this->Arr_S104_10[0].field27_0x6c != 0) {
    bVar5 = S103_FUN_00448730(this);
    if (bVar5 == 0) {
      this->Arr_S104_10[0].field27_0x6c = 0;
      this->Arr_S104_10[0].field85_0x14c = 0x3c;
    }
  }
  if (this->Arr_S104_10[0].field26_0x68 != 0) {
    bVar5 = S103_FUN_004487d0(this);
    if (bVar5 == 0) {
      this->Arr_S104_10[0].field26_0x68 = 0;
      this->Arr_S104_10[0].field85_0x14c = 0x3c;
    }
  }
  if (this->Arr_S104_10[0].SpriteS1 != (SpriteS1 *)0x0) {
    bVar6 = S103_FUN_00448870(this);
    if (!bVar6) {
      this->Arr_S104_10[0].SpriteS1 = (SpriteS1 *)0x0;
      this->Arr_S104_10[0].field85_0x14c = 0x3c;
    }
  }
  iVar1 = this->Arr_S104_10[0].field89_0x150;
  if (((iVar1 == 2) || (iVar1 == 3)) || (iVar1 == 4)) {
    bVar5 = S103_FUN_00448090(this);
    if (bVar5 == 0) {
      this->Arr_S104_10[0].field86_0x14d = 0;
      if (this->Arr_S104_10[0].field89_0x150 != 4) {
        S103_FUN_00448c00(this);
      }
    }
    else {
      this->Arr_S104_10[0].field86_0x14d = 1;
    }
  }
  iVar1 = this->Arr_S104_10[0].field89_0x150;
  if (((iVar1 == 2) || (iVar1 == 3)) || (iVar1 == 4)) {
    this->Arr_S104_10[0].CameraOrPhysics1 =
         this->Arr_S104_10[0].CameraOrPhysics2;
    iVar1 = this->Arr_S104_10[0].field2_0x8;
    this->Arr_S104_10[0].Player2 = this->Arr_S104_10[0].Player3;
    this->Arr_S104_10[0].field45_0xb4 = this->Arr_S104_10[0].field70_0x118;
    this->Arr_S104_10[0].field0_0x0 = iVar1;
    this->Arr_S104_10[0].field1_0x4 = (void *)this->Arr_S104_10[0].field3_0xc;
    this->Arr_S104_10[0].SpriteS1_2 =
         (SpriteS1 *)this->Arr_S104_10[0].field71_0x11c;
    return (byte)iVar1;
  }
  if ((iVar1 == 1) && (this->Arr_S104_10[0].SpriteS1 != (SpriteS1 *)0x0)) {
    this->Arr_S104_10[0].Player2 = (Player *)this->Arr_S104_10[0].field48_0xc0;
    this->Arr_S104_10[0].CameraOrPhysics1 =
         (CameraOrPhysics *)this->Arr_S104_10[0].field47_0xbc;
    this->Arr_S104_10[0].field86_0x14d = 1;
    this->Arr_S104_10[0].field45_0xb4 = (int)this->Arr_S104_10[0].Car4;
    S1::S1_FUN_0041e1e0((S1 *)this);
    pSVar2 = (SpriteS1 *)this->Arr_S104_10[0].field53_0xd4;
    this->Arr_S104_10[0].SpriteS1_2 = pSVar2;
    return (byte)pSVar2;
  }
  if (this->Arr_S104_10[0].field27_0x6c != 0) {
    iVar1 = this->Arr_S104_10[0].field66_0x108;
    this->Arr_S104_10[0].CameraOrPhysics1 =
         (CameraOrPhysics *)this->Arr_S104_10[0].field61_0xf4;
    this->Arr_S104_10[0].Player2 = (Player *)this->Arr_S104_10[0].field62_0xf8;
    this->Arr_S104_10[0].field45_0xb4 = iVar1;
    this->Arr_S104_10[0].field86_0x14d = 1;
    this->Arr_S104_10[0].SpriteS1_2 =
         (SpriteS1 *)this->Arr_S104_10[0].field67_0x10c;
    return (byte)iVar1;
  }
  if ((this->Arr_S104_10[0].field26_0x68 != 0) &&
     ((((this->Arr_S104_10[0].SpriteS1 != (SpriteS1 *)0x0 ||
        (uVar3 = this->Arr_S104_10[0].field83_0x144, uVar3 == 1)) ||
       (uVar3 == 2)) || (uVar3 == 3)))) {
    pPVar4 = (Player *)this->Arr_S104_10[0].field55_0xdc;
    this->Arr_S104_10[0].CameraOrPhysics1 =
         (CameraOrPhysics *)this->Arr_S104_10[0].field54_0xd8;
    this->Arr_S104_10[0].Player2 = pPVar4;
    this->Arr_S104_10[0].field45_0xb4 = this->Arr_S104_10[0].field59_0xec;
    this->Arr_S104_10[0].field86_0x14d = 1;
    this->Arr_S104_10[0].SpriteS1_2 =
         (SpriteS1 *)this->Arr_S104_10[0].field60_0xf0;
    return (byte)pPVar4;
  }
  bVar5 = this->Arr_S104_10[0].field85_0x14c;
  this->Arr_S104_10[0].field86_0x14d = 0;
  if (bVar5 == 0) {
    S103_FUN_00447d40(this);
    return bVar5;
  }
  this->Arr_S104_10[0].field85_0x14c = bVar5 - 1;
  return bVar5 - 1;
}


void __thiscall S103__S103_FUN_00449aa0(S103 *this)

{
  uint uVar1;
  byte bVar2;
  bool bVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  Player *local_10;
  CameraOrPhysics *local_c;
  Passenger *local_8;
  Player *local_4;
  
  local_c = this->Arr_S104_10[0].CameraOrPhysics;
  local_10 = this->Arr_S104_10[0].Player1;
  local_8 = (Passenger *)this->Arr_S104_10[0].field40_0xa0;
  local_4 = this->Arr_S104_10[0].Player;
  bVar2 = FUN_00448c60(this);
  bVar3 = Car::Car_FUN_00403820
                    ((Car *)&local_10,(int *)&this->Arr_S104_10[0].Player1);
  if (CONCAT31(extraout_var,bVar3) == 0) {
    bVar3 = Car::Car_FUN_00403820
                      ((Car *)&local_c,
                       (int *)&this->Arr_S104_10[0].CameraOrPhysics);
    if (CONCAT31(extraout_var_00,bVar3) == 0) {
      bVar3 = Car::Car_FUN_00403820
                        ((Car *)&local_8,&this->Arr_S104_10[0].field40_0xa0);
      if (CONCAT31(extraout_var_01,bVar3) == 0) {
        bVar3 = Car::Car_FUN_00403820
                          ((Car *)&local_4,(int *)&this->Arr_S104_10[0].Player);
        if (CONCAT31(extraout_var_02,bVar3) == 0) goto LAB_00449b33;
      }
    }
  }
  FUN_00448e30(this);
LAB_00449b33:
  if (bVar2 != 0) {
    if (this->Arr_S104_10[0].field27_0x6c != 0) {
      FUN_00448300(this);
      return;
    }
    if ((this->Arr_S104_10[0].field26_0x68 != 0) &&
       ((((this->Arr_S104_10[0].SpriteS1 != (SpriteS1 *)0x0 ||
          (uVar1 = this->Arr_S104_10[0].field83_0x144, uVar1 == 1)) ||
         (uVar1 == 2)) || (uVar1 == 3)))) {
      FUN_00448450(this);
      return;
    }
    S103_FUN_00448df0(this);
  }
  return;
}


void __thiscall S103__S103_FUN_00449ba0(S103 *this)

{
  char cVar1;
  int iVar2;
  GameObject *this_00;
  S103 *pS103;
  SpriteS1 *pSprite;
  
  *(undefined1 *)((int)&this->Arr_S104_10[0].field94_0x158 + 1) = 0;
  iVar2 = General::GetCycle(gGeneral);
  Turrel::Turrel_FUN_004bed00((Turrel *)&this->Arr_S104_10[0].Turrel,iVar2 + -1)
  ;
  pSprite = this->Arr_S104_10[0].SpriteS1_1;
  if (pSprite != (SpriteS1 *)0x0) {
    S56::S56_FUN_00447bd0(gS56_ARR2,pSprite);
  }
  S103_FUN_00449880(this);
  iVar2 = this->Arr_S104_10[0].field84_0x148;
  if (iVar2 == 0) {
    pS103 = this->Arr_S104_10[0].s103;
    if (pS103 != (S103 *)0x0) {
      S103_FUN_00447f40(this);
      cVar1 = (char)iVar2;
      if ((cVar1 != '\0') && (S103_FUN_00447f40(pS103), cVar1 == '\0'))
      goto LAB_00449c09;
    }
    S103_FUN_00449aa0(this);
  }
LAB_00449c09:
  pSprite = this->Arr_S104_10[0].SpriteS1_1;
  if (pSprite != (SpriteS1 *)0x0) {
    this_00 = SpriteS1::GetObject(pSprite);
    GameObject::GameObject_FUN_00429fc0(this_00);
  }
  pSprite = this->Arr_S104_10[0].SpriteS1_1;
  if (pSprite != (SpriteS1 *)0x0) {
    S56::S56_FUN_00447ba0(gS56_ARR2,pSprite);
  }
  return;
}


void __thiscall S103__S103_FUN_00449c40(S103 *this)

{
  int iVar1;
  S103 *pS113;
  
  iVar1 = 0;
  pS113 = this;
  if (0 < this->count) {
    do {
      S103_FUN_00449ba0(pS113);
      iVar1 = iVar1 + 1;
      pS113 = (S103 *)(pS113->Arr_S104_10 + 1);
    } while (iVar1 < this->count);
  }
  return;
}


S103 * __thiscall S103__S103(S103 *this)

{
  _eh_vector_constructor_iterator_(this,0x15c,10,S104::S104,S104::~S104);
  this->count = 0;
  return this;
}


