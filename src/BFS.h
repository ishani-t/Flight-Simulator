#pragma once
#include <string>
#include <vector>
#include <queue>
#include "Flights.h"
#include "Node.h"
#include "Edge.h"

using namespace std;

class BFS {
    public: 
        std::vector<Node> traversal(Flights flights, Node start);
    private:
        std::queue<Node> queue;
        std::vector<Node> reachableAirports;
        std::vector<Node> airports;
        std::vector<bool> visited;
};