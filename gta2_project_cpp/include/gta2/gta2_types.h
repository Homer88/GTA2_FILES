/**
 * @file gta2_types.h
 * @brief Главный заголовочный файл GTA 2 - связывает все структуры и типы
 * 
 * Проект: Reverse Engineering GTA 2 (gta2.exe)
 * Версия DirectX: 6.1 (1998 год)
 * 
 * ВАЖНО: Все адреса функций взяты из gta2.exe.map
 * НЕ использовать структуры DirectX 9 из дампа IDA!
 */

#pragma once

#ifndef _WIN32
    // Заглушки для Linux для компиляции тестов
    typedef void* HWND;
    typedef void* HINSTANCE;
    #define CALLBACK
    typedef int INT;
    typedef unsigned int UINT;
    typedef long LONG;
    typedef long LPARAM;
    typedef long WPARAM;
    typedef long LRESULT;
#else
    #include <windows.h>
#endif

#include <cstdint>

// ============================================================================
// FORWARD DECLARATIONS - порядок важен для корректной компиляции
// ============================================================================

struct GameObject;
struct Ped;
struct Car;
struct Player;
struct Weapon;
struct Gang;
struct Game;

// ============================================================================
// БАЗОВЫЕ ТИПЫ И КОНСТАНТЫ
// ============================================================================

constexpr int MAX_PLAYERS = 6;
constexpr int MAX_PEDS = 256;      // Требует проверки по бинарнику
constexpr int MAX_CARS = 256;      // Требует проверки по бинарнику
constexpr int MAX_GANGS = 32;      // Требует проверки по бинарнику

// Типы состояний игры
enum class GameState : uint32_t {
    STATE_IDLE = 0,
    STATE_LOADING = 1,
    STATE_PLAYING = 2,
    STATE_PAUSED = 3,
    STATE_GAMEOVER = 4
};

// Флаги PED
enum class PedFlags : uint32_t {
    NONE = 0,
    IN_VEHICLE = 0x01,
    IS_PLAYER = 0x02,
    DEAD = 0x04,
    ARMED = 0x08
};

// ============================================================================
// ПОДКЛЮЧЕНИЕ СТРУКТУР В ПРАВИЛЬНОМ ПОРЯДКЕ
// ============================================================================

// 1. GameObject - базовый класс для всех объектов мира
#include "GameObject.h"

// 1.5 Passenger - должен быть перед Car
#include "Passenger.h"

// 2. Weapon - оружие (может использоваться Ped и Player)
#include "Weapon.h"

// 3. Gang - банды (используется в Ped и Player)
#include "Gang.h"

// 4. Car - транспорт (связан с Ped как водитель/пассажир)
#include "Car.h"

// 5. Ped - персонажи (использует Car, Weapon, Gang)
#include "Ped.h"

// 6. Player - игрок (наследует/содержит Ped)
#include "Player.h"

// 7. Game - основная структура управления игрой
#include "Game.h"

// 8. InitWindow - окно инициализации
#include "InitWindow.h"

// 9. Menu - система меню
#include "Menu.h"

// ============================================================================
// ГЛОБАЛЬНЫЕ ЭКЗЕМПЛЯРЫ (адреса будут определены при линковке)
// ============================================================================

// extern Game g_Game;
// extern Ped g_Peds[MAX_PEDS];
// extern Car g_Cars[MAX_CARS];
// extern Gang g_Gangs[MAX_GANGS];

// ============================================================================
// МАКРОСЫ ДЛЯ РАБОТЫ С АДРЕСАМИ
// ============================================================================

// Макрос для получения функции по адресу (для отладки)
#define GET_FUNC_ADDR(className, funcName, addr) \
    static const void* className##_##funcName##_addr = reinterpret_cast<void*>(addr)

// ============================================================================
// ПРОВЕРКИ РАЗМЕРОВ СТРУКТУР (static_assert)
// ============================================================================

// Эти проверки должны быть активированы после восстановления всех структур

