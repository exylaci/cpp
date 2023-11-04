#include <iostream>

int main() {
	long in[]{ 11, 2287 ,-6840 ,587601 ,1000000000 };

	for (auto one : in) {

		one = abs(one);
		int n = sqrt(0.25 + 2 * one) + 1;
		long sum = (n * n + n) / 2;
		long diff = one - sum;

		int x{ 0 };
		int y{ 0 };
		if (diff % 2 == 0) {
			x = (sum - one) / 2;
		}
		else {
			++n;
			sum = (n * n + n) / 2;
			diff = sum - one;
			x = (diff) / 2;
			std::cout << "A(z) " << x << "-t kivonni kell." << std::endl;
			if (n % 2 == 0) {
				++n;
				sum = (n * n + n) / 2;
				diff = sum - (x * 2) - one;
				y = (diff) / 2;
				std::cout << "A(z) " << y << "-t is kivonni kell." << std::endl;
			}
		}
		std::cout << "A lepesek szama: " << n << std::endl;

		std::cout << "Ellenorzes:  az elvart ertek: " << one << std::endl;
		std::cout << "             az elert osszeg: " << sum - 2 * x - 2 * y << std::endl << std::endl;
	}
}