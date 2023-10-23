#include <string>
#include <iostream>
#include <fstream>
#include <vector>

int main() {
	using namespace std;

	for (char fileCounter = '0'; fileCounter <= '6'; ++fileCounter) {
		string filename("osszeg");
		filename += fileCounter;
		filename += ".in.txt";
		cout << endl << filename << ": ";

		ifstream fi{ filename };
		if (!fi.is_open()) {
			cout << "Nem nyilt meg." << endl;
			continue;
		}

		vector<long> numbers{};
		vector<long long> sums{};
		long long decreaser{ 0 };
		long long sum{ 0 };
		long number{};
		while (fi >> number) {
			numbers.emplace_back(number);
			sum += number;
			sums.emplace_back(sum);
		}
		fi.close();

		long size = numbers.size() - 1;
		for (long first = 0; first < size; ++first) {
			for (long last = first; last < size; ++last) {
				if (sums.at(last) - decreaser == numbers.at(last + 1)) {
					cout << first << "-" << last << endl;
					first = size;
					break;
				}
			}
			decreaser += numbers.at(first);
		}
	}
}