// Module: car
// Generated from gta2.exe.c
// Functions count: 334

#include "../../include/common.h"

void __thiscall CarSystemManager__ClampValues(CarSystemManager *this)


// Было: Car_FUN_00403820
// Стало: Car::CheckCarCondition
bool __thiscall Car::CheckCarCondition(Car *this, int *pResult)


bool __thiscall Car::IsTrainOrTrainCarriage(Car *this)


byte __thiscall Car__IsSpecialVehicle(Car *this)


void __thiscall CarSystemManager::SetIndexDefautCarManager(CarSystemManager *this)


// Было: S5_FUN_0040f490
// Стало: CarsPrefabs::InitializeCarPrefab
void __thiscall CarsPrefabs::InitializeCarPrefab(CarsPrefabs *this, Car *pCar)


bool __thiscall Car::Car_GetFullDamegeCar(Car *this)


// Было: FUN_004112a0
// Стало: Car::IsCarUsable
bool __thiscall Car::IsCarUsable(Car *this)


bool __thiscall Car::IsEngineOn(Car *this)


byte __thiscall Car::IsDriverPlayer(Car *this)


bool __thiscall Car::isFileTruck(Car *this)


bool __thiscall Car::isTank(Car *this)


bool __thiscall Car::isGunJeep(Car *this)


bool __thiscall Car::isEDSELFBI(Car *this)


// Было: GetCarFlags
// Стало: Car::GetCarFlags
ushort __thiscall Car::GetCarFlags(Car *this, ushort flagsMask)


CarType __thiscall Car::GetModelCar(Car *this)


// Было: GetCarDamageFlags
// Стало: Car::GetCarDamageFlags
byte __thiscall Car::GetCarDamageFlags(Car *this)


// Было: GetCarSpecialFlags
// Стало: Car::GetCarSpecialFlags
byte __thiscall Car::GetCarSpecialFlags(Car *this)


// Было: GetCarState
// Стало: Car::GetCarState
undefined1 __thiscall Car::GetCarState(Car *this)


bool __thiscall Car::IsEmergencyOrFbiCar(Car *this)


// Было: ResetCarPhysics
// Стало: Car::ResetCarPhysics
void __thiscall Car::ResetCarPhysics(Car *this)


// Было: InitCarVisuals
// Стало: Car::InitCarVisuals
void __thiscall Car::InitCarVisuals(Car *this)


// Было: GetCarClassType
// Стало: Car::GetCarClassType
undefined1 __thiscall Car::GetCarClassType(Car *this)


// Было: FUN_00416bb0
// Стало: Car::UpdateCarElectronics
void __thiscall Car::UpdateCarElectronics(Car *this, undefined2 *pElectronicsData)


// Было: UpdateCarMatrix
// Стало: Car::UpdateCarMatrix
void __thiscall Car::UpdateCarMatrix(Car *this, undefined4 *pTransformData)


// Было: ProcessCarCollisions
// Стало: Car::ProcessCarCollisions
void __thiscall Car::ProcessCarCollisions(Car *this, undefined4 *pCollisionData)


// Было: HandleCarImpact
// Стало: Car::HandleCarImpact
void __thiscall Car::HandleCarImpact(Car *this, undefined4 *pImpactData)


// Было: Set_FUN_0041f6c0
// Стало: CarDoor::ResetDoorState
void __thiscall CarDoor::ResetDoorState(CarDoor *this)


bool __thiscall Car::IsCopCar(Car *this)


void* __thiscall Car::GetInfoByTypeCar(Car *this)


// Было: SetCarPaintJob
// Стало: Car::SetCarPaintJob
void __thiscall Car::SetCarPaintJob(Car *this, undefined *pPaintJobData)


int __thiscall Car::GetDoor(Car *this, byte doorIndex)


// Было: GetCarVelocity
// Стало: Car::GetCarVelocity
undefined1 __thiscall Car::GetCarVelocity(Car *this)


// Было: FUN_0041f8f0
// Стало: Car::UpdateCarMovement
void __thiscall Car::UpdateCarMovement(Car *this)


// Было: GetCarHeading
// Стало: Car::GetCarHeading
void __thiscall Car::GetCarHeading(Car *this)


// Было: SetCarHeading
// Стало: Car::SetCarHeading
void __thiscall Car::SetCarHeading(Car *this)


// Было: ApplyCarForce
// Стало: Car::ApplyCarForce
void __thiscall Car::ApplyCarForce(Car *this)


// Было: Car_FUN_0041fab0
// Стало: Car::ApplyHandbrake
Car* __thiscall Car::ApplyHandbrake(Car *this)


// Было: FUN_0041fac0
// Стало: Car::StartCarEngine
void __thiscall Car::StartCarEngine(Car *this, undefined2 *pEngineParams)


// Было: FUN_0041fbb0
// Стало: Car::StopCarEngine
undefined1 __thiscall Car::StopCarEngine(Car *this)


void __thiscall Car::AddRoofWaterGun(Car *this)


void __thiscall Car::AddRoofTankTurret(Car *this)


void __thiscall Car::AddRoofGun(Car *this)


void __thiscall Car::DecrementHorn(Car *this)


void __thiscall Car::SetPosition(Car *this, int x, int y, int z)


// Было: Car_FUN_00420840
// Стало: Car::DamageCarFromImpact
CarSystemManager* __thiscall Car::DamageCarFromImpact(Car *this, void *pImpactSource)


// Было: SetCarIntegrity
// Стало: Car::SetCarIntegrity
void __thiscall Car::SetCarIntegrity(Car *this)


// Было: GetCarGasLevel
// Стало: Car::GetCarGasLevel
void __thiscall Car::GetCarGasLevel(Car *this, undefined4 param_1)


void __thiscall Car::UpdateDamageCooldown(Car *this)


// Было: CarSystemManager_FUN_00420a10
// Стало: CarSystemManager::GetCarByIndex
byte* __thiscall CarSystemManager::GetCarByIndex(short index)


// Было: CarSystemManager_FUN_00420c00
// Стало: CarSystemManager::ResetCarSystem
void __thiscall CarSystemManager::ResetCarSystem(CarSystemManager *this)


Car_conflict1* __thiscall CarsPrefabs::GetCar(CarsPrefabs *this)


// Было: S5_FUN_00420f20
// Стало: CarsPrefabs::ReleaseCarPrefab
void __thiscall CarsPrefabs::ReleaseCarPrefab(CarsPrefabs *this, Car *pCar)


// Было: S5_FUN_00420f30
// Стало: CarsPrefabs::CloneCarPrefab
void* __thiscall CarsPrefabs::CloneCarPrefab(CarsPrefabs *this, Car *pCar)


// Было: CarSystemManager_FUN_004212d0
// Стало: CarSystemManager::CleanupCarSystem
void __thiscall CarSystemManager::CleanupCarSystem(CarSystemManager *this)


// Было: S7
// Стало: CarDoor::InitDoor
void __thiscall CarDoor::InitDoor(CarDoor *this)


// Было: CheckCarOccupied
// Стало: Car::CheckCarOccupied
void __thiscall Car::CheckCarOccupied(Car *this)


// Было: CountCarOccupants
// Стало: Car::CountCarOccupants
void __thiscall Car::CountCarOccupants(Car *this)


// Было: Car_Set_FUN_00421460
// Стало: Car::PrepareCarForEntry
void __thiscall Car::PrepareCarForEntry(Car *this)


// Было: ValidateCarExit
// Стало: Car::ValidateCarExit
void __thiscall Car::ValidateCarExit(Car *this)


// Было: FUN_00421490
// Стало: Car::BoardCarAsDriver
void __thiscall Car::BoardCarAsDriver(Car *this)


// Было: BoardCarAsPassenger
// Стало: Car::BoardCarAsPassenger
bool __thiscall Car::BoardCarAsPassenger(Car *this)


// Было: DisembarkCar
// Стало: Car::DisembarkCar
void __thiscall Car::DisembarkCar(Car *this)


bool __thiscall Car::IsDriverActive(Car *this)


// Было: CarMakeDriveable2
// Стало: Car::MakeCarDriveableAdvanced
void __thiscall Car::MakeCarDriveableAdvanced(Car *this)


// Было: ReadCarDoorAngle
// Стало: Car::ReadCarDoorAngle
void __thiscall Car::ReadCarDoorAngle(Car *this)


// Было: WriteCarDoorAngle
// Стало: Car::WriteCarDoorAngle
void __thiscall Car::WriteCarDoorAngle(Car *this)


// Было: CarMakeDriveable1
// Стало: Car::MakeCarDriveableBasic
void __thiscall Car::MakeCarDriveableBasic(Car *this, int driveableFlags)


// Было: FixCarBrokenEngine
// Стало: Car::FixCarBrokenEngine
void __thiscall Car::FixCarBrokenEngine(Car *this)


// Было: SwingCarDoorOpen
// Стало: Car::SwingCarDoorOpen
void __thiscall Car::SwingCarDoorOpen(Car *this)


bool __thiscall Car::IsMask5(Car *this)


// Было: ShutCarDoor
// Стало: Car::ShutCarDoor
byte __thiscall Car::ShutCarDoor(Car *this)


// Было: EngageCarDoorLocks
// Стало: Car::EngageCarDoorLocks
void __thiscall Car::EngageCarDoorLocks(Car *this)


bool __thiscall Car::IsTrain(Car *this)


// Было: DisengageCarDoorLocks
// Стало: Car::DisengageCarDoorLocks
void __thiscall Car::DisengageCarDoorLocks(Car *this)


// Было: InspectCarWheel
// Стало: Car::InspectCarWheel
void __thiscall Car::InspectCarWheel(Car *this)


// Было: RepairCarWheel
// Стало: Car::RepairCarWheel
void __thiscall Car::RepairCarWheel(Car *this)


// Было: CheckCarLights
// Стало: Car::CheckCarLights
void __thiscall Car::CheckCarLights(Car *this)


// Было: ControlCarLights
// Стало: Car::ControlCarLights
void __thiscall Car::ControlCarLights(Car *this)


// Было: has_for_hire_lights
// Стало: Car::SetTaxiLightState
void __thiscall Car::SetTaxiLightState(Car *this)


// Было: FlashCarLights
// Стало: Car::FlashCarLights
byte __thiscall Car::FlashCarLights(Car *this)


// Было: Car_FUN_00421700
// Стало: Car::UpdateCarAlarm
void __thiscall Car::UpdateCarAlarm(Car *this)


// Было: Car_FUN_00421720
// Стало: Car::IsCarAlarmActive
bool __thiscall Car::IsCarAlarmActive(Car *this)


// Было: Car_FUN_00421740
// Стало: Car::GetCarSirenState
byte __thiscall Car::GetCarSirenState(Car *this)


// Было: Car_FUN_00421760
// Стало: Car::GetCarHornState
byte __thiscall Car::GetCarHornState(Car *this)


bool __thiscall Car::isMedicCar(Car *this)


bool __thiscall Car::isCopCar(Car *this)


bool __thiscall Car::isSWATVAN(Car *this)


bool __thiscall Car::isJeep(Car *this)


bool __thiscall Car::IsAPC(Car *this)


// Было: GetGT24640
// Стало: Car::HasSpecialEquipment
bool __thiscall Car::HasSpecialEquipment(Car *this)


bool __thiscall Car::isTVVAN(Car *this)


bool __thiscall Car::isTaxi(Car *this)


// Было: Car_FUN_00421810
// Стало: Car::UpdateCarRadar
void __thiscall Car::UpdateCarRadar(Car *this)


// Было: Car_FUN_00421830
// Стало: Car::IsCarTargetable
bool __thiscall Car::IsCarTargetable(Car *this)


Player* __thiscall Car::GetPlayer(Car *this)


// Было: Car_FUN_00420840 (дубликат)
// Стало: Car::RequestCarDamage
CarSystemManager* __thiscall Car::RequestCarDamage(Car *this, void *pDamageSource)


// Было: Car_FUN_00421890
// Стало: Car::SetCarSpecialMode
void __thiscall Car::SetCarSpecialMode(Car *this, ushort modeFlags)


// Было: FUN_004218a0
// Стало: Car::ResetCarWeapons
void __thiscall Car::ResetCarWeapons(Car *this)


// Было: Car_FUN_004218b0
// Стало: Car::UpdateCarTurret
void __thiscall Car::UpdateCarTurret(Car *this)


// Было: FUN_004218c0
// Стало: Car::ClearCarPassengers
void __thiscall Car::ClearCarPassengers(Car *this)


// Было: FUN_004218d0
// Стало: Car::ResetCarState
void __thiscall Car::ResetCarState(Car *this)


// Было: Car_FUN_004218e0
// Стало: Car::RefreshCarVisuals
void __thiscall Car::RefreshCarVisuals(Car *this)


// Было: Car_FUN_004218f0
// Стало: Car::GetCarTransmissionState
byte __thiscall Car::GetCarTransmissionState(Car *this)


// Было: Car_FUN_00421900
// Стало: Car::SetCarRadioStation
void __thiscall Car::SetCarRadioStation(Car *this, undefined4 stationId)


// Было: SetSound
// Стало: Car::SetEngineSound
void __thiscall Car::SetEngineSound(Car *this, undefined4 soundId)


// Было: CarSystemManager_FUN_00421960
// Стало: CarSystemManager::ProcessAllCars
void __thiscall CarSystemManager::ProcessAllCars(CarSystemManager *this)


// Было: FUN_00421a00
// Стало: CarDoor::AttachTurret
void __thiscall CarDoor::AttachTurret(CarDoor *this, Turrel *pTurret)


// Было: FUN_00421a80
// Стало: CarDoor::DetachTurret
void __thiscall CarDoor::DetachTurret(CarDoor *this, Turrel *pTurret)


// Было: FUN_00421af0
// Стало: CarDoor::UpdateTurretPosition
void __thiscall CarDoor::UpdateTurretPosition(CarDoor *this, Turrel *pTurret)


// Было: FUN_00421c40
// Стало: Car::ProcessCarComponent
undefined4 __thiscall Car::ProcessCarComponent(Car *this, undefined4 componentId)


// Было: Car_FUN_00421d80
// Стало: Car::CleanupCarExtras
void __thiscall Car::CleanupCarExtras(Car *this)


// Было: Car_FUN_00421d90
// Стало: Car::CopyCarData
Car* __thiscall Car::CopyCarData(Car *this, Car *pSourceCar)


// Было: Car_FUN_00421df0
// Стало: Car::FinalizeCarInit
undefined1 __thiscall Car::FinalizeCarInit(Car *this)


// Было: FUN_00421e70
// Стало: Car::GetCarTransformMatrix
undefined4* __thiscall Car::GetCarTransformMatrix(Car *this, undefined4 *pMatrix)


// Было: Car_FUN_00421ec0
// Стало: Car::GetCarGameObject
S6* __thiscall Car::GetCarGameObject(Car *this, S6 *pGameObject)


// Было: Car_FUN_00421f40
// Стало: Car::SetCarRemapTexture
byte __thiscall Car::SetCarRemapTexture(Car *this, short remapId)


// Было: FUN_00421f80
// Стало: Car::SetCarPaintJobIndex
byte __thiscall Car::SetCarPaintJobIndex(Car *this, byte paintJobId)


void __thiscall Car::SetRemap(Car *this, short Remap)


// Было: Car_FUN_004220a0
// Стало: Car::IsCarVisible
byte __thiscall Car::IsCarVisible(Car *this)


// Было: Car_FUN_004221d0
// Стало: Car::AssignPedToCar
void __thiscall Car::AssignPedToCar(Car *this, Ped *pPed)


// Было: Car_FUN_00422230
// Стало: Car::RemoveCarOccupants
void __thiscall Car::RemoveCarOccupants(Car *this)


// Было: Car_FUN_00422260
// Стало: Car::EjectAllOccupants
void __thiscall Car::EjectAllOccupants(Car *this)


// Было: FUN_004222d0
// Стало: Car::ExplodeCar
void __thiscall Car::ExplodeCar(Car *this)


// Было: FUN_004222f0
// Стало: Car::IgniteCarFuel
void __thiscall Car::IgniteCarFuel(Car *this)


// Было: Car_FUN_00422360
// Стало: Car::CanPedEnterCar
byte __thiscall Car::CanPedEnterCar(Car *this, Ped *pPed)


// Было: Car_FUN_00422670
// Стало: Car::UpdateCarAI
void __thiscall Car::UpdateCarAI(Car *this)


// Было: Car_FUN_004226c0
// Стало: Car::SetCarDriver
void __thiscall Car::SetCarDriver(Car *this, byte driverType, Ped *pPed)


// Было: Car_FUN_004228f0
// Стало: Car::StartCarMission
void __thiscall Car::StartCarMission(Car *this)


// Было: Car_FUN_00422980
// Стало: Car::StopCarMission
void __thiscall Car::StopCarMission(Car *this)


// Было: Car_FUN_00422a40
// Стало: Car::UpdateCarPathfinding
void __thiscall Car::UpdateCarPathfinding(Car *this)


// Было: Car_FUN_00422b70
// Стало: Car::AvoidCarObstacles
void __thiscall Car::AvoidCarObstacles(Car *this)


// Было: Car_FUN_00422cb0
// Стало: Car::FollowCarRoute
void __thiscall Car::FollowCarRoute(Car *this)


// Было: Car_FUN_00422d20
// Стало: Car::ParkCar
void __thiscall Car::ParkCar(Car *this)


// Было: Car_FUN_00422d80
// Стало: Car::UnparkCar
void __thiscall Car::UnparkCar(Car *this)


// Было: Car_FUN_00422de0
// Стало: Car::FleeCarFromDanger
void __thiscall Car::FleeCarFromDanger(Car *this)


// Было: Car_FUN_00422e00
// Стало: Car::AimCarTurret
void __thiscall Car::AimCarTurret(Car *this, Turrel *pTarget)


// Было: Car_FUN_00422f00
// Стало: Car::FireCarWeapon
void __thiscall Car::FireCarWeapon(Car *this, undefined4 weaponType)


// Было: Car_FUN_004230d0
// Стало: Car::IsCarWeaponReady
byte __thiscall Car::IsCarWeaponReady(Car *this, undefined4 weaponType)


// Было: Car_FUN_00423230
// Стало: Car::SpawnCarWithParams
void __thiscall Car::SpawnCarWithParams(Car *this, int carType, SpriteS1 *pSpawnPoint, S46 *pCarPool)


// Было: Car_FUN_00423290
// Стало: Car::DespawnCar
void __thiscall Car::DespawnCar(Car *this)


// Было: Car_FUN_004232e0
// Стало: Car::RespawnCar
void __thiscall Car::RespawnCar(Car *this)


// Было: Car_FUN_004233b0
// Стало: Car::WarpCarToLocation
void __thiscall Car::WarpCarToLocation(Car *this)


// Было: Car_FUN_00423480
// Стало: Car::GetCarDriver
Ped* __thiscall Car::GetCarDriver(Car *this)


void __thiscall Car::CarPutDummyDriverIn(Car *this)


// Было: Car_FUN_00423590
// Стало: Car::RemovePedFromCar
void __thiscall Car::RemovePedFromCar(Car *this, Ped *pPed)


// Было: Car_FUN_004235d0
// Стало: Car::KillCarDriver
void __thiscall Car::KillCarDriver(Car *this)


// Было: FUN_00423630
// Стало: Car::GetCarSpeed
undefined4 __thiscall Car::GetCarSpeed(Car *this)


// Было: Car_FUN_00423720
// Стало: Car::SetCarAlertState
byte __thiscall Car::SetCarAlertState(Car *this, char alertLevel)


// Было: Car_FUN_00423830
// Стало: Car::ResetCarAlert
void __thiscall Car::ResetCarAlert(Car *this)


// Было: Car_FUN_00423940
// Стало: Car::SetCarTarget
void __thiscall Car::SetCarTarget(Car *this, int targetType)


// Было: Car_FUN_00423a50
// Стало: Car::ClearCarTarget
void __thiscall Car::ClearCarTarget(Car *this)


// Было: Car_FUN_00423aa0
void __thiscall Car::Car_FUN_00423aa0(Car *this)


// Было: FUN_00423b30
void __thiscall Car::FUN_00423b30(Car *this)


// Было: Car_FUN_00424010
byte __thiscall Car::Car_FUN_00424010(Car *this)


// Было: Car_FUN_00424090
void __thiscall Car::Car_FUN_00424090(Car *this)


// Было: Car_FUN_004241c0
byte __thiscall Car::Car_FUN_004241c0(Car *this)


Ped * __thiscall Car::car_FUN_00424220(Car *this,Ped *param_1)


// Было: Car_FUN_00423aa0
void __thiscall Car::Car_FUN_00423aa0(Car *this)


// Было: Car_FUN_004243c0
int __thiscall Car::Car_FUN_004243c0(Car *this)


// Было: Car_FUN_00424400
void __thiscall Car::Car_FUN_00424400(Car *this)


// Было: Car_FUN_004244a0
void __thiscall Car::Car_FUN_004244a0(Car *this,int param_1)


// Было: Car__FUN_00424630
void __thiscall Car::Car__FUN_00424630(Car *this,void *param_1)


// Было: Car_FUN_004246a0
int __thiscall Car::Car_FUN_004246a0(Car *this)


// Было: Car_FUN_00424700
void __thiscall Car::Car_FUN_00424700(Car *this)


// Было: Car_FUN_00424880
void __thiscall Car::Car_FUN_00424880(Car *this)


void __thiscall CarsPrefabs::S5_Destruct(CarsPrefabs *this)


Car * __thiscall CarsPrefabs::S5_FUN_00425480(CarsPrefabs *this)


void * __thiscall CarsPrefabs::S5_FUN_004254a0(CarsPrefabs *this)


// Было: Car_FUN_00425590
void __thiscall Car::Car_FUN_00425590(Car *this)


// Было: Car_FUN_00425650
void __thiscall Car::Car_FUN_00425650(Car *this)


// Было: Car_FUN_00425770
void __thiscall Car::Car_FUN_00425770(Car *this)


// Было: Car_FUN_00425780
void __thiscall Car::Car_FUN_00425780(Car *this)


// Было: FUN_004257b0
byte __thiscall Car::FUN_004257b0(Car *this)


// Было: Car_FUN_00425810
byte __thiscall Car::Car_FUN_00425810(Car *this,SpriteS1 *pSprite)


// Было: Car_FUN_00425a40
bool __thiscall Car::Car_FUN_00425a40(Car *this,uint param_1)


// Было: Car_FUN_00425b60
bool __thiscall Car::Car_FUN_00425b60(Car *this,byte param_1)


// Было: Car_FUN_00425ca0
void __thiscall Car::Car_FUN_00425ca0(Car *this,Car *pCar)


// Было: Car_FUN_00425d90
void __thiscall Car::Car_FUN_00425d90(Car *this)


void __thiscall Car::CarMakeDriveable4(Car *this)


// Было: Car_FUN_00425df0
void __thiscall Car::Car_FUN_00425df0(Car *this)


void __thiscall Car::EnableSiren(Car *this)


// Было: Car_FUN_00425e60
void __thiscall Car::Car_FUN_00425e60(Car *this)


// Было: Car_FUN_00425e90
void __thiscall Car::Car_FUN_00425e90(Car *this)


// Было: Car_FUN_00425ed0
void __thiscall Car::Car_FUN_00425ed0(Car *this)


void __thiscall Car::FixCarDamage(Car *this)


void __thiscall Car::AddRoofAntenna(Car *this)


// Было: Car_FUN_004260c0
void __thiscall Car::Car_FUN_004260c0(Car *this,char param_1)


// Было: Car_FUN_00426120
void __thiscall Car::Car_FUN_00426120(Car *this)


// Было: Car_FUN_00426220
void __thiscall Car::Car_FUN_00426220(Car *this)


// Было: Car_FUN_00426270
void __thiscall Car::Car_FUN_00426270(Car *this)


// Было: Car_FUN_004262b0
void __thiscall Car::Car_FUN_004262b0(Car *this,Car *pCar)


// Было: Car_FUN_004262e0
void __thiscall Car::Car_FUN_004262e0(Car *this)


// Было: Car_FUN_00426540
byte __thiscall Car::Car_FUN_00426540(Car *this)


// Было: Car_FUN_00426580
void __thiscall Car::Car_FUN_00426580(Car *this,S110 *param_1)


// Было: Car_FUN_004266f0
void __thiscall Car::Car_FUN_004266f0(Car *this)


// Было: Car_FUN_00426730
void __thiscall Car::Car_FUN_00426730(Car *this)


Car * __thiscall Car::Car(Car *this)


CarsPrefabs * __thiscall CarsPrefabs::S5(CarsPrefabs *this)


void __thiscall Car::ENGINE_ON(Car *this)


// Было: Car_FUN_00426ee0
void __thiscall Car::Car_FUN_00426ee0(Car *this)


// Было: Car_FUN_00426f00
void __thiscall Car::Car_FUN_00426f00(Car *this)


// Было: Car_FUN_00426f40
void __thiscall Car::Car_FUN_00426f40(Car *this)


// Было: Car_FUN_00426f60
void __thiscall Car::Car_FUN_00426f60(Car *this)


void __thiscall Car::ExplodeCar(Car *this,int explosionSize)


Car::Car_CollisionOnCar(Car *this,int iCount_32000,Ped *param_2)


// Было: Car_FUN_00427290
void __thiscall Car::Car_FUN_00427290(Car *this)


// Было: Car_FUN_00427450
char __thiscall Car::Car_FUN_00427450(Car *this)


// Было: Car_FUN_004274c0
int __thiscall Car::Car_FUN_004274c0(Car *this,S63 *param_1)


void __thiscall Car::CarMakeDummy(Car *this)


// Было: Car_FUN_00427a20
void __thiscall Car::Car_FUN_00427a20(Car *this,Ped *pPed)


// Было: Car_FUN_00427b20
void __thiscall Car::Car_FUN_00427b20(Car *this)


// Было: Car_FUN_00427b40
void __thiscall Car::Car_FUN_00427b40(Car *this)


// Было: Car_FUN_00427b60
void __thiscall Car::Car_FUN_00427b60(Car *this)


void __thiscall Car::MaxPaynt(Car *this,short pRemap)


// Было: Car_FUN_00427ca0
void __thiscall Car::Car_FUN_00427ca0(Car *this,undefined4 param_1)


// Было: Car_FUN_00427d10
void __thiscall Car::Car_FUN_00427d10(Car *this,S61 *pS61)


// Было: FUN_00428f70
void __thiscall CarSystemManager::FUN_00428f70(CarSystemManager *this,Car *pCar)


CarSystemManager::CarSystemManager(CarSystemManager *this)


// Было: Car_FUN_004292f0
short __thiscall Car::Car_FUN_004292f0(Car *this,undefined4 param_1)


// Было: Car_FUN_00429370
void __thiscall Car::Car_FUN_00429370(Car *this,int param_1)


// Было: Car_FUN_004293d0
byte __thiscall Car::Car_FUN_004293d0(Car *this,S61 *pS61)


// Было: Car_FUN_00429660
void __thiscall Car::Car_FUN_00429660(Car *this)


// Было: FUN_00429680
void __thiscall Car::FUN_00429680(Car *this,int param_1,int param_2,int param_3)


void * __thiscall Car::Car_FUN_00429800(Car *this)


// Было: Car_FUN_004298b0
byte __thiscall Car::Car_FUN_004298b0(Car *this)


// Было: Car_FUN_00429e50
byte __thiscall Car::Car_FUN_00429e50(Car *this)


// Было: S5_FUN_0042a2d0
void __thiscall CarsPrefabs::S5_FUN_0042a2d0(CarsPrefabs *this)


// Было: Car_FUN_0042a360
void __thiscall Car::Car_FUN_0042a360(Car *this,void *param_1)


// Было: CarSystemManager_FUN_0042a4c0
CarSystemManager::CarSystemManager_FUN_0042a4c0(CarSystemManager *this)


// Было: Car_FUN_0042a510
void __thiscall Car::Car_FUN_0042a510(Car *this)


// Было: Car_FUN_0042a5b0
void __thiscall Car::Car_FUN_0042a5b0(Car *this)


void __thiscall Car::CarMakeDriveable3(Car *this,Car *pCar)


// Было: FUN_0042c030
void __thiscall Car::FUN_0042c030(Car *this)


// Было: FUN_0042d820
void __thiscall Car::FUN_0042d820(Car *this)


// Было: FUN_00431c10
void __thiscall Car::FUN_00431c10(Car *this)


// Было: Car_FUN_00432370
void __thiscall Car::Car_FUN_00432370(Car *this)


// Было: Car_FUN_004326e0
void __thiscall Car::Car_FUN_004326e0(Car *this)


// Было: Car_FUN_004327a0
void __thiscall Car::Car_FUN_004327a0(Car *this)


// Было: S96_FUN_004327e0
int __thiscall CarEngines::S96_FUN_004327e0(CarEngines *this,byte param_1)


int __thiscall CarEngines::GetEngineState(CarEngines *this,byte index)


void __thiscall CarEngines::ResetEngineArrays(CarEngines *this)


CarEngines * __thiscall CarEngines::S96(CarEngines *this)


// Было: FUN_00432cd0
void __thiscall CarEngines::FUN_00432cd0(CarEngines *this)


void __thiscall CarEngines::CarInfo(CarEngines *this)


// Было: FUN_00432ea0
void __thiscall CarEngines::FUN_00432ea0(CarEngines *this)


// Было: FUN_00432fc0
void __thiscall CarEngines::FUN_00432fc0(CarEngines *this,char *param_1)


// Было: FUN_00433000
void __thiscall CarEngines::FUN_00433000(CarEngines *this)


// Было: thunk_FUN_00433000
void __thiscall CarEngines::thunk_FUN_00433000(CarEngines *this)


// Было: FUN_00433050
void __thiscall CarEngines::FUN_00433050(CarEngines *this)


void __thiscall Car_FUN_00441450(void *this,Car *param_1,int param_2)


undefined2 * __thiscall CarSystemManager::PrepareArray(CarSystemManager *this)


// Было: CarSystemManager_FUN_00447d30
CarSystemManager::CarSystemManager_FUN_00447d30(CarSystemManager *this)


// Было: Car_FUN_00447ea0
void __thiscall Car::Car_FUN_00447ea0(Car *this)


// Было: Car_FUN_00447eb0
bool __thiscall Car::Car_FUN_00447eb0(Car *this)


bool __thiscall S105::S105_FindCar(S105 *this,Car *pCar)


// Было: Car_FUN_00450cc0
bool __thiscall Car::Car_FUN_00450cc0(Car *this)


short __thiscall CarsPrefabs::GetCarsCount(CarsPrefabs *this)


// Было: Car_FUN_00475c10
void __thiscall Car::Car_FUN_00475c10(Car *this)


// Было: Car_FUN_00475c30
void __thiscall Car::Car_FUN_00475c30(Car *this)


// Было: Car_FUN_00475c80
void __thiscall Car::Car_FUN_00475c80(Car *this)


// Было: Car_FUN_00476270
void __thiscall Car::Car_FUN_00476270(Car *this)


bool __thiscall S119::IsCarEqual(S119 *this,Car *param_1)


// Было: Car_FUN_0049efc0
void __thiscall Car::Car_FUN_0049efc0(Car *this)


// Было: Car_FUN_0049efe0
undefined1 __thiscall Car::Car_FUN_0049efe0(Car *this)


// Было: FUN_004ab220
void __thiscall Car::FUN_004ab220(Car *this)


PublicTransport::S81_FindCarField(PublicTransport *this,Car *pCar)


void __thiscall SoundCard::AcquireSampleHandle(SoundCard *this)


void __thiscall SoundCard::ReleaseSampleHandle(SoundCard *this)


void __thiscall SoundCard::ReleaseAllSampleHandles(SoundCard *this)


// Было: SoundCard_FUN_004b6020
int __thiscall SoundCard::SoundCard_FUN_004b6020(SoundCard *this,int param_1)


// Было: SoundCard_FUN_004b6040
SoundCard::SoundCard_FUN_004b6040(SoundCard *this,int param_1)


// Было: SoundCard_FUN_004b6060
SoundCard::SoundCard_FUN_004b6060(SoundCard *this,int param_1)


// Было: SoundCard_FUN_004b6080
SoundCard::SoundCard_FUN_004b6080(SoundCard *this,int param_1)


// Было: SoundCard_FUN_004b60a0
SoundCard::SoundCard_FUN_004b60a0(SoundCard *this,int param_1)


// Было: SoundCard_FUN_004b60c0
SoundCard::SoundCard_FUN_004b60c0(SoundCard *this,int param_1,int param_2)


// Было: SoundCard_FUN_004b6110
void __thiscall SoundCard::SoundCard_FUN_004b6110(SoundCard *this,int param_1)


// Было: SoundCard_FUN_004b6130
void __thiscall SoundCard::SoundCard_FUN_004b6130(SoundCard *this,int param_1)


// Было: SoundCard_FUN_004b6150
void __thiscall SoundCard::SoundCard_FUN_004b6150(SoundCard *this,int param_1)


// Было: SoundCard_FUN_004b6170
void __thiscall SoundCard::SoundCard_FUN_004b6170(SoundCard *this,int param_1)


// Было: SoundCard_FUN_004b6190
void __thiscall SoundCard::SoundCard_FUN_004b6190(SoundCard *this,int param_1)


// Было: SoundCard_FUN_004b61b0
bool __thiscall SoundCard::SoundCard_FUN_004b61b0(SoundCard *this,int param_1)


// Было: SoundCard_FUN_004b61e0
void __thiscall SoundCard::SoundCard_FUN_004b61e0(SoundCard *this,int param_1)


void __thiscall SoundCard::StopSample(SoundCard *this,int param_1)


// Было: SoundCard_FUN_004b62b0
void __thiscall SoundCard::SoundCard_FUN_004b62b0(SoundCard *this,int param_1)


// Было: SoundCard_FUN_004b62d0
void __thiscall SoundCard::SoundCard_FUN_004b62d0(SoundCard *this,int param_1)


// Было: SoundCard_FUN_004b6320
void __thiscall SoundCard::SoundCard_FUN_004b6320(SoundCard *this,int param_1)


// Было: SoundCard_FUN_004b6340
void __thiscall SoundCard::SoundCard_FUN_004b6340(SoundCard *this,int param_1)


// Было: SoundCard_FUN_004b6360
void __thiscall SoundCard::SoundCard_FUN_004b6360(SoundCard *this,int param_1)


// Было: SoundCard_FUN_004b6380
bool __thiscall SoundCard::SoundCard_FUN_004b6380(SoundCard *this,int param_1)


// Было: SoundCard_FUN_004b63b0
void __thiscall SoundCard::SoundCard_FUN_004b63b0(SoundCard *this,int param_1)


void __thiscall SoundCard::CheckAndStop3DSample(SoundCard *this,int param_1)


void __thiscall SoundCard::SetEAXEnvironment(SoundCard *this,int param_1)


void __thiscall SoundCard::Shutdown3DAudio(SoundCard *this)


void __thiscall SoundCard::Enumerate3DAudioProviders(SoundCard *this)


void __thiscall SoundCard::ShutdownAudioStream(SoundCard *this)


// Было: SoundCard_FUN_004b6680
byte __thiscall SoundCard::SoundCard_FUN_004b6680(SoundCard *this)


// Было: SoundCard_FUN_004b66a0
bool __thiscall SoundCard::SoundCard_FUN_004b66a0(SoundCard *this)


// Было: SoundCard_FUN_004b66d0
SoundCard::SoundCard_FUN_004b66d0(SoundCard *this,undefined1 param_1)


// Было: SoundCard_FUN_004b6700
void __thiscall SoundCard::SoundCard_FUN_004b6700(SoundCard *this,uint param_1)


// Было: SoundCard_FUN_004b67b0
void __thiscall SoundCard::SoundCard_FUN_004b67b0(SoundCard *this)


void __thiscall SoundCard::FadeOutAndCloseStream(SoundCard *this)


// Было: SoundCard_FUN_004b6850
undefined1 __thiscall SoundCard::SoundCard_FUN_004b6850(SoundCard *this)


void * __thiscall SoundCard::CloseStreamByIndex(SoundCard *this,int streamIndex)


// Было: SoundCard_FUN_004b6890
void __thiscall SoundCard::SoundCard_FUN_004b6890(SoundCard *this,int param_1)


// Было: SoundCard_FUN_004b68c0
void __thiscall SoundCard::SoundCard_FUN_004b68c0(SoundCard *this,int param_1)


// Было: SoundCard_FUN_004b68e0
SoundCard::SoundCard_FUN_004b68e0(SoundCard *this,int param_1)


// Было: SoundCard_FUN_004b6910
void __thiscall SoundCard::SoundCard_FUN_004b6910(SoundCard *this,int param_1)


// Было: SoundCard_FUN_004b6930
int __thiscall SoundCard::SoundCard_FUN_004b6930(SoundCard *this,int param_1)


// Было: SoundCard_FUN_004b6960
int __thiscall SoundCard::SoundCard_FUN_004b6960(SoundCard *this,int param_1)


// Было: SoundCard_FUN_004b6990
SoundCard::SoundCard_FUN_004b6990(SoundCard *this,undefined1 param_1)


// Было: SoundCard_FUN_004b69b0
void __thiscall SoundCard::SoundCard_FUN_004b69b0(SoundCard *this,int param_1)


// Было: SoundCard_FUN_004b6a40
bool __thiscall SoundCard::SoundCard_FUN_004b6a40(SoundCard *this)


// Было: SoundCard_FUN_004b6a60
void __thiscall SoundCard::SoundCard_FUN_004b6a60(SoundCard *this)


// Было: SoundCard_FUN_004b6a80
SoundCard::SoundCard_FUN_004b6a80(SoundCard *this,uint param_1,uint param_2)


// Было: SoundCard_FUN_004b6b20
void __thiscall SoundCard::SoundCard_FUN_004b6b20(SoundCard *this)


// Было: SoundCard_FUN_004b6b40
byte __thiscall SoundCard::SoundCard_FUN_004b6b40(SoundCard *this,char *param_1)


void __thiscall SoundCard::Reset3DAudioSystem(SoundCard *this)


byte __thiscall SoundCard::ReinitializeAudioSystem(SoundCard *this)


void __thiscall SoundCard::CloseAudioSystem(SoundCard *this)


byte __thiscall SoundCard::InitializeAudioSystem(SoundCard *this)


int * __thiscall Car::Car_FUN_004be980(Car *this,int param_1)


// Было: Car_FUN_004be9c0
int __thiscall Car::Car_FUN_004be9c0(Car *this,int param_1)


SpriteS1 * __thiscall Car::Car_FUN_004be9f0(Car *this)


// Было: Car_FUN_004bea20
void __thiscall Car::Car_FUN_004bea20(Car *this)


// Было: Car_FUN_004bea40
void __thiscall Car::Car_FUN_004bea40(Car *this)


// Было: Car_FUN_004beb70
void __thiscall Car::Car_FUN_004beb70(Car *this)


// Было: Car_FUN_004bee80
void __thiscall Car::Car_FUN_004bee80(Car *this)


// Было: Car_FUN_004bef70
void __thiscall Car::Car_FUN_004bef70(Car *this,Sprite *param_1)


// Было: Car_FUN_004bf000
void __thiscall Car::Car_FUN_004bf000(Car *this)


void __thiscall Car::ExtinguishCar(Car *this)


// Было: Car_FUN_004bf100
void __thiscall Car::Car_FUN_004bf100(Car *this)


// Было: CarSystemManager_FUN_004c39f0
CarSystemManager::CarSystemManager_FUN_004c39f0(CarSystemManager *this)


Turrel::CarAddWeapon(Turrel *this,int pWeaponType,uint pAmmo,Car *pCar)


