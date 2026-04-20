// Module: S119
// Functions working with structure S119
// Generated from gta2.exe.c

#include "common.h"

byte __thiscall S119__S119_FUN_0044c870(S119 *this,Car *pCar)

{
  if (((pCar == (Car *)this->field1_0x4) && (pCar != (Car *)0x0)) &&
     (pCar->ID_Object == this->field2_0x8)) {
    return 1;
  }
  return 0;
}


void __thiscall S119__FUN_00476ad0(S119 *this)

{
  this->field_0x3f = 1;
  return;
}


byte __thiscall S119__S199_FUN_00489680(S119 *this)

{
  byte bVar1;
  bool bVar2;
  char cVar3;
  undefined4 *puVar4;
  Player *pPVar5;
  Ped *pPVar6;
  short *psVar7;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  void *this_00;
  void *pvVar8;
  undefined3 extraout_var_03;
  int iVar9;
  Car *pCVar10;
  int *piVar11;
  S169 **ppSVar12;
  undefined4 *puVar13;
  S110 *pSVar14;
  undefined *puVar15;
  S1 **ppSVar16;
  undefined1 local_5c [2];
  undefined1 local_5a [2];
  uint local_58;
  byte local_54 [4];
  undefined4 local_50;
  undefined1 local_4c [4];
  undefined1 local_48 [4];
  undefined1 local_44 [4];
  undefined1 local_40 [4];
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  S110 local_30;
  undefined3 extraout_var_04;
  
  iVar9 = this->field3_0xc;
  if (iVar9 != 1) {
    if (iVar9 == 2) {
      if (this->Car->Player == (Player *)0x0) {
        Car::CarMakeDriveable4(this->Car);
      }
      pCVar10 = (Car *)(*(int *)&this->field_0x44 + 1);
      *(Car **)&this->field_0x44 = pCVar10;
      if ((Car *)0x12b < pCVar10) goto LAB_00489863;
      pPVar6 = this->Car->Driver;
      if (pPVar6 != (Ped *)0x0) {
        bVar1 = Car::IsDriverPlayer(this->Car);
        if (bVar1 == 0) {
          Ped::PedSetObjective(pPVar6,0x1b,9999);
        }
      }
      cVar3 = FUN_004bb4d0(&this->S1_1,&this->S1_2,local_54,&local_58);
      if ((cVar3 != '\x04') && (this->field_0x3d == '\0')) {
        pCVar10 = this->Car;
        FUN_004895d0(pCVar10->Player);
        bVar1 = (byte)pCVar10;
        S1::S1_FUN_004a0930((S1 *)this->Car->Player);
        return bVar1;
      }
      this->field_0x3d = 1;
      this->field_0x3c = this->field_0x3c + -1;
      FUN_004895d0(this->Car->Player);
      bVar1 = this->field_0x3c;
      puVar4 = (undefined4 *)(uint)bVar1;
      if (bVar1 == 0) {
        this->field3_0xc = 3;
        FUN_004895d0(this->Car->Player);
        return bVar1;
      }
    }
    else {
      puVar4 = (undefined4 *)(iVar9 + -3);
      if (puVar4 == (undefined4 *)0x0) {
        if (this->Car->CarSprite != (SpriteS1 *)0x0) {
          FUN_00476230(this->Car);
          FUN_004895e0(this->Car);
          FUN_00476a30((void *)this->field4_0x10);
          FUN_004895f0((void *)this->field4_0x10);
          Car::Car_FUN_00475c30(this->Car);
          Car::Car_FUN_00426f60(this->Car);
          Passenger::FUN_00446120((Passenger *)&this->Car->Passenger);
          pCVar10 = this->Car;
          bVar1 = Car::IsDriverPlayer(pCVar10);
          if (bVar1 != 0) {
            pPVar5 = (Player *)Car::GetPlayer(pCVar10);
            Player::SetAllControlStatusOn(pPVar5);
          }
          if (this->field_0x3f == '\0') {
            pCVar10 = this->Car;
            pPVar6 = Get_FUN_004118b0(pCVar10);
            if (pPVar6 == (Ped *)0x0) {
              pPVar6 = (Ped *)this->field5_0x14;
              if (pPVar6 != (Ped *)0x0) {
                ppSVar16 = &this->S1_1;
                pPVar5 = (Player *)Ped__GetXCoordinate(pPVar6,(int)local_4c);
                bVar2 = Player::FUN_0040ce70(pPVar5,(int *)ppSVar16);
                if (CONCAT31(extraout_var,bVar2) != 0) {
                  ppSVar16 = &this->S1_2;
                  pPVar5 = (Player *)Ped__GetXCoordinate(pPVar6,(int)local_48);
                  bVar2 = Player::CheckCondition(pPVar5,(int *)ppSVar16);
                  if (CONCAT31(extraout_var_00,bVar2) != 0) {
                    piVar11 = (int *)&this->field_0x1c;
                    pPVar5 = (Player *)Ped__GetYCoordinate(pPVar6,(int)local_44);
                    bVar2 = Player::FUN_0040ce70(pPVar5,piVar11);
                    if (CONCAT31(extraout_var_01,bVar2) != 0) {
                      piVar11 = (int *)&this->field_0x24;
                      pPVar5 = (Player *)Ped__GetYCoordinate(pPVar6,(int)local_40)
                      ;
                      bVar2 = Player::CheckCondition(pPVar5,piVar11);
                      puVar4 = (undefined4 *)CONCAT31(extraout_var_02,bVar2);
                      if (puVar4 != (undefined4 *)0x0) {
                        Car::Car_FUN_0041e450(pCVar10,&local_3c);
                        FUN_0043ad50(pPVar6,this->S1_3,
                                     *(undefined4 *)&this->field_0x34,*puVar4);
                        psVar7 = (short *)FUN_00489560(local_5a,this->
                                        field26_0x38);
                        Ped::SetRotation((Ped *)this->field5_0x14,*psVar7);
                      }
                    }
                  }
                }
              }
            }
            else {
              puVar4 = &local_50;
              Car::Car_FUN_0041e450(pCVar10,puVar4);
              FUN_0043ad50(pPVar6,this->S1_3,*(undefined4 *)&this->field_0x34,
                           *puVar4);
              Car::Car_FUN_004235d0(this->Car);
              psVar7 = (short *)FUN_00489560(local_5c,this->field26_0x38);
              Ped::SetRotation(pPVar6,*psVar7);
              this->Car->Driver = (Ped *)0x0;
              pPVar6->GameObject->field47_0x5c = 0x14;
            }
          }
          Car::FUN_00421490(this->Car);
        }
        this->field1_0x4 = this->Car;
        iVar9 = this->Car->ID_Object;
        this->Car = (Car *)0x0;
        this->field2_0x8 = iVar9;
        FUN_00489650(this);
        return (byte)iVar9;
      }
    }
    goto LAB_00489ab5;
  }
  pCVar10 = this->Car;
  if (pCVar10->CarSprite == (SpriteS1 *)0x0) {
LAB_00489863:
    this->field3_0xc = 3;
    return (byte)pCVar10;
  }
  pPVar6 = pCVar10->Driver;
  if ((pPVar6 != (Ped *)0x0) && (pPVar6 != (Ped *)this->field5_0x14)) {
    this->field5_0x14 = pPVar6;
  }
  puVar4 = (undefined4 *)
           FUN_004bb4d0(&this->S1_1,&this->S1_2,local_54,&local_58);
  bVar1 = (byte)puVar4;
  if (bVar1 == 2) {
    puVar4 = (undefined4 *)(uint)local_54[0];
    if (local_54[0] == 0) {
      if ((char)local_58 != '\x01') {
        return local_54[0];
      }
    }
    else {
      if (local_54[0] != 2) goto LAB_00489ab5;
      if ((char)local_58 != '\x03') {
        return local_54[0];
      }
    }
LAB_00489989:
    FUN_0044a3e0(this->Car);
    Car::FUN_004218a0(this->Car);
    pCVar10 = this->Car;
    bVar1 = Car::IsDriverPlayer(pCVar10);
    if (bVar1 != 0) {
      pPVar5 = (Player *)Car::GetPlayer(pCVar10);
      Player::SetAllControlStatusOff(pPVar5);
    }
    Car::Car_FUN_00475c10(this->Car);
    FUN_004895d0(this->Car->Player);
    pCVar10 = this->Car;
    puVar4 = &local_38;
    Car::Car_FUN_0041e440(pCVar10,puVar4);
    puVar13 = puVar4;
    Car::Car_FUN_0041e430(pCVar10,&local_34);
    FUN_00432860(&local_30,puVar4,puVar13);
    pSVar14 = &local_30;
    pvVar8 = &local_30.field_0x10;
    ppSVar12 = &local_30.S169;
    piVar11 = (int *)&DAT_00669c5c;
    this_00 = (void *)FUN_0040f5c0(&local_30.field15_0x18,
                                   &(pCVar10->CarSprite->S3_arr5031[0].SpriteS3)
                                    ->S39_Arr48[0].field7_0xc +
                                   (local_58 & 0xff) * 2);
    pvVar8 = FUN_004202e0(this_00,pvVar8,piVar11);
    puVar4 = (undefined4 *)FUN_0040f600(pvVar8,ppSVar12,pSVar14);
    ppSVar16 = &this->S1;
    *ppSVar16 = (S1 *)*puVar4;
    *(undefined4 *)&this->field_0x2c = puVar4[1];
    bVar2 = Player::IsCurrentPlayer((Player *)ppSVar16,(Player *)&DAT_00669be0);
    if (CONCAT31(extraout_var_03,bVar2) != 0) {
      bVar2 = Player::IsCurrentPlayer
                        ((Player *)&this->field_0x2c,(Player *)&DAT_00669be0);
      iVar9 = CONCAT31(extraout_var_04,bVar2);
      if (iVar9 != 0) {
        this->field_0x3d = 1;
        this->field3_0xc = 2;
        S1::S1_FUN_004a0930((S1 *)pCVar10->Player);
        this->field3_0xc = 2;
        return (byte)iVar9;
      }
    }
    puVar4 = &local_30.field20_0x20;
    puVar15 = &DAT_00669c9c;
    FUN_00420390(&local_30.field22_0x28);
    puVar4 = (undefined4 *)FUN_0041e1a0(puVar4,puVar15);
    *ppSVar16 = (S1 *)*puVar4;
    *(undefined4 *)&this->field_0x2c = puVar4[1];
    S1::S1_FUN_004a0930((S1 *)pCVar10->Player);
  }
  else {
    if (bVar1 < 3) goto LAB_00489ab5;
    if (bVar1 < 4) goto LAB_00489989;
  }
  this->field3_0xc = 2;
LAB_00489ab5:
  return (byte)puVar4;
}


S119 * __thiscall S119__S119(S119 *this)

{
  this->Car = (Car *)0x0;
  this->field4_0x10 = 0;
  this->field5_0x14 = 0;
  this->field3_0xc = 0;
  S1::S1_FUN_0041e1e0((S1 *)&this->S1);
  S1::S1_FUN_0041e1e0((S1 *)&this->S1_1);
  S1::S1_FUN_0041e1e0((S1 *)&this->S1_2);
  this->field26_0x38 = 0;
  S1::S1_FUN_0041e1e0((S1 *)&this->S1_3);
  this->field_0x3c = 0x1e;
  this->field_0x3d = 0;
  this->field_0x3e = 0;
  this->field_0x3f = 0;
  this->field_0x40 = 0;
  this->field1_0x4 = 0;
  this->field2_0x8 = 0;
  return this;
}


bool __thiscall S119__IsCarEqual(S119 *this,Car *param_1)

{
  return param_1 == this->Car;
}


