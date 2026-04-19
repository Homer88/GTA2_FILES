// Module: S70
// Functions working with structure S70
// Generated from gta2.exe.c

#include "../../include/common.h"

undefined4 __thiscall S70__S70_FUN_004c3380(S70 *this)

{
  undefined4 extraout_ECX;
  S71 *pS71;
  
  pS71 = this->s71;
  this->s71 = pS71->S71;
  pS71->S71 = this->S71;
  this->S71 = pS71;
  S71::S71_FUN_004c3240(pS71);
  return extraout_ECX;
}


void __thiscall S70__FUN_004c3490(S70 *this)

{
  this->s71 = (S71 *)0x0;
  this->S71 = (S71 *)0x0;
  _eh_vector_destructor_iterator_(this->ArrS71,0x18,0x32,S71::S71);
  return;
}


S70 * __thiscall S70__S70(S70 *this)

{
  S71 **ppSVar1;
  int iVar2;
  
  _eh_vector_constructor_iterator_(this->ArrS71,24,50,S71::S71,S71::S71);
  ppSVar1 = &this->ArrS71[0].S71;
  iVar2 = 0x31;
  do {
    *ppSVar1 = (S71 *)(ppSVar1 + 1);
    ppSVar1 = ppSVar1 + 6;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  this->s71 = this->ArrS71;
  this->ArrS71[49].S71 = (S71 *)0x0;
  this->S71 = (S71 *)0x0;
  this->field3_0x4b8 = 0;
  return this;
}


void __thiscall S70__S70_FUN_004c3500(S70 *this)

{
  S71 *pSVar1;
  byte bVar2;
  S71 *pS71_2;
  S71 *pS71;
  S71 *pS71_1;
  
  this->field3_0x4b8 = 0;
  pSVar1 = this->S71;
  pS71 = (S71 *)0x0;
  do {
    while( true ) {
      do {
        pS71_2 = pS71;
        pS71 = pSVar1;
        if (pS71 == (S71 *)0x0) {
          return;
        }
        this->field3_0x4b8 = this->field3_0x4b8 + 1;
        pSVar1 = pS71->S71;
        bVar2 = S71::S71_FUN_004c3300(pS71);
      } while (bVar2 == 0);
      if (pS71_2 != (S71 *)0x0) break;
LAB_004c3536:
      pS71_1 = this->S71;
      if (pS71_1 == pS71) {
        this->S71 = pS71->S71;
        pS71->S71 = this->s71;
        this->s71 = pS71;
        pS71 = pS71_2;
      }
      else {
        pS71_2 = pS71_1->S71;
        while (pS71_2 != pS71) {
          pS71_1 = pS71_1->S71;
          pS71_2 = pS71_1->S71;
        }
        pS71_1->S71 = pS71->S71;
        pS71->S71 = this->s71;
        this->s71 = pS71;
        pS71 = pS71_1;
      }
    }
    if (pS71_2->S71 != pS71) {
      pS71_2 = (S71 *)0x0;
      goto LAB_004c3536;
    }
    pS71_2->S71 = pS71->S71;
    pS71->S71 = this->s71;
    this->s71 = pS71;
    pS71 = pS71_2;
  } while( true );
}


