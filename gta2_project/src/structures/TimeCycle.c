// Module: S31
// Functions working with structure S31
// Generated from gta2.exe.c

#include "common.h"

S31 * __thiscall S31__S31(S31 *this)

{
  S32 *pS32;
  int index;
  
  *(undefined1 *)&this->s32[0x31].next_field = 0;
                              //  // Получение указателя на
                              // начало массива структур
  pS32 = this->s32;
                              // // Инициализация 50
                              // элементов массива
                              //     for (int i = 0; i < 50; i++) {
                              //         entry->prev_field = 0;
                              //         entry->current_field = 0;
                              //         entry->next_field = 0;
                              //         
                              //         // Переход к
                              // следующему элементу (12
                              // байт)
                              //         entry++;
                              //     }
  index = 50;
  do {
    *(undefined4 *)((int)(pS32 + -1) + 8) = 0;
    pS32->prev_field = 0;
    pS32->current_field = '\0';
    pS32 = pS32 + 1;
    index = index + -1;
  } while (index != 0);
  return this;
}


S31 * __thiscall S31__FUN_00474e80(S31 *this)

{
  ushort uVar1;
  
  uVar1 = 0;
  do {
    if (*(int *)this == 0) {
      return this;
    }
    this = (S31 *)((int)this + 0xc);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x32);
  return (S31 *)0x0;
}


void __thiscall S31__S31_FUN_00474ea0(S31 *this,int param_1)

{
  uint32_t uVar1;
  S31 *pSVar2;
  int extraout_ECX;
  
  pSVar2 = FUN_00474e80(this);
  if (pSVar2 != (S31 *)0x0) {
    *(int *)pSVar2 = param_1;
    uVar1 = *(uint32_t *)(param_1 + 0x6c);
    pSVar2->s32[0].current_field = '\x01';
    pSVar2->s32[0].prev_field = uVar1;
    *(char *)(extraout_ECX + 600) = *(char *)(extraout_ECX + 600) + '\x01';
  }
  return;
}


void __thiscall S31__FUN_00474ed0(S31 *this,int param_1)

{
  uint32_t uVar1;
  S31 *pSVar2;
  int extraout_ECX;
  
  pSVar2 = FUN_00474e80(this);
  if (pSVar2 != (S31 *)0x0) {
    *(int *)pSVar2 = param_1;
    uVar1 = *(uint32_t *)(param_1 + 0x14);
    pSVar2->s32[0].current_field = '\x02';
    pSVar2->s32[0].prev_field = uVar1;
    *(char *)(extraout_ECX + 600) = *(char *)(extraout_ECX + 600) + '\x01';
  }
  return;
}


void __thiscall S31__S31_FUN_00476bc0(S31 *this)

{
  uint8_t uVar1;
  S169 *this_00;
  S63 *this_01;
  Car *pCVar2;
  bool bVar3;
  uint32_t *puVar4;
  int local_4;
  
  this_00 = *(S169 **)(*(int *)&gGame->PlayerMain->field_0x2c4 + 0x164);
  if (this_00 != (S169 *)0x0) {
    PedManager__UpdatePedStates(this_00);
  }
  if ((_DAT_006644b0 != (Car *)0x0) &&
     (_DAT_006644b0->ID_Object == _DAT_006644b4)) {
    Player::FUN_004a47f0(gGame->PlayerMain,_DAT_006644b0);
    pCVar2 = _DAT_006644b0;
    Car::CarMakeDriveable1(_DAT_006644b0,3);
    bVar3 = Car::Car_FUN_004214d0(pCVar2);
    if (!bVar3) {
      Car::Car_FUN_00421470(pCVar2);
    }
    _DAT_006644b0 = (Car *)0x0;
    _DAT_006644b4 = 0;
  }
  local_4 = 0x32;
  puVar4 = (uint32_t *)this;
  do {
    this_01 = (S63 *)*puVar4;
    if (this_01 != (S63 *)0x0) {
      uVar1 = ((S32 *)(puVar4 + 1))->current_field;
      if (uVar1 == '\x01') {
        if (*(uint32_t *)&this_01[2].CameraX == puVar4[2]) {
          Player::FUN_004a47f0(gGame->PlayerMain,this_01);
          Car::CarMakeDriveable1((Car *)*puVar4,3);
          pCVar2 = (Car *)*puVar4;
          bVar3 = Car::Car_FUN_004214d0(pCVar2);
          if (!bVar3) {
            Car::Car_FUN_00421470(pCVar2);
          }
        }
      }
      else if (uVar1 == '\x02') {
        if (*(uint32_t *)&this_01->CameraX == puVar4[2]) {
          S63::FUN_00483c40(this_01);
          FUN_004827c0();
        }
      }
      else if ((uVar1 == '\x03') && (*(uint32_t *)&this_01[0xb].z == puVar4[2]))
      {
        if (this_01[8].SpriteS1 != (SpriteS1 *)0x0) {
          PedManager__ProcessPeds((S169 *)this_01[8].SpriteS1);
        }
        Ped::sPed_FUN_0043ec30((Ped *)*puVar4);
        *(uint *)(*puVar4 + 0x21c) = *(uint *)(*puVar4 + 0x21c) | 0x400;
      }
      *puVar4 = 0;
      puVar4[2] = 0;
      ((S32 *)(puVar4 + 1))->current_field = '\0';
      *(char *)&this->s32[0x31].next_field =
           (char)this->s32[0x31].next_field + -1;
    }
    puVar4 = puVar4 + 3;
    local_4 = local_4 + -1;
  } while (local_4 != 0);
  *(undefined4 *)(_gMissionManager + 0xc1e70) = 0x57;
  return;
}


void __thiscall S31__CreatePed2(S31 *this,Ped *pPed)

{
  uint32_t *puVar1;
  S31 *pSVar2;
  uint32_t uVar3;
  
  pSVar2 = FUN_00474e80(this);
  if (pSVar2 != (S31 *)0x0) {
    *(Ped **)pSVar2 = pPed;
    uVar3 = Ped::GetIdPlayer(pPed);
    pSVar2->s32[0].prev_field = uVar3;
    pSVar2->s32[0].current_field = '\x03';
    puVar1 = &this->s32[0x31].next_field;
    *(char *)puVar1 = (char)*puVar1 + '\x01';
  }
  return;
}


void __thiscall S31__S31_FUN_00476d50(S31 *this,int param_1,char param_2)

{
  uint32_t *puVar1;
  int iVar2;
  S31 *pSVar3;
  
  if (param_2 == '\0') {
    if (param_1 == 0) {
      return;
    }
    iVar2 = FUN_0040fef0((void *)param_1);
    if ((0x3f < iVar2) && (iVar2 = FUN_0040fef0((void *)param_1), iVar2 < 0x6d))
    {
      return;
    }
    iVar2 = FUN_0040fef0((void *)param_1);
    if ((199 < iVar2) && (iVar2 = FUN_0040fef0((void *)param_1), iVar2 < 0xf5))
    {
      return;
    }
  }
  pSVar3 = FUN_00474e80(this);
  if (pSVar3 != (S31 *)0x0) {
    *(int *)pSVar3 = param_1;
    pSVar3->s32[0].prev_field = *(uint32_t *)(param_1 + 0x14);
    pSVar3->s32[0].current_field = '\x02';
    puVar1 = &this->s32[0x31].next_field;
    *(char *)puVar1 = (char)*puVar1 + '\x01';
  }
  return;
}


