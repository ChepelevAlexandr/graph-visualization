#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <random>
#include "DrawingFunctions.h"

int main() {
	std::ifstream inputFile("input.txt");
	int numVertices, numEdges;
	inputFile >> numVertices >> numEdges;

	std::vector<std::vector<int>> adjacencyMatrix(numVertices, std::vector<int>(numVertices, 0));
	for (int i = 0; i < numEdges; ++i) {
		int u, v;
		inputFile >> u >> v;

		adjacencyMatrix[u][v] = 1;
		adjacencyMatrix[v][u] = 1;
	}
	drawGraph(adjacencyMatrix, numVertices, 1000);
	return 0;
}