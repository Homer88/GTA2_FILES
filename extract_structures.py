import re
import os

# Путь к файлу gta2.exe.h
h_file = '/workspace/gta2.exe/ida_pro/gta2.exe.h'
output_dir = '/workspace/structures_dump'

# Создаем директорию для вывода
os.makedirs(output_dir, exist_ok=True)

# Читаем файл по частям (так как он большой)
structs = []
current_struct_name = None
current_struct_start = 0
brace_count = 0
in_struct = False
struct_content = []

with open(h_file, 'r', encoding='utf-8') as f:
    line_num = 0
    for line in f:
        line_num += 1
        
        # Проверяем начало структуры
        match = re.match(r'^struct ([A-Za-z_][A-Za-z0-9_]*)$', line.strip())
        if match and not in_struct:
            current_struct_name = match.group(1)
            current_struct_start = line_num
            in_struct = True
            brace_count = 0
            struct_content = [line]
            continue
        
        if in_struct:
            struct_content.append(line)
            # Считаем скобки
            brace_count += line.count('{') - line.count('}')
            
            # Если закрыли структуру
            if brace_count == 0 and '{' in ''.join(struct_content):
                # Вычисляем размер (примерно по количеству байт в полях)
                struct_text = ''.join(struct_content)
                
                # Сохраняем информацию о структуре
                structs.append({
                    'name': current_struct_name,
                    'start_line': current_struct_start,
                    'end_line': line_num,
                    'content': struct_text,
                    'field_count': len([l for l in struct_content if ';' in l and l.strip() and not l.strip().startswith('//')])
                })
                
                in_struct = False
                current_struct_name = None

print(f"Найдено структур: {len(structs)}")

# Сохраняем список структур с размерами полей
with open(os.path.join(output_dir, 'structures_list.txt'), 'w', encoding='utf-8') as f:
    f.write(f"Всего структур: {len(structs)}\n\n")
    f.write(f"{'Name':<50} {'Start':>10} {'End':>10} {'Fields':>10}\n")
    f.write("=" * 90 + "\n")
    
    for s in structs:
        f.write(f"{s['name']:<50} {s['start_line']:>10} {s['end_line']:>10} {s['field_count']:>10}\n")

print(f"Список структур сохранен в {output_dir}/structures_list.txt")

# Сохраняем первые 100 структур в отдельные файлы для примера
for i, s in enumerate(structs[:100]):
    safe_name = re.sub(r'[^\w]', '_', s['name'])
    with open(os.path.join(output_dir, f'{safe_name}.txt'), 'w', encoding='utf-8') as f:
        f.write(f"// Structure: {s['name']}\n")
        f.write(f"// Lines: {s['start_line']} - {s['end_line']}\n")
        f.write(f"// Fields: {s['field_count']}\n\n")
        f.write(s['content'])

print(f"Первые 100 структур сохранены в отдельные файлы")
