// Module: S8
// Functions working with structure S8
// Generated from gta2.exe.c

#include "../../include/common.h"

S8 * __thiscall S8__S8(S8 *this)

{
  S9 *pS9;
  
  this->field3_0x9 = 0;
  this->field4_0xa = 0;
  this->field2_0x8 = 0;
  this->field0_0x0 = 0;
  this->field6_0xc = 0;
  this->field7_0x10 = 0;
  pS9 = (S9 *)operator_new(0x18);
  if (pS9 != (S9 *)0x0) {
    pS9 = S9::S9(pS9);
    this->S9 = pS9;
    FUN_004b2ff0();
    return this;
  }
  this->S9 = (S9 *)0x0;
  FUN_004b2ff0();
  return this;
}


void __thiscall S8__S8_FUN_004b4a60(S8 *this)

{
  undefined4 in_stack_fffffff0;
  undefined4 in_stack_fffffff4;
  uint in_stack_fffffff8;
  
  if ((gLimitRecycling) && (1 < (int)gCarSystemManager->RecycledCars)) {
    return;
  }
  FUN_003f1314((void *)(gCarSystemManager->RecycledCars_1 +
                       gCarSystemManager->RecycledCars),in_stack_fffffff0,
               in_stack_fffffff4,in_stack_fffffff8);
  return;
}


void __thiscall S8__S8_FUN_004b4e60(S8 *this)

{
  byte bVar1;
  int iVar2;
  Player *pPVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  Ped *pPVar7;
  undefined4 local_10;
  undefined4 local_c;
  undefined1 local_8 [4];
  undefined1 local_4 [4];
  
  if (!gSkipRecycling) {
    iVar2 = Game::Game_FUN_003f113c(gGame);
    this->field0_0x0 = iVar2;
    pPVar3 = Game::Game_FUN_003f11a8(gGame);
    this->field6_0xc = pPVar3;
    if (pPVar3 != (Player *)0x0) {
      pPVar7 = *(Ped **)&pPVar3->field_0x2c4;
      puVar4 = (undefined4 *)Ped::GetPositionX(pPVar7,(int)&local_c);
      local_c = *puVar4;
      puVar4 = (undefined4 *)Ped::GetPositionY(pPVar7,(int)&local_10);
      local_10 = *puVar4;
      iVar2 = DecoderFloat(&local_10);
      iVar5 = DecoderFloat(&local_c);
      uVar6 = MapRelatedStruct::S16_FUN_00465250(_gMapRelatedStruct,iVar5,iVar2)
      ;
      this->field7_0x10 = uVar6;
    }
    iVar2 = this->field0_0x0;
    while (iVar2 != 0) {
      bVar1 = CameraOrPhysics::FUN_00433e90((CameraOrPhysics *)this->field0_0x0)
      ;
      if (bVar1 != 0) {
        S8_FUN_004b4a60(this);
      }
      iVar2 = Game::Game_FUN_003f1208(gGame);
      this->field0_0x0 = iVar2;
      if (iVar2 == this->field6_0xc + 0x208) {
        pPVar7 = *(Ped **)(this->field6_0xc + 0x2c8);
LAB_004b4f34:
        if (pPVar7 != (Ped *)0x0) {
          puVar4 = (undefined4 *)Ped::GetPositionX(pPVar7,(int)local_8);
          local_c = *puVar4;
          puVar4 = (undefined4 *)Ped::GetPositionY(pPVar7,(int)local_4);
          local_10 = *puVar4;
          iVar2 = DecoderFloat(&local_10);
          iVar5 = DecoderFloat(&local_c);
          uVar6 = MapRelatedStruct::S16_FUN_00465250
                            (_gMapRelatedStruct,iVar5,iVar2);
          this->field7_0x10 = uVar6;
        }
      }
      else {
        iVar2 = Game::Game_FUN_003f12a8(gGame);
        this->field6_0xc = iVar2;
        if (iVar2 != 0) {
          pPVar7 = *(Ped **)(iVar2 + 0x2c4);
          goto LAB_004b4f34;
        }
      }
      iVar2 = this->field0_0x0;
    }
  }
  return;
}


