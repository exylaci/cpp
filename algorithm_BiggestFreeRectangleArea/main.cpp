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
		fi >> width >> height;
		auto t = allocateArray(width, height);

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
std::ifstream openFile(std::string& fileName)
{
	std::ifstream fi{ fileName };
	if (!fi.is_open()) {
		std::cout << fileName << "    <--- Baj van! Nem nyilt meg." << std::endl;
	}
	return fi;
}

//2D array, memory allocation in heap
int** allocateArray(const int& width, const int& height) {
	//one-one unit bigger array for simplier if conditions
	int** arr = new int* [width + 1];
	for (int i = 0; i <= width; ++i) {
		int* tmp = new int[height + 1];
		arr[i] = tmp;
	}
	return arr;
}

//2D array, memory release
void releaseArray(const int& width, int** arr) {
	for (int i = 0; i <= width; ++i) {
		delete[] arr[i];
	}
	delete[] arr;
}