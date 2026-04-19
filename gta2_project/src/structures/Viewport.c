// Module: S34
// Functions working with structure S34
// Generated from gta2.exe.c

#include "../../include/common.h"

void __thiscall S34__S34(S34 *this)

{
  this->NextElement = (S34 *)0x0;
  this->Data1 = 125;
  this->Data2 = 205;
  return;
}


void __thiscall S34__S34_FUN_00474f90(S34 *this)

{
  this->Data1 = 0;
  this->Data2 = 0;
  this->NextElement = (S34 *)0x0;
  return;
}


S34 * __thiscall S34__S33_FUN_00476780(S33 *this,S34 *pS34)

{
  pS34->NextElement = this->Next_S34;
  this->Next_S34 = pS34;
  return pS34;
}


S34 * __thiscall S34__FUN_00476e00(void *this,S34 *pS34)

{
  S34 *pSVar1;
  
  pSVar1 = S33::S33_FUN_00476780(_gS33,pS34);
  return pSVar1;
}


