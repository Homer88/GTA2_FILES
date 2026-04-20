// Module: S76
// Functions working with structure S76
// Generated from gta2.exe.c

#include "common.h"

byte __thiscall S76__S76_FUN_0044c860(S76 *this)

{
  return *(int *)this->field0_0x0 == 2;
}


S76 * __thiscall S76__S76(S76 *this)

{
  this->field0_0x0 = 0;
  this->field1_0x4 = 0;
  this->field2_0x8 = 0;
  this->field3_0xc = 0;
  this->field9_0x20 = 0;
  this->field10_0x24 = 0;
  this->Ped = (Ped *)0x0;
  this->field6_0x18 = 0;
  this->field11_0x28 = 1;
  this->field15_0x2c = 1;
  this->field7_0x1c = 0;
  this->field8_0x1e = 0;
  this->ID = 0;
  this->field12_0x29 = 1;
  this->field13_0x2a = 0;
  this->field14_0x2b = 0;
  this->field19_0x30 = DAT_005e946c;
  this->field20_0x34 = DAT_005e946c;
  this->field16_0x2d = 0;
  return this;
}


undefined1 __thiscall S76__S76_FUN_0044ca70(S76 *this,S63 *pCAr)

{
  int iVar1;
  int iVar2;
  S119 *this_00;
  bool bVar3;
  byte bVar4;
  undefined1 uVar5;
  
  uVar5 = 0;
  switch(this->field9_0x20) {
  case 1:
    bVar4 = Car::IsDriverPlayer((Car *)pCAr);
    if (bVar4 != 0) goto switchD_0044ca82_caseD_1;
    iVar2._0_1_ = pCAr[2].field15_0x24;
    iVar2._1_1_ = pCAr[2].field16_0x25;
    iVar2._2_1_ = pCAr[2].field17_0x26;
    iVar2._3_1_ = pCAr[2].field18_0x27;
    if (iVar2 == 2) {
      return 1;
    }
    break;
  case 2:
switchD_0044ca82_caseD_1:
    uVar5 = 1;
    break;
  case 3:
    if (((this->Ped != (Ped *)0x0) && ((Ped *)pCAr == this->Ped)) &&
       (*(int *)&pCAr[2].CameraX == this->ID)) {
      return 1;
    }
    break;
  case 4:
    if ((Ped *)pCAr[3].IsFlag == this->Ped) {
      return 1;
    }
    break;
  case 5:
    break;
  case 6:
    if ((((this->Ped != (Ped *)0x0) && ((Ped *)pCAr == this->Ped)) &&
        (*(int *)&pCAr[2].CameraX == this->ID)) &&
       (((iVar1._0_1_ = pCAr[1].field15_0x24, iVar1._1_1_ = pCAr[1].field16_0x25
         , iVar1._2_1_ = pCAr[1].field17_0x26,
         iVar1._3_1_ = pCAr[1].field18_0x27, bVar3 = FUN_0044c6d0(this,iVar1),
         !bVar3 || ((bVar4 = Car::IsDriverPlayer((Car *)pCAr), this_00 = _gS119,
                    bVar4 != 0 &&
                    (bVar4 = S119::S119_FUN_0044c870(_gS119,(Car *)pCAr),
                    bVar4 == 0)))) ||
        ((bVar4 = Car::IsDriverPlayer((Car *)pCAr), bVar4 == 0 &&
         (bVar4 = S119::S119_FUN_0044c870(this_00,(Car *)pCAr), bVar4 != 0))))))
    goto switchD_0044ca82_caseD_1;
    break;
  default:
    goto switchD_0044ca82_caseD_6;
  }
switchD_0044ca82_caseD_6:
  return uVar5;
}


byte __thiscall S76__S76_FUN_0044cb80(S76 *this,Ped *pPed)

{
  byte bVar1;
  
  if (this->field9_0x20 == 1) {
    bVar1 = Ped::IsPlayerControlled(pPed);
    if (bVar1 != 0) {
      return 1;
    }
  }
  else if ((((this->field9_0x20 == 5) && (this->Ped != (Ped *)0x0)) &&
           (pPed == this->Ped)) && (pPed->ID == this->ID)) {
    return 1;
  }
  return 0;
}


