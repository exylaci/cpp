#include <vector>
#include <windows.h>
#include <fstream>
#include <iostream>
#include <iomanip>

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

void feladat3() {
	using namespace std;
	cout << "3. feladat" << endl;

	int pieces{ 0 };
	for (auto deep : deeps) {
		if (deep == 0) { ++pieces; }
	}

	cout << "Az érintetlen terület aránya " <<
		std::setprecision(2) << std::fixed <<
		((float)pieces) * 100 / deeps.size() << "%."
		<< endl << endl;
}

void feladat4() {
	bool newline{ false };

	std::ofstream fs{ "godrok.txt" };
	for (auto deep : deeps) {
		if (deep == 0 && newline) {
			fs << std::endl;
			newline = false;
		}
		if (deep != 0) {
			if (newline) {
				fs << " ";
			}
			fs << deep;
			newline = true;
		}
	}
	fs.close();
}

void feladat5() {
	using namespace std;
	cout << "5. feladat" << endl;

	bool newpit{ true };
	int pieces{ 0 };

	for (auto deep : deeps) {
		if (deep != 0 && newpit) {
			++pieces;
			newpit = false;
		}
		if (deep == 0) {
			newpit = true;
		}
	}

	cout << "A gödrök száma: " << pieces << endl << endl;
}


int main() {
	SetConsoleOutputCP(1250);
	feladat1();
	int distance{ feladat2() };
	feladat3();
	feladat4();
	feladat5();
	return 0;
}