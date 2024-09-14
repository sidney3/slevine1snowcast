#include <sys/types.h>
#include <netdb.h>
#include <cstddef>

namespace slib {

class UDPStream
{
public:
    UDPStream(int socketFd, sockaddr *sendAddr, socklen_t sockLen);
    size_t read(std::byte *out, size_t readSize);
    size_t write(const std::byte *out, size_t writeSize);
    void disconnect();
};

}