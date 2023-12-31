#include "main.h"
#include <iostream>
#include <algorithm> 

int main() {
	for (char fileCounter{ '1' }; fileCounter <= '7'; ++fileCounter) {
		auto coordinates = getInputData(fileCounter);
		if (coordinates.size() > 0) {
			auto resoult = calculate(coordinates);
			printOut(fileCounter, resoult);
		}
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

//calculate the answers
std::pair<long long, int> calculate(std::vector<std::pair<int, int>>& dots) {
	std::pair<int, int> medianX = calculateMedianX(dots);
	std::pair<int, int> medianY = calculateMedianY(dots);
	auto pieces = checkMedianPoints(dots, medianX, medianY);
	if (pieces == 0) {
		return inExtendedArea(dots, medianX, medianY);
	}
	auto distances = calculateDistances(dots, medianX.first, medianY.first);
	return std::pair<long long, int>(distances, pieces);
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
int checkMedianPoints(std::vector<std::pair<int, int>>& dots, std::pair<int, int>& medianX, std::pair<int, int>& medianY) {
	int pieces{ 0 };
	for (int x = medianX.first; x <= medianX.second; ++x) {
		for (int y = medianY.first; y <= medianY.second; ++y) {
			if (std::find(dots.begin(), dots.end(), std::pair<int, int>(x, y)) == dots.end()) {
				++pieces;
			}
		}
	}
	return pieces;
}
//calculate the total distances of dots from any medialPoint
long long calculateDistances(std::vector<std::pair<int, int>>& dots, int x, int y) {
	long long resoult{ 0 };
	for (auto& dot : dots) {
		resoult += abs(dot.first - x);
		resoult += abs(dot.second - y);
	}
	return resoult;
}
//every median point is occupied -> bruteforce checking the one step outer area
std::pair<long long, int> inExtendedArea(std::vector<std::pair<int, int>>& dots, std::pair<int, int>& medianX, std::pair<int, int>& medianY) {
	long long minDistances{ LLONG_MAX };
	int pieces{ 0 };
	--medianX.first;
	++medianX.second;
	--medianY.first;
	++medianY.second;
	for (int x = medianX.first; x <= medianX.second; ++x) {
		checkThisPoint(dots, minDistances, pieces, x, medianY.first);
		checkThisPoint(dots, minDistances, pieces, x, medianY.second);
	}
	for (int y = medianY.first; y <= medianY.second; ++y) {
		checkThisPoint(dots, minDistances, pieces, medianX.first, y);
		checkThisPoint(dots, minDistances, pieces, medianX.second, y);
	}
	return 	std::make_pair(minDistances, pieces);
}
//check the recalculated distances from this point and store it if it is less 
//than the previously calculated ones and also set the pieces of minimum distances
void checkThisPoint(std::vector<std::pair<int, int>>& dots, long long& minDistances, int& pieces, int x, int y) {
	if (std::find(dots.begin(), dots.end(), std::pair<int, int>(x, y)) == dots.end()) {
		long long distances = calculateDistances(dots, x, y);
		if (distances < minDistances) {
			minDistances = distances;
			pieces = 1;
		}
		else if (minDistances == distances) {
			++pieces;
		}
	}
}

//print out the resoult to the standard output
void printOut(char fileCounter, std::pair<long long, int>& resoult) {
	std::cout << fileCounter << ": " << resoult.first << " " << resoult.second << std::endl;
}
