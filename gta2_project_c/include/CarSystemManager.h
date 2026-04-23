#ifndef CAR_SYSTEM_MANAGER_H
#define CAR_SYSTEM_MANAGER_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief CarSystemManager - Менеджер системы машин в GTA 2
 * 
 * Размер: 4096 байт (предположительно, требует уточнения по дампу)
 * Адрес в памяти: определяется по MAP-файлу
 * 
 * Отвечает за создание, удаление, обновление и управление всеми машинами в игре.
 * Включает логику трафика, спавна, физики и столкновений.
 */
typedef struct CarSystemManager {
    // Поля структуры будут определены после анализа дампа
    // Пока оставляем заглушку для размера
    uint8_t data[4096]; 
} CarSystemManager;

// Глобальные переменные
extern CarSystemManager* pCarSystemManager;      // Указатель на менеджер
extern CarSystemManager gCarSystemManager;       // Глобальный экземпляр
extern CarSystemManager gCarSystemManager2;      // Второй глобальный экземпляр

// ============================================================================
// КОНСТРУКТОР И ДЕСТРУКТОР
// ============================================================================

/**
 * @brief Конструктор CarSystemManager
 * @param self Указатель на экземпляр структуры
 * @return Указатель на инициализированный экземпляр
 * 
 * Инициализирует массивы машин, сбрасывает счётчики, подготавливает систему к работе.
 */
CarSystemManager* CarSystemManager__Constructor(CarSystemManager* self);

/**
 * @brief Деструктор CarSystemManager
 * @param self Указатель на экземпляр структуры
 * 
 * Освобождает ресурсы, удаляет все машины из системы, очищает память.
 */
void CarSystemManager__Destructor(CarSystemManager* self);

// ============================================================================
// ОСНОВНЫЕ МЕТОДЫ УПРАВЛЕНИЯ МАШИНАМИ
// ============================================================================

/**
 * @brief Добавление машины в систему
 * @param self Указатель на экземпляр структуры
 * @param carData Данные машины для добавления
 * @return Индекс добавленной машины или -1 при ошибке
 */
int CarSystemManager__AddCarToSystem(CarSystemManager* self, void* carData);

/**
 * @brief Удаление машины из системы
 * @param self Указатель на экземпляр структуры
 * @param carIndex Индекс машины для удаления
 * @return true если успешно, false иначе
 */
bool CarSystemManager__RemoveCarFromSystem(CarSystemManager* self, int carIndex);

/**
 * @brief Получение машины по индексу
 * @param self Указатель на экземпляр структуры
 * @param carIndex Индекс машины
 * @return Указатель на машину или NULL если не найдена
 */
void* CarSystemManager__GetCar(CarSystemManager* self, int carIndex);

/**
 * @brief Проверка валидности машины
 * @param self Указатель на экземпляр структуры
 * @param carIndex Индекс машины
 * @return true если машина валидна, false иначе
 */
bool CarSystemManager__IsValidCar(CarSystemManager* self, int carIndex);

/**
 * @brief Получение количества машин в системе
 * @param self Указатель на экземпляр структуры
 * @return Количество активных машин
 */
int CarSystemManager__GetCarCount(CarSystemManager* self);

/**
 * @brief Очистка массива машин
 * @param self Указатель на экземпляр структуры
 */
void CarSystemManager__ClearCarArray(CarSystemManager* self);

// ============================================================================
// СПАВН И ДЕСПАВН МАШИН
// ============================================================================

/**
 * @brief Спавн машины в игре
 * @param self Указатель на экземпляр структуры
 * @param x Координата X позиции спавна
 * @param y Координата Y позиции спавна
 * @param type Тип машины
 * @return Индекс заспавненной машины или -1 при ошибке
 */
int CarSystemManager__SpawnCar(CarSystemManager* self, float x, float y, int type);

/**
 * @brief Фактический спавн машины (внутренняя функция)
 * @param self Указатель на экземпляр структуры
 * @param carData Параметры машины для спавна
 * @return true если успешно, false иначе
 */
bool CarSystemManager__ActualSpawnCar(CarSystemManager* self, void* carData);

/**
 * @brief Удаление машины из игры (деспавн)
 * @param self Указатель на экземпляр структуры
 * @param carIndex Индекс машины для удаления
 */
void CarSystemManager__DespawnCar(CarSystemManager* self, int carIndex);

/**
 * @brief Переработка машины (возврат в пул)
 * @param self Указатель на экземпляр структуры
 * @param carIndex Индекс машины
 */
void CarSystemManager__RecycleCar(CarSystemManager* self, int carIndex);

/**
 * @brief Управление спавном машин
 * @param self Указатель на экземпляр структуры
 * @param maxCars Максимальное количество машин
 */
void CarSystemManager__ManageCarSpawning(CarSystemManager* self, int maxCars);

/**
 * @brief Выбор типа трафика для спавна
 * @param self Указатель на экземпляр структуры
 * @param areaType Тип области (центр, окраина и т.д.)
 * @return Тип машины для спавна
 */
int CarSystemManager__SelectTraffic(CarSystemManager* self, int areaType);

// ============================================================================
// ОБНОВЛЕНИЕ И ЛОГИКА
// ============================================================================

/**
 * @brief Обновление состояния всех машин
 * @param self Указатель на экземпляр структуры
 * @param deltaTime Время между кадрами
 */
void CarSystemManager__UpdateCarState(CarSystemManager* self, float deltaTime);

/**
 * @brief Обработка логики машины
 * @param self Указатель на экземпляр структуры
 * @param carIndex Индекс машины
 */
void CarSystemManager__ProcessCarLogic(CarSystemManager* self, int carIndex);

/**
 * @brief Обработка потока трафика
 * @param self Указатель на экземпляр структуры
 */
void CarSystemManager__ProcessTrafficFlow(CarSystemManager* self);

/**
 * @brief Подготовка массива машин к обновлению
 * @param self Указатель на экземпляр структуры
 */
void CarSystemManager__PrepareArray(CarSystemManager* self);

// ============================================================================
// ФИЗИКА И ДВИЖЕНИЕ
// ============================================================================

/**
 * @brief Расчёт физики машины
 * @param self Указатель на экземпляр структуры
 * @param carIndex Индекс машины
 */
void CarSystemManager__CalculateCarPhysics(CarSystemManager* self, int carIndex);

/**
 * @brief Применение сил к машине
 * @param self Указатель на экземпляр структуры
 * @param carIndex Индекс машины
 * @param forceX Сила по оси X
 * @param forceY Сила по оси Y
 */
void CarSystemManager__ApplyCarForces(CarSystemManager* self, int carIndex, float forceX, float forceY);

/**
 * @brief Обновление позиции машины
 * @param self Указатель на экземпляр структуры
 * @param carIndex Индекс машины
 */
void CarSystemManager__UpdateCarPosition(CarSystemManager* self, int carIndex);

/**
 * @brief Получение скорости машины
 * @param self Указатель на экземпляр структуры
 * @param carIndex Индекс машины
 * @return Скорость машины
 */
float CarSystemManager__GetCarSpeed(CarSystemManager* self, int carIndex);

/**
 * @brief Проверка, движется ли машина
 * @param self Указатель на экземпляр структуры
 * @param carIndex Индекс машины
 * @return true если движется, false иначе
 */
bool CarSystemManager__IsCarMoving(CarSystemManager* self, int carIndex);

/**
 * @brief Получение направления движения машины
 * @param self Указатель на экземпляр структуры
 * @param carIndex Индекс машины
 * @return Направление в радианах
 */
float CarSystemManager__GetCarHeading(CarSystemManager* self, int carIndex);

/**
 * @brief Установка направления движения машины
 * @param self Указатель на экземпляр структуры
 * @param carIndex Индекс машины
 * @param heading Новое направление
 */
void CarSystemManager__SetCarHeading(CarSystemManager* self, int carIndex, float heading);

/**
 * @brief Парковка машины
 * @param self Указатель на экземпляр структуры
 * @param carIndex Индекс машины
 * @param spotX Координата X места парковки
 * @param spotY Координата Y места парковки
 */
void CarSystemManager__ParkCar(CarSystemManager* self, int carIndex, float spotX, float spotY);

// ============================================================================
// СТОЛКНОВЕНИЯ И ПОВРЕЖДЕНИЯ
// ============================================================================

/**
 * @brief Проверка столкновений машины
 * @param self Указатель на экземпляр структуры
 * @param carIndex Индекс машины
 * @return true если есть столкновение, false иначе
 */
bool CarSystemManager__CheckCarCollision(CarSystemManager* self, int carIndex);

/**
 * @brief Обработка повреждений машины
 * @param self Указатель на экземпляр структуры
 * @param carIndex Индекс машины
 * @param damageAmount Количество урона
 */
void CarSystemManager__HandleCarDamage(CarSystemManager* self, int carIndex, float damageAmount);

// ============================================================================
// МИССИИ И ЗАДАЧИ
// ============================================================================

/**
 * @brief Назначение машины на миссию
 * @param self Указатель на экземпляр структуры
 * @param carIndex Индекс машины
 * @param missionId ID миссии
 * @return true если успешно, false иначе
 */
bool CarSystemManager__AssignCarToMission(CarSystemManager* self, int carIndex, int missionId);

/**
 * @brief Освобождение машины из миссии
 * @param self Указатель на экземпляр структуры
 * @param carIndex Индекс машины
 */
void CarSystemManager__ReleaseCarFromMission(CarSystemManager* self, int carIndex);

// ============================================================================
// ПОИСК И НАВИГАЦИЯ
// ============================================================================

/**
 * @brief Поиск ближайшей машины
 * @param self Указатель на экземпляр структуры
 * @param x Координата X точки поиска
 * @param y Координата Y точки поиска
 * @param radius Радиус поиска
 * @return Индекс ближайшей машины или -1 если не найдено
 */
int CarSystemManager__FindNearestCar(CarSystemManager* self, float x, float y, float radius);

// ============================================================================
// СОХРАНЕНИЕ И ЗАГРУЗКА
// ============================================================================

/**
 * @brief Сохранение данных о машине
 * @param self Указатель на экземпляр структуры
 * @param carIndex Индекс машины
 * @param saveData Буфер для сохранения
 * @return true если успешно, false иначе
 */
bool CarSystemManager__SaveCarData(CarSystemManager* self, int carIndex, void* saveData);

/**
 * @brief Загрузка данных о машине
 * @param self Указатель на экземпляр структуры
 * @param carIndex Индекс машины
 * @param loadData Буфер с данными для загрузки
 * @return true если успешно, false иначе
 */
bool CarSystemManager__LoadCarData(CarSystemManager* self, int carIndex, void* loadData);

/**
 * @brief Сброс статистики машины
 * @param self Указатель на экземпляр структуры
 * @param carIndex Индекс машины
 */
void CarSystemManager__ResetCarStats(CarSystemManager* self, int carIndex);

// ============================================================================
// УТИЛИТЫ
// ============================================================================

/**
 * @brief Ограничение значений параметров машины
 * @param self Указатель на экземпляр структуры
 * @param carIndex Индекс машины
 * @param minVal Минимальное значение
 * @param maxVal Максимальное значение
 */
void CarSystemManager__ClampValues(CarSystemManager* self, int carIndex, float minVal, float maxVal);

/**
 * @brief Установка индекса машины по умолчанию
 * @param self Указатель на экземпляр структуры
 * @param defaultIndex Индекс по умолчанию
 */
void CarSystemManager__SetIndexDefautCarManager(CarSystemManager* self, int defaultIndex);

/**
 * @brief Очистка всей системы машин
 * @param self Указатель на экземпляр структуры
 */
void CarSystemManager__CleanupCarSystem(CarSystemManager* self);

// ============================================================================
// ОПЕРАТОРЫ СРАВНЕНИЯ (для внутренней логики)
// ============================================================================

bool CarSystemManager__greater_than(CarSystemManager* self, int index1, int index2);
bool CarSystemManager__less_or_equal(CarSystemManager* self, int index1, int index2);
bool CarSystemManager__NotEqual(CarSystemManager* self, int index1, int index2);
bool CarSystemManager__less_than(CarSystemManager* self, int index1, int index2);

#ifdef __cplusplus
}
#endif

#endif // CAR_SYSTEM_MANAGER_H
