#pragma once

#include <cstddef>
#include <iostream>
#include <sys/types.h>
#include <vector>

class Day3 {
private:
    uint64_t result = 0;
    std::string filePath = "/mnt/d/Github/advent-of-code/AOCpp/Day3/input.txt";
    std::vector<std::string> schematic;

    bool IsSymbol(const char& input);
    bool IsOutOfRange(const int x, const int y, const int maxX, const int maxY);

public:
    Day3();
    ~Day3();

    int run();
};
