#pragma once

#include "Node.h"

//#include <string>

//using std::string;

class Edge
{
public:
    Edge(Node& s, Node& e, double w); //possibly add a label?
    Node& getStart();
    Node& getEnd();
    double getWeight();
private:
    Node start_;
    Node end_;
    double weight_;
};
