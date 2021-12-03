#pragma once
#include "Flights.h"
#include "Edge.h"
#include "Node.h"

#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <queue>

using std::vector;

class Dijkstra {
    public:
        Dijkstra(Flights graph, string start, string destination);
        void solveDijkstra();

    private:
        Flights graph_;
        Node start_airport_;
        Node dest_airport_;
        
        vector<Node> nodes_;
        std::unordered_map<string,string> previous_; //maps current node to previous node
        std::unordered_map<string, double> distances_;
        vector<bool> visited_;
        std::priority_queue<int, vector<int>, greater<int> > q;

}