/**
 * @file c_game_entity.h
 * @brief Базовая структура игрового объекта (бывшая S1)
 * 
 * Анализ:
 * - Используется в массиве g_EntityPool[306]
 * - Размер экземпляра в пуле: 176 байт
 * - Базовый размер заголовка: ~60 байт
 * - Конструктор: 0x004xxxxx (S1::S1)
 * - Деструктор: 0x004xxxxx (S1::S1_DEc)
 * 
 * Назначение: Корневой класс для всех динамических объектов (машины, пешеходы, предметы).
 * Содержит координаты, тип объекта, флаги состояния и ссылки на спрайт/физику.
 */

#ifndef C_GAME_ENTITY_H
#define C_GAME_ENTITY_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// Предварительные объявления
struct Vector3D;
struct Matrix3D;

/**
 * @brief Типы игровых объектов (предположительно)
 */
typedef enum EEntityType {
    ENTITY_TYPE_NONE      = 0,
    ENTITY_TYPE_CAR       = 1,
    ENTITY_TYPE_PED       = 2,
    ENTITY_TYPE_PROJECTILE= 3,
    ENTITY_TYPE_ITEM      = 4,
    // ... другие типы
} EEntityType;

/**
 * @brief Флаги состояния объекта
 */
typedef enum EEntityFlags {
    ENTITY_FLAG_ACTIVE    = 0x01,
    ENTITY_FLAG_VISIBLE   = 0x02,
    ENTITY_FLAG_COLLIDING = 0x04,
    ENTITY_FLAG_MISSION   = 0x08,
    // ...
} EEntityFlags;

/**
 * @brief Базовая структура игрового объекта (S1)
 * 
 * Смещения (предварительные, требуют уточнения по ассемблеру):
 * 0x00 - vtable / ID типа
 * 0x04 - Позиция X (float)
 * 0x08 - Позиция Y (float)
 * 0x0C - Позиция Z (float) / Угол?
 * 0x10 - Угол направления (float)
 * 0x14 - Тип модели (uint16)
 * 0x16 - Флаги состояния (uint16)
 * 0x18 - Ссылка на следующий объект (для списка активных?)
 * 0x1C - Ссылка на предыдущий объект
 * ...
 * 0x3C - Радиус коллизии (float)
 * 0x40 - Здоровье / Прочность (int16)
 * ...
 * Общий размер в пуле: 176 байт (включая наследников)
 */
typedef struct CGameEntity {
    uint32_t type_id;           // 0x00: Тип объекта или vtable
    float pos_x;                // 0x04: Координата X
    float pos_y;                // 0x08: Координата Y
    float pos_z;                // 0x0C: Координата Z или угол
    float heading;              // 0x10: Направление (угол)
    uint16_t model_id;          // 0x14: ID модели
    uint16_t flags;             // 0x16: Флаги состояния
    struct CGameEntity* next;   // 0x18: Следующий в списке (если есть)
    struct CGameEntity* prev;   // 0x1C: Предыдущий в списке
    uint8_t  pad_20[0x3C - 0x20]; // Выравнивание до известных полей
    
    float collision_radius;     // 0x3C: Радиус для коллизий
    int16_t health;             // 0x40: Здоровье
    int16_t sub_type;           // 0x42: Подтип (вид машины/педа)
    
    // Оставшаяся часть до 176 байт заполняется в наследниках (Car/Ped)
    // Для базовой структуры оставляем как opaque buffer
    uint8_t extended_data[176 - 0x44]; 
} CGameEntity;

// Проверка размера (для базовой части, полный размер зависит от наследования)
// В пуле элементы упакованы плотно по 176 байт
static_assert(sizeof(CGameEntity) >= 0x44, "CGameEntity header size mismatch");

/**
 * @brief Конструктор объекта
 * @param entity Указатель на память объекта
 * @return Указатель на инициализированный объект
 */
CGameEntity* CGameEntity_Construct(CGameEntity* entity);

/**
 * @brief Деструктор объекта
 * @param entity Указатель на объект
 */
void CGameEntity_Destruct(CGameEntity* entity);

/**
 * @brief Инициализация пула объектов
 * @param pool Массив объектов
 * @param count Количество элементов (306)
 * @param item_size Размер одного элемента (176)
 */
void EntityPool_Init(void* pool, int count, int item_size);

#ifdef __cplusplus
}
#endif

#endif // C_GAME_ENTITY_H
