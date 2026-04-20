#ifndef TYPES_H
#define TYPES_H

#include <windows.h>
#include <stdio.h>
#include <stdbool.h>
#include <float.h>

// Basic types from Ghidra
typedef unsigned char   undefined;
typedef unsigned char   bool;
typedef unsigned char   byte;
typedef unsigned int    dword;
typedef unsigned long long GUID;
typedef long double     longdouble;
typedef long long       longlong;
typedef unsigned long long qword;
typedef unsigned char   uchar;
typedef unsigned int    uint;
typedef unsigned long   ulong;
typedef unsigned long long ulonglong;
typedef unsigned char   undefined1;
typedef unsigned short  undefined2;
typedef unsigned int    undefined3;
typedef unsigned int    undefined4;
typedef unsigned long long undefined5;
typedef unsigned long long undefined8;
typedef unsigned short  ushort;
typedef unsigned short  wchar16;
typedef short           wchar_t;
typedef unsigned short  word;
typedef int             intptr_t;
typedef longlong        __time64_t;
typedef __time64_t      time_t;

// Pointer types
typedef void* pointer32;
typedef pointer32 ImageBaseOffset32;

// Standard numeric types for GTA2
typedef signed char     s8;
typedef signed short    s16;
typedef signed int      s32;
typedef signed long long s64;
typedef unsigned char   u8;
typedef unsigned short  u16;
typedef unsigned int    u32;
typedef unsigned long long u64;
typedef float           f32;
typedef double          f64;

#endif // TYPES_H
