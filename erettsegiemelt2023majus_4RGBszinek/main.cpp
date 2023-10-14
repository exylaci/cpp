#include <windows.h>
#include <fstream>
#include <iostream>

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

int main() {
	SetConsoleOutputCP(1250);
	feladat1();
	return 0;
}