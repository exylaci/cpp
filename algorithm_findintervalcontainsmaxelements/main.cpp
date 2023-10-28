#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
	using namespace std;

	for (char fileCounter = '0'; fileCounter <= '6'; ++fileCounter) {
		string filename("traffipax");
		filename += fileCounter;
		filename += ".in.txt";
		cout << endl << filename << " : ";

		ifstream fi{ filename };
		if (!fi.is_open()) {
			cout << "Nem nyilt meg." << endl;
			continue;
		}

		long pieces;
		int interval;
		vector<int> times{};
		int h;
		int m;
		int s;

		fi >> pieces;
		fi >> interval;
		while (fi >> h >> m >> s) {
			times.emplace_back(h * 3600 + m * 60 + s);
		}
		fi.close();
		std::sort(times.begin(), times.end());

		long maxElements{ 0 };
		long previousLast{ 0 };
		long closingTime;
		long last;

		for (long first = 0; first < pieces; ++first) {
			closingTime = times.at(first) + interval;
			last = previousLast;
			if (closingTime > 86399) {
				closingTime = closingTime - 86400;
				if (times.at(last) > closingTime) {
					last = 0;
				}
			}

			for (; times.at(last) <= closingTime; ++last) {
				if (last >= pieces - 1) {
					last = 0;
					closingTime = closingTime - 86400;
				}
			}
			--last;
			if (last < 0) {
				last = pieces - 1;
			}

			previousLast = last;
			if (last >= first) {
				maxElements = max(maxElements, last - first + 1);
			}
			else {
				maxElements = max(maxElements, pieces - first + last + 1);
			}
		}
		cout << maxElements;
	}
}