#include "Edge.h"

Edge::Edge(Node& s, Node& e, double w) {
    start_ = s;
    end_ = e;
    weight_ = w;
}

Node& Edge::getStart() {
    return start_;
}

Node& Edge::getEnd() {
    return end_;
}