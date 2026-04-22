# GTA 2 C++ Project

## Purpose
This project contains C++ classes with **confirmed vtable methods** from gta2.exe.

## Rules
1. **NO fake methods** - Only add methods found in ASM/MAP files
2. **Verify vtables** - Class must have confirmed vtable pointer in binary
3. **Match signatures** - Method signatures must match calling convention in ASM

## Current Status
- Empty placeholder - awaiting vtable analysis
- Will be populated when classes with virtual methods are confirmed

## Structure
```
include/gta2/
  ├── Car.hpp      # Class with vtable (if confirmed)
  ├── Weapon.hpp   # Class with vtable (if confirmed)
  └── ...

src/
  ├── Car.cpp      # Only confirmed virtual methods
  ├── Weapon.cpp
  └── ...
```

## How to Add a Class
1. Find class constructor in MAP file
2. Analyze ASM for vtable initialization (`mov [eax], offset vtable`)
3. Extract all virtual method addresses from vtable
4. Create header with exact method signatures
5. Implement only what's confirmed in ASM
