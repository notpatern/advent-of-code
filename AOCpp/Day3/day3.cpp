#include "day3.h"
#include <cctype>
#include <cstdint>
#include <fstream>
#include <string>

Day3::Day3() {
    std::ifstream file(filePath);

    for(std::string str; getline(file, str);) {
        schematic.push_back(str);
    }

    file.close();

}

Day3::~Day3() {

}

int Day3::run() {

    int row = schematic.size();
    int col = schematic[0].size();

    for (uint16_t r = 0; r < row; r++) {
        int buffer = 0;
        bool isPart = false;
        for (uint16_t c = 0; c < col; c++) {
            char ch = schematic[r][c];
            if (std::isdigit(ch)) {
                buffer = buffer*10 + ch - '0';

                if (isPart) {
                    continue;
                }

                for (int16_t currentRow = -1; currentRow <= 1; currentRow++) {
                    for (int16_t currentCol = -1; currentCol <= 1; currentCol++) {
                        int16_t indentedRow = r + currentRow;
                        int16_t indentedCol = c + currentCol;

                        if (!(indentedRow < row && indentedRow >= 0) || !(indentedCol < col && indentedCol >=0) || (indentedRow == 0 && indentedCol == 0)) {
                            continue;
                        }

                        if (!std::isdigit(schematic[indentedRow][indentedCol]) && schematic[indentedRow][indentedCol] != '.') {
                            isPart = true;
                            break;
                        }
                    }
                    if (isPart) {
                        break;
                    }
                }

            } else {
                if (isPart) result += buffer;
                buffer = 0;
                isPart = false;
            }
        }
        if (isPart) result += buffer;
        buffer = 0;
        isPart = false;

    }
    return result;
}
