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

int main() {
	SetConsoleOutputCP(1250);
	feladat1();
	int distance{ feladat2() };
	return 0;
}