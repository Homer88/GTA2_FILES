// Module: S89
// Functions working with structure S89
// Generated from gta2.exe.c

#include "common.h"

void __thiscall S89__S89_FUN_004c2780(S89 *this)

{
  ushort id;
  short sVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  
  if ((this->_byte != '\0') && (uVar4 = 0, this->count != 0)) {
    do {
      puVar2 = (undefined4 *)Style::GetSprite(gStyle,(short)uVar4);
      id = Style::S15_FUN_004bf430(gStyle,2,(short)uVar4);
      sVar1 = Style::GetPhysPalette(gStyle,id);
      iVar3 = (*(code *)gbh_RegisterTexture)
                        (*(undefined1 *)(puVar2 + 1),
                         *(undefined1 *)((int)puVar2 + 5),*puVar2,sVar1,0);
      this->S89_2->C1[uVar4] = iVar3;
      uVar4 = uVar4 + 1;
    } while (uVar4 < this->count);
  }
  return;
}


void __thiscall S89__S89_FUN_004c27f0(S89 *this)

{
  short sVar1;
  ushort id;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  if (this->_byte != '\0') {
    uVar2 = (uint)((ulonglong)this->count /
                  (ulonglong)(longlong)(int)(uint)this->param_2);
    uVar5 = 0;
    if (uVar2 != 0) {
      do {
        sVar1 = Style::GetBaseIndex(gStyle,this->field3_0x8,(short)uVar5);
        puVar3 = (undefined4 *)Style::GetSprite(gStyle,sVar1);
        uVar6 = 0;
        _DAT_00671974 = _DAT_00671974 + 1;
        if (this->param_2 != 0) {
          do {
            id = Style::S15_FUN_004bf430(gStyle,this->field4_0xc,(short)uVar6);
            sVar1 = Style::GetPhysPalette(gStyle,id);
            iVar4 = (*(code *)gbh_RegisterTexture)
                              (*(undefined1 *)(puVar3 + 1),
                               *(undefined1 *)((int)puVar3 + 5),*puVar3,sVar1,1)
            ;
            this->S89_2->C1[this->param_2 * uVar5 + uVar6] = iVar4;
            _DAT_00671970 = _DAT_00671970 + 1;
            uVar6 = uVar6 + 1;
          } while (uVar6 < this->param_2);
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < uVar2);
    }
  }
  return;
}


void __thiscall S89__FUN_004c28d0(S89 *this)

{
  ushort uVar1;
  
  if ((this->_byte != '\0') && (this->S89_2 != (S89_2 *)0x0)) {
    uVar1 = 0;
    if (this->count != 0) {
      do {
        (*gbh_FreeTexture)((void *)this->S89_2->C1[uVar1]);
        uVar1 = uVar1 + 1;
      } while (uVar1 < this->count);
    }
    _free(this->S89_2);
    this->S89_2 = (S89_2 *)0x0;
  }
  return;
}


int __thiscall S89__FUN_004c2920(S89 *this,int param_1,short param_2)

{
  ushort uVar1;
  
  uVar1 = Style::GetBaseIndex(gStyle,param_1,param_2);
  return this->S89_2->C1[uVar1];
}


int __thiscall S89__FUN_004c2950(S89 *this,short param_1,int param_2)

{
  return this->S89_2->C1
         [(uint)(ushort)(this->param_2 * param_1) + param_2 & 0xffff];
}


S89 * __thiscall S89__S89(S89 *this)

{
  this->S89_2 = (S89_2 *)0x0;
  this->count = 0;
  this->param_2 = 0;
  this->field3_0x8 = 0;
  this->field4_0xc = 0;
  this->_byte = 0;
  return this;
}


void __thiscall S89__FUN_004c2f30(S89 *this,int param_1,int param_2)

{
  short sVar1;
  short sVar2;
  int iVar3;
  
  iVar3 = param_1;
  sVar1 = Style::S15_FUN_004bf3a0(gStyle,param_2);
  sVar2 = Style::S15_FUN_004bf330(gStyle,param_1);
  S89_FUN_004c2710(this,sVar2,sVar1,iVar3,param_2);
  return;
}


