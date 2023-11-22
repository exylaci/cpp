#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>
#include <list>

int v[10001][10001]{};

void CleanUp(int& width, int& height) {
	for (int x = 0; x < width; ++x) {
		for (int y = 0; y < height; ++y) {
			v[x][y] = 0;
		}
	}
	for (int x = 0; x < width; ++x) {
		v[x][height] = -2;
	}
	for (int y = 0; y < height; ++y) {
		v[width][y] = -1;
	}
}

int main() {
	using namespace std;

	for (char fileCounter = '0'; fileCounter <= '4'; ++fileCounter) {
		string filename("input_6fordulo_");
		filename += fileCounter;
		filename += "feladat.txt";

		ifstream fi{ filename };
		if (!fi.is_open()) {
			std::cout << filename << "    <--- Nem nyilt meg!" << std::endl;
			continue;
		}
		auto startTime = std::chrono::system_clock::now();

		int width;
		int height;
		int cuts;
		fi >> width >> height >> cuts;
		CleanUp(width, height);

		int ax;
		int ay;
		int bx;
		int by;
		while (fi >> ax >> ay >> bx >> by) {
			if (ax == bx) {
				for (int y = ay; y < by; ++y) {
					--v[ax][y];
				}
			}
			else {
				for (int x = ax; x < bx; ++x) {
					v[x][ay] -= 2;
				}
			}
		}
		fi.close();

		std::list<int> sizes{};
		int size = 1;
		for (int y = 0; y < height; ++y) {
			size = 1;
			for (int x = 0; x < width; ++x) {
				if (v[x + 1][y] == -1 || v[x + 1][y] == -3) {
					v[x][y] = size;
					size = 0;
					if (y > 0) {
						v[x][y] += v[x][y - 1];
					}
					if (v[x][y + 1] < -1) {
						sizes.emplace_back(v[x][y]);
						v[x][y] = 0;
					}
				}
				++size;
			}
		}
		cout << fileCounter << ": I've found " << sizes.size() << " pieces.";

		std::cout << "    (futasi ido: " << std::setw(6) << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - startTime).count() << " millisec)" << endl;
		std::cout << endl;
	}
}