#ifndef COMMON_H
#define COMMON_H

// Main include file for GTA2 project
#include "types.h"
#include "enums.h"
#include "forward_declarations.h"
// #include "structures_s.h"  // ОТКЛЮЧЕНО: содержит сырые данные IDA, конфликты с новыми структурами
#include "game.h"
#include "player.h"
#include "car.h"
#include "ped.h"

// Global variables
extern Game* gGame;

#endif // COMMON_H
