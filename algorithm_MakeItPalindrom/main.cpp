#include <iostream>
#include "color_lists_inputs.cpp.inc"
#include <vector>

// copying the input so it can be modified locally
int task1(std::vector<int> test_case) {
    // TODO: Task 1 solution here
    return 0;
}

int task2(std::vector<int> test_case) {
    // TODO: Task 2 solution here
    return 0;
}

int task3(std::vector<int> test_case) {
    // TODO: Task 3 solution here
    return 0;
}

int main() {
    std::cout << "Solution for Task 1:" << std::endl;
    for (std::vector<int>& test_case : test_cases_task_1_3) {
        std::cout << task1(test_case) << " ";
    }
    std::cout << std::endl;
    std::cout << "Solution for Task 2:" << std::endl;
    for (std::vector<int>& test_case : test_cases_task_1_3) {
        std::cout << task2(test_case) << " ";
    }
    std::cout << std::endl;
    std::cout << "Solution for Task 3:" << std::endl;
    for (std::vector<int>& test_case : test_cases_task_2) {
        std::cout << task3(test_case) << " ";
    }
    std::cout << std::endl;
    return 0;
}