#pragma once
#include <string>

using std::string;

class Node
{
private:
    string name_;
    string code_;
    double latitude_;
    double longitude_;
    double altitude_;

public:
    Node();
    Node(string n, string c, double lat, double lon, double alt);
    string getCode();
};