// Module: S9
// Functions working with structure S9
// Generated from gta2.exe.c

#include "common.h"

S9 * __thiscall S9__S9(S9 *this)

{
  return this;
}


void __thiscall S9__FUN_0041e370(S9 *this,undefined4 param_1,undefined4 param_2)

{
  *(undefined4 *)(this->Arr_24 + 0x10) = param_1;
  *(undefined4 *)(this->Arr_24 + 0x14) = param_2;
  return;
}


undefined4 S9__FUN_00424ff0(SpriteS1 *param_1,S9 *pS9,undefined4 param_3)

{
  char cVar1;
  byte bVar2;
  bool bVar3;
  void *this;
  int iVar4;
  int iVar5;
  SpriteS1 *pSVar6;
  undefined4 *puVar7;
  SpriteS1 *pSVar8;
  undefined4 *puVar9;
  SpriteS1 *pSVar10;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  short *psVar11;
  S9 *pSVar12;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  undefined1 local_48 [20];
  undefined1 local_34 [52];
  
  pSVar12 = pS9;
  pSVar10 = param_1;
  local_4c = 0;
  this = MapRelatedStruct::FindMaxZForLocation
                   (_gMapRelatedStruct,(float10 *)local_48,(float10 *)param_1,
                    (float10 *)pS9);
  local_58 = Decoder_DecodeFloat(this);
  do {
    iVar4 = Decoder_DecodeFloat(&pS9);
    iVar5 = Decoder_DecodeFloat(&param_1);
    iVar4 = FUN_00466a00(iVar5,iVar4);
    local_58 = local_58 + 1;
    if ((iVar4 != 0) && ((*(byte *)(iVar4 + 0xb) & 3) == 1)) {
      cVar1 = FUN_0040c810(iVar4,1);
      if (cVar1 == '\0') {
        cVar1 = FUN_0040c810(iVar4,1);
        if (cVar1 == '\0') {
          cVar1 = FUN_0040c810(iVar4,1);
          if (cVar1 == '\0') {
            cVar1 = FUN_0040c810(iVar4,1);
            if (cVar1 == '\0') {
              cVar1 = FUN_0040c810(iVar4,1);
              if (cVar1 == '\0') {
                return 0;
              }
              param_3 = 4;
            }
            else {
              param_3 = 2;
            }
          }
          else {
            param_3 = 3;
          }
        }
        else {
          param_3 = 1;
        }
      }
      bVar2 = Game::FUN_0045bc10(gGame,pSVar10,pSVar12);
      if (bVar2 == 0) {
        FUN_0041f980(&stack0xffffff94,local_58);
        FUN_00469570(local_48,pSVar10,pSVar12);
        iVar4 = Style::getCarModelById(gStyle,*(byte *)(local_48._4_4_ + 0x84));
        local_50 = *(int *)(&DAT_006639a0 + (uint)*(byte *)(iVar4 + 2) * 4);
        local_54 = *(int *)(&DAT_006639a0 + (uint)*(byte *)(iVar4 + 3) * 4);
        FUN_0041fe40(param_3,&local_50);
        pSVar6 = S9::S9_FUN_00401b20((S9 *)&pS9,(SpriteS1 *)(local_48 + 8),
                                     &local_54);
        puVar7 = (undefined4 *)
                 Decoder_ProcessData(&pS9,(S110 *)(local_48 + 0xc),&local_54);
        pSVar8 = S9::S9_FUN_00401b20((S9 *)&param_1,
                                     (SpriteS1 *)(local_48 + 0x10),&local_50);
        puVar9 = (undefined4 *)
                 Decoder_ProcessData(&param_1,(S110 *)local_34,&local_50);
        S9::FUN_0041e350((S9 *)(local_34 + 0x1c),*puVar9,pSVar8->FirstElement,
                         *puVar7,pSVar6->FirstElement);
        pSVar6 = S9::S9_FUN_00401b20((S9 *)local_48,(SpriteS1 *)(local_34 + 4),
                                     &DAT_005e4d4c);
        puVar7 = (undefined4 *)
                 Decoder_ProcessData(local_48,(S110 *)(local_34 + 8),&DAT_005e4d4c
                                  );
        S9::FUN_0041e370((S9 *)(local_34 + 0x1c),*puVar7,pSVar6->FirstElement);
        cVar1 = S56::FUN_004477b0(gS56,(S9 *)(local_34 + 0x1c),0,0,0);
        if ((cVar1 == '\0') &&
           (S9::FUN_004ba720((S9 *)(local_34 + 0x1c)), cVar1 == '\0')) {
          SpriteS1::SetPosition
                    (*(SpriteS1 **)(local_48._4_4_ + 0x50),(int)pSVar10,(int)pS9
                     ,local_48._0_4_);
          psVar11 = (short *)FUN_004725b0(&pS9);
          SpriteS1::SetRotation(*(SpriteS1 **)(local_48._4_4_ + 0x50),*psVar11);
          if (*(int *)(local_48._4_4_ + 0x58) != 0) {
            FUN_0049ee50();
            FUN_00421210(*(void **)(local_48._4_4_ + 0x58));
            Player::FUN_00421260(*(Player **)(local_48._4_4_ + 0x58));
            FUN_00421200();
          }
          return 1;
        }
      }
    }
    switch(param_3) {
    case 1:
      pSVar6 = S9::S9_FUN_00401b20((S9 *)&pS9,(SpriteS1 *)(local_34 + 0xc),
                                   &DAT_005e4d4c);
      pS9 = (S9 *)pSVar6->FirstElement;
      break;
    case 2:
      puVar7 = (undefined4 *)
               Decoder_ProcessData(&pS9,(S110 *)(local_34 + 0x10),&DAT_005e4d4c);
      pS9 = (S9 *)*puVar7;
      break;
    case 3:
      pSVar10 = (SpriteS1 *)
                Decoder_ProcessData(&param_1,(S110 *)(local_34 + 0x14),
                                  &DAT_005e4d4c);
      goto LAB_004252b6;
    case 4:
      pSVar10 = S9::S9_FUN_00401b20((S9 *)&param_1,(SpriteS1 *)(local_34 + 0x18)
                                    ,&DAT_005e4d4c);
LAB_004252b6:
      pSVar10 = pSVar10->FirstElement;
      param_1 = pSVar10;
    }
    bVar3 = FUN_004037e0(&param_1,(SpriteS1 *)&gSpriteS1_0);
    if ((((CONCAT31(extraout_var,bVar3) != 0) ||
         (bVar3 = S169::FUN_00403800((S169 *)&param_1,(int *)&DAT_005e4fd8),
         CONCAT31(extraout_var_00,bVar3) != 0)) ||
        (bVar3 = FUN_004037e0(&pS9,(SpriteS1 *)&gSpriteS1_0),
        CONCAT31(extraout_var_01,bVar3) != 0)) ||
       (((bVar3 = S169::FUN_00403800((S169 *)&pS9,(int *)&DAT_005e4fd8),
         CONCAT31(extraout_var_02,bVar3) != 0 || (local_58 < 0)) ||
        (7 < local_58)))) {
      local_4c = 200;
    }
    local_4c = local_4c + 1;
    pSVar12 = pS9;
    if (199 < local_4c) {
      return 0;
    }
  } while( true );
}


void __thiscall S9__FUN_0045ada0(S9 *this,undefined4 *param_1)

{
  *param_1 = *(undefined4 *)(this->Arr_24 + 4);
  return;
}


void __thiscall S9__FUN_0045adb0(S9 *this,undefined4 *param_1)

{
  *param_1 = *(undefined4 *)this->Arr_24;
  return;
}


void __thiscall S9__FUN_0045adc0(S9 *this,undefined4 *param_1)

{
  *param_1 = *(undefined4 *)(this->Arr_24 + 0xc);
  return;
}


void __thiscall S9__FUN_0045add0(S9 *this,S9 *param_1)

{
  *(undefined4 *)param_1->Arr_24 = *(undefined4 *)(this->Arr_24 + 8);
  return;
}


void __thiscall S9__FUN_0045add0(S9 *this,S9 *param_1)

{
  *(undefined4 *)param_1->Arr_24 = *(undefined4 *)(this->Arr_24 + 8);
  return;
}


byte __thiscall S9__FUN_0045af40(CameraOrPhysics *this,S9 *pS9)

{
  bool bVar1;
  undefined3 extraout_var;
  Player *pPVar2;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  Player **pConditionValue;
  int *piVar3;
  void **pConditionValue_00;
  undefined4 local_8 [2];
  undefined3 extraout_var_00;
  S9 *pS9__1;
  
  pS9__1 = pS9;
  pPVar2 = (Player *)&this->Player;
  pConditionValue = (Player **)pPVar2;
  S9::FUN_0045add0(pS9,(S9 *)&pS9);
  bVar1 = Player::CheckCondition(pPVar2,(int *)pConditionValue);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    piVar3 = &this->field7_0x28;
    pPVar2 = (Player *)&stack0xfffffff4;
    S9::FUN_0045adc0(pS9__1,(undefined4 *)pPVar2);
    bVar1 = Player::FUN_0040ce70(pPVar2,piVar3);
    pPVar2 = (Player *)CONCAT31(extraout_var_00,bVar1);
    if (pPVar2 != (Player *)0x0) {
      pConditionValue_00 = &this->field6_0x24;
      S9::FUN_0045adb0(pS9__1,local_8);
      bVar1 = Player::CheckCondition(pPVar2,(int *)pConditionValue_00);
      if (CONCAT31(extraout_var_01,bVar1) != 0) {
        piVar3 = &this->m_nMovementBitmask;
        pPVar2 = (Player *)(local_8 + 1);
        S9::FUN_0045ada0(pS9__1,(undefined4 *)pPVar2);
        bVar1 = Player::FUN_0040ce70(pPVar2,piVar3);
        if (CONCAT31(extraout_var_02,bVar1) != 0) {
          return 1;
        }
      }
    }
  }
  return 0;
}


byte __thiscall S9__Game_FUN_0045bc90(Game *this,S9 *pS9)

{
  byte bVar1;
  Player *pPVar2;
  byte bVar3;
  int iVar4;
  Player **pPlayer;
  
  bVar1 = this->byte_;
  iVar4 = 0;
  pPlayer = this->cPlayer;
  if (bVar1 != 0) {
    do {
      pPVar2 = *pPlayer;
      if (pPVar2->NextPlayer != false) {
        bVar3 = CameraOrPhysics::FUN_0045af40
                          ((CameraOrPhysics *)&pPVar2->CameraOrPhysics,pS9);
        if (bVar3 != 0) {
          return 1;
        }
        if ((pPVar2->field643_0x2d0 != '\0') &&
           (bVar3 = CameraOrPhysics::FUN_0045af40
                              ((CameraOrPhysics *)&pPVar2->field_0x208,pS9),
           bVar3 != 0)) {
          return 1;
        }
      }
      iVar4 = iVar4 + 1;
      pPlayer = pPlayer + 1;
    } while (iVar4 < (int)(uint)bVar1);
  }
  return 0;
}


void __thiscall S9__S9_FUN_004ba5e0(S9 *this)

{
  _DAT_00662bd4 = Decoder_DecodeFloat(this);
  _DAT_00662bf8 = Decoder_DecodeFloat(this->Arr_24 + 4);
  _DAT_00662bac = Decoder_DecodeFloat(this->Arr_24 + 8);
  _DAT_00662bfc = Decoder_DecodeFloat(this->Arr_24 + 0xc);
  return;
}


void __thiscall S9__FUN_004ba720(S9 *this)

{
  SpriteS1 *pSVar1;
  SpriteS1 *pSVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int local_c [3];
  
  S9_FUN_004ba5e0(this);
  piVar6 = local_c;
  pSVar2 = (SpriteS1 *)(local_c + 1);
  local_c[0] = 2;
  pSVar1 = S9_FUN_00401b20(this,(SpriteS1 *)(local_c + 2),
                           (int *)(this->Arr_24 + 4));
  pSVar2 = Model::FUN_00401bf0((Model *)pSVar1,pSVar2,piVar6);
  iVar3 = Decoder_DecodeFloat(pSVar2);
  piVar6 = local_c;
  pSVar2 = (SpriteS1 *)(local_c + 2);
  local_c[0] = 2;
  pSVar1 = S9_FUN_00401b20((S9 *)(this->Arr_24 + 8),(SpriteS1 *)(local_c + 1),
                           (int *)(this->Arr_24 + 0xc));
  pSVar2 = Model::FUN_00401bf0((Model *)pSVar1,pSVar2,piVar6);
  iVar4 = Decoder_DecodeFloat(pSVar2);
  piVar6 = local_c;
  pSVar2 = (SpriteS1 *)(local_c + 2);
  local_c[0] = 2;
  pSVar1 = S9_FUN_00401b20((S9 *)(this->Arr_24 + 0x10),(SpriteS1 *)(local_c + 1)
                           ,(int *)(this->Arr_24 + 0x14));
  pSVar2 = Model::FUN_00401bf0((Model *)pSVar1,pSVar2,piVar6);
  iVar5 = Decoder_DecodeFloat(pSVar2);
  FUN_0046b440(iVar3,iVar4,iVar5,0,0x400);
  return;
}


uint __thiscall S9__FUN_004bb020(void *this,S9 *param_2)

{
  S9 *this_00;
  bool bVar1;
  void *pvVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  uint uVar5;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  undefined3 extraout_var_07;
  undefined3 extraout_var_08;
  undefined3 extraout_var_09;
  undefined3 extraout_var_10;
  undefined3 extraout_var_11;
  undefined3 extraout_var_12;
  undefined3 extraout_var_13;
  undefined3 extraout_var_14;
  void *pvVar6;
  int *piVar7;
  S9 *pSVar8;
  SpriteS1 *pSVar9;
  SpriteS1 *pSVar10;
  SpriteS1 *pSVar11;
  undefined3 extraout_var_15;
  undefined3 extraout_var_16;
  undefined3 extraout_var_17;
  undefined3 extraout_var_18;
  S9 *pSVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  undefined1 *puVar17;
  undefined1 *puVar18;
  int local_38;
  undefined1 local_34 [4];
  undefined1 local_30 [4];
  int local_2c;
  int local_28;
  S9 local_24;
  undefined1 local_8 [4];
  undefined4 local_4;
  undefined3 extraout_var_02;
  
  FUN_004ba0a0(*(void **)((int)this + 0xc),&local_2c,&local_28);
  puVar18 = local_30;
  puVar17 = local_34;
  iVar16 = (int)this + 0x18;
  iVar14 = (int)this + 0x14;
  iVar13 = iVar14;
  iVar15 = iVar16;
  pvVar2 = PedPool_Get(this,&local_38);
  this_00 = param_2;
  pvVar6 = pvVar2;
  S9::FUN_0045add0(param_2,(S9 *)&param_2);
  puVar3 = (undefined4 *)&local_24;
  S9::FUN_0045adb0(this_00,puVar3);
  FUN_0042a720(puVar3,pvVar2,pvVar6,iVar13,iVar15,puVar17,puVar18);
  piVar4 = (int *)Texture_Find(&local_2c,&param_2);
  bVar1 = Player::FUN_0040ce70((Player *)local_34,piVar4);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    bVar1 = Player::CheckCondition((Player *)local_34,&local_2c);
    if (CONCAT31(extraout_var_00,bVar1) != 0) {
      piVar4 = (int *)Texture_Find(&local_28,&param_2);
      bVar1 = Player::FUN_0040ce70((Player *)local_30,piVar4);
      if (CONCAT31(extraout_var_01,bVar1) != 0) {
        bVar1 = Player::CheckCondition((Player *)local_30,&local_28);
        uVar5 = CONCAT31(extraout_var_02,bVar1);
        if (uVar5 != 0) goto LAB_004bb39a;
      }
    }
  }
  puVar18 = local_30;
  puVar17 = local_34;
  iVar13 = iVar14;
  iVar15 = iVar16;
  pvVar2 = PedPool_Get(this,&param_2);
  pvVar6 = pvVar2;
  S9::FUN_0045add0(this_00,&local_24);
  piVar4 = &local_38;
  S9::FUN_0045ada0(this_00,piVar4);
  FUN_0042a720(piVar4,pvVar2,pvVar6,iVar13,iVar15,puVar17,puVar18);
  piVar4 = (int *)Texture_Find(&local_2c,&param_2);
  bVar1 = Player::FUN_0040ce70((Player *)local_34,piVar4);
  if (CONCAT31(extraout_var_03,bVar1) != 0) {
    bVar1 = Player::CheckCondition((Player *)local_34,&local_2c);
    if (CONCAT31(extraout_var_04,bVar1) != 0) {
      piVar4 = (int *)Texture_Find(&local_28,&param_2);
      bVar1 = Player::FUN_0040ce70((Player *)local_30,piVar4);
      if (CONCAT31(extraout_var_05,bVar1) != 0) {
        bVar1 = Player::CheckCondition((Player *)local_30,&local_28);
        uVar5 = CONCAT31(extraout_var_06,bVar1);
        if (uVar5 != 0) goto LAB_004bb39a;
      }
    }
  }
  puVar18 = local_30;
  puVar17 = local_34;
  iVar13 = iVar14;
  iVar15 = iVar16;
  pvVar2 = PedPool_Get(this,&param_2);
  pvVar6 = pvVar2;
  S9::FUN_0045adc0(this_00,(undefined4 *)&local_24);
  piVar4 = &local_38;
  S9::FUN_0045ada0(this_00,piVar4);
  FUN_0042a720(piVar4,pvVar2,pvVar6,iVar13,iVar15,puVar17,puVar18);
  piVar4 = (int *)Texture_Find(&local_2c,&param_2);
  bVar1 = Player::FUN_0040ce70((Player *)local_34,piVar4);
  if (CONCAT31(extraout_var_07,bVar1) != 0) {
    bVar1 = Player::CheckCondition((Player *)local_34,&local_2c);
    if (CONCAT31(extraout_var_08,bVar1) != 0) {
      piVar4 = (int *)Texture_Find(&local_28,&param_2);
      bVar1 = Player::FUN_0040ce70((Player *)local_30,piVar4);
      if (CONCAT31(extraout_var_09,bVar1) != 0) {
        bVar1 = Player::CheckCondition((Player *)local_30,&local_28);
        uVar5 = CONCAT31(extraout_var_10,bVar1);
        if (uVar5 != 0) goto LAB_004bb39a;
      }
    }
  }
  puVar18 = local_30;
  puVar17 = local_34;
  iVar13 = iVar14;
  iVar15 = iVar16;
  pvVar2 = PedPool_Get(this,&param_2);
  pvVar6 = pvVar2;
  S9::FUN_0045adc0(this_00,(undefined4 *)&local_24);
  piVar4 = &local_38;
  S9::FUN_0045adb0(this_00,piVar4);
  FUN_0042a720(piVar4,pvVar2,pvVar6,iVar13,iVar15,puVar17,puVar18);
  piVar4 = (int *)Texture_Find(&local_2c,&param_2);
  bVar1 = Player::FUN_0040ce70((Player *)local_34,piVar4);
  if (CONCAT31(extraout_var_11,bVar1) != 0) {
    bVar1 = Player::CheckCondition((Player *)local_34,&local_2c);
    if (CONCAT31(extraout_var_12,bVar1) != 0) {
      piVar4 = (int *)Texture_Find(&local_28,&param_2);
      bVar1 = Player::FUN_0040ce70((Player *)local_30,piVar4);
      if (CONCAT31(extraout_var_13,bVar1) != 0) {
        bVar1 = Player::CheckCondition((Player *)local_30,&local_28);
        uVar5 = CONCAT31(extraout_var_14,bVar1);
        if (uVar5 != 0) goto LAB_004bb39a;
      }
    }
  }
  puVar18 = local_30;
  local_38 = 2;
  local_24.Arr_24._0_4_ = (S46 *)0x2;
  puVar17 = local_34;
  pvVar6 = PedPool_Get(this,&param_2);
  piVar4 = &local_38;
  piVar7 = (int *)((int)&local_24 + 4);
  pSVar11 = (SpriteS1 *)piVar7;
  S9::FUN_0045adc0(this_00,(undefined4 *)((int)&local_24 + 8));
  pSVar9 = (SpriteS1 *)((int)&local_24 + 0xc);
  pSVar8 = (S9 *)((int)&local_24 + 0x10);
  S9::FUN_0045add0(this_00,pSVar8);
  pSVar9 = S9::S9_FUN_00401b20(pSVar8,pSVar9,piVar7);
  pSVar10 = Model::FUN_00401bf0((Model *)pSVar9,pSVar11,piVar4);
  piVar4 = (int *)&local_24;
  pSVar9 = (SpriteS1 *)((int)&local_24 + 0x14);
  pSVar8 = (S9 *)((int)&local_24 + 0x18);
  S9::FUN_0045ada0(this_00,(undefined4 *)pSVar8);
  pSVar11 = (SpriteS1 *)((int)&local_24 + 0x1c);
  pSVar12 = pSVar8;
  S9::FUN_0045adb0(this_00,&local_4);
  pSVar11 = S9::S9_FUN_00401b20(pSVar8,pSVar11,(int *)pSVar12);
  pSVar9 = Model::FUN_00401bf0((Model *)pSVar11,pSVar9,piVar4);
  FUN_0042a720(pSVar9,pSVar10,pvVar6,iVar14,iVar16,puVar17,puVar18);
  piVar4 = (int *)Texture_Find(&local_2c,&param_2);
  bVar1 = Player::FUN_0040ce70((Player *)local_34,piVar4);
  uVar5 = CONCAT31(extraout_var_15,bVar1);
  if (uVar5 != 0) {
    bVar1 = Player::CheckCondition((Player *)local_34,&local_2c);
    uVar5 = CONCAT31(extraout_var_16,bVar1);
    if (uVar5 != 0) {
      piVar4 = (int *)Texture_Find(&local_28,&param_2);
      bVar1 = Player::FUN_0040ce70((Player *)local_30,piVar4);
      uVar5 = CONCAT31(extraout_var_17,bVar1);
      if (uVar5 != 0) {
        bVar1 = Player::CheckCondition((Player *)local_30,&local_28);
        uVar5 = CONCAT31(extraout_var_18,bVar1);
        if (uVar5 != 0) {
LAB_004bb39a:
          return CONCAT31((int3)(uVar5 >> 8),1);
        }
      }
    }
  }
  return uVar5 & 0xffffff00;
}


