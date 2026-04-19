// Module: S105
// Functions working with structure S105
// Generated from gta2.exe.c

#include "../../include/common.h"

bool __thiscall S105__S105_FindCar(S105 *this,Car *pCar)

{
  int iVar1;
  Car **ppCVar2;
  
  iVar1 = 0;
  if (0 < this->count) {
    ppCVar2 = &this->ARR_S106[0].Car;
    do {
      if (*ppCVar2 == pCar) {
        return true;
      }
      iVar1 = iVar1 + 1;
      ppCVar2 = ppCVar2 + 0xc;
    } while (iVar1 < this->count);
  }
  return false;
}


void __thiscall S105__S105_FUN_0044a970(S105 *this,Car *pCar,byte param_2)

{
  FUN_0044a420(this->ARR_S106 + param_2,pCar);
  return;
}


void __thiscall S105__S105_FUN_0044a990(S105 *this)

{
  int iVar1;
  S105 *this_00;
  
  iVar1 = 0;
  this_00 = this;
  if (0 < this->count) {
    do {
      FUN_0044a470(this_00);
      iVar1 = iVar1 + 1;
      this_00 = (S105 *)(this_00->ARR_S106 + 1);
    } while (iVar1 < this->count);
  }
  return;
}


S105 * __thiscall S105__S105(S105 *this)

{
  _eh_vector_constructor_iterator_(this,0x30,3,S106::S106,S106::~S106);
  this->count = 0;
  return this;
}


void __thiscall S105__FUN_0045acd0(S105 *this)

{
  _eh_vector_destructor_iterator_(this,0x30,3,S106::~S106);
  return;
}


