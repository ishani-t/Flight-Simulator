#include "../catch/catch.hpp"
#include <vector>
#include <string>
#include "../src/Dijkstra.h"
#include "../src/Parser.h"

TEST_CASE("Test shortest path") {
    Parser airport_parser("./tests/airports_test.dat");
    std::vector<std::vector<string>> airports = airport_parser.getData();

    Parser route_parser("./tests/routes_test.dat");
    std::vector<std::vector<string>> routes = route_parser.getData();
    Flights flights(airports, routes);

    Dijkstra d;
    d.solveDijkstra(flights,"CLE","CVG");
    vector<string> path = d.findShortestPath();
    REQUIRE(path.size() == 2);
    REQUIRE(path[0] == "CLE");
    REQUIRE(path[1] == "CVG");
}