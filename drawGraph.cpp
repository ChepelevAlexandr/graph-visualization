#include "DrawingFunctions.h"
void drawGraph(std::vector<std::vector<int>>& A, int numVertices, int iterations) {
	const int vertexRadius = 7; // point thickness
	const int edgeThickness = 3; // line thickness

	Alhorithm fdgd;
	std::vector<std::vector<double>> positions = fdgd.forceDirectedGraphDrawing(A, 30.0, iterations);
	int imageSize = fdgd.GetImageSize();

	GraphPos(positions, imageSize * 0.85);

	std::vector<std::vector<int>> image(imageSize, std::vector<int>(imageSize, 255));

	for (size_t i = 0; i < positions.size(); ++i) {
		int x = static_cast<int>(positions[i][0]);
		int y = static_cast<int>(positions[i][1]);

		if (x >= 0 && x < imageSize && y >= 0 && y < imageSize) {
			drawVertex(image, x, y, vertexRadius, i + 1);
		}
	}

	for (size_t i = 0; i < numVertices; ++i) {
		for (size_t j = i + 1; j < numVertices; ++j) {
			if (A[i][j] == 1) {
				int x1 = static_cast<int>(positions[i][0]);
				int y1 = static_cast<int>(positions[i][1]);
				int x2 = static_cast<int>(positions[j][0]);
				int y2 = static_cast<int>(positions[j][1]);
				drawLine(image, x1, y1, x2, y2, edgeThickness);
			}
		}
	}
	saveBMP(image);
}