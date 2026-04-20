#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"
#include "enums.h"
#include "forward_declarations.h"

#pragma pack(push, 1)
struct Player {
    // --- Указатели на текущий и основной объект игрока ---
    struct Player *CurrentPlayer;   // Было: CurrentPlayer - Указатель на текущего активного игрока
    struct Player *Player;          // Было: Player - Указатель на основной объект игрока
    
    // --- Управление (Input) ---
    int16_t TurnLeftRight;          // Было: Left - Поворот влево/вправо (48=влево, 1392=вправо)
    int16_t field3_0xa;             // Было: field3_0xa - Неизвестное поле управления (требует анализа)
    int32_t MoveForwardBackward;    // Было: Forw - Движение вперед/назад (16384=вперед, 4294950912=назад)
    
    // --- Состояние транспорта ---
    struct S46 *s46;                // Было: s46 - Указатель на структуру S46 (возможно, данные транспортного средства)
    int16_t SW;                     // Было: SW - Переключатель или состояние (требуется анализ)
    
    // --- Оружие ---
    int16_t TypeWeapon;             // Было: TypeWeapon - Тип текущего оружия
    uint16_t field8_0x18;           // Было: field8_0x18 - Неизвестное поле оружия (возможно, прицел)
    uint16_t Armor;                 // Было: Arrmo - Текущее состояние брони/защиты
    uint16_t SelectWeaponNext;      // Было: SelectWeaponNext - Индекс следующего оружия для выбора
    uint8_t field11_0x1e;           // Было: field11_0x1e - Неизвестный флаг оружия
    uint8_t field12_0x1f;           // Было: field12_0x1f - Неизвестный флаг оружия
    
    // --- Транспорт ---
    struct Car *car;                // Было: car - Указатель на машину, в которой находится игрок
    int ID_1;                       // Было: ID_1 - Первый ID игрока (возможно, связан с Ped)
    uint8_t field15_0x28;           // Было: field15_0x28 - Неизвестное поле транспорта
    uint8_t field16_0x29;           // Было: field16_0x29 - Неизвестное поле транспорта
    uint8_t field17_0x2a;           // Было: field17_0x2a - Неизвестное поле транспорта
    uint8_t field18_0x2b;           // Было: field18_0x2b - Неизвестное поле транспорта
    uint16_t field19_0x2c;          // Было: field19_0x2c - Неизвестное поле транспорта
    
    // --- Идентификаторы и статусы ---
    uint8_t IDs;                    // Было: IDs - Основной ID игрока (байт)
    uint8_t AllControlStatus;       // Было: AllControlStatus - Общий статус управления (все контролы активны?)
    uint8_t EnterControlStatus;     // Было: EnterControlStatus - Статус управления при посадке/высадке
    bool field23_0x31;              // Было: field23_0x31 - Флаг неизвестного назначения
    uint8_t field24_0x32;           // Было: field24_0x32 - Неизвестное поле статуса
    uint8_t field25_0x33;           // Было: field25_0x33 - Неизвестное поле статуса
    
    // --- Репутация и статистика ---
    int32_t RESPECT;                // Было: RESPECT - Уровень репутации/уважения игрока
    int32_t field27_0x38;           // Было: field27_0x38 - Дополнительная статистика (возможно, деньги)
    int32_t field28_0x3c;           // Было: field28_0x3c - Дополнительная статистика (возможно, очки)
    
    // --- Миссии и задания ---
    struct S103 *S103;              // Было: S103 - Указатель на структуру миссии/задания S103
    int PlayerState;                // Было: PlayerState - Состояние игрока (жив, мертв, в машине, арестован)
    uint8_t field31_0x48;           // Было: field31_0x48 - Неизвестное поле состояния
    uint8_t field32_0x49;           // Было: field32_0x49 - Неизвестное поле состояния
    uint8_t field33_0x4a;           // Было: field33_0x4a - Неизвестное поле состояния
    uint8_t field34_0x4b;           // Было: field34_0x4b - Неизвестное поле состояния
    int32_t field35_0x4c;           // Было: field35_0x4c - Неизвестное поле состояния (таймер?)
    uint8_t field36_0x50;           // Было: field36_0x50 - Неизвестное поле состояния
    uint8_t field37_0x51;           // Было: field37_0x51 - Неизвестное поле состояния
    uint8_t field38_0x52;           // Было: field38_0x52 - Неизвестное поле состояния
    uint8_t field39_0x53;           // Было: field39_0x53 - Неизвестное поле состояния
    int32_t field40_0x54;           // Было: field40_0x54 - Неизвестное поле состояния (таймер?)
    
    // --- Физика и камера ---
    int32_t theta;                  // Было: theta - Угол поворота камеры или игрока
    struct Car *pCar_2;             // Было: pCar_2 - Второй указатель на машину (возможно, предыдущая или целевая)
    int32_t Revs;                   // Было: Revs - Обороты двигателя (если в машине)
    int32_t field44_0x64;           // Было: field44_0x64 - Неизвестное поле физики
    int32_t ID;                     // Было: ID - Основной уникальный ID игрока
    int32_t field46_0x6c;           // Было: field46_0x6c - Неизвестное поле (возможно, смещение или таймер)
    
    // --- Флаги и байтовые поля ---
    uint8_t field47_0x70;           // Было: field47_0x70 - Неизвестный флаг
    uint8_t field48_0x71;           // Было: field48_0x71 - Неизвестный флаг
    uint8_t field49_0x72;           // Было: field49_0x72 - Неизвестный флаг
    uint8_t field50_0x73;           // Было: field50_0x73 - Неизвестный флаг
    uint8_t field51_0x74;           // Было: field51_0x74 - Неизвестный флаг
    uint8_t field52_0x75;           // Было: field52_0x75 - Неизвестный флаг
    uint8_t field53_0x76;           // Было: field53_0x76 - Неизвестный флаг
    uint8_t field54_0x77;           // Было: field54_0x77 - Неизвестный флаг
    
    // --- Состояние кнопок управления (Input Flags) ---
    bool KEY_UP;                    // Было: KEY_UP - Флаг нажатия кнопки "Вверх"
    bool Backward;                  // Было: Backward - Флаг нажатия кнопки "Назад"
    bool RotateLeft;                // Было: RotateLeft - Флаг нажатия кнопки "Влево"
    bool RotateRight;               // Было: RotateRight - Флаг нажатия кнопки "Вправо"
    bool Attack;                    // Было: Attack - Флаг нажатия кнопки "Атака/Огонь"
    bool Enter;                     // Было: Enter - Флаг нажатия кнопки "Войти/Выйти"
    uint8_t Jump;                   // Было: Jump - Флаг/состояние прыжка
    uint8_t NextWeaponZ;            // Было: NextWeaponZ - Флаг переключения оружия вперед (клавиша Z)
    uint8_t PrevWeaponX;            // Было: PrevWeaponX - Флаг переключения оружия назад (клавиша X)
    uint8_t keySpecial;             // Было: keySpecial - Флаг специальной кнопки 1
    uint8_t keySpecial2;            // Было: keySpecial2 - Флаг специальной кнопки 2
    uint8_t field66_0x83;           // Было: field66_0x83 - Неизвестный флаг управления
    uint8_t field67_0x84;           // Было: field67_0x84 - Неизвестный флаг управления
    uint8_t field68_0x85;           // Было: field68_0x85 - Неизвестный флаг управления
    uint8_t field69_0x86;           // Было: field69_0x86 - Неизвестный флаг управления
    uint8_t field70_0x87;           // Было: field70_0x87 - Неизвестный флаг управления
    uint8_t field71_0x88;           // Было: field71_0x88 - Неизвестный флаг управления
    uint8_t field72_0x89;           // Было: field72_0x89 - Неизвестный флаг управления
    uint8_t field73_0x8a;           // Было: field73_0x8a - Неизвестный флаг управления
    uint8_t field74_0x8b;           // Было: field74_0x8b - Неизвестный флаг управления
    uint8_t AttackIsChanged;        // Было: AttackIsChanged - Флаг изменения режима атаки
    uint8_t field76_0x8d;           // Было: field76_0x8d - Неизвестный флаг управления
    bool NextPlayer;                // Было: NextPlayer - Флаг переключения на следующего игрока
    uint8_t field78_0x8f;           // Было: field78_0x8f - Неизвестный флаг управления
    
    // --- Камера ---
    struct CameraOrPhysics *CameraOrPhysics; // Было: CameraOrPhysics - Указатель на камеру или физику
    uint8_t field80_0x94;           // Было: field80_0x94 - Неизвестное поле камеры
};
#pragma pack(pop)

// Player function declarations
Player* Game__Game_FUN_003f11a8(Game *this);

#endif // PLAYER_H
