/**
 * @file game_balance.h
 * @brief Таблицы баланса и настройки геймплея.
 * 
 * Содержит константы и структуры, определяющие баланс игры:
 * урон оружия, цены, характеристики машин, шансы спавна.
 * В оригинале эти данные часто лежат в отдельных таблицах в сегменте данных.
 */

#ifndef GAME_BALANCE_H
#define GAME_BALANCE_H

#include "types.h"
#include "enums.h"

#pragma pack(push, 1)

/**
 * @brief Параметры оружия для баланса.
 * Оригинал IDA: Массив `WeaponStats` / `WPN_STATS`
 */
typedef struct WeaponBalance {
    u8 Type;                // Тип оружия
    u8 DamageBase;          // Базовый урон
    u8 Range;               // Дальность (в клетках)
    u8 FireRate;            // Скорострельность (кадры между выстрелами)
    u8 Accuracy;            // Точность (0-100)
    u8 ReloadTime;          // Время перезарядки (в кадрах)
    u8 AmmoPerPickup;       // Количество патронов в подборе
    u8 Cost;                // Стоимость в магазине (если есть)
} WeaponBalance;

/**
 * @brief Характеристики автомобиля.
 * Оригинал IDA: Массив `CarStats` / `CAR_STATS`
 */
typedef struct CarBalance {
    u8 ModelID;             // ID модели
    u8 Health;              // Прочность кузова
    u8 SpeedMax;            // Максимальная скорость
    u8 Acceleration;        // Ускорение
    u8 Handling;            // Управляемость
    u8 Mass;                // Масса (влияет на инерцию)
    u8 Value;               // Стоимость угона/продажи
    u8 TrafficFreq;         // Частота появления в трафике (0-255)
} CarBalance;

/**
 * @brief Настройки банд.
 * Оригинал IDA: `GangConfig` / `GANG_CFG`
 */
typedef struct GangBalance {
    u8 GangID;              // ID банды
    u8 RespectStart;        // Начальное уважение
    u8 WeaponProb[4];       // Вероятности выдачи оружия (Пистолет, Дробовик, UZI, Огнемет)
    u8 CarProb[3];          // Вероятности типов машин
    u8 Aggression;          // Уровень агрессии (как быстро атакуют)
    u8 TerritorySize;       // Размер территории (радиус)
} GangBalance;

/**
 * @brief Таблица вероятностей погоды.
 */
typedef struct WeatherProbability {
    u8 ClearChance;         // Шанс ясной погоды
    u8 RainChance;          // Шанс дождя
    u8 FogChance;           // Шанс тумана
    u8 SnowChance;          // Шанс снега (если есть)
} WeatherProbability;

/**
 * @brief Глобальная структура баланса игры.
 * Объединяет все таблицы для удобного доступа.
 */
typedef struct GameBalanceData {
    WeaponBalance Weapons[16];      // Таблица оружия
    CarBalance Cars[32];            // Таблица машин
    GangBalance Gangs[8];           // Таблица банд
    WeatherProbability Weather;     // Погода
    u32 WantedScoreTable[10];       // Очки для каждого уровня розыска
    u16 PedHealthBase;              // Базовое здоровье пешехода
    u16 PlayerArmorStart;           // Стартовая броня
    u8  PoliceResponseTime;         // Время прибытия полиции (кадры)
    u8  Reserved[3];                // Выравнивание
} GameBalanceData;

// Внешняя переменная с балансом (инициализируется в .c файле)
extern GameBalanceData g_game_balance;

#pragma pack(pop)

#endif // GAME_BALANCE_H
