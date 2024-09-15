#pragma once
#include <sys/types.h>
#include <netdb.h>
#include <cstddef>
#include <memory>

namespace slib {

class UDPStream
{
private:
    int m_socketFd;
    std::unique_ptr<sockaddr> m_sendAddr;
    socklen_t m_sockLen;
public:
    UDPStream(int socketFd, std::unique_ptr<sockaddr> sendAddr, socklen_t sockLen);
    size_t read(char *out, size_t readSize);
    size_t write(const char *out, size_t writeSize);
    void disconnect();
};

}