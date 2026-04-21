/**
 * Тест размеров и смещений структур транспорта GTA2
 * 
 * Проверяет целостность иерархии:
 *   S82_BaseCar (0x68 байт) -> базовый класс
 *   S81_PublicTransport (0x7C байт) -> наследник
 * 
 * Компиляция:
 *   gcc -o test_vehicle_structs test_vehicle_structs.c -I../include
 * 
 * Запуск:
 *   ./test_vehicle_structs
 */

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <assert.h>

#include "entities/vehicle_types.h"

// ============================================================================
// МАКРОСЫ ДЛЯ ПРОВЕРКИ
// ============================================================================

#define CHECK_SIZE(type, expected) \
    do { \
        size_t actual = sizeof(struct type); \
        printf("  sizeof(" #type ") = 0x%zX (ожидалось 0x%X) ... ", actual, expected); \
        if (actual == expected) { \
            printf("✓ OK\n"); \
            pass_count++; \
        } else { \
            printf("✗ FAIL\n"); \
            fail_count++; \
        } \
    } while(0)

#define CHECK_OFFSET(type, field, expected) \
    do { \
        size_t actual = offsetof(struct type, field); \
        printf("  offsetof(" #type ", " #field ") = 0x%zX (ожидалось 0x%X) ... ", actual, expected); \
        if (actual == expected) { \
            printf("✓ OK\n"); \
            pass_count++; \
        } else { \
            printf("✗ FAIL\n"); \
            fail_count++; \
        } \
    } while(0)

// ============================================================================
// ГЛОБАЛЬНЫЕ СЧЁТЧИКИ
// ============================================================================

static int pass_count = 0;
static int fail_count = 0;

// ============================================================================
// ОСНОВНАЯ ФУНКЦИЯ ТЕСТА
// ============================================================================

int main() {
    printf("================================================================================\n");
    printf("ТЕСТ СТРУКТУР ТРАНСПОРТА GTA2\n");
    printf("================================================================================\n\n");

    // ------------------------------------------------------------------------
    // Тест 1: S82_BaseCar (базовый класс)
    // ------------------------------------------------------------------------
    printf("[Тест 1] S82_BaseCar - Базовый класс автомобиля\n");
    printf("--------------------------------------------------------------------------------\n");
    
    CHECK_SIZE(S82_BaseCar, 0x68);
    
    // Проверка смещений полей BaseCar
    CHECK_OFFSET(S82_BaseCar, PositionX, 0x00);
    CHECK_OFFSET(S82_BaseCar, PositionY, 0x04);
    CHECK_OFFSET(S82_BaseCar, PositionZ, 0x08);
    CHECK_OFFSET(S82_BaseCar, Heading, 0x0C);
    
    CHECK_OFFSET(S82_BaseCar, Speed, 0x10);
    CHECK_OFFSET(S82_BaseCar, Acceleration, 0x14);
    CHECK_OFFSET(S82_BaseCar, Mass, 0x18);
    CHECK_OFFSET(S82_BaseCar, Friction, 0x1C);
    
    CHECK_OFFSET(S82_BaseCar, VehicleType, 0x20);
    CHECK_OFFSET(S82_BaseCar, Health, 0x24);
    CHECK_OFFSET(S82_BaseCar, MaxHealth, 0x28);
    CHECK_OFFSET(S82_BaseCar, Flags, 0x2C);
    
    CHECK_OFFSET(S82_BaseCar, State, 0x30);
    CHECK_OFFSET(S82_BaseCar, Timer, 0x34);
    CHECK_OFFSET(S82_BaseCar, PassengerCount, 0x38);
    
    CHECK_OFFSET(S82_BaseCar, VelocityX, 0x3C);
    CHECK_OFFSET(S82_BaseCar, VelocityY, 0x40);
    CHECK_OFFSET(S82_BaseCar, AngularVelocity, 0x44);
    
    // Проверка смещений полей BaseCar (обновлённые адреса после реверса)
    CHECK_OFFSET(S82_BaseCar, DamageFlags, 0x48);   // Обновлено: было 0x4C
    CHECK_OFFSET(S82_BaseCar, LightState, 0x4C);    // Обновлено: было 0x50
    CHECK_OFFSET(S82_BaseCar, EngineOn, 0x50);      // Обновлено: было 0x54
    CHECK_OFFSET(S82_BaseCar, Handbrake, 0x51);     // Обновлено: было 0x55
    CHECK_OFFSET(S82_BaseCar, SuspensionHeight, 0x54); // Обновлено: было 0x58
    CHECK_OFFSET(S82_BaseCar, WheelRotation, 0x58); // Обновлено: было 0x5C
    
    printf("\n");

    // ------------------------------------------------------------------------
    // Тест 2: S81_PublicTransport (наследник BaseCar)
    // ------------------------------------------------------------------------
    printf("[Тест 2] S81_PublicTransport - Общественный транспорт\n");
    printf("--------------------------------------------------------------------------------\n");
    
    CHECK_SIZE(S81_PublicTransport, 0x7C);
    
    // Проверка что Base находится в начале
    CHECK_OFFSET(S81_PublicTransport, Base, 0x00);
    
    // Проверка специфичных полей PublicTransport
    CHECK_OFFSET(S81_PublicTransport, RouteNodesPtr, 0x68);
    CHECK_OFFSET(S81_PublicTransport, CurrentRouteIndex, 0x6C);
    CHECK_OFFSET(S81_PublicTransport, NextRouteIndex, 0x6E);
    CHECK_OFFSET(S81_PublicTransport, StopTimer, 0x70);
    CHECK_OFFSET(S81_PublicTransport, RouteFlags, 0x74);
    CHECK_OFFSET(S81_PublicTransport, StopState, 0x75);
    CHECK_OFFSET(S81_PublicTransport, Priority, 0x76);
    CHECK_OFFSET(S81_PublicTransport, RouteID, 0x78);
    
    printf("\n");

    // ------------------------------------------------------------------------
    // Тест 3: Проверка наследования
    // ------------------------------------------------------------------------
    printf("[Тест 3] Проверка наследования\n");
    printf("--------------------------------------------------------------------------------\n");
    
    // Размер Base должен совпадать со смещением последних полей PublicTransport
    size_t base_size = sizeof(struct S82_BaseCar);
    size_t route_ptr_offset = offsetof(struct S81_PublicTransport, RouteNodesPtr);
    
    printf("  Размер S82_BaseCar: 0x%zX\n", base_size);
    printf("  Смещение RouteNodesPtr: 0x%zX\n", route_ptr_offset);
    printf("  Совпадение: ");
    
    if (base_size == route_ptr_offset) {
        printf("✓ OK (наследование корректно)\n");
        pass_count++;
    } else {
        printf("✗ FAIL (нарушено наследование)\n");
        fail_count++;
    }
    
    printf("\n");

    // ------------------------------------------------------------------------
    // Тест 4: Enum VehicleType
    // ------------------------------------------------------------------------
    printf("[Тест 4] Enum VehicleType\n");
    printf("--------------------------------------------------------------------------------\n");
    
    printf("  VEHICLE_TYPE_CAR = %d ... ", VEHICLE_TYPE_CAR);
    if (VEHICLE_TYPE_CAR == 0) { printf("✓ OK\n"); pass_count++; } else { printf("✗ FAIL\n"); fail_count++; }
    
    printf("  VEHICLE_TYPE_BUS = %d ... ", VEHICLE_TYPE_BUS);
    if (VEHICLE_TYPE_BUS == 2) { printf("✓ OK\n"); pass_count++; } else { printf("✗ FAIL\n"); fail_count++; }
    
    printf("  VEHICLE_TYPE_SPECIAL = %d ... ", VEHICLE_TYPE_SPECIAL);
    if (VEHICLE_TYPE_SPECIAL == 15) { printf("✓ OK\n"); pass_count++; } else { printf("✗ FAIL\n"); fail_count++; }
    
    printf("\n");

    // ========================================================================
    // ИТОГОВЫЙ ОТЧЁТ
    // ========================================================================
    printf("================================================================================\n");
    printf("ИТОГИ:\n");
    printf("  Пройдено: %d\n", pass_count);
    printf("  Провалено: %d\n", fail_count);
    printf("  Всего: %d\n", pass_count + fail_count);
    printf("================================================================================\n");
    
    if (fail_count == 0) {
        printf("\n✓ ВСЕ ТЕСТЫ ПРОЙДЕНЫ! Структуры транспорта корректны.\n\n");
        return 0;
    } else {
        printf("\n✗ ОБНАРУЖЕНЫ ОШИБКИ! Требуется проверка структур.\n\n");
        return 1;
    }
}
