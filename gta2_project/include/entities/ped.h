#ifndef PED_H
#define PED_H

#include "types.h"
#include "enums.h"
#include "forward_declarations.h"
#include "systems/vector2d.h"
#include "ai/ped_ai_states.h"

#pragma pack(push, 1)

// ============================================================================
// S200 - Элемент очереди задач (3 байта)
// ============================================================================
struct S200 {
    u8 X;           // 0x0 - Координата X или параметр задачи
    u8 Y;           // 0x1 - Координата Y или параметр задачи
    u8 Param;       // 0x2 - Параметр задачи (тип действия)
};

// ============================================================================
// Weapon - Оружие (48 байт)
// ============================================================================
struct Weapon {
    u16 Ammo;               // 0x0 - Патроны
    u8 field1_0x2;          // 0x2
    u8 field2_0x3;          // 0x3
    u32 WeaponType;         // 0x4 - Тип оружия
    u32 field4_0x8;         // 0x8
    u32 field5_0xc;         // 0xc
    u16 field6_0x10;        // 0x10
    u8 field7_0x12;         // 0x12
    u8 field8_0x13;         // 0x13
    struct Car* Car;        // 0x14 - Машина (для оружия транспорта)
    struct Weapon* Next;    // 0x18 - Следующее оружие в списке
    u32 Type;               // 0x1c - Тип оружия (дубликат?)
    u8 field12_0x20;        // 0x20
    u8 field13_0x21;        // 0x21
    u8 field14_0x22;        // 0x22
    u8 field15_0x23;        // 0x23
    struct Ped* Ped;        // 0x24 - Владелец оружия
    u32 Sound;              // 0x28 - Звук выстрела
    u8 field18_0x2c;        // 0x2c
    u8 field19_0x2d;        // 0x2d
    u8 field20_0x2e;        // 0x2e
    u8 field21_0x2f;        // 0x2f
};

// ============================================================================
// Gang - Банда (размер уточняется)
// ============================================================================
struct Gang {
    bool IsCreated;         // 0x0 - Флаг создания банды
    enum GANG CurrentGang;  // 0x4 - Тип текущей банды
    char Name[10];          // 0x8 - Название банды
    // 0x12 - далее данные о членах, территориях и т.д.
};

// ============================================================================
// SpriteS1 - Спрайт (огромный массив матриц)
// ============================================================================
struct SpriteS1 {
    struct SpriteS1* FirstElement;      // 0x0 - Первый элемент
    struct Matrix3D MatrixArray[5031];  // 0x4 - Массив 3D матриц (5031 шт.)
};

// ============================================================================
// S169 - Неизвестная структура (заглушка)
// ============================================================================
struct S169 {
    u8 data[1]; // Размер неизвестен
};

// ============================================================================
// Ped - Пешеход/Персонаж (~664 байта)
// ============================================================================
struct Ped {
    // === Блок 1: Очередь задач (150 байт) ===
    struct S200 ObjectiveQueue[50];   // 0x0 - Массив целей/задач (50 * 3 = 150 байт)
    i32 Counter;                       // 0x96 - Счетчик задач
    u8 Reserved_0x9a[146];            // 0x9a - Резерв
    
    // === Блок 2: Неизвестные поля (12 байт) ===
    u16 field_0x12c;                  // 0x12c
    u16 field_0x12e;                  // 0x12e
    u16 field_0x130;                  // 0x130
    u16 field_0x132;                  // 0x132
    u16 field_0x134;                  // 0x134
    u8 field_0x136;                   // 0x136
    u8 field_0x137;                   // 0x137
    u32 field_0x138;                  // 0x138
    u32 field_0x13c;                  // 0x13c
    u32 field_0x140;                  // 0x140
    
    // === Блок 3: Связи с другими педами и машинами (32 байта) ===
    struct Ped* sPed1;                // 0x144 - Связанный пед 1
    struct Ped* Driver;               // 0x148 - Водитель (если пед в машине)
    struct Ped* LinkedPed;            // 0x14c - Связанный пед
    struct Car* Car;                  // 0x150 - Машина (анимация входа/выхода)
    struct Car* ObjectiveTargetCar;   // 0x154 - Целевая машина для задачи
    struct Car* TargetCarForEnter;    // 0x158 - Машина для входа
    struct Player* Player;            // 0x15c - Игрок
    struct Ped* NextPed;              // 0x160 - Следующий пед в списке
    struct S169* pS169;               // 0x164 - Неизвестная структура
    u8 field_0x168;                   // 0x168
    u8 field_0x169;                   // 0x169
    u8 field_0x16a;                   // 0x16a
    u8 field_0x16b;                   // 0x16b
    
    // === Блок 4: Текущее состояние и оружие (28 байт) ===
    struct Car* CarCurrent;           // 0x16c - Текущая машина
    struct Weapon* SelectedWeapon;    // 0x170 - Выбранное оружие
    struct Weapon* Weapon1;           // 0x174 - Оружие 1
    struct Weapon* Weapon2;           // 0x178 - Оружие 2
    struct Gang* Gang;                // 0x17c - Банда
    struct Ped* PedDriver;            // 0x180 - Пед-водитель
    u32 field_0x184;                  // 0x184
    struct Ped* LastCharPunched;      // 0x188 - Последний ударенный персонаж
    u32 field_0x18c;                  // 0x18c
    u32 field_0x190;                  // 0x190
    u32 field_0x194;                  // 0x194
    struct Ped* ped3;                 // 0x198 - Пед 3
    struct Gang* Gang1;               // 0x19c - Банда 1
    u32 field_0x1a0;                  // 0x1a0
    u32 field_0x1a4;                  // 0x1a4
    u32 field_0x1a8;                  // 0x1a8
    
    // === Блок 5: Позиция в мире (16 байт) ===
    i32 PositionX;                    // 0x1ac - Позиция X
    i32 PositionY;                    // 0x1b0 - Позиция Y
    i32 PositionZ;                    // 0x1b4 - Позиция Z
    struct Ped* pPed;                 // 0x1b8 - Указатель на педа
    
    // === Блок 6: Неизвестные указатели (24 байта) ===
    void* field_0x1bc;                // 0x1bc
    void* field_0x1c0;                // 0x1c0
    void* field_0x1c4;                // 0x1c4
    void* field_0x1c8;                // 0x1c8
    void* field_0x1cc;                // 0x1cc
    u32 field_0x1d0;                  // 0x1d0
    u32 field_0x1d4;                  // 0x1d4
    
    // === Блок 7: Спрайт и дополнительные машины (28 байт) ===
    struct SpriteS1* SpriteS1;        // 0x1d8 - Спрайт
    struct Car* Car_1;                // 0x1dc - Машина 1
    struct Car* Car_2;                // 0x1e0 - Машина 2
    u32 field_0x1e4;                  // 0x1e4
    u32 field_0x1e8;                  // 0x1e8
    u32 field_0x1ec;                  // 0x1ec
    u32 field_0x1f0;                  // 0x1f0
    u32 field_0x1f4;                  // 0x1f4
    u32 field_0x1f8;                  // 0x1f8
    
    // === Блок 8: Идентификаторы и статусы (24 байта) ===
    i32 ID;                           // 0x1fc - ID персонажа
    i32 PedID;                        // 0x200 - ID педа
    i16 Invulnerability;              // 0x204 - Невосприимчивость (видимость)
    i16 PoliceStars;                  // 0x206 - Звезды полиции
    i16 field_0x208;                  // 0x208
    u16 field_0x20a;                  // 0x20a
    i16 field_0x20c;                  // 0x20c
    i16 field_0x20e;                  // 0x20e
    i16 field_0x210;                  // 0x210
    i16 Health;                       // 0x212 - Здоровье
    i16 ObjectiveTimer;               // 0x214 - Таймер задачи
    i16 CarStateTimer;                // 0x216 - Таймер состояния машины
    enum PedFlags Flags;              // 0x218 - Флаги педа
    u8 field_0x21c;                   // 0x21c
    u8 field_0x21d;                   // 0x21d
    u8 field_0x21e;                   // 0x21e
    u32 field_0x220;                  // 0x220
    enum CarDamageState DamageState;  // 0x224 - Состояние повреждений
    u8 ExitAnimState;                 // 0x225 - Состояние анимации выхода
    u8 field_0x227;                   // 0x227
    u8 field_0x228;                   // 0x228
    u8 field_0x229;                   // 0x229
    u8 field_0x22a;                   // 0x22a
    u8 field_0x22b;                   // 0x22b
    u32 field_0x22c;                  // 0x22c
    u32 field_0x230;                  // 0x230
    u8 field_0x234;                   // 0x234
    u8 field_0x235;                   // 0x235
    u8 field_0x236;                   // 0x236
    u8 field_0x237;                   // 0x237
    enum SearchType SearchType;       // 0x238 - Тип поиска
    u8 IndexPed;                      // 0x23c - Индекс педа
    u8 field_0x23d;                   // 0x23d
    u8 field_0x23e;                   // 0x23e
    u8 field_0x23f;                   // 0x23f
    enum ALL_PED Occupation;          // 0x240 - Профессия/занятие
    enum Remap Remap;                 // 0x244 - Ремэппинг текстур
    u8 field_0x248;                   // 0x248
    u8 field_0x249;                   // 0x249
    u8 field_0x24a;                   // 0x24a
    i32 TargetCarDoor;                // 0x24c - Целевая дверь машины
    u8 Idex;                          // 0x250 - Индекс анимации
    u8 field_0x251;                   // 0x251
    u8 field_0x252;                   // 0x252
    u8 field_0x253;                   // 0x253
    u32 field_0x254;                  // 0x254
    u32 field_0x258;                  // 0x258
    u32 State;                        // 0x25c - Состояние
    i32 CurrentAction;                // 0x260 - Текущее действие
    u8 field_0x264;                   // 0x264
    u8 field_0x265;                   // 0x265
    u8 field_0x266;                   // 0x266
    u8 field_0x267;                   // 0x267
    u8 field_0x268;                   // 0x268
    u8 field_0x269;                   // 0x269
    u8 field_0x26a;                   // 0x26a
    u8 field_0x26b;                   // 0x26b
    u8 field_0x26c;                   // 0x26c
    u8 field_0x26d;                   // 0x26d
    u8 field_0x26e;                   // 0x26e
    u8 field_0x26f;                   // 0x26f
    u32 GraphicType;                  // 0x270 - Тип графики
    u32 field_0x274;                  // 0x274
    i32 GangCarModel;                 // 0x278 - Модель машины банды
    enum PedState CurrentState;       // 0x27c - Текущее состояние
    u32 field_0x280;                  // 0x280
    enum PedState SavedState;         // 0x284 - Сохраненное состояние
    u32 field_0x288;                  // 0x288
    u32 field_0x28c;                  // 0x28c
    u32 field_0x290;                  // 0x290
    u32 field_0x294;                  // 0x294
    
    // === Блок 9: ИИ пешехода (контекст AI) ===
    struct PedAIContext AI;           // Контекст искусственного интеллекта
};

#pragma pack(pop)

// ============================================================================
// Функции работы с Ped
// ============================================================================

// Поиск и цели
void Ped__SetSearchType(struct Ped* this, enum SearchType type);
enum SearchType Ped__GetSearchType(struct Ped* this);

// Профессия
void Ped__SetOccupation(struct Ped* this, enum ALL_PED occupation);
enum ALL_PED Ped__GetOccupation(struct Ped* this);

// Состояние
enum PedState Ped__GetCurrentState(struct Ped* this);
void Ped__SetCurrentState(struct Ped* this, enum PedState state);
enum PedState Ped__GetSavedState(struct Ped* this);
void Ped__SetSavedState(struct Ped* this, enum PedState state);

// Здоровье
void Ped__SetHealth(struct Ped* this, i16 health);
i16 Ped__GetHealth(struct Ped* this);
bool Ped__IsDead(struct Ped* this);

// Машина
struct Car* Ped__GetCurrentCar(struct Ped* this);
void Ped__SetCar(struct Ped* this, struct Car* car);
struct Car* Ped__GetTargetCarForEnter(struct Ped* this);

// Ремэппинг
void Ped__SetRemap(struct Ped* this, enum Remap remap);
enum Remap Ped__GetRemap(struct Ped* this);

// Оружие
struct Weapon* Ped__GetSelectedWeapon(struct Ped* this);
void Ped__SetSelectedWeapon(struct Ped* this, struct Weapon* weapon);

// Флаги
bool Ped__IsCrouching(struct Ped* this);
void Ped__SetCrouching(struct Ped* this, bool crouch);

#endif // PED_H
