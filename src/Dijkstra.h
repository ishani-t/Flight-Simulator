#pragma once
#include "Flights.h"
#include "Edge.h"
#include "Node.h"

#include <utility>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

class Dijkstra {
    public:
        /**
         * Finds shortest path between given airports from given start and destination airpot codes.
         * https://courses.engr.illinois.edu/cs225/fa2021/resources/dijkstra/
         */
        void solveDijkstra(Flights graph, string start, string destination);
        
        //Finds and returns shortest path from input start and ending airports
        vector<string> findShortestPath();

    private:
        //Returns node matching given airport code
        Node findNode(vector<Node> nodes, string code);

        //Returns edge weight if edge exists between given start and end node
        double findEdgeWeight(vector<Edge> edges, Node start, Node end);

        Node start_airport_;
        Node dest_airport_;

        //maps current node to previous node
        std::unordered_map<string,string> previous_;

        //total distance values from starting node
        std::unordered_map<string, double> distances_; 

        //all nodes that have been visited
        std::unordered_map<string,bool> visited_; 

        //finds the next closest unvisited node
        priority_queue< pair<double,string>, vector<pair<double,string> >, greater< pair<double,string>> > pq_;
        vector<string> shortest_path;
};