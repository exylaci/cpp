#include "main.h"
#include <iostream>

int main() {
	for (char fileCounter{ '1' }; fileCounter <= '2'; ++fileCounter) {
		auto fh = openInputFile(fileCounter);
		fh.close();
	}
}

//open the input file for reading
std::ifstream openInputFile(const char& order) {
	auto filename{ prepareFileName(order) };
	auto fileHandler{ openFile(filename) };
	return fileHandler;
}
//build up the filename string
std::string prepareFileName(const char& order) {
	std::string filename(BEGINNING_OF_INPUT_FILE_NAME);
	filename += order;
	filename += ".in.txt";
	return filename;
}
//open the input file for reading
std::ifstream openFile(const std::string& filename) {
	using namespace std;
	ifstream fileHandler{ filename };
	if (!fileHandler.is_open()) {
		cout << filename << "    <--- Baj van! Nem nyilt meg." << endl;
	}
	return fileHandler;
}
