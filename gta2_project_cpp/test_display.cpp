#include "gta2/Display.h"
#include <cassert>
#include <iostream>
#include <cstring>

using namespace gta2;

// Тест размера структуры
void test_display_size() {
    assert(sizeof(Display) == 28);
    std::cout << "[PASS] Display size is 28 bytes" << std::endl;
}

// Тест конструктора
void test_display_constructor() {
    Display display;
    // Проверка, что массив modes инициализирован нулями
    for (int i = 0; i < 7; ++i) {
        assert(display.modes[i].field_0 == 0);
    }
    std::cout << "[PASS] Display constructor initializes modes to zero" << std::endl;
}

// Тест initModes
void test_display_init_modes() {
    Display display;
    // Изменим значения
    for (int i = 0; i < 7; ++i) {
        display.modes[i].field_0 = i + 1;
    }
    // Вызовем initModes
    display.initModes();
    // Проверим, что всё сброшено
    for (int i = 0; i < 7; ++i) {
        assert(display.modes[i].field_0 == 0);
    }
    std::cout << "[PASS] Display::initModes resets all modes" << std::endl;
}

// Тест resetModes
void test_display_reset_modes() {
    Display display;
    // Изменим значения
    for (int i = 0; i < 7; ++i) {
        display.modes[i].field_0 = 100 + i;
    }
    // Вызовем resetModes
    display.resetModes();
    // Проверим, что всё сброшено
    for (int i = 0; i < 7; ++i) {
        assert(display.modes[i].field_0 == 0);
    }
    std::cout << "[PASS] Display::resetModes resets all modes" << std::endl;
}

// Тест setupVideo (заглушка - просто проверяем, что вызывается без крэша)
void test_display_setup_video() {
    Display display;
    display.setupVideo();
    std::cout << "[PASS] Display::setupVideo called successfully" << std::endl;
}

// Тест shutdownVideo (заглушка)
void test_display_shutdown_video() {
    Display display;
    display.shutdownVideo();
    std::cout << "[PASS] Display::shutdownVideo called successfully" << std::endl;
}

// Тест handleError (заглушка)
void test_display_handle_error() {
    Display display;
    display.handleError(42);
    std::cout << "[PASS] Display::handleError called successfully" << std::endl;
}

// Тест деструктора
void test_display_destructor() {
    {
        Display display;
        // Деструктор вызовется автоматически
    }
    std::cout << "[PASS] Display destructor works" << std::endl;
}

int main() {
    std::cout << "=== Running Display Tests ===" << std::endl;
    
    test_display_size();
    test_display_constructor();
    test_display_init_modes();
    test_display_reset_modes();
    test_display_setup_video();
    test_display_shutdown_video();
    test_display_handle_error();
    test_display_destructor();
    
    std::cout << "=== All Display Tests Passed! ===" << std::endl;
    return 0;
}
