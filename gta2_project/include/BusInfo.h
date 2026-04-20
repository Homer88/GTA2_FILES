// Структура: BusInfo (S82)
// Общественный транспорт (автобусы)
// Размер: ~56 байт

#ifndef BUSINFO_H
#define BUSINFO_H

#include "structures_s.h"

// Structure definition for S82 (Public Transport Vehicle)
// Исправлено: RouteID заменён на RouteNodesPtr (указатель на массив узлов маршрута)

typedef struct S82 BusInfo;

#endif // BUSINFO_H
