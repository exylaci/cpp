#include <vector>
#include <windows.h>
#include <fstream>
#include <iostream>

std::vector<int> deeps{};

void feladat1() {
	using namespace std;
	cout << "1. feladat" << endl;

	std::ifstream fs{ "melyseg.txt" };
	int deep;
	while (fs >> deep) {
		deeps.emplace_back(deep);
	}
	fs.close();
	//for (int deep : deeps) cout << deep << " ";

	cout << "A fájl adatainak száma: " << deeps.size() << endl << endl;
}

int main() {
	SetConsoleOutputCP(1250);
	feladat1();
	return 0;
}