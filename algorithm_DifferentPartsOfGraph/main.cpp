#include "main.h"
#include <iostream>

int main() {
	for (char fileCounter{ '1' }; fileCounter <= '6'; ++fileCounter) {
		hierarchy.clear();
		hashs.clear();
		if (getInputData(fileCounter)) {
			auto answer = countDifferents();
			std::cout << fileCounter << ": " << answer << std::endl;
		}
	}
}

//build up file name, open input file, load data from input file, close input file
bool getInputData(char order) {
	auto filename = prepareFileName(order);
	auto fileHandler = openFile(filename);
	if (fileHandler) {
		loadDataFromFile(fileHandler);
		closeFile(fileHandler);
		return true;
	}
	return false;
}
//build up filename string
std::string prepareFileName(char order) {
	std::string filename(BEGINNING_OF_INPUT_FILE_NAME);
	filename += order;
	filename += END_OF_INPUT_FILE_NAME;
	return filename;
}
//open input file for reading
std::ifstream openFile(const std::string& filename) {
	using namespace std;
	ifstream fileHandler{ filename };
	if (!fileHandler.is_open()) {
		cout << filename << "    <--- Baj van! Nem nyilt meg." << endl;
	}
	return fileHandler;
}
//load data from input file
void loadDataFromFile(std::ifstream& fileHandler) {
	int x;
	int y;
	fileHandler >> x;
	addToHierarchyList(0);
	while (fileHandler >> x >> y) {
		addToHierarchyList(x);
		addToLeadersList(y, x);
	}
}
//add a new member to the list map
void addToHierarchyList(int x) {
	hierarchy.emplace(x, std::pair<size_t, std::vector<int>>(std::make_pair(0, std::vector<int>{})));
}
//add a memeber to its leader's member vector
void addToLeadersList(int y, int x) {
	hierarchy.at(y).second.emplace_back(x);
}
//close input file
void closeFile(std::ifstream& fileHandler) {
	fileHandler.close();
}

//count the different subparts of the hierarchy graph
int countDifferents() {
	hierarchy.at(0).first = getHash(0);
	return hashs.size();
}
//get the hash code of a member
size_t getHash(int id) {
	if (hierarchy.at(id).first > 0) {
		return hierarchy.at(id).first;
	}
	if (hierarchy.at(id).second.size() == 0) {
		hierarchy.at(id).first = std::hash<size_t>{}(0);
		hashs.insert(hierarchy.at(id).first);
		return hierarchy.at(id).first;
	}
	size_t hash{ 0 };
	for (auto one : hierarchy.at(id).second) {
		hash += getHash(one);
	}
	hierarchy.at(id).first = std::hash<size_t>{}(hash);
	hashs.insert(hierarchy.at(id).first);
	return hierarchy.at(id).first;
}
