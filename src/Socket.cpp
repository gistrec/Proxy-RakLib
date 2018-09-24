#include "Socket.h"

Socket::Socket(struct sockaddr_in& address) {
    // Создаем дескриптор сокета
    _sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (_sockfd == -1) {
        throw runtime_error("Ошибка при создании сокета");
    }

    // Связываем дискриптор сокета
    int result = bind(_sockfd, (struct sockaddr*) &address, sizeof(address));
    if (result == -1) {
        cout << "ERROR!" << endl;
        cout << "IP: " << *inet_ntoa(address.sin_addr) << endl;
        cout << "Port: " << ntohs(address.sin_port) << endl;
        throw runtime_error("Ошибка при связывании сокета");
    }

    // Устанавливаем неблокирующий флаг сокету
    int flags = fcntl(_sockfd, F_GETFL);
    flags |= O_NONBLOCK;
    fcntl(_sockfd, F_SETFL, flags);

    // Копируем адрес сокета
    memcpy(&_address, &address, sizeof(address));
}

void Socket::send(const struct sockaddr_in *addr, const char *buf, int buf_size) {
    sendto(_sockfd, buf, (size_t) buf_size, 0, (struct sockaddr*) addr, sizeof(*addr));
}

int Socket::read(char *buf, struct sockaddr_in* addr, unsigned int *addr_len) {
    int recv_len = (int) recvfrom(_sockfd, buf, BUFLEN, 0, (struct sockaddr*) addr, addr_len);
    return recv_len;
}

Socket::~Socket() {
    close(_sockfd);
}