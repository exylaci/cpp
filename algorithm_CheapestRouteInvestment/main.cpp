#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>
#include <list>
#include <algorithm>
#include <vector>

struct Road
{
	int cityA;
	int cityB;
	int cost;
	Road(int cityA, int cityB, int cost) : cityA{ cityA }, cityB{ cityB }, cost{ cost } {}
	bool operator<(const Road& a) const {
		return cost < a.cost;
	}
};

int main() {
	using namespace std;
	for (char fileCounter = '0'; fileCounter <= '5'; ++fileCounter) {
		string filename("utak");
		filename += fileCounter;
		filename += ".in.txt";

		ifstream fi{ filename };
		if (!fi.is_open()) {
			std::cout << filename << "    <--- Nem nyilt meg!" << std::endl;
			continue;
		}
		auto startTime = std::chrono::system_clock::now();

		int cities;
		int piecesOfOffers;
		fi >> cities >> piecesOfOffers;
		cout << fileCounter << ":" << std::setw(6) << cities << std::setw(8) << piecesOfOffers << " -> ";

		std::vector<Road> roads{};
		roads.reserve(piecesOfOffers);
		int cityA;
		int cityB;
		int cost;
		while (fi >> cityA >> cityB >> cost) {
			roads.emplace_back(cityA, cityB, cost);
		}
		fi.close();
		std::sort(roads.begin(), roads.end());

		std::list<std::list<int>> connecteds;
		auto connected1 = connecteds.end();
		auto connected2 = connecteds.end();
		bool aHasRoad = false;
		bool bHasRoad = false;
		long long resoult{ 0 };
		bool* v = new bool[cities];
		for (int index = 0; index < cities; ++index) { v[index] = false; }

		for (const auto& road : roads) {

			aHasRoad = v[road.cityA];
			bHasRoad = v[road.cityB];
			v[road.cityA] = true;
			v[road.cityB] = true;
			if (!aHasRoad && !bHasRoad) {
				std::list<int> temp{};
				temp.emplace_back(road.cityA);
				temp.emplace_back(road.cityB);
				connecteds.emplace_back(temp);
				resoult += road.cost;
				continue;
			}
			connected1 = connecteds.end();
			connected2 = connecteds.end();
			for (auto it = connecteds.begin(); it != connecteds.end(); ++it) {
				if (aHasRoad && connected1 == connecteds.end()) {
					if (std::find((*it).begin(), (*it).end(), road.cityA) != (*it).end()) {
						connected1 = it;
					}
				}
				if (bHasRoad && connected2 == connecteds.end()) {
					if (std::find((*it).begin(), (*it).end(), road.cityB) != (*it).end()) {
						connected2 = it;
					}
				}
				if (!aHasRoad && !bHasRoad || connected1 != connecteds.end() && connected2 != connecteds.end()) {
					break;
				}
			}
			if (!aHasRoad) {
				(*connected2).emplace_back(road.cityA);
				resoult += road.cost;
				continue;
			}
			if (!bHasRoad) {
				(*connected1).emplace_back(road.cityB);
				resoult += road.cost;
				continue;
			}
			if (connected1 != connected2) {
				std::copy((*connected2).begin(), (*connected2).end(), std::back_inserter((*connected1)));
				connecteds.erase(connected2);
				resoult += road.cost;
			}
		}

		std::cout << std::setw(12) << resoult;
		std::cout << "    (futasi ido: " << std::setw(6) << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - startTime).count() << " millisec)" << endl;
		std::cout << endl;
	}
}