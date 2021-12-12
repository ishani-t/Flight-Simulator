#include "Map.h"
#include <stdlib.h>
#include <cmath>

//Map::Map(vector<Node> airports)
Map::Map(Flights graph, string start, string destination, string inputImagePath, string outputImagePath)
{
    blank_map_.readFromFile(inputImagePath);
    height_ = blank_map_.height();
    width_ = blank_map_.width();
    Dijkstra d;
    d.solveDijkstra(graph, start, destination);
    vector<string> path = d.findShortestPath();
    drawFlight(path);
    blank_map_.writeToFile(outputImagePath);
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
    //NOTE: this might be very wrong my geography and math knowledge are both low :(
    //also this is really based on the assumption that the equator and prime meridian are in the middle i think
    //latitude
    int equator = height_ / 2;
    int lat_scale = height_ / 180;
    int x_coord = equator * lat_scale + coordinates.first * lat_scale;
    //longitude
    int prime_meridian = width_ / 2;
    int long_scale = height_ / 360;
    int y_coord = prime_meridian * long_scale + coordinates.second * long_scale;
    return std::make_pair(x_coord, y_coord);
}

//void Map::drawFlight(vector<string> path, string inputImagePath, string outputImagePath)
void Map::drawFlight(vector<string> path)
{
    for (unsigned long i = 0; i < path.size() - 1; i++)
    {
        drawLine(path[i], path[i + 1]);
    }
}

//void Map::drawLine(string a1, string a2, string inputImagePath, string ouputImagePath)
void Map::drawLine(string a1, string a2)
{
    std::pair<int, int> coord_1 = getCoordinates(a1);
    std::pair<int, int> pixels_1 = getImagePixels(coord_1);
    std::pair<int, int> coord_2 = getCoordinates(a2);
    std::pair<int, int> pixels_2 = getImagePixels(coord_2);

    //x2 is greater than x1 for for loop purposes lol
    int x1, x2, y1, y2;
    if (pixels_1.first - pixels_2.first >= 0)
    {
        x1 = pixels_2.first;
        x2 = pixels_1.first;
        y1 = pixels_2.second;
        y2 = pixels_1.second;
    }
    else
    {
        x2 = pixels_2.first;
        x1 = pixels_1.first;
        y2 = pixels_2.second;
        y1 = pixels_1.second;
    }

    int slope = (y2 - y1) / (x2 - x1);
    int b = y1 - slope * x1;

    for (int x = x1; x < x2; x++)
    {
        int y = slope * x + b;
        cs225::HSLAPixel pixel = blank_map_.getPixel(x, y);
        pixel.h = 50;
    }
}