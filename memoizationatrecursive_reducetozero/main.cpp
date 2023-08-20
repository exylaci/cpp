#include <iostream>
#include <limits>
using namespace std;

//for loop (bottom-up) solution
int CalculateWithFor(int n) {
	int steps[100000];
	steps[0] = 0;     //default
	for (int i = 1; i <= n; ++i) {
		int a = INT_MAX;
		int b = INT_MAX;
		int c = INT_MAX;
		if (i % 3 == 0) {
			a = steps[i / 3] + 1;
		}
		if (i % 2 == 0) {
			b = steps[i / 2] + 1;
		}
		c = steps[i - 1] + 1;

		steps[i] = min(min(a, b), c);
	}
	return steps[n];
}

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

	//cout << "The minimum necessary steps are: " << CalculateSteps(n) << endl;
	cout << "The minimum necessary steps are: " << CalculateWithFor(n) << endl;
	return 0;
}