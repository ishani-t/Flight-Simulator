#pragma once

#include "Node.h"

//#include <string>

//using std::string;

class Edge
{
public:
    Edge(Node s, Node e, int w); //possibly add a label?

private:
    Node start_;
    Node end_;
    int weight_;
};
