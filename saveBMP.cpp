#pragma once
#include "DrawingFunctions.h"
void saveBMP(const std::vector<std::vector<int>>& image) {
	std::ofstream outFile("output.bmp", std::ios::binary);
	if (!outFile) {
		std::cout << "Failed to open output file." << std::endl;
		return;
	}
	int width = image.size();
	int height = image[0].size();
	int padding = (4 - (width * 3) % 4) % 4;
	int fileSize = 54 + (3 * width + padding) * height;

	// Çàãîëîâîê BMP ôàéëà
	unsigned char bmpHeader[54] = {
		'B', 'M',         // Ñèãíàòóðà
		fileSize & 0xFF, (fileSize >> 8) & 0xFF, (fileSize >> 16) & 0xFF, (fileSize >> 24) & 0xFF, // Ðàçìåð ôàéëà
		0, 0, 0, 0,       // Çàðåçåðâèðîâàííîå ïîëå
		54, 0, 0, 0,      // Ñìåùåíèå äî äàííûõ
		40, 0, 0, 0,      // Ðàçìåð çàãîëîâêà
		width & 0xFF, (width >> 8) & 0xFF, (width >> 16) & 0xFF, (width >> 24) & 0xFF, // Øèðèíà
		height & 0xFF, (height >> 8) & 0xFF, (height >> 16) & 0xFF, (height >> 24) & 0xFF, // Âûñîòà
		1, 0,             // Êîëè÷åñòâî öâåòîâûõ ïëîñêîñòåé
		24, 0,            // Áèò íà ïèêñåëü
		0, 0, 0, 0,       // Ìåòîä ñæàòèÿ (0 = áåç ñæàòèÿ)
		0, 0, 0, 0,       // Ðàçìåð èçîáðàæåíèÿ â áàéòàõ (ìîæíî 0 äëÿ áåçñæàòèÿ)
		0, 0, 0, 0,       // Ãîðèçîíòàëüíîå ðàçðåøåíèå, ïèêñåëü íà ìåòð (íå âàæíî)
		0, 0, 0, 0,       // Âåðòèêàëüíîå ðàçðåøåíèå, ïèêñåëü íà ìåòð (íå âàæíî)
		0, 0, 0, 0,       // Êîëè÷åñòâî èñïîëüçóåìûõ öâåòîâ â èçîáðàæåíèè (íå âàæíî)
		0, 0, 0, 0        // Êîëè÷åñòâî îñíîâíûõ öâåòîâ (íå âàæíî)
	};

	outFile.write(reinterpret_cast<char*>(bmpHeader), 54);

	for (int y = height - 1; y >= 0; --y) {
		for (int x = 0; x < width; ++x) {
			unsigned char color = static_cast<unsigned char>(image[x][y]);
			outFile.write(reinterpret_cast<char*>(&color), sizeof(color));
			outFile.write(reinterpret_cast<char*>(&color), sizeof(color));
			outFile.write(reinterpret_cast<char*>(&color), sizeof(color));
		}
		for (int p = 0; p < padding; ++p) {
			outFile.put(0);
		}
	}
	outFile.close();
}