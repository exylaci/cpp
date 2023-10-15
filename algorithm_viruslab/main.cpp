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
		int resoult{ 0 };
		char letters[]{ "VIRUS" };
		for (int pieces{ 1 }; pieces < s.length() / 5; ++pieces) {
			int letter{ 0 };
			int counter{ 0 };
			for (long index{ 0 }; index < s.length(); ++index) {
				if (s[index] == letters[letter]) {
					++counter;
					if (counter == pieces) {
						++letter;
						if (letter > 4) {
							resoult = pieces;
							break;
						}
						counter = 0;
					}
				}
			}
		}

		//saving
		filename = "virus";
		filename += counter;
		filename += ".out.txt";
		cout << filename << " : " << resoult << endl << endl;;

		ofstream fo{ filename };
		fo << resoult;
		fo.close();
	}
}