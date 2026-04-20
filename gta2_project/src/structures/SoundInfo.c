// Module: S28
// Functions working with structure S28
// Generated from gta2.exe.c

#include "common.h"

S28 * __thiscall S28__S28(S28 *this)

{
  S29 *pS29;
  int Index;
  S30 *ppSVar1;
  
  this->NextElement = (S28 *)0x0;
  pS29 = (S29 *)operator_new(8);
  if (pS29 == (S29 *)0x0) {
    pS29 = (S29 *)0x0;
  }
  else {
    pS29 = S29::S29(pS29);
  }
  this->S29 = pS29;
  this->field1_0x4 = 0;
  this->field_0x6 = 0;
  this->field4_0x8 = 0;
  this->field_0xc = 0;
  this->field7_0xe = 0;
  this->field_0x10 = 0;
  this->field10_0x12 = 0;
  this->field18_0x11a = 0;
  ppSVar1 = this->S30;
  for (Index = 63; Index != 0; Index = Index + -1) {
    *ppSVar1 = (S30)0x0;
    ppSVar1 = ppSVar1 + 1;
  }
  ppSVar1->field0_0x0 = 0;
  ppSVar1->field_0x2 = 0;
  this->field16_0x118 = 0;
  return this;
}


