#include <iostream>
#include <cassert>
#include <cstring>
#include "gta2/MenuItemConfig.h"

void Test_MenuItemConfig_Size() {
    std::cout << "[TEST] Checking MenuItemConfig size..." << std::endl;
    static_assert(sizeof(MenuItemConfig) == 108, "Size mismatch!");
    std::cout << "  -> Size OK (108 bytes)" << std::endl;
}

void Test_MenuItemConfig_Ctor() {
    std::cout << "[TEST] Testing constructor..." << std::endl;
    MenuItemConfig item;
    
    // После конструктора все поля должны быть 0
    assert(item.IsActive == 0);
    assert(item.SubType == 0);
    assert(item.Param1 == 0);
    assert(item.Param2 == 0);
    assert(item.SelectedIndex == 0);
    assert(item.Description[0] == L'\0');
    
    std::cout << "  -> Constructor OK" << std::endl;
}

void Test_MenuItemConfig_Initialize() {
    std::cout << "[TEST] Testing Initialize() method..." << std::endl;
    MenuItemConfig item;
    
    const wchar_t* testText = L"Test Menu Item";
    item.Initialize(1, 2, 100, 200, 5, testText);
    
    assert(item.IsActive == 1);
    assert(item.SubType == 2);
    assert(item.Param1 == 100);
    assert(item.Param2 == 200);
    assert(item.SelectedIndex == 5);
    assert(wcscmp(item.Description, testText) == 0);
    
    std::cout << "  -> Initialize OK" << std::endl;
}

void Test_MenuItemConfig_SetDescription() {
    std::cout << "[TEST] Testing SetDescription()..." << std::endl;
    MenuItemConfig item;
    
    const wchar_t* shortText = L"Short";
    item.SetDescription(shortText);
    assert(wcscmp(item.Description, shortText) == 0);
    
    // Длинная строка (должна обрезаться)
    const wchar_t* longText = L"This is a very long menu item description that exceeds the maximum length of 49 characters and should be truncated";
    item.SetDescription(longText);
    assert(wcslen(item.Description) <= 49);
    assert(item.Description[49] == L'\0');
    
    // nullptr
    item.SetDescription(nullptr);
    assert(item.Description[0] == L'\0');
    
    std::cout << "  -> SetDescription OK" << std::endl;
}

void Test_MenuItemConfig_Accessors() {
    std::cout << "[TEST] Testing accessor methods..." << std::endl;
    MenuItemConfig item;
    
    // IsActiveElement / SetActive
    assert(!item.IsActiveElement());
    item.SetActive(true);
    assert(item.IsActiveElement());
    assert(item.IsActive == 1);
    
    // SetSubType
    item.SetSubType(5);
    assert(item.SubType == 5);
    
    // SetParam1 / SetParam2
    item.SetParam1(12345);
    item.SetParam2(54321);
    assert(item.Param1 == 12345);
    assert(item.Param2 == 54321);
    
    // SetSelectedIndex / GetSelectedIndex
    item.SetSelectedIndex(7);
    assert(item.GetSelectedIndex() == 7);
    assert(item.SelectedIndex == 7);
    
    std::cout << "  -> Accessors OK" << std::endl;
}

void Test_MenuItemConfig_Reset() {
    std::cout << "[TEST] Testing Reset() method..." << std::endl;
    MenuItemConfig item;
    
    // Инициализируем данными
    item.Initialize(1, 3, 999, 888, 10, L"Test Text");
    
    // Сбрасываем
    item.Reset();
    
    assert(item.IsActive == 0);
    assert(item.SubType == 0);
    assert(item.Param1 == 0);
    assert(item.Param2 == 0);
    assert(item.SelectedIndex == 0);
    assert(item.Description[0] == L'\0');
    
    std::cout << "  -> Reset OK" << std::endl;
}

void Test_MenuItemConfig_CopyFrom() {
    std::cout << "[TEST] Testing CopyFrom() method..." << std::endl;
    MenuItemConfig source;
    MenuItemConfig dest;
    
    const wchar_t* sourceText = L"Source Item";
    source.Initialize(1, 4, 111, 222, 3, sourceText);
    
    dest.CopyFrom(source);
    
    assert(dest.IsActive == source.IsActive);
    assert(dest.SubType == source.SubType);
    assert(dest.Param1 == source.Param1);
    assert(dest.Param2 == source.Param2);
    assert(dest.SelectedIndex == source.SelectedIndex);
    assert(wcscmp(dest.Description, source.Description) == 0);
    
    std::cout << "  -> CopyFrom OK" << std::endl;
}

void Test_MenuItemConfig_C_Functions() {
    std::cout << "[TEST] Testing C-style functions..." << std::endl;
    MenuItemConfig_t config;
    
    const wchar_t* testText = L"C Style Test";
    MenuItemConfig_Init(&config, 1, 2, 333, 444, 8, testText);
    
    assert(config.IsActive == 1);
    assert(config.SubType == 2);
    assert(config.Param1 == 333);
    assert(config.Param2 == 444);
    assert(config.SelectedIndex == 8);
    assert(wcscmp(config.Description, testText) == 0);
    
    // MenuItemConfig_IsActive
    assert(MenuItemConfig_IsActive(&config) == 1);
    
    // MenuItemConfig_Reset
    MenuItemConfig_Reset(&config);
    assert(config.IsActive == 0);
    assert(config.Description[0] == L'\0');
    
    // MenuItemConfig_Copy
    MenuItemConfig_t source;
    MenuItemConfig_Init(&source, 1, 1, 100, 200, 5, L"Source");
    
    MenuItemConfig_t dest;
    MenuItemConfig_Copy(&dest, &source);
    
    assert(dest.IsActive == source.IsActive);
    assert(wcscmp(dest.Description, source.Description) == 0);
    
    std::cout << "  -> C Functions OK" << std::endl;
}

void Test_MenuItemConfig_OffsetLayout() {
    std::cout << "[TEST] Testing field offsets..." << std::endl;
    MenuItemConfig item;
    
    // Проверяем оффсеты полей (должны соответствовать оригиналу)
    assert(offsetof(MenuItemConfig, IsActive) == 0x00);
    assert(offsetof(MenuItemConfig, SubType) == 0x01);
    assert(offsetof(MenuItemConfig, Param1) == 0x02);
    assert(offsetof(MenuItemConfig, Param2) == 0x04);
    assert(offsetof(MenuItemConfig, SelectedIndex) == 0x06);
    assert(offsetof(MenuItemConfig, Description) == 0x08);
    
    std::cout << "  -> Offsets OK" << std::endl;
}

int main() {
    std::cout << "=== Running MenuItemConfig (S140) Tests ===" << std::endl;
    
    Test_MenuItemConfig_Size();
    Test_MenuItemConfig_Ctor();
    Test_MenuItemConfig_Initialize();
    Test_MenuItemConfig_SetDescription();
    Test_MenuItemConfig_Accessors();
    Test_MenuItemConfig_Reset();
    Test_MenuItemConfig_CopyFrom();
    Test_MenuItemConfig_C_Functions();
    Test_MenuItemConfig_OffsetLayout();
    
    std::cout << "=== All Tests Passed ===" << std::endl;
    return 0;
}
