#include "./src/Parser.h"
#include "./src/Flights.h"
#include "./src/Map.h"
#include "./src/Dijkstra.h"


#include <vector>
#include <string>

using std::string;
using std::vector;

#include <iostream>

int main()
{
    Parser Parser_1("./data/airports.dat.txt");
    std::cout << "parsed airports\n";

    Parser Parser_2("./data/routes.dat.txt");
    std::cout << "parsed routes\n";

    Flights Flights_1(Parser_1.getData(), Parser_2.getData());
    std::cout << "created flights data structures\n";

    vector<Node> airports = Flights_1.getAirports();

    // vector<string> path = {"ORD", "LHR"};
    Dijkstra d;
    d.solveDijkstra(Flights_1, "ORD", "LHR");
    std::cout << "solved dijkstra";
    vector<string> path = d.findShortestPath();

    Map Map_1(path, "map_grid.png", "Output.png", airports);
}