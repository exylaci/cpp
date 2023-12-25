#include <iostream>
#include "main.h"

int main() {
	std::cout << task1(10'000) << std::endl;
	std::cout << task2(200) << std::endl;
}

//Count the pieces of the Lychrel numbers less than lastNumber
int task1(int lastNumber) {
	int counter{ 0 };
	for (unsigned int i{ 1 }; i < lastNumber; ++i) {
		if (isItLychrelNumber(i)) {
			++counter;
		}
	}
	return counter;
}
//Which one is the <<n>>th Lychrel number
int task2(int searched) {
	int counter{ 0 };
	int currentNumber{ 0 };
	while(counter<searched) {
		if (isItLychrelNumber(++currentNumber)) {
			++counter;
		}
	}
	return currentNumber;
}

//dedcide whether a number is Lychrel or not
bool isItLychrelNumber(BigInt inspected) {
	int iterations{ 0 };
	do {
		if (isItPalindrom(inspected)) {
			return false;
		}
		inspected += reverse(inspected);
		++iterations;
	} while (iterations <= MAXITERATION);
	return true;
}
//decide whether the number is Palindrom or not
bool isItPalindrom(BigInt& number) {
	auto s{ toString(number) };
	for (int i{ 0 }; i < s.length() / 2; ++i) {
		if (s[i] != s[s.length() - 1 - i]) {
			return false;
		}
	}
	return true;
}
//give back in reverse order of number's digits
BigInt reverse(BigInt& number) {
	auto s{ toString(number) };
	std::string reverse{ "" };
	for (int i = s.length() - 1; i >= 0; --i) {
		reverse += s[i];
	}
	return reverse;
}