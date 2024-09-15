#pragma once
#include "Types.h"
#include <fstream>
#include <functional>
#include <optional>
#include <string>
#include <unordered_map>

namespace snowcast {

class RadioStation {
private:
  std::reference_wrapper<const std::unordered_map<station_id_t, std::string>>
      m_stationFiles;
  TimepointT m_startTime;
  DurationT m_tickDuration;
  size_t m_bytesPerTick;

private:
  std::optional<std::ifstream> activeSong{};
  std::string activeSongName{};

private:
  size_t currByteCount() const;

public:
  RadioStation(
      const std::unordered_map<station_id_t, std::string> &stationFiles,
      TimepointT startTime, DurationT tickDuration, size_t bytesPerTick);
  bool active() const;
  const std::string &currSong() const;
  bool switchStation(station_id_t newStation);
  size_t readAndCountLoops(char *out, size_t toRead);
};

} // namespace snowcast