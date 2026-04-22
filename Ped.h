#pragma once

#include <cstdint>

// Forward declarations for related structures (to be defined later)
struct S200;
struct Car;
struct Ped;
struct Player;
struct Weapon;
struct Gang;
struct S169;
struct GameObject;
struct S94;

// Enumerations (placeholders based on common GTA logic, to be refined)
enum class PedState : int32_t {
    UNKNOWN = 0
};

enum class SearchType : int32_t {
    NONE = 0
};

enum class Occupation : int32_t {
    NONE = 0
};

enum class Remap : int32_t {
    NONE = 0
};

enum class GraphicType : int32_t {
    NONE = 0
};

#pragma pack(push, 1)

struct Ped {
    // === BLOCK 1: Internal Buffers / S200 Array (0x00 - 0x12B) ===
    // Constructor mentions initializing 3 blocks of 100 bytes.
    // Clean zeroes most of this, but specific offsets might hold pointers or state.
    uint8_t unknown_block_00[0x12C];  // 0x00 - 0x12B (Size: 300 bytes)

    // === BLOCK 2: Grid/Tile Coordinates (0x12C - 0x137) ===
    int16_t tile_x_12C;               // 0x12C
    int16_t tile_y_12E;               // 0x12E
    int16_t field_130;                // 0x130
    int16_t field_132;                // 0x132
    int32_t field_134;                // 0x134 (Aligned to 4 bytes potentially)

    // === BLOCK 3: Pointers & Links (0x138 - 0x1AB) ===
    // These are zeroed in Clean, likely dynamic links reset on spawn/clean.
    void* ptr_138;                    // 0x138
    void* ptr_13C;                    // 0x13C
    void* ptr_140;                    // 0x140
    void* ptr_144;                    // 0x144
    void* ptr_148;                    // 0x148
    void* ptr_14C;                    // 0x14C
    void* ptr_150;                    // 0x150
    void* ptr_154;                    // 0x154
    void* ptr_158;                    // 0x158
    void* ptr_15C;                    // 0x15C
    void* ptr_160;                    // 0x160
    void* ptr_164;                    // 0x164
    void* ptr_168;                    // 0x168
    void* ptr_16C;                    // 0x16C
    void* ptr_170;                    // 0x170
    void* ptr_174;                    // 0x174
    void* ptr_178;                    // 0x178
    void* ptr_17C;                    // 0x17C
    void* ptr_180;                    // 0x180
    void* ptr_184;                    // 0x184
    void* ptr_188;                    // 0x188
    void* ptr_18C;                    // 0x18C
    void* ptr_190;                    // 0x190
    void* ptr_194;                    // 0x194
    void* ptr_198;                    // 0x198
    void* ptr_19C;                    // 0x19C
    void* ptr_1A0;                    // 0x1A0
    void* ptr_1A4;                    // 0x1A4
    void* ptr_1A8;                    // 0x1A8

    // === BLOCK 4: World Position (Confirmed by GetXCoordinate) (0x1AC - 0x1CF) ===
    // Clean initializes these from global defaults (unk_5E5CFC etc.)
    int32_t world_x_1AC;              // 0x1AC
    int32_t world_y_1B0;              // 0x1B0
    int32_t world_z_1B4;              // 0x1B4
    
    int32_t ptr_1B8;                  // 0x1B8 (Initialized via bitShift in Clean)
    int32_t ptr_1BC;                  // 0x1BC
    int32_t ptr_1C0;                  // 0x1C0
    int32_t ptr_1C4;                  // 0x1C4
    int32_t ptr_1C8;                  // 0x1C8
    int32_t ptr_1CC;                  // 0x1CC

    // === BLOCK 5: Global Resources / Model Pointers (0x1D0 - 0x1FF) ===
    void* global_ptr_1D0;             // 0x1D0
    void* global_ptr_1D4;             // 0x1D4
    void* global_ptr_1D8;             // 0x1D8
    void* global_ptr_1DC;             // 0x1DC
    void* global_ptr_1E0;             // 0x1E0
    void* global_ptr_1E4;             // 0x1E4
    void* global_ptr_1E8;             // 0x1E8
    void* global_ptr_1EC;             // 0x1EC
    void* model_ptr_1F0;              // 0x1F0 (Init: unk_5E5D28)
    void* texture_ptr_1F4;            // 0x1F4 (Init: unk_5E5D90)
    void* global_ptr_1F8;             // 0x1F8
    void* global_ptr_1FC;             // 0x1FC

    // === BLOCK 6: Stats & Health (0x200 - 0x21B) ===
    int32_t field_200;                // 0x200
    int32_t score_or_id_204;          // 0x204
    
    int16_t max_health_208;           // 0x208
    int16_t max_health_20A;           // 0x20A
    int16_t max_health_20C;           // 0x20C
    
    int16_t current_health_20E;       // 0x20E (Zeroed in Clean)
    int16_t current_health_210;       // 0x210 (Zeroed in Clean)
    int16_t start_health_212;         // 0x212 (Init: 100 / 0x64)
    int16_t field_214;                // 0x214
    int16_t field_216;                // 0x216
    int16_t objective_timer_218;      // 0x218
    int16_t car_state_timer_21A;      // 0x21A

    // === BLOCK 7: Control Flags & AI State (0x21C - 0x233) ===
    uint32_t control_flags_21C;       // 0x21C (Bitfield: bits 2,3,5,6,9,29,30 cleared in Clean)
    
    int32_t ai_state_220;             // 0x220
    
    uint8_t ai_mode_224;              // 0x224 (Bits 0-3 cleared, bit 5 set in Clean)
    uint8_t ai_submode_225;           // 0x225
    uint8_t ai_submode_226;           // 0x226
    uint8_t ai_flag_227;              // 0x227
    uint8_t ai_flag_228;              // 0x228
    uint8_t ai_flag_229;              // 0x229
    uint8_t pad_22A[2];               // 0x22A-0x22B
    
    int32_t timer_22C;                // 0x22C
    int32_t timer_230;                // 0x230

    // === BLOCK 8: Internal Block Headers? (0x234 - 0x243) ===
    // Corresponds to the "3 blocks of 100 bytes" mentioned in constructor context?
    uint8_t block1_active_234;        // 0x234
    uint8_t pad_235[3];               // 0x235-0x237
    int32_t block1_count_238;         // 0x238 (Init: 3)
    
    uint8_t block2_active_23C;        // 0x23C
    uint8_t pad_23D[3];               // 0x23D-0x23F
    int32_t block2_count_240;         // 0x240 (Init: 3)

    // === BLOCK 9: Status & Occupation (0x244 - 0x253) ===
    uint8_t status_244;               // 0x244 (Init: 0xFF)
    uint8_t pad_245[3];               // 0x245-0x247
    int32_t target_car_door_248;      // 0x248 (Init: 1, likely door index)
    
    uint8_t animation_state_24C;      // 0x24C
    uint8_t pad_24D[3];               // 0x24D-0x24F
    int32_t status_val_250;           // 0x250

    // === BLOCK 10: Action States & Graphics (0x254 - 0x293) ===
    uint8_t unknown_254[4];           // 0x254-0x257
    int32_t action_state_258;         // 0x258
    int32_t current_action_25C;       // 0x25C
    
    uint8_t flag_260;                 // 0x260
    uint8_t flag_261;                 // 0x261
    uint8_t flag_262;                 // 0x262
    uint8_t flag_263;                 // 0x263
    uint8_t flag_264;                 // 0x264
    uint8_t flag_265;                 // 0x265
    uint8_t flag_266;                 // 0x266
    uint8_t flag_267;                 // 0x267
    uint8_t flag_268;                 // 0x268
    uint8_t flag_269;                 // 0x269 (Init: 0xFF)
    uint8_t flag_26A;                 // 0x26A
    uint8_t pad_26B;                  // 0x26B
    
    int32_t graphic_type_26C;         // 0x26C (Init: 1)
    
    int32_t timer_270;                // 0x270 (Init: 1)
    int32_t limit_274;                // 0x274 (Init: 0x23 = 35)
    int32_t field_278;                // 0x278
    int32_t field_27C;                // 0x27C
    int32_t limit_280;                // 0x280 (Init: 0x0B = 11)
    int32_t limit_284;                // 0x284 (Init: 0x1C = 28)
    int32_t limit_288;                // 0x288 (Init: 0x02 = 2)
    int32_t field_28C;                // 0x28C
    
    int32_t damage_type_290;          // 0x290

    // Total Size: 0x294 bytes
};

#pragma pack(pop)

// Static assertion to verify size (requires compiler support)
// static_assert(sizeof(Ped) == 0x294, "Ped structure size mismatch");
