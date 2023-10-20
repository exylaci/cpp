#include <string>
#include <iostream>
#include <fstream>
#include <unordered_set>

int main() {
	using namespace std;
	for (char fileCounter = '1'; fileCounter <= '4'; ++fileCounter) {

		string filename("feladat.txt");
		filename = fileCounter + filename;
		cout << "Az " << filename << " fajlban ";

		ifstream fi{ filename };
		if (!fi.is_open()) {
			cout << "Nem nyilt meg." << endl;
			continue;
		}

		int number;
		fi >> number;

		std::unordered_set <int> temp{};
		std::unordered_set <int> finds{};

		int size{ 1 };
		while (fi >> number) {
			temp.emplace(number);
			if (size == temp.size()) {
				finds.emplace(number);
			}
			else { ++size; }
		}

		fi.close();
		
		std::cout << finds.size() << " fele ismetlodo szam van." << std::endl;
		
		temp.clear();
		finds.clear();
	}
}