#pragma once

#include "Edge.h"
#include "Node.h"

#include <vector>
#include <string>

using std::string;

class Flights {

public:
    Flights(std::vector<std::vector<std::string>> a, std::vector<std::vector<std::string>> p);
    void createAirports(std::vector<std::vector<std::string>> data);
    void createPaths(std::vector<std::vector<std::string>> data);
    

private:
    std::vector<Node> airports_;
    std::vector<Edge> paths_;
};