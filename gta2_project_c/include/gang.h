#ifndef GANG_H
#define GANG_H

#include <stdint.h>
#include <stdbool.h>

// Структура банды Gang
// Размер требует уточнения по asm (конструктор 0x0046C960)
// Глобальный менеджер: gGangs (0x0046F898)

typedef struct Gang Gang;
typedef struct Gangs Gangs;

// Перечисление отношений
typedef enum {
    GANG_RELATION_NEUTRAL = 0,
    GANG_RELATION_ALLY = 1,
    GANG_RELATION_ENEMY = 2,
    GANG_RELATION_WAR = 3
} GangRelation;

// Структура одной банды (поля предположительные, требуют уточнения по asm)
struct Gang {
    char     name[24];        // Имя банды
    int      colors[2];       // Цвета
    int      carModel;        // Модель машины
    int      weapons[3];      // Оружие
    int      gangType;        // Тип банды
    float    spawnX, spawnY, spawnZ; // Координаты
    int      respect[4];      // Уважение
    uint32_t warMask;         // Маска войны
    uint8_t  remap;           // Перекраска
    uint8_t  carRemap;        // Перекраска авто
    uint8_t  killChar;        // Символ убийства
    uint8_t  padding;
};

// Менеджер гангов
struct Gangs {
    Gang gangsArray[32];
    int    count;
    int    selectedGangId;
};

// ==========================================
// МЕТОДЫ КЛАССА Gang (Реальные адреса из gta2.map)
// ==========================================

// Конструктор / Деструктор
void Gang__Gang(Gang* this);                 // 0x0046C960
void Gang__Gang_Des(Gang* this);             // 0x00469E50
void Gang__Gang1(Gang* this, Gang* src);     // 0x00469E40

// Свойства и настройка
void Gang__SetName(Gang* this, const char* name);       // 0x0046CB40
void Gang__SetRespectForPlayer(Gang* this, int playerId, int value); // 0x0046CA20
int  Gang__GetRespectForPlayer(Gang* this, int playerId); // 0x0046CAC0
void Gang__decreaseRespect(Gang* this, int playerId);   // 0x0046CA80
void Gang__SetWarMaskGang(Gang* this, uint32_t mask);   // 0x0046CB20
void Gang__SetRemap(Gang* this, uint8_t remap);         // 0x004848A0
void Gang__SetWeapon1(Gang* this, int weaponId);        // 0x004848B0
void Gang__SetWeapon2(Gang* this, int weaponId);        // 0x004848C0
void Gang__SetWeapon3(Gang* this, int weaponId);        // 0x004848D0
void Gang__SetTypeCar(Gang* this, int carModel);        // 0x004848E0
void Gang__SetCar_remap(Gang* this, uint8_t remap);     // 0x004848F0
void Gang__SetXYZ(Gang* this, float x, float y, float z); // 0x00484910
void Gang__SetGang(Gang* this, int type);               // 0x00484940
void Gang__SetKillChar(Gang* this, char ch);            // 0x00484950

// Внутренние функции
void Gang__sub_45D920(Gang* this);           // 0x0046C920
void Gang__sub_45D9E0(Gang* this);           // 0x0046C9E0
void Gang__sub_45DAE0(Gang* this);           // 0x0046CAE0
void Gang__sub_45DB70(Gang* this);           // 0x0046CB70
Gang* Gang__GetVisibleGang(Gang* this);      // 0x0046CD50
void Gang__sub_45DE10(Gang* this);           // 0x0046CE10
void Gang__sub_45DEA0(Gang* this);           // 0x0046CEA0
void Gang__Set_475900(Gang* this);           // 0x00484900

// ==========================================
// МЕТОДЫ КЛАССА Gangs (Менеджер)
// ==========================================

void Gangs__Gangs(Gangs* this);              // 0x00469E60
void Gangs__Gangs_Des(Gangs* this);          // 0x00469E80
void Gangs__Gangs_des(Gangs* this);          // 0x0046AEE0

void Gangs__IncreaseRespectForPlayer(Gangs* this, int playerId, int value); // 0x0046CA40
Gang* Gangs__FindByName(Gangs* this, const char* name); // 0x0046CBB0
Gang* Gangs__GetGang(Gangs* this, int id);              // 0x0046CC20
void  Gangs__SelectGang(Gangs* this, int id);           // 0x0046CC70
int   Gangs__AddNewGang(Gangs* this);                   // 0x0046CC90
float* Gangs__GetGangPositionByName(Gangs* this, const char* name); // 0x0046CCC0
Gang* Gangs__FindGangByCarModel(Gangs* this, int carModel); // 0x0046CCE0
Gang* Gangs__GetFirstUsedGang(Gangs* this);  // 0x0046CD60
Gang* Gangs__GetNextUsedGang(Gangs* this, Gang* current); // 0x0046CDB0
void Gangs__sub_45DF30(Gangs* this);         // 0x0046CF30

#endif // GANG_H
