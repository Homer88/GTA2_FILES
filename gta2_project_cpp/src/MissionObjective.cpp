#include "gta2/MissionObjective.h"
#include <cstring>
#include <iostream>

namespace gta2 {

// Вспомогательная функция для доступа к элементам массива через char-буфер
// Примечание: точная структура элемента требует уточнения по дизассемблеру
// Используем предположительный размер 14 байт на элемент (302 / 22 ≈ 13.7)
MissionObjective::ObjectiveEntry& MissionObjective::getObjective(int index) {
    if (index < 0 || index >= MAX_OBJECTIVES) {
        static ObjectiveEntry dummy{};
        return dummy;
    }
    // Вычисляем смещение в массиве gap4
    size_t offset = index * ENTRY_SIZE;
    if (offset + sizeof(ObjectiveEntry) > sizeof(gap4)) {
        static ObjectiveEntry dummy{};
        return dummy;
    }
    return reinterpret_cast<ObjectiveEntry*>(gap4)[index];
}

const MissionObjective::ObjectiveEntry& MissionObjective::getObjective(int index) const {
    if (index < 0 || index >= MAX_OBJECTIVES) {
        static const ObjectiveEntry dummy{};
        return dummy;
    }
    size_t offset = index * ENTRY_SIZE;
    if (offset + sizeof(ObjectiveEntry) > sizeof(gap4)) {
        static const ObjectiveEntry dummy{};
        return dummy;
    }
    return reinterpret_cast<const ObjectiveEntry*>(gap4)[index];
}

void MissionObjective::init() {
    // sub_4768C0: Инициализация
    flags = 0;
    objectivesCount = 0;
    field_213 = 0;
    // Очищаем массив данных целей
    std::memset(gap4, 0, sizeof(gap4));
    // Очищаем gap
    std::memset(gap133, 0, sizeof(gap133));
}

void MissionObjective::setObjectiveType(int index, int32_t typeId) {
    // sub_4C4EA0: Установка типа условия
    if (index < 0 || index >= MAX_OBJECTIVES) {
        return;
    }
    
    ObjectiveEntry& entry = getObjective(index);
    entry.setTypeId(static_cast<int16_t>(typeId));
    // Сбрасываем состояние и счётчик при смене типа
    entry.setState(0);
    entry.setCounter(0);
}

void MissionObjective::resetObjective(int index) {
    // sub_4C4EE0: Сброс конкретной цели
    if (index < 0 || index >= MAX_OBJECTIVES) {
        return;
    }

    ObjectiveEntry& entry = getObjective(index);
    entry.setId(-1);
    entry.setTypeId(-1);
    entry.setParam1(0);
    entry.setParam2(0);
    entry.setState(0);
    entry.setCounter(0);
    entry.setFlags(0);
}

void MissionObjective::resetAllObjectives() {
    // sub_4C4F30: Сброс всех целей
    flags = 0;
    objectivesCount = 0;
    
    for (int i = 0; i < MAX_OBJECTIVES; ++i) {
        resetObjective(i);
    }
    
    field_213 = 0;
}

int MissionObjective::addObjective(int32_t typeId, int32_t param1, int32_t param2) {
    // sub_4C4FE0: Добавление новой цели
    // Логика: найти первый свободный слот (где state == 0 и counter == 0)
    
    for (int i = 0; i < MAX_OBJECTIVES; ++i) {
        ObjectiveEntry& entry = getObjective(i);
        
        // Проверка на свободный слот
        if (entry.getState() == 0 && entry.getCounter() == 0) {
            entry.setId(-1);
            entry.setTypeId(static_cast<int16_t>(typeId));
            entry.setParam1(static_cast<int16_t>(param1));
            entry.setParam2(static_cast<int16_t>(param2));
            entry.setState(1); // Активно
            entry.setCounter(0);
            entry.setFlags(0);
            
            // Обновляем счётчик активных целей
            if (objectivesCount < MAX_OBJECTIVES) {
                objectivesCount++;
            }
            
            return i;
        }
    }
    
    // Нет свободных мест
    return -1;
}

bool MissionObjective::checkObjective(int index) {
    // Проверка выполнения условия
    // В оригинале здесь было 6 типов проверок в зависимости от typeId
    if (index < 0 || index >= MAX_OBJECTIVES) {
        return false;
    }

    const ObjectiveEntry& entry = getObjective(index);
    
    // Если тип не установлен, условие не может быть выполнено
    if (entry.getTypeId() <= 0) {
        return false;
    }

    // Эмуляция логики проверки в зависимости от типа
    switch (entry.getTypeId()) {
        case 1:
            // Проверка по параметру 1 (например, количество убитых)
            return (entry.getCounter() >= entry.getParam1());
        case 2:
            // Проверка наличия объекта (параметр 1 - ID объекта)
            return (entry.getState() == 2); 
        case 3:
            // Проверка времени или дистанции
            return (entry.getCounter() >= entry.getParam2());
        case 4:
            // Логическое ИЛИ условий
            return (entry.getState() != 0);
        case 5:
            // Специфичное условие (например, зона)
            return (entry.getParam1() == entry.getParam2()); 
        case 6:
            // Флаг завершения
            return (entry.getState() == 3);
        default:
            // Неизвестный тип, считаем невыполненным
            return false;
    }
}

} // namespace gta2
