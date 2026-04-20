#ifndef PED_AI_STATES_H
#define PED_AI_STATES_H

#include "../types.h"

/**
 * @brief Основные состояния пешехода (Finite State Machine)
 * Определяют текущее поведение и доступные действия.
 */
typedef enum PedState {
    PED_STATE_IDLE = 0,       // Бездействие, ожидание
    PED_STATE_WALK = 1,       // Обычная ходьба
    PED_STATE_RUN = 2,        // Бег (спешка, погоня)
    PED_STATE_FLEE = 3,       // Побег от угрозы
    PED_STATE_ATTACK = 4,     // Атака цели
    PED_STATE_ENTER_CAR = 5,  // Посадка в машину
    PED_STATE_EXIT_CAR = 6,   // Выход из машины
    PED_STATE_DRIVE = 7,      // Вождение автомобиля
    PED_STATE_PASSENGER = 8,  // Пассажир в машине
    PED_STATE_DIE = 9,        // Процесс смерти (анимация)
    PED_STATE_DEAD = 10,      // Мёртв (тело)
    PED_STATE_STUNNED = 11,   // Оглушён (взрыв, удар)
    PED_STATE_HANDSUP = 12,   // Руки вверх (сдача полиции)
    PED_STATE_WATCH = 13,     // Наблюдение за событием
    PED_STATE_TALK = 14       // Разговор с другим педом
} PedState;

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
    PERSONALITY_COWARD = 0,   // Легко пугается, быстро бежит
    PERSONALITY_NORMAL = 1,   // Стандартное поведение
    PERSONALITY_BRAVE = 2,    // Редко убегает, часто атакует
    PERSONALITY_AGGRESSIVE = 3, // Быстро злится, любит драки
    PERSONALITY_POLICE = 4    // Специфичное для копов
} PedPersonality;

#endif // PED_AI_STATES_H
