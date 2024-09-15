#include <gtest/gtest.h>
#include <fstream>
#include <thread>
#include "Types.h"
#include "RadioStation.h"

namespace snowcast {

std::string makeMockFile(const std::string &contents)
{
    std::string fileName = std::to_string(std::chrono::system_clock::now().time_since_epoch().count());
    std::string dirName = testing::TempDir();
    std::string fullFile = dirName + "/" + fileName;
    std::ofstream writer{fullFile};
    writer << contents;
    return fullFile;
}

TEST(RadioStationTest, BasicFunctionality)
{
    using namespace std::chrono;

    std::string fileContents = "1234";
    std::string fileName = makeMockFile(fileContents);
    station_id_t mockStation{};
    std::unordered_map<station_id_t, std::string> mockStations = 
    {
        {mockStation, fileName} 
    };

    static constexpr DurationT tickLength = 1ns;
    RadioStation r{mockStations, system_clock::now(), tickLength, static_cast<size_t>(1e8)};

    std::this_thread::sleep_for(5ms);

    r.switchStation(mockStation);
    EXPECT_EQ(fileName, r.currSong());
    EXPECT_TRUE(r.active());

    std::string expectedOut = fileContents + fileContents + fileContents;
    char s[12];

    size_t loops = r.readAndCountLoops(s, 12);
    EXPECT_EQ(loops, 3);
    EXPECT_STREQ(s, expectedOut.c_str());
}

}