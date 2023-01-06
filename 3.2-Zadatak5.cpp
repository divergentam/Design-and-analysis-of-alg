#include <iostream>

/*
a^8 mod m = a^4 mod m * a^4 mod m
a^9 mod m = a mod m * (a^4 mod m * a^4 mod m)
*/

int Zadatak5(int a, int n, int m) {
	int x;
	if (n == 1) {
		return a % m;
	}
	else if (n % 2 == 0) {
		x = Zadatak5(a, n / 2, m);
		return (x * x) % m;
	}
	else {
		x = Zadatak5(a, (n - 1) / 2, m);
		return (a * x * x) % m;
	}
}


int main() {
	int a = 7;
	int n = 8;
	int m = 1000;

	std::cout << Zadatak5(a, n, m);

	return 0;
}