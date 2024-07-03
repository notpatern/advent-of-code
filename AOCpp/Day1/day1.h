#include <array>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <regex>
#include <string>

class Day1{
    private:
        int result = 0;
        std::string firstNumberRegexPattern = "\\d";
        std::string secondNumberRegexPattern = "\\d(?!.*\\d)";

        std::vector<std::string> fileLines;
        std::string inputFilePath;

        int AnalyzeFile();
        std::string GetNumber(std::string& line, std::string& pattern);

    public:
        Day1();
        ~Day1();

        int run();
};

