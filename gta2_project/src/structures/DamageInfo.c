// Module: S116
// Functions working with structure S116
// Generated from gta2.exe.c

#include "common.h"

S116 * __thiscall S116__S166(S116 *this)

{
  S116 *local_4;
  
  this->field0_0x0 = 0x2a2a2a2a;
  local_4 = this;
  Decoder_ShiftLeft(&local_4,(void *)0x0);
  this->S116 = local_4;
  Decoder_ShiftLeft(&local_4,(void *)0x0);
  *(S116 **)&this->field_0x8 = local_4;
  Decoder_ShiftLeft(&local_4,(void *)0x0);
  this->field10_0x10 = 0xffffff;
  *(S116 **)&this->field_0xc = local_4;
  this->S116_1 = (S116 *)0x0;
  this->field20_0x24 = 0;
  this->field19_0x20 = 0;
  this->field_0x14 = 0;
  this->field_0x15 = 0;
  this->field_0x16 = 0;
  this->field_0x17 = 0;
  this->field_0x18 = 0;
  return this;
}


void __thiscall S116__S116_FUN_004613b0(S116 *this)

{
  int iVar1;
  int iVar2;
  
  if (this->field20_0x24 == 0) {
    iVar1 = Decoder_DecodeFloat(&this->field_0x8);
    iVar2 = Decoder_DecodeFloat(&this->S116);
    *(undefined4 *)(_Buffer_0x4000 + ((iVar1 >> 2) * 0x40 + (iVar2 >> 2)) * 4) =
         this->field19_0x20;
  }
  else {
    *(undefined4 *)(this->field20_0x24 + 0x20) = this->field19_0x20;
  }
  if (this->field19_0x20 != 0) {
    *(undefined4 *)(this->field19_0x20 + 0x24) = this->field20_0x24;
  }
  return;
}


void __thiscall S116__S115_FUN_0047f450(S115 *this,S116 *pS116)

{
  S116 *pSVar1;
  S116 *pSVar2;
  S116 *pSVar3;
  
  pSVar3 = (S116 *)0x0;
  pSVar1 = this->S116;
  if (this->S116 != (S116 *)0x0) {
    while (pSVar2 = pSVar1, pSVar2 != pS116) {
      pSVar1 = pSVar2->S116_1;
      pSVar3 = pSVar2;
      if (pSVar2->S116_1 == (S116 *)0x0) {
        return;
      }
    }
    FUN_0045b320(&pSVar2->field0_0x0);
    if (pSVar3 != (S116 *)0x0) {
      pSVar3->S116_1 = pSVar2->S116_1;
      pSVar2->S116_1 = this->BeginArr;
      this->BeginArr = pSVar2;
      return;
    }
    this->S116 = pSVar2->S116_1;
    pSVar2->S116_1 = this->BeginArr;
    this->BeginArr = pSVar2;
  }
  return;
}


void __thiscall S116__S115_FUN_0047f4b0(S115 *this,S116 *pS116)

{
  FUN_0045b320(&pS116->field0_0x0);
  pS116->S116_1 = this->BeginArr;
  this->BeginArr = pS116;
  return;
}


void __thiscall S116__S115_FUN_0047f4f0(S115 *this,S116 *pS116)

{
  S116::S116_FUN_004613b0(pS116);
  if (pS116->field_0x14 != '\0') {
    S115_FUN_0047f450(this,pS116);
    return;
  }
  S115_FUN_0047f4b0(this,pS116);
  return;
}


void __thiscall S116__S116_FUN_0048a510(S116 *this)

{
  int iVar1;
  
  iVar1 = this->field0_0x0;
  *(undefined2 *)((int)&this->S116 + 2) = 0;
  if (iVar1 == 0) {
    *(undefined1 *)(*(byte *)&this->S116 + 0x780 + _gS102) = 0;
    return;
  }
  *(undefined1 *)(*(byte *)&this->S116 + 0x3c0 + _gS100) = 0;
  return;
}


void __thiscall S116__S116_FUN_00491240(S116 *this)

{
  byte bVar1;
  bool bVar2;
  undefined4 *puVar3;
  void *pvVar4;
  int iVar5;
  int *piVar6;
  undefined3 extraout_var;
  undefined4 *puVar7;
  undefined3 extraout_var_00;
  undefined2 extraout_var_01;
  void *pvVar8;
  undefined2 extraout_var_02;
  undefined4 uVar9;
  SpriteS1 *extraout_ECX;
  undefined4 extraout_ECX_00;
  SpriteS1 *extraout_ECX_01;
  SpriteS1 *pSVar10;
  Player *pPVar11;
  int iVar12;
  undefined4 uVar13;
  Player *pPVar14;
  short sVar15;
  Player *pPVar16;
  undefined1 local_c [4];
  undefined1 local_8 [4];
  undefined1 local_4 [4];
  
  bVar2 = true;
  if (((ushort)this->field17_0x1a < 0x5a) &&
     (iVar12 = *(int *)(*(int *)&this->field_0x14 + 4),
     bVar1 = Game::FUN_0045bc10(gGame,*(undefined4 *)(iVar12 + 0x14),
                                *(undefined4 *)(iVar12 + 0x18)), bVar1 == 0)) {
    bVar2 = false;
  }
  DAT_00669e82 = 0;
  if (!bVar2) goto switchD_004912d4_caseD_3c;
  switch(this->field10_0x10) {
  case 0x12:
  case 0x21:
    FUN_0048eb00();
    break;
  case 0x13:
  case 0x20:
    FUN_0048ed40(this);
    goto LAB_004912b3;
  case 0x14:
    FUN_0048ef90();
LAB_004912b3:
    DAT_00669e82 = 1;
  }
  puVar3 = (undefined4 *)((ushort)this->field17_0x1a - 0x3b);
  switch(this->field17_0x1a) {
  case 0x3b:
  case 0x45:
  case 0x4f:
  case 0x59:
    Decoder_ShiftLeft(local_c,(void *)0x91);
    puVar7 = puVar3;
    Decoder_ShiftLeft(local_8,(void *)0x71);
    pvVar8 = (void *)CONCAT22(extraout_var_01,_DAT_00669ee0);
    iVar12 = 5;
    pvVar4 = pvVar8;
    Decoder_ShiftLeft(&stack0xffffffd4,(void *)0x2);
    pvVar4 = Object::S60_FUN_00485540
                       (_gObject,*puVar7,*puVar3,pvVar8,pvVar4,iVar12);
    if (pvVar4 != (void *)0x0) {
      Texture_Find(&DAT_00669fcc,local_4);
      iVar12 = *(int *)(*(int *)&this->field_0x14 + 4);
      iVar12 = FUN_004854c0(0x7f,*(undefined4 *)(iVar12 + 0x14),
                            *(undefined4 *)(iVar12 + 0x18));
      uVar9 = CONCAT22(extraout_var_02,_DAT_00669ee0);
      uVar13 = uVar9;
      Decoder_ShiftLeft(&stack0xffffffdc,(void *)0x0);
      sVar15 = (short)uVar13;
      pSVar10 = extraout_ECX;
      Decoder_ShiftLeft(&stack0xffffffd8,(void *)0x0);
      SpriteS1::FUN_004b9d50
                (*(SpriteS1 **)(iVar12 + 4),*(int *)((int)pvVar4 + 4),pSVar10,
                 uVar9,sVar15);
      Decoder_ShiftLeft(&stack0xffffffdc,(void *)0x3);
      Decoder_ShiftLeft(&stack0xffffffd4,(void *)0x2);
      Decoder_ShiftLeft(&stack0xffffffd0,(void *)0x8a);
      Decoder_ShiftLeft(&stack0xffffffcc,(void *)0x5e);
      iVar5 = FUN_00485370();
      uVar13 = extraout_ECX_00;
      sVar15 = _DAT_00669ee0;
      Decoder_ShiftLeft(&stack0xffffffdc,(void *)0x0);
      pSVar10 = extraout_ECX_01;
      Decoder_ShiftLeft(&stack0xffffffd8,(void *)0x0);
      SpriteS1::FUN_004b9d50
                (*(SpriteS1 **)(iVar12 + 4),*(int *)(iVar5 + 4),pSVar10,uVar13,
                 sVar15);
    }
  }
switchD_004912d4_caseD_3c:
  puVar3 = &this->field20_0x24;
  if ((ushort)this->field17_0x1a < 0x1f) {
    bVar2 = S169::FUN_00403800((S169 *)puVar3,(int *)&DAT_0066a17c);
    if (CONCAT31(extraout_var_00,bVar2) != 0) {
      *puVar3 = _DAT_0066a17c;
    }
    piVar6 = (int *)Decoder_ReadInt(&DAT_00669fcc,local_4,(int *)&DAT_00669ff0);
    FUN_0040e550(puVar3,piVar6);
  }
  else {
    piVar6 = (int *)WorldCoordinateToScreenCoord
                              (&DAT_0066a17c,local_4,(int *)&DAT_00669ff0);
    bVar2 = S169::FUN_00403800((S169 *)puVar3,piVar6);
    if (CONCAT31(extraout_var,bVar2) != 0) {
      puVar7 = (undefined4 *)
               WorldCoordinateToScreenCoord
                         (&DAT_0066a17c,local_4,(int *)&DAT_00669ff0);
      *puVar3 = *puVar7;
    }
    piVar6 = (int *)Decoder_ReadInt(&DAT_00669fcc,local_4,(int *)&DAT_00669ff0);
    FUN_0040e530(puVar3,piVar6);
  }
  if (0x32 < (ushort)this->field17_0x1a) {
    FUN_00490d60(this,this->field17_0x1a);
  }
  if (this->field17_0x1a == 99) {
    iVar12 = *(int *)(*(int *)&this->field_0x14 + 4);
    pPVar11 = *(Player **)(iVar12 + 0x18);
    pPVar14 = *(Player **)(iVar12 + 0x14);
    pPVar16 = pPVar11;
    Decoder_ShiftLeft(&stack0xffffffd8,(void *)0x8);
    Game::Game_FUN_0045bb00(gGame,pPVar11,pPVar14,pPVar16);
  }
  if (this->field17_0x1a != 9999) {
    this->field17_0x1a = this->field17_0x1a + -1;
  }
  if (9999 < (ushort)this->field17_0x1a) {
    this->field17_0x1a = 1;
  }
  return;
}


void __thiscall S116__S116_FUN_00491550(S116 *this,undefined1 param_1)

{
  undefined2 *puVar1;
  ushort uVar2;
  undefined1 uVar3;
  bool bVar4;
  byte bVar5;
  int *in_EAX;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  Particle1 *pPVar6;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  void *pvVar7;
  short *psVar8;
  undefined2 *puVar9;
  SpriteS1 *pSVar10;
  undefined3 extraout_var_07;
  undefined4 *puVar11;
  undefined3 extraout_var_08;
  short *unaff_ESI;
  void *unaff_EDI;
  Particle *this_00;
  int iVar12;
  short *psVar13;
  Player *pPVar14;
  int *piVar15;
  Player *pPVar16;
  byte local_7d;
  undefined1 local_7c [2];
  short local_7a;
  short local_78;
  undefined1 local_76 [2];
  short local_74;
  short local_72;
  undefined1 local_70 [2];
  short local_6e;
  short local_6c;
  undefined1 local_6a [2];
  short local_68;
  short local_66;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined1 local_50 [4];
  undefined1 local_4c [12];
  undefined1 local_40 [4];
  undefined1 local_3c [12];
  undefined1 local_30 [4];
  undefined1 local_2c [12];
  undefined1 local_20 [4];
  undefined1 local_1c [12];
  undefined1 local_10 [4];
  undefined1 local_c [12];
  
  iVar12 = *(int *)&this->field_0x14;
  Decoder_ShiftLeft(&local_54,(void *)0xfe);
  bVar4 = Player::FUN_0040ce70((Player *)(*(int *)(iVar12 + 4) + 0x14),in_EAX);
  if (CONCAT31(extraout_var,bVar4) == 0) {
    iVar12 = *(int *)(iVar12 + 4);
    bVar4 = Player::CheckCondition
                      ((Player *)(iVar12 + 0x14),(int *)&DAT_00669f14);
    piVar15 = (int *)CONCAT31(extraout_var_00,bVar4);
    if (piVar15 == (int *)0x0) {
      Decoder_ShiftLeft(&local_54,(void *)0xfe);
      bVar4 = Player::FUN_0040ce70((Player *)(iVar12 + 0x18),piVar15);
      if ((CONCAT31(extraout_var_01,bVar4) == 0) &&
         (local_7d = Player::CheckCondition
                               ((Player *)(iVar12 + 0x18),(int *)&DAT_00669f14),
         this_00 = _gParticle, uVar3 = local_7d,
         CONCAT31(extraout_var_02,local_7d) == 0)) {
        do {
          DAT_00669e82 = uVar3;
          bVar4 = Particle::S98_IsNotEmpty(this_00);
          if (bVar4) {
            pPVar6 = Particle::FUN_0048a900(this_00);
            pPVar6->field_0x46 = 0;
            switch(param_1) {
            case 0:
              *(undefined4 *)&pPVar6->field_0x38 = 0x18;
              local_64 = 0x2d;
              bVar5 = Random(&gRandom,(int)&local_64);
              piVar15 = (int *)CONCAT31(extraout_var_03,bVar5);
              Decoder_SetValue(local_50,(short)piVar15);
              pvVar7 = WorldCoordinateToScreenCoord
                                 (&DAT_0066a17c,local_4c,piVar15);
              psVar8 = (short *)FUN_0040f540(local_7c,(int)pvVar7);
              psVar13 = &local_7a;
              pvVar7 = FUN_0040e5a0(&DAT_00669ffc,&local_78,
                                    (short *)&DAT_00669eec,psVar13,psVar8);
              puVar9 = (undefined2 *)
                       FUN_0040e5a0(pvVar7,psVar13,psVar8,unaff_EDI,unaff_ESI);
              puVar1 = (undefined2 *)((int)&this->field19_0x20 + 2);
              *puVar1 = *puVar9;
              FUN_0041fc20(puVar1,puVar1,(S110 *)&DAT_00669fcc,
                           (Ped *)&DAT_00669f80,(Ped *)&DAT_0066a1ec);
              pSVar10 = S9::S9_FUN_00401b20((S9 *)(*(int *)(*(int *)&this->
                                        field_0x14 + 4) + 0x14),
                                        (SpriteS1 *)(local_4c + 4),
                                        (int *)&DAT_00669f80);
              _DAT_00669f80 = pSVar10->FirstElement;
              pSVar10 = (SpriteS1 *)(local_4c + 8);
              break;
            case 1:
              *(undefined4 *)&pPVar6->field_0x38 = 0x19;
              local_60 = 0x5a;
              bVar5 = Random(&gRandom,(int)&local_60);
              piVar15 = (int *)CONCAT31(extraout_var_04,bVar5);
              Decoder_SetValue(local_40,(short)piVar15);
              pvVar7 = WorldCoordinateToScreenCoord
                                 (&DAT_0066a17c,local_3c,piVar15);
              psVar8 = (short *)FUN_0040f540(local_76,(int)pvVar7);
              psVar13 = &local_74;
              pvVar7 = FUN_0040e5a0(&DAT_0066a164,&local_72,
                                    (short *)&DAT_00669eec,psVar13,psVar8);
              puVar9 = (undefined2 *)
                       FUN_0040e5a0(pvVar7,psVar13,psVar8,unaff_EDI,unaff_ESI);
              puVar1 = (undefined2 *)((int)&this->field19_0x20 + 2);
              *puVar1 = *puVar9;
              FUN_0041fc20(puVar1,puVar1,(S110 *)&DAT_00669fcc,
                           (Ped *)&DAT_00669f80,(Ped *)&DAT_0066a1ec);
              pSVar10 = S9::S9_FUN_00401b20((S9 *)(*(int *)(*(int *)&this->
                                        field_0x14 + 4) + 0x14),
                                        (SpriteS1 *)(local_3c + 4),
                                        (int *)&DAT_00669f80);
              _DAT_00669f80 = pSVar10->FirstElement;
              pSVar10 = (SpriteS1 *)(local_3c + 8);
              break;
            case 2:
              *(undefined4 *)&pPVar6->field_0x38 = 0x17;
              local_5c = 0x5a;
              bVar5 = Random(&gRandom,(int)&local_5c);
              piVar15 = (int *)CONCAT31(extraout_var_05,bVar5);
              Decoder_SetValue(local_30,(short)piVar15);
              pvVar7 = WorldCoordinateToScreenCoord
                                 (&DAT_0066a17c,local_2c,piVar15);
              psVar8 = (short *)FUN_0040f540(local_70,(int)pvVar7);
              psVar13 = &local_6e;
              pvVar7 = FUN_0040e5a0(&DAT_0066a0a0,&local_6c,
                                    (short *)&DAT_00669eec,psVar13,psVar8);
              puVar9 = (undefined2 *)
                       FUN_0040e5a0(pvVar7,psVar13,psVar8,unaff_EDI,unaff_ESI);
              puVar1 = (undefined2 *)((int)&this->field19_0x20 + 2);
              *puVar1 = *puVar9;
              FUN_0041fc20(puVar1,puVar1,(S110 *)&DAT_00669fcc,
                           (Ped *)&DAT_00669f80,(Ped *)&DAT_0066a1ec);
              pSVar10 = S9::S9_FUN_00401b20((S9 *)(*(int *)(*(int *)&this->
                                        field_0x14 + 4) + 0x14),
                                        (SpriteS1 *)(local_2c + 4),
                                        (int *)&DAT_00669f80);
              _DAT_00669f80 = pSVar10->FirstElement;
              pSVar10 = (SpriteS1 *)(local_2c + 8);
              break;
            case 3:
              *(undefined4 *)&pPVar6->field_0x38 = 0x16;
              local_58 = 0x5a;
              bVar5 = Random(&gRandom,(int)&local_58);
              piVar15 = (int *)CONCAT31(extraout_var_06,bVar5);
              Decoder_SetValue(local_20,(short)piVar15);
              pvVar7 = WorldCoordinateToScreenCoord
                                 (&DAT_0066a17c,local_1c,piVar15);
              psVar8 = (short *)FUN_0040f540(local_6a,(int)pvVar7);
              psVar13 = &local_68;
              pvVar7 = FUN_0040e5a0(&DAT_00669f84,&local_66,
                                    (short *)&DAT_00669eec,psVar13,psVar8);
              puVar9 = (undefined2 *)
                       FUN_0040e5a0(pvVar7,psVar13,psVar8,unaff_EDI,unaff_ESI);
              puVar1 = (undefined2 *)((int)&this->field19_0x20 + 2);
              *puVar1 = *puVar9;
              FUN_0041fc20(puVar1,puVar1,(S110 *)&DAT_00669fcc,
                           (Ped *)&DAT_00669f80,(Ped *)&DAT_0066a1ec);
              pSVar10 = S9::S9_FUN_00401b20((S9 *)(*(int *)(*(int *)&this->
                                        field_0x14 + 4) + 0x14),
                                        (SpriteS1 *)(local_1c + 4),
                                        (int *)&DAT_00669f80);
              _DAT_00669f80 = pSVar10->FirstElement;
              pSVar10 = (SpriteS1 *)(local_1c + 8);
              break;
            default:
              goto switchD_00491614_caseD_4;
            }
            pSVar10 = S9::S9_FUN_00401b20((S9 *)(*(int *)(*(int *)&this->
                                        field_0x14 + 4) + 0x18),pSVar10,
                                        (int *)&DAT_0066a1ec);
            _DAT_0066a1ec = pSVar10->FirstElement;
switchD_00491614_caseD_4:
            pSVar10 = SpriteS1::S38_FUN_00421000(_gSpriteS1);
            pPVar6->SpriteS1 = pSVar10;
            SpriteS1::S38_FUN_004206f0(pSVar10,8);
            pPVar6->field_0x48 = 0;
            pPVar6->field_0x46 = 0;
            *(undefined2 *)&pPVar6->CarSystemManager =
                 *(undefined2 *)((int)&this->field19_0x20 + 2);
            uVar2 = this->field17_0x1a;
            local_54 = CONCAT22((short)((uint)pSVar10 >> 0x10),uVar2);
            if ((uVar2 < 0x3c) && (uVar2 < 0x1e)) {
              local_7d = 4;
            }
            bVar5 = Random(&gRandom,(int)&local_54);
            piVar15 = (int *)CONCAT31(extraout_var_07,bVar5);
            Decoder_SetValue(local_10,(short)piVar15);
            puVar11 = (undefined4 *)
                      WorldCoordinateToScreenCoord
                                (&DAT_0066a1a8,local_c,piVar15);
            *(undefined4 *)&pPVar6->field_0x20 = *puVar11;
            SpriteS1::S38_FUN_004206c0
                      (pPVar6->SpriteS1,*(short *)(_gS57 + 0x8ca4) + 0x28);
            iVar12 = *(int *)&this->field_0x14;
            piVar15 = (int *)&DAT_00669eb8;
            pSVar10 = S9::S9_FUN_00401b20((S9 *)(*(int *)(iVar12 + 4) + 0x1c),
                                          (SpriteS1 *)(local_c + 4),
                                          (int *)&DAT_00669f14);
            bVar4 = Player::FUN_0040ce70((Player *)pSVar10,piVar15);
            iVar12 = *(int *)(iVar12 + 4);
            if (CONCAT31(extraout_var_08,bVar4) == 0) {
              pSVar10 = S9::S9_FUN_00401b20((S9 *)(iVar12 + 0x1c),
                                            (SpriteS1 *)(local_c + 8),
                                            (int *)&DAT_00669f14);
              pSVar10 = pSVar10->FirstElement;
            }
            else {
              pSVar10 = *(SpriteS1 **)(iVar12 + 0x1c);
            }
            SpriteS1::SetPosition
                      (pPVar6->SpriteS1,(int)_DAT_00669f80,(int)_DAT_0066a1ec,
                       (int)pSVar10);
            S56::S56_FUN_00447ba0(gS56_ARR2,pPVar6->SpriteS1);
            FUN_004337f0((int)pPVar6->SpriteS1);
            this_00 = _gParticle;
          }
          local_7d = local_7d + 1;
          uVar3 = DAT_00669e82;
        } while (local_7d < 2);
        if (this->field17_0x1a == 99) {
          iVar12 = *(int *)&this->field_0x14;
          pPVar16 = *(Player **)(*(int *)(iVar12 + 4) + 0x18);
          pPVar14 = *(Player **)(*(int *)(iVar12 + 4) + 0x14);
          Decoder_ShiftLeft(&stack0xffffff64,(void *)0x8);
          Game::Game_FUN_0045bb00(gGame,iVar12,pPVar14,pPVar16);
        }
        if (0x32 < (ushort)this->field17_0x1a) {
          FUN_00490d60(this,this->field17_0x1a);
        }
        uVar2 = this->field17_0x1a;
        if (uVar2 != 9999) {
          if (0x3c < uVar2) {
            this->field17_0x1a = uVar2 - 1;
          }
          if (9999 < (ushort)this->field17_0x1a) {
            this->field17_0x1a = 1;
          }
        }
      }
    }
  }
  return;
}


