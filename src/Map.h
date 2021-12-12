#pragma once

#include "Edge.h"
#include "Node.h"
#include "../cs225/PNG.h"
#include "Dijkstra.h"

#include <vector>
#include <string>

using std::string;
using std::vector;

class Map
{

public:
    // Constructor will accept the vector of all airports in the map
    //Map(vector<Node> airports);
    Map(Flights graph, string start, string destination, string inputImagePath, string outputImagePath);

    // getCoordinates will go through the vector of airports and return the latitude and longitude of a specific
    std::pair<double, double> getCoordinates(string code);

    // given the latitude and longitude coordinates of an airport, getImagePixels will find the corresponding location on our image
    std::pair<int, int> getImagePixels(std::pair<double, double> coordinates);

    /**
     * Draws flight path onto a PNG image
     * path: vector of strings containing the code of the airports visited in order
     * inputImagePath: path to the map PNG we will draw onto
     * outputImagePath: where the image will be saved to
     */
    //void drawFlight(vector<string> path, string inputImagePath, string outputImagePath);
    void drawFlight(vector<string> path);

private:
    std::vector<Node> airports_;

    // helper function: will draw a line onto the map (will call this for each pair of airports being travelled between)
    //void drawLine(string a1, string a2, string inputImagePath, string ouputImagePath);
    void drawLine(string a1, string a2);
    cs225::PNG blank_map_;
    int width_;
    int height_;
};