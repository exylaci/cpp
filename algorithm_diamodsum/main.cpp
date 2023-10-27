#include <string>
#include <iostream>
#include "../bigint/bigint.cpp"


int main() {
	using namespace std;

	string s[]{ "5", "951", "2515", "347865737", "782631431860047389" };
	for (int i{ 0 }; i < 5; ++i) {
		cout << s[i] << ": ";
		BigInt n{ s[i] };
		cout << ((n * n + 1) / 2 * (n * 2 - 2)) % 987654321 << endl;
	}
}