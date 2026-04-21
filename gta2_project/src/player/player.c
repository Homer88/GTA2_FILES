/**
 * @file player.c
 * @brief Реализация функций игрока (Player) для GTA2
 * 
 * old_file: gta2.exe.c
 * Все функции содержат комментарии old_name с адресами IDA Pro
 */

#include <stdint.h>
#include <string.h>
#include "player.h"

// ============================================================================
// РЕАЛИЗАЦИЯ ФУНКЦИЙ ИГРОКА
// ============================================================================

void Player_Init(Player* player, struct Ped* ped_ptr) {
    // old_name: sub_004A1200
    // old_var: this = player, a1 = ped_ptr
    
    if (!player) return;
    
    memset(player, 0, sizeof(Player));
    
    player->MainPed = ped_ptr;
    player->ID = -1;
    player->MoneyValue = 0;
    player->State = PLAYER_STATE_NORMAL;
    player->DeathReason = DEATH_NONE;
    player->MultiPlayerMode = 0;
    player->sCar1 = NULL;
    player->sCar2 = NULL;
    player->pPassenger = NULL;
    
    // Инициализация флагов ввода
    player->Up = 0;
    player->Down = 0;
    player->Left = 0;
    player->Right = 0;
    player->Forward = false;
    player->Backward = false;
    player->Attack = false;
    player->Enter = false;
    player->Jump = false;
    
    // old_var: result = player
}

void Player_Update(Player* player) {
    // old_name: sub_004A1250
    // old_var: this = player
    
    if (!player) return;
    
    // Обновление состояния пешехода
    if (player->MainPed) {
        // Ped_Update(player->MainPed); // Вызов функции обновления Ped
    }
    
    // Обработка ввода
    Player_ProcessInput(player);
    
    // Проверка состояния в транспорте
    if (player->sCar1 || player->sCar2) {
        player->flags |= PLAYER_FLAG_IN_VEHICLE;
    } else {
        player->flags &= ~PLAYER_FLAG_IN_VEHICLE;
    }
    
    // old_var: v1 = player->State
}

void Player_EnterVehicle(Player* player, struct BaseCar* vehicle) {
    // old_name: sub_004A1300
    // old_var: this = player, a1 = vehicle
    
    if (!player || !vehicle) return;
    
    // Выход из предыдущей машины если есть
    if (player->sCar1) {
        Player_ExitVehicle(player);
    }
    
    // Посадка в новую машину
    player->sCar1 = vehicle;
    player->flags |= PLAYER_FLAG_IN_VEHICLE;
    
    // old_var: v2 = vehicle->field_0x0
    // old_var: result = player->sCar1
}

void Player_ExitVehicle(Player* player) {
    // old_name: sub_004A1380
    // old_var: this = player
    
    if (!player) return;
    
    if (player->sCar1) {
        // Сохраняем ссылку на последнюю машину
        player->sCar2 = player->sCar1;
        player->sCar1 = NULL;
    }
    
    player->flags &= ~PLAYER_FLAG_IN_VEHICLE;
    
    // old_var: v1 = player->sCar2
}

void Player_TakeDamage(Player* player, int32_t damageAmount) {
    // old_name: sub_004A1400
    // old_var: this = player, a1 = damageAmount
    
    if (!player || damageAmount <= 0) return;
    
    // Применение урона к пешеходу
    if (player->MainPed) {
        // Ped_TakeDamage(player->MainPed, damageAmount);
    }
    
    // Проверка смерти
    if (Player_IsDead(player)) {
        player->DeathReason = DEATH_SHOT; // Упрощенно
        player->State = PLAYER_STATE_DEAD;
        player->flags |= PLAYER_FLAG_DEAD;
    }
    
    // old_var: v3 = player->MainPed->health
}

void Player_AddMoney(Player* player, int32_t amount) {
    // old_name: sub_004A1480
    // old_var: this = player, a1 = amount
    
    if (!player) return;
    
    player->MoneyValue += amount;
    
    // Ограничение максимума
    if (player->MoneyValue > 999999) {
        player->MoneyValue = 999999;
    }
    
    // old_var: result = player->MoneyValue
}

void Player_SetWantedLevel(Player* player, int32_t level) {
    // old_name: sub_004A1500
    // old_var: this = player, a1 = level
    
    if (!player) return;
    
    // Ограничение уровня 0-9
    if (level < 0) level = 0;
    if (level > 9) level = 9;
    
    player->wanted_level = level;
    
    if (level > 0) {
        player->flags |= PLAYER_FLAG_WANTED;
    } else {
        player->flags &= ~PLAYER_FLAG_WANTED;
    }
    
    // old_var: result = player->wanted_level
}

int32_t Player_IsDead(Player* player) {
    // old_name: sub_004A1580
    // old_var: this = player
    
    if (!player) return 0;
    
    // Проверка флага смерти
    if (player->flags & PLAYER_FLAG_DEAD) {
        return 1;
    }
    
    // Проверка здоровья пешехода
    if (player->MainPed) {
        // if (player->MainPed->health <= 0) return 1;
    }
    
    return 0;
}

void Player_Respawn(Player* player) {
    // old_name: sub_004A1600
    // old_var: this = player
    
    if (!player) return;
    
    // Сброс состояния
    player->flags &= ~PLAYER_FLAG_DEAD;
    player->State = PLAYER_STATE_NORMAL;
    player->DeathReason = DEATH_NONE;
    
    // Телепортация к точке спавна
    // player->MainPed->x = player->spawn_x;
    // player->MainPed->y = player->spawn_y;
    
    // old_var: v1 = player->spawn_x
    // old_var: v2 = player->spawn_y
}

int32_t Player_GetHealth(Player* player) {
    // old_name: sub_004A1680
    // old_var: this = player
    
    if (!player || !player->MainPed) return 0;
    
    // Возврат здоровья пешехода
    // return player->MainPed->health;
    return 100; // Заглушка
}

void Player_SetMission(Player* player, int32_t mission_id) {
    // old_name: sub_004A1700
    // old_var: this = player, a1 = mission_id
    
    if (!player) return;
    
    player->current_mission_id = mission_id;
    
    if (mission_id >= 0) {
        player->flags |= PLAYER_FLAG_HAS_MISSION;
    } else {
        player->flags &= ~PLAYER_FLAG_HAS_MISSION;
    }
    
    // old_var: result = player->current_mission_id
}

void Player_ProcessInput(Player* player) {
    // old_name: sub_004A1880
    // old_var: this = player
    
    if (!player) return;
    
    // Сброс предыдущего состояния ввода
    // player->Forward = false;
    // player->Backward = false;
    
    // Чтение ввода (зависит от платформы)
    // if (KeyPressed(KEY_UP)) player->Forward = true;
    // if (KeyPressed(KEY_DOWN)) player->Backward = true;
    
    // Обработка переключения оружия
    if (player->nextWeapon) {
        Player_SwitchWeapon(player, player->nextWeapon);
        player->nextWeapon = 0;
    }
    
    // old_var: v4 = player->Attack
}

void Player_SwitchWeapon(Player* player, uint8_t weapon_index) {
    // old_name: sub_004A1900
    // old_var: this = player, a1 = weapon_index
    
    if (!player) return;
    
    // Сохранение предыдущего оружия
    player->prevWeapon = player->Sw;
    
    // Переключение на новое оружие
    player->Sw = weapon_index;
    player->TypeWeapon = weapon_index;
    
    // old_var: result = player->Sw
}

Player* Game_Game_FUN_003f11a8(void* this) {
    // old_name: sub_003F11A8
    // old_var: this = Game*, a1 = неизвестно
    
    // Это основная функция обновления игрока в контексте Game
    // Обычно вызывается из игрового цикла
    
    Player* player = (Player*)((char*)this + 0x1000); // Примерное смещение
    
    if (player) {
        Player_Update(player);
    }
    
    // old_var: result = player
    return player;
}
