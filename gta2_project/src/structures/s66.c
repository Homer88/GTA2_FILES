// Module: S66
// Functions working with structure S66
// Generated from gta2.exe.c

#include "common.h"

S67 * __thiscall S66__S66_FUN_00483fe0(S66 *this)

{
  S67 *this_00;
  
  this_00 = this->S67;
  this->S67 = (S67 *)this_00->Count;
  FUN_00482b20(this_00);
  return this_00;
}


S66 * __thiscall S66__S66(S66 *this)

{
  int *piVar1;
  int iVar2;
  
  _eh_vector_constructor_iterator_
            (this->Arr_0x180_S67,0x3c,385,S67::S67,S67::~S67);
  piVar1 = &this->Arr_0x180_S67[0].Count;
  iVar2 = 0x180;
  do {
    *piVar1 = (int)(piVar1 + 0xd);
    piVar1 = piVar1 + 0xf;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  this->Arr_0x180_S67[0x180].Count = 0;
  this->S67 = this->Arr_0x180_S67;
  return this;
}


