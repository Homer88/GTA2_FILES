// Module: S109
// Functions working with structure S109
// Generated from gta2.exe.c

#include "common.h"

S109 * __thiscall S109__S109(S109 *this)

{
  void *local_c;
  code *pcStack_8;
  int local_4;
  
  local_4 = -1;
  pcStack_8 = FUN_004e3ca3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  _eh_vector_constructor_iterator_(this,0x30,10,S110::S110,S110::~S110);
  local_4 = 0;
  FUN_004c5420(this);
  ExceptionList = local_c;
  return this;
}


void * __thiscall S109__S109_FUN_004c5430(S109 *this)

{
  byte bVar1;
  uint index;
  
  bVar1 = 0;
  index = 0;
  do {
    if (this->Arr_S110_10[index].field18_0x1e == 0) {
      return this->Arr_S110_10 + index;
    }
    bVar1 = bVar1 + 1;
    index = (uint)bVar1;
  } while (bVar1 < 10);
  return (void *)0x0;
}


void __thiscall S109__S109_FUN_004c5db0(S109 *this)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  
  pbVar2 = &this->Arr_S110_10[0].field18_0x1e;
  iVar3 = 10;
  do {
    if (*pbVar2 != 0) {
      bVar1 = FUN_004c5ca0((S110 *)(pbVar2 + -0x1e));
      if (bVar1 != 0) {
        *pbVar2 = 0;
      }
    }
    pbVar2 = pbVar2 + 0x30;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}


