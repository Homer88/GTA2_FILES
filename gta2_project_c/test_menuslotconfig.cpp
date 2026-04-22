#include <iostream>
#include <cassert>
#include "gta2/MenuSlotConfig.h"

void Test_MenuSlotConfig_Size() {
    std::cout << "[TEST] Checking MenuSlotConfig size..." << std::endl;
    static_assert(sizeof(MenuSlotConfig) == 0x08, "Size mismatch!");
    std::cout << "  -> Size OK (0x08)" << std::endl;
}

void Test_MenuSlotConfig_Init() {
    std::cout << "[TEST] Testing Init() method..." << std::endl;
    MenuSlotConfig slot;
    
    // После конструктора
    assert(slot.slotId == 0xFF);
    assert(slot.inputDevice == 0);
    
    slot.Init();
    assert(slot.slotId == 0xFF);
    assert(slot.flags == 0);
    
    std::cout << "  -> Init OK" << std::endl;
}

void Test_MenuSlotConfig_InputDevice() {
    std::cout << "[TEST] Testing SetInputDevice()..." << std::endl;
    MenuSlotConfig slot;
    
    assert(!slot.IsActive());
    
    slot.SetInputDevice(1); // Геймпад
    assert(slot.inputDevice == 1);
    assert(slot.IsActive());
    
    std::cout << "  -> InputDevice OK" << std::endl;
}

int main() {
    std::cout << "=== Running MenuSlotConfig Tests ===" << std::endl;
    
    Test_MenuSlotConfig_Size();
    Test_MenuSlotConfig_Init();
    Test_MenuSlotConfig_InputDevice();
    
    std::cout << "=== All Tests Passed ===" << std::endl;
    return 0;
}
