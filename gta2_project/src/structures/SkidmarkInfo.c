// Module: S107
// Functions working with structure S107
// Generated from gta2.exe.c

#include "../../include/common.h"

void __thiscall S107__S107_FUN_0045e000(S107 *this)

{
  int iVar1;
  char cVar2;
  ushort *puVar3;
  int *piVar4;
  byte bVar5;
  uint local_4;
  
  iVar1 = this->Index;
  cVar2 = (char)(iVar1 / 3);
  this->field_0x14a8 = cVar2;
  if (cVar2 == '\0') {
    this->field_0x14a8 = (char)this->Index;
  }
  if ((4 < iVar1) && (bVar5 = 0, 0 < iVar1)) {
    puVar3 = &this->ARR_S108_0X78[0].field6_0x14;
    do {
      puVar3[-1] = puVar3[-1] >> 2;
      *puVar3 = *puVar3 >> 2;
      puVar3 = puVar3 + 0x16;
      bVar5 = bVar5 + 1;
      local_4 = (uint)bVar5;
    } while ((int)local_4 < this->Index);
  }
  if ((_gNetworkGame != 0) && (bVar5 = 0, 0 < this->Index)) {
    piVar4 = &this->ARR_S108_0X78[0].Cycle;
    do {
      *piVar4 = 1;
      piVar4 = piVar4 + 0xb;
      bVar5 = bVar5 + 1;
      local_4 = (uint)bVar5;
    } while ((int)local_4 < this->Index);
  }
  return;
}


void __thiscall S107__S107_FUN_0045e2e0(S107 *this)

{
  byte bVar1;
  uint pCycle;
  int iVar2;
  int iVar3;
  S108 *this_00;
  
  bVar1 = this->field_0x14a8;
  pCycle = General::GetCycle(gGeneral);
  iVar2 = (pCycle & 3) * (uint)bVar1;
  iVar3 = (uint)bVar1 + iVar2;
  if (this->Index < iVar3) {
    iVar3 = this->Index;
  }
  this_00 = this->ARR_S108_0X78 + iVar2;
  if (iVar2 < iVar3) {
    iVar3 = iVar3 - iVar2;
    do {
      FUN_0045e240(this_00);
      this_00 = this_00 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}


S107 * __thiscall S107__S107(S107 *this)

{
  Constructor(this,0x2c,0x78,S108::S108);
  this->Index = 0;
  this->field2_0x14a4 = 0;
  this->field_0x14a8 = 0;
  return this;
}


