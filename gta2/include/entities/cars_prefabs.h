/**
 * @file cars_prefabs.h
 * @brief Структура префабов автомобилей (пул шаблонов машин)
 * 
 * Анализ на основе gta2.exe.asm:
 * - Глобальный экземпляр: gCarsPrefabs по адресу 0x005E4874
 * - Конструктор: CarsPrefabs__CarsPrefabs (0x004254F0)
 * - Деструктор: CarsPrefabs__CarsPrefabs_des (0x00426AA0)
 * - Размер: определяется через анализ конструктора
 * 
 * Старое имя: S2 (ошибочное, использовалось как заглушка)
 * Реальное назначение: Менеджер префабов/шаблонов автомобилей
 */

#ifndef GTA2_ENTITIES_CARS_PREFABS_H
#define GTA2_ENTITIES_CARS_PREFABS_H

#include <cstdint>
#include <cstddef>

// Forward declarations
struct Car;
struct CarSystemManager;

/**
 * @class CarsPrefabs
 * @brief Менеджер префабов автомобилей - хранит шаблоны и настройки для спавна машин
 * 
 * Эта структура управляет коллекцией префабов автомобилей, которые используются
 * системой для создания экземпляров машин в игре.
 * 
 * Известные методы:
 * - GetCar(index) - получение префаба по индексу
 * - InsertCarAtFront - добавление префаба в начало списка
 * - GetCarsCount() - получение количества префабов
 * - sub_420F20, sub_420F30 - внутренние методы инициализации
 */
struct CarsPrefabs {
    // === Вероятная структура (требует уточнения по смещениям) ===
    
    /* 0x00 */ void* vtable;           // Таблица виртуальных методов
    /* 0x04 */ CarSystemManager* carSysManager; // Ссылка на менеджер системы машин
    /* 0x08 */ uint32_t count;         // Количество префабов в коллекции
    /* 0x0C */ uint32_t capacity;      // Вместимость массива префабов
    /* 0x10 */ void** prefabsArray;    // Массив указателей на префабы машин
    /* 0x14 */ void* head;             // Голова связанного списка (если используется)
    /* 0x18 */ void* tail;             // Хвост связанного списка
    /* 0x1C */ uint32_t flags;         // Флаги состояния менеджера
    
    // === Методы ===
    
    /**
     * @brief Конструктор CarsPrefabs
     * @address 0x004254F0
     */
    CarsPrefabs();
    
    /**
     * @brief Деструктор CarsPrefabs
     * @address 0x00426AA0
     */
    ~CarsPrefabs();
    
    /**
     * @brief Получение префаба автомобиля по индексу
     * @address 0x00420F04 (CarsPrefabs__GetCar)
     * @param index Индекс префаба в массиве
     * @return Указатель на префаб или nullptr
     */
    void* GetCar(uint32_t index);
    
    /**
     * @brief Добавление префаба в начало списка
     * @address 0x00401C7B (CarsPrefabs__InsertCarAtFront)
     * @param prefab Указатель на префаб для добавления
     */
    void InsertCarAtFront(void* prefab);
    
    /**
     * @brief Получение количества префабов
     * @address 0x00427D88 (CarsPrefabs__GetCarsCount)
     * @return Количество префабов
     */
    uint32_t GetCarsCount() const;
    
    /**
     * @brief Внутренний метод инициализации #1
     * @address 0x00420F20
     */
    void sub_420F20();
    
    /**
     * @brief Внутренний метод инициализации #2
     * @address 0x00420F30
     */
    void sub_420F30();
    
    /**
     * @brief Метод работы с префабами #1
     * @address 0x00425400
     */
    void sub_425400();
    
    /**
     * @brief Метод работы с префабами #2
     * @address 0x00425480
     */
    void sub_425480();
    
    /**
     * @brief Метод работы с префабами #3
     * @address 0x004254A0
     */
    void sub_4254A0();
};

// Глобальный экземпляр
extern CarsPrefabs* gCarsPrefabs;

// Проверка размера структуры (требует уточнения после полного анализа)
// static_assert(sizeof(CarsPrefabs) == 0x??, "CarsPrefabs size mismatch");

#endif // GTA2_ENTITIES_CARS_PREFABS_H
