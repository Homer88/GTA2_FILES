// Module: S352
// Functions working with structure S352
// Generated from gta2.exe.c

#include "../../include/common.h"

S352 * __thiscall S352__S352(S352 *this,int param_1,int param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  ushort *puVar3;
  S352 *pS352;
  S352 *pS352_1;
  void *pvVar4;
  S353 *pS353;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004e3996;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this->field9_0x24 = 0;
  this->field32_0x80 = param_1;
  this->field0_0x0 = *(undefined4 *)(param_2 + 0x44);
  this->field1_0x4 = *(undefined4 *)(param_2 + 0x48);
  this->field2_0x8 = *(undefined4 *)(param_2 + 0x4c);
  this->field3_0xc = *(undefined4 *)(param_2 + 0x54);
  this->field4_0x10 = *(undefined4 *)(param_2 + 0x50);
  this->field5_0x14 = *(undefined4 *)(param_2 + 0x58);
  this->field6_0x18 = *(undefined4 *)(param_2 + 0x5c);
  this->field7_0x1c = *(undefined4 *)(param_2 + 0x60);
  this->field8_0x20 = *(undefined4 *)(param_2 + 100);
  this->field27_0x6c = *(undefined4 *)(param_2 + 4);
  this->field28_0x70 = *(undefined4 *)(param_2 + 8);
  uVar2 = *(undefined4 *)(param_2 + 0xc);
  this->field11_0x2c = 0;
  this->field29_0x74 = uVar2;
  this->field10_0x28 = 0x3f800000;
  this->field12_0x30 = 0;
  this->field13_0x34 = 0;
  this->field14_0x38 = 0;
  this->field15_0x3c = 0x3f800000;
  this->field16_0x40 = 0;
  this->field17_0x44 = 0;
  this->field18_0x48 = 0;
  this->field19_0x4c = 0;
  this->field20_0x50 = 0x3f800000;
  this->field21_0x54 = 0;
  if (*(int *)(param_2 + 0x14) == 0) {
    this->field30_0x78 = (undefined4 *)0x0;
  }
  else {
    pS352 = (S352 *)operator_new(0x84);
    local_4 = 0;
    if (pS352 == (S352 *)0x0) {
      this->field30_0x78 = (undefined4 *)0x0;
    }
    else {
      pS352_1 = S352(pS352,param_1,*(int *)(param_2 + 0x14));
      this->field30_0x78 = &pS352_1->field0_0x0;
    }
  }
  local_4 = 0xffffffff;
  if (*(int *)(param_2 + 0x1c) == 0) {
    this->field31_0x7c = (undefined4 *)0x0;
  }
  else {
    pS352_1 = (S352 *)operator_new(0x84);
    local_4 = 1;
    if (pS352_1 == (S352 *)0x0) {
      this->field31_0x7c = (undefined4 *)0x0;
    }
    else {
      pS352_1 = S352(pS352_1,param_1,*(int *)(param_2 + 0x1c));
      this->field31_0x7c = &pS352_1->field0_0x0;
    }
  }
  local_4 = 0xffffffff;
  if (*(int *)(param_2 + 0x24) == 0) {
    this->field22_0x58 = 0;
    this->field23_0x5c = 0;
    this->field24_0x60 = 0;
  }
  else {
    puVar3 = *(ushort **)(*(int *)(param_2 + 0x24) + 0xc);
    uVar1 = *puVar3;
    this->field22_0x58 = (uint)uVar1;
    this->field23_0x5c = (uint)puVar3[1];
    this->field24_0x60 = (uint)puVar3[2];
    pvVar4 = _malloc((uint)uVar1 << 2);
    this->field25_0x64 = pvVar4;
    param_1 = *(int *)(puVar3 + 4);
    iVar7 = 0;
    if (0 < (int)this->field22_0x58) {
      do {
        pS353 = (S353 *)operator_new(0x2c);
        if (pS353 == (S353 *)0x0) {
          pS353 = (S353 *)0x0;
        }
        else {
          pS353 = S353::S353(pS353,param_1);
        }
        param_1 = param_1 + 0x20;
        *(S353 **)((int)this->field25_0x64 + iVar7 * 4) = pS353;
        iVar7 = iVar7 + 1;
      } while (iVar7 < (int)this->field22_0x58);
    }
    puVar5 = (undefined4 *)_malloc(this->field23_0x5c * 0xc);
    this->field26_0x68 = puVar5;
    puVar8 = *(undefined4 **)(puVar3 + 6);
    for (uVar6 = this->field23_0x5c * 3 & 0x3fffffff; uVar6 != 0;
        uVar6 = uVar6 - 1) {
      *puVar5 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar5 = puVar5 + 1;
    }
    for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
      *(undefined1 *)puVar5 = *(undefined1 *)puVar8;
      puVar8 = (undefined4 *)((int)puVar8 + 1);
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
  }
  ExceptionList = local_c;
  return this;
}


