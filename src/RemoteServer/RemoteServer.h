#ifndef MULTIRAKLIB_REMOTESERVER_H
#define MULTIRAKLIB_REMOTESERVER_H

#include <vector>
#include "../Packets/Packet.h"
#include "../RemoteClient/RemoteClient.h"

/**
 * Класс описывает сущность удаленного сервера
 */
class RemoteServer {
private:
    /**
     * Адрес сервера
     */
    struct sockaddr_in address;

    /**
     * Клиенты на текущем сервере
     */
    std::vector<RemoteClient> clients;

    /**
     * Сокет для общения с сервером
     */
    Socket internalSocket;
public:
    /**
     * В конструкторе создаем сокет
     * @param address
     */
    RemoteServer(sockaddr_in &address);

    /**
     * Функция вызывается при получении пакета от сервера
     * @param packet
     */
    void handlePacket(Packet &packet);
};


#endif //MULTIRAKLIB_REMOTESERVER_H
