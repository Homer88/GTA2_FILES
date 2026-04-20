// Module: S46
// Functions working with structure S46
// Generated from gta2.exe.c

#include "common.h"

void __thiscall S46__S154_FUN_00411a50(AudioManager *this,S46 *param_1)

{
  byte bVar1;
  S46 *pSVar2;
  bool bVar3;
  int *piVar4;
  undefined1 *this_00;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  undefined1 local_8 [4];
  undefined1 local_4 [4];
  
  pSVar2 = param_1;
  puVar5 = *(undefined4 **)
            (*(int *)&this->Elements[(int)((int)&param_1[-1].DATA1 + 3)].
                      field5_0x8 + 0xc);
  if (puVar5 == (undefined4 *)0x0) {
    return;
  }
  if (*(char *)(puVar5 + 1) == '\0') {
    if (this->field_0x3 == '\0') {
      bVar3 = SoundCard::SoundCard_FUN_004b66a0((SoundCard *)&gSoundCard);
      if (bVar3) {
        SoundCard::SoundCard_FUN_004b67b0((SoundCard *)&gSoundCard);
        SoundCard::SoundCard_FUN_004b6700((SoundCard *)&gSoundCard,1);
        bVar1 = this->CDVol;
        goto LAB_00411b5c;
      }
    }
    else {
      bVar3 = SoundCard::SoundCard_FUN_004b66a0((SoundCard *)&gSoundCard);
      if (bVar3) {
        SoundCard::SoundCard_FUN_004b67b0((SoundCard *)&gSoundCard);
        SoundCard::SoundCard_FUN_004b6700((SoundCard *)&gSoundCard,0);
        bVar1 = this->CDVol;
LAB_00411b5c:
        SoundCard::SoundCard_FUN_004b66d0
                  ((SoundCard *)&gSoundCard,(char)(((uint)bVar1 * 6) / 10));
      }
    }
  }
  else {
    this->field_0x3 = 0;
    bVar3 = SoundCard::SoundCard_FUN_004b66a0((SoundCard *)&gSoundCard);
    if ((bVar3) || (DAT_005dc769 == '\0')) {
      SoundCard::SoundCard_FUN_004b67b0((SoundCard *)&gSoundCard);
      SoundCard::SoundCard_FUN_004b6700((SoundCard *)&gSoundCard,2);
      SoundCard::SoundCard_FUN_004b66d0
                ((SoundCard *)&gSoundCard,(char)(((uint)this->CDVol * 6) / 10));
      DAT_005dc769 = '\x01';
    }
  }
  switch(*puVar5) {
  case 1:
    iVar7 = 0;
    iVar6 = 1;
    break;
  case 2:
    iVar7 = 2;
    iVar6 = 3;
    break;
  case 3:
    iVar7 = 4;
    iVar6 = 5;
    break;
  case 4:
    iVar7 = 6;
    iVar6 = 7;
    break;
  case 5:
    iVar7 = 8;
    iVar6 = 9;
    break;
  case 6:
    iVar7 = 10;
    iVar6 = 0xb;
    break;
  case 7:
    iVar7 = 0xc;
    iVar6 = 0xd;
    break;
  case 8:
    iVar7 = 0xe;
    iVar6 = 0xf;
    break;
  case 9:
    iVar7 = 0x10;
    iVar6 = 0x11;
    break;
  default:
    goto switchD_00411b74_caseD_9;
  }
  piVar4 = (int *)0x0;
  this->field36_0x30 = pSVar2;
  this->field80_0x8c = 0;
  this->field45_0x48 = 1;
  this->field41_0x38 = DAT_005dc870;
  this->field42_0x3c = DAT_005dc870;
  this->field43_0x40 = DAT_005dc870;
  this->field49_0x4c = 0;
  this->field51_0x54 = 0x7f;
  this->field55_0x58 = (int)DAT_005dc870;
  this->field60_0x60 = 1;
  this->field61_0x64 = 0;
  this->field62_0x68 = (int *)0xffffffff;
  this->field63_0x6c = 0;
  this->field65_0x71 = 1;
  Decoder_ShiftLeft(&param_1,(void *)0x2);
  this_00 = local_8;
  puVar8 = this_00;
  Decoder_ShiftLeft(local_4,(void *)0xa);
  puVar5 = (undefined4 *)Decoder_ReadInt(this_00,puVar8,piVar4);
  this->field78_0x84 = *puVar5;
  this->field79_0x88 = 0x14;
  this->field81_0x90 = 0x7f;
  this->field85_0x94 = 10;
  this->SoundCar = iVar7;
  this->field_0x70 = 0;
  iVar7 = SoundCard::SoundCard_FUN_004b6020((SoundCard *)&gSoundCard,iVar7);
  this->field50_0x50 = iVar7;
  this->field37_0x34 = DAT_005dc768;
  DAT_005dc768 = DAT_005dc768 + '\x01';
  if (DAT_005dc768 == -1) {
    DAT_005dc768 = '\0';
  }
  S154_FUN_004171a0(this);
  this->SoundCar = iVar6;
  this->field_0x70 = 0x7f;
  iVar6 = SoundCard::SoundCard_FUN_004b6020((SoundCard *)&gSoundCard,iVar6);
  this->field50_0x50 = iVar6;
  this->field37_0x34 = DAT_005dc768;
  DAT_005dc768 = DAT_005dc768 + '\x01';
  if (DAT_005dc768 == -1) {
    DAT_005dc768 = '\0';
  }
  S154_FUN_004171a0(this);
switchD_00411b74_caseD_9:
  return;
}


void __thiscall S46__S154_FUN_00411d20(AudioManager *this,S46 *param_1)

{
  byte bVar1;
  void *pvVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined3 uVar10;
  undefined1 *puVar7;
  int *piVar8;
  undefined4 uVar9;
  char cVar11;
  int iVar12;
  int iVar13;
  int *piVar14;
  undefined1 *puVar15;
  int local_2c;
  int *local_28;
  undefined4 local_24;
  int local_20;
  undefined1 local_1c;
  undefined3 uStack_1b;
  undefined1 local_18 [4];
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  undefined1 local_c [4];
  undefined1 local_8 [4];
  undefined1 local_4 [4];
  
  local_28 = *(int **)(*(int *)&this->Elements
                                [(int)((int)&param_1[-1].DATA1 + 3)].field5_0x8
                      + 0xc);
  if ((local_28 != (int *)0x0) &&
     (pvVar2 = (void *)FUN_00411a00(), pvVar2 != (void *)0x0)) {
    FUN_004117b0(pvVar2,&this->field41_0x38,&this->field42_0x3c,
                 &this->field43_0x40);
    this->field36_0x30 = param_1;
    this->field80_0x8c = 0;
    uVar3 = MapRelatedStruct::S16_FUN_00463850
                      (_gMapRelatedStruct,this->field41_0x38,this->field42_0x3c,
                       this->field43_0x40);
    _local_1c = CONCAT31(uStack_1b,(char)uVar3);
    piVar4 = (int *)S154_FUN_00411730(this,&param_1);
    this->field31_0x28 = (int *)*piVar4;
    this->field32_0x2c = 0;
    Decoder_ShiftLeft(&param_1,(void *)0x2);
    piVar8 = &local_20;
    piVar14 = piVar4;
    Decoder_ShiftLeft(&local_24,(void *)0x32);
    piVar5 = (int *)Decoder_ReadInt(piVar4,piVar8,piVar14);
    piVar8 = &local_2c;
    piVar4 = piVar8;
    Decoder_ShiftLeft(local_18,(void *)0x2);
    puVar7 = local_14;
    piVar14 = piVar8;
    Decoder_ShiftLeft(local_10,(void *)0x32);
    pvVar2 = Decoder_ReadInt(piVar8,puVar7,piVar14);
    puVar6 = (undefined4 *)WorldCoordinateToScreenCoord(pvVar2,piVar4,piVar5);
    bVar1 = S154_FUN_004116b0(this,*puVar6);
    if (bVar1 != 0) {
      bVar1 = 0;
      param_1 = (S46 *)((uint)param_1 & 0xffffff00);
      local_20 = 0;
      do {
        uVar10 = (undefined3)((uint)local_20 >> 8);
        piVar8 = local_28;
        switch(local_20) {
        case 0:
          if (*(char *)((int)local_28 + 0x156) != '\0') {
            iVar13 = 0x3c;
            iVar12 = 9000;
            local_2c = CONCAT31(local_2c._1_3_,0x3c);
            local_24 = 3;
            cVar11 = '\0';
LAB_00411edb:
            if (bVar1 < 5) {
              Decoder_ShiftLeft(local_10,(void *)0x2);
              puVar7 = local_14;
              puVar15 = puVar7;
              Decoder_ShiftLeft(local_18,(void *)0x32);
              piVar8 = (int *)Decoder_ReadInt(puVar7,puVar15,piVar8);
              bVar1 = S154_FUN_004116f0(this,local_2c,*piVar8,(char)_local_1c);
              if (bVar1 != 0) {
                this->SoundCar = iVar13;
                this->field37_0x34 = (char)param_1;
                this->field65_0x71 = cVar11;
                this->field50_0x50 = iVar12;
                if (cVar11 == '\0') {
                  this->field60_0x60 = 0;
                  this->field73_0x7c = 3;
                }
                else {
                  this->field60_0x60 = 1;
                }
                uVar9 = SoundCard::SoundCard_FUN_004b6060
                                  ((SoundCard *)&gSoundCard,iVar13);
                this->field61_0x64 = uVar9;
                piVar8 = (int *)SoundCard::SoundCard_FUN_004b6080
                                          ((SoundCard *)&gSoundCard,iVar13);
                this->field62_0x68 = piVar8;
                this->field49_0x4c = local_24;
                Decoder_ShiftLeft(local_c,(void *)0x2);
                puVar7 = local_8;
                puVar15 = puVar7;
                Decoder_ShiftLeft(local_4,(void *)0x32);
                puVar6 = (undefined4 *)Decoder_ReadInt(puVar7,puVar15,piVar8);
                this->field78_0x84 = *puVar6;
                this->field81_0x90 = (undefined1)local_2c;
                this->field85_0x94 = 0x32;
                this->field79_0x88 = 0x14;
                this->field63_0x6c = 400;
                this->field45_0x48 = 0;
                S154_FUN_004171a0(this);
              }
            }
          }
          break;
        case 1:
          if (*(char *)((int)local_28 + 0x157) != '\0') {
            iVar13 = 0x3c;
            iVar12 = 13000;
            local_2c = CONCAT31(local_2c._1_3_,0x1e);
            local_24 = 4;
            cVar11 = '\0';
            piVar8 = (int *)CONCAT31(uVar10,*(char *)((int)local_28 + 0x157));
            goto LAB_00411edb;
          }
          break;
        case 2:
          if ((char)local_28[0x56] != '\0') {
            iVar13 = 0x3c;
            iVar12 = 8000;
            local_2c = CONCAT31(local_2c._1_3_,0x2d);
            local_24 = 4;
            cVar11 = '\0';
            goto LAB_00411edb;
          }
          break;
        case 3:
          if (*(char *)((int)local_28 + 0x159) != '\0') {
            iVar13 = 0x25;
            iVar12 = 0x5622;
            local_2c = CONCAT31(local_2c._1_3_,0x32);
            local_24 = 5;
            cVar11 = '\x01';
            piVar8 = (int *)CONCAT31(uVar10,*(char *)((int)local_28 + 0x159));
            goto LAB_00411edb;
          }
        }
        bVar1 = (char)param_1 + 1;
        local_20 = local_20 + 1;
        param_1 = (S46 *)CONCAT31(param_1._1_3_,bVar1);
      } while (bVar1 < 4);
    }
  }
  return;
}


void __thiscall S46__S154_FUN_00412010(AudioManager *this,S46 *param_1)

{
  S46 *pSVar1;
  byte bVar2;
  undefined4 *puVar3;
  uint uVar4;
  int *piVar5;
  undefined1 *puVar6;
  void *pvVar7;
  undefined3 extraout_var;
  int *piVar8;
  undefined4 uVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 local_1c [4];
  undefined1 local_18 [4];
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  undefined1 local_c [4];
  undefined1 local_8 [4];
  undefined1 local_4 [4];
  
  pSVar1 = param_1;
  pvVar7 = *(void **)(*(int *)&this->Elements
                               [(int)((int)&param_1[-1].DATA1 + 3)].field5_0x8 +
                     0xc);
  if (pvVar7 != (void *)0x0) {
    puVar3 = (undefined4 *)FUN_00411a10(pvVar7);
    if (puVar3 != (undefined4 *)0x0) {
      FUN_00411a20(pvVar7,&param_1);
      puVar3 = (undefined4 *)*puVar3;
      this->field41_0x38 = puVar3;
      FUN_00411a30(pvVar7,&param_1);
      uVar9 = *puVar3;
      this->field43_0x40 = this->field164_0x1470;
      this->field42_0x3c = uVar9;
      this->field36_0x30 = pSVar1;
      this->field80_0x8c = 0;
      uVar4 = MapRelatedStruct::S16_FUN_00463850
                        (_gMapRelatedStruct,this->field41_0x38,uVar9,
                         this->field164_0x1470);
      param_1 = (S46 *)CONCAT31(param_1._1_3_,(char)uVar4);
      puVar3 = (undefined4 *)S154_FUN_00411730(this,local_1c);
      piVar8 = (int *)*puVar3;
      this->field31_0x28 = piVar8;
      this->field32_0x2c = 0;
      Decoder_ShiftLeft(local_1c,(void *)0x2);
      puVar10 = local_18;
      piVar5 = piVar8;
      Decoder_ShiftLeft(local_14,(void *)0x16);
      piVar5 = (int *)Decoder_ReadInt(piVar8,puVar10,piVar5);
      puVar10 = local_10;
      piVar8 = piVar5;
      Decoder_ShiftLeft(local_c,(void *)0x2);
      puVar6 = local_8;
      puVar11 = puVar6;
      Decoder_ShiftLeft(local_4,(void *)0x16);
      pvVar7 = Decoder_ReadInt(puVar6,puVar11,piVar5);
      puVar3 = (undefined4 *)WorldCoordinateToScreenCoord(pvVar7,puVar10,piVar8)
      ;
      bVar2 = S154_FUN_004116b0(this,*puVar3);
      piVar8 = (int *)CONCAT31(extraout_var,bVar2);
      if (bVar2 != 0) {
        Decoder_ShiftLeft(local_4,(void *)0x2);
        puVar10 = local_8;
        piVar5 = piVar8;
        Decoder_ShiftLeft(local_c,(void *)0x16);
        piVar8 = (int *)Decoder_ReadInt(piVar8,puVar10,piVar5);
        bVar2 = S154_FUN_004116f0(this,0x6e,*piVar8,(char)param_1);
        if (bVar2 != 0) {
          this->SoundCar = 0x3c;
          this->field37_0x34 = 0;
          this->field65_0x71 = 0;
          this->field50_0x50 = 17000;
          this->field60_0x60 = 0;
          this->field73_0x7c = 5;
          uVar9 = SoundCard::SoundCard_FUN_004b6060
                            ((SoundCard *)&gSoundCard,0x3c);
          this->field61_0x64 = uVar9;
          piVar8 = (int *)SoundCard::SoundCard_FUN_004b6080
                                    ((SoundCard *)&gSoundCard,0x3c);
          this->field62_0x68 = piVar8;
          this->field49_0x4c = 6;
          Decoder_ShiftLeft(&param_1,(void *)0x2);
          puVar10 = local_4;
          puVar6 = puVar10;
          Decoder_ShiftLeft(local_8,(void *)0x16);
          puVar3 = (undefined4 *)Decoder_ReadInt(puVar10,puVar6,piVar8);
          uVar9 = *puVar3;
          this->field81_0x90 = 0x6e;
          this->field78_0x84 = uVar9;
          this->field85_0x94 = 0x16;
          this->field79_0x88 = 0x14;
          this->field63_0x6c = 400;
          this->field45_0x48 = 0;
          S154_FUN_004171a0(this);
        }
      }
    }
  }
  return;
}


void __thiscall S46__S154_FUN_00414e50(AudioManager *this,S46 *param_1)

{
  AudioManager *this_00;
  S46 *pSVar1;
  int iVar2;
  undefined3 uVar4;
  undefined4 *puVar3;
  
  pSVar1 = param_1;
  this_00 = *(AudioManager **)
             (*(int *)&this->Elements[(int)((int)&param_1[-1].DATA1 + 3)].
                       field5_0x8 + 0xc);
  if (this_00 != (AudioManager *)0x0) {
    iVar2 = S154_FUN_00411a40(this_00);
    if (0 < iVar2) {
      uVar4 = (undefined3)((uint)iVar2 >> 8);
      if (iVar2 < 0x12d) {
        if (iVar2 < 0x97) {
          this->field50_0x50 = 0x819a;
          puVar3 = (undefined4 *)CONCAT31(uVar4,0x46);
        }
        else {
          this->field50_0x50 = 0x666d;
          puVar3 = (undefined4 *)CONCAT31(uVar4,0x37);
        }
      }
      else {
        this->field50_0x50 = 0x5622;
        puVar3 = (undefined4 *)CONCAT31(uVar4,0x28);
      }
      this->SoundCar = 0x39;
      this->field36_0x30 = pSVar1;
      this->field80_0x8c = 0;
      this->field51_0x54 = (byte)puVar3;
      this->field81_0x90 = (byte)puVar3;
      this->field85_0x94 = 100;
      this->field79_0x88 = 0x14;
      Decoder_ShiftLeft(&param_1,(void *)0x64);
      this->field78_0x84 = *puVar3;
      this->field37_0x34 = 0;
      this->field65_0x71 = 0;
      this->field45_0x48 = 1;
      this->field49_0x4c = 0;
      this->field63_0x6c = 0;
      this->field60_0x60 = 0;
      this->field61_0x64 = 0;
      this->field62_0x68 = (int *)0xffffffff;
      this->field_0x70 = 0x3f;
      this->field73_0x7c = 3;
      S154_FUN_004171a0(this);
    }
  }
  return;
}


void __thiscall S46__FUN_00415880(void *this,S46 *param_1,S46 *param_2)

{
  undefined4 uVar1;
  S46 *pSVar2;
  bool bVar3;
  char cVar4;
  byte bVar5;
  undefined3 extraout_var;
  int *piVar6;
  undefined3 extraout_var_00;
  S46 **ppSVar7;
  int *this_00;
  void *this_01;
  undefined4 *puVar8;
  int *piVar9;
  undefined3 extraout_var_01;
  undefined1 *puVar10;
  undefined1 *puVar11;
  S46 **ppSVar12;
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  undefined1 local_c [4];
  undefined1 local_8 [4];
  undefined1 local_4 [4];
  Car *pCar;
  
  pSVar2 = param_1;
  pCar = *(Car **)&param_1->DATA->field_0x8;
  bVar3 = Car::isFileTruck(pCar);
  if (((!bVar3) && (bVar3 = Car::IsEmergencyOrFbiCar(pCar), bVar3)) &&
     (cVar4 = Car::Car_FUN_00414f80(pCar), cVar4 != '\0')) {
    return;
  }
  bVar3 = Car::isFileTruck(pCar);
  if ((((bVar3) || (bVar3 = Car::isTank(pCar), bVar3)) ||
      (bVar3 = Car::isGunJeep(pCar), bVar3)) &&
     (cVar4 = Car::Car_FUN_004119f0(pCar), cVar4 != '\0')) {
    return;
  }
  bVar5 = Car::Car_FUN_00411970(*(Car **)&pSVar2->DATA->field_0x8);
  if (bVar5 == 0) {
    return;
  }
  piVar6 = (int *)CONCAT31(extraout_var,*(char *)&pSVar2->NextElement);
  if ((*(char *)&pSVar2->NextElement == '\0') &&
     (piVar6 = (int *)Car::GetModelCar(pCar), piVar6 != (int *)0x1b)) {
    bVar5 = Car::Car_FUN_00411990(pCar);
    if (bVar5 == 0) {
      return;
    }
    if (0x2b < bVar5) {
      bVar5 = 0x2c;
      param_2->field_0xa = *(byte *)((int)this + 0x1464) & 7;
    }
    piVar6 = (int *)CONCAT31(extraout_var_00,
                             (&DAT_0056e820)
                             [(uint)(byte)param_2->field_0xa * 0x2c +
                              (uint)(byte)(0x2c - bVar5)]);
    if ((&DAT_0056e820)
        [(uint)(byte)param_2->field_0xa * 0x2c + (uint)(byte)(0x2c - bVar5)] ==
        '\0') {
      return;
    }
  }
  Decoder_ShiftLeft(&param_1,(void *)0x2);
  ppSVar7 = &param_2;
  ppSVar12 = ppSVar7;
  Decoder_ShiftLeft(local_14,(void *)0xf);
  this_00 = (int *)Decoder_ReadInt(ppSVar7,ppSVar12,piVar6);
  puVar11 = local_10;
  piVar9 = this_00;
  Decoder_ShiftLeft(local_c,(void *)0x2);
  puVar10 = local_8;
  piVar6 = this_00;
  Decoder_ShiftLeft(local_4,(void *)0xf);
  this_01 = Decoder_ReadInt(this_00,puVar10,piVar6);
  puVar8 = (undefined4 *)WorldCoordinateToScreenCoord(this_01,puVar11,piVar9);
  bVar5 = AudioManager::S154_FUN_004116b0((AudioManager *)this,*puVar8);
  if (bVar5 != 0) {
    piVar9 = (int *)Car::GetModelCar(pCar);
    cVar4 = (-(piVar9 != (int *)0x3c) & 0x95U) + 0x7f;
    param_1 = (S46 *)CONCAT31(param_1._1_3_,cVar4);
    Decoder_ShiftLeft(&param_2,(void *)0x2);
    puVar11 = local_4;
    piVar6 = piVar9;
    Decoder_ShiftLeft(local_8,(void *)0xf);
    piVar6 = (int *)Decoder_ReadInt(piVar9,puVar11,piVar6);
    bVar5 = AudioManager::S154_FUN_004116f0
                      ((AudioManager *)this,param_1,*piVar6,
                       *(char *)((int)&pSVar2->NextElement + 1));
    piVar6 = (int *)CONCAT31(extraout_var_01,bVar5);
    if (bVar5 != 0) {
      Decoder_ShiftLeft(&param_1,(void *)0x2);
      ppSVar7 = &param_2;
      piVar9 = piVar6;
      Decoder_ShiftLeft(local_4,(void *)0xf);
      puVar8 = (undefined4 *)Decoder_ReadInt(piVar6,ppSVar7,piVar9);
      uVar1 = *puVar8;
      *(char *)((int)this + 0x90) = cVar4;
      *(undefined4 *)((int)this + 0x84) = uVar1;
      *(undefined4 *)((int)this + 0x94) = 0xf;
      *(undefined4 *)((int)this + 0x88) = 5;
      *(undefined1 *)((int)this + 0x34) = 8;
      *(undefined1 *)((int)this + 0x71) = 0;
      *(undefined1 *)((int)this + 0x48) = 0;
      *(uint *)((int)this + 0x4c) =
           (uint)(*(char *)&pSVar2->NextElement == '\0') * 2 + 2;
      AudioManager::S154_FUN_004171a0((AudioManager *)this);
    }
  }
  return;
}


void __thiscall S46__FUN_00415880(void *this,S46 *param_1,S46 *param_2)

{
  undefined4 uVar1;
  S46 *pSVar2;
  bool bVar3;
  char cVar4;
  byte bVar5;
  undefined3 extraout_var;
  int *piVar6;
  undefined3 extraout_var_00;
  S46 **ppSVar7;
  int *this_00;
  void *this_01;
  undefined4 *puVar8;
  int *piVar9;
  undefined3 extraout_var_01;
  undefined1 *puVar10;
  undefined1 *puVar11;
  S46 **ppSVar12;
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  undefined1 local_c [4];
  undefined1 local_8 [4];
  undefined1 local_4 [4];
  Car *pCar;
  
  pSVar2 = param_1;
  pCar = *(Car **)&param_1->DATA->field_0x8;
  bVar3 = Car::isFileTruck(pCar);
  if (((!bVar3) && (bVar3 = Car::IsEmergencyOrFbiCar(pCar), bVar3)) &&
     (cVar4 = Car::Car_FUN_00414f80(pCar), cVar4 != '\0')) {
    return;
  }
  bVar3 = Car::isFileTruck(pCar);
  if ((((bVar3) || (bVar3 = Car::isTank(pCar), bVar3)) ||
      (bVar3 = Car::isGunJeep(pCar), bVar3)) &&
     (cVar4 = Car::Car_FUN_004119f0(pCar), cVar4 != '\0')) {
    return;
  }
  bVar5 = Car::Car_FUN_00411970(*(Car **)&pSVar2->DATA->field_0x8);
  if (bVar5 == 0) {
    return;
  }
  piVar6 = (int *)CONCAT31(extraout_var,*(char *)&pSVar2->NextElement);
  if ((*(char *)&pSVar2->NextElement == '\0') &&
     (piVar6 = (int *)Car::GetModelCar(pCar), piVar6 != (int *)0x1b)) {
    bVar5 = Car::Car_FUN_00411990(pCar);
    if (bVar5 == 0) {
      return;
    }
    if (0x2b < bVar5) {
      bVar5 = 0x2c;
      param_2->field_0xa = *(byte *)((int)this + 0x1464) & 7;
    }
    piVar6 = (int *)CONCAT31(extraout_var_00,
                             (&DAT_0056e820)
                             [(uint)(byte)param_2->field_0xa * 0x2c +
                              (uint)(byte)(0x2c - bVar5)]);
    if ((&DAT_0056e820)
        [(uint)(byte)param_2->field_0xa * 0x2c + (uint)(byte)(0x2c - bVar5)] ==
        '\0') {
      return;
    }
  }
  Decoder_ShiftLeft(&param_1,(void *)0x2);
  ppSVar7 = &param_2;
  ppSVar12 = ppSVar7;
  Decoder_ShiftLeft(local_14,(void *)0xf);
  this_00 = (int *)Decoder_ReadInt(ppSVar7,ppSVar12,piVar6);
  puVar11 = local_10;
  piVar9 = this_00;
  Decoder_ShiftLeft(local_c,(void *)0x2);
  puVar10 = local_8;
  piVar6 = this_00;
  Decoder_ShiftLeft(local_4,(void *)0xf);
  this_01 = Decoder_ReadInt(this_00,puVar10,piVar6);
  puVar8 = (undefined4 *)WorldCoordinateToScreenCoord(this_01,puVar11,piVar9);
  bVar5 = AudioManager::S154_FUN_004116b0((AudioManager *)this,*puVar8);
  if (bVar5 != 0) {
    piVar9 = (int *)Car::GetModelCar(pCar);
    cVar4 = (-(piVar9 != (int *)0x3c) & 0x95U) + 0x7f;
    param_1 = (S46 *)CONCAT31(param_1._1_3_,cVar4);
    Decoder_ShiftLeft(&param_2,(void *)0x2);
    puVar11 = local_4;
    piVar6 = piVar9;
    Decoder_ShiftLeft(local_8,(void *)0xf);
    piVar6 = (int *)Decoder_ReadInt(piVar9,puVar11,piVar6);
    bVar5 = AudioManager::S154_FUN_004116f0
                      ((AudioManager *)this,param_1,*piVar6,
                       *(char *)((int)&pSVar2->NextElement + 1));
    piVar6 = (int *)CONCAT31(extraout_var_01,bVar5);
    if (bVar5 != 0) {
      Decoder_ShiftLeft(&param_1,(void *)0x2);
      ppSVar7 = &param_2;
      piVar9 = piVar6;
      Decoder_ShiftLeft(local_4,(void *)0xf);
      puVar8 = (undefined4 *)Decoder_ReadInt(piVar6,ppSVar7,piVar9);
      uVar1 = *puVar8;
      *(char *)((int)this + 0x90) = cVar4;
      *(undefined4 *)((int)this + 0x84) = uVar1;
      *(undefined4 *)((int)this + 0x94) = 0xf;
      *(undefined4 *)((int)this + 0x88) = 5;
      *(undefined1 *)((int)this + 0x34) = 8;
      *(undefined1 *)((int)this + 0x71) = 0;
      *(undefined1 *)((int)this + 0x48) = 0;
      *(uint *)((int)this + 0x4c) =
           (uint)(*(char *)&pSVar2->NextElement == '\0') * 2 + 2;
      AudioManager::S154_FUN_004171a0((AudioManager *)this);
    }
  }
  return;
}


void __thiscall S46__FUN_00415c70(void *this,S46 *param_1,S46 *param_2)

{
  if ((*(int *)(*(int *)&param_1->DATA->field_0x8 + 0x58) != 0) &&
     (*(char *)((int)&param_1->NextElement + 1) == '\0')) {
    FUN_00412680(param_1);
    FUN_00412830(param_1);
  }
  FUN_00415880(this,param_1,param_2);
  AudioManager::FUN_004143b0((AudioManager *)this,(int *)param_1);
  FUN_00412a20(param_1);
  return;
}


void __thiscall S46__FUN_00415c70(void *this,S46 *param_1,S46 *param_2)

{
  if ((*(int *)(*(int *)&param_1->DATA->field_0x8 + 0x58) != 0) &&
     (*(char *)((int)&param_1->NextElement + 1) == '\0')) {
    FUN_00412680(param_1);
    FUN_00412830(param_1);
  }
  FUN_00415880(this,param_1,param_2);
  AudioManager::FUN_004143b0((AudioManager *)this,(int *)param_1);
  FUN_00412a20(param_1);
  return;
}


void __thiscall S46__FUN_00415cc0(void *this,S46 *param_1,S46 *param_2)

{
  if (*(int *)(*(int *)&param_1->DATA->field_0x8 + 0x58) != 0) {
    FUN_00412bd0(param_1);
    FUN_00413160(param_1);
    FUN_004156c0(param_1);
  }
  FUN_00412d80(param_1);
  AudioManager::FUN_004143b0((AudioManager *)this,(int *)param_1);
  FUN_00415880(this,param_1,param_2);
  FUN_00412fe0(param_1);
  return;
}


void __thiscall S46__FUN_00415cc0(void *this,S46 *param_1,S46 *param_2)

{
  if (*(int *)(*(int *)&param_1->DATA->field_0x8 + 0x58) != 0) {
    FUN_00412bd0(param_1);
    FUN_00413160(param_1);
    FUN_004156c0(param_1);
  }
  FUN_00412d80(param_1);
  AudioManager::FUN_004143b0((AudioManager *)this,(int *)param_1);
  FUN_00415880(this,param_1,param_2);
  FUN_00412fe0(param_1);
  return;
}


void __thiscall S46__FUN_00415d20(AudioManager *param_1,S46 *param_2,S46 *param_3)

{
  S46 *pSVar1;
  bool bVar2;
  undefined3 extraout_var;
  
  pSVar1 = *(S46 **)&param_2->DATA->field_0x8;
  param_3->NextElement = pSVar1;
  bVar2 = Car::Car_FUN_00403820((Car *)&pSVar1[4].field_0x8,&DAT_005dc804);
  if (CONCAT31(extraout_var,bVar2) == 0) {
    if (*(int *)(*(int *)&param_2->DATA->field_0x8 + 0x58) != 0) {
      FUN_00413160(param_2);
      FUN_00414030(param_2);
      FUN_00414200(param_2);
      FUN_004148d0(param_2);
    }
    AudioManager::FUN_004143b0(param_1,(int *)param_2);
    FUN_00415a90(param_2);
    FUN_004139a0(param_2);
    FUN_00415880(param_1,param_2,param_3);
    FUN_00414780(param_2);
    FUN_00413bd0(param_2);
    FUN_00413eb0(param_2,param_3);
    FUN_00412fe0(param_2);
    FUN_00412eb0(param_2);
    FUN_004123c0(param_2);
  }
  else if (pSVar1[3].CarSystemManager != (CarSystemManager *)0x0) {
    FUN_00413160(param_2);
    return;
  }
  return;
}


void __thiscall S46__FUN_00415d20(AudioManager *param_1,S46 *param_2,S46 *param_3)

{
  S46 *pSVar1;
  bool bVar2;
  undefined3 extraout_var;
  
  pSVar1 = *(S46 **)&param_2->DATA->field_0x8;
  param_3->NextElement = pSVar1;
  bVar2 = Car::Car_FUN_00403820((Car *)&pSVar1[4].field_0x8,&DAT_005dc804);
  if (CONCAT31(extraout_var,bVar2) == 0) {
    if (*(int *)(*(int *)&param_2->DATA->field_0x8 + 0x58) != 0) {
      FUN_00413160(param_2);
      FUN_00414030(param_2);
      FUN_00414200(param_2);
      FUN_004148d0(param_2);
    }
    AudioManager::FUN_004143b0(param_1,(int *)param_2);
    FUN_00415a90(param_2);
    FUN_004139a0(param_2);
    FUN_00415880(param_1,param_2,param_3);
    FUN_00414780(param_2);
    FUN_00413bd0(param_2);
    FUN_00413eb0(param_2,param_3);
    FUN_00412fe0(param_2);
    FUN_00412eb0(param_2);
    FUN_004123c0(param_2);
  }
  else if (pSVar1[3].CarSystemManager != (CarSystemManager *)0x0) {
    FUN_00413160(param_2);
    return;
  }
  return;
}


void __thiscall S46__S154_FUN_00415df0(AudioManager *this,S46 *param_1)

{
  S46 *pSVar1;
  Car *this_00;
  S46 *pSVar2;
  void *this_01;
  byte bVar3;
  undefined4 uVar4;
  
  pSVar1 = param_1->DATA;
  this_00 = *(Car **)&pSVar1->field_0x8;
  if (this_00 != (Car *)0x0) {
    bVar3 = Car::IsDriverPlayer(this_00);
    *(byte *)&param_1->NextElement = bVar3;
    pSVar2 = (S46 *)this->Elements[(int)this->field36_0x30].field0_0x0;
    if (pSVar2 != (S46 *)0x0) {
      this_01 = *(void **)(*(int *)&pSVar1->field_0x8 + 0x58);
      if (this_01 == (void *)0x0) {
        pSVar2->DATA = DAT_005dc870;
      }
      else {
        FUN_0049ec80(this_01);
      }
      uVar4 = Car::GetModelCar(*(Car **)&param_1->DATA->field_0x8);
      switch(uVar4) {
      case 6:
      case 0x3b:
      case 0x3d:
        thunk_FUN_004143b0(this,(int *)param_1);
        return;
      default:
        FUN_00415d20(param_1,pSVar2);
        break;
      case 0x36:
        FUN_00415cc0(this,param_1,pSVar2);
        return;
      case 0x3c:
        FUN_00415c70(this,param_1,pSVar2);
        return;
      }
    }
  }
  return;
}


void __thiscall S46__S154_FUN_00415f90(AudioManager *this,S46 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  byte bVar5;
  byte bVar6;
  char cVar7;
  uint uVar8;
  undefined4 *puVar9;
  int *piVar10;
  undefined1 *puVar11;
  void *this_00;
  undefined3 extraout_var;
  int *piVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  byte local_37;
  byte local_36;
  undefined1 local_35;
  int local_30;
  undefined1 local_2c [4];
  undefined1 local_28 [4];
  undefined1 local_24 [4];
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  undefined1 local_18 [4];
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  undefined1 local_c [4];
  undefined1 local_8 [4];
  undefined1 local_4 [4];
  
  local_36 = 0;
  Decoder_ShiftLeft(&local_30,(void *)0x0);
  local_37 = 0xff;
  local_35 = 0;
  iVar2 = *(int *)(*(int *)&this->Elements[(int)((int)&param_1[-1].DATA1 + 3)].
                            field5_0x8 + 0xc);
  if (iVar2 != 0) {
    this->field80_0x8c = 0;
    this->field36_0x30 = param_1;
    bVar6 = 0;
    if (0 < *(int *)(iVar2 + 0xc84)) {
      uVar8 = 0;
      do {
        iVar1 = iVar2 + uVar8 * 0x28;
        uVar4 = FUN_004121f0((undefined4 *)(iVar1 + 4));
        param_1 = (S46 *)CONCAT31(param_1._1_3_,uVar4);
        bVar5 = S154_FUN_00415ef0(this,(undefined4 *)(iVar1 + 4),param_1);
        if (bVar5 != 0) {
          if (this->field45_0x48 != '\0') {
            this->field41_0x38 = DAT_005dc870;
            this->field42_0x3c = DAT_005dc870;
            piVar10 = (int *)0x0;
            this->field43_0x40 = DAT_005dc870;
            this->field37_0x34 = DAT_005dc76a._2_1_;
            this->field49_0x4c = 0;
            this->field51_0x54 = 0x2d;
            this->field55_0x58 = (int)DAT_005dc870;
            cVar7 = DAT_005dc76a._2_1_ + '\x01';
            this->field60_0x60 = 1;
            this->field65_0x71 = 1;
            DAT_005dc76a._2_1_ = cVar7;
            this->field61_0x64 = 0;
            this->field62_0x68 = (int *)0xffffffff;
            this->field63_0x6c = 0;
            this->field_0x70 = 0x3f;
            Decoder_ShiftLeft(&param_1,(void *)0x2);
            puVar13 = local_4;
            piVar12 = piVar10;
            Decoder_ShiftLeft(local_8,(void *)0xa);
            puVar9 = (undefined4 *)Decoder_ReadInt(piVar10,puVar13,piVar12);
            uVar3 = *puVar9;
            this->field81_0x90 = 0x2d;
            this->field78_0x84 = uVar3;
            this->field85_0x94 = 10;
            goto LAB_004161f7;
          }
          if ((char)param_1 != '\0') {
            this->field41_0x38 = *(undefined4 **)(iVar1 + 8);
            this->field42_0x3c = *(undefined4 *)(iVar1 + 0xc);
            this->field43_0x40 = *(undefined4 *)(iVar1 + 0x10);
            puVar9 = (undefined4 *)S154_FUN_00411730(this,local_2c);
            piVar12 = (int *)*puVar9;
            this->field31_0x28 = piVar12;
            this->field32_0x2c = 0;
            Decoder_ShiftLeft(local_28,(void *)0x2);
            puVar13 = local_24;
            piVar10 = piVar12;
            Decoder_ShiftLeft(local_20,(void *)0xa);
            piVar10 = (int *)Decoder_ReadInt(piVar12,puVar13,piVar10);
            puVar13 = local_1c;
            piVar12 = piVar10;
            Decoder_ShiftLeft(local_18,(void *)0x2);
            puVar11 = local_14;
            puVar14 = puVar11;
            Decoder_ShiftLeft(local_10,(void *)0xa);
            this_00 = Decoder_ReadInt(puVar11,puVar14,piVar10);
            puVar9 = (undefined4 *)
                     WorldCoordinateToScreenCoord(this_00,puVar13,piVar12);
            bVar5 = S154_FUN_004116b0(this,*puVar9);
            piVar12 = (int *)CONCAT31(extraout_var,bVar5);
            if (bVar5 != 0) {
              Decoder_ShiftLeft(local_c,(void *)0x2);
              puVar13 = local_8;
              piVar10 = piVar12;
              Decoder_ShiftLeft(local_4,(void *)0xa);
              piVar12 = (int *)Decoder_ReadInt(piVar12,puVar13,piVar10);
              uVar8 = MapRelatedStruct::S16_FUN_00463850
                                (_gMapRelatedStruct,this->field41_0x38,
                                 this->field42_0x3c,this->field43_0x40);
              bVar5 = S154_FUN_004116f0(this,param_1,*piVar12,(char)uVar8);
              if (bVar5 != 0) {
                local_36 = this->field51_0x54;
                local_30 = this->field55_0x58;
                local_35 = (char)param_1;
                local_37 = bVar6;
              }
            }
          }
        }
        bVar6 = bVar6 + 1;
        uVar8 = (uint)bVar6;
      } while ((int)uVar8 < *(int *)(iVar2 + 0xc84));
      if (local_37 != 0xff) {
        iVar1 = iVar2 + (char)local_37 * 0x28;
        this->field41_0x38 = *(undefined4 **)(iVar2 + 8 + (char)local_37 * 0x28)
        ;
        this->field42_0x3c = *(undefined4 *)(iVar1 + 0xc);
        piVar12 = (int *)CONCAT31((int3)((uint)iVar1 >> 8),local_36);
        this->field43_0x40 = *(undefined4 *)(iVar1 + 0x10);
        this->field55_0x58 = local_30;
        this->field51_0x54 = local_36;
        this->field81_0x90 = local_35;
        this->field85_0x94 = 10;
        Decoder_ShiftLeft(&param_1,(void *)0x2);
        puVar13 = local_4;
        puVar11 = puVar13;
        Decoder_ShiftLeft(local_8,(void *)0xa);
        puVar9 = (undefined4 *)Decoder_ReadInt(puVar13,puVar11,piVar12);
        this->field78_0x84 = *puVar9;
        this->field37_0x34 = DAT_005dc76a._2_1_;
        cVar7 = DAT_005dc76a._2_1_ + '\x01';
        DAT_005dc76a._2_1_ = cVar7;
        this->field65_0x71 = 1;
        this->field49_0x4c = 8;
        this->field45_0x48 = 0;
        this->field63_0x6c = 600;
        this->field60_0x60 = 1;
        this->field61_0x64 = 0;
        this->field62_0x68 = (int *)0xffffffff;
LAB_004161f7:
        this->field79_0x88 = 0x14;
        if (cVar7 == -1) {
          DAT_005dc76a._2_1_ = '\0';
        }
        S154_FUN_004171a0(this);
      }
    }
  }
  return;
}


void __thiscall S46__S154_FUN_0041cca0(AudioManager *this,S46 *param_1)

{
  Weapon *this_00;
  char cVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int *piVar6;
  undefined1 *puVar7;
  int *this_01;
  void *this_02;
  undefined4 *puVar8;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar9;
  undefined1 *puVar10;
  int *piVar11;
  int local_28;
  undefined4 local_24;
  int local_20;
  Weapon *local_1c;
  undefined1 local_18 [4];
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  undefined1 local_c [4];
  undefined1 local_8 [4];
  undefined1 local_4 [4];
  
  local_20 = 0;
  local_24 = CONCAT31(local_24._1_3_,0x28);
  this_00 = *(Weapon **)
             (*(int *)&this->Elements[(int)((int)&param_1[-1].DATA1 + 3)].
                       field5_0x8 + 0xc);
  this->field65_0x71 = 2;
  local_1c = this_00;
  cVar1 = FUN_0041cc80(this_00);
  if (((cVar1 != '\0') && (this_00 != (Weapon *)0x0)) &&
     (iVar3 = FUN_0041cc70(this_00), iVar3 == 0)) {
    uVar4 = Weapon::GetTypeWeapon(this_00);
    switch(uVar4) {
    case 0:
    case 10:
      local_28 = 0x137;
      break;
    case 1:
    case 0x12:
    case 0x16:
      local_28 = 0x138;
      local_24 = CONCAT31(local_24._1_3_,0x2c);
      break;
    case 2:
    case 0x13:
      local_28 = 0x13b;
      break;
    case 3:
      local_28 = 0x13e;
      this->field65_0x71 = 0;
      break;
    default:
      goto switchD_0041cd0d_caseD_4;
    case 6:
      local_28 = 0x13a;
      local_24 = CONCAT31(local_24._1_3_,0x2c);
      local_20 = -8000;
      break;
    case 8:
    case 0x15:
      local_28 = 0x13c;
      local_24 = CONCAT31(local_24._1_3_,0x78);
      this->field65_0x71 = 0;
      break;
    case 9:
      local_28 = 0x139;
      local_24 = CONCAT31(local_24._1_3_,0x28);
      break;
    case 0xf:
    case 0x11:
    case 0x17:
      local_28 = 0x13f;
      break;
    case 0x10:
      local_28 = 0x3d;
      break;
    case 0x14:
      local_28 = 0x13d;
      this->field65_0x71 = 0;
    }
    FUN_004cd8c0(local_1c,&this->field41_0x38,&this->field42_0x3c,
                 &this->field43_0x40);
    this->field36_0x30 = param_1;
    this->field80_0x8c = 0;
    uVar5 = MapRelatedStruct::S16_FUN_00463850
                      (_gMapRelatedStruct,this->field41_0x38,this->field42_0x3c,
                       this->field43_0x40);
    param_1 = (S46 *)CONCAT31(param_1._1_3_,(char)uVar5);
    piVar6 = (int *)S154_FUN_00411730(this,&local_1c);
    this->field31_0x28 = (int *)*piVar6;
    this->field32_0x2c = 0;
    Decoder_ShiftLeft(&local_1c,(void *)0x2);
    puVar7 = local_18;
    puVar10 = puVar7;
    Decoder_ShiftLeft(local_14,(void *)0x14);
    this_01 = (int *)Decoder_ReadInt(puVar7,puVar10,piVar6);
    puVar7 = local_10;
    piVar11 = this_01;
    Decoder_ShiftLeft(local_c,(void *)0x2);
    puVar10 = local_8;
    piVar6 = this_01;
    Decoder_ShiftLeft(local_4,(void *)0x14);
    this_02 = Decoder_ReadInt(this_01,puVar10,piVar6);
    puVar8 = (undefined4 *)WorldCoordinateToScreenCoord(this_02,puVar7,piVar11);
    bVar2 = S154_FUN_004116b0(this,*puVar8);
    piVar6 = (int *)CONCAT31(extraout_var,bVar2);
    if (bVar2 != 0) {
      Decoder_ShiftLeft(local_4,(void *)0x2);
      puVar7 = local_8;
      piVar11 = piVar6;
      Decoder_ShiftLeft(local_c,(void *)0x14);
      piVar6 = (int *)Decoder_ReadInt(piVar6,puVar7,piVar11);
      bVar2 = S154_FUN_004116f0(this,local_24,*piVar6,(char)param_1);
      piVar6 = (int *)CONCAT31(extraout_var_00,bVar2);
      if (bVar2 != 0) {
        this->SoundCar = local_28;
        Decoder_ShiftLeft(&param_1,(void *)0x2);
        puVar7 = local_4;
        piVar11 = piVar6;
        Decoder_ShiftLeft(local_8,(void *)0x14);
        puVar8 = (undefined4 *)Decoder_ReadInt(piVar6,puVar7,piVar11);
        uVar4 = *puVar8;
        this->field81_0x90 = (undefined1)local_24;
        this->field78_0x84 = uVar4;
        this->field85_0x94 = 0x14;
        iVar3 = SoundCard::SoundCard_FUN_004b6020
                          ((SoundCard *)&gSoundCard,local_28);
        iVar9 = S154_FUN_004166e0(this,(undefined *)this->SoundCar);
        this->field79_0x88 = 0x14;
        this->field63_0x6c = 0;
        this->field50_0x50 = iVar9 + local_20 + iVar3;
        this->field37_0x34 = 0;
        this->field49_0x4c = 4;
        this->field45_0x48 = 0;
        uVar4 = SoundCard::SoundCard_FUN_004b6060
                          ((SoundCard *)&gSoundCard,this->SoundCar);
        this->field61_0x64 = uVar4;
        this->field62_0x68 = (int *)0xffffffff;
        this->field73_0x7c = 5;
        this->field60_0x60 = (uint)(this->field65_0x71 != '\0');
        S154_FUN_004171a0(this);
      }
    }
  }
switchD_0041cd0d_caseD_4:
  return;
}


byte __thiscall S46__S46_FUN_004214b0(S46 *this)

{
  CarSystemManager *pCVar1;
  
  pCVar1 = this[5].CarSystemManager;
  if (((pCVar1 != (CarSystemManager *)0x2) &&
      (pCVar1 != (CarSystemManager *)0x4)) &&
     (pCVar1 != (CarSystemManager *)0x3)) {
    return 0;
  }
  return 1;
}


void __thiscall S46__S54_FUN_00447360(S54 *this,S46 *pS46)

{
  pS46->NextElement = (S46 *)this->SpriteS1;
  this->SpriteS1 = (SpriteS1 *)pS46;
  return;
}


void __thiscall S46__FUN_00447900(void *this,int param_1,S46 *param_2)

{
  byte *pbVar1;
  S46 *pS46;
  S46 *pSVar2;
  S46 *pSVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  uint local_4;
  
  pbVar5 = *(byte **)((int)this + param_1 * 4);
  pbVar1 = (byte *)0x0;
  local_4 = _DAT_00662bd4;
  uVar6 = _DAT_00662bd4;
  do {
    pbVar4 = pbVar5;
    if (pbVar4 == (byte *)0x0) {
      return;
    }
    if (*pbVar4 == uVar6) {
      pSVar3 = *(S46 **)(pbVar4 + 4);
      pSVar2 = (S46 *)0x0;
      while (pS46 = pSVar3, pS46 != (S46 *)0x0) {
        if (pS46->DATA == param_2) {
          if (pSVar2 == (S46 *)0x0) {
            *(S46 **)(pbVar4 + 4) = pS46->NextElement;
          }
          else {
            pSVar2->NextElement = pS46->NextElement;
          }
          S54::S54_FUN_00447360(gS54,pS46);
          if (*(int *)(pbVar4 + 4) == 0) {
            if (pbVar1 == (byte *)0x0) {
              *(undefined4 *)((int)this + param_1 * 4) =
                   *(undefined4 *)(pbVar4 + 8);
            }
            else {
              *(undefined4 *)(pbVar1 + 8) = *(undefined4 *)(pbVar4 + 8);
            }
            pbVar5 = *(byte **)(pbVar4 + 8);
            S55::S55_FUN_00447380(gS55,pbVar4);
            pbVar4 = pbVar1;
            uVar6 = local_4;
          }
          else {
            pbVar5 = *(byte **)(pbVar4 + 8);
          }
          uVar6 = uVar6 + 1;
          if (_DAT_00662bf8 < (int)uVar6) {
            return;
          }
          pSVar3 = *(S46 **)(pbVar5 + 4);
          pSVar2 = (S46 *)0x0;
          pbVar1 = pbVar4;
          pbVar4 = pbVar5;
          local_4 = uVar6;
        }
        else {
          pSVar3 = pS46->NextElement;
          pSVar2 = pS46;
        }
      }
    }
    pbVar5 = *(byte **)(pbVar4 + 8);
    pbVar1 = pbVar4;
  } while( true );
}


void __thiscall S46__S63_FUN_00486390(S63 *this,S46 *pSprite)

{
  byte bVar1;
  int iVar2;
  Car *car;
  S63 *this_00;
  Ped *pPVar3;
  
  iVar2 = SpriteS1::SpriteS1_FUN_0040fea0((SpriteS1 *)pSprite);
  if (iVar2 != 0) {
    S63_FUN_004932d0(this);
    return;
  }
  car = (Car *)SpriteS1::GetObject((SpriteS1 *)pSprite);
  if (car != (Car *)0x0) {
    ::Car::Car_FUN_004274c0(car,this);
    return;
  }
  this_00 = SpriteS1::SpriteS1_FUN_0040fec0((SpriteS1 *)pSprite);
  bVar1 = S63_FUN_00420ff0(this);
  iVar2 = S68::S68GetPedID(_gS68,bVar1);
  if (iVar2 != 0) {
    pPVar3 = Char::FindPed(gChar,iVar2);
    if (pPVar3 != (Ped *)0x0) {
      FUN_004350c0(this_00);
    }
  }
  S63_FUN_00486360(this_00,this);
  return;
}


void __thiscall S46__FUN_00486410(void *this,S46 *param_1)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  GameObject *pGVar4;
  undefined4 uVar5;
  byte bVar6;
  
  if (*(char *)((int)this + 0x24) != '\0') {
    return;
  }
  if ((param_1 != (S46 *)0x0) && (cVar1 = FUN_00482fa0(param_1), cVar1 == '\0'))
  {
    return;
  }
  *(undefined1 *)((int)this + 0x24) = 1;
  iVar3 = *(int *)(*(int *)((int)this + 8) + 0x44) + -1;
  switch(iVar3) {
  case 0:
  case 1:
    goto switchD_00486449_caseD_1;
  case 2:
    pGVar4 = SpriteS1::GetObject((SpriteS1 *)param_1);
    *(bool *)((int)this + 0x24) = pGVar4 != (GameObject *)0x0;
    goto LAB_004864b0;
  case 3:
  case 4:
    iVar3 = SpriteS1::SpriteS1_FUN_0040fea0((SpriteS1 *)param_1);
    *(bool *)((int)this + 0x24) = iVar3 != 0;
    goto LAB_004864b0;
  case 5:
    bVar6 = FUN_00483b50(this,param_1);
    *(byte *)((int)this + 0x24) = bVar6;
    if (bVar6 != 0) {
      S61::S61_FUN_00482f60((S61 *)this);
    }
    break;
  case 6:
  case 7:
    if (param_1 == (S46 *)0x0) {
      S63::S63_FUN_00485c90((S63 *)this);
    }
    else {
      S63::S63_FUN_00486390((S63 *)this,param_1);
      *(char *)((int)this + 0x24) = (char)iVar3;
    }
LAB_004864b0:
    if (*(char *)((int)this + 0x24) == '\0') {
      return;
    }
switchD_00486449_caseD_1:
    S61::S61_FUN_00482f60((S61 *)this);
    break;
  case 8:
    bVar6 = FUN_00483b50(this,param_1);
    goto LAB_004864d0;
  case 9:
    if (param_1 == (S46 *)0x0) break;
    iVar3 = SpriteS1::SpriteS1_FUN_0040fea0((SpriteS1 *)param_1);
    bVar6 = iVar3 != 0;
LAB_004864d0:
    *(byte *)((int)this + 0x24) = bVar6;
    break;
  case 10:
    *(undefined1 *)((int)this + 0x24) = 0;
  }
  if (*(char *)((int)this + 0x24) != '\0') {
    if (param_1 == (S46 *)0x0) {
      if (DAT_005e6874 == 4) {
        CameraOrPhysics::S131_FUN_004102a0
                  ((CameraOrPhysics *)gCameraOrPhysics,*(S110 **)((int)this + 4)
                  );
        return;
      }
      if (DAT_005e6874 == 5) {
        CameraOrPhysics::S131_FUN_00410370
                  ((CameraOrPhysics *)gCameraOrPhysics,*(S46 **)((int)this + 4))
        ;
        return;
      }
      CameraOrPhysicsCameraOrPhysics::S1331_FUN_00410460
                (gCameraOrPhysics,*(undefined4 *)((int)this + 4));
      return;
    }
    bVar2 = S61::S61_FUN_00421060((S61 *)this);
    if ((!bVar2) || (uVar5 = FUN_004bca80(param_1), (char)uVar5 == '\0')) {
      CameraOrPhysics::S131_FUN_00410480
                ((CameraOrPhysics *)gCameraOrPhysics,
                 *(undefined4 *)((int)this + 4),(SpriteS1 *)param_1);
    }
  }
  return;
}


void __thiscall S46__FUN_004ba070(void *this,S46 *param_1,undefined4 param_2)

{
  *(undefined4 *)((int)this + 4) = param_2;
  *(S46 **)this = param_1;
  Decoder_ShiftLeft(&param_1,(void *)0x0);
  *(S46 **)((int)this + 8) = param_1;
  return;
}


S46 * __thiscall S46__S46(S46 *this)

{
  CarSystemManager::SetIndexDefautCarManager
            ((CarSystemManager *)&this->CarSystemManager);
  return this;
}


byte __thiscall S46__S38_FUN_004bcac0(SpriteS1 *this,S46 *param_1)

{
  Player *this_00;
  Player *this_01;
  char cVar1;
  byte bVar2;
  
  this_00 = *(Player **)&param_1->field_0xc;
  this_01 = (Player *)this->S3_arr5031[0].SpriteS3;
  cVar1 = FUN_0041e2f0(&this_00->EnterControlStatus);
  if (cVar1 == '\0') {
    return 0;
  }
  bVar2 = Player::IsActionAllowed(this_01);
  if ((bVar2 != 0) || (bVar2 = thunk_FUN_0041e110(this), bVar2 != 0)) {
    bVar2 = Player::IsActionAllowed(this_00);
    if (bVar2 != 0) {
      return 1;
    }
    bVar2 = thunk_FUN_0041e110(param_1);
    if (bVar2 != 0) {
      return 1;
    }
  }
  bVar2 = FUN_004bb560(this,(int)param_1);
  if ((bVar2 == 0) && (bVar2 = FUN_004bb560(param_1,(int)this), bVar2 == 0)) {
    return 0;
  }
  return 1;
}


char __thiscall S46__S46_1_FUN_004be870(S46 *this,Sprite *pSprite)

{
  SpriteS1 *this_00;
  char cVar1;
  S63 *pS63;
  Car *pCar;
  GameObject *this_01;
  undefined2 extraout_var;
  undefined4 uVar2;
  
  this_00 = (SpriteS1 *)this->DATA;
  pS63 = SpriteS1::SpriteS1_FUN_0040fec0(this_00);
  if (pS63 == (S63 *)0x0) {
    pCar = (Car *)SpriteS1::GetObject(this_00);
    if (pCar == (Car *)0x0) {
      cVar1 = '\0';
      uVar2 = _DAT_006703b0;
      this_01 = (GameObject *)SpriteS1::SpriteS1_FUN_0040fea0(this_00);
      GameObject::FUN_0049c460(this_01,uVar2);
    }
    else {
      cVar1 = FUN_00429ff0(pSprite,*(undefined4 *)&this->field_0x8,
                           *(undefined4 *)&this->field_0xc,
                           CONCAT22(extraout_var,
                                    *(undefined2 *)&this->CarSystemManager));
      if (cVar1 != '\0') {
        CarsPrefabs::S5_FUN_0040f490(gCarsPrefabs,pCar);
        return cVar1;
      }
    }
  }
  else {
    cVar1 = FUN_00486130(pSprite,*(undefined4 *)&this->field_0x8,
                         *(undefined4 *)&this->field_0xc,
                         *(undefined2 *)&this->CarSystemManager);
    if (cVar1 != '\0') {
      S61::S61_FUN_00484db0(_gObject,pS63);
      return cVar1;
    }
  }
  return cVar1;
}


void __thiscall S46__S45_1_FUN_004bec50(SpriteS4 *this,S46 *pS46_)

{
  pS46_->NextElement = this->FirstElement;
  this->FirstElement = pS46_;
  return;
}


void __thiscall S46__FUN_004bec60(void *this,S46 *param_1)

{
  S46 *pSVar1;
  S46 *pS46_;
  
                              // WARNING: Load size is inaccurate
  pS46_ = *this;
  if (pS46_->DATA != param_1) {
    do {
      pSVar1 = pS46_;
      pS46_ = pSVar1->NextElement;
    } while (pS46_->DATA != param_1);
    if (pSVar1 != (S46 *)0x0) {
      pSVar1->NextElement = pS46_->NextElement;
      SpriteS4::S45_1_FUN_004bec50(_gSpriteS4,pS46_);
      return;
    }
  }
  *(S46 **)this = pS46_->NextElement;
  SpriteS4::S45_1_FUN_004bec50(_gSpriteS4,pS46_);
  return;
}


void __thiscall S46__S46_1FUN_004becb0(S46 *this,S46 *pS46_4)

{
  S46 *pS46_;
  S46 *pS46_2;
  S46 *pS46_3;
  
  pS46_2 = this->DATA;
  pS46_3 = (S46 *)0x0;
  while( true ) {
    pS46_ = pS46_2;
    if (pS46_ == (S46 *)0x0) {
      return;
    }
    if (pS46_->DATA == pS46_4) break;
    pS46_2 = pS46_->NextElement;
    pS46_3 = pS46_;
  }
  if (pS46_3 != (S46 *)0x0) {
    pS46_3->NextElement = pS46_->NextElement;
    SpriteS4::S45_1_FUN_004bec50(_gSpriteS4,pS46_);
    return;
  }
  this->DATA = pS46_->NextElement;
  SpriteS4::S45_1_FUN_004bec50(_gSpriteS4,pS46_);
  return;
}


void __thiscall S46__S46_1FUN_004becb0(S46 *this,S46 *pS46_4)

{
  S46 *pS46_;
  S46 *pS46_2;
  S46 *pS46_3;
  
  pS46_2 = this->DATA;
  pS46_3 = (S46 *)0x0;
  while( true ) {
    pS46_ = pS46_2;
    if (pS46_ == (S46 *)0x0) {
      return;
    }
    if (pS46_->DATA == pS46_4) break;
    pS46_2 = pS46_->NextElement;
    pS46_3 = pS46_;
  }
  if (pS46_3 != (S46 *)0x0) {
    pS46_3->NextElement = pS46_->NextElement;
    SpriteS4::S45_1_FUN_004bec50(_gSpriteS4,pS46_);
    return;
  }
  this->DATA = pS46_->NextElement;
  SpriteS4::S45_1_FUN_004bec50(_gSpriteS4,pS46_);
  return;
}


    else S46__if (pSVar2 == (S46 *)0x0) {
      pSVar1 = pS46_->NextElement;
      SpriteS4::S45_1_FUN_004bec50(_gSpriteS4,pS46_);
      this->void1 = pSVar1;
      pS46_ = pSVar1;
    }


S46 * __thiscall S46__S46_1_FUN_004bee10(S46 *this)

{
  S46 *pS46_;
  S46 *pSVar1;
  
  pS46_ = this->DATA;
  if (pS46_ == (S46 *)0x0) {
    return pS46_;
  }
  pSVar1 = pS46_->DATA;
  this->DATA = pS46_->NextElement;
  SpriteS4::S45_1_FUN_004bec50(_gSpriteS4,pS46_);
  return pSVar1;
}


void __thiscall S46__S25_FUN_004c4fe0(S25 *this,byte param_1,S46 *param_2)

{
  int *piVar1;
  S46 *this_00;
  bool bVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  int iVar3;
  GameObject *this_01;
  Ped *pPVar4;
  void *pvVar5;
  Player *pPVar6;
  undefined3 extraout_var_02;
  undefined4 uVar7;
  undefined3 in_stack_00000005;
  ushort uVar8;
  Player *pPVar9;
  undefined1 local_8 [4];
  undefined1 local_4 [4];
  
  this_00 = param_2;
  piVar1 = this->arr_22 + (uint)param_1 * 6 + -2;
  if (this->arr_22[(uint)param_1 * 6 + 3] != 1) {
    return;
  }
  if (piVar1[1] == 0) {
    return;
  }
  this_01 = (GameObject *)param_2;
  switch(piVar1[2]) {
  case 1:
    iVar3 = SpriteS1::FUN_00416b40((SpriteS1 *)param_2);
    this_01 = (GameObject *)param_2;
    if (iVar3 == 2) {
      piVar1[5] = 0;
      this_01 = SpriteS1::GetObject((SpriteS1 *)this_00);
    }
    break;
  case 2:
    iVar3 = SpriteS1::FUN_00416b40((SpriteS1 *)param_2);
    this_01 = (GameObject *)param_2;
    if (iVar3 == 2) {
      this_01 = SpriteS1::GetObject((SpriteS1 *)this_00);
      pvVar5 = MissionManager__StartMission
                         (_gMissionManager,*(ushort *)(*piVar1 + 8));
      if (this_01->field63_0x6c == *(int *)(*(int *)((int)pvVar5 + 8) + 0x6c)) {
        piVar1[5] = 0;
      }
    }
    break;
  case 3:
    iVar3 = SpriteS1::FUN_00416b40((SpriteS1 *)param_2);
    if (iVar3 != 3) {
      iVar3 = SpriteS1::FUN_00416b40((SpriteS1 *)this_00);
      this_01 = (GameObject *)param_2;
      if (iVar3 != 2) break;
      this_01 = SpriteS1::GetObject((SpriteS1 *)this_00);
      pPVar4 = Get_FUN_004118b0(this_01);
      if (pPVar4 == (Ped *)0x0) break;
      iVar3 = *piVar1;
      if (*(short *)(iVar3 + 2) != 0x1b2) goto LAB_004c51b2;
      pvVar5 = MissionManager__StartMission
                         (_gMissionManager,*(ushort *)(iVar3 + 0x24));
      goto LAB_004c53bd;
    }
    pvVar5 = (void *)SpriteS1::SpriteS1_FUN_0040fea0((SpriteS1 *)this_00);
    pPVar4 = FUN_00433a20(pvVar5);
    this_01 = (GameObject *)param_2;
    if (pPVar4 == (Ped *)0x0) break;
    iVar3 = *piVar1;
    if (*(short *)(iVar3 + 2) == 0x1b2) {
      uVar8 = *(ushort *)(iVar3 + 0x24);
    }
    else {
LAB_004c50d9:
      uVar8 = *(ushort *)(iVar3 + 8);
    }
    goto LAB_004c50de;
  case 4:
    iVar3 = SpriteS1::FUN_00416b40((SpriteS1 *)param_2);
    this_01 = (GameObject *)param_2;
    if (iVar3 != 3) break;
    pvVar5 = (void *)SpriteS1::SpriteS1_FUN_0040fea0((SpriteS1 *)this_00);
    FUN_00433a20(pvVar5);
    iVar3 = *piVar1;
    if (*(short *)(iVar3 + 2) == 0xd4) {
      uVar8 = *(ushort *)(iVar3 + 0x10);
    }
    else {
      if (*(short *)(iVar3 + 2) != 0xd6) goto LAB_004c50d9;
      uVar8 = *(ushort *)(iVar3 + 0x24);
    }
LAB_004c50de:
    pvVar5 = MissionManager__StartMission(_gMissionManager,uVar8)
    ;
    iVar3 = FUN_004c4f20();
    bVar2 = iVar3 == *(int *)(*(int *)((int)pvVar5 + 8) + 0x200);
LAB_004c522d:
    this_01 = (GameObject *)param_2;
    if (bVar2) {
      piVar1[5] = 0;
    }
    break;
  case 5:
    iVar3 = SpriteS1::FUN_00416b40((SpriteS1 *)param_2);
    this_01 = (GameObject *)param_2;
    if (iVar3 != 2) break;
    this_01 = SpriteS1::GetObject((SpriteS1 *)this_00);
    pPVar4 = Get_FUN_004118b0(this_01);
    if (pPVar4 == (Ped *)0x0) break;
    iVar3 = *piVar1;
LAB_004c51b2:
    pvVar5 = MissionManager__StartMission
                       (_gMissionManager,*(ushort *)(iVar3 + 8));
    goto LAB_004c53bd;
  case 6:
    iVar3 = SpriteS1::FUN_00416b40((SpriteS1 *)param_2);
    if (iVar3 == 3) {
      pvVar5 = (void *)SpriteS1::SpriteS1_FUN_0040fea0((SpriteS1 *)this_00);
      pPVar4 = FUN_00433a20(pvVar5);
      this_01 = (GameObject *)param_2;
      if (pPVar4 == (Ped *)0x0) break;
      pvVar5 = MissionManager__StartMission
                         (_gMissionManager,*(ushort *)(*piVar1 + 8));
      pPVar9 = (Player *)&DAT_00672900;
      pPVar6 = (Player *)FUN_00433c20(pPVar4,&param_1);
      bVar2 = Player::IsCurrentPlayer(pPVar6,pPVar9);
      this_01 = (GameObject *)param_2;
      if (CONCAT31(extraout_var_00,bVar2) == 0) break;
      iVar3 = FUN_004c4f20();
      bVar2 = iVar3 == *(int *)(*(int *)((int)pvVar5 + 8) + 0x200);
      goto LAB_004c522d;
    }
    iVar3 = SpriteS1::FUN_00416b40((SpriteS1 *)this_00);
    this_01 = (GameObject *)param_2;
    if (iVar3 != 2) break;
    this_01 = SpriteS1::GetObject((SpriteS1 *)this_00);
    pPVar4 = Get_FUN_004118b0(this_01);
    if (pPVar4 == (Ped *)0x0) break;
    pvVar5 = MissionManager__StartMission
                       (_gMissionManager,*(ushort *)(*piVar1 + 8));
    pPVar9 = (Player *)&DAT_00672900;
    pPVar6 = (Player *)Ped::FUN_00436160(pPVar4,local_8);
    bVar2 = Player::IsCurrentPlayer(pPVar6,pPVar9);
    if (CONCAT31(extraout_var_01,bVar2) == 0) break;
    iVar3 = FUN_004c4f20();
    bVar2 = iVar3 == *(int *)(*(int *)((int)pvVar5 + 8) + 0x200);
    goto LAB_004c53cd;
  case 7:
    iVar3 = SpriteS1::FUN_00416b40((SpriteS1 *)param_2);
    this_01 = (GameObject *)param_2;
    if (iVar3 != 3) break;
    pvVar5 = (void *)SpriteS1::SpriteS1_FUN_0040fea0((SpriteS1 *)this_00);
    pPVar4 = FUN_00433a20(pvVar5);
    this_01 = (GameObject *)param_2;
    if (pPVar4 == (Ped *)0x0) break;
    pvVar5 = MissionManager__StartMission
                       (_gMissionManager,*(ushort *)(*piVar1 + 8));
    pPVar9 = (Player *)&DAT_00672900;
    pPVar6 = (Player *)FUN_00433c20(pPVar4,&param_2);
    bVar2 = Player::IsCurrentPlayer(pPVar6,pPVar9);
    this_01 = (GameObject *)param_2;
    if (CONCAT31(extraout_var,bVar2) == 0) break;
    iVar3 = FUN_004c4f20();
    bVar2 = iVar3 == *(int *)(*(int *)((int)pvVar5 + 8) + 0x200);
    goto LAB_004c522d;
  case 8:
    iVar3 = SpriteS1::FUN_00416b40((SpriteS1 *)param_2);
    this_01 = (GameObject *)param_2;
    if (iVar3 != 2) break;
    this_01 = SpriteS1::GetObject((SpriteS1 *)this_00);
    pPVar4 = Get_FUN_004118b0(this_01);
    if (pPVar4 == (Ped *)0x0) break;
    pvVar5 = MissionManager__StartMission
                       (_gMissionManager,*(ushort *)(*piVar1 + 8));
    pPVar9 = (Player *)&DAT_00672900;
    pPVar6 = (Player *)Ped::FUN_00436160(pPVar4,local_4);
    bVar2 = Player::IsCurrentPlayer(pPVar6,pPVar9);
    if (CONCAT31(extraout_var_02,bVar2) == 0) break;
LAB_004c53bd:
    iVar3 = FUN_004c4f20();
    bVar2 = iVar3 == *(int *)(*(int *)((int)pvVar5 + 8) + 0x200);
LAB_004c53cd:
    if (bVar2) {
      piVar1[5] = 0;
    }
  }
  if (piVar1[5] == 0) {
    if (piVar1[3] == 2) {
      iVar3 = *piVar1;
      uVar7 = FUN_0047f200(*(undefined2 *)(iVar3 + 0xe),0);
      *(undefined4 *)(iVar3 + 8) = uVar7;
    }
    else if (piVar1[3] == 3) {
      FUN_0047ed20(this_01->Car_1,*piVar1);
      FUN_004c4ea0((char)piVar1[4]);
      return;
    }
  }
  return;
}


