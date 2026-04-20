// Module: S27
// Functions working with structure S27
// Generated from gta2.exe.c

#include "common.h"

void * __thiscall S27_RemoveFirstElement(S27 *this)

{
  S28 *this_00;
  void *extraout_ECX;
  
  this_00 = this->FirstElement;
  this->FirstElement = this_00->NextElement;
  this_00->NextElement = (S28 *)this->field1_0x4;
  this->field1_0x4 = this_00;
  S28_dtor(this_00);
  return extraout_ECX;
}


void __thiscall S27_DestroyAllElements(S27 *this)

{
  undefined4 *this_00;
  
  for (this_00 = (undefined4 *)this->field1_0x4; this_00 != (undefined4 *)0x0;
      this_00 = (undefined4 *)*this_00) {
    S28_reset(this_00);
  }
  return;
}


S27 * __thiscall S27_ctor(S27 *this)

{
  S28 *pS28;
  
  pS28 = this->S28;
  _eh_vector_constructor_iterator_(pS28,0x11c,8,S28_ctor,S28_dtor);
  pS28->NextElement = this->S28 + 1;
  this->S28[1].NextElement = this->S28 + 2;
  this->S28[2].NextElement = this->S28 + 3;
  this->S28[3].NextElement = this->S28 + 4;
  this->S28[4].NextElement = this->S28 + 5;
  this->S28[5].NextElement = this->S28 + 6;
  this->S28[6].NextElement = this->S28 + 7;
  this->S28[7].NextElement = (S28 *)0x0;
  this->field1_0x4 = 0;
  this->field3_0x8e8 = 0;
  this->FirstElement = pS28;
  return this;
}


void __thiscall S27_ctor_FUN_00481380(S27 *this)

{
  S28 *pSVar1;
  S28 *pSVar2;
  S28 *pSVar3;
  bool bVar4;
  S28 *pSVar5;
  
  this->field3_0x8e8 = 0;
  pSVar1 = (S28 *)this->field1_0x4;
  pSVar3 = (S28 *)0x0;
  do {
    while( true ) {
      do {
        pSVar5 = pSVar3;
        pSVar3 = pSVar1;
        if (pSVar3 == (S28 *)0x0) {
          return;
        }
        this->field3_0x8e8 = this->field3_0x8e8 + 1;
        pSVar1 = pSVar3->NextElement;
        bVar4 = S28_isActive(pSVar3);
      } while (!bVar4);
      if (pSVar5 != (S28 *)0x0) break;
LAB_004813b4:
      pSVar2 = (S28 *)this->field1_0x4;
      if (pSVar2 == pSVar3) {
        this->field1_0x4 = pSVar3->NextElement;
        pSVar3->NextElement = this->FirstElement;
        this->FirstElement = pSVar3;
        pSVar3 = pSVar5;
      }
      else {
        pSVar5 = pSVar2->NextElement;
        while (pSVar5 != pSVar3) {
          pSVar2 = pSVar2->NextElement;
          pSVar5 = pSVar2->NextElement;
        }
        pSVar2->NextElement = pSVar3->NextElement;
        pSVar3->NextElement = this->FirstElement;
        this->FirstElement = pSVar3;
        pSVar3 = pSVar2;
      }
    }
    if (pSVar5->NextElement != pSVar3) {
      pSVar5 = (S28 *)0x0;
      goto LAB_004813b4;
    }
    pSVar5->NextElement = pSVar3->NextElement;
    pSVar3->NextElement = this->FirstElement;
    this->FirstElement = pSVar3;
    pSVar3 = pSVar5;
  } while( true );
}


