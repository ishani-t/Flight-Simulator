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

bool Node::operator==(const Node& rhs) const {
    return (this->name_ == rhs.name_) && (this->code_ == rhs.code_) && (this->latitude_ == rhs.latitude_) 
        && (this->longitude_ == rhs.longitude_) && (this->altitude_ == rhs.altitude_);
}