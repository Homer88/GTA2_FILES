/**
 * @file hud_structs.h
 * @brief Структуры HUD интерфейса GTA2
 * 
 * Восстановлено на основе конструктора Hud::Hud и размеров:
 * - Hud: 0x2AF8
 * - HudArrow: 0x848
 * - HudMessage: 0x1C8
 * - HudBrief: 0x704
 * - HudElement: 0x38
 * 
 * Критическое смещение: field_27B8 находится по адресу 0x27B8 внутри Hud.
 */

#pragma once

#include <cstdint>
#include <cstddef>

#ifdef __cplusplus
extern "C" {
#endif

// Forward declarations for unknown sub-structures
struct S86_8;
struct S166;
struct S86_7;
struct S86_4;
struct S86_5;
struct S86_10;
struct S86_9_Item; // Предположительно элемент массива S86_9

/**
 * @brief Базовый элемент HUD (предположительно)
 * Размер: 0x38 (56 байт)
 */
typedef struct HudElement {
    uint8_t data[0x38]; // Заглушка, пока не известны поля
    // old_var: vftable? flags? position?
} HudElement;

/**
 * @brief Стрелка направления / Радар
 * Размер: 0x848 (2120 байт)
 * Инициализируется: HudArrow::HudArrow()
 */
typedef struct HudArrow {
    uint8_t data[0x848]; 
    // old_var: rotation, target_coords, radar_data
} HudArrow;

/**
 * @brief Сообщения на экране (текст миссий, подсказки)
 * Размер: 0x1C8 (456 байт)
 * Инициализируется: HudMessage::HudMessage()
 */
typedef struct HudMessage {
    uint8_t data[0x1C8];
    // old_var: text_buffer, timer, color, priority
} HudMessage;

/**
 * @brief Краткие сообщения (Briefs)
 * Размер: 0x704 (1796 байт)
 * Инициализируется: HudBrief::HudBrief()
 */
typedef struct HudBrief {
    uint8_t data[0x704];
    // old_var: queue, history, display_timer
} HudBrief;

/**
 * @brief Неизвестная структура S86_8
 * Расчет размера: Должна идти после базового класса (если есть) и до HudBrief.
 * Предположим размер ~0x???. Уточним по сумме.
 */
typedef struct S86_8 {
    uint8_t data[0x??]; // TODO: Вычислить точный размер
    // old_var: unknown hud state
} S86_8;

/**
 * @brief Неизвестная структура S166
 * Инициализируется: S166::S166()
 */
typedef struct S166 {
    uint8_t data[0x??]; // TODO: Вычислить точный размер
} S166;

/**
 * @brief Неизвестная структура S86_7
 * Замечена в конструкторе между S166 и HudArrow
 */
typedef struct S86_7 {
    uint8_t data[0x??]; // TODO: Вычислить точный размер
} S86_7;

/**
 * @brief Неизвестная структура S86_4
 * Инициализируется перед field_27B8
 */
typedef struct S86_4 {
    uint8_t data[0x??]; // TODO: Вычислить точный размер
} S86_4;

/**
 * @brief Неизвестная структура S86_5
 * Инициализируется после field_27B8
 */
typedef struct S86_5 {
    uint8_t data[0x??]; // TODO: Вычислить точный размер
} S86_5;

/**
 * @brief Неизвестная структура S86_10
 * Инициализируется после HudMessage
 */
typedef struct S86_10 {
    uint8_t data[0x??]; // TODO: Вычислить точный размер
} S86_10;

/**
 * @brief Неизвестная структура S86_9 (возможно массив или контейнер)
 * Инициализируется через sub_4C6AC0(this->S86_9)
 */
typedef struct S86_9 {
    uint8_t data[0x??]; // TODO: Вычислить размер остатка
} S86_9;

/**
 * @brief Основная структура HUD
 * Общий размер: 0x2AF8 (10992 байта)
 * Глобальный указатель: gHud
 */
typedef struct Hud {
    // 1. Базовый класс / Первый элемент (Hud::Hud1)
    // Предположим, это какой-то базовый блок или vtable
    uint8_t base[0x??]; 

    // 2. S86_8
    S86_8 S86_8;

    // 3. HudBrief (0x704)
    HudBrief HudBrief;

    // 4. S166
    S166 S166;

    // 5. S86_7
    S86_7 S86_7;

    // 6. HudArrow (0x848)
    HudArrow HudArrow;

    // 7. S86_4
    S86_4 struc_S86_4;

    // 8. Некий объект 's' (инициализация sub_4C6E70)
    uint8_t s[0x??];

    // 9. Поле по смещению 0x27B8 (критическая точка!)
    // Все предыдущие поля в сумме должны давать 0x27B8
    uint8_t field_27B8[0x??]; 

    // 10. S86_5
    S86_5 S86_5;

    // 11. HudMessage (0x1C8)
    HudMessage HudMessage;

    // 12. S86_10
    S86_10 S86_10;

    // 13. S86_9
    S86_9 S86_9;

    // 14. TextSpeed (int)
    int32_t TextSpeed;

    // Остаток до 0x2AF8
    uint8_t padding_end[0x??];

} Hud;

// Глобальный указатель
extern Hud* gHud;

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
namespace GTA2 {
namespace UI {
    // C++ обертки будут здесь
}
}
#endif
