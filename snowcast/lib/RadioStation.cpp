#include "RadioStation.h"
#include <stdexcept>
#include <cassert>
#include <iostream>

namespace snowcast {

RadioStation::RadioStation(const std::unordered_map<station_id_t, std::string> &stationFiles, TimepointT startTime, DurationT tickDuration, size_t bytesPerTick)
    : m_stationFiles{stationFiles}, m_startTime{startTime}, m_tickDuration{tickDuration}, m_bytesPerTick{bytesPerTick}
{}

size_t RadioStation::currByteCount() const
{
    const auto ticksExecuted = ((std::chrono::system_clock::now() - m_startTime) / m_tickDuration);
    return ticksExecuted * m_bytesPerTick;
}

bool RadioStation::active() const
{
    return activeSong.has_value();
}

const std::string &RadioStation::currSong() const
{
    return activeSongName;
}

bool RadioStation::switchStation(station_id_t newStation)
{
    auto &allStations = m_stationFiles.get();
    if(!allStations.contains(newStation))
    {
        return false;
    }

    activeSongName = allStations.at(newStation);
    activeSong = std::ifstream{activeSongName};

    if(activeSong->eof())
    {
        throw std::runtime_error{"Radio cannot be an empty file"};
    }
    return true;
}

size_t RadioStation::readAndCountLoops(char *out, size_t toRead)
{
    if(!activeSong.has_value())
    {
        return 0;
    }

    std::ifstream &radio = *activeSong;
    size_t loops = 0;
    size_t numRead = 0;

    while(numRead < toRead)
    {
        loops += radio.tellg() == 0;
        radio.read(&out[numRead], toRead - numRead);
        numRead += radio.gcount();
        if(radio.eof())
        {
            radio.clear();
            radio.seekg(0);
        }
    }

    return loops;
}
}