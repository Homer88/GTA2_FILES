// Module: S10
// Functions working with structure S10
// Generated from gta2.exe.c

#include "common.h"

S10 * __thiscall S10__S10(S10 *this)

{
  EngineStruct *_pS11;
  int index;
  
  Constructor(this->EngineStruct,120,306,EngineStruct::EngineStruct);
  _pS11 = (EngineStruct *)&this->EngineStruct[0].FirstElement;
  index = 0x131;
  do {
    _pS11->ElementNext = (EngineStruct *)&_pS11->NextElement;
    _pS11 = _pS11 + 1;
    index = index + -1;
  } while (index != 0);
  this->EngineStruct[0x131].FirstElement = (EngineStruct *)0x0;
  this->FirstElement = this->EngineStruct;
  return this;
}


EngineStruct * __thiscall S10__S10_FUN_00420ef0(S10 *this)

{
  EngineStruct *pS11;
  
  pS11 = this->FirstElement;
  this->FirstElement = pS11->FirstElement;
  EngineStruct::EngineStruct(pS11);
  return pS11;
}


void __thiscall S10__S10_FUN_00425460(S10 *this,EngineStruct *pS11)

{
  EngineStruct::S11_FUN_004210c0(pS11);
  pS11->FirstElement = this->FirstElement;
  this->FirstElement = pS11;
  return;
}


