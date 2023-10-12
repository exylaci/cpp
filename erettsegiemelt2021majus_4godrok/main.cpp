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

	cout << "A f�jl adatainak sz�ma: " << deeps.size() << endl << endl;
}

int feladat2() {
	using namespace std;
	cout << "2. feladat" << endl;

	cout << "Adjon meg egy t�vols�g�rt�ket! ";
	int distance;
	cin >> distance;

	if (distance < 1 || distance > deeps.size()) {
		cout << "Nem megfelel� a megadott t�vols�g!" << endl << endl;
	}
	else {
		cout << "Ezen a helyen a felsz�n " <<
			deeps.at(distance - 1)
			<< " m�ter m�lyen van." << endl << endl;
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

	cout << "Az �rintetlen ter�let ar�nya " <<
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

	cout << "A g�dr�k sz�ma: " << pieces << endl << endl;
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