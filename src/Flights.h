#pragma once

#include "Edge.h"
#include "Node.h"

#include <vector>
#include <string>

using std::string;
using std::vector;

class Flights
{

public:
    Flights(vector<vector<string>> a, vector<vector<string>> p);
    void createAirports(vector<vector<string>> data);
    void createPaths(vector<vector<string>> data);
    vector<Node> getAdjacentNodes(Node airport);
    
private:
    std::vector<Node> airports_;
    std::vector<Edge> paths_;
};