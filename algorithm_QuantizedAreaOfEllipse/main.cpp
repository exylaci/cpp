#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

int main() {
	for (char fileCounter{ '1' }; fileCounter <= '5'; ++fileCounter) {
		std::string fileName{ "parcella" };
		fileName += fileCounter;
		std::ifstream fi{ fileName + ".in.txt" };
		if (!fi) {
			std::cout << fileCounter << ": Baj van! Nem nyilt meg." << std::endl;
			continue;
		}

		double cx;
		double cy;
		double a;
		double b;
		fi >> cx >> cy >> a >> b;
		fi.close();

		double pieces{ 0 };
		//run along the x axis in the middle of every parcell
		for (double x{ -a + 0.5 }; x <= a - 0.5; ++x) {
			//Considering that, we need only the area, the offset from the origo can be left out. The
			//rearanged equation is: y= +- sqrt(  ( 1-(x/a)^2 )*b )
			double y = std::sqrt((1.0 - x * x / a / a) * b * b);

			//the positive and the negative results are also count so it has to be multiplied by 2
			pieces +=  2 * floor(y + 0.5);
		}

		std::cout << fileCounter << ": " << std::setprecision(20) << pieces << std::endl;
	}
}