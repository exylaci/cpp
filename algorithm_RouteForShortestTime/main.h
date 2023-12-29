#include <iostream>
#include <vector>
#include <map>

#pragma once

const std::string INPUT_FILE_NAME = "menetrendek.txt";

std::ifstream openInputFile(std::string filename);
std::vector<std::map<char,int>> loadSchedules(std::ifstream fileHandler);
int fastestRoute(std::vector<std::map<char, int>>& schedules, char departure,char destination);
int shortestRoute(std::vector<std::map<char, int>>& schedules, char departure,char destination);
