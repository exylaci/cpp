#include <fstream>
#include <map>

#pragma once

const std::string INPUT_FILE_NAME = "menetrend.txt";

std::ifstream openInputFile(const std::string& fileName);
void closeInputFile(std::ifstream& fileHandler);

std::map<char, std::map<char, int>> loadSchedules(std::ifstream& fileHandler);
void storeOneHop(std::map<char, std::map<char, int>>& schedules, char& previousStop, std::pair<char, int>& oneHop);

void setFontCodePage();

int fastestRoute(std::map<char, std::map<char, int>>& schedules, char departure, char destination);
int shortestRoute(std::map<char, std::map<char, int>>& schedules, char departure, char destination);
