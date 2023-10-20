#include <string>
#include <iostream>
#include <fstream>
#include <vector>

struct Dino
{
	int weight;
	int length;
};

int main() {
	for (char fileCounter = '0'; fileCounter <= '6'; ++fileCounter) {
		std::string fileName = "dino";
		fileName += fileCounter;
		fileName += ".in.txt";
		std::cout << fileCounter << ": ";

		std::ifstream fi{ fileName };
		if (!fi) {
			std::cout << "Nem nyilt meg!" << std::endl;
			continue;
		}

		std::vector<Dino> dinos{};
		Dino dino{};

		while (fi >> dino.weight >> dino.length) {
			bool wontBeEaten{ true };
			if (dinos.size() > 0) {
				for (auto one : dinos) {
					if (one.weight > dino.weight && one.length > dino.length) {
						wontBeEaten = false;
						break;
					}
				}
				if (wontBeEaten) {
					auto it = dinos.begin();
					auto tempit = it;
					while (it < dinos.end()) {
						if ((*it).weight < dino.weight && (*it).length < dino.length) {
							if (it > dinos.begin()) {
								tempit = it - 1;
								dinos.erase(it);
								it = tempit;
							}
							else {
								dinos.erase(it);
								it = dinos.begin();
							}
						}
						else {
							++it;
						}
					}
					dinos.emplace_back(dino);
				}
			}
			else {
				dinos.emplace_back(dino);
			}

		}

		std::cout << dinos.size() << " dino nem tudja megenni egymast." << std::endl;

		fi.close();
	}
}