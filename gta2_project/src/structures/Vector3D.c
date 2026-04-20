// Module: S2
// Functions working with structure S2
// Generated from gta2.exe.c

#include "common.h"

S2 * __thiscall S2__S2(S2 *this)

{
  S1 *S1_A;
  int CorrentArr;
  
  _eh_vector_constructor_iterator_(this->S1,0xb0,306,S1::S1,S1::~S1);
  S1_A = (S1 *)&this->S1[0].FistElement;
  CorrentArr = 0x131;
  do {
    S1_A->CurrentElement = (S1 *)&S1_A->NextElement;
    S1_A = S1_A + 1;
    CorrentArr = CorrentArr + -1;
  } while (CorrentArr != 0);
  this->S1[0x131].FistElement = (S1 *)0x0;
  this->Next = this->S1;
  return this;
}


int __thiscall S2__S2_FUN_00420fd0(S2 *this)

{
  S1 *this_00;
  
  this_00 = this->Next;
  this->Next = this_00->FistElement;
  S1::S1_dop(this_00);
  return (int)this_00;
}


void __thiscall S2__S2_FUN_004254f0(S2 *this,int param_1)

{
  *(S1 **)(param_1 + 0xc) = this->Next;
  this->Next = (S1 *)param_1;
  return;
}


