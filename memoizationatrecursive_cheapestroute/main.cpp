#include <iostream>
using namespace std;

//with a for-loop
int CalculateWithFor(int costs[][100], int top, int left, int bottom, int right) {
	for (int i = 1; i <= bottom; ++i) {
		costs[i][0] = costs[i][0] + costs[i - 1][0];
	}
	for (int i = 1; i <= right; ++i) {
		costs[0][i] = costs[0][i] + costs[0][i-1];
	}
	for (int i = 1; i <= bottom; ++i) {
		for (int j = 1; j <= right; ++j) {
			costs[i][j] = min(costs[i - 1][j], costs[i][j - 1]) + costs[i][j];
		}
	}
	return costs[bottom][right];
}

//reducting the overlapped recursive calls by memoization
int calculated_routes[100][100];

//recursive solution:
int CalculateRoute(int cost[][100], int top, int left, int bottom, int right) {
	if (calculated_routes[top][left] > -1)
		return calculated_routes[top][left];
	if (left == right && top == bottom) {
		calculated_routes[top][left] = cost[bottom][right];
		return cost[bottom][right];
	}
	if (left == right) {
		calculated_routes[top][left] =
			cost[top][left] + CalculateRoute(cost, top + 1, left, bottom, right);
		return calculated_routes[top][left];
	}
	if (top == bottom) {
		calculated_routes[top][left] =
			cost[top][left] + CalculateRoute(cost, top, left + 1, bottom, right);
		return calculated_routes[top][left];
	}
	calculated_routes[top][left] =
		cost[top][left] + min(
			CalculateRoute(cost, top, left + 1, bottom, right),
			CalculateRoute(cost, top + 1, left, bottom, right)
		);
	return calculated_routes[top][left];
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
			calculated_routes[i][j] = -1;
		}
	}

	cout << "Cheapest route is: " << CalculateRoute(costs, 0, 0, r - 1, c - 1) << endl;
	cout << "Calculate with for:" << CalculateWithFor(costs, 0, 0, r - 1, c - 1) << endl;
	return 0;
}