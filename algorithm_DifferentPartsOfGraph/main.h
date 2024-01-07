#pragma once
#include <map>
#include <vector>
#include <set>
#include <fstream>

std::map<int, std::pair<size_t, std::vector<int>>> hierarchy{};
std::set<size_t> hashs{};

const std::string BEGINNING_OF_INPUT_FILE_NAME = "maffia";
const std::string END_OF_INPUT_FILE_NAME = ".in.txt";

bool getInputData(char order);

void cleanUp();

std::string prepareFileName(char order);
std::ifstream openFile(const std::string& filename);
void closeFile(std::ifstream& fileHandler);
void loadDataFromFile(std::ifstream& fileHandler);
void addToHierarchyList(int x);
void addToLeadersList(int y, int x);

int countDifferents();
size_t getHash(int id);
inline void calculateItsUnderlingsHashs(int id);
inline size_t getCalculatedHash(int id);
inline void calculateOneHash(int id, size_t amount);
inline size_t iterateOnItsUnderlings(int id);

void printOutAnswer(char fileCounter, int answer);
