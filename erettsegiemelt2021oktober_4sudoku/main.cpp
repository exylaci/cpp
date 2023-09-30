#include <iostream>
#include <windows.h>
#include <fstream>

int panel[9][9];
int row;
int column;

std::string feladat1() {
	using namespace std;
	cout << "1. feladat" << endl;

	std::cout << "Adja meg a bemeneti fájl nevét! ";
	string filename;
	cin >> filename;

	do {
		cout << "Adja meg egy sor számát! ";
		cin >> row;
		if (row < 1 || row > 9) {
			cout << "1 és 9 közötti számot adjon meg!" << endl;
		}
	} while (row < 1 || row > 9);

	do {
		cout << "Adja meg egy oszlop számát! ";
		cin >> column;
		if (column < 1 || column > 9) {
			cout << "1 és 9 közötti számot adjon meg!" << endl;
		}
	} while (column < 1 || column > 9);

	return filename;
}

void feladat2(std::string filename) {
	std::ifstream fs{ filename };
	for (int x = 0; x < 9; ++x) {
		for (int y = 0; y < 9; ++y) {
			fs >> panel[x][y];
			std::cout << " " << panel[x][y];
		}
		std::cout << std::endl;
	}
	fs.close();
}


int main() {
	SetConsoleOutputCP(1250);
	std::string filename;
	filename = feladat1();

	feladat2(filename);

	return 0;
}