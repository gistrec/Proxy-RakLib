#ifndef MULTIRAKLIB_REMOTESERVER_H
#define MULTIRAKLIB_REMOTESERVER_H

#include <vector>
#include "../Packets/Packet.h"
#include "../RemoteClient/RemoteClient.h"
#include "../Socket.h"

/**
 * Класс описывает сущность удаленного сервера
 */
class RemoteServer {
private:
    /**
     * Адрес сервера
     */
    struct sockaddr_in _address;

    /**
     * Клиенты на текущем сервере
     */
    std::vector<RemoteClient> _clients;

    /**
     * Сокет для общения с сервером
     */
    Socket _socket;
public:
    /**
     * В конструкторе создаем сокет
     * @param address
     */
    explicit RemoteServer(sockaddr_in &address);

    /**
     * Функция вызывается при получении пакета от сервера
     * @param packet
     */
    void handlePacket(Packet &packet);
};


#endif //MULTIRAKLIB_REMOTESERVER_H
