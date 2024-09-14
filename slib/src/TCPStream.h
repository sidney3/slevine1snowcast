#include <sys/types.h>
#include <netdb.h>
#include <cstddef>

/*
    RAII representation of a TCP connection
*/
namespace slib {
class TCPStream
{
public:
    TCPStream(int socketFd);
    size_t read(std::byte *out, size_t readSize);
    size_t write(const std::byte *out, size_t writeSize);
    void disconnect();
};
}