#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>
#include <iomanip>

struct Step {
	int number;
	int row;
	int column;
};
Step ReadOneStep(std::ifstream* fs);

int panel[9][9];
int row;
int column;
std::vector<Step> steps;

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

void feladat2(std::string filename) {
	std::ifstream fs{ filename };
	for (int x = 0; x < 9; ++x) {
		for (int y = 0; y < 9; ++y) {
			fs >> panel[x][y];
			//std::cout << " " << panel[x][y];
		}
		//std::cout << std::endl;
	}

	while (!fs.eof()) {
		Step step{ ReadOneStep(&fs) };
		if (step.number > 0) {
			steps.push_back(step);
			//std::cout << " Sz�m: " << steps.back().number << " poz�ci�: " <<
			//	steps.back().row << "x" << steps.back().column << std::endl;
		}
	}

	fs.close();
}

Step ReadOneStep(std::ifstream* fs) {
	Step step{};
	*fs >> step.number;
	*fs >> step.row;
	*fs >> step.column;
	return step;
}

void feladat3() {
	using namespace std;
	cout << endl << "3. feladat" << endl;

	if (panel[row - 1][column - 1] > 0) {
		std::cout << "Az adott helyen szerepl� sz�m: " << panel[row - 1][column - 1] << endl;
	}
	else {
		std::cout << "Az adott helyet m�g nem t�lt�tt�k ki." << endl;
	}

	std::cout << "A hely a(z) " <<
		1 + (row - 1) / 3 * 3 + (column - 1) / 3
		<< " r�szt�bl�zathoz tartozik." << endl;
}

void feladat4() {
	using namespace std;
	cout << endl << "4. feladat" << endl;

	int counter{ 9 * 9 };
	for (int i = 0; i < 9; ++i) {
		for (int cell : panel[i]) {
			if (cell > 0) {
				--counter;
			}
		}
	}
	float percentage{ (float)counter * 100 / (9 * 9) };

	std::cout << "Az �res helyek ar�nya: " <<
		std::setprecision(1) << std::fixed << percentage << "%" << endl;

}

int main() {
	SetConsoleOutputCP(1250);
	std::string filename;
	filename = feladat1();
	feladat2(filename);
	feladat3();
	feladat4();
	return 0;
}