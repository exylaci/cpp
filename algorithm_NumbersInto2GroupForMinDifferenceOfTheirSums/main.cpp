#include <iostream>
#include <fstream>
#include <string>

int main() {
	using namespace std;
	for (char fileCounter = '1'; fileCounter <= '5'; ++fileCounter) {
		string filename("testver");
		filename += fileCounter;
		filename += ".in.txt";

		ifstream fi{ filename };
		if (!fi.is_open()) {
			std::cout << filename << "   <--- Nem nyilt meg!" << std::endl << std::endl;
			continue;
		}

		int num;
		long difference{ 0 };
		while (fi >> num) {
			if (difference > 0) {
				difference -= num;
			}
			else {
				difference += num;
			}
		}
		fi.close();

		std::cout << fileCounter << ":  " << abs(difference) << endl;
	}
}