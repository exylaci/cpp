#include "main.h"
#include <iostream>
#include <iomanip>
#include <chrono>

//take over data copy from variables (original version)  10x5. 291'225 msec 
//take over the references variables (2nd version)       10x5. 293'124 msec 
//inline to avoid variables take overs (3rd version)     10x5. 290'762 msec 

int main() {
	auto startTime = std::chrono::system_clock::now();
	for (char fileCounter{ '1' }; fileCounter <= '6'; ++fileCounter) {
		cleanUp();
		if (getInputData(fileCounter)) {
			auto answer = countDifferents();
			printOutAnswer(fileCounter, answer);
		}
	}
	std::cout << std::setw(5) << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - startTime).count() << std::endl;
}

//erase the previous data before start new calculation 
void cleanUp() {
	hierarchy.clear();
	hashs.clear();
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
//close input file
void closeFile(std::ifstream& fileHandler) {
	fileHandler.close();
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

//count the different subparts of the hierarchy graph
int countDifferents() {
	hierarchy.at(0).first = getHash(0);
	return hashs.size();
}
//get the hash code of a member
size_t getHash(int id) {
	if (hierarchy.at(id).first > 0) {
		return getCalculatedHash(id);
	}
	if (hierarchy.at(id).second.size() == 0) {
		calculateOneHash(id, 0);
		return getCalculatedHash(id);
	}
	calculateItsUnderlingsHashs(id);
	return getCalculatedHash(id);
}
//return the already calculated hash of its member
inline size_t getCalculatedHash(int id) {
	return hierarchy.at(id).first;
}
//calculate the hash of a member without underling
inline void calculateOneHash(int id, size_t amount) {
	hierarchy.at(id).first = std::hash<size_t>{}(amount);
	hashs.insert(hierarchy.at(id).first);
}
//calculate the underling members' hashs of this member
inline void calculateItsUnderlingsHashs(int id) {
	auto underlingsHash = iterateOnItsUnderlings(id);
	calculateOneHash(id, underlingsHash);
}
//cumulate the hashs of its underlings
inline size_t iterateOnItsUnderlings(int id) {
	size_t hash{ 0 };
	for (auto one : hierarchy.at(id).second) {
		hash += getHash(one);
	}
	return hash;
}

//print out the resoult of the calculation
void printOutAnswer(char fileCounter, int answer) {
	std::cout << fileCounter << ": " << answer << std::endl;
}
