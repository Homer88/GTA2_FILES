// Module: S128
// Functions working with structure S128
// Generated from gta2.exe.c

#include "common.h"

S128 * __thiscall S128__S128(S128 *this)

{
  this->field0_0x0 = 0;
  this->field1_0x4 = 0;
  this->field2_0x8 = DAT_005e7ae0;
  this->field3_0xc = DAT_005e7ae0;
  this->field4_0x10 = DAT_005e7ae0;
  return this;
}


void __thiscall S128__S128_FUN_0044a060(S128 *this,int pEventType,int pId)

{
  Ped *this_00;
  undefined4 *puVar1;
  
  this->field0_0x0 = pEventType;
  this->field1_0x4 = pId;
  if (pId == 0) {
    this->field2_0x8 = DAT_005e7ae0;
    this->field3_0xc = DAT_005e7ae0;
    this->field4_0x10 = DAT_005e7ae0;
    return;
  }
  this_00 = Char::FindPed(gChar,pId);
  puVar1 = (undefined4 *)Ped__GetXCoordinate(this_00,(int)&pEventType);
  this->field2_0x8 = *puVar1;
  puVar1 = (undefined4 *)Ped__GetYCoordinate(this_00,(int)&pEventType);
  this->field3_0xc = *puVar1;
  puVar1 = (undefined4 *)Ped::GetPositionZ(this_00,(int)&pEventType);
  this->field4_0x10 = *puVar1;
  return;
}


