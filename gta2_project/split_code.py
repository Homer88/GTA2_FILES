#!/usr/bin/env python3
"""
Скрипт для разбиения gta2.exe.c на модульные файлы по функциям
"""

import re
import os
from collections import defaultdict

INPUT_FILE = "/workspace/gta2.exe/gid/gta2.exe.c"
OUTPUT_DIR = "/workspace/gta2_project/src"

# Маппинг префиксов функций к папкам
MODULE_MAPPING = {
    'Game::': 'game',
    'Player::': 'player',
    'Car::': 'car',
    'Ped::': 'ped',
    'PedManager::': 'ped',
    'MissionManager::': 'mission',
    'Replay::': 'replay',
    'Registry::': 'registry',
    'FileMgr::': 'filemgr',
    'DMAudio::': 'sound',
    'AudioManager::': 'sound',
    'SpriteS1::': 'sprite',
    'cNetwork::': 'network',
    'JuncIds::': 'object',
    'CarsPrefabs::': 'car',
    'CarSystemManager::': 'car',
    'CameraOrPhysics::': 'render',
    'GameObject::': 'object',
    'AutoClass': 'game',
    'S1::': 'game',
    'S3::': 'game',
    'S16::': 'game',
    'S17::': 'game',
    'S38::': 'sprite',
    'S46::': 'game',
    'S48::': 'ped',
    'S49::': 'ped',
    'S63::': 'game',
    'S91::': 'object',
    'S92::': 'object',
    'S110::': 'game',
    'S131::': 'render',
    'S154::': 'sound',
    'S157::': 'sound',
    'S159::': 'network',
    'S162::': 'ui',
    'S165::': 'ui',
    'S169::': 'ped',
    'Style::': 'filemgr',
    'Weapon::': 'weapon',
    'General::': 'game',
    'Turrel::': 'weapon',
}

def get_module_name(func_name):
    """Определяет модуль по имени функции"""
    for prefix, module in MODULE_MAPPING.items():
        if func_name.startswith(prefix) or f'::{prefix}' in func_name:
            return module
    
    # Определяем по ключевым словам в имени
    func_lower = func_name.lower()
    if 'ped' in func_lower:
        return 'ped'
    elif 'car' in func_lower:
        return 'car'
    elif 'player' in func_lower:
        return 'player'
    elif 'game' in func_lower:
        return 'game'
    elif 'mission' in func_lower:
        return 'mission'
    elif 'replay' in func_lower:
        return 'replay'
    elif 'registry' in func_lower or 'reg' in func_lower:
        return 'registry'
    elif 'file' in func_lower or 'fread' in func_lower:
        return 'filemgr'
    elif 'audio' in func_lower or 'sound' in func_lower or 'dmaudio' in func_lower:
        return 'sound'
    elif 'render' in func_lower or 'camera' in func_lower or 'sprite' in func_lower:
        return 'render'
    elif 'network' in func_lower or 'net' in func_lower:
        return 'network'
    elif 'weapon' in func_lower or 'gun' in func_lower or 'turrel' in func_lower:
        return 'weapon'
    elif 'ui' in func_lower or 'menu' in func_lower or 'window' in func_lower:
        return 'ui'
    elif 'object' in func_lower or 'gameObject' in func_lower:
        return 'object'
    elif 'gang' in func_lower:
        return 'gang'
    elif 'main' in func_lower or 'winmain' in func_lower:
        return 'main'
    
    return 'game'  # По умолчанию

def parse_functions(file_path):
    """Парсит файл и извлекает функции с их кодом"""
    with open(file_path, 'r', encoding='utf-8') as f:
        content = f.read()
    
    # Разбиваем на строки
    lines = content.split('\n')
    
    functions = []
    current_func = None
    current_lines = []
    brace_count = 0
    in_function = False
    
    # Regex для определения начала функции
    func_pattern = re.compile(
        r'^(?P<return_type>\w+(?:\s*\*|\s+::\s*\w+)?)\s*'
        r'(?:__thiscall|__fastcall|__cdecl)?\s*'
        r'(?P<name>[\w:]+(?:FUN_|[A-Z]\w*)?)\s*'
        r'\([^)]*\)\s*(?:{|$)'
    )
    
    for i, line in enumerate(lines):
        # Проверяем начало функции
        match = func_pattern.match(line.strip())
        
        if match and not in_function:
            # Сохраняем предыдущую функцию если была
            if current_func:
                functions.append((current_func, current_lines))
            
            current_func = match.group('name')
            current_lines = [line]
            brace_count = line.count('{') - line.count('}')
            in_function = brace_count > 0
            
            # Если функция в одну строку или нет открывающей скобки
            if brace_count == 0 and '{' not in line:
                # Ищем открывающую скобку в следующих строках
                in_function = True
        elif in_function:
            current_lines.append(line)
            brace_count += line.count('{') - line.count('}')
            
            if brace_count <= 0:
                functions.append((current_func, current_lines))
                current_func = None
                current_lines = []
                in_function = False
                brace_count = 0
    
    # Добавляем последнюю функцию
    if current_func:
        functions.append((current_func, current_lines))
    
    return functions

def write_module_files(functions, output_dir):
    """Записывает функции в соответствующие файлы модулей"""
    module_functions = defaultdict(list)
    
    for func_name, func_lines in functions:
        module = get_module_name(func_name)
        module_functions[module].append((func_name, func_lines))
    
    # Создаем файлы для каждого модуля
    for module, funcs in module_functions.items():
        module_path = os.path.join(output_dir, module, f'{module}.c')
        
        with open(module_path, 'w', encoding='utf-8') as f:
            f.write(f'// Module: {module}\n')
            f.write(f'// Generated from gta2.exe.c\n')
            f.write(f'// Functions count: {len(funcs)}\n\n')
            f.write('#include "../../include/common.h"\n\n')
            
            for func_name, func_lines in funcs:
                f.write('\n'.join(func_lines))
                f.write('\n\n')
        
        print(f"Created {module_path} with {len(funcs)} functions")

def main():
    print(f"Parsing {INPUT_FILE}...")
    functions = parse_functions(INPUT_FILE)
    print(f"Found {len(functions)} functions")
    
    print(f"Writing module files to {OUTPUT_DIR}...")
    write_module_files(functions, OUTPUT_DIR)
    
    print("Done!")

if __name__ == '__main__':
    main()
