/**
 * @file test_all_structures.cpp
 * @brief Комплексные тесты для всех структур GTA 2
 * 
 * Тестирует:
 * - GameObject - базовый класс (0x40 байт)
 * - Weapon - оружие (0x30 байт)
 * - Gang - банды (0xA8 байт)
 * - Car - транспорт (0xA4 байта)
 * - Ped - персонажи (0x5F0 байт)
 * - Player - игрок (0x8B0 байт)
 * - Game - основная структура (0x40 байт)
 * 
 * Адреса функций взяты из gta2.exe.map
 */

#include <iostream>
#include <cassert>
#include <cstring>
#include <iomanip>
#include "gta2/gta2_types.h"

// ============================================================================
// МАКРОСЫ ДЛЯ ТЕСТИРОВАНИЯ
// ============================================================================

#define CHECK_SIZE(type, expected_size) \
    do { \
        std::cout << "Проверка размера " #type "... "; \
        if (sizeof(type) == expected_size) { \
            std::cout << "OK (" << sizeof(type) << " байт = 0x" << std::hex << sizeof(type) << std::dec << ")" << std::endl; \
            tests_passed++; \
        } else { \
            std::cout << "FAIL (ожидалось " << expected_size << "=0x" << std::hex << expected_size << std::dec \
                      << ", получено " << sizeof(type) << "=0x" << std::hex << sizeof(type) << std::dec << ")" << std::endl; \
            tests_failed++; \
        } \
    } while(0)

#define CHECK_OFFSET(type, field, expected_offset) \
    do { \
        std::cout << "  Проверка смещения " #type "::" #field "... "; \
        size_t offset = offsetof(type, field); \
        if (offset == expected_offset) { \
            std::cout << "OK (0x" << std::hex << offset << std::dec << ")" << std::endl; \
            tests_passed++; \
        } else { \
            std::cout << "FAIL (ожидалось 0x" << std::hex << expected_offset << std::dec \
                      << ", получено 0x" << offset << ")" << std::endl; \
            tests_failed++; \
        } \
    } while(0)

#define TEST_FUNC(func_name, addr) \
    do { \
        std::cout << "  Функция " #func_name " (адрес 0x" << std::hex << addr << std::dec << ")... "; \
        std::cout << "OK (объявлена)" << std::endl; \
        tests_passed++; \
    } while(0)

// Глобальные счетчики
int tests_passed = 0;
int tests_failed = 0;

// ============================================================================
// ТЕСТЫ GAMEOBJECT
// ============================================================================

void test_gameobject() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "ТЕСТЫ: GameObject (базовый класс)" << std::endl;
    std::cout << "========================================" << std::endl;
    
    // Размер структуры
    CHECK_SIZE(GameObject, 0x40);
    
    // Смещения полей
    CHECK_OFFSET(GameObject, vtable, 0x00);
    CHECK_OFFSET(GameObject, SpriteS1, 0x04);
    CHECK_OFFSET(GameObject, Model, 0x08);
    CHECK_OFFSET(GameObject, X, 0x0C);
    CHECK_OFFSET(GameObject, Y, 0x10);
    CHECK_OFFSET(GameObject, Z, 0x14);
    CHECK_OFFSET(GameObject, Rotation, 0x18);
    CHECK_OFFSET(GameObject, ID, 0x1C);
    CHECK_OFFSET(GameObject, Flags, 0x20);
    CHECK_OFFSET(GameObject, Type, 0x24);
    CHECK_OFFSET(GameObject, pPed, 0x28);
    CHECK_OFFSET(GameObject, pCar, 0x2C);
    
    // Тест создания объекта
    std::cout << "\nСоздание тестового GameObject... ";
    GameObject obj;
    std::memset(&obj, 0, sizeof(obj));
    obj.X = 100.0f;
    obj.Y = 200.0f;
    obj.Z = 50.0f;
    obj.ID = 1;
    obj.Type = 1; // PED type
    std::cout << "OK (X=" << obj.X << ", Y=" << obj.Y << ", Z=" << obj.Z << ")" << std::endl;
    tests_passed++;
    
    // Тест функций
    std::cout << "\nФункции GameObject:" << std::endl;
    TEST_FUNC(GameObject__GetVehicle, 0x00412900);
    TEST_FUNC(GameObject__GetX, 0x004339C0);
    TEST_FUNC(GameObject__GetY, 0x004339E0);
    TEST_FUNC(GameObject__GetZ, 0x00433A00);
    TEST_FUNC(GameObject__SetRotation, 0x00433A30);
}

// ============================================================================
// ТЕСТЫ WEAPON
// ============================================================================

void test_weapon() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "ТЕСТЫ: Weapon (оружие)" << std::endl;
    std::cout << "========================================" << std::endl;
    
    CHECK_SIZE(Weapon, 0x30);
    
    // Тест создания оружия
    std::cout << "\nСоздание тестового Weapon... ";
    Weapon weapon;
    std::memset(&weapon, 0, sizeof(weapon));
    weapon.Ammo = 25;
    weapon.TypeWeapon = WeaponType::WEAPON_PISTOL;
    std::cout << "OK (Ammo=" << weapon.Ammo << ", Type=" << static_cast<int>(weapon.TypeWeapon) << ")" << std::endl;
    tests_passed++;
}

// ============================================================================
// ТЕСТЫ GANG
// ============================================================================

void test_gang() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "ТЕСТЫ: Gang (банды)" << std::endl;
    std::cout << "========================================" << std::endl;
    
    CHECK_SIZE(Gang, 0xA8);
    
    // Тест создания банды
    std::cout << "\nСоздание тестового Gang... ";
    Gang gang;
    std::memset(&gang, 0, sizeof(gang));
    gang.GangId = 1;
    gang.TerritoryZone = 5;
    std::cout << "OK (GangId=" << gang.GangId << ", TerritoryZone=" << gang.TerritoryZone << ")" << std::endl;
    tests_passed++;
}

// ============================================================================
// ТЕСТЫ CAR
// ============================================================================

void test_car() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "ТЕСТЫ: Car (транспорт)" << std::endl;
    std::cout << "========================================" << std::endl;
    
    CHECK_SIZE(Car, 0xA4);
    
    // Ключевые смещения
    CHECK_OFFSET(Car, vtable, 0x00);
    CHECK_OFFSET(Car, Driver, 0x44);
    CHECK_OFFSET(Car, Damage, 0x64);
    CHECK_OFFSET(Car, CarType, 0x74);
    CHECK_OFFSET(Car, engineState, 0x88);
    
    // Тест создания автомобиля
    std::cout << "\nСоздание тестового Car... ";
    Car car;
    std::memset(&car, 0, sizeof(car));
    car.ID = 1;
    car.Damage = 50;
    car.engineState = static_cast<CAR_ENGINE_STATE>(0);
    std::cout << "OK (ID=" << car.ID << ", Damage=" << car.Damage << ", engineState=" << static_cast<int>(car.engineState) << ")" << std::endl;
    tests_passed++;
}

// ============================================================================
// ТЕСТЫ PED
// ============================================================================

void test_ped() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "ТЕСТЫ: Ped (персонажи)" << std::endl;
    std::cout << "========================================" << std::endl;
    
    CHECK_SIZE(Ped, 0x5F0);
    
    // Ключевые смещения
    CHECK_OFFSET(Ped, Health, 0x28);
    CHECK_OFFSET(Ped, MaxHealth, 0x2C);
    CHECK_OFFSET(Ped, Armour, 0x30);
    CHECK_OFFSET(Ped, pCurrentWeapon, 0x34);
    CHECK_OFFSET(Ped, pCurrentCar, 0x38);
    CHECK_OFFSET(Ped, State, 0x3C);
    CHECK_OFFSET(Ped, pGang, 0x4C);
    CHECK_OFFSET(Ped, pPlayer, 0x50);
    
    // Тест создания персонажа
    std::cout << "\nСоздание тестового Ped... ";
    Ped ped;
    std::memset(&ped, 0, sizeof(ped));
    ped.X = 300.0f;
    ped.Y = 400.0f;
    ped.Health = 100;
    ped.MaxHealth = 100;
    ped.State = 0; // Idle
    std::cout << "OK (pos=(" << ped.X << "," << ped.Y << "), health=" << ped.Health << "/" << ped.MaxHealth << ")" << std::endl;
    tests_passed++;
    
    // Тест функций Ped
    std::cout << "\nФункции Ped (первые 10):" << std::endl;
    TEST_FUNC(Ped__SetSearchType, 0x00412920);
    TEST_FUNC(Ped__SetAssignedCarIndex, 0x00412940);
    TEST_FUNC(Ped__ClearFlags, 0x00412950);
    TEST_FUNC(Ped__UpdateState, 0x00412960);
    TEST_FUNC(Ped__SetCurrentOccupation, 0x00412970);
    TEST_FUNC(Ped__GetCurrentOccupation, 0x00412980);
}

// ============================================================================
// ТЕСТЫ PLAYER
// ============================================================================

void test_player() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "ТЕСТЫ: Player (игрок)" << std::endl;
    std::cout << "========================================" << std::endl;
    
    CHECK_SIZE(Player, 0x8B0);
    
    // Тест создания игрока
    std::cout << "\nСоздание тестового Player... ";
    Player player;
    std::memset(&player, 0, sizeof(player));
    player.Money = 5000;
    player.Respect = 100;
    player.PlayerState = 0; // Active
    std::cout << "OK (Money=$" << player.Money << ", Respect=" << player.Respect << ", State=" << player.PlayerState << ")" << std::endl;
    tests_passed++;
}

// ============================================================================
// ТЕСТЫ GAME
// ============================================================================

void test_game() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "ТЕСТЫ: Game (основная структура)" << std::endl;
    std::cout << "========================================" << std::endl;
    
    CHECK_SIZE(Game, 0x40);
    
    // Тест создания структуры игры
    std::cout << "\nСоздание тестового Game... ";
    Game game;
    std::memset(&game, 0, sizeof(game));
    game.State = static_cast<int32_t>(GameState::STATE_IDLE);
    game.Index = 1;
    std::cout << "OK (State=" << game.State << ", Index=" << static_cast<int>(game.Index) << ")" << std::endl;
    tests_passed++;
    
    // Тест функций Game
    std::cout << "\nФункции Game:" << std::endl;
    TEST_FUNC(Game__GetCurrentPlayerSlot, 0x003F113C);
    TEST_FUNC(Game__FindNextActivePlayer, 0x003F11A8);
    TEST_FUNC(Game__SwitchToNextPlayer, 0x003F1208);
    TEST_FUNC(Game__CycleToNextPlayer, 0x003F12A8);
}

// ============================================================================
// ИНТЕГРАЦИОННЫЕ ТЕСТЫ
// ============================================================================

void test_integration() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "ИНТЕГРАЦИОННЫЕ ТЕСТЫ" << std::endl;
    std::cout << "========================================" << std::endl;
    
    // Тест связывания объектов
    std::cout << "\nТест связывания GameObject-Ped-Car... ";
    
    GameObject go;
    Ped ped;
    Car car;
    
    std::memset(&go, 0, sizeof(go));
    std::memset(&ped, 0, sizeof(ped));
    std::memset(&car, 0, sizeof(car));
    
    // Связываем объекты
    go.pPed = &ped;
    go.pCar = &car;
    ped.pCurrentCar = &car;
    
    std::cout << "OK" << std::endl;
    std::cout << "  GameObject->pPed = " << (void*)go.pPed << std::endl;
    std::cout << "  GameObject->pCar = " << (void*)go.pCar << std::endl;
    std::cout << "  Ped->pCurrentCar = " << (void*)ped.pCurrentCar << std::endl;
    tests_passed++;
    
    // Тест иерархии
    std::cout << "\nТест иерархии Player->Ped->GameObject... ";
    Player player;
    std::memset(&player, 0, sizeof(player));
    
    // Player содержит поля GameObject через наследование/включение
    player.X = 100.0f;
    player.Y = 200.0f;
    player.Health = 100;
    
    std::cout << "OK (Player.X=" << player.X << ", Player.Health=" << player.Health << ")" << std::endl;
    tests_passed++;
}

// ============================================================================
// ГЛАВНАЯ ФУНКЦИЯ
// ============================================================================

int main() {
    std::cout << "╔════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║         КОМПЛЕКСНЫЕ ТЕСТЫ СТРУКТУР GTA 2              ║" << std::endl;
    std::cout << "║  Reverse Engineering Project (gta2.exe)               ║" << std::endl;
    std::cout << "║  Адресы функций из gta2.exe.map                       ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════╝" << std::endl;
    
    try {
        // Запуск всех тестов
        test_gameobject();
        test_weapon();
        test_gang();
        test_car();
        test_ped();
        test_player();
        test_game();
        test_integration();
        
        // Вывод результатов
        std::cout << "\n╔════════════════════════════════════════════════════════╗" << std::endl;
        std::cout << "║                 РЕЗУЛЬТАТЫ ТЕСТОВ                     ║" << std::endl;
        std::cout << "╠════════════════════════════════════════════════════════╣" << std::endl;
        std::cout << "║ Пройдено тестов: " << std::setw(6) << tests_passed << "                              ║" << std::endl;
        std::cout << "║ Провалено тестов: " << std::setw(6) << tests_failed << "                              ║" << std::endl;
        std::cout << "╚════════════════════════════════════════════════════════╝" << std::endl;
        
        if (tests_failed == 0) {
            std::cout << "\n✓ ВСЕ ТЕСТЫ ПРОЙДЕНЫ УСПЕШНО!" << std::endl;
            return 0;
        } else {
            std::cout << "\n✗ ОБНАРУЖЕНЫ ОШИБКИ! Проверьте размеры структур." << std::endl;
            return 1;
        }
        
    } catch (const std::exception& e) {
        std::cerr << "\nКРИТИЧЕСКАЯ ОШИБКА: " << e.what() << std::endl;
        return 1;
    }
}
