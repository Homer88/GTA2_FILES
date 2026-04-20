#ifndef PED_AI_H
#define PED_AI_H

#include "../ped.h"
#include "ped_ai_states.h"
#include "../systems/vector2d.h"

/**
 * @brief Контекст ИИ пешехода
 * Содержит все данные, необходимые для принятия решений.
 */
typedef struct PedAIContext {
    // Цели и задачи
    struct Ped* TargetPed;        // Цель-пешеход
    struct Car* TargetCar;        // Цель-машина
    Vector2D TargetPosition;      // Целевая координата
    float TargetRadius;           // Радиус достижения цели
    
    // Навигация
    Vector2D CurrentDirection;    // Текущее направление движения
    float MoveSpeed;              // Текущая скорость движения
    float MaxWalkSpeed;           // Макс. скорость ходьбы
    float MaxRunSpeed;            // Макс. скорость бега
    float PathProgress;           // Прогресс по маршруту (0.0-1.0)
    
    // Восприятие
    float ViewDistance;           // Дальность зрения
    float HearingDistance;        // Дальность слуха
    float FOV;                    // Угол обзора (в радианах)
    u32 LastSeenThreatTime;       // Время последнего обнаружения угрозы
    u32 LastHeardSoundTime;       // Время последнего услышанного звука
    
    // Поведение
    PedPersonality Personality;   // Тип личности
    float Aggression;             // Уровень агрессии (0.0-1.0)
    float Courage;                // Уровень смелости (0.0-1.0)
    float StressLevel;            // Уровень стресса (растёт при опасности)
    
    // Таймеры
    u32 StateTimer;               // Таймер текущего состояния
    u32 AttackCooldown;           // Перезарядка атаки
    u32 DecisionTimer;            // Таймер принятия решений
    
    // Флаги поведения
    bool IsFollowingOrders;       // Следует приказам (для банд)
    bool IsInCombat;              // В бою
    bool IsSearching;             // Ищет цель/укрытие
    bool HasLineOfSight;          // Есть прямая видимость цели
} PedAIContext;

// ============================================================================
// API Системы ИИ
// ============================================================================

/**
 * @brief Инициализация ИИ пешехода
 * @param ped Указатель на пешехода
 * @param personality Тип личности
 */
void PedAI_Init(struct Ped* ped, PedPersonality personality);

/**
 * @brief Обновление ИИ (вызывается каждый кадр)
 * @param ped Указатель на пешехода
 * @param dt Дельта времени (сек)
 */
void PedAI_Update(struct Ped* ped, float dt);

/**
 * @brief Добавление задачи в очередь
 * @param ped Указатель на пешехода
 * @param type Тип задачи
 * @param priority Приоритет
 * @param data Данные задачи (координаты, указатели)
 * @return true если задача добавлена
 */
bool PedAI_AddTask(struct Ped* ped, TaskType type, TaskPriority priority, void* data);

/**
 * @brief Прерывание текущей задачи
 * @param ped Указатель на пешехода
 * @param newPriority Минимальный приоритет для прерывания
 */
void PedAI_InterruptTask(struct Ped* ped, TaskPriority newPriority);

/**
 * @brief Очистка очереди задач
 * @param ped Указатель на пешехода
 */
void PedAI_ClearTasks(struct Ped* ped);

/**
 * @brief Проверка видимости цели
 * @param ped Указатель на пешехода
 * @param targetX X координата цели
 * @param targetY Y координата цели
 * @return true если цель видна
 */
bool PedAI_CanSee(struct Ped* ped, float targetX, float targetY);

/**
 * @brief Проверка слышимости звука
 * @param ped Указатель на пешехода
 * @param soundX X координата источника звука
 * @param soundY Y координата источника звука
 * @param volume Громкость звука (0.0-1.0)
 * @return true если звук слышен
 */
bool PedAI_CanHear(struct Ped* ped, float soundX, float soundY, float volume);

/**
 * @brief Установка целевой позиции
 * @param ped Указатель на пешехода
 * @param x X координата
 * @param y Y координата
 * @param radius Радиус достижения
 */
void PedAI_SetTargetPosition(struct Ped* ped, float x, float y, float radius);

/**
 * @brief Установка цели-пешехода
 * @param ped Указатель на пешехода
 * @param target Целевой пешеход
 */
void PedAI_SetTargetPed(struct Ped* ped, struct Ped* target);

/**
 * @brief Установка цели-машины
 * @param ped Указатель на пешехода
 * @param target Целевая машина
 */
void PedAI_SetTargetCar(struct Ped* ped, struct Car* target);

/**
 * @brief Принудительный переход в состояние
 * @param ped Указатель на пешехода
 * @param state Новое состояние
 */
void PedAI_ForceState(struct Ped* ped, PedState state);

/**
 * @brief Обработка получения урона
 * @param ped Указатель на пешехода
 * @param attacker Атакующий пешеход
 * @param damageAmount Размер урона
 */
void PedAI_OnDamage(struct Ped* ped, struct Ped* attacker, float damageAmount);

/**
 * @brief Обработка смерти
 * @param ped Указатель на пешехода
 * @param killer Убийца
 */
void PedAI_OnDeath(struct Ped* ped, struct Ped* killer);

/**
 * @brief Попытка посадки в машину
 * @param ped Указатель на пешехода
 * @param car Машина
 * @param doorIndex Индекс двери
 * @return true если посадка началась
 */
bool PedAI_TryEnterCar(struct Ped* ped, struct Car* car, int doorIndex);

/**
 * @brief Попытка выхода из машины
 * @param ped Указатель на пешехода
 * @return true если выход начался
 */
bool PedAI_TryExitCar(struct Ped* ped);

/**
 * @brief Атака цели
 * @param ped Указатель на пешехода
 * @return true если атака выполнена
 */
bool PedAI_PerformAttack(struct Ped* ped);

/**
 * @brief Случайное блуждание
 * @param ped Указатель на пешехода
 * @param dt Дельта времени
 */
void PedAI_Wander(struct Ped* ped, float dt);

/**
 * @brief Побег от точки
 * @param ped Указатель на пешехода
 * @param threatX X координата угрозы
 * @param threatY Y координата угрозы
 * @param dt Дельта времени
 */
void PedAI_Flee(struct Ped* ped, float threatX, float threatY, float dt);

/**
 * @brief Получение строкового названия состояния
 * @param state Состояние
 * @return Строка с названием
 */
const char* PedAI_GetStateName(PedState state);

/**
 * @brief Получение строкового названия задачи
 * @param task Тип задачи
 * @return Строка с названием
 */
const char* PedAI_GetTaskName(TaskType task);

#endif // PED_AI_H
