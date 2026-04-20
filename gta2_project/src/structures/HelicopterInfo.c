// Module: S290
// Functions working with structure S290
// Generated from gta2.exe.c

#include "common.h"

S290 * __thiscall S290__S290(S290 *this)

{
  S291 *pSVar1;
  S291 *pSVar2;
  int iVar3;
  float10 fVar4;
  int local_10;
  
  Constructor(this,4,1440,Texture_Load);
  local_10 = 0;
  iVar3 = 0x5a0;
  pSVar2 = this->field0_0x0;
  do {
    fVar4 = (float10)fcos((float10)local_10 *
                          (float10)(double)0x400921fb54524550 *
                          (float10)0.001388888888888889);
    pSVar1 = (S291 *)FUN_0040e510((double)fVar4);
    *pSVar2 = *pSVar1;
    local_10 = local_10 + 1;
    pSVar2 = pSVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return this;
}


