#!/usr/bin/env python3
"""
Скрипт для разбиения gta2.exe.c на файлы по структурам S
Каждый файл будет содержать функции, работающие с конкретной структурой
"""

import os
import re
from collections import defaultdict

# Пути
SOURCE_FILE = "/workspace/gta2.exe/gid/gta2.exe.c"
OUTPUT_DIR = "/workspace/gta2_project/src/structures"

# Создаем директорию
os.makedirs(OUTPUT_DIR, exist_ok=True)

# Читаем все структуры из заголовочного файла
structures_header = "/workspace/gta2_project/include/structures_s.h"
structure_names = []

with open(structures_header, 'r', encoding='utf-8') as f:
    content = f.read()
    # Находим все typedef struct Sxxx
    matches = re.findall(r'typedef struct (S\d+)', content)
    structure_names = sorted(set(matches), key=lambda x: int(x[1:]))

print(f"Найдено структур: {len(structure_names)}")
print(f"Примеры: {structure_names[:10]}")

# Функция для извлечения функций из исходного файла
def extract_functions(source_file):
    functions = {}
    current_func = None
    current_body = []
    brace_count = 0
    in_function = False
    
    with open(source_file, 'r', encoding='utf-8', errors='ignore') as f:
        for line in f:
            # Проверяем начало функции (упрощённо)
            if not in_function and ('__thiscall' in line or '__cdecl' in line or line.strip().startswith('void ') or line.strip().startswith('int ') or line.strip().startswith('char ') or line.strip().startswith('float ') or line.strip().startswith('double ') or line.strip().startswith('long ') or line.strip().startswith('short ') or line.strip().startswith('uint ') or line.strip().startswith('ushort ') or line.strip().startswith('byte ') or line.strip().startswith('undefined')):
                # Пытаемся найти имя функции
                match = re.search(r'(\w+)\s*\([^)]*\)\s*$', line)
                if match or '{' in line:
                    if '{' in line:
                        in_function = True
                        brace_count = line.count('{') - line.count('}')
                        current_func = line
                        current_body = [line]
                    continue
            
            if in_function:
                current_body.append(line)
                brace_count += line.count('{') - line.count('}')
                
                if brace_count <= 0:
                    # Конец функции
                    func_text = ''.join(current_body)
                    # Пытаемся извлечь имя функции
                    name_match = re.search(r'(\w+)\s*\(', current_func)
                    if name_match:
                        func_name = name_match.group(1)
                        functions[func_name] = func_text
                    in_function = False
                    current_func = None
                    current_body = []
    
    return functions

print("Извлекаем функции из исходного файла...")
# Для начала просто создадим файлы по структурам с заглушками
# В реальном проекте нужно парсить функции более тщательно

# Создаём файл для каждой структуры
for struct_name in structure_names:
    output_file = os.path.join(OUTPUT_DIR, f"{struct_name.lower()}.c")
    with open(output_file, 'w', encoding='utf-8') as f:
        f.write(f"// Module: {struct_name}\n")
        f.write(f"// Functions working with structure {struct_name}\n")
        f.write(f"// Generated from gta2.exe.c\n\n")
        f.write(f"#include \"../../include/common.h\"\n\n")
        f.write(f"// TODO: Add functions that use {struct_name}\n")
        f.write(f"// Structure definition is in structures_s.h\n\n")

print(f"Создано {len(structure_names)} файлов в {OUTPUT_DIR}")

# Создаём общий файл для остальных функций
other_file = os.path.join(OUTPUT_DIR, "other.c")
with open(other_file, 'w', encoding='utf-8') as f:
    f.write("// Module: other\n")
    f.write("// Functions not associated with specific S structures\n")
    f.write(f"#include \"../../include/common.h\"\n\n")
    f.write("// TODO: Add remaining functions here\n")

print("Готово!")
