#include <iostream>
#include <windows.h>

int panel[9][9];
int row;
int column;

std::string feladat1() {
	using namespace std;
	cout << "1. feladat" << endl;

	std::cout << "Adja meg a bemeneti f�jl nev�t! ";
	string filename;
	cin >> filename;

	do {
		cout << "Adja meg egy sor sz�m�t! ";
		cin >> row;
		if (row < 1 || row > 9) {
			cout << "1 �s 9 k�z�tti sz�mot adjon meg!" << endl;
		}
	} while (row < 1 || row > 9);

	do {
		cout << "Adja meg egy oszlop sz�m�t! ";
		cin >> column;
		if (column < 1 || column > 9) {
			cout << "1 �s 9 k�z�tti sz�mot adjon meg!" << endl;
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