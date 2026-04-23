#include "gta2/PathNode.h"
#include <cmath>
#include <cstring>

namespace gta2 {

// Глобальные переменные (адреса требуют уточнения по дизассемблеру)
PathNode* gPathNodes = nullptr;
int32_t gPathNodesCount = 0;

/**
 * @brief Инициализация узла
 * Оригинал: S12::sub_?????? (адрес неизвестен)
 * Размер: ~20 байт
 */
void PathNode::init(float posX, float posY, float posZ) {
    x = posX;
    y = posY;
    z = posZ;
    
    // Сброс всех связей в -1 (нет связи)
    for (int i = 0; i < 4; ++i) {
        connectedNodeIndices[i] = -1;
    }
    
    flags = 0;
    trafficLightState = 0;
    oneWayFlags = 0;
    density = 0;
    padding = 0;
}

/**
 * @brief Проверка связи с другим узлом
 * Оригинал: S12::sub_?????? (адрес неизвестен)
 * Размер: ~15 байт
 */
bool PathNode::isConnected(int32_t otherIndex) const {
    for (int i = 0; i < 4; ++i) {
        if (connectedNodeIndices[i] == otherIndex) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Установка связи с другим узлом
 * Оригинал: S12::sub_?????? (адрес неизвестен)
 * Размер: ~12 байт
 */
void PathNode::setConnection(int direction, int32_t targetNodeIndex) {
    if (direction >= 0 && direction < 4) {
        connectedNodeIndices[direction] = targetNodeIndex;
    }
}

/**
 * @brief Поиск ближайшего узла к заданным координатам
 * Оригинал: sub_?????? (адрес неизвестен)
 * Размер: ~80 байт
 * 
 * Алгоритм: перебор всех узлов и поиск минимального расстояния
 */
int32_t PathNode_FindNearest(float x, float y, float z) {
    if (!gPathNodes || gPathNodesCount <= 0) {
        return -1;
    }
    
    int32_t nearestIndex = -1;
    float minDistance = std::numeric_limits<float>::max();
    
    for (int32_t i = 0; i < gPathNodesCount; ++i) {
        float dx = gPathNodes[i].x - x;
        float dy = gPathNodes[i].y - y;
        float dz = gPathNodes[i].z - z;
        
        // Используем квадрат расстояния для оптимизации (без sqrt)
        float distanceSq = dx * dx + dy * dy + dz * dz;
        
        if (distanceSq < minDistance) {
            minDistance = distanceSq;
            nearestIndex = i;
        }
    }
    
    return nearestIndex;
}

/**
 * @brief Построение пути между двумя узлами (алгоритм поиска в ширину)
 * Оригинал: sub_?????? (адрес неизвестен)
 * Размер: ~200 байт
 * 
 * Примечание: Это упрощённая реализация. В оригинале может использоваться
 * более сложный алгоритм с учётом типа дороги, светофоров и т.д.
 */
int32_t PathNode_BuildPath(int32_t startIndex, int32_t endIndex, int32_t* outPath, int32_t maxPathSize) {
    if (!gPathNodes || !outPath || maxPathSize <= 0) {
        return -1;
    }
    
    if (startIndex < 0 || startIndex >= gPathNodesCount ||
        endIndex < 0 || endIndex >= gPathNodesCount) {
        return -1;
    }
    
    if (startIndex == endIndex) {
        outPath[0] = startIndex;
        return 1;
    }
    
    // Упрощённый BFS (поиск в ширину)
    // В реальной игре здесь может быть A* или другой алгоритм
    
    bool* visited = new bool[gPathNodesCount];
    int32_t* parent = new int32_t[gPathNodesCount];
    int32_t* queue = new int32_t[gPathNodesCount];
    
    std::memset(visited, 0, gPathNodesCount * sizeof(bool));
    std::memset(parent, -1, gPathNodesCount * sizeof(int32_t));
    
    int head = 0;
    int tail = 0;
    
    queue[tail++] = startIndex;
    visited[startIndex] = true;
    
    bool found = false;
    
    while (head < tail) {
        int32_t current = queue[head++];
        
        if (current == endIndex) {
            found = true;
            break;
        }
        
        // Проверяем все связи текущего узла
        for (int i = 0; i < 4; ++i) {
            int32_t next = gPathNodes[current].connectedNodeIndices[i];
            
            if (next != -1 && !visited[next]) {
                // Проверка одностороннего движения
                if (gPathNodes[current].isOneWay(i)) {
                    // Если одностороннее, можно двигаться только в направлении связи
                    visited[next] = true;
                    parent[next] = current;
                    queue[tail++] = next;
                } else {
                    // Двустороннее движение
                    visited[next] = true;
                    parent[next] = current;
                    queue[tail++] = next;
                }
            }
        }
    }
    
    int32_t pathLength = 0;
    
    if (found) {
        // Восстанавливаем путь от конца к началу
        int32_t tempPath[1000]; // Максимальная длина пути
        int32_t count = 0;
        
        int32_t current = endIndex;
        while (current != -1) {
            tempPath[count++] = current;
            current = parent[current];
        }
        
        // Переворачиваем путь
        pathLength = (count < maxPathSize) ? count : maxPathSize;
        for (int32_t i = 0; i < pathLength; ++i) {
            outPath[i] = tempPath[count - 1 - i];
        }
    }
    
    delete[] visited;
    delete[] parent;
    delete[] queue;
    
    return found ? pathLength : -1;
}

} // namespace gta2
