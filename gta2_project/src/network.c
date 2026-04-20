#include "network.h"
#include <string.h>

// ============================================================================
// УТИЛИТЫ
// ============================================================================

u8 Net_CalculateChecksum(const void* data, u16 len) {
    if (!data || len == 0) return 0;
    
    const u8* bytes = (const u8*)data;
    u32 sum = 0;
    
    for (u16 i = 0; i < len; i++) {
        sum += bytes[i];
        sum = (sum >> 16) + (sum & 0xFFFF); // Fold 32-bit sum to 16 bits
    }
    
    return (u8)(~sum & 0xFF);
}

bool Net_VerifyChecksum(PacketHeader* header, u8* payload) {
    if (!header) return false;
    
    u8 calculated = Net_CalculateChecksum(payload, header->PayloadLen);
    return (calculated == header->Checksum);
}

// ============================================================================
// ИНИЦИАЛИЗАЦИЯ И ЗАВЕРШЕНИЕ
// ============================================================================

bool Net_Init(NetworkSession* session, NetMode mode) {
    if (!session) return false;
    
    memset(session, 0, sizeof(NetworkSession));
    session->Mode = mode;
    session->MaxPlayers = MAX_NETWORK_PLAYERS;
    session->SyncRate = 30; // 30 тиков в секунду
    session->LagCompensation = 1;
    session->IsRunning = 0;
    
    // В реальной реализации здесь создается сокет
    // session->SocketHandle = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    
    return true;
}

void Net_Shutdown(NetworkSession* session) {
    if (!session) return;
    
    if (session->IsRunning) {
        Net_LeaveGame(session);
    }
    
    // Закрытие сокета
    // closesocket(session->SocketHandle);
    
    memset(session, 0, sizeof(NetworkSession));
}

void Net_Reset(NetworkSession* session) {
    if (!session) return;
    
    session->ActiveCount = 0;
    session->LastPacketTime = 0;
    session->PacketsSent = 0;
    session->PacketsReceived = 0;
    session->BytesSent = 0;
    session->BytesReceived = 0;
    
    for (int i = 0; i < MAX_NETWORK_PLAYERS; i++) {
        session->Players[i].StateFlags = 0;
    }
}

// ============================================================================
// УПРАВЛЕНИЕ СЕССИЕЙ
// ============================================================================

bool Net_HostGame(NetworkSession* session, u16 port, u8 maxPlayers) {
    if (!session || session->Mode != NET_MODE_HOST) return false;
    
    session->LocalPlayerID = 0; // Хост всегда игрок 0
    session->MaxPlayers = maxPlayers;
    session->IsRunning = 1;
    session->ServerTime = 0;
    
    // Инициализация локального игрока
    NetworkPlayer* local = &session->Players[0];
    local->PlayerID = 0;
    local->StateFlags = 3; // Connected | Ready
    strcpy(local->AvatarName, "Host");
    
    return true;
}

bool Net_JoinGame(NetworkSession* session, u32 ip, u16 port) {
    if (!session || session->Mode != NET_MODE_CLIENT) return false;
    
    // Отправка запроса на присоединение
    // В реальной реализации: sendto(socket, JOIN_REQUEST, ...)
    
    session->IsRunning = 1;
    session->LocalPlayerID = 255; // Пока не назначен
    
    return true;
}

void Net_LeaveGame(NetworkSession* session) {
    if (!session) return;
    
    // Отправка сообщения о выходе
    if (session->IsRunning) {
        Net_SendPacket(session, 255, NET_MSG_LEAVE, NULL, 0);
    }
    
    session->IsRunning = 0;
    Net_Reset(session);
}

// ============================================================================
// ОТПРАВКА И ПОЛУЧЕНИЕ ПАКЕТОВ
// ============================================================================

bool Net_SendPacket(NetworkSession* session, u8 targetPlayerId, NetMessageType type, const void* data, u16 len) {
    if (!session || !session->IsRunning) return false;
    if (len > NETWORK_BUFFER_SIZE - sizeof(PacketHeader)) return false;
    
    // Формирование заголовка
    PacketHeader* header = (PacketHeader*)session->SendBuffer;
    header->Magic = NETWORK_PROTOCOL_MAGIC;
    header->MsgType = type;
    header->Flags = 1; // Reliable по умолчанию
    header->SequenceNum = (u16)(session->PacketsSent & 0xFFFF);
    header->PayloadLen = len;
    
    // Копирование данных
    if (data && len > 0) {
        memcpy(session->SendBuffer + sizeof(PacketHeader), data, len);
    }
    
    // Расчет чексуммы
    header->Checksum = Net_CalculateChecksum(
        session->SendBuffer + sizeof(PacketHeader), 
        len
    );
    
    // В реальной реализации: sendto(socket, buffer, totalLen, ...)
    session->PacketsSent++;
    session->BytesSent += sizeof(PacketHeader) + len;
    
    return true;
}

bool Net_ReceivePackets(NetworkSession* session) {
    if (!session || !session->IsRunning) return false;
    
    // В реальной реализации: recvfrom(socket, buffer, ...)
    // Здесь заглушка для демонстрации
    
    return true;
}

void Net_ProcessIncomingMessage(NetworkSession* session, PacketHeader* header, u8* payload) {
    if (!session || !header) return;
    
    // Проверка чексуммы
    if (!Net_VerifyChecksum(header, payload)) {
        return; // Пакет поврежден
    }
    
    session->PacketsReceived++;
    session->BytesReceived += sizeof(PacketHeader) + header->PayloadLen;
    
    // Обработка по типу сообщения
    switch (header->MsgType) {
        case NET_MSG_PING:
            // Отправить PONG обратно
            break;
            
        case NET_MSG_INPUT_DATA:
            // Обновить ввод удаленного игрока
            break;
            
        case NET_MSG_DAMAGE:
            // Применить урон
            break;
            
        case NET_MSG_PLAYER_DIED:
            // Обработать смерть
            break;
            
        default:
            break;
    }
}

// ============================================================================
// РАБОТА С ИГРОКАМИ
// ============================================================================

NetworkPlayer* Net_GetPlayer(NetworkSession* session, u8 playerId) {
    if (!session || playerId >= MAX_NETWORK_PLAYERS) return NULL;
    return &session->Players[playerId];
}

NetworkPlayer* Net_GetLocalPlayer(NetworkSession* session) {
    if (!session) return NULL;
    return Net_GetPlayer(session, session->LocalPlayerID);
}

void Net_UpdatePlayerPing(NetworkSession* session, u8 playerId, u16 ping) {
    NetworkPlayer* player = Net_GetPlayer(session, playerId);
    if (player) {
        player->PingMS = ping;
    }
}

// ============================================================================
// СИНХРОНИЗАЦИЯ
// ============================================================================

void Net_SendInput(NetworkSession* session, u32 inputData) {
    if (!session) return;
    
    // Отправка сжатых данных ввода
    Net_SendPacket(session, 255, NET_MSG_INPUT_DATA, &inputData, sizeof(inputData));
}

void Net_InterpolatePlayer(NetworkPlayer* player, f32 dt) {
    if (!player) return;
    
    // Плавная интерполяция позиции между полученными пакетами
    // В реальной реализации используется экстраполяция на основе скорости
    // и последний известный ввод
}

void Net_SyncWorldState(NetworkSession* session) {
    if (!session || session->Mode != NET_MODE_HOST) return;
    
    // Хост периодически отправляет полное состояние мира
    // для коррекции рассинхронизации
}
