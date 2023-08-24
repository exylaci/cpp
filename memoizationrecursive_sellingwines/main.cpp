#include <iostream>
using namespace std;

//recursive (out-in) solution
long CalculateProfit(int arr[], int begin, int end, int year) {
	if (begin > end) {
		return 0;
	}

	long left = CalculateProfit(arr, begin + 1, end, year + 1) + year * arr[begin];
	long right = CalculateProfit(arr, begin, end - 1, year + 1) + year * arr[end];

	return max(left, right);
}

int main() {
	int bottles[100];
	cout << "How many bottle of wine do you have? ";
	int n;
	cin >> n;
	cout << "Give their prices: " << endl;
	for (int i = 0; i < n; ++i) {
		cin >> bottles[i];
	}

	cout << "The maximum profit is: " << CalculateProfit(bottles, 0, n - 1, 1) << endl;
	return 0;
}