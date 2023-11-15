#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>
#include <vector>
#include <algorithm>

struct Range
{
	int pieces;
	int first;
	bool operator >(const Range& r) const {
		return pieces > r.pieces;
	}
	bool operator <(const Range& r) const {
		return pieces < r.pieces;
	}
};

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

		int* data = new int[n];
		int index = 0;
		while (fi >> data[index]) {
			++index;
		}
		fi.close();
		if (index != n) {
			cout << "Baj van! Csak " << index << " darab adatot tudtam beolvasni." << endl;
			continue;
		}

		int last{ 0 };
		std::vector<Range> ranges{};
		for (int first = 0; first < n; ++first) {
			//collect the potential ranges
			for (last = first + 1; last < n && abs(data[first] - data[last]) <= k; ++last) {
			}
			--last;
			ranges.emplace_back(Range{ last - first + 1, first });
		}
		std::sort(ranges.begin(), ranges.end(), std::greater<Range>());

		int maxPieces{ 0 };
		for (const auto& one : ranges) {
			//is this range long enough?
			if (one.pieces <= maxPieces) {
				break;
			}

			//check this range
			last = one.first + one.pieces - 1;
			for (int i = one.first; i < last; ++i) {
				for (int j = i + 1; j <= last; ++j) {
					if (abs(data[i] - data[j]) > k) {
						//reduce the length of this range
						last = j - 1;
						if (last - one.first < maxPieces) {
							//the remained part is too short
							goto label;
						}
						break;
					}
				}
			}
			label: maxPieces = std::max(maxPieces, last - one.first + 1);
		}

		std::cout << std::setw(4) << maxPieces;
		std::cout << "    (futasi ido: " << std::setw(6) << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - startTime).count() << " millisec)" << endl;
		std::cout << endl;
	}
}