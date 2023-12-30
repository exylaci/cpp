#include <fstream>
#include <map>

#pragma once

const std::string INPUT_FILE_NAME = "menetrend.txt";

std::ifstream openInputFile(const std::string& fileName);
void closeInputFile(std::ifstream& fileHandler);

std::map<char, std::map<char, int>> loadSchedules(std::ifstream& fileHandler);
void storeOneHop(std::map<char, std::map<char, int>>& schedules, char& previousStop, std::pair<char, int>& oneHop);

void setFontCodePage();

void question(std::map<char, std::map<char, int>>& schedules, char departure, char destination);
std::pair<int, int> findFastestRoute(std::map<char, std::map<char, int>>& schedules, char departure, char destination);
bool recalculatingRoute(std::map<char, std::map<char, int>>& schedules, std::pair<const char, std::pair<int, int>>& route, std::map<char, std::pair<int, int>>& routes, char destination);
bool addToRoutesStopsFromThisStop(std::map<char, std::map<char, int>>::iterator& hops, std::pair<const char, std::pair<int, int>>& route, std::map<char, std::pair<int, int>>& routes);
bool updateRoutingTable(std::map<char, std::pair<int, int>>::iterator& it, std::map<char, std::pair<int, int>>& routes, std::pair<char, std::pair<int, int>>& newValue);
