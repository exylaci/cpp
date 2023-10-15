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
		long maxPieces{ (long)s.length() / 5 + 1 };
		long sLength{ (long)s.length() };
		vector<long> lastPosition{ -1,-1,-1,-1,-1 };
		vector<long> firstPosition{ LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX };

		int have;
		int letter;
		char currentLetter;
		for (int pieces{ 1 }; pieces < maxPieces; ++pieces) {
			have = pieces - 1;
			letter = 0;
			currentLetter = 'V';
			for (long index{ lastPosition.at(letter) + 1 }; index < sLength; ++index) {
				if (s[index] == currentLetter) {
					++have;
					if (have == pieces) {
						lastPosition.at(letter) = index;
						++letter;
						if (letter > 4) {
							resoult = pieces;
							break;
						}
						currentLetter = letters[letter];
						if (lastPosition.at(letter) <= index) {
							lastPosition.at(letter) = index;
							have = 0;
						}
						else {
							have = pieces - 1;
							for (long i{ firstPosition.at(letter) }; i <= index; ++i) {
								if (s[i] == currentLetter) {
									--have;
								}
							}
						}
						firstPosition.at(letter) = index;
					}
				}
			}
			if (resoult < pieces) {
				break;
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