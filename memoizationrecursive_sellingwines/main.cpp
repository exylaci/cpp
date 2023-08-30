#include <iostream>
#include <iomanip>
using namespace std;

//with a for-loop
long CalculateWithFor(int prices[], int pieces) {
	int profits[100][100] = {};
	int year{ pieces };

	//calculate the profit only for the last year in diagonal
	for (int i = 0; i < pieces; ++i) {
		profits[i][i] = prices[i] * year;	// = price * nuber of years
	}
	--year;

	//select the order in sub groups based on theirs calculated profits
	for (int len = 2; len <= pieces; ++len) {
		for (int left = 0; left <= pieces - len; ++left) {
			int right = left + len - 1;
			profits[left][right] = max(
				prices[left] * year + profits[left + 1][right],
				prices[right] * year + profits[left][right - 1]
			);
		}
		--year;
	}

	//cout << endl;
	//for (int i = 0; i < pieces; ++i) {
	//	for (int j = 0; j < pieces; ++j) {
	//		cout << setw(3) << profits[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	return profits[0][pieces - 1];
}

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
	cout << " result with for-loop: " << CalculateWithFor(bottles, n);
	return 0;
}