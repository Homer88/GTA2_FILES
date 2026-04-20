/**
 * @file memory_pool.c
 * @brief Реализация системы пулов памяти
 * 
 * Старые имена из IDA:
 * - FUN_00401000 -> MemPool_Init
 * - FUN_00401150 -> MemPool_Alloc
 * - FUN_00401280 -> MemPool_Free
 */

#include "core/memory_pool.h"
#include <string.h>
#include <stdlib.h>

// -----------------------------------------------------------------------------
// Инициализация менеджера
// -----------------------------------------------------------------------------

void MemManager_Init(MemoryManager* manager) {
    if (!manager) return;
    
    memset(manager, 0, sizeof(MemoryManager));
    manager->pool_count = 0;
    manager->total_allocated = 0;
    manager->peak_usage = 0;
}

// -----------------------------------------------------------------------------
// Создание пула
// IDA: FUN_00401000
// -----------------------------------------------------------------------------

int MemPool_Create(MemoryManager* manager, const char* name, u32 block_size, u32 block_count) {
    if (!manager || !name || block_size == 0 || block_count == 0) {
        return -1;
    }
    
    if (manager->pool_count >= MAX_POOLS) {
        return -1; // Пулы переполнены
    }
    
    MemoryPool* pool = &manager->pools[manager->pool_count];
    
    // Выделяем основной буфер
    pool->buffer = malloc(block_size * block_count);
    if (!pool->buffer) {
        return -1;
    }
    
    // Выделяем список свободных (стек индексов)
    pool->free_list = (u32*)malloc(sizeof(u32) * block_count);
    if (!pool->free_list) {
        free(pool->buffer);
        return -1;
    }
    
    // Заполняем имя
    strncpy(pool->name, name, POOL_NAME_LEN - 1);
    pool->name[POOL_NAME_LEN - 1] = '\0';
    
    // Инициализируем параметры
    pool->block_size = block_size;
    pool->total_blocks = block_count;
    pool->free_count = block_count;
    pool->initialized = true;
    
    // Заполняем free_list индексами (LIFO - последний выделенный первый освобождается)
    for (u32 i = 0; i < block_count; i++) {
        pool->free_list[i] = block_count - 1 - i;
    }
    
    // Обновляем статистику менеджера
    manager->total_allocated += block_size * block_count;
    if (manager->total_allocated > manager->peak_usage) {
        manager->peak_usage = manager->total_allocated;
    }
    
    manager->pool_count++;
    
    return manager->pool_count - 1; // Возвращаем индекс созданного пула
}

// -----------------------------------------------------------------------------
// Выделение блока
// IDA: FUN_00401150
// -----------------------------------------------------------------------------

void* MemPool_Alloc(MemoryPool* pool) {
    if (!pool || !pool->initialized || pool->free_count == 0) {
        return NULL;
    }
    
    // Берем индекс из вершины стека свободных
    pool->free_count--;
    u32 index = pool->free_list[pool->free_count];
    
    // Вычисляем адрес
    u8* base = (u8*)pool->buffer;
    return base + (index * pool->block_size);
}

// -----------------------------------------------------------------------------
// Освобождение блока
// IDA: FUN_00401280
// -----------------------------------------------------------------------------

void MemPool_Free(MemoryPool* pool, void* ptr) {
    if (!pool || !pool->initialized || !ptr) {
        return;
    }
    
    // Проверяем, принадлежит ли указатель этому пулу
    u8* base = (u8*)pool->buffer;
    u8* end = base + (pool->total_blocks * pool->block_size);
    
    if ((u8*)ptr < base || (u8*)ptr >= end) {
        return; // Указатель не из этого пула
    }
    
    // Вычисляем индекс
    u32 offset = (u32)((u8*)ptr - base);
    if (offset % pool->block_size != 0) {
        return; // Неверное выравнивание (ошибка!)
    }
    
    u32 index = offset / pool->block_size;
    
    // Возвращаем индекс в стек свободных
    pool->free_list[pool->free_count] = index;
    pool->free_count++;
}

// -----------------------------------------------------------------------------
// Получение индекса по указателю
// -----------------------------------------------------------------------------

int MemPool_GetIndex(MemoryPool* pool, void* ptr) {
    if (!pool || !pool->initialized || !ptr) {
        return -1;
    }
    
    u8* base = (u8*)pool->buffer;
    u8* end = base + (pool->total_blocks * pool->block_size);
    
    if ((u8*)ptr < base || (u8*)ptr >= end) {
        return -1;
    }
    
    u32 offset = (u32)((u8*)ptr - base);
    if (offset % pool->block_size != 0) {
        return -1;
    }
    
    return (int)(offset / pool->block_size);
}

// -----------------------------------------------------------------------------
// Получение указателя по индексу
// -----------------------------------------------------------------------------

void* MemPool_GetPtr(MemoryPool* pool, int index) {
    if (!pool || !pool->initialized || index < 0 || (u32)index >= pool->total_blocks) {
        return NULL;
    }
    
    u8* base = (u8*)pool->buffer;
    return base + (index * pool->block_size);
}

// -----------------------------------------------------------------------------
// Очистка пула
// -----------------------------------------------------------------------------

void MemPool_Clear(MemoryPool* pool) {
    if (!pool || !pool->initialized) {
        return;
    }
    
    // Сбрасываем free_list в исходное состояние
    for (u32 i = 0; i < pool->total_blocks; i++) {
        pool->free_list[i] = pool->total_blocks - 1 - i;
    }
    pool->free_count = pool->total_blocks;
}

// -----------------------------------------------------------------------------
// Статистика
// -----------------------------------------------------------------------------

void MemPool_GetStats(MemoryPool* pool, u32* out_used, u32* out_free) {
    if (!pool || !pool->initialized) {
        if (out_used) *out_used = 0;
        if (out_free) *out_free = 0;
        return;
    }
    
    if (out_used) *out_used = pool->total_blocks - pool->free_count;
    if (out_free) *out_free = pool->free_count;
}
