#include "DrawingFunctions.h"
void drawVertex(std::vector<std::vector<int>>& image, int x, int y, int radius, int number) {
	for (int i = x - radius; i <= x + radius; ++i) {
		for (int j = y - radius; j <= y + radius; ++j) {
			if ((i - x) * (i - x) + (j - y) * (j - y) <= radius * radius) {
				if (i >= 0 && i < image.size() && j >= 0 && j < image[0].size()) {
					image[i][j] = (0, 0, 0);
				}
			}
		}
	}

	int labelX = x - 4;
	int labelY = y + 4;
	std::string label = std::to_string(number);
	int digitWidth = 12;
	for (char c : label) {
		int digit = c - '0';
		drawDigit(image, labelX, labelY, digit);
		labelX += digitWidth - 2;
	}
}