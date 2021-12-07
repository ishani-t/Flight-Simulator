#include "Dijkstra.h"
#include <cmath>

void Dijkstra::solveDijkstra(Flights graph, string start, string destination) {
    nodes_ = graph.getAirports();
    for (size_t i = 0; i < graph.getAirports().size(); i++) {
        if (nodes_[i].getCode() == destination) {
            dest_airport_ = nodes_[i];
        }
        if (nodes_[i].getCode() == start) {
            start_airport_ = nodes_[i];
            distances_.insert(make_pair(nodes_[i].getCode(),0.0));

        } else {
            distances_.insert(std::pair<string,double>(nodes_[i].getCode(), INFINITY));
        }

        previous_.insert(make_pair(nodes_[i].getCode(),""));
        visited_.insert(make_pair(nodes_[i].getCode(),false));
    }
    
    pair<double,string> start_node = make_pair(0,start);
    pq_.push(start_node);


    while (!pq_.empty()) {
        pair<double,string> current_node = pq_.top();
        
        pq_.pop();
        vector<Node> neighbors = graph.getAdjacentNodes(findNode(graph.getAirports(),current_node.second));
        for (size_t i = 0; i < neighbors.size(); i++) {
            string neighbor_name = neighbors[i].getCode();
            string current_name = current_node.second;

            if (!visited_[current_name] && !visited_[neighbor_name]) {
                vector<Node> n = graph.getAirports();
                double weight = findEdgeWeight(graph.getPaths(), findNode(n,current_name), neighbors[i]);
                
                if (distances_[neighbor_name] > distances_[current_name] + weight) {
                    distances_[neighbor_name] = distances_[current_name] + weight;
                    previous_[neighbor_name] = current_name;
                    pq_.push(make_pair(distances_[neighbor_name],neighbor_name));
                }
            }
        }
        visited_[current_node.second] = true;
    }
}

Node Dijkstra::findNode(vector<Node> airports, string code) {

    for (size_t i = 0; i < airports.size(); i++) {
        if (airports[i].getCode() == code) {
            return airports[i];
        }
    }
    return airports[0];
}

vector<string> Dijkstra::findShortestPath() {
    string dest_name = dest_airport_.getCode();
    string start_name = start_airport_.getCode();
    
    
    shortest_path.push_back(dest_name);
    while(dest_name != start_name) {
        shortest_path.push_back(previous_[dest_name]);
        dest_name = previous_[dest_name];
    }

    std::reverse(shortest_path.begin(), shortest_path.end());
    return shortest_path;
}

double Dijkstra::findEdgeWeight(vector<Edge> edges, Node start, Node end) {
    
    for (size_t i = 0; i < edges.size(); i++) {
        if (edges[i].getStart().getCode() == start.getCode() && edges[i].getEnd().getCode() == end.getCode()) {
            return edges[i].getWeight();
        }
    } 
    return INFINITY;
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