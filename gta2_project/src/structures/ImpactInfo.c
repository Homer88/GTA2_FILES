// Module: S115
// Functions working with structure S115
// Generated from gta2.exe.c

#include "../../include/common.h"

S115 * __thiscall S115__S115(S115 *this)

{
  S116 **ppSVar1;
  int iVar2;
  
  _eh_vector_constructor_iterator_
            (this->ARR_S116,40,3000,S116::S166,S116::~S116);
  ppSVar1 = &this->ARR_S116[0].S116_1;
  iVar2 = 2999;
  do {
    *ppSVar1 = (S116 *)(ppSVar1 + 3);
    ppSVar1 = ppSVar1 + 10;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  this->BeginArr = this->ARR_S116;
  this->ARR_S116[2999].S116_1 = (S116 *)0x0;
  this->S116 = (S116 *)0x0;
  this->index = 0;
  return this;
}


S115 * __thiscall S115__S115(S115 *this)

{
  void *local_c;
  code *pcStack_8;
  int local_4;
  
  local_4 = -1;
  pcStack_8 = FUN_004e3d08;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  S115(this);
  local_4 = 0;
  FUN_004612a0();
  ExceptionList = local_c;
  return this;
}


void __thiscall S115__S115_Lighting(S115 *this)

{
  S116 *pSVar1;
  S116 *pSVar2;
  byte bVar3;
  S116 *pSVar4;
  S116 *pS116_1;
  
  this->index = 0;
  pSVar1 = this->S116;
  pS116_1 = (S116 *)0x0;
  do {
    while( true ) {
      do {
        pSVar4 = pS116_1;
        pS116_1 = pSVar1;
        if (pS116_1 == (S116 *)0x0) {
          return;
        }
        this->index = this->index + 1;
        pSVar1 = pS116_1->S116_1;
        bVar3 = FUN_0045b330(pS116_1);
      } while (bVar3 == 0);
      FUN_0045b320(&pS116_1->field0_0x0);
      if (pSVar4 != (S116 *)0x0) break;
LAB_0045bf8d:
      pSVar2 = this->S116;
      if (pSVar2 == pS116_1) {
        this->S116 = pS116_1->S116_1;
        pS116_1->S116_1 = this->BeginArr;
        this->BeginArr = pS116_1;
        pS116_1 = pSVar4;
      }
      else {
        pSVar4 = pSVar2->S116_1;
        while (pSVar4 != pS116_1) {
          pSVar2 = pSVar2->S116_1;
          pSVar4 = pSVar2->S116_1;
        }
        pSVar2->S116_1 = pS116_1->S116_1;
        pS116_1->S116_1 = this->BeginArr;
        this->BeginArr = pS116_1;
        pS116_1 = pSVar2;
      }
    }
    if (pSVar4->S116_1 != pS116_1) {
      pSVar4 = (S116 *)0x0;
      goto LAB_0045bf8d;
    }
    pSVar4->S116_1 = pS116_1->S116_1;
    pS116_1->S116_1 = this->BeginArr;
    this->BeginArr = pS116_1;
    pS116_1 = pSVar4;
  } while( true );
}


void __thiscall S115__S115_Lighting(S115 *this)

{
  S116 *pSVar1;
  S116 *pSVar2;
  S116 *this_00;
  byte bVar3;
  S116 *pSVar4;
  
  this->index = 0;
  pSVar1 = this->S116;
  this_00 = (S116 *)0x0;
  do {
    while( true ) {
      do {
        pSVar4 = this_00;
        this_00 = pSVar1;
        if (this_00 == (S116 *)0x0) {
          return;
        }
        this->index = this->index + 1;
        pSVar1 = this_00->S116_1;
        bVar3 = FUN_0045b330(this_00);
      } while (bVar3 == 0);
      FUN_0045b320(&this_00->field0_0x0);
      if (pSVar4 != (S116 *)0x0) break;
LAB_0045bf8d:
      pSVar2 = this->S116;
      if (pSVar2 == this_00) {
        this->S116 = this_00->S116_1;
        this_00->S116_1 = this->BeginArr;
        this->BeginArr = this_00;
        this_00 = pSVar4;
      }
      else {
        pSVar4 = pSVar2->S116_1;
        while (pSVar4 != this_00) {
          pSVar2 = pSVar2->S116_1;
          pSVar4 = pSVar2->S116_1;
        }
        pSVar2->S116_1 = this_00->S116_1;
        this_00->S116_1 = this->BeginArr;
        this->BeginArr = this_00;
        this_00 = pSVar2;
      }
    }
    if (pSVar4->S116_1 != this_00) {
      pSVar4 = (S116 *)0x0;
      goto LAB_0045bf8d;
    }
    pSVar4->S116_1 = this_00->S116_1;
    this_00->S116_1 = this->BeginArr;
    this->BeginArr = this_00;
    this_00 = pSVar4;
  } while( true );
}


void __thiscall S115__S115_FUN_0047f450(S115 *this,S116 *pS116)

{
  S116 *pSVar1;
  S116 *pSVar2;
  S116 *pSVar3;
  
  pSVar3 = (S116 *)0x0;
  pSVar1 = this->S116;
  if (this->S116 != (S116 *)0x0) {
    while (pSVar2 = pSVar1, pSVar2 != pS116) {
      pSVar1 = pSVar2->S116_1;
      pSVar3 = pSVar2;
      if (pSVar2->S116_1 == (S116 *)0x0) {
        return;
      }
    }
    FUN_0045b320(&pSVar2->field0_0x0);
    if (pSVar3 != (S116 *)0x0) {
      pSVar3->S116_1 = pSVar2->S116_1;
      pSVar2->S116_1 = this->BeginArr;
      this->BeginArr = pSVar2;
      return;
    }
    this->S116 = pSVar2->S116_1;
    pSVar2->S116_1 = this->BeginArr;
    this->BeginArr = pSVar2;
  }
  return;
}


void __thiscall S115__S115_FUN_0047f4b0(S115 *this,S116 *pS116)

{
  FUN_0045b320(&pS116->field0_0x0);
  pS116->S116_1 = this->BeginArr;
  this->BeginArr = pS116;
  return;
}


void __thiscall S115__S115_FUN_0047f4f0(S115 *this,S116 *pS116)

{
  S116::S116_FUN_004613b0(pS116);
  if (pS116->field_0x14 != '\0') {
    S115_FUN_0047f450(this,pS116);
    return;
  }
  S115_FUN_0047f4b0(this,pS116);
  return;
}


