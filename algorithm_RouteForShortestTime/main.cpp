#include "main.h"
#include <iostream>
#include <windows.h>

int main() {
	auto fileHandler = openInputFile(INPUT_FILE_NAME);
	auto schedules = loadSchedules(fileHandler);
	closeInputFile(fileHandler);

	setFontCodePage();

	question(schedules, 'A', 'W');
	question(schedules, 'B', 'Y');
}

//open input file for reading
std::ifstream openInputFile(const std::string& fileName) {
	std::ifstream fileHandler{ fileName };
	if (!fileHandler.is_open()) {
		std::cout << fileName << "      <--- Baj van! Nem nyilt meg." << std::endl;
	}
	return fileHandler;
}
//close input file
void closeInputFile(std::ifstream& fileHandler) {
	fileHandler.close();
}
//load schedule data from inout files and calculating distances
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
//store dstances of stops into <schedules> map
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

//set the codepage of standard output to Hungarian caracters
void setFontCodePage() {
	SetConsoleOutputCP(1250);
}

//calculate and printout distances between <departure> and <destination> stops
void question(std::map<char, std::map<char, int>>& schedules, char departure, char destination) {
	auto resoult = findFastestRoute(schedules, departure, destination);
	std::cout << "A leggyorsabb útvonal a " << resoult.second << " megálló távolságra levõ "
		<< departure << " és " << destination << " megállók között " << resoult.first
		<< " perc." << std::endl;
}
//find the fastes route between <departure> and <destination> stops
std::pair<int, int> findFastestRoute(std::map<char, std::map<char, int>>& schedules, char departure, char destination) {
	std::map<char, std::pair<int, int>> routes{};
	routes.insert(std::make_pair(departure, std::pair<int, int>(std::make_pair(0, 0))));
	bool updated{};
	do {
		updated = false;
		for (auto& route : routes) {
			updated |= recalculatingRoute(schedules, route, routes, destination);
		}
	} while (updated);
	return (*routes.find(destination)).second;
}
//decide whether it has to be calculated
bool recalculatingRoute(std::map<char, std::map<char, int>>& schedules, std::pair<const char, std::pair<int, int>>& route, std::map<char, std::pair<int, int>>& routes, char destination) {
	if (route.first == destination) {
		return false;
	}
	auto hops = schedules.find(route.first);
	if (hops == schedules.end()) {
		return false;
	}
	return addToRoutesStopsFromThisStop(hops, route, routes);
}
//increasing the distance and hop routing information by the following stop's data
bool addToRoutesStopsFromThisStop(std::map<char, std::map<char, int>>::iterator& hops, std::pair<const char, std::pair<int, int>>& route, std::map<char, std::pair<int, int>>& routes) {
	bool updated{ false };
	for (const auto& hop : (*hops).second) {
		auto newValue = std::make_pair(hop.first, std::pair<int, int>(std::make_pair(hop.second + route.second.first, route.second.second + 1)));
		auto it = routes.find(newValue.first);
		updated = updateRoutingTable(it, routes, newValue);
	}
	return updated;
}
//store increased distances and hops data into routing table
bool updateRoutingTable(std::map<char, std::pair<int, int>>::iterator& it, std::map<char, std::pair<int, int>>& routes, std::pair<char, std::pair<int, int>>& newValue) {
	if (it == routes.end()) {
		routes.insert(newValue);
		return true;
	}
	if ((*it).second.first > newValue.second.first
		|| ((*it).second.first > newValue.second.first && (*it).second.second > newValue.second.second)) {
		(*it).second = newValue.second;
		return true;
	}
	return false;
}
