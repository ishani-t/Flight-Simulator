#pragma once

// #include <fstream>
#include <vector>

using namespace std;

class Parser {
    public:

        /**
         * Constructor - parses a CSV file into a vector of vector of strings.
         * Each row is a line in the CSV, each entry in the row is a comma separated value.
         */
        Parser(const string &filepath);

        std::vector<std::vector<std::string>> getData();
        

    private:
        vector<string> convertLineToVector(const string &line);

        std::vector<std::vector<std::string>> data_;

}