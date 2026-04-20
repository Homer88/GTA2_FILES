/**
 * @file memory_pool.h
 * @brief Система управления пулами памяти (Fixed-Size Block Allocator)
 * 
 * В оригинале GTA 2 использует собственные аллокаторы для каждого типа объектов
 * (машины, педы, частицы), чтобы избежать фрагментации и ускорить выделение.
 * 
 * Старые имена из IDA:
 * - FUN_00401000 -> MemPool_Init
 * - FUN_00401150 -> MemPool_Alloc
 * - FUN_00401280 -> MemPool_Free
 * - DAT_00500000 -> g_memory_pools (глобальный массив пулов)
 */

#ifndef MEMORY_POOL_H
#define MEMORY_POOL_H

#include "types.h"
#include "common.h"

#define MAX_POOLS 16
#define POOL_NAME_LEN 32

/**
 * @struct MemoryPool
 * @brief Структура одного пула памяти
 */
typedef struct MemoryPool {
    char name[POOL_NAME_LEN];   // 0x00: Имя пула (отладка)
    void* buffer;               // 0x20: Указатель на выделенную память
    u32 block_size;             // 0x24: Размер одного блока
    u32 total_blocks;           // 0x28: Общее количество блоков
    u32 free_count;             // 0x2C: Количество свободных блоков
    u32* free_list;             // 0x30: Список индексов свободных блоков (stack)
    u8* used_bitmap;            // 0x34: Битовая карта занятости (опционально)
    bool initialized;           // 0x38: Флаг инициализации
} MemoryPool;

/**
 * @struct MemoryManager
 * @brief Глобальный менеджер памяти
 */
typedef struct MemoryManager {
    MemoryPool pools[MAX_POOLS]; // Массив пулов
    u32 pool_count;              // Количество активных пулов
    u32 total_allocated;         // Статистика: всего выделено байт
    u32 peak_usage;              // Статистика: пик использования
} MemoryManager;

// --- Функции управления пулами ---

/**
 * @brief Инициализация глобального менеджера памяти
 * @param manager Указатель на менеджер
 */
void MemManager_Init(MemoryManager* manager);

/**
 * @brief Создание нового пула памяти
 * @param manager Менеджер памяти
 * @param name Имя пула (для отладки)
 * @param block_size Размер одного элемента
 * @param block_count Количество элементов
 * @return Индекс созданного пула или -1 при ошибке
 * 
 * IDA: FUN_00401000 (MemPool_Init)
 */
int MemPool_Create(MemoryManager* manager, const char* name, u32 block_size, u32 block_count);

/**
 * @brief Выделение блока из пула по индексу
 * @param pool Указатель на пул
 * @return Указатель на память или NULL, если пул полон
 * 
 * IDA: FUN_00401150 (MemPool_Alloc)
 */
void* MemPool_Alloc(MemoryPool* pool);

/**
 * @brief Освобождение блока обратно в пул
 * @param pool Указатель на пул
 * @param ptr Указатель на освобождаемую память
 * 
 * IDA: FUN_00401280 (MemPool_Free)
 */
void MemPool_Free(MemoryPool* pool, void* ptr);

/**
 * @brief Получение индекса блока по указателю (для отладки/серииализации)
 * @param pool Указатель на пул
 * @param ptr Указатель на блок
 * @return Индекс блока или -1
 */
int MemPool_GetIndex(MemoryPool* pool, void* ptr);

/**
 * @brief Получение указателя по индексу
 * @param pool Указатель на пул
 * @param index Индекс блока
 * @return Указатель на блок
 */
void* MemPool_GetPtr(MemoryPool* pool, int index);

/**
 * @brief Очистка пула (сброс всех блоков в свободные)
 * @param pool Указатель на пул
 */
void MemPool_Clear(MemoryPool* pool);

/**
 * @brief Статистика использования пула
 * @param pool Указатель на пул
 * @param out_used Выходной параметр: кол-во занятых блоков
 * @param out_free Выходной параметр: кол-во свободных блоков
 */
void MemPool_GetStats(MemoryPool* pool, u32* out_used, u32* out_free);

#endif // MEMORY_POOL_H
