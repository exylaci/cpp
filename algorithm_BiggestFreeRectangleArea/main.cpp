#include <string>
#include <iostream>
#include <fstream>
#include "main.h"

int main() {
	for (char fileCounter{ '1' }; fileCounter <= '4'; ++fileCounter) {
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

		std::cout << fileCounter << ": " << width << "x" << height << std::endl;
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
		for (int a = 0; a < h; ++a)
			for (int b = 0; b < w; ++b) {
				t[b + x][a + y] = 0;
			}
	}
}