// Module: S4
// Functions working with structure S4
// Generated from gta2.exe.c

#include "common.h"

S4 * __thiscall S4__S4(S4 *this)

{
  Constructor(this->S4_01_Arr10,16,0xa,S4_01::S4_01);
  this->S4_01_Arr10[0].NextElement = this->S4_01_Arr10 + 1;
  this->S4_01_Arr10[1].NextElement = this->S4_01_Arr10 + 2;
  this->S4_01_Arr10[2].NextElement = this->S4_01_Arr10 + 3;
  this->S4_01_Arr10[3].NextElement = this->S4_01_Arr10 + 4;
  this->S4_01_Arr10[4].NextElement = this->S4_01_Arr10 + 5;
  this->S4_01_Arr10[5].NextElement = this->S4_01_Arr10 + 6;
  this->S4_01_Arr10[6].NextElement = this->S4_01_Arr10 + 7;
  this->S4_01_Arr10[7].NextElement = this->S4_01_Arr10 + 8;
  this->S4_01_Arr10[8].NextElement = this->S4_01_Arr10 + 9;
  this->S4_01_Arr10[9].NextElement = (S4_01 *)0x0;
  this->FirstElement = this->S4_01_Arr10;
  return this;
}


void __thiscall S4__S4_FUN_00425570(S4 *this)

{
  this->FirstElement = this->FirstElement->NextElement;
  return;
}


void __thiscall S4__S4_FUN_00425580(S4 *this,void *param_1)

{
  *(S4_01 **)((int)param_1 + 4) = this->FirstElement;
  this->FirstElement = (S4_01 *)param_1;
  return;
}


