#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <random>

void drawDigit(std::vector<std::vector<int>>& image, int posX, int posY, int digit);

void drawGraph(std::vector<std::vector<int>>& A, int numVertices, int iterations);

void drawLine(std::vector<std::vector<int>>& image, int x1, int y1, int x2, int y2, int thickness);

void drawVertex(std::vector<std::vector<int>>& image, int x, int y, int radius, int number);

void saveBMP(const std::vector<std::vector<int>>& image);

void drawPixel(std::vector<std::vector<int>>& image, int x, int y, int red, int green, int blue);

void GraphPos(std::vector<std::vector<double>>& positions, int imageSize);

#ifndef ALHORITHM_H
#define ALHORITHM_H
class Alhorithm {
public:
    std::vector<std::vector<double>> forceDirectedGraphDrawing(const std::vector<std::vector<int>>& A, double k, int iterations);
    int GetImageSize() const;
private:
    const int imageSize = 1200;
    void initializeRandomPositions(std::vector<std::vector<double>>& positions);
    void computeForces(const std::vector<std::vector<int>>& A, const std::vector<std::vector<double>>& positions, std::vector<std::vector<double>>& forces, double k);
    void updatePositions(std::vector<std::vector<double>>& positions, std::vector<std::vector<double>>& forces);
};
#endif