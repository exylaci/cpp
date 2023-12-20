#include <iostream>
#include "color_lists_inputs.cpp.inc"
#include <vector>
#include <map>

//Count the differences as it vould be a palindrom.
int task1(std::vector<int> test_case) {
	int counter = 0;
	for (int i = 0; i < test_case.size() / 2; ++i) {
		if (test_case.at(i) != test_case.at(test_case.size() - 1 - i)) {
			++counter;
		}
	}
	return counter;
}

//recursively find the longest palindrome subsequence accelerate by memoization
int longestSubSequence(std::vector<int> test_case, int first, int last, std::map<std::tuple<int, int>, int>& memo) {
	if (first == last) {
		return 1;
	}
	if (first + 1 == last) {
		return test_case[first] == test_case[last] ? 2 : 1;
	}
	if (memo.find({ first, last }) == memo.end()) {
		auto leftPart = longestSubSequence(test_case, first, last - 1, memo);
		auto rightPart = longestSubSequence(test_case, first + 1, last, memo);
		auto result = std::max(leftPart, rightPart);
		if (test_case[first] == test_case[last]) {
			auto middlePart = longestSubSequence(test_case, first + 1, last - 1, memo) + 2;
			result = std::max(result, middlePart);
		}
		memo[{first, last}] = result;
	}
	return memo[{first, last}];
}

int task2(std::vector<int> test_case) {
	std::map<std::tuple<int, int>, int> memo = {};
	return test_case.size() - longestSubSequence(test_case, 0, test_case.size() - 1, memo);
}

//Count the difference from the beginnig or end, the fewer ones.
int task3(std::vector<int> test_case) {
	if (test_case.at(0) == test_case.at(test_case.size() - 1)) return 0;
	for (int i = 1; i < test_case.size(); ++i) {
		if (test_case.at(i) != test_case.at(i - 1) ||
			test_case.at(test_case.size() - 1) != test_case.at(test_case.size() - 1 - i)) {
			return(i);
		}
	}
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