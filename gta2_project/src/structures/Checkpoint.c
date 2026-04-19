// Module: S56
// Functions working with structure S56
// Generated from gta2.exe.c

#include "../../include/common.h"

S56 * __thiscall S56__S56_FUN_00446860(S56 *this)

{
  int iVar1;
  S56 *pSVar2;
  
  pSVar2 = this;
  for (iVar1 = 0x100; iVar1 != 0; iVar1 = iVar1 + -1) {
    pSVar2->Arr[0] = 0;
    pSVar2 = (S56 *)(pSVar2->Arr + 1);
  }
  return this;
}


S56 * __thiscall S56__S56(S56 *this)

{
  S56_FUN_00446860(this);
  return this;
}


void __thiscall S56__S56_FUN_00446cb0(S56 *this,uint param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = DAT_005e6678;
  if (DAT_005e6678 < (param_1 & 0xff) + DAT_005e6678) {
    do {
      puVar1 = (undefined4 *)FUN_00446820(this,DAT_005e6660,uVar2);
      FUN_00446b80(puVar1);
      uVar2 = uVar2 + 1;
    } while (uVar2 < (param_1 & 0xff) + DAT_005e6678);
  }
  return;
}


void __thiscall S56__S56_FUN_00446d00(S56 *this,uint param_1)

{
  byte *pbVar1;
  
  _DAT_00662bd4 = DAT_005e6660;
  _DAT_00662bf8 = ((param_1 & 0xff) - 1) + DAT_005e6660;
  for (pbVar1 = FUN_00446740(this,DAT_005e6678);
      (pbVar1 != (byte *)0x0 && ((int)(uint)*pbVar1 <= _DAT_00662bf8));
      pbVar1 = *(byte **)(pbVar1 + 8)) {
    FUN_00446b80(*(undefined4 **)(pbVar1 + 4));
  }
  return;
}


void __thiscall S56__S56_FUN_00447390(S56 *this)

{
  void *pvVar1;
  int iVar2;
  SpriteS1 *pSVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  CameraOrPhysics *pCameraOrPhysics;
  
  pCameraOrPhysics = gCameraOrPhysics;
  pvVar1 = Decoder_ProcessData(&gCameraOrPhysics->CamPosition,
                             (S110 *)&stack0xfffffffc,&DAT_005e672c);
  iVar2 = Decoder_DecodeFloat(pvVar1);
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  else if (0xff < iVar2) {
    iVar2 = 0xff;
  }
  pSVar3 = S9::S9_FUN_00401b20((S9 *)&pCameraOrPhysics->field_148,
                               (SpriteS1 *)&stack0xfffffffc,(int *)&DAT_005e6944
                              );
  iVar4 = Decoder_DecodeFloat(pSVar3);
  if (iVar4 < 0) {
    iVar4 = 0;
  }
  else if (0xff < iVar4) {
    iVar4 = 255;
  }
  pvVar1 = Decoder_ProcessData(&pCameraOrPhysics->PosInterp,
                             (S110 *)&stack0xfffffffc,&DAT_005e672c);
  iVar5 = Decoder_DecodeFloat(pvVar1);
  if (iVar5 < 0) {
    iVar5 = 0;
  }
  else if (0xff < iVar5) {
    iVar5 = 0xff;
  }
  pSVar3 = S9::S9_FUN_00401b20((S9 *)&pCameraOrPhysics->field_164,
                               (SpriteS1 *)&stack0xfffffffc,(int *)&DAT_005e6944
                              );
  iVar6 = Decoder_DecodeFloat(pSVar3);
  if (iVar6 < 0) {
    iVar6 = 0;
  }
  else if (0xff < iVar6) {
    iVar6 = 0xff;
  }
  S56_FUN_00446d60(this,iVar2,iVar4,iVar5,iVar6);
  return;
}


byte __thiscall S56__S56_FUN_00447480(S56 *this,SpriteS1 *param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  
  bVar2 = 0;
  gCollide->field1_0x4 = gCollide->field1_0x4 + 1;
  SpriteS1::S38_FUN_004bcb40(param_1);
  FUN_004bc580(param_1->S3_arr5031[0].SpriteS3);
  iVar3 = _DAT_00662bac;
  if (_DAT_00662bac <= _DAT_00662bfc) {
    do {
      bVar1 = FUN_00446f30(iVar3,param_1);
      bVar2 = bVar2 | bVar1;
      iVar3 = iVar3 + 1;
    } while (iVar3 <= _DAT_00662bfc);
  }
  return bVar2;
}


void __thiscall S56__S56_FUN_00447a60(S56 *this,int param_1,SpriteS1 *pSpriteS1)

{
  SpriteS1 *pSVar1;
  SpriteS1 *pSVar2;
  uint uVar3;
  SpriteS1 *pSVar4;
  SpriteS1 *psSpriteS1;
  
  psSpriteS1 = (SpriteS1 *)this->Arr[param_1];
  pSVar4 = (SpriteS1 *)0x0;
  uVar3 = _DAT_00662bd4;
  if ((int)_DAT_00662bd4 <= _DAT_00662bf8) {
    do {
      for (; (psSpriteS1 != (SpriteS1 *)0x0 &&
             ((int)(uint)*(byte *)&psSpriteS1->FirstElement <= (int)uVar3));
          psSpriteS1 = (SpriteS1 *)psSpriteS1->S3_arr5031[0].Car) {
        if (*(byte *)&psSpriteS1->FirstElement == uVar3) {
          pSVar4 = S54::S54_FUN_00447350(gS54);
          uVar3 = uVar3 + 1;
          pSVar4->FirstElement = pSpriteS1;
          pSVar4->S3_arr5031[0].SpriteS1 = psSpriteS1->S3_arr5031[0].SpriteS1;
          psSpriteS1->S3_arr5031[0].SpriteS1 = pSVar4;
          if (_DAT_00662bf8 < (int)uVar3) {
            return;
          }
        }
        pSVar4 = psSpriteS1;
      }
      pSVar1 = S54::S54_FUN_00447350(gS54);
      pSVar1->FirstElement = pSpriteS1;
      pSVar2 = pSpriteS1;
      S55::S55_FUN_00447370(gS55);
      if (pSVar4 == (SpriteS1 *)0x0) {
        this->Arr[param_1] = pSVar2;
      }
      else {
        pSVar4->S3_arr5031[0].Car = (Car *)pSVar2;
      }
      pSVar2->S3_arr5031[0].Car = (Car *)psSpriteS1;
      pSVar2->S3_arr5031[0].SpriteS1 = pSVar1;
      *(char *)&pSVar2->FirstElement = (char)uVar3;
      pSVar1->S3_arr5031[0].SpriteS1 = (SpriteS1 *)0x0;
      psSpriteS1 = (SpriteS1 *)pSVar2->S3_arr5031[0].Car;
      uVar3 = uVar3 + 1;
      pSVar4 = pSVar2;
    } while ((int)uVar3 <= _DAT_00662bf8);
  }
  return;
}


void __thiscall S56__S56_FUN_00447ba0(S56 *this,SpriteS1 *param_1)

{
  int iVar1;
  uint uVar2;
  SpriteS1 *pSprite;
  
  pSprite = param_1;
  iVar1 = Decoder_DecodeFloat(&param_1->S3_arr5031[0].PositionY);
  uVar2 = Decoder_DecodeFloat(&param_1->S3_arr5031[0].PositionX);
  S56_FUN_004479d0(this,uVar2,iVar1,pSprite);
  return;
}


void __thiscall S56__S56_FUN_00447bd0(S56 *this,SpriteS1 *pS46)

{
  int iVar1;
  uint uVar2;
  SpriteS1 *pS46_1;
  
  pS46_1 = pS46;
  iVar1 = Decoder_DecodeFloat(&pS46->S3_arr5031[0].PositionY);
  uVar2 = Decoder_DecodeFloat(&pS46->S3_arr5031[0].PositionX);
  S56_FUN_00447850(this,uVar2,iVar1,(S46 *)pS46_1);
  return;
}


void __thiscall S56__S56_FUN_00447c00(S56 *this,SpriteS1 *pSpriteS1)

{
  int iVar1;
  
  SpriteS1::S38_FUN_004bcb40(pSpriteS1);
  FUN_004bc580(pSpriteS1->S3_arr5031[0].SpriteS3);
  iVar1 = _DAT_00662bac;
  if (_DAT_00662bac <= _DAT_00662bfc) {
    do {
      S56_FUN_00447a60(this,iVar1,pSpriteS1);
      iVar1 = iVar1 + 1;
    } while (iVar1 <= _DAT_00662bfc);
  }
  return;
}


void __thiscall S56__S56_FUN_00447c40(S56 *this,SpriteS1 *pSpriteS1)

{
  int iVar1;
  
  FUN_004bc580(pSpriteS1->S3_arr5031[0].SpriteS3);
  iVar1 = _DAT_00662bac;
  if (_DAT_00662bac <= _DAT_00662bfc) {
    do {
      FUN_00447900(this,iVar1,(S46 *)pSpriteS1);
      iVar1 = iVar1 + 1;
    } while (iVar1 <= _DAT_00662bfc);
  }
  return;
}


