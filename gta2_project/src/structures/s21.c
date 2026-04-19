// Module: S21
// Functions working with structure S21
// Generated from gta2.exe.c

#include "../../include/common.h"

void __thiscall S21__S21_FUN_004c4b80(S21 *this,void *param_1)

{
  this->S21->field0_0x0 = param_1;
  this->S21 = (S21 *)&this->S21->field_0x4;
  return;
}


S21 * __thiscall S21__S21_FUN_004c4ba0(S21 *this)

{
  S21 **ppSVar1;
  
  ppSVar1 = &this->S21[-1].S21;
  this->S21 = (S21 *)ppSVar1;
  return *ppSVar1;
}


bool __thiscall S21__S21_FUN_004c4bc0(S21 *this)

{
  return this->S21 == this;
}


S21 * __thiscall S21__S21(S21 *this)

{
  this->S21 = this;
  return this;
}


