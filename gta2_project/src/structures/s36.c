// Module: S36
// Functions working with structure S36
// Generated from gta2.exe.c

#include "../../include/common.h"

byte * __thiscall S36__S36_FUN_004c3680(S36 *this)

{
  DWORD DVar1;
  byte *pbVar2;
  
  DVar1 = timeGetTime();
  pbVar2 = (byte *)(DVar1 - this->field1_0x4);
  this->field2_0x8 = pbVar2 + this->field2_0x8;
  return pbVar2;
}


void __thiscall S36__S36(S36 *this)

{
  this->field0_0x0 = 0;
  this->field2_0x8 = 0;
  this->field1_0x4 = 0;
  return;
}


