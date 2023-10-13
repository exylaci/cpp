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
	for (const auto& deep : deeps) {
		if (deep == 0) { ++pieces; }
	}

	//#include <algorithm>
	//pieces = 0;
	//std::for_each(deeps.begin(), deeps.end(),
	//	[&pieces](int deep) {if (deep == 0) { ++pieces; } });

	cout << "Az �rintetlen ter�let ar�nya " <<
		std::setprecision(2) << std::fixed <<
		((float)pieces) * 100 / deeps.size() << "%."
		<< endl << endl;
}

void feladat4() {
	bool newline{ false };

	std::ofstream fs{ "godrok.txt" };
	for (const auto& deep : deeps) {
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

	for (const auto deep : deeps) {
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

void feladat6(int distance) {
	using namespace std;
	cout << "6. feladat" << endl;

	if (deeps.at(distance - 1) == 0) {
		cout << "Az adott helyen nincs g�d�r." << endl << endl;
		return;
	}

	int first{ distance - 1 };
	while (first > 0 && deeps.at(first - 1) > 0) {
		--first;
	}
	cout << "a)" << endl;
	cout << "A g�d�r kezdete: " << first + 1 << " m�ter, ";

	int last{ distance - 1 };
	int size{ (int)deeps.size() - 1 };
	while (last < size && deeps.at(last + 1) > 0) {
		++last;
	}
	cout << "a g�d�r v�ge: " << last + 1 << " m�ter." << endl;

	enum DIRECTION { DOWN, UP, NONMONOTIC };
	DIRECTION direction{ DOWN };
	int maxDeep{ 0 };
	int totalDeep{ 0 };
	int safeTotalDeep{ 0 };

	for (int position = first; position <= last; ++position) {
		if (first > 0 && direction == DOWN && deeps.at(position - 1) < deeps.at(position)) {
			direction = UP;
		}
		if (first > 0 && direction == UP && deeps.at(position - 1) > deeps.at(position)) {
			direction = NONMONOTIC;
		}
		maxDeep = max(maxDeep, deeps.at(position));
		totalDeep += deeps.at(position);
		safeTotalDeep += deeps.at(position) - 1;
	}

	cout << "b)" << endl;
	if (direction == NONMONOTIC) {
		cout << "Nem m�ly�l folyamatosan." << endl;
	}
	else {
		cout << "Folyamatosan m�ly�l." << endl;
	}

	cout << "c)" << endl << "A legnagyobb m�lys�ge " <<
		maxDeep << " m�ter." << endl;

	cout << "d)" << endl << "A t�rfogata " <<
		totalDeep * 10 << " m^3." << endl;

	cout << "e)" << endl << "A v�zmennyis�g " <<
		safeTotalDeep * 10 << " m^3." << endl << endl;
}

int main() {
	SetConsoleOutputCP(1250);
	feladat1();
	int distance{ feladat2() };
	feladat3();
	feladat4();
	feladat5();
	feladat6(distance);
	return 0;
}