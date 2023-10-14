#include <windows.h>
#include <fstream>
#include <iostream>
#include <vector>

struct RGB {
	unsigned char R;
	unsigned char G;
	unsigned char B;
};

RGB pixels[640][360];

void feladat1() {
	std::ifstream fs{ "kep.txt" };
	int red, green, blue;
	for (int y = 0; y < 360; ++y) {
		for (int x = 0; x < 640; ++x) {
			fs >> red >> green >> blue;
			pixels[x][y].R = red;
			pixels[x][y].G = green;
			pixels[x][y].B = blue;
		}
	}
	fs.close();
}

void feladat2() {
	using namespace std;
	cout << "2. feladat" << endl;

	cout << "Kérem egy képpont adatait!" << endl << "Sor: ";
	int row;
	do {
		cin >> row;
		if (row < 1 || row>360) {
			cout << "1 és 360 közötti számot adj meg! Sor: ";
		}
	} while (row < 1 || row>360);

	cout << "Oszlop: ";
	int column;
	do {
		cin >> column;
		if (column < 1 || column>640) {
			cout << "1 és 640 közötti számot adj meg! Oszlop: ";
		}
	} while (column < 1 || column>640);

	--row;
	--column;

	cout << "A képpont színe RGB(" << (int)pixels[column][row].R << ", "
		<< (int)pixels[column][row].G << ", "
		<< (int)pixels[column][row].B << ")" << endl << endl;
}

void feladat3() {
	using namespace std;
	cout << "3. feladat" << endl;

	int pieces{ 0 };
	for (int x = 0; x < 640; ++x) {
		for (int y = 0; y < 360; ++y) {
			if ((int)pixels[x][y].R + pixels[x][y].G + pixels[x][y].B > 600) {
				++pieces;
			}
		}
	}

	cout << "A világos képpontok száma: " << pieces << endl << endl;
}

void feladat4() {
	using namespace std;
	cout << "4. feladat" << endl;

	int darkest{ INT_MAX };
	std::vector<RGB> darkests{};
	int current;

	for (int x = 0; x < 640; ++x) {
		for (int y = 0; y < 360; ++y) {
			current = (int)pixels[x][y].R + pixels[x][y].G + pixels[x][y].B;
			if (current < darkest) {
				darkests.clear();
				darkest = current;
			}
			if (current == darkest) {
				darkests.emplace_back(pixels[x][y]);
			}
		}
	}

	cout << "A legsötétebb pont RGB összege: " << darkest << endl;
	cout << "A legsötétebb pixelek színe :" << endl;
	for (auto& pixel : darkests) {
		cout << "RGB(" << (int)pixel.R << ", "
			<< (int)pixel.G << ", "
			<< (int)pixel.B << ")" << endl;
	}
	cout << endl;
}

int main() {
	SetConsoleOutputCP(1250);
	feladat1();
	feladat2();
	feladat3();
	feladat4();
	return 0;
}