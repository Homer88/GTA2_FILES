# GTA 2 Reverse Engineering Project Split

## Overview
The original `gta2_project` has been split into two separate projects:

### 1. gta2_project_c (Pure C)
**Purpose:** Structures and procedural code (constructors/destructors only)

**Location:** `/workspace/gta2_project_c/`

**Structure:**
```
gta2_project_c/
├── CMakeLists.txt
├── include/gta2/
│   ├── types.h      # Basic type definitions (u8, s32, f32, etc.)
│   └── entities.h   # All entity structures (Car, Passenger, CarDoor, Turret, etc.)
└── src/
    └── entities.c   # Constructor/destructor implementations
```

**Confirmed Structures:**
| Structure | Size | Constructor Address | Destructor Address |
|-----------|------|---------------------|-------------------|
| Passenger | 0x10 | 0x42FE90 | 0x42FEA0 |
| CarDoor | 0x10 | 0x41F680 | - |
| Car | TBD | 0x403800 | - |
| Turret | 0x8 | - | - |

**Rules:**
- ✅ Only structures with confirmed sizes from MAP/ASM
- ✅ Only constructor/destructor functions (no fake methods)
- ✅ Sizes will be verified with `static_assert` after full analysis

---

### 2. gta2_project_cpp (C++ with vtables)
**Purpose:** Classes with confirmed virtual method tables

**Location:** `/workspace/gta2_project_cpp/`

**Structure:**
```
gta2_project_cpp/
├── CMakeLists.txt
├── include/gta2/
│   └── README.md    # Guidelines for adding classes
└── src/
    └── (empty - awaiting vtable analysis)
```

**Rules:**
- ❌ NO classes added until vtable is confirmed in ASM
- ✅ Only methods found in MAP file
- ✅ Exact calling convention matching binary

---

### 3. gta2.exe (Original Data - Unchanged)
**Location:** `/workspace/gta2.exe/`

**Contents:**
- `ida_pro/gta2.exe.asm` - IDA Pro disassembly (1M+ lines)
- `ida_pro/gta2.exe.map` - MAP file with all symbols

---

## Migration Status

| Component | Status | Notes |
|-----------|--------|-------|
| Basic types (u8, s32, etc.) | ✅ Done | In `gta2_project_c/include/gta2/types.h` |
| Entity structures | ✅ Done | In `gta2_project_c/include/gta2/entities.h` |
| Constructors | ✅ Done | In `gta2_project_c/src/entities.c` |
| CMake build files | ✅ Done | Both projects have CMakeLists.txt |
| C++ classes | ⏳ Pending | Awaiting vtable analysis |

---

## Next Steps

1. **Verify structure sizes** - Analyze constructors in ASM to confirm exact sizes
2. **Add static_assert** - Add size checks to all structures
3. **Vtable analysis** - Search ASM for vtable initializations
4. **Populate C++ project** - Add classes only when vtables are confirmed

---

## Build Instructions

### C Project
```bash
cd /workspace/gta2_project_c
mkdir build && cd build
cmake ..
make
```

### C++ Project (currently empty)
```bash
cd /workspace/gta2_project_cpp
mkdir build && cd build
cmake ..
make
```

---

## File Origin Reference

All structures and functions are derived from:
- **MAP file:** `/workspace/gta2.exe/ida_pro/gta2.exe.map`
- **ASM listing:** `/workspace/gta2.exe/ida_pro/gta2.exe.asm`

Function naming convention: `ClassName__MethodName` (e.g., `Passenger__Passenger`)
