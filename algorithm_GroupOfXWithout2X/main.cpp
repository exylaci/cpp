#include "main.h"
#include <iostream>

int main() {
	for (char fileCounter{ '1' }; fileCounter <= '5'; ++fileCounter) {
		std::string last;
		loadDataFromInputfile(fileCounter, last);
		auto resoult = countNumbers(last);
		printResoult(fileCounter, resoult);
	}
}

//load maximum data from input files
void loadDataFromInputfile(char order, std::string& last) {
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
BigInt countNumbers(BigInt last) {
	BigInt pieces{ "0" };
	for (int n = 0; last >= power(2, 2 * n); ++n) {
		pieces += (last + power(2, 2 * n)) / power(2, 2 * n + 1);
	}
	return pieces;
}

//printout resoult on standard output
void printResoult(char fileCounter, BigInt resoult) {
	std::cout << fileCounter << ": " << resoult << std::endl;
}