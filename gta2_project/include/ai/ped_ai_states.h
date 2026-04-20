#ifndef PED_AI_STATES_H
#define PED_AI_STATES_H

#include "../types.h"

// PedState уже определен в enums.h, используем его напрямую

/**
 * @brief Типы задач в очереди действий
 * Задачи планируют будущее поведение пешехода.
 */
typedef enum TaskType {
    TASK_NONE = 0,            // Нет задачи
    TASK_GOTO_XY = 1,         // Идти к координатам (X, Y)
    TASK_GOTO_OBJ = 2,        // Идти к объекту (Ped*, Car*)
    TASK_WAIT = 3,            // Ждать указанное время
    TASK_ATTACK_PED = 4,      // Атаковать пешехода
    TASK_ATTACK_CAR = 5,      // Атаковать машину
    TASK_ENTER_CAR = 6,       // Сесть в машину
    TASK_EXIT_CAR = 7,        // Выйти из машины
    TASK_FLEE_FROM = 8,       // Бежать от точки/объекта
    TASK_WANDER = 9,          // Случайное блуждание
    TASK_FOLLOW_ROUTE = 10,   // Следовать по маршруту (path node)
    TASK_PLAY_ANIM = 11,      // Проиграть анимацию
    TASK_SAY_LINE = 12        // Произнести фразу
} TaskType;

/**
 * @brief Приоритет задачи
 * Определяет порядок выполнения и возможность прерывания.
 */
typedef enum TaskPriority {
    PRIORITY_LOW = 0,     // Фоновые задачи (wander)
    PRIORITY_NORMAL = 1,  // Обычные задачи (goto)
    PRIORITY_HIGH = 2,    // Важные задачи (attack, enter car)
    PRIORITY_CRITICAL = 3 // Критические (flee, handsup) - прерывают всё
} TaskPriority;

/**
 * @brief Типы поведения (Personality)
 * Влияют на реакцию пешехода в различных ситуациях.
 */
typedef enum PedPersonality {
    PERSONALITY_COWARD = 0,   // Трус: легко пугается, убегает
    PERSONALITY_NORMAL = 1,   // Обычный: стандартное поведение
    PERSONALITY_BRAVE = 2,    // Смелый: реже убегает, чаще атакует
    PERSONALITY_AGGRESSIVE = 3, // Агрессивный: быстро злится, атакует
    PERSONALITY_POLICE = 4    // Полиция: следует закону, арестовывает
} PedPersonality;

#endif // PED_AI_STATES_H
