#include <iostream>
using namespace std;

int CalculateRoute(int cost[][100], int top, int left, int bottom, int right) {
	if (left == right && top == bottom)
		return cost[bottom][right];
	if (left == right)
		return cost[top][left] + CalculateRoute(cost, top + 1, left, bottom, right);
	if (top == bottom)
		return cost[top][left] + CalculateRoute(cost, top, left + 1, bottom, right);
	return cost[top][left] + min(
		CalculateRoute(cost, top, left + 1, bottom, right),
		CalculateRoute(cost, top + 1, left, bottom, right)
	);
}

int main() {
	int costs[100][100];
	cout << "Number of rows: ";
	int r;
	cin >> r;
	cout << "Number of columns: ";
	int c;
	cin >> c;
	cout << "Give the costs: " << endl;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> costs[i][j];
		}
	}

	cout << "Cheapest route is: " << CalculateRoute(costs, 0, 0, r - 1, c - 1) << endl;
	return 0;
}