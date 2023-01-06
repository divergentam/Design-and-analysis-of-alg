#include <iostream>

int nzd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return nzd(b, a % b);
	}
}
// Vremenska slozenost:  O(log(min{a,b})
// Memorijska slozenost: O(1)


int nzs(int a, int b) {
	return (a * b) / nzd(a, b);
}

int main() {
	std::cout << nzd(12, 8);
	return 0;
}