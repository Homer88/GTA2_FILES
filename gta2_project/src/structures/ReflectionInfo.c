// Module: S102
// Functions working with structure S102
// Generated from gta2.exe.c

#include "common.h"

void __thiscall S102__S102_FUN_0048a5a0(S102 *this)

{
  byte bVar1;
  byte bVar2;
  byte local_9;
  uint local_8;
  uint local_4;
  
  bVar2 = 0;
  bVar1 = 0;
  local_9 = 99;
  local_4 = 99;
  local_8 = 0;
  do {
    if (this->FLAG[local_8] == 1) {
      switch(this->ARR_S101_0x28[local_8].field6_0x10) {
      default:
        goto switchD_0048a5e9_caseD_1;
      case 5:
      case 0x1c:
      case 0x1d:
      case 0x1e:
        bVar2 = 2;
        break;
      case 0xc:
      case 0xe:
      case 0xf:
        bVar2 = 5;
        break;
      case 0xd:
        bVar2 = 4;
        break;
      case 0x10:
      case 0x11:
        bVar2 = 6;
        break;
      case 0x12:
      case 0x21:
        if (0x51 < (ushort)this->ARR_S101_0x28[local_8].field9_0x1a)
        goto switchD_0048a5e9_caseD_2;
        bVar2 = 3;
        break;
      case 0x13:
      case 0x14:
      case 0x20:
        if ((ushort)this->ARR_S101_0x28[local_8].field9_0x1a < 0x32)
        goto switchD_0048a5e9_caseD_16;
      case 2:
      case 3:
      case 4:
      case 0x15:
      case 0x1f:
      case 0x22:
switchD_0048a5e9_caseD_2:
        if (bVar2 == 1) {
switchD_0048a5e9_caseD_1:
          this->ARR_S101_0x28[local_8].field9_0x1a = 0;
          return;
        }
        break;
      case 0x16:
      case 0x17:
      case 0x18:
      case 0x19:
switchD_0048a5e9_caseD_16:
        bVar2 = 3;
      }
      if (bVar2 < local_9) {
        local_4 = (uint)bVar1;
        local_9 = bVar2;
      }
    }
    bVar1 = bVar1 + 1;
    local_8 = (uint)bVar1;
    if (0x27 < bVar1) {
      this->ARR_S101_0x28[local_4].field9_0x1a = 0;
      return;
    }
  } while( true );
}


byte __thiscall S102__S102_FUN_0048a6c0(S102 *this)

{
  byte bVar1;
  uint local_4;
  S101 *pS101_1;
  
  bVar1 = 0;
  local_4 = 0;
  do {
    if (this->FLAG[local_4] == 0) {
      pS101_1 = this->ARR_S101_0x28 + local_4;
      S101::S101_FUN_0048a550(pS101_1);
      pS101_1->Ids = bVar1;
      pS101_1->field3_0x6 = DAT_00593220;
      DAT_00593220 = DAT_00593220 + 1;
      pS101_1->a = (S6 *)0x0;
      this->FLAG[local_4] = 1;
      return (byte)pS101_1;
    }
    bVar1 = bVar1 + 1;
    local_4 = (uint)bVar1;
  } while (bVar1 < 0x14);
  S102_FUN_0048a5a0(this);
  bVar1 = 0;
  local_4 = 0;
  do {
    if (this->FLAG[local_4] == 0) {
      pS101_1 = this->ARR_S101_0x28 + local_4;
      S101::S101_FUN_0048a550(pS101_1);
      pS101_1->Ids = bVar1;
      pS101_1->field3_0x6 = DAT_00593220;
      DAT_00593220 = DAT_00593220 + 1;
      pS101_1->a = (S6 *)0x0;
      this->FLAG[local_4] = 1;
      return (byte)pS101_1;
    }
    bVar1 = bVar1 + 1;
    local_4 = (uint)bVar1;
  } while (bVar1 < 0x28);
  return 0;
}


S102 * __thiscall S102__S102(S102 *this)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  _eh_vector_constructor_iterator_(this,0x30,0x28,S101::S101,S101::~S101);
  bVar1 = 0;
  pbVar3 = this->FLAG;
  pbVar2 = &this->ARR_S101_0x28[0].Ids;
  do {
    *pbVar2 = bVar1;
    *pbVar3 = 0;
    bVar1 = bVar1 + 1;
    pbVar2 = pbVar2 + 0x30;
    pbVar3 = pbVar3 + 1;
  } while (bVar1 < 0x28);
  _DAT_00669e80 = 0;
  return this;
}


