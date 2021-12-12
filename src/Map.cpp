#include "Map.h"
#include <stdlib.h>
#include <cmath>

Map::Map(vector<Node> airports)
{
    airports_ = airports;
}

std::pair<double, double> Map::getCoordinates(string code)
{
    for (size_t i = 0; i < airports_.size(); i++)
    {
        if (airports_[i].getCode() == code)
        {
            return std::make_pair(airports_[i].getLat(), airports_[i].getLong());
        }
    }
}

std::pair<int, int> Map::getImagePixels(std::pair<double, double> coordinates)
{
    return std::make_pair(0, 0);
}

void Map::drawFlight(vector<string> path, string inputImagePath, string outputImagePath)
{
}

void Map::drawLine(string a1, string a2, string inputImagePath, string ouputImagePath)
{
}