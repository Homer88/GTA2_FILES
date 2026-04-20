// Module: S6
// Functions working with structure S6
// Generated from gta2.exe.c

#include "common.h"

S6 * __thiscall S6__Car_FUN_00421ec0(Car *this,S6 *param_1)

{
  if (this->Player == (Player *)0x0) {
    Decoder_ShiftLeft(param_1,(void *)0x0);
    return param_1;
  }
  Player::FUN_004211c0(this->Player,param_1);
  return param_1;
}


S6 * __thiscall S6__FUN_00436160(Ped *this,S6 *param_2)

{
  if (this->GameObject != (GameObject *)0x0) {
    FUN_0041b080(this->GameObject,&param_2->S46);
    return param_2;
  }
  if (this->CarCurrent != (Car *)0x0) {
    Car::Car_FUN_00421ec0(this->CarCurrent,param_2);
    return param_2;
  }
  param_2->S46 = DAT_005e5cfc;
  return param_2;
}


