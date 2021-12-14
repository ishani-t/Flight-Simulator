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
    Parser airportParser("./data/airports.dat.txt");

    Parser routeParser("./data/routes.dat.txt");

    Flights Flights_1(airportParser.getData(), routeParser.getData());

    vector<Node> airports = Flights_1.getAirports();

    Dijkstra d;
    d.solveDijkstra(Flights_1, "CMI", "MNL");
    std::cout << "This is the path from Willard Airport (CMI) to Ninoy Aquino International Airport (MNL)\n";
    vector<string> path = d.findShortestPath();
    for (unsigned long i = 0; i < path.size(); i++) {
        std::cout<<"Airport " << i << " is: " << path[i] << std::endl;
    }
    std::cout << "You can view the flight path in output.png \n";
    Map Map_1(path, "map_grid.png", "Output.png", airports);
}