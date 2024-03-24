#include "DrawingFunctions.h"
void GraphPos(std::vector<std::vector<double>>& positions, int imageSize) {
    // find min and max pos
    double minX = positions[0][0], minY = positions[0][1];
    double maxX = positions[0][0], maxY = positions[0][1];
    for (const auto& vertex : positions) {
        minX = std::min(minX, vertex[0]);
        minY = std::min(minY, vertex[1]);
        maxX = std::max(maxX, vertex[0]);
        maxY = std::max(maxY, vertex[1]);
    }

    // find true size of graph
    double graphWidth = maxX - minX;
    double graphHeight = maxY - minY;

    // calculate the scale along the X and Y axes to fill the entire image
    double scaleX = (graphWidth > 0) ? imageSize / graphWidth : 1.0;
    double scaleY = (graphHeight > 0) ? imageSize / graphHeight : 1.0;


    for (auto& vertex : positions) {
        vertex[0] = (vertex[0] - minX) * scaleX;
        vertex[1] = (vertex[1] - minY) * scaleY;
    }
}