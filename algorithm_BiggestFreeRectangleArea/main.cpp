#include <string>
#include <iostream>
#include <fstream>
#include "main.h"

int main() {
	for (char fileCounter{ '0' }; fileCounter <= '4'; ++fileCounter) {
		auto fileName = prepareFileName(fileCounter);
		auto fi = openFile(fileName);

		int width;
		int height;
		int tmp;
		fi >> width >> height >> tmp;
		auto t = allocateArray(width, height);
		cleanArray(width, height, t);
		loadAndPutAllRectangle(fi, t);
		fi.close();

		auto freeSize = findBiggestAreea(width, height, t);
		std::cout << fileCounter << ": " << freeSize << std::endl;

		releaseArray(width, t);
	}
}

//build up input file's name
std::string prepareFileName(char fileCounter) {
	std::string filename("input_7fordulo_");
	filename += fileCounter;
	filename += "feladat.txt";
	return filename;
}

//open input file for reading
std::ifstream openFile(std::string& fileName) {
	std::ifstream fi{ fileName };
	if (!fi.is_open()) {
		std::cout << fileName << "    <--- Baj van! Nem nyilt meg." << std::endl;
	}
	return fi;
}

//2D array, memory allocation in heap
int** allocateArray(const int& width, const int& height) {
	//one-one unit bigger array for simplier if conditions
	int** arr = new int* [width];
	for (int i = 0; i < width; ++i) {
		int* tmp = new int[height];
		arr[i] = tmp;
	}
	return arr;
}

//2D array, memory release
void releaseArray(const int& width, int** arr) {
	for (int i = 0; i < width; ++i) {
		delete[] arr[i];
	}
	delete[] arr;
}

//fill up the array with 1
void cleanArray(const int& width, const int& height, int** arr) {
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			arr[x][y] = 1;
		}
	}
}

//load rectangles data from input file and draw them to the array
void loadAndPutAllRectangle(std::ifstream& fi, int** t) {
	int x;
	int y;
	int w;
	int h;
	while (fi >> x >> y >> w >> h) {
		storeToTheArray(x, y, w, h, t);
	}
}

//draw one rectangle into the array
void storeToTheArray(const int& x, const int& y, const int& w, const int& h, int** t) {
	for (int a = 0; a < h; ++a)
		for (int b = 0; b < w; ++b) {
			t[b + x][a + y] = 0;
		}
}

int findBiggestAreea(const int& width, const int& height, int** t) {
	int maxSize{ 0 };
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			incrementHeightValueBelow(y, height, t[x]);
			if (t[x][y] != 0 && (y + 1 == height || t[x][y + 1] == 0)) {
				auto leftSize = findLeftEdge(x, y, t);
				auto rightSize = findRightEdge(x, y, width, t);
				auto freeRectangleSize = t[x][y] * (rightSize + leftSize - 1);
				maxSize = std::max(maxSize, freeRectangleSize);
			}
		}
	}
	return maxSize;
}

//increment the height values in the next line below
void incrementHeightValueBelow(const int& y, const int& height, int* oneColumn) {
	if (y < height - 1 && oneColumn[y + 1]>0) {
		oneColumn[y + 1] = oneColumn[y] + 1;
	}
}

//find the right edge (where the height value is smaler than the current one)
int findRightEdge(const int& x, const int& y, const int& width, int** t) {
	int vege{ 0 };
	while (x + vege < width && t[x][y] <= t[x + vege][y]) ++vege;
	return vege;
}

//find the left edge (where the height value is smaler than the current one)
int findLeftEdge(const int& x, const int& y, int** t) {
	int eleje{ 0 };
	while (x - eleje >= 0 && t[x - eleje][y] >= t[x][y]) ++eleje;
	return eleje;
}