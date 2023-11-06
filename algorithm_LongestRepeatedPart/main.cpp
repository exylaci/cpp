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
				bool exists = true;
				for (int i = 0; i < subStringLength; ++i) {
					if (s[from + i] != s[from + i + subStringLength]) {
						exists = false;
						break;
					}
				}
				if (exists) {
					resoult = max(resoult, subStringLength * 2);
				}
			}
		}
		cout << fileCounter << " -> hossz:" << std::setw(5) << resoult << " karakter.";
		std::cout << "  (Futasido:" << std::setw(5) << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - startTime).count() << "msec)" << endl;
	}
}