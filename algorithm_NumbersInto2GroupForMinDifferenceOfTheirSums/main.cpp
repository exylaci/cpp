#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
	using namespace std;
	for (char fileCounter = '1'; fileCounter <= '5'; ++fileCounter) {
		string filename("testver");
		filename += fileCounter;
		filename += ".in.txt";

		ifstream fi{ filename };
		if (!fi.is_open()) {
			std::cout << filename << "   <--- Nem nyilt meg!" << std::endl << std::endl;
			continue;
		}

		std::vector<int> nums{};
		int num;
		while (fi >> num) {
			nums.emplace_back(num);
		}
		fi.close();

		std::sort(nums.begin(), nums.end(), std::greater<int>());
		long difference{ 0 };
		for (const auto num : nums) {
			if (difference > 0) {
				difference -= num;
			}
			else {
				difference += num;
			}
		}

		std::cout << fileCounter << ":   " << abs(difference) << endl;
	}
}