#include <iostream>

// niz d[i] - maximalna suma elemenata do i - tog elementa

// ako izaberemo el a[i] onda ne smemo izabrati el a[i-1] pa preostale el mozemo izabrati od a[1... i - 2]
// ukoliko ne izaberemo onda smo slobodni da biramo bilo koje el iz podniza a[1.. i - 1] pa je u tom slucaju resenje d[i - 1]
int max(int a, int b) {
	return a > b ? a : b;
}

int solve(int a[], int n) {
	int* d = new int[n + 1];
	d[0] = max(0, a[0]);
	for (int i = 1; i < n; i++) {
		d[i] = max(a[i] + d[i - 2], d[i - 1]);
		// imamo prvi slucaj ako je poslednji element uso u zbir, a drugi je slucaj ako nije
	}

	for (int i = n - 1; i >= 0; i--) {
		if (d[i] - a[i] == d[i - 2]) {
			std::cout << a[i] << " ";
			i--;
		}
		else if (i == 0) {
			std::cout << a[i] << " ";

		}
	}
	return d[n - 1];
}

int main() {
	int n = 8;
	int a[] = { 4, -1, 3, 8, 7, -1, -5, 6 };
	std::cout << std::endl << solve(a, n);
}

