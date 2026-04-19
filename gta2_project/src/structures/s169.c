// Module: S169
// Functions working with structure S169
// Generated from gta2.exe.c

#include "../../include/common.h"

undefined1 __thiscall S169__AreAnyPedActive(S169 *this)

{
  byte bVar1;
  uint local_4;
  
  bVar1 = 0;
  local_4 = 0;
  if (this->Index != 0) {
    do {
      if (this->Ped_Arr9[local_4]->CarCurrent != (Car *)0x0) {
        return 0;
      }
      bVar1 = bVar1 + 1;
      local_4 = (uint)bVar1;
    } while (bVar1 < this->Index);
  }
  return 1;
}


bool __thiscall S169__FUN_00403800(S169 *this,int *param_1)

{
  int iVar1;
  
  iVar1._0_1_ = this->field0_0x0;
  iVar1._1_1_ = this->field1_0x1;
  iVar1._2_1_ = this->field2_0x2;
  iVar1._3_1_ = this->field3_0x3;
  return *param_1 < iVar1;
}


bool __thiscall S169__FUN_004038f0(S169 *this)

{
  return (bool)this->field17_0x40;
}


void __thiscall S169__FUN_00403be0(S169 *this)

{
  AutoClass4 *pS49;
  int iVar1;
  
  this->field17_0x40 = 0;
  this->field15_0x38 = 2;
  this->field10_0x30 = 0;
  this->field13_0x36 = 0;
  this->Index = 0;
  if (this->Ped != (Ped *)0x0) {
    Ped::SetDefault(this->Ped);
  }
  this->Ped = (Ped *)0x0;
  this->field0_0x0 = 1;
  this->field1_0x1 = 0;
  this->Index = 0;
  this->field12_0x35 = 0;
  pS49 = (AutoClass4 *)this->Ped_Arr9;
  iVar1 = 9;
  do {
    if (*(Ped **)pS49 != (Ped *)0x0) {
      Ped::SetDefault(*(Ped **)pS49);
    }
    pS49->field0_0x0 = 0;
    pS49->field1_0x1 = 0;
    *(undefined2 *)&pS49->field_0x2 = 0;
    pS49 = (AutoClass4 *)pS49->Ped;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}


byte __thiscall S169__S169_FUN_00403c40(S169 *this)

{
  ushort uVar1;
  byte bVar2;
  uint index;
  
  if ((this->Ped->GameObject == (GameObject *)0x0) ||
     (uVar1 = Ped::S49_FUN_004039f0(this->Ped), uVar1 < 0x28)) {
    return 0;
  }
  bVar2 = 0;
  index = 0;
  if (this->Index != 0) {
    do {
      if (this->Ped_Arr9[index]->GameObject == (GameObject *)0x0) {
        return 0;
      }
      uVar1 = Ped::S49_FUN_004039f0(this->Ped_Arr9[index]);
      if (uVar1 < 0x28) {
        return 0;
      }
      bVar2 = bVar2 + 1;
      index = (uint)bVar2;
    } while (bVar2 < this->Index);
  }
  return 1;
}


void __thiscall S169__FUN_00403da0(S169 *this)

{
  Ped *this_00;
  byte bVar1;
  int iVar2;
  byte bVar3;
  uint local_4;
  void *piVar1;
  
  if (this->field17_0x40 == 0) {
    return;
  }
  Ped::SetDefault(this->Ped);
  if (this->Ped_Arr9[0] != (Ped *)0x0) {
    bVar3 = 0;
    local_4 = 0;
    if (this->Index != 0) {
      do {
        this_00 = this->Ped_Arr9[local_4];
        piVar1 = this->Ped_Arr9 + local_4;
        iVar2 = Ped::GetCurrentState(this_00);
        if ((iVar2 == 9) || (this_00->SavedState == PEDSTATE_DEAD)) {
          Ped::SetDefault(this_00);
        }
        else {
          bVar1 = Ped::IsInCar(this_00);
          if (bVar1 == 1) {
            Ped::PedSetObjective(this_00,0x22,9999);
                              // WARNING: Load size is inaccurate
            Ped::S49_FUN_00403aa0(*piVar1,(*piVar1)->CarCurrent);
          }
          else {
            Ped::PedSetObjective(this_00,0,9999);
          }
                              // WARNING: Load size is inaccurate
          Ped::SetAnimationState(*piVar1,0,9999);
                              // WARNING: Load size is inaccurate
          Ped::SetDefault(*piVar1);
                              // WARNING: Load size is inaccurate
          Ped::SetSearchType(*piVar1,3);
        }
                              // WARNING: Load size is inaccurate
        bVar3 = bVar3 + 1;
        *(uint *)(*piVar1 + 0x21c) = *(uint *)(*piVar1 + 0x21c) | 0x400;
        local_4 = (uint)bVar3;
      } while (bVar3 < this->Index);
    }
  }
  FUN_00403be0(this);
  return;
}


void __thiscall S169__FUN_00403e90(S169 *this)

{
  Ped **ppPVar1;
  byte bVar2;
  int iVar3;
  byte bVar4;
  uint local_4;
  Ped *pPed;
  
  if (this->field17_0x40 == 0) {
    return;
  }
  pPed = this->Ped;
  iVar3 = Ped::GetCurrentState(pPed);
  if ((iVar3 != 9) && (pPed->SavedState != PEDSTATE_DEAD)) {
    Ped::PedSetObjective(pPed,0,9999);
    Ped::SetAnimationState(this->Ped,0,9999);
  }
  Ped::SetDefault(this->Ped);
  if (this->Ped_Arr9[0] != (Ped *)0x0) {
    bVar4 = 0;
    local_4 = 0;
    if (this->Index != 0) {
      do {
        pPed = this->Ped_Arr9[local_4];
        ppPVar1 = this->Ped_Arr9 + local_4;
        iVar3 = Ped::GetCurrentState(pPed);
        if ((iVar3 == 9) || (pPed->SavedState == PEDSTATE_DEAD)) {
          Ped::SetDefault(pPed);
        }
        else {
          bVar2 = Ped::IsInCar(pPed);
          if (bVar2 == 1) {
            Ped::SetAnimationState(pPed,0,9999);
            Ped::PedSetObjective(*ppPVar1,0x22,9999);
            Ped::S49_FUN_00403aa0(*ppPVar1,(*ppPVar1)->CarCurrent);
          }
          else {
            Ped::PedSetObjective(pPed,0,9999);
            Ped::SetAnimationState(*ppPVar1,0,9999);
          }
          Ped::SetDefault(*ppPVar1);
          Ped::SetSearchType(*ppPVar1,3);
        }
        bVar4 = bVar4 + 1;
        local_4 = (uint)bVar4;
      } while (bVar4 < this->Index);
    }
  }
  FUN_00403be0(this);
  return;
}


void __thiscall S169__FUN_00403fb0(S169 *this,int param_1)

{
  int linkedPed;
  bool bVar1;
  byte bVar2;
  int iVar3;
  Ped *pS49;
  
  linkedPed = param_1;
  if (param_1 != 0) {
    bVar1 = Ped::HasSearchType(this->Ped,SEARCHTYPE_LINE_OF_SIGHT_PLAYER_ONLY);
    if (!bVar1) {
      Ped::PedSetObjective(this->Ped,3,9999);
      Ped::SetDriverPed(this->Ped,param_1);
      Ped::SetAnimationState(this->Ped,3,9999);
      Ped::SetLinkedPed(this->Ped,param_1);
      Ped::S49_Set_FUN_00403950(this->Ped);
      Ped::SetDefaut_Pararam0x228(this->Ped);
      Ped::S49_FUN_00403a50(this->Ped,DAT_005d2e28);
    }
    Ped::SetDefault(this->Ped);
    param_1 = 0;
    if (this->Index != 0) {
      iVar3 = 0;
      do {
        pS49 = this->Ped_Arr9[iVar3];
        bVar2 = Ped::IsInCar(pS49);
        if (bVar2 == 1) {
          Ped::SetAnimationState(pS49,0,9999);
          Ped::PedSetObjective(this->Ped_Arr9[iVar3],6,9999);
          Ped::SetDriverPed(this->Ped_Arr9[iVar3],linkedPed);
          Ped::SetDefaut_Pararam0x228(this->Ped_Arr9[iVar3]);
          Ped::SetDefault(this->Ped_Arr9[iVar3]);
        }
        else {
          Ped::PedSetObjective(pS49,3,9999);
          Ped::SetDriverPed(this->Ped_Arr9[iVar3],linkedPed);
          Ped::SetAnimationState(this->Ped_Arr9[iVar3],3,9999);
          Ped::SetLinkedPed(this->Ped_Arr9[iVar3],linkedPed);
          Ped::S49_Set_FUN_00403950(this->Ped_Arr9[iVar3]);
          Ped::SetDefaut_Pararam0x228(this->Ped_Arr9[iVar3]);
          Ped::S49_FUN_00403a50(this->Ped_Arr9[iVar3],DAT_005d2e28);
          Ped::SetDefault(this->Ped_Arr9[iVar3]);
          Ped::SetSearchType(this->Ped_Arr9[iVar3],3);
        }
        iVar3 = (int)(char)((char)param_1 + 1U);
        param_1 = (int)(byte)((char)param_1 + 1U);
      } while (iVar3 < (int)(uint)this->Index);
    }
    FUN_00403be0(this);
    return;
  }
  FUN_00403e90(this);
  return;
}


void __thiscall S169__FUN_00404120(S169 *this,byte index)

{
  Weapon *pWVar1;
  Weapon *pWVar2;
  undefined1 uVar3;
  ushort timer;
  undefined2 uVar4;
  Ped *pPed;
  int iVar5;
  undefined2 extraout_var;
  undefined4 uVar6;
  uint Index;
  GameObject *pGameGameObject;
  Ped *pS49_1;
  Weapon *pWeapon;
  Weapon *pWeapon1;
  
  pPed = PedManager::S48_FUN_00403890(gPedManager);
  pS49_1 = this->Ped;
  Index = (uint)index;
  pWVar1 = pS49_1->SelectedWeapon;
  pWeapon = this->Ped_Arr9[Index]->SelectedWeapon;
  pWeapon1 = this->Ped_Arr9[Index]->Weapon1;
  pWVar2 = pS49_1->Weapon1;
  Ped::CopyPed(pPed,pS49_1);
  Ped::CopyPed(this->Ped,this->Ped_Arr9[Index]);
  this->Ped->SelectedWeapon = pWVar1;
  this->Ped->Weapon1 = pWVar2;
  timer = Ped::S49_Get_FUN_00403b30(pPed);
  iVar5 = Ped::S49_Get_FUN_00403a80(pPed);
  Ped::PedSetObjective(this->Ped,iVar5,timer);
  uVar4 = Ped::S49_Get_FUN_00403b20(pPed);
  iVar5 = CONCAT22(extraout_var,uVar4);
  uVar6 = Ped::GetCurrentAction(pPed);
  Ped::SetAnimationState(this->Ped,uVar6,iVar5);
  uVar3 = Ped::S49_Get_FUN_004039e0(pPed);
  Ped::SetCarDamageState(this->Ped,uVar3);
  uVar3 = Ped::S49_Get_FUN_004039d0(pPed);
  Ped::SetExitAnimState(this->Ped,uVar3);
  uVar6 = Ped::S49_Get_FUN_00403ad0(pPed);
  Ped::SetDriverPed(this->Ped,uVar6);
  uVar6 = Ped::GetCarPed(pPed);
  Ped::S49_FUN_00403aa0(this->Ped,uVar6);
  this->Ped->uns21 = pPed->uns21;
  this->Ped->uns22 = pPed->uns22;
  this->Ped->Car_1 = pPed->Car_1;
  this->Ped->Car_2 = pPed->Car_2;
  this->Ped->uns40 = pPed->uns40;
  uVar6 = Ped::GetPed(pPed);
  Ped::SetLinkedPed(this->Ped,uVar6);
  uVar6 = Ped::GetCurrentCar(pPed);
  Ped::SetObjectiveTargetCar(this->Ped,uVar6);
  this->Ped->uns35 = pPed->uns35;
  this->Ped->uns36 = pPed->uns36;
  this->Ped->SpriteS1 = pPed->SpriteS1;
  Ped::SetCarId(this->Ped,99);
  uVar6 = Ped::S49_Get_FUN_004039c0(pPed);
  Ped::SetTargetCarDoor(this->Ped,uVar6);
  uVar3 = Ped::S49_Get_FUN_00403a60(pPed);
  Ped::S49_FUN_00403a70(this->Ped,uVar3);
  pS49_1 = this->Ped;
  if (pS49_1->GameObject == (GameObject *)0x0) {
    iVar5 = Ped::S49_Get_FUN_004039c0(pS49_1);
    if ((iVar5 == 0) && (pS49_1->CarCurrent->Driver != pS49_1)) {
      Ped::SetTargetCarDoor(pS49_1,1);
    }
  }
  else {
    pS49_1->GameObject->Ped = pS49_1;
  }
  Ped::CopyPed(this->Ped_Arr9[Index],pPed);
  Ped::SetCarId(this->Ped_Arr9[Index],index);
  this->Ped_Arr9[Index]->SelectedWeapon = pWeapon;
  this->Ped_Arr9[Index]->Weapon1 = pWeapon1;
  pGameGameObject = this->Ped_Arr9[Index]->GameObject;
  if (pGameGameObject != (GameObject *)0x0) {
    iVar5 = Ped::GetOccupation(this->Ped_Arr9[Index]);
    if (iVar5 == 0x17) {
      pGameGameObject->Ped = this->Ped_Arr9[Index];
      Ped::SetTargetCarDoor(this->Ped_Arr9[Index],1);
      goto LAB_004043b1;
    }
  }
  if (pGameGameObject != (GameObject *)0x0) {
    pGameGameObject->Ped = this->Ped_Arr9[Index];
  }
  if ((int)Index < (int)(this->Index - 1)) {
    Ped::SetDefault(this->Ped_Arr9[Index]);
    pS49_1 = this->Ped_Arr9[this->Index - 1];
    this->Ped_Arr9[Index] = pS49_1;
    Ped::SetCarId(pS49_1,index);
  }
  else {
    this->Ped_Arr9[Index]->pS169 = (S169 *)0x0;
    this->Ped_Arr9[Index] = (Ped *)0x0;
  }
  this->Index = this->Index - 1;
  Ped::SetCarId(this->Ped,99);
LAB_004043b1:
  if (pPed->SearchType == (SEARCHTYPE_AREA_PLAYER_ONLY|SEARCHTYPE_LINE_OF_SIGHT)
     ) {
    Ped::CleanupAndUpdateOccupationCounts(pPed);
    Index._0_1_ = pPed->flags;
    Index._1_1_ = pPed->uns59;
    Index._2_1_ = pPed->uns60;
    Index._3_1_ = pPed->uns61;
    Index = Index | 0x400;
    pPed->flags = (char)Index;
    pPed->uns59 = (char)(Index >> 8);
    pPed->uns60 = (char)(Index >> 0x10);
    pPed->uns61 = (char)(Index >> 0x18);
  }
  else {
    Ped::CleanupAndUpdateOccupationCounts(pPed);
  }
  Ped::SetHealthPlayer(pPed,100);
  Ped::SetOccupation(pPed,2);
  Ped::S49_FUN_004411b0(pPed);
  return;
}


undefined4 __thiscall S169__FUN_00404450(S169 *this)

{
  byte bVar1;
  PedFlags PVar2;
  
  bVar1 = this->Index;
  do {
    bVar1 = bVar1 - 1;
    if ((char)bVar1 < '\0') {
      return 0;
    }
    PVar2 = Ped::IsCrouching(this->Ped_Arr9[(char)bVar1]);
  } while (PVar2 != 0);
  return this->Ped_Arr9[(char)bVar1];
}


void __thiscall S169__FUN_00404480(S169 *this)

{
  Ped::IsCrouching(this->Ped);
  return;
}


Ped * __thiscall S169__FUN_00404490(S169 *this,int *param_1)

{
  byte bVar1;
  Ped *this_00;
  Ped *pPVar2;
  bool bVar3;
  undefined4 *puVar4;
  void *pvVar5;
  int *piVar6;
  undefined3 extraout_var;
  Ped **ppPVar7;
  undefined3 extraout_var_00;
  byte bVar8;
  Ped **ppPVar9;
  Ped *local_34;
  Ped *local_30;
  Ped *local_2c;
  byte local_28;
  undefined3 uStack_27;
  S169 *local_24;
  undefined1 local_20 [4];
  undefined1 local_1c [8];
  undefined1 local_14 [4];
  undefined1 local_10 [8];
  int local_8;
  int local_4;
  
  bVar8 = 0;
  local_24 = this;
  bitShiftLeft1(&local_2c,(void *)0x0);
  bVar1 = this->Index;
  _local_28 = (Ped *)((uint)_local_28 & 0xffffff00);
  if (bVar1 != 0) {
    this_00 = this->Ped;
    ppPVar9 = this->Ped_Arr9;
    do {
      puVar4 = (undefined4 *)Ped::GetPositionX(this_00,(int)local_20);
      local_34 = (Ped *)*puVar4;
      pPVar2 = *ppPVar9;
      pvVar5 = (void *)Ped::GetPositionX(pPVar2,(int)local_1c);
      puVar4 = (undefined4 *)
               S110_FUN_00401b40(&local_34,(S110 *)(local_1c + 4),pvVar5);
      local_34 = (Ped *)*puVar4;
      puVar4 = (undefined4 *)Ped::GetPositionY(this_00,(int)local_14);
      local_30 = (Ped *)*puVar4;
      pvVar5 = (void *)Ped::GetPositionY(pPVar2,(int)local_10);
      puVar4 = (undefined4 *)
               S110_FUN_00401b40(&local_30,(S110 *)(local_10 + 4),pvVar5);
      local_30 = (Ped *)*puVar4;
      piVar6 = FUN_00403840(&local_34,&local_8,(S110 *)&local_34);
      local_34 = (Ped *)*piVar6;
      piVar6 = FUN_00403840(&local_30,&local_4,(S110 *)&local_30);
      local_30 = (Ped *)*piVar6;
      bVar3 = FUN_00403800((S169 *)&local_34,(int *)&local_30);
      ppPVar7 = &local_34;
      if (CONCAT31(extraout_var,bVar3) == 0) {
        ppPVar7 = &local_30;
      }
      pPVar2 = *ppPVar7;
      local_30 = pPVar2;
      bVar3 = FUN_00403800((S169 *)&local_30,(int *)&local_2c);
      if (CONCAT31(extraout_var_00,bVar3) != 0) {
        _local_28 = (Ped *)CONCAT31(uStack_27,bVar8);
        local_2c = pPVar2;
      }
      bVar8 = bVar8 + 1;
      ppPVar9 = ppPVar9 + 1;
      this = local_24;
    } while (bVar8 < bVar1);
  }
  *param_1 = (int)local_2c;
  return this->Ped_Arr9[(uint)_local_28 & 0xff];
}


bool __thiscall S169__FUN_00404840(S169 *this)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  
  bVar1 = this->Index;
  if (bVar1 == 0) {
    return this->Ped->CarCurrent != (Car *)0x0;
  }
  bVar2 = 0;
  if (bVar1 != 0) {
    do {
      iVar3 = Ped::GetCurrentState(this->Ped_Arr9[bVar2]);
      if (iVar3 != 10) {
        return false;
      }
      bVar2 = bVar2 + 1;
    } while (bVar2 < bVar1);
  }
  return true;
}


void __thiscall S169__FUN_00404d40(S169 *this,void *pPed)

{
  void *this_00;
  bool bVar1;
  int iVar2;
  uint uVar3;
  byte IndexNextPed;
  Ped *pS49;
  Ped *pS49_1;
  
  this_00 = pPed;
  if ((Ped *)pPed == this->Ped) {
    bVar1 = Ped::HasSearchType(this->Ped,SEARCHTYPE_LINE_OF_SIGHT_PLAYER_ONLY);
    if (!bVar1) {
      pS49 = this->Ped;
      iVar2 = Ped::GetCurrentState(pS49);
      if ((iVar2 == 9) &&
         (pS49->SearchType ==
          (SEARCHTYPE_AREA_PLAYER_ONLY|SEARCHTYPE_LINE_OF_SIGHT))) {
        uVar3._0_1_ = pS49->flags;
        uVar3._1_1_ = pS49->uns59;
        uVar3._2_1_ = pS49->uns60;
        uVar3._3_1_ = pS49->uns61;
        uVar3 = uVar3 | 0x400;
        pS49->flags = (char)uVar3;
        pS49->uns59 = (char)(uVar3 >> 8);
        pS49->uns60 = (char)(uVar3 >> 0x10);
        pS49->uns61 = (char)(uVar3 >> 0x18);
      }
      pS49 = this->Ped_Arr9[0];
      if ((pS49 != (Ped *)0x0) && (bVar1 = Ped::GetDeadPed(pS49), !bVar1)) {
        FUN_00404120(this,0);
        pS49_1 = this->Ped;
        iVar2 = Ped::GetCurrentAction(pS49_1);
        Ped::S49_FUN_00433650(pS49_1,iVar2 == 0);
        iVar2 = Ped::GetOccupation((Ped *)pPed);
        IndexNextPed = this->Index;
        if (iVar2 == 0x17) {
          if (IndexNextPed != 0) {
            this->Ped_Arr9[IndexNextPed] = pS49;
            Ped::SetCarId(this->Ped_Arr9[this->Index],this->field13_0x36 - 1);
            AutoClass4::FUN_004045d0((AutoClass4 *)this);
            return;
          }
        }
        else if (IndexNextPed != 0) {
          this->Ped_Arr9[IndexNextPed] = (Ped *)0x0;
        }
        AutoClass4::FUN_004045d0((AutoClass4 *)this);
        return;
      }
      FUN_00403be0(this);
      return;
    }
  }
  else {
    IndexNextPed = 0;
    pPed = (void *)0x0;
    if (this->Index != 0) {
      while (this->Ped_Arr9[(int)pPed] != (Ped *)this_00) {
        IndexNextPed = IndexNextPed + 1;
        pPed = (void *)(uint)IndexNextPed;
        if (this->Index <= IndexNextPed) {
          return;
        }
      }
      pS49 = this->Ped_Arr9[this->Index - 1];
      this->Ped_Arr9[(int)pPed] = pS49;
      Ped::SetCarId(pS49,(char)pPed);
      this->Ped_Arr9[this->Index - 1] = (Ped *)this_00;
      Ped::SetCarId((Ped *)this_00,this->Index - 1);
      iVar2 = Ped::GetOccupation((Ped *)this_00);
      if (iVar2 != 0x17) {
        Ped::SetDefault(this->Ped_Arr9[this->Index - 1]);
        this->Ped_Arr9[this->Index - 1] = (Ped *)0x0;
        if (*(int *)((int)this_00 + 0x238) == 5) {
          *(uint *)((int)this_00 + 0x21c) =
               *(uint *)((int)this_00 + 0x21c) | 0x400;
        }
      }
      this->Index = this->Index - 1;
    }
  }
  return;
}


void __thiscall S169__FUN_00404ef0(S169 *this,undefined4 *param_1)

{
  S169 *this_00;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *linkedPed;
  PedFlags PVar5;
  char cVar6;
  bool bVar7;
  byte bVar8;
  PedFlags pPedFlag;
  int iVar9;
  Ped *pPed;
  undefined3 extraout_var;
  PedState pPedState;
  char cVar10;
  uint uVar11;
  uint local_8;
  int local_4;
  Ped *pPed1;
  
  linkedPed = param_1;
  this->field10_0x30 = 1;
  this_00 = (S169 *)param_1[0x59];
  if (this_00 == (S169 *)0x0) {
    cVar10 = this->Index - 1;
    if (-1 < cVar10) {
      param_1 = this->Ped_Arr9 + cVar10;
      do {
        pPed1 = (Ped *)*param_1;
        PVar5 = Ped::IsCrouching(pPed1);
        if (((PVar5 == 0) &&
            (uVar1._0_1_ = pPed1->flags, uVar1._1_1_ = pPed1->uns59,
            uVar1._2_1_ = pPed1->uns60, uVar1._3_1_ = pPed1->uns61,
            (uVar1 & 0x8000000) == 0)) &&
           (pPed1->GameObject != (GameObject *)0x0)) {
          cVar6 = FUN_00404900(cVar10);
          if (cVar6 == '\0') {
            iVar9 = Ped::GetCurrentAction(this->Ped);
            if (iVar9 == 0x23) {
              bVar7 = FUN_004049f0();
              if (!bVar7) goto LAB_00404fac;
            }
            Ped::SetAnimationState(pPed1,0x14,9999);
            pPed = (Ped *)linkedPed;
          }
          else {
            Ped::SetAnimationState(pPed1,7,9999);
            pPed = this->Ped;
          }
          Ped::SetLinkedPed(pPed1,pPed);
          Ped::S49_Set_FUN_00403950(pPed1);
        }
LAB_00404fac:
        cVar10 = cVar10 + -1;
        param_1 = param_1 + -1;
      } while (-1 < cVar10);
    }
    bVar7 = Ped::HasSearchType(this->Ped,SEARCHTYPE_LINE_OF_SIGHT_PLAYER_ONLY);
    if (!bVar7) {
      pPed1 = this->Ped;
      PVar5 = Ped::IsCrouching(pPed1);
      if (PVar5 == 0) {
        bVar8 = Ped::IsInCar(pPed1);
        if (((bVar8 == 0) &&
            (uVar2._0_1_ = pPed1->flags, uVar2._1_1_ = pPed1->uns59,
            uVar2._2_1_ = pPed1->uns60, uVar2._3_1_ = pPed1->uns61,
            (uVar2 & 0x8000000) == 0)) && (pPed1->CarCurrent == (Car *)0x0)) {
          Ped::SetAnimationState(pPed1,0x14,9999);
          Ped::SetLinkedPed(this->Ped,linkedPed);
          Ped::S49_Set_FUN_00403950(this->Ped);
          return;
        }
      }
    }
  }
  else {
    cVar10 = this->Index - 1;
    if (-1 < cVar10) {
      local_8 = (uint)this->Index;
      param_1 = this->Ped_Arr9 + cVar10;
      do {
        pPed1 = (Ped *)*param_1;
        pPedFlag = Ped::IsCrouching(pPed1);
        if (((pPedFlag == 0) &&
            (uVar11._0_1_ = pPed1->flags, uVar11._1_1_ = pPed1->uns59,
            uVar11._2_1_ = pPed1->uns60, uVar11._3_1_ = pPed1->uns61,
            (uVar11 & 0x8000000) == 0)) &&
           (pPed1->GameObject != (GameObject *)0x0)) {
          pPed = (Ped *)FUN_00404450(this_00);
          if (pPed == (Ped *)0x0) {
            local_4 = this_00->Index + 1;
            bVar8 = Random(&gRandom,(int)&local_4);
            uVar11 = (uint)(short)CONCAT31(extraout_var,bVar8);
            if (uVar11 == this_00->Index) {
              if (this_00->Ped != (Ped *)0x0) {
                pPedState = Ped::GetCurrentState(this_00->Ped);
                if (pPedState != PEDSTATE_DEAD) {
                  Ped::SetAnimationState(pPed1,0x14,9999);
                  pPed = this_00->Ped;
LAB_00405155:
                  Ped::SetLinkedPed(pPed1,pPed);
                  goto LAB_0040515e;
                }
              }
            }
            else if (this_00->Ped_Arr9[uVar11] != (Ped *)0x0) {
              iVar9 = Ped::GetCurrentState(this_00->Ped_Arr9[uVar11]);
              if (iVar9 != 9) {
                Ped::SetAnimationState(pPed1,0x14,9999);
                pPed = this_00->Ped_Arr9[uVar11];
                goto LAB_00405155;
              }
            }
          }
          else {
            Ped::SetAnimationState(pPed1,0x14,9999);
            Ped::SetLinkedPed(pPed1,pPed);
            Ped::S49_Set_FUN_00403950(pPed1);
            bVar8 = Ped::IsInCar(pPed);
            if (bVar8 == 0) {
              Ped::SetAnimationState(pPed,0x14,9999);
              Ped::SetLinkedPed(pPed,pPed1);
              pPed1 = pPed;
LAB_0040515e:
              Ped::S49_Set_FUN_00403950(pPed1);
            }
          }
        }
        param_1 = param_1 + -1;
        local_8 = local_8 - 1;
      } while (local_8 != 0);
    }
    pPed1 = this->Ped;
    PVar5 = Ped::IsCrouching(pPed1);
    if (PVar5 == 0) {
      PVar5 = Ped::IsCrouching(this_00->Ped);
      if (PVar5 == 0) {
        bVar7 = Ped::HasSearchType(pPed1,SEARCHTYPE_LINE_OF_SIGHT_PLAYER_ONLY);
        if (((!bVar7) &&
            (pPed1 = this->Ped, uVar3._0_1_ = pPed1->flags,
            uVar3._1_1_ = pPed1->uns59, uVar3._2_1_ = pPed1->uns60,
            uVar3._3_1_ = pPed1->uns61, (uVar3 & 0x8000000) == 0)) &&
           (pPed1->GameObject != (GameObject *)0x0)) {
          Ped::SetAnimationState(pPed1,0x14,9999);
          Ped::SetLinkedPed(this->Ped,this_00->Ped);
          Ped::S49_Set_FUN_00403950(this->Ped);
        }
        bVar7 = Ped::HasSearchType(this_00->Ped,
                                   SEARCHTYPE_LINE_OF_SIGHT_PLAYER_ONLY);
        if (((!bVar7) &&
            (pPed1 = this_00->Ped, uVar4._0_1_ = pPed1->flags,
            uVar4._1_1_ = pPed1->uns59, uVar4._2_1_ = pPed1->uns60,
            uVar4._3_1_ = pPed1->uns61, (uVar4 & 0x8000000) == 0)) &&
           (pPed1->GameObject != (GameObject *)0x0)) {
          Ped::SetAnimationState(pPed1,0x14,9999);
          Ped::SetLinkedPed(this_00->Ped,this->Ped);
          Ped::S49_Set_FUN_00403950(this_00->Ped);
        }
      }
    }
  }
  return;
}


void __thiscall S169__FUN_00405240(S169 *this)

{
  Ped *this_00;
  uint uVar1;
  byte bVar2;
  bool bVar3;
  PedFlags PVar4;
  byte bVar5;
  byte bVar6;
  char cVar7;
  undefined4 linkedPed;
  undefined3 extraout_var;
  uint uVar8;
  int Index;
  char cVar9;
  Car *pCar;
  uint unaff_EBX;
  undefined3 uVar10;
  uint3 uVar11;
  char local_18;
  char local_17;
  char local_16;
  S169 *pS169;
  Ped *local_4;
  GameObject *pGameObject;
  Ped *pPed1;
  
  pPed1 = this->Ped;
  pS169 = this;
  Index = Ped::GetCurrentState(pPed1);
  if (((Index == 3) || (Index = Ped::GetCurrentState(pPed1), Index == 10)) ||
     (Index = Ped::GetCurrentState(pPed1), Index == 5)) {
    this->field10_0x30 = 1;
    Index = Ped::GetCurrentState(pPed1);
    if ((Index == 10) || (bVar2 = Ped::FUN_00437ec0(pPed1), bVar2 != 0)) {
      pGameObject = this->Ped->GameObject;
      if (pGameObject == (GameObject *)0x0) {
        pCar = this->Ped->CarCurrent;
      }
      else {
        pCar = pGameObject->Car_1;
      }
      bVar2 = Car::FUN_0041fbb0(pCar);
      uVar8 = unaff_EBX & 0xffffff00;
      local_16 = '\0';
      local_4 = (Ped *)(uint)bVar2;
      if (bVar2 != 0) {
        Index = 0;
        local_18 = '\x02';
        do {
          if ((int)(uint)this->Index <= Index) break;
          pPed1 = this->Ped_Arr9[Index];
          bVar2 = Ped::IsInCar(pPed1);
          if ((((bVar2 != 1) && (bVar3 = Ped::GetDeadPed(pPed1), !bVar3)) &&
              ((Index = Ped::GetOccupation(pPed1), Index != 0x17 ||
               (Index = Ped::S49_Get_FUN_00403a80(pPed1), Index == 0)))) &&
             (Index = Ped::S49_Get_FUN_00403a80(pPed1), Index != 8)) {
            pCar = this->Ped->CarCurrent;
            if ((pCar == (Car *)0x0) ||
               (bVar3 = Car::IsTrainOrTrainCarriage(pCar), !bVar3)) {
              Index = Ped::GetCurrentAction(pPed1);
              if (Index != 0x23) {
                Ped::S49_FUN_00403960(pPed1);
                if (this->Ped->GameObject == (GameObject *)0x0) {
                  Ped::PedSetObjective(pPed1,0,9999);
                  Ped::SetAnimationState(pPed1,0x23,9999);
                  Ped::SetTargetCarDoor(pPed1,1);
                  pCar = this->Ped->CarCurrent;
                }
                else {
                  Ped::SetAnimationState(pPed1,0x12,9999);
                  Ped::SetTargetCarDoor(pPed1,1);
                  pCar = (Car *)GameObject::GetCar(this->Ped->GameObject);
                }
                Ped::SetObjectiveTargetCar(pPed1,pCar);
                GameObject::FUN_00491e60(pPed1->GameObject);
              }
              pCar = (Car *)Ped::GetCurrentCar(pPed1);
              DAT_0058f512 = local_18 + -1;
              bVar2 = 0;
              cVar9 = Car::Car_FUN_0041f880(pCar);
              bVar5 = cVar9 - 1;
              bVar6 = Car::isSWATVANOrBankVan(pCar);
              uVar1 = (uint)bVar5;
              uVar10 = (undefined3)(uVar8 >> 8);
              if (bVar6 == 0) {
                uVar8 = CONCAT31(uVar10,DAT_0058f512);
                do {
                  do {
                    if ((int)uVar1 < (int)(char)uVar8) {
                      uVar8 = CONCAT31((int3)(uVar8 >> 8),(char)uVar8 - bVar5);
                    }
                    DAT_0058f512 = (byte)uVar8;
                  } while ((int)uVar1 < (int)(char)DAT_0058f512);
                  bVar3 = Car::Car_FUN_00425a40(pCar,uVar8);
                  uVar11 = (uint3)(uVar8 >> 8);
                  if (!bVar3) {
                    DAT_0058f512 = DAT_0058f512 + 1;
                  }
                  uVar8 = CONCAT31(uVar11,DAT_0058f512);
                  bVar2 = bVar2 + 1;
                  if ((uint)bVar2 == uVar1 + 1) {
                    DAT_0058f512 = bVar5;
                    bVar3 = Car::Car_FUN_00425a40(pCar,0);
                    if (!bVar3) goto LAB_0040566e;
                    uVar8 = (uint)uVar11 << 8;
                    DAT_0058f512 = 0;
                    break;
                  }
                } while (!bVar3);
              }
              else {
                uVar8 = CONCAT31(uVar10,local_18);
                do {
                  do {
                    if ((int)uVar1 < (int)(char)uVar8) {
                      uVar8 = CONCAT31((int3)(uVar8 >> 8),
                                       (char)uVar8 + ('\x01' - bVar5));
                    }
                    DAT_0058f512 = (byte)uVar8;
                  } while ((int)uVar1 < (int)(char)DAT_0058f512);
                  bVar3 = Car::Car_FUN_00425a40(pCar,uVar8);
                  uVar11 = (uint3)(uVar8 >> 8);
                  if (!bVar3) {
                    DAT_0058f512 = DAT_0058f512 + 1;
                  }
                  uVar8 = CONCAT31(uVar11,DAT_0058f512);
                  bVar2 = bVar2 + 1;
                  if ((uint)bVar2 == uVar1 + 1) {
                    DAT_0058f512 = bVar5;
                    bVar3 = Car::Car_FUN_00425a40(pCar,0);
                    if (bVar3) {
                      uVar8 = (uint)uVar11 << 8;
                      DAT_0058f512 = 0;
                    }
                    else {
                      bVar3 = Car::Car_FUN_00425a40(pCar,1);
                      if (bVar3) {
                        uVar8 = CONCAT31(uVar11,1);
                        DAT_0058f512 = 1;
                      }
                      else {
LAB_0040566e:
                        uVar8 = CONCAT31((int3)(uVar8 >> 8),DAT_0058f512);
                      }
                    }
                    break;
                  }
                } while (!bVar3);
              }
              local_17 = '\0';
              if (this->Index != 0) {
                Index = 0;
                do {
                  this_00 = this->Ped_Arr9[Index];
                  if ((this_00 != pPed1) &&
                     (Index = Ped::GetCurrentAction(this_00), Index == 0x12)) {
                    cVar9 = Ped::S49_Get_FUN_00403a60(this_00);
                    cVar7 = Ped::S49_Get_FUN_00403a60(pPed1);
                    this = pS169;
                    if (cVar7 == cVar9) {
                      Ped::SetAnimationState(pPed1,9,9999);
                      Ped::SetLinkedPed(pPed1,this_00);
                      uVar8 = CONCAT31((int3)(uVar8 >> 8),DAT_0058f512);
                      this = pS169;
                    }
                  }
                  local_17 = local_17 + '\x01';
                  Index = (int)local_17;
                } while (Index < (int)(uint)this->Index);
              }
              Ped::S49_FUN_00403a70(pPed1,(char)uVar8);
              uVar8 = CONCAT31((int3)(uVar8 >> 8),local_16);
            }
            else {
              Ped::SetAnimationState(pPed1,0x25,9999);
              Ped::SetObjectiveTargetCar(pPed1,this->Ped->CarCurrent);
            }
          }
          local_16 = (char)uVar8 + '\x01';
          uVar8 = CONCAT31((int3)(uVar8 >> 8),local_16);
          local_18 = local_18 + '\x01';
          Index = (int)local_16;
        } while (Index < (int)local_4);
      }
      Index = (int)(char)uVar8;
      if (Index < (int)(uint)this->Index) {
        do {
          pPed1 = this->Ped_Arr9[Index];
          Index = Ped::S49_Get_FUN_00403a80(pPed1);
          if (Index != 8) {
            Ped::PedSetObjective(pPed1,8,9999);
            Ped::SetAnimationState(pPed1,0,9999);
          }
          bVar2 = (char)uVar8 + 1;
          uVar8 = (uint)bVar2;
          Index = (int)(char)bVar2;
        } while (Index < (int)(uint)this->Index);
      }
    }
    return;
  }
  bVar2 = Ped::S49_Get_FUN_00403b70(pPed1);
  uVar8 = (uint)bVar2;
  if (bVar2 != 0) {
    uVar8 = (uint)this->field1_0x1;
    if (this->field1_0x1 != 0) {
      linkedPed = FUN_00404490(this,(int *)&pS169);
      bVar3 = FUN_00403800((S169 *)&pS169,(int *)&DAT_005d288c);
      uVar8 = CONCAT31(extraout_var,bVar3);
      if (uVar8 != 0) {
        bVar3 = Ped::HasSearchType(pPed1,SEARCHTYPE_LINE_OF_SIGHT_PLAYER_ONLY);
        uVar8 = (uint)bVar3;
        if (!bVar3) {
          pPed1 = this->Ped;
          uVar8 = Ped::S49_Get_FUN_00403a80(pPed1);
          if ((uVar8 != 0xd) &&
             (uVar8 = Ped::GetCurrentAction(pPed1), uVar8 != 0x24)) {
            Ped::SetAnimationState(pPed1,9,9999);
            Ped::SetLinkedPed(this->Ped,linkedPed);
            this->field16_0x3c = 1;
          }
          goto LAB_0040531a;
        }
      }
      if (this->field16_0x3c == 1) {
        Ped::SetAnimationState(this->Ped,0,9999);
      }
    }
    this->field16_0x3c = 0;
  }
LAB_0040531a:
  cVar9 = (char)uVar8;
  FUN_00404480(this);
  if (cVar9 != '\0') {
LAB_0040535a:
    this->field10_0x30 = 1;
    return;
  }
  cVar9 = '\0';
  if (this->Index != 0) {
    Index = 0;
    do {
      PVar4 = Ped::IsCrouching(this->Ped_Arr9[Index]);
      if (PVar4 == 1) goto LAB_0040535a;
      cVar9 = cVar9 + '\x01';
      Index = (int)cVar9;
    } while (Index < (int)(uint)this->Index);
  }
  this->field10_0x30 = 0;
  return;
}


void * S169__FUN_0040e810(void *param_1,S169 *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  int iVar2;
  int iVar3;
  short sVar4;
  int iVar5;
  int local_4;
  
  iVar2 = 0;
  iVar3 = 0x167;
  do {
    iVar5 = (int)(short)iVar3 + (int)(short)iVar2 >> 1;
    sVar4 = (short)iVar5;
    local_4 = iVar5;
    bVar1 = FUN_004037e0(param_2,(SpriteS1 *)(&DAT_005d5090 + sVar4 * 4));
    if (CONCAT31(extraout_var,bVar1) == 0) {
      bVar1 = S169::FUN_00403800(param_2,(int *)(&DAT_005d5090 + sVar4 * 4));
      if (CONCAT31(extraout_var_00,bVar1) == 0) goto LAB_0040e8b7;
      iVar2 = iVar5 + 1;
    }
    else {
      iVar3 = iVar5 + -1;
    }
  } while ((short)iVar2 <= (short)iVar3);
  if (sVar4 == 1) {
    bVar1 = FUN_004037e0(param_2,(SpriteS1 *)&DAT_005d5094);
    if (CONCAT31(extraout_var_01,bVar1) != 0) {
      local_4 = 0;
    }
  }
  else if ((sVar4 == 0x167) &&
          (bVar1 = S169::FUN_00403800(param_2,(int *)&DAT_005d562c),
          CONCAT31(extraout_var_02,bVar1) != 0)) {
    local_4 = 0x168;
  }
LAB_0040e8b7:
  FUN_00401c60(param_1,(int)&local_4);
  return param_1;
}


void __thiscall S169__FUN_00413eb0(AudioManager *param_1,int *param_2,S169 *param_3)

{
  Car *this;
  Player *pPVar1;
  S169 *pSVar2;
  bool bVar3;
  byte bVar4;
  Car *pCVar5;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined4 uVar6;
  int *piVar7;
  Player **this_00;
  int *this_01;
  void *this_02;
  undefined4 *puVar8;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined1 *puVar9;
  Player **ppPVar10;
  undefined1 *puVar11;
  undefined4 *puVar12;
  int *piVar13;
  Player *local_18;
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  undefined1 local_c [4];
  undefined1 local_8 [4];
  undefined1 local_4 [4];
  
  this = *(Car **)(*param_2 + 8);
  pCVar5 = Car::Car_FUN_00421d90(this,(Car *)&local_18);
  pSVar2 = param_3;
  pPVar1 = (Player *)pCVar5->s72;
  local_18 = pPVar1;
  bVar3 = S169::FUN_00403800(param_3,&DAT_005dc870);
  if (CONCAT31(extraout_var,bVar3) != 0) {
    bVar3 = Player::IsCurrentPlayer((Player *)&local_18,(Player *)&DAT_005dc870)
    ;
    if (CONCAT31(extraout_var_00,bVar3) != 0) {
      uVar6 = Car::GetModelCar(this);
      piVar7 = (int *)FUN_00411120(uVar6);
      if ((char)piVar7 != '\0') {
        bitShiftLeft1(&param_3,(void *)0x2);
        this_00 = &local_18;
        ppPVar10 = this_00;
        bitShiftLeft1(local_14,(void *)0xa);
        this_01 = (int *)FUN_00401b90(this_00,ppPVar10,piVar7);
        puVar11 = local_10;
        piVar13 = this_01;
        bitShiftLeft1(local_c,(void *)0x2);
        puVar9 = local_8;
        piVar7 = this_01;
        bitShiftLeft1(local_4,(void *)0xa);
        this_02 = FUN_00401b90(this_01,puVar9,piVar7);
        puVar8 = (undefined4 *)
                 WorldCoordinateToScreenCoord(this_02,puVar11,piVar13);
        bVar4 = AudioManager::S154_FUN_004116b0(param_1,*puVar8);
        piVar7 = (int *)CONCAT31(extraout_var_01,bVar4);
        if (bVar4 != 0) {
          bitShiftLeft1(&param_3,(void *)0x2);
          puVar11 = local_4;
          piVar13 = piVar7;
          bitShiftLeft1(local_8,(void *)0xa);
          piVar7 = (int *)FUN_00401b90(piVar7,puVar11,piVar13);
          bVar4 = AudioManager::S154_FUN_004116f0
                            (param_1,0x28,*piVar7,*(char *)((int)param_2 + 5));
          piVar7 = (int *)CONCAT31(extraout_var_02,bVar4);
          if (bVar4 != 0) {
            bitShiftLeft1(&param_2,(void *)0x2);
            puVar8 = &param_3;
            puVar12 = puVar8;
            bitShiftLeft1(local_4,(void *)0xa);
            puVar8 = (undefined4 *)FUN_00401b90(puVar8,puVar12,piVar7);
            param_1->field78_0x84 = *puVar8;
            param_1->field81_0x90 = 0x28;
            param_1->field85_0x94 = 10;
            param_1->field79_0x88 = 7;
            param_1->field37_0x34 = 2;
            param_1->field65_0x71 = 1;
            param_1->field45_0x48 = 0;
            param_1->field49_0x4c = 7;
            AudioManager::S154_FUN_004171a0(param_1);
          }
        }
      }
    }
  }
  *(Player **)pSVar2 = pPVar1;
  return;
}


uint __thiscall S169__FUN_00434ba0(Ped *param_1,S169 *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  Ped *this;
  Ped *this_00;
  Ped *extraout_EDX;
  Ped *pPVar3;
  S169 *pSVar2;
  
  pSVar2 = param_1->pS169;
  if ((pSVar2 != param_2) &&
     (pSVar2 = (S169 *)param_1->Player, pSVar2 == (S169 *)0x0)) {
    bVar1 = Ped::HasSearchType(param_1,SEARCHTYPE_AREA );
    pSVar2 = (S169 *)CONCAT31(extraout_var,bVar1);
    if (!bVar1) {
      bVar1 = Ped::HasSearchType(this,SEARCHTYPE_AREA_PLAYER_ONLY);
      pSVar2 = (S169 *)CONCAT31(extraout_var_00,bVar1);
      pPVar3 = this_00;
      if (!bVar1) {
        bVar1 = Ped::HasSearchType(this_00,SEARCHTYPE_AREA_PLAYER_ONLY|
                                           SEARCHTYPE_LINE_OF_SIGHT_PLAYER_ONLY)
        ;
        pSVar2 = (S169 *)CONCAT31(extraout_var_01,bVar1);
        pPVar3 = extraout_EDX;
        if (!bVar1) goto LAB_00434bef;
      }
      if (pPVar3->Occupation != 0x23) goto LAB_00434bef;
    }
    return CONCAT31((int3)((uint)pSVar2 >> 8),1);
  }
LAB_00434bef:
  return (uint)pSVar2 & 0xffffff00;
}


    else S169__if (((extraout_EDX_00->pS169 == (S169 *)0x0) ||
             (pPVar3 = *(Ped **)&gGame->PlayerMain->field_0x2c4,
             pPVar3 == (Ped *)0x0)) || (extraout_EDX_00->pS169 != pPVar3->pS169)
            ) goto LAB_0043dac3;
    FUN_00434ff0(this,pPVar3);
  }
LAB_0043dac3:
  if (((_gNetworkGame != 0) && (this->uns23 == 0)) &&
     (bVar1 = HasSearchType(this,SEARCHTYPE_LINE_OF_SIGHT_PLAYER_ONLY), bVar1))
  {


          else S169__if (this_00 == (S169 *)0x0) {
            uVar26._0_1_ = this->flags;
            uVar26._1_1_ = this->uns59;
            uVar26._2_1_ = this->uns60;
            uVar26._3_1_ = this->uns61;
            uVar26 = uVar26 | 4;
            this->flags = (char)uVar26;
            this->uns59 = (char)(uVar26 >> 8);
            this->uns60 = (char)(uVar26 >> 0x10);
            this->uns61 = (char)(uVar26 >> 0x18);
            SetAnimationState(this,0x14,9999);
            this->LinkedPed = pPed;
            this->uns50 = 0;
            goto LAB_0043f884;
          }


    else S169__if ((this->pS169 == (S169 *)0x0) &&
            (this->SearchType !=
             (SEARCHTYPE_AREA_PLAYER_ONLY|SEARCHTYPE_LINE_OF_SIGHT))) {
      PedSetObjective(this,0x1c,9999);
    }


void S169__FUN_0049e2c0(int *param_1,S169 *param_2,S169 *param_3,int *param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  
  bVar1 = S169::FUN_00403800(param_2,(int *)param_3);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    bVar1 = S169::FUN_00403800(param_3,param_4);
    if (CONCAT31(extraout_var_01,bVar1) != 0) {
      *param_1 = *(int *)param_3;
      return;
    }
    *param_1 = *param_4;
    return;
  }
  bVar1 = S169::FUN_00403800(param_2,param_4);
  if (CONCAT31(extraout_var_00,bVar1) != 0) {
    *param_1 = *(int *)param_2;
    return;
  }
  *param_1 = *param_4;
  return;
}


void S169__FUN_0049e2c0(int *param_1,S169 *param_2,S169 *param_3,int *param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  
  bVar1 = S169::FUN_00403800(param_2,(int *)param_3);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    bVar1 = S169::FUN_00403800(param_3,param_4);
    if (CONCAT31(extraout_var_01,bVar1) != 0) {
      *param_1 = *(int *)param_3;
      return;
    }
    *param_1 = *param_4;
    return;
  }
  bVar1 = S169::FUN_00403800(param_2,param_4);
  if (CONCAT31(extraout_var_00,bVar1) != 0) {
    *param_1 = *(int *)param_2;
    return;
  }
  *param_1 = *param_4;
  return;
}


void __thiscall S169__FUN_0049e480(S169 *param_1,SpriteS1 *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  Ped **this;
  S3 *pSpriteS1;
  
  bVar1 = Player::FUN_0040ce70((Player *)param_1,(int *)&DAT_0066acdc);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    bVar1 = FUN_004037e0(param_1,param_2);
    if (CONCAT31(extraout_var_01,bVar1) != 0) {
      *(SpriteS1 **)param_1 = param_2->FirstElement;
    }
  }
  else {
    bVar1 = S169::FUN_00403800(param_1,(int *)param_2);
    if (CONCAT31(extraout_var_00,bVar1) != 0) {
      *(SpriteS1 **)param_1 = param_2->FirstElement;
    }
  }
  this = param_1->Ped_Arr9;
  bVar1 = Player::FUN_0040ce70((Player *)this,(int *)&DAT_0066acdc);
  pSpriteS1 = param_2->S3_arr5031;
  if (CONCAT31(extraout_var_02,bVar1) == 0) {
    bVar1 = FUN_004037e0(this,(SpriteS1 *)pSpriteS1);
    if (CONCAT31(extraout_var_04,bVar1) != 0) {
      *this = (Ped *)pSpriteS1->SpriteS1;
    }
  }
  else {
    bVar1 = S169::FUN_00403800((S169 *)this,(int *)pSpriteS1);
    if (CONCAT31(extraout_var_03,bVar1) != 0) {
      *this = (Ped *)pSpriteS1->SpriteS1;
      return;
    }
  }
  return;
}


                else S169__if ((pS110->S169 == (S169 *)0x0) ||
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


              else S169__if ((pS110->S169 == (S169 *)0x0) ||
                      (cVar13 = FUN_004048a0(), pS49_1 = _pS49_2, cVar13 != '\0'
                      )) {
                Ped::SetAnimationState(pS49_1,0,9999);
                goto LAB_004ac8bd;
              }


void __thiscall S169__FUN_004ba620(S169 *param_1,int *param_2)

{
  S169 *pSVar1;
  int *piVar2;
  int iVar3;
  bool bVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  
  bVar4 = S169::FUN_00403800(param_1,param_2);
  if (CONCAT31(extraout_var,bVar4) != 0) {
    iVar3 = *param_2;
    param_1->field0_0x0 = (char)iVar3;
    param_1->field1_0x1 = (char)((uint)iVar3 >> 8);
    param_1->field2_0x2 = (char)((uint)iVar3 >> 0x10);
    param_1->field3_0x3 = (char)((uint)iVar3 >> 0x18);
  }
  bVar4 = FUN_004037e0(param_1->Ped_Arr9,(SpriteS1 *)(param_2 + 1));
  if (CONCAT31(extraout_var_00,bVar4) != 0) {
    param_1->Ped_Arr9[0] = (Ped *)((SpriteS1 *)(param_2 + 1))->FirstElement;
  }
  pSVar1 = (S169 *)(param_1->Ped_Arr9 + 1);
  bVar4 = S169::FUN_00403800(pSVar1,param_2 + 2);
  if (CONCAT31(extraout_var_01,bVar4) != 0) {
    iVar3 = param_2[2];
    pSVar1->field0_0x0 = (char)iVar3;
    pSVar1->field1_0x1 = (char)((uint)iVar3 >> 8);
    pSVar1->field2_0x2 = (char)((uint)iVar3 >> 0x10);
    pSVar1->field3_0x3 = (char)((uint)iVar3 >> 0x18);
  }
  bVar4 = FUN_004037e0(param_1->Ped_Arr9 + 2,(SpriteS1 *)(param_2 + 3));
  if (CONCAT31(extraout_var_02,bVar4) != 0) {
    param_1->Ped_Arr9[2] = (Ped *)((SpriteS1 *)(param_2 + 3))->FirstElement;
  }
  piVar2 = param_2 + 4;
  pSVar1 = (S169 *)(param_1->Ped_Arr9 + 3);
  bVar4 = S169::FUN_00403800(pSVar1,piVar2);
  if (CONCAT31(extraout_var_03,bVar4) != 0) {
    iVar3 = *piVar2;
    pSVar1->field0_0x0 = (char)iVar3;
    pSVar1->field1_0x1 = (char)((uint)iVar3 >> 8);
    pSVar1->field2_0x2 = (char)((uint)iVar3 >> 0x10);
    pSVar1->field3_0x3 = (char)((uint)iVar3 >> 0x18);
  }
  bVar4 = FUN_004037e0(param_1->Ped_Arr9 + 4,(SpriteS1 *)(param_2 + 5));
  if (CONCAT31(extraout_var_04,bVar4) != 0) {
    param_1->Ped_Arr9[4] = (Ped *)*piVar2;
  }
  return;
}


