// Module: S85
// Functions working with structure S85
// Generated from gta2.exe.c

#include "common.h"

void * __thiscall S85__S85_FUN_00433120(S85 *this)

{
  void *pvVar1;
  
  pvVar1 = this->field0_0x0;
  this->field0_0x0 = *(void **)((int)pvVar1 + 4);
  return pvVar1;
}


S85 * __thiscall S85__S85(S85 *this)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 99;
  piVar2 = (int *)this->field2_0x8;
  do {
    *piVar2 = (int)(piVar2 + 1);
    piVar2 = piVar2 + 2;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  this->field0_0x0 = &this->field1_0x4;
  this->field3_0x320 = 0;
  return this;
}


