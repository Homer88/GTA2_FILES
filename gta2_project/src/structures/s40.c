// Module: S40
// Functions working with structure S40
// Generated from gta2.exe.c

#include "../../include/common.h"

void __thiscall S40__S40_FUN_004ba020(S40 *this)

{
  this->NextElement = 0;
  return;
}


S40 * __thiscall S40__S40(S40 *this)

{
  _eh_vector_constructor_iterator_
            (this->s41,8,4,S41::S41,(_func_void_void_ptr *)&S41::~S41);
  SpriteS3::_FUN_004bc8f0((SpriteS3 *)this);
  return this;
}


void __thiscall S40__S39_FUN_004bca10(SpriteS2 *this,S40 *pS40)

{
  pS40->NextElement = this->FirstElement;
  this->FirstElement = (SpriteS3 *)pS40;
  return;
}


