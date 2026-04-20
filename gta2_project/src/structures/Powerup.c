// Module: S55
// Functions working with structure S55
// Generated from gta2.exe.c

#include "common.h"

S55 * __thiscall S55__S55(S55 *this)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 5999;
  piVar2 = this->ARR_5999;
  do {
    *piVar2 = (int)(piVar2 + 1);
    piVar2 = piVar2 + 3;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  this->field0_0x0 = (int)&this->field1_0x4;
  this->Index = 0;
  return this;
}


void __thiscall S55__S55_FUN_00447370(S55 *this)

{
  this->field0_0x0 = *(int *)(this->field0_0x0 + 8);
  return;
}


void __thiscall S55__S55_FUN_00447380(S55 *this,void *param_1)

{
  *(int *)((int)param_1 + 8) = this->field0_0x0;
  this->field0_0x0 = (int)param_1;
  return;
}


