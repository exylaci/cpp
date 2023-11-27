#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <chrono>
#include <iomanip>

//build up the filename string
std::string prepareFileName(char fileCounter) {
	std::string filename("testver");
	filename += fileCounter;
	filename += ".in.txt";
	return filename;
}
//open the input file for reading
std::ifstream openFile(const std::string& filename) {
	std::ifstream fi{ filename };
	if (!fi.is_open()) {
		std::cout << filename << "    <--- Baj van! Nem nyilt meg." << std::endl;
	}
	return fi;
}
//read the data from the input file
std::vector<int> readDataFromFile(std::ifstream& fi) {
	std::vector<int> nums{};
	int num;
	while (fi >> num) {
		nums.emplace_back(num);
	}
	fi.close();
	return nums;
}
//collect the input data into a vector
std::vector<int> loadNumbers(char fileCounter) {
	auto filename = prepareFileName(fileCounter);
	auto fi = openFile(filename);
	if (fi) {
		auto nums = readDataFromFile(fi);
		return nums;
	}
	return std::vector<int>{};
}


//With dinamic programming, lets use the cookes from i to select into them to 2 groups and using
// for loop to select the closest numer to half weight.
void selectNums(long sumOfNums, bool* sums, std::vector<int>& nums) {
	long halfOfSums{ sumOfNums / 2 };
	for (long i{ 0 }; i <= halfOfSums; ++i) {
		sums[i] = false;
	}
	sums[0] = true;

	long total{ 0 };
	for (const auto& num : nums) {
		total = std::min(total, halfOfSums-num);
		for (long i{ total }; i >= 0; --i) {
			if (sums[i]) {
				sums[i + num] = true;
			}
		}
		total += num;
	}
}
long calculateDifference(std::vector<int>& nums) {
	auto sumOfNums = std::accumulate(nums.begin(), nums.end(), 0L);
	bool* sums = new bool[sumOfNums / 2 + 1];

	selectNums(sumOfNums, sums, nums);

	for (long i{ sumOfNums / 2 }; i >= 0; --i) {
		if (sums[i]) {
			delete[] sums;
			return  (sumOfNums / 2 - i) * 2 + sumOfNums % 2;
		}
	}
	return 0;
}

int main() {
	for (char fileCounter = '1'; fileCounter <= '5'; ++fileCounter) {
		auto nums = loadNumbers(fileCounter);
		if (!nums.empty()) {
			auto startTime = std::chrono::system_clock::now();

			auto difference = calculateDifference(nums);

			std::cout << fileCounter << ":" << std::setw(4) << abs(difference);
			std::cout << "    (futasi ido:" << std::setw(4) << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - startTime).count() << " millisec)";
			std::cout << std::endl;
		}
	}
}