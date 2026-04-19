// Module: S113
// Functions working with structure S113
// Generated from gta2.exe.c

#include "../../include/common.h"

byte __thiscall S113__S111_FUN_004a9ef0(Police *this,S113 *pS113)

{
  undefined4 uVar1;
  S113 *pSVar2;
  byte bVar3;
  int iVar4;
  S112 *this_00;
  S110 *pSVar5;
  byte local_c [4];
  byte local_8 [4];
  undefined4 local_4;
  
  pSVar2 = pS113;
  iVar4 = DecoderFloat(&pS113->S110);
  pS113 = (S113 *)CONCAT31(pS113._1_3_,(char)iVar4);
  iVar4 = DecoderFloat(&pSVar2->ped2);
  local_c[0] = (char)iVar4;
  iVar4 = DecoderFloat(&pSVar2->ped1);
  local_8[0] = (char)iVar4;
  bVar3 = S95::S95_FUN_0049d7a0
                    (_gS95,'\x01',(byte *)&pS113,local_c,local_8,'\0');
  if (bVar3 != 0) {
    this_00 = S111_FUN_004a9ae0(this);
    this_00->field15_0x1c = 1;
    this_00->field2_0x2 = (byte)pS113;
    this_00->field3_0x3 = local_c[0];
    this_00->field4_0x4 = local_8[0];
    pSVar5 = (S110 *)S109::S109_FUN_004c5430(_gS109);
    this_00->s110 = pSVar5;
    if (pSVar5 != (S110 *)0x0) {
      this_00->field11_0x14 = (int)pSVar2;
      *(short *)this_00 = _DAT_0066b7a8;
      _DAT_0066b7a8 = _DAT_0066b7a8 + 1;
      this_00->select = _DAT_0066b790;
      this_00->field16_0x20 = _DAT_0066b798;
      pSVar5->field18_0x1e = 1;
      uVar1 = _DAT_0066b788;
      pSVar5->field21_0x24 = 1;
      pSVar5->field20_0x20 = uVar1;
      pSVar5->field22_0x28 = 3;
      pSVar5->field15_0x18 = _DAT_0066b78c;
      FUN_0040ce30(&local_4,(byte)pS113);
      *(undefined4 *)&pSVar5->field_0xc = local_4;
      FUN_0040ce30(&local_4,local_c[0]);
      *(undefined4 *)&pSVar5->field_0x10 = local_4;
      FUN_0040ce30(&local_4,local_8[0]);
      *(undefined4 *)&pSVar5->field_0x14 = local_4;
      S112::S112_FUN_004a9720(this_00);
      return 1;
    }
    S112::S112_FUN_004a96d0(this_00);
  }
  return 0;
}


