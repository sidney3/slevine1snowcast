#include "UDPStream.h"

namespace slib {
UDPStream::UDPStream(int socketFd, std::unique_ptr<sockaddr> sendAddr,
                     socklen_t sockLen)
    : m_socketFd(socketFd), m_sendAddr(std::move(sendAddr)),
      m_sockLen(sockLen) {}

} // namespace slib