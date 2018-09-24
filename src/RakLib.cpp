#include "RakLib.h"

RakLib::RakLib(sockaddr_in &address)
        : _socket(address)
{
    // Копируем адрес клиента
    memcpy(&_address, &address, sizeof(address));
}

void handlePacket(Packet &packet, RemoteClient &client) {

}

void handlePacket(Packet &packet, sockaddr_in &address) {

}