// Module: S3
// Functions working with structure S3
// Generated from gta2.exe.c

#include "../../include/common.h"

void __thiscall S3__FUN_00401ad0(SpriteS1 *this,S3 *pS3)

{
  this->FirstElement = (SpriteS1 *)pS3;
  return;
}


S3 * __thiscall S3__S3(S3 *this)

{
  *(undefined2 *)&this->SpriteS1 = PTR_005e4d14._0_2_;
  this->Car = (Car *)0x0;
  this->PositionY = gSpriteS1_0;
  this->PositionZ = gSpriteS1_0;
  this->field7_0x1c = gSpriteS1_0;
  this->Remap = 0;
  this->field9_0x22 = 0;
  this->field10_0x24 = 0;
  this->field13_0x28 = 0;
  this->field14_0x2c = 0;
  this->field18_0x30 = (S3 *)0x0;
  this->field19_0x34 = 0;
  this->field20_0x38 = 0;
  this->field21_0x39 = 0xff;
  this->SpriteS3 = (SpriteS3 *)0x0;
  this->NextElement = (S3 *)0x0;
  this->PositionX = 0;
  return this;
}


void __thiscall S3__S3_DESTRUC(S3 *this)

{
  if (this->PositionX != 0) {
    DMAudio::~DMAudio(&gDMAudio,this->PositionX);
    this->PositionX = 0;
  }
  return;
}


void __thiscall S3__S3_DESTRUC(S3 *this)

{
  if (this->PositionX != 0) {
    DMAudio::~DMAudio(&gDMAudio,this->PositionX);
    this->PositionX = 0;
  }
  return;
}


void __thiscall S3__S3_FUN_004bccc0(S3 *this)

{
  if ((S40 *)this->NextElement != (S40 *)0x0) {
    SpriteS2::S39_FUN_004bca10(_gSpriteS2,(S40 *)this->NextElement);
    this->NextElement = (S3 *)0x0;
  }
  if (this->Car != (Car *)0x0) {
    SpriteS2::S39_FUN_004bca10(_gSpriteS2,(S40 *)this->Car);
    this->Car = (Car *)0x0;
  }
  return;
}


void __thiscall S3__S3_FUN_004bdc40(S3 *this)

{
  S3_FUN_004bccc0(this);
  this->Remap = 0;
  S3_DESTRUC(this);
  return;
}


