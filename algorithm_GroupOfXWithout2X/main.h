#pragma once
#include <fstream>
#include "../bigint/bigint.cpp"

const std::string BEGINNING_OF_INPUT_FILE_NAME = "halmaz";
const std::string END_OF_INPUT_FILE_NAME = ".in.txt";

void loadDataFromInputfile(char order, std::string& last);
std::ifstream openInputFile(char order);
std::string prepareFileName(char order);
std::ifstream openFile(const std::string& filename);

BigInt countNumbers(BigInt last);

void printResoult(char fileCounter, BigInt resoult);
