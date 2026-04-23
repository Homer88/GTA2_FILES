/**
 * @file MenuItemConfig.cpp
 * @brief Реализация структуры MenuItemConfig (S140)
 * 
 * Конфигурация текстового элемента меню GTA 2
 * Размер: 108 байт
 */

#include "gta2/MenuItemConfig.h"
#include <cstring>
#include <cwchar>

#ifdef __cplusplus

// ============================================================================
// Конструкторы и деструкторы
// ============================================================================

MenuItemConfig::MenuItemConfig()
{
    Reset();
}

MenuItemConfig::~MenuItemConfig()
{
    // Деструктор пустой - нет динамических ресурсов
}

// ============================================================================
// Методы инициализации
// ============================================================================

void MenuItemConfig::Initialize(uint8_t isActive, uint8_t subType,
                                 uint16_t param1, uint16_t param2,
                                 uint16_t selectedIndex, const wchar_t* description)
{
    IsActive = isActive;
    SubType = subType;
    Param1 = param1;
    Param2 = param2;
    SelectedIndex = selectedIndex;
    
    if (description != nullptr)
    {
        SetDescription(description);
    }
}

void MenuItemConfig::SetDescription(const wchar_t* text, size_t maxLength)
{
    if (text == nullptr)
    {
        Description[0] = L'\0';
        return;
    }
    
    // Безопасное копирование с ограничением длины
    size_t copyLen = (maxLength < 49) ? maxLength : 49;
    wcsncpy(Description, text, copyLen);
    Description[copyLen] = L'\0';  // Гарантируем нуль-терминатор
}

void MenuItemConfig::Reset()
{
    IsActive = 0;
    SubType = 0;
    Param1 = 0;
    Param2 = 0;
    SelectedIndex = 0;
    
    // Очищаем строку описания
    std::memset(Description, 0, sizeof(Description));
}

void MenuItemConfig::CopyFrom(const MenuItemConfig& other)
{
    IsActive = other.IsActive;
    SubType = other.SubType;
    Param1 = other.Param1;
    Param2 = other.Param2;
    SelectedIndex = other.SelectedIndex;
    
    // Копируем строку описания
    std::memcpy(Description, other.Description, sizeof(Description));
}

#endif // __cplusplus

// ============================================================================
// C-функции для работы со структурой
// ============================================================================

extern "C" {

void MenuItemConfig_Init(MenuItemConfig_t* config,
                         uint8_t isActive,
                         uint8_t subType,
                         uint16_t param1,
                         uint16_t param2,
                         uint16_t selectedIndex,
                         const wchar_t* description)
{
    if (config == nullptr) return;
    
    config->IsActive = isActive;
    config->SubType = subType;
    config->Param1 = param1;
    config->Param2 = param2;
    config->SelectedIndex = selectedIndex;
    
    if (description != nullptr)
    {
        MenuItemConfig_SetDescription(config, description, 49);
    }
    else
    {
        config->Description[0] = L'\0';
    }
}

void MenuItemConfig_Reset(MenuItemConfig_t* config)
{
    if (config == nullptr) return;
    
    config->IsActive = 0;
    config->SubType = 0;
    config->Param1 = 0;
    config->Param2 = 0;
    config->SelectedIndex = 0;
    config->Description[0] = L'\0';
}

void MenuItemConfig_SetDescription(MenuItemConfig_t* config,
                                   const wchar_t* text,
                                   size_t maxLength)
{
    if (config == nullptr || text == nullptr) return;
    
    size_t copyLen = (maxLength < 49) ? maxLength : 49;
    wcsncpy(config->Description, text, copyLen);
    config->Description[copyLen] = L'\0';
}

int MenuItemConfig_IsActive(const MenuItemConfig_t* config)
{
    if (config == nullptr) return 0;
    return config->IsActive != 0 ? 1 : 0;
}

void MenuItemConfig_Copy(MenuItemConfig_t* dest, const MenuItemConfig_t* src)
{
    if (dest == nullptr || src == nullptr) return;
    
    dest->IsActive = src->IsActive;
    dest->SubType = src->SubType;
    dest->Param1 = src->Param1;
    dest->Param2 = src->Param2;
    dest->SelectedIndex = src->SelectedIndex;
    
    std::memcpy(dest->Description, src->Description, sizeof(dest->Description));
}

} // extern "C"
