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
    //std::cout << "parsed airports\n";

    Parser Parser_2("./data/routes.dat.txt");
    //std::cout << "parsed routes\n";

    Flights Flights_1(Parser_1.getData(), Parser_2.getData());
    std::cout << "created flights data structures\n";

    vector<Node> airports = Flights_1.getAirports();

    // vector<string> path = {"ORD", "LHR"};
    Dijkstra d;
    d.solveDijkstra(Flights_1, "CMI", "MNL");
    std::cout << "This is the path from Willard Airport to Ninoy Aquino International Airport\n";
    vector<string> path = d.findShortestPath();
    for (unsigned long i = 0; i < path.size(); i++) {
        std::cout<<"Airport " << i << " is: " << path[i] << std::endl;
    }

    Map Map_1(path, "map_grid.png", "Output.png", airports);
}