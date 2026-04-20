/**
 * @file file_system_ext.h
 * @brief Расширенные структуры файловой системы и архивов.
 * 
 * GTA 2 хранит ресурсы в архивах (например, gta2.dat, sounds.dat).
 * Эти структуры описывают формат заголовков и записей файлов.
 */

#ifndef FILE_SYSTEM_EXT_H
#define FILE_SYSTEM_EXT_H

#include "types.h"

#pragma pack(push, 1)

/**
 * @brief Заголовок архива.
 * Оригинал IDA: `DAT_ArchiveHeader` / `ARCH_HEAD`
 * Находится в начале каждого .dat файла.
 */
typedef struct FileArchiveHeader {
    u32 Magic;              // 0x00: Сигнатура (например, '2ATG' или 0x12345678)
    u16 Version;            // 0x04: Версия формата архива
    u16 Flags;              // 0x06: Флаги (сжатие, шифрование)
    u32 FileCount;          // 0x08: Количество файлов в архиве
    u32 DirectoryOffset;    // 0x0C: Смещение к таблице файлов
    u32 TotalSize;          // 0x10: Общий размер архива
    u8  Reserved[12];       // 0x14: Резерв
} FileArchiveHeader;

/**
 * @brief Элемент файла в архиве.
 * Оригинал IDA: `struct FileEntry` / `FILE_ENT`
 * Массив таких структур идет после заголовка (по смещению DirectoryOffset).
 */
typedef struct FileEntry {
    char Filename[12];      // 0x00: Имя файла (короткое, 8.3 format)
    u32 Offset;             // 0x0C: Смещение данных файла внутри архива
    u32 SizeCompressed;     // 0x10: Сжатый размер
    u32 SizeUncompressed;   // 0x14: Реальный размер
    u16 Flags;              // 0x18: Флаги (сжат, зашифрован)
    u16 Checksum;           // 0x1A: Контрольная сумма имени
} FileEntry;

/**
 * @brief Заголовок файла сохранения.
 * Оригинал IDA: `SaveHeader` / `SAVE_HDR`
 * Первые байты файла savegame.dat.
 */
typedef struct SaveHeader {
    u32 Magic;              // 0x00: Сигнатура "GTA2SAVE"
    u16 Version;            // 0x04: Версия сохранения
    u16 Checksum;           // 0x06: CRC данных
    u32 PlayTimeSeconds;    // 0x08: Время игры
    u32 Money;              // 0x0C: Деньги игрока
    u16 CurrentMissionID;   // 0x10: Текущая миссия
    u16 UnlockedDistricts;  // 0x12: Открытые районы (битовая маска)
    u8  Difficulty;         // 0x14: Сложность
    u8  Language;           // 0x15: Язык
    u8  Pad[2];             // 0x16: Выравнивание
} SaveHeader;

/**
 * @brief Элемент конфигурации.
 * Оригинал IDA: `ConfigEntry` / `CFG_ENTRY`
 * Используется для чтения gta2.cfg или реестра.
 */
typedef struct ConfigEntry {
    char Key[32];           // Ключ (например, "Resolution", "Volume")
    char Value[64];         // Значение (строка или число в тексте)
    u8  Type;               // Тип данных (Int, String, Float, Bool)
    u8  Dirty;              // Флаг изменения (нужно сохранить)
    u16 Reserved;           // Выравнивание
} ConfigEntry;

/**
 * @brief Контекст работы с архивом.
 * Хранит открытые дескрипторы и кэш.
 */
typedef struct ArchiveContext {
    void* FileHandle;           // Дескриптор открытого файла
    FileArchiveHeader Header;   // Заголовок
    FileEntry* FileTable;       // Указатель на таблицу файлов (загружена в память)
    u32 CacheSize;              // Размер кэша
    void* CacheBuffer;          // Буфер кэша
} ArchiveContext;

#pragma pack(pop)

#endif // FILE_SYSTEM_EXT_H
