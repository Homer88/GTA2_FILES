// Module: S121
// Functions working with structure S121
// Generated from gta2.exe.c

#include "../../include/common.h"

byte __thiscall S121__S121FUN_00446200(S121 *this)

{
  byte bVar1;
  uint local_4;
  
  bVar1 = 0;
  local_4 = 0;
  do {
    if ((char)this->ARR_Model_0x14[local_4].CarModel == '\0') {
      *(undefined1 *)&this->ARR_Model_0x14[local_4].CarModel = 1;
      return (byte)(this->ARR_Model_0x14 + local_4);
    }
    bVar1 = bVar1 + 1;
    local_4 = (uint)bVar1;
  } while (bVar1 < 0x14);
  return 0;
}


int __thiscall S121__FUN_00446240(S121 *this,Ped *param_2)

{
  Model *pMVar1;
  uint3 uVar2;
  byte bVar3;
  uint local_4;
  
  bVar3 = 0;
  local_4 = 0;
  while( true ) {
    pMVar1 = this->ARR_Model_0x14 + local_4;
    uVar2 = (uint3)((uint)pMVar1 >> 8);
    if (((char)pMVar1->CarModel == '\x01') && (pMVar1->Ped1 == param_2)) break;
    bVar3 = bVar3 + 1;
    local_4 = (uint)bVar3;
    if (0x13 < bVar3) {
      return (uint)uVar2 << 8;
    }
  }
  return CONCAT31(uVar2,1);
}


void __thiscall S121__S121_FUN_00446290(S121 *this,Model *pModel)

{
  byte bVar1;
  uint index;
  
  bVar1 = 0;
  index = 0;
  do {
    if ((Model *)(this->ARR_Model_0x14 + index) == pModel) {
      *(undefined1 *)&this->ARR_Model_0x14[index].CarModel = 0;
      Model::Model_FUN_004461a0(this->ARR_Model_0x14 + index);
      return;
    }
    bVar1 = bVar1 + 1;
    index = (uint)bVar1;
  } while (bVar1 < 0x14);
  return;
}


undefined4 __thiscall S121__FUN_004462f0(S121 *this,Ped *param_1,Ped *param_2)

{
  int iVar1;
  Gang *pGVar2;
  
  iVar1 = Ped::GetOccupation(param_1);
  if ((iVar1 < 0x18) || (0x1b < iVar1)) {
    pGVar2 = param_1->Gang;
    if (param_2->Gang != pGVar2) goto LAB_00446333;
  }
  else {
    pGVar2 = (Gang *)Ped::GetOccupation(param_2);
    if (((int)pGVar2 < 0x18) || (0x1b < (int)pGVar2)) {
LAB_00446333:
      return (uint)pGVar2 & 0xffffff00;
    }
  }
  return CONCAT31((int3)((uint)pGVar2 >> 8),1);
}


undefined4 __thiscall S121__S121_FUN_00446340(S121 *this,int param_1,Ped *pPed)

{
  byte bVar1;
  undefined4 uVar2;
  
  bVar1 = 0;
  do {
    if (((char)this->ARR_Model_0x14[bVar1].CarModel == '\x01') &&
       (this->ARR_Model_0x14[bVar1].Ped1 == pPed)) {
      uVar2 = FUN_004462f0(this,pPed,this->ARR_Model_0x14[bVar1].Ped);
      if (((char)uVar2 != '\0') &&
         (param_1 == this->ARR_Model_0x14[bVar1].field3_0xc)) {
        return this->ARR_Model_0x14[bVar1].Ped;
      }
    }
    bVar1 = bVar1 + 1;
    if (0x13 < bVar1) {
      return 0;
    }
  } while( true );
}


char __thiscall S121__FUN_004463c0(S121 *param_1,Ped *param_2,Ped *param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  Ped **ppPVar4;
  
  cVar1 = '\0';
  iVar3 = 0x14;
  ppPVar4 = &param_1->ARR_Model_0x14[0].Ped;
  do {
    if (((char)((Model *)(ppPVar4 + -1))->CarModel == '\x01') &&
       (ppPVar4[0xb] == param_2)) {
      uVar2 = S121::FUN_004462f0(param_1,param_3,*ppPVar4);
      if ((char)uVar2 != '\0') {
        cVar1 = cVar1 + '\x01';
      }
    }
    ppPVar4 = ppPVar4 + 0x10;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return cVar1;
}


undefined4 __thiscall S121__FUN_00446410(S121 *param_1,Ped *param_2)

{
  int iVar1;
  undefined4 uVar2;
  byte bVar3;
  uint local_4;
  
  bVar3 = 0;
  local_4 = 0;
  do {
    if ((char)param_1->ARR_Model_0x14[local_4].CarModel == '\x01') {
      uVar2 = S121::FUN_004462f0(param_1,param_2,
                                 param_1->ARR_Model_0x14[local_4].Ped);
      if (((char)uVar2 != '\0') &&
         ((iVar1 = param_1->ARR_Model_0x14[local_4].field3_0xc, iVar1 == 0xd ||
          (iVar1 == 0xf)))) {
        return 1;
      }
    }
    bVar3 = bVar3 + 1;
    local_4 = (uint)bVar3;
    if (0x13 < bVar3) {
      return 0;
    }
  } while( true );
}


undefined4 __thiscall S121__FUN_00446480(S121 *param_1,Ped *param_2)

{
  undefined4 uVar1;
  byte bVar2;
  uint local_4;
  
  bVar2 = 0;
  local_4 = 0;
  do {
    if ((char)param_1->ARR_Model_0x14[local_4].CarModel == '\x01') {
      uVar1 = S121::FUN_004462f0(param_1,param_2,
                                 param_1->ARR_Model_0x14[local_4].Ped);
      if (((char)uVar1 != '\0') &&
         (param_1->ARR_Model_0x14[local_4].field3_0xc == 8)) {
        return 1;
      }
    }
    bVar2 = bVar2 + 1;
    local_4 = (uint)bVar2;
    if (0x13 < bVar2) {
      return 0;
    }
  } while( true );
}


undefined4 __thiscall S121__FUN_004464e0(S121 *param_1,Ped *param_2)

{
  int iVar1;
  undefined4 uVar2;
  byte bVar3;
  uint local_4;
  
  bVar3 = 0;
  local_4 = 0;
  do {
    if ((char)param_1->ARR_Model_0x14[local_4].CarModel == '\x01') {
      uVar2 = S121::FUN_004462f0(param_1,param_2,
                                 param_1->ARR_Model_0x14[local_4].Ped);
      if (((char)uVar2 != '\0') &&
         (((iVar1 = param_1->ARR_Model_0x14[local_4].field3_0xc, iVar1 == 6 ||
           (iVar1 == 8)) || (iVar1 == 10)))) {
        return 1;
      }
    }
    bVar3 = bVar3 + 1;
    local_4 = (uint)bVar3;
    if (0x13 < bVar3) {
      return 0;
    }
  } while( true );
}


undefined4 __thiscall S121__FUN_00446550(S121 *this,Ped *param_2)

{
  undefined4 uVar1;
  byte bVar2;
  uint local_4;
  
  bVar2 = 0;
  local_4 = 0;
  do {
    if ((char)this->ARR_Model_0x14[local_4].CarModel == '\x01') {
      uVar1 = FUN_004462f0(this,param_2,this->ARR_Model_0x14[local_4].Ped);
      if (((char)uVar1 != '\0') &&
         (this->ARR_Model_0x14[local_4].field3_0xc == 9)) {
        return 1;
      }
    }
    bVar2 = bVar2 + 1;
    local_4 = (uint)bVar2;
    if (0x13 < bVar2) {
      return 0;
    }
  } while( true );
}


undefined4 __thiscall S121__FUN_004465b0(S121 *param_1,Ped *param_2)

{
  int iVar1;
  undefined4 uVar2;
  byte bVar3;
  uint local_4;
  
  bVar3 = 0;
  local_4 = 0;
  do {
    if ((char)param_1->ARR_Model_0x14[local_4].CarModel == '\x01') {
      uVar2 = S121::FUN_004462f0(param_1,param_2,
                                 param_1->ARR_Model_0x14[local_4].Ped);
      if (((char)uVar2 != '\0') &&
         (((iVar1 = param_1->ARR_Model_0x14[local_4].field3_0xc, iVar1 == 7 ||
           (iVar1 == 9)) || (iVar1 == 0xb)))) {
        return 1;
      }
    }
    bVar3 = bVar3 + 1;
    local_4 = (uint)bVar3;
    if (0x13 < bVar3) {
      return 0;
    }
  } while( true );
}


undefined4 __thiscall S121__FUN_00446620(S121 *param_1,Ped *param_2)

{
  int iVar1;
  undefined4 uVar2;
  byte bVar3;
  uint local_4;
  
  bVar3 = 0;
  local_4 = 0;
  do {
    if ((char)param_1->ARR_Model_0x14[local_4].CarModel == '\x01') {
      uVar2 = S121::FUN_004462f0(param_1,param_2,
                                 param_1->ARR_Model_0x14[local_4].Ped);
      if ((((char)uVar2 != '\0') &&
          (iVar1 = param_1->ARR_Model_0x14[local_4].field3_0xc, 5 < iVar1)) &&
         ((iVar1 < 10 || (iVar1 == 0xd)))) {
        return 1;
      }
    }
    bVar3 = bVar3 + 1;
    local_4 = (uint)bVar3;
    if (0x13 < bVar3) {
      return 0;
    }
  } while( true );
}


undefined4 __thiscall S121__FUN_00446690(S121 *this,Ped *param_2)

{
  int iVar1;
  undefined4 uVar2;
  byte bVar3;
  uint local_4;
  
  bVar3 = 0;
  local_4 = 0;
  do {
    if ((char)this->ARR_Model_0x14[local_4].CarModel == '\x01') {
      uVar2 = FUN_004462f0(this,param_2,this->ARR_Model_0x14[local_4].Ped);
      if ((((char)uVar2 != '\0') &&
          (iVar1 = this->ARR_Model_0x14[local_4].field3_0xc, 3 < iVar1)) &&
         (iVar1 < 6)) {
        return 1;
      }
    }
    bVar3 = bVar3 + 1;
    local_4 = (uint)bVar3;
    if (0x13 < bVar3) {
      return 0;
    }
  } while( true );
}


S121 * __thiscall S121__S121(S121 *this)

{
  _eh_vector_constructor_iterator_
            (this,64,20,Model::Model,(_func_void_void_ptr *)&Model::~S122);
  return this;
}


