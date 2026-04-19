// Module: S77
// Functions working with structure S77
// Generated from gta2.exe.c

#include "../../include/common.h"

S77 * __thiscall S77__S77(S77 *this)

{
  int iVar1;
  S373 *pSVar2;
  
  iVar1 = 43;
  pSVar2 = this->ARR;
  do {
    *(undefined1 **)pSVar2 = &pSVar2->field_0x4;
    pSVar2 = pSVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  this->field0_0x0 = &this->field1_0x4;
  this->field11_0x2c0 = 0;
  return this;
}


