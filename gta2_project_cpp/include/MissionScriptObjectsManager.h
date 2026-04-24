#ifndef MISSION_SCRIPT_OBJECTS_MANAGER_H
#define MISSION_SCRIPT_OBJECTS_MANAGER_H

#include <cstdint>

// Forward declaration
class MissionScriptObject; // S28

/**
 * @brief Менеджер коллекции объектов миссии (S27)
 * Размер: 0x34C (844 байта)
 * 
 * Управляет коллекцией объектов MissionScriptObject (S28)
 * Координирует работу со скриптами и потоками выполнения
 */
class MissionScriptObjectsManager {
public:
    // === Поля структуры (размер 0x34C) ===
    uint8_t data[0x34C]; // Детальная структура полей требует уточнения
    
    // === Конструкторы и деструкторы ===
    
    /**
     * @brief Конструктор
     * Адрес: требуется уточнение по дампу
     */
    MissionScriptObjectsManager();
    
    /**
     * @brief Деструктор
     * Адрес: требуется уточнение по дампу
     */
    virtual ~MissionScriptObjectsManager();

    // === Методы управления объектами миссии ===
    
    /**
     * @brief Инициализация менеджера объектов
     * Адрес: требуется уточнение
     */
    virtual void Init();
    
    /**
     * @brief Добавление объекта в коллекцию
     * Адрес: требуется уточнение
     */
    virtual int AddObject(MissionScriptObject* obj);
    
    /**
     * @brief Удаление объекта из коллекции
     * Адрес: требуется уточнение
     */
    virtual void RemoveObject(MissionScriptObject* obj);
    
    /**
     * @brief Получение объекта по индексу
     * Адрес: требуется уточнение
     */
    virtual MissionScriptObject* GetObject(int index);
    
    /**
     * @brief Очистка всех объектов
     * Адрес: требуется уточнение
     */
    virtual void ClearAllObjects();

    // === Методы интеграции со структурой S28 ===
    
    /**
     * @brief Создание нового объекта миссии
     * Адрес: требуется уточнение
     */
    virtual MissionScriptObject* CreateMissionObject();
    
    /**
     * @brief Уничтожение объекта миссии
     * Адрес: требуется уточнение
     */
    virtual void DestroyMissionObject(MissionScriptObject* obj);
    
    /**
     * @brief Обновление всех объектов
     * Адрес: требуется уточнение
     */
    virtual void UpdateAllObjects();
    
    /**
     * @brief Сохранение всех объектов
     * Адрес: требуется уточнение
     */
    virtual void SaveAllObjects();
    
    /**
     * @brief Загрузка всех объектов
     * Адрес: требуется уточнение
     */
    virtual void LoadAllObjects();
};

#endif // MISSION_SCRIPT_OBJECTS_MANAGER_H
