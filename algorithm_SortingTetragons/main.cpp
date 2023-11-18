#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>
#include <list>
#include <algorithm>
#include <vector>
#include "../bigint/bigint.cpp"

struct Point
{
	long long x;
	long long y;
	Point(int x, int y) : x{ x }, y{ y } {}
	bool operator<(const Point& p) const {
		return p.x == x ? y < p.y : x < p.x;
	}
	bool operator>(const Point& p) const {
		return p.x == x ? y > p.y : x > p.x;
	}
	bool operator==(const Point& p) const {
		return p.x == x && p.y == y;
	}
};

struct Tetragon
{
	Point a;
	Point b;
	Point c;
	Point d;
	float ga{};
	float gb{};
	float gc{};
	float gd{};
	Tetragon(Point a, Point b, Point c, Point d) : a{ a }, b{ b }, c{ c }, d{ d } {}
};

bool isDepraved(Tetragon& t) {
	if (t.a == t.b || t.b == t.c || t.c == t.d || t.d == t.a) {
		return true;
	}
	t.ga = t.a.y - t.b.y;
	t.ga /= t.a.x - t.b.x;
	t.gb = t.b.y - t.c.y;
	t.gb /= t.b.x - t.c.x;
	if (t.ga == t.gb) {
		return true;
	}
	t.gc = t.c.y - t.d.y;
	t.gc /= t.c.x - t.d.x;
	if (t.gb == t.gc) {
		return true;
	}
	t.gd = t.d.y - t.a.y;
	t.gd /= t.d.x - t.a.x;
	if (t.gc == t.gd || t.gd == t.ga) {
		return true;
	}
	return false;
}

int main() {
	using namespace std;

	for (char fileCounter = '1'; fileCounter <= '5'; ++fileCounter) {
		string filename("negyszog.pelda");
		filename += fileCounter;
		filename += ".in.txt";

		ifstream fi{ filename };
		if (!fi.is_open()) {
			std::cout << filename << "    <--- Nem nyilt meg!" << std::endl;
			continue;
		}
		auto startTime = std::chrono::system_clock::now();

		Point a{ 0,0 };
		Point b{ 0,0 };
		Point c{ 0,0 };
		Point d{ 0,0 };
		Tetragon t{ a,b,c,d };
		std::string qualifications{};
		while (fi >> t.a.x >> t.a.y >> t.b.x >> t.b.y >> t.c.x >> t.c.y >> t.d.x >> t.d.y) {
			if (isDepraved(t)) {
				qualifications += 'E';
			}
			else {
				qualifications += '.';
			}
		}
		fi.close();

		std::cout << fileCounter << ": " << qualifications;
		std::cout << "    (futasi ido:" << std::setw(7) << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - startTime).count() << " millisec)" << endl;
		std::cout << endl;
	}
}