#pragma once

#include <cstdint>

namespace gta2 {

/**
 * @brief Структура S20 - Менеджер рендеринга (RenderManager)
 * Размер: 0x2EE4 (12004 байт)
 * Глобальный объект: gRenderManager (Address: 0x5E6CB80 - уточнить по карте)
 * 
 * Отвечает за инициализацию видео, отрисовку спрайтов, управление камерой
 * и работу со списками отрисовки.
 */
struct RenderManager {
    // Смещение 0x00 - 0x?? : Поля видеобуфера, настройки режима
    uint8_t video_buffer[256];      // Примерное поле (требуется уточнение смещений)
    
    // Смещение 0x?? - 0x?? : Параметры камеры
    float camera_x;
    float camera_y;
    float camera_z;
    float camera_angle;
    float camera_zoom;

    // Смещение 0x?? - 0x?? : Счётчики и флаги
    int32_t frame_count;
    int32_t draw_calls;
    uint32_t flags;

    // Смещение 0x?? - 0x2EE4 : Массивы спрайтов, текстур, списки отрисовки
    // (детальная раскладка требует дополнительного анализа дизассемблера)
    uint8_t reserved[0x2EE4 - 0x20]; // Заполнитель до конца размера

    // --- Методы ---

    /**
     * @brief Конструктор
     * Address: 0x44B??? (Требуется точный адрес из MAP/ASM)
     */
    RenderManager();

    /**
     * @brief Деструктор
     * Address: 0x44B???
     */
    ~RenderManager();

    /**
     * @brief Инициализация видеосистемы
     * Address: 0x44B???
     */
    void init();

    /**
     * @brief Сброс настроек рендеринга
     * Address: 0x44B???
     */
    void reset();

    /**
     * @brief Начало кадра (очистка буферов)
     * Address: 0x44B???
     */
    void beginFrame();

    /**
     * @brief Отрисовка кадра (спрайты, геометрия)
     * Address: 0x44B???
     */
    void renderFrame();

    /**
     * @brief Конец кадра (смена буферов)
     * Address: 0x44B???
     */
    void endFrame();

    /**
     * @brief Установка параметров камеры
     * Address: 0x44B???
     * @param x, y, z Координаты
     * @param angle Угол поворота
     * @param zoom Масштаб
     */
    void setCamera(float x, float y, float z, float angle, float zoom);

    /**
     * @brief Отрисовка спрайта
     * Address: 0x44B???
     */
    void drawSprite(int id, float x, float y, float w, float h, uint32_t color);

    /**
     * @brief Отрисовка текста
     * Address: 0x44B???
     */
    void drawText(const char* text, float x, float y, uint32_t color);

    /**
     * @brief Обработка ошибок рендеринга
     * Address: 0x44B???
     */
    void handleError(int code);

    /**
     * @brief Выключение видеосистемы
     * Address: 0x44B???
     */
    void shutdown();
};

// Глобальный экземпляр
extern RenderManager gRenderManager;

} // namespace gta2
