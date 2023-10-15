#include <iostream>
#include <fstream>
#include <vector>

//correct answers:
//	sample: 1,4
//	1,3,35,379,36842

int main() {
	using namespace std;

	for (char counter = '1'; counter <= '5'; ++counter) {
		//opening
		string filename("virus");
		filename += counter;
		filename += ".in.txt";
		cout << filename << endl;;

		ifstream fi{ filename };
		if (!fi.is_open()) {
			cout << "Nem nyilt meg." << endl;
			continue;
		}
		string s;
		fi >> s;
		fi.close();

		//processing
		int pieces{ 0 };

		//saving
		filename = "virus";
		filename += counter;
		filename += ".out.txt";
		cout << filename << " : " << pieces << endl << endl;;

		ofstream fo{ filename };
		fo << pieces;
		fo.close();
	}
}