#pragma once
#include <vector>
#include <fstream>

const std::string BEGINNING_OF_INPUT_FILE_NAME = "manhattan";
const std::string END_OF_INPUT_FILE_NAME = ".in.txt";

std::vector<std::pair<int, int>> getInputData(char order);
std::string prepareFileName(char order);
std::ifstream openFile(const std::string& filename);
std::vector<std::pair<int, int>> loadDataFromFile(std::ifstream& fileHandler);
void closeFile(std::ifstream& fileHandler);

std::pair<long long, int> calculate(std::vector<std::pair<int, int>>& dots);
std::pair<int, int> calculateMedianX(std::vector<std::pair<int, int>>& dots);
std::pair<int, int> calculateMedianY(std::vector<std::pair<int, int>>& dots);
int checkMedianPoints(std::vector<std::pair<int, int>>& dots, std::pair<int, int>& medianx, std::pair<int, int>& mediany);
long long calculateDistances(std::vector<std::pair<int, int>>& dots, int x, int y);
std::pair<long long, int> inExtendedArea(std::vector<std::pair<int, int>>& dots, std::pair<int, int>& medianX, std::pair<int, int>& medianY);
void checkThisPoint(std::vector<std::pair<int, int>>& dots, long long& minDistances, int& pieces, int x, int y);

void printOut(char fileCounter, std::pair<long long, int>& resoult);
