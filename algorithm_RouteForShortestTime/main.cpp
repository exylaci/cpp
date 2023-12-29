#include <iostream>
#include "main.h"

int main() {
	using namespace std;
	auto fileHandler = openInputFile(INPUT_FILE_NAME);
	auto schedules = loadSchedules(fileHandler);
	fileHandler.close();
	cout << "Leggyorsabb �tvonal A �s W k�z�tt: " << fastestRoute(schedules, 'A', 'W') << endl;
	cout << "Legr�videbb �tvonal A �s W k�z�tt: " << shortestRoute(schedules, 'A', 'W') << endl;
	cout << "Leggyorsabb �tvonal B �s Y k�z�tt: " << fastestRoute(schedules, 'B', 'Y') << endl;
	cout << "Legr�videbb �tvonal B �s Y k�z�tt: " << shortestRoute(schedules, 'B', 'Y') << endl;
}