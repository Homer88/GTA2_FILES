/**
 * @file car_system_manager.h
 * @brief Главный менеджер системы автомобилей (пул активных машин)
 * 
 * Анализ на основе gta2.exe.asm:
 * - Глобальный экземпляр: gCarSystemManager по адресу 0x005E487C
 * - Конструктор: CarSystemManager__CarSystemManager (0x00428FA0)
 * - Деструктор: CarSystemManager__CarSystemManager_des (0x00429250)
 * - Размер: 0xD264 (53860 байт) - крупный менеджер с пулом объектов
 * 
 * Старое имя: gVector3D (ошибочное, использовалось как заглушка)
 * Старое имя функции: S2__S2 (ошибочное, это CarSystemManager__CarSystemManager)
 * Реальное назначение: Менеджер активных автомобилей в игре (физический мир машин)
 */

#ifndef GTA2_ENTITIES_CAR_SYSTEM_MANAGER_H
#define GTA2_ENTITIES_CAR_SYSTEM_MANAGER_H

#include <cstdint>
#include <cstddef>

// Forward declarations
struct Car;
struct CarsPrefabs;

// Максимальное количество машин в системе (предположительно)
#define CAR_SYSTEM_MAX_CARS 256

/**
 * @class CarSystemManager
 * @brief Главный менеджер системы автомобилей
 * 
 * Эта структура управляет всеми активными автомобилями в игре:
 * - Спавн и удаление машин
 * - Обновление физики и состояния
 * - Управление трафиком
 * - Взаимодействие с игроком и пешеходами
 * 
 * Размер: 0xD264 (53860 байт)
 * 
 * Известные методы:
 * - SpawnCar / ActualSpawnCar - спавн автомобиля
 * - GetCar - получение машины по индексу
 * - AddCarToSystem - добавление машины в систему
 * - SelectTraffic - выбор типа трафика
 * - PrepareArray - подготовка массива машин
 */
struct CarSystemManager {
    // === Вероятная структура (требует уточнения по смещениям) ===
    
    /* 0x0000 */ void* vtable;              // Таблица виртуальных методов
    /* 0x0004 */ Car** carsPool;            // Пул указателей на автомобили (массив)
    /* 0x0008 */ uint32_t maxCars;          // Максимальное количество машин в пуле
    /* 0x000C */ uint32_t activeCarsCount;  // Количество активных машин
    /* 0x0010 */ CarsPrefabs* prefabs;      // Ссылка на менеджер префабов
    /* 0x0014 */ void* freeListHead;        // Голова списка свободных слотов
    /* 0x0018 */ uint32_t flags;            // Флаги состояния менеджера
    /* 0x001C */ uint32_t trafficDensity;   // Плотность трафика
    /* 0x0020 */ float spawnRadius;         // Радиус спавна машин вокруг игрока
    /* 0x0024 */ float despawnRadius;       // Радиус удаления машин
    /* 0x0028 */ uint32_t frameCounter;     // Счётчик кадров для таймеров
    /* 0x002C */ void* collisionData;       // Данные коллизий
    // ... множество других полей до общего размера 0xD264
    
    // Массив для внутренних данных (до заполнения полной структуры)
    /* 0x0030 */ uint8_t reserved[0xD264 - 0x30];
    
    // === Методы ===
    
    /**
     * @brief Конструктор CarSystemManager
     * @address 0x00428FA0 (CarSystemManager__CarSystemManager)
     */
    CarSystemManager();
    
    /**
     * @brief Деструктор CarSystemManager
     * @address 0x00429250 (CarSystemManager__CarSystemManager_des)
     */
    ~CarSystemManager();
    
    /**
     * @brief Спавн автомобиля
     * @address 0x00426AF0 (CarSystemManager__SpawnCar)
     * @param type Тип автомобиля
     * @param x Координата X
     * @param y Координата Y
     * @param z Координата Z
     * @return Указатель на созданную машину или nullptr
     */
    Car* SpawnCar(uint32_t type, float x, float y, float z);
    
    /**
     * @brief Внутренний метод фактического спавна
     * @address 0x00426B10 (CarSystemManager__ActualSpawnCar)
     */
    Car* ActualSpawnCar(uint32_t type, float x, float y, float z);
    
    /**
     * @brief Получение машины по индексу
     * @address 0x004BCA00 (CarSystemManager__GetCar)
     * @param index Индекс машины в пуле
     * @return Указатель на машину или nullptr
     */
    Car* GetCar(uint32_t index);
    
    /**
     * @brief Добавление машины в систему
     * @address 0x00401C5C (CarSystemManager__AddCarToSystem)
     * @param car Указатель на машину
     */
    void AddCarToSystem(Car* car);
    
    /**
     * @brief Выбор типа трафика
     * @address 0x00420B60 (CarSystemManager__SelectTraffic)
     */
    uint32_t SelectTraffic(uint32_t areaType);
    
    /**
     * @brief Подготовка массива машин
     * @address 0x00447CB0 (CarSystemManager__PrepareArray)
     */
    void PrepareArray();
    
    /**
     * @brief Ограничение значений
     * @address 0x00401C30 (CarSystemManager__ClampValues)
     */
    void ClampValues(float* value, float min, float max);
    
    /**
     * @brief Установка индекса менеджера по умолчанию
     * @address 0x00426A70 (CarSystemManager__SetIndexDefautCarManager)
     */
    void SetIndexDefautCarManager(uint32_t index);
    
    /**
     * @brief Проверка на больше
     * @address 0x00426A90 (CarSystemManager__greater_than)
     */
    bool greater_than(uint32_t a, uint32_t b);
    
    /**
     * @brief Проверка на меньше или равно
     * @address 0x00426AE0 (CarSystemManager__less_or_equal)
     */
    bool less_or_equal(uint32_t a, uint32_t b);
    
    /**
     * @brief Проверка на неравенство
     * @address 0x0041E440 (CarSystemManager__NotEqual)
     */
    bool NotEqual(uint32_t a, uint32_t b);
    
    /**
     * @brief Проверка на меньше
     * @address 0x0041E430 (CarSystemManager__less_than)
     */
    bool less_than(uint32_t a, uint32_t b);
    
    // === Внутренние методы (требуют анализа) ===
    
    void sub_401C60();
    void sub_420A10();
    void sub_420C00();
    void sub_420C40();
    void sub_420CE0();
    void sub_4212D0();
    void sub_421960();
    void sub_421970();
    void sub_424980();
    void sub_424BD0();
    void sub_424E70();
    void sub_426A80();
    void sub_426AA0();
    void sub_426E40();
    void sub_427D60();
    void sub_428540();
    void sub_428EC0();
    void sub_428F70();
    void sub_42A120();
    void sub_42A4C0();
    void sub_447D30();
    void sub_4764A0();
    void sub_476610();
    void sub_476630();
    void sub_476640();
    void sub_476650();
    void sub_4C39F0();
};

// Глобальный экземпляр
extern CarSystemManager* gCarSystemManager;

// Проверка размера структуры
static_assert(sizeof(CarSystemManager) == 0xD264, "CarSystemManager size must be 0xD264 (53860 bytes)");

#endif // GTA2_ENTITIES_CAR_SYSTEM_MANAGER_H
