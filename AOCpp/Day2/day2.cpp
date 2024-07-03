#include "day2.h"
#include <cctype>
#include <fstream>
#include <string>

Day2::Day2() {
    std::ifstream file(inputFilePath);
    for(std::string str; getline(file, str);) {
        fileLines.push_back(str);
    }

    file.close();
}

Day2::~Day2() {
}

int Day2::run() {
    for (std::string game : fileLines) {
        result += ValidateGame(game);
    }

    return result;
}

int Day2::ValidateGame(std::string& game) {
    int gameNumber = 0;

    bool red = ValidateColor(RED, maxRed, game);
    bool blue = ValidateColor(BLUE, maxBlue, game);
    bool green = ValidateColor(GREEN, maxGreen, game);

    if (red && blue && green) {
        gameNumber = GetGameNumber(game);
        std::cout << gameNumber << std::endl;
    }

    return gameNumber;
}

int Day2::GetGameNumber(std::string& line) {
    std::string stringBuffer = "";
    int buffer = 0;

    for (const char character : line) {
        if (isdigit(character)) {
            std::string str(1, character);
            stringBuffer += str;
        }
        else if (character == ':' && stringBuffer != "") {
            buffer = std::stoi(stringBuffer);
            return buffer;
        }
        else {
            stringBuffer = "";
            buffer = 0;
        }
    }
    return 0;
}

bool Day2::ValidateColor(const char& color, const int& maxColorAmount, std::string& line) {
    std::string stringBuffer = "";
    int buffer = 0;

    for (const char character : line) {
        if (isdigit(character)) {
            std::string str(1, character);
            stringBuffer += str;
        }
        else if (isalpha(character) && stringBuffer != "") {
            if (character == color) {
                buffer = std::stoi(stringBuffer);
                if (buffer > maxColorAmount) {
                    return false;
                }
            }
            buffer = 0;
            stringBuffer = "";
        }
        else if (character == ':' || character == ';') {
            buffer = 0;
            stringBuffer = "";
        }
    }

    return true;
}
