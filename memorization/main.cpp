#include <iostream>
using namespace std;

//calculate by bottom-up approach methodology
long long int Fibonacci_bottop_up(int n) {
	long long int fibonacci_numbers[1000] = {};
	fibonacci_numbers[0] = 0;
	fibonacci_numbers[1] = 1;
	for (int i = 2; i <= n; ++i) {
		fibonacci_numbers[i] = fibonacci_numbers[i - 2] + fibonacci_numbers[i - 1];
	}
	return fibonacci_numbers[n];
}

//with dynamic programming
long long int calculated_fibonacci_numbers[1000];

//get Fibonacci number by a recursive function
long long int Fibonacci(int n) {
	if (n == 0 || n == 1) {
		return n;
	}

	if (calculated_fibonacci_numbers[n] == -1) {
		calculated_fibonacci_numbers[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
	}

	return calculated_fibonacci_numbers[n];
}

int main() {
	cout << "Which Fibonacci number do you need: ";
	int n;
	cin >> n;

	for (int i = 0; i <= n; ++i) {
		calculated_fibonacci_numbers[i] = -1;
	}

	cout << "The recursive result is: " << Fibonacci(n) << endl;
	cout << "The bottom-up result is: " << Fibonacci_bottop_up(n) << endl;
	return 0;
}