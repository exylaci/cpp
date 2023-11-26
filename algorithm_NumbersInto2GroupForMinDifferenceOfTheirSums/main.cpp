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
std::vector<bool> selectNums(std::vector<int>& nums) {
	std::vector<bool> cache{};
	std::vector<bool> prevCache{};

	auto sumOfNums = std::accumulate(nums.begin(), nums.end(), 0L);
	bool intoGroupA;
	int num;

	for (int startIndex = nums.size(); startIndex > -1; --startIndex) {
		for (long sum{ 0 }; sum <= sumOfNums; ++sum) {
			if (startIndex >= nums.size()) {
				intoGroupA = (sum == 0);
			}
			else {
				num = nums.at(startIndex);
				intoGroupA = (sum >= num && prevCache.at(sum - num)) || prevCache.at(sum);
			}
			cache.push_back(intoGroupA);
		}
		prevCache.swap(cache);
		cache.clear();
		cache.reserve(sumOfNums + 1);
	}
	return prevCache;
}
long calculateDifference(std::vector<int>& nums){
	auto cache = selectNums(nums);

	long difference{ 0 };
	auto s = std::accumulate(nums.begin(), nums.end(), 0L);
	for (int i{ s / 2 }; i > 0; --i) {
		if (cache.at(i)) {
			difference = abs(i - (s - i));
			break;
		}
	}
	return difference;
}

int main() {
	for (char fileCounter = '1'; fileCounter <= '5'; ++fileCounter) {
		auto nums = loadNumbers(fileCounter);
		if (!nums.empty()) {
			auto startTime = std::chrono::system_clock::now();

			auto difference = calculateDifference(nums);

			std::cout << fileCounter << ":" << std::setw(4) << abs(difference);
			std::cout << "    (futasi ido:" << std::setw(4) << std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - startTime).count() << " sec)";
			std::cout << std::endl;
		}
	}
}