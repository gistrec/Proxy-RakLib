#ifndef MULTIRAKLIB_RAKLIB_H
#define MULTIRAKLIB_RAKLIB_H

#include "./Socket.h"
#include "RemoteClient/RemoteClient.h"
#include "RemoteServer/RemoteServer.h"

class RakLib {
private:
    /**
     * Внешний адрес раклиба
     */
    sockaddr_in _address;

    /**
     * Сокет для общения с клиентами
     */

    Socket _socket;
    /**
     * Массив с клиентами
     */
    // vector<RemoteServer> _servers;

    /**
     * Массив с удаленными серверами
     */
    // vector<RemoteClient> _clients;

public:
    /**
     * Создаем сокет
     */
    explicit RakLib(sockaddr_in &address);

    /**
     * Функция вызывается при получении пакета от игрока
     * @param packet пакет
     */
    void handlePacket(Packet &packet, RemoteClient &client);
    void handlePacket(Packet &packet, sockaddr_in &address);
};


#endif //MULTIRAKLIB_RAKLIB_H
