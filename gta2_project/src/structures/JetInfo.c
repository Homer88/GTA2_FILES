// Module: S353
// Functions working with structure S353
// Generated from gta2.exe.c

#include "common.h"

S353 * __thiscall S353__S353(S353 *this,int param_1)

{
  this->field0_0x0 = *(undefined2 *)(param_1 + 2);
  this->field1_0x2 = *(undefined2 *)(param_1 + 4);
  this->field2_0x4 = *(undefined2 *)(param_1 + 6);
  this->field3_0x6 = *(undefined2 *)(param_1 + 8);
  this->field4_0x8 = *(undefined2 *)(param_1 + 10);
  this->field5_0xa = *(undefined2 *)(param_1 + 0xc);
  this->field6_0xc = *(undefined2 *)(param_1 + 0xe);
  if (*(int **)(param_1 + 0x10) != (int *)0x0) {
    this->field8_0x10 = (float)**(int **)(param_1 + 0x10) * 1.5258789e-05;
    this->field9_0x14 =
         (float)*(int *)(*(int *)(param_1 + 0x10) + 4) * 1.5258789e-05;
    this->field10_0x18 =
         (float)*(int *)(*(int *)(param_1 + 0x10) + 8) * 1.5258789e-05;
    this->field11_0x1c =
         (float)*(int *)(*(int *)(param_1 + 0x10) + 0xc) * 1.5258789e-05;
    this->field12_0x20 =
         (float)*(int *)(*(int *)(param_1 + 0x10) + 0x10) * 1.5258789e-05;
    this->field13_0x24 =
         (float)*(int *)(*(int *)(param_1 + 0x10) + 0x14) * 1.5258789e-05;
    this->field7_0xe = *(undefined2 *)(param_1 + 0x14);
    this->field14_0x28 = *(undefined4 *)(param_1 + 0x1c);
    return this;
  }
  this->field13_0x24 = 0.0;
  this->field12_0x20 = 0.0;
  this->field11_0x1c = 0.0;
  this->field10_0x18 = 0.0;
  this->field9_0x14 = 0.0;
  this->field8_0x10 = 0.0;
  this->field7_0xe = *(undefined2 *)(param_1 + 0x14);
  this->field14_0x28 = *(undefined4 *)(param_1 + 0x1c);
  return this;
}


