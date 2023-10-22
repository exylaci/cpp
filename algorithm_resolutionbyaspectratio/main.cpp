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

		string temp1, temp2;
		int third, fourth;
		fi >> temp1 >> temp2 >> third >> fourth;
		BigInt first{ temp1 };
		BigInt second{ temp2 };
		fi.close();
		if (third > fourth) {
			BigInt A{ first };
			A /= third;
			cout << A * third << " " << A * fourth << endl;
		}
		else {
			BigInt B{ second };
			B /= fourth;
			cout << B * third << " " << B * fourth << endl;
		}
	}
}