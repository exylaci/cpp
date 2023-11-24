#include <iostream>
#include <string>
#include <fstream>

int main() {
	for (char fileCounter{ '1' }; fileCounter <= '5'; ++fileCounter) {
		std::string fileName{ "ret" };
		fileName += fileCounter;
		fileName += ".in.txt";
		std::ifstream fi{ fileName };
		if (!fi) {
			std::cout << fileCounter << ": Baj van! Nem nyilt meg." << std::endl;
			continue;
		}

		//the width of the field equals of the first line's lenght
		std::string previousData;
		std::string thisData{};
		fi >> thisData;
		int width = thisData.size();
		int* line = new int[width];
		fi.seekg(0);

		int lineCounter{ 0 };
		while (fi >> thisData) {
			int up = INT_MAX;
			int left = INT_MAX;
			for (int i{ 0 }; i < width; ++i) {
				if (lineCounter > 0) {
					//increase the cost in previous line if there is a fence
					up = line[i] + (previousData[i] != thisData[i] ? lineCounter + i : 0);
				}
				if (i > 0) {
					//increase the cost in left field if there is a fence
					left = line[i - 1] + (thisData[i - 1] != thisData[i] ? lineCounter + i : 0);
				}
				if (lineCounter == 0 && i == 0) {
					//cost in start field is zero
					line[i] = 0;
				}
				else {
					//store the cheaper one
					line[i] = std::min(up, left);
				}
			}
			++lineCounter;
			previousData = thisData;
		}
		fi.close();

		//the minimum cost, as the cost of the optimal route is in the last cell of the array
		std::cout << fileCounter << ": " << width << " x " << lineCounter << "  ->  " 
			<< line[width - 1] << std::endl;
		delete [] line;
	}
}