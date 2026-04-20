#ifndef SAVEGAME_H
#define SAVEGAME_H

#include "core/types.h"
#include "savegame_types.h"
#include "forward_declarations.h"

#define SAVE_DIR "saves"
#define SAVE_EXTENSION ".gta2sav"

/**
 * Менеджер сохранений
 */
typedef struct SaveGameManager {
    char SaveDirectory[256];      // 0x0 - Путь к папке сохранений
    SaveSlot Slots[MAX_SAVE_SLOTS]; // 0x100 - Кэш слотов
    u8 SlotValid[MAX_SAVE_SLOTS]; // 0xD00 - Валидность слотов
    s32 LastLoadedSlot;           // 0xD0A - Последний загруженный слот
    u8 IsInitialized;             // 0xD0E - Инициализирован
    u8 Padding[5];                // Выравнивание
} SaveGameManager;

/**
 * Инициализация менеджера сохранений
 * @param manager Указатель на менеджер
 * @param basePath Базовый путь для сохранений
 * @return true если успешно
 */
bool SaveGameManager_Init(SaveGameManager* manager, const char* basePath);

/**
 * Очистка менеджера сохранений
 * @param manager Указатель на менеджер
 */
void SaveGameManager_Shutdown(SaveGameManager* manager);

/**
 * Сохранение игры в указанный слот
 * @param manager Указатель на менеджер
 * @param slotIndex Индекс слота (0-9)
 * @param player Состояние игрока
 * @param world Состояние мира
 * @return Статус операции
 */
SaveStatus SaveGameManager_Save(SaveGameManager* manager, u8 slotIndex,
                                PlayerState* player, WorldState* world);

/**
 * Загрузка игры из указанного слота
 * @param manager Указатель на менеджер
 * @param slotIndex Индекс слота
 * @param outPlayer Выходное состояние игрока
 * @param outWorld Выходное состояние мира
 * @return Статус операции
 */
SaveStatus SaveGameManager_Load(SaveGameManager* manager, u8 slotIndex,
                                PlayerState* outPlayer, WorldState* outWorld);

/**
 * Проверка валидности слота
 * @param manager Указатель на менеджер
 * @param slotIndex Индекс слота
 * @return true если слот содержит валидное сохранение
 */
bool SaveGameManager_IsSlotValid(SaveGameManager* manager, u8 slotIndex);

/**
 * Удаление сохранения
 * @param manager Указатель на менеджер
 * @param slotIndex Индекс слота
 * @return Статус операции
 */
SaveStatus SaveGameManager_Delete(SaveGameManager* manager, u8 slotIndex);

/**
 * Получение информации о слоте (без полной загрузки)
 * @param manager Указатель на менеджер
 * @param slotIndex Индекс слота
 * @param outHeader Выходной заголовок
 * @return Статус операции
 */
SaveStatus SaveGameManager_GetSlotInfo(SaveGameManager* manager, u8 slotIndex,
                                       SaveHeader* outHeader);

/**
 * Обновление кэша слотов
 * @param manager Указатель на менеджер
 */
void SaveGameManager_RefreshCache(SaveGameManager* manager);

/**
 * Поиск первого свободного слота
 * @param manager Указатель на менеджер
 * @return Индекс слота или -1 если нет свободных
 */
s32 SaveGameManager_FindFreeSlot(SaveGameManager* manager);

/**
 * Расчет контрольной суммы данных
 * @param data Указатель на данные
 * @param size Размер данных
 * @return Контрольная сумма
 */
u32 SaveGame_CalculateChecksum(void* data, u32 size);

/**
 * Проверка контрольной суммы сохранения
 * @param slot Указатель на слот
 * @return true если контрольная сумма верна
 */
bool SaveGame_VerifyChecksum(SaveSlot* slot);

/**
 * Генерация имени файла сохранения
 * @param slotIndex Индекс слота
 * @param outBuffer Буфер для имени
 * @param bufferSize Размер буфера
 */
void SaveGame_GenerateFilename(u8 slotIndex, char* outBuffer, u32 bufferSize);

/**
 * Конвертация состояния игры в структуру сохранения
 * @param outSlot Выходной слот сохранения
 * @param game Игра (глобальное состояние)
 * @param player Игрок
 */
void SaveGame_ConvertFromGame(SaveSlot* outSlot, struct Game* game, 
                              struct Player* player);

/**
 * Восстановление состояния игры из сохранения
 * @param game Игра (глобальное состояние)
 * @param player Игрок
 * @param slot Слот сохранения
 */
void SaveGame_ConvertToGame(struct Game* game, struct Player* player,
                            SaveSlot* slot);

// Удобные макросы для быстрой работы
#define SAVE_SLOT_VALID(manager, slot) \
    SaveGameManager_IsSlotValid(manager, slot)

#define SAVE_GAME(manager, slot, player, world) \
    SaveGameManager_Save(manager, slot, player, world)

#define LOAD_GAME(manager, slot, player, world) \
    SaveGameManager_Load(manager, slot, player, world)

#endif // SAVEGAME_H
