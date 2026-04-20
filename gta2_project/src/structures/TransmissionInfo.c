// Module: S123
// Functions working with structure S123
// Generated from gta2.exe.c

#include "common.h"

ushort __thiscall S123__S123_FUN_004b8d60(S123 *this)

{
  this->Arr_Element = this->Arr_Element + 1;
  if (0xd < this->Arr_Element) {
    this->Arr_Element = 9;
  }
  return this->Arr_Element;
}


void __thiscall S123__S123_FUN_004b8d80(S123 *this)

{
  this->count = this->count + 1;
  return;
}


void __thiscall S123__S123_FUN_004b9260(S123 *this)

{
  S124::S124_FUN_004b9050(&this->S124);
  return;
}


S123 * __thiscall S123__S123(S123 *this)

{
  S124::S124(&this->S124);
  this->Arr_Element = 9;
  this->count = 3;
  return this;
}


void __thiscall S123__S123_FUN_004b98b0(S123 *this)

{
  void *this_00;
  
  for (this_00 = (void *)S124::GetS125(&this->S124); this_00 != (void *)0x0;
      this_00 = *(void **)((int)this_00 + 0x44)) {
    FUN_004b94b0(this_00);
  }
  return;
}


