#pragma once
#include <map>
#include <vector>
#include <fstream>

std::map<int, std::pair<size_t, std::vector<int>>> hierarchy{};

const std::string BEGINNING_OF_INPUT_FILE_NAME = "maffia.pelda";
const std::string END_OF_INPUT_FILE_NAME = ".in.txt";

bool getInputData(char order);
std::string prepareFileName(char order);
std::ifstream openFile(const std::string& filename);
void loadDataFromFile(std::ifstream& fileHandler);
void addToHierarchyList(int x);
void addToLeadersList(int y, int x);
void closeFile(std::ifstream& fileHandler);

