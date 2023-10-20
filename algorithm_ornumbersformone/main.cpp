#include "../bigint/bigint.cpp"
#include <string>
#include <iostream>
#include <fstream>

int main() {
	for (char fileCounter = '0'; fileCounter <= '6'; ++fileCounter) {
		std::string fileName = "vagy";
		fileName += fileCounter;
		fileName += ".in.txt";
		std::cout << fileCounter << ": ";

		std::ifstream fi{ fileName };
		if (!fi) {
			std::cout << "Nem nyilt meg!" << std::endl;
			continue;
		}

		std::string temp;
		fi >> temp;
		fi.close();
		std::cout << temp << std::endl;

		BigInt number(temp);
		BigInt resuolt(2);
		while (resuolt < number) {
			resuolt *= 2;
		}
		resuolt -= 1;
		std::cout << "   " << resuolt << std::endl;
	}
}