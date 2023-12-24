#include <iostream>
#include "main.h"

int main() {
	std::cout << task1(10'000) << std::endl;
	std::cout << task2(200) << std::endl;
}

//Count the pieces of the Lychrel numbers less than lastNumber
int task1(int lastNumber) {
	int counter{ 0 };
	for (int i{ 1 }; i < lastNumber; ++i) {
		int iterates{ 0 };
		long inspected{ i };
		do {
			if (isItPalindrom(i)) {
				++counter;
				break;
			}
			inspected += reverse(inspected);
			++iterates;
		} while (i <= MAXITERATION);
	}
	return counter;
}
//Which one is the <<n>>th Lychrel number
int task2(int numero) { return -1; }

//decide whether the number is Palindrom or not
bool isItPalindrom(int number) {
	return true;
}
//give back in reverse order of number's digits
long reverse(long number) {
	return -1;
}