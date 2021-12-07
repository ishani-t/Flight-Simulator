#include "../catch/catch.hpp"
#include "../src/Node.h"
#include "../src/Edge.h"
#include "../src/Flights.h"
#include "../src/Parser.h"
#include <string>
#include <vector>

TEST_CASE("Check node initialization") {
    Node n = Node("Undergraduate Library", "UGL", 40.1048, -88.2266,10);
    REQUIRE(n.getCode() == "UGL");
    REQUIRE(n.getLat() == 40.1048);
    REQUIRE(n.getLong() == -88.2266);
}

TEST_CASE("Check edge initialization") {
    Node n1 = Node("Undergraduate Library", "UGL", 40.1048, -88.2266,10);
    Node n2 = Node("Grainger Engineering Library", "GEL", 40.1123, -88.2264,15);
    Edge e = Edge(n1,n2, 4.2);
    REQUIRE(e.getStart() == n1);
    REQUIRE(e.getEnd() == n2);
}

TEST_CASE("Check sample flights vectors of nodes and edges are accurate") {
    Parser airport_parser("./tests/airports_test.dat");
    std::vector<std::vector<string>> airports = airport_parser.getData();

    Parser route_parser("./tests/routes_test.dat");
    std::vector<std::vector<string>> routes = route_parser.getData();
    Flights flights(airports, routes);

    SECTION("Test vector of airport nodes") {
        std::vector<Node> nodes = flights.getAirports();
        REQUIRE(nodes.size() == 5);
        REQUIRE(nodes[0] == Node("Los Angeles International Airport","LAX",33.94250107,-118.4079971,125));
        REQUIRE(nodes[2] == Node("Cleveland Hopkins International Airport","CLE",41.4117012024,-81.8498001099,791));
        REQUIRE(nodes[4] == Node("Cincinnati Northern Kentucky International Airport","CVG",39.0488014221,-84.6678009033,896));
    }

    SECTION("Test vector of route edges") {
        std::vector<Edge> edges = flights.getPaths();
        REQUIRE(edges.size() == 5);
        REQUIRE(edges[0].getStart().getCode() == "ORD");
        REQUIRE(edges[0].getEnd().getCode() == "AZO");
    }

    //Fix test file and add more test cases for edges
}