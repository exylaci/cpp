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

int feladat2() {
	using namespace std;
	cout << "2. feladat" << endl;

	cout << "Adjon meg egy távolságértéket! ";
	int distance;
	cin >> distance;

	if (distance < 1 || distance > deeps.size()) {
		cout << "Nem megfelelõ a megadott távolság!" << endl << endl;
	}
	else {
		cout << "Ezen a helyen a felszín " <<
			deeps.at(distance - 1)
			<< " méter mélyen van." << endl << endl;
	}

	return distance;
}

int main() {
	SetConsoleOutputCP(1250);
	feladat1();
	int distance{ feladat2() };
	return 0;
}