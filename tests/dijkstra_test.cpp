#include "../catch/catch.hpp"
#include <vector>
#include <string>
#include "../src/Dijkstra.h"
#include "../src/Parser.h"

TEST_CASE("Test dijkstra shortest path") {
    Parser airport_parser("./tests/airports_test.dat");
    std::vector<std::vector<string>> airports = airport_parser.getData();

    Parser route_parser("./tests/routes_test.dat");
    std::vector<std::vector<string>> routes = route_parser.getData();
    Flights flights(airports, routes);

    Dijkstra d;

    SECTION("Find shortest path with direct flight") {
        d.solveDijkstra(flights,"CLE","CVG");
        vector<string> path = d.findShortestPath();
        REQUIRE(path.size() == 2);
        REQUIRE(path[0] == "CLE");
        REQUIRE(path[1] == "CVG");
    }

    SECTION("Find path with one stop") {
        d.solveDijkstra(flights,"CLE","ORD");
        vector<string> path = d.findShortestPath();
        REQUIRE(path.size() == 3);
        REQUIRE(path[0] == "CLE");
        REQUIRE(path[1] == "LAX");
        REQUIRE(path[2] == "ORD");
    }

    SECTION("Find path with multiple stops") {
        d.solveDijkstra(flights,"CLE","AZO");
        vector<string> path = d.findShortestPath();
        REQUIRE(path.size() == 4);
        REQUIRE(path[0] == "CLE");
        REQUIRE(path[1] == "LAX");
        REQUIRE(path[2] == "ORD");
        REQUIRE(path[3] == "AZO");
    }
    
    SECTION("Check when there is no path") {
        d.solveDijkstra(flights,"LAX","CVG");
        vector<string> path = d.findShortestPath();
        REQUIRE(path.size() == 0);
    }
}