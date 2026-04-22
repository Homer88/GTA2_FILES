#ifndef GTA2_ARSENAL_MANAGER_H
#define GTA2_ARSENAL_MANAGER_H

#include <cstdint>

// =============================================================================
// Структура: CArsenalManager (бывшая Weapon1)
// =============================================================================
// Адрес конструктора: 0x00424620 (вызывается внутри Turrel::Turrel)
// Размер: 0x2FDC (12252 байт)
// Назначение: Глобальный менеджер данных об оружии (таблицы характеристик, 
//             модели, звуки, параметры для всех видов оружия в игре).
// Глобальная переменная: gWeapon1
// =============================================================================

#pragma pack(push, 1)

// Предположительная структура определения одного вида оружия
// Размер одной записи оценивается примерно в 200-400 байт
struct CWeaponDefinition {
    uint32_t id;                // 0x00 ID оружия
    char name[32];              // 0x04 Имя оружия (строка)
    float damage;               // 0x24 Базовый урон
    float range;                // 0x28 Дальность
    float fireRate;             // 0x2C Скорострельность
    float spread;               // 0x30 Разброс
    uint32_t ammoType;          // 0x34 Тип боеприпаса
    uint32_t modelId;           // 0x38 ID модели
    uint32_t soundId;           // 0x3C ID звука выстрела
    uint32_t flags;             // 0x40 Флаги (автоматический, взрывной и т.д.)
    // ... остальные поля зависят от конкретной реализации
    uint8_t padding[0xF0];      // 0x44 Выравнивание/доп. данные
};

struct CArsenalManager {
    // --- Заголовок (предположительно) ---
    uint32_t totalWeapons;          // 0x00 Количество типов оружия
    uint32_t maxWeapons;            // 0x04 Максимальное количество слотов
    CWeaponDefinition* pWeapons;    // 0x08 Указатель на массив определений
    void* pAmmoTable;               // 0x0C Таблица параметров боеприпасов
    void* pEffectTable;             // 0x10 Таблица визуальных эффектов
    
    // --- Основное хранилище данных ---
    // Основная часть размера 0x2FDC занята сырыми данными таблиц:
    // - Пути к моделям и текстурам
    // - Параметры физики снарядов
    // - Звуковые банки
    // - Скрипты поведения
    uint8_t rawData[0x2FBC];        // 0x14 Сырые данные (12220 байт)
};

#pragma pack(pop)

// Проверка размера структуры
static_assert(sizeof(CArsenalManager) == 0x2FDC, "CArsenalManager size must be 0x2FDC");

#ifdef __cplusplus
extern "C" {
#endif

// C-обертки для методов
CArsenalManager* CArsenalManager_Constructor(CArsenalManager* this_ptr);
void CArsenalManager_Destructor(CArsenalManager* this_ptr);
CWeaponDefinition* CArsenalManager_GetWeaponDef(CArsenalManager* manager, uint32_t id);

#ifdef __cplusplus
}

// C++ класс с методами
class CArsenalManagerCpp {
public:
    // Конструктор (соответствует CArsenalManager_Constructor)
    CArsenalManagerCpp* Constructor();
    
    // Деструктор
    ~CArsenalManagerCpp();
    
    // Получить определение оружия по ID
    CWeaponDefinition* GetWeaponDef(uint32_t id);
    
    // Статический метод создания экземпляра
    static CArsenalManagerCpp* CreateInstance();

    // Данные (совпадают со структурой CArsenalManager)
    uint32_t totalWeapons;
    uint32_t maxWeapons;
    CWeaponDefinition* pWeapons;
    void* pAmmoTable;
    void* pEffectTable;
    uint8_t rawData[0x2FBC];
};
#endif // __cplusplus

#endif // GTA2_ARSENAL_MANAGER_H
