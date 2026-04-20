#ifndef TYPES_H
#define TYPES_H

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <math.h>
#include <stdbool.h>

// Basic types from Ghidra (compatible with Linux)
typedef unsigned char   undefined;
// bool уже определен в <stdbool.h>
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
// wchar_t уже определен в стандартной библиотеке
typedef unsigned short  word;
typedef intptr_t        intptr_t;
typedef longlong        __time64_t;
typedef __time64_t      time_t;

// Pointer types
typedef void* pointer32;
typedef pointer32 ImageBaseOffset32;

// Standard numeric types for GTA2
typedef int8_t          i8;
typedef int16_t         i16;
typedef int32_t         i32;
typedef int64_t         i64;
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

// Windows compatibility macros (for cross-platform support)
#define FALSE 0
#define TRUE 1
#define CALLBACK
#define WINAPI

#endif // TYPES_H
