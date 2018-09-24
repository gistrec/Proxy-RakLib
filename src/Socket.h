#ifndef MULTIRAKLIB_SOCKET_H
#define MULTIRAKLIB_SOCKET_H

#include <arpa/inet.h> // inet_ntoa
#include <netinet/in.h> // sockaddr_in
#include <unistd.h> // read(), close()
#include <fcntl.h>  // fcntl()
#include <stdexcept> // std::runtime_error
#include <iostream> // cout, endl
#include <cstring> // memcpy

#include "Packets/Packet.h"
#include "RemoteClient/RemoteClient.h"

#define BUFLEN 512

using namespace std;

class Socket {
private:
    /**
     * Дискриптор сокета
     */
    int _sockfd;

    /**
     * Адрес сокета
     */
    struct sockaddr_in _address;
public:
    /**
     * Создаем сокет с нужным IP адресом и портом
     * @param address
     * @param port
     */
    Socket(struct sockaddr_in& address);

    /**
     * Отправляем пакет
     * @param addr - адрес
     * @param buf  - набор байт
     * @param buf_size - кол-во байт
     */
    void send(const struct sockaddr_in *addr, const char *buf, int buf_size);

    /**
     * Чтение данных из сокета
     * @param buf  - сюда запишутся данные
     * @param addr - сюда запишется адрес
     * @param addr_len - сюда запишется длина адреса
     * @return int - кол-во байт в принятой датаграмме
     */
    int read(char *buf, struct sockaddr_in* addr, unsigned int *addr_len);

    /**
     * Освобождаем дискриптор сокета
     */
    ~Socket();
};


#endif //MULTIRAKLIB_SOCKET_H
