// Module: S71
// Functions working with structure S71
// Generated from gta2.exe.c

#include "common.h"

void __thiscall S71__S71_FUN_004c3240(S71 *this)

{
  this->field8_0x12 = *_gTileAnim;
  *_gTileAnim = *_gTileAnim + 1;
  return;
}


void * __thiscall S71__S71_FUN_004c3260(S71 *this)

{
  int iVar1;
  undefined2 uVar3;
  void *pvVar2;
  undefined4 in_EDX;
  
  iVar1 = this->field6_0xc;
  uVar3 = (undefined2)((uint)iVar1 >> 0x10);
  if (iVar1 != 0) {
    pvVar2 = (void *)CONCAT22(uVar3,*(undefined2 *)
                                     (iVar1 + 6 + (uint)this->count1 * 2));
    Style::S15_FUN_004bf770(gStyle,this->field7_0x10,(uint)pvVar2);
    return pvVar2;
  }
  pvVar2 = (void *)CONCAT22(uVar3,this->field7_0x10);
  Style::S15_FUN_004bf770
            (gStyle,this->field7_0x10,
             CONCAT22((short)((uint)in_EDX >> 0x10),this->count1));
  return pvVar2;
}


void __fastcall S71__FUN_004c32e0(S71 *param_1)

{
  param_1->count = param_1->field2_0x4;
  param_1->count1 = param_1->field0_0x0;
  S71::S71_FUN_004c3260(param_1);
  return;
}


byte __thiscall S71__S71_FUN_004c3300(S71 *this)

{
  ushort uVar1;
  short sVar2;
  bool bVar3;
  
  this->count = this->count + -1;
  if (this->count == 0) {
    uVar1 = this->field1_0x2;
    if (uVar1 < this->field0_0x0) {
      this->count1 = this->count1 - 1;
      bVar3 = this->count1 < uVar1;
    }
    else {
      this->count1 = this->count1 + 1;
      bVar3 = uVar1 < this->count1;
    }
    if (bVar3) {
      if ((this->field3_0x6 != 0) &&
         (sVar2 = this->field3_0x6 + -1, this->field3_0x6 = sVar2, sVar2 == 0))
      {
        return 1;
      }
      this->count1 = this->field0_0x0;
    }
    S71_FUN_004c3260(this);
    this->count = this->field2_0x4;
  }
  return 0;
}


void __thiscall S71__S71(S71 *this)

{
  this->field0_0x0 = 0;
  this->field1_0x2 = 0;
  this->field2_0x4 = 0;
  this->field3_0x6 = 0;
  this->count1 = 0;
  this->count = 0;
  this->field6_0xc = 0;
  this->field7_0x10 = 0;
  this->field8_0x12 = 0;
  this->S71 = (S71 *)0x0;
  return;
}


void __thiscall S71__S71(S71 *this)

{
  this->field6_0xc = 0;
  this->S71 = (S71 *)0x0;
  return;
}


