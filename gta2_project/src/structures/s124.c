// Module: S124
// Functions working with structure S124
// Generated from gta2.exe.c

#include "../../include/common.h"

S125 * __thiscall S124__GetS125(S124 *this)

{
  return this->s125;
}


S125 * __thiscall S124__FUN_004b8fe0(S124 *this)

{
  S125 *pSVar1;
  
  pSVar1 = this->Begin;
  this->Begin = pSVar1->s125;
  pSVar1->s125 = this->s125;
  this->s125 = pSVar1;
  return pSVar1;
}


void __thiscall S124__FUN_004b9000(S124 *this,S125 *pS125)

{
  S125 *pSVar1;
  S125 *pSVar2;
  S125 *pSVar3;
  
  pSVar3 = (S125 *)0x0;
  pSVar1 = this->s125;
  if (this->s125 != (S125 *)0x0) {
    while (pSVar2 = pSVar1, pSVar2 != pS125) {
      pSVar1 = pSVar2->s125;
      pSVar3 = pSVar2;
      if (pSVar2->s125 == (S125 *)0x0) {
        return;
      }
    }
    if (pSVar3 != (S125 *)0x0) {
      pSVar3->s125 = pSVar2->s125;
      pSVar2->s125 = this->Begin;
      this->Begin = pSVar2;
      return;
    }
    this->s125 = pSVar2->s125;
    pSVar2->s125 = this->Begin;
    this->Begin = pSVar2;
  }
  return;
}


void __thiscall S124__S124_FUN_004b9050(S124 *this)

{
  byte bVar1;
  S125 *pS125_3;
  S125 *pS125;
  S125 *pS125_1;
  S125 *pS125_2;
  
  this->count = 0;
  pS125 = this->s125;
  pS125_2 = (S125 *)0x0;
  do {
    while( true ) {
      do {
        pS125_3 = pS125_2;
        pS125_2 = pS125;
        if (pS125_2 == (S125 *)0x0) {
          return;
        }
        this->count = this->count + 1;
        pS125 = pS125_2->s125;
        bVar1 = S125::S125_FUN_004b8f70(pS125_2);
      } while (bVar1 == 0);
      if (pS125_3 != (S125 *)0x0) break;
LAB_004b9086:
      pS125_1 = this->s125;
      if (pS125_1 == pS125_2) {
        this->s125 = pS125_2->s125;
        pS125_2->s125 = this->Begin;
        this->Begin = pS125_2;
        pS125_2 = pS125_3;
      }
      else {
        pS125_3 = pS125_1->s125;
        while (pS125_3 != pS125_2) {
          pS125_1 = pS125_1->s125;
          pS125_3 = pS125_1->s125;
        }
        pS125_1->s125 = pS125_2->s125;
        pS125_2->s125 = this->Begin;
        this->Begin = pS125_2;
        pS125_2 = pS125_1;
      }
    }
    if (pS125_3->s125 != pS125_2) {
      pS125_3 = (S125 *)0x0;
      goto LAB_004b9086;
    }
    pS125_3->s125 = pS125_2->s125;
    pS125_2->s125 = this->Begin;
    this->Begin = pS125_2;
    pS125_2 = pS125_3;
  } while( true );
}


S124 * __thiscall S124__S124(S124 *this)

{
  _eh_vector_constructor_iterator_(this->S125_arr_3,80,3,S125::S125,S125::~S125)
  ;
  this->S125_arr_3[0].s125 = this->S125_arr_3 + 1;
  this->S125_arr_3[1].s125 = this->S125_arr_3 + 2;
  this->S125_arr_3[2].s125 = (S125 *)0x0;
  this->Begin = this->S125_arr_3;
  this->s125 = (S125 *)0x0;
  this->count = 0;
  return this;
}


