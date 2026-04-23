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

// Заглушка для Windows API при компиляции на Linux
#ifndef _WIN32
#include <cstdint>
using HWND = void*;
using HINSTANCE = void*;
using WPARAM = uintptr_t;
using LPARAM = intptr_t;
using UINT = unsigned int;
using LRESULT = intptr_t;
using RECT = struct { int left; int top; int right; int bottom; };
using POINT = struct { int x; int y; };
using MSG = struct { void* hwnd; UINT message; WPARAM wParam; LPARAM lParam; };
#define CW_USEDEFAULT 0x80000000
#define WS_OVERLAPPEDWINDOW 0
#define WS_VISIBLE 0
#define WS_CHILD 0
#define BS_PUSHBUTTON 0
#define ES_NUMBER 0
#define SW_SHOW 0
#define IDI_APPLICATION nullptr
#define IDC_ARROW nullptr
#define WHITE_BRUSH 0
#define WM_DESTROY 0
#define WM_COMMAND 0
#define PostQuitMessage(x) do {} while(0)
#define LoadIcon(x,y) nullptr
#define LoadCursor(x,y) nullptr
#define GetStockObject(x) nullptr
#define RegisterClass(x) 0
#define CreateWindowEx(a,b,c,d,e,f,g,h,i,j,k,l) nullptr
#define ShowWindow(x,y) do {} while(0)
#define UpdateWindow(x) do {} while(0)
#define GetMessage(x,y,z,w) 0
#define TranslateMessage(x) 0
#define DispatchMessage(x) 0
#define DefWindowProc(x,y,z,w) 0
#define SendMessage(x,y,z,w) 0
#define SetWindowText(x,y) do {} while(0)
#define GetWindowText(x,y,z) 0
#define DestroyWindow(x) 0
#else
#include <windows.h>
#endif

#include <cstdint>

// Basic types matching GTA2 binary
using u8 = uint8_t;
using s8 = int8_t;
using u16 = uint16_t;
using s16 = int16_t;
using u32 = uint32_t;
using s32 = int32_t;
using f32 = float;
using f64 = double;

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
// static_assert(sizeof(GameObject) == 0x??, "GameObject size mismatch");
// static_assert(sizeof(Ped) == 0x??, "Ped size mismatch");
// static_assert(sizeof(Car) == 0x??, "Car size mismatch");
// static_assert(sizeof(Player) == 0x8B0, "Player size mismatch");
// static_assert(sizeof(Gang) == 0x??, "Gang size mismatch");
// static_assert(sizeof(Game) == 0x40, "Game size mismatch");

