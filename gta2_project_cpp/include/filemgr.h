#ifndef FILEMGR_H
#define FILEMGR_H

#include <stdio.h>
#include <stdint.h>

/*
 * Структура FileMgr
 * Размер: 0x28 байт (40 байт)
 * Источник: gta2.h строка 8199
 * 
 * Менеджер файлов для работы с файловой системой игры
 */
struct FileMgr
{
  FILE* FILE;        // смещение 0x0 - указатель на файл
  FILE* File1;       // смещение 0x4 - второй указатель на файл
  size_t field_8;    // смещение 0x8 - размер поля
  int field_C;       // смещение 0xC
  int field_10;      // смещение 0x10
  int field_14;      // смещение 0x14
  int field_18;      // смещение 0x18
  int field_1C;      // смещение 0x1C
  int field_20;      // смещение 0x20
  char field_24;     // смещение 0x24
  char field_25;     // смещение 0x25
  char field_26;     // смещение 0x26
  char field_27;     // смещение 0x27
};

// Проверка размера структуры
static_assert(sizeof(struct FileMgr) == 40, "Размер структуры FileMgr должен быть 40 байт");

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Методы FileMgr
 */

// Открытие файла
// Адрес: нужно найти в gta2.c
void FileMgr__FileOpen(struct FileMgr* self, const char* lpFileName);

// Чтение из файла
// Адрес: нужно найти в gta2.c
void FileMgr__Read(struct FileMgr* self, size_t* lpFileName);

// Закрытие файла
// Адрес: нужно найти в gta2.c
void FileMgr__CloseFile(struct FileMgr* self);

// Установка пути к файлу
// Адрес: нужно найти в gta2.c
void FileMgr__SetFilePath(const char* path);

#ifdef __cplusplus
}
#endif

#endif // FILEMGR_H
