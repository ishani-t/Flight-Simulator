#include "Map.h"
#include <stdlib.h>
#include <cmath>

Map::Map(vector<Node> airports) {
    
}

std::pair<double, double> Map::getCoordinates(string code) {
    for (size_t i = 0; i < airports.size(); i++) {
        if (airports[i].getCode() == code) {
            return airports[i];
        }
    }
}

std::pair<int, int> Map::getImagePixels(std::pair<double, double> coordinates) {

}

void Map::drawFlight(vector<string> path, string inputImagePath, string outputImagePath) {

}

void Map::drawLine(string a1, string a2, string inputImagePath, string ouputImagePath) {

}