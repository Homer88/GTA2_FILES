// Module: S54
// Functions working with structure S54
// Generated from gta2.exe.c

#include "common.h"

S54 * __thiscall S54__S54(S54 *this)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 4095;
  piVar2 = this->ARR_4095;
  do {
    *piVar2 = (int)(piVar2 + 1);
    piVar2 = piVar2 + 2;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  this->SpriteS1 = (SpriteS1 *)&this->field1_0x4;
  this->field16383_0x8000 = 0;
  return this;
}


SpriteS1 * __thiscall S54__S54_FUN_00447350(S54 *this)

{
  SpriteS1 *pSVar1;
  
  pSVar1 = this->SpriteS1;
  this->SpriteS1 = pSVar1->S3_arr5031[0].SpriteS1;
  return pSVar1;
}


void __thiscall S54__S54_FUN_00447360(S54 *this,S46 *pS46)

{
  pS46->NextElement = (S46 *)this->SpriteS1;
  this->SpriteS1 = (SpriteS1 *)pS46;
  return;
}


