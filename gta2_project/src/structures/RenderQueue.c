// Module: S100
// Functions working with structure S100
// Generated from gta2.exe.c

#include "common.h"

S100 * __thiscall S100__S100(S100 *this)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  _eh_vector_constructor_iterator_(this,0x30,0x14,S101::S101,S101::~S101);
  bVar1 = 0;
  pbVar3 = this->Flag;
  pbVar2 = &this->Arr_S101_0x14[0].Ids;
  do {
    *pbVar2 = bVar1;
    *pbVar3 = 0;
    bVar1 = bVar1 + 1;
    pbVar2 = pbVar2 + 0x30;
    pbVar3 = pbVar3 + 1;
  } while (bVar1 < 0x14);
  _DAT_00669e80 = 0;
  return this;
}


