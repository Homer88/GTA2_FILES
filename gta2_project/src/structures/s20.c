// Module: S20
// Functions working with structure S20
// Generated from gta2.exe.c

#include "../../include/common.h"

S20_01 * __thiscall S20__S20_FUN_004c4b40(S20 *this)

{
  uint uVar1;
  
  uVar1 = this->field1_0x2ee0;
  if (999 < uVar1) {
    return (S20_01 *)0x0;
  }
  this->field1_0x2ee0 = uVar1 + 1;
  return this->arr + uVar1;
}


void __thiscall S20__S20_FUN_004c4b70(S20 *this)

{
  this->field1_0x2ee0 = 0;
  return;
}


S20 * __thiscall S20__S20(S20 *this)

{
  S20 *pS20;
  int count;
  
  count = 1000;
  pS20 = this;
  do {
    pS20->arr[0].Data = 0;
    pS20 = (S20 *)(pS20->arr + 1);
    count = count + -1;
  } while (count != 0);
  S20_FUN_004c4b70(this);
  return this;
}


