/**
 * @file car.h
 * @brief Определение структуры автомобиля (CCar) в GTA 2.
 *
 * Анализ конструктора:
 * - Адрес: 0x004E39E0
 * - Размер элемента в пуле: 0xBC (188 байт)
 * - Наследование: Turrel + Passenger (множественное)
 * 
 * История имен:
 * - S2 (ошибочно, временное)
 * - Car (старое)
 * - CCar (текущее, корректное)
 * 
 * Логика конструктора:
 * 1. Turrel::sub_424620(this) - инициализация турели
 * 2. Passenger::sub_425450(&this->Passenger) - инициализация пассажира
 * 3. sub_420D80(&this->carLights) - инициализация огней
 * 4. Construct(doors[4], 16, 4, CarDoor::CarDoor, CarDoor::CarDoor_Des) - 4 двери
 * 5. Обнуление полей: Driver, Damage, FireState, locksDoor, engineState=BROKEN, SearchType=NO_THREATS
 * 6. ID = 0xFFFF, LastCar = 0
 * 7. sub_4BF000(), SetHornDefault()
 * 8. bitShiftLeft1(&pCar, 1) -> field_68
 */

#ifndef GTA2_ENTITIES_CAR_H
#define GTA2_ENTITIES_CAR_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================================
// ПРЕДВАРИТЕЛЬНЫЕ ОБЪЯВЛЕНИЯ
// ============================================================================
typedef struct Turrel Turrel;
typedef struct Passenger Passenger;
typedef struct CarDoor CarDoor;
typedef struct CarLights CarLights;
typedef struct SpriteS1 SpriteS1;
typedef struct Player Player;
typedef struct Ped Ped;

// ============================================================================
// ПЕРЕЧИСЛЕНИЯ
// ============================================================================

/** Состояние двигателя */
typedef enum CarEngineState {
    ENGINE_OK = 0,
    BROKEN_DOESNT_WORK = 1,
} CarEngineState;

/** Тип поиска угроз */
typedef enum CarSearchType {
    SEARCHTYPE_NO_THREATS = 0,
    SEARCHTYPE_ENEMIES = 1,
} CarSearchType;

/** Тип повреждения */
typedef enum CarDamageType {
    DAMAGE_NONE = 0,
    DAMAGE_BULLET = 1,
    DAMAGE_COLLISION = 2,
    DAMAGE_FIRE = 3,
} CarDamageType;

/** Тип трафика */
typedef enum CarTrafficType {
    TRAFFIC_0 = 0,
    TRAFFIC_CIVILIAN = 1,
    TRAFFIC_POLICE = 2,
    TRAFFIC_GANG = 3,
} CarTrafficType;

// ============================================================================
// РАЗМЕРЫ БАЗОВЫХ КЛАССОВ (из анализа кода)
// ============================================================================
// Turrel:   0x20 байт (32)
// Passenger: 0x18 байт (24)
// Итого базовая часть: 0x38 (56 байт)
// CarLights: 4 байта
// CarDoor: 4 байта * 4 = 16 байт
// ---------------------------------------------------------------------------
// Смещение первых полей Car: 0x38 + 0x04 + 0x10 = 0x4C (76 байт)
// Это совпадает со смещением поля LastCar в цикле инициализации пула!
// ============================================================================

// ============================================================================
// СТРУКТУРА АВТОМОБИЛЯ (CCar)
// ============================================================================
/**
 * @brief Основная структура автомобиля.
 * 
 * Размер: 0xBC (188 байт) - подтверждено через Construct(this->sCarArr306, 0xBC, 306, ...)
 * Выравнивание: 4 байта
 */
typedef struct CCar {
    // === БАЗОВЫЕ КЛАССЫ (0x00 - 0x37) ===
    uint8_t turrel_base[32];        ///< 0x00: Turrel (vtable + поля оружия)
    uint8_t passenger_base[24];     ///< 0x20: Passenger (vtable + данные пассажира)
    
    // === ПОЛЯ CAR (начинаются с 0x38) ===
    CarLights carLights;            ///< 0x38: Система огней (иниц. sub_420D80)
    CarDoor doors[4];               ///< 0x3C: 4 двери (каждая 4 байта, инци. через Construct)
    
    // --- Поля после дверей (с 0x4C) ---
    void* Driver;                   ///< 0x4C: Указатель на водителя (Ped*) [обнуляется]
    int32_t Damage;                 ///< 0x50: Текущий урон [0]
    int32_t FireState;              ///< 0x54: Состояние пожара [0]
    int32_t locksDoor;              ///< 0x58: Флаг замков дверей [0]
    CarEngineState engineState;     ///< 0x5C: Состояние двигателя [BROKEN_DOESNT_WORK=1]
    CarSearchType SearchType;       ///< 0x60: Тип поиска угроз [SEARCHTYPE_NO_THREATS=0]
    int16_t field_76;               ///< 0x64: Неизвестное поле [0]
    int8_t sirenState;              ///< 0x66: Состояние сирены [0]
    int8_t sirenPhase;              ///< 0x67: Фаза сирены [0]
    int8_t field_A6;                ///< 0x68: Неизвестно [0]
    int8_t _pad1;                   ///< 0x69: Выравнивание
    
    // !!! КРИТИЧЕСКОЕ ПОЛЕ ДЛЯ ПУЛА !!!
    struct CCar* LastCar;           ///< 0x6A: Указатель на след. машину в пуле [0 или next]
                                    ///         В цикле инициализации: *p_LastCar = (Car *)(p_LastCar + 28)
                                    ///         Шаг между элементами: 0xBC (188 байт)
    int16_t _pad2;                  ///< 0x6E: Выравнивание
    
    int32_t CarType;                ///< 0x70: ID модели [MODEL_NUM_CAR_MODELS]
    SpriteS1* CarSprite;            ///< 0x74: Визуальный спрайт [0]
    Player* Player;                 ///< 0x78: Владелец-игрок [0]
    void* EngineStruct;             ///< 0x7C: Физическая структура двигателя [0]
    int32_t Mask;                   ///< 0x80: Маска коллизий/групп [0]
    uint16_t ID;                    ///< 0x84: Уникальный ID [0xFFFF]
    int8_t TrailerCtrl;             ///< 0x86: Управление прицепом [0]
    int8_t PhysicsBitmask;          ///< 0x87: Физическая битмаска [0]
    
    // Поля после sub_4BF000()
    int32_t field_80;               ///< 0x88: Неизвестно (заполняется в sub_4BF000) [0]
    CarTrafficType trafficCarType;  ///< 0x8C: Тип трафика [TRAFFIC_0]
    int8_t field_8D;                ///< 0x90: Неизвестно [0]
    int8_t _pad3;                   ///< 0x91: Выравнивание
    int16_t _pad4;                  ///< 0x92: Выравнивание
    
    Ped* lastDamagingPed;           ///< 0x94: Последний повредивший пешеход [0]
    CarDamageType DamageType;       ///< 0x98: Тип последнего урона [DAMAGE_NONE]
    int8_t _pad5;                   ///< 0x9C: Выравнивание
    int16_t _pad6;                  ///< 0x9D: Выравнивание
    int32_t DamageShotTimer;        ///< 0xA0: Таймер урона от выстрела [0]
    int32_t PlayerId;               ///< 0xA4: ID игрока-владельца [0]
    int32_t AlarmTime;              ///< 0xA8: Время работы сигнализации [0]
    int32_t field_68;               ///< 0xAC: Вычисляемое поле (bitShiftLeft1 result)
    
} CCar;

// Проверки размера и смещений
#ifdef __cplusplus
static_assert(sizeof(CCar) == 0xBC, "CCar size must be 0xBC (188 bytes)");
static_assert(offsetof(CCar, LastCar) == 0x6A, "CCar::LastCar offset must be 0x6A");
static_assert(offsetof(CCar, ID) == 0x84, "CCar::ID offset must be 0x84");
#endif

// ============================================================================
// ФУНКЦИИ
// ============================================================================

/**
 * @brief Конструктор автомобиля
 * @param this Указатель на экземпляр CCar
 * @return Указатель на инициализированный экземпляр
 * 
 * Адрес: 0x004E39E0
 * 
 * Логика:
 * 1. Инициализирует базовые классы Turrel и Passenger
 * 2. Создает массив из 4 дверей
 * 3. Обнуляет большинство полей
 * 4. Устанавливает ID = 0xFFFF, engineState = BROKEN
 * 5. Вызывает helper-функции sub_4BF000 и SetHornDefault
 * 6. Вычисляет field_68 через bitShiftLeft1
 */
CCar* CCar_Constructor(CCar* this);

/**
 * @brief Деструктор автомобиля
 * @param this Указатель на экземпляр CCar
 * @return Указатель на экземпляр
 */
CCar* CCar_Destructor(CCar* this);

/**
 * @brief Внутренняя функция инициализации (sub_4BF000)
 * @param this Указатель на экземпляр CCar
 */
void CCar_sub_4BF000(CCar* this);

/**
 * @brief Установка параметров гудка по умолчанию
 * @param this Указатель на экземпляр CCar
 */
void CCar_SetHornDefault(CCar* this);

#ifdef __cplusplus
}
#endif

#endif // GTA2_ENTITIES_CAR_H
