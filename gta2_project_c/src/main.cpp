#include "gta2/gta2_types.h"
#include "gta2/InitWindow.h"
#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "GTA2 Reversing Project" << std::endl;
    
    // Парсинг параметров командной строки
    gta2::InitParams params = gta2::ParseCommandLine(argc, argv);
    
    if (params.gameMode == gta2::GameMode::SinglePlayer) {
        std::cout << "Mode: Single Player" << std::endl;
    } else {
        std::cout << "Mode: Multiplayer (Server: " << params.serverIP 
                  << ":" << params.port << ")" << std::endl;
    }
    
    return 0;
}
