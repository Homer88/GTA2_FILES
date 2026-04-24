#ifndef MISSION_SCRIPT_OBJECT_H
#define MISSION_SCRIPT_OBJECT_H

#include <cstdint>

// Forward declaration
class ScriptThread; // S29
class MissionScriptObjectsManager; // S27

/**
 * @brief Структура данных объекта миссии (S28)
 * Размер: 0x11C (284 байта)
 * Адрес экземпляра: зависит от контекста использования
 * 
 * Содержит данные об объекте миссии для сохранения/загрузки
 * Связана со структурой ScriptThread (S29)
 */
class MissionScriptObject {
public:
    // === Поля структуры (размер 0x11C) ===
    void* NextElement;              // 0x00 - Указатель на следующий элемент
    char field_04;                  // 0x04
    char field_05;                  // 0x05
    int16_t field_06;               // 0x06
    int32_t field_08;               // 0x08
    int32_t field_0C;               // 0x0C
    int32_t field_10;               // 0x10
    int32_t field_14;               // 0x14
    int32_t field_18;               // 0x18
    int32_t field_1C;               // 0x1C
    int32_t field_20;               // 0x20
    int32_t field_24;               // 0x24
    int32_t field_28;               // 0x28
    int32_t field_2C;               // 0x2C
    int32_t field_30;               // 0x30
    int32_t field_34;               // 0x34
    int32_t field_38;               // 0x38
    int32_t field_3C;               // 0x3C
    int32_t field_40;               // 0x40
    int32_t field_44;               // 0x44
    int32_t field_48;               // 0x48
    int32_t field_4C;               // 0x4C
    int32_t field_50;               // 0x50
    int32_t field_54;               // 0x54
    int32_t field_58;               // 0x58
    int32_t field_5C;               // 0x5C
    uint8_t arr[252];               // 0x60 - Массив данных (252 байта)
    ScriptThread* scriptThread;     // 0x118 - Указатель на структуру S29 (ScriptThread)
    // Итого: 0x11C байт

    // === VTable (виртуальная таблица методов) ===
    // Адрес VTable: требуется уточнение по дампу
    // Количество методов: ~64

    // === Конструкторы и деструкторы ===
    
    /**
     * @brief Конструктор
     * Адрес: 0x475C00
     * Размер: 0x62 байта
     */
    MissionScriptObject();
    
    /**
     * @brief Деструктор
     * Адрес: 0x475C70 (предположительно)
     * Размер: 0x26 байт
     */
    virtual ~MissionScriptObject();

    // === Основные методы управления ===
    
    /**
     * @brief Инициализация/обновление объекта
     * Адрес: 0x476E50
     */
    virtual void Init();
    
    /**
     * @brief Главный метод обработки
     * Адрес: 0x4805B0
     * Размер: 0x6A0 байт
     */
    virtual void MainProcess();
    
    /**
     * @brief Обновление состояния
     * Адрес: 0x477A20
     */
    virtual void Update();
    
    /**
     * @brief Сброс состояния
     * Адрес: 0x477D80
     */
    virtual void Reset();
    
    /**
     * @brief Активация объекта
     * Адрес: 0x478100
     */
    virtual void Activate();

    // === Методы сохранения/загрузки ===
    
    /**
     * @brief Сохранение в файл игры
     * Адрес: 0x479F10
     */
    virtual int SaveToFile(const char* filename);
    
    /**
     * @brief Загрузка из файла игры
     * Адрес: 0x479CC0
     */
    virtual int LoadFromFile(const char* filename);
    
    /**
     * @brief Сохранение данных миссии
     * Адрес: 0x47A100
     */
    virtual void SaveMissionData();
    
    /**
     * @brief Загрузка данных миссии
     * Адрес: 0x47A250
     */
    virtual void LoadMissionData();
    
    /**
     * @brief Проверка валидности сохранения
     * Адрес: 0x47A380
     */
    virtual bool IsValidSave();
    
    /**
     * @brief Очистка данных сохранения
     * Адрес: 0x47A4B0
     */
    virtual void ClearSaveData();

    // === Работа с объектами миссии ===
    
    /**
     * @brief Получение указателя на объект
     * Адрес: 0x47B200
     */
    virtual void* GetObjectPtr();
    
    /**
     * @brief Создание спавна объектов скрипта
     * Адрес: 0x47B350
     */
    virtual void SpawnScriptObjects();
    
    /**
     * @brief Удаление объекта
     * Адрес: 0x47B4A0
     */
    virtual void RemoveObject();
    
    /**
     * @brief Активация триггера
     * Адрес: 0x47B5F0
     */
    virtual void ActivateTrigger();

    // === Работа со скриптами ===
    
    /**
     * @brief Загрузка скрипта
     * Адрес: 0x47C100
     */
    virtual int LoadScript(const char* scriptName);
    
    /**
     * @brief Парсинг команды скрипта
     * Адрес: 0x47C250
     */
    virtual int ParseScriptCommand();
    
    /**
     * @brief Выполнение команды скрипта
     * Адрес: 0x47C3A0
     */
    virtual int ExecuteScriptCommand();
    
    /**
     * @brief Переход к метке в скрипте
     * Адрес: 0x47C4F0
     */
    virtual void GotoLabel(const char* label);
    
    /**
     * @brief Вызов подпрограммы
     * Адрес: 0x47C640
     */
    virtual void CallSubroutine(int subroutineId);

    // === Работа с целями ===
    
    /**
     * @brief Обновление целей
     * Адрес: 0x47D100
     */
    virtual void UpdateObjectives();
    
    /**
     * @brief Проверка завершения
     * Адрес: 0x47D250
     */
    virtual bool CheckCompletion();
    
    /**
     * @brief Выдача награды
     * Адрес: 0x47D3A0
     */
    virtual void GiveReward();
    
    /**
     * @brief Установка цели
     * Адрес: 0x47D4F0
     */
    virtual void SetObjective(int objectiveId);

    // === Внутренние методы обработки ===
    
    /**
     * @brief Обработка коллизий
     * Адрес: 0x47E100
     */
    virtual void ProcessCollisions();
    
    /**
     * @brief Проверка условий
     * Адрес: 0x47E250
     */
    virtual bool CheckConditions();
    
    /**
     * @brief Сравнение значений
     * Адрес: 0x47E3A0
     */
    virtual int CompareValues(int a, int b);
    
    /**
     * @brief Ограничение значений
     * Адрес: 0x47E4F0
     */
    virtual void ClampValues(int* value, int min, int max);
    
    /**
     * @brief Копирование данных
     * Адрес: 0x47E640
     */
    virtual void CopyData(void* dest, const void* src, int size);
    
    /**
     * @brief Инициализация массива
     * Адрес: 0x47E790
     */
    virtual void InitArray(void* array, int value, int size);
    
    /**
     * @brief Поиск в массиве
     * Адрес: 0x47E8E0
     */
    virtual int FindInArray(const void* array, int value, int size);
    
    /**
     * @brief Сортировка массива
     * Адрес: 0x47EA30
     */
    virtual void SortArray(void* array, int size);
    
    /**
     * @brief Вычисление контрольной суммы
     * Адрес: 0x47EB80
     */
    virtual int CalculateChecksum(const void* data, int size);
    
    /**
     * @brief Шифрование данных
     * Адрес: 0x47ECD0
     */
    virtual void EncryptData(void* data, int size);
    
    /**
     * @brief Дешифрование данных
     * Адрес: 0x47EE20
     */
    virtual void DecryptData(void* data, int size);
    
    /**
     * @brief Сжатие данных
     * Адрес: 0x47EF70
     */
    virtual int CompressData(void* dest, const void* src, int srcSize);
    
    /**
     * @brief Распаковка данных
     * Адрес: 0x47F0C0
     */
    virtual int DecompressData(void* dest, const void* src, int srcSize);

    // === Работа с состоянием миссии ===
    
    /**
     * @brief Завершение миссии
     * Адрес: 0x480100
     */
    virtual void CompleteMission();
    
    /**
     * @brief Провал миссии
     * Адрес: 0x480250
     */
    virtual void FailMission();
    
    /**
     * @brief Перезапуск миссии
     * Адрес: 0x4803A0
     */
    virtual void RestartMission();
    
    /**
     * @brief Пауза миссии
     * Адрес: 0x4804F0
     */
    virtual void PauseMission();
    
    /**
     * @brief Возобновление миссии
     * Адрес: 0x480640
     */
    virtual void ResumeMission();

    // === Отладка и логирование ===
    
    /**
     * @brief Вывод отладочной информации
     * Адрес: 0x481100
     */
    virtual void PrintDebugInfo();
    
    /**
     * @brief Логирование события
     * Адрес: 0x481250
     */
    virtual void LogEvent(const char* event);
    
    /**
     * @brief Установка уровня отладки
     * Адрес: 0x4813A0
     */
    virtual void SetDebugLevel(int level);
    
    /**
     * @brief Получение уровня отладки
     * Адрес: 0x4814F0
     */
    virtual int GetDebugLevel();

    // === Дополнительные методы (sub_*) ===
    // Требуют анализа ассемблерного листинга
    
    virtual void sub_475D00();
    virtual void sub_475E50();
    virtual void sub_475FA0();
    virtual void sub_4760F0();
    virtual void sub_476240();
    virtual void sub_476390();
    virtual void sub_4764E0();
    virtual void sub_476630();
    virtual void sub_476780();
    virtual void sub_4768D0();
    virtual void sub_476A20();
    virtual void sub_476B70();
    virtual void sub_476CC0();
    virtual void sub_476E10();
    virtual void sub_4770F0();
    virtual void sub_477240();
    virtual void sub_477390();
};

#endif // MISSION_SCRIPT_OBJECT_H
