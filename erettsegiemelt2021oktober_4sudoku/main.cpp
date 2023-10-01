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

int panel[9][9];
int row;
int column;
std::vector<Step> steps;

Step ReadOneStep(std::ifstream* fs);
bool FilledAlready(Step step);
bool RowContains(Step step);
bool ColumnContains(Step step);
bool SubPanelContains(Step step);

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
			//std::cout << " Szám: " << steps.back().number << " pozíció: " <<
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
		std::cout << "Az adott helyen szereplõ szám: " << panel[row - 1][column - 1] << endl;
	}
	else {
		std::cout << "Az adott helyet még nem töltötték ki." << endl;
	}

	std::cout << "A hely a(z) " <<
		1 + (row - 1) / 3 * 3 + (column - 1) / 3
		<< " résztáblázathoz tartozik." << endl << endl;
}

void feladat4() {
	using namespace std;
	cout << "4. feladat" << endl;

	int counter{ 9 * 9 };
	for (int i = 0; i < 9; ++i) {
		for (int cell : panel[i]) {
			if (cell > 0) {
				--counter;
			}
		}
	}
	float percentage{ (float)counter * 100 / (9 * 9) };

	std::cout << "Az üres helyek aránya: " <<
		std::setprecision(1) << std::fixed << percentage << "%" << endl << endl;
}

void feladat5() {
	using namespace std;
	cout << "5. feladat" << endl;
	for (Step step : steps) {
		cout << "A kiválasztott sor: " << step.row
			<< " oszlop: " << step.column
			<< " a szám: " << step.number << endl;
		--step.row;
		--step.column;
		if (FilledAlready(step)) {
			cout << "A helyet már kitöltötték.";
		}
		else if (RowContains(step)) {
			cout << "Az adott sorban már szerepel a szám.";
		}
		else if (ColumnContains(step)) {
			cout << "Az adott oszlopban már szerepel a szám.";
		}
		else if (SubPanelContains(step)) {
			cout << "Az adott résztáblázatban már szerepel a szám.";
		}
		else {
			cout << "A lépés megtehetõ";
		}
		cout << endl << endl;
	}
}

bool FilledAlready(Step step) {
	if (panel[step.row][step.column] > 0) {
		return true;
	}
	return false;
}

bool RowContains(Step step) {
	for (int i = 0; i < 9; ++i) {
		if (panel[step.row][i] == step.number) {
			return true;
		}
	}
	return false;
}

bool ColumnContains(Step step) {
	for (int i = 0; i < 9; ++i) {
		if (panel[i][step.column] == step.number) {
			return true;
		}
	}
	return false;
}

bool SubPanelContains(Step step) {
	for (int i = step.row / 3 * 3; i < (step.row / 3 + 1) * 3; ++i) {
		for (int j = step.column / 3 * 3; j < (step.column / 3 + 1) * 3; ++j) {
			if (panel[i][j] == step.number) {
				return true;
			}
		}
	}
	return false;
}

void feladatBonusz() {
	std::cout << "Bónusz feladat:" << std::endl;
	std::cout << "Azon mezõk kitöltése, ahova már csak egyetlen szám illik be." << std::endl;

	bool findOne;
	do {
		findOne = false;
		Step step;
		for (step.row = 0; step.row < 9; ++step.row) {
			for (step.column = 0; step.column < 9; ++step.column) {
				if (!FilledAlready(step)) {
					int good{ 0 };
					for (step.number = 1; step.number < 10; ++step.number) {
						if (!RowContains(step) && !ColumnContains(step) && !SubPanelContains(step)) {
							if (good != 0) {
								good = 10;
								break;
							}
							good = step.number;
						}
					}
					if (good != 10) {
						panel[step.row][step.column] = good;
						std::cout << "Megtalált helyes szám: " << good << " a(z) " <<
							step.row + 1 << ":" << step.column + 1 << " mezõre." << std::endl;
						findOne = true;
					}
				}
			}
		}
	} while (findOne);
}

int main() {
	SetConsoleOutputCP(1250);
	std::string filename;
	filename = feladat1();
	feladat2(filename);
	feladat3();
	feladat4();
	feladat5();
	feladatBonusz();
	return 0;
}