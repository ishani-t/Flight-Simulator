#include "Node.h"

Node::Node() {

}

Node::Node(string n, string c, double lat, double lon, double alt)
{
    name_ = n;
    code_ = c;
    latitude_ = lat;
    longitude_ = lon;
    altitude_ = alt;
}

string Node::getCode() {
    return code_;
}

double Node::getLat() {
    return latitude_;
}

double Node::getLong() {
    return longitude_;
}