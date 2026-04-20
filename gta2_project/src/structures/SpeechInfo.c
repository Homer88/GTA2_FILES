// Module: S140
// Functions working with structure S140
// Generated from gta2.exe.c

#include "common.h"

S140 * __thiscall S140__S140(S140 *this)

{
  int iVar1;
  char *pcVar2;
  
  *(undefined1 *)&this->field0_0x0 = 0;
  this->field1_0x2 = 0;
  this->field2_0x4 = 0;
  this->field3_0x6 = 0;
  pcVar2 = this->str;
  for (iVar1 = 0x19; iVar1 != 0; iVar1 = iVar1 + -1) {
    pcVar2[0] = '\0';
    pcVar2[1] = '\0';
    pcVar2[2] = '\0';
    pcVar2[3] = '\0';
    pcVar2 = pcVar2 + 4;
  }
  return this;
}


