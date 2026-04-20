// Module: ped
// Generated from gta2.exe.c
// Functions count: 243

#include "../../include/common.h"

undefined1 __thiscall PedManager__HasActivePeds(S169 *this)


// Было: FUN_00403800
bool __thiscall S169::FUN_00403800(S169 *this,int *param_1)


Ped * __thiscall PedManager::S48_FUN_00403890(PedManager *this)


// Было: FUN_004038f0
bool __thiscall S169::FUN_004038f0(S169 *this)


void __thiscall Ped__SetSearchMode(Ped *this,SearchType type)


void * __thiscall Ped__SetAIController(Ped *this,AutoClass4 *pAutoClass4)


void __thiscall Ped__SetAssignedCarIndex(Ped *this,byte pIndex)


// Было: S49_Set_FUN_00403950
void __thiscall Ped__ClearFlags(Ped *this)


// Было: S49_FUN_00403960
void __thiscall Ped__UpdateState(Ped *this)


void __thiscall Ped__SetCurrentOccupation(Ped *this,int occupation)


int __thiscall Ped__GetCurrentOccupation(Ped *this)


PedState __thiscall Ped__GetPedState(Ped *this)


void __thiscall Ped__SetHealth(Ped *this,short Health)


void __thiscall Ped__SetTargetCarDoorIndex(Ped *this,int param_1)


// Было: S49_Get_FUN_004039c0
int __thiscall Ped__GetFlags1(Ped *this)


// Было: S49_Get_FUN_004039d0
byte __thiscall Ped__GetFlags2(Ped *this)


// Было: S49_Get_FUN_004039e0
CarDamageState __thiscall Ped__GetDamageState(Ped *this)


// Было: S49_FUN_004039f0
ushort __thiscall Ped::S49_FUN_004039f0(Ped *this)


int __thiscall Ped__GetXCoordinate(Ped *this,int x)


int __thiscall Ped__GetYCoordinate(Ped *this,int Y)


void __thiscall Ped__ResetSpecialParam(Ped *this)


void __thiscall Ped__ResetToDefaults(Ped *this)


// Было: Ped_Set_FUN_00403a40
void __thiscall Ped__Initialize(Ped *this)


// Было: S49_FUN_00403a50
void __thiscall Ped__SetFlags(Ped *this,undefined4 param_1)


// Было: S49_Get_FUN_00403a60
byte __thiscall Ped__GetAnimationState(Ped *this)


// Было: S49_FUN_00403a70
void __thiscall Ped__SetAnimationState(Ped *this,byte param_1)


// Было: S49_Get_FUN_00403a80
undefined4 __thiscall Ped__GetActionParam(Ped *this)


int __thiscall Ped__GetCurrentAction(Ped *this)


// Было: S49_FUN_00403aa0
void __thiscall Ped__EnterCar(Ped *this,Car *param_1)


Car * __thiscall Ped__GetVehicle(Ped *this)


void __thiscall Ped__SetAsDriver(Ped *this,Ped *param_1)


Ped * __thiscall Ped__GetPassenger(Ped *this)


void __thiscall Ped__SetLinkedPedestrian(Ped *this,Ped *linkedPed)


Ped * __thiscall Ped__GetLinkedPed(Ped *this)


void __thiscall Ped__SetTargetVehicle(Ped *this,Car *pCar)


Car * __thiscall Ped__GetCurrentVehicle(Ped *this)


// Было: S49_Get_FUN_00403b20
short __thiscall Ped::S49_Get_FUN_00403b20(Ped *this)


// Было: S49_Get_FUN_00403b30
short __thiscall Ped::S49_Get_FUN_00403b30(Ped *this)


void __thiscall Ped__SetVehicleDamageState(Ped *this,CarDamageState param_1)


void __thiscall Ped__SetExitAnimationState(Ped *this,byte param_1)


bool __thiscall Ped::GetDeadPed(Ped *this)


// Было: S49_Get_FUN_00403b70
byte __thiscall Ped__GetExitAnimState(Ped *this)


byte __thiscall Ped__IsInsideVehicle(Ped *this)


PedFlags __thiscall Ped__GetStance(Ped *this)


// Было: FUN_00403be0
void __thiscall PedManager__UpdateAll(S169 *this)


// Было: S169_FUN_00403c40
byte __thiscall PedManager__CheckPedStatus(S169 *this)


// Было: FUN_00403da0
void __thiscall PedManager__ProcessPeds(S169 *this)


// Было: FUN_00403e90
void __thiscall PedManager__UpdatePedStates(S169 *this)


// Было: FUN_00403fb0
void __thiscall PedManager__HandlePedAction(S169 *this,int param_1)


// Было: FUN_00404120
void __thiscall PedManager__SetPedIndex(S169 *this,byte index)


// Было: FUN_00404450
undefined4 __thiscall PedManager__GetPedCount(S169 *this)


// Было: FUN_00404480
void __thiscall PedManager__ClearAll(S169 *this)


Ped * __thiscall PedManager__GetPedByIndex(S169 *this,int *param_1)


// Было: FUN_00404840
bool __thiscall S169::FUN_00404840(S169 *this)


void __thiscall PedGroup_AddMember(void *this,Ped *param_1)


// Было: FUN_00404d40
void __thiscall PedManager__RemovePed(S169 *this,void *pPed)


// Было: FUN_00404ef0
void __thiscall PedManager__ProcessGroup(S169 *this,undefined4 *param_1)


// Было: FUN_00405240
void __thiscall PedManager__UpdateGroup(S169 *this)


int __thiscall Ped::GetPositionZ(Ped *this,int Z)


Car * __thiscall Ped::GetCarPlayers(Ped *this)


byte __thiscall Ped::IsPlayerControlled(Ped *this)


// Было: FUN_0041b0b0
undefined4 __thiscall Ped::FUN_0041b0b0(Ped *this)


// Было: sPed_FUN_00420b50
byte __thiscall Ped::sPed_FUN_00420b50(Ped *this)


int __thiscall Ped::GetIdPlayer(Ped *this)


SearchType __thiscall Ped::GetSearchType(Ped *this)


void __thiscall Ped::SetPoliceNoStar(Ped *this)


int __thiscall S68::S68GetPedID(S68 *this,byte param_1)


byte __thiscall Ped__GetCurrentOccupationPolice(Ped *this)


// Было: sPed_FUN_004331d0
void __thiscall Ped::sPed_FUN_004331d0(Ped *this)


// Было: FUN_004331e0
byte __thiscall Ped::FUN_004331e0(Ped *this)


// Было: sPed_FUN_00433220
void __thiscall Ped::sPed_FUN_00433220(Ped *this)


// Было: S49_FUN_00433250
void __thiscall Ped::S49_FUN_00433250(Ped *this)


PedState __thiscall Ped::TransitionState(Ped *this,PedState newState)


void * __thiscall Ped::S49_FUN_004332b0(Ped *this,int param_1)


// Было: PedNormal_FUN_00433380
byte __thiscall Ped::PedNormal_FUN_00433380(Ped *this)


bool __thiscall Ped::HasSearchType(Ped *this,SearchType param_1)


void __thiscall Ped__SetCurrentOccupationAGENT(Ped *this,int newOccupation)


void * __thiscall Ped::S49_FUN_00433580(Ped *this,byte param_1)


// Было: S49_FUN_00433650
byte __thiscall Ped::S49_FUN_00433650(Ped *this,char param_1)


// Было: Get_FUN_00433b40
uint __thiscall Ped::Get_FUN_00433b40(Ped *this)


// Было: S49_FUN_00433b50
void __thiscall Ped::S49_FUN_00433b50(Ped *this)


short __thiscall Ped::GetHealthPlayer(Ped *this)


// Было: Set_FUN_00433b80
void __thiscall Ped::Set_FUN_00433b80(Ped *this,ushort param_1)


void __thiscall Ped::SetRemap(Ped *this,char remap)


byte __thiscall Ped::GetRemap(Ped *this)


// Было: PedNormal_FUN_00433bb0
void __thiscall Ped::PedNormal_FUN_00433bb0(Ped *this,undefined4 param_1)


// Было: PedNormal_FUN_00433bc0
void __thiscall Ped::PedNormal_FUN_00433bc0(Ped *this,undefined4 param_1)


// Было: sPed_FUN_00433bd0
void __thiscall Ped::sPed_FUN_00433bd0(Ped *this)


// Было: sPed_FUN_00433bf0
void __thiscall Ped::sPed_FUN_00433bf0(Ped *this,Ped *pPed)


void __thiscall Ped::SetRotation(Ped *this,short Rotation)


// Было: sPed_FUN_00433c10
void __thiscall Ped::sPed_FUN_00433c10(Ped *this,char Remap)


// Было: Set_UNS56_FUN_00433c80
void __thiscall Ped::Set_UNS56_FUN_00433c80(Ped *this,short param_1)


// Было: sPed_FUN_00433c90
bool __thiscall Ped::sPed_FUN_00433c90(Ped *this)


// Было: sPed_FUN_00433cb0
undefined4 __thiscall Ped::sPed_FUN_00433cb0(Ped *this,Sprite *param_1)


// Было: FUN_00433da0
char __thiscall Ped::FUN_00433da0(Ped *this)


short __thiscall Ped::GetPoliceStar(Ped *this)


// Было: S49_FUN_00433dd0
void __thiscall Ped::S49_FUN_00433dd0(Ped *this,undefined4 param_1)


// Было: sPed_FUN_00433df0
void __thiscall Ped::sPed_FUN_00433df0(Ped *this)


// Было: sPed_FUN_00433e50
void __thiscall Ped::sPed_FUN_00433e50(Ped *this)


// Было: FUN_00433eb0
void __thiscall Ped::FUN_00433eb0(Ped *this)


// Было: sPed_FUN_00434160
char __thiscall Ped::sPed_FUN_00434160(Ped *this)


// Было: FUN_00434180
void __thiscall Ped::FUN_00434180(Ped *this)


// Было: FUN_004341d0
void __thiscall Ped::FUN_004341d0(Ped *this)


// Было: FUN_00434300
void __thiscall Ped::FUN_00434300(Ped *this)


// Было: sPed_FUN_00434740
void __thiscall Ped::sPed_FUN_00434740(Ped *this)


// Было: sPed_FUN_004347d0
void __thiscall Ped::sPed_FUN_004347d0(Ped *this)


// Было: sPed_FUN_00434870
void __thiscall Ped::sPed_FUN_00434870(Ped *this)


// Было: sPed_FUN_00434980
void __thiscall Ped::sPed_FUN_00434980(Ped *this)


// Было: sPed_FUN_00434a30
void __thiscall Ped::sPed_FUN_00434a30(Ped *this)


// Было: sPed_FUN_00434b40
void __thiscall Ped::sPed_FUN_00434b40(Ped *this)


SpriteS1 * __thiscall Ped::GetSprite(Ped *this)


byte __thiscall Ped::sPed_GetCopStars(Ped *this)


// Было: sPed_FUN_00434c40
ushort __thiscall Ped::sPed_FUN_00434c40(Ped *this,ushort pCopLevel)


byte __thiscall Ped::sPed_HandleWantedEvent(Ped *this,byte pWantedLevel)


// Было: sPed_FUN_00434d70
int __thiscall Ped::sPed_FUN_00434d70(Ped *this)


Weapon * __thiscall Ped::sPed_FUN_00434e60(Ped *this)


// Было: FUN_00434ff0
void __thiscall Ped::FUN_00434ff0(Ped *this,Ped *param_1)


void __thiscall Ped::UpdateWantedLevel(Ped *this,ushort WantedLevel)


void __thiscall Ped::PedGroupChangeLeader(Ped *this,Ped *pPed)


// Было: sPed__FUN_004354c0
void __thiscall Ped::sPed__FUN_004354c0(Ped *this)


// Было: sPed_FUN_004354f0
byte __thiscall Ped::sPed_FUN_004354f0(Ped *this)


Ped * __thiscall PedManager::GetNextPed(PedManager *this)


void __thiscall Ped::BasicCleanup(Ped *this)


void __thiscall Ped::CleanupAndUpdateOccupationCounts(Ped *this)


Ped::SetPedTeleportTarget(Ped *this,float10 *ViewCameraX,float10 *ViewCameraY)


// Было: FUN_00435ce0
void __thiscall Ped::FUN_00435ce0(Ped *this)


// Было: PedNormal_FUN_00435e90
void __thiscall Ped::PedNormal_FUN_00435e90(Ped *this)


// Было: sPed_FUN_00435eb0
void __thiscall Ped::sPed_FUN_00435eb0(Ped *this)


// Было: S49_FUN_00435ee0
void __thiscall Ped::S49_FUN_00435ee0(Ped *this)


// Было: sPed_FUN_00435f00
void __thiscall Ped::sPed_FUN_00435f00(Ped *this)


// Было: S49_FUN_00435f20
void __thiscall Ped::S49_FUN_00435f20(Ped *this)


// Было: sPed_FUN_00435f40
void __thiscall Ped::sPed_FUN_00435f40(Ped *this)


void __thiscall Ped::CreatePlayer(Ped *this)


void __thiscall Ped::PutPedInCarRelated(Ped *this,Car *pCar)


byte __thiscall Ped::SetPedPosition(Ped *this,int x,int y,int z)


S6 * __thiscall Ped::FUN_00436160(Ped *this,S6 *param_2)


short * __thiscall Ped::GetRotation(Ped *this,short *param_1)


Car * __thiscall Ped::FUN_00436200(Ped *this,Car *param_1)


// Было: S49_FUN_00436250
void __thiscall Ped::S49_FUN_00436250(Ped *this)


// Было: sPed_FUN_00436460
void __thiscall Ped::sPed_FUN_00436460(Ped *this)


// Было: S49_FUN_00436830
void __thiscall Ped::S49_FUN_00436830(Ped *this)


// Было: S49_FUN_00436860
void __thiscall Ped::S49_FUN_00436860(Ped *this)


// Было: sPed_FUN_00436890
void __thiscall Ped::sPed_FUN_00436890(Ped *this)


void __thiscall Ped::SetAnimationState(Ped *this,int param_1,int param_2)


// Было: FUN_00437010
void __thiscall Ped::FUN_00437010(Ped *this)


// Было: sPed_FUN_004371d0
byte __thiscall Ped::sPed_FUN_004371d0(Ped *this,Game *pGame)


// Было: sPed_FUN_00437670
byte __thiscall Ped::sPed_FUN_00437670(Ped *this)


Ped * __thiscall Ped::sPed_FUN_00437be0(Ped *this,Car *param_1)


// Было: FUN_00437ec0
byte __thiscall Ped::FUN_00437ec0(Ped *this)


// Было: FUN_004390f0
void __thiscall Ped::FUN_004390f0(Ped *this)


// Было: FUN_00439190
void __thiscall Ped::FUN_00439190(Ped *this)


// Было: FUN_00439780
void __thiscall Ped::FUN_00439780(Ped *this)


void __thiscall Ped::UpdateCarDamageState(Ped *this)


// Было: sPed_FUN_004398b0
void __thiscall Ped::sPed_FUN_004398b0(Ped *this)


// Было: sPed_FUN_00439970
void __thiscall Ped::sPed_FUN_00439970(Ped *this)


// Было: sPed_FUN_00439d30
void __thiscall Ped::sPed_FUN_00439d30(Ped *this)


// Было: sPed_FUN_00439e60
void __thiscall Ped::sPed_FUN_00439e60(Ped *this)


// Было: sPed_FUN_0043a210
void __thiscall Ped::sPed_FUN_0043a210(Ped *this)


// Было: sPed_FUN_0043a290
void __thiscall Ped::sPed_FUN_0043a290(Ped *this)


// Было: sPed_FUN_0043a340
void __thiscall Ped::sPed_FUN_0043a340(Ped *this)


// Было: sPed_FUN_0043a3c0
void __thiscall Ped::sPed_FUN_0043a3c0(Ped *this)


// Было: sPed_FUN_0043a490
void __thiscall Ped::sPed_FUN_0043a490(Ped *this)


// Было: sPed_FUN_0043a550
void __thiscall Ped::sPed_FUN_0043a550(Ped *this)


// Было: sPed_FUN_0043a660
void __thiscall Ped::sPed_FUN_0043a660(Ped *this)


// Было: sPed_FUN_0043a770
void __thiscall Ped::sPed_FUN_0043a770(Ped *this)


// Было: sPed_FUN_0043a880
void __thiscall Ped::sPed_FUN_0043a880(Ped *this)


// Было: sPed_FUN_0043a990
void __thiscall Ped::sPed_FUN_0043a990(Ped *this)


// Было: sPed_FUN_0043aa10
void __thiscall Ped::sPed_FUN_0043aa10(Ped *this)


byte __thiscall Ped::sPed_GetCopLevel(Ped *this)


// Было: FUN_0043ad10
void __thiscall Ped::FUN_0043ad10(Ped *this,int WeaponType)


Ped * __thiscall Char::FindPed(Char *this,int pPed_id)


Ped * __thiscall Ped::sPed(Ped *this)


void __thiscall Ped::CopyPed(Ped *this,Ped *pS49)


// Было: PedNormal_FUN_0043b550
void __thiscall Ped::PedNormal_FUN_0043b550(Ped *this)


// Было: PedNormal_FUN_0043b560
void __thiscall Ped::PedNormal_FUN_0043b560(Ped *this)


// Было: sPed_FUN_0043b570
void __thiscall Ped::sPed_FUN_0043b570(Ped *this,int param_1)


// Было: sPed_FUN_0043b9d0
void __thiscall Ped::sPed_FUN_0043b9d0(Ped *this)


// Было: sPed_FUN_0043bb50
void __thiscall Ped::sPed_FUN_0043bb50(Ped *this)


void __thiscall Ped::PedSetObjective(Ped *this,int objective,ushort timer)


// Было: sPed_FUN_0043bec0
void __thiscall Ped::sPed_FUN_0043bec0(Ped *this,Car *param_1)


// Было: sPed_FUN_0043c480
void __thiscall Ped::sPed_FUN_0043c480(Ped *this)


// Было: sPed_FUN_0043d1c0
void __thiscall Ped::sPed_FUN_0043d1c0(Ped *this)


void __thiscall Ped::SetNPCWeapon(Ped *this,int param_1)


// Было: S49_FUN_0043d880
void __thiscall Ped::S49_FUN_0043d880(Ped *this)


Char::SpawnPedAtPosition(Char *this,int x,int y,int z,char repmap,short param_5)


Ped * __thiscall Char::CreatePed(Char *this)


PedManager * __thiscall PedManager::PedManager(PedManager *this)


// Было: sPed_FUN_0043e140
void __thiscall Ped::sPed_FUN_0043e140(Ped *this,int param_1)


void __thiscall Ped::EnterCarAsPassenger(Ped *this,Car *target)


// Было: sPed_FUN_0043e3a0
void __thiscall Ped::sPed_FUN_0043e3a0(Ped *this,undefined2 *param_1)


uint __thiscall Ped::GiveWeapon(Ped *this,WeaponType ID_Weapon,char pAmmo)


// Было: FUN_0043e650
void __thiscall Ped::FUN_0043e650(Ped *this)


// Было: sPed_FUN_0043e8b0
void __thiscall Ped::sPed_FUN_0043e8b0(Ped *this)


// Было: sPed_FUN_0043eaf0
void __thiscall Ped::sPed_FUN_0043eaf0(Ped *this)


// Было: sPed_FUN_0043ebc0
void __thiscall Ped::sPed_FUN_0043ebc0(Ped *this)


// Было: sPed_FUN_0043ec30
void __thiscall Ped::sPed_FUN_0043ec30(Ped *this)


// Было: sPed_FUN_0043ecc0
byte __thiscall Ped::sPed_FUN_0043ecc0(Ped *this)


// Было: sPed_FUN_0043f180
void __thiscall Ped::sPed_FUN_0043f180(Ped *this)


// Было: sPed_FUN_0043f340
void __thiscall Ped::sPed_FUN_0043f340(Ped *this)


// Было: FUN_0043fd10
void __thiscall Ped::FUN_0043fd10(Ped *this)


// Было: sPed_FUN_0043fee0
void __thiscall Ped::sPed_FUN_0043fee0(Ped *this)


// Было: sPed_FUN_004402c0
void __thiscall Ped::sPed_FUN_004402c0(Ped *this,int param_1,int param_2)


void __thiscall Ped::PedGroupCreate(Ped *this,byte membersCount)


// Было: S49_FUN_004411b0
void __thiscall Ped::S49_FUN_004411b0(Ped *this)


void __thiscall Ped::TakeDamage(Ped *this,short damage)


// Было: PedNormal_FUN_00441a30
byte __thiscall Ped::PedNormal_FUN_00441a30(Ped *this,S63 *pS63)


// Было: FUN_00441f10
void __thiscall Ped::FUN_00441f10(Ped *this)


// Было: sPed_FUN_00442050
void __thiscall Ped::sPed_FUN_00442050(Ped *this)


// Было: sPed_FUN_00442420
void __thiscall Ped::sPed_FUN_00442420(Ped *this)


// Было: sPed_FUN_004427e0
void __thiscall Ped::sPed_FUN_004427e0(Ped *this)


// Было: sPed_FUN_00442a40
void __thiscall Ped::sPed_FUN_00442a40(Ped *this)


// Было: sPed_FUN_00442de0
void __thiscall Ped::sPed_FUN_00442de0(Ped *this)


// Было: sPed_FUN_00443170
void __thiscall Ped::sPed_FUN_00443170(Ped *this)


// Было: sPed_FUN_004436a0
void __thiscall Ped::sPed_FUN_004436a0(Ped *this)


// Было: sPed_FUN_00443c30
void __thiscall Ped::sPed_FUN_00443c30(Ped *this)


// Было: sPed_FUN_004440f0
void __thiscall Ped::sPed_FUN_004440f0(Ped *this)


// Было: sPed_FUN_004441b0
void __thiscall Ped::sPed_FUN_004441b0(Ped *this,uint param_1)


// Было: sPed_FUN_00444900
void __thiscall Ped::sPed_FUN_00444900(Ped *this)


// Было: sPed_FUN_00444910
void __thiscall Ped::sPed_FUN_00444910(Ped *this)


// Было: sPed_FUN_00444920
void __thiscall Ped::sPed_FUN_00444920(Ped *this)


// Было: PedNormal_FUN_00444930
Ped::PedNormal_FUN_00444930(Ped *this,uint param_1,undefined4 param_2)


// Было: sPed_FUN_00444a70
void __thiscall Ped::sPed_FUN_00444a70(Ped *this)


// Было: sPed_FUN_00444b50
void __thiscall Ped::sPed_FUN_00444b50(Ped *this)


// Было: sPed_FUN_00444d00
void __thiscall Ped::sPed_FUN_00444d00(Ped *this)


// Было: sPed_FUN_00445230
void __thiscall Ped::sPed_FUN_00445230(Ped *this)


// Было: sPed_FUN_00445330
void __thiscall Ped::sPed_FUN_00445330(Ped *this)


// Было: sPed_FUN_004454d0
void __thiscall Ped::sPed_FUN_004454d0(Ped *this)


byte __thiscall Ped::PedTick(Ped *this)


// Было: S48_FUN_00445960
void __thiscall PedManager::S48_FUN_00445960(PedManager *this)


S127::S127_HandlePedInteraction(S127 *this,uint param_1,Ped *pPed)


// Было: _Ped_FUN_0044a370
void __thiscall Ped::_Ped_FUN_0044a370(Ped *this,int param_1,Player *pPlayer)


// Было: S49_FUN_00450cb0
CarDamageState __thiscall Ped::S49_FUN_00450cb0(Ped *this)


// Было: S49_Get_FUN_00472fd0
bool __thiscall Ped::S49_Get_FUN_00472fd0(Ped *this)


void __thiscall S31::CreatePed2(S31 *this,Ped *pPed)


// Было: sPed_FUN_00482080
void __thiscall Ped::sPed_FUN_00482080(Ped *this)


// Было: sPed_FUN_00493000
void __thiscall Ped::sPed_FUN_00493000(Ped *this,int param_1)


GameObject * __thiscall Ped::PedNormal_FUN_004a5020(Ped *this)


// Было: sPed_FUN_004a5040
bool __thiscall Ped::sPed_FUN_004a5040(Ped *this)


void __thiscall Ped::SetHealthFullPlayer(Ped *this)


// Было: PedNormal_FUN_004a5060
void __thiscall Ped::PedNormal_FUN_004a5060(Ped *this)


// Было: FUN_004af860
void __thiscall Ped::FUN_004af860(Ped *this,int param_1)


// Было: FUN_004af880
void __thiscall Ped::FUN_004af880(Ped *this,int param_1)


void __thiscall sPed_FUN_004c7cf0(void *this)


