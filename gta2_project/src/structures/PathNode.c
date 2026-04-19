// Module: S57
// Functions working with structure S57
// Generated from gta2.exe.c

#include "../../include/common.h"

undefined4 __thiscall S57__S57_FUN_00488170(S57 *this,int param_1)

{
  return *(undefined4 *)(this->buffer_0x4B0 + param_1 * 4);
}


void __thiscall S57__S57_FUN_00488450(S57 *this)

{
  byte *pbVar1;
  void *this_00;
  int iVar2;
  short sVar3;
  
  sVar3 = 0;
  pbVar1 = (byte *)Style::S15_FUN_004bf750(gStyle,0);
  iVar2 = 1;
  while (pbVar1 != (byte *)0x0) {
    this_00 = (void *)CONCAT31((int3)((uint)pbVar1 >> 8),pbVar1[1]);
    S57_FUN_00488420(this,(uint)*pbVar1,5,sVar3,pbVar1[1]);
    sVar3 = sVar3 + (ushort)pbVar1[1];
    FUN_00487fa0(this_00);
    pbVar1 = (byte *)Style::S15_FUN_004bf750(gStyle,iVar2);
    iVar2 = iVar2 + 1;
  }
  return;
}


void __thiscall S57__S57_FUN_004884b0(S57 *this)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *extraout_EDX;
  int iVar4;
  
  if (0 < DAT_00593218) {
    puVar3 = (undefined4 *)&DAT_006692c8;
    iVar4 = DAT_00593218;
    do {
      iVar2 = S57_FUN_00488170(this,puVar3[-2]);
      puVar3 = extraout_EDX + 0x15;
      *(undefined4 *)(iVar2 + 0x34) = extraout_EDX[-1];
      *(undefined4 *)(iVar2 + 0x38) = *extraout_EDX;
      *(undefined4 *)(iVar2 + 0x3c) = *extraout_EDX;
      *(undefined1 *)(iVar2 + 0x61) = *(undefined1 *)(extraout_EDX + 1);
      *(undefined4 *)(iVar2 + 0x40) = extraout_EDX[4];
      *(undefined4 *)(iVar2 + 0x44) = extraout_EDX[2];
      *(undefined4 *)(iVar2 + 0x48) = extraout_EDX[3];
      *(undefined4 *)(iVar2 + 0x10) = extraout_EDX[5];
      *(undefined1 *)(iVar2 + 0x65) = *(undefined1 *)(extraout_EDX + 7);
      *(undefined4 *)(iVar2 + 0x14) = extraout_EDX[6];
      *(undefined4 *)(iVar2 + 0x4c) = extraout_EDX[8];
      *(undefined1 *)(iVar2 + 100) = *(undefined1 *)(extraout_EDX + 10);
      *(undefined4 *)(iVar2 + 0x58) = extraout_EDX[0xb];
      *(undefined4 *)(iVar2 + 0x18) = extraout_EDX[0xc];
      *(undefined1 *)(iVar2 + 0x20) = *(undefined1 *)(extraout_EDX + 0xe);
      *(undefined4 *)(iVar2 + 0x2c) = extraout_EDX[0xd];
      *(undefined1 *)(iVar2 + 0x60) = 1;
      uVar1 = extraout_EDX[0x11];
      *(undefined4 *)(iVar2 + 0x68) = 0;
      *(undefined4 *)(iVar2 + 0x5c) = uVar1;
      *(undefined4 *)(iVar2 + 0x70) = extraout_EDX[0xf];
      *(undefined1 *)(iVar2 + 0x62) = *(undefined1 *)(extraout_EDX + 0x10);
      iVar4 = iVar4 + -1;
      *(undefined1 *)(iVar2 + 99) = *(undefined1 *)(extraout_EDX + 0x12);
      *(undefined4 *)(iVar2 + 0x54) = 0;
    } while (iVar4 != 0);
  }
  return;
}


void __thiscall S57__S57_FUN_00488570(S57 *this)

{
  int iVar1;
  undefined4 *puVar2;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int extraout_ECX_02;
  int extraout_ECX_03;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  undefined2 extraout_var_03;
  undefined2 extraout_var_04;
  undefined2 extraout_var_05;
  undefined2 extraout_var_06;
  undefined2 extraout_var_07;
  undefined2 extraout_var_08;
  undefined2 extraout_var_09;
  undefined2 extraout_var_10;
  undefined2 extraout_var_11;
  undefined2 extraout_var_12;
  undefined2 extraout_var_13;
  undefined2 extraout_var_14;
  undefined2 extraout_var_15;
  undefined2 extraout_var_16;
  undefined2 extraout_var_17;
  S57 *local_4;
  
  local_4 = this;
  FUN_00488180(0x97,6);
  iVar1 = S57_FUN_00488170(this,0x97);
  FUN_004880a0(1,CONCAT22((short)((uint)iVar1 >> 0x10),
                          (ushort)*(byte *)(iVar1 + 0x6c)) + -1);
  *(undefined4 *)(extraout_ECX + 0x34) = 2;
  *(undefined1 *)(extraout_ECX + 100) = 5;
  *(undefined4 *)(extraout_ECX + 0x38) = 0x98;
  *(undefined4 *)(extraout_ECX + 0x3c) = 0x98;
  *(undefined4 *)(extraout_ECX + 0x40) = 0;
  *(undefined4 *)(extraout_ECX + 0x44) = 0;
  *(undefined1 *)(extraout_ECX + 0x65) = 1;
  *(undefined1 *)(extraout_ECX + 0x61) = 1;
  iVar1 = FUN_00488180(0x98,6);
  FUN_004880a0(CONCAT22(extraout_var_08,(ushort)*(byte *)(iVar1 + 0x6c)) + -1,1)
  ;
  *(undefined4 *)(extraout_ECX_00 + 0x34) = 0;
  *(undefined4 *)(extraout_ECX_00 + 0x38) = 0;
  *(undefined4 *)(extraout_ECX_00 + 0x3c) = 0;
  *(undefined4 *)(extraout_ECX_00 + 0x40) = 0;
  *(undefined4 *)(extraout_ECX_00 + 0x44) = 0;
  *(undefined1 *)(extraout_ECX_00 + 0x61) = 0;
  iVar1 = FUN_00488180(0x34,4);
  FUN_004880a0(CONCAT22((short)((uint)iVar1 >> 0x10),
                        (ushort)*(byte *)(iVar1 + 0x6c)) + -1,1);
  *(undefined4 *)(extraout_ECX_01 + 0x34) = 0;
  *(undefined4 *)(extraout_ECX_01 + 0x38) = 0;
  *(undefined4 *)(extraout_ECX_01 + 0x3c) = 0;
  *(undefined4 *)(extraout_ECX_01 + 0x40) = 0;
  *(undefined4 *)(extraout_ECX_01 + 0x44) = 0;
  *(undefined1 *)(extraout_ECX_01 + 0x61) = 0;
  FUN_00488180(0x32,0xc);
  iVar1 = S57_FUN_00488170(this,0x32);
  FUN_004880a0(1,CONCAT22(extraout_var_09,(ushort)*(byte *)(iVar1 + 0x6c)) + -1)
  ;
  *(undefined4 *)(extraout_ECX_02 + 0x34) = 2;
  *(undefined1 *)(extraout_ECX_02 + 100) = 3;
  *(undefined4 *)(extraout_ECX_02 + 0x38) = 0x33;
  *(undefined4 *)(extraout_ECX_02 + 0x3c) = 0x33;
  *(undefined4 *)(extraout_ECX_02 + 0x40) = 0;
  *(undefined4 *)(extraout_ECX_02 + 0x44) = 0;
  *(undefined1 *)(extraout_ECX_02 + 0x65) = 1;
  *(undefined1 *)(extraout_ECX_02 + 0x61) = 1;
  iVar1 = FUN_00488180(0x33,0xc);
  FUN_004880a0(CONCAT22((short)((uint)iVar1 >> 0x10),
                        (ushort)*(byte *)(iVar1 + 0x6c)) + -1,1);
  *(undefined4 *)(extraout_ECX_03 + 0x34) = 0;
  *(undefined4 *)(extraout_ECX_03 + 0x38) = 0;
  *(undefined4 *)(extraout_ECX_03 + 0x3c) = 0;
  *(undefined4 *)(extraout_ECX_03 + 0x40) = 0;
  *(undefined4 *)(extraout_ECX_03 + 0x44) = 0;
  *(undefined1 *)(extraout_ECX_03 + 0x61) = 0;
  iVar1 = FUN_00488180(0x9b,3);
  FUN_004880a0(1,CONCAT22(extraout_var,(ushort)*(byte *)(iVar1 + 0x6c)) + -1);
  *(undefined4 *)(iVar1 + 0x34) = 4;
  *(undefined4 *)(iVar1 + 0x40) = 4;
  *(undefined1 *)(iVar1 + 100) = 1;
  *(undefined4 *)(iVar1 + 0x38) = 0x35;
  *(undefined4 *)(iVar1 + 0x3c) = 0x35;
  *(undefined4 *)(iVar1 + 0x44) = 0;
  *(undefined4 *)(iVar1 + 0x10) = _DAT_00665b50;
  puVar2 = (undefined4 *)Texture_Find(&DAT_00665b54,&local_4);
  *(undefined4 *)(iVar1 + 0x14) = *puVar2;
  *(undefined1 *)(iVar1 + 0x61) = 1;
  *(undefined4 *)(iVar1 + 0x4c) = 3;
  *(undefined4 *)(iVar1 + 0x50) = 3;
  *(undefined1 *)(iVar1 + 0x65) = 0xff;
  *(undefined4 *)(iVar1 + 0x58) = 1;
  iVar1 = FUN_00488180(0x35,3);
  FUN_004880a0(CONCAT22(extraout_var_10,(ushort)*(byte *)(iVar1 + 0x6c)) + -1,1)
  ;
  iVar1 = FUN_00488180(0x7b,0xb);
  FUN_004880a0(1,CONCAT22((short)((uint)iVar1 >> 0x10),
                          (ushort)*(byte *)(iVar1 + 0x6c)) + -1);
  *(undefined4 *)(iVar1 + 0x34) = 4;
  *(undefined1 *)(iVar1 + 100) = 1;
  *(undefined4 *)(iVar1 + 0x38) = 0x37;
  *(undefined4 *)(iVar1 + 0x3c) = 0x37;
  *(undefined4 *)(iVar1 + 0x40) = 4;
  *(undefined4 *)(iVar1 + 0x44) = 0;
  *(undefined4 *)(iVar1 + 0x10) = _DAT_00665b50;
  puVar2 = (undefined4 *)Texture_Find(&DAT_00665b54,&local_4);
  *(undefined4 *)(iVar1 + 0x14) = *puVar2;
  *(undefined1 *)(iVar1 + 0x61) = 1;
  *(undefined4 *)(iVar1 + 0x4c) = 3;
  *(undefined4 *)(iVar1 + 0x50) = 3;
  *(undefined1 *)(iVar1 + 0x65) = 0xff;
  *(undefined4 *)(iVar1 + 0x58) = 1;
  iVar1 = FUN_00488180(0x37,0xb);
  FUN_004880a0(CONCAT22(extraout_var_00,(ushort)*(byte *)(iVar1 + 0x6c)) + -1,1)
  ;
  iVar1 = FUN_00488180(0x9c,5);
  FUN_004880a0(1,CONCAT22(extraout_var_11,(ushort)*(byte *)(iVar1 + 0x6c)) + -1)
  ;
  *(undefined4 *)(iVar1 + 0x38) = 0x36;
  *(undefined4 *)(iVar1 + 0x3c) = 0x36;
  *(undefined4 *)(iVar1 + 0x34) = 4;
  *(undefined1 *)(iVar1 + 100) = 1;
  *(undefined4 *)(iVar1 + 0x40) = 4;
  *(undefined4 *)(iVar1 + 0x44) = 0;
  *(undefined4 *)(iVar1 + 0x10) = _DAT_00665b50;
  puVar2 = (undefined4 *)Texture_Find(&DAT_00665b54,&local_4);
  *(undefined4 *)(iVar1 + 0x14) = *puVar2;
  *(undefined1 *)(iVar1 + 0x61) = 1;
  *(undefined4 *)(iVar1 + 0x4c) = 3;
  *(undefined4 *)(iVar1 + 0x50) = 3;
  *(undefined1 *)(iVar1 + 0x65) = 0xff;
  *(undefined4 *)(iVar1 + 0x58) = 1;
  iVar1 = FUN_00488180(0x36,5);
  FUN_004880a0(CONCAT22(extraout_var_01,(ushort)*(byte *)(iVar1 + 0x6c)) + -1,1)
  ;
  iVar1 = FUN_00488180(0x38,0xd);
  FUN_004880a0(1,CONCAT22(extraout_var_12,(ushort)*(byte *)(iVar1 + 0x6c)) + -1)
  ;
  *(undefined1 *)(iVar1 + 100) = 1;
  *(undefined4 *)(iVar1 + 0x34) = 4;
  *(undefined4 *)(iVar1 + 0x38) = 0xd;
  *(undefined4 *)(iVar1 + 0x3c) = 0xd;
  *(undefined4 *)(iVar1 + 0x40) = 4;
  *(undefined4 *)(iVar1 + 0x44) = 0;
  *(undefined4 *)(iVar1 + 0x10) = _DAT_00665b50;
  puVar2 = (undefined4 *)Texture_Find(&DAT_00665b54,&local_4);
  *(undefined4 *)(iVar1 + 0x14) = *puVar2;
  *(undefined1 *)(iVar1 + 0x61) = 1;
  *(undefined4 *)(iVar1 + 0x4c) = 3;
  *(undefined4 *)(iVar1 + 0x50) = 3;
  *(undefined1 *)(iVar1 + 0x65) = 0xff;
  *(undefined4 *)(iVar1 + 0x58) = 1;
  iVar1 = FUN_00488180(0x39,0xe);
  FUN_004880a0(1,CONCAT22((short)((uint)iVar1 >> 0x10),
                          (ushort)*(byte *)(iVar1 + 0x6c)) + -1);
  *(undefined4 *)(iVar1 + 0x34) = 4;
  *(undefined1 *)(iVar1 + 100) = 1;
  *(undefined4 *)(iVar1 + 0x38) = 0x3a;
  *(undefined4 *)(iVar1 + 0x3c) = 0x3a;
  *(undefined4 *)(iVar1 + 0x40) = 4;
  *(undefined4 *)(iVar1 + 0x44) = 0;
  *(undefined4 *)(iVar1 + 0x10) = _DAT_00665b50;
  puVar2 = (undefined4 *)Texture_Find(&DAT_00665b54,&local_4);
  *(undefined4 *)(iVar1 + 0x14) = *puVar2;
  *(undefined1 *)(iVar1 + 0x61) = 1;
  *(undefined4 *)(iVar1 + 0x4c) = 3;
  *(undefined4 *)(iVar1 + 0x50) = 3;
  *(undefined1 *)(iVar1 + 0x65) = 0xff;
  *(undefined4 *)(iVar1 + 0x58) = 1;
  iVar1 = FUN_00488180(0x3a,0xe);
  FUN_004880a0(CONCAT22(extraout_var_02,(ushort)*(byte *)(iVar1 + 0x6c)) + -1,1)
  ;
  iVar1 = FUN_00488180(0x3b,0xf);
  FUN_004880a0(1,CONCAT22(extraout_var_13,(ushort)*(byte *)(iVar1 + 0x6c)) + -1)
  ;
  *(undefined4 *)(iVar1 + 0x34) = 4;
  *(undefined1 *)(iVar1 + 100) = 1;
  *(undefined4 *)(iVar1 + 0x38) = 0x3c;
  *(undefined4 *)(iVar1 + 0x3c) = 0x3c;
  *(undefined4 *)(iVar1 + 0x40) = 4;
  *(undefined4 *)(iVar1 + 0x44) = 0;
  *(undefined4 *)(iVar1 + 0x10) = _DAT_00665b50;
  puVar2 = (undefined4 *)Texture_Find(&DAT_00665b54,&local_4);
  *(undefined4 *)(iVar1 + 0x14) = *puVar2;
  *(undefined1 *)(iVar1 + 0x61) = 1;
  *(undefined4 *)(iVar1 + 0x4c) = 3;
  *(undefined4 *)(iVar1 + 0x50) = 3;
  *(undefined1 *)(iVar1 + 0x65) = 0xff;
  *(undefined4 *)(iVar1 + 0x58) = 1;
  iVar1 = FUN_00488180(0x3c,0xf);
  FUN_004880a0(CONCAT22(extraout_var_03,(ushort)*(byte *)(iVar1 + 0x6c)) + -1,1)
  ;
  iVar1 = FUN_00488180(0x3d,0x10);
  FUN_004880a0(1,CONCAT22(extraout_var_14,(ushort)*(byte *)(iVar1 + 0x6c)) + -1)
  ;
  *(undefined4 *)(iVar1 + 0x38) = 0x3e;
  *(undefined4 *)(iVar1 + 0x3c) = 0x3e;
  *(undefined4 *)(iVar1 + 0x34) = 4;
  *(undefined1 *)(iVar1 + 100) = 1;
  *(undefined4 *)(iVar1 + 0x40) = 4;
  *(undefined4 *)(iVar1 + 0x44) = 0;
  *(undefined4 *)(iVar1 + 0x10) = _DAT_00665b50;
  puVar2 = (undefined4 *)Texture_Find(&DAT_00665b54,&local_4);
  *(undefined4 *)(iVar1 + 0x14) = *puVar2;
  *(undefined1 *)(iVar1 + 0x61) = 1;
  *(undefined4 *)(iVar1 + 0x4c) = 3;
  *(undefined4 *)(iVar1 + 0x50) = 3;
  *(undefined1 *)(iVar1 + 0x65) = 0xff;
  *(undefined4 *)(iVar1 + 0x58) = 1;
  iVar1 = FUN_00488180(0x3e,0x10);
  FUN_004880a0(CONCAT22(extraout_var_04,(ushort)*(byte *)(iVar1 + 0x6c)) + -1,1)
  ;
  iVar1 = FUN_00488180(0x31,0x12);
  FUN_004880a0(1,CONCAT22(extraout_var_15,(ushort)*(byte *)(iVar1 + 0x6c)) + -1)
  ;
  *(undefined1 *)(iVar1 + 100) = 1;
  *(undefined4 *)(iVar1 + 0x34) = 4;
  *(undefined4 *)(iVar1 + 0x38) = 0x12;
  *(undefined4 *)(iVar1 + 0x3c) = 0x12;
  *(undefined4 *)(iVar1 + 0x40) = 4;
  *(undefined4 *)(iVar1 + 0x44) = 0;
  *(undefined4 *)(iVar1 + 0x10) = _DAT_00665b50;
  puVar2 = (undefined4 *)Texture_Find(&DAT_00665b54,&local_4);
  *(undefined4 *)(iVar1 + 0x14) = *puVar2;
  *(undefined1 *)(iVar1 + 0x61) = 1;
  *(undefined4 *)(iVar1 + 0x4c) = 3;
  *(undefined4 *)(iVar1 + 0x50) = 3;
  *(undefined1 *)(iVar1 + 0x65) = 0xff;
  *(undefined4 *)(iVar1 + 0x58) = 1;
  iVar1 = FUN_00488180(0x2d,0x16);
  FUN_004880a0(1,CONCAT22((short)((uint)iVar1 >> 0x10),
                          (ushort)*(byte *)(iVar1 + 0x6c)) + -1);
  *(undefined4 *)(iVar1 + 0x34) = 4;
  *(undefined1 *)(iVar1 + 100) = 1;
  *(undefined4 *)(iVar1 + 0x38) = 0x2e;
  *(undefined4 *)(iVar1 + 0x3c) = 0x2e;
  *(undefined4 *)(iVar1 + 0x40) = 4;
  *(undefined4 *)(iVar1 + 0x44) = 0;
  *(undefined4 *)(iVar1 + 0x10) = _DAT_00665b50;
  puVar2 = (undefined4 *)Texture_Find(&DAT_00665b54,&local_4);
  *(undefined4 *)(iVar1 + 0x14) = *puVar2;
  *(undefined1 *)(iVar1 + 0x61) = 1;
  *(undefined4 *)(iVar1 + 0x4c) = 3;
  *(undefined4 *)(iVar1 + 0x50) = 3;
  *(undefined1 *)(iVar1 + 0x65) = 0xff;
  *(undefined4 *)(iVar1 + 0x58) = 1;
  iVar1 = FUN_00488180(0x2e,0x16);
  FUN_004880a0(CONCAT22(extraout_var_05,(ushort)*(byte *)(iVar1 + 0x6c)) + -1,1)
  ;
  iVar1 = FUN_00488180(0x2f,0x15);
  FUN_004880a0(1,CONCAT22(extraout_var_16,(ushort)*(byte *)(iVar1 + 0x6c)) + -1)
  ;
  *(undefined4 *)(iVar1 + 0x34) = 4;
  *(undefined1 *)(iVar1 + 100) = 1;
  *(undefined4 *)(iVar1 + 0x38) = 0x30;
  *(undefined4 *)(iVar1 + 0x3c) = 0x30;
  *(undefined4 *)(iVar1 + 0x40) = 4;
  *(undefined4 *)(iVar1 + 0x44) = 0;
  *(undefined4 *)(iVar1 + 0x10) = _DAT_00665b50;
  puVar2 = (undefined4 *)Texture_Find(&DAT_00665b54,&local_4);
  *(undefined4 *)(iVar1 + 0x14) = *puVar2;
  *(undefined1 *)(iVar1 + 0x61) = 1;
  *(undefined4 *)(iVar1 + 0x4c) = 3;
  *(undefined4 *)(iVar1 + 0x50) = 3;
  *(undefined1 *)(iVar1 + 0x65) = 0xff;
  *(undefined4 *)(iVar1 + 0x58) = 1;
  iVar1 = FUN_00488180(0x30,0x15);
  FUN_004880a0(CONCAT22(extraout_var_06,(ushort)*(byte *)(iVar1 + 0x6c)) + -1,1)
  ;
  iVar1 = FUN_00488180(0x3f,0x11);
  *(undefined4 *)(iVar1 + 0x38) = 0x11;
  *(undefined4 *)(iVar1 + 0x3c) = 0x11;
  *(undefined4 *)(iVar1 + 0x34) = 3;
  *(undefined4 *)(iVar1 + 0x40) = 4;
  *(undefined4 *)(iVar1 + 0x44) = 0;
  *(undefined4 *)(iVar1 + 0x10) = _DAT_00665b50;
  puVar2 = (undefined4 *)Texture_Find(&DAT_00665b54,&local_4);
  *(undefined4 *)(iVar1 + 0x14) = *puVar2;
  *(undefined1 *)(iVar1 + 0x61) = 1;
  *(undefined4 *)(iVar1 + 0x4c) = 3;
  *(undefined4 *)(iVar1 + 0x50) = 3;
  *(undefined4 *)(iVar1 + 0x58) = 1;
  iVar1 = FUN_00488180(0x2b,0x17);
  FUN_004880a0(1,CONCAT22(extraout_var_17,(ushort)*(byte *)(iVar1 + 0x6c)) + -1)
  ;
  *(undefined4 *)(iVar1 + 0x38) = 0x2c;
  *(undefined4 *)(iVar1 + 0x3c) = 0x2c;
  *(undefined4 *)(iVar1 + 0x34) = 4;
  *(undefined1 *)(iVar1 + 100) = 1;
  *(undefined4 *)(iVar1 + 0x40) = 4;
  *(undefined4 *)(iVar1 + 0x44) = 0;
  *(undefined4 *)(iVar1 + 0x10) = _DAT_00665b50;
  puVar2 = (undefined4 *)Texture_Find(&DAT_00665b54,&local_4);
  *(undefined4 *)(iVar1 + 0x14) = *puVar2;
  *(undefined1 *)(iVar1 + 0x61) = 1;
  *(undefined4 *)(iVar1 + 0x4c) = 3;
  *(undefined4 *)(iVar1 + 0x50) = 3;
  *(undefined1 *)(iVar1 + 0x65) = 0xff;
  *(undefined4 *)(iVar1 + 0x58) = 1;
  iVar1 = FUN_00488180(0x2c,0x17);
  FUN_004880a0(CONCAT22(extraout_var_07,(ushort)*(byte *)(iVar1 + 0x6c)) + -1,1)
  ;
  iVar1 = FUN_00488180(0x9d,7);
  *(undefined4 *)(iVar1 + 0x34) = 3;
  *(undefined4 *)(iVar1 + 0x4c) = 2;
  puVar2 = (undefined4 *)Texture_Find(&DAT_00665b54,&local_4);
  *(undefined4 *)(iVar1 + 0x14) = *puVar2;
  *(undefined4 *)(iVar1 + 0x40) = 4;
  *(undefined4 *)(iVar1 + 0x38) = 7;
  *(undefined4 *)(iVar1 + 0x3c) = 7;
  *(undefined4 *)(iVar1 + 0x44) = 0;
  *(undefined1 *)(iVar1 + 0x61) = 1;
  *(undefined4 *)(iVar1 + 0x58) = 1;
  iVar1 = FUN_00488180(0x9e,1);
  *(undefined4 *)(iVar1 + 0x34) = 3;
  *(undefined4 *)(iVar1 + 0x4c) = 2;
  puVar2 = (undefined4 *)Texture_Find(&DAT_00665b54,&local_4);
  *(undefined4 *)(iVar1 + 0x14) = *puVar2;
  *(undefined4 *)(iVar1 + 0x38) = 1;
  *(undefined4 *)(iVar1 + 0x3c) = 1;
  *(undefined4 *)(iVar1 + 0x44) = 0;
  *(undefined1 *)(iVar1 + 0x61) = 1;
  *(undefined4 *)(iVar1 + 0x58) = 1;
  iVar1 = S57_FUN_00488170(this,0x19);
  *(undefined4 *)(iVar1 + 0x28) = 1;
  *(undefined4 *)(iVar1 + 8) = _DAT_00665c48;
  return;
}


void __thiscall S57__S57_FUN_00488d10(S57 *this)

{
  bool bVar1;
  void *this_00;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  short sVar2;
  byte *pbVar3;
  int local_8;
  
  sVar2 = 0;
  if (0 < DAT_0059321c) {
    local_8 = DAT_0059321c;
    pbVar3 = &DAT_00665c54;
    do {
      this_00 = (void *)CONCAT31((int3)((uint)local_8 >> 8),*pbVar3);
      S57_FUN_00488420(this,*(undefined4 *)(pbVar3 + -4),4,sVar2,*pbVar3);
      sVar2 = sVar2 + (ushort)*pbVar3;
      *(undefined4 *)((int)this_00 + 0x28) = *(undefined4 *)(pbVar3 + 0x34);
      bVar1 = Player::IsCurrentPlayer
                        ((Player *)(pbVar3 + 0x44),(Player *)&DAT_00665bf8);
      if (((CONCAT31(extraout_var,bVar1) == 0) ||
          (bVar1 = Player::IsCurrentPlayer
                             ((Player *)(pbVar3 + 0x48),(Player *)&DAT_00665bf8)
          , CONCAT31(extraout_var_00,bVar1) == 0)) ||
         (bVar1 = Player::IsCurrentPlayer
                            ((Player *)(pbVar3 + 0x4c),(Player *)&DAT_00665bf8),
         CONCAT31(extraout_var_01,bVar1) == 0)) {
        FUN_00487f60(((Player *)(pbVar3 + 0x44))->CurrentPlayer,
                     *(undefined4 *)(pbVar3 + 0x48),
                     *(undefined4 *)(pbVar3 + 0x4c));
      }
      else {
        FUN_00487fa0(this_00);
      }
      *(undefined4 *)((int)this_00 + 0x34) = *(undefined4 *)(pbVar3 + 4);
      *(undefined4 *)((int)this_00 + 0x38) = *(undefined4 *)(pbVar3 + 8);
      *(undefined4 *)((int)this_00 + 0x3c) = *(undefined4 *)(pbVar3 + 0xc);
      *(byte *)((int)this_00 + 0x61) = pbVar3[0x10];
      *(undefined4 *)((int)this_00 + 0x40) = *(undefined4 *)(pbVar3 + 0x1c);
      *(undefined4 *)((int)this_00 + 0x44) = *(undefined4 *)(pbVar3 + 0x14);
      *(undefined4 *)((int)this_00 + 0x48) = *(undefined4 *)(pbVar3 + 0x18);
      *(undefined4 *)((int)this_00 + 0x10) = *(undefined4 *)(pbVar3 + 0x20);
      *(byte *)((int)this_00 + 0x65) = pbVar3[0x28];
      *(undefined4 *)((int)this_00 + 0x14) = *(undefined4 *)(pbVar3 + 0x24);
      *(undefined4 *)((int)this_00 + 0x4c) = *(undefined4 *)(pbVar3 + 0x2c);
      *(undefined4 *)((int)this_00 + 0x50) = *(undefined4 *)(pbVar3 + 0x30);
      *(byte *)((int)this_00 + 100) = pbVar3[0x38];
      *(undefined4 *)((int)this_00 + 0x54) = 0;
      *(undefined4 *)((int)this_00 + 0x58) = *(undefined4 *)(pbVar3 + 0x3c);
      *(undefined4 *)((int)this_00 + 0x18) = *(undefined4 *)(pbVar3 + 0x40);
      *(undefined4 *)((int)this_00 + 0x2c) = *(undefined4 *)(pbVar3 + 0x50);
      *(byte *)((int)this_00 + 0x20) = pbVar3[0x54];
      *(byte *)((int)this_00 + 0x60) = pbVar3[0x55];
      *(undefined4 *)((int)this_00 + 0x5c) = *(undefined4 *)(pbVar3 + 0x58);
      *(undefined4 *)((int)this_00 + 0x68) = *(undefined4 *)(pbVar3 + 0x5c);
      *(undefined4 *)((int)this_00 + 0x70) = *(undefined4 *)(pbVar3 + 0x60);
      *(byte *)((int)this_00 + 0x62) = pbVar3[100];
      local_8 = local_8 + -1;
      *(byte *)((int)this_00 + 99) = pbVar3[0x65];
      pbVar3 = pbVar3 + 0x6c;
    } while (local_8 != 0);
  }
  return;
}


void __thiscall S57__S57_FUN_00488e50(S57 *this)

{
  int iVar1;
  int extraout_ECX;
  
  iVar1 = S57_FUN_00488170(this,0x70);
  *(undefined2 *)(extraout_ECX + 0x8ca4) = *(undefined2 *)(iVar1 + 0x1e);
  return;
}


void __thiscall S57__FUN_00488e70(S57 *param_1,int param_2)

{
  short sVar1;
  int iVar2;
  
  iVar2 = S57::S57_FUN_00488170(param_1,param_2);
  sVar1 = Style::GetBaseIndex(gStyle,4,*(short *)(iVar2 + 0x1e));
  Style::GetSprite(gStyle,sVar1);
  FUN_004c0340();
  return;
}


S57 * __thiscall S57__S57(S57 *this)

{
  int iVar1;
  byte *pbVar2;
  
  _eh_vector_constructor_iterator_(this->arr300,0x74,300,S58::S58,S58::~58);
  pbVar2 = this->buffer_0x4B0;
  for (iVar1 = 300; iVar1 != 0; iVar1 = iVar1 + -1) {
    pbVar2[0] = 0;
    pbVar2[1] = 0;
    pbVar2[2] = 0;
    pbVar2[3] = 0;
    pbVar2 = pbVar2 + 4;
  }
  this->field0_0x0 = 0;
  this->a = 99;
  return this;
}


void __thiscall S57__S57_FUN_00488f70(S57 *this)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int extraout_ECX_02;
  int extraout_ECX_03;
  int extraout_ECX_04;
  int extraout_ECX_05;
  int extraout_ECX_06;
  int extraout_ECX_07;
  int extraout_ECX_08;
  int extraout_ECX_09;
  int extraout_ECX_10;
  int extraout_ECX_11;
  int extraout_ECX_12;
  int extraout_ECX_13;
  int extraout_ECX_14;
  bool bVar5;
  undefined4 *local_10;
  int local_c;
  undefined1 local_8 [4];
  undefined1 local_4 [4];
  
  FUN_00488180(0x93,0x90);
  FUN_00488060(4);
  FUN_00488180(0xfa,0xfd);
  FUN_00488060(4);
  FUN_00488180(0x78,0x79);
  FUN_00488060(4);
  FUN_00488180(0x75,0x76);
  FUN_00488060(4);
  FUN_00488180(0x92,0x90);
  FUN_00488060(3);
  FUN_00488180(0xf9,0xfd);
  FUN_00488060(3);
  FUN_00488180(0x77,0x79);
  FUN_00488060(3);
  FUN_00488180(0x74,0x76);
  FUN_00488060(3);
  FUN_00488180(0x91,0x90);
  FUN_00488060(5);
  *(undefined1 *)(extraout_ECX + 100) = 3;
  FUN_00488180(0x7c,0xfd);
  FUN_00488060(5);
  *(undefined1 *)(extraout_ECX_00 + 100) = 3;
  FUN_00488180(0x7d,0x79);
  FUN_00488060(5);
  *(undefined1 *)(extraout_ECX_01 + 100) = 3;
  FUN_00488180(0x7e,0x76);
  FUN_00488060(5);
  *(undefined1 *)(extraout_ECX_02 + 100) = 3;
  iVar2 = FUN_00488180(0x9a,0xfe);
  if (gDoShowImaginary == '\0') {
    *(undefined4 *)(iVar2 + 0x40) = 2;
  }
  FUN_00488180(0x109,0xfe);
  iVar2 = FUN_00488180(0x9f,0x80);
  if (gDoShowImaginary == '\0') {
    *(undefined4 *)(iVar2 + 0x40) = 2;
  }
  FUN_00488180(0x115,0xfe);
  iVar2 = FUN_00488180(0x6e,0x9b);
  *(undefined4 *)(iVar2 + 0x38) = 0x6e;
  *(undefined4 *)(iVar2 + 0x3c) = 0x6e;
  *(undefined4 *)(iVar2 + 0x54) = 2;
  FUN_00487f60(_DAT_00669ac0,_DAT_00669ac0,_DAT_00669aac);
  *(undefined4 *)(iVar2 + 0x18) = _DAT_0066921c;
  *(uint *)(iVar2 + 0x40) = 2 - (uint)(gDoShowImaginary != '\0');
  *(undefined4 *)(iVar2 + 0x44) = 2;
  *(undefined4 *)(iVar2 + 0x58) = 1;
  *(undefined4 *)(iVar2 + 0x50) = 1;
  iVar2 = FUN_00488180(0x7f,0x9b);
  *(undefined4 *)(iVar2 + 0x38) = 0;
  *(undefined4 *)(iVar2 + 0x3c) = 0;
  *(undefined4 *)(iVar2 + 0x54) = 2;
  local_10 = (undefined4 *)0x8;
  local_c = 8;
  local_10 = (undefined4 *)FUN_00401bd0(&DAT_00665b88,local_8,(int *)&local_10);
  puVar3 = (undefined4 *)FUN_00401bd0(&DAT_00665b88,local_4,&local_c);
  FUN_00487f60(*puVar3,*local_10,_DAT_00669aac);
  *(undefined4 *)(iVar2 + 0x18) = _DAT_0066921c;
  bVar5 = gDoShowImaginary != '\0';
  *(undefined4 *)(iVar2 + 0x44) = 2;
  *(uint *)(iVar2 + 0x40) = 2 - (uint)bVar5;
  *(undefined4 *)(iVar2 + 0x58) = 1;
  *(undefined4 *)(iVar2 + 0x50) = 1;
  iVar2 = FUN_00488180(0xc1,0xc0);
  *(undefined4 *)(iVar2 + 0x38) = 0;
  *(undefined4 *)(iVar2 + 0x3c) = 0;
  if (gDoShowImaginary == '\0') {
    *(undefined4 *)(iVar2 + 0x40) = 2;
  }
  iVar2 = FUN_00488180(0xb9,0xa3);
  *(undefined4 *)(iVar2 + 0x38) = 0xb8;
  *(undefined4 *)(iVar2 + 0x3c) = 0xb8;
  *(undefined4 *)(iVar2 + 0x44) = 4;
  *(undefined4 *)(iVar2 + 0x40) = 3;
  *(undefined1 *)(iVar2 + 0x61) = 1;
  iVar2 = FUN_00488180(0xb8,0xa3);
  *(undefined4 *)(iVar2 + 0x38) = 0xb9;
  *(undefined4 *)(iVar2 + 0x3c) = 0xa4;
  *(undefined1 *)(iVar2 + 0x65) = 100;
  *(undefined1 *)(iVar2 + 0x61) = 1;
  *(undefined4 *)(iVar2 + 0x34) = 2;
  *(undefined1 *)(iVar2 + 0x6c) = 1;
  *(undefined1 *)(iVar2 + 100) = 1;
  *(undefined4 *)(iVar2 + 0x40) = 3;
  *(undefined4 *)(iVar2 + 0x44) = 5;
  FUN_00488180(0xb0,0xa3);
  FUN_00488060(1);
  *(undefined4 *)(extraout_ECX_03 + 0x38) = 0xb1;
  *(undefined4 *)(extraout_ECX_03 + 0x3c) = 0xb1;
  if (gGoKillPhonesOnAnswer != false) {
    iVar2 = S57_FUN_00488170(this,0xa4);
    *(undefined4 *)(iVar2 + 0x38) = 0xae;
    *(undefined4 *)(iVar2 + 0x3c) = 0xae;
  }
  FUN_00488180(0xb1,0xa4);
  FUN_00488060(1);
  if (gGoKillPhonesOnAnswer == false) {
    *(undefined4 *)(extraout_ECX_04 + 0x38) = 0xbb;
    *(undefined4 *)(extraout_ECX_04 + 0x3c) = 0xbb;
  }
  FUN_00488180(0xbb,0xb9);
  FUN_00488060(1);
  *(undefined4 *)(extraout_ECX_05 + 0x38) = 0xba;
  *(undefined4 *)(extraout_ECX_05 + 0x3c) = 0xba;
  FUN_00488180(0xba,0xb8);
  FUN_00488060(1);
  *(undefined4 *)(extraout_ECX_06 + 0x38) = 0xbb;
  *(undefined4 *)(extraout_ECX_06 + 0x3c) = 0xb1;
  FUN_00488180(0xb2,0xa3);
  FUN_00488060(2);
  *(undefined4 *)(extraout_ECX_07 + 0x38) = 0xb3;
  *(undefined4 *)(extraout_ECX_07 + 0x3c) = 0xb3;
  FUN_00488180(0xb3,0xa4);
  FUN_00488060(2);
  if (gGoKillPhonesOnAnswer == false) {
    *(undefined4 *)(extraout_ECX_08 + 0x38) = 0xbd;
    *(undefined4 *)(extraout_ECX_08 + 0x3c) = 0xbd;
  }
  FUN_00488180(0xbd,0xb9);
  FUN_00488060(2);
  *(undefined4 *)(extraout_ECX_09 + 0x38) = 0xbc;
  *(undefined4 *)(extraout_ECX_09 + 0x3c) = 0xbc;
  FUN_00488180(0xbc,0xb8);
  FUN_00488060(2);
  *(undefined4 *)(extraout_ECX_10 + 0x38) = 0xbd;
  *(undefined4 *)(extraout_ECX_10 + 0x3c) = 0xb3;
  FUN_00488180(0xb4,0xa3);
  FUN_00488060(0);
  *(undefined4 *)(extraout_ECX_11 + 0x38) = 0xb5;
  *(undefined4 *)(extraout_ECX_11 + 0x3c) = 0xb5;
  FUN_00488180(0xb5,0xa4);
  FUN_00488060(0);
  if (gGoKillPhonesOnAnswer == false) {
    *(undefined4 *)(extraout_ECX_12 + 0x38) = 0xbf;
    *(undefined4 *)(extraout_ECX_12 + 0x3c) = 0xbf;
  }
  FUN_00488180(0xbf,0xb9);
  FUN_00488060(0);
  *(undefined4 *)(extraout_ECX_13 + 0x38) = 0xbe;
  *(undefined4 *)(extraout_ECX_13 + 0x3c) = 0xbe;
  FUN_00488180(0xbe,0xb8);
  FUN_00488060(0);
  *(undefined4 *)(extraout_ECX_14 + 0x38) = 0xbf;
  *(undefined4 *)(extraout_ECX_14 + 0x3c) = 0xb5;
  iVar2 = FUN_00488180(0xae,0xa3);
  *(undefined4 *)(iVar2 + 0x44) = 0;
  iVar2 = FUN_00488180(0xb6,0xb7);
  *(undefined4 *)(iVar2 + 0x38) = 0xb7;
  *(undefined4 *)(iVar2 + 0x34) = 2;
  *(undefined4 *)(iVar2 + 0x44) = 2;
  uVar1 = _DAT_00665bf8;
  *(undefined4 *)(iVar2 + 0x14) = _DAT_00665bf8;
  *(undefined4 *)(iVar2 + 0x10) = _DAT_00665bf8;
  *(undefined4 *)(iVar2 + 0x4c) = 0;
  *(undefined4 *)(iVar2 + 0x50) = 0;
  *(undefined1 *)(iVar2 + 100) = 8;
  FUN_004880a0(CONCAT22((short)((uint)uVar1 >> 0x10),
                        (ushort)*(byte *)(iVar2 + 0x6c)) + -1,1);
  iVar2 = 200;
  local_10 = (undefined4 *)0x2d;
  do {
    iVar4 = FUN_00488180(iVar2 + -0x88,iVar2);
    *(int *)(iVar4 + 0x38) = iVar2;
    *(uint *)(iVar4 + 0x34) = (uint)(*(int *)(iVar4 + 0x34) != 6) * 2 + 7;
    puVar3 = (undefined4 *)Texture_Find(&DAT_00665b54,local_4);
    uVar1 = *puVar3;
    *(undefined4 *)(iVar4 + 0x4c) = 1;
    *(undefined4 *)(iVar4 + 0x14) = uVar1;
    *(undefined4 *)(iVar4 + 0x50) = 1;
    *(undefined1 *)(iVar4 + 0x61) = 1;
    *(undefined4 *)(iVar4 + 0x58) = 1;
    *(undefined4 *)(iVar4 + 0x40) = 3;
    iVar2 = iVar2 + 1;
    *(undefined4 *)(iVar4 + 0x18) = _DAT_00665b50;
    local_10 = (undefined4 *)((int)local_10 + -1);
    *(undefined4 *)(iVar4 + 0x10) = _DAT_00669258;
  } while (local_10 != (undefined4 *)0x0);
  FUN_00488f10();
  return;
}


void __thiscall S57__S57_FUN_00489530(S57 *this)

{
  S57_FUN_00488450(this);
  S57_FUN_004884b0(this);
  S57_FUN_00488570(this);
  S57_FUN_00488d10(this);
  S57_FUN_00488f70(this);
  S57_FUN_00488e50(this);
  return;
}


undefined2 __thiscall S57__FUN_004c6e30(S57 *this,int param_1)

{
  int iVar1;
  
  iVar1 = S57_FUN_00488170(this,param_1);
  return *(undefined2 *)(iVar1 + 0x1e);
}


