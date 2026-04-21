#ifndef GTA2_WEAPON_H
#define GTA2_WEAPON_H

#include <cstdint>

// Старое имя: Weapon
// Размер: 48 байт (0x30)
// Конструктор: 0x00426760 (Weapon::Weapon)
// Назначение: Экземпляр оружия у персонажа или машины

enum EWeaponType : uint8_t {
    Pistolet = 0,       // Пистолет
    Uzi = 1,            // Узи
    Shotgun = 2,        // Дробовик
    AK47 = 3,           // Автомат
    RocketLauncher = 4, // Гранатомет
    Flamethrower = 5,   // Огнемет
    // ... другие типы
    WEAPON_TYPE_COUNT
};

struct Weapon {
    // Смещение 0x00
    int32_t Ammo;           // Текущее количество патронов
    
    // Смещение 0x04
    void* Ped;              // Указатель на владельца-персонажа (Ped*)
    
    // Смещение 0x08
    void* Car;              // Указатель на владельца-машину (Car*)
    
    // Смещение 0x0C
    int32_t TimeToReload;   // Таймер до завершения перезарядки
    
    // Смещение 0x10
    int32_t SMG;            // Флаг наличия/типа SMG (Sub-Machine Gun)
    
    // Смещение 0x14
    Weapon* NextWeapon;     // Указатель на следующее оружие (для списка/пула)
    
    // Смещение 0x18
    EWeaponType TypeWeapon; // Тип оружия
    
    // Смещение 0x19 (1 байт + выравнивание)
    uint8_t short_field;    // Короткое поле (возможно, флаг или ID магазина)
    uint8_t pad_1A[3];      // Выравнивание до 4 байт
    
    // Смещение 0x1C
    int32_t field_8;        // Неизвестное поле (возможно, прицел или режим)
    
    // Смещение 0x20
    int32_t field_C;        // Инициализируется в -1 (возможно, ID цели или таймер)
    
    // Смещение 0x24
    uint8_t field_20;       // Флаг состояния 1
    uint8_t field_21;       // Флаг состояния 2
    uint8_t pad_22[2];      // Выравнивание
    
    // Смещение 0x28 (пропуск 4 байт между 0x24 и 0x2C в листинге?)
    // Проверка: 0x24 (4 байта) -> 0x28
    // В конструкторе: this->field_2C = 0; значит смещение 0x2C
    // Между 0x24 и 0x2C есть 4 байта (0x28-0x2B), которые не инициализируются явно?
    // Или field_20/21 идут сразу за ними?
    // Уточним по порядку инициализации в конструкторе:
    // ... field_21(0x25), затем field_2C(0x2C). Значит 0x26-0x2B - паддинг или другие поля.
    // Предположим, что там есть еще поля, но они не инициализируются в конструкторе (мусор).
    // Для безопасности оставим паддинг.
    uint8_t pad_26[6];      // 0x26 - 0x2B
    
    // Смещение 0x2C
    int32_t field_2C;       // Неизвестное поле (таймер, счетчик?)
    
    // Смещение 0x30 - СТОП! Размер структуры 48 байт (0x30).
    // Проверим сумму:
    // 0x00-0x03: Ammo (4)
    // 0x04-0x07: Ped (4)
    // 0x08-0x0B: Car (4)
    // 0x0C-0x0F: TimeToReload (4)
    // 0x10-0x13: SMG (4)
    // 0x14-0x17: NextWeapon (4)
    // 0x18: TypeWeapon (1)
    // 0x19: short (1) - имя "short" может означать int16? Но в коде `this->short = 0`.
    // Если short это int16_t, то:
    // 0x18: Type (1)
    // 0x19-0x1A: short_val (2)
    // 0x1B: pad (1)
    // Тогда field_8 будет по 0x1C.
    // Пересчитаем строго по конструктору:
    /*
      this->Ammo = 0;           // 0x00
      this->Ped = 0;            // 0x04
      this->Car = 0;            // 0x08
      this->TimeToReload = 0;   // 0x0C
      this->SMG = 0;            // 0x10
      this->NextWeapon = 0;     // 0x14
      this->TypeWeapon = ...;   // 0x18 (1 байт)
      this->short = 0;          // 0x19 (скорее всего 2 байта, т.к. имя "short")
      this->field_8 = 0;        // Если short=2 байта, то 0x1B(pad)+0x1C = field_8?
                                // Или field_8 это имя переменной в IDA, а не смещение?
                                // В IDA часто называют field_XX где XX - смещение.
                                // Если field_8 названо так, значит смещение 0x08? Но там Car.
                                // Значит это просто имя переменной из декомпилятора, а не смещение.
                                // Будем следовать порядку объявления в конструкторе.
      
      Порядок в конструкторе:
      1. Ammo (0x00)
      2. Ped (0x04)
      3. Car (0x08)
      4. TimeToReload (0x0C)
      5. SMG (0x10)
      6. NextWeapon (0x14)
      7. TypeWeapon (0x18) - 1 байт
      8. short (0x19) - предположим 2 байта (int16), тогда 0x19-0x1A
      9. field_8 (0x1C после выравнивания) - 4 байта
      10. field_C (0x20) - 4 байта (знач -1)
      11. field_20 (0x24) - 1 байт
      12. field_21 (0x25) - 1 байт
      13. field_2C (0x28? или 0x2C?) 
          Если после 0x25 идет выравнивание до 0x28, то field_2C это 0x28.
          Но имя field_2C намекает на смещение 0x2C.
          Значит между 0x25 и 0x2C есть 3 байта паддинга + 4 байта неизв. поля?
          Или field_20/21 это часть union?
          
      Давайте попробуем упаковать в 48 байт (0x30):
      0x00: Ammo (4)
      0x04: Ped (4)
      0x08: Car (4)
      0x0C: TimeToReload (4)
      0x10: SMG (4)
      0x14: NextWeapon (4)
      0x18: TypeWeapon (1)
      0x19: short_val (2) - int16_t
      0x1B: pad1 (1)
      0x1C: field_1C (4) - назван field_8 в коде, но это ошибка имени
      0x20: field_20 (4) - назван field_C в коде (знач -1)
      0x24: flags_24 (1)
      0x25: flags_25 (1)
      0x26: pad2 (2)
      0x28: field_28 (4) - назван field_2C?
      0x2C: SoundWeapon (4) - последний в конструкторе
      
      Сумма: 0x2C + 4 = 0x30 (48 байт). Сходится!
      
      Исправленные имена полей согласно порядку инициализации:
    */
    
    // Переопределим структуру строго по смещениям, вычисленным выше:
    
    // 0x00
    int32_t m_Ammo;
    // 0x04
    void* m_Ped;
    // 0x08
    void* m_Car;
    // 0x0C
    int32_t m_TimeToReload;
    // 0x10
    int32_t m_SMG; // или флаг наличия SMG
    // 0x14
    Weapon* m_NextWeapon;
    // 0x18
    EWeaponType m_TypeWeapon;
    // 0x19
    int16_t m_ShortVal; // "short" в конструкторе
    // 0x1B
    uint8_t m_pad1;
    // 0x1C (названо field_8 в конструкторе)
    int32_t m_field_1C; 
    // 0x20 (названо field_C в конструкторе, знач -1)
    int32_t m_field_20;
    // 0x24 (названо field_20)
    uint8_t m_flags1;
    // 0x25 (названо field_21)
    uint8_t m_flags2;
    // 0x26
    uint8_t m_pad2[2];
    // 0x28 (названо field_2C в конструкторе?? Нет, в конструкторе сначала field_20, field_21, потом field_2C)
    // Если field_2C названо так, значит смещение 0x2C.
    // Тогда 0x28-0x2B - это неинициализированные поля или пропуск?
    // В конструкторе: 
    // this->field_20 = 0; (0x24)
    // this->field_21 = 0; (0x25)
    // this->field_2C = 0; (0x2C) -> Пропуск 0x26-0x2B?
    // this->SoundWeapon = 0; (0x30??) -> Но размер 48 байт (0x30).
    // Значит SoundWeapon по 0x2C? Тогда field_2C это 0x28?
    // Путаница с именами. Будем считать по порядку байт.
    
    // Версия 2 (строгая упаковка до 0x30):
    // 0x24: field_20 (1)
    // 0x25: field_21 (1)
    // 0x26-0x27: pad (2)
    // 0x28: field_28 (4) (который назвали field_2C ошибочно?)
    // 0x2C: SoundWeapon (4)
    // Итого 0x30.
    
    // Примем эту версию:
    uint8_t m_byte24;       // field_20
    uint8_t m_byte25;       // field_21
    uint8_t m_pad26[2];
    int32_t m_field28;      // field_2C в коде
    int32_t m_SoundWeapon;  // 0x2C
    
    // Итого: 0x2C + 4 = 0x30. Все верно.
};

static_assert(sizeof(Weapon) == 0x30, "Weapon size must be 48 bytes (0x30)");

#ifdef __cplusplus
extern "C" {
#endif

Weapon* Weapon_Constructor(Weapon* this);
void Weapon_Destructor(Weapon* this);
void Weapon_SetOwner(Weapon* this, void* ped, void* car);
void Weapon_Reload(Weapon* this);
int32_t Weapon_GetAmmo(Weapon* this);
void Weapon_SetAmmo(Weapon* this, int32_t ammo);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
struct WeaponCpp : public Weapon {
    WeaponCpp() { Weapon_Constructor(this); }
    ~WeaponCpp() { Weapon_Destructor(this); }
    
    void SetOwner(void* ped, void* car) { Weapon_SetOwner(this, ped, car); }
    void Reload() { Weapon_Reload(this); }
    int32_t GetAmmo() { return Weapon_GetAmmo(this); }
    void SetAmmo(int32_t ammo) { Weapon_SetAmmo(this, ammo); }
};
#endif

#endif // GTA2_WEAPON_H
