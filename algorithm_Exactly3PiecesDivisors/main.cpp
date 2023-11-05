#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

std::vector<long> prims{};

long loadPrims() {
	std::ifstream fi{ "prims.txt" };
	if (!fi.is_open()) {
		std::cout << "Nem nyilt meg." << std::endl;
		return -1;
	}

	prims.reserve(150'000L);
	long one;
	while (fi >> one) {
		prims.emplace_back(one);
	}
	fi.close();
	std::cout << prims.size() << " db prim szam betoltve." << std::endl;

	return prims.size();
}

int main() {
	using namespace std;

	long numberOfPrims{ loadPrims() };
	if (numberOfPrims < 1) {
		cout << "Baj van! Nem tudtam betolteni a prim szamokat." << endl;
		return-1;
	}


	for (char fileCounter = '0'; fileCounter <= '6'; ++fileCounter) {
		string filename("oszto");
		filename += fileCounter;
		filename += ".in.txt";

		ifstream fi{ filename };
		if (!fi.is_open()) {
			cout << "Nem nyilt meg." << endl;
			continue;
		}

		long long from;
		long long till;
		fi >> from >> till;

		long resoult = 0;
		long long negyzet;
		for (long i = 0; i < numberOfPrims; ++i) {
			negyzet = prims.at(i);
			negyzet *= negyzet;
			if (negyzet > till) {
				break;
			}
			if (negyzet >= from) {
				++resoult;
			}
		}
		cout << fileCounter << ": " << resoult << endl;

		if ((long long)prims.at(numberOfPrims - 1) * prims.at(numberOfPrims - 1) < till) {
			cout << " Baj van! Lehet, hogy tobb ilyen szam is van, de ehhez kellenenek nagyobb prim szamok is." << endl;
		}
	}
}