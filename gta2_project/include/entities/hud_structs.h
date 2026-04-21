/**
 * @file hud_structs.h
 * @brief Структуры HUD интерфейса GTA2
 * 
 * Восстановлено на основе конструктора Hud::Hud (004CAD30) и размеров из IDA Pro:
 * - Hud: 0x2AF8 (10992 байта)
 * - HudArrow: 0x848 (2120 байт) - field_844 существует
 * - HudMessage: 0x1C8 (456 байт) - m_nTimeToShow, m_nType
 * - HudBrief: 0x704 (1796 байт) - field_50C...field_6EC
 * - S86_7: ~0xB5C - циклический буфер на 29 элементов
 * - S86_8: field_0, str, field_84, field_88, field_8C, field_90, field_94
 * - S86_10: field_0, field_1 (45), field_2, field_3
 * - S166: массив S167 (12 элементов по 8 байт = 0x60)
 * - S86_4: массив S86_3 (6 элементов) + CopStars
 * 
 * Критические смещения:
 * - field_27B8: 0x27B8 (содержит wchar_t строку и счетчик)
 * - TextSpeed: последнее поле перед концом структуры
 */

#pragma once

#include <cstdint>
#include <cstddef>

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================================
// FORWARD DECLARATIONS
// ============================================================================

struct ArrowTrace;
struct S86_2_1;
struct S167;
struct S86_3;
struct HudBrief_S2;

// ============================================================================
// ARROW TRACE STRUCTURES
// ============================================================================

/**
 * @brief ArrowTrace - отслеживание стрелок направления
 * Размер: 0x24 (36 байт)
 */
typedef struct ArrowTrace {
    int32_t field_0;          // 0x00
    int32_t field_4;          // 0x04
    int32_t field_8;          // 0x08
    void* CurrentPlayer;      // 0x0C
    int32_t m_nType;          // 0x10
    int8_t field_23;          // 0x14 - флаг использования
    int8_t padding[3];        // 0x15-0x17
} ArrowTrace; // old_name: ArrowTrace, old_size: 0x24

/**
 * @brief S86_2_1 - элемент массива стрелок
 * Размер: 0x6C (108 байт) * 17 = 0x75C в HudArrow
 */
typedef struct S86_2_1 {
    int32_t m_nPointRotation; // 0x00
    void* Gang;               // 0x04
    int8_t m_bVisible;        // 0x08
    int8_t ArrowVisible;      // 0x09
    int16_t m_nSpriteId;      // 0x0A
    ArrowTrace m_ArrowTrace;  // 0x0C - 0x2F
    ArrowTrace m_SecondArrowTrace; // 0x30 - 0x53
    ArrowTrace* ArrowTrace;   // 0x54 - указатель на активный trace
    int32_t field_10;         // 0x58
    int32_t field_14;         // 0x5C
    int32_t field_18;         // 0x60
    int32_t field_1C;         // 0x64
    int8_t field_26;          // 0x68
    int8_t padding[1];        // 0x69
    int16_t field_2E;         // 0x6A
} S86_2_1; // old_name: S86_2_1, old_size: 0x6C

// ============================================================================
// HUD ARROW
// ============================================================================

/**
 * @brief HudArrow - управление стрелками и радаром
 * Размер: 0x848 (2120 байт)
 * Конструктор: HudArrow::HudArrow (004C7080)
 * Поля: field_83C=1, HudArrowNext=0, field_844=0/1
 */
typedef struct HudArrow {
    S86_2_1 S86_2_1[17];      // 0x000 - 0x75C (17 * 0x6C = 0x75C)
    int32_t field_83C;        // 0x75C - флаг (инициализируется в 1)
    void* HudArrowNext;       // 0x760 - следующая стрелка
    int32_t field_844;        // 0x764 - флаг видимости/активности
    int8_t padding[0x848 - 0x768]; // 0x768 - 0x847
} HudArrow; // old_name: HudArrow, old_size: 0x848

// ============================================================================
// HUD MESSAGE
// ============================================================================

/**
 * @brief HudMessage - большие экранные сообщения
 * Размер: 0x1C8 (456 байт)
 * Конструктор: HudMessage::HudMessage (004C60A0)
 * Поля: m_nTimeToShow=0, m_nType=1
 */
typedef struct HudMessage {
    int32_t m_nTimeToShow;    // 0x00 - время показа
    int32_t m_nType;          // 0x04 - тип сообщения (1 = большой текст)
    int8_t padding[0x1C8 - 0x8]; // 0x08 - 0x1C7
} HudMessage; // old_name: HudMessage, old_size: 0x1C8

// ============================================================================
// HUDBRIEF STRUCTURES
// ============================================================================

/**
 * @brief HudBrief_S2 - элемент очереди кратких сообщений
 * Размер: 0x24 (36 байт)
 */
typedef struct HudBrief_S2 {
    int32_t field_0;          // 0x00
    int32_t field_2;          // 0x04 - возможно wchar_t*
    int32_t field_8;          // 0x08 - флаг/тип
    int32_t field_10;         // 0x0C
    HudBrief_S2* nextHudBrief_S2; // 0x10 - следующий элемент
    int8_t padding[0x24 - 0x14]; // 0x14 - 0x23
} HudBrief_S2; // old_name: HudBrief_S2, old_size: 0x24

/**
 * @brief HudBrief - очередь кратких сообщений
 * Размер: 0x704 (1796 байт)
 * Конструктор: HudBrief::HudBrief (004C6590)
 */
typedef struct HudBrief {
    int32_t field_504;        // 0x00
    int32_t field_50C;        // 0x04
    int32_t field_510;        // 0x08
    int32_t field_514;        // 0x0C
    HudBrief_S2* HudBrief_S2; // 0x10 - голова очереди
    HudBrief_S2* pHudBrief_S2; // 0x14 - хвост очереди
    int32_t field_518;        // 0x18 - первый элемент пула
    int32_t field_51C;        // 0x1C
    // Пул из 19 элементов по 24 байта (0x18)
    int8_t pool[19 * 0x18];   // 0x20 - 0x1D7
    int32_t field_6EC;        // 0x1D8
    int32_t field_6FC;        // 0x1DC - свободный список
    int8_t padding[0x704 - 0x1E0]; // 0x1E0 - 0x703
} HudBrief; // old_name: HudBrief, old_size: 0x704

// ============================================================================
// S167 / S166
// ============================================================================

/**
 * @brief S167 - элемент таймера/счетчика
 * Размер: 0xC (12 байт)
 */
typedef struct S167 {
    int32_t field_0;          // 0x00 - значение таймера
    int32_t field_4;          // 0x04 - связанный звук/объект
    int32_t field_8;          // 0x08
} S167; // old_name: S167, old_size: 0xC

/**
 * @brief S166 - массив S167 (12 элементов)
 * Размер: 0x90 (144 байта)
 * Конструктор: S166::S166 (004CA660) - Construct(12, 4, ...)
 */
typedef struct S166 {
    S167 S167[12];            // 0x00 - 0x8F (12 * 0xC = 0x90)
} S166; // old_name: S166, old_size: 0x90

// ============================================================================
// S86_3 / S86_4
// ============================================================================

/**
 * @brief S86_3 - элемент звезд розыска
 * Размер: 0xC (12 байт)
 */
typedef struct S86_3 {
    int32_t field_0;          // 0x00
    int32_t field_2;          // 0x04
    int32_t field_1;          // 0x08
    int32_t field_4;          // 0x0C
    int32_t field_8;          // 0x10 - инициализируется в -1
} S86_3; // old_name: S86_3, old_size: 0x10

/**
 * @brief S86_4 - управление звездами полиции
 * Размер: 0x64 (100 байт)
 * Конструктор: S86_4::S86_4 (004C6EE0) - constructor(12, 6, ...)
 */
typedef struct S86_4 {
    S86_3 S83_3[6];           // 0x00 - 0x5F (6 * 0x10 = 0x60)
    int32_t CopStars;         // 0x60 - текущие звезды
} S86_4; // old_name: S86_4, old_size: 0x64

// ============================================================================
// S86_7 - ТЕКСТОВЫЙ БУФЕР
// ============================================================================

/**
 * @brief S86_7 - циклический буфер текстовых элементов
 * Размер: 0x1700 (5888 байт)
 * Конструктор: S86_7::S86_7 (004C6250)
 * Цикл: 29 элементов по 0xC4 (196) байт = 0xB5C
 * Поля: field_C0...field_16F8, field_16FC, field_16F4, field_16F8
 */
typedef struct S86_7_Element {
    int8_t data[0xC4];        // 0x00 - 0xC3 - данные элемента
} S86_7_Element;

typedef struct S86_7 {
    int8_t padding_C0[0xB5C]; // 0x00 - 0xB5B - 29 элементов
    int32_t field_16F4;       // 0xB5C - счетчик/флаг
    void* field_16F8;         // 0xB60 - голова списка
    S86_7* field_16FC;        // 0xB64 - указатель на себя
    int8_t padding[0x1700 - 0xB68]; // 0xB68 - 0x16FF
} S86_7; // old_name: S86_7, old_size: 0x1700

// ============================================================================
// S86_8 - ОБЛАСТЬ НА ЭКРАНЕ
// ============================================================================

/**
 * @brief S86_8 - отображение названия местности/района
 * Размер: 0x98 (152 байта)
 * Конструктор: S86_8::S86_8 (004C6C70)
 * Поля: field_0, str, field_84, field_88, field_8C, field_90, field_94
 */
typedef struct S86_8 {
    int32_t field_0;          // 0x00 - таймер/счетчик (90 при активном)
    wchar_t str[64];          // 0x04 - 0x83 - текст названия
    int32_t field_84;         // 0x84 - ширина строки
    int32_t field_88;         // 0x88 - указатель/флаг
    int32_t field_8C;         // 0x8C - указатель на зону
    int8_t field_90;          // 0x90 - направление мигания
    int8_t field_94;          // 0x91 - прозрачность/альфа
    int8_t padding[2];        // 0x92-0x93
} S86_8; // old_name: S86_8, old_size: 0x94

// ============================================================================
// S86_5 - МИНИ-КАРТА/КОМПАС
// ============================================================================

/**
 * @brief S86_5 - компас/индикатор направления
 * Размер: 0x10 (16 байт)
 * Конструктор: S86_5::S86_5 (004C7350)
 */
typedef struct S86_5 {
    int32_t field_0;          // 0x00
    int32_t field_4;          // 0x04
    int32_t field_8;          // 0x08
    int32_t field_C;          // 0x0C - связано с sub_4C9C20
} S86_5; // old_name: S86_5, old_size: 0x10

// ============================================================================
// S86_10 - ЧАТ/ВВОД
// ============================================================================

/**
 * @brief S86_10 - чат и ввод текста
 * Размер: 0x438 (1080 байт)
 * Конструктор: S86_10::S86_10 (004C7120)
 * Поля: field_0=0, field_1=45, field_2, field_3
 */
typedef struct S86_10 {
    int32_t field_0;          // 0x00 - индекс банка GANG
    int32_t field_1;          // 0x04 - значение (45 по умолчанию)
    int8_t field_2[0x434];    // 0x08 - 0x43B - буфер чата/ввода
    int8_t padding[0x438 - 0x43C]; // 0x43C - 0x437
} S86_10; // old_name: S86_10, old_size: 0x438

// ============================================================================
// S86_9 - НЕИЗВЕСТНАЯ СТРУКТУРА
// ============================================================================

/**
 * @brief S86_9 - неизвестная структура (возможно, связана с целями)
 * Размер: вычисляется из общего размера Hud
 * Инициализация: sub_4C6AC0 (устанавливает byte в 0)
 */
typedef struct S86_9 {
    int8_t field_0;           // 0x00 - флаг (инициализируется в 0)
    int8_t padding[0x???];    // TODO: уточнить размер
} S86_9;

// ============================================================================
// FIELD_27B8 STRUCTURE
// ============================================================================

/**
 * @brief field_27B8 - структура для отображения имени игрока/цели
 * Размер: предположительно 0x88 (136 байт)
 * Инициализация: sub_4C6A50 (byte = 0), sub_4C69F0 (заполнение)
 */
typedef struct Field27B8 {
    int8_t field_0;           // 0x00 - счетчик/таймер (90 при активном)
    wchar_t str[64];          // 0x01 - 0x81 - текст имени
    int32_t field_84;         // 0x81 - ширина строки
} Field27B8; // old_name: Field27B8, old_size: 0x88

// ============================================================================
// MAIN HUD STRUCTURE
// ============================================================================

/**
 * @brief Hud - основная структура HUD
 * Общий размер: 0x2AF8 (10992 байта)
 * Глобальный указатель: gHud (00595004)
 * Конструктор: Hud::Hud (004CAD30)
 * 
 * Раскладка полей согласно конструктору:
 * 1. field_0 (от Hud::Hud1)
 * 2. S86_8
 * 3. HudBrief
 * 4. S166
 * 5. S86_7
 * 6. HudArrow
 * 7. S86_4
 * 8. s (sub_4C6E70)
 * 9. field_27B8 (по смещению 0x27B8!)
 * 10. S86_5
 * 11. HudMessage
 * 12. S86_10
 * 13. S86_9
 * 14. TextSpeed
 */
typedef struct Hud {
    // Базовое поле (от Hud::Hud1)
    int32_t field_0;          // 0x0000 - счетчик/таймер
    
    // S86_8 - название местности
    S86_8 S86_8;              // 0x0004 - 0x0097 (0x94 байта)
    
    // HudBrief - краткие сообщения  
    HudBrief HudBrief;        // 0x0098 - 0x079B (0x704 байта)
    
    // S166 - таймеры
    S166 S166;                // 0x079C - 0x082B (0x90 байт)
    
    // S86_7 - текстовый буфер
    S86_7 S86_7;              // 0x082C - 0x1F2B (0x1700 байт)
    
    // HudArrow - стрелки/радар
    HudArrow HudArrow;        // 0x1F2C - 0x2773 (0x848 байт)
    
    // S86_4 - звезды полиции
    S86_4 struc_S86_4;        // 0x2774 - 0x27D7 (0x64 байта)
    
    // s - неизвестное поле
    int8_t s[0x10];           // 0x27D8 - 0x27E7 (предположительно)
    
    // field_27B8 - имя цели/игрока (КРИТИЧЕСКОЕ СМЕЩЕНИЕ!)
    // Примечание: имя field_27B8 указывает на смещение в оригинальной структуре
    Field27B8 field_27B8;     // 0x27E8 - 0x286F (0x88 байт)
    
    // S86_5 - компас
    S86_5 S86_5;              // 0x2870 - 0x287F (0x10 байт)
    
    // HudMessage - большие сообщения
    HudMessage HudMessage;    // 0x2880 - 0x2A47 (0x1C8 байт)
    
    // S86_10 - чат
    S86_10 S86_10;            // 0x2A48 - 0x2E7F (0x438 байт)
    
    // S86_9 - неизвестная структура
    S86_9 S86_9;              // 0x2E80 - ???
    
    // TextSpeed - скорость текста
    int32_t TextSpeed;        // последнее поле
    
    // Padding до конца структуры (0x2AF8)
    int8_t padding_end[1];    // заполнитель
    
} Hud; // old_name: Hud, old_size: 0x2AF8

// ============================================================================
// GLOBAL VARIABLES
// ============================================================================

/**
 * @brief Глобальный указатель на HUD
 * Адрес: 0x595004
 */
extern Hud* gHud; // old_var: gHud

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
namespace GTA2 {
namespace UI {
    // C++ обертки будут определены в hud.cpp
}
}
#endif

// ============================================================================
// SIZE CHECKS (для верификации в отладке)
// ============================================================================
/*
Статическая проверка размеров (раскомментировать для проверки):

static_assert(sizeof(ArrowTrace) == 0x24, "ArrowTrace size mismatch");
static_assert(sizeof(S86_2_1) == 0x6C, "S86_2_1 size mismatch");
static_assert(sizeof(HudArrow) == 0x848, "HudArrow size mismatch");
static_assert(sizeof(HudMessage) == 0x1C8, "HudMessage size mismatch");
static_assert(sizeof(HudBrief_S2) == 0x24, "HudBrief_S2 size mismatch");
static_assert(sizeof(HudBrief) == 0x704, "HudBrief size mismatch");
static_assert(sizeof(S167) == 0xC, "S167 size mismatch");
static_assert(sizeof(S166) == 0x90, "S166 size mismatch");
static_assert(sizeof(S86_3) == 0x10, "S86_3 size mismatch");
static_assert(sizeof(S86_4) == 0x64, "S86_4 size mismatch");
static_assert(sizeof(S86_7) == 0x1700, "S86_7 size mismatch");
static_assert(sizeof(S86_8) == 0x94, "S86_8 size mismatch");
static_assert(sizeof(S86_5) == 0x10, "S86_5 size mismatch");
static_assert(sizeof(S86_10) == 0x438, "S86_10 size mismatch");
static_assert(sizeof(Field27B8) == 0x88, "Field27B8 size mismatch");
static_assert(sizeof(Hud) == 0x2AF8, "Hud size mismatch");
*/
