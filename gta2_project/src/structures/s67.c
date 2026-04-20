// Module: S67
// Functions working with structure S67
// Generated from gta2.exe.c

#include "common.h"

S67 * __thiscall S67__S67(S67 *this)

{
  Turrel::Turrel_FUN_00424620((Turrel *)this);
  CarSystemManager::SetIndexDefautCarManager
            ((CarSystemManager *)&this->CarSystemManager);
  this->Count = 0;
  this->field10_0x1c = _DAT_00665aa0;
  this->field9_0x18 = _DAT_00665aa0;
  this->field4_0x10 = _DAT_00665aa0;
  this->field3_0xc = _DAT_00665aa0;
  *(undefined2 *)&this->CarSystemManager = _DAT_006657f8______S38;
  this->field16_0x28 = 0;
  this->field11_0x20 = 0;
  this->field18_0x2c = 0;
  this->field17_0x2a = 0;
  this->field26_0x38 = 0;
  this->field19_0x2e = 0;
  this->field20_0x2f = 0;
  this->field25_0x34 = 2;
  return this;
}


