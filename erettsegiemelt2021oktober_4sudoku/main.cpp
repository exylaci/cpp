#include <iostream>
#include <windows.h>

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

int main() {
	SetConsoleOutputCP(1250);
	std::string filename;
	filename = feladat1();

	return 0;
}