cmake_minimum_required(VERSION 3.10)
project(gta2_project_cpp CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ============================================
# СТАТИЧЕСКАЯ БИБЛИОТЕКА ЯДРА GTA2
# ============================================

set(GTA2_CORE_SOURCES
    src/GameObject.cpp
    src/Weapon.cpp
    src/Gang.cpp
    src/Car.cpp
    src/Ped.cpp
    src/Player.cpp
    src/Game.cpp
    src/InitWindow.cpp
    src/Menu.cpp
    src/PlayerSlotConfig.cpp
    src/MenuItemConfig.cpp
    src/gta2/MenuStringSlot.cpp
    src/gta2/PlayerStats.cpp
    src/MissionObjective.cpp
    src/DebugProfiler.cpp
    src/PathNode.cpp
    src/EntityManager.cpp
)

set(GTA2_CORE_HEADERS
    include/gta2/GameObject.h
    include/gta2/Weapon.h
    include/gta2/Gang.h
    include/gta2/Car.h
    include/gta2/Ped.h
    include/gta2/Player.h
    include/gta2/Game.h
    include/gta2/InitWindow.h
    include/gta2/Menu.h
    include/gta2/PlayerSlotConfig.h
    include/gta2/MenuItemConfig.h
    include/gta2/MenuStringSlot.h
    include/gta2/PlayerStats.h
    include/gta2/DebugProfiler.h
    include/gta2/MissionObjective.h
    include/gta2/PathNode.h
    include/gta2/EntityManager.h
    include/gta2/gta2_forward.h
    include/gta2/gta2_types.h
)

# Создаем статическую библиотеку
add_library(gta2_core STATIC ${GTA2_CORE_SOURCES} ${GTA2_CORE_HEADERS})
target_include_directories(gta2_core PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Компиляторные флаги
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(gta2_core PRIVATE
        -Wall
        -Wextra
        -fno-strict-aliasing
    )
endif()

# Для Windows: подключение WinAPI библиотек
if(WIN32)
    target_link_libraries(gta2_core PUBLIC user32 gdi32)
endif()

# ============================================
# ТЕСТЫ
# ============================================

# Тест структур данных (размеры, оффсеты)
add_executable(test_structures test_all_structures.cpp)
target_link_libraries(test_structures PRIVATE gta2_core)

# Тест InitWindow
add_executable(test_initwindow test_initwindow.cpp)
target_link_libraries(test_initwindow PRIVATE gta2_core)

# Тест MenuSlotConfig
add_executable(test_menuslotconfig test_menuslotconfig.cpp)
target_link_libraries(test_menuslotconfig PRIVATE gta2_core)

# Тест MenuItemConfig (S140)
add_executable(test_menuitemconfig test_menuitemconfig.cpp)
target_link_libraries(test_menuitemconfig PRIVATE gta2_core)

# Тест MenuStringSlot (S140 - новая структура)
add_executable(test_menustringslot test_menustringslot.cpp)
target_link_libraries(test_menustringslot PRIVATE gta2_core)

# Тест PlayerStats (S161 - статистика игрока)
add_executable(test_playerstats test_playerstats.cpp)
target_link_libraries(test_playerstats PRIVATE gta2_core)

# Тест MissionObjective (S25 - цели миссии)
add_executable(test_missionobjective test_missionobjective.cpp)
target_link_libraries(test_missionobjective PRIVATE gta2_core)

# Тест PathNode (S12 - навигационные узлы)
add_executable(test_pathnode test_pathnode.cpp)
target_link_libraries(test_pathnode PRIVATE gta2_core)

# Тест EntityManager (S17 - менеджер сущностей)
add_executable(test_entitymanager test_entitymanager.cpp)
target_link_libraries(test_entitymanager PRIVATE gta2_core)

# ============================================
# ОСНОВНОЕ ПРИЛОЖЕНИЕ (точка входа)
# ============================================

# Создаем main.cpp если нет
if(NOT EXISTS "${CMAKE_SOURCE_DIR}/src/main.cpp")
    file(WRITE "${CMAKE_SOURCE_DIR}/src/main.cpp" 
"#include \"gta2/gta2_types.h\"
#include \"gta2/InitWindow.h\"
#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << \"GTA2 Reversing Project\" << std::endl;
    
    // Парсинг параметров командной строки
    gta2::InitParams params = gta2::ParseCommandLine(argc, argv);
    
    if (params.gameMode == gta2::GameMode::SinglePlayer) {
        std::cout << \"Mode: Single Player\" << std::endl;
    } else {
        std::cout << \"Mode: Multiplayer (Server: \" << params.serverIP 
                  << \":\" << params.port << \")\" << std::endl;
    }
    
    return 0;
}
")
endif()

add_executable(gta2_runner src/main.cpp)
target_link_libraries(gta2_runner PRIVATE gta2_core)

# ============================================
# ЭКСПОРТ КОМПИЛЯЦИОННЫХ ДАННЫХ
# ============================================
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

message(STATUS "GTA2 Core Library: gta2_core (STATIC)")
message(STATUS "Sources: ${GTA2_CORE_SOURCES}")
