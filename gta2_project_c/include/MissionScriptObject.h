#ifndef MISSION_SCRIPT_OBJECT_H
#define MISSION_SCRIPT_OBJECT_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// Структура S28 - MissionScriptObject
// Размер: 0x11C (284 байта)
// Адрес глобального массива: используется в MissionManager
typedef struct MissionScriptObject MissionScriptObject;

struct MissionScriptObject {
    // Поля пока не восстановлены (требуется дополнительный анализ)
    uint8_t data[0x11C];
};

// ============================================================================
// КОНСТРУКТОРЫ И ДЕСТРУКТОРЫ
// ============================================================================

// Конструктор S28
// Адрес: 0x475C00
// Размер: 0x62 байта
void MissionScriptObject_Init(MissionScriptObject* self);

// Деструктор S28
// Адрес: вычисляется из кода
// Размер: 0x26 байт
void MissionScriptObject_Destroy(MissionScriptObject* self);

// ============================================================================
// ОСНОВНЫЕ МЕТОДЫ УПРАВЛЕНИЯ
// ============================================================================

// sub_4751B0 - Инициализация/сброс
// Адрес: 0x4751B0
// Размер: 0x1D байт
void MissionScriptObject_Reset(MissionScriptObject* self);

// sub_4751E0 - Быстрая проверка состояния
// Адрес: 0x4751E0
// Размер: 0x07 байт
int MissionScriptObject_CheckState(MissionScriptObject* self);

// sub_4751F0 - Установка параметров
// Адрес: 0x4751F0
// Размер: 0x31 байт
void MissionScriptObject_SetParams(MissionScriptObject* self, int param1, int param2);

// sub_475420 - Обработка события
// Адрес: 0x475420
// Размер: 0x35 байт
void MissionScriptObject_ProcessEvent(MissionScriptObject* self, int eventType);

// sub_475460 - Обновление состояния
// Адрес: 0x475460
// Размер: 0x63 байт
void MissionScriptObject_UpdateState(MissionScriptObject* self);

// ============================================================================
// МЕТОДЫ СОХРАНЕНИЯ/ЗАГРУЗКИ
// ============================================================================

// sub_476E50 - Основная инициализация
// Адрес: 0x476E50
// Размер: 0x2F байт
void MissionScriptObject_Initialize(MissionScriptObject* self);

// sub_476E80 - Проверка флага
// Адрес: 0x476E80
// Размер: 0x1A байт
int MissionScriptObject_CheckFlag(MissionScriptObject* self);

// sub_479CC0 - Загрузка из файла сохранения
// Адрес: 0x479CC0
// Размер: 0x77 байт
int MissionScriptObject_LoadFromFile(MissionScriptObject* self, const char* filename);

// sub_479F10 - Сохранение в файл
// Адрес: 0x479F10
// Размер: 0x2AE байт
int MissionScriptObject_SaveToFile(MissionScriptObject* self, const char* filename);

// sub_47A1E0 - Валидация данных
// Адрес: 0x47A1E0
// Размер: 0xF8 байт
int MissionScriptObject_ValidateData(MissionScriptObject* self);

// ============================================================================
// МЕТОДЫ РАБОТЫ С ОБЪЕКТАМИ МИССИИ
// ============================================================================

// sub_4779A0 - Получение объекта
// Адрес: 0x4779A0
// Размер: 0x5E байт
void* MissionScriptObject_GetObject(MissionScriptObject* self, int objectId);

// sub_477A00 - Создание объекта
// Адрес: 0x477A00
// Размер: 0xB4 байт
int MissionScriptObject_CreateObject(MissionScriptObject* self, int type, int x, int y);

// sub_477B70 - Удаление объекта
// Адрес: 0x477B70
// Размер: 0x5F байт
void MissionScriptObject_DeleteObject(MissionScriptObject* self, int objectId);

// sub_477BD0 - Обновление объектов
// Адрес: 0x477BD0
// Размер: 0x126 байт
void MissionScriptObject_UpdateObjects(MissionScriptObject* self);

// ============================================================================
// МЕТОДЫ РАБОТЫ СО СКРИПТАМИ
// ============================================================================

// sub_478450 - Выполнение команды скрипта
// Адрес: 0x478450
// Размер: 0x4E байт
void MissionScriptObject_ExecuteCommand(MissionScriptObject* self, int commandId);

// sub_478610 - Парсинг скрипта
// Адрес: 0x478610
// Размер: 0x39 байт
int MissionScriptObject_ParseScript(MissionScriptObject* self, const char* scriptData);

// sub_479050 - Обработка условия
// Адрес: 0x479050
// Размер: 0x42 байт
int MissionScriptObject_CheckCondition(MissionScriptObject* self, int conditionId);

// sub_479850 - Запуск подпрограммы
// Адрес: 0x479850
// Размер: 0x180 байт
void MissionScriptObject_RunSubroutine(MissionScriptObject* self, int subroutineId);

// sub_479B70 - Остановка выполнения
// Адрес: 0x479B70
// Размер: 0x74 байт
void MissionScriptObject_StopExecution(MissionScriptObject* self);

// ============================================================================
// МЕТОДЫ РАБОТЫ С ЦЕЛЯМИ
// ============================================================================

// sub_47A330 - Установка цели
// Адрес: 0x47A330
// Размер: 0x71 байт
void MissionScriptObject_SetObjective(MissionScriptObject* self, int objectiveId);

// sub_47A3B0 - Проверка выполнения цели
// Адрес: 0x47A3B0
// Размер: 0xAD байт
int MissionScriptObject_CheckObjectiveComplete(MissionScriptObject* self, int objectiveId);

// sub_47A620 - Обновление целей
// Адрес: 0x47A620
// Размер: 0x1A9 байт
void MissionScriptObject_UpdateObjectives(MissionScriptObject* self);

// sub_47A860 - Выдача награды
// Адрес: 0x47A860
// Размер: 0xF8 байт
void MissionScriptObject_GiveReward(MissionScriptObject* self, int rewardType);

// ============================================================================
// ВНУТРЕННИЕ МЕТОДЫ ОБРАБОТКИ
// ============================================================================

// sub_47ACC0 - Внутренняя обработка A
// Адрес: 0x47ACC0
// Размер: 0x123 байт
void MissionScriptObject_InternalProcessA(MissionScriptObject* self);

// sub_47AF50 - Внутренняя обработка B
// Адрес: 0x47AF50
// Размер: 0x73 байт
void MissionScriptObject_InternalProcessB(MissionScriptObject* self);

// sub_47B430 - Обработка триггера
// Адрес: 0x47B430
// Размер: 0x62 байт
void MissionScriptObject_ProcessTrigger(MissionScriptObject* self, int triggerId);

// sub_47B5E0 - Активация зоны
// Адрес: 0x47B5E0
// Размер: 0x130 байт
void MissionScriptObject_ActivateZone(MissionScriptObject* self, int zoneId);

// sub_47B810 - Деактивация зоны
// Адрес: 0x47B810
// Размер: 0x136 байт
void MissionScriptObject_DeactivateZone(MissionScriptObject* self, int zoneId);

// sub_47BAC0 - Проверка зоны
// Адрес: 0x47BAC0
// Размер: 0xA0 байт
int MissionScriptObject_CheckZone(MissionScriptObject* self, int zoneId);

// sub_47BCD0 - Работа с таймером
// Адрес: 0x47BCD0
// Размер: 0x130 байт
void MissionScriptObject_TimerUpdate(MissionScriptObject* self, int timerId);

// sub_47BE00 - Установка таймера
// Адрес: 0x47BE00
// Размер: 0x8B байт
void MissionScriptObject_SetTimer(MissionScriptObject* self, int timerId, int duration);

// sub_47C000 - Сброс таймера
// Адрес: 0x47C000
// Размер: 0x4E байт
void MissionScriptObject_ResetTimer(MissionScriptObject* self, int timerId);

// ============================================================================
// МЕТОДЫ РАБОТЫ С СОСТОЯНИЕМ МИССИИ
// ============================================================================

// sub_47C1E0 - Установка статуса миссии
// Адрес: 0x47C1E0
// Размер: 0x16F байт
void MissionScriptObject_SetMissionStatus(MissionScriptObject* self, int status);

// sub_47C6A0 - Проверка статуса
// Адрес: 0x47C6A0
// Размер: 0x49 байт
int MissionScriptObject_GetMissionStatus(MissionScriptObject* self);

// sub_47C8D0 - Завершение миссии
// Адрес: 0x47C8D0
// Размер: 0x3B байт
void MissionScriptObject_CompleteMission(MissionScriptObject* self);

// sub_47CC50 - Провал миссии
// Адрес: 0x47CC50
// Размер: 0x6B байт
void MissionScriptObject_FailMission(MissionScriptObject* self);

// sub_47CCC0 - Перезапуск миссии
// Адрес: 0x47CCC0
// Размер: 0x3C байт
void MissionScriptObject_RestartMission(MissionScriptObject* self);

// ============================================================================
// МЕТОДЫ ОТЛАДКИ И ЛОГИРОВАНИЯ
// ============================================================================

// sub_47CE00 - Вывод отладочной информации
// Адрес: 0x47CE00
// Размер: 0x18A байт
void MissionScriptObject_PrintDebugInfo(MissionScriptObject* self);

// sub_47D070 - Логирование события
// Адрес: 0x47D070
// Размер: 0xFB байт
void MissionScriptObject_LogEvent(MissionScriptObject* self, const char* eventName);

// sub_47D260 - Проверка целостности
// Адрес: 0x47D260
// Размер: 0xCA байт
int MissionScriptObject_CheckIntegrity(MissionScriptObject* self);

// sub_47D360 - Восстановление состояния
// Адрес: 0x47D360
// Размер: 0xC1 байт
int MissionScriptObject_RestoreState(MissionScriptObject* self);

// ============================================================================
// ДОПОЛНИТЕЛЬНЫЕ МЕТОДЫ
// ============================================================================

// sub_47D7A0 - Метод обработки D7A0
// Адрес: 0x47D7A0
// Размер: 0xB3 байт
void MissionScriptObject_ProcessD7A0(MissionScriptObject* self);

// sub_47D860 - Метод обработки D860
// Адрес: 0x47D860
// Размер: 0xB4 байт
void MissionScriptObject_ProcessD860(MissionScriptObject* self);

// sub_47D9D0 - Метод обработки D9D0
// Адрес: 0x47D9D0
// Размер: 0xB0 байт
void MissionScriptObject_ProcessD9D0(MissionScriptObject* self);

// sub_47DAD0 - Метод обработки DAD0
// Адрес: 0x47DAD0
// Размер: 0xFF байт
void MissionScriptObject_ProcessDAD0(MissionScriptObject* self);

// sub_47DE70 - Метод обработки DE70
// Адрес: 0x47DE70
// Размер: 0x1C8 байт
void MissionScriptObject_ProcessDE70(MissionScriptObject* self);

// sub_47E210 - Метод обработки E210
// Адрес: 0x47E210
// Размер: 0x62 байт
void MissionScriptObject_ProcessE210(MissionScriptObject* self);

// sub_47E360 - Метод обработки E360
// Адрес: 0x47E360
// Размер: 0x250 байт
void MissionScriptObject_ProcessE360(MissionScriptObject* self);

// sub_47ECB0 - Быстрая проверка
// Адрес: 0x47ECB0
// Размер: 0x24 байт
int MissionScriptObject_QuickCheck(MissionScriptObject* self);

// sub_47ECE0 - Инициализация буфера
// Адрес: 0x47ECE0
// Размер: 0x40 байт
void MissionScriptObject_InitBuffer(MissionScriptObject* self);

// sub_47F550 - Обработка провала
// Адрес: 0x47F550
// Размер: 0x1BA байт
void MissionScriptObject_HandleFailure(MissionScriptObject* self);

// sub_47F710 - Метод F710
// Адрес: 0x47F710
// Размер: 0x4F байт
void MissionScriptObject_ProcessF710(MissionScriptObject* self);

// sub_47F760 - Метод F760
// Адрес: 0x47F760
// Размер: неизвестен
void MissionScriptObject_ProcessF760(MissionScriptObject* self);

// sub_47F890 - Метод F890
// Адрес: 0x47F890
// Размер: неизвестен
void MissionScriptObject_ProcessF890(MissionScriptObject* self);

// sub_47F920 - Метод F920
// Адрес: 0x47F920
// Размер: неизвестен
void MissionScriptObject_ProcessF920(MissionScriptObject* self);

// sub_47FAC0 - Глобальная обработка
// Адрес: 0x47FAC0
// Размер: 0x354 байт
void MissionScriptObject_GlobalProcess(MissionScriptObject* self);

// sub_480080 - Синхронизация
// Адрес: 0x480080
// Размер: 0x267 байт
void MissionScriptObject_Sync(MissionScriptObject* self);

// sub_480430 - Финализация
// Адрес: 0x480430
// Размер: 0x179 байт
void MissionScriptObject_Finalize(MissionScriptObject* self);

// sub_4805B0 - Главный метод обработки (самый большой)
// Адрес: 0x4805B0
// Размер: 0x6A0 байт
void MissionScriptObject_MainProcess(MissionScriptObject* self);

// sub_481120 - Очистка
// Адрес: 0x481120
// Размер: 0xD3 байт
void MissionScriptObject_Cleanup(MissionScriptObject* self);

// sub_3F10B0 - Специальный метод
// Адрес: 0x3F10B0
// Размер: 0x20 байт
void MissionScriptObject_SpecialProcess(MissionScriptObject* self);

#ifdef __cplusplus
}
#endif

#endif // MISSION_SCRIPT_OBJECT_H
