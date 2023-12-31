#pragma once
#include <fstream>

const std::string BEGINNING_OF_INPUT_FILE_NAME = "halmaz.pelda";
const std::string END_OF_INPUT_FILE_NAME = ".in.txt";

void loadDataFromInputfile(char order, int& last);
std::ifstream openInputFile(char order);
std::string prepareFileName(char order);
std::ifstream openFile(const std::string& filename);

int countNumbers(int last);

void printResoult(char fileCounter, int resoult);
