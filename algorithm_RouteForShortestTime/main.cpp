#include "main.h"
#include <iostream>
#include <windows.h>

int main() {
	using namespace std;
	auto fileHandler = openInputFile(INPUT_FILE_NAME);
	auto schedules = loadSchedules(fileHandler);
	closeInputFile(fileHandler);

	setFontCodePage();
	cout << "Leggyorsabb útvonal A és W között: " << fastestRoute(schedules, 'A', 'W') << endl;
	cout << "Legrövidebb útvonal A és W között: " << shortestRoute(schedules, 'A', 'W') << endl;
	cout << "Leggyorsabb útvonal B és Y között: " << fastestRoute(schedules, 'B', 'Y') << endl;
	cout << "Legrövidebb útvonal B és Y között: " << shortestRoute(schedules, 'B', 'Y') << endl;
}

std::ifstream openInputFile(const std::string& fileName) {
	std::ifstream fileHandler{ fileName };
	if (!fileHandler.is_open()) {
		std::cout << fileName << "      <--- Baj van! Nem nyilt meg." << std::endl;
	}
	return fileHandler;
}
void closeInputFile(std::ifstream& fileHandler) {
	fileHandler.close();
}
//load every schedules
std::map<char, std::map<char, int>> loadSchedules(std::ifstream& fileHandler) {
	std::map<char, std::map<char, int>> schedules{};
	char tmp;
	char stop;
	int distance;
	char previousStop{ ' ' };
	int previousDistance{ 0 };
	fileHandler >> tmp;
	while (fileHandler >> tmp >> tmp >> stop >> tmp >> tmp >> distance >> tmp >> tmp) {
		if (previousStop != ' ') {
			auto oneHop = std::make_pair(stop, distance - previousDistance);
			storeOneHop(schedules, previousStop, oneHop);
		}
		previousStop = stop;
		previousDistance = distance;

		if (tmp == '}') {
			previousStop = ' ';
			previousDistance = 0;
			if (!(fileHandler >> tmp)) {
				break;
			}
		}
	}
	return schedules;
}
void storeOneHop(std::map<char, std::map<char, int>>& schedules, char& previousStop, std::pair<char, int>& oneHop) {
	auto found = schedules.find(previousStop);
	if (found == schedules.end()) {
		schedules.insert(std::make_pair(previousStop, std::map<char, int> {oneHop }));
	}
	else {
		auto storedHop = (*found).second.find(oneHop.first);
		if (storedHop == (*found).second.end() || (*storedHop).second < oneHop.second) {
			(*found).second.insert(oneHop);
		}
	}
}

void setFontCodePage() {
	SetConsoleOutputCP(1250);
}

int fastestRoute(std::map<char, std::map<char, int>>& schedules, char departure, char destination) {
	return -1;
}
int shortestRoute(std::map<char, std::map<char, int>>& schedules, char departure, char destination) {
	return -1;
}

