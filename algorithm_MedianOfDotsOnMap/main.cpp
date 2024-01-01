#include "main.h"
#include <iostream>
#include <algorithm> 
#include <execution>

int main() {
	for (char fileCounter{ '1' }; fileCounter <= '5'; ++fileCounter) {
		auto coordinates = getInputData(fileCounter);
		auto resoult = calculate(coordinates);
		std::cout << fileCounter << ": " << resoult << std::endl;
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

//calculate the answer
int calculate(std::vector<std::pair<int, int>>& dots) {
	if (dots.size() > 0) {
		std::pair<int, int> medianX = calculateMedianX(dots);
		std::pair<int, int> medianY = calculateMedianY(dots);
		auto pieces = checkMedianPoints(dots, medianX, medianY);
		return pieces;
	}
	return -1;
}
//calculate the median points of x coordinates
std::pair<int, int> calculateMedianX(std::vector<std::pair<int, int>>& dots) {
	std::sort(dots.begin(), dots.end(),
		[](const std::pair<int, int>& a, const std::pair<int, int>& b) {return a.first < b.first; });
	int m1 = dots.at((dots.size() - 1) / 2).first;
	int m2 = dots.at((dots.size()) / 2).first;
	return std::make_pair(m1, m2);
}
//calculate the median points of x coordinates
std::pair<int, int> calculateMedianY(std::vector<std::pair<int, int>>& dots) {
	std::sort(dots.begin(), dots.end(),
		[](const std::pair<int, int>& a, const std::pair<int, int>& b) {return a.second < b.second; });
	int m1 = dots.at((dots.size() - 1) / 2).second;
	int m2 = dots.at((dots.size()) / 2).second;
	return std::make_pair(m1, m2);
}
//exclude the occupied points
int checkMedianPoints(std::vector<std::pair<int, int>>& dots, std::pair<int, int>& medianx, std::pair<int, int>& mediany) {
	int pieces{ 0 };
	for (int x = medianx.first; x <= medianx.second; ++x) {
		for (int y = mediany.first; y <= mediany.second; ++y) {
			if (!isItOccupied(dots, x, y)) {
				++pieces;
			}
		}
	}
	return pieces;
}
//decide whether a dpoint on the map is occupied or not
bool isItOccupied(std::vector<std::pair<int, int>>& dots, int x, int y) {
	for (auto& dot : dots) {
		if (x == dot.first && y == dot.second) {
			return true;
		}
	}
	return false;
}