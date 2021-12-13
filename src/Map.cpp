#include "Map.h"
#include <stdlib.h>
#include <cmath>
#include <iostream>

//Map::Map(vector<Node> airports)
Map::Map(vector<string> path, string inputImagePath, string outputImagePath, vector<Node> airports)
{
    airports_ = airports;

    blank_map_.readFromFile(inputImagePath);
    height_ = blank_map_.height();
    width_ = blank_map_.width();

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
    return std::make_pair(0.0, 0.0);
}

std::pair<int, int> Map::getImagePixels(std::pair<double, double> coordinates)
{
    //latitude
    float equator = 200;
    float x_coord = equator - coordinates.first * 315/180;
    
    //longitude
    float prime_meridian = 370;
    float y_coord = prime_meridian + coordinates.second * 630/360;

    // converting floats to ints
    int x_val = static_cast<int>(x_coord);
    int y_val = static_cast<int>(y_coord);

    return std::make_pair(y_val, x_val);
}

void Map::drawFlight(vector<string> path)
{
    for (unsigned long i = 0; i < path.size() - 1; i++)
    {
        drawLine(path[i], path[i + 1]);
    }
}

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
        cs225::HSLAPixel &pixel = blank_map_.getPixel(x, y);
        pixel.h = 0;
        pixel.s = 1;
        pixel.l = 0.50;
        pixel.a = 1.0;
    }    
}