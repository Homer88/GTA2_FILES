#include "gang.h"

// ==========================================
// РЕАЛИЗАЦИЯ МЕТОДОВ КЛАССА Gang
// ==========================================

void Gang__Gang(Gang* this) {
    // Адрес: 0x0046C960
    // TODO: Реализовать конструктор по asm
}

void Gang__Gang_Des(Gang* this) {
    // Адрес: 0x00469E50
    // TODO: Реализовать деструктор по asm
}

void Gang__Gang1(Gang* this, Gang* src) {
    // Адрес: 0x00469E40
    // TODO: Реализовать копирующий конструктор по asm
}

void Gang__SetName(Gang* this, const char* name) {
    // Адрес: 0x0046CB40
    // TODO: Реализовать по asm
}

void Gang__SetRespectForPlayer(Gang* this, int playerId, int value) {
    // Адрес: 0x0046CA20
    // TODO: Реализовать по asm
}

int Gang__GetRespectForPlayer(Gang* this, int playerId) {
    // Адрес: 0x0046CAC0
    // TODO: Реализовать по asm
    return 0;
}

void Gang__decreaseRespect(Gang* this, int playerId) {
    // Адрес: 0x0046CA80
    // TODO: Реализовать по asm
}

void Gang__SetWarMaskGang(Gang* this, uint32_t mask) {
    // Адрес: 0x0046CB20
    // TODO: Реализовать по asm
}

void Gang__SetRemap(Gang* this, uint8_t remap) {
    // Адрес: 0x004848A0
    // TODO: Реализовать по asm
}

void Gang__SetWeapon1(Gang* this, int weaponId) {
    // Адрес: 0x004848B0
    // TODO: Реализовать по asm
}

void Gang__SetWeapon2(Gang* this, int weaponId) {
    // Адрес: 0x004848C0
    // TODO: Реализовать по asm
}

void Gang__SetWeapon3(Gang* this, int weaponId) {
    // Адрес: 0x004848D0
    // TODO: Реализовать по asm
}

void Gang__SetTypeCar(Gang* this, int carModel) {
    // Адрес: 0x004848E0
    // TODO: Реализовать по asm
}

void Gang__SetCar_remap(Gang* this, uint8_t remap) {
    // Адрес: 0x004848F0
    // TODO: Реализовать по asm
}

void Gang__SetXYZ(Gang* this, float x, float y, float z) {
    // Адрес: 0x00484910
    // TODO: Реализовать по asm
}

void Gang__SetGang(Gang* this, int type) {
    // Адрес: 0x00484940
    // TODO: Реализовать по asm
}

void Gang__SetKillChar(Gang* this, char ch) {
    // Адрес: 0x00484950
    // TODO: Реализовать по asm
}

void Gang__sub_45D920(Gang* this) {
    // Адрес: 0x0046C920
    // TODO: Реализовать по asm
}

void Gang__sub_45D9E0(Gang* this) {
    // Адрес: 0x0046C9E0
    // TODO: Реализовать по asm
}

void Gang__sub_45DAE0(Gang* this) {
    // Адрес: 0x0046CAE0
    // TODO: Реализовать по asm
}

void Gang__sub_45DB70(Gang* this) {
    // Адрес: 0x0046CB70
    // TODO: Реализовать по asm
}

Gang* Gang__GetVisibleGang(Gang* this) {
    // Адрес: 0x0046CD50
    // TODO: Реализовать по asm
    return (Gang*)0;
}

void Gang__sub_45DE10(Gang* this) {
    // Адрес: 0x0046CE10
    // TODO: Реализовать по asm
}

void Gang__sub_45DEA0(Gang* this) {
    // Адрес: 0x0046CEA0
    // TODO: Реализовать по asm
}

void Gang__Set_475900(Gang* this) {
    // Адрес: 0x00484900
    // TODO: Реализовать по asm
}

// ==========================================
// РЕАЛИЗАЦИЯ МЕТОДОВ КЛАССА Gangs
// ==========================================

void Gangs__Gangs(Gangs* this) {
    // Адрес: 0x00469E60
    // TODO: Реализовать конструктор по asm
}

void Gangs__Gangs_Des(Gangs* this) {
    // Адрес: 0x00469E80
    // TODO: Реализовать деструктор по asm
}

void Gangs__Gangs_des(Gangs* this) {
    // Адрес: 0x0046AEE0
    // TODO: Реализовать по asm
}

void Gangs__IncreaseRespectForPlayer(Gangs* this, int playerId, int value) {
    // Адрес: 0x0046CA40
    // TODO: Реализовать по asm
}

Gang* Gangs__FindByName(Gangs* this, const char* name) {
    // Адрес: 0x0046CBB0
    // TODO: Реализовать по asm
    return (Gang*)0;
}

Gang* Gangs__GetGang(Gangs* this, int id) {
    // Адрес: 0x0046CC20
    // TODO: Реализовать по asm
    return (Gang*)0;
}

void Gangs__SelectGang(Gangs* this, int id) {
    // Адрес: 0x0046CC70
    // TODO: Реализовать по asm
}

int Gangs__AddNewGang(Gangs* this) {
    // Адрес: 0x0046CC90
    // TODO: Реализовать по asm
    return 0;
}

float* Gangs__GetGangPositionByName(Gangs* this, const char* name) {
    // Адрес: 0x0046CCC0
    // TODO: Реализовать по asm
    return (float*)0;
}

Gang* Gangs__FindGangByCarModel(Gangs* this, int carModel) {
    // Адрес: 0x0046CCE0
    // TODO: Реализовать по asm
    return (Gang*)0;
}

Gang* Gangs__GetFirstUsedGang(Gangs* this) {
    // Адрес: 0x0046CD60
    // TODO: Реализовать по asm
    return (Gang*)0;
}

Gang* Gangs__GetNextUsedGang(Gangs* this, Gang* current) {
    // Адрес: 0x0046CDB0
    // TODO: Реализовать по asm
    return (Gang*)0;
}

void Gangs__sub_45DF30(Gangs* this) {
    // Адрес: 0x0046CF30
    // TODO: Реализовать по asm
}
