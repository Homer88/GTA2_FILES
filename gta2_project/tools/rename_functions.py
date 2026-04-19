#!/usr/bin/env python3
import os
import re
from pathlib import Path

FUNCTION_PATTERNS = {
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
    'Car_FUN_0041f8f0': 'SetCarVelocity',
    'Car_FUN_0041f960': 'GetCarHeading',
    'Car_FUN_0041f9f0': 'SetCarHeading',
    'Car_FUN_0041fa60': 'ApplyCarForce',
    'Car_FUN_0041fab0': 'BrakeCar',
    'Car_FUN_0041fac0': 'IgniteCarEngine',
    'Car_FUN_0041fbb0': 'ShutOffCarEngine',
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
    'Car_FUN_00421490': 'BoardCarAsDriver',
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

def process_file(filepath):
    with open(filepath, 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()
    
    pattern = r'(\w+(?:\s+\w+)*?)\s+__thiscall\s+(\w+)::(FUN_[0-9a-f]{8})\(([^)]*)\)'
    matches = re.findall(pattern, content)
    
    renames = []
    for return_type, class_name, func_name, params in matches:
        key = f'{class_name}_{func_name}'
        if key in FUNCTION_PATTERNS:
            new_name = FUNCTION_PATTERNS[key]
            renames.append((func_name, f'{class_name}__{new_name}', class_name))
    
    return renames

src_dir = Path('/workspace/gta2_project/src')
all_renames = []

for c_file in src_dir.rglob('*.c'):
    renames = process_file(c_file)
    if renames:
        all_renames.extend(renames)
        print(f"{c_file.name}: {len(renames)} функций можно переименовать")

print(f"\nВсего найдено {len(all_renames)} функций для переименования")

with open('/workspace/gta2_project/docs/AUTO_RENAMES.md', 'w') as f:
    f.write("# Автоматические переименования функций\n\n")
    for old, new, cls in all_renames:
        f.write(f"- `{cls}::{old}` → `{new}`\n")

print("Список сохранен в docs/AUTO_RENAMES.md")
