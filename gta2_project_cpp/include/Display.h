#pragma once

#include <cstdint>

namespace gta2 {

// Структура S19 (вложенная в Display)
// Размер: 4 байта (предположительно, исходя из размера Display 28 байт / 7 элементов)
struct DisplayMode {
    int32_t field_0; // 0x00 - возможно, флаг или ID режима
};

// Структура S18 -> Display
// Размер: 28 байт (0x1C)
// Содержит массив из 7 структур S19 (DisplayMode)
// Глобальный объект: gDisplay (Address: 0x5E6CB80)
struct Display {
    DisplayMode modes[7]; // 0x00 - массив режимов отображения (7 * 4 = 28 байт)

    // Конструктор
    // Address: 0x44B8F0 (Original: Display__Display)
    Display();

    // Деструктор
    // Address: 0x4699B0 (Original: Display__Display_des)
    ~Display();

    // Метод 1: Инициализация режимов (предположительно)
    // Address: 0x44B890 (Original: Display__sub_44B890)
    void initModes();

    // Метод 2: Сброс режимов (предположительно)
    // Address: 0x44B8B0 (Original: Display__sub_44B8B0)
    void resetModes();

    // Метод 3: Настройка видео (предположительно)
    // Address: 0x44B990 (Original: Display__sub_44B990)
    void setupVideo();

    // Метод 4: Завершение работы видео (предположительно)
    // Address: 0x44B9E0 (Original: Display__sub_44B9E0)
    void shutdownVideo();

    // Метод 5: Дополнительная обработка/обновление (предположительно)
    // Address: 0x4C3950 (Original: Display__sub_4C3950)
    void update();
};

// Глобальная переменная (если существует, адрес уточнить)
// extern Display gDisplay;

} // namespace gta2
