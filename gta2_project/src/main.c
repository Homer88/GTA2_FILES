/**
 * @file main.c
 * @brief Главная точка входа и игровой цикл GTA 2
 * 
 * REVERSE ENGINEERING LOG:
 * IDA Pro Reference: gta2.exe/gid/gta2.exe.c
 * Original Function: entry_point / WinMain
 * Адрес оригинала: 0x00401000 (примерно)
 * 
 * Эта функция объединяет все системы игры в единый цикл.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Ядро
#include "core/memory_pool.h"
#include "core/random.h"
#include "core/time_manager.h"

// Базовые типы
#include "types.h"
#include "enums.h"
#include "game.h"

// Системы
#include "collision.h"
#include "navigation.h"
#include "event_manager.h"
#include "resource_loader.h"
#include "sound_manager.h"
#include "debug_console.h"

// Менеджеры сущностей
#include "vehicle_pool.h"
#include "ped_pool.h"
#include "world_objects.h"

// Геймплей
#include "player.h"
#include "mission_manager.h"
#include "menu_system.h"
#include "hud.h"

// Рендеринг (заглушка, если нет бэкенда)
#include "renderer.h"

// ============================================================================
// Глобальное состояние игры
// ============================================================================

static bool g_game_running = false;
static bool g_is_paused = false;
static f32 g_delta_time = 0.0f;

// ============================================================================
// Инициализация всех подсистем
// ============================================================================

static bool Game_Init(void) {
    printf("[INIT] Запуск GTA 2 Reversed Engine...\n");

    // 1. Инициализация ядра
    printf("[INIT] Инициализация памяти...\n");
    MemManager_Init();
    
    printf("[INIT] Инициализация RNG...\n");
    Random_Init((u32)time(NULL));
    
    printf("[INIT] Инициализация времени...\n");
    TimeManager_Init();

    // 2. Инициализация систем
    printf("[INIT] Инициализация событий...\n");
    EventManager_Init();
    
    printf("[INIT] Инициализация ресурсов...\n");
    if (!ResourceLoader_Init()) {
        fprintf(stderr, "[ERROR] Не удалось загрузить ресурсы!\n");
        return false;
    }
    
    printf("[INIT] Инициализация звука...\n");
    SoundManager_Init();

    // 3. Инициализация менеджеров сущностей
    printf("[INIT] Создание пулов объектов...\n");
    VehiclePool_Init();
    PedPool_Init();
    World_Init();

    // 4. Инициализация геймплея
    printf("[INIT] Инициализация игрока...\n");
    Player_Init();
    
    printf("[INIT] Инициализация миссий...\n");
    MissionManager_Init();
    
    printf("[INIT] Инициализация меню...\n");
    MenuSystem_Init();

    // 5. Инициализация рендерера
    printf("[INIT] Инициализация рендерера...\n");
    Renderer_Init(800, 600);

    // 6. Отладка
    DebugConsole_Init();

    g_game_running = true;
    g_is_paused = false;
    
    printf("[INIT] Игра успешно инициализирована!\n");
    printf("==========================================\n");
    
    return true;
}

// ============================================================================
// Обработка ввода
// ============================================================================

static void Game_ProcessInput(void) {
    // Здесь будет опрос клавиатуры/геймпада
    // Пока заглушка для выхода по ESC
    
    // Пример обработки читов через консоль
    DebugConsole_Update();
    
    // Пауза по P
    // if (Input_IsKeyPressed(KEY_P)) {
    //     g_is_paused = !g_is_paused;
    // }
    
    // Выход по ESC
    // if (Input_IsKeyPressed(KEY_ESCAPE)) {
    //     g_game_running = false;
    // }
}

// ============================================================================
// Обновление игровой логики
// ============================================================================

static void Game_Update(f32 dt) {
    if (g_is_paused) {
        return;
    }

    // 1. Обновление времени
    TimeManager_Update(dt);

    // 2. Обработка событий
    EventManager_ProcessQueue();

    // 3. Обновление менеджеров
    VehiclePool_Update(dt);
    PedPool_Update(dt);
    World_Update(dt);

    // 4. Обновление игрока
    Player_Update(dt);

    // 5. Обновление миссий
    MissionManager_Update(dt);

    // 6. Обновление меню (если активно)
    if (MenuSystem_IsActive()) {
        MenuSystem_Update(dt);
    }

    // 7. Обновление HUD
    HUD_Update(dt);
}

// ============================================================================
// Отрисовка кадра
// ============================================================================

static void Game_Render(void) {
    // Начало кадра
    Renderer_BeginFrame();

    // Очистка экрана
    Renderer_Clear(0x20, 0x20, 0x40); // Темно-синий фон

    if (MenuSystem_IsActive()) {
        // Отрисовка меню
        MenuSystem_Render();
    } else {
        // Отрисовка игрового мира
        Renderer_SetCamera(Player_GetCamera());
        
        // Слои рендеринга
        World_Render();           // Карта, здания
        VehiclePool_Render();     // Машины
        PedPool_Render();         // Пешеходы
        World_RenderParticles();  // Частицы
        
        // Интерфейс
        HUD_Render();
    }

    // Отладочная информация
    DebugConsole_Render();

    // Конец кадра
    Renderer_EndFrame();
}

// ============================================================================
// Завершение работы и очистка
// ============================================================================

static void Game_Shutdown(void) {
    printf("\n[SHUTDOWN] Завершение работы...\n");

    // Сохранение прогресса перед выходом
    printf("[SHUTDOWN] Сохранение игры...\n");
    SaveGame_Save("autosave.sav");

    // Очистка в обратном порядке инициализации
    DebugConsole_Shutdown();
    Renderer_Shutdown();
    MenuSystem_Shutdown();
    MissionManager_Shutdown();
    Player_Shutdown();
    World_Shutdown();
    PedPool_Shutdown();
    VehiclePool_Shutdown();
    SoundManager_Shutdown();
    ResourceLoader_Shutdown();
    EventManager_Shutdown();
    TimeManager_Shutdown();

    printf("[SHUTDOWN] Игра завершена.\n");
}

// ============================================================================
// Главный цикл игры (Game Loop)
// ============================================================================

int main(int argc, char* argv[]) {
    printf("==========================================\n");
    printf("   GTA 2 REVERSED ENGINE\n");
    printf("   Версия: 0.1.0-alpha\n");
    printf("==========================================\n\n");

    // Инициализация
    if (!Game_Init()) {
        fprintf(stderr, "[FATAL] Критическая ошибка инициализации!\n");
        return EXIT_FAILURE;
    }

    u32 frame_count = 0;
    f32 fps_timer = 0.0f;
    f32 fps = 0.0f;

    printf("[MAIN] Запуск игрового цикла...\n\n");

    // Основной цикл
    while (g_game_running) {
        f32 current_time = (f32)clock() / CLOCKS_PER_SEC;
        
        // Расчет delta time (фиксированный шаг для физики)
        g_delta_time = 1.0f / 60.0f; // 60 FPS target

        // 1. Обработка ввода
        Game_ProcessInput();

        // 2. Обновление логики (фиксированный шаг)
        Game_Update(g_delta_time);

        // 3. Отрисовка
        Game_Render();

        // Подсчет FPS
        frame_count++;
        fps_timer += g_delta_time;
        if (fps_timer >= 1.0f) {
            fps = (f32)frame_count / fps_timer;
            frame_count = 0;
            fps_timer = 0.0f;
            
            // Вывод FPS в консоль (можно убрать в релизе)
            // printf("[FPS] %.2f\n", fps);
        }

        // Ограничение частоты кадров (для простоты - без sleep)
        // В реальной реализации нужен таймер или vsync
    }

    // Завершение
    Game_Shutdown();

    return EXIT_SUCCESS;
}

// ============================================================================
// Точки входа для платформо-специфичного кода (Windows)
// ============================================================================

#ifdef _WIN32
#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Подавляем неиспользуемые параметры
    (void)hInstance;
    (void)hPrevInstance;
    (void)lpCmdLine;
    (void)nCmdShow;

    return main(__argc, __argv);
}
#endif
