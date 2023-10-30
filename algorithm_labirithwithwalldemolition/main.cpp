#include <iostream>
#include <vector>
#include "wall_demolish_inputs.cpp.inc"

// full copy of the test case so it can be modified locally
int task1(TestCase test_case) {
    // TODO: Task 1 code here
    return -1;
}

int task2(TestCase test_case) {
    // TODO: Task 2 code here
    return -1;
}

int task3(TestCase test_case) {
    // TODO: Task 3 code here
    return -1;
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