#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>
#include <list>

int main() {

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

		std::list<std::list<int>> islands{};
		int city1;
		int city2;
		while (fi >> city1 >> city2) {
			auto island1 = islands.end();
			auto island2 = islands.end();
			for (auto it = islands.begin(); it != islands.end(); ++it) {
				if (island1 == islands.end()) {
					if (std::find((*it).begin(), (*it).end(), city1) != (*it).end()) {
						island1 = it;
					}
				}
				if (island2 == islands.end()) {
					if (std::find((*it).begin(), (*it).end(), city2) != (*it).end()) {
						island2 = it;
					}
				}
				if (island1 != islands.end() && island2 != islands.end()) {
					break;
				}
			}
			if (island1 == islands.end() && island2 == islands.end()) {
				islands.emplace_back(std::list<int> {city1, city2});
			}
			else if (island1 == islands.end()) {
				(*island2).emplace_back(city1);
			}
			else if (island2 == islands.end()) {
				(*island1).emplace_back(city2);
			}
			else if (island1 != island2) {
				std::copy((*island2).begin(), (*island2).end(), std::back_inserter((*island1)));
				islands.erase(island2);
			}
		}

		//int* a = new int[cities];
		//for (int index = 0; index < cities; ++index) a[index] = 0;

		//int city1;
		//int city2;
		//int current;
		//int merge;
		//int islands{ 0 };
		//int counter{ 1 };
		//while (fi >> city1 >> city2) {
		//	if (a[city1] == 0 && a[city2] == 0) {
		//		a[city1] = counter;
		//		a[city2] = counter;
		//		++islands;
		//		++counter;
		//	}
		//	else {
		//		if (a[city1] == 0) {
		//			a[city1] = a[city2];
		//		}
		//		else if (a[city2] == 0) {
		//			a[city2] = a[city1];
		//		}
		//		else if (a[city1] != a[city2]) {
		//			current = std::min(a[city1], a[city2]);
		//			merge = std::max(a[city1], a[city2]);
		//			for (int index = 0; index < cities; ++index) {
		//				if (a[index] == merge) {
		//					a[index] = current;
		//				}
		//			}
		//			--islands;
		//		}
		//	}
		//}
		fi.close();

		std::cout << fileCounter << ":  szigetek szama: " << islands.size();
		std::cout << "    (futasi ido:" << std::setw(5) << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - startTime).count() << ")" << std::endl;
	}
}