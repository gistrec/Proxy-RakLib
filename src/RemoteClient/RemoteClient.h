#ifndef MULTIRAKLIB_REMOTECLIENT_H
#define MULTIRAKLIB_REMOTECLIENT_H

#include "../Packets/Packet.h"

class RemoteClient {
private:
    /**
     * Стадии подключения к раклибу
     */
    enum State {connecting, connected, disconnecting, disconnected};

    /**
     * Стадия подключения к раклибу
     */
    State _state = connecting;

    /**
    * Адрес клиента
    */
    struct sockaddr_in _address;

public:
    explicit RemoteClient(sockaddr_in &address);

    /**
     * Функция вызывается при получении пакета от игрока
     * @param packet пакет
     */
    void handlePacket(Packet &packet);

    /**
     * Функция нужна для отправки игроку пакета
     * @param packet
     */
    void send(Packet &packet);

    ~RemoteClient();
};


#endif //MULTIRAKLIB_REMOTECLIENT_H
