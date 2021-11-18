#include "Parser.h"

#include <fstream>
#include <sstream>

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
    std::istringstream lineStream(line);
    std::string val;

    std::vector<std::string> lineVec;

    while(std::getline(lineStream, val, ",")) {
        lineVec.push_back(val);
    }
    return lineVec;
}
