#include "DrawingFunctions.h"

std::vector<std::vector<double>> Alhorithm::forceDirectedGraphDrawing(const std::vector<std::vector<int>>& A, double k, int iterations) {
	std::vector<std::vector<double>> positions(A.size(), std::vector<double>(2));
	std::vector<std::vector<double>> forces(A.size(), std::vector<double>(2));

	initializeRandomPositions(positions);

	for (int iter = 0; iter < iterations; ++iter) {
		computeForces(A, positions, forces, k);
		updatePositions(positions, forces);
	}
	return positions;
}

int Alhorithm::GetImageSize() const {
	return imageSize;
}

void Alhorithm::initializeRandomPositions(std::vector<std::vector<double>>& positions) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<double> dis(0, imageSize);

	for (auto& pos : positions) {
		pos[0] = dis(gen);
		pos[1] = dis(gen);
	}
}

void Alhorithm::computeForces(const std::vector<std::vector<int>>& A, const std::vector<std::vector<double>>& positions, std::vector<std::vector<double>>& forces, double k) {
	double temp = 1.0;

	for (size_t i = 0; i < positions.size(); ++i) {
		for (size_t j = i + 1; j < positions.size(); ++j) {
			double dx = positions[i][0] - positions[j][0];
			double dy = positions[i][1] - positions[j][1];
			double dist = std::sqrt(dx * dx + dy * dy);

			if (A[i][j] == 1) {
				double attractForce = (dist * dist) / k;
				forces[i][0] -= attractForce * (dx / dist);
				forces[i][1] -= attractForce * (dy / dist);
				forces[j][0] += attractForce * (dx / dist);
				forces[j][1] += attractForce * (dy / dist);
			}
			else {
				double repelForce = (k * k) / dist;
				forces[i][0] += repelForce * (dx / dist);
				forces[i][1] += repelForce * (dy / dist);
				forces[j][0] -= repelForce * (dx / dist);
				forces[j][1] -= repelForce * (dy / dist);
			}
		}
	}
	//reducing force growth with temp
	for (size_t i = 0; i < positions.size(); ++i) {
		double forceNorm = std::sqrt(forces[i][0] * forces[i][0] + forces[i][1] * forces[i][1]);
		if (forceNorm >= 2.0) {
			double appForceNorm = std::min(forceNorm, temp);
			forces[i][0] = forces[i][0] / forceNorm * appForceNorm;
			forces[i][1] = forces[i][1] / forceNorm * appForceNorm;
		}
	}
	if (temp > 1) {
		temp *= 0.97;
	}
	else {
		temp = 1;
	}
}

void Alhorithm::updatePositions(std::vector<std::vector<double>>& positions, std::vector<std::vector<double>>& forces) {
	// updating coordinates based on forces
	for (size_t i = 0; i < positions.size(); ++i) {
		positions[i][0] += forces[i][0];
		positions[i][1] += forces[i][1];

		// checking for going beyond the limits
		positions[i][0] = std::max(0.0, std::min(positions[i][0], static_cast<double>(imageSize)));
		positions[i][1] = std::max(0.0, std::min(positions[i][1], static_cast<double>(imageSize)));
	}
}