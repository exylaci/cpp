#pragma once
#include <fstream>

const std::string BEGINNING_OF_INPUT_FILE_NAME = "osszeg.pelda";

std::ifstream openInputFile(const char& order);
std::string prepareFileName(const char& order);
std::ifstream openFile(const std::string& filename);