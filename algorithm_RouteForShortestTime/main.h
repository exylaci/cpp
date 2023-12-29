#include <fstream>
#include <vector>
#include <map>

#pragma once

const std::string INPUT_FILE_NAME = "menetrend.txt";

std::ifstream openInputFile(const std::string& fileName);
void closeInputFile(std::ifstream& fileHandler);

std::vector<std::map<char, int>> loadSchedules(std::ifstream& fileHandler);
std::map<char, int> loadOneShedule(std::ifstream& fileHandler);

void setFontCodePage();

int fastestRoute(std::vector<std::map<char, int>>& schedules, char departure, char destination);
int shortestRoute(std::vector<std::map<char, int>>& schedules, char departure, char destination);
