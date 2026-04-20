// Module: S52
// Functions working with structure S52
// Generated from gta2.exe.c

#include "common.h"

void __thiscall S52__S52(S52 *this)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 99;
  piVar2 = this->int_;
  do {
    *piVar2 = (int)(piVar2 + 1);
    piVar2 = piVar2 + 2;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  this->Passenger = (Passenger *)&this->field1_0x4;
  this->field395_0x320 = 0;
  return;
}


void __thiscall S52__SetPassengerPrev(S52 *this)

{
  this->Passenger = this->Passenger->PassengerPrev;
  return;
}


void __thiscall S52__S52_FUN_00445f00(S52 *this,Passenger *pPassenger)

{
  pPassenger->PassengerPrev = this->Passenger;
  this->Passenger = pPassenger;
  return;
}


