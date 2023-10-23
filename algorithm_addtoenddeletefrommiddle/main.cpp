#include <string>
#include <iostream>
#include <fstream>
#include "../bigint/bigint.cpp"
#include <list>

int main() {
	using namespace std;
	for (char fileCounter = '0'; fileCounter <= '6'; ++fileCounter) {
		string filename("adat");
		filename += fileCounter;
		filename += ".in.txt";
		std::cout << filename << ": ";

		ifstream fi{ filename };
		if (!fi.is_open()) {
			std::cout << "Nem nyilt meg." << endl;
			continue;
		}

		BigInt sum{ "0" };
		list<string> numbers{};
		long index{ 0 };
		auto it = numbers.begin();
		auto tmpit = numbers.begin();
		std::string s;
		long torlendo;

		while (fi >> s) {
			if (s == "p") {
				if (numbers.size() > 0) {
					torlendo = (numbers.size()) / 2;
					while (index < torlendo) {
						++it;
						++index;
					}
					sum += BigInt(*it);
					tmpit = it;
					if (index > 0) {
						--index;
						--it;
					}
					numbers.erase(tmpit);
				}
			}
			else {
				numbers.emplace_back(s);
				if (numbers.size() == 1) {
					index = 0;
					it = numbers.begin();
				}
			}
		}
		fi.close();
		std::cout << sum << endl;
	}
}