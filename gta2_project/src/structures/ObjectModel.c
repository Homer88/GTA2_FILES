// Module: S24
// Functions working with structure S24
// Generated from gta2.exe.c

#include "../../include/common.h"

S24 * __thiscall S24__S24(S24 *this)

{
  int Index;
  S24 *pS24;
  
  this->next = 0;
  this->Test = 0;
  pS24 = this;
  for (Index = 30; Index != 0; Index = Index + -1) {
    pS24->Data[0] = 0;
    pS24 = (S24 *)(pS24->Data + 1);
  }
  return this;
}


