#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>

int main() {
	using namespace std;

	for (char fileCounter = '0'; fileCounter <= '6'; ++fileCounter) {
		string filename("lift");
		filename += fileCounter;
		filename += ".in.txt";
		cout << endl << filename << ": ";

		ifstream fi{ filename };
		if (!fi.is_open()) {
			cout << "Nem nyilt meg." << endl;
			continue;
		}

		auto startTime = std::chrono::system_clock::now();

		long crowd;
		int maxPerson;
		int maxWeight;
		vector<int> weights{};
		int weight;

		fi >> crowd >> maxPerson >> maxWeight;
		while (fi >> weight) {
			weights.emplace_back(weight);
		}
		fi.close();
		std::sort(weights.begin(), weights.end());

		long long sums[21][1000]{ 0 };
		for (int kg : weights) {
			for (int fo{ maxPerson - 1 }; fo > 0; --fo) {
				for (int veight{ kg }; veight <= maxWeight; ++veight) {
					sums[fo][veight] += sums[fo - 1][veight - kg];
				}
			}
			++sums[0][kg];
		}
		cout << sums[maxPerson - 1][maxWeight];

		cout << endl << " duration: " <<
			std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - startTime).count() << endl;
	}
}