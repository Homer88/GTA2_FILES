// Module: BusInfo (S82)
// Functions working with structure S82 (Public Transport Vehicle)
// Generated from gta2.exe.c
// 
// Критическое исправление: RouteID заменён на RouteNodesPtr (указатель на массив узлов маршрута)

#include "common.h"
#include "BusInfo.h"
#include "RouteNode.h"

// ============================================================================
// BUS INFO FUNCTIONS
// ============================================================================

// Было: S285__FUN_00432c60
// Теперь: BusInfo_UpdateScreenPosition
void __thiscall BusInfo_UpdateScreenPosition(BusInfo *this)
{
  SpriteS1 *pSVar1;
  undefined4 *puVar2;
  undefined4 local_4 [1]; // Временный буфер для экранных координат
  
  pSVar1 = S9_GetActiveSprite((S9 *)&DAT_005e5514);
  puVar2 = (undefined4 *)WorldCoordinateToScreenCoord(&this->field1_0x4, local_4, (int *)pSVar1);
  this->field1_0x4 = *puVar2; // Обновление экранных координат
}

// Новая функция: Инициализация маршрута автобуса
void BusInfo_InitRoute(BusInfo *bus, RouteNode* nodes, uint16_t nodeCount) {
    if (!bus || !nodes) return;
    
    bus->RouteNodesPtr = nodes;
    bus->field14_0x30 = 0; // RouteIndex = 0
    bus->field15_0x31 = 0; // StopTimer = 0
    bus->field16_0x32 = 0; // RouteFlags = 0
}

// Новая функция: Получить текущий узел маршрута
RouteNode* BusInfo_GetCurrentNode(BusInfo *bus) {
    if (!bus || !bus->RouteNodesPtr) return NULL;
    return &bus->RouteNodesPtr[bus->field14_0x30];
}

// Новая функция: Перейти к следующему узлу маршрута
void BusInfo_AdvanceToNextNode(BusInfo *bus) {
    if (!bus || !bus->RouteNodesPtr) return;
    
    RouteNode* currentNode = &bus->RouteNodesPtr[bus->field14_0x30];
    if (currentNode->NextNodeIdx != 0xFFFF) {
        bus->field14_0x30 = currentNode->NextNodeIdx;
    }
}

// Новая функция: Проверка достижения остановки
bool BusInfo_IsAtStop(BusInfo *bus) {
    if (!bus) return false;
    return (bus->field16_0x32 & 0x01) != 0; // Флаг остановки в RouteFlags
}


