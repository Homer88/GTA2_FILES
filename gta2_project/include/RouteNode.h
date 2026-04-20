// Структура: RouteNode
// Узел маршрута общественного транспорта
// Размер: ~12 байт

#ifndef ROUTENODE_H
#define ROUTENODE_H

#include <stdint.h>

// Узел маршрута - точка пути для общественного транспорта
typedef struct RouteNode {
    float X;              // 0x0 - Координата X
    float Y;              // 0x4 - Координата Y
    uint16_t Flags;       // 0x8 - Флаги узла (тип остановки, направление)
    uint16_t NextNodeIdx; // 0xA - Индекс следующего узла в маршруте
} RouteNode, *PRouteNode;

// Массив узлов маршрута
typedef struct RouteNodesArray {
    RouteNode* Nodes;     // Указатель на массив узлов
    uint16_t NodeCount;   // Количество узлов в маршруте
    uint16_t CurrentNode; // Текущий узел маршрута
} RouteNodesArray, *PRouteNodesArray;

#endif // ROUTENODE_H
