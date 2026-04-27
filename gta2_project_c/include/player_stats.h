#ifndef PLAYER_STATS_H
#define PLAYER_STATS_H

#include <stdint.h>

/**
 * Структура статистики игрока (PlayerStats)
 * Размер: 0x84 байта (132 байта)
 */
typedef struct PlayerStats {
    /* 0x00 */ uint32_t kills;           // Количество убийств
    /* 0x04 */ uint32_t deaths;          // Количество смертей
    /* 0x08 */ uint32_t shots_fired;     // Количество выстрелов
    /* 0x0C */ uint32_t shots_hit;       // Попаданий
    /* 0x10 */ uint32_t distance_walked; // Пройденное расстояние
    /* 0x14 */ uint32_t distance_driven; // Проеханное расстояние
    /* 0x18 */ uint32_t time_played;     // Время в игре (секунды)
    /* 0x1C */ uint32_t money_earned;    // Заработано денег
    /* 0x20 */ uint32_t money_spent;     // Потрачено денег
    /* 0x24 */ uint32_t missions_passed; // Пройдено миссий
    /* 0x28 */ uint32_t missions_failed; // Провалено миссий
    /* 0x2C */ uint32_t bonuses_collected; // Собрано бонусов
    /* 0x30 */ uint32_t secrets_found;   // Найдено секретов
    /* 0x34 */ uint32_t crimes_committed; // Совершено преступлений
    /* 0x38 */ uint32_t people_killed;   // Убито людей
    /* 0x3C */ uint32_t cops_killed;     // Убито копов
    /* 0x40 */ uint32_t cars_destroyed;  // Уничтожено машин
    /* 0x44 */ uint32_t highest_wanted_level; // Максимальный уровень розыска
    /* 0x48 */ uint32_t times_arrested;  // Количество арестов
    /* 0x4C */ uint32_t times_hospitalized; // Количество госпитализаций
    /* 0x50 */ uint32_t field_50;        // Неизвестно
    /* 0x54 */ uint32_t field_54;        // Неизвестно
    /* 0x58 */ uint32_t field_58;        // Неизвестно
    /* 0x5C */ uint32_t field_5C;        // Неизвестно
    /* 0x60 */ uint32_t field_60;        // Неизвестно
    /* 0x64 */ uint32_t field_64;        // Неизвестно
    /* 0x68 */ uint32_t field_68;        // Неизвестно
    /* 0x6C */ uint32_t field_6C;        // Неизвестно
    /* 0x70 */ uint32_t field_70;        // Неизвестно
    /* 0x74 */ uint32_t field_74;        // Неизвестно
    /* 0x78 */ uint32_t field_78;        // Неизвестно
    /* 0x7C */ uint32_t field_7C;        // Неизвестно
    /* 0x80 */ uint32_t field_80;        // Неизвестно
} PlayerStats;

// Методы (функции) для работы со структурой

/**
 * Конструктор
 * Адрес: 0x0043D100, Размер: 0x34 байта
 */
void PlayerStats__PlayerStats(PlayerStats* self);

/**
 * Деструктор
 * Адрес: 0x0043D140, Размер: 0x10 байт
 */
void PlayerStats__~PlayerStats(PlayerStats* self);

/**
 * Сброс статистики
 * Адрес: 0x0043D160, Размер: 0x48 байт
 */
void PlayerStats__Reset(PlayerStats* self);

/**
 * Добавить убийство
 * Адрес: 0x0043D1B0, Размер: 0x24 байта
 */
void PlayerStats__AddKill(PlayerStats* self);

/**
 * Добавить смерть
 * Адрес: 0x0043D1E0, Размер: 0x24 байта
 */
void PlayerStats__AddDeath(PlayerStats* self);

/**
 * Добавить выстрел
 * Адрес: 0x0043D210, Размер: 0x2A байт
 */
void PlayerStats__AddShot(PlayerStats* self, int hit);

/**
 * Добавить деньги
 * Адрес: 0x0043D240, Размер: 0x2E байт
 */
void PlayerStats__AddMoney(PlayerStats* self, int amount);

/**
 * Добавить преступление
 * Адрес: 0x0043D280, Размер: 0x32 байта
 */
void PlayerStats__AddCrime(PlayerStats* self, int type);

/**
 * Обновить уровень розыска
 * Адрес: 0x0043D2C0, Размер: 0x26 байт
 */
void PlayerStats__UpdateWantedLevel(PlayerStats* self, int level);

/**
 * Добавить пройденную миссию
 * Адрес: 0x0043D2F0, Размер: 0x24 байта
 */
void PlayerStats__AddMissionPassed(PlayerStats* self);

/**
 * Добавить проваленную миссию
 * Адрес: 0x0043D320, Размер: 0x24 байта
 */
void PlayerStats__AddMissionFailed(PlayerStats* self);

/**
 * Сохранение статистики
 * Адрес: 0x0043D350, Размер: 0x86 байт
 */
int PlayerStats__Save(PlayerStats* self, const char* filename);

/**
 * Загрузка статистики
 * Адрес: 0x0043D3E0, Размер: 0x92 байта
 */
int PlayerStats__Load(PlayerStats* self, const char* filename);

/**
 * Очистка всех данных
 * Адрес: 0x0043D480, Размер: 0x38 байт
 */
void PlayerStats__Clear(PlayerStats* self);

/**
 * Подсчет очков
 * Адрес: 0x0043D4C0, Размер: 0x4A байт
 */
uint32_t PlayerStats__CalculateScore(PlayerStats* self);

#endif // PLAYER_STATS_H
