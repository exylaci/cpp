#pragma once

std::string prepareFileName(char fileCounter);
std::ifstream openFile(std::string& fileName);

int** allocateArray(const int& width, const int& height);
void releaseArray(const int& width, int** arr);
void cleanArray(const int& width, const int& height, int** arr);

void loadAndPutAllRectangle(std::ifstream& fi, int** t);