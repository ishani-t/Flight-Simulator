#include "../src/Parser.h"

#include <fstream>
#include <sstream>
#include <iostream>

#include <string>
#include <vector>


Parser::Parser(const string &filepath) {

    std::ifstream fileStream(filepath);
    std::string line;

    if (fileStream.is_open()) {
        while(std::getline(fileStream, line)) {
            vector<string> lineVec = convertLineToVector(line);
            data_.push_back(lineVec);
        }
    }
    fileStream.close();
}

std::vector<std::vector<std::string>> Parser::getData() {
    return data_;
}


vector<string> Parser::convertLineToVector(const string &line) {
    vector<string> lineVec;
    stringstream s_stream(line); // create string stream from string
    while(s_stream.good()) {
        string val;
        getline(s_stream, val, ','); // get first string delimited by comma
        val.erase(remove(val.begin(),val.end(),'\"' ),val.end()); //removes abundant quotations from strings
        lineVec.push_back(val);
    }
    
    return lineVec;
}

