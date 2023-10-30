#include <iostream>
#include <vector>
//#include "wall_demolish_testinputs.cpp.inc"
#include "wall_demolish_inputs.cpp.inc"

int findPathWithBruteForce(TestCase one, int cost) {
	int labirinth[60][60];
	for (int y = 0; y < one.rows; ++y) {
		for (int x = 0; x < one.cols; ++x) {
			labirinth[x][y] = 50000;
		}
	}
	labirinth[0][0] = 0;
	int round = 0;
	do {
		for (int x = 0; x < one.cols; ++x) {
			for (int y = 0; y < one.rows; ++y) {
				if (x > 0) {
					labirinth[x][y] = std::min(labirinth[x][y], labirinth[x - 1][y] + 2 + cost * one.field.at(y).at(x));
				}
				if (y > 0) {
					labirinth[x][y] = std::min(labirinth[x][y], labirinth[x][y - 1] + 2 + cost * one.field.at(y).at(x));
				}
				if (x < one.cols - 1) {
					labirinth[x][y] = std::min(labirinth[x][y], labirinth[x + 1][y] + 2 + cost * one.field.at(y).at(x));
				}
				if (y < one.rows - 1) {
					labirinth[x][y] = std::min(labirinth[x][y], labirinth[x][y + 1] + 2 + cost * one.field.at(y).at(x));
				}
			}
		}
		++round;
	} while (round < 1000);
	return labirinth[one.cols - 1][one.rows - 1];
}

// full copy of the test case so it can be modified locally
int task1(TestCase test_case) {
	// TODO: Task 1 code here
	int routeLength{ findPathWithBruteForce(test_case,10001) };
	if (routeLength > 10000) {
		return -1;
	}
	return routeLength / 2;
}

int task2(TestCase test_case) {
	// TODO: Task 2 code here
	int routeLength{ findPathWithBruteForce(test_case,10001) };
	if (routeLength < 10000) {
		return routeLength / 2;
	}
	if (routeLength < 20000) {
		return (routeLength - 10001) / 2;
	}
	return -1;
}

int task3(TestCase test_case) {
	// TODO: Task 3 code here
	int routeLength{ findPathWithBruteForce(test_case,1) };
	return routeLength;
}

int main()
{
	std::cout << "Solution for Task 1:" << std::endl;
	for (TestCase& test_case : test_cases) {
		std::cout << task1(test_case) << " ";
	}
	std::cout << std::endl;
	std::cout << "Solution for Task 2:" << std::endl;
	for (TestCase& test_case : test_cases) {
		std::cout << task2(test_case) << " ";
	}
	std::cout << std::endl;
	std::cout << "Solution for Task 3:" << std::endl;
	for (TestCase& test_case : test_cases) {
		std::cout << task3(test_case) << " ";
	}
	std::cout << std::endl;
	return 0;
}