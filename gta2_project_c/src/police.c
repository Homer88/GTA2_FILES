#include "police.h"

// Инициализация и жизненный цикл
// Адрес: TODO_FIND_ADDRESS
void Police__Init(Police* self) {
    // TODO: Реализация из ассемблера
}

// Адрес: TODO_FIND_ADDRESS
void Police__Update(Police* self) {
    // TODO: Реализация из ассемблера
}

// Адрес: TODO_FIND_ADDRESS
void Police__Reset(Police* self) {
    // TODO: Реализация из ассемблера
}

// Управление уровнем розыска
// Адрес: TODO_FIND_ADDRESS
void Police__SetWantedLevel(Police* self, uint8_t level) {
    // TODO: Реализация из ассемблера
}

// Адрес: TODO_FIND_ADDRESS
uint8_t Police__GetWantedLevel(Police* self) {
    // TODO: Реализация из ассемблера
    return 0;
}

// Адрес: TODO_FIND_ADDRESS
void Police__AddWantedLevel(Police* self, uint8_t amount) {
    // TODO: Реализация из ассемблера
}

// Адрес: TODO_FIND_ADDRESS
void Police__ClearWantedLevel(Police* self) {
    // TODO: Реализация из ассемблера
}

// Преступления
// Адрес: TODO_FIND_ADDRESS
void Police__AddCrime(Police* self, int crimeType, void* pTarget) {
    // TODO: Реализация из ассемблера
}

// Адрес: TODO_FIND_ADDRESS
void Police__ClearCrimes(Police* self) {
    // TODO: Реализация из ассемблера
}

// Спавн и управление юнитами
// Адрес: TODO_FIND_ADDRESS
void Police__SpawnCops(Police* self, float x, float y, int count) {
    // TODO: Реализация из ассемблера
}

// Адрес: TODO_FIND_ADDRESS
void Police__DispatchUnits(Police* self) {
    // TODO: Реализация из ассемблера
}

// Адрес: TODO_FIND_ADDRESS
void Police__StartChase(Police* self, void* pTarget) {
    // TODO: Реализация из ассемблера
}

// Адрес: TODO_FIND_ADDRESS
void Police__EndChase(Police* self) {
    // TODO: Реализация из ассемблера
}

// Взаимодействие
// Адрес: TODO_FIND_ADDRESS
bool Police__Bribe(Police* self, int money) {
    // TODO: Реализация из ассемблера
    return false;
}

// Адрес: TODO_FIND_ADDRESS
void Police__ArrestPlayer(Police* self, void* pPlayer) {
    // TODO: Реализация из ассемблера
}

// Адрес: TODO_FIND_ADDRESS
void Police__KillSuspect(Police* self, void* pSuspect) {
    // TODO: Реализация из ассемблера
}

// Утилиты
// Адрес: TODO_FIND_ADDRESS
bool Police__IsPlayerWanted(Police* self) {
    // TODO: Реализация из ассемблера
    return false;
}

// Адрес: TODO_FIND_ADDRESS
void Police__PlaySiren(Police* self) {
    // TODO: Реализация из ассемблера
}

// Адрес: TODO_FIND_ADDRESS
void Police__StopSiren(Police* self) {
    // TODO: Реализация из ассемблера
}
