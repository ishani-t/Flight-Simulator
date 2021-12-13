#include "Dijkstra.h"
#include <cmath>


void Dijkstra::solveDijkstra(Flights graph, string start, string destination) {
    vector<Node> nodes = graph.getAirports();
    for (size_t i = 0; i < graph.getAirports().size(); i++) {
        if (nodes[i].getCode() == destination) {
            dest_airport_ = nodes[i];
        }
        if (nodes[i].getCode() == start) {
            start_airport_ = nodes[i];
            distances_.insert(make_pair(nodes[i].getCode(),0.0));

        } else {
            distances_.insert(std::pair<string,double>(nodes[i].getCode(), INFINITY));
        }

        previous_.insert(make_pair(nodes[i].getCode(),""));
        visited_.insert(make_pair(nodes[i].getCode(),false));
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

vector<string> Dijkstra::findShortestPath() {
    string dest_name = dest_airport_.getCode();
    string start_name = start_airport_.getCode();
    
    
    shortest_path.push_back(dest_name);
    while(dest_name != start_name) {
        //Checks and returns empty vector if there is no path
        if (shortest_path.back() == previous_[dest_name]) {
            return vector<string>();
        }
        shortest_path.push_back(previous_[dest_name]);
        dest_name = previous_[dest_name];
    }

    std::reverse(shortest_path.begin(), shortest_path.end());
    return shortest_path;
}

Node Dijkstra::findNode(vector<Node> airports, string code) {

    for (size_t i = 0; i < airports.size(); i++) {
        if (airports[i].getCode() == code) {
            return airports[i];
        }
    }
    return airports[0];
}

double Dijkstra::findEdgeWeight(vector<Edge> edges, Node start, Node end) {
    
    for (size_t i = 0; i < edges.size(); i++) {
        if (edges[i].getStart().getCode() == start.getCode() && edges[i].getEnd().getCode() == end.getCode()) {
            return edges[i].getWeight();
        }
    } 
    return INFINITY;
}