// Module: S29
// Functions working with structure S29
// Generated from gta2.exe.c

#include "../../include/common.h"

S29 * __thiscall S29__S29(S29 *this)

{
  this->S34 = (S34 *)0x0;
  this->Index = 0;
  return this;
}


void __thiscall S29__S29_FUN_00476dc0(S29 *this)

{
  S34 *pS34;
  
  pS34 = this->S34;
  while (pS34 != (S34 *)0x0) {
    pS34 = this->S34;
    this->S34 = pS34->NextElement;
    S33::S33_FUN_00476780(_gS33,pS34);
    this->Index = this->Index - 1;
    pS34 = this->S34;
  }
  return;
}


