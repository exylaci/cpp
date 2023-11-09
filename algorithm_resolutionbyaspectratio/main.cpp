#include <string>
#include <iostream>
#include <fstream>
#include "../bigint/bigint.cpp"

int main() {
	using namespace std;
	for (char fileCounter = '0'; fileCounter <= '6'; ++fileCounter) {
		string filename("input_2fordulo_");
		filename += fileCounter;
		filename += "feladat.txt";
		cout << endl << filename << ": ";
		ifstream fi{ filename };
		if (!fi.is_open()) {
			cout << "Nem nyilt meg." << endl;
			continue;
		}

		long long temp1, temp2, temp3, temp4;
		fi >> temp1 >> temp2 >> temp3 >> temp4;
		fi.close();

		long long first = max(temp1, temp2);
		long long second = min(temp1, temp2);
		long long third = max(temp3, temp4);
		long long fourth = min(temp3, temp4);

		long long ratio = min(first / third, second / fourth);
		long long x = ratio * third;
		long long y = ratio * fourth;

		for (long long i = x; i <= first; ++i) {
			double newy = (double)(i) / third * fourth;
			//cout << aspect << " ";
			if (newy == floor(newy) && newy <= second) {
				x = i;
				y = newy;
			}
		}

		cout << x << " " << y << endl;
	}
}