#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>
#include <limits>

//coordinates
struct Point
{
	double x;
	double y;

	Point operator-(const Point& p) const {
		return Point{ x - p.x , y - p.y };
	}

	bool operator==(const Point& p) const {
		return p.x == x && p.y == y;
	}
};

//gradients of two sides are equal
bool isParalel(const Point a, const Point b) {
	return (double)a.y * b.x == (double)a.x * b.y;
}

//gradients of two sides are 1/-x
bool isPerpendicular(const Point a, const Point b) {
	return (double)a.y * b.y == -(double)a.x * b.x;
}

//length^2 of a side
double diagonPow2(const Point a) {
	//by Pythegoras but without squareroot because we only want to compare two of them
	return (double)a.x * a.x + (double)a.y * a.y;
}

//1 or -1 depending we turn on the right or left at the peak
int direction(Point b, Point d) {
	if (d.y == 0) {
		return ((d.x < 0) && (b.y < 0)) || ((d.x > 0) && (b.y > 0)) ? 1 : -1;
	}
	if (d.x == 0) {
		return ((d.y < 0) && (b.x > 0)) || ((d.y > 0) && (b.x < 0)) ? 1 : -1;
	}
	double by2 = (double)b.x * d.y / d.x;
	return ((d.x < 0) && (b.y < by2)) || ((d.x > 0) && (b.y > by2)) ? 1 : -1;
}

//Contains 4 peaks of the tetragon
struct Tetragon
{
	Point a;	//coordinates of peaks
	Point b;
	Point c;
	Point d;
	Tetragon(Point a, Point b, Point c, Point d) : a{ a }, b{ b }, c{ c }, d{ d } {}

	//any two peaks have the same coordinates
	bool isDepraved() const {
		if (a == b || a == c || a == d || b == c || b == d || c == d) {
			return true;
		}
		return isParalel(b - a, c - b)
			|| isParalel(c - b, d - c)
			|| isParalel(d - c, a - d)
			|| isParalel(a - d, b - a);
	}

	//selfcutting if we turn two times right and two times left at the peaks
	bool isSelfcutting() {
		int turns{ 0 };
		turns += direction(d - a, b - a);
		turns += direction(a - b, c - b);
		turns += direction(b - c, d - c);
		turns += direction(c - d, a - d);
		return turns == 0;
	}

	//two times two paralel side and only one perpendicular side pair is enough
	//the other perpendiculars are obvious
	//and also 2 side have the same length is enoug the rest are also obvious
	bool isSquare() const {
		double aside = diagonPow2(a - b);
		double bside = diagonPow2(b - c);

		return isParalel(b - a, c - d)
			&& isParalel(c - b, d - a)
			&& (isPerpendicular(b - a, c - b) || isPerpendicular(b - a, b - c))
			&& (aside == bside);
	}

	//two times two paralel side and one perpendicular side pair is also enough
	bool isRectangular() const {
		return isParalel(b - a, c - d)
			&& isParalel(c - b, d - a)
			&& (isPerpendicular(b - a, c - b) || isPerpendicular(b - a, b - c));
	}

	//all sides have the same length
	bool isRhombus() {
		double aside = diagonPow2(a - b);
		double bside = diagonPow2(b - c);
		double cside = diagonPow2(c - d);
		double dside = diagonPow2(d - a);

		return (aside == bside) && (aside == cside) && (aside == dside);
	}

	//two times two paralel side
	//the two times to equal side lenths could also good, but it takes longer time to calculate that one
	bool isParallelogram() const {
		return isParalel(b - a, c - d)
			&& isParalel(c - b, d - a);
	}

	//one times two paralel side is enough
	bool isTrapeze() const {
		return isParalel(b - a, c - d)
			|| isParalel(c - b, d - a);
	}

	//two times two neighbouring sides have the same lengths
	bool isDeltoid() {
		double aside = diagonPow2(a - b);
		double bside = diagonPow2(b - c);
		double cside = diagonPow2(c - d);
		double dside = diagonPow2(d - a);

		return ((aside == bside) && (cside == dside))
			|| ((bside == cside) && (dside == aside));
	}

	char Qualification() {
		if (isDepraved()) {
			return 'E';
		}
		if (isSelfcutting()) {
			return 'M';
		}
		if (isSquare()) {
			return 'N';
		}
		if (isRectangular()) {
			return 'T';
		}
		if (isRhombus()) {
			return 'R';
		}
		if (isParallelogram()) {
			return 'P';
		}
		if (isTrapeze()) {
			return 'Z';
		}
		if (isDeltoid()) {
			return 'D';
		}
		return 'L';
	}
};

int main() {
	using namespace std;

	for (char fileCounter = '1'; fileCounter <= '5'; ++fileCounter) {
		std::string filename("negyszog");
		filename += fileCounter;
		filename += ".in.txt";

		std::ifstream fi{ filename };
		if (!fi.is_open()) {
			std::cout << filename << "    <--- Nem nyilt meg!" << std::endl;
			continue;
		}
		auto startTime = std::chrono::system_clock::now();

		Point a{};
		Point b{};
		Point c{};
		Point d{};
		Tetragon t{ a,b,c,d };
		std::string qualifications{};
		while (fi >> t.a.x >> t.a.y >> t.b.x >> t.b.y >> t.c.x >> t.c.y >> t.d.x >> t.d.y) {
			qualifications += t.Qualification();
		}
		fi.close();

		filename = "negyszog";
		filename += fileCounter;
		filename += ".out.txt";
		std::ofstream fs{ filename };
		if (fs) {
			fs << qualifications;
			fs.close();
		}

		std::cout << fileCounter << ": " << std::hash<std::string>{}(qualifications);
		std::cout << " (futasi ido:" << std::setw(7) << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - startTime).count() << " millisec)" << endl;
		std::cout << endl;
	}
	return 0;
}