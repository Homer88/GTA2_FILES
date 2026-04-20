// Module: S170
// Functions working with structure S170
// Generated from gta2.exe.c

#include "common.h"

undefined1 __thiscall S170__S170_FUN_004b5ed0(S170 *this)

{
  LSTATUS LVar1;
  undefined1 uStack_d;
  BYTE aBStack_c [4];
  HKEY local_8;
  DWORD local_4;
  
  LVar1 = RegCreateKeyExA((HKEY)0x80000001,"Software\\Aureal\\A3D",0,(LPSTR)0x0,
                          0,0x20006,(LPSECURITY_ATTRIBUTES)0x0,&local_8,&local_4
                         );
  if (LVar1 == 0) {
    aBStack_c[0] = '\0';
    aBStack_c[1] = '\0';
    aBStack_c[2] = '\0';
    aBStack_c[3] = '\0';
    LVar1 = RegSetValueExA(local_8,"SplashScreen",0,4,aBStack_c,4);
    if (LVar1 != 0) {
      uStack_d = 0;
    }
    aBStack_c[0] = '\0';
    aBStack_c[1] = '\0';
    aBStack_c[2] = '\0';
    aBStack_c[3] = '\0';
    LVar1 = RegSetValueExA(local_8,"SplashAudio",0,4,aBStack_c,4);
    if (LVar1 != 0) {
      uStack_d = 0;
    }
    RegCloseKey(local_8);
    return uStack_d;
  }
  return 0;
}


void * __thiscall S170__S170_FUN_004b6ce0(S170 *this)

{
  int *piVar1;
  int iVar2;
  
  this->field6485_0x1ea8 = 0;
  this->field6486_0x1eac = 0;
  piVar1 = this->arr16;
  for (iVar2 = 16; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar1 = 0;
    piVar1 = piVar1 + 1;
  }
  this->field78_0x9c = 0;
  this->field79_0xa0 = 0;
  piVar1 = this->arr_16;
  for (iVar2 = 16; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar1 = 0;
    piVar1 = piVar1 + 1;
  }
  this->field_0xa4 = 0;
  piVar1 = this->arr320;
  iVar2 = 320;
  do {
    piVar1[-1] = 0;
    *piVar1 = 0;
    piVar1[1] = 11025;
    piVar1[2] = 0;
    piVar1[3] = 0;
    piVar1[4] = -1;
    piVar1 = piVar1 + 6;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  this->field0_0x0 = 0;
  this->field_0x1eb0 = 0x10;
  this->field_0x1eb1 = 2;
  this->field_0x1eb2 = 0;
  this->field8539_0x26b4 = 0xffffffff;
  this->field8540_0x26b8 = 0;
  this->field8542_0x26c0 = 0;
  this->field8544_0x2704 = 0xbf800000;
  this->field8545_0x2708 = 0xbf800000;
  this->field8546_0x270c = 0xbf800000;
  this->field8541_0x26bc = 0;
  this->field8547_0x2710 = 0;
  this->field_0x2714 = 0;
  S170_FUN_004b5ed0(this);
  this->field_0x4 = 0;
  this->field_0x55 = 0;
  builtin_strncpy(this->str,"data\\gtaudio",12);
  this->field_0x55 = '\x01';
  this->field_0x4 = 99;
  this->end = 0x5c;
  return this;
}


