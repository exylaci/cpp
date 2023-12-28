#include "main.h"
#include <iostream>

int main() {
	for (char fileCounter{ '0' }; fileCounter <= '7'; ++fileCounter) {
		std::string first;
		std::string last;
		int sum;
		loadDataFromInputfile(fileCounter, first, last, sum);
		auto resoult{ findTheNumber(first,last, sum) };
		printResoult(fileCounter, resoult, last);
	}
}

//load min, max, summary data from inout files
void loadDataFromInputfile(const char& order, std::string& first, std::string& last, int& sum) {
	auto fileHandler = openInputFile(order);
	if (fileHandler) {
		fileHandler >> first >> last >> sum;
		fileHandler.close();
	}
}
//open the input file for reading
std::ifstream openInputFile(const char& order) {
	auto filename{ prepareFileName(order) };
	auto fileHandler{ openFile(filename) };
	return fileHandler;
}
//build up the filename string
std::string prepareFileName(const char& order) {
	std::string filename(BEGINNING_OF_INPUT_FILE_NAME);
	filename += order;
	filename += END_OF_INPUT_FILE_NAME;
	return filename;
}
//open the input file for reading
std::ifstream openFile(const std::string& filename) {
	using namespace std;
	ifstream fileHandler{ filename };
	if (!fileHandler.is_open()) {
		cout << filename << "    <--- Baj van! Nem nyilt meg." << endl;
	}
	return fileHandler;
}

//find the the first number that is greather than the <<first>> and the sum of its digit is equal to <<sum>>
std::string findTheNumber(std::string& first, std::string& last, const int& sum) {
	auto differences{ calculateDifference(sumOfDigits(first), sum) };
	std::string resoult{};
	if (differences < 0) {
		resoult = sumIsLess(first, differences);
	}
	else {
		resoult = sumIsGreather(first, differences);
	}
	return validateResoult(resoult, last);
}
//summarize the values of the digits
int sumOfDigits(std::string& numberString) {
	int resoult{ 0 };
	for (int index = 0; index < numberString.length(); ++index) {
		resoult += numberString[index] - '0';
	}
	return resoult;
}
//calculate the difference between the first and the second parameter
int calculateDifference(int one, int two) {
	return two - one;
}
//sum is greather -> last digits should be increased 
const std::string& sumIsGreather(std::string& numberString, int& differences) {
	int index = numberString.length();
	while (differences > 0) {
		if (--index < 0) {
			index = 0;
			numberString = '0' + numberString;
		}
		auto diff = '9' - numberString[index];
		if (diff > differences) {
			numberString[index] += differences;
		}
		else {
			numberString[index] += diff;
		}
		differences -= diff;
	}
	return numberString;
}

//sum is less -> last digits should be decreased 
std::string sumIsLess(std::string& numberString, int& differences) {
	return "0";
}

//check whether the resoult is greather than the secound input number
std::string validateResoult(std::string& resoult, std::string& last) {
	if (isItGreater(resoult, last)) {
		return "NINCS";
	}
	return resoult;
}
//check whether the resoult is greather than the secound input number
bool isItGreater(const BigInt one, const BigInt two) {
	return one > two;
}
//print out the resoult
void printResoult(const char& fileCounter, const std::string& resoult, const std::string& last) {
	std::cout
		<< fileCounter << ": "
		<< resoult
		<< std::endl;
}
