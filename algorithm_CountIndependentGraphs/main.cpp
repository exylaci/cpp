#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>

int main() {
	int a[100000];

	for (char fileCounter = '1'; fileCounter <= '5'; ++fileCounter) {
		std::string filename("sziget");
		filename += fileCounter;
		filename += ".in.txt";
		std::ifstream fi{ filename };
		if (!fi.is_open()) {
			std::cout << filename << "   Nem nyilt meg." << std::endl;
			continue;
		}
		auto startTime = std::chrono::system_clock::now();

		int cities;
		fi >> cities;
		if (cities > sizeof(a) / sizeof(cities)) {
			std::cout << filename << "   Tul sok telepules van!" << std::endl;
			continue;
		}
		for (int index = 0; index < cities; ++index) a[index] = 0;

		int city1;
		int city2;
		int current;
		int merge;
		int islands{ 1 };
		while (fi >> city1 >> city2) {
			if (a[city1] == 0 && a[city2] == 0) {
				a[city1] = islands;
				a[city2] = islands;
				++islands;
			}
			else {
				if (a[city1] == 0) {
					a[city1] = a[city2];
				}
				else if (a[city2] == 0) {
					a[city2] = a[city1];
				}
				else if (a[city1] != a[city2]) {
					current = std::min(a[city1], a[city2]);
					merge = std::max(a[city1], a[city2]);
					for (int index = 0; index < cities; ++index) {
						if (a[index] == merge) {
							a[index] = current;
						}
						else if (a[index] > merge) {
							--a[index];
						}
					}
					--islands;
				}
			}
		}
		fi.close();
		--islands;

		std::cout << fileCounter << ":  szigetek szama: " << islands;
		std::cout << "    (futasi ido:" << std::setw(5) << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - startTime).count() << ")" << std::endl;
	}
}