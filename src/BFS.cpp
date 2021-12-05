#include "BFS.h"
#include <algorithm>


std::vector<Node> traversal(Flights & flights, Node & start) {
    std::queue<Node> queue;
    queue.push(start);
    std::vector<Node> reachableAirports;
    std::vector<Node> airports = flights.getAirports();
    std::vector<bool> visited;
    auto sourceIterator = find(airports.begin(), airports.end(), start);
    int sourceIndex = distance(airports.begin(), sourceIterator);
    for (unsigned long i = 0; i < flights.getAirports().size(); i++) {
        visited[i] = false;
    }
    visited[sourceIndex] = true;


    while(queue.empty() == false) {
        Node cur = queue.front();
        reachableAirports.push_back(cur);
        queue.pop();
        std::vector<Node> adjacent = flights.getAdjacentNodes(cur);

        for (unsigned int i = 0; i < adjacent.size(); i++) {
            auto curIterator = find(airports.begin(), airports.end(), adjacent[i]);
            int curPosition = distance(airports.begin(), curIterator);

            if (!visited[curPosition]) {
                visited[curPosition] = true;
                queue.push(adjacent[i]);
            }
        }
    }
    return reachableAirports;
} 