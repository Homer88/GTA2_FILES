// Module: S17
// Functions working with structure S17
// Generated from gta2.exe.c

#include "../../include/common.h"

void __thiscall S17__S17_FUN_0045b040(S17 *this)

{
  this->field12019_0x2efc = 0;
  return;
}


S17 * __thiscall S17__S17(S17 *this)

{
  S17 *local_4;
  
  this->DAT_005eb854 = DAT_005eb854;
  this->DAT_005eb854_ = DAT_005eb854;
  local_4 = this;
  Decoder_ShiftLeft(&local_4,(void *)0x0);
  this->s17 = local_4;
  this->field12020_0x2f00 = 0;
  S17_FUN_0045b040(this);
  S17_FUN_0046b620(this,0xf);
  return this;
}


void __thiscall S17__S17_FUN_0046b620(S17 *this,byte param_1)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  
  cVar1 = (char)((ulonglong)((longlong)(int)((uint)param_1 * 2) * 0x55555556) >>
                0x20);
  cVar7 = param_1 * -4 + -1;
  cVar2 = ('3' - param_1) * '\x05';
  cVar3 = cVar1 * '\x02' + cVar7;
  cVar4 = cVar7 + cVar1;
  this->field_0xe = cVar7;
  cVar5 = cVar2 - cVar1;
  cVar6 = cVar2 + cVar1 * -2;
  this->field_0xc = cVar3;
  this->field_0x10 = cVar7;
  this->field_0xd = cVar2 + cVar1 * -3;
  this->field_0xf = cVar5;
  this->field_0x11 = cVar6;
  this->field_0x12 = cVar4;
  this->field_0x13 = cVar5;
  this->field_0x17 = cVar1 * '\x03' + cVar7;
  this->field_0x14 = cVar4;
  this->field_0x18 = cVar4;
  this->field_0x15 = cVar2;
  this->field_0x19 = cVar5;
  this->field_0x16 = cVar6;
  this->field_0x1a = cVar3;
  this->field_0x1b = cVar2;
  return;
}


void __thiscall S17__S17_FUN_0046bb40(S17 *this)

{
  this->field12020_0x2f00 = 0;
  return;
}


void __thiscall S17__FUN_0046bdf0(void *this,S17 *pS17_a1,S17 *pS17,float *param_3)

{
  float10 fVar1;
  float10 fVar2;
  float *pfVar3;
  
  pfVar3 = param_3;
  FUN_0041f980(&stack0xffffffe4,_DAT_006633a0);
  FUN_0046bbf0((void *)pS17->DAT_005eb854,(S17 *)pS17_a1->DAT_005eb854,
               (S17 *)pS17->DAT_005eb854,this,(int)pfVar3);
  fVar1 = S17::EncodedFloatToRegularFloat(pS17_a1);
  fVar2 = S17::EncodedFloatToRegularFloat(&gS17_V3);
  *param_3 = (float)((float10)(uint)gCameraOrPhysics->ScreenY +
                    fVar2 * (float10)(float)fVar1);
  fVar1 = S17::EncodedFloatToRegularFloat(pS17);
  fVar2 = S17::EncodedFloatToRegularFloat(&gS17_V3);
  param_3[1] = (float)((float10)(uint)gCameraOrPhysics->ScreenH +
                      fVar2 * (float10)(float)fVar1);
  fVar1 = S17::EncodedFloatToRegularFloat(&gS17_V2);
  param_3[2] = (float)fVar1;
  return;
}


void __thiscall S17__FUN_0046bdf0(void *this,S17 *pS17_a1,S17 *pS17,float *param_3)

{
  float10 fVar1;
  float10 fVar2;
  float *pfVar3;
  
  pfVar3 = param_3;
  FUN_0041f980(&stack0xffffffe4,_DAT_006633a0);
  FUN_0046bbf0((void *)pS17->DAT_005eb854,(S17 *)pS17_a1->DAT_005eb854,
               (S17 *)pS17->DAT_005eb854,this,(int)pfVar3);
  fVar1 = S17::EncodedFloatToRegularFloat(pS17_a1);
  fVar2 = S17::EncodedFloatToRegularFloat(&gS17_V3);
  *param_3 = (float)((float10)(uint)gCameraOrPhysics->ScreenY +
                    fVar2 * (float10)(float)fVar1);
  fVar1 = S17::EncodedFloatToRegularFloat(pS17);
  fVar2 = S17::EncodedFloatToRegularFloat(&gS17_V3);
  param_3[1] = (float)((float10)(uint)gCameraOrPhysics->ScreenH +
                      fVar2 * (float10)(float)fVar1);
  fVar1 = S17::EncodedFloatToRegularFloat(&gS17_V2);
  param_3[2] = (float)fVar1;
  return;
}


void __thiscall S17__FUN_0046c140(S17 *this,undefined4 *param_2,short *param_3)

{
  undefined4 uVar1;
  int *piVar2;
  void *this_00;
  undefined4 *puVar3;
  S17 *local_4;
  
  uVar1 = *param_2;
  this->DAT_005eb854_ = uVar1;
  piVar2 = (int *)CONCAT22((short)((uint)param_2 >> 0x10),*param_3);
  if (*param_3 != 0) {
    local_4 = this;
    FUN_0041f990(&param_2,(uint)piVar2);
    puVar3 = &param_3;
    this_00 = Decoder_ProcessData(&this->DAT_005eb854_,(S110 *)&local_4,this);
    puVar3 = (undefined4 *)Decoder_ReadInt(this_00,puVar3,piVar2);
    this->s17 = (S17 *)*puVar3;
    return;
  }
  this->DAT_005eb854 = uVar1;
  this->s17 = _DAT_006634b4;
  return;
}


void __thiscall S17__S17_FUN_004720e0(S17 *this)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = this->field12019_0x2efc;
  puVar2 = &this->field_0x14 + iVar1 * 8;
  if (-1 < iVar1 + -1) {
    do {
      FUN_00471f20(this,puVar2,puVar2 + 4);
      puVar2 = puVar2 + -8;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}


void __thiscall S17__S17_FUN_00472110(S17 *this)

{
  undefined1 *puVar1;
  bool bVar2;
  SpriteS1 *pSVar3;
  int *piVar4;
  undefined4 *puVar5;
  void *pvVar6;
  char *pcVar7;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  Player *pPVar13;
  S46 *pSVar14;
  Player *pPVar15;
  Player *pPVar16;
  float10 fVar17;
  SpriteS1 *pSpriteS1;
  int *piVar18;
  SpriteS1 *pSStack_7c;
  undefined1 auStack_78 [16];
  void *pvStack_68;
  SpriteS1 *pSStack_64;
  Player *pPStack_60;
  Player *pPStack_5c;
  int iStack_58;
  undefined1 auStack_50 [4];
  undefined1 auStack_4c [4];
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [28];
  undefined1 auStack_24 [8];
  undefined1 auStack_1c [4];
  undefined1 auStack_18 [4];
  undefined1 auStack_14 [8];
  undefined1 auStack_c [4];
  undefined1 auStack_8 [4];
  undefined1 auStack_4 [4];
  CameraOrPhysics *pCameraOrPhysics;
  
  if (isLighting) {
    fVar17 = EncodedFloatToRegularFloat(this);
    (*(code *)gbh_SetAmbient)((float)fVar17);
    FUN_0046c1a0(&this->DAT_005eb854);
  }
  auStack_78._8_4_ = (char *)0x0;
  do {
    pcVar7 = (char *)auStack_78._8_4_;
    if ((char *)auStack_78._8_4_ != (char *)0x0) {
      cDisplay::S18_FUN_0044b8b0(gDisplay,auStack_78._8_4_);
    }
    pCameraOrPhysics = gCameraOrPhysics;
    if (gSkipTiles == false) {
      pSVar3 = (SpriteS1 *)&stack0xffffffac;
      iVar12 = 8 - (int)pcVar7;
      piVar18 = (int *)&gCameraOrPhysics->field_0xa0;
      pSpriteS1 = pSVar3;
      piVar4 = piVar18;
      FUN_0041f980(auStack_50,iVar12);
      pSVar3 = S9::S9_FUN_00401b20((S9 *)pSVar3,pSpriteS1,piVar4);
      pSStack_64 = pSVar3->FirstElement;
      piVar4 = (int *)Decoder_ReadInt(&pSStack_64,auStack_4c,
                                   (int *)&pCameraOrPhysics->field_0xa4);
      auStack_78._0_4_ = *piVar4;
      puVar5 = (undefined4 *)
               WorldCoordinateToScreenCoord
                         (auStack_78,auStack_48,(int *)&DAT_006636c8);
      auStack_78._12_4_ = *puVar5;
      pSStack_64 = (SpriteS1 *)0x2;
      pSVar3 = Model::FUN_00401bf0((Model *)auStack_78,
                                   (SpriteS1 *)(auStack_48 + 4),
                                   (int *)&pSStack_64);
      pvVar6 = Decoder_ProcessData(&pCameraOrPhysics->field_0x98,
                                 (S110 *)auStack_40,pSVar3);
      auStack_78._4_4_ = Decoder_DecodeFloat(pvVar6);
      pSStack_64 = (SpriteS1 *)0x2;
      pSVar3 = Model::FUN_00401bf0((Model *)auStack_78,
                                   (SpriteS1 *)(auStack_40 + 4),
                                   (int *)&pSStack_64);
      pSVar3 = S9::S9_FUN_00401b20((S9 *)&pCameraOrPhysics->field_0x98,
                                   (SpriteS1 *)(auStack_40 + 8),(int *)pSVar3);
      pvStack_68 = (void *)Decoder_DecodeFloat(pSVar3);
      iVar11 = (int)(((int)pvStack_68 - auStack_78._4_4_) + 1U) / 2;
      uVar8 = (int)pvStack_68 - auStack_78._4_4_ & 0x80000001;
      if ((int)uVar8 < 0) {
        uVar8 = (uVar8 - 1 | 0xfffffffe) + 1;
      }
      if (uVar8 != 1) {
        iVar11 = iVar11 + 1;
      }
      pSStack_64 = (SpriteS1 *)0x2;
      pSVar3 = Model::FUN_00401bf0((Model *)(auStack_78 + 0xc),
                                   (SpriteS1 *)(auStack_40 + 0xc),
                                   (int *)&pSStack_64);
      pvVar6 = Decoder_ProcessData(&pCameraOrPhysics->field_0x9c,
                                 (S110 *)(auStack_40 + 0x10),pSVar3);
      auStack_78._0_4_ = Decoder_DecodeFloat(pvVar6);
      pSStack_64 = (SpriteS1 *)0x2;
      pSVar3 = Model::FUN_00401bf0((Model *)(auStack_78 + 0xc),
                                   (SpriteS1 *)(auStack_40 + 0x14),
                                   (int *)&pSStack_64);
      pSVar3 = S9::S9_FUN_00401b20((S9 *)&pCameraOrPhysics->field_0x9c,
                                   (SpriteS1 *)(auStack_40 + 0x18),(int *)pSVar3
                                  );
      auStack_78._12_4_ = Decoder_DecodeFloat(pSVar3);
      pSStack_64 = (SpriteS1 *)
                   ((int)((auStack_78._12_4_ - auStack_78._0_4_) + 1) / 2);
      uVar8 = auStack_78._12_4_ - auStack_78._0_4_ & 0x80000001;
      if ((int)uVar8 < 0) {
        uVar8 = (uVar8 - 1 | 0xfffffffe) + 1;
      }
      if (uVar8 != 1) {
        pSStack_64 = (SpriteS1 *)((int)&pSStack_64->FirstElement + 1);
      }
      _DAT_006633a0 = (char *)auStack_78._8_4_;
      pcVar7 = (char *)auStack_78._8_4_;
      FUN_0041f980(auStack_24,auStack_78._8_4_);
      _DAT_00663738 = *(undefined4 *)pcVar7;
      pSVar3 = (SpriteS1 *)(auStack_24 + 4);
      piVar4 = piVar18;
      FUN_0041f980(auStack_1c,iVar12);
      pSVar3 = S9::S9_FUN_00401b20((S9 *)pcVar7,pSVar3,piVar4);
      pSStack_7c = pSVar3->FirstElement;
      bVar2 = Player::IsCurrentPlayer
                        ((Player *)&pSStack_7c,(Player *)&DAT_006634b4);
      uVar9 = _DAT_006634b4;
      if (CONCAT31(extraout_var,bVar2) == 0) {
        puVar5 = (undefined4 *)
                 Decoder_ReadInt(&DAT_00663450,auStack_18,(int *)&pSStack_7c);
        uVar9 = *puVar5;
      }
      _gS17_V2 = uVar9;
      puVar5 = (undefined4 *)
               WorldCoordinateToScreenCoord
                         (&pCameraOrPhysics->HalfWidth,auStack_14,
                          (int *)&gS17_V2);
      uVar9 = auStack_78._8_4_;
      _gS17_V3 = *puVar5;
      pcVar7 = (char *)(auStack_78._8_4_ + 1);
      pSVar3 = (SpriteS1 *)(auStack_14 + 4);
      _DAT_006633ac = pcVar7;
      FUN_0041f980(auStack_c,8 - (int)pcVar7);
      pSVar3 = S9::S9_FUN_00401b20((S9 *)pcVar7,pSVar3,piVar18);
      pSStack_7c = pSVar3->FirstElement;
      bVar2 = Player::IsCurrentPlayer
                        ((Player *)&pSStack_7c,(Player *)&DAT_006634b4);
      uVar10 = _DAT_006634b4;
      if (CONCAT31(extraout_var_00,bVar2) == 0) {
        puVar5 = (undefined4 *)
                 Decoder_ReadInt(&DAT_00663450,auStack_8,(int *)&pSStack_7c);
        uVar10 = *puVar5;
      }
      _DAT_006635fc = uVar10;
      puVar5 = (undefined4 *)
               WorldCoordinateToScreenCoord
                         (&pCameraOrPhysics->HalfWidth,auStack_4,
                          (int *)&DAT_006635fc);
      _DAT_00663504 = *puVar5;
      pSVar14 = (S46 *)auStack_78._12_4_;
      if (((char *)uVar9 == (char *)0x0) && (isLighting != false)) {
        (*(code *)gbh_ResetLights)();
        (*(code *)gbh_SetCamera)
                  ((float)(int)auStack_78._4_4_,(float)(int)auStack_78._0_4_,
                   (float)(int)pvStack_68,(float)(int)auStack_78._12_4_);
        pSVar14 = (S46 *)auStack_78._12_4_;
        FUN_00461400(pvStack_68,auStack_78._4_4_,auStack_78._0_4_,
                     (int)pvStack_68,auStack_78._12_4_);
      }
      S17_FUN_0045b040(this);
      puVar1 = &pSStack_64[-1].S3_arr5031[0x13a6].field_0x3b;
      if (-1 < (int)puVar1) {
        pPVar15 = (Player *)((int)pSVar14 - (int)puVar1);
        iVar11 = iVar11 + -1;
        pPVar13 = (Player *)(puVar1 + auStack_78._0_4_);
        auStack_78._12_4_ = pSStack_64;
        iStack_58 = iVar11;
        do {
          if (-1 < iVar11) {
            pSVar3 = (SpriteS1 *)((int)pvStack_68 - iVar11);
            pPVar16 = (Player *)(&((S200 *)auStack_78._4_4_)->X + iVar11);
            pSStack_64 = (SpriteS1 *)(iVar11 + 1);
            pPStack_60 = pPVar15;
            pPStack_5c = pPVar13;
            do {
              pSStack_7c = pSVar3;
              auStack_78._0_4_ = pPVar15;
              FUN_0046bb90(&pSStack_7c,auStack_78);
              auStack_78._0_4_ = pPVar16;
              FUN_0046bb90(auStack_78,&pPStack_60);
              pSStack_7c = pSVar3;
              auStack_78._0_4_ = pPVar13;
              FUN_0046bb90(&pSStack_7c,auStack_78);
              auStack_78._0_4_ = pPVar16;
              FUN_0046bb90(auStack_78,&pPStack_5c);
              pSVar3 = (SpriteS1 *)((int)&pSVar3->FirstElement + 1);
              pPVar16 = (Player *)((int)pPVar16[-1].string_Arr0x16 + 0x1f);
              pSStack_64 = (SpriteS1 *)
                           &pSStack_64[-1].S3_arr5031[0x13a6].field_0x3b;
            } while (pSStack_64 != (SpriteS1 *)0x0);
            pSStack_64 = (SpriteS1 *)0x0;
            iVar11 = iStack_58;
          }
          pPVar15 = (Player *)&((S200 *)&pPVar15->CurrentPlayer)->Y;
          pPVar13 = (Player *)((int)pPVar13[-1].string_Arr0x16 + 0x1f);
          auStack_78._12_4_ =
               &((SpriteS1 *)(auStack_78._12_4_ + -0x49b28))->S3_arr5031[0x13a6]
                .field_0x3b;
        } while ((undefined1 *)auStack_78._12_4_ != (undefined1 *)0x0);
      }
      S17_FUN_004720e0(this);
      pcVar7 = (char *)auStack_78._8_4_;
    }
    auStack_78._8_4_ = pcVar7 + 1;
  } while ((int)auStack_78._8_4_ < 7);
  cDisplay::S18_FUN_0044b8b0(gDisplay,7);
  return;
}


