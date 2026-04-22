#pragma once
#include <cstdint>

// ============================================================================
// FORWARD DECLARATIONS
// Объявления структур, которые будут определены в других файлах
// ============================================================================
struct Player;
struct General;
struct Text;
struct Style;
struct MapRelatedStruct;
struct S17;
struct Display;
struct Mike;
struct CarSystemManager;
struct S25;
struct MissionManager;
struct Camera;
struct Timing;
struct SpriteEntry;
struct Character;
struct Collide;
struct PathNode;
struct Object;
struct ScriptThread;
struct TileAnim;
struct Arsenal;
struct Door;
struct Ambulance;
struct PublicTransport;
struct Taxi;
struct Hud;
struct TextureManager;
struct TrafficLigthStruct;
struct JuncIds;
struct S93_1;
struct S95;
struct CarEngines;
struct Particles;
struct S100;
struct S102;
struct S103;
struct S105;
struct S107;
struct S109;
struct Police;
struct S115;
struct Gangs;
struct S119;
struct S121;
struct S123;
struct S127;
struct TangoMain;
struct CameraOrPhysics;
struct FileMgr;
struct DMAudio;

#define MAX_PLAYERS 8 

#pragma pack(push, 1)

/**
 * @brief Основная структура игровой сессии (Game).
 * Размер: 0x40 (64) байта.
 * Адрес конструктора: 0x004E3D90
 * 
 * Эта структура хранит состояние текущего сеанса игры и указатели на активных игроков.
 * Все основные системы (менеджеры) реализованы как глобальные переменные (синглтоны).
 */
struct Game {
    // === БЛОК 1: Игроки (0x00 - 0x1F) ===
    // Массив указателей на объекты игроков. 
    Player* Players[MAX_PLAYERS];   // 0x00: Указатели на игроков (nullptr если не активен)

    // === БЛОК 2: Параметры сессии (0x20 - 0x33) ===
    uint8_t  MaxPlayersCount;       // 0x20: Максимальное количество игроков (v107)
    uint8_t  PlayerInFocusIndex;    // 0x21: Индекс текущего управляемого игрока
    uint16_t pad_22;                // 0x22: Выравнивание (field_22 обнуляется)
    
    int32_t  GameStatus;            // 0x24: Статус игры (1 = запущена/активна)
    Player*  CurrentPlayer;         // 0x28: Указатель на активного игрока
    Player*  CurrentPlayerCopy;     // 0x2C: Дублирующий указатель (CurentPlayer__)
    
    int32_t  IsGameOver;            // 0x30: Флаг конца игры (-1 = игра окончена)

    // === БЛОК 3: Флаги и состояние (0x34 - 0x3F) ===
    uint8_t  Flags_34;              // 0x34: Байт флагов
    uint8_t  pad_35[3];             // 0x35-0x37: Выравнивание до 4 байт
    
    int32_t  GameState;             // 0x38: Состояние игры (0 = меню, 1 = геймплей)
    int32_t  SkipPoliceFlag;        // 0x3C: Флаг отключения полиции
    
    // Итого: 0x40 байт
};

#pragma pack(pop)

// ============================================================================
// ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ (Синглтоны)
// Инициализируются в Game::Game
// ============================================================================
extern General*           gGeneral;
extern Text*              gText;
extern Style*             gStyle;
extern MapRelatedStruct*  gMapRelatedStruct;
extern S17*               gS17;
extern Display*           gDisplay;
extern Mike*              gMike;
extern CarSystemManager*  gCarSystemManager;
extern S25*               gS25;
extern MissionManager*    gMissionManager;
extern Camera*            gCamera;
extern Timing*            gTiming;
extern SpriteEntry*       gSpriteEntry;
extern Character*         gCharacter;
extern Collide*           gCollide;
extern PathNode*          gPathNode;      // S57
extern Object*            gObject;
extern ScriptThread*      gScriptThread;  // S68
extern TileAnim*          gTileAnim;
extern Arsenal*           gArsenal;
extern Door*              gDoor;
extern Ambulance*         gAmbulance;
extern PublicTransport*   gPublicTransport;
extern Taxi*              gTaxi;
extern Hud*               gHud;
extern TextureManager*    gTextureManager;
extern TrafficLigthStruct* gTrafficLigthStruct;
extern JuncIds*           gJuncIds;
extern S93_1*             gS93;
extern S95*               gS95;
extern CarEngines*        gCarEngines;
extern Particles*         gParticles;
extern S100*              gS100;
extern S102*              gS102;
extern S103*              gS103;
extern S105*              gS105;
extern S107*              gS107;
extern S109*              gS109;
extern Police*            gPolice;
extern S115*              gS115;
extern Gangs*             gGangs;
extern S119*              gS119;
extern S121*              gS121;
extern S123*              gS123;
extern S127*              gS127;
extern TangoMain*         gTangoMain;     // S129
extern CameraOrPhysics*   gCameraOrPhysics;
extern FileMgr*           gFileMgr;
extern DMAudio*           gDMAudio;

// Глобальный указатель на текущую игру
extern Game* gGame;

// ============================================================================
// ФУНКЦИИ
// ============================================================================

/**
 * @brief Конструктор класса Game.
 * @param this Указатель на экземпляр Game.
 * @param a2 Неизвестный параметр (вероятно, связанный с сетью или индексом).
 * @param a3 Неизвестный параметр (флаг).
 * @return Указатель на созданный объект Game.
 * Адрес: 0x004E3D90
 */
Game* __thiscall Game__Game(Game* this, int a2, char a3);

// Проверка размера
// static_assert(sizeof(Game) == 0x40, "Invalid Game size");
