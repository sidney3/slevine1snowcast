#pragma once
#include "Types.h"
#include "jthread.h"
#include <unordered_map>

namespace snowcast {

template <typename TD> class ClientConnection {
private:
  using UDPStreamT = typename TD::UDPStreamT;
  using TCPStreamT = typename TD::TCPStreamT;
  using RadioStationT = typename TD::RadioStationT;

private:
  UDPStreamT m_clientUDPConn;
  TCPStreamT m_clientTCPConn;
  RadioStationT m_radioStation;

public:
  ClientConnection(UDPStreamT &&UDPConn, TCPStreamT &&TCPConn,
                   RadioStationT radioStation) {}
  static ClientConnection make(TCPStreamT &&clientConn,
                               RadioStationT radioStation) {}
};

} // namespace snowcast