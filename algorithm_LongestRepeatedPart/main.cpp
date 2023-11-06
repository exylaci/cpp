#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>

int main() {
	using namespace std;
	for (char fileCounter = '0'; fileCounter <= '6'; ++fileCounter) {
		string filename("unalmas");
		filename += fileCounter;
		filename += ".in.txt";

		ifstream fi{ filename };
		if (!fi.is_open()) {
			cout << "Nem nyilt meg." << endl;
			continue;
		}
		auto startTime = std::chrono::system_clock::now();

		string s;
		fi >> s;
		int stringLength = s.size();

		int resoult = 0;
		for (int from = 0; from < stringLength; ++from) {
			for (int subStringLength = 1; subStringLength < stringLength - from; ++subStringLength) {
				int repeats = (stringLength - from) / subStringLength;
				bool exists = true;
				for (int i = 0; i < subStringLength; ++i) {
					for (int j = 1; j <= repeats; ++j) {
						if (s[from + i] != s[from + i + j * subStringLength]) {
							repeats = j - 1;
							break;
						}
					}
					if (repeats < 1) {
						exists = false;
						break;
					}
				}
				if (exists) {
					resoult = max(resoult, subStringLength * (repeats + 1));
				}
			}
		}
		cout << fileCounter << " -> hossz:" << std::setw(5) << resoult << " karakter.";
		std::cout << "  (Futasido:" << std::setw(5) << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - startTime).count() << "msec)" << endl;
	}
}