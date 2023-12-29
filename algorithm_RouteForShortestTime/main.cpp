#include <iostream>
#include "main.h"

int main() {
	using namespace std;
	auto fileHandler = openInputFile(INPUT_FILE_NAME);
	auto schedules = loadSchedules(fileHandler);
	fileHandler.close();
	cout << "Leggyorsabb útvonal A és W között: " << fastestRoute(schedules, 'A', 'W') << endl;
	cout << "Legrövidebb útvonal A és W között: " << shortestRoute(schedules, 'A', 'W') << endl;
	cout << "Leggyorsabb útvonal B és Y között: " << fastestRoute(schedules, 'B', 'Y') << endl;
	cout << "Legrövidebb útvonal B és Y között: " << shortestRoute(schedules, 'B', 'Y') << endl;
}