// Module: S112
// Functions working with structure S112
// Generated from gta2.exe.c

#include "common.h"

S112 * __thiscall S112__S112(S112 *this)

{
  S112_FUN_004a96d0(this);
  return this;
}


void * __thiscall S112__S112_FUN_004a96d0(S112 *this)

{
  this->field2_0x2 = 0;
  this->field3_0x3 = 0;
  this->field4_0x4 = 0;
  this->field12_0x18 = 0;
  this->field15_0x1c = 0;
  this->field_0x1a = 0;
  this->s110 = (S110 *)0x0;
  this->select = 0;
  this->field_0x28 = 0;
  this->field8_0x8 = _DAT_0066b89c;
  this->field9_0xc = _DAT_0066b89c;
  this->field11_0x14 = 0;
  this->field_0x1a = 0;
  this->field19_0x29 = 0;
  this->field20_0x2a = 0;
  this->field21_0x2c = 0;
  this->field24_0x30 = 0;
  this->field25_0x34 = 0;
  return (void *)0x0;
}


byte __thiscall S112__S112_FUN_004a9720(S112 *this)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  uint local_4;
  
  iVar2 = this->field11_0x14;
  bVar4 = *(byte *)(iVar2 + 0x75);
  uVar3 = (uint)bVar4;
  if (bVar4 < 6) {
    bVar4 = 0;
    local_4 = 0;
    do {
      if (*(S112 **)(iVar2 + 0x20 + local_4 * 4) == this) goto LAB_004a979f;
      bVar4 = bVar4 + 1;
      local_4 = (uint)bVar4;
    } while (bVar4 < 6);
    *(S112 **)(iVar2 + 0x20 + uVar3 * 4) = this;
    *(char *)(this->field11_0x14 + 0x75) =
         *(char *)(this->field11_0x14 + 0x75) + '\x01';
    uVar3 = this->s110->field20_0x20 - 3;
    bVar4 = (byte)uVar3;
    switch(uVar3) {
    case 0:
      pcVar1 = (char *)(this->field11_0x14 + 0x70);
      *pcVar1 = *pcVar1 + '\x01';
      return bVar4;
    case 1:
      pcVar1 = (char *)(this->field11_0x14 + 0x73);
      *pcVar1 = *pcVar1 + '\x01';
      return bVar4;
    case 2:
      pcVar1 = (char *)(this->field11_0x14 + 0x72);
      *pcVar1 = *pcVar1 + '\x01';
      return bVar4;
    case 3:
      pcVar1 = (char *)(this->field11_0x14 + 0x74);
      *pcVar1 = *pcVar1 + '\x01';
    }
LAB_004a979f:
    bVar4 = (byte)uVar3;
  }
  return bVar4;
}


void __thiscall S112__S112_FUN_004a9930(S112 *this)

{
  char *pcVar1;
  int iVar2;
  byte bVar3;
  uint local_4;
  
  iVar2 = this->field11_0x14;
  if ((iVar2 != 0) && (local_4 = 0, *(char *)(iVar2 + 0x75) != '\0')) {
    do {
      if (this == *(S112 **)(iVar2 + 0x20 + local_4 * 4)) {
        if (local_4 == *(byte *)(iVar2 + 0x75) - 1) {
          *(undefined4 *)(iVar2 + 0x20 + local_4 * 4) = 0;
        }
        else {
          *(undefined4 *)(iVar2 + 0x20 + local_4 * 4) =
               *(undefined4 *)(iVar2 + 0x1c + (uint)*(byte *)(iVar2 + 0x75) * 4)
          ;
          *(undefined4 *)(iVar2 + 0x1c + (uint)*(byte *)(iVar2 + 0x75) * 4) = 0;
        }
        *(char *)(iVar2 + 0x75) = *(char *)(iVar2 + 0x75) + -1;
        switch(this->s110->field20_0x20) {
        case 3:
          pcVar1 = (char *)(this->field11_0x14 + 0x70);
          *pcVar1 = *pcVar1 + -1;
          break;
        case 4:
          pcVar1 = (char *)(this->field11_0x14 + 0x73);
          *pcVar1 = *pcVar1 + -1;
          break;
        case 5:
          pcVar1 = (char *)(this->field11_0x14 + 0x72);
          *pcVar1 = *pcVar1 + -1;
          break;
        case 6:
          pcVar1 = (char *)(this->field11_0x14 + 0x74);
          *pcVar1 = *pcVar1 + -1;
        }
      }
      bVar3 = (char)local_4 + 1;
      local_4 = (uint)bVar3;
    } while (bVar3 < *(byte *)(iVar2 + 0x75));
  }
  return;
}


byte __thiscall S112__S111_FUN_004aab90(Police *this,S112 *pS112,int param_2)

{
  pS112->field11_0x14 = param_2;
  pS112->select = 5;
  S112::S112_FUN_004a9720(pS112);
  return 1;
}


void __thiscall S112__FUN_004ab060(S112 *this)

{
  byte bVar1;
  S169 *pAutoClass4;
  Ped *pPed;
  Ped *pPED;
  byte local_4;
  undefined3 uStack_3;
  
  _local_4 = (Car *)this;
  pAutoClass4 = (S169 *)FUN_00404c40(this);
  pPed = Char::CreatePed(gChar);
  Ped__SetSearchMode(pPed,4);
  Ped__SetCurrentOccupation(pPed,0x19);
  Ped::PutPedInCarRelated(pPed,this->s110->car);
  Ped::PedSetObjective(pPed,0xe,0);
  FUN_0040ce30(&local_4,this->field2_0x2);
  pPed->Car_1 = _local_4;
  FUN_0040ce30(&local_4,this->field3_0x3);
  pPed->Car_2 = _local_4;
  FUN_0040ce30(&local_4,this->field4_0x4);
  pPed->uns40 = _local_4;
  Ped::SetRemap(pPed,-1);
  Ped::SetNPCWeapon(pPed,0);
  Ped__SetHealth(pPed,400);
  pPed->field129_0x288 = 1;
  pPed->field130_0x28c = 1;
  pPed->GraphicType = 2;
  AIController__AssignPed((AutoClass4 *)pAutoClass4,pPed);
  AutoClass4::SetIndexPed((AutoClass4 *)pAutoClass4,3);
  _local_4 = (Car *)((uint)_local_4 & 0xffffff00);
  do {
    pPED = Char::CreatePed(gChar);
    FUN_00433320(pPED,this->s110->car);
    Ped__SetSearchMode(pPED,4);
    Ped__SetCurrentOccupation(pPED,0x19);
    Ped::PedSetObjective(pPED,0,9999);
    Ped::SetRemap(pPED,-1);
    Ped::SetNPCWeapon(pPED,0);
    Ped__SetHealth(pPED,400);
    pPED->field129_0x288 = 1;
    pPED->field130_0x28c = 1;
    pPED->GraphicType = 2;
    AIController__SetPedIndex((AutoClass4 *)pAutoClass4,pPED,(byte)_local_4);
    bVar1 = local_4 + 1;
    _local_4 = (Car *)CONCAT31(uStack_3,bVar1);
  } while (bVar1 < 3);
  pAutoClass4->field0_0x0 = 0;
  this->s110->pPed = pPed;
  this->s110->field22_0x28 = 6;
  Car::CarMakeDriveable1(this->s110->car,5);
  Car::CarMakeDummy(this->s110->car);
  Car::FUN_004222d0(this->s110->car);
  Car::Car_FUN_00422d20(this->s110->car);
  this->s110->S169 = pAutoClass4;
  return;
}


void __thiscall S112__S112_FUN_004ab330(S112 *this)

{
  S110 *pSVar1;
  S169 *pSVar2;
  byte bVar3;
  ushort uVar4;
  uint uVar5;
  Ped *pS49;
  
  pSVar1 = this->s110;
  this->select = 2;
  if (pSVar1->S169 == (S169 *)0x0) {
    pS49 = pSVar1->pPed;
    if (pS49 == (Ped *)0x0) {
      pSVar1->field22_0x28 = 5;
      this->s110->field23_0x2c = 1;
    }
    else {
      uVar4 = Ped::S49_FUN_004039f0(pS49);
      if (0x1d < uVar4) {
        Ped::FUN_0043e650(pS49);
        this->s110->field22_0x28 = 5;
        this->s110->field23_0x2c = 1;
        return;
      }
    }
  }
  else {
    bVar3 = PedManager__CheckPedStatus(pSVar1->S169);
    if (bVar3 != 0) {
      bVar3 = 0;
      pS49 = this->s110->pPed;
      while (pS49 != (Ped *)0x0) {
        Ped__ResetToDefaults(pS49);
        Ped::FUN_0043e650(pS49);
        pSVar2 = this->s110->S169;
        if (pSVar2 == (S169 *)0x0) break;
        uVar5 = (uint)bVar3;
        bVar3 = bVar3 + 1;
        pS49 = pSVar2->Ped_Arr9[uVar5];
      }
      PedManager__UpdateAll(this->s110->S169);
      this->s110->field22_0x28 = 5;
      this->s110->field23_0x2c = 1;
      return;
    }
  }
  return;
}


void __thiscall S112__S112_FUN_004ab400(S112 *this)

{
  S110 *pSVar1;
  Car *this_00;
  S169 *pSVar2;
  byte bVar3;
  short sVar4;
  ushort uVar5;
  uint uVar6;
  Ped *pS49;
  
  pSVar1 = this->s110;
  this_00 = pSVar1->car;
  if (this_00 == (Car *)0x0) {
    if (pSVar1->S169 == (S169 *)0x0) {
      pS49 = pSVar1->pPed;
      if (pS49 == (Ped *)0x0) {
        pSVar1->field22_0x28 = 5;
        this->s110->field23_0x2c = 1;
      }
      else {
        uVar5 = Ped::S49_FUN_004039f0(pS49);
        if (0x1d < uVar5) {
          Ped::FUN_0043e650(pS49);
          this->s110->field22_0x28 = 5;
          this->s110->field23_0x2c = 1;
          return;
        }
        if (pS49->CarCurrent != (Car *)0x0) {
          Ped::FUN_0043e650(pS49);
          goto LAB_004ab5bf;
        }
        if (pS49->field130_0x28c != 1) {
          pSVar1->field22_0x28 = 5;
          this->s110->field23_0x2c = 1;
          return;
        }
      }
    }
    else {
      bVar3 = PedManager__CheckPedStatus(pSVar1->S169);
      if (bVar3 != 0) {
        bVar3 = 0;
        pS49 = this->s110->pPed;
        while (pS49 != (Ped *)0x0) {
          Ped__ResetToDefaults(pS49);
          Ped::FUN_0043e650(pS49);
          pSVar2 = this->s110->S169;
          if (pSVar2 == (S169 *)0x0) break;
          uVar6 = (uint)bVar3;
          bVar3 = bVar3 + 1;
          pS49 = pSVar2->Ped_Arr9[uVar6];
        }
        PedManager__UpdateAll(this->s110->S169);
        this->s110->field22_0x28 = 5;
        this->s110->field23_0x2c = 1;
        return;
      }
    }
  }
  else {
    pSVar2 = pSVar1->S169;
    if (pSVar2 == (S169 *)0x0) {
      pS49 = pSVar1->pPed;
      if (pS49 == (Ped *)0x0) {
        sVar4 = FUN_004a9ad0(this_00);
        if (200 < sVar4) {
          Car::Car_FUN_00421470(this_00);
          this->s110->field22_0x28 = 5;
          this->s110->field23_0x2c = 1;
          return;
        }
      }
      else if ((0x1e < pS49->uns51) &&
              (sVar4 = FUN_004a9ad0(this_00), 200 < sVar4)) {
        Ped::FUN_0043e650(pS49);
        Car::Car_FUN_00421470(this->s110->car);
        goto LAB_004ab5bf;
      }
    }
    else {
      sVar4 = FUN_004a9ad0(this_00);
      if ((200 < sVar4) && (bVar3 = PedManager__CheckPedStatus(pSVar2), bVar3 != 0)
         ) {
        bVar3 = 0;
        pS49 = this->s110->pPed;
        while (pS49 != (Ped *)0x0) {
          Ped__ResetToDefaults(pS49);
          Ped::FUN_0043e650(pS49);
          pSVar2 = this->s110->S169;
          if (pSVar2 == (S169 *)0x0) break;
          uVar6 = (uint)bVar3;
          bVar3 = bVar3 + 1;
          pS49 = pSVar2->Ped_Arr9[uVar6];
        }
        PedManager__UpdateAll(this->s110->S169);
        Car::Car_FUN_00421470(this->s110->car);
LAB_004ab5bf:
        this->s110->field22_0x28 = 5;
        this->s110->field23_0x2c = 1;
        return;
      }
    }
  }
  return;
}


void __thiscall S112__S112_FUN_004ab610(S112 *this)

{
  S110 *pSVar1;
  S169 *pSVar3;
  Car *pCVar4;
  bool bVar5;
  short sVar6;
  ushort uVar7;
  byte bVar8;
  uint uVar9;
  S169 *pSVar2;
  Ped *pPed;
  
  if ((*(int *)(_pS49_2 + 0x16c) == 0) ||
     (_pS49_2 != *(int *)(*(int *)(_pS49_2 + 0x16c) + 0x54))) {
    pSVar1 = this->s110;
    if (pSVar1->S169 != (S169 *)0x0) {
      bVar8 = PedManager__CheckPedStatus(pSVar1->S169);
      if (bVar8 == 0) {
        return;
      }
      pSVar1 = this->s110;
      pCVar4 = pSVar1->car;
      sVar6 = FUN_004a9ad0(pCVar4);
      if ((sVar6 < 0xc9) && (pCVar4->field19_0x7c != 2)) {
        return;
      }
      bVar8 = 0;
      pPed = pSVar1->pPed;
      while (pPed != (Ped *)0x0) {
        Ped__ResetToDefaults(pPed);
        Ped::FUN_0043e650(pPed);
        pSVar3 = this->s110->S169;
        if (pSVar3 == (S169 *)0x0) break;
        uVar9 = (uint)bVar8;
        bVar8 = bVar8 + 1;
        pPed = pSVar3->Ped_Arr9[uVar9];
      }
      PedManager__UpdateAll(this->s110->S169);
      pCVar4 = this->s110->car;
      if (pCVar4->field19_0x7c != 2) {
        Car::Car_FUN_00421470(pCVar4);
      }
      goto LAB_004ab77c;
    }
    pCVar4 = pSVar1->car;
    sVar6 = FUN_004a9ad0(pCVar4);
    if ((sVar6 < 0xc9) && (pCVar4->field19_0x7c != 2)) {
      return;
    }
    if (pSVar1->pPed->uns51 < 0x1f) {
      return;
    }
    if (pCVar4->field19_0x7c != 2) {
      Car::Car_FUN_00421470(pCVar4);
    }
    Ped::FUN_0043e650(this->s110->pPed);
  }
  else {
    pSVar1 = this->s110;
    pSVar2 = pSVar1->S169;
    if (pSVar2 == (S169 *)0x0) {
      pCVar4 = pSVar1->car;
      sVar6 = FUN_004a9ad0(pCVar4);
      if (sVar6 < 0x51) {
        return;
      }
      Car::Car_FUN_00421470(pCVar4);
      this->s110->field22_0x28 = 5;
      this->s110->field23_0x2c = 1;
      return;
    }
    sVar6 = FUN_004a9ad0(pSVar1->car);
    if (sVar6 < 0xc9) {
      return;
    }
    bVar5 = S169::FUN_00404840(pSVar2);
    if (!bVar5) {
      bVar5 = true;
      Car::FUN_004222f0(this->s110->car);
      pSVar1 = this->s110;
      bVar8 = 0;
      pSVar3 = pSVar1->S169;
      pPed = pSVar3->Ped_Arr9[0];
      if (pPed != (Ped *)0x0) {
        do {
          if ((pPed->GameObject != (GameObject *)0x0) &&
             (uVar7 = Ped::S49_FUN_004039f0(pPed), uVar7 < 10)) {
            bVar5 = false;
          }
          bVar8 = bVar8 + 1;
          pPed = pSVar3->Ped_Arr9[bVar8];
        } while (pPed != (Ped *)0x0);
        if (!bVar5) {
          return;
        }
      }
      Ped__ResetToDefaults(pSVar1->pPed);
      Car::Car_FUN_00421470(this->s110->car);
      bVar8 = 0;
      pPed = this->s110->S169->Ped_Arr9[0];
      while (pPed != (Ped *)0x0) {
        if (pPed->GameObject != (GameObject *)0x0) {
          Ped__ResetToDefaults(pPed);
          Ped::FUN_0043e650(pPed);
        }
        bVar8 = bVar8 + 1;
        pPed = this->s110->S169->Ped_Arr9[bVar8];
      }
      PedManager__UpdateAll(this->s110->S169);
LAB_004ab77c:
      this->s110->field22_0x28 = 5;
      this->s110->field23_0x2c = 1;
      return;
    }
    bVar8 = 0;
    pPed = this->s110->pPed;
    while (pPed != (Ped *)0x0) {
      Ped__SetSearchMode(pPed,3);
      Ped__ResetToDefaults(pPed);
      pSVar3 = this->s110->S169;
      if (pSVar3 == (S169 *)0x0) break;
      uVar9 = (uint)bVar8;
      bVar8 = bVar8 + 1;
      pPed = pSVar3->Ped_Arr9[uVar9];
    }
    PedManager__UpdateAll(this->s110->S169);
    Car::Car_FUN_00421470(this->s110->car);
  }
  this->s110->field22_0x28 = 5;
  this->s110->field23_0x2c = 1;
  return;
}


void * __thiscall S112__S112_FUN_004ab8c0(S112 *this)

{
  byte bVar1;
  S110 *pSVar2;
  void *pvVar3;
  
  pSVar2 = this->s110;
  if (pSVar2->field21_0x24 == 2) {
    bVar1 = this->field19_0x29;
    if (bVar1 != 0) {
      bVar1 = *(byte *)(_gPolice + 0x658);
      if (bVar1 != 0) {
        bVar1 = bVar1 - 1;
        *(byte *)(_gPolice + 0x658) = bVar1;
      }
      this->field19_0x29 = 0;
    }
    pSVar2 = (S110 *)CONCAT31((int3)((uint)pSVar2 >> 8),bVar1);
    if (this->select == 6) {
LAB_004ab90b:
      pvVar3 = (void *)this->s110->field21_0x24;
      if (pvVar3 == (void *)0x0) {
        S112_FUN_004ab330(this);
        return pvVar3;
      }
      if (pvVar3 == (void *)0x2) {
        S112_FUN_004ab400(this);
        return pvVar3;
      }
      S112_FUN_004ab610(this);
      return pvVar3;
    }
    S112_FUN_004a9930(this);
    this->select = 6;
  }
  else if (this->select == 6) goto LAB_004ab90b;
  return pSVar2;
}


byte __thiscall S112__S112_FUN_004ab930(S112 *this)

{
  Ped *this_00;
  bool bVar1;
  S110 *pS110;
  S110 *pS110_00;
  int *piVar2;
  S110 *pS110_4;
  undefined3 extraout_var;
  void *this_01;
  Car *local_14;
  undefined1 local_10 [4];
  undefined1 local_c [4];
  undefined1 local_8 [4];
  undefined4 local_4;
  
  piVar2 = (int *)this->field11_0x14;
  if (((*piVar2 != 0) && (this->field25_0x34 == 0)) && ((short)piVar2[3] != 0))
  {
    if (this->s110->field21_0x24 == 0) {
      pS110 = (S110 *)Ped__GetYCoordinate((Ped *)*piVar2,(int)&local_14);
      pS110_00 = (S110 *)Ped__GetXCoordinate((Ped *)*piVar2,(int)local_10);
      this_00 = _pS49_2;
      piVar2 = (int *)Ped__GetYCoordinate(_pS49_2,(int)local_c);
      pS110_4 = (S110 *)Ped__GetXCoordinate(this_00,(int)local_8);
      FUN_0042a6b0(this_01,&local_4,pS110_4,piVar2,pS110_00,pS110);
      local_14 = pS110_4->car;
      bVar1 = FUN_004037e0(&local_14,(SpriteS1 *)&DAT_0066bb2c);
      return CONCAT31(extraout_var,bVar1) != 0;
    }
    return 1;
  }
  return 0;
}


void __thiscall S112__S112_FUN_004ab9d0(S112 *this)

{
  S110 *pSVar1;
  char cVar2;
  Ped *pS49;
  
  pS49 = _pS49_2;
  pSVar1 = this->s110;
  if (((pSVar1->field21_0x24 != 0) &&
      (cVar2 = Ped::S49_FUN_00450cb0(_pS49_2), cVar2 == '\0')) &&
     (cVar2 = Ped::S49_FUN_00450cb0(pS49), cVar2 != '\x02')) {
    Car::Car_FUN_00421540(pSVar1->car);
    return;
  }
  Ped::SetAnimationState(pS49,0,9999);
  Ped::PedSetObjective(_pS49_2,0,9999);
  return;
}


void __thiscall S112__S112_FUN_004aba30(S112 *this)

{
  Ped *this_00;
  char cVar1;
  
  this_00 = _pS49_2;
  if (((this->s110->field21_0x24 == 0) ||
      (cVar1 = Ped::S49_FUN_00450cb0(_pS49_2), cVar1 != '\0')) ||
     (cVar1 = Ped::S49_FUN_00450cb0(this_00), cVar1 == '\x02')) {
    Ped::SetAnimationState(this_00,0,9999);
    Ped::PedSetObjective(_pS49_2,0,9999);
  }
  return;
}


void __thiscall S112__S112_FUN_004ad600(S112 *this)

{
  uint uVar1;
  uint uVar2;
  Car *pCVar3;
  Model *pMVar4;
  EngineStruct *pEVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  bool bVar11;
  byte bVar12;
  char cVar13;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar14;
  S110 *pS110_00;
  S110 *pS110_4;
  undefined4 *puVar15;
  undefined3 extraout_var_01;
  S169 *pSVar16;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  Player *this_00;
  undefined3 extraout_var_04;
  undefined4 *puVar17;
  undefined4 uVar18;
  int *piVar19;
  int iVar20;
  uint uVar21;
  byte bVar22;
  void *this_01;
  S112 *this_02;
  Car *unaff_ESI;
  undefined4 unaff_EDI;
  ushort timer;
  int *piVar23;
  uint local_24;
  byte local_20 [4];
  byte bVar24;
  Car *in_stack_ffffffe8;
  Car *local_14;
  undefined4 local_10;
  Ped *in_stack_fffffff4;
  Car *in_stack_fffffff8;
  AutoClass4 *pAutoClass4;
  S110 *pS110_1;
  S110 *pS110;
  Ped *pS49_1;
  
  pS110_1 = this->s110;
  if (pS110_1 != (S110 *)0x0) {
    pS49_1 = pS110_1->pPed;
    in_stack_fffffff8 = unaff_ESI;
    if (pS49_1 == (Ped *)0x0) {
      pAutoClass4 = (AutoClass4 *)pS110_1->S169;
      if ((pAutoClass4 != (AutoClass4 *)0x0) &&
         (pS49_1 = pAutoClass4->Ped[0], pS49_1 != (Ped *)0x0)) {
        local_10 = 0x4ad655;
        PedManager__RemovePed((S169 *)pAutoClass4,pS49_1);
        local_10 = 0x4ad661;
        in_stack_fffffff4 = pS49_1;
        AIController__AssignPed((AutoClass4 *)this->s110->S169,pS49_1);
        this->s110->pPed = pS49_1;
      }
    }
    else if (pS49_1->uns51 == 0) {
      in_stack_fffffff4 = (Ped *)0x4ad623;
      iVar20 = Ped__GetPedState(pS49_1);
      if (iVar20 != 9) {
        in_stack_fffffff4 = (Ped *)0x4ad62f;
        uVar21 = Ped::Get_FUN_00433b40(pS49_1);
        if ((char)uVar21 != '\0') {
          _gPolice->field_0x7b4 = 1;
        }
      }
    }
  }
  switch(this->select) {
  case 1:
    DAT_0066b79c = 1;
    bVar22 = 0;
    iVar20 = this->s110->field21_0x24;
    if (((iVar20 == 2) || (iVar20 == 0)) ||
       (pCVar3 = this->s110->car, 0x50 < pCVar3->field15_0x76)) {
      this->select = 6;
    }
    else {
      Car::Car_FUN_00421550(pCVar3);
      if (this->s110->field22_0x28 == 6) {
        S112_FUN_004ab8c0(this);
      }
      pS110 = this->s110;
      if (pS110->field22_0x28 == 5) {
        if (((pS110->car != (Car *)0x0) &&
            (pEVar5 = pS110->car->EngineStruct, pEVar5 != (EngineStruct *)0x0))
           && (cVar13 = pEVar5->field_0x28, '\0' < cVar13)) {
          JuncIds::S91_FUN_0040cb60(gJuncIds,(short)cVar13);
          this->s110->car->EngineStruct->field_0x28 = 255;
        }
        S112_FUN_004a9930(this);
        if ((this->field19_0x29 != 0) && (_gPolice->count != 0)) {
          _gPolice->count = _gPolice->count - 1;
        }
        this->s110->field22_0x28 = 0;
        S110::S110_FUN_004c5480(this->s110);
        S112_FUN_004a96d0(this);
        return;
      }
      piVar23 = (int *)this->field11_0x14;
      if ((((piVar23 != (int *)0x0) && (*piVar23 != 0)) &&
          (bVar12 = S112_FUN_004ab930(this), bVar12 != 0)) &&
         ((pS110->field20_0x20 == 6 || (piVar23[1] != 6)))) {
        piVar19 = (int *)Ped__GetXCoordinate((Ped *)*piVar23,(int)&stack0xfffffffc
                                          );
        piVar23[4] = *piVar19;
        puVar15 = (undefined4 *)this->field11_0x14;
        puVar17 = (undefined4 *)
                  Ped__GetYCoordinate((Ped *)*puVar15,(int)&stack0xfffffffc);
        puVar15[5] = *puVar17;
        puVar15 = (undefined4 *)this->field11_0x14;
        puVar17 = (undefined4 *)
                  Ped::GetPositionZ((Ped *)*puVar15,(int)&stack0xfffffffc);
        puVar15[6] = *puVar17;
        local_20[0] = 0x49;
        local_20[1] = 0xd4;
        local_20[2] = 0x4a;
        local_20[3] = 0;
        Police::S111_FUN_004aab90(_gPolice,this,this->field11_0x14);
        return;
      }
      _pS49_2 = pS110->pPed;
      Ped__Initialize(_pS49_2);
      if (_pS49_2 != (Ped *)0x0) {
        do {
          pS49_1 = _pS49_2;
          uVar18 = Ped__GetActionParam(_pS49_2);
          switch(uVar18) {
          case 0:
            if (pS49_1 == this->s110->pPed) {
              if (pS49_1->CarCurrent == (Car *)0x0) {
                uVar6._0_1_ = pS49_1->flags;
                uVar6._1_1_ = pS49_1->uns59;
                uVar6._2_1_ = pS49_1->uns60;
                uVar6._3_1_ = pS49_1->uns61;
                if ((uVar6 & 0x8000000) == 0) {
                  local_20[0] = 0xf6;
                  local_20[1] = 0xd4;
                  local_20[2] = 0x4a;
                  local_20[3] = 0;
                  Ped::SetAnimationState(pS49_1,0,9999);
                  local_20[0] = 8;
                  local_20[1] = 0xd5;
                  local_20[2] = 0x4a;
                  local_20[3] = 0;
                  Ped::PedSetObjective(_pS49_2,0x23,9999);
                  Ped__EnterCar(_pS49_2,this->s110->car);
                  Ped__UpdateState(_pS49_2);
                }
              }
              else {
                DAT_0066b79c = 0;
              }
            }
            break;
          case 2:
          case 0xc:
          case 0x14:
switchD_004ad48a_caseD_2:
            local_20[0] = 0x50;
            local_20[1] = 0xd5;
            local_20[2] = 0x4a;
            local_20[3] = 0;
            Ped::SetAnimationState(pS49_1,0,9999);
            local_20[0] = 0x61;
            local_20[1] = 0xd5;
            local_20[2] = 0x4a;
            local_20[3] = 0;
            Ped::PedSetObjective(_pS49_2,0,9999);
            break;
          case 0xe:
          case 0x34:
            DAT_0066b79c = 0;
            pMVar4 = this->s110->car->Model;
            if (pMVar4 != (Model *)0x0) {
              S121::S121_FUN_00446290(gS121,pMVar4);
              this->s110->car->Model = (Model *)0x0;
            }
            break;
          case 0x1c:
            cVar13 = Ped::S49_FUN_00450cb0(pS49_1);
            if (cVar13 != '\0') goto switchD_004ad48a_caseD_2;
            break;
          case 0x23:
            S112_FUN_004ab9d0(this);
            break;
          case 0x24:
            S112_FUN_004aba30(this);
          }
          pSVar16 = this->s110->S169;
          if (pSVar16 == (S169 *)0x0) {
            _pS49_2 = (Ped *)0x0;
          }
          else {
            _pS49_2 = pSVar16->Ped_Arr9[bVar22];
          }
          bVar22 = bVar22 + 1;
          if (_pS49_2 == (Ped *)0x0) {
            return;
          }
        } while( true );
      }
    }
    return;
  case 2:
    DAT_0066b79c = 1;
    this->select = 6;
    return;
  case 3:
    bVar11 = true;
    DAT_0066b79c = 1;
    bVar22 = 0;
    pS110 = this->s110;
    if (pS110->field22_0x28 != 3) {
      if (pS110->field22_0x28 == 6) {
        S112_FUN_004ab8c0(this);
      }
      goto LAB_004ac130;
    }
    if (pS110->field23_0x2c == 0) {
      bVar11 = false;
      if (pS110->field15_0x18 != -0x50) goto LAB_004ac130;
    }
    else {
      if (gChar->field4_0x5 < 0x1a) {
        if (pS110->field20_0x20 == 3) {
          FUN_004aadd0(unaff_ESI);
        }
        else if (pS110->field20_0x20 == 5) {
          FUN_004ab060(this);
          _pS49_2 = this->s110->pPed;
          this->field_0x1a = 0;
          goto LAB_004ac130;
        }
        _pS49_2 = this->s110->pPed;
        this->field_0x1a = 0;
        goto LAB_004ac130;
      }
      if (pS110->car == (Car *)0x0) goto LAB_004ac130;
      Car::Car_FUN_00421470(pS110->car);
      this->s110->car = (Car *)0x0;
    }
    this->select = 6;
    S112_FUN_004a9930(this);
LAB_004ac130:
    if ((this->select != 6) && (bVar11)) {
      pS49_1 = this->s110->pPed;
      _pS49_2 = pS49_1;
      if (*(short *)(this->field11_0x14 + 0xc) == 0xfa) {
        this->select = 5;
        return;
      }
      if (pS49_1 != (Ped *)0x0) {
        do {
          if ((pS49_1->CurrentState != PEDSTATE_DEAD) &&
             (pS49_1->field130_0x28c == 1)) {
            _pS49_2 = pS49_1;
            uVar18 = Ped__GetActionParam(pS49_1);
            switch(uVar18) {
            case 0:
              bVar11 = Ped::S49_Get_FUN_00472fd0(pS49_1);
              if (bVar11) {
                if (pS49_1->CarCurrent == (Car *)0x0) {
                  Ped::SetAnimationState(pS49_1,0,9999);
                  Ped::PedSetObjective(_pS49_2,0xc,9999);
                  _pS49_2->Car_1 = *(Car **)(this->field11_0x14 + 0x10);
                  _pS49_2->Car_2 = *(Car **)(this->field11_0x14 + 0x14);
                  _pS49_2->uns40 = *(undefined4 *)(this->field11_0x14 + 0x18);
                }
                else {
                  Ped::SetAnimationState(pS49_1,0,9999);
                  Ped::PedSetObjective(_pS49_2,0x24,9999);
                  Ped__EnterCar(_pS49_2,this->s110->car);
                }
              }
              break;
            case 0xc:
              this->field_0x28 = 0;
              pS49_1 = _pS49_2;
              cVar13 = Ped::S49_FUN_00450cb0(_pS49_2);
              if (cVar13 == '\x01') {
                Ped::SetAnimationState(pS49_1,0,9999);
                timer = 200;
                iVar20 = 0x33;
                goto LAB_004ac4c7;
              }
              break;
            case 0xe:
              FUN_004aba90();
              pS49_1 = _pS49_2;
              iVar20 = this->field11_0x14;
              bVar11 = Car::Car_FUN_00403820
                                 ((Car *)&_pS49_2->Car_1,(int *)(iVar20 + 0x10))
              ;
              if ((CONCAT31(extraout_var,bVar11) != 0) ||
                 (bVar11 = Car::Car_FUN_00403820
                                     ((Car *)&pS49_1->Car_2,
                                      (int *)(iVar20 + 0x14)),
                 CONCAT31(extraout_var_00,bVar11) != 0)) {
                iVar14 = Decoder_DecodeFloat((int *)(iVar20 + 0x10));
                local_24 = CONCAT31(local_24._1_3_,(char)iVar14);
                iVar14 = Decoder_DecodeFloat((void *)(iVar20 + 0x14));
                local_20[0] = (char)iVar14;
                iVar20 = Decoder_DecodeFloat((void *)(iVar20 + 0x18));
                bVar24 = (byte)iVar20;
                bVar12 = S95::S95_FUN_0049d7a0
                                   (_gS95,'\x01',(byte *)&local_24,local_20,
                                    &stack0xffffffe4,'\0');
                if (bVar12 != 0) {
                  FUN_0040ce30(&stack0xfffffff4,(byte)local_24);
                  _pS49_2->Car_1 = (Car *)in_stack_fffffff4;
                  *(Car **)(this->field11_0x14 + 0x10) = _pS49_2->Car_1;
                  FUN_0040ce30(&stack0xfffffff8,local_20[0]);
                  _pS49_2->Car_2 = in_stack_fffffff8;
                  *(Car **)(this->field11_0x14 + 0x14) = _pS49_2->Car_2;
                  FUN_0040ce30(&stack0xfffffffc,bVar24);
                  _pS49_2->uns40 = unaff_EDI;
                  *(undefined4 *)(this->field11_0x14 + 0x18) = _pS49_2->uns40;
                }
              }
              this->field_0x28 = 1;
              break;
            case 0x14:
              Ped::SetAnimationState(pS49_1,0,9999);
              Ped::PedSetObjective(_pS49_2,0xc,9999);
              _pS49_2->Car_1 = *(Car **)(this->field11_0x14 + 0x10);
              _pS49_2->Car_2 = *(Car **)(this->field11_0x14 + 0x14);
              _pS49_2->uns40 = *(undefined4 *)(this->field11_0x14 + 0x18);
              break;
            case 0x1c:
              cVar13 = Ped::S49_FUN_00450cb0(pS49_1);
              if (cVar13 != '\0') goto switchD_004ac1a3_caseD_20;
              break;
            case 0x20:
switchD_004ac1a3_caseD_20:
              Ped::SetAnimationState(pS49_1,0,9999);
              timer = 9999;
              iVar20 = 0;
LAB_004ac4c7:
              Ped::PedSetObjective(_pS49_2,iVar20,timer);
              break;
            case 0x23:
              S112_FUN_004ab9d0(this);
              break;
            case 0x24:
              S112_FUN_004aba30(this);
              break;
            case 0x33:
              cVar13 = Ped::S49_FUN_00450cb0(pS49_1);
              if (cVar13 == '\x02') {
                this->select = 6;
                *(undefined1 *)(this->field11_0x14 + 0x1c) = 1;
              }
              break;
            case 0x34:
              Ped::PedSetObjective(pS49_1,0xe,9999);
              iVar20 = Decoder_DecodeFloat((void *)(this->field11_0x14 + 0x10));
              FUN_0040ce30(&stack0xffffffe8,(byte)iVar20);
              _pS49_2->Car_1 = in_stack_ffffffe8;
              iVar20 = Decoder_DecodeFloat((void *)(this->field11_0x14 + 0x14));
              FUN_0040ce30(&local_14,(byte)iVar20);
              _pS49_2->Car_2 = local_14;
              iVar20 = Decoder_DecodeFloat((void *)(this->field11_0x14 + 0x18));
              FUN_0040ce30(&local_10,(byte)iVar20);
              _pS49_2->uns40 = local_10;
            }
          }
          pSVar16 = this->s110->S169;
          if (pSVar16 == (S169 *)0x0) {
            pS49_1 = (Ped *)0x0;
          }
          else {
            pS49_1 = pSVar16->Ped_Arr9[bVar22];
          }
          bVar22 = bVar22 + 1;
        } while (pS49_1 != (Ped *)0x0);
        _pS49_2 = (Ped *)0x0;
      }
    }
    return;
  default:
    return;
  case 5:
    break;
  case 6:
    DAT_0066b79c = 1;
    bVar22 = 0;
    _pS49_2 = this->s110->pPed;
    pCVar3 = this->s110->car;
    if (pCVar3 != (Car *)0x0) {
      pMVar4 = pCVar3->Model;
      if (pMVar4 != (Model *)0x0) {
        S121::S121_FUN_00446290(gS121,pMVar4);
        this->s110->car->Model = (Model *)0x0;
      }
      bVar11 = Car::IsEmergencyOrFbiCar(this->s110->car);
      if (bVar11) {
        Car::Car_FUN_00422d80(this->s110->car);
      }
    }
    iVar20 = this->s110->field22_0x28;
    if (iVar20 == 3) {
      pCVar3 = this->s110->car;
      if (((pCVar3 != (Car *)0x0) &&
          (pEVar5 = pCVar3->EngineStruct, pEVar5 != (EngineStruct *)0x0)) &&
         (cVar13 = pEVar5->field_0x28, '\0' < cVar13)) {
        JuncIds::S91_FUN_0040cb60(gJuncIds,(short)cVar13);
        this->s110->car->EngineStruct->field_0x28 = 0xff;
      }
      this->s110->field22_0x28 = 0;
      S110::S110_FUN_004c5480(this->s110);
      if ((this->field19_0x29 != 0) && (_gPolice->count != 0)) {
        _gPolice->count = _gPolice->count - 1;
      }
      S112_FUN_004a96d0(this);
      S112_FUN_004a9930(this_02);
    }
    else {
      if (iVar20 == 6) {
        S112_FUN_004ab8c0(this);
      }
      pS49_1 = _pS49_2;
      pS110 = this->s110;
      if (pS110->field22_0x28 == 5) {
        if (((pS110->car != (Car *)0x0) &&
            (pEVar5 = pS110->car->EngineStruct, pEVar5 != (EngineStruct *)0x0))
           && (cVar13 = pEVar5->field_0x28, '\0' < cVar13)) {
          JuncIds::S91_FUN_0040cb60(gJuncIds,(short)cVar13);
          this->s110->car->EngineStruct->field_0x28 = 0xff;
        }
        S112_FUN_004a9930(this);
        if (this->field19_0x29 != 0) {
          if (_gPolice->count != 0) {
            _gPolice->count = _gPolice->count - 1;
          }
          this->field19_0x29 = 0;
        }
        pS49_1 = this->s110->pPed;
        if (pS49_1 != (Ped *)0x0) {
          Ped::sPed_FUN_0043ec30(pS49_1);
        }
        this->s110->field22_0x28 = 0;
        S110::S110_FUN_004c5480(this->s110);
        S112_FUN_004a96d0(this);
        return;
      }
      piVar23 = (int *)this->field11_0x14;
      if (piVar23 != (int *)0x0) {
        if (pS110->field21_0x24 == 2) {
          return;
        }
        if (((*piVar23 != 0) && (bVar12 = S112_FUN_004ab930(this), bVar12 != 0))
           && ((pS110->field20_0x20 == 6 ||
               ((piVar23[1] != 6 && (piVar23[1] != 0)))))) {
          iVar20 = Ped__GetActionParam(pS49_1);
          if ((iVar20 == 0x23) &&
             (uVar21._0_1_ = pS49_1->flags, uVar21._1_1_ = pS49_1->uns59,
             uVar21._2_1_ = pS49_1->uns60, uVar21._3_1_ = pS49_1->uns61,
             (uVar21 & 0x8000000) == 0)) {
            local_20[0] = 3;
            local_20[1] = 0xd0;
            local_20[2] = 0x4a;
            local_20[3] = 0;
            Ped::SetAnimationState(pS49_1,0,9999);
            local_20[0] = 0x15;
            local_20[1] = 0xd0;
            local_20[2] = 0x4a;
            local_20[3] = 0;
            Ped::PedSetObjective(_pS49_2,0,9999);
          }
          puVar15 = (undefined4 *)this->field11_0x14;
          puVar17 = (undefined4 *)
                    Ped__GetXCoordinate((Ped *)*puVar15,(int)&stack0xfffffffc);
          puVar15[4] = *puVar17;
          puVar15 = (undefined4 *)this->field11_0x14;
          puVar17 = (undefined4 *)
                    Ped__GetYCoordinate((Ped *)*puVar15,(int)&stack0xfffffffc);
          puVar15[5] = *puVar17;
          puVar15 = (undefined4 *)this->field11_0x14;
          puVar17 = (undefined4 *)
                    Ped::GetPositionZ((Ped *)*puVar15,(int)&stack0xfffffffc);
          puVar15[6] = *puVar17;
          local_20[0] = 0x61;
          local_20[1] = 0xd0;
          local_20[2] = 0x4a;
          local_20[3] = 0;
          Police::S111_FUN_004aab90(_gPolice,this,this->field11_0x14);
          return;
        }
      }
      if (((pS110->field21_0x24 != 2) && (pS49_1 != (Ped *)0x0)) &&
         (Ped__Initialize(pS49_1), _pS49_2 != (Ped *)0x0)) {
        do {
          pS49_1 = _pS49_2;
          if ((_pS49_2->CurrentState != PEDSTATE_DEAD) &&
             (_pS49_2->field130_0x28c == 1)) {
            uVar18 = Ped__GetActionParam(_pS49_2);
            switch(uVar18) {
            case 0:
              pS110 = this->s110;
              if (pS49_1 == pS110->pPed) {
                if (pS49_1->CarCurrent == (Car *)0x0) {
                  if ((pS110->field21_0x24 == 1) &&
                     (uVar9._0_1_ = pS49_1->flags, uVar9._1_1_ = pS49_1->uns59,
                     uVar9._2_1_ = pS49_1->uns60, uVar9._3_1_ = pS49_1->uns61,
                     (uVar9 & 0x8000000) == 0)) {
                    local_20[0] = 0x9f;
                    local_20[1] = 0xd1;
                    local_20[2] = 0x4a;
                    local_20[3] = 0;
                    Ped::SetAnimationState(pS49_1,0,9999);
                    local_20[0] = 0xb1;
                    local_20[1] = 0xd1;
                    local_20[2] = 0x4a;
                    local_20[3] = 0;
                    Ped::PedSetObjective(_pS49_2,0x23,9999);
                    Ped__EnterCar(_pS49_2,this->s110->car);
                    Ped__UpdateState(_pS49_2);
                  }
                }
                else if ((pS110->S169 == (S169 *)0x0) ||
                        (bVar11 = S169::FUN_00404840(pS110->S169),
                        pS49_1 = _pS49_2, bVar11)) {
                  local_20[0] = 0x3d;
                  local_20[1] = 0xd1;
                  local_20[2] = 0x4a;
                  local_20[3] = 0;
                  Ped::SetAnimationState(pS49_1,0,9999);
                  local_20[0] = 0x4f;
                  local_20[1] = 0xd1;
                  local_20[2] = 0x4a;
                  local_20[3] = 0;
                  Ped::PedSetObjective(_pS49_2,0x2b,9999);
                  Car::CarMakeDummy(_pS49_2->CarCurrent);
                  Car::FUN_004222d0(_pS49_2->CarCurrent);
                  DAT_0066b79c = 0;
                }
              }
              break;
            default:
switchD_004ad0ca_caseD_1:
              local_20[0] = 0xfa;
              local_20[1] = 0xd1;
              local_20[2] = 0x4a;
              local_20[3] = 0;
              Ped::SetAnimationState(pS49_1,0,9999);
              local_20[0] = 0xc;
              local_20[1] = 0xd2;
              local_20[2] = 0x4a;
              local_20[3] = 0;
              Ped::PedSetObjective(_pS49_2,0,9999);
              break;
            case 8:
            case 0x1b:
            case 0x22:
            case 0x2b:
            case 0x32:
              break;
            case 0xe:
            case 0x34:
              local_20[0] = 0xdf;
              local_20[1] = 0xd0;
              local_20[2] = 0x4a;
              local_20[3] = 0;
              Ped::SetAnimationState(pS49_1,0,9999);
              local_20[0] = 0xf1;
              local_20[1] = 0xd0;
              local_20[2] = 0x4a;
              local_20[3] = 0;
              Ped::PedSetObjective(_pS49_2,0x2b,9999);
              DAT_0066b79c = 0;
              break;
            case 0x1c:
              cVar13 = Ped::S49_FUN_00450cb0(pS49_1);
              if (cVar13 != '\0') goto switchD_004ad0ca_caseD_1;
              break;
            case 0x23:
              S112_FUN_004ab9d0(this);
              break;
            case 0x24:
              S112_FUN_004aba30(this);
            }
          }
          pSVar16 = this->s110->S169;
          if (pSVar16 == (S169 *)0x0) {
            _pS49_2 = (Ped *)0x0;
          }
          else {
            _pS49_2 = pSVar16->Ped_Arr9[bVar22];
          }
          bVar22 = bVar22 + 1;
          if (_pS49_2 == (Ped *)0x0) {
            return;
          }
        } while( true );
      }
    }
    return;
  }
  bVar11 = true;
  bVar10 = false;
  local_24 = local_24 & 0xffffff00;
  if (*(int *)this->field11_0x14 == 0) {
    this->select = 6;
    S112_FUN_004a9930(this);
    return;
  }
  pS110 = this->s110;
  if (pS110->field22_0x28 == 3) {
    if (pS110->field23_0x2c == 0) {
      bVar11 = false;
      if (pS110->field15_0x18 == -0x50) {
LAB_004ac657:
        this->select = 6;
        S112_FUN_004a9930(this);
      }
    }
    else if (gChar->field4_0x5 < 0x1a) {
      if (pS110->field20_0x20 == 3) {
        FUN_004aadd0(unaff_EDI);
      }
      else if (pS110->field20_0x20 == 5) {
        FUN_004ab060(this);
      }
      _pS49_2 = this->s110->pPed;
      this->field_0x1a = 0;
    }
    else if (pS110->car != (Car *)0x0) {
      Car::Car_FUN_00421470(pS110->car);
      this->s110->car = (Car *)0x0;
      goto LAB_004ac657;
    }
LAB_004ac661:
    if (this->select == 6) {
      return;
    }
  }
  else {
    if (pS110->field22_0x28 != 6) goto LAB_004ac661;
    S112_FUN_004ab8c0(this);
    if ((this->s110->field22_0x28 == 5) || (this->select == 6)) {
      this->select = 6;
      S112_FUN_004a9930(this);
      return;
    }
  }
  if (bVar11) {
    pS49_1 = this->s110->pPed;
    _pS49_2 = pS49_1;
    bVar22 = S112_FUN_004ab930(this);
    if (bVar22 == 0) {
      puVar15 = (undefined4 *)this->field11_0x14;
      if (*(short *)(puVar15 + 3) == 0) {
        if (this->s110->field21_0x24 != 0) {
          this->select = 3;
          return;
        }
        goto LAB_004acdda;
      }
      if (this->s110->field21_0x24 == 0) goto LAB_004acdda;
      if (((Ped *)*puVar15)->CarCurrent != (Car *)0x0) {
        puVar17 = (undefined4 *)Ped__GetXCoordinate((Ped *)*puVar15,(int)local_20)
        ;
        puVar15[4] = *puVar17;
        puVar15 = (undefined4 *)this->field11_0x14;
        puVar17 = (undefined4 *)Ped__GetYCoordinate((Ped *)*puVar15,(int)local_20)
        ;
        puVar15[5] = *puVar17;
        puVar15 = (undefined4 *)this->field11_0x14;
        puVar17 = (undefined4 *)Ped::GetPositionZ((Ped *)*puVar15,(int)local_20)
        ;
        puVar15[6] = *puVar17;
        pS49_1 = _pS49_2;
      }
    }
    else {
      puVar15 = (undefined4 *)this->field11_0x14;
      puVar17 = (undefined4 *)Ped__GetXCoordinate((Ped *)*puVar15,(int)local_20);
      puVar15[4] = *puVar17;
      puVar15 = (undefined4 *)this->field11_0x14;
      puVar17 = (undefined4 *)Ped__GetYCoordinate((Ped *)*puVar15,(int)local_20);
      puVar15[5] = *puVar17;
      puVar15 = (undefined4 *)this->field11_0x14;
      puVar17 = (undefined4 *)Ped::GetPositionZ((Ped *)*puVar15,(int)local_20);
      puVar15[6] = *puVar17;
      pS49_1 = _pS49_2;
    }
    if (*(short *)(this->field11_0x14 + 0xc) == 0) {
      Ped::SetAnimationState(pS49_1,0,9999);
      Ped::PedSetObjective(_pS49_2,0,9999);
LAB_004acdda:
      this->select = 6;
      S112_FUN_004a9930(this);
      return;
    }
    if (pS49_1 != (Ped *)0x0) {
      do {
        if ((pS49_1->CurrentState != PEDSTATE_DEAD) &&
           (pS49_1->field130_0x28c == 1)) {
          uVar18 = Ped__GetActionParam(pS49_1);
          switch(uVar18) {
          case 0:
            pS110 = this->s110;
            if (pS49_1 == pS110->pPed) {
              if (pS49_1->CarCurrent == (Car *)0x0) {
                if ((this->field_0x28 == '\0') || (pS110->field21_0x24 != 1)) {
                  uVar2._0_1_ = pS49_1->flags;
                  uVar2._1_1_ = pS49_1->uns59;
                  uVar2._2_1_ = pS49_1->uns60;
                  uVar2._3_1_ = pS49_1->uns61;
                  if ((uVar2 & 0x8000000) == 0) {
                    Ped::SetAnimationState(pS49_1,0,9999);
                    Ped::PedSetObjective(_pS49_2,0x14,9999);
                    Ped__SetAsDriver(_pS49_2,*(undefined4 *)this->field11_0x14)
                    ;
                    Ped__UpdateState(_pS49_2);
                    this->field_0x28 = 0;
                    this->field_0x35 = 0;
                  }
                }
                else {
                  uVar1._0_1_ = pS49_1->flags;
                  uVar1._1_1_ = pS49_1->uns59;
                  uVar1._2_1_ = pS49_1->uns60;
                  uVar1._3_1_ = pS49_1->uns61;
                  if ((uVar1 & 0x8000000) == 0) {
                    Ped::SetAnimationState(pS49_1,0,9999);
                    Ped::PedSetObjective(_pS49_2,0x23,9999);
                    Ped__EnterCar(_pS49_2,this->s110->car);
                    Ped__UpdateState(_pS49_2);
                  }
                }
              }
              else if (*(int *)(*(int *)this->field11_0x14 + 0x16c) == 0) {
                Ped::SetAnimationState(pS49_1,0,9999);
                Ped::PedSetObjective(_pS49_2,0x24,9999);
                Ped__EnterCar(_pS49_2,this->s110->car);
                this->field_0x28 = 0;
              }
              else if ((pS110->S169 == (S169 *)0x0) ||
                      (cVar13 = PathFind_CalculateRoute(), pS49_1 = _pS49_2, cVar13 != '\0'
                      )) {
                Ped::SetAnimationState(pS49_1,0,9999);
                goto LAB_004ac8bd;
              }
            }
            else {
              iVar20 = Ped__GetLinkedPed(pS49_1);
              if ((iVar20 == this->field24_0x30) &&
                 (iVar20 = Ped__GetLinkedPed(pS49_1), iVar20 != 0)) {
                Ped__SetLinkedPedestrian(pS49_1,*(undefined4 *)this->field11_0x14);
              }
            }
            break;
          case 2:
            DAT_0066b79c = 0;
            FUN_004a97c0(this);
            break;
          case 0xc:
          case 0x33:
switchD_004ac782_caseD_c:
LAB_004aca8e:
            Ped::SetAnimationState(pS49_1,0,9999);
            Ped::PedSetObjective(_pS49_2,0,9999);
            break;
          case 0xe:
            if (pS49_1 == this->s110->pPed) {
              pSVar16 = this->s110->S169;
              if (pSVar16 == (S169 *)0x0) {
                Ped::SetAnimationState(pS49_1,0,9999);
                Ped::PedSetObjective(_pS49_2,0x34,9999);
                uVar18 = *(undefined4 *)this->field11_0x14;
              }
              else {
                bVar11 = S169::FUN_00404840(pSVar16);
                if (!bVar11) {
                  Ped::SetAnimationState(_pS49_2,0,9999);
                  Ped::PedSetObjective(_pS49_2,0,9999);
                  this->field_0x28 = 1;
                  break;
                }
                Ped::SetAnimationState(_pS49_2,0,9999);
                Ped::PedSetObjective(_pS49_2,0x34,9999);
                uVar18 = *(undefined4 *)this->field11_0x14;
              }
              Ped__SetAsDriver(_pS49_2,uVar18);
              this->field_0x28 = 1;
            }
            this->field_0x28 = 1;
            break;
          case 0x14:
          case 0x20:
            iVar20 = Ped__GetLinkedPed(pS49_1);
            iVar14 = Ped__GetPassenger(pS49_1);
            if (iVar14 == iVar20) {
              uVar18 = Ped__GetPassenger(pS49_1);
              this->field24_0x30 = uVar18;
              Ped__SetLinkedPedestrian(_pS49_2,*(undefined4 *)this->field11_0x14);
              pS49_1 = _pS49_2;
            }
            Ped__SetAsDriver(pS49_1,*(undefined4 *)this->field11_0x14);
            pS49_1 = _pS49_2;
            cVar13 = Ped::S49_FUN_00450cb0(_pS49_2);
            if (cVar13 == '\x01') {
              DAT_0066b79c = 0;
            }
            else {
              cVar13 = Ped::S49_FUN_00450cb0(pS49_1);
              if (cVar13 == '\x02') goto switchD_004ac782_caseD_c;
              piVar23 = (int *)this->field11_0x14;
              if ((Ped *)*piVar23 == (Ped *)0x0) {
                puVar15 = (undefined4 *)
                          WorldCoordinateToScreenCoord
                                    (&DAT_0066bb2c,&stack0xfffffff4,
                                     (int *)&DAT_0066bab0);
                this->field8_0x8 = *puVar15;
              }
              else {
                pS110 = (S110 *)Ped__GetYCoordinate((Ped *)*piVar23,(int)local_20)
                ;
                pS110_00 = (S110 *)Ped__GetXCoordinate((Ped *)*piVar23,
                                                     (int)&stack0xffffffe4);
                piVar19 = (int *)Ped__GetYCoordinate(pS49_1,(int)&stack0xffffffe8)
                ;
                pS110_4 = (S110 *)Ped__GetXCoordinate(pS49_1,(int)&local_14);
                puVar15 = &local_10;
                FUN_0042a6b0(this_01,puVar15,pS110_4,piVar19,pS110_00,pS110);
                this->field8_0x8 = *puVar15;
              }
              if (this->s110->field21_0x24 == 1) {
                bVar11 = S169::FUN_00403800((S169 *)&this->field8_0x8,
                                            (int *)&DAT_0066bb2c);
                if (CONCAT31(extraout_var_01,bVar11) != 0) goto LAB_004acb79;
                if (*(Car **)(*piVar23 + 0x16c) != (Car *)0x0) {
                  piVar19 = (int *)&DAT_0066b7bc;
                  pSVar16 = (S169 *)Car::Car_FUN_00421d90
                                              (*(Car **)(*piVar23 + 0x16c),
                                               (Car *)&stack0xfffffff8);
                  bVar11 = S169::FUN_00403800(pSVar16,piVar19);
                  if (CONCAT31(extraout_var_02,bVar11) == 0) {
                    bVar11 = S169::FUN_00403800((S169 *)&this->field8_0x8,
                                                (int *)&DAT_0066b840);
                    if (CONCAT31(extraout_var_03,bVar11) != 0)
                    goto LAB_004acb79;
                    bVar10 = true;
                  }
                  else {
                    bVar22 = this->field_0x35 + 1;
                    this->field_0x35 = bVar22;
                    if (0x1e < bVar22) {
LAB_004acb79:
                      pS49_1 = _pS49_2;
                      iVar20 = Ped__GetActionParam(_pS49_2);
                      if (((iVar20 != 0x20) ||
                          (iVar20 = Ped__GetPedState(pS49_1), iVar20 == 1))
                         && (uVar7._0_1_ = pS49_1->flags,
                            uVar7._1_1_ = pS49_1->uns59,
                            uVar7._2_1_ = pS49_1->uns60,
                            uVar7._3_1_ = pS49_1->uns61,
                            (uVar7 & 0x8000000) == 0)) {
                        Ped::SetAnimationState(pS49_1,0,9999);
                        Ped::PedSetObjective(_pS49_2,0x23,9999);
                        Ped__EnterCar(_pS49_2,this->s110->car);
                        Ped__UpdateState(_pS49_2);
                        this->field_0x28 = 1;
                      }
                      break;
                    }
                  }
                }
              }
              pS49_1 = _pS49_2;
              iVar20 = Ped__GetActionParam(_pS49_2);
              if (iVar20 == 0x20) {
                if ((*(int *)(*(int *)this->field11_0x14 + 0x168) != 0) &&
                   (uVar8._0_1_ = pS49_1->flags, uVar8._1_1_ = pS49_1->uns59,
                   uVar8._2_1_ = pS49_1->uns60, uVar8._3_1_ = pS49_1->uns61,
                   (uVar8 & 0x8000000) != 0)) {
                  Ped::SetAnimationState(pS49_1,0,9999);
                  Ped::PedSetObjective(_pS49_2,0x14,9999);
                  Ped__SetAsDriver(_pS49_2,*(undefined4 *)this->field11_0x14);
                  Ped__UpdateState(_pS49_2);
                  this->field_0x28 = 0;
                }
              }
              else if (bVar10) {
                Ped::PedSetObjective(pS49_1,0x20,9999);
                Ped__SetAsDriver(_pS49_2,*(undefined4 *)this->field11_0x14);
                Ped__UpdateState(_pS49_2);
              }
            }
            break;
          case 0x1b:
            piVar23 = (int *)&DAT_0066ba64;
            this_00 = (Player *)
                      Car::Car_FUN_00421d90
                                (this->s110->car,(Car *)&stack0xfffffffc);
            bVar11 = Player::CheckCondition(this_00,piVar23);
            if (CONCAT31(extraout_var_04,bVar11) != 0) {
              Ped::PedSetObjective(_pS49_2,0x24,9999);
              Ped__EnterCar(_pS49_2,_pS49_2->CarCurrent);
            }
            break;
          case 0x1c:
            cVar13 = Ped::S49_FUN_00450cb0(pS49_1);
            if (cVar13 != '\0') goto switchD_004ac782_caseD_c;
            break;
          case 0x23:
            S112_FUN_004ab9d0(this);
            this->field_0x28 = 1;
            break;
          case 0x24:
            S112_FUN_004aba30(this);
            this->field_0x28 = 0;
            break;
          case 0x2b:
            Ped::SetAnimationState(pS49_1,0,9999);
            pSVar16 = this->s110->S169;
            if (pSVar16 == (S169 *)0x0) {
LAB_004ac8bd:
              Ped::PedSetObjective(_pS49_2,0x34,9999);
              Ped__SetAsDriver(_pS49_2,*(undefined4 *)this->field11_0x14);
              this->field_0x28 = 1;
            }
            else {
              bVar11 = S169::FUN_00404840(pSVar16);
              if (bVar11) {
                Ped::PedSetObjective(_pS49_2,0x34,9999);
                Ped__SetAsDriver(_pS49_2,*(undefined4 *)this->field11_0x14);
                this->field_0x28 = 1;
              }
              else {
                Ped::PedSetObjective(_pS49_2,0,9999);
              }
            }
            break;
          case 0x34:
            this->field_0x28 = 1;
            pS49_1 = _pS49_2;
            if ((this->s110->car == (Car *)0x0) ||
               ((this->s110->S169 != (S169 *)0x0 &&
                (cVar13 = PathFind_CalculateRoute(), pS49_1 = _pS49_2, cVar13 == '\0'))))
            goto LAB_004aca8e;
            FUN_004abae0();
            this->field_0x28 = 1;
          }
        }
        pSVar16 = this->s110->S169;
        if (pSVar16 == (S169 *)0x0) {
          pS49_1 = (Ped *)0x0;
        }
        else {
          pS49_1 = pSVar16->Ped_Arr9[local_24 & 0xff];
        }
        _pS49_2 = pS49_1;
        local_24 = CONCAT31(local_24._1_3_,(char)local_24 + '\x01');
        if (pS49_1 == (Ped *)0x0) {
          return;
        }
      } while( true );
    }
  }
  return;
}


