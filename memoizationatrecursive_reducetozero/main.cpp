#include <iostream>
#include <limits>
using namespace std;

//reducting the overlapped recursive calls by memoization
int calculated_steps[1000000];

//recursive (top-down) solution
int CalculateSteps(int n) {
	if (n == 0) {              //exit condition
		return 0;
	}

	if (calculated_steps[n] > 0) {
		return calculated_steps[n];
	}

	int a = INT_MAX;
	int b = INT_MAX;
	int c = INT_MAX;
	if (n % 3 == 0) {
		a = CalculateSteps(n / 3) + 1;
	}
	if (n % 2 == 0) {
		b = CalculateSteps(n / 2) + 1;
	}
	c = CalculateSteps(n - 1) + 1;

	calculated_steps[n] = min(min(a, b), c);
	return calculated_steps[n];
}

int main() {
	cout << "Give the starting number: ";
	int n;
	cin >> n;

	fill(calculated_steps, calculated_steps + n + 1, 0);

	cout << "The minimum necessary steps are: " << CalculateSteps(n) << endl;
	return 0;
}