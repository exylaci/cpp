#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>
#include <limits>

struct Point
{
	long long x;
	long long y;
	Point(long long x, long long y) : x{ x }, y{ y } {}
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
	Point a;		//coordinates
	Point b;
	Point c;
	Point d;
	double ga{};	//gradients
	double gb{};
	double gc{};
	double gd{};
	double gap{};	//perpendicular gradient
	double gbp{};
	double gcp{};
	double gdp{};
	double la{};	//lengths
	double lb{};
	double lc{};
	double ld{};
	Tetragon(Point a, Point b, Point c, Point d) : a{ a }, b{ b }, c{ c }, d{ d } {}
};

bool isDepraved(Tetragon& t) {
	if (t.a == t.b || t.b == t.c || t.c == t.d || t.d == t.a) {
		return true;
	}
	t.ga = t.a.y - t.b.y;
	t.ga /= t.a.x - t.b.x;
	if (t.ga > -std::numeric_limits<double>::min() && t.ga < std::numeric_limits<double>::min()) {
		t.ga = 0;
	}
	if (t.ga == -std::numeric_limits<double>::infinity()) {
		t.ga = -t.ga;
	}
	t.gb = t.b.y - t.c.y;
	t.gb /= t.b.x - t.c.x;
	if (t.gb > -std::numeric_limits<double>::min() && t.gb < std::numeric_limits<double>::min()) {
		t.gb = 0;
	}
	if (t.gb == -std::numeric_limits<double>::infinity()) {
		t.gb = -t.gb;
	}
	if (t.ga == t.gb) {
		return true;
	}
	t.gc = t.c.y - t.d.y;
	t.gc /= t.c.x - t.d.x;
	if (t.gc > -std::numeric_limits<double>::min() && t.gc < std::numeric_limits<double>::min()) {
		t.gc = 0;
	}
	if (t.gc == -std::numeric_limits<double>::infinity()) {
		t.gc = -t.gc;
	}
	if (t.gb == t.gc) {
		return true;
	}
	t.gd = t.d.y - t.a.y;
	t.gd /= t.d.x - t.a.x;
	if (t.gd > -std::numeric_limits<double>::min() && t.gd < std::numeric_limits<double>::min()) {
		t.gd = 0;
	}
	if (t.gd == -std::numeric_limits<double>::infinity()) {
		t.gd = -t.gd;
	}
	if (t.gc == t.gd || t.gd == t.ga) {
		return true;
	}
	return false;
}

bool isSelfcutting(Tetragon& t) {
	return false;
}

bool isSquare(Tetragon& t) {
	if (t.ga != t.gc || t.gb != t.gd) {
		return false;
	}
	t.gbp = t.c.x - t.b.x;
	t.gbp /= t.b.y - t.c.y;
	if (t.gbp > -std::numeric_limits<double>::min() && t.gbp < std::numeric_limits<double>::min()) {
		t.gbp = 0;
	}
	if (t.gbp == -std::numeric_limits<double>::infinity()) {
		t.gbp = -t.gbp;
	}
	if (t.ga != t.gbp) {
		return false;
	}

	t.la = hypot(abs(t.a.x - t.b.x), abs(t.a.y - t.b.y));
	t.lb = hypot(abs(t.b.x - t.c.x), abs(t.b.y - t.c.y));
	return t.la == t.lb;
}

bool isRectangular(Tetragon& t) {
	return t.ga == t.gc && t.gb == t.gd && t.ga == t.gbp;
}

bool isRhombus(Tetragon& t) {
	t.la = hypot(abs(t.a.x - t.b.x), abs(t.a.y - t.b.y));
	t.lb = hypot(abs(t.b.x - t.c.x), abs(t.b.y - t.c.y));
	if (t.la != t.lb) {
		return false;
	}
	t.lc = sqrt(pow(t.c.x - t.d.x, 2) + pow(t.c.y - t.d.y, 2));
	if (t.la != t.lc) {
		return false;
	}
	t.ld = hypot(abs(t.d.x - t.a.x), abs(t.d.y - t.a.y));
	return t.la == t.ld;
}

bool isParallelogram(Tetragon& t) {
	return t.ga == t.gc && t.gb == t.gd;
	}

bool isTrapeze(Tetragon& t) {
	return t.ga == t.gc || t.gb == t.gd;
}

bool isDeltoid(Tetragon& t) {
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
			else if (isSelfcutting(t)) {
				qualifications += 'M';
			}
			else if (isSquare(t)) {
				qualifications += 'N';
			}
			else if (isRectangular(t)) {
				qualifications += 'T';
			}
			else if (isRhombus(t)) {
				qualifications += 'R';
			}
			else if (isParallelogram(t)) {
				qualifications += 'P';
			}
			else if (isTrapeze(t)) {
				qualifications += 'Z';
			}
			else if (isDeltoid(t)) {
				qualifications += 'D';
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
	return 0;
}