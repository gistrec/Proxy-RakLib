#include "RemoteClient.h"

RemoteClient::RemoteClient(sockaddr_in &address) {
    // Копируем адрес клиента
    memcpy(&_address, &address, sizeof(address));
}

void RemoteClient::handlePacket(Packet &packet) {

}

void RemoteClient::send(Packet &packet) {

}

RemoteClient::~RemoteClient() {

}