#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>
#include <list>
#include <numeric>

int** ReserveArray(int& width, int& height) {
	int** v = new int* [width + 1];
	for (int i = 0; i <= width; ++i) {
		int* p = new int[height + 1];
		v[i] = p;
	}
	return v;
}

void ReleaseArray(int& width, int** v) {
	for (int i = 0; i <= width; ++i) {
		delete[] v[i];
	}
	delete[] v;
}

void CleanUp(int& width, int& height, int** v) {
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
		auto v = ReserveArray(width, height);
		CleanUp(width, height, v);

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
		ReleaseArray(width, v);

		long long sum{ std::accumulate(sizes.begin(),sizes.end(),0) };
		double average = (double)sum / sizes.size();
		double variance{ 0 };
		for (const auto& oneSize : sizes) {
			variance += pow((double)oneSize - average, 2);
		}
		variance /= sizes.size();
		double deviation = sqrt(variance);

		std::cout << "Bemenet: " << fileCounter << "-ben a" << std::setw(5)
			<< sizes.size() << " darab teglalap teruleteinek szorasa:"
			<< std::setw(10) << std::fixed << std::setprecision(2) << deviation;
		std::cout << "    (futasi ido:" << std::setw(5) << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - startTime).count() << " millisec)" << endl;
		std::cout << endl;
	}
}