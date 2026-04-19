// Module: S33
// Functions working with structure S33
// Generated from gta2.exe.c

#include "../../include/common.h"

S33 * __thiscall S33__S33(S33 *this)

{
  S34 *ppSVar1;
  int iVar1;
  
  _eh_vector_constructor_iterator_(this->First,12,50,S34::S34,S34::~34);
  ppSVar1 = (S34 *)&this->First[0].NextElement;
  iVar1 = 0x31;
  do {
    ppSVar1->Data1 = &ppSVar1->Data2;
    ppSVar1 = ppSVar1 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  this->First[49].NextElement = (S34 *)0x0;
  this->Next_S34 = this->First;
  return this;
}


byte __thiscall S33__S33_FUN_00476760(S33 *this)

{
  S34 *this_00;
  byte extraout_CL;
  
  this_00 = this->Next_S34;
  this->Next_S34 = this_00->NextElement;
  S34::S34_FUN_00474f90(this_00);
  return extraout_CL;
}


S34 * __thiscall S33__S33_FUN_00476780(S33 *this,S34 *pS34)

{
  pS34->NextElement = this->Next_S34;
  this->Next_S34 = pS34;
  return pS34;
}


