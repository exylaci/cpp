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

	cout << "Adja meg egy sor sz�m�t! ";
	cin >> row;
	cout << "Adja meg egy oszlop sz�m�t! ";
	cin >> column;
	return filename;
}

int main() {
	SetConsoleOutputCP(1250);
	std::string filename;
	filename = feladat1();

	return 0;
}