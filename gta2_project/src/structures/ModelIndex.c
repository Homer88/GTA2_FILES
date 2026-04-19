// Module: S93
// Functions working with structure S93
// Generated from gta2.exe.c

#include "../../include/common.h"

S93 * __thiscall S93__S93(S93 *this)

{
  int iVar1;
  undefined4 *puVar2;
  
  _eh_vector_constructor_iterator_(this,0x96,50,S94::S94,S200::~S200);
  puVar2 = this->ARR_0XC;
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined2 *)puVar2 = 0;
  return this;
}


