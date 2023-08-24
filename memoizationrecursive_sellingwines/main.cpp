#include <iostream>
using namespace std;

//reducting the overlapped recursive calls by memoization
int calculated_profits[100][100];

//recursive (out-in) solution
long CalculateProfit(int arr[], int begin, int end, int year) {
	if (begin > end) {
		return 0;
	}
	
	if (calculated_profits[begin][end] > 0) {
		return calculated_profits[begin][end];
	}
	
	long left = CalculateProfit(arr, begin + 1, end, year + 1) + year * arr[begin];
	long right = CalculateProfit(arr, begin, end - 1, year + 1) + year * arr[end];
	
	calculated_profits[begin][end] = max(left, right);
	return calculated_profits[begin][end];
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

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			calculated_profits[i][j] = 0;
		}
	}

	cout << "The maximum profit is: " << CalculateProfit(bottles, 0, n - 1, 1) << endl;
	return 0;
}