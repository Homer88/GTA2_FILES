// Module: S83
// Functions working with structure S83
// Generated from gta2.exe.c

#include "common.h"

S83 * __thiscall S83__S83(S83 *this)

{
  TrainComponent *pTVar1;
  undefined1 *puVar2;
  int iVar3;
  
  this->field7_0x8 = 0;
  this->Car = (Car *)0x0;
  this->field54_0x44 = 0;
  this->field59_0x4c = 0;
  this->field4_0x4 = 0;
  this->field0_0x0 = 0;
  this->field2_0x2 = 0;
  this->field58_0x48 = 0;
  this->field60_0x50 = 2;
  this->field61_0x54 = 0;
  this->field62_0x55 = 0;
  this->SkipCount = 0;
  this->field64_0x57 = 0;
  puVar2 = &this->field42_0x38;
  pTVar1 = this->trainComponents;
  iVar3 = 10;
  do {
    pTVar1->linkedCar = (Car *)0x0;
    *puVar2 = 0xff;
    pTVar1 = pTVar1 + 1;
    puVar2 = puVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  this->field52_0x42 = 0xff;
  this->field53_0x43 = 0;
  this->field1_0x1 = 0;
  return this;
}


void __thiscall S83__FUN_004af290(S83 *this)

{
  if (!gSkipTrains) {
    this->field60_0x50 = (this->Car->Driver != (Ped *)0x0) + 2;
  }
  return;
}


void __thiscall S83__FUN_004af2b0(S83 *this)

{
  Car *pCVar1;
  char cVar2;
  Car *this_00;
  byte bVar3;
  short *psVar4;
  uint local_4;
  
  pCVar1 = this->trainComponents[0].linkedCar;
  if (!gSkipTrains) {
    this_00 = this->Car;
    if ((31999 < this_00->Damage) && (this->field52_0x42 == -1)) {
      this->field52_0x42 = 10;
    }
    if ((this->field42_0x38 == '\x01') && (31999 < pCVar1->Damage)) {
      this->field52_0x42 = 10;
    }
    if (('\0' < (char)this->field52_0x42) &&
       (cVar2 = this->field52_0x42 + -1, this->field52_0x42 = cVar2,
       cVar2 == '\0')) {
      if (31999 < this_00->Damage) {
        this_00 = pCVar1;
      }
      Car::Car_CollisionOnCar(this_00,32000,&DAT_0066bb90);
    }
    bVar3 = 0;
    local_4 = 0;
    if (this->field53_0x43 != 0) {
      psVar4 = &pCVar1->Damage;
      do {
        if ((*(char *)((int)(this->trainComponents + 10) + local_4) == -1) &&
           (31999 < *psVar4)) {
          if (bVar3 == 0) {
            if ((int)local_4 < (int)(this->field53_0x43 - 1)) {
              *(undefined1 *)((int)(this->trainComponents + 10) + local_4 + 1) =
                   10;
            }
            else {
              this->field52_0x42 = 10;
            }
          }
          else {
            *(undefined1 *)((int)(this->trainComponents + 9) + local_4 + 3) = 10
            ;
          }
          *(undefined1 *)((int)(this->trainComponents + 10) + local_4) = 0;
        }
        if (('\0' < *(char *)((int)(this->trainComponents + 10) + local_4)) &&
           (cVar2 = *(char *)((int)(this->trainComponents + 10) + local_4) + -1,
           *(char *)((int)(this->trainComponents + 10) + local_4) = cVar2,
           cVar2 == '\0')) {
          Car::Car_CollisionOnCar
                    (this->trainComponents[local_4].linkedCar,32000,
                     &DAT_0066bb90);
          if (bVar3 != 0) {
            *(undefined1 *)((int)(this->trainComponents + 9) + local_4 + 3) = 10
            ;
          }
          if ((int)local_4 < (int)(this->field53_0x43 - 1)) {
            *(undefined1 *)((int)(this->trainComponents + 10) + local_4 + 1) =
                 10;
          }
          if (bVar3 == 0) {
            this->field52_0x42 = 10;
          }
        }
        psVar4 = psVar4 + 0x5e;
        bVar3 = bVar3 + 1;
        local_4 = (uint)bVar3;
      } while (bVar3 < this->field53_0x43);
    }
  }
  return;
}


void __thiscall S83__FUN_004af8a0(S83 *this)

{
  Car *pCVar1;
  Car *pCVar2;
  Player *this_00;
  byte bVar3;
  undefined4 uVar4;
  
  if (!gSkipTrains) {
    pCVar1 = this->Car;
    this->Car = this->trainComponents[this->field53_0x43 - 1].linkedCar;
    this->trainComponents[this->field53_0x43 - 1].linkedCar = pCVar1;
    CarsPrefabs::S5_FUN_00420f20(gCarsPrefabs,this->Car);
    CarsPrefabs::S5_FUN_00420f30
              (gCarsPrefabs,
               this->trainComponents[this->field53_0x43 - 1].linkedCar);
    pCVar2 = this->trainComponents[this->field53_0x43 - 1].linkedCar;
    if (pCVar2->Player != (Player *)0x0) {
      Car::Car_FUN_00423a50(pCVar2);
    }
    S1::S1_FUN_004a1be0((S1 *)(this->trainComponents[this->field53_0x43 - 1].
                              linkedCar)->Player);
    if (this->Car->Player != (Player *)0x0) {
      Car::Car_FUN_00423a50(this->Car);
    }
    Player::FUN_0049ee10(this->Car->Player,this->Car->CarSprite);
    this->Car->Driver = pCVar1->Driver;
    if (this->Car->Player != (Player *)0x0) {
      Car::Car_FUN_00423a50(this->Car);
    }
    pCVar2 = this->Car;
    bVar3 = Car::IsDriverPlayer(pCVar2);
    this_00 = pCVar2->Player;
    if (bVar3 == 0) {
      Player::SetAttackChanged(this_00);
    }
    else {
      Player::Player_FUN_004212b0(this_00);
    }
    pCVar1->Driver = (Ped *)0x0;
    Car::CarMakeDriveable2(this->Car);
    Car::CarMakeDriveable3((Car *)this->Car->EngineStruct,this->Car);
    Car::Car_FUN_004266f0(pCVar1);
    pCVar1 = this->Car;
    uVar4 = Ped::GetSearchType(pCVar1->Driver);
    Car::CarMakeDriveable1(pCVar1,uVar4);
  }
  return;
}


void __thiscall S83__FUN_004af9a0(S83 *this)

{
  if (!gSkipTrains) {
    switch(this->field60_0x50) {
    case 0:
      this->field60_0x50 = 1;
      return;
    case 1:
      FUN_004af8a0(this);
      this->field60_0x50 = 2;
      return;
    case 2:
      this->field60_0x50 = 3;
      return;
    case 3:
      this->field60_0x50 = 4;
      return;
    case 4:
      this->field60_0x50 = 5;
    }
  }
  return;
}


void __thiscall S83__FUN_004afa10(S83 *this)

{
  if (!gSkipTrains) {
    switch(this->field60_0x50) {
    case 1:
      this->field60_0x50 = 0;
      return;
    case 2:
      FUN_004af8a0(this);
      this->field60_0x50 = 1;
      return;
    case 3:
      this->field60_0x50 = 2;
      return;
    case 4:
      this->field60_0x50 = 3;
      return;
    case 5:
      this->field60_0x50 = 4;
    }
  }
  return;
}


void __thiscall S83__FUN_004afa80(S83 *this)

{
  if (!gSkipTrains) {
    if (this->field60_0x50 < 2) {
      this->field1_0x1 = 1;
      FUN_004af8a0(this);
    }
    this->field60_0x50 = 2;
  }
  return;
}


void __thiscall S83__UpdateTrainComponents(S83 *this)

{
  int iVar1;
  int iVar2;
  TrainComponent *pTrainComponent;
  Car *pCar;
  
  if (!gSkipTrains) {
    pTrainComponent = this->trainComponents;
    iVar2 = 2;
    do {
      pCar = pTrainComponent->linkedCar;
      if ((pCar != (Car *)0x0) &&
         (iVar1 = Car::GetModelCar(pCar), iVar1 == 0x3b)) {
        Car::FUN_0041f8f0(pCar);
      }
      pTrainComponent = pTrainComponent + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}


void __thiscall S83__FUN_004afaf0(S83 *this)

{
  Car *this_00;
  int iVar1;
  int iVar2;
  TrainComponent *pTVar3;
  
  if (!gSkipTrains) {
    pTVar3 = this->trainComponents;
    iVar2 = 2;
    do {
      this_00 = pTVar3->linkedCar;
      if ((this_00 != (Car *)0x0) &&
         (iVar1 = Car::GetModelCar(this_00), iVar1 == 0x3b)) {
        FUN_0041f8a0(this_00);
      }
      pTVar3 = pTVar3 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}


void __thiscall S83__FUN_004afb30(S83 *this)

{
  Passenger **this_00;
  TrainComponent *pTVar1;
  byte bVar2;
  bool bVar3;
  byte bVar4;
  int iVar5;
  Ped *pPVar6;
  undefined4 local_4;
  
  if (gSkipTrains) {
    return;
  }
  if (gSkipDummies) {
    return;
  }
  if (0x31 < (byte)gChar->dummy_chars) {
    return;
  }
  if (this->field7_0x8 == 2) {
    bVar4 = 0;
    if (this->field53_0x43 != 0) {
      do {
        pTVar1 = this->trainComponents + bVar4;
        iVar5 = Car::GetModelCar(this->trainComponents[bVar4].linkedCar);
        if (iVar5 == 0x3b) {
          this->SkipCount = 1;
          bVar2 = Game::Game_FUN_0045c420
                            (gGame,(Sprite *)pTVar1->linkedCar->CarSprite,
                             _DAT_0066bc54);
          if ((bVar2 != 0) && ((char)this->field61_0x54 < '\x01')) {
            local_4 = 4;
            DAT_0066bee8 = Random(&gRandom,(int)&local_4);
            bVar2 = Car::Car_FUN_0041f880(pTVar1->linkedCar);
            if (DAT_0066bee8 < bVar2) {
              do {
                bVar3 = Car::Car_FUN_00425b60(pTVar1->linkedCar,DAT_0066bee8);
                if ((bVar3) && ('\0' < (char)this->SkipCount)) {
                  pPVar6 = Char::S47_FUN_0043deb0(gChar);
                  pPVar6->CarCurrent = pTVar1->linkedCar;
                  Ped::PedSetObjective(pPVar6,0x26,9999);
                  Ped__EnterCar(pPVar6,pTVar1->linkedCar);
                  Passenger::FUN_00445f10
                            ((Passenger *)&pPVar6->CarCurrent->Passenger,pPVar6)
                  ;
                  Ped__SetAnimationState(pPVar6,DAT_0066bee8);
                  this->SkipCount = this->SkipCount - 1;
                }
                DAT_0066bee8 = DAT_0066bee8 + 1;
                bVar2 = Car::Car_FUN_0041f880(pTVar1->linkedCar);
              } while (DAT_0066bee8 < bVar2);
            }
            this->field61_0x54 = 7;
          }
        }
        bVar4 = bVar4 + 1;
      } while (bVar4 < this->field53_0x43);
      this->field61_0x54 = this->field61_0x54 + -1;
      return;
    }
    goto LAB_004afe09;
  }
  bVar4 = Game::Game_FUN_0045c420
                    (gGame,(Sprite *)this->Car->CarSprite,_DAT_0066bc54);
  if (((bVar4 == 0) || ('\0' < (char)this->field61_0x54)) ||
     (*(char *)(_gPublicTransport + 0x1818) != '\0')) goto LAB_004afe09;
  bVar3 = Car::Car_FUN_00425b60(this->Car,2);
  if (bVar3) {
    this_00 = &this->Car->Passenger;
    bVar3 = Passenger::FUN_00420ea0((Passenger *)this_00);
    if (!bVar3) {
      pPVar6 = FUN_00446100(this_00);
      pPVar6->CarCurrent = this->Car;
      Ped::PedSetObjective(pPVar6,0x26,9999);
      Ped__EnterCar(pPVar6,this->Car);
      Ped__SetAnimationState(pPVar6,2);
      Ped__SetCurrentOccupation(pPVar6,8);
      if ((this->field0_0x0 == 1) &&
         (bVar4 = this->SkipCount, '\0' < (char)bVar4)) {
LAB_004afdbc:
        this->SkipCount = bVar4 - 1;
      }
      goto LAB_004afdc1;
    }
    if (('\x06' < (char)this->SkipCount) || (this->field0_0x0 == 0)) {
      pPVar6 = Char::S47_FUN_0043deb0(gChar);
      pPVar6->CarCurrent = this->Car;
      Passenger::FUN_00445f10((Passenger *)&this->Car->Passenger,pPVar6);
      Ped::PedSetObjective(pPVar6,0x26,9999);
      Ped__EnterCar(pPVar6,this->Car);
      Ped__SetAnimationState(pPVar6,2);
      Ped__SetCurrentOccupation(pPVar6,8);
      if (this->field0_0x0 == 1) {
        bVar4 = this->SkipCount;
        goto LAB_004afdbc;
      }
      goto LAB_004afdc1;
    }
  }
  else {
LAB_004afdc1:
    if (this->field0_0x0 == 0) {
      local_4 = 0x14;
      bVar4 = Random(&gRandom,(int)&local_4);
      this->field61_0x54 = bVar4 + 0x14;
      this->field61_0x54 = bVar4 + 0x13;
      return;
    }
  }
  local_4 = 0x14;
  bVar4 = Random(&gRandom,(int)&local_4);
  this->field61_0x54 = bVar4 + 0x28;
LAB_004afe09:
  this->field61_0x54 = this->field61_0x54 + -1;
  return;
}


