#include "Dijkstra.h"

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

/*
  initialize distances  // initialize tentative distance value
  initialize previous   // initialize a map that maps current node -> its previous node
  initialize priority_queue   // initialize the priority queue
  initialize visited

  while the top of priority_queue is not destination:
      get the current_node from priority_queue
      for neighbor in current_node's neighbors and not in visited:
          if update its neighbor's distances:
              previous[neighbor] = current_node
      save current_node into visited

  extract path from previous
  return path and distance
  */

void Dijkstra::solveDijkstra() {
    
}