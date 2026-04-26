#pragma once

#include <cstdint>
#include <cstddef>

// Structure S17: EntityManager
// Original Name: S17
// Size: 0x2F04 (12036 bytes)
// Description: Global manager for game entities (Peds, Cars, Weapons, etc.).
//              Manages a pool of objects, handles creation, deletion, and updates.
// Allocation: Created via operator_new(0x2F04u) in game initialization.
// Global Instance: gS17 (or gEntityManager)

namespace gta2 {

// Forward declarations
struct Ped;
struct Car;
struct Weapon;
struct GameObject;

// Entity Slot structure (hypothetical internal structure within the manager)
// Assuming each slot is roughly 40-64 bytes depending on implementation
// Total slots approx: 12036 / sizeof(Slot)
struct EntitySlot {
    uint32_t flags;        // 0x00: State flags (active, type, etc.)
    void* objectPtr;       // 0x04: Pointer to the actual object (Ped, Car, etc.)
    uint32_t type;         // 0x08: Type identifier
    uint32_t nextIndex;    // 0x0C: Index of next free/used slot (linked list logic)
    uint32_t prevIndex;    // 0x10: Index of previous slot
    uint8_t  padding[0x2C]; // 0x14 - 0x3F: Reserved / specific data
    // Total size per slot hypothesis: 0x40 (64 bytes) -> ~188 slots
    // Or if packed differently. We leave raw buffer for now to match total size.
};

class EntityManager {
public:
    // Raw data buffer to ensure exact size 0x2F04
    // We will define known fields and pad the rest
    uint8_t raw_data[0x2F04]; 

    // Known/Inferred fields accessors (offsets are hypothetical until confirmed)
    // Offset 0x00: Likely count or first index
    inline int32_t& GetCount() { return *reinterpret_cast<int32_t*>(raw_data + 0x00); }
    inline int32_t& GetMaxCount() { return *reinterpret_cast<int32_t*>(raw_data + 0x04); }
    
    // Constructor
    // Address: 0x0045B050 (Called after operator_new(0x2F04))
    EntityManager();
    
    // Destructor
    ~EntityManager();

    // --- Initialization & Reset ---
    // Address: 0x??????
    void Init();
    
    // Address: 0x??????
    void Reset();

    // --- Memory Management ---
    // Address: 0x??????
    int32_t AllocateSlot();
    
    // Address: 0x??????
    void FreeSlot(int32_t index);
    
    // Address: 0x??????
    bool IsSlotUsed(int32_t index);

    // --- Entity Creation ---
    // Address: 0x??????
    GameObject* CreateCar(float x, float y, float z, int32_t modelId);
    
    // Address: 0x??????
    GameObject* CreatePed(float x, float y, float z, int32_t gangId);
    
    // Address: 0x??????
    GameObject* CreateWeapon(int32_t type, float x, float y, float z);

    // --- Entity Removal ---
    // Address: 0x??????
    void RemoveEntity(int32_t index);
    
    // Address: 0x??????
    void RemoveAllByType(uint32_t type);

    // --- Access & Search ---
    // Address: 0x??????
    GameObject* GetEntity(int32_t index);
    
    // Address: 0x??????
    int32_t FindFreeSlot();
    
    // Address: 0x??????
    int32_t FindByType(uint32_t type);
    
    // Address: 0x??????
    int32_t FindNearest(float x, float y, uint32_t type);

    // --- Update Loop ---
    // Address: 0x??????
    void Update();
    
    // Address: 0x??????
    void UpdateAI();
    
    // Address: 0x??????
    void UpdatePhysics();

    // --- Debug & Misc ---
    // Address: 0x??????
    void DebugDraw();

    // Placeholder for remaining methods (Total ~45 methods expected)
    // Add specific signatures here as you identify them from disassembly
    void Sub_Unknown_01();
    void Sub_Unknown_02();
    void Sub_Unknown_03();
    void Sub_Unknown_04();
    void Sub_Unknown_05();
    void Sub_Unknown_06();
    void Sub_Unknown_07();
    void Sub_Unknown_08();
    void Sub_Unknown_09();
    void Sub_Unknown_10();
    void Sub_Unknown_11();
    void Sub_Unknown_12();
    void Sub_Unknown_13();
    void Sub_Unknown_14();
    void Sub_Unknown_15();
    void Sub_Unknown_16();
    void Sub_Unknown_17();
    void Sub_Unknown_18();
    void Sub_Unknown_19();
    void Sub_Unknown_20();
    void Sub_Unknown_21();
    void Sub_Unknown_22();
    void Sub_Unknown_23();
    void Sub_Unknown_24();
    void Sub_Unknown_25();
    void Sub_Unknown_26();
    void Sub_Unknown_27();
    void Sub_Unknown_28();
    void Sub_Unknown_29();
    void Sub_Unknown_30();
};

// Global instance pointer
// Address: 0x5E???? (Set after allocation)
extern EntityManager* gEntityManager; // aka gS17

} // namespace gta2
