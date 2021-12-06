#include "../catch/catch.hpp"
#include <vector>
#include <string>
#include "../src/BFS.h"

using std::string;
using std::vector;

TEST_CASE("Testing")
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
    vector<string> p3{"", "", "ap1", "", "ap4", "", "", "", ""};
    vector<string> p4{"", "", "ap2", "", "ap5", "", "", "", ""};
    paths.push_back(p1);
    paths.push_back(p2);
    paths.push_back(p3);
    paths.push_back(p4);

    Flights f(airports, paths);

    BFS bfs;
    //vector<Node> bfs_traversal = bfs.traversal(f, f.getAirports()[0]);
    //REQUIRE(bfs_traversal.size() == 4);
}