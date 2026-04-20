// Module: S19
// Functions working with structure S19
// Generated from gta2.exe.c

#include "common.h"

void __thiscall S19__S19_FUN_004c4d60(S19 *this)

{
  S20::S20_FUN_004c4b70(_gS20);
  this->field0_0x0 = 0;
  return;
}


S19 * __thiscall S19__S19(S19 *this)

{
  S20 *pS20;
  S21 *pS21;
  
  if (_gS20 == (S20 *)0x0) {
    pS20 = (S20 *)operator_new(0x2ee4);
    if (pS20 == (S20 *)0x0) {
      _gS20 = (S20 *)0x0;
    }
    else {
      _gS20 = S20::S20(pS20);
    }
  }
  if (_gS21 == (S21 *)0x0) {
    pS21 = (S21 *)operator_new(0xfa4);
    if (pS21 != (S21 *)0x0) {
      _gS21 = S21::S21(pS21);
      S19_FUN_004c4d60(this);
      return this;
    }
    _gS21 = (S21 *)0x0;
  }
  S19_FUN_004c4d60(this);
  return this;
}


