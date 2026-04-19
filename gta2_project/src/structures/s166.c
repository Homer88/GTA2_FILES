// Module: S166
// Functions working with structure S166
// Generated from gta2.exe.c

#include "../../include/common.h"

void __thiscall S166__S166_FUN_004c6290(S166 *this)

{
  int iVar1;
  
  iVar1 = this->S167[0].field0_0x0;
  if ((-1 < iVar1) &&
     (iVar1 = iVar1 + -1, this->S167[0].field0_0x0 = iVar1, iVar1 == -1)) {
    this->S167[0].field1_0x4 = 0;
  }
  return;
}


void __thiscall S166__FUN_004c62b0(S166 *this)

{
  int extraout_ECX;
  int extraout_EDX;
  
  do {
    S166_FUN_004c6290(this);
    this = (S166 *)(extraout_ECX + 0xc);
  } while (extraout_EDX != 1);
  return;
}


void __thiscall S166__S166_Set_004c7120(S166 *this,int param_1)

{
  this->S167[0].field0_0x0 = param_1;
  return;
}


byte __thiscall S166__S166_Get_004c7160(S166 *this)

{
  return this->S167[0].field1_0x4 == 0;
}


bool __thiscall S166__S166_Get_004c7170(S166 *this)

{
  return this->S167[0].field0_0x0 < 0;
}


undefined1 __thiscall S166__S166_FUN_004c7250(S166 *this,short param_1)

{
  undefined1 uVar1;
  short sVar2;
  
  sVar2 = Style::GetBaseIndex(gStyle,6,param_1);
  uVar1 = Style::S15_FUN_004c6c90(gStyle,sVar2);
  return uVar1;
}


void __thiscall S166__FUN_004c92a0(S166 *this)

{
  char cVar1;
  char cVar2;
  char cVar3;
  undefined1 uVar4;
  char cVar5;
  int3 extraout_var;
  S166 *this_00;
  S166 *this_01;
  Hud *this_02;
  byte bVar6;
  int local_4;
  
  cVar1 = S166_FUN_004c7250(this,0x77);
  cVar2 = S166_FUN_004c7250(this_00,0x76);
  cVar3 = S166_FUN_004c7250(this_01,0x75);
  uVar4 = Hud::S86_FUN_004c7220(this_02,0x75);
  cVar5 = MapGm::MapGm_Get_0045e540(&gMapGm);
  local_4 = 4;
  bVar6 = (-(cVar5 != '\0') & 0xbcU) + 0x68;
  do {
    FUN_004c9040(this,(char)(CONCAT31(extraout_var,uVar4) -
                             ((int)extraout_var >> 0x17) >> 1) + 3,bVar6);
    bVar6 = bVar6 + cVar1 + cVar2 + cVar3;
    this = (S166 *)((int)this + 0xc);
    local_4 = local_4 + -1;
  } while (local_4 != 0);
  return;
}


int __thiscall S166__FUN_004c9310(S166 *this,int param_1)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    bVar1 = S166_Get_004c7170(this);
    if (bVar1) {
      bVar2 = S166_Get_004c7160(this);
      if (bVar2 != 0) {
        S166_Set_004c7120(this,param_1 * 0x1e);
        return iVar3;
      }
    }
    iVar3 = iVar3 + 1;
    this = (S166 *)((int)this + 0xc);
  } while (iVar3 < 4);
  return -1;
}


void __thiscall S166__FUN_004c93b0(S166 *this,int param_1)

{
  S167::~S167(this->S167 + param_1);
  return;
}


S166 * __thiscall S166__S166(S166 *this)

{
  _eh_vector_constructor_iterator_(this,0xc,4,S167::S167,S167::~S167);
  return this;
}


