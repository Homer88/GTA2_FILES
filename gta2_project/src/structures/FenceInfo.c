// Module: S151
// Functions working with structure S151
// Generated from gta2.exe.c

#include "common.h"

void __thiscall S151__FUN_004a8600(S151 *this)

{
  int iVar1;
  
  iVar1 = 10;
  do {
    CopyWideString(this->ALAN,&IDS_005733d8);
    this->field1_0x14 = 0;
    this = (S151 *)this->BRIAN;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}


bool __thiscall S151__FUN_004a8630(S151 *this,wchar_t *param_1,uint param_2)

{
  int iVar1;
  ushort uVar2;
  ushort uVar3;
  int *piVar4;
  uint uVar5;
  
  uVar2 = 10;
  uVar3 = 9;
  while( true ) {
    if (*(uint *)(this->BRIAN + (short)uVar3 * 12 + -2) < param_2) {
      uVar2 = uVar3;
    }
    if ((param_2 == *(uint *)(this->BRIAN + (short)uVar3 * 12 + -2)) &&
       (iVar1 = _wcscmp(param_1,this->ALAN + (short)uVar3 * 0xc), iVar1 == 0))
    break;
    uVar3 = uVar3 - 1;
    if (uVar3 == 0xffff) {
      if (uVar2 == 10) {
        return false;
      }
      if (uVar2 < 9) {
        piVar4 = &this->field17_0xd4;
        uVar5 = (uint)(ushort)(9 - uVar2);
        do {
          _wcsncpy((wchar_t *)(piVar4 + 1),(wchar_t *)(piVar4 + -5),9);
          piVar4[6] = *piVar4;
          piVar4 = piVar4 + -6;
          uVar5 = uVar5 - 1;
        } while (uVar5 != 0);
      }
      _wcsncpy(this->ALAN + (uint)uVar2 * 0xc,param_1,9);
      *(uint *)(this->ALAN + (uint)uVar2 * 0xc + 10) = param_2;
      return true;
    }
  }
  return false;
}


S151 * __thiscall S151__S151(S151 *this)

{
  FUN_004a8600(this);
  return this;
}


