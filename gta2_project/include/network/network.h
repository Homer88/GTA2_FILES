#ifndef NETWORK_H
#define NETWORK_H

#include "types.h"
#include "systems/vector2d.h"

// ============================================================================
// 1. СЕТЕВЫЕ КОНСТАНТЫ И ТИПЫ
// ============================================================================

#define MAX_NETWORK_PLAYERS 8
#define NETWORK_BUFFER_SIZE 512
#define NETWORK_PORT_DEFAULT 27015
#define NETWORK_PROTOCOL_MAGIC 0x47544132 // "GTA2"

// ============================================================================
// 2. ТИПЫ СЕТЕВЫХ СООБЩЕНИЙ
// ============================================================================

typedef enum {
    NET_MSG_NONE = 0,
    NET_MSG_PING = 1,
    NET_MSG_PONG = 2,
    NET_MSG_JOIN_REQUEST = 3,
    NET_MSG_JOIN_ACCEPT = 4,
    NET_MSG_JOIN_REJECT = 5,
    NET_MSG_LEAVE = 6,
    NET_MSG_INPUT_DATA = 7,
    NET_MSG_PLAYER_SPAWN = 8,
    NET_MSG_PLAYER_DESPAWN = 9,
    NET_MSG_DAMAGE = 10,
    NET_MSG_PLAYER_DIED = 11,
    NET_MSG_CHAT_MESSAGE = 12,
    NET_MSG_GAME_STATE = 13,
    NET_MSG_MISSION_START = 14,
    NET_MSG_MISSION_END = 15
} NetMessageType;

// ============================================================================
// 3. ЗАГОЛОВОК ПАКЕТА (8 байт)
// ============================================================================

typedef struct {
    u32 Magic;          // 0x00 - Сигнатура протокола (0x47544132 = "GTA2")
    u8 MsgType;         // 0x04 - Тип сообщения (NetMessageType)
    u8 Flags;           // 0x05 - Флаги доставки (бит 0: reliable, бит 1: encrypted)
    u16 SequenceNum;    // 0x06 - Порядковый номер пакета
    u16 PayloadLen;     // 0x08 - Длина полезных данных
    u8 Checksum;        // 0x0A - Контрольная сумма
    u8 Padding;         // 0x0B - Выравнивание до 12 байт
} PacketHeader;         // Размер: 12 байт

// ============================================================================
// 4. УДАЛЕННЫЙ ИГРОК (48 байт)
// ============================================================================

typedef struct {
    u8 PlayerID;            // 0x00 - Уникальный слот (0-7)
    u8 StateFlags;          // 0x01 - Флаги (Connected, Ready, Talking)
    u8 TeamID;              // 0x02 - ID команды
    u8 Padding;             // 0x03 - Выравнивание
    u32 IPAddress;          // 0x04 - IP адрес
    u16 Port;               // 0x08 - Порт соединения
    u16 PingMS;             // 0x0A - Задержка в миллисекундах
    u16 ControlledPedID;    // 0x0C - ID пешехода игрока
    u16 ControlledCarID;    // 0x0E - ID машины (или 0xFFFF если пешком)
    u32 LastInputSeq;       // 0x10 - Последний номер пакета ввода
    u32 LastInputData;      // 0x14 - Последние данные ввода (кнопки)
    u32 Score;              // 0x18 - Текущий счет
    u16 Kills;              // 0x1C - Количество убийств
    u16 Deaths;             // 0x1E - Количество смертей
    char AvatarName[16];    // 0x20 - Имя игрока (null-terminated)
} NetworkPlayer;            // Размер: 48 байт

// ============================================================================
// 5. СЕТЕВАЯ СЕССИЯ (~1200 байт)
// ============================================================================

typedef enum {
    NET_MODE_NONE = 0,
    NET_MODE_HOST = 1,
    NET_MODE_CLIENT = 2,
    NET_MODE_LISTENER = 3
} NetMode;

typedef struct {
    // Основная информация
    u8 Mode;                    // 0x00 - Режим работы (NetMode)
    u8 Padding[3];              // 0x01 - Выравнивание
    void* SocketHandle;         // 0x04 - Дескриптор сокета (platform-specific)
    u8 LocalPlayerID;           // 0x08 - ID локального игрока
    u8 MaxPlayers;              // 0x09 - Максимум игроков (обычно 8)
    u8 ActiveCount;             // 0x0A - Количество подключенных
    u8 SyncRate;                // 0x0B - Частота синхронизации (тикрат в секунду)
    
    // Игроки
    NetworkPlayer Players[MAX_NETWORK_PLAYERS]; // 0x0C - Массив игроков
    
    // Буферы
    u8 RecvBuffer[NETWORK_BUFFER_SIZE];   // 0xAC - Буфер приема
    u8 SendBuffer[NETWORK_BUFFER_SIZE];   // 0x2AC - Буфер отправки
    
    // Настройки
    u8 LagCompensation : 1;     // 0x4AC - Включение сглаживания лагов
    u8 IsRunning : 1;           // 0x4AC - Сессия активна
    u8 Unused : 6;              // 0x4AC - Не используется
    u8 Padding2[3];             // 0x4AD - Выравнивание
    
    // Время
    u32 ServerTime;             // 0x4B0 - Время сервера (для синхронизации)
    u32 LastPacketTime;         // 0x4B4 - Время последнего полученного пакета
    
    // Статистика
    u32 PacketsSent;            // 0x4B8 - Отправлено пакетов
    u32 PacketsReceived;        // 0x4BC - Получено пакетов
    u32 BytesSent;              // 0x4C0 - Отправлено байт
    u32 BytesReceived;          // 0x4C4 - Получено байт
} NetworkSession;               // Размер: ~1224 байта

// ============================================================================
// 6. ПРОТОТИПЫ ФУНКЦИЙ
// ============================================================================

// Инициализация и завершение
bool Net_Init(NetworkSession* session, NetMode mode);
void Net_Shutdown(NetworkSession* session);
void Net_Reset(NetworkSession* session);

// Управление сессией
bool Net_HostGame(NetworkSession* session, u16 port, u8 maxPlayers);
bool Net_JoinGame(NetworkSession* session, u32 ip, u16 port);
void Net_LeaveGame(NetworkSession* session);

// Отправка/Получение
bool Net_SendPacket(NetworkSession* session, u8 targetPlayerId, NetMessageType type, const void* data, u16 len);
bool Net_ReceivePackets(NetworkSession* session);
void Net_ProcessIncomingMessage(NetworkSession* session, PacketHeader* header, u8* payload);

// Работа с игроками
NetworkPlayer* Net_GetPlayer(NetworkSession* session, u8 playerId);
NetworkPlayer* Net_GetLocalPlayer(NetworkSession* session);
void Net_UpdatePlayerPing(NetworkSession* session, u8 playerId, u16 ping);

// Синхронизация
void Net_SendInput(NetworkSession* session, u32 inputData);
void Net_InterpolatePlayer(NetworkPlayer* player, f32 dt);
void Net_SyncWorldState(NetworkSession* session);

// Утилиты
u8 Net_CalculateChecksum(const void* data, u16 len);
bool Net_VerifyChecksum(PacketHeader* header, u8* payload);

#endif // NETWORK_H
