#include "../catch/catch.hpp"
#include "../src/Parser.h"
#include <string>
#include <vector>

TEST_CASE("Parsing sample airports data file") {
    Parser airport_parser("./tests/airports_test.dat");
    std::vector<std::vector<string>> airports = airport_parser.getData();

    SECTION("Size of parsed vector is accurate") {
        REQUIRE(airports.size() == 5);

        for (size_t i = 0; i < 5; i++) {
            REQUIRE(airports[i].size() == 14);
        }
    }

    SECTION("Check first line values are accurate") {
        REQUIRE(airports[0][0] == "1");
        REQUIRE(airports[0][1] == "Los Angeles International Airport");
        REQUIRE(airports[0][4] == "LAX");
        REQUIRE(airports[0][6] == "33.94250107");
        REQUIRE(airports[0][7] == "-118.4079971");
        REQUIRE(airports[0][8] == "125");
    }

    SECTION("Check last line values are accurate") {
        REQUIRE(airports[4][0] == "5");
        REQUIRE(airports[4][1] == "Cincinnati Northern Kentucky International Airport");
        REQUIRE(airports[4][4] == "CVG");
        REQUIRE(airports[4][6] == "39.0488014221");
        REQUIRE(airports[4][7] == "-84.6678009033");
        REQUIRE(airports[4][8] == "896");
    }

}

TEST_CASE("Parsing sample routes data file") {
    Parser route_parser("./tests/routes_test.dat");
    std::vector<std::vector<string>> routes = route_parser.getData();
    
    SECTION("Size of parsed vector is accurate") {
        REQUIRE(routes.size() == 5);

        for (size_t i = 0; i < 5; i++) {
            REQUIRE(routes[i].size() == 9);
        }  
    }

    SECTION("Check first line values are accurate") {
        std::vector<string> first{"2G","1654","UKX","6924","IKT","2937","","0","AN4"};
        REQUIRE(routes[0] == first);
    }
}