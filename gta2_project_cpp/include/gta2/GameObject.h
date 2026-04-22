#pragma once
#include "gta2_types.h"

#pragma pack(push, 1)

// Структура: GameObject
// Размер: 0x1C8 (456 байт) - НО в дампе только 79 полей до 0xB0, нужно уточнить
// Полей: 71 (в дампе IDA)
// Файл: structures_dump/all_structures/GameObject.txt
struct GameObject {
    GameObject* NextGameObject1;     // 0x0000 - Ссылка на следующий GameObject
    char field_4;                    // 0x0004
    char Remap;                      // 0x0005 - Флаг ремэпа/перекраски
    char field_6;                    // 0x0006
    char field_7;                    // 0x0007
    int field_8;                     // 0x0008
    int field_C;                     // 0x000C
    int field_10;                    // 0x0010
    __int16 field_14;                // 0x0014
    char field_16;                   // 0x0016
    char field_17;                   // 0x0017
    int field_18;                    // 0x0018
    int ProbablyPhysics;             // 0x001C - Физические параметры
    int field_20;                    // 0x0020
    int field_24;                    // 0x0024
    __int16 field_28;                // 0x0028
    __int16 field_2A;                // 0x002A
    __int16 field_2C;                // 0x002C
    char field_2E;                   // 0x002E
    char field_2F;                   // 0x002F
    int field_30;                    // 0x0030
    __int16 field_34;                  // 0x0034
    char field_36;                   // 0x0036
    char field_37;                   // 0x0037
    int Speed;                       // 0x0038 - Текущая скорость
    GameObject* NextGameObject;      // 0x003C - Ссылка на следующий GameObject в списке
    __int16 Rotation;                // 0x0040 - Угол поворота
    __int16 field_42;                // 0x0042
    char field_44;                   // 0x0044
    char field_45;                   // 0x0045
    __int16 field_46;                // 0x0046
    char field_48;                   // 0x0048
    char field_49;                   // 0x0049
    __int16 CigaretteIdleTimer;      // 0x004A - Таймер бездействия (сигарета)
    Car* Car1;                       // 0x004C - Ссылка на автомобиль 1
    Car* Car2;                       // 0x0050 - Ссылка на автомобиль 2
    char field_54;                   // 0x0054
    char field_55;                   // 0x0055
    char field_56;                   // 0x0056
    char field_57;                   // 0x0057
    int field_58;                    // 0x0058
    int field_5C;                    // 0x005C
    int field_60;                    // 0x0060
    int field_64;                    // 0x0064
    char field_68;                   // 0x0068
    char field_69;                   // 0x0069
    char field_6A;                   // 0x006A
    char field_6B;                   // 0x006B
    int field_6C;                    // 0x006C
    char field_70;                   // 0x0070
    char field_71;                   // 0x0071
    char field_72;                   // 0x0072
    char field_73;                   // 0x0073
    __int16 field_74;                // 0x0074
    char field_76;                   // 0x0076
    char field_77;                   // 0x0077
    GameObject* GameObject;          // 0x0078 - Ссылка на родительский/связанный GameObject
    Ped* Ped;                        // 0x007C - Ссылка на пешехода
    SpriteS1* SpriteS1;              // 0x0080 - Ссылка на спрайт
    Car* GetVehiclePtr;              // 0x0084 - Полученный автомобиль
    Car* CarPtr;                     // 0x0088 - Основная ссылка на автомобиль
    int field_8C;                    // 0x008C
    int Speed1;                      // 0x0090 - Дополнительная скорость
    int field_94;                    // 0x0094
    int deltaX;                      // 0x0098 - Дельта X
    int deltaY;                      // 0x009C - Дельта Y
    int field_A0;                    // 0x00A0
    int teleportX;                   // 0x00A4 - Координата телепортации X
    int teleportY;                   // 0x00A8 - Координата телепортации Y
    int teleportZ;                   // 0x00AC - Координата телепортации Z
    int field_B0;                    // 0x00B0
    // ... остальные поля до 0x1C8 need investigation
    char remaining_data[0x118];      // 0x00B4 - 0x1C8 (требуется дополнительный анализ)
};
#pragma pack(pop)

// Forward declarations для связанных типов
struct Car;
struct Ped;
struct SpriteS1;

// ============================================================================
// ФУНКЦИИ GameObject (62 функции из gta2.exe.map)
// Адреса взяты из: gta2.exe/ida_pro/gta2.exe.map
// ============================================================================

// Конструктор и деструктор
void GameObject_Constructor(GameObject* obj);           // Address: 0x004A6A60 - GameObject::GameObject
void GameObject_Destructor(GameObject* obj);            // Address: 0x004A25F0 - GameObject::~GameObject

// Основные методы доступа к координатам
float GameObject_GetX(GameObject* obj);                 // Address: 0x004329C0 - GameObject::GetX
float GameObject_GetY(GameObject* obj);                 // Address: 0x004329E0 - GameObject::GetY
float GameObject_GetZ(GameObject* obj);                 // Address: 0x00432A00 - GameObject::GetZ

// Методы установки и получения параметров
void GameObject_SetPed(GameObject* obj, Ped* ped);      // Address: 0x004328E0 - GameObject::SetPed
void GameObject_SetCar(GameObject* obj, Car* car);      // Address: 0x00432900 - GameObject::SetCar
void GameObject_SetSpeed(GameObject* obj, int speed);   // Address: 0x00432920 - GameObject::SetSpeed
void GameObject_SetRotation(GameObject* obj, __int16 angle); // Address: 0x00432A30 - GameObject::SetRotation
__int16 GameObject_get_rotation(GameObject* obj);       // Address: 0x00432A40 - GameObject::get_rotation

// Получение связанных объектов
Car* GameObject_GetVehicle(GameObject* obj);            // Address: 0x00412900 - GameObject::GetVehicle
SpriteS1* GameObject_GetSpriteS1(GameObject* obj);      // Address: 0x004328D0 - GameObject::GetSpriteS1

// Установка состояния пешехода
void GameObject_set_ped_state_1(GameObject* obj, int state); // Address: 0x00432910 - GameObject::set_ped_state_1

// Методы управления объектами (требуют анализа поведения)
void GameObject_Initialize(GameObject* obj);            // Address: 0x0042A080 - Инициализация объекта после создания
void GameObject_PreUpdate(GameObject* obj);             // Address: 0x00432880 - Подготовка к обновлению кадра
void GameObject_PostUpdate(GameObject* obj);            // Address: 0x004328F0 - Завершение обновления кадра
void GameObject_UpdatePhysics(GameObject* obj);         // Address: 0x00432930 - Обновление физики
void GameObject_UpdatePosition(GameObject* obj);        // Address: 0x00432940 - Обновление позиции
void GameObject_UpdateTransform(GameObject* obj);       // Address: 0x00432970 - Обновление трансформации
void GameObject_Cleanup(GameObject* obj);               // Address: 0x00432A20 - Очистка перед удалением
void GameObject_ResetState(GameObject* obj);            // Address: 0x00432A50 - Сброс состояния
void GameObject_ResetVelocity(GameObject* obj);         // Address: 0x00432A60 - Сброс скорости
void GameObject_ResetRotation(GameObject* obj);         // Address: 0x00432A70 - Сброс поворота
void GameObject_ResetFlags(GameObject* obj);            // Address: 0x00432A80 - Сброс флагов
void GameObject_ResetTimers(GameObject* obj);           // Address: 0x00432A90 - Сброс таймеров

// Методы из сегмента 0x49xxxx (обработка, рендеринг, коллизии)
void GameObject_ProcessMessage(GameObject* obj);        // Address: 0x004A0DE0 - Обработка сообщений
void GameObject_UpdateState(GameObject* obj);           // Address: 0x004A0E00 - Обновление состояния
void GameObject_CheckCollision(GameObject* obj);        // Address: 0x004A0E40 - Проверка коллизий
void GameObject_ResolveCollision(GameObject* obj);      // Address: 0x004A0E60 - Разрешение коллизий
void GameObject_ApplyDamage(GameObject* obj);           // Address: 0x004A0EA0 - Применение урона
void GameObject_PlayAnimation(GameObject* obj);         // Address: 0x004A0EC0 - Воспроизведение анимации
void GameObject_UpdateAI(GameObject* obj);              // Address: 0x004A0FA0 - Обновление ИИ
void GameObject_SpawnParticles(GameObject* obj);        // Address: 0x004A1190 - Создание частиц
void GameObject_UpdateEffects(GameObject* obj);         // Address: 0x004A18A0 - Обновление эффектов
void GameObject_SaveState(GameObject* obj);             // Address: 0x004A20C0 - Сохранение состояния
void GameObject_LoadState(GameObject* obj);             // Address: 0x004A20F0 - Загрузка состояния
void GameObject_Clone(GameObject* obj);                 // Address: 0x004A2390 - Клонирование объекта
void GameObject_Destroy(GameObject* obj);               // Address: 0x004A2640 - Уничтожение объекта
void GameObject_Release(GameObject* obj);               // Address: 0x004A2710 - Освобождение ресурсов
void GameObject_Hide(GameObject* obj);                  // Address: 0x004A2850 - Скрыть объект
void GameObject_Show(GameObject* obj);                  // Address: 0x004A28A0 - Показать объект
void GameObject_Enable(GameObject* obj);                // Address: 0x004A3180 - Включить объект
void GameObject_Disable(GameObject* obj);               // Address: 0x004A4220 - Отключить объект
void GameObject_Activate(GameObject* obj);              // Address: 0x004A4540 - Активировать объект
void GameObject_Deactivate(GameObject* obj);            // Address: 0x004A4700 - Деактивировать объект
void GameObject_Pause(GameObject* obj);                 // Address: 0x004A4980 - Пауза объекта
void GameObject_Resume(GameObject* obj);                // Address: 0x004A4BF0 - Возобновить объект
void GameObject_Render(GameObject* obj);                // Address: 0x004A5800 - Рендеринг объекта
void GameObject_UpdateRender(GameObject* obj);          // Address: 0x004A5880 - Обновление рендера
void GameObject_OnEnterArea(GameObject* obj);           // Address: 0x004A6C20 - Вход в зону
void GameObject_OnLeaveArea(GameObject* obj);           // Address: 0x004A85A0 - Выход из зоны
void GameObject_OnTrigger(GameObject* obj);             // Address: 0x004A9560 - Срабатывание триггера
void GameObject_OnInteract(GameObject* obj);            // Address: 0x004AA0D0 - Взаимодействие
void GameObject_OnPickup(GameObject* obj);              // Address: 0x004AAAC0 - Подбор предмета
void GameObject_OnDrop(GameObject* obj);                // Address: 0x004AAAD0 - Бросок предмета
void GameObject_OnUse(GameObject* obj);                 // Address: 0x004AAC20 - Использование
void GameObject_OnEquip(GameObject* obj);               // Address: 0x004AAD10 - Экипировка
void GameObject_OnUnequip(GameObject* obj);             // Address: 0x004AB120 - Снятие экипировки
void GameObject_OnDestroy(GameObject* obj);             // Address: 0x004AB460 - Обработка уничтожения

// Методы из сегмента 0x4Axxxx (дополнительные)
void GameObject_Finalize(GameObject* obj);              // Address: 0x004B4030 - Финализация объекта

// Связанные функции из SpriteS1
SpriteS1* SpriteS1_GetGameObject(SpriteS1* sprite);     // Address: 0x0041EEA0
void SpriteS1_SetGameObject(SpriteS1* sprite, GameObject* obj); // Address: 0x004A1180
