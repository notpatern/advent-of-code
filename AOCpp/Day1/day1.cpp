#include "day1.h"

Day1::Day1()
    : inputFilePath("/home/caca/AOCpp/Day1/input.txt")
{
    std::ifstream file(inputFilePath);
    std::string str;

    while (file >> str) {
        fileLines.push_back(str);
    }

    file.close();
}

Day1::~Day1() {}

int Day1::run() {
    return AnalyzeFile();
}

int Day1::AnalyzeFile() {
    std::string lineStringValue;

   for (std::string& line : fileLines) {
        lineStringValue = "";
        lineStringValue += GetNumber(line, firstNumberRegexPattern)
            + GetNumber(line, secondNumberRegexPattern);
        result += std::stoi(lineStringValue);
    }

    return result;
}

std::string Day1::GetNumber(std::string& line, std::string& pattern) {
    std::regex digit_regex(pattern);

    std::smatch match;

    if (std::regex_search(line, match, digit_regex)) {
        return match[0];
    }

    return "";
}
