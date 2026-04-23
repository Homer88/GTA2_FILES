#ifndef GTA2_PATH_NODE_H
#define GTA2_PATH_NODE_H

#include <cstdint>

namespace gta2 {

/**
 * @brief Структура S12 - точка маршрута (навигационный узел)
 * 
 * Оригинал: S12
 * Размер: 36 байт (0x24)
 * Описание: Используется для построения путей движения транспорта и пешеходов.
 *            Содержит координаты, связи с другими узлами, тип дороги и параметры светофора.
 */
#pragma pack(push, 1)
struct PathNode {
    // Смещение 0x00 (12 байт): Позиция узла в мире
    float x;       // Координата X
    float y;       // Координата Y
    float z;       // Координата Z (высота)

    // Смещение 0x0C (16 байт): Индексы связанных узлов (до 4 направлений)
    // -1 означает отсутствие связи в данном направлении
    int32_t connectedNodeIndices[4];

    // Смещение 0x1C (1 байт): Флаги и тип узла
    // Биты 0-3: Тип дороги (0=обычная, 1=шоссе, 2=аллея, и т.д.)
    // Бит 4: Наличие светофора
    // Бит 5: Одностороннее движение
    // Бит 6-7: Зарезервировано
    uint8_t flags;

    // Смещение 0x1D (1 байт): Состояние светофора (если есть)
    // 0=зеленый, 1=желтый, 2=красный, 3=выключен
    uint8_t trafficLightState;

    // Смещение 0x1E (1 байт): Флаги одностороннего движения по направлениям
    // Каждый бит соответствует направлению в connectedNodeIndices
    uint8_t oneWayFlags;

    // Смещение 0x1F (1 байт): Плотность трафика (0-255)
    // Влияет на вероятность появления машин на этом участке
    uint8_t density;

    // Смещение 0x20-0x23 (4 байта): Выравнивание/зарезервировано
    uint32_t padding;

    /**
     * @brief Инициализация узла
     * Оригинал: sub_?????? (адрес неизвестен)
     */
    void init(float posX, float posY, float posZ);

    /**
     * @brief Проверка связи с другим узлом
     * @param otherIndex Индекс другого узла
     * @return true если узлы соединены
     * Оригинал: sub_??????
     */
    bool isConnected(int32_t otherIndex) const;

    /**
     * @brief Установка связи с другим узлом
     * @param direction Направление (0-3)
     * @param targetNodeIndex Индекс целевого узла
     * Оригинал: sub_??????
     */
    void setConnection(int direction, int32_t targetNodeIndex);

    /**
     * @brief Получение типа дороги
     * @return Тип дороги (0-15)
     */
    uint8_t getRoadType() const { return flags & 0x0F; }

    /**
     * @brief Проверка наличия светофора
     * @return true если есть светофор
     */
    bool hasTrafficLight() const { return (flags & 0x10) != 0; }

    /**
     * @brief Проверка одностороннего движения
     * @param direction Направление (0-3)
     * @return true если движение одностороннее в этом направлении
     */
    bool isOneWay(int direction) const { return (oneWayFlags & (1 << direction)) != 0; }
};
#pragma pack(pop)

// Статический размер структуры
static_assert(sizeof(PathNode) == 36, "PathNode must be 36 bytes");

/**
 * @brief Глобальный массив всех узлов пути
 * Оригинал: gS12 или аналогичный
 * Адрес: 0x?????? (требуется уточнение)
 * Размер массива: зависит от карты
 */
extern PathNode* gPathNodes;
extern int32_t gPathNodesCount;

/**
 * @brief Поиск ближайшего узла к заданным координатам
 * @param x Координата X
 * @param y Координата Y
 * @param z Координата Z
 * @return Индекс ближайшего узла или -1 если не найдено
 * Оригинал: sub_??????
 */
int32_t PathNode_FindNearest(float x, float y, float z);

/**
 * @brief Построение пути между двумя узлами
 * @param startIndex Индекс начального узла
 * @param endIndex Индекс конечного узла
 * @param outPath Массив для сохранения пути
 * @param maxPathSize Максимальный размер массива пути
 * @return Количество узлов в пути или -1 если путь не найден
 * Оригинал: sub_??????
 */
int32_t PathNode_BuildPath(int32_t startIndex, int32_t endIndex, int32_t* outPath, int32_t maxPathSize);

} // namespace gta2

#endif // GTA2_PATH_NODE_H
