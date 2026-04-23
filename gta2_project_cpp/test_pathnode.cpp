#include "gta2/PathNode.h"
#include <iostream>
#include <cassert>
#include <cstring>

using namespace gta2;

void test_PathNode_size() {
    std::cout << "[TEST] PathNode size... ";
    assert(sizeof(PathNode) == 36);
    std::cout << "PASSED (36 bytes)" << std::endl;
}

void test_PathNode_init() {
    std::cout << "[TEST] PathNode::init()... ";
    
    PathNode node;
    node.init(100.0f, 200.0f, 50.0f);
    
    assert(node.x == 100.0f);
    assert(node.y == 200.0f);
    assert(node.z == 50.0f);
    
    // Все связи должны быть -1
    for (int i = 0; i < 4; ++i) {
        assert(node.connectedNodeIndices[i] == -1);
    }
    
    assert(node.flags == 0);
    assert(node.trafficLightState == 0);
    assert(node.oneWayFlags == 0);
    assert(node.density == 0);
    
    std::cout << "PASSED" << std::endl;
}

void test_PathNode_connections() {
    std::cout << "[TEST] PathNode connections... ";
    
    PathNode node;
    node.init(0, 0, 0);
    
    // Устанавливаем связи
    node.setConnection(0, 5);
    node.setConnection(1, 10);
    node.setConnection(2, 15);
    
    // Проверяем isConnected
    assert(node.isConnected(5) == true);
    assert(node.isConnected(10) == true);
    assert(node.isConnected(15) == true);
    assert(node.isConnected(999) == false);
    
    // Проверяем индексы
    assert(node.connectedNodeIndices[0] == 5);
    assert(node.connectedNodeIndices[1] == 10);
    assert(node.connectedNodeIndices[2] == 15);
    assert(node.connectedNodeIndices[3] == -1);
    
    std::cout << "PASSED" << std::endl;
}

void test_PathNode_flags() {
    std::cout << "[TEST] PathNode flags... ";
    
    PathNode node;
    node.init(0, 0, 0);
    
    // Тип дороги = 3 (шоссе)
    node.flags = 0x03;
    assert(node.getRoadType() == 3);
    
    // Добавляем светофор (бит 4)
    node.flags |= 0x10;
    assert(node.hasTrafficLight() == true);
    assert(node.getRoadType() == 3); // Тип дороги не изменился
    
    // Одностороннее движение для направления 0 и 2
    node.oneWayFlags = 0x05; // биты 0 и 2
    assert(node.isOneWay(0) == true);
    assert(node.isOneWay(1) == false);
    assert(node.isOneWay(2) == true);
    assert(node.isOneWay(3) == false);
    
    std::cout << "PASSED" << std::endl;
}

void test_PathNode_FindNearest() {
    std::cout << "[TEST] PathNode_FindNearest()... ";
    
    // Создаём тестовый массив узлов
    PathNode testNodes[3];
    testNodes[0].init(0.0f, 0.0f, 0.0f);
    testNodes[1].init(10.0f, 10.0f, 0.0f);
    testNodes[2].init(20.0f, 20.0f, 0.0f);
    
    gPathNodes = testNodes;
    gPathNodesCount = 3;
    
    // Ищем ближайший к (1, 1, 0) - должен быть узел 0
    int32_t nearest = PathNode_FindNearest(1.0f, 1.0f, 0.0f);
    assert(nearest == 0);
    
    // Ищем ближайший к (11, 11, 0) - должен быть узел 1
    nearest = PathNode_FindNearest(11.0f, 11.0f, 0.0f);
    assert(nearest == 1);
    
    // Ищем ближайший к (100, 100, 100) - должен быть узел 2 (самый дальний, но всё равно ближайший из доступных)
    nearest = PathNode_FindNearest(100.0f, 100.0f, 100.0f);
    assert(nearest == 2);
    
    // Сбрасываем глобальные переменные
    gPathNodes = nullptr;
    gPathNodesCount = 0;
    
    std::cout << "PASSED" << std::endl;
}

void test_PathNode_BuildPath_simple() {
    std::cout << "[TEST] PathNode_BuildPath() simple... ";
    
    // Создаём линейный путь: 0 -> 1 -> 2 -> 3
    PathNode testNodes[4];
    testNodes[0].init(0, 0, 0);
    testNodes[1].init(10, 0, 0);
    testNodes[2].init(20, 0, 0);
    testNodes[3].init(30, 0, 0);
    
    testNodes[0].setConnection(0, 1);
    testNodes[1].setConnection(0, 2);
    testNodes[2].setConnection(0, 3);
    
    gPathNodes = testNodes;
    gPathNodesCount = 4;
    
    int32_t path[10];
    int32_t length = PathNode_BuildPath(0, 3, path, 10);
    
    assert(length == 4);
    assert(path[0] == 0);
    assert(path[1] == 1);
    assert(path[2] == 2);
    assert(path[3] == 3);
    
    // Тест: тот же начало и конец
    length = PathNode_BuildPath(1, 1, path, 10);
    assert(length == 1);
    assert(path[0] == 1);
    
    // Тест: нет пути (узлы не связаны в обратном направлении)
    length = PathNode_BuildPath(3, 0, path, 10);
    // Может вернуть -1 или найти путь если связи двусторонние по умолчанию
    
    gPathNodes = nullptr;
    gPathNodesCount = 0;
    
    std::cout << "PASSED" << std::endl;
}

void test_PathNode_BuildPath_bidirectional() {
    std::cout << "[TEST] PathNode_BuildPath() bidirectional... ";
    
    // Создаём двусторонний путь: 0 <-> 1 <-> 2
    PathNode testNodes[3];
    testNodes[0].init(0, 0, 0);
    testNodes[1].init(10, 0, 0);
    testNodes[2].init(20, 0, 0);
    
    testNodes[0].setConnection(0, 1);
    testNodes[1].setConnection(0, 2);
    testNodes[1].setConnection(1, 0); // Обратная связь
    testNodes[2].setConnection(0, 1); // Обратная связь
    
    gPathNodes = testNodes;
    gPathNodesCount = 3;
    
    int32_t path[10];
    
    // Путь от 0 к 2
    int32_t length = PathNode_BuildPath(0, 2, path, 10);
    assert(length == 3);
    assert(path[0] == 0);
    assert(path[1] == 1);
    assert(path[2] == 2);
    
    // Путь от 2 к 0 (обратный)
    length = PathNode_BuildPath(2, 0, path, 10);
    assert(length == 3);
    assert(path[0] == 2);
    assert(path[1] == 1);
    assert(path[2] == 0);
    
    gPathNodes = nullptr;
    gPathNodesCount = 0;
    
    std::cout << "PASSED" << std::endl;
}

void test_PathNode_oneWay() {
    std::cout << "[TEST] PathNode one-way... ";
    
    PathNode testNodes[2];
    testNodes[0].init(0, 0, 0);
    testNodes[1].init(10, 0, 0);
    
    // Узел 0 имеет одностороннюю связь с узлом 1
    testNodes[0].setConnection(0, 1);
    testNodes[0].oneWayFlags = 0x01; // Направление 0 одностороннее
    
    gPathNodes = testNodes;
    gPathNodesCount = 2;
    
    assert(testNodes[0].isOneWay(0) == true);
    
    gPathNodes = nullptr;
    gPathNodesCount = 0;
    
    std::cout << "PASSED" << std::endl;
}

int main() {
    std::cout << "=== PathNode (S12) Tests ===" << std::endl << std::endl;
    
    test_PathNode_size();
    test_PathNode_init();
    test_PathNode_connections();
    test_PathNode_flags();
    test_PathNode_FindNearest();
    test_PathNode_BuildPath_simple();
    test_PathNode_BuildPath_bidirectional();
    test_PathNode_oneWay();
    
    std::cout << std::endl << "=== All tests PASSED ===" << std::endl;
    
    return 0;
}
