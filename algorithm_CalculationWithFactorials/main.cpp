#include <iostream>
#include <fstream>
#include "../bigint/bigint.cpp"
#include <string>
#include <chrono>
#include <iomanip>

int main() {
	using namespace std;
	for (char fileCounter = '1'; fileCounter <= '3'; ++fileCounter) {
		string filename("combine");
		filename += fileCounter;
		filename += ".txt";
		ifstream fi{ filename };
		if (!fi.is_open()) {
			std::cout << filename << "    <--- Nem nyilt meg!" << std::endl << std::endl;
			continue;
		}
		auto startTime = std::chrono::system_clock::now();

		int n;
		int k;
		BigInt resoult{ "0" };
		BigInt calculation{ "1" };
		const BigInt zero{ "0" };
		fi >> n;
		while (fi >> n >> k) {
			calculation = Factorial(n) / (Factorial(n - k) * Factorial(k));
			while (calculation > zero) {
				resoult += calculation % 10;
				calculation /= 10;
			}
		}

		fi.close();

		std::cout << fileCounter << ":  " << resoult;
		std::cout << "     (futasi ido: " << std::setw(4) << std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - startTime).count() << " masodperc)";
		std::cout << std::endl << std::endl;
	}
}