#include "DrawingFunctions.h"

void drawPixel(std::vector<std::vector<int>>& image, int x, int y, int red, int green, int blue) {
    if (x >= 0 && x < image.size() && y >= 0 && y < image[x].size()) {
        int pixelColor = (red << 16) | (green << 8) | blue;
        image[x][y] = pixelColor;
    }
}