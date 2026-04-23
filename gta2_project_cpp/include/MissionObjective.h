#ifndef GTA2_MISSION_OBJECTIVE_H
#define GTA2_MISSION_OBJECTIVE_H

#include <cstdint>
#include <cstddef>

namespace gta2 {

/**
 * @brief Структура условия/цели миссии (S25).
 * 
 * Размер: 532 байта (0x214).
 * Содержит массив условий выполнения миссий.
 * 
 * Layout:
 * 0x000: flags (1 byte)
 * 0x001-0x003: padding_01[3] (явный padding)
 * 0x004-0x131: gap4[302] - данные целей
 * 0x132: objectivesCount (1 byte)
 * 0x133-0x212: gap133[224]
 * 0x213: field_213 (1 byte)
 * 
 * Итого: 1 + 3 + 302 + 1 + 224 + 1 = 532 байта
 */
#pragma pack(push, 1)
struct MissionObjective {
    // Смещение 0x00
    uint8_t flags;
    
    // Явный padding 3 байта до 0x04
    uint8_t padding_01[3];
    
    // Смещение 0x04 - 0x131: Данные целей (302 байта)
    char gap4[302];

    // Смещение 0x132
    uint8_t objectivesCount;

    // Смещение 0x133 - 0x212: Резерв (224 байта)
    char gap133[224];

    // Смещение 0x213
    uint8_t field_213;

    // Статический размер для проверок
    static constexpr size_t SIZEOF = 532;
    
    // Вложенная структура для доступа к элементам (предположительная, packed для точного размера)
    // 302 байта / 22 элемента ≈ 13.72 байта на элемент
    // Компилятор выравнивает до 16 байт даже с pack(1) из-за int16_t
    // Используем только char-массив для точного соответствия
    struct ObjectiveEntry {
        char data[14];  // 14 байт сырых данных
        
        // Helper методы для доступа к полям
        int16_t getId() const { return *reinterpret_cast<const int16_t*>(&data[0]); }
        int16_t getTypeId() const { return *reinterpret_cast<const int16_t*>(&data[2]); }
        int16_t getParam1() const { return *reinterpret_cast<const int16_t*>(&data[4]); }
        int16_t getParam2() const { return *reinterpret_cast<const int16_t*>(&data[6]); }
        int8_t getState() const { return data[8]; }
        int8_t getCounter() const { return data[9]; }
        int8_t getFlags() const { return data[10]; }
        
        void setId(int16_t v) { *reinterpret_cast<int16_t*>(&data[0]) = v; }
        void setTypeId(int16_t v) { *reinterpret_cast<int16_t*>(&data[2]) = v; }
        void setParam1(int16_t v) { *reinterpret_cast<int16_t*>(&data[4]) = v; }
        void setParam2(int16_t v) { *reinterpret_cast<int16_t*>(&data[6]) = v; }
        void setState(int8_t v) { data[8] = v; }
        void setCounter(int8_t v) { data[9] = v; }
        void setFlags(int8_t v) { data[10] = v; }
    };
    
    static_assert(sizeof(ObjectiveEntry) == 14, "ObjectiveEntry must be 14 bytes");
    
    // Константы для методов (предположительные, требуют уточнения по дизассемблеру)
    static constexpr size_t MAX_OBJECTIVES = 21; // 302 / 14 = 21.57, максимум 21 полный элемент
    static constexpr size_t ENTRY_SIZE = 14;     // Размер структуры ObjectiveEntry

    // --- Методы ---

    /**
     * @brief Инициализация структуры (аналог sub_4768C0).
     * Сбрасывает флаги и счётчики.
     */
    void init();

    /**
     * @brief Установка типа условия для конкретной цели (аналог sub_4C4EA0).
     * @param index Индекс цели (0-21).
     * @param typeId ID типа условия.
     */
    void setObjectiveType(int index, int32_t typeId);

    /**
     * @brief Сброс конкретной цели (аналог sub_4C4EE0).
     * @param index Индекс цели.
     */
    void resetObjective(int index);

    /**
     * @brief Сброс всех целей (аналог sub_4C4F30).
     * Инициализирует весь массив условий.
     */
    void resetAllObjectives();

    /**
     * @brief Добавление новой цели (аналог sub_4C4FE0).
     * Сложная логика проверки и добавления условия.
     * @param typeId ID типа.
     * @param param1 Параметр 1.
     * @param param2 Параметр 2.
     * @return Индекс добавленной цели или -1 если ошибка.
     */
    int addObjective(int32_t typeId, int32_t param1, int32_t param2);

    /**
     * @brief Проверка выполнения условия.
     * Реализует логику 6 типов проверок.
     * @param index Индекс цели.
     * @return true если условие выполнено.
     */
    bool checkObjective(int index);

    /**
     * @brief Получение доступа к элементу массива целей.
     * @param index Индекс.
     * @return Ссылка на ObjectiveEntry.
     */
    ObjectiveEntry& getObjective(int index);
    const ObjectiveEntry& getObjective(int index) const;

    /**
     * @brief Получение количества активных целей.
     */
    uint8_t getObjectivesCount() const { return objectivesCount; }
};

// Проверка размера структуры во время компиляции
static_assert(sizeof(MissionObjective) == 532, "MissionObjective must be 532 bytes");

} // namespace gta2

#endif // GTA2_MISSION_OBJECTIVE_H
