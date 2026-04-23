// Structure: S21 (Integer Stack)
// Source: gta2.exe (IDA Pro dump)
// Size: 4004 bytes (0xFA4)
// Description: Stack data structure for storing integers/pointers
// Used in: PedModel rendering, object management
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations
struct S21;

#pragma pack(push, 1)

struct S21
{
    char field_0;              // +0: Unused or flag byte
    BYTE gap1[3999];           // +1: Stack buffer (holds ~1000 integers)
    S21* stack_pointer;        // +4000: Current stack position pointer
};

#pragma pack(pop)

// Static size check
static_assert(sizeof(S21) == 0xFA4, "Size mismatch for S21");

// ============================================================================
// Class: S21 - Integer Stack Implementation
// ============================================================================

#ifdef __cplusplus
extern "C" {
#endif

// Constructor: Initialize stack (self-referential pointer)
// Address: 0x004C4BD0
// Size: 9 bytes
// Returns: this pointer
S21* __thiscall S21_Constructor(S21* this);

// Push: Add integer value to stack
// Address: 0x004C4B80
// Size: 30 bytes (0x1E)
// Parameters:
//   - this: S21 instance pointer
//   - value: Integer value to push onto stack
// Returns: Updated stack pointer
S21* __thiscall S21_Push(S21* this, int value);

// Pop: Remove and return top value from stack
// Address: 0x004C4BA0
// Size: 20 bytes (0x14)
// Parameters:
//   - this: S21 instance pointer
// Returns: Value popped from stack
int __thiscall S21_Pop(S21* this);

// IsEmpty: Check if stack is empty
// Address: 0x004C4BC0
// Size: 10 bytes (0x0A)
// Parameters:
//   - this: S21 instance pointer
// Returns: true if stack is empty (stack_pointer == this), false otherwise
BOOL __thiscall S21_IsEmpty(S21* this);

// Destructor: Free stack memory
// Address: 0x004C4DA0
// Size: 26 bytes (0x1A)
// Parameters:
//   - this: S21 instance pointer
//   - flags: Destruction flags (bit 0 = free memory)
// Returns: this pointer
S21* __thiscall S21_Destructor(S21* this, char flags);

// Global S21 instance pointer
// Address: 0x003F657C (from MAP file: 0003:000F657C)
extern S21* gS21;

#ifdef __cplusplus
}

// C++ wrapper class
class S21Stack
{
public:
    // Constructor
    S21Stack() { S21_Constructor(reinterpret_cast<S21*>(this)); }
    
    // Destructor
    ~S21Stack() { S21_Destructor(reinterpret_cast<S21*>(this), 1); }
    
    // Push value onto stack
    void Push(int value) { S21_Push(reinterpret_cast<S21*>(this), value); }
    
    // Pop value from stack
    int Pop() { return S21_Pop(reinterpret_cast<S21*>(this)); }
    
    // Check if stack is empty
    bool IsEmpty() { return S21_IsEmpty(reinterpret_cast<S21*>(this)) != FALSE; }
    
private:
    S21 data;
};
#endif
