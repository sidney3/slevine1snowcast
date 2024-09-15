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
    size_t read(char *out, size_t readSize);
    size_t write(const char* out, size_t writeSize);
    void disconnect();
};
}