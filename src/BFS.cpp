#include "BFS.h"
#include <algorithm>

std::vector<Node> BFS::traversal(Flights flights, Node start) {
    queue.push(start);

    airports = flights.getAirports();
    //finding the index of the start airport
    std::vector<Node>::iterator first = airports.begin(); 
    std::vector<Node>::iterator startAirport = find(first, airports.end(), start);
    int current = 0;
    while (first != startAirport) {
        current++;
        first++;
    }
    int startIndex = current;

    //setting each airport to unvisited 
    unsigned long counter = 0;  
    while (counter < flights.getAirports().size()) {
        visited.push_back(false);
        counter++;
    }
    visited[startIndex] = true;

    while(queue.empty() == false) {
        Node cur = queue.front();
        reachableAirports.push_back(cur);
        //getting reachable airports
        std::vector<Node> adjacent = flights.getAdjacentNodes(cur);
        //setting reachable airports to visited
        for (unsigned int i = 0; i < adjacent.size(); i++) {
            std::vector<Node>::iterator first = airports.begin();
            std::vector<Node>::iterator curIterator = find(first, airports.end(), adjacent[i]);
            int current = 0;
            while (first != curIterator) {
                current++;
                first++;
            }
            int curPosition = current;

            if (visited[curPosition] == false) {
                queue.push(adjacent[i]);
                visited[curPosition] = true;
            }
        }
        queue.pop();
    }
    return reachableAirports;
} 