#include <iostream>
using namespace std;

//reducting the overlapped recursive calls by memoization
int calculated_costs[100];

//recursive solution:
int CalculateSplits(int costs[], int length) {
	if (length == 0)return 0;
	if (calculated_costs[length] > -1) {
		return calculated_costs[length];
	}

	int resoult = 0;
	for (int i = 1; i <= length; ++i) {
		resoult = max(resoult, costs[i] + CalculateSplits(costs, length - i));
	}
	calculated_costs[length]=resoult;
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
		calculated_costs[i] = -1;
	}

	cout << "The most expensive splits is: " << CalculateSplits(costs, length) << endl;
	return 0;
}