#include "Flights.h"
#include <stdlib.h>

Flights::Flights(std::vector<std::vector<std::string>> a, std::vector<std::vector<std::string>> p) {
    createAirports(a);
    createPaths(p);
}

void Flights::createAirports(std::vector<std::vector<std::string>> data) {
    for (unsigned long i = 0; i < data.size(); i++) {
        double lat = atof(data[i][6].c_str());
        double lon = atof(data[i][7].c_str());
        double alt = atof(data[i][8].c_str());
        Node n(data[i][0], data[i][4], lat, lon, alt);
        airports_.push_back(n);
    }
}

void Flights::createPaths(std::vector<std::vector<std::string>> data) {
    for (unsigned long i = 0; i < data.size(); i++) {
        string start_code = data[i][2];
        string end_code = data[i][4];
        Node start;
        Node end;
        for (unsigned long j = 0; j < airports_.size(); j++) {
            if (start_code == airports_[j].getCode()) {
                start = airports_[j];
            }
            if (end_code == airports_[j].getCode()) {
                end = airports_[j];
            }
        }
        Edge e(start, end, 0); //idk how to get weight
        paths_.push_back(e);
    }
}