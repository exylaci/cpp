#include <iostream>
using namespace std;

//get Fibonacci number by a recursive function
int Fibonacci(int n) {
	if (n == 0 || n == 1) {
		return n;
	}
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {
	cout << "Which Fibonacci number do you need: ";
	int n;
	cin >> n;
	int fibonacci_number = Fibonacci(n);
	cout << "It is: " << fibonacci_number << endl;
	return 0;
}