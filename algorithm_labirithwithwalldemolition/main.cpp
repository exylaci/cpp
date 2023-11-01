#include <iostream>
#include <vector>
//#include "wall_demolish_testinputs.cpp.inc"
#include "wall_demolish_inputs.cpp.inc"

struct Junction {
	int x;
	int y;
	Junction(int x, int y) : x{ x }, y{ y } {}
};
int findPathStepToward(TestCase one, int cost) {
	int labirinth[60][60];
	for (int y = 0; y < one.rows; ++y) {
		for (int x = 0; x < one.cols; ++x) {
			labirinth[x][y] = 50000;
		}
	}
	labirinth[0][0] = 0;

	std::vector<Junction> junctions{};
	junctions.emplace_back(0, 1);
	junctions.emplace_back(1, 0);
	int x;
	int y;
	bool storedup;
	bool storedleft;
	bool storedright;
	bool storeddown;
	do {
		x = junctions.at(junctions.size() - 1).x;;
		y = junctions.at(junctions.size() - 1).y;;
		junctions.pop_back();
		storedup = false;
		storedleft = false;
		storedright = false;
		storeddown = false;
		if (x > 0) {
			if (labirinth[x][y] > labirinth[x - 1][y] + 2 + cost * one.field.at(y).at(x)) {
				labirinth[x][y] = labirinth[x - 1][y] + 2 + cost * one.field.at(y).at(x);
				if (x < one.cols - 1) {
					junctions.emplace_back(x + 1, y);
					storedright = true;
				}
				if (y > 0) {
					junctions.emplace_back(x, y - 1);
					storedup = true;
				}
				if (y < one.rows - 1) {
					junctions.emplace_back(x, y + 1);
					storeddown = true;
				}
			}
		}
		if (x < one.cols - 1) {
			if (labirinth[x][y] > labirinth[x + 1][y] + 2 + cost * one.field.at(y).at(x)) {
				labirinth[x][y] = labirinth[x + 1][y] + 2 + cost * one.field.at(y).at(x);
				if (x > 0 && !storedleft) {
					junctions.emplace_back(x - 1, y);
					storedleft = true;
				}
				if (y > 0 && !storedup) {
					junctions.emplace_back(x, y - 1);
					storedup = true;
				}
				if (y < one.rows - 1 && !storeddown) {
					junctions.emplace_back(x, y + 1);
					storeddown = true;
				}
			}

		}
		if (y > 0) {
			if (labirinth[x][y] > labirinth[x][y - 1] + 2 + cost * one.field.at(y).at(x)) {
				labirinth[x][y] = labirinth[x][y - 1] + 2 + cost * one.field.at(y).at(x);
				if (x > 0 && !storedleft) {
					junctions.emplace_back(x - 1, y);
					storedleft = true;
				}
				if (x < one.cols - 1 && !storedright) {
					junctions.emplace_back(x + 1, y);
					storedright = true;
				}
				if (y < one.rows - 1 && !storeddown) {
					junctions.emplace_back(x, y + 1);
					storeddown = true;
				}
			}
		}
		if (y < one.rows - 1) {
			if (labirinth[x][y] > labirinth[x][y + 1] + 2 + cost * one.field.at(y).at(x)) {
				labirinth[x][y] = labirinth[x][y + 1] + 2 + cost * one.field.at(y).at(x);
				if (x > 0 && !storedleft) {
					junctions.emplace_back(x - 1, y);
					storedleft = true;
				}
				if (x < one.cols - 1 && !storedright) {
					junctions.emplace_back(x + 1, y);
					storedright = true;
				}
				if (y > 0 && !storedup) {
					junctions.emplace_back(x, y - 1);
					storedup = true;
				}
			}
		}
	} while (junctions.size() > 0);
	return labirinth[one.cols - 1][one.rows - 1];
}


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
	int routeLength{ findPathStepToward(test_case,10001) };
	if (routeLength > 10000) {
		return -1;
	}
	return routeLength / 2;
}

int task2(TestCase test_case) {
	// TODO: Task 2 code here
	int routeLength{ findPathStepToward(test_case,10001) };
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
	int routeLength{ findPathStepToward(test_case,1) };
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