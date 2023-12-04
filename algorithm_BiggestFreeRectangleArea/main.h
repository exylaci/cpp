#pragma once

std::string prepareFileName(char fileCounter);
std::ifstream openFile(std::string& fileName);

int** allocateArray(const int& width, const int& height);
void releaseArray(const int& width, int** arr);
void cleanArray(const int& width, const int& height, int** arr);

void loadAndPutAllRectangle(std::ifstream& fi, int** t);
void storeToTheArray(const int& x, const int& y, const int& w, const int& h, int** t);

int findBiggestAreea(const int& width, const int& height, int** t);
void incrementHeightValueBelow(const int& y, const int& height, int* oneColumn);
int findRightEdge(const int& x, const int& y, const int& width, int** t);
int findLeftEdge(const int& x, const int& y, int** t);