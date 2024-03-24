#include "DrawingFunctions.h"
// function for drawing a numbers
void drawDigit(std::vector<std::vector<int>>& image, int posX, int posY, int digit) {
    std::vector<std::vector<std::vector<bool>>> nums = {
        { // 0
            {1, 1, 1, 1},
            {1, 0, 0, 1},
            {1, 0, 0, 1},
            {1, 0, 0, 1},
            {1, 1, 1, 1}
        },
        { // 1
            {0, 0, 1, 0},
            {0, 1, 1, 0},
            {1, 0, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 1, 0}
        },
        { // 2
            {1, 1, 1, 1},
            {0, 0, 0, 1},
            {1, 1, 1, 1},
            {1, 0, 0, 0},
            {1, 1, 1, 1}
        },
        { // 3
            {1, 1, 1, 1},
            {0, 0, 0, 1},
            {1, 1, 1, 1},
            {0, 0, 0, 1},
            {1, 1, 1, 1}
        },
        { // 4
            {1, 0, 0, 1},
            {1, 0, 0, 1},
            {1, 1, 1, 1},
            {0, 0, 0, 1},
            {0, 0, 0, 1}
        },
        { // 5
            {1, 1, 1, 1},
            {1, 0, 0, 0},
            {1, 1, 1, 1},
            {0, 0, 0, 1},
            {1, 1, 1, 1}
        },
        { // 6
            {1, 1, 1, 1},
            {1, 0, 0, 0},
            {1, 1, 1, 1},
            {1, 0, 0, 1},
            {1, 1, 1, 1}
        },
        { // 7
            {1, 1, 1, 1},
            {0, 0, 0, 1},
            {0, 0, 0, 1},
            {0, 0, 0, 1},
            {0, 0, 0, 1}
        },
        { // 8
            {1, 1, 1, 1},
            {1, 0, 0, 1},
            {1, 1, 1, 1},
            {1, 0, 0, 1},
            {1, 1, 1, 1}
        },
        { // 9
            {1, 1, 1, 1},
            {1, 0, 0, 1},
            {1, 1, 1, 1},
            {0, 0, 0, 1},
            {1, 1, 1, 1}
        }
    };

    if (digit < 0 || digit >= nums.size()) {
        std::cerr << "Invalid digit: " << digit << std::endl;
        return;
    }

    // rendering a digit with an increased size
    for (size_t i = 0; i < nums[digit].size(); ++i) {
        for (size_t j = 0; j < nums[digit][i].size(); ++j) {
            if (nums[digit][i][j]) {
                // increasing the size of a digit by multiplying the indexes by the scaling factor
                drawPixel(image, posX + 2 * j, posY + 2 * i + 8, 0, 0, 0);
                drawPixel(image, posX + 2 * j + 1, posY + 2 * i + 8, 0, 0, 0);
                drawPixel(image, posX + 2 * j, posY + 2 * i + 9, 0, 0, 0);
                drawPixel(image, posX + 2 * j + 1, posY + 2 * i + 9, 0, 0, 0);
            }
        }
    }
}