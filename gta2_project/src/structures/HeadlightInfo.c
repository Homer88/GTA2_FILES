// Module: S127
// Functions working with structure S127
// Generated from gta2.exe.c

#include "../../include/common.h"

byte __thiscall S127__S127_IsActionAllowed(S127 *this,int param_1)

{
  ushort uVar1;
  
  uVar1 = this->field1_0x2;
  while( true ) {
    if (uVar1 == this->field0_0x0) {
      return 0;
    }
    if (this->arr_S128[uVar1].field0_0x0 == param_1) break;
    uVar1 = uVar1 + 1;
    if (9 < uVar1) {
      uVar1 = 0;
    }
  }
  return 1;
}


S127 * __thiscall S127__S127(S127 *this)

{
  _eh_vector_constructor_iterator_
            (this->arr_S128,20,10,S128::S128,(_func_void_void_ptr *)&S128::~s128
            );
  this->field0_0x0 = 0;
  this->field1_0x2 = 0;
  return this;
}


void __thiscall S127__S127_FUN_0044a110(S127 *this,int pID,int param_2)

{
  ushort uVar1;
  
  S128::S128_FUN_0044a060(this->arr_S128 + this->field0_0x0,pID,param_2);
  this->field0_0x0 = this->field0_0x0 + 1;
  if (9 < this->field0_0x0) {
    this->field0_0x0 = 0;
  }
  if ((this->field0_0x0 == this->field1_0x2) &&
     (uVar1 = this->field1_0x2 + 1, this->field1_0x2 = uVar1, 9 < uVar1)) {
    this->field1_0x2 = 0;
  }
  return;
}


S127 * __thiscall S127__S127(S127 *this)

{
  S127(this);
  return this;
}


byte __thiscall S127__S127_FUN_0044a2c0(S127 *this,Car *pCar,Player *pPlayer)

{
  byte bVar1;
  bool bVar2;
  char cVar3;
  byte bVar5;
  byte bVar6;
  CarSystemManager *pCVar4;
  
  bVar6 = gCarSystemManager->field46_0x68;
  bVar5 = 1;
  pCVar4 = gCarSystemManager;
  if ((bool)bVar6 != false) {
    Decoder_ShiftLeft(&stack0xfffffff4,(void *)0x0);
    bVar1 = Player::Player_GetID(pPlayer);
    bVar2 = Game::Game_FUN_0045bba0(gGame,(Sprite *)pCar->CarSprite,bVar1,bVar6)
    ;
    pCVar4 = (CarSystemManager *)(uint)bVar2;
    if (!bVar2) {
      bVar5 = 0;
    }
  }
  cVar3 = (char)pCVar4;
  Car::Car_FUN_0041fa60(pCar);
  if (cVar3 != '\0') {
    return 0;
  }
  return bVar5;
}


