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

//https://courses.engr.illinois.edu/cs225/fa2021/resources/dijkstra/

class Dijkstra {
    public:
        void solveDijkstra(Flights graph, string start, string destination);
        vector<string> findShortestPath();

    private:
        Node findNode(vector<Node> nodes, string code);
        double findEdgeWeight(vector<Edge> edges, Node start, Node end);

        //Flights graph_;
        Node start_airport_;
        Node dest_airport_;
        
        vector<Node> nodes_;

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