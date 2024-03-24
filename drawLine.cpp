#include "DrawingFunctions.h"
void drawLine(std::vector<std::vector<int>>& image, int x1, int y1, int x2, int y2, int thickness) {
	// Bresenham algorithm to draw a line
	int dx = std::abs(x2 - x1);
	int dy = std::abs(y2 - y1);
	int sx = x1 < x2 ? 1 : -1;
	int sy = y1 < y2 ? 1 : -1;
	int err = (dx > dy ? dx : -dy) / 2;
	int e2;

	while (true) {
		for (int i = -thickness / 2; i < thickness / 2; ++i) {
			int px = x1 + i;
			int py = y1 + i;
			if (px >= 0 && px < image.size() && py >= 0 && py < image[0].size()) {
				image[px][py] = (0, 0, 0);
			}
		}

		if (x1 == x2 && y1 == y2) break;
		e2 = err;
		if (e2 > -dx) { err -= dy; x1 += sx; }
		if (e2 < dy) { err += dx; y1 += sy; }
	}
}