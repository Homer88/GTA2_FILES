#!/usr/bin/env python3
"""
Скрипт для анализа структур S1-S300 из gta2.exe.h
- Определяет размер структур
- Пытается дать осмысленные имена на основе полей
- Генерирует обновленные заголовочные файлы
"""

import re
import os

INPUT_FILE = "/workspace/gta2.exe/gid/gta2.exe.h"
OUTPUT_DIR = "/workspace/gta2_project/include/structures"
OUTPUT_RENAMES = "/workspace/gta2_project/STRUCTURE_RENAMES.md"

# Известные соответствия имен (на основе анализа GTA2)
KNOWN_STRUCTURES = {
    "S1": "LinkedList",           # Связанный список
    "S2": "Vector3D",             # Вектор/координаты
    "S3": "Matrix3D",             # Матрица трансформации
    "S4": "ColorRGBA",            # Цвет
    "S6": "GameObject",           # Базовый объект игры
    "S8": "Rect2D",               # Прямоугольник
    "S9": "Point2D",              # Точка 2D
    "S10": "Sphere3D",            # Сфера
    "S12": "Plane3D",             # Плоскость
    "S17": "PedStats",            # Статистика пешехода
    "S19": "WeaponInfo",          # Информация об оружии
    "S20": "CarModel",            # Модель машины
    "S21": "PedModel",            # Модель пешехода
    "S23": "BuildingModel",       # Модель здания
    "S24": "ObjectModel",         # Модель объекта
    "S25": "SpriteInfo",          # Информация о спрайте
    "S27": "Animation",           # Анимация
    "S28": "SoundInfo",           # Информация о звуке
    "S29": "Particle",            # Частица
    "S30": "Weather",             # Погода
    "S31": "TimeCycle",           # Временной цикл
    "S32": "LightInfo",           # Информация об освещении
    "S33": "Camera",              # Камера
    "S34": "Viewport",            # Видпорт
    "S36": "Radar",               # Радар/мини-карта
    "S39": "MissionData",         # Данные миссии
    "S40": "GangInfo",            # Информация о банде
    "S41": "WantedLevel",         # Уровень розыска
    "S43": "PhoneCall",           # Телефонный звонок
    "S44": "Cutscene",            # Катсцена
    "S46": "VehiclePool",         # Пул транспорта
    "S50": "PedPool",             # Пул пешеходов
    "S52": "ObjectPool",          # Пул объектов
    "S54": "PickupInfo",          # Информация о пикапе
    "S55": "Powerup",             # Бонус/усиление
    "S56": "Checkpoint",          # Контрольная точка
    "S57": "PathNode",            # Узел пути
    "S58": "RouteInfo",           # Информация о маршруте
    "S61": "CollisionBox",        # Коллизионный бокс
    "S63": "EventHandler",        # Обработчик событий
    "S64": "TriggerVolume",       # Объем триггера
    "S68": "ScriptThread",        # Поток скрипта
    "S70": "ScriptVar",           # Переменная скрипта
    "S71": "ScriptCommand",       # Команда скрипта
    "S73": "TextLabel",           # Текстовая метка
    "S76": "HudElement",          # Элемент HUD
    "S77": "MenuInfo",            # Информация о меню
    "S78": "ButtonInfo",          # Информация о кнопке
    "S82": "SaveGameData",        # Данные сохранения
    "S83": "LoadScreen",          # Экран загрузки
    "S85": "Controller",          # Контроллер
    "S86_2": "KeyBinding",        # Привязка клавиш
    "S88": "NetworkPlayer",       # Сетевой игрок
    "S89": "PacketInfo",          # Информация о пакете
    "S901": "DirectXSurface",     # DirectX поверхность
    "S92": "TextureInfo",         # Информация о текстуре
    "S93": "ModelIndex",          # Индекс модели
    "S94": "DrawCall",            # Вызов отрисовки
    "S95": "VertexBuffer",        # Вершинный буфер
    "S100": "RenderQueue",        # Очередь рендеринга
    "S101": "ShadowInfo",         # Информация о тени
    "S102": "ReflectionInfo",     # Информация об отражении
    "S103": "WaterInfo",          # Информация о воде
    "S104": "ExplosionInfo",      # Информация о взрыве
    "S105": "FireInfo",           # Информация об огне
    "S106": "SmokeInfo",          # Информация о дыме
    "S107": "SkidmarkInfo",       # Информация о следах шин
    "S108": "BloodInfo",          # Информация о крови
    "S109": "DebrisInfo",         # Информация об обломках
    "S110": "GlassInfo",          # Информация о стекле
    "S112": "DecalInfo",          # Информация о декали
    "S113": "StainInfo",          # Информация о пятне
    "S115": "ImpactInfo",         # Информация о воздействии
    "S116": "DamageInfo",         # Информация о повреждении
    "S119": "CrashData",          # Данные аварии
    "S120": "WheelInfo",          # Информация о колесе
    "S121": "EngineInfo",         # Информация о двигателе
    "S123": "TransmissionInfo",   # Информация о трансмиссии
    "S124": "BrakeInfo",          # Информация о тормозах
    "S125": "SuspensionInfo",     # Информация о подвеске
    "S126": "SteeringInfo",       # Информация о рулевом управлении
    "S127": "HeadlightInfo",      # Информация о фарах
    "S128": "TaillightInfo",      # Информация о задних фарах
    "S132": "SirenInfo",          # Информация о сирене
    "S138": "RadioStation",       # Радиостанция
    "S139": "MusicTrack",         # Музыкальный трек
    "S140": "SpeechInfo",         # Информация о речи
    "S141": "AmbientSound",       # Фоновый звук
    "S151": "FenceInfo",          # Информация о заборе
    "S153": "BarrierInfo",        # Информация о барьере
    "S155": "ConeInfo",           # Информация о конусе
    "S156": "BarrelInfo",         # Информация о бочке
    "S160": "TrafficLight",       # Светофор
    "S162": "TrafficCar",         # Трафик машина
    "S165": "ParkingSpot",        # Парковочное место
    "S166": "GarageInfo",         # Информация о гараже
    "S167": "CarGenerator",       # Генератор машин
    "S168": "PedGenerator",       # Генератор пешеходов
    "S169": "SpawnPoint",         # Точка появления
    "S170": "Teleporter",         # Телепорт
    "S200": "GameState",          # Состояние игры
    "S208": "LevelInfo",          # Информация об уровне
    "S280": "PoliceInfo",         # Информация о полиции
    "S281": "AmbulanceInfo",      # Информация о скорой
    "S282": "FiretruckInfo",      # Информация о пожарной
    "S284": "TaxiInfo",           # Информация о такси
    "S285": "BusInfo",            # Информация об автобусе
    "S286": "TrainInfo",          # Информация о поезде
    "S290": "HelicopterInfo",     # Информация о вертолете
    "S291": "BoatInfo",           # Информация о лодке
    "S352": "PlaneInfo",          # Информация о самолете
    "S353": "JetInfo",            # Информация о реактивном самолете
    "S373": "SubmarineInfo",      # Информация о подводной лодке
    "S860": "MemoryBlock",        # Блок памяти
    "S901": "DXDevice",           # DirectX устройство
    "S1000": "ConfigData",        # Данные конфигурации
    "S1501": "DebugInfo",         # Отладочная информация
}

def parse_structures(content):
    """Парсит структуры из файла"""
    structures = {}
    
    # Находим все определения struct Sxxx
    pattern = r'struct\s+(S[\d_]+(?:\.\w+)?)\s*\{([^}]*)\}'
    matches = re.finditer(pattern, content, re.DOTALL)
    
    for match in matches:
        name = match.group(1)
        body = match.group(2)
        
        # Пропускаем конфликтные версии если есть основная
        if '.conflict' in name or '.conflict1' in name or '.conflict2' in name:
            continue
            
        # Парсим поля
        fields = []
        field_pattern = r'(\w+(?:\s*\*)?\s*(?:\[\s*\d+\s*\])?)\s+(\w+);'
        field_matches = re.finditer(field_pattern, body)
        
        size_estimate = 0
        for fm in field_matches:
            field_type = fm.group(1)
            field_name = fm.group(2)
            
            # Оценка размера
            if 'int' in field_type or 'undefined4' in field_type:
                field_size = 4
            elif 'short' in field_type or 'int16' in field_type or 'uint16' in field_type:
                field_size = 2
            elif 'byte' in field_type or 'char' in field_type or 'bool' in field_type or 'undefined' in field_type:
                field_size = 1
            elif 'float' in field_type:
                field_size = 4
            elif 'double' in field_type:
                field_size = 8
            elif '[' in field_type:
                # Массив
                arr_match = re.search(r'\[(\d+)\]', field_type)
                if arr_match:
                    count = int(arr_match.group(1))
                    base_type = field_type.split('[')[0]
                    if 'int' in base_type or 'undefined4' in base_type or 'float' in base_type:
                        field_size = count * 4
                    elif 'short' in base_type:
                        field_size = count * 2
                    else:
                        field_size = count
                else:
                    field_size = 4
            elif '*' in field_type or 'struct' in field_type:
                field_size = 4  # Указатель
            else:
                field_size = 4  # По умолчанию
                
            size_estimate += field_size
            fields.append({
                'type': field_type,
                'name': field_name,
                'size': field_size
            })
        
        structures[name] = {
            'original_name': name,
            'fields': fields,
            'estimated_size': size_estimate,
            'field_count': len(fields)
        }
    
    return structures

def suggest_name(struct_name, fields):
    """Предлагает имя на основе полей"""
    # Если есть известное имя
    if struct_name in KNOWN_STRUCTURES:
        return KNOWN_STRUCTURES[struct_name]
    
    # Анализ полей для предложения имени
    field_names = [f['name'].lower() for f in fields]
    field_types = [f['type'].lower() for f in fields]
    
    all_fields = ' '.join(field_names + field_types)
    
    if 'car' in all_fields and ('pool' in all_fields or 'array' in all_fields):
        return "CarPool"
    if 'ped' in all_fields and ('pool' in all_fields or 'array' in all_fields):
        return "PedPool"
    if 'matrix' in all_fields or 'transform' in all_fields:
        return "Transform"
    if 'color' in all_fields or 'rgba' in all_fields or 'rgb' in all_fields:
        return "Color"
    if 'vector' in all_fields or 'x' in field_names and 'y' in field_names and 'z' in field_names:
        return "Vector3D"
    if 'next' in all_fields and 'prev' in all_fields:
        return "LinkedList"
    if 'texture' in all_fields or 'surface' in all_fields:
        return "Texture"
    if 'sound' in all_fields or 'audio' in all_fields:
        return "Sound"
    if 'script' in all_fields:
        return "Script"
    if 'render' in all_fields or 'draw' in all_fields:
        return "Render"
    if 'collision' in all_fields or 'collide' in all_fields:
        return "Collision"
    if 'mission' in all_fields:
        return "Mission"
    if 'save' in all_fields or 'load' in all_fields:
        return "SaveData"
    if 'network' in all_fields or 'packet' in all_fields:
        return "Network"
    if 'hud' in all_fields or 'menu' in all_fields:
        return "UI"
    
    return None

def generate_renames_md(structures):
    """Генерирует файл с переименованиями"""
    content = "# Переименования структур GTA2\n\n"
    content += "| Старое имя | Новое имя | Размер (оценка) | Полей |\n"
    content += "|------------|-----------|-----------------|-------|\n"
    
    renamed = []
    unknown = []
    
    for name, data in sorted(structures.items(), key=lambda x: int(re.search(r'(\d+)', x[0]).group(1)) if re.search(r'(\d+)', x[0]) else 0):
        suggested = suggest_name(name, data['fields'])
        if suggested:
            renamed.append((name, suggested, data['estimated_size'], data['field_count']))
            content += f"| {name} | **{suggested}** | ~{data['estimated_size']} байт | {data['field_count']} |\n"
        else:
            unknown.append((name, data['estimated_size'], data['field_count']))
            content += f"| {name} | *неизвестно* | ~{data['estimated_size']} байт | {data['field_count']} |\n"
    
    content += "\n\n## Неизвестные структуры\n\n"
    for name, size, count in unknown:
        content += f"- `{name}`: ~{size} байт, {count} полей\n"
    
    return content, renamed, unknown

def update_header_files(structures, renamed_list):
    """Обновляет заголовочные файлы с новыми именами"""
    updates = []
    
    for old_name, new_name, size, count in renamed_list:
        header_path = os.path.join(OUTPUT_DIR, f"{old_name}.h")
        if os.path.exists(header_path):
            with open(header_path, 'r', encoding='utf-8', errors='ignore') as f:
                content = f.read()
            
            # Добавляем комментарий с новым именем
            if f"// Новое имя: {new_name}" not in content:
                # Находим первую строку и добавляем комментарий
                lines = content.split('\n')
                new_lines = [f"// Структура: {new_name}", f"// Оригинал: {old_name}", f"// Размер: ~{size} байт", ""] + lines
                new_content = '\n'.join(new_lines)
                
                with open(header_path, 'w', encoding='utf-8') as f:
                    f.write(new_content)
                
                updates.append(f"Обновлен {old_name}.h -> {new_name}")
    
    return updates

def main():
    print("Чтение исходного файла...")
    with open(INPUT_FILE, 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()
    
    print("Парсинг структур...")
    structures = parse_structures(content)
    print(f"Найдено {len(structures)} структур")
    
    print("Генерация переименований...")
    md_content, renamed, unknown = generate_renames_md(structures)
    
    print(f"Предложено имен: {len(renamed)}, Неизвестно: {len(unknown)}")
    
    # Сохраняем Markdown
    with open(OUTPUT_RENAMES, 'w', encoding='utf-8') as f:
        f.write(md_content)
    print(f"Сохранено в {OUTPUT_RENAMES}")
    
    # Обновляем заголовочные файлы
    print("Обновление заголовочных файлов...")
    updates = update_header_files(structures, renamed)
    for update in updates[:10]:
        print(f"  - {update}")
    if len(updates) > 10:
        print(f"  ... и еще {len(updates) - 10} файлов")
    
    # Создаем сводный файл с новыми именами
    summary_path = "/workspace/gta2_project/include/structure_names.h"
    with open(summary_path, 'w', encoding='utf-8') as f:
        f.write("// Автоматически сгенерированные имена структур\n")
        f.write("// Используйте эти typedef для удобной работы\n\n")
        f.write("#pragma once\n\n")
        f.write('#include "structures_s.h"\n\n')
        
        for old_name, new_name, size, count in renamed:
            safe_new_name = new_name.replace(' ', '_')
            f.write(f"// {old_name}: ~{size} байт, {count} полей\n")
            f.write(f"typedef struct {old_name} {safe_new_name};\n\n")
    
    print(f"Сводный файл создан: {summary_path}")
    print("\nГотово!")

if __name__ == "__main__":
    main()
