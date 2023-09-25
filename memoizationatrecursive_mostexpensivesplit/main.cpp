#include <iostream>
using namespace std;

//recursive solution:
int CalculateSplits(int costs[], int length) {
	if (length == 0)return 0;
	int resoult = 0;
	for (int i = 1; i <= length; ++i) {
		resoult = max(resoult, costs[i] + CalculateSplits(costs, length - i));
	}
	return resoult;
}

int main() {
	int costs[100];
	cout << "Length of the section: ";
	int length;
	cin >> length;
	for (int i = 1; i <= length; ++i) {
		cout << "Give the costs of the " << i << " length section: ";
		cin >> costs[i];
	}

	cout << "The most expensive splits is: " << CalculateSplits(costs, length) << endl;
	return 0;
}