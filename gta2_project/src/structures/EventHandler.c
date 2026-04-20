// Module: S63
// Functions working with structure S63
// Generated from gta2.exe.c

#include "common.h"

S63 * __thiscall S63__FUN_0041d030(S63 *param_1,byte param_2)

{
  S63::~S63(param_1);
  if ((param_2 & 1) != 0) {
    _free(param_1);
  }
  return param_1;
}


undefined1 __thiscall S63__S63_FUN_00420ff0(S63 *this)

{
  return this->field17_0x26;
}


byte __thiscall S63__S63_FUN_00421080(S63 *this)

{
  int iVar1;
  
  iVar1 = *(int *)(this->Struc___ + 0x34);
  if ((((iVar1 != 6) && (iVar1 != 7)) && (iVar1 != 8)) &&
     (((iVar1 != 9 && (iVar1 != 10)) && ((iVar1 != 1 && (iVar1 != 0xc)))))) {
    return 1;
  }
  return 0;
}


byte __thiscall S63__FUN_004210b0(S63 *this)

{
  return *(int *)(this->Struc___ + 0x40) == 3;
}


int __thiscall S63__Car_FUN_004274c0(Car *this,S63 *param_1)

{
  char cVar1;
  byte bVar2;
  char cVar3;
  bool bVar4;
  short sVar5;
  int iVar6;
  uint3 extraout_var;
  undefined4 uVar7;
  int iVar8;
  undefined2 extraout_var_01;
  S110 *pSVar9;
  void *pvVar10;
  undefined1 *puVar11;
  undefined2 extraout_var_02;
  undefined2 extraout_var_03;
  undefined2 extraout_var_04;
  undefined3 extraout_var_00;
  Ped *this_00;
  SpriteS1 *pSVar12;
  undefined1 *puVar13;
  undefined4 *puVar14;
  undefined4 local_108;
  S46 *local_104;
  Ped *local_100;
  undefined4 local_fc;
  undefined1 local_f6 [2];
  undefined1 local_f4 [2];
  undefined1 local_f2 [2];
  undefined1 local_f0 [8];
  undefined1 local_e8 [8];
  undefined1 local_e0 [8];
  undefined1 local_d8 [8];
  undefined1 local_d0 [8];
  undefined1 local_c8 [8];
  undefined1 local_c0 [8];
  undefined1 local_b8 [8];
  undefined1 local_b0 [8];
  undefined1 local_a8 [8];
  undefined1 local_a0 [8];
  undefined1 local_98 [8];
  undefined1 local_90 [8];
  undefined1 local_88 [8];
  undefined1 local_80 [8];
  undefined1 local_78 [8];
  undefined1 local_70 [8];
  undefined1 local_68 [8];
  undefined1 local_60 [8];
  undefined1 local_58 [8];
  undefined1 local_50 [8];
  undefined1 local_48 [8];
  undefined1 local_40 [8];
  undefined1 local_38 [8];
  undefined1 local_30 [8];
  undefined1 local_28 [8];
  undefined1 local_20 [8];
  undefined1 local_18 [8];
  undefined1 local_10 [12];
  
  local_100 = (Ped *)0x0;
  local_fc = 0;
  cVar1 = S63::S63_FUN_00420ff0(param_1);
  this_00 = (Ped *)0x0;
  if (cVar1 != '\0') {
    bVar2 = S63::S63_FUN_00420ff0(param_1);
    iVar6 = S68::S68GetPedID(_gS68,bVar2);
    if (iVar6 == 0) {
      local_100 = (Ped *)0x0;
    }
    else {
      local_100 = Char::FindPed(gChar,iVar6);
      if (local_100 != (Ped *)0x0) {
        Car_FUN_00441450(local_100,this,param_1->DamageType);
      }
    }
    iVar6 = param_1->DamageType;
    if ((((iVar6 == 0x9a) || (iVar6 == 0xc1)) || (iVar6 == 0xc3)) ||
       ((iVar6 == 0x9f || (this_00 = local_100, iVar6 == 199))))
    goto LAB_004279d2;
  }
  if ((this->Driver != (Ped *)0x0) && (param_1->DamageType != 10)) {
    cVar1 = Ped::sPed_FUN_00420b50(this->Driver);
    cVar3 = S63::S63_FUN_00420ff0(param_1);
    this_00 = local_100;
    if (cVar3 == cVar1) {
      return (uint)extraout_var << 8;
    }
  }
  if (((param_1->DamageType != 0xc6) &&
      (cVar1 = FUN_0044ab20(param_1->DamageType), cVar1 == '\0')) &&
     (this_00 != (Ped *)0x0)) {
    this->lastDamagingPed = (Ped *)this_00->ID;
    uVar7 = FUN_0044ab80(param_1->DamageType);
    this->DamageType = uVar7;
    this->DamageShotTimer = 0x32;
  }
  FUN_00476530(this->ID_Object,param_1->DamageType,0);
  iVar6 = param_1->DamageType;
  if (iVar6 < 0xc3) {
    if (iVar6 == 0xc2) {
      Car_FUN_00425770(this);
      if ((char)iVar6 == '\0') {
        puVar11 = local_c0;
        puVar14 = &DAT_005e4e7c;
        uVar7 = SpriteS1::FUN_004207b0(this->CarSprite,local_b0);
        puVar13 = local_a0;
        SpriteS1::FUN_004207b0(param_1->SpriteS1,local_90);
        FUN_0040f5c0(puVar13,uVar7);
        uVar7 = FUN_0041e1a0(puVar11,puVar14);
        iVar6 = FUN_00436220(this_00);
        sVar5 = Car_CollisionOnCar(this,iVar6 * 100,uVar7);
        local_fc = CONCAT22(extraout_var_03,sVar5);
      }
    }
    else if (iVar6 == 10) {
      if (gCarSystemManager->field46_0x68 == false) {
        gCarSystemManager->field46_0x68 = true;
        cVar1 = Car_GetFullDamegeCar(this);
        if ((!(bool)cVar1) && (S63::S63_FUN_00425760(this), cVar1 == '\0')) {
          puVar11 = local_98;
          puVar14 = &DAT_005e4e7c;
          uVar7 = SpriteS1::FUN_004207b0(this->CarSprite,local_f0);
          puVar13 = local_88;
          SpriteS1::FUN_004207b0(param_1->SpriteS1,local_48);
          FUN_0040f5c0(puVar13,uVar7);
          uVar7 = FUN_0041e1a0(puVar11,puVar14);
          sVar5 = Car_CollisionOnCar(this,32000,uVar7);
          local_fc = CONCAT22(extraout_var_02,sVar5);
        }
        bVar4 = Car_GetFullDamegeCar(this);
        if (!bVar4) {
          pSVar12 = this->CarSprite;
          pSVar9 = (S110 *)SpriteS1::FUN_004207b0(pSVar12,local_e8);
          puVar11 = local_e0;
          pvVar10 = (void *)SpriteS1::FUN_004207b0(param_1->SpriteS1,local_d0);
          puVar14 = (undefined4 *)FUN_0040f600(pvVar10,puVar11,pSVar9);
          local_108 = *puVar14;
          local_104 = (S46 *)puVar14[1];
          puVar11 = local_f6;
          goto LAB_004276c5;
        }
      }
    }
    else {
      iVar8 = iVar6 + -0x80;
      if ((iVar8 != 0) && (iVar8 = iVar6 + -0x8a, iVar8 != 0)) {
LAB_00427882:
        cVar1 = (char)iVar8;
        Car_FUN_00414f60(this);
        if (cVar1 == '\0') {
          puVar11 = local_80;
          puVar14 = &DAT_005e4e7c;
          uVar7 = SpriteS1::FUN_004207b0(this->CarSprite,local_70);
          puVar13 = local_60;
          SpriteS1::FUN_004207b0(param_1->SpriteS1,local_50);
          FUN_0040f5c0(puVar13,uVar7);
          uVar7 = FUN_0041e1a0(puVar11,puVar14);
          iVar6 = FUN_00436220(this_00);
          iVar6 = iVar6 * 800;
          goto LAB_004278e2;
        }
        goto LAB_004278ed;
      }
      cVar1 = (char)iVar8;
      S63::S63_FUN_00425760(this);
      if ((cVar1 != '\0') || (bVar4 = Car_GetFullDamegeCar(this), bVar4)) {
        pSVar12 = this->CarSprite;
        pSVar9 = (S110 *)SpriteS1::FUN_004207b0(pSVar12,local_38);
        puVar11 = local_a8;
        pvVar10 = (void *)SpriteS1::FUN_004207b0(param_1->SpriteS1,local_58);
        puVar14 = (undefined4 *)FUN_0040f600(pvVar10,puVar11,pSVar9);
        local_108 = *puVar14;
        local_104 = (S46 *)puVar14[1];
        puVar11 = local_f2;
      }
      else {
        puVar13 = local_18;
        puVar14 = &DAT_005e4e7c;
        uVar7 = SpriteS1::FUN_004207b0(this->CarSprite,local_78);
        puVar11 = local_d8;
        SpriteS1::FUN_004207b0(param_1->SpriteS1,local_28);
        FUN_0040f5c0(puVar11,uVar7);
        uVar7 = FUN_0041e1a0(puVar13,puVar14);
        sVar5 = Car_CollisionOnCar(this,32000,uVar7);
        local_fc = CONCAT22(extraout_var_01,sVar5);
        bVar4 = Car_GetFullDamegeCar(this);
        if (bVar4) goto LAB_0042797f;
        pSVar12 = this->CarSprite;
        pSVar9 = (S110 *)SpriteS1::FUN_004207b0(pSVar12,local_c8);
        puVar11 = local_68;
        pvVar10 = (void *)SpriteS1::FUN_004207b0(param_1->SpriteS1,local_b8);
        puVar14 = (undefined4 *)FUN_0040f600(pvVar10,puVar11,pSVar9);
        local_108 = *puVar14;
        local_104 = (S46 *)puVar14[1];
        puVar11 = local_f4;
      }
LAB_004276c5:
      pSVar9 = (S110 *)PedPool_Get(pSVar12,puVar11);
      FUN_0040f6b0(&local_108,pSVar9);
      Car_FUN_00423230(this,0x12,local_108,local_104);
      this_00 = local_100;
    }
  }
  else if (iVar6 == 0xc6) {
    ExtinguishCar(this);
  }
  else {
    iVar8 = iVar6 + -0x109;
    if (iVar8 == 0) {
      Car_FUN_00414f60(this);
      if ((char)iVar8 == '\0') {
        puVar11 = local_40;
        puVar14 = &DAT_005e4e7c;
        uVar7 = SpriteS1::FUN_004207b0(this->CarSprite,local_30);
        puVar13 = local_20;
        SpriteS1::FUN_004207b0(param_1->SpriteS1,local_10);
        FUN_0040f5c0(puVar13,uVar7);
        uVar7 = FUN_0041e1a0(puVar11,puVar14);
        iVar6 = FUN_00436220(this_00);
        iVar6 = iVar6 * 0x640;
LAB_004278e2:
        sVar5 = Car_CollisionOnCar(this,iVar6,uVar7);
        local_fc = CONCAT22(extraout_var_04,sVar5);
      }
LAB_004278ed:
      pSVar12 = param_1->SpriteS1;
      FUN_0048db00(pSVar12->S3_arr5031[0].PositionX,
                   pSVar12->S3_arr5031[0].PositionY,
                   pSVar12->S3_arr5031[0].PositionZ,local_108,local_104);
    }
    else {
      iVar8 = iVar6 + -0x115;
      if (iVar8 != 0) goto LAB_00427882;
    }
  }
LAB_0042797f:
  iVar8 = param_1->DamageType;
  iVar6 = iVar8 + -0xc0;
  if (((iVar6 == 0) || (iVar6 = iVar8 + -0xfe, iVar6 == 0)) ||
     (iVar6 = iVar8 + -0x109, iVar6 == 0)) {
    Car_FUN_00421900(this,3);
  }
  if (((param_1->DamageType != 0xc6) && (0 < (short)local_fc)) &&
     (this_00 != (Ped *)0x0)) {
    bVar4 = Ped::HasSearchType(this_00,SEARCHTYPE_LINE_OF_SIGHT_PLAYER_ONLY);
    iVar6 = CONCAT31(extraout_var_00,bVar4);
    if (bVar4) {
      SaveSlotAnimatedValue::FUN_004b89b0
                ((SaveSlotAnimatedValue *)&this_00->Player->money,this,1);
    }
  }
LAB_004279d2:
  return CONCAT31((int3)((uint)iVar6 >> 8),1);
}


byte __thiscall S63__PedNormal_FUN_00441a30(Ped *this,S63 *pS63)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  Player *pPVar4;
  char cVar5;
  byte bVar6;
  bool bVar7;
  short sVar8;
  int iVar9;
  undefined4 uVar10;
  undefined3 extraout_var;
  undefined2 extraout_var_01;
  undefined2 uVar12;
  short *psVar11;
  undefined3 extraout_var_00;
  Weapon *pWVar13;
  undefined2 extraout_var_02;
  undefined2 extraout_var_03;
  undefined2 extraout_var_04;
  Ped *this_00;
  int iVar14;
  undefined1 local_8 [2];
  undefined1 local_6 [2];
  short local_4;
  
  CarSystemManager::SetIndexDefautCarManager((CarSystemManager *)&local_4);
  this_00 = (Ped *)0x0;
  if (((this->CurrentState == PEDSTATE_FALL) ||
      ((this->CurrentState == PEDSTATE_DEAD && (pS63->DamageType != 0xc6)))) &&
     (this->field126_0x27c != 0x16)) {
    return 0;
  }
  cVar5 = S63::S63_FUN_00420ff0(pS63);
  if (cVar5 != '\0') {
    bVar6 = S63::S63_FUN_00420ff0(pS63);
    iVar9 = S68::S68GetPedID(_gS68,bVar6);
    if ((iVar9 != 0) &&
       (this_00 = Char::FindPed(gChar,iVar9), this_00 != (Ped *)0x0)) {
      bVar6 = sPed_FUN_004371d0(this_00,(Game *)this);
      if ((bVar6 == 0) && (this != this_00->LinkedPed)) {
        bVar7 = HasSearchType(this_00,SEARCHTYPE_LINE_OF_SIGHT_PLAYER_ONLY);
        if (bVar7) {
          uVar1._0_1_ = this_00->flags;
          uVar1._1_1_ = this_00->uns59;
          uVar1._2_1_ = this_00->uns60;
          uVar1._3_1_ = this_00->uns61;
          if ((uVar1 & 0x2000) == 0) {
            pWVar13 = this_00->SelectedWeapon;
          }
          else {
            pWVar13 = this_00->Weapon1;
          }
          if (pWVar13 != (Weapon *)0x0) {
            Weapon::SetTypeWeapons(pWVar13,Pistol);
          }
          FUN_004b76a0(&this_00->Player->money,3,pS63->DamageType,this);
          this->sPed1 = this_00;
          cVar5 = FUN_0044ab20(pS63->DamageType);
          if (cVar5 == '\0') {
            this->PedID = this_00->ID;
            uVar10 = FUN_0044ab80(pS63->DamageType);
            this->field131_0x290 = uVar10;
            this->uns104 = 0x32;
            return 1;
          }
          return 1;
        }
        bVar6 = sPed_FUN_004371d0(this,(Game *)this_00);
        if (bVar6 != 0) {
          this->sPed1 = this_00;
        }
        uVar2._0_1_ = this_00->flags;
        uVar2._1_1_ = this_00->uns59;
        uVar2._2_1_ = this_00->uns60;
        uVar2._3_1_ = this_00->uns61;
        if ((uVar2 & 0x2000) == 0) {
          pWVar13 = this_00->SelectedWeapon;
        }
        else {
          pWVar13 = this_00->Weapon1;
        }
        if (pWVar13 != (Weapon *)0x0) {
          Weapon::SetTypeWeapons(pWVar13,SNG);
        }
        if (this->sPed1 != this_00) {
          return 1;
        }
      }
      else {
        uVar3._0_1_ = this_00->flags;
        uVar3._1_1_ = this_00->uns59;
        uVar3._2_1_ = this_00->uns60;
        uVar3._3_1_ = this_00->uns61;
        if ((uVar3 & 0x2000) == 0) {
          pWVar13 = this_00->SelectedWeapon;
        }
        else {
          pWVar13 = this_00->Weapon1;
        }
        if (pWVar13 != (Weapon *)0x0) {
          Weapon::SetTypeWeapons(pWVar13,Pistol);
        }
        bVar7 = HasSearchType(this_00,SEARCHTYPE_LINE_OF_SIGHT_PLAYER_ONLY);
        if (bVar7) {
          FUN_004b76a0(&this_00->Player->money,2,pS63->DamageType,this);
        }
        this->sPed1 = this_00;
        cVar5 = FUN_0044ab20(pS63->DamageType);
        if (cVar5 == '\0') {
          this->PedID = this_00->ID;
          uVar10 = FUN_0044ab80(pS63->DamageType);
          this->field131_0x290 = uVar10;
          this->uns104 = 0x32;
        }
      }
    }
  }
  FUN_00476530(this->ID,pS63->DamageType,1);
  switch(pS63->DamageType) {
  case 0x80:
  case 0x8a:
  case 0xc0:
  case 0xc3:
  case 0xfe:
  case 0x109:
    psVar11 = (short *)FUN_0040eab0(local_6,(CarSystemManager *)
                                            this->GameObject->SpriteS1,
                                    pS63->SpriteS1);
    local_4 = *psVar11;
    bVar7 = CarSystemManager::greater_than
                      ((CarSystemManager *)&local_4,&DAT_005e5f4c);
    if (CONCAT31(extraout_var_00,bVar7) == 0) {
      uVar10 = 0x22;
    }
    else {
      uVar10 = 0x21;
    }
    FUN_00433a60(this->GameObject,uVar10);
    if (this->Invulnerability == 0) {
      cVar5 = (pS63->DamageType == 0x109) + '\x01';
      if (this->SearchType == SEARCHTYPE_LINE_OF_SIGHT_PLAYER_ONLY) {
        pPVar4 = this->Player;
        bVar7 = Player::GivePowerUp(pPVar4,POWERUP_TYPE_ARMOR);
        if (bVar7) {
          Player::S158_FUN_00434940(pPVar4,POWERUP_TYPE_ARMOR);
          uVar12 = extraout_var_02;
        }
        else {
          sVar8 = FUN_00436220(this_00);
          TakeDamage(this,sVar8 * cVar5 * 10);
          uVar12 = extraout_var_03;
        }
      }
      else {
        sVar8 = FUN_00436220(this_00);
        TakeDamage(this,sVar8 * cVar5 * 0x19);
        uVar12 = extraout_var_04;
      }
      FUN_0048c9c0(this->PositionX,this->PositionY,this->PositionZ,
                   CONCAT22(uVar12,*(undefined2 *)&pS63->SpriteS1->FirstElement)
                  );
      return 1;
    }
    break;
  case 0xc2:
    PedNormal_FUN_00435e90(this);
    return 1;
  case 0xc6:
    sPed_FUN_00433220(this);
    psVar11 = (short *)FUN_0040eab0(local_8,(CarSystemManager *)
                                            this->GameObject->SpriteS1,
                                    pS63->SpriteS1);
    local_4 = *psVar11;
    bVar7 = CarSystemManager::greater_than
                      ((CarSystemManager *)&local_4,&DAT_005e5f4c);
    if (CONCAT31(extraout_var,bVar7) == 0) {
      uVar10 = 0x22;
    }
    else {
      uVar10 = 0x21;
    }
    FUN_00433a60(this->GameObject,uVar10);
    if (this->Invulnerability != 0) {
      return 1;
    }
    if (this->SearchType == SEARCHTYPE_LINE_OF_SIGHT_PLAYER_ONLY) {
      pPVar4 = this->Player;
      bVar7 = Player::GivePowerUp(pPVar4,POWERUP_TYPE_ARMOR);
      if (bVar7) {
        uVar12 = extraout_var_01;
        Player::S158_FUN_00434940(pPVar4,POWERUP_TYPE_ARMOR);
        goto LAB_00441d16;
      }
      iVar9 = FUN_00436220(this_00);
      iVar9 = iVar9 * 2;
      iVar14 = iVar9;
    }
    else {
      iVar9 = FUN_00436220(this_00);
      iVar14 = iVar9 * 5;
    }
    uVar12 = (undefined2)((uint)iVar9 >> 0x10);
    TakeDamage(this,(short)iVar14);
LAB_00441d16:
    FUN_0048c9c0(this->PositionX,this->PositionY,this->PositionZ,
                 CONCAT22(uVar12,*(undefined2 *)&pS63->SpriteS1->FirstElement));
    return 1;
  case 0x115:
    if (this_00 != (Ped *)0x0) {
      this_00->ped3 = this;
      this_00->uns108 = 0x14;
    }
  }
  return 1;
}


undefined1 __thiscall S63__S76_FUN_0044ca70(S76 *this,S63 *pCAr)

{
  int iVar1;
  int iVar2;
  S119 *this_00;
  bool bVar3;
  byte bVar4;
  undefined1 uVar5;
  
  uVar5 = 0;
  switch(this->field9_0x20) {
  case 1:
    bVar4 = Car::IsDriverPlayer((Car *)pCAr);
    if (bVar4 != 0) goto switchD_0044ca82_caseD_1;
    iVar2._0_1_ = pCAr[2].field15_0x24;
    iVar2._1_1_ = pCAr[2].field16_0x25;
    iVar2._2_1_ = pCAr[2].field17_0x26;
    iVar2._3_1_ = pCAr[2].field18_0x27;
    if (iVar2 == 2) {
      return 1;
    }
    break;
  case 2:
switchD_0044ca82_caseD_1:
    uVar5 = 1;
    break;
  case 3:
    if (((this->Ped != (Ped *)0x0) && ((Ped *)pCAr == this->Ped)) &&
       (*(int *)&pCAr[2].CameraX == this->ID)) {
      return 1;
    }
    break;
  case 4:
    if ((Ped *)pCAr[3].IsFlag == this->Ped) {
      return 1;
    }
    break;
  case 5:
    break;
  case 6:
    if ((((this->Ped != (Ped *)0x0) && ((Ped *)pCAr == this->Ped)) &&
        (*(int *)&pCAr[2].CameraX == this->ID)) &&
       (((iVar1._0_1_ = pCAr[1].field15_0x24, iVar1._1_1_ = pCAr[1].field16_0x25
         , iVar1._2_1_ = pCAr[1].field17_0x26,
         iVar1._3_1_ = pCAr[1].field18_0x27, bVar3 = FUN_0044c6d0(this,iVar1),
         !bVar3 || ((bVar4 = Car::IsDriverPlayer((Car *)pCAr), this_00 = _gS119,
                    bVar4 != 0 &&
                    (bVar4 = S119::S119_FUN_0044c870(_gS119,(Car *)pCAr),
                    bVar4 == 0)))) ||
        ((bVar4 = Car::IsDriverPlayer((Car *)pCAr), bVar4 == 0 &&
         (bVar4 = S119::S119_FUN_0044c870(this_00,(Car *)pCAr), bVar4 != 0))))))
    goto switchD_0044ca82_caseD_1;
    break;
  default:
    goto switchD_0044ca82_caseD_6;
  }
switchD_0044ca82_caseD_6:
  return uVar5;
}


void __thiscall S63__FUN_0045e0a0(S63 *this,undefined1 param_1)

{
  this->field17_0x26 = param_1;
  return;
}


S63 * __thiscall S63__S63(S63 *this)

{
  this->IsFlag = (S63 *)0x0;
  this->SpriteS1 = (SpriteS1 *)0x0;
  this->DamageType = 0;
  this->Struc___ = 0;
  this->S116 = (S116 *)0x0;
  this->s6 = (S6 *)0x0;
  *(undefined4 *)&this->CameraX = 99;
  this->field15_0x24 = 0;
  this->field16_0x25 = 0;
  this->field17_0x26 = 99;
  this->field14_0x20 = 0;
  this->field18_0x27 = 0;
  this->field19_0x28 = 0xcd;
  this->z = 0;
  return this;
}


void __thiscall S63__S63_FUN_00482490(S63 *this)

{
  this->field17_0x26 = 99;
  *(int *)&this->CameraX = DAT_00593210;
  DAT_00593210 = DAT_00593210 + 1;
  this->field16_0x25 = 0;
  this->s6 = (S6 *)0x0;
  this->S116 = (S116 *)0x0;
  this->z = 0;
  this->SpriteS1 = (SpriteS1 *)0x0;
  this->DamageType = 0;
  return;
}


void __thiscall S63__S63_FUN_00482560(S63 *this)

{
  if ((this->DamageType == 0x8b) || (this->DamageType == 0x8d)) {
    S56::S56_FUN_00447480(gS56,this->SpriteS1);
    S56::S56_FUN_00447480(gS56_ARR1,this->SpriteS1);
  }
  return;
}


void __thiscall S63__S63_FUN_004825a0(S63 *this)

{
  S6 *this_00;
  
  this_00 = this->s6;
  if ((this_00 != (S6 *)0x0) && (this_00->S46 != (S46 *)0x0)) {
    ::Car::Car_FUN_004bef70((Car *)this_00,(Sprite *)this->SpriteS1);
  }
  return;
}


void __thiscall S63__S63_FUN_004825c0(S63 *this)

{
  if (this->DamageType == 0x80) {
    FUN_0048dfc0(this->SpriteS1);
  }
  return;
}


byte __thiscall S63__S63_FUN_00482630(S63 *this)

{
  SpriteS1 *pSpriteS1;
  
  pSpriteS1 = *(SpriteS1 **)(this->Struc___ + 0x40);
  switch(pSpriteS1) {
  case (SpriteS1 *)0x0:
  case (SpriteS1 *)0x1:
    S56::S56_FUN_00447ba0(gS56_ARR2,this->SpriteS1);
    return (byte)pSpriteS1;
  case (SpriteS1 *)0x3:
    _DAT_0066578c = _DAT_0066578c + 1;
    S56::S56_FUN_00447c00(gS56_ARR1,this->SpriteS1);
    return (byte)pSpriteS1;
  case (SpriteS1 *)0x4:
    pSpriteS1 = this->SpriteS1;
    S56::S56_FUN_00447c00(gS56,pSpriteS1);
  }
  return (byte)pSpriteS1;
}


void __thiscall S63__S63_FUN_004826a0(S63 *this)

{
  switch(*(undefined4 *)(this->Struc___ + 0x40)) {
  case 0:
  case 1:
    S56::S56_FUN_00447bd0(gS56_ARR2,this->SpriteS1);
    return;
  case 3:
    _DAT_0066578c = _DAT_0066578c + -1;
    S56::S56_FUN_00447c40(gS56_ARR1,this->SpriteS1);
    return;
  case 4:
    S56::S56_FUN_00447c40(gS56,this->SpriteS1);
  }
  return;
}


void __thiscall S63__S63_FUN_00482790(S63 *this,byte param_1)

{
  this->field17_0x26 = param_1;
  S68::S68_FUN_004b9920(_gS68,param_1);
  return;
}


void __thiscall S63__S63_FUN_004827b0(S63 *this)

{
  this->field16_0x25 = 1;
  return;
}


void __thiscall S63__S63_FUN_00482be0(S63 *this)

{
  SpriteS1::FUN_0040f7b0(this->SpriteS1,*(int *)(this->Struc___ + 0x2c));
  return;
}


undefined4 __thiscall S63__FUN_00482e80(S63 *param_1,SpriteS1 *param_2)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  
  bVar1 = S63::S63_FUN_00421080(param_1);
  if (bVar1 != 0) {
    cVar2 = S63::S63_FUN_00420ff0(param_1);
    if ((cVar2 != '\0') && (param_2 != (SpriteS1 *)0x0)) {
      iVar4 = SpriteS1::SpriteS1_FUN_0040fea0(param_2);
      if (iVar4 != 0) {
        cVar2 = Ped::sPed_FUN_00420b50(*(Ped **)(iVar4 + 0x7c));
        cVar3 = S63::S63_FUN_00420ff0(param_1);
        if (cVar2 == cVar3) {
          return 1;
        }
      }
    }
  }
  return 0;
}


void __thiscall S63__S63_FUN_00482ed0(S63 *this)

{
  CarDoor *this_00;
  short sVar1;
  S6 *pSVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  bool bVar6;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int *this_01;
  
  pSVar2 = this->s6;
  sVar1._0_1_ = pSVar2->S7[1].field5_0xe;
  sVar1._1_1_ = pSVar2->S7[1].field6_0xf;
  if (sVar1 == 1) {
    FUN_0040e530(pSVar2->S7 + 1,(int *)&DAT_00665948);
    FUN_0040e530(&this->s6->S7[0].doorState,&this->s6->S7[1].AnimationFrame);
    return;
  }
  FUN_0040e530(pSVar2->S7,(int *)&pSVar2->S7[0].field3_0xc);
  this_00 = this->s6->S7;
  bVar6 = FUN_004037e0(this_00,(SpriteS1 *)&DAT_00665894);
  if (CONCAT31(extraout_var,bVar6) != 0) {
    this_00->AnimationFrame = _DAT_00665894;
    pSVar2 = this->s6;
    uVar3 = DAT_00665894_1;
    uVar4 = uRam00665896;
    uVar5 = uRam00665897;
    pSVar2->S7[0].field3_0xc = DAT_00665894;
    pSVar2->S7[0].field4_0xd = uVar3;
    pSVar2->S7[0].field5_0xe = uVar4;
    pSVar2->S7[0].field6_0xf = uVar5;
  }
  this_01 = &this->s6->S7[0].doorState;
  bVar6 = FUN_004037e0(this_01,(SpriteS1 *)&DAT_00665894);
  if (CONCAT31(extraout_var_00,bVar6) != 0) {
    *this_01 = _DAT_00665894;
  }
  return;
}


void __thiscall S63__S63_FUN_00483100(S63 *this,SpriteS1 *param_1)

{
  undefined4 *this_00;
  undefined4 *this_01;
  S3 *pSVar1;
  SpriteS1 *this_02;
  byte bVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  void *this_03;
  Car *local_8;
  uint local_4;
  
  this_02 = param_1;
  pSVar1 = param_1->S3_arr5031;
  this_00 = &param_1->S3_arr5031[0].PositionY;
  this_01 = &param_1->S3_arr5031[0].PositionX;
  param_1 = (SpriteS1 *)param_1->S3_arr5031[0].PositionZ;
  iVar5 = Decoder_DecodeFloat(&pSVar1->PositionZ);
  iVar5 = iVar5 + -1;
  iVar6 = Decoder_DecodeFloat(this_00);
  iVar7 = Decoder_DecodeFloat(this_01);
  bVar2 = MapRelatedStruct::S16_FUN_00466cf0
                    (_gMapRelatedStruct,iVar7,iVar6,iVar5);
  if (bVar2 != 0) {
    FUN_00482510(&param_1,(S110 *)&local_8);
  }
  cVar3 = FUN_00466b70(*this_01,*this_00,&param_1);
  if (cVar3 == '\0') {
    puVar8 = (undefined4 *)FUN_0042a630(&local_8,&param_1);
    local_8 = (Car *)*puVar8;
    bVar4 = ::Car::Car_FUN_00403820((Car *)&local_8,(int *)&DAT_00665894);
    if (CONCAT31(extraout_var,bVar4) != 0) {
      puVar8 = (undefined4 *)FUN_00462ea0(this_03,&local_4,(uint *)&param_1);
      param_1 = (SpriteS1 *)*puVar8;
      bVar4 = S169::FUN_00403800((S169 *)&local_8,(int *)&DAT_00665a04);
      if (CONCAT31(extraout_var_00,bVar4) != 0) {
        FUN_004824e0(&local_4,0);
      }
      bVar4 = S169::FUN_00403800((S169 *)&param_1,(int *)&DAT_006658bc);
      if (CONCAT31(extraout_var_01,bVar4) != 0) {
        param_1 = _DAT_006658bc;
      }
    }
  }
  SpriteS1::SetPosition(this_02,*this_01,*this_00,(int)param_1);
  return;
}


void __thiscall S63__FUN_004837f0(S63 *param_1,SpriteS1 *param_2)

{
  byte bVar1;
  char cVar2;
  Car *this;
  Ped *pPVar3;
  int explosionSize;
  void *this_00;
  
  bVar1 = FUN_00475a80(param_1);
  if ((((bVar1 != 0) && (cVar2 = FUN_00482c10(), cVar2 != '\0')) &&
      (bVar1 = FUN_00482400(this_00), bVar1 != 0)) &&
     (this = (Car *)SpriteS1::GetObject(param_2), this != (Car *)0x0)) {
    if (param_1->DamageType == 0x84) {
      bVar1 = S63::S63_FUN_00420ff0(param_1);
      pPVar3 = (Ped *)S68::S68GetPedID(_gS68,bVar1);
      if (pPVar3 != (Ped *)0x0) {
        this->lastDamagingPed = pPVar3;
        this->DamageType = 0xc;
        this->DamageShotTimer = 0x32;
      }
    }
    explosionSize =
         FUN_004825e0((void *)param_1->Struc___,
                      *(undefined4 *)((int)param_1->Struc___ + 0x3c));
    Car::ExplodeCar(this,explosionSize);
  }
  return;
}


undefined4 __thiscall S63__FUN_00483a20(S63 *param_1,int param_2,int param_3)

{
  if (param_2 == 1) {
    if (param_3 == 2) {
      if (*(int *)(_gObject + 0x10) == 0x168) {
LAB_00483a51:
        S63::S63_FUN_004827b0(param_1);
        return 1;
      }
      *(int *)(_gObject + 0x10) = *(int *)(_gObject + 0x10) + 1;
    }
    else if (param_3 == 3) {
      *(int *)(_gObject + 0x14) = *(int *)(_gObject + 0x14) + 1;
      FUN_004bed60((void *)(_gObject + 0x1c),(S63 *)param_1->SpriteS1);
      return 0;
    }
  }
  else if (param_2 == 2) {
    if (param_3 == 1) {
      *(int *)(_gObject + 0x10) = *(int *)(_gObject + 0x10) + -1;
      return 0;
    }
    if (param_3 == 3) {
      *(int *)(_gObject + 0x10) = *(int *)(_gObject + 0x10) + -1;
      *(int *)(_gObject + 0x14) = *(int *)(_gObject + 0x14) + 1;
      FUN_004bed60((void *)(_gObject + 0x1c),(S63 *)param_1->SpriteS1);
      return 0;
    }
  }
  else if (param_2 == 3) {
    if (param_3 == 1) {
      *(int *)(_gObject + 0x14) = *(int *)(_gObject + 0x14) + -1;
      FUN_004bec60((void *)(_gObject + 0x1c),(S46 *)param_1->SpriteS1);
      return 0;
    }
    if (param_3 == 2) {
      if (*(int *)(_gObject + 0x10) != 0x168) {
        *(int *)(_gObject + 0x14) = *(int *)(_gObject + 0x14) + -1;
        FUN_004bec60((void *)(_gObject + 0x1c),(S46 *)param_1->SpriteS1);
        *(int *)(_gObject + 0x10) = *(int *)(_gObject + 0x10) + 1;
        return 0;
      }
      goto LAB_00483a51;
    }
  }
  return 0;
}


void __thiscall S63__S63_FUN_00483ba0(S63 *this)

{
  byte bVar1;
  uint uVar2;
  
  if (this->s6 != (S6 *)0x0) {
    *(undefined1 *)&this->s6->S7[2].doorState = 1;
  }
  uVar2 = General::GetCycle(gGeneral);
  if ((uVar2 & 3) == 0) {
    SpriteS1::FUN_004bab10(this->SpriteS1,'\x01');
    bVar1 = SpriteS1::FUN_004bddd0
                      (this->SpriteS1,_DAT_00665940,(Ped *)_DAT_00665940,
                       (Ped *)0x0);
    if (bVar1 != 0) {
      FUN_00420660(_DAT_00665894);
      S63_FUN_004827b0(this);
      return;
    }
  }
  return;
}


void __thiscall S63__FUN_00483c40(S63 *this)

{
  S61::S61_FUN_00482f60((S61 *)this);
  S63_FUN_004827b0(this);
  return;
}


void __thiscall S63__FUN_00483d50(S63 *this)

{
  char cVar1;
  int pDamageType;
  
  pDamageType = this->DamageType;
  if (pDamageType < 200) {
    pDamageType = pDamageType + -64;
  }
  else {
    pDamageType = pDamageType + -200;
  }
  if (pDamageType < 28) {
    cVar1 = Turrel::S72_FUN_004cc9a0(_gTurrel,pDamageType);
    FUN_0045e0a0(this,cVar1);
  }
  return;
}


void __fastcall S63__FUN_00484710(S63 *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1->Struc___ + 0x34);
  if ((-1 < iVar1) && (iVar1 < 2)) {
    if (param_1->DamageType != 0x94) {
      S63::S63_FUN_004827b0(param_1);
      return;
    }
    FUN_00483c20(param_1,1);
  }
  return;
}


undefined1 __thiscall S63__S63_FUN_00484740(S63 *this)

{
  byte bVar1;
  
  bVar1 = SpriteS1::SpriteS1_FUN_004baa90(this->SpriteS1);
  if (bVar1 != 0) {
    S63_FUN_00483ba0(this);
    return 1;
  }
  return 0;
}


void __thiscall S63__S63_FUN_00484760(S63 *this)

{
  S6 *this_00;
  S116 *pS116;
  
  pS116 = this->S116;
  if (pS116 != (S116 *)0x0) {
    if (*(int *)(this->Struc___ + 0x34) == 0xb) {
      S115::S115_FUN_0047f4f0(_gS115,pS116);
    }
    else if (this->z == 0) {
      S64::S64_FUN_00483fc0(_gS64,&pS116->field0_0x0);
    }
    else {
      S116::S116_FUN_0048a510(pS116);
    }
    this->S116 = (S116 *)0x0;
  }
  this_00 = this->s6;
  if (this_00 != (S6 *)0x0) {
    if (this_00->S46 != (S46 *)0x0) {
      ::Car::Car_FUN_004bf000((Car *)this_00);
    }
    S6::S6_FUN_00484000(this->s6);
    this->s6 = (S6 *)0x0;
  }
  return;
}


void __thiscall S63__S63_FUN_00484910(S63 *this)

{
  int iVar1;
  byte bVar2;
  
  this->DamageType = 0;
  iVar1 = *(int *)(this->Struc___ + 0x5c);
  if (iVar1 == 2) {
    *(int *)(_gObject + 0x10) = *(int *)(_gObject + 0x10) + -1;
  }
  else if (iVar1 == 3) {
    *(int *)(_gObject + 0x14) = *(int *)(_gObject + 0x14) + -1;
    S46::S46_1FUN_004becb0((S46 *)(_gObject + 0x1c),(S46 *)this->SpriteS1);
  }
  _DAT_0066578c = _DAT_0066578c + -1;
  bVar2 = S63_FUN_00421080(this);
  if ((bVar2 != 0) && (this->field17_0x26 != 0)) {
    S68::S68_FUN_004b9940(_gS68,this->field17_0x26);
    this->field17_0x26 = 0;
  }
  S63_FUN_00484760(this);
  if (this->SpriteS1 != (SpriteS1 *)0x0) {
    SpriteS1::SpriteS1_FUN_00421030(_gSpriteS1,this->SpriteS1);
    this->SpriteS1 = (SpriteS1 *)0x0;
  }
  *(undefined4 *)&this->CameraX = 0;
  return;
}


void __thiscall S63__S61_FUN_00484d60(S61 *this,S63 *param_1)

{
  S63 *pSVar1;
  S63 *this_00;
  S63 *pSVar2;
  
  pSVar2 = (S63 *)0x0;
  pSVar1 = this->Index;
  if (this->Index != (S63 *)0x0) {
    while (this_00 = pSVar1, this_00 != param_1) {
      pSVar1 = this_00->IsFlag;
      pSVar2 = this_00;
      if (this_00->IsFlag == (S63 *)0x0) {
        return;
      }
    }
    S63::S63_FUN_00484910(this_00);
    if (pSVar2 != (S63 *)0x0) {
      pSVar2->IsFlag = this_00->IsFlag;
      this_00->IsFlag = this->Begin_S63;
      this->Begin_S63 = this_00;
      return;
    }
    this->Index = this_00->IsFlag;
    this_00->IsFlag = this->Begin_S63;
    this->Begin_S63 = this_00;
  }
  return;
}


void __thiscall S63__S61_FUN_00484db0(S61 *this,S63 *pS63)

{
  S63::S63_FUN_00484910(pS63);
  pS63->IsFlag = this->Begin_S63;
  this->Begin_S63 = pS63;
  return;
}


void __thiscall S63__FUN_00484dd0(S63 *param_1,int param_2)

{
  if (*(int *)(param_2 + 0x18) != 0x8b) {
    if ((*(int *)(param_2 + 0x18) == 0x8d) &&
       (*(char *)(param_1->Struc___ + 0x60) != '\0')) {
      S63::FUN_00483c40(param_1);
    }
    return;
  }
  FUN_00484ad0();
  return;
}


void __thiscall S63__S60_FUN_00485260(Object *this,S63 *pS63)

{
  if (*(int *)(pS63->Struc___ + 0x34) != 0xb) {
    S56::S56_FUN_00447bd0(gS56_ARR2,pS63->SpriteS1);
  }
  S61::S61_FUN_00484db0(_gObject,pS63);
  return;
}


void __thiscall S63__FUN_00485760(S63 *param_1,int param_2)

{
  SpriteS1 *pSVar1;
  undefined4 uVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  S63 *this;
  int iVar6;
  S6 *pSVar7;
  S116 *pSVar8;
  void *this_00;
  undefined2 extraout_var;
  bool bVar9;
  undefined4 local_8;
  undefined4 local_4;
  
  if (param_2 == 0) {
    S63::S63_FUN_004827b0(param_1);
    return;
  }
  bVar3 = FUN_00482400(param_1);
  if (bVar3 == 0) {
    if (param_2 == 0x103) {
      pSVar1 = param_1->SpriteS1;
      FUN_0041e210(&local_8,(S110 *)&DAT_00665a60,(Ped *)pSVar1);
      FUN_0048db00(pSVar1->S3_arr5031[0].PositionX,
                   pSVar1->S3_arr5031[0].PositionY,
                   pSVar1->S3_arr5031[0].PositionZ,local_8,local_4);
      S63::S63_FUN_004827b0(param_1);
      return;
    }
    iVar6 = S57::S57_FUN_00488170(_gS57,param_2);
    iVar5 = *(int *)(param_1->Struc___ + 0x5c);
    if ((iVar5 == *(int *)(iVar6 + 0x5c)) ||
       (cVar4 = FUN_00483a20(iVar5,*(int *)(iVar6 + 0x5c)), cVar4 == '\0')) {
      if ((DAT_00665774 == '\0') && (DAT_00665761 == '\0')) {
        S63::S63_FUN_004826a0(param_1);
      }
      S3::S3_FUN_004bccc0((S3 *)param_1->SpriteS1);
      switch(*(undefined4 *)(iVar6 + 0x34)) {
      case 0:
      case 1:
      case 6:
      case 10:
      case 0xc:
        S63::S63_FUN_00484760(param_1);
        pSVar1 = param_1->SpriteS1;
        FUN_00483990(param_1,param_2,pSVar1->S3_arr5031[0].PositionX,
                     pSVar1->S3_arr5031[0].PositionY,
                     pSVar1->S3_arr5031[0].PositionZ,
                     *(undefined2 *)&pSVar1->FirstElement);
        if (param_1->s6 != (S6 *)0x0) {
          return;
        }
        break;
      case 2:
      case 8:
        pSVar7 = param_1->s6;
        if ((pSVar7 != (S6 *)0x0) && (pSVar7->S46 == (S46 *)0x0)) {
          S6::S6_FUN_00484000(pSVar7);
          param_1->s6 = (S6 *)0x0;
        }
        bVar9 = param_1->S116 == (S116 *)0x0;
        if (bVar9) {
          pSVar8 = (S116 *)S64::S64_FUN_00483fa0(_gS64);
          param_1->S116 = pSVar8;
        }
        if ((*(char *)(iVar6 + 0x65) != *(char *)(param_1->Struc___ + 0x65)) ||
           (bVar9)) {
          *(short *)&param_1->S116->S116 = (short)*(char *)(iVar6 + 0x65);
          *(undefined1 *)((int)&param_1->S116->S116 + 3) = 0;
          *(undefined1 *)((int)&param_1->S116->S116 + 2) = 0;
        }
        else if (*(byte *)(iVar6 + 0x6c) < *(byte *)(param_1->Struc___ + 0x6c))
        {
          *(bool *)((int)&param_1->S116->S116 + 3) = bVar9;
        }
        pSVar1 = param_1->SpriteS1;
        FUN_00483990(param_1,param_2,pSVar1->S3_arr5031[0].PositionX,
                     pSVar1->S3_arr5031[0].PositionY,
                     pSVar1->S3_arr5031[0].PositionZ,
                     *(undefined2 *)&pSVar1->FirstElement);
        SpriteS1::S38_FUN_004206c0
                  (param_1->SpriteS1,
                   (ushort)*(byte *)((int)&param_1->S116->S116 + 3) +
                   *(short *)(param_1->Struc___ + 0x1e));
        break;
      case 3:
      case 7:
        if (param_1->s6 == (S6 *)0x0) {
          pSVar7 = (S6 *)S66::S66_FUN_00483fe0(_gS66);
          param_1->s6 = pSVar7;
          pSVar7->S7[1].doorState = *(int *)&param_1->CameraX;
        }
        if (param_1->S116 != (S116 *)0x0) {
          S64::S64_FUN_00483fc0(_gS64,&param_1->S116->field0_0x0);
          param_1->S116 = (S116 *)0x0;
        }
        pSVar7 = param_1->s6;
        uVar2 = *(undefined4 *)(iVar6 + 0x14);
        pSVar7->S7[0].field3_0xc = (char)uVar2;
        pSVar7->S7[0].field4_0xd = (char)((uint)uVar2 >> 8);
        pSVar7->S7[0].field5_0xe = (char)((uint)uVar2 >> 0x10);
        pSVar7->S7[0].field6_0xf = (char)((uint)uVar2 >> 0x18);
        param_1->s6->S7[1].AnimationFrame = _DAT_00665894;
        param_1->s6->S7[0].doorState = _DAT_00665894;
        pSVar7 = param_1->s6;
        cVar4 = *(char *)(iVar6 + 0x65);
        pSVar7->S7[1].field3_0xc = (char)(short)cVar4;
        pSVar7->S7[1].field4_0xd = (char)((ushort)(short)cVar4 >> 8);
        pSVar1 = param_1->SpriteS1;
        FUN_00483990(param_1,param_2,pSVar1->S3_arr5031[0].PositionX,
                     pSVar1->S3_arr5031[0].PositionY,
                     pSVar1->S3_arr5031[0].PositionZ,
                     *(undefined2 *)&pSVar1->FirstElement);
        break;
      case 4:
      case 9:
        if (param_1->s6 == (S6 *)0x0) {
          pSVar7 = (S6 *)S66::S66_FUN_00483fe0(_gS66);
          param_1->s6 = pSVar7;
          pSVar7->S7[1].doorState = *(int *)&param_1->CameraX;
        }
        bVar9 = param_1->S116 == (S116 *)0x0;
        if (bVar9) {
          pSVar8 = (S116 *)S64::S64_FUN_00483fa0(_gS64);
          param_1->S116 = pSVar8;
        }
        if ((*(char *)(iVar6 + 0x65) != *(char *)(param_1->Struc___ + 0x65)) ||
           (bVar9)) {
          *(short *)&param_1->S116->S116 = (short)*(char *)(iVar6 + 0x65);
          *(undefined1 *)((int)&param_1->S116->S116 + 3) = 0;
          *(undefined1 *)((int)&param_1->S116->S116 + 2) = 0;
        }
        else if (*(byte *)(iVar6 + 0x6c) < *(byte *)(param_1->Struc___ + 0x6c))
        {
          *(bool *)((int)&param_1->S116->S116 + 3) = bVar9;
        }
        pSVar1 = param_1->SpriteS1;
        FUN_00483990(param_1,param_2,pSVar1->S3_arr5031[0].PositionX,
                     pSVar1->S3_arr5031[0].PositionY,
                     pSVar1->S3_arr5031[0].PositionZ,
                     *(undefined2 *)&pSVar1->FirstElement);
        SpriteS1::S38_FUN_004206c0
                  (param_1->SpriteS1,
                   (ushort)*(byte *)((int)&param_1->S116->S116 + 3) +
                   *(short *)(param_1->Struc___ + 0x1e));
        pSVar7 = param_1->s6;
        uVar2 = *(undefined4 *)(iVar6 + 0x14);
        pSVar7->S7[0].field3_0xc = (char)uVar2;
        pSVar7->S7[0].field4_0xd = (char)((uint)uVar2 >> 8);
        pSVar7->S7[0].field5_0xe = (char)((uint)uVar2 >> 0x10);
        pSVar7->S7[0].field6_0xf = (char)((uint)uVar2 >> 0x18);
        param_1->s6->S7[1].AnimationFrame = _DAT_00665894;
        param_1->s6->S7[0].doorState = _DAT_00665894;
      }
      if ((*(char *)(iVar6 + 0x61) == '\0') && (param_1->field16_0x25 == '\0'))
      {
        FUN_00482f80(param_1);
      }
      if (DAT_00665761 == '\0') {
        DAT_00665760 = 1;
        S63::S63_FUN_00482630(param_1);
      }
    }
    return;
  }
  pSVar1 = param_1->SpriteS1;
  S68::S68GetPedID(_gS68,param_1->field17_0x26);
  iVar5 = FUN_004825e0(this_00,param_2);
  this = (S63 *)Object::S60_FUN_00485540
                          (_gObject,pSVar1->S3_arr5031[0].PositionX,
                           pSVar1->S3_arr5031[0].PositionY,
                           pSVar1->S3_arr5031[0].PositionZ,
                           (void *)CONCAT22(extraout_var,_DAT_006657f8______S38)
                           ,iVar5);
  if (this != (S63 *)0x0) {
    S63::S63_FUN_00482790(this,param_1->field17_0x26);
  }
  S63::S63_FUN_004827b0(param_1);
  return;
}


void __thiscall S63__S63_FUN_00485b00(S63 *this,void *param_1)

{
  SpriteS1 *pSVar1;
  byte bVar2;
  S63 *this_00;
  int pedID;
  Ped *pPVar3;
  undefined2 extraout_var;
  
  switch(this->DamageType) {
  case 0x80:
  case 0x8a:
    break;
  case 0x81:
  case 0x82:
  case 0x83:
  case 0x84:
  case 0x85:
  case 0x86:
  case 0x87:
  case 0x88:
  case 0x89:
  case 0x8b:
  case 0x8c:
  case 0x8d:
  case 0x8e:
  case 0x8f:
  case 0x90:
  case 0x91:
  case 0x92:
  case 0x93:
  case 0x94:
  case 0x95:
  case 0x96:
  case 0x97:
  case 0x98:
  case 0x99:
  case 0x9b:
  case 0x9c:
  case 0x9d:
  case 0x9e:
  case 0xa0:
  case 0xa1:
  case 0xa2:
  case 0xa3:
  case 0xa4:
  case 0xa5:
  case 0xa6:
  case 0xa7:
  case 0xa8:
  case 0xa9:
  case 0xaa:
  case 0xab:
  case 0xac:
  case 0xad:
  case 0xae:
  case 0xaf:
  case 0xb0:
  case 0xb1:
  case 0xb2:
  case 0xb3:
  case 0xb4:
  case 0xb5:
  case 0xb6:
  case 0xb7:
  case 0xb8:
  case 0xb9:
  case 0xba:
  case 0xbb:
  case 0xbc:
  case 0xbd:
  case 0xbe:
  case 0xbf:
  case 0xc4:
  case 0xc5:
  case 200:
  case 0xc9:
  case 0xca:
  case 0xcb:
  case 0xcc:
  case 0xcd:
  case 0xce:
  case 0xcf:
  case 0xd0:
  case 0xd1:
  case 0xd2:
  case 0xd3:
  case 0xd4:
  case 0xd5:
  case 0xd6:
  case 0xd7:
  case 0xd8:
  case 0xd9:
  case 0xda:
  case 0xdb:
  case 0xdc:
  case 0xdd:
  case 0xde:
  case 0xdf:
  case 0xe0:
  case 0xe1:
  case 0xe2:
  case 0xe3:
  case 0xe4:
  case 0xe5:
  case 0xe6:
  case 0xe7:
  case 0xe8:
  case 0xe9:
  case 0xea:
  case 0xeb:
  case 0xec:
  case 0xed:
  case 0xee:
  case 0xef:
  case 0xf0:
  case 0xf1:
  case 0xf2:
  case 0xf3:
  case 0xf4:
  case 0xf5:
  case 0xf6:
  case 0xf7:
  case 0xf8:
  case 0xf9:
  case 0xfa:
  case 0xfb:
  case 0xfc:
  case 0xfd:
  case 0xff:
  case 0x100:
  case 0x101:
  case 0x102:
  case 0x103:
  case 0x104:
  case 0x105:
  case 0x106:
  case 0x107:
  case 0x108:
  case 0x10a:
  case 0x10b:
  case 0x10c:
  case 0x10d:
  case 0x10e:
  case 0x10f:
  case 0x110:
  case 0x111:
  case 0x112:
  case 0x113:
  case 0x114:
    return;
  case 0x9a:
  case 0x9f:
  case 0xc0:
  case 0xc1:
  case 0xc2:
  case 0xc3:
  case 0xc6:
  case 199:
  case 0xfe:
  case 0x109:
  case 0x115:
    goto switchD_00485b21_caseD_9a;
  default:
    return;
  }
  if (*(int *)((int)param_1 + 0x18) == 0xa6) {
    pedID = FUN_00483c80(param_1);
  }
  else {
    pedID = (*(int *)(*(int *)((int)param_1 + 8) + 0x48) == 0xd) + 0x12;
  }
  pSVar1 = this->SpriteS1;
  S68::S68GetPedID(_gS68,this->field17_0x26);
  this_00 = (S63 *)Object::S60_FUN_00485540
                             (_gObject,pSVar1->S3_arr5031[0].PositionX,
                              pSVar1->S3_arr5031[0].PositionY,
                              pSVar1->S3_arr5031[0].PositionZ,
                              (void *)CONCAT22(extraout_var,
                                               _DAT_006657f8______S38),pedID);
  if (this_00 != (S63 *)0x0) {
    S63_FUN_00482790(this_00,this->field17_0x26);
  }
switchD_00485b21_caseD_9a:
  bVar2 = S63_FUN_00420ff0(this);
  pedID = S68::S68GetPedID(_gS68,bVar2);
  if (pedID == 0) {
    pPVar3 = (Ped *)0x0;
  }
  else {
    pPVar3 = Char::FindPed(gChar,pedID);
  }
  if (*(int *)((int)param_1 + 0x18) != 0xa6) {
    return;
  }
  if (pPVar3 == (Ped *)0x0) {
    return;
  }
  FUN_00435180(this->SpriteS1->S3_arr5031[0].PositionX,
               this->SpriteS1->S3_arr5031[0].PositionY,this->DamageType);
  return;
}


void __thiscall S63__S63_FUN_00485c90(S63 *this)

{
  SpriteS1 *pSVar1;
  byte bVar2;
  S63 *this_00;
  int iVar3;
  Ped *pPVar4;
  void *this_01;
  short *unaff_ESI;
  void *unaff_EDI;
  short local_a;
  undefined4 local_8;
  undefined4 local_4;
  
  switch(this->DamageType) {
  case 0x80:
  case 0x8a:
    pSVar1 = this->SpriteS1;
    S68::S68GetPedID(_gS68,this->field17_0x26);
    iVar3 = FUN_00482410(this_01,_DAT_00665794);
    this_00 = (S63 *)Object::S60_FUN_00485540
                               (_gObject,pSVar1->S3_arr5031[0].PositionX,
                                pSVar1->S3_arr5031[0].PositionY,
                                pSVar1->S3_arr5031[0].PositionZ,
                                (void *)CONCAT22((short)((uint)iVar3 >> 0x10),
                                                 _DAT_006657f8______S38),iVar3);
    if (this_00 != (S63 *)0x0) {
      S63_FUN_00482790(this_00,this->field17_0x26);
    }
    break;
  case 0x81:
  case 0x82:
  case 0x83:
  case 0x84:
  case 0x85:
  case 0x86:
  case 0x87:
  case 0x88:
  case 0x89:
  case 0x8b:
  case 0x8c:
  case 0x8d:
  case 0x8e:
  case 0x8f:
  case 0x90:
  case 0x91:
  case 0x92:
  case 0x93:
  case 0x94:
  case 0x95:
  case 0x96:
  case 0x97:
  case 0x98:
  case 0x99:
  case 0x9b:
  case 0x9c:
  case 0x9d:
  case 0x9e:
  case 0xa0:
  case 0xa1:
  case 0xa2:
  case 0xa3:
  case 0xa4:
  case 0xa5:
  case 0xa6:
  case 0xa7:
  case 0xa8:
  case 0xa9:
  case 0xaa:
  case 0xab:
  case 0xac:
  case 0xad:
  case 0xae:
  case 0xaf:
  case 0xb0:
  case 0xb1:
  case 0xb2:
  case 0xb3:
  case 0xb4:
  case 0xb5:
  case 0xb6:
  case 0xb7:
  case 0xb8:
  case 0xb9:
  case 0xba:
  case 0xbb:
  case 0xbc:
  case 0xbd:
  case 0xbe:
  case 0xbf:
  case 0xc4:
  case 0xc5:
  case 200:
  case 0xc9:
  case 0xca:
  case 0xcb:
  case 0xcc:
  case 0xcd:
  case 0xce:
  case 0xcf:
  case 0xd0:
  case 0xd1:
  case 0xd2:
  case 0xd3:
  case 0xd4:
  case 0xd5:
  case 0xd6:
  case 0xd7:
  case 0xd8:
  case 0xd9:
  case 0xda:
  case 0xdb:
  case 0xdc:
  case 0xdd:
  case 0xde:
  case 0xdf:
  case 0xe0:
  case 0xe1:
  case 0xe2:
  case 0xe3:
  case 0xe4:
  case 0xe5:
  case 0xe6:
  case 0xe7:
  case 0xe8:
  case 0xe9:
  case 0xea:
  case 0xeb:
  case 0xec:
  case 0xed:
  case 0xee:
  case 0xef:
  case 0xf0:
  case 0xf1:
  case 0xf2:
  case 0xf3:
  case 0xf4:
  case 0xf5:
  case 0xf6:
  case 0xf7:
  case 0xf8:
  case 0xf9:
  case 0xfa:
  case 0xfb:
  case 0xfc:
  case 0xfd:
  case 0xff:
  case 0x100:
  case 0x101:
  case 0x102:
  case 0x103:
  case 0x104:
  case 0x105:
  case 0x106:
  case 0x107:
  case 0x108:
  case 0x10a:
  case 0x10b:
  case 0x10c:
  case 0x10d:
  case 0x10e:
  case 0x10f:
  case 0x110:
  case 0x111:
  case 0x112:
  case 0x113:
  case 0x114:
    return;
  case 0x9a:
  case 0x9f:
  case 0xc0:
  case 0xc1:
  case 0xc2:
  case 0xc3:
  case 0xc6:
  case 199:
  case 0x115:
    goto switchD_00485cb0_caseD_9a;
  case 0xfe:
  case 0x109:
    break;
  default:
    return;
  }
  pSVar1 = this->SpriteS1;
  pPVar4 = (Ped *)FUN_0040e5a0(pSVar1,&local_a,(short *)&DAT_006659a4,unaff_EDI,
                               unaff_ESI);
  FUN_0041e210(&local_8,(S110 *)&DAT_00665a60,pPVar4);
  FUN_0048db00(pSVar1->S3_arr5031[0].PositionX,pSVar1->S3_arr5031[0].PositionY,
               pSVar1->S3_arr5031[0].PositionZ,local_8,local_4);
switchD_00485cb0_caseD_9a:
  bVar2 = S63_FUN_00420ff0(this);
  iVar3 = S68::S68GetPedID(_gS68,bVar2);
  if (iVar3 == 0) {
    return;
  }
  pPVar4 = Char::FindPed(gChar,iVar3);
  if (pPVar4 == (Ped *)0x0) {
    return;
  }
  FUN_00435180(this->SpriteS1->S3_arr5031[0].PositionX,
               this->SpriteS1->S3_arr5031[0].PositionY,this->DamageType);
  return;
}


void __thiscall S63__S63_FUN_00485fd0(S63 *this)

{
  short sVar1;
  char cVar2;
  
  *(char *)((int)&this->S116->S116 + 2) =
       *(char *)((int)&this->S116->S116 + 2) + '\x01';
  if ((int)*(char *)(this->Struc___ + 100) <=
      (int)(uint)*(byte *)((int)&this->S116->S116 + 2)) {
    *(undefined1 *)((int)&this->S116->S116 + 2) = 0;
    *(char *)((int)&this->S116->S116 + 3) =
         *(char *)((int)&this->S116->S116 + 3) + '\x01';
    if (*(byte *)(this->Struc___ + 0x6c) <=
        *(byte *)((int)&this->S116->S116 + 3)) {
      *(undefined1 *)((int)&this->S116->S116 + 3) = 0;
      sVar1 = *(short *)&this->S116->S116;
      if (0 < sVar1) {
        *(short *)&this->S116->S116 = sVar1 + -1;
      }
    }
    SpriteS1::S38_FUN_004206c0
              (this->SpriteS1,
               (ushort)*(byte *)((int)&this->S116->S116 + 3) +
               *(short *)(this->Struc___ + 0x1e));
    cVar2 = FUN_00482c10();
    if (cVar2 != '\0') {
      FUN_00485760(*(undefined4 *)(this->Struc___ + 0x3c));
    }
  }
  return;
}


byte __thiscall S63__S63_FUN_00486060(S63 *this)

{
  char cVar1;
  int iVar2;
  
  cVar1 = this->field15_0x24;
  if (cVar1 != '\0') {
    switch(*(undefined4 *)(this->Struc___ + 0x44)) {
    case 1:
    case 2:
    case 5:
    case 6:
    case 8:
    case 0xb:
      goto switchD_00486082_caseD_1;
    default:
      this->field15_0x24 = 0;
      return 0;
    case 4:
      if (cVar1 != '\x01') {
        FUN_00485760(cVar1);
      }
      this->field15_0x24 = 0;
      return 1;
    case 7:
    case 10:
      this->field15_0x24 = 0;
      S63_FUN_004827b0(this);
      return 1;
    }
  }
  iVar2 = *(int *)(this->Struc___ + 0x44);
  if ((iVar2 != 3) && (iVar2 != 4)) {
    return 0;
  }
  FUN_00485760(*(undefined4 *)(this->Struc___ + 0x38));
  return 1;
switchD_00486082_caseD_1:
  if (cVar1 == '\x01') {
    FUN_00485760(*(undefined4 *)(this->Struc___ + 0x38));
    this->field15_0x24 = 0;
    return 1;
  }
  FUN_00485760(cVar1);
  this->field15_0x24 = 0;
  return 1;
}


byte __thiscall S63__S63_FUN_00486360(S63 *this,S63 *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(this->Struc___ + 0x48);
  if ((0xb < iVar1) && (iVar1 < 0xe)) {
    S63_FUN_00485b00(param_1,this);
    return 1;
  }
  return 0;
}


byte __thiscall S63__S63_FUN_00486360(S63 *this,S63 *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(this->Struc___ + 0x48);
  if ((0xb < iVar1) && (iVar1 < 0xe)) {
    S63_FUN_00485b00(param_1,this);
    return 1;
  }
  return 0;
}


void __thiscall S63__S63_FUN_00486390(S63 *this,S46 *pSprite)

{
  byte bVar1;
  int iVar2;
  Car *car;
  S63 *this_00;
  Ped *pPVar3;
  
  iVar2 = SpriteS1::SpriteS1_FUN_0040fea0((SpriteS1 *)pSprite);
  if (iVar2 != 0) {
    S63_FUN_004932d0(this);
    return;
  }
  car = (Car *)SpriteS1::GetObject((SpriteS1 *)pSprite);
  if (car != (Car *)0x0) {
    ::Car::Car_FUN_004274c0(car,this);
    return;
  }
  this_00 = SpriteS1::SpriteS1_FUN_0040fec0((SpriteS1 *)pSprite);
  bVar1 = S63_FUN_00420ff0(this);
  iVar2 = S68::S68GetPedID(_gS68,bVar1);
  if (iVar2 != 0) {
    pPVar3 = Char::FindPed(gChar,iVar2);
    if (pPVar3 != (Ped *)0x0) {
      FUN_004350c0(this_00);
    }
  }
  S63_FUN_00486360(this_00,this);
  return;
}


void __thiscall S63__S63_FUN_00486e90(S63 *this,uint param_1,undefined4 param_2)

{
  undefined4 *this_00;
  short sVar1;
  SpriteS1 *pSVar2;
  S6 *pSVar3;
  byte bVar4;
  bool bVar5;
  char cVar6;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined3 extraout_var_01;
  int *piVar11;
  undefined3 extraout_var_02;
  SpriteS1 *pSVar12;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined4 *puVar13;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  undefined3 extraout_var_07;
  undefined3 extraout_var_08;
  undefined4 *puVar14;
  char local_5a;
  char local_59;
  SpriteS1 *local_58;
  SpriteS1 *local_54;
  Player *local_50;
  Player *local_4c;
  undefined1 local_48 [20];
  Ped *local_34;
  undefined1 local_30 [16];
  Ped *local_20;
  undefined1 local_1c [20];
  SpriteS1 *local_8;
  SpriteS1 *local_4;
  
  pSVar2 = *(SpriteS1 **)(_gObject + 0x58);
  local_54 = (SpriteS1 *)param_1;
  local_50 = (Player *)((uint)local_50 & 0xffffff00);
  local_48._4_4_ = local_48._4_4_ & 0xffffff00;
  local_5a = '\0';
  _DAT_00665794 = 0;
  S63_FUN_00482be0(this);
  bVar4 = FUN_00483460(this,param_1);
  if (bVar4 != 0) {
    local_54 = (SpriteS1 *)this->s6->S7[0].AnimationFrame;
  }
  bVar5 = Player::IsCurrentPlayer((Player *)&local_54,(Player *)&DAT_00665894);
  if (((CONCAT31(extraout_var,bVar5) != 0) &&
      (pSVar3 = this->s6, sVar1._0_1_ = pSVar3->S7[1].field5_0xe,
      sVar1._1_1_ = pSVar3->S7[1].field6_0xf, sVar1 == 0)) &&
     (bVar5 = Player::IsCurrentPlayer
                        ((Player *)&pSVar3->S7[0].doorState,
                         (Player *)&DAT_00665894),
     CONCAT31(extraout_var_00,bVar5) != 0)) {
    return;
  }
  FUN_004637b0(&DAT_005e6874);
  pSVar12 = this->SpriteS1;
  SpriteS1::SetPosition
            (pSVar2,pSVar12->S3_arr5031[0].PositionX,
             pSVar12->S3_arr5031[0].PositionY,pSVar12->S3_arr5031[0].PositionZ);
  SpriteS1::SetRotation(pSVar2,*(short *)&this->SpriteS1->FirstElement);
  puVar14 = (undefined4 *)this->Struc___;
  SpriteS1::S38_FUN_004bcb90(pSVar2,*puVar14,puVar14[1],puVar14[2]);
  uVar7 = SpriteS1::FUN_00416b40(this->SpriteS1);
  SpriteS1::S38_FUN_004206f0(pSVar2,uVar7);
  SpriteS1::S38_FUN_00482a30(pSVar2,this->SpriteS1->S3_arr5031[0].Car);
  puVar14 = &pSVar2->S3_arr5031[0].PositionZ;
  this_00 = &pSVar2->S3_arr5031[0].PositionY;
  iVar8 = Decoder_DecodeFloat(puVar14);
  iVar9 = Decoder_DecodeFloat(this_00);
  iVar10 = Decoder_DecodeFloat(&pSVar2->S3_arr5031[0].PositionX);
  bVar4 = MapRelatedStruct::S16_FUN_00466cf0
                    (_gMapRelatedStruct,iVar10,iVar9,iVar8);
  if (bVar4 == 0) {
    *(undefined1 *)((int)&this->s6->S7[2].AnimationFrame + 3) = 0;
  }
  else {
    *(undefined1 *)((int)&this->s6->S7[2].AnimationFrame + 3) = 1;
  }
  bVar5 = ::Car::Car_FUN_00403820((Car *)&local_54,(int *)&DAT_00665894);
  if (CONCAT31(extraout_var_01,bVar5) == 0) {
    local_58 = _DAT_00665894;
    local_48._0_4_ = _DAT_00665894;
  }
  else {
    piVar11 = (int *)Decoder_ReadInt(&local_54,&local_20,
                                  (int *)(this->Struc___ + 0xc));
    local_58 = (SpriteS1 *)*piVar11;
    piVar11 = (int *)Decoder_ReadInt(&local_54,&local_20,(int *)&local_58);
    local_48._0_4_ = *piVar11;
    piVar11 = (int *)Decoder_ReadInt(&this->s6->S7[0].doorState,&local_20,
                                  (int *)&local_58);
    local_4c = (Player *)*piVar11;
  }
  bVar5 = FUN_004037e0(&local_58,(SpriteS1 *)&DAT_0066582c);
  if (CONCAT31(extraout_var_02,bVar5) != 0) {
    local_58 = _DAT_0066582c;
    local_4c = (Player *)this->s6->S7[0].doorState;
    local_48._0_4_ = local_54;
  }
  local_30._0_4_ = local_48._0_4_;
  FUN_0041fc20(&param_2,&param_2,(S110 *)local_30,(Ped *)(local_48 + 0xc),
               (Ped *)(local_48 + 8));
  local_54 = (SpriteS1 *)CONCAT31(local_54._1_3_,1);
  iVar8 = Decoder_DecodeFloat(&local_58);
  if (0 < iVar8) {
    do {
      local_30._12_4_ = pSVar2->S3_arr5031[0].PositionX;
      local_20 = (Ped *)*this_00;
      local_34 = (Ped *)*puVar14;
      local_30._0_2_ = *(undefined2 *)&pSVar2->FirstElement;
      piVar11 = (int *)FUN_00469570(local_1c,pSVar2->S3_arr5031[0].PositionX,
                                    *this_00,local_34);
      local_48._16_4_ = *piVar11;
      local_30._4_4_ =
           S9::S9_FUN_00401b20((S9 *)puVar14,(SpriteS1 *)(local_1c + 8),
                               (int *)&local_4c);
      local_30._8_4_ =
           S9::S9_FUN_00401b20((S9 *)this_00,(SpriteS1 *)(local_1c + 0xc),
                               (int *)(local_48 + 8));
      pSVar12 = S9::S9_FUN_00401b20((S9 *)&pSVar2->S3_arr5031[0].PositionX,
                                    (SpriteS1 *)(local_1c + 0x10),
                                    (int *)(local_48 + 0xc));
      SpriteS1::SetPosition
                (pSVar2,(int)pSVar12->FirstElement,
                 (int)*(SpriteS1 **)local_30._8_4_,
                 (int)*(SpriteS1 **)local_30._4_4_);
      SpriteS1::SetRotation(pSVar2,(short)param_2);
      bVar5 = Player::IsCurrentPlayer
                        ((Player *)&local_4c,(Player *)&DAT_00665894);
      if (CONCAT31(extraout_var_03,bVar5) == 0) {
        bVar5 = S169::FUN_00403800((S169 *)&local_4c,(int *)&DAT_00665894);
        if (CONCAT31(extraout_var_04,bVar5) == 0) {
          local_59 = FUN_004843a0(pSVar2,&local_8,&local_5a,&local_50,
                                  local_48._16_4_);
        }
        else {
          local_59 = FUN_00484260(pSVar2,&local_8,&local_5a,local_48 + 4);
        }
      }
      else {
        local_59 = FUN_00484090(pSVar2,&local_8,&local_5a,local_48._16_4_);
      }
      local_54 = (SpriteS1 *)CONCAT31(local_54._1_3_,(char)local_54 + '\x01');
      iVar8 = Decoder_DecodeFloat(&local_58);
    } while ((int)((uint)local_54 & 0xff) <= iVar8);
    if ((char)local_50 != '\0') {
      CameraOrPhysics::S131_FUN_004102a0
                ((CameraOrPhysics *)gCameraOrPhysics,(S110 *)this->SpriteS1);
    }
    if (local_59 != '\0') {
      _DAT_00665880 = local_34;
      _DAT_00665b1c = local_30._0_2_;
      _DAT_00665b00 = local_20;
      _DAT_00665898 = (SpriteS1 *)local_30._12_4_;
      SpriteS1::SetPosition(pSVar2,local_30._12_4_,(int)local_20,(int)local_34);
      SpriteS1::SetRotation(pSVar2,(short)local_30._0_4_);
      S63_FUN_00483100(this,pSVar2);
      local_20 = (Ped *)0x2;
      local_30._0_4_ = (Ped *)0x3;
      do {
        pSVar12 = Model::FUN_00401bf0((Model *)local_48,
                                      (SpriteS1 *)(local_1c + 0x10),
                                      (int *)&local_20);
        local_48._0_4_ = pSVar12->FirstElement;
        FUN_0041fc20(&param_2,&param_2,(S110 *)local_48,(Ped *)(local_48 + 0xc),
                     (Ped *)(local_48 + 8));
        local_30._12_4_ =
             S9::S9_FUN_00401b20((S9 *)this_00,(SpriteS1 *)(local_1c + 0xc),
                                 (int *)(local_48 + 8));
        pSVar12 = S9::S9_FUN_00401b20((S9 *)&pSVar2->S3_arr5031[0].PositionX,
                                      (SpriteS1 *)(local_1c + 8),
                                      (int *)(local_48 + 0xc));
        SpriteS1::SetPosition
                  (pSVar2,(int)pSVar12->FirstElement,
                   (int)*(SpriteS1 **)local_30._12_4_,*puVar14);
        SpriteS1::SetRotation(pSVar2,(short)param_2);
        S63_FUN_00483100(this,pSVar2);
        local_59 = '\0';
        if ((this->s6->S7[2].PedInDoor == (Ped *)0x2) &&
           (cVar6 = FUN_00483060(pSVar2), cVar6 != '\0')) {
          local_59 = '\x01';
        }
        cVar6 = SpriteS1::S38_FUN_004bd670(pSVar2);
        if ((cVar6 == '\0') && (local_59 == '\0')) {
          _DAT_00665898 = (SpriteS1 *)pSVar2->S3_arr5031[0].PositionX;
          bVar5 = true;
          _DAT_00665b00 = (Ped *)*this_00;
          _DAT_00665880 = (Ped *)*puVar14;
          _DAT_00665b1c = *(ushort *)&pSVar2->FirstElement;
        }
        else {
          puVar13 = (undefined4 *)SpriteS1::FUN_004207b0(pSVar2,local_1c);
          local_8 = (SpriteS1 *)*puVar13;
          local_4 = (SpriteS1 *)puVar13[1];
          SpriteS1::SetPosition
                    (pSVar2,(int)_DAT_00665898,(int)_DAT_00665b00,
                     (int)_DAT_00665880);
          SpriteS1::SetRotation(pSVar2,_DAT_00665b1c);
          bVar5 = false;
        }
        local_30._0_4_ =
             (int)&((Ped *)(local_30._0_4_ + -0x294))->field131_0x290 + 3;
      } while ((undefined1 *)local_30._0_4_ != (undefined1 *)0x0);
      if (!bVar5) {
        SpriteS1::SetPosition
                  (pSVar2,(int)_DAT_00665898,(int)_DAT_00665b00,
                   (int)_DAT_00665880);
        SpriteS1::SetRotation(pSVar2,_DAT_00665b1c);
      }
      SpriteS1::SetPosition
                (this->SpriteS1,pSVar2->S3_arr5031[0].PositionX,*this_00,
                 *puVar14);
      SpriteS1::SetRotation(this->SpriteS1,*(short *)&pSVar2->FirstElement);
      if ((((char)local_50 != '\0') || (local_5a != '\0')) ||
         (local_48[4] != '\0')) {
        FUN_00486d70(local_8,local_4,local_50,local_48._4_4_);
      }
      goto LAB_00487469;
    }
  }
  SpriteS1::SetPosition
            (this->SpriteS1,pSVar2->S3_arr5031[0].PositionX,*this_00,*puVar14);
  SpriteS1::SetRotation(this->SpriteS1,*(short *)&pSVar2->FirstElement);
  if ((char)local_50 == '\0') {
    if (local_48[4] != '\0') {
      CameraOrPhysics::S131_FUN_00410370
                ((CameraOrPhysics *)gCameraOrPhysics,(S46 *)this->SpriteS1);
    }
  }
  else {
    bVar4 = SpriteS1::SpriteS1_FUN_004baa90(this->SpriteS1);
    if (bVar4 != 0) {
      this->s6->S7[0].AnimationFrame = (int)_DAT_00665894;
      this->s6->S7[0].doorState = (int)_DAT_00665894;
    }
    CameraOrPhysics::S131_FUN_004102a0
              ((CameraOrPhysics *)gCameraOrPhysics,(S110 *)this->SpriteS1);
  }
LAB_00487469:
  FUN_00483460(this,param_1);
  pSVar2 = this->SpriteS1;
  puVar14 = &pSVar2->S3_arr5031[0].PositionX;
  bVar5 = FUN_004037e0(puVar14,(SpriteS1 *)&DAT_00665894);
  if ((CONCAT31(extraout_var_05,bVar5) == 0) &&
     (bVar5 = Player::FUN_0040ce70((Player *)puVar14,(int *)&DAT_006657f4),
     CONCAT31(extraout_var_06,bVar5) == 0)) {
    puVar14 = &pSVar2->S3_arr5031[0].PositionY;
    bVar5 = FUN_004037e0(puVar14,(SpriteS1 *)&DAT_00665894);
    if ((CONCAT31(extraout_var_07,bVar5) == 0) &&
       (bVar5 = Player::FUN_0040ce70((Player *)puVar14,(int *)&DAT_006657f4),
       CONCAT31(extraout_var_08,bVar5) == 0)) {
      return;
    }
  }
  S63_FUN_004827b0(this);
  return;
}


void __thiscall S63__FUN_004874d0(S63 *param_1,SpriteS1 *param_2,Ped *param_3)

{
  undefined4 *this;
  undefined4 *this_00;
  short sVar1;
  SpriteS1 *this_01;
  SpriteS1 *pSVar2;
  S6 *pSVar3;
  bool bVar4;
  bool bVar5;
  byte bVar6;
  char cVar7;
  undefined3 extraout_var;
  undefined4 uVar8;
  undefined3 extraout_var_00;
  undefined4 *puVar9;
  undefined3 extraout_var_01;
  int iVar10;
  int iVar11;
  int iVar12;
  SpriteS1 *pSVar13;
  void *pvVar14;
  undefined4 *puVar15;
  undefined3 extraout_var_02;
  int *piVar16;
  SpriteS1 *local_44;
  Player *local_40;
  int local_3c;
  int local_38;
  S46 *local_34;
  Ped *local_30;
  SpriteS1 *local_2c;
  SpriteS1 *local_28 [2];
  undefined1 local_20 [16];
  undefined1 local_10 [8];
  SpriteS3 *local_8;
  S103 *local_4;
  
  pSVar13 = param_2;
  this_01 = *(SpriteS1 **)(_gObject + 0x58);
  bVar4 = false;
  local_44 = param_2;
  _DAT_00665790 = 0;
  bVar5 = Player::IsCurrentPlayer((Player *)&local_44,(Player *)&DAT_00665894);
  if ((CONCAT31(extraout_var,bVar5) != 0) &&
     (sVar1._0_1_ = param_1->s6->S7[1].field5_0xe,
     sVar1._1_1_ = param_1->s6->S7[1].field6_0xf, sVar1 == 0)) {
    return;
  }
  FUN_004637b0(&DAT_005e6874);
  pSVar2 = param_1->SpriteS1;
  SpriteS1::SetPosition
            (this_01,pSVar2->S3_arr5031[0].PositionX,
             pSVar2->S3_arr5031[0].PositionY,pSVar2->S3_arr5031[0].PositionZ);
  SpriteS1::SetRotation(this_01,*(short *)&param_1->SpriteS1->FirstElement);
  puVar9 = (undefined4 *)param_1->Struc___;
  SpriteS1::S38_FUN_004bcb90(this_01,*puVar9,puVar9[1],puVar9[2]);
  uVar8 = SpriteS1::FUN_00416b40(param_1->SpriteS1);
  SpriteS1::S38_FUN_004206f0(this_01,uVar8);
  SpriteS1::S38_FUN_00482a30(this_01,param_1->SpriteS1->S3_arr5031[0].Car);
  bVar5 = Car::Car_FUN_00403820((Car *)&local_44,(int *)&DAT_00665894);
  if (CONCAT31(extraout_var_00,bVar5) == 0) {
    param_2 = _DAT_00665894;
    local_44 = _DAT_00665894;
  }
  else {
    puVar9 = (undefined4 *)
             Decoder_ReadInt(&local_44,&param_2,(int *)(param_1->Struc___ + 0xc));
    param_2 = (SpriteS1 *)*puVar9;
    puVar9 = (undefined4 *)Decoder_ReadInt(&local_44,local_28,(int *)&param_2);
    local_44 = (SpriteS1 *)*puVar9;
  }
  bVar5 = FUN_004037e0(&param_2,(SpriteS1 *)&DAT_0066582c);
  if (CONCAT31(extraout_var_01,bVar5) != 0) {
    local_44 = pSVar13;
    param_2 = _DAT_0066582c;
  }
  local_2c = local_44;
  FUN_0041fc20(&param_3,&param_3,(S110 *)&local_2c,(Ped *)&local_38,
               (Ped *)&local_3c);
  local_40 = (Player *)CONCAT31(local_40._1_3_,1);
  iVar10 = Decoder_DecodeFloat(&param_2);
  if (0 < iVar10) {
    puVar9 = &this_01->S3_arr5031[0].PositionY;
    this = &this_01->S3_arr5031[0].PositionX;
    this_00 = &this_01->S3_arr5031[0].PositionZ;
    do {
      local_30 = (Ped *)*this;
      local_34 = (S46 *)*puVar9;
      local_2c = (SpriteS1 *)
                 CONCAT22(local_2c._2_2_,*(undefined2 *)&this_01->FirstElement);
      pSVar3 = param_1->s6;
      pSVar3->S7[1].field5_0xe = 0;
      pSVar3->S7[1].field6_0xf = 0;
      iVar10 = Decoder_DecodeFloat(this_00);
      iVar11 = Decoder_DecodeFloat(puVar9);
      iVar12 = Decoder_DecodeFloat(this);
      bVar6 = MapRelatedStruct::S16_FUN_00466cf0
                        (_gMapRelatedStruct,iVar12,iVar11,iVar10);
      if (bVar6 != 0) {
        bVar4 = true;
      }
      local_28[0] = S9::S9_FUN_00401b20((S9 *)puVar9,(SpriteS1 *)(local_28 + 1),
                                        &local_3c);
      pSVar13 = S9::S9_FUN_00401b20((S9 *)this,(SpriteS1 *)local_20,&local_38);
      SpriteS1::SetPosition
                (this_01,(int)pSVar13->FirstElement,
                 (int)local_28[0]->FirstElement,*this_00);
      SpriteS1::SetRotation(this_01,(short)param_3);
      iVar10 = Decoder_DecodeFloat(this_00);
      iVar11 = Decoder_DecodeFloat(puVar9);
      iVar12 = Decoder_DecodeFloat(this);
      bVar6 = MapRelatedStruct::S16_FUN_00466cf0
                        (_gMapRelatedStruct,iVar12,iVar11,iVar10);
      if (bVar6 != 0) {
        S63::S63_FUN_00483100(param_1,this_01);
      }
      pvVar14 = Decoder_ProcessData(this_00,(S110 *)(local_20 + 8),&DAT_0066582c);
      iVar10 = Decoder_DecodeFloat(pvVar14);
      iVar11 = Decoder_DecodeFloat(puVar9);
      iVar12 = Decoder_DecodeFloat(this);
      cVar7 = FUN_00420420(iVar12,iVar11,iVar10);
      if (cVar7 == '\0') {
        pvVar14 = Decoder_ProcessData(this_00,(S110 *)(local_20 + 0xc),
                                    &DAT_0066582c);
        iVar10 = Decoder_DecodeFloat(pvVar14);
        iVar11 = Decoder_DecodeFloat(puVar9);
        iVar12 = Decoder_DecodeFloat(this);
        bVar6 = MapRelatedStruct::S16_FUN_00466cf0
                          (_gMapRelatedStruct,iVar12,iVar11,iVar10);
        if (bVar6 != 0) {
          S63::S63_FUN_00483100(param_1,this_01);
        }
      }
      cVar7 = SpriteS1::S38_FUN_004bd670(this_01);
      if (cVar7 != '\0') {
        if (bVar4) {
          puVar15 = (undefined4 *)
                    FUN_00462ea0(local_10,(uint *)local_10,this_00);
          *this_00 = *puVar15;
          bVar5 = S169::FUN_00403800((S169 *)this_00,(int *)&DAT_00665a04);
          if (CONCAT31(extraout_var_02,bVar5) != 0) {
            FUN_004824e0(local_28,0);
          }
          cVar7 = SpriteS1::S38_FUN_004bd670(this_01);
          if ((cVar7 == '\0') && (cVar7 = FUN_00483060(this_01), cVar7 == '\0'))
          goto LAB_00487978;
        }
        piVar16 = (int *)SpriteS1::FUN_004207b0(this_01,local_10);
        local_8 = (SpriteS3 *)*piVar16;
        local_4 = (S103 *)piVar16[1];
        FUN_00483500();
LAB_004877f8:
        param_2 = local_44;
        SpriteS1::SetPosition(this_01,(int)local_30,(int)local_34,*this_00);
        SpriteS1::SetRotation(this_01,(short)local_2c);
        S63::S63_FUN_00483100(param_1,this_01);
        local_28[0] = (SpriteS1 *)0x2;
        local_40 = (Player *)0x3;
        do {
          local_30 = (Ped *)*this;
          local_34 = (S46 *)*puVar9;
          local_2c = (SpriteS1 *)
                     CONCAT22(local_2c._2_2_,
                              *(undefined2 *)&this_01->FirstElement);
          pSVar13 = Model::FUN_00401bf0((Model *)&param_2,(SpriteS1 *)local_10,
                                        (int *)local_28);
          param_2 = pSVar13->FirstElement;
          FUN_0041fc20(&local_38,&param_3,(S110 *)&param_2,(Ped *)&local_38,
                       (Ped *)&local_3c);
          local_44 = S9::S9_FUN_00401b20((S9 *)puVar9,
                                         (SpriteS1 *)(local_20 + 0xc),&local_3c)
          ;
          pSVar13 = S9::S9_FUN_00401b20((S9 *)this,(SpriteS1 *)(local_20 + 8),
                                        &local_38);
          SpriteS1::SetPosition
                    (this_01,(int)pSVar13->FirstElement,
                     (int)local_44->FirstElement,*this_00);
          SpriteS1::SetRotation(this_01,(short)param_3);
          cVar7 = SpriteS1::S38_FUN_004bd670(this_01);
          if ((cVar7 != '\0') || (cVar7 = FUN_00483060(this_01), cVar7 != '\0'))
          {
            piVar16 = (int *)SpriteS1::FUN_004207b0(this_01,local_20);
            local_8 = (SpriteS3 *)*piVar16;
            local_4 = (S103 *)piVar16[1];
            SpriteS1::SetPosition(this_01,(int)local_30,(int)local_34,*this_00);
            SpriteS1::SetRotation(this_01,(short)local_2c);
            S63::S63_FUN_00483100(param_1,this_01);
          }
          local_40 = (Player *)((int)local_40[-1].string_Arr0x16 + 0x1f);
        } while (local_40 != (Player *)0x0);
        SpriteS1::SetPosition(param_1->SpriteS1,*this,*puVar9,*this_00);
        SpriteS1::SetRotation
                  (param_1->SpriteS1,*(short *)&this_01->FirstElement);
        switch(*(undefined4 *)(param_1->Struc___ + 0x4c)) {
        case 0:
        case 1:
          FUN_00486410(param_1,DAT_005e6894);
          return;
        case 2:
        case 3:
          FUN_00486c60(param_1,&local_8);
          return;
        default:
          return;
        }
      }
      cVar7 = FUN_00483060(this_01);
      if (cVar7 != '\0') {
        piVar16 = (int *)SpriteS1::FUN_004207b0(this_01,local_10);
        local_8 = (SpriteS3 *)*piVar16;
        local_4 = (S103 *)piVar16[1];
        goto LAB_004877f8;
      }
LAB_00487978:
      local_40 = (Player *)CONCAT31(local_40._1_3_,(char)local_40 + '\x01');
      iVar10 = Decoder_DecodeFloat(&param_2);
    } while ((int)((uint)local_40 & 0xff) <= iVar10);
  }
  SpriteS1::SetPosition
            (param_1->SpriteS1,this_01->S3_arr5031[0].PositionX,
             this_01->S3_arr5031[0].PositionY,this_01->S3_arr5031[0].PositionZ);
  SpriteS1::SetRotation(param_1->SpriteS1,*(short *)&this_01->FirstElement);
  return;
}


void __thiscall S63__S63_FUN_00487a30(S63 *this)

{
  CarDoor *pCVar1;
  short sVar2;
  short sVar3;
  S6 *pSVar4;
  byte bVar5;
  bool bVar6;
  char cVar7;
  int *piVar8;
  undefined3 extraout_var;
  int pPed_id;
  Ped *this_00;
  undefined4 local_8;
  Player *local_4;
  
  CarSystemManager::SetIndexDefautCarManager((CarSystemManager *)&local_8);
  S63_FUN_00482ed0(this);
  FUN_00482d90(&local_4,&local_8);
  if (*(int *)(this->Struc___ + 0x58) == 0) {
    FUN_004874d0(local_4,local_8);
  }
  else {
    S63_FUN_00486e90(this,(uint)local_4,local_8);
  }
  S63_FUN_004825c0(this);
  pCVar1 = this->s6->S7;
  piVar8 = (int *)FUN_00482730(&local_8,pCVar1);
  pCVar1->AnimationFrame = *piVar8;
  bVar5 = S63_FUN_00486060(this);
  if (bVar5 == 0) {
    if (this->s6->S46 != (S46 *)0x0) {
      ::Car::Car_FUN_004bef70((Car *)this->s6,(Sprite *)this->SpriteS1);
    }
    bVar6 = Player::IsCurrentPlayer((Player *)&local_4,(Player *)&DAT_00665894);
    if ((((CONCAT31(extraout_var,bVar6) != 0) &&
         (pSVar4 = this->s6, sVar2._0_1_ = pSVar4->S7[1].field5_0xe,
         sVar2._1_1_ = pSVar4->S7[1].field6_0xf, sVar2 == 0)) &&
        (pSVar4->S7[2].PedInDoor != (Ped *)0x2)) &&
       (cVar7 = S63_FUN_00484740(this), cVar7 == '\0')) {
      this->s6->S7[1].AnimationFrame = _DAT_00665894;
      this->s6->S7[0].doorState = _DAT_00665894;
      FUN_00485760(*(undefined4 *)(this->Struc___ + 0x38));
      bVar5 = S63_FUN_00421080(this);
      if (bVar5 == 0) {
        return;
      }
      cVar7 = S63_FUN_00420ff0(this);
      if (cVar7 == '\0') {
        return;
      }
      S68::S68_FUN_004b9940(_gS68,this->field17_0x26);
      this->field17_0x26 = 0;
      return;
    }
    sVar2 = *(short *)&this->s6->S7[1].field3_0xc;
    if ((0 < sVar2) &&
       (*(short *)&this->s6->S7[1].field3_0xc = sVar2 + -1,
       sVar3._0_1_ = this->s6->S7[1].field3_0xc,
       sVar3._1_1_ = this->s6->S7[1].field4_0xd, sVar3 == 0)) {
      cVar7 = S63_FUN_00420ff0(this);
      if (cVar7 != '\0') {
        bVar5 = S63_FUN_00420ff0(this);
        pPed_id = S68::S68GetPedID(_gS68,bVar5);
        if ((pPed_id != 0) &&
           (this_00 = Char::FindPed(gChar,pPed_id), this_00 != (Ped *)0x0)) {
          FUN_00435220(this_00,this->DamageType);
        }
      }
      FUN_00485760(*(undefined4 *)(this->Struc___ + 0x3c));
    }
  }
  return;
}


void __thiscall S63__S63_FUN_00487bc0(S63 *this)

{
  CarDoor *pCVar1;
  short sVar2;
  SpriteS1 *pSVar3;
  S6 *pSVar4;
  bool bVar5;
  byte bVar6;
  char cVar7;
  int *piVar8;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined4 local_14;
  Player *local_10;
  Player *local_c;
  int local_8;
  int local_4;
  
  CarSystemManager::SetIndexDefautCarManager((CarSystemManager *)&local_14);
  pSVar3 = this->SpriteS1;
  local_c = (Player *)pSVar3->S3_arr5031[0].PositionX;
  local_8 = pSVar3->S3_arr5031[0].PositionY;
  local_4 = pSVar3->S3_arr5031[0].PositionZ;
  S63_FUN_00482ed0(this);
  FUN_00482d90(&local_10,&local_14);
  if (*(int *)(this->Struc___ + 0x58) == 0) {
    FUN_004874d0(local_10,local_14);
  }
  else {
    S63_FUN_00486e90(this,(uint)local_10,local_14);
  }
  pCVar1 = this->s6->S7;
  piVar8 = (int *)FUN_00482730(&local_14,pCVar1);
  pCVar1->AnimationFrame = *piVar8;
  if ((*(char *)(this->Struc___ + 0x65) == -1) &&
     (*(int *)(this->Struc___ + 0x34) != 9)) {
    pSVar3 = this->SpriteS1;
    bVar5 = ::Car::Car_FUN_00403820
                      ((Car *)&pSVar3->S3_arr5031[0].PositionX,(int *)&local_c);
    if (CONCAT31(extraout_var,bVar5) == 0) {
      bVar5 = ::Car::Car_FUN_00403820
                        ((Car *)&pSVar3->S3_arr5031[0].PositionY,&local_8);
      if (CONCAT31(extraout_var_00,bVar5) == 0) {
        bVar5 = ::Car::Car_FUN_00403820
                          ((Car *)&pSVar3->S3_arr5031[0].PositionZ,&local_4);
        if (CONCAT31(extraout_var_01,bVar5) == 0) goto LAB_00487c9a;
      }
    }
  }
  if ((char)this->s6->S7[2].doorState == '\0') {
    S63_FUN_00485fd0(this);
  }
LAB_00487c9a:
  bVar6 = S63_FUN_00486060(this);
  if (bVar6 == 0) {
    if (this->s6->S46 != (S46 *)0x0) {
      ::Car::Car_FUN_004bef70((Car *)this->s6,(Sprite *)this->SpriteS1);
      if ((this->s6->S46 == (S46 *)0x0) && (this->DamageType == 0x7f)) {
        S63_FUN_004827b0(this);
      }
    }
    bVar5 = Player::IsCurrentPlayer((Player *)&local_10,(Player *)&DAT_00665894)
    ;
    if (((CONCAT31(extraout_var_02,bVar5) != 0) &&
        (pSVar4 = this->s6, sVar2._0_1_ = pSVar4->S7[1].field5_0xe,
        sVar2._1_1_ = pSVar4->S7[1].field6_0xf, sVar2 == 0)) &&
       (pSVar4->S7[2].PedInDoor == (Ped *)0x2)) {
      cVar7 = S63_FUN_00484740(this);
      if ((cVar7 == '\0') && (_DAT_00665790 == 0)) {
        this->s6->S7[1].AnimationFrame = _DAT_00665894;
        this->s6->S7[0].doorState = _DAT_00665894;
        if (this->DamageType != 0xb7) {
          bVar6 = S63_FUN_00421080(this);
          if (bVar6 != 0) {
            cVar7 = S63_FUN_00420ff0(this);
            if (cVar7 != '\0') {
              S68::S68_FUN_004b9940(_gS68,this->field17_0x26);
              this->field17_0x26 = 0;
            }
          }
        }
        FUN_00485760(*(undefined4 *)(this->Struc___ + 0x38));
      }
    }
  }
  return;
}


void __thiscall S63__S63_FUN_00487d70(S63 *this)

{
  byte bVar1;
  undefined4 in_EDX;
  
  _DAT_00665790 = 0;
switchD_00487d88_switchD:
  switch(*(undefined4 *)(this->Struc___ + 0x34)) {
  case 0:
    bVar1 = S63_FUN_00486060(this);
    if (bVar1 == 0) {
      S63_FUN_004825a0(this);
      return;
    }
    break;
  case 1:
    bVar1 = S63_FUN_00486060(this);
    if (bVar1 == 0) {
      S63_FUN_004825a0(this);
      S63_FUN_00482560(this);
      return;
    }
    break;
  case 2:
  case 8:
    bVar1 = S63_FUN_00486060(this);
    if (bVar1 == 0) {
      S63_FUN_004825a0(this);
      S63_FUN_00485fd0(this);
      return;
    }
    break;
  case 3:
  case 7:
    S63_FUN_004826a0(this);
    DAT_00665774 = 1;
    S63_FUN_00487a30(this);
    goto LAB_00487e26;
  case 4:
  case 9:
    S63_FUN_004826a0(this);
    DAT_00665774 = 1;
    S63_FUN_00487bc0(this);
LAB_00487e26:
    if (DAT_00665760 == '\0') {
      S63_FUN_00482630(this);
      return;
    }
    break;
  case 5:
    if ((this->S116 != (S116 *)0x0) &&
       (bVar1 = S116::S116_FUN_00491a70
                          (this->S116,_DAT_00665894,
                           CONCAT22((short)((uint)in_EDX >> 0x10),
                                    _DAT_006657f8______S38)), bVar1 != 0)) {
      this->field16_0x25 = 1;
    }
    break;
  case 6:
  case 10:
  case 0xb:
    S63_FUN_00486060(this);
  case 0xc:
    S63_FUN_004825a0(this);
    return;
  default:
    goto switchD_00487d88_switchD;
  }
  return;
}


undefined4 __thiscall S63__S63_FUN_00487e80(S63 *this)

{
  byte bVar1;
  undefined4 in_EAX;
  uint3 uVar2;
  uint3 extraout_var;
  
  DAT_00665774 = 0;
  DAT_00665760 = 0;
  if (this->field16_0x25 != '\x01') {
    S63_FUN_00487d70(this);
  }
  uVar2 = (uint3)((uint)in_EAX >> 8);
  if (this->field16_0x25 != '\0') {
    if (this->field16_0x25 == '\x02') {
      bVar1 = Game::Game_FUN_0045c420
                        (gGame,(Sprite *)this->SpriteS1,_DAT_00665894);
      uVar2 = extraout_var;
      if (bVar1 != 0) goto LAB_00487ecb;
    }
    S63_FUN_004826a0(this);
    return CONCAT31(uVar2,1);
  }
LAB_00487ecb:
  return (uint)uVar2 << 8;
}


byte __thiscall S63__S63_FUN_004932d0(int param_1,S63 *param_2)

{
  int iVar1;
  Ped *this;
  byte bVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  
  bVar2 = S63_FUN_00420ff0(param_2);
  iVar5 = S68::S68GetPedID(_gS68,bVar2);
  iVar1 = param_2->DamageType;
  if (((iVar1 == 0x80) || (iVar1 == 0x8a)) ||
     ((iVar1 == 10 && (DAT_0066a3c9 == '\0')))) {
    iVar1 = *(int *)(param_1 + 0x80);
    Object::S60_FUN_00485540
              (_gObject,*(undefined4 *)(iVar1 + 0x14),
               *(undefined4 *)(iVar1 + 0x18),*(undefined4 *)(iVar1 + 0x1c),
               (void *)CONCAT22((short)((uint)iVar5 >> 0x10),_DAT_0066a434),0x12
              );
    if (param_2->DamageType == 10) {
      DAT_0066a3c9 = '\x01';
    }
  }
  this = *(Ped **)(param_1 + 0x7c);
  cVar3 = Ped::sPed_FUN_00420b50(this);
  cVar4 = S63_FUN_00420ff0(param_2);
  if (cVar4 != cVar3) {
    bVar2 = Ped::PedNormal_FUN_00441a30(this,param_2);
    return bVar2;
  }
  return 0;
}


undefined1 __thiscall S63__FUN_004973e0(S63 *param_1,char param_2)

{
  byte bVar1;
  
  bVar1 = S63::S63_FUN_00421080(param_1);
  if ((bVar1 != 0) && (param_1->field17_0x26 == param_2)) {
    return 1;
  }
  return 0;
}


void __thiscall S63__FUN_004bed60(void *this,S63 *pS63)

{
  undefined4 *in_EAX;
  
  SpriteS4::S45_SetNext(_gSpriteS4);
  *in_EAX = pS63;
                              // WARNING: Load size is inaccurate
  in_EAX[1] = *this;
  S1::S1_FUN_0041e1e0((S1 *)(in_EAX + 2));
  *(undefined4 **)this = in_EAX;
  return;
}


