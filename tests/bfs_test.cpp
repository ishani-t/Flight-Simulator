#include "../catch/catch.hpp"
#include "../src/BFS.h"
#include <vector>
#include <string>

using std::string;
using std::vector;

TEST_CASE("Linear Test")
{
    vector<vector<string>> airports;
    vector<string> ap1{"", "Airport 1", "", "", "ap1", " ", "1", "1", "1", "", "", "", ""};
    vector<string> ap2{"", "Airport 2", "", "", "ap2", " ", "2", "2", "2", "", "", "", ""};
    vector<string> ap3{"", "Airport 3", "", "", "ap3", " ", "3", "3", "3", "", "", "", ""};
    vector<string> ap4{"", "Airport 4", "", "", "ap4", " ", "4", "4", "4", "", "", "", ""};
    vector<string> ap5{"", "Airport 5", "", "", "ap5", " ", "5", "5", "5", "", "", "", ""};
    airports.push_back(ap1);
    airports.push_back(ap2);
    airports.push_back(ap3);
    airports.push_back(ap4);
    airports.push_back(ap5);

    vector<vector<string>> paths;
    //2B,410,AER,2965,KZN,2990,,0,CR2
    vector<string> p1{"", "", "ap1", "", "ap2", "", "", "", ""};
    vector<string> p2{"", "", "ap2", "", "ap3", "", "", "", ""};
    vector<string> p3{"", "", "ap3", "", "ap4", "", "", "", ""};
    vector<string> p4{"", "", "ap4", "", "ap5", "", "", "", ""};
    paths.push_back(p1);
    paths.push_back(p2);
    paths.push_back(p3);
    paths.push_back(p4);

    Flights f(airports, paths);

    BFS bfs;
    vector<Node> bfs_traversal = bfs.traversal(f, f.getAirports()[0]);
    REQUIRE(bfs_traversal.size() == 5);
    REQUIRE(bfs_traversal[0] == f.getAirports()[0]);
    REQUIRE(bfs_traversal[1] == f.getAirports()[1]);
    REQUIRE(bfs_traversal[2] == f.getAirports()[2]);
    REQUIRE(bfs_traversal[3] == f.getAirports()[3]);
    REQUIRE(bfs_traversal[4] == f.getAirports()[4]);
}

TEST_CASE("Non-linear Test")
{
    vector<vector<string>> airports;
    vector<string> ap1{"", "Airport 1", "", "", "ap1", " ", "1", "1", "1", "", "", "", ""};
    vector<string> ap2{"", "Airport 2", "", "", "ap2", " ", "2", "2", "2", "", "", "", ""};
    vector<string> ap3{"", "Airport 3", "", "", "ap3", " ", "3", "3", "3", "", "", "", ""};
    vector<string> ap4{"", "Airport 4", "", "", "ap4", " ", "4", "4", "4", "", "", "", ""};
    vector<string> ap5{"", "Airport 5", "", "", "ap5", " ", "5", "5", "5", "", "", "", ""};
    airports.push_back(ap1);
    airports.push_back(ap2);
    airports.push_back(ap3);
    airports.push_back(ap4);
    airports.push_back(ap5);

    vector<vector<string>> paths;
    //2B,410,AER,2965,KZN,2990,,0,CR2
    vector<string> p1{"", "", "ap1", "", "ap2", "", "", "", ""};
    vector<string> p2{"", "", "ap1", "", "ap3", "", "", "", ""};
    vector<string> p3{"", "", "ap2", "", "ap4", "", "", "", ""};
    vector<string> p4{"", "", "ap2", "", "ap5", "", "", "", ""};
    paths.push_back(p1);
    paths.push_back(p2);
    paths.push_back(p3);
    paths.push_back(p4);

    Flights f(airports, paths);

    BFS bfs;
    vector<Node> bfs_traversal = bfs.traversal(f, f.getAirports()[0]);
    REQUIRE(bfs_traversal.size() == 5);
    REQUIRE(bfs_traversal[0] == f.getAirports()[0]);
    REQUIRE(bfs_traversal[1] == f.getAirports()[1]);
    REQUIRE(bfs_traversal[2] == f.getAirports()[2]);
    REQUIRE(bfs_traversal[3] == f.getAirports()[3]);
    REQUIRE(bfs_traversal[4] == f.getAirports()[4]);
}

TEST_CASE("Not connected node")
{
    vector<vector<string>> airports;
    vector<string> ap1{"", "Airport 1", "", "", "ap1", " ", "1", "1", "1", "", "", "", ""};
    vector<string> ap2{"", "Airport 2", "", "", "ap2", " ", "2", "2", "2", "", "", "", ""};
    vector<string> ap3{"", "Airport 3", "", "", "ap3", " ", "3", "3", "3", "", "", "", ""};
    vector<string> ap4{"", "Airport 4", "", "", "ap4", " ", "4", "4", "4", "", "", "", ""};
    vector<string> ap5{"", "Airport 5", "", "", "ap5", " ", "5", "5", "5", "", "", "", ""};
    airports.push_back(ap1);
    airports.push_back(ap2);
    airports.push_back(ap3);
    airports.push_back(ap4);
    airports.push_back(ap5);

    vector<vector<string>> paths;
    //2B,410,AER,2965,KZN,2990,,0,CR2
    vector<string> p1{"", "", "ap1", "", "ap2", "", "", "", ""};
    vector<string> p2{"", "", "ap1", "", "ap3", "", "", "", ""};
    vector<string> p3{"", "", "ap2", "", "ap4", "", "", "", ""};

    paths.push_back(p1);
    paths.push_back(p2);
    paths.push_back(p3);

    Flights f(airports, paths);

    BFS bfs;
    vector<Node> bfs_traversal = bfs.traversal(f, f.getAirports()[0]);
    REQUIRE(bfs_traversal.size() == 4);
    REQUIRE(bfs_traversal[0] == f.getAirports()[0]);
    REQUIRE(bfs_traversal[1] == f.getAirports()[1]);
    REQUIRE(bfs_traversal[2] == f.getAirports()[2]);
    REQUIRE(bfs_traversal[3] == f.getAirports()[3]);
}