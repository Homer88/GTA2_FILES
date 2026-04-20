// Module: S23
// Functions working with structure S23
// Generated from gta2.exe.c

#include "common.h"

void __thiscall BuildingModel_Clear(S23 *this)

{
  this->field0_0x0 = 0;
  this->field1_0x4 = 0;
  return;
}


S23 * __thiscall BuildingModel_ctor(S23 *this)

{
  BuildingModel_Clear(this);
  return this;
}


