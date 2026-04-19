// Module: S73
// Functions working with structure S73
// Generated from gta2.exe.c

#include "../../include/common.h"

void __thiscall S73__S73_FUN_004a4f20(S73 *this,Weapon *sWeapon)

{
  Weapon *pWVar1;
  Weapon *this_00;
  Weapon *pWVar2;
  
  pWVar2 = (Weapon *)0x0;
  pWVar1 = this->cWeapon;
  if (this->cWeapon != (Weapon *)0x0) {
    while (this_00 = pWVar1, this_00 != sWeapon) {
      pWVar1 = this_00->NextWeapon;
      pWVar2 = this_00;
      if (this_00->NextWeapon == (Weapon *)0x0) {
        return;
      }
    }
    Weapon::Weapon_FUN_004ccb40(this_00);
    if (pWVar2 != (Weapon *)0x0) {
      pWVar2->NextWeapon = this_00->NextWeapon;
      this_00->NextWeapon = this->Weapon_1;
      this->Weapon_1 = this_00;
      return;
    }
    this->cWeapon = this_00->NextWeapon;
    this_00->NextWeapon = this->Weapon_1;
    this->Weapon_1 = this_00;
  }
  return;
}


Weapon * __thiscall S73__S73_GetWeapon_1(S73 *this)

{
  return this->cWeapon;
}


void * __thiscall S73__S73_FUN_004cc9c0(S73 *this)

{
  Weapon *this_00;
  
  this_00 = this->Weapon_1;
  this->Weapon_1 = this_00->NextWeapon;
  this_00->NextWeapon = this->cWeapon;
  this->cWeapon = this_00;
  Weapon::Weapon_FUN_004cc810(this_00);
  return this_00;
}


Weapon * __thiscall S73__S73_FUN_004cc9e0(S73 *this)

{
  Weapon *this_00;
  
  this_00 = this->Weapon_1;
  this->Weapon_1 = this_00->NextWeapon;
  this_00->NextWeapon = (Weapon *)0x0;
  Weapon::Weapon_FUN_004cc810(this_00);
  return this_00;
}


S73 * __thiscall S73__S73(S73 *this)

{
  Weapon *ppWVar1;
  int count;
  
  _eh_vector_constructor_iterator_
            (this->Weapon,0x30,255,Weapon::Weapon,Weapon::~S74);
  ppWVar1 = (Weapon *)&this->Weapon[0].NextWeapon;
  count = 254;
  do {
    *(Weapon ***)ppWVar1 = &ppWVar1->NextWeapon;
    ppWVar1 = ppWVar1 + 1;
    count = count + -1;
  } while (count != 0);
  this->Weapon_1 = this->Weapon;
  this->Weapon[254].NextWeapon = (Weapon *)0x0;
  this->cWeapon = (Weapon *)0x0;
  this->field3_0x2fd8 = 0;
  return this;
}


void __thiscall S73__S73_FUN_004cda70(S73 *this,Weapon *cWeapon)

{
  Weapon::Weapon_FUN_004ccb40(cWeapon);
  cWeapon->NextWeapon = this->Weapon_1;
  this->Weapon_1 = cWeapon;
  return;
}


