#include "main.h"
#include <iostream>

int main() {
	for (char fileCounter{ '1' }; fileCounter <= '5'; ++fileCounter) {
		auto coordinates = getInputData(fileCounter);
		std::cout << fileCounter << ": " << coordinates.size() << std::endl;
	}
}

//build up file name, open input file, load data from input file, close input file
std::vector<std::pair<int, int>> getInputData(char order) {
	auto filename = prepareFileName(order);
	auto fileHandler = openFile(filename);
	if (fileHandler) {
		auto data = loadDataFromFile(fileHandler);
		closeFile(fileHandler);
		return data;
	}
	return std::vector<std::pair<int, int>> {};
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
//load data from input file
std::vector<std::pair<int, int>> loadDataFromFile(std::ifstream& fileHandler) {
	std::vector<std::pair<int, int>> resoult{};
	int x;
	int y;
	while (fileHandler >> x >> y) {
		resoult.emplace_back(std::pair<int, int>(std::make_pair(x, y)));
	}
	return resoult;
}
//close input file
void closeFile(std::ifstream& fileHandler) {
	fileHandler.close();
}