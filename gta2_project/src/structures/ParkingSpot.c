// Module: S165
// Functions working with structure S165
// Generated from gta2.exe.c

#include "common.h"

S165 * __thiscall S165__S165(S165 *this)

{
  _eh_vector_constructor_iterator_
            (this,0x2c,10,S162::S162,(_func_void_void_ptr *)&DAT_0041d890);
  this->field1_0x1b8 = 0;
  this->Cycle = 0;
  return this;
}


void __thiscall S165__S165_FUN_0041dcc0(S165 *this)

{
  int iVar1;
  char *pcVar2;
  int extraout_EDX;
  
  iVar1 = General::GetCycle(gGeneral);
  this->Cycle = iVar1;
  pcVar2 = &this->S162[0].field18_0x2b;
  iVar1 = 10;
  do {
    if ((((pcVar2[-1] != '\0') && (*pcVar2 != '\0')) &&
        (*(uint *)(pcVar2 + -0xf) != 0xffffffff)) &&
       (*(uint *)(pcVar2 + -0xf) < (uint)(this->Cycle - *(int *)(pcVar2 + -0xb))
       )) {
      pcVar2[-5] = '\0';
      FUN_0041d900(pcVar2 + -0x2b);
      iVar1 = extraout_EDX;
    }
    pcVar2 = pcVar2 + 0x2c;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}


