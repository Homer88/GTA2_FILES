// Module: S101
// Functions working with structure S101
// Generated from gta2.exe.c

#include "../../include/common.h"

S101 * __thiscall S101__S101(S101 *this)

{
  CarSystemManager::SetIndexDefautCarManager
            ((CarSystemManager *)&this->CarSystemManager);
  CarSystemManager::SetIndexDefautCarManager
            ((CarSystemManager *)&this->CarSystemManager_1);
  CarSystemManager::SetIndexDefautCarManager
            ((CarSystemManager *)&this->CarSystemManager_2);
  this->Ids = 0;
  this->field6_0x10 = 0;
  this->field7_0x14 = 0;
  this->field8_0x18 = 0;
  this->field9_0x1a = 0;
  this->field4_0x8 = _DAT_00669f7c;
  this->CarSystemManager_1 = _DAT_00669ee0;
  this->CarSystemManager_2 = _DAT_00669ee0;
  this->field13_0x24 = _DAT_00669f7c;
  this->field14_0x28 = _DAT_00669f7c;
  *(undefined2 *)&this->CarSystemManager = _DAT_00669ee0;
  this->field10_0x1c = 0;
  this->field3_0x6 = 0;
  this->field15_0x2c = 0;
  return this;
}


void __thiscall S101__S101_FUN_0048a550(S101 *this)

{
  undefined2 uVar1;
  S101 *local_4;
  
  this->field6_0x10 = 0;
  this->field8_0x18 = 0;
  local_4 = this;
  bitShiftLeft1(&local_4,(void *)0x0);
  this->field13_0x24 = local_4;
  uVar1 = _DAT_00669ee0;
  this->field7_0x14 = 0;
  this->field15_0x2c = 0;
  this->a = (S6 *)0x0;
  this->CarSystemManager_2 = uVar1;
  this->field9_0x1a = 200;
  return;
}


