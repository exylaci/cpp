#include <iostream>
#include <limits>
using namespace std;

//recursive (top-down) solution
int CalculateSteps(int n) {
    if (n == 0) {              //exit condition
        return 0;
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

    return min(min(a, b), c);
}

int main() {
    cout << "Give the starting number: ";
    int n;
    cin >> n;

    cout << "The minimum necessary steps are: " << CalculateSteps(n) << endl;
    return 0;
}