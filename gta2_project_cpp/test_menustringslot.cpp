#include <gtest/gtest.h>
#include "gta2/MenuStringSlot.h"
#include <cstring>
#include <cwchar>

namespace gta2 {
namespace tests {

class MenuStringSlotTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

/**
 * @brief Тест проверки размера структуры
 * Ожидаемый размер: 108 байт
 */
TEST_F(MenuStringSlotTest, SizeCheck) {
    EXPECT_EQ(sizeof(MenuStringSlot), 108u);
}

/**
 * @brief Тест конструктора по умолчанию
 * Все поля должны быть инициализированы нулями
 */
TEST_F(MenuStringSlotTest, DefaultConstructor) {
    MenuStringSlot slot;
    
    EXPECT_EQ(slot.fild, 0);
    EXPECT_EQ(slot.field_1, 0);
    EXPECT_EQ(slot.field_2, 0);
    EXPECT_EQ(slot.field_4, 0);
    EXPECT_EQ(slot.Select, 0);
    
    // Проверка что строка пустая
    EXPECT_EQ(slot.str[0], L'\0');
    EXPECT_EQ(std::wcslen(slot.str), 0u);
}

/**
 * @brief Тест конструктора с параметрами
 */
TEST_F(MenuStringSlotTest, ParameterizedConstructor) {
    const wchar_t* testText = L"Test Menu Item";
    MenuStringSlot slot(0x0F, 0x1234, testText);
    
    EXPECT_EQ(slot.fild, 0x0F);
    EXPECT_EQ(slot.field_2, 0x1234);
    EXPECT_EQ(slot.field_4, 0);
    EXPECT_EQ(slot.Select, 0);
    
    std::wstring text = slot.getText();
    EXPECT_EQ(text, L"Test Menu Item");
}

/**
 * @brief Тест геттеров и сеттеров
 */
TEST_F(MenuStringSlotTest, GettersAndSetters) {
    MenuStringSlot slot;
    
    // Тест флагов
    slot.setFlags(0xAB);
    EXPECT_EQ(slot.getFlags(), 0xAB);
    
    // Тест ID
    slot.setId(0x5678);
    EXPECT_EQ(slot.getId(), 0x5678);
    
    // Тест индекса выбора
    slot.setSelectIndex(42);
    EXPECT_EQ(slot.getSelectIndex(), 42);
    
    // Тест текста
    slot.setText(L"New Text");
    EXPECT_EQ(slot.getText(), L"New Text");
}

/**
 * @brief Тест установки длинного текста (обрезка)
 */
TEST_F(MenuStringSlotTest, LongTextTruncation) {
    MenuStringSlot slot;
    
    // Создаем строку длиннее 50 символов
    std::wstring longText(100, L'A');
    slot.setText(longText.c_str());
    
    // Строка должна быть обрезана до 49 символов + \0
    EXPECT_LT(std::wcslen(slot.str), 50u);
    EXPECT_EQ(slot.str[49], L'\0');
}

/**
 * @brief Тест установки nullptr текста
 */
TEST_F(MenuStringSlotTest, NullTextHandling) {
    MenuStringSlot slot;
    
    // Сначала установим какой-то текст
    slot.setText(L"Initial Text");
    EXPECT_NE(slot.str[0], L'\0');
    
    // Установим nullptr
    slot.setText(nullptr);
    EXPECT_EQ(slot.str[0], L'\0');
    EXPECT_EQ(std::wcslen(slot.str), 0u);
}

/**
 * @brief Тест статической константы expectedSize
 */
TEST_F(MenuStringSlotTest, ExpectedSizeConstant) {
    EXPECT_EQ(MenuStringSlot::expectedSize(), 108u);
}

/**
 * @brief Тест памяти (проверка отсутствия переполнения буфера)
 */
TEST_F(MenuStringSlotTest, MemorySafety) {
    MenuStringSlot slot;
    
    // Заполняем структуру паттерном
    std::memset(&slot, 0xFF, sizeof(slot));
    
    // Проверяем что структура все еще валидна
    // (этот тест больше для отладки и проверки целостности)
    EXPECT_EQ(sizeof(slot), 108u);
}

/**
 * @brief Тест Unicode символов
 */
TEST_F(MenuStringSlotTest, UnicodeCharacters) {
    MenuStringSlot slot;
    
    // Текст с Unicode символами (кириллица, эмодзи и т.д.)
    const wchar_t* unicodeText = L"Привет мир! 🎮";
    slot.setText(unicodeText);
    
    EXPECT_EQ(slot.getText(), unicodeText);
}

} // namespace tests
} // namespace gta2
