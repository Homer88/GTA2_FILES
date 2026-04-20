#ifndef PED_H
#define PED_H

#include "types.h"
#include "enums.h"
#include "forward_declarations.h"

#pragma pack(push, 1)

struct Weapon {
    undefined4 field0_0x0;
    undefined4 field1_0x4;
    undefined4 field2_0x8;
    undefined4 field3_0xc;
    undefined4 field4_0x10;
    undefined4 field5_0x14;
    undefined4 field6_0x18;
    undefined4 field7_0x1c;
    undefined4 field8_0x20;
    undefined4 field9_0x24;
    undefined4 field10_0x28;
};

struct Gang {
    undefined4 field0_0x0;
    undefined4 field1_0x4;
    undefined4 field2_0x8;
    undefined4 field3_0xc;
    undefined4 field4_0x10;
    undefined4 field5_0x14;
    undefined4 field6_0x18;
    undefined4 field7_0x1c;
    undefined4 field8_0x20;
    undefined4 field9_0x24;
    undefined4 field10_0x28;
    undefined4 field11_0x2c;
    undefined4 field12_0x30;
    undefined4 field13_0x34;
    undefined4 field14_0x38;
    undefined4 field15_0x3c;
    undefined4 field16_0x40;
    undefined4 field17_0x44;
    undefined4 field18_0x48;
    undefined4 field19_0x4c;
    undefined4 field20_0x50;
    undefined4 field21_0x54;
    undefined4 field22_0x58;
    undefined4 field23_0x5c;
    undefined4 field24_0x60;
    undefined4 field25_0x64;
    undefined4 field26_0x68;
    undefined4 field27_0x6c;
    undefined4 field28_0x70;
    undefined4 field29_0x74;
    undefined4 field30_0x78;
    undefined4 field31_0x7c;
    undefined4 field32_0x80;
    undefined4 field33_0x84;
    undefined4 field34_0x88;
    undefined4 field35_0x8c;
    undefined4 field36_0x90;
    undefined4 field37_0x94;
    undefined4 field38_0x98;
    undefined4 field39_0x9c;
    undefined4 field40_0xa0;
    undefined4 field41_0xa4;
    undefined4 field42_0xa8;
    undefined4 field43_0xac;
    undefined4 field44_0xb0;
    undefined4 field45_0xb4;
    undefined4 field46_0xb8;
    undefined4 field47_0xbc;
    undefined4 field48_0xc0;
    undefined4 field49_0xc4;
    undefined4 field50_0xc8;
    undefined4 field51_0xcc;
    undefined4 field52_0xd0;
    undefined4 field53_0xd4;
    undefined4 field54_0xd8;
    undefined4 field55_0xdc;
    undefined4 field56_0xe0;
    undefined4 field57_0xe4;
    undefined4 field58_0xe8;
    undefined4 field59_0xec;
    undefined4 field60_0xf0;
    undefined4 field61_0xf4;
    undefined4 field62_0xf8;
    undefined4 field63_0xfc;
    undefined4 field64_0x100;
    undefined4 field65_0x104;
    undefined4 field66_0x108;
    undefined4 field67_0x10c;
    undefined4 field68_0x110;
    undefined4 field69_0x114;
    undefined4 field70_0x118;
    undefined4 field71_0x11c;
    undefined4 field72_0x120;
    undefined4 field73_0x124;
    undefined4 field74_0x128;
    undefined4 field75_0x12c;
    undefined4 field76_0x130;
    undefined4 field77_0x134;
    undefined4 field78_0x138;
    undefined4 field79_0x13c;
    undefined4 field80_0x140;
    undefined4 field81_0x144;
    undefined4 field82_0x148;
    undefined4 field83_0x14c;
    undefined4 field84_0x150;
    undefined4 field85_0x154;
    undefined4 field86_0x158;
    undefined4 field87_0x15c;
    undefined4 field88_0x160;
    undefined4 field89_0x164;
    undefined4 field90_0x168;
    undefined4 field91_0x16c;
    undefined4 field92_0x170;
    undefined4 field93_0x174;
    undefined4 field94_0x178;
    undefined4 field95_0x17c;
    undefined4 field96_0x180;
    undefined4 field97_0x184;
    undefined4 field98_0x188;
    undefined4 field99_0x18c;
    undefined4 field100_0x190;
    undefined4 field101_0x194;
    undefined4 field102_0x198;
    undefined4 field103_0x19c;
    undefined4 field104_0x1a0;
    undefined4 field105_0x1a4;
    undefined4 field106_0x1a8;
    undefined4 field107_0x1ac;
    undefined4 field108_0x1b0;
    undefined4 field109_0x1b4;
    undefined4 field110_0x1b8;
    undefined4 field111_0x1bc;
    undefined4 field112_0x1c0;
    undefined4 field113_0x1c4;
    undefined4 field114_0x1c8;
    undefined4 field115_0x1cc;
    undefined4 field116_0x1d0;
    undefined4 field117_0x1d4;
    undefined4 field118_0x1d8;
    undefined4 field119_0x1dc;
    undefined4 field120_0x1e0;
    undefined4 field121_0x1e4;
    undefined4 field122_0x1e8;
    undefined4 field123_0x1ec;
    undefined4 field124_0x1f0;
    undefined4 field125_0x1f4;
    undefined4 field126_0x1f8;
    undefined4 field127_0x1fc;
    undefined4 field128_0x200;
    undefined4 field129_0x204;
    undefined4 field130_0x208;
    undefined4 field131_0x20c;
    undefined4 field132_0x210;
    undefined4 field133_0x214;
    undefined4 field134_0x218;
    undefined4 field135_0x21c;
    undefined4 field136_0x220;
    undefined4 field137_0x224;
    undefined4 field138_0x228;
    undefined4 field139_0x22c;
    undefined4 field140_0x230;
    undefined4 field141_0x234;
    undefined4 field142_0x238;
    undefined4 field143_0x23c;
    undefined4 field144_0x240;
    undefined4 field145_0x244;
    undefined4 field146_0x248;
    undefined4 field147_0x24c;
    undefined4 field148_0x250;
    undefined4 field149_0x254;
    undefined4 field150_0x258;
    undefined4 field151_0x25c;
    undefined4 field152_0x260;
    undefined4 field153_0x264;
    undefined4 field154_0x268;
    undefined4 field155_0x26c;
    undefined4 field156_0x270;
    undefined4 field157_0x274;
    undefined4 field158_0x278;
    undefined4 field159_0x27c;
    undefined4 field160_0x280;
    undefined4 field161_0x284;
    undefined4 field162_0x288;
    undefined4 field163_0x28c;
    undefined4 field164_0x290;
    undefined4 field165_0x294;
    undefined4 field166_0x298;
    undefined4 field167_0x29c;
    undefined4 field168_0x2a0;
    undefined4 field169_0x2a4;
    undefined4 field170_0x2a8;
    undefined4 field171_0x2ac;
    undefined4 field172_0x2b0;
    undefined4 field173_0x2b4;
    undefined4 field174_0x2b8;
    undefined4 field175_0x2bc;
    undefined4 field176_0x2c0;
    undefined4 field177_0x2c4;
    undefined4 field178_0x2c8;
    undefined4 field179_0x2cc;
    undefined4 field180_0x2d0;
    undefined4 field181_0x2d4;
    undefined4 field182_0x2d8;
    undefined4 field183_0x2dc;
    undefined4 field184_0x2e0;
    undefined4 field185_0x2e4;
    undefined4 field186_0x2e8;
    undefined4 field187_0x2ec;
    undefined4 field188_0x2f0;
    undefined4 field189_0x2f4;
    undefined4 field190_0x2f8;
    undefined4 field191_0x2fc;
};

struct S169 {
    // Add fields as needed
};

struct GameObject {
    undefined4 field0_0x0;
    undefined4 field1_0x4;
    undefined4 field2_0x8;
    undefined4 field3_0xc;
    undefined4 field4_0x10;
    undefined4 field5_0x14;
    undefined4 field6_0x18;
    undefined4 field7_0x1c;
    undefined4 field8_0x20;
    undefined4 field9_0x24;
    undefined4 field10_0x28;
    undefined4 field11_0x2c;
    undefined4 field12_0x30;
    undefined4 field13_0x34;
    undefined4 field14_0x38;
    undefined4 field15_0x3c;
    undefined4 field16_0x40;
    undefined4 field17_0x44;
    undefined4 field18_0x48;
    undefined4 field19_0x4c;
    undefined4 field20_0x50;
    undefined4 field21_0x54;
    undefined4 field22_0x58;
    undefined4 field23_0x5c;
    undefined4 field24_0x60;
    undefined4 field25_0x64;
    undefined4 field26_0x68;
    undefined4 field27_0x6c;
    undefined4 field28_0x70;
    undefined4 field29_0x74;
    undefined4 field30_0x78;
    undefined4 field31_0x7c;
    undefined4 field32_0x80;
    undefined4 field33_0x84;
    undefined4 field34_0x88;
    undefined4 field35_0x8c;
    undefined4 field36_0x90;
    undefined4 field37_0x94;
    undefined4 field38_0x98;
    undefined4 field39_0x9c;
    undefined4 field40_0xa0;
    undefined4 field41_0xa4;
    undefined4 field42_0xa8;
    undefined4 field43_0xac;
    undefined4 field44_0xb0;
    undefined4 field45_0xb4;
    undefined4 field46_0xb8;
    undefined4 field47_0xbc;
    undefined4 field48_0xc0;
    undefined4 field49_0xc4;
    undefined4 field50_0xc8;
    undefined4 field51_0xcc;
    undefined4 field52_0xd0;
    undefined4 field53_0xd4;
    undefined4 field54_0xd8;
    undefined4 field55_0xdc;
    undefined4 field56_0xe0;
    undefined4 field57_0xe4;
    undefined4 field58_0xe8;
    undefined4 field59_0xec;
    undefined4 field60_0xf0;
    undefined4 field61_0xf4;
    undefined4 field62_0xf8;
    undefined4 field63_0xfc;
};

struct S200 {
    undefined4 field0_0x0;
    undefined4 field1_0x4;
    undefined4 field2_0x8;
    undefined4 field3_0xc;
};

struct Ped {
    struct S200 objective_queue[50];  // Массив целей/задач
    int counter;                       // Счетчик
    char reserved_0x9a[146];           // Резерв
    int16_t field_0x12c;
    int16_t field_0x12e;
    int16_t field_0x130;
    int16_t field_0x132;
    int16_t field_0x134;
    int8_t field_0x136;
    int8_t field_0x137;
    int32_t field_0x138;
    int32_t field_0x13c;
    int32_t field_0x140;
    struct Ped *sPed1;                 // Связанный пед 1
    struct Ped *driver;                // Водитель (если пед в машине)
    struct Ped *linked_ped;            // Связанный пед
    struct Car *car;                   // Машина для анимации входа/выхода
    struct Car *objective_target_car;  // Целевая машина для задачи
    struct Car *target_car_for_enter;  // Машина для входа
    struct Player *player;             // Игрок
    struct Ped *next_ped;              // Следующий пед в списке
    struct S169 *pS169;                // Неизвестная структура
    int8_t field_0x168;
    int8_t field_0x169;
    int8_t field_0x16a;
    int8_t field_0x16b;
    struct Car *car_current;           // Текущая машина
    struct Weapon *selected_weapon;    // Выбранное оружие
    struct Weapon *weapon1;            // Оружие 1
    struct Weapon *weapon2;            // Оружие 2
    struct Gang *gang;                 // Банда
    struct Ped *ped_driver;            // Пед-водитель
    int32_t field_0x184;
    struct Ped *last_char_punched;     // Последний ударенный персонаж
    int32_t field_0x18c;
    int32_t field_0x190;
    int32_t field_0x194;
    struct Ped *ped3;                  // Пед 3
    struct Gang *gang1;                // Банда 1
    int32_t field_0x1a0;
    int32_t field_0x1a4;
    int32_t field_0x1a8;
    int position_x;                    // Позиция X
    int position_y;                    // Позиция Y
    int position_z;                    // Позиция Z
    struct Ped *pPed;                  // Указатель на педа
    void *field_0x1dc;
    void *field_0x1e0;
    void *field_0x1e4;
    void *field_0x1e8;
    void *field_0x1ec;
    int32_t field_0x1f0;
    int32_t field_0x1f4;
    struct SpriteS1 *sprite_s1;        // Спрайт
    struct Car *car_1;
    struct Car *car_2;
    int32_t field_0x200;
    int32_t field_0x204;
    int32_t field_0x208;
    int32_t field_0x20c;
    int32_t field_0x210;
    int32_t field_0x214;
    int32_t field_0x218;
    int id;                            // ID персонажа
    int ped_id;                        // ID педа
    int16_t invulnerability;           // Невосприимчивость (видимость)
    int16_t police_star;               // Звезды полиции
    int16_t field_0x224;
    uint16_t field_0x226;
    int16_t field_0x228;
    int16_t field_0x22a;
    int16_t field_0x22c;
    int16_t health;                    // Здоровье
    int16_t objective_timer;           // Таймер задачи
    int16_t car_state_timer;           // Таймер состояния машины
    enum PedFlags flags;               // Флаги педа
    int8_t field_0x234;
    int8_t field_0x235;
    int8_t field_0x236;
    int32_t field_0x238;
    int8_t damage_state;               // Состояние повреждений
    int8_t exit_anim_state;            // Состояние анимации выхода
    int8_t field_0x23f;
    int8_t field_0x240;
    int8_t field_0x241;
    int8_t field_0x242;
    int8_t field_0x243;
    int32_t field_0x244;
    int32_t field_0x248;
    int8_t field_0x24c;
    int8_t field_0x24d;
    int8_t field_0x24e;
    int8_t field_0x24f;
    enum SearchType search_type;       // Тип поиска
    int8_t index_ped;                  // Индекс педа
    int8_t field_0x253;
    int8_t field_0x254;
    int8_t field_0x255;
    enum ALL_PED occupation;           // Профессия/занятие
    enum Remap remap;                  // Ремэппинг текстур
    int8_t field_0x259;
    int8_t field_0x25a;
    int8_t field_0x25b;
    int target_car_door;               // Целевая дверь машины
    int8_t animation_state;            // Состояние анимации
    int8_t field_0x261;
    int8_t field_0x262;
    int8_t field_0x263;
    int32_t field_0x264;
    int8_t field_0x268;
    int8_t field_0x269;
    int8_t field_0x26a;
    int8_t field_0x26b;
    int action_state;                  // Состояние действия
    int current_action;                // Текущее действие
    int8_t field_0x270;
    int8_t field_0x271;
    int8_t field_0x272;
    int8_t field_0x273;
    int8_t field_0x274;
    int8_t field_0x275;
    int8_t field_0x276;
    int8_t field_0x277;
    int8_t field_0x278;
    int8_t field_0x279;
    int8_t field_0x27a;
    int8_t field_0x27b;
    enum GraphicType graphic_type;     // Тип графики
    int32_t field_0x27c;
    int gang_car_model;                // Модель машины банды
    enum PedState current_state;       // Текущее состояние
    int32_t field_0x284;
    enum PedState saved_state;         // Сохраненное состояние
    int32_t field_0x28c;
    int32_t field_0x290;
    int32_t field_0x294;
    int32_t field_0x298;
};
#pragma pack(pop)

// Ped function declarations
void Ped__SetSearchType(struct Ped *this, enum SearchType type);
void Ped__SetOccupation(struct Ped *this, int occupation);
int Ped__GetOccupation(struct Ped *this);
enum PedState Ped__GetCurrentState(struct Ped *this);
void Ped__SetHealthPlayer(struct Ped *this, int16_t health);
bool Ped__GetDeadPed(struct Ped *this);
struct Car* Ped__GetCurrentCar(struct Ped *this);
void Ped__SetRemap(struct Ped *this, char remap);
char Ped__GetRemap(struct Ped *this);

#endif // PED_H
