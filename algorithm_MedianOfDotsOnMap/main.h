#pragma once
#include <vector>
#include <fstream>

const std::string BEGINNING_OF_INPUT_FILE_NAME = "manhattan.pelda";
const std::string END_OF_INPUT_FILE_NAME = ".in.txt";

std::vector<std::pair<int, int>> getInputData(char order);
std::string prepareFileName(char order);
std::ifstream openFile(const std::string& filename);
std::vector<std::pair<int, int>> loadDataFromFile(std::ifstream& fileHandler);
void closeFile(std::ifstream& fileHandler);
