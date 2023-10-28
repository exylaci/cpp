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

		long crowd;
		int maxPerson;
		int maxWeight;
		vector<int> weights{};
		int weight;
		long sums[100];

		fi >> crowd >> maxPerson >> maxWeight;
		while (fi >> weight) {
			weights.emplace_back(weight);
		}
		fi.close();
		std::sort(weights.begin(), weights.end(), greater<int>());

		sums[crowd - 1] = weights.at(crowd - 1);
		for (int i = crowd - 2; i >= 0; --i) {
			sums[i] = sums[i + 1] + weights.at(i);
		}

		long long variations{ 0 };
		int people[100]{};
		int index{ 0 };
		int i = 0;
		int previousWeight{ 0 };
		for (; i < crowd; ++i) {
			if (sums[i] < maxWeight) {
				break;
			}
			weight = 0;
			int person = 0;
			int j = i;
			do {
				for (; j < crowd; ++j) {
					if (maxWeight - weight > sums[j]) {
						break;
					}
					if (weights.at(j) + weight <= maxWeight) {
						if (index == maxPerson) {
							break;
						}
						people[index] = j;
						++index;
						weight += weights.at(j);
					}
					if (weight == maxWeight) {
						if (index == maxPerson) {
							++variations;
						}
						weight -= weights.at(j);
						--index;
					}
				}

				if (index > 0) {
					--index;
					weight -= weights.at(people[index]);
					j = people[index] + 1;
				}
			} while (index > 0);

			i = people[0];
		}
		cout << " " << variations << endl;
	}
}