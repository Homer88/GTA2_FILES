// Module: S68
// Functions working with structure S68
// Generated from gta2.exe.c

#include "../../include/common.h"

int __thiscall S68__S68GetPedID(S68 *this,byte param_1)

{
  return *(int *)(this->Arr255 + (uint)param_1 * 8 + -8);
}


void __thiscall S68__S68_FUN_00434070(S68 *this,byte param_1)

{
  uint8_t *puVar1;
  
  puVar1 = this->Arr255 + (uint)param_1 * 8 + -8;
  puVar1[0] = '\0';
  puVar1[1] = '\0';
  puVar1[2] = '\0';
  puVar1[3] = '\0';
  puVar1[4] = '\0';
  return;
}


byte __thiscall S68__S68_FUN_004b98d0(S68 *this,undefined4 param_1)

{
  byte bVar1;
  uint8_t *puVar2;
  uint local_4;
  
  bVar1 = 1;
  puVar2 = this->Arr255;
  while ((*(int *)puVar2 != 0 || (puVar2[4] != '\0'))) {
    puVar2 = puVar2 + 8;
    bVar1 = bVar1 + 1;
    if (bVar1 == 0xff) {
      return 0;
    }
  }
  local_4 = (uint)bVar1;
  *(undefined4 *)(this->Arr255 + local_4 * 8 + -8) = param_1;
  return bVar1;
}


void __thiscall S68__S68_FUN_004b9920(S68 *this,byte param_1)

{
  this->Arr255[(uint)param_1 * 8 + -4] =
       this->Arr255[(uint)param_1 * 8 + -4] + '\x01';
  return;
}


void __thiscall S68__S68_FUN_004b9940(S68 *this,byte param_1)

{
  uint8_t uVar1;
  
  uVar1 = this->Arr255[(uint)param_1 * 8 + -4];
  if (uVar1 != '\0') {
    this->Arr255[(uint)param_1 * 8 + -4] = uVar1 + 0xff;
  }
  return;
}


void __thiscall S68__S68(S68 *this)

{
  int iVar1;
  
  iVar1 = 255;
  do {
    this->next = 0;
    this->flags = '\0';
    this = (S68 *)this->Arr255;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}


