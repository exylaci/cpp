#include "main.h"
#include <iostream>
#include <windows.h>

int main() {
	using namespace std;
	auto fileHandler = openInputFile(INPUT_FILE_NAME);
	auto schedules = loadSchedules(fileHandler);
	closeInputFile(fileHandler);

	setFontCodePage();
	cout << "Leggyorsabb �tvonal A �s W k�z�tt: " << fastestRoute(schedules, 'A', 'W') << endl;
	cout << "Legr�videbb �tvonal A �s W k�z�tt: " << shortestRoute(schedules, 'A', 'W') << endl;
	cout << "Leggyorsabb �tvonal B �s Y k�z�tt: " << fastestRoute(schedules, 'B', 'Y') << endl;
	cout << "Legr�videbb �tvonal B �s Y k�z�tt: " << shortestRoute(schedules, 'B', 'Y') << endl;
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
std::vector<std::map<char, int>> loadSchedules(std::ifstream& fileHandler) {
	std::vector<std::map<char, int>> resoult{};
	do {
		auto oneSchedule = loadOneShedule(fileHandler);
		if (oneSchedule.size() > 0) {
			resoult.emplace_back(oneSchedule);
		}
		else {
			return resoult;
		}
	} while (true);
}
//load the schedule of one bus
std::map<char, int> loadOneShedule(std::ifstream& fileHandler) {
	std::map<char, int> resoult{};
	char tmp;
	char stop;
	int distance;
	fileHandler >> tmp;
	while (fileHandler >> tmp >> tmp >> stop >> tmp >> tmp >> distance >> tmp >> tmp) {
		resoult.emplace(stop, distance);
		if (tmp == '}') {
			return resoult;
		}
	}
	return resoult;
}

void setFontCodePage() {
	SetConsoleOutputCP(1250);
}

int fastestRoute(std::vector<std::map<char, int>>& schedules, char departure, char destination) {
	return -1;
}
int shortestRoute(std::vector<std::map<char, int>>& schedules, char departure, char destination) {
	return -1;
}

