#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>

int main() {
	using namespace std;
	for (char fileCounter = '0'; fileCounter <= '4'; ++fileCounter) {
		string filename("input_5fordulo_");
		filename += fileCounter;
		filename += "feladat.txt";

		ifstream fi{ filename };
		if (!fi.is_open()) {
			std::cout << filename << "    <--- Nem nyilt meg!" << std::endl;
			continue;
		}
		auto startTime = std::chrono::system_clock::now();

		int n;
		int k;
		fi >> n >> k;
		cout << fileCounter << ":" << std::setw(7) << n << std::setw(3) << k << " -> ";

		int data[100000];
		int index = 0;
		while (fi >> data[index]) {
			++index;
		}
		fi.close();
		if (index != n) {
			cout << "Baj van! Csak " << index << " darab adatot tudtam beolvasni." << endl;
			continue;
		}

		int maxDarab{ 0 };
		int vege{ 0 };
		for (int eleje = 0; eleje + maxDarab < n; ++eleje) {
			//find a potential range
			for (vege = eleje + 1; vege < n && abs(data[eleje] - data[vege]) <= k; ++vege) {
			}
			--vege;

			//is the range long enough?
			if (vege - eleje < maxDarab) {
				continue;
			}

			//check the range
			bool fewRemained = false;
			for (int i = eleje; i < vege; ++i) {
				for (int j = i + 1; j <= vege; ++j) {
					if (abs(data[i] - data[j]) > k) {
						//reduce the length of the range
						vege = j - 1;
						if (vege - eleje < maxDarab) {
							//the remained part is too short
							fewRemained = true;
						}
						break;
					}
				}
				if (fewRemained) {
					break;
				}
			}
			maxDarab = std::max(maxDarab, vege - eleje + 1);
		}

		std::cout << std::setw(4) << maxDarab;
		std::cout << "    (futasi ido: " << std::setw(6) << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - startTime).count() << " millisec)" << endl;
		std::cout << endl;
	}
}