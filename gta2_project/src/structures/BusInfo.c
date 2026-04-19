// Module: S285
// Functions working with structure S285
// Generated from gta2.exe.c

#include "../../include/common.h"

void __thiscall S285__FUN_00432c60(S285 *this)

{
  SpriteS1 *pSVar1;
  undefined4 *puVar2;
  undefined1 local_4 [4];
  
  pSVar1 = S9::S9_FUN_00401b20((S9 *)&DAT_005e5514,(SpriteS1 *)&stack0xfffffff8,
                               &DAT_005e54a0);
  puVar2 = (undefined4 *)
           WorldCoordinateToScreenCoord(&this->field_0x4,local_4,(int *)pSVar1);
  *(undefined4 *)&this->field_0x4 = *puVar2;
  return;
}


