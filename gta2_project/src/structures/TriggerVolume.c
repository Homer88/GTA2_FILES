// Module: S64
// Functions working with structure S64
// Generated from gta2.exe.c

#include "common.h"

S64 * __thiscall S64__S64(S64 *this)

{
  S65 *pSVar1;
  S65 *pSVar2;
  int iVar3;
  
  pSVar1 = this->S65;
  _eh_vector_constructor_iterator_(pSVar1,8,1101,S65::S65,S65::~S65);
  iVar3 = 1100;
  pSVar2 = pSVar1;
  do {
    iVar3 = iVar3 + -1;
    pSVar2->s65 = pSVar2 + 1;
    pSVar2 = pSVar2 + 1;
  } while (iVar3 != 0);
  this->Begin_ARR_S65 = pSVar1;
  this->S65[1100].s65 = (S65 *)0x0;
  return this;
}


S65 * __thiscall S64__S64_FUN_00483fa0(S64 *this)

{
  S65 *this_00;
  
  this_00 = this->Begin_ARR_S65;
  this->Begin_ARR_S65 = this_00->s65;
  S65::S65_FUN_00482ad0(this_00);
  return this_00;
}


void __thiscall S64__S64_FUN_00483fc0(S64 *this,undefined4 *param_1)

{
  FUN_00482af0();
  *param_1 = this->Begin_ARR_S65;
  this->Begin_ARR_S65 = (S65 *)param_1;
  return;
}


