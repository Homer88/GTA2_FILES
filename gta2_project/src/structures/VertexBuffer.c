// Module: S95
// Functions working with structure S95
// Generated from gta2.exe.c

#include "common.h"

S95 * __thiscall S95__S95(S95 *this)

{
  Passenger::Passenger_FUN_00425450(&this->Passenger2);
  S95_FUN_0049c700(this);
  return this;
}


void * __thiscall S95__InitBuffer(S95 *this)

{
  int iVar1;
  Passenger **ppPVar2;
  
  ppPVar2 = &(this->Passenger2).PassengerPrev;
  for (iVar1 = 0x8c4; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppPVar2 = (Passenger *)0x0;
    ppPVar2 = ppPVar2 + 1;
  }
  return (void *)0x0;
}


void __thiscall S95__S95_FUN_0049c700(S95 *this)

{
  int iVar1;
  Passenger **ppPVar2;
  
  ppPVar2 = &(this->Passenger2).PassengerPrev;
  for (iVar1 = 2244; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppPVar2 = (Passenger *)0x0;
    ppPVar2 = ppPVar2 + 1;
  }
  this->field_0x38 = 0;
  this->field42_0x34 = 1;
  this->field43_0x36 = 0;
  this->field46_0x3a = 0;
  this->field_0x2fd0 = 1;
  this->field_0x2fd1 = 0;
  return;
}


void __thiscall S95__S95_FUN_0049c740(S95 *this,Passenger *param_1)

{
  if (param_1 == this->Passenger) {
    this->field_0x2fd0 = 1;
    this->field_0x2fd1 = 0;
  }
  return;
}


byte __thiscall S95__S95_FUN_0049c760(S95 *this)

{
  ushort uVar1;
  Passenger **ppPVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  
  bVar3 = this->field_0x23;
  if (((0x20 < bVar3) || (0x20 < (byte)this->field_0x24)) ||
     (bVar4 = this->field_0x22, 8 < bVar4)) {
    if (this->field_0x10 == this->field_0x13) {
      switch(_DAT_0066a7d4) {
      case 1:
        if (this->field_0x24 == '\0') {
          return 2;
        }
        break;
      case 2:
        if (0x20 < (byte)this->field_0x24) {
          return 2;
        }
        break;
      case 3:
        if (0x20 < bVar3) {
          return 2;
        }
        break;
      case 4:
        if (bVar3 == 0) {
          return 2;
        }
      }
    }
    return 0;
  }
  uVar1 = (ushort)bVar3 + (ushort)(byte)this->field_0x24 * 0x22;
  this->field20_0x1c = uVar1;
  ppPVar2 = &(&this->Passenger2)[uVar1].PassengerPrev;
  if (*(char *)((int)ppPVar2 + 1) != '\0') {
    if (*(char *)ppPVar2 == '\x01') {
      return 0;
    }
    if (*(byte *)((int)ppPVar2 + 2) == bVar4) {
      return 0;
    }
    uVar5 = (uint)*(byte *)((int)ppPVar2 + 2) - (uint)bVar4;
    uVar6 = (int)uVar5 >> 0x1f;
    if ((int)((uVar5 ^ uVar6) - uVar6) < 1) {
      return 0;
    }
    *(undefined1 *)ppPVar2 = 1;
  }
  return 1;
}


byte __thiscall S95__S95_FUN_0049c820(S95 *this)

{
  ushort uVar1;
  Passenger **ppPVar2;
  short sVar3;
  byte bVar4;
  char cVar5;
  short sVar6;
  
  cVar5 = this->field_0x22;
  if (DAT_0066a7e0 != '\0') {
    cVar5 = cVar5 + DAT_0066a7e0;
  }
  uVar1 = (ushort)(byte)this->field_0x23 + (ushort)(byte)this->field_0x24 * 0x22
  ;
  this->field20_0x1c = uVar1;
  ppPVar2 = &(&this->Passenger2)[uVar1].PassengerPrev;
  if ((*(char *)&(&this->Passenger2)[uVar1].PassengerPrev == '\x01') &&
     (cVar5 == *(char *)((int)ppPVar2 + 2))) {
    *(undefined1 *)ppPVar2 = 0;
    return (byte)ppPVar2;
  }
  if (this->field_0x4 == '\0') {
    sVar3 = (ushort)(byte)this->field_0x20 - (ushort)(byte)this->field_0x11;
    sVar6 = (ushort)(byte)this->field_0x21 - (ushort)(byte)this->field_0x12;
    sVar6 = (sVar6 * sVar6 + sVar3 * sVar3) * ((cVar5 != this->field_0x13) + 1);
  }
  else {
    sVar6 = this->count;
  }
  *this->field5_0x8 = this->field_0x23;
  this->field5_0x8[1] = this->field_0x24;
  this->field5_0x8[2] = this->field_0x20;
  this->field5_0x8[3] = this->field_0x21;
  this->field5_0x8[4] = cVar5;
  *(short *)(this->field5_0x8 + 6) = sVar6;
  this->field6_0xc = this->field6_0xc + 1;
  this->field5_0x8 = this->field5_0x8 + 8;
  if (*(char *)ppPVar2 == '\x01') {
    *(undefined1 *)((int)ppPVar2 + 3) = this->field_0x1b;
    *(char *)(ppPVar2 + 1) = cVar5;
  }
  else {
    *(undefined1 *)((int)ppPVar2 + 1) = this->field_0x1b;
    *(char *)((int)ppPVar2 + 2) = cVar5;
  }
  *(short *)((int)ppPVar2 + 6) = this->short + 1;
  if (this->field_0x24 == '\0') {
    DAT_0066a7c4 = this->field_0x23;
    DAT_0066a7c5 = this->field_0x24;
    DAT_0066a7c6 = this->field_0x20;
    DAT_0066a7c7 = this->field_0x21;
    DAT_0066a7c8 = this->field_0x22;
  }
  else if (this->field_0x24 == '\x1f') {
    DAT_0066a7d8 = this->field_0x23;
    DAT_0066a7d9 = this->field_0x24;
    DAT_0066a7da = this->field_0x20;
    DAT_0066a7db = this->field_0x21;
    DAT_0066a7dc = this->field_0x22;
  }
  bVar4 = this->field_0x23;
  if (bVar4 == 0) {
    DAT_0066a7cd = this->field_0x24;
    DAT_0066a7ce = this->field_0x20;
    DAT_0066a7cf = this->field_0x21;
    bVar4 = this->field_0x22;
    DAT_0066a7cc = 0;
    DAT_0066a7d0 = bVar4;
  }
  else if (bVar4 == 0x1f) {
    DAT_0066a7bc = bVar4;
    DAT_0066a7bd = this->field_0x24;
    DAT_0066a7be = this->field_0x20;
    DAT_0066a7bf = this->field_0x21;
    DAT_0066a7c0 = this->field_0x22;
    return this->field_0x21;
  }
  return bVar4;
}


byte __thiscall S95__S95_FUN_0049cf10(S95 *this)

{
  Passenger **ppPVar1;
  byte bVar2;
  char cVar3;
  undefined3 extraout_var;
  
  bVar2 = S95_FUN_0049c760(this);
  if (bVar2 == 1) {
    cVar3 = FUN_0049cb60(this->field_0x20,
                         CONCAT31(extraout_var,this->field_0x21));
    if (cVar3 == '\0') {
      ppPVar1 = &(&this->Passenger2)[(ushort)this->field20_0x1c].PassengerPrev;
      if ((*(char *)&(&this->Passenger2)[(ushort)this->field20_0x1c].
                     PassengerPrev == '\x01') &&
         (*(char *)((int)ppPVar1 + 3) == '\0')) {
        *(undefined1 *)ppPVar1 = 0;
        return 0;
      }
    }
    else {
      S95_FUN_0049c820(this);
    }
  }
  else if (bVar2 == 2) {
    this->field16_0x18 = 0;
    this->field_0x19 = 1;
    this->field_0x1a = 1;
    return 1;
  }
  return 0;
}


