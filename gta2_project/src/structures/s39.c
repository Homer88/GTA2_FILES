// Module: S39
// Functions working with structure S39
// Generated from gta2.exe.c

#include "../../include/common.h"

void __thiscall S39__S39(S39 *this)

{
  this->field7_0xc = 0;
  this->field6_0x8 = 0;
  this->index = -1;
  this->count = 0;
  return;
}


void __thiscall S39__FUN_0044af70(S39 *this)

{
  this->index = -1;
  return;
}


void __thiscall S39__FUN_0044afb0(S39 *param_1,ushort *param_2)

{
  int iVar1;
  
  iVar1 = 0x30;
  do {
    if ((int)param_1->index == (uint)*param_2) {
      S39::FUN_0044af70(param_1);
    }
    param_1 = param_1 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}


void __thiscall S39__FUN_0044afe0(S39 *this)

{
  int iVar1;
  
  iVar1 = 48;
  do {
    FUN_0044af70(this);
    this = this + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}


