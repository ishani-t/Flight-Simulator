#include "Dijkstra.h"
/*
Dijkstra::Dijkstra(Flights graph, string start, string destination) {
    graph_ = graph;
    nodes_ = graph_.getAirports();
    visited_ = vector<bool>(nodes_.size(), false);
    for (size_t i = 0; i < graph_.getAirports().size(); i++) {
        if (nodes_[i].getCode() == start) {
            start_airport_ = nodes_[i];

        } else if (nodes_[i].getCode() == destination) {
            dest_airport_ = nodes_[i];
        }    
        distances_.insert(std::pair<string,double>(nodes_[i].getCode(), INT_MAX));
    }
}

void Dijkstra::solveDijkstra() {
    std::queue<Node> not_visited_nodes;
    Node source = start_airport_;
    distances_[source.getCode()] = 0;
    not_visited_nodes.push(source);

    while (!not_visited_nodes.empty()) {
        
        not_visited_nodes.pop_front();  
        source = not_visited_nodes.front();
        for (Node neighbor : graph_.getAdjacentNodes(source)) {
            //alt = dist[source] + length(sourve, neighbor)
            //if alt < dist[neighbor] then dist[neigh] = alt
        } 
    }
}*/