#include <iostream>
using namespace std;

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

	for (int i = 0; i <=n; ++i) {
		calculated_fibonacci_numbers[i] = -1;
	}

	long long int fibonacci_number = Fibonacci(n);
	cout << "It is: " << fibonacci_number << endl;
	return 0;
}