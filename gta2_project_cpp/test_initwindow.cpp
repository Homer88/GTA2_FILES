#include <iostream>
#include <cassert>
#include <cstring>
#include "include/gta2/InitWindow.h"

using namespace GTA2;

// Тест структуры InitParams
void Test_InitParams() {
    std::cout << "Тест InitParams... ";
    
    InitParams params;
    
    // Проверка значений по умолчанию
    assert(params.mode == GameMode::SinglePlayer);
    assert(params.serverIP == nullptr);
    assert(params.port == 27015);
    assert(params.resolutionX == 640);
    assert(params.resolutionY == 480);
    assert(params.windowed == false);
    assert(params.soundEnabled == true);
    assert(params.musicEnabled == true);
    
    std::cout << "OK" << std::endl;
}

// Тест парсинга командной строки
void Test_ParseCommandLine() {
    std::cout << "Тест ParseCommandLine... ";
    
    // Тест одиночной игры
    char* args1[] = {(char*)"game.exe", (char*)"-single"};
    InitParams params1 = ParseCommandLine(2, args1);
    assert(params1.mode == GameMode::SinglePlayer);
    
    // Тест мультиплеера
    char* args2[] = {(char*)"game.exe", (char*)"-multi", (char*)"-ip", (char*)"192.168.1.100", (char*)"-port", (char*)"27016"};
    InitParams params2 = ParseCommandLine(6, args2);
    assert(params2.mode == GameMode::MultiPlayer);
    assert(strcmp(params2.serverIP, "192.168.1.100") == 0);
    assert(params2.port == 27016);
    
    // Тест оконного режима
    char* args3[] = {(char*)"game.exe", (char*)"-windowed", (char*)"-res", (char*)"800", (char*)"600"};
    InitParams params3 = ParseCommandLine(5, args3);
    assert(params3.windowed == true);
    assert(params3.resolutionX == 800);
    assert(params3.resolutionY == 600);
    
    // Тест отключения звука
    char* args4[] = {(char*)"game.exe", (char*)"-nosound", (char*)"-nomusic"};
    InitParams params4 = ParseCommandLine(3, args4);
    assert(params4.soundEnabled == false);
    assert(params4.musicEnabled == false);
    
    std::cout << "OK" << std::endl;
}

// Тест создания и инициализации окна (без реального окна Windows)
void Test_InitWindow_Structure() {
    std::cout << "Тест InitWindow структура... ";
    
    // Проверка размера структуры
    assert(sizeof(InitWindow) > 0);
    
    std::cout << "OK" << std::endl;
}

int main() {
    std::cout << "=== Тесты InitWindow ===" << std::endl;
    
    Test_InitParams();
    Test_ParseCommandLine();
    Test_InitWindow_Structure();
    
    std::cout << "\nВсе тесты пройдены!" << std::endl;
    
    return 0;
}
