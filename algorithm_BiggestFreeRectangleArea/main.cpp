#include <string>
#include <iostream>
#include <fstream>
#include "main.h"

int main() {
	for (char fileCounter{ '1' }; fileCounter <= '4'; ++fileCounter) {
		auto fileName = prepareFileName(fileCounter);
		auto fi = openFile(fileName);

		std::cout << fileCounter << ": " << std::endl;
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