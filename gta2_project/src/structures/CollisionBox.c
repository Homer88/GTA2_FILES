// Module: S61
// Functions working with structure S61
// Generated from gta2.exe.c

#include "../../include/common.h"

undefined1 __thiscall S61__S61_FUN_00421050(S61 *this)

{
  return this->Arr_3825_S63[0].field_0x1e;
}


bool __thiscall S61__S61_FUN_00421060(S61 *this)

{
  int iVar1;
  
  iVar1 = this->Arr_3825_S63[0].IsFlag[1].Struc___;
  if ((((iVar1 != 6) && (iVar1 != 7)) && (iVar1 != 8)) && (iVar1 != 9)) {
    return false;
  }
  return true;
}


void __thiscall S61__Car_FUN_00427d10(Car *this,S61 *pS61)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = Car_FUN_004215c0(this);
  if ((bVar1 != 0) && (pS61->Arr_3825_S63[0].s6 == (S6 *)0x82)) {
    bVar1 = FUN_00421020(pS61);
    pS61 = (S61 *)CONCAT31(pS61._1_3_,bVar1);
    if ((0xf9 < bVar1) && ((bVar1 < 0xfd || (bVar1 == 0xfe)))) {
      iVar2 = FUN_00420760(bVar1);
      Car_FUN_004244a0(this,iVar2);
      return;
    }
    Car_FUN_00427ca0(this,pS61);
  }
  return;
}


byte __thiscall S61__Car_FUN_004293d0(Car *this,S61 *pS61)

{
  S6 *pSVar1;
  bool bVar2;
  undefined1 uVar3;
  byte bVar4;
  Car *this_00;
  Ped *this_01;
  
  bVar2 = S61::S61_FUN_00421060(pS61);
  if ((bVar2) || (pSVar1 = pS61->Arr_3825_S63[0].s6, pSVar1 == (S6 *)0x10a)) {
    this_01 = Car_FUN_00423480(this);
    if (this_01 != (Ped *)0x0) {
      bVar4 = FUN_0043e550(this_01,pS61);
      return bVar4;
    }
  }
  else {
    switch(pSVar1) {
    case (S6 *)0x8:
    case (S6 *)0x9:
      Player::cPlayer_FUN_0049f2d0(this->Player);
      return 0;
    case (S6 *)0x81:
      PublicTransport::S81_FUN_004b0d70(_gPublicTransport,this);
      break;
    case (S6 *)0x82:
      this_00 = (Car *)Car_FUN_0041fab0(this);
      Car_FUN_00427d10(this_00,pS61);
      return 1;
    case (S6 *)0x89:
      uVar3 = S61::S61_FUN_00421050(pS61);
      FUN_004497e0(this,uVar3);
      return 0;
    case (S6 *)0x8b:
      FUN_0049f460(this->Player,pS61);
      return 0;
    case (S6 *)0x8d:
      if (this->Driver == (Ped *)0x0) {
        FUN_00421490(this);
        return 0;
      }
      break;
    case (S6 *)0x8f:
      bVar4 = S61::S61_FUN_00421050(pS61);
      S105::S105_FUN_0044a970(gS105,this,bVar4);
      return 0;
    case (S6 *)0xa1:
      S25::S25_FUN_004c4fe0
                (_gS25,pS61->Arr_3825_S63[0].field_0x1f,(S46 *)this->CarSprite);
      return 0;
    case (S6 *)0xa7:
      bVar4 = S61::S61_FUN_00421050(pS61);
      Door::S75_FUN_0044d180(gDoor,this,bVar4);
      return 0;
    }
  }
  return 0;
}


undefined1 __thiscall S61__S61_FUN_004340a0(S61 *this)

{
  return this->Arr_3825_S63[0].field_0x1e;
}


char __thiscall S61__FUN_0043e550(void *this,S61 *pS61)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  S6 *pSVar4;
  undefined4 unaff_EDI;
  
  if (*(int *)((int)this + 0x238) != 2) {
    return '\0';
  }
  cVar1 = max_frame_rate_(&gPlayer_2);
  if (((cVar1 != '\0') &&
      (bVar2 = Player::cPlayer_FUN_00434b20((Player *)&gPlayer_2), bVar2 != 0))
     && (bVar2 = FUN_00434b60(&gPlayer_2,this), bVar2 != 0)) {
    return '\0';
  }
  pSVar4 = pS61->Arr_3825_S63[0].s6;
  if (pSVar4 != (S6 *)0x10a) {
    if ((int)pSVar4 < 0x6d) {
      pSVar4 = (S6 *)&pSVar4->field28_0x88;
    }
    if ((int)pSVar4 < 228) {
      cVar1 = S61::S61_FUN_004340a0(pS61);
      bVar2 = Ped::GiveWeapon((Ped *)this,&pSVar4[-2].field53_0xb0,cVar1);
    }
    else {
      bVar2 = Player::GivePowerUp(*(Player **)((int)this + 0x15c),
                                  (short)pSVar4 - 0xe4);
    }
    if (bVar2 != 0) {
      bVar3 = Player::GetCurrentPlayer(*(Player **)((int)this + 0x15c));
      if (bVar3 != 0) {
        FUN_004c69f0(&gHud->a,(char)pSVar4 + 0x38,unaff_EDI);
      }
      S63::FUN_00483c40((S63 *)pS61);
    }
    return bVar2;
  }
  MapGm::incrementSpecialTokens(&gMapGm);
  bVar2 = S61::S61_FUN_00421050(pS61);
  *(undefined1 *)(bVar2 + 0x20 + _gObject) = 0;
  S63::FUN_00483c40((S63 *)pS61);
  return '\x01';
}


S63 * __thiscall S61__S61_FUN_00482970(S61 *this)

{
  return this->Arr_3825_S63;
}


S63 * __thiscall S61__S61_FUN_004829a0(S61 *this)

{
  S63 *this_00;
  
  this_00 = this->Begin_S63;
  this->Begin_S63 = this_00->IsFlag;
  this_00->IsFlag = this->Index;
  this->Index = this_00;
  S63::S63_FUN_00482490(this_00);
  return this_00;
}


S63 * __thiscall S61__S61_FUN_004829c0(S61 *this)

{
  S63 *this_00;
  
  this_00 = this->Begin_S63;
  this->Begin_S63 = this_00->IsFlag;
  this_00->IsFlag = (S63 *)0x0;
  S63::S63_FUN_00482490(this_00);
  return this_00;
}


void __thiscall S61__S61_FUN_004829e0(S61 *this,undefined4 *param_1)

{
  *param_1 = this->Index;
  this->Index = (S63 *)param_1;
  return;
}


void __thiscall S61__S61_FUN_004829f0(S61 *this,undefined4 *param_1)

{
  S63 *pSVar1;
  S63 *pSVar2;
  S63 *pSVar3;
  
  pSVar3 = (S63 *)0x0;
  pSVar1 = this->Index;
  if (this->Index != (S63 *)0x0) {
    while (pSVar2 = pSVar1, pSVar2 != (S63 *)param_1) {
      pSVar1 = pSVar2->IsFlag;
      pSVar3 = pSVar2;
      if (pSVar2->IsFlag == (S63 *)0x0) {
        return;
      }
    }
    if (pSVar3 != (S63 *)0x0) {
      pSVar3->IsFlag = pSVar2->IsFlag;
      pSVar2->IsFlag = (S63 *)0x0;
      return;
    }
    this->Index = pSVar2->IsFlag;
    pSVar2->IsFlag = (S63 *)0x0;
  }
  return;
}


void __thiscall S61__S61_FUN_00482f60(S61 *this)

{
  if (this->Arr_3825_S63[0].DamageType == 2) {
    S61_FUN_004829e0(_gObject,&this->Begin_S63);
    this->Arr_3825_S63[0].DamageType = 1;
  }
  return;
}


bool __thiscall S61__FUN_004835e0(S61 *this,SpriteS1 *pSpriteS1)

{
  byte Index;
  char cVar1;
  bool bVar2;
  Car *this_00;
  int iVar3;
  S61 *this_01;
  
  switch(this->Arr_3825_S63[0].s6) {
  case (S6 *)0x7a:
    if (pSpriteS1 == (SpriteS1 *)0x0) {
      return false;
    }
    Index = FUN_00483570(this,pSpriteS1);
    return (bool)Index;
  case (S6 *)0xa9:
    if (pSpriteS1 == (SpriteS1 *)0x0) {
      return (bool)DAT_00665768;
    }
    Index = S61_FUN_00421050(this);
    Index = Door::FUN_0044d1e0(gDoor,pSpriteS1,Index);
    return (bool)Index;
  case (S6 *)0x126:
    if ((pSpriteS1 != (SpriteS1 *)0x0) &&
       (this_00 = (Car *)SpriteS1::GetObject(pSpriteS1), this_00 != (Car *)0x0))
    {
      bVar2 = Car::IsTrainOrTrainCarriage(this_00);
      return !bVar2;
    }
  default:
    if ((gCollide->field2_0x8 != 1) || (cVar1 = FUN_00482c90(), cVar1 == '\0'))
    {
      iVar3 = this->Arr_3825_S63[0].Struc___;
      if (iVar3 != 0) {
        if (*(int *)(iVar3 + 0x34) != 2) {
          return false;
        }
        if (pSpriteS1 == (SpriteS1 *)0x0) {
          iVar3 = this->Arr_3825_S63[0].IsFlag[1].field14_0x20;
          if (iVar3 == 3) {
            return false;
          }
          if (iVar3 != 0) {
            return true;
          }
          return false;
        }
        iVar3 = SpriteS1::FUN_00416b40(pSpriteS1);
        if (iVar3 != 3) {
          iVar3 = this->Arr_3825_S63[0].IsFlag[1].field14_0x20;
          if (iVar3 == 3) {
            return false;
          }
          if (iVar3 == 0) {
            return false;
          }
        }
      }
      if ((pSpriteS1 != (SpriteS1 *)0x0) &&
         (this_01 = (S61 *)SpriteS1::SpriteS1_FUN_0040fec0(pSpriteS1),
         this_01 != (S61 *)0x0)) {
        iVar3 = this_01->Arr_3825_S63[0].IsFlag[1].DamageType;
        if ((iVar3 == 7) || (iVar3 == 8)) {
          iVar3 = *(int *)&this->Arr_3825_S63[0].IsFlag[1].z;
          if (iVar3 == 0) {
            return false;
          }
          if (iVar3 == 0xc) {
            return true;
          }
          if (iVar3 == 0xd) {
            return true;
          }
        }
        if (this_01->Arr_3825_S63[0].s6 == (S6 *)0x8b) {
          return false;
        }
        bVar2 = S61_FUN_00421060(this_01);
        if ((bVar2) && (bVar2 = S61_FUN_00421060(this), !bVar2)) {
          return false;
        }
      }
      return true;
    }
  case (S6 *)0x8b:
    return false;
  }
}


void __thiscall S61__S61__FUN_00483c50(S61 *this)

{
  S61_FUN_00482f60(this);
  this->Arr_3825_S63[0].z = 1;
  return;
}


void __thiscall S61__S61_FUN_00483c60(S61 *this,byte param_1)

{
  S61_FUN_00482f60(this);
  this->Arr_3825_S63[0].z = param_1;
  return;
}


undefined4 __thiscall S61__S61_FUN_00483cc0(S61 *this)

{
  S63 *pSVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  ushort *puVar6;
  
  pSVar1 = this->Index;
  iVar3 = Decoder_DecodeFloat(&pSVar1->z);
  iVar4 = Decoder_DecodeFloat(&pSVar1->DamageType);
  iVar5 = Decoder_DecodeFloat(&pSVar1->CameraX);
  puVar6 = (ushort *)
           MapRelatedStruct::S16_FUN_004653c0
                     (_gMapRelatedStruct,iVar5,iVar4,iVar3);
  uVar2 = S61_FUN_00421050(this);
  switch(uVar2) {
  case 0x2d:
  case 0x2f:
    iVar3 = Style::S15_FUN_00462fd0(gStyle,*puVar6 & 0x3ff);
    return iVar3;
  case 0x2e:
  case 0x30:
    iVar3 = Style::S15_FUN_00462fd0(gStyle,puVar6[1] & 0x3ff);
    return iVar3;
  default:
    return 0;
  }
}


void __thiscall S61__FUN_00483ea0(S61 *this)

{
  this->Begin_S63 = (S63 *)0x0;
  this->Index = (S63 *)0x0;
  _eh_vector_destructor_iterator_(this->Arr_3825_S63,0x2c,3825,S63::~S63);
  return;
}


S61 * __thiscall S61__S61(S61 *this)

{
  S63 *pSVar1;
  S63 *pSVar2;
  int iVar3;
  
  pSVar1 = this->Arr_3825_S63;
  _eh_vector_constructor_iterator_(pSVar1,44,3825,S63::S63,S63::~S63);
  iVar3 = 3824;
  pSVar2 = pSVar1;
  do {
    iVar3 = iVar3 + -1;
    pSVar2->IsFlag = pSVar2 + 1;
    pSVar2 = pSVar2 + 1;
  } while (iVar3 != 0);
  this->Begin_S63 = pSVar1;
  this->Arr_3825_S63[3824].IsFlag = (S63 *)0x0;
  this->Index = (S63 *)0x0;
  this->a = 0;
  return this;
}


void __thiscall S61__S61_FUN_00484880(S61 *this)

{
  S67 *pSVar1;
  
  if (this->Arr_3825_S63[0].Struc___ == 0) {
    pSVar1 = S66::S66_FUN_00483fe0(_gS66);
    this->Arr_3825_S63[0].Struc___ = pSVar1;
    pSVar1->field11_0x20 = this->Arr_3825_S63[0].S116;
    *(undefined4 *)(this->Arr_3825_S63[0].Struc___ + 0xc) = _DAT_00665894;
    *(undefined4 *)(this->Arr_3825_S63[0].Struc___ + 0x10) = _DAT_00665894;
  }
  S61_FUN_00482f60(this);
  return;
}


void S61__FUN_00484ad0(S61 *param_1)

{
  undefined1 uVar1;
  
  uVar1 = S61::S61_FUN_00421050(param_1);
  FUN_00484aa0(uVar1);
  return;
}


void __thiscall S61__S61_FUN_00484d60(S61 *this,S63 *param_1)

{
  S63 *pSVar1;
  S63 *this_00;
  S63 *pSVar2;
  
  pSVar2 = (S63 *)0x0;
  pSVar1 = this->Index;
  if (this->Index != (S63 *)0x0) {
    while (this_00 = pSVar1, this_00 != param_1) {
      pSVar1 = this_00->IsFlag;
      pSVar2 = this_00;
      if (this_00->IsFlag == (S63 *)0x0) {
        return;
      }
    }
    S63::S63_FUN_00484910(this_00);
    if (pSVar2 != (S63 *)0x0) {
      pSVar2->IsFlag = this_00->IsFlag;
      this_00->IsFlag = this->Begin_S63;
      this->Begin_S63 = this_00;
      return;
    }
    this->Index = this_00->IsFlag;
    this_00->IsFlag = this->Begin_S63;
    this->Begin_S63 = this_00;
  }
  return;
}


void __thiscall S61__S61_FUN_00484db0(S61 *this,S63 *pS63)

{
  S63::S63_FUN_00484910(pS63);
  pS63->IsFlag = this->Begin_S63;
  this->Begin_S63 = pS63;
  return;
}


void __thiscall S61__FUN_004856e0(S61 *param_1,byte param_2)

{
  byte bVar1;
  int iVar2;
  S63 *pSVar3;
  undefined1 extraout_CL;
  int extraout_EDX;
  
  bVar1 = FUN_00482400(param_1->Arr_3825_S63[0].IsFlag[1].s6);
  if (bVar1 == 0) {
    if (*(int *)(extraout_EDX + 0x48) == 0xd) {
      S61::S61__FUN_00483c50(param_1);
      pSVar3 = param_1->Index;
      iVar2 = S68::S68GetPedID(_gS68,param_2);
      pSVar3 = (S63 *)Object::S60_FUN_00485540
                                (_gObject,*(undefined4 *)&pSVar3->CameraX,
                                 pSVar3->DamageType,*(undefined4 *)&pSVar3->z,
                                 (void *)CONCAT22((short)((uint)iVar2 >> 0x10),
                                                  _DAT_006657f8______S38),0x13);
      if (pSVar3 != (S63 *)0x0) {
        S63::S63_FUN_00482790(pSVar3,param_2);
      }
    }
    return;
  }
  S61::S61_FUN_00483c60(param_1,extraout_CL);
  return;
}


void __thiscall S61__FUN_004993b0(void *this,S61 *param_1)

{
  int iVar1;
  S61 *this_00;
  byte bVar2;
  char cVar3;
  bool bVar4;
  void *this_01;
  undefined3 extraout_var;
  undefined4 *puVar5;
  SpriteS1 *pSpriteS1;
  undefined1 local_1a;
  undefined1 local_19;
  undefined1 local_18 [8];
  undefined4 local_10;
  undefined4 local_c;
  undefined1 local_8 [8];
  
  this_00 = param_1;
  local_1a = 0;
  bVar2 = S63::S63_FUN_00421080((S63 *)param_1);
  if (((bVar2 != 0) &&
      (cVar3 = S63::S63_FUN_00420ff0((S63 *)this_00), cVar3 != '\0')) &&
     (cVar3 = S63::S63_FUN_00420ff0((S63 *)this_00),
     cVar3 == *(char *)(*(int *)((int)this + 0x7c) + 0x267))) {
    return;
  }
  cVar3 = FUN_00482c90();
  if (cVar3 == '\0') goto LAB_004994bb;
  bVar4 = Ped::HasSearchType(*(Ped **)((int)this + 0x7c),
                             SEARCHTYPE_LINE_OF_SIGHT_PLAYER_ONLY);
  if (bVar4) {
    bVar4 = *(int *)((int)this + 0x10) == 0xf;
LAB_00499425:
    if (bVar4) goto LAB_004994bb;
  }
  else {
    iVar1 = this_00->Arr_3825_S63[0].IsFlag[1].field14_0x20;
    bVar4 = iVar1 != 3;
    if (iVar1 != 0) goto LAB_00499425;
  }
  pSpriteS1 = (SpriteS1 *)&DAT_0066a464;
  this_01 = (void *)FUN_00482c80(local_18);
  bVar4 = FUN_004037e0(this_01,pSpriteS1);
  if (CONCAT31(extraout_var,bVar4) != 0) {
    SpriteS1::SetPosition
              (*(SpriteS1 **)((int)this + 0x80),_DAT_0066a480,_DAT_0066a74c,
               _DAT_0066a754);
    puVar5 = (undefined4 *)
             FUN_004bd8a0(local_18,this_00->Index,local_8,
                          CONCAT22((short)((uint)&param_1 >> 0x10),
                                   **(undefined2 **)((int)this + 0x80)),
                          &local_19,&param_1,&local_1a);
    local_10 = *puVar5;
    local_c = puVar5[1];
    FUN_004867e0(this,&local_10,1);
    return;
  }
  *(undefined1 *)((int)this + 0x5c) = 10;
LAB_004994bb:
  FUN_004948c0(this,(Car *)0x0,(int)this_00,0);
  return;
}


void __thiscall S61__FUN_0049f460(void *this,S61 *pS61)

{
  int *piVar1;
  char local_9;
  int local_8;
  undefined1 local_4 [4];
  
  S61::S61_FUN_00493090(pS61,&pS61,&local_9);
  local_8 = (int)(char)pS61;
  piVar1 = (int *)FUN_00401bd0(&DAT_0066ac10,local_4,&local_8);
  FUN_0040e530(&DAT_0066b004,piVar1);
  local_8 = (int)local_9;
  piVar1 = (int *)FUN_00401bd0(&DAT_0066ac10,local_4,&local_8);
  FUN_0040e530(&DAT_0066b008,piVar1);
  Player::cPlayer_FUN_0049ef50((Player *)this,0xf);
  return;
}


