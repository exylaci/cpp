#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>
#include <list>
#include <numeric>

std::string SetFileName(char fileCounter) {
	std::string filename("input_6fordulo_");
	filename += fileCounter;
	filename += "feladat.txt";
	return filename;
}

//Allocating memory in heap for the 2D array
int** AllocateArray(int& width, int& height) {
	//one-one unit bigger array for simplier if conditions
	int** v = new int* [width + 1];
	for (int i = 0; i <= width; ++i) {
		int* p = new int[height + 1];
		v[i] = p;
	}
	return v;
}

//Rellease the allocated memory of the array
void ReleaseArray(int& width, int** v) {
	for (int i = 0; i <= width; ++i) {
		delete[] v[i];
	}
	delete[] v;
}

void CleanUp(int& width, int& height, int** v) {
	//Fill up with zeros the array
	for (int x = 0; x < width; ++x) {
		for (int y = 0; y < height; ++y) {
			v[x][y] = 0;
		}
	}

	//registering a vertical cutting on right edge
	for (int x = 0; x < width; ++x) {
		v[x][height] = -2;
	}

	//registering a horizontal cutting on bottom edge
	for (int y = 0; y < height; ++y) {
		v[width][y] = -1;
	}
}

int RegisterCuttings(std::ifstream& fi, int** v) {
	int ax;
	int ay;
	int bx;
	int by;
	int cut{ 0 };
	while (fi >> ax >> ay >> bx >> by) {
		if (ax == bx) {
			//registing this vertical cutting
			for (int y = ay; y < by; ++y) {
				--v[ax][y];
			}
		}
		else {
			//registing this horizontal cutting
			for (int x = ax; x < bx; ++x) {
				v[x][ay] -= 2;
			}
		}
		++cut;
	}
	return cut;
}

std::list<int> CollectPieces(int width, int height, int** v) {
	//for collecting the sizes of the pieces
	std::list<int> sizes{};

	//iterate horizontally and vertically along each unit parts of the panel
	int size = 1;
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			if (v[x + 1][y] == -1 || v[x + 1][y] == -3) {
				//right end of this piece reached -> store the width of this pieces
				v[x][y] = size;
				size = 1;

				if (y > 0 && v[x][y - 1] > 0) {
					//add the width of the above unit parts lines to this line's width,
					//but only if a valid (higer than 0) number is there
					//because the negative numbers indicate the cuttings
					v[x][y] += v[x][y - 1];
				}

				if (v[x][y + 1] < -1) {
					//it is the bottom line of this pieces
					//-> storing the size of this piece
					sizes.emplace_back(v[x][y]);
					v[x][y] = 0;
				}
			}
			else {
				++size;
			}
		}
	}
	return sizes;
}

double CalculateDeviation(double totalSize, std::list<int> sizes) {
	// = sqrt( average( (SizeOfOnePiece-AverageSize)^2 ) )
	double average = totalSize / sizes.size();

	double variance{ 0 };
	for (const auto& oneSize : sizes) {
		variance += pow((double)oneSize - average, 2);
	}
	variance /= sizes.size();

	return sqrt(variance);
}

int main() {
	for (char fileCounter = '0'; fileCounter <= '4'; ++fileCounter) {
		std::ifstream fi{ SetFileName(fileCounter) };
		if (!fi.is_open()) {
			std::cout << fileCounter << ": Baj van! Nem nyilt meg." << std::endl;
			continue;
		}
		auto startTime = std::chrono::system_clock::now();

		int width;
		int height;
		int cuts;
		fi >> width >> height >> cuts;

		auto v = AllocateArray(width, height);
		CleanUp(width, height, v);

		auto registeredCuts{ RegisterCuttings(fi, v) };
		if (registeredCuts != cuts) {
			std::cout << fileCounter << ": Baj van! " << cuts << " helyett, "
				<< registeredCuts << " darab sort tudtam beolvasni." << std::endl;
			ReleaseArray(width, v);
			continue;
		}
		fi.close();

		auto sizes = CollectPieces(width, height, v);
		ReleaseArray(width, v);
		if (sizes.size() != cuts + 1) {
			std::cout << fileCounter << ": Baj van! " << sizes.size()
				<< " darabot talaltam meg." << std::endl;
			continue;
		}

		long long totalSize{ std::accumulate(sizes.begin(),sizes.end(),0) };
		if (totalSize != ((double)width) * height) {
			std::cout << fileCounter << ": Baj van! " << totalSize
				<< " lett a szumma terule a daraboknak." << std::endl;
			continue;
		}
		double deviation{ CalculateDeviation(totalSize,sizes) };

		std::cout << fileCounter << ": a keletkezett teglalapok teruleteinek szorasa:"
			<< std::setw(10) << std::fixed << std::setprecision(2) << deviation;
		std::cout << "    (futasi ido:" << std::setw(6) << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - startTime).count() << " millisec)";
		std::cout << std::endl;
	}
}