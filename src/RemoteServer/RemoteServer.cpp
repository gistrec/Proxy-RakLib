#include "RemoteServer.h"

RemoteServer::RemoteServer(sockaddr_in &address)
    : _socket(address)
{
    // Копируем адрес сервера
    memcpy(&_address, &address, sizeof(address));
}

void RemoteServer::handlePacket(Packet &packet) {
// TODO: Проверка типа пакета
}