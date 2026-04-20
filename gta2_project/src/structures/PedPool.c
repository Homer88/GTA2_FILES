// Module: S50
// Functions working with structure S50
// Generated from gta2.exe.c

#include "common.h"

S50 * __thiscall S50__S50(S50 *this)

{
  GameObject **ppGVar1;
  int iVar2;
  
  _eh_vector_constructor_iterator_
            (this->S51,0xb4,400,GameObject::S51,GameObject::~S51);
  ppGVar1 = &this->S51[0].pS51;
  iVar2 = 399;
  do {
    *ppGVar1 = (GameObject *)(ppGVar1 + 15);
    ppGVar1 = ppGVar1 + 0x2d;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  this->S51[399].pS51 = (GameObject *)0x0;
  this->FirstElement = this->S51;
  return this;
}


GameObject * __thiscall S50__S50_FUN_004355a0(S50 *this)

{
  GameObject *FirstElement;
  
  FirstElement = this->FirstElement;
  this->FirstElement = FirstElement->pS51;
  GameObject::S51_FUN_00497c20(FirstElement);
  return FirstElement;
}


void __thiscall S50__S50_FUN_004355c0(S50 *this,GameObject *param_1)

{
  FUN_00493640(param_1);
  param_1->pS51 = this->FirstElement;
  this->FirstElement = param_1;
  return;
}


