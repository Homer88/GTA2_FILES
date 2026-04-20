// Module: S139
// Functions working with structure S139
// Generated from gta2.exe.c

#include "common.h"

S139 * __thiscall S139__S139(S139 *this)

{
  _eh_vector_constructor_iterator_
            (this->Arr_S140,0x6c,600,S140::S140,
             (_func_void_void_ptr *)&S140::~S140);
  this->field0_0x0 = 0;
  return this;
}


void __thiscall S139__FUN_00449d10(S139 *this)

{
  _eh_vector_destructor_iterator_
            (this->Arr_S140,0x6c,600,(_func_void_void_ptr *)&S140::~S140);
  return;
}


void __thiscall S139__FUN_00449d70(S139 *this)

{
  S140 *pSVar1;
  short sVar2;
  wchar_t *pCredits;
  int *piVar3;
  uint uVar4;
  short sVar5;
  uint uVar6;
  int local_8;
  int *local_4;
  
  sVar5 = 0;
  local_8 = 0;
  pCredits = (wchar_t *)Text::Bsearch(gText,"credits");
  piVar3 = &local_8;
  AdvanceToNextChar(this,pCredits,(int)piVar3,'\x01');
  sVar2 = (short)piVar3;
  local_4 = (int *)0x0;
  do {
    if (sVar2 == 0) {
      return;
    }
    sVar2 = (short)piVar3;
    pSVar1 = this->Arr_S140 + ((uint)local_4 & 0xffff);
    if (sVar2 == 0x2a) {
      sVar5 = sVar5 + 0x14;
    }
    else {
      if (sVar2 == 0x23) {
        AdvanceToNextChar(this,pCredits,(int)&local_8,'\x01');
        if (sVar2 == 0x57) goto LAB_00449e22;
        if (sVar2 == 0x42) {
          pSVar1->field3_0x6 = 2;
        }
        else if (sVar2 == 0x47) {
          pSVar1->field3_0x6 = 3;
        }
        else {
          pSVar1->field3_0x6 = (-(ushort)(sVar2 != 0x43) & 0xfffd) + 4;
        }
      }
      else {
        local_8 = local_8 + 0xffff;
LAB_00449e22:
        pSVar1->field3_0x6 = 0;
      }
      pSVar1->field2_0x4 = sVar5;
      pSVar1->field1_0x2 = 300;
      uVar6 = 0;
      while( true ) {
        piVar3 = &local_8;
        AdvanceToNextChar(this,pCredits,(int)piVar3,'\0');
        if ((short)piVar3 == 0x2a) break;
        uVar4 = uVar6 & 0xffff;
        uVar6 = uVar6 + 1;
        *(short *)(pSVar1->str + uVar4 * 2) = (short)piVar3;
      }
      local_8 = local_8 + 0xffff;
      (pSVar1->str + (uVar6 & 0xffff) * 2)[0] = '\0';
      (pSVar1->str + (uVar6 & 0xffff) * 2)[1] = '\0';
      *(undefined1 *)&pSVar1->field0_0x0 = 1;
      this->field0_0x0 = this->field0_0x0 + 1;
      sVar5 = 0;
      piVar3 = (int *)((int)local_4 + 1);
      local_4 = piVar3;
    }
    AdvanceToNextChar(this,pCredits,(int)&local_8,'\x01');
    sVar2 = (short)piVar3;
  } while( true );
}


