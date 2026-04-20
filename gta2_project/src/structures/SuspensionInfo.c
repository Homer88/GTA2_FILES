// Module: S125
// Functions working with structure S125
// Generated from gta2.exe.c

#include "common.h"

void __thiscall S125__FUN_004b8dc0(S125 *this,int param_1)

{
  S125 *pSVar1;
  
  if (param_1 != 0) {
    pSVar1 = (S125 *)(this->Arr + param_1);
    do {
      pSVar1->field0_0x0 = 0;
      pSVar1 = (S125 *)((int)(pSVar1 + 0xffffffff) + 0x4c);
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}


byte __thiscall S125__S125_FUN_004b8f70(S125 *this)

{
  if (this->field8_0x38 < 0) {
    this->count = this->count + 1;
    this->count1 = this->count1 + 1;
    if (this->field6_0x36 < 3) {
      this->field6_0x36 = 0;
      S123::S123_FUN_004b8d80(_gS123);
      return 1;
    }
    this->field6_0x36 = this->field6_0x36 - 2;
  }
  this->field8_0x38 = this->field8_0x38 + -1;
  return 0;
}


void __thiscall S125__FUN_004b9000(S124 *this,S125 *pS125)

{
  S125 *pSVar1;
  S125 *pSVar2;
  S125 *pSVar3;
  
  pSVar3 = (S125 *)0x0;
  pSVar1 = this->s125;
  if (this->s125 != (S125 *)0x0) {
    while (pSVar2 = pSVar1, pSVar2 != pS125) {
      pSVar1 = pSVar2->s125;
      pSVar3 = pSVar2;
      if (pSVar2->s125 == (S125 *)0x0) {
        return;
      }
    }
    if (pSVar3 != (S125 *)0x0) {
      pSVar3->s125 = pSVar2->s125;
      pSVar2->s125 = this->Begin;
      this->Begin = pSVar2;
      return;
    }
    this->s125 = pSVar2->s125;
    pSVar2->s125 = this->Begin;
    this->Begin = pSVar2;
  }
  return;
}


S125 * __thiscall S125__S125(S125 *this)

{
  int iVar1;
  int *piVar2;
  
  this->field0_0x0 = 0;
  piVar2 = this->Arr;
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar2 = 0;
    piVar2 = piVar2 + 1;
  }
  this->field6_0x36 = 0;
  this->field8_0x38 = 0;
  this->count = 0;
  this->count1 = 0;
  this->MultiPlayer = 0;
  this->field12_0x48 = 0;
  this->s125 = (S125 *)0x0;
  this->ArrElement = 9;
  return this;
}


