#pragma once

#include <iostream>
#include <vector>
#include <cctype>

class Day2 {
private:
    const char RED = 'r';
    const char BLUE = 'b';
    const char GREEN = 'g';

    const int maxRed = 12;
    const int maxBlue = 14;
    const int maxGreen = 13;

    std::vector<std::string> fileLines;

    int result = 0;
    std::string inputFilePath = "/mnt/d/Github/advent-of-code/AOCpp/Day2/input.txt";

    int ValidateGame(std::string& line);
    int GetGameNumber(std::string& line);
    bool ValidateColor(const char& color, const int& maxColorAmount, std::string& line);

public:
    Day2();
    ~Day2();

    int run();
};

struct Coords {
public:
    int x;
    int y;
};
