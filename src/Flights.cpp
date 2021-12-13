#include "Flights.h"
#include <stdlib.h>
#include <cmath>
#include <iostream>

Flights::Flights(vector<vector<string>> a, vector<vector<string>> p)
{
    createAirports(a);
    createPaths(p);
}

void Flights::createAirports(vector<vector<string>> data)
{
    for (unsigned long i = 0; i < data.size(); i++)
    {
        double lat = atof(data[i][6].c_str());
        double lon = atof(data[i][7].c_str());
        double alt = atof(data[i][8].c_str());
        Node n(data[i][1], data[i][4], lat, lon, alt);
        airports_.push_back(n);
    }
}

double Flights::findWeight(Node start, Node end) {
    //https://www.geeksforgeeks.org/program-distance-two-points-earth/
    double lat1 = start.getLat() * M_PI / 180;
    double lat2 = end.getLat() * M_PI / 180;
    double long1 = start.getLong() * M_PI / 180;
    double long2 = end.getLong() * M_PI / 180;

    double dLat = lat2 - lat1;
    double dLong = long2 - long1;

    double weight = pow(sin(dLat / 2), 2) +
                    cos(lat1) * cos(lat2) *
                        pow(sin(dLong / 2), 2);

    weight = 2 * asin(sqrt(weight));
    double radius = 6371;
    return weight * radius;
}

void Flights::createPaths(vector<vector<string>> data)
{
    for (unsigned long i = 0; i < data.size(); i++)
    {
        string start_code = data[i][2];
        string end_code = data[i][4];
        Node start;
        Node end;
        for (unsigned long j = 0; j < airports_.size(); j++)
        {
            if (start_code == airports_[j].getCode())
            {
                start = airports_[j];
            }
            if (end_code == airports_[j].getCode())
            {
                end = airports_[j];
            }
        }
        double weight = findWeight(start, end);
        Edge e(start, end, weight);
        paths_.push_back(e);
    }
}

vector<Node> Flights::getAdjacentNodes(Node airport_code)
{
    vector<Node> adj_airports = vector<Node>();

    for (unsigned long i = 0; i < paths_.size(); i++)
    {
        if (paths_[i].getStart().getCode() == airport_code.getCode())
        {
            adj_airports.push_back(paths_[i].getEnd());
        }
        // else if (paths_[i].getEnd().getCode() == airport_code.getCode())
        // {
        //     adj_airports.push_back(paths_[i].getStart());
        // }
    }
    return adj_airports;
}

vector<Node>& Flights::getAirports() {
    return airports_;
}

vector<Edge>& Flights::getPaths() {
    return paths_;
}

