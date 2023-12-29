#pragma once
#include <fstream>
#include "../bigint/bigint.cpp"

const std::string BEGINNING_OF_INPUT_FILE_NAME = "osszeg";
const std::string END_OF_INPUT_FILE_NAME = ".in.txt";

void loadDataFromInputfile(const char& order, std::string& first, std::string& last, int& sum);
std::ifstream openInputFile(const char& order);
std::string prepareFileName(const char& order);
std::ifstream openFile(const std::string& filename);

std::string findTheNumber(std::string& first, std::string& last, int sum);
int sumOfDigits(std::string& numberString);
int calculateDifference(int one, int two);
const std::string& sumIsGreater(std::string& numberString, int differences);
std::string sumIsLess(std::string& numberString, int differences, int sum);
void replaceLastDigitsToZero(std::string& numberString, int differences);
std::string incrementByOneAtIndex(std::string& numberString, int index);
std::string validateResoult(std::string& resoult, std::string& last);
bool isItGreater(const BigInt one, const BigInt two);
void printResoult(const char& fileCounter, const std::string& resoult);
