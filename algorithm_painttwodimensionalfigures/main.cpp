#include "field_10_by_10.cpp.inc"
//#include "field_80_by_25.cpp.inc"
//#include "field_1024_by_768.cpp.inc"
#include <iostream>
#include <vector>

std::vector<size_t> pendings{};

void PrintOut() {
	using namespace std;
	for (size_t index = 0; index < N; ++index) {
		if (index % XS == 0) {
			cout << endl;
		}
		cout << field[index];
	}
	cout << endl;
}

bool analisys(size_t index) {
	bool hasneighbour{ false };
	if (index % XS > 0 && field[index - 1] == 1) {
		pendings.emplace_back(index - 1);
		hasneighbour = true;
	}
	if (index > XS && field[index - XS] == 1) {
		pendings.emplace_back(index - XS);
		hasneighbour = true;
	}
	if ((index + 1) % XS != 0 && field[index + 1] == 1) {
		pendings.emplace_back(index + 1);
		hasneighbour = true;
	}
	if (index + XS < N && field[index + XS] == 1) {
		pendings.emplace_back(index + XS);
		hasneighbour = true;
	}
	return hasneighbour;
}

void main() {
	PrintOut();
	int counter{ 0 };
	for (size_t index = 0; index < N; ++index) {
		bool hasneighbour{ false };
		if (field[index] == 1) {
			hasneighbour = analisys(index);
			if (hasneighbour) {
				++counter;
				field[index] = 2;
				while (pendings.size() > 0) {
					size_t temp = pendings.at(pendings.size() - 1);
					pendings.pop_back();
					field[temp] = 2;
					analisys(temp);
				}
			}
		}
	}
	PrintOut();
	std::cout << std::endl << "Az erdok szama: " << counter;
}