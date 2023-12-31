#include "main.h"
#include <iostream>

int main() {
	for (char fileCounter{ '1' }; fileCounter <= '2'; ++fileCounter) {
		int last;
		loadDataFromInputfile(fileCounter, last);
		auto resoult = countNumbers(last);
		printResoult(fileCounter, resoult);
	}
}

//load maximum data from input files
void loadDataFromInputfile(char order, int& last) {
	auto fileHandler = openInputFile(order);
	if (fileHandler) {
		fileHandler >> last;
		fileHandler.close();
	}
}
//build up file names and open input files for reading
std::ifstream openInputFile(char order) {
	auto filename = prepareFileName(order);
	auto fileHandler = openFile(filename);
	return fileHandler;
}
//build up filename string
std::string prepareFileName(char order) {
	std::string filename(BEGINNING_OF_INPUT_FILE_NAME);
	filename += order;
	filename += END_OF_INPUT_FILE_NAME;
	return filename;
}
//open input file for reading
std::ifstream openFile(const std::string& filename) {
	using namespace std;
	ifstream fileHandler{ filename };
	if (!fileHandler.is_open()) {
		cout << filename << "    <--- Baj van! Nem nyilt meg." << endl;
	}
	return fileHandler;
}

//count numbers fullfil conditions
int countNumbers(int last) {
	return -1;
}

//printout resoult on standard output
void printResoult(char fileCounter, int resoult) {
	std::cout << fileCounter << ": " << resoult << std::endl;
}
