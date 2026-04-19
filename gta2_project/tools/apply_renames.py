#!/usr/bin/env python3
import re
from pathlib import Path

RENAMES = {
    'Car_FUN_0041f8f0': 'SetCarVelocity',
    'Car_FUN_0041fac0': 'IgniteCarEngine',
    'Car_FUN_0041fbb0': 'ShutOffCarEngine',
    'Car_FUN_00421490': 'BoardCarAsDriver',
    'Car_FUN_00411930': 'GetCarFlags',
    'Car_FUN_00411970': 'GetCarDamageFlags',
    'Car_FUN_00411990': 'GetCarSpecialFlags',
    'Car_FUN_004119f0': 'GetCarState',
    'Car_FUN_00414f60': 'ResetCarPhysics',
    'Car_FUN_00414f70': 'InitCarVisuals',
    'Car_FUN_00414f80': 'GetCarClassType',
    'Car_FUN_0041e430': 'UpdateCarMatrix',
    'Car_FUN_0041e440': 'ProcessCarCollisions',
    'Car_FUN_0041e450': 'HandleCarImpact',
    'Car_FUN_0041f730': 'SetCarPaintJob',
    'Car_FUN_0041f880': 'GetCarVelocity',
    'Car_FUN_0041f960': 'GetCarHeading',
    'Car_FUN_0041f9f0': 'SetCarHeading',
    'Car_FUN_0041fa60': 'ApplyCarForce',
    'Car_FUN_0041fab0': 'BrakeCar',
    'Car_FUN_00420840': 'GetCarIntegrity',
    'Car_FUN_004208f0': 'SetCarIntegrity',
    'Car_FUN_00420950': 'GetCarGasLevel',
    'Car_FUN_00420a10': 'SetCarGasLevel',
    'Car_FUN_00420c00': 'GetCarDriverPed',
    'Car_FUN_00420f20': 'AssignCarDriver',
    'Car_FUN_00420f30': 'GetCarPassengerPed',
    'Car_FUN_004212d0': 'EjectCarOccupant',
    'Car_FUN_004213d0': 'CheckCarOccupied',
    'Car_FUN_00421430': 'CountCarOccupants',
    'Car_FUN_00421460': 'ValidateCarEntry',
    'Car_FUN_00421470': 'ValidateCarExit',
    'Car_FUN_004214d0': 'BoardCarAsPassenger',
    'Car_FUN_004214e0': 'DisembarkCar',
    'Car_FUN_00421540': 'ReadCarDoorAngle',
    'Car_FUN_00421550': 'WriteCarDoorAngle',
    'Car_FUN_00421590': 'SwingCarDoorOpen',
    'Car_FUN_004215c0': 'ShutCarDoor',
    'Car_FUN_004215f0': 'EngageCarDoorLocks',
    'Car_FUN_00421620': 'DisengageCarDoorLocks',
    'Car_FUN_00421640': 'InspectCarWheel',
    'Car_FUN_00421660': 'RepairCarWheel',
    'Car_FUN_00421680': 'CheckCarLights',
    'Car_FUN_004216a0': 'ControlCarLights',
    'Car_FUN_004216e0': 'FlashCarLights',
}

def apply_renames_to_file(filepath):
    with open(filepath, 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()
    
    count = 0
    for old_suffix, new_name in RENAMES.items():
        # Match function definition
        pattern_def = rf'(void|bool|byte|int|uint|float|undefined\d*|char|short|ushort|long|ulong|DWORD|LPDWORD|GANG|CarType|CarDamageState)\s+(__thiscall\s+)?Car::({old_suffix})\('
        replacement_def = rf'\1\2Car::{new_name}('
        
        matches = re.findall(pattern_def, content)
        if matches:
            count += len(matches)
            content = re.sub(pattern_def, replacement_def, content)
        
        # Match function calls
        pattern_call = rf'->{old_suffix}\('
        replacement_call = rf'->{new_name}('
        content = re.sub(pattern_call, replacement_call, content)
    
    if count > 0:
        with open(filepath, 'w', encoding='utf-8') as f:
            f.write(content)
    
    return count

# Apply to car.c
car_file = Path('/workspace/gta2_project/src/car/car.c')
renamed = apply_renames_to_file(car_file)
print(f"Переименовано {renamed} функций в {car_file}")
