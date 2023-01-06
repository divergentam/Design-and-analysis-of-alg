#include <iostream>

#define MAXD 10000

// d[i][j] - maximalna suma do elementa d[i][j]
// za svaku vrstu (1 <= i <= n) i kolonu (1 <= j <= m)

int max(int a, int b) {
	return a > b ? a : b;
}

int zad2(int a[][MAXD], int n, int m) {
	// formiranje matrice d dimenzija (n + 1) x (m + 1)
	int** d = new int* [n + 1];
	for (int i = 0; i <= n; i++) {
		d[i] = new int[m + 1];
	}

	//popunjavamo pocetne vrednosti
	for (int i = 0; i <= n; i++) {
		d[i][0] = 0;
	}
	for (int j = 0; j <= m; j++) {
		d[0][j] = 0;
	}
	
	// primena rekurentne formule
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			d[i][j] = max(d[i - 1][j], d[i][j - 1]) + a[i - 1][j - 1];
			// to je + a[i][j] ali posto se ide od 1 do n za j i m onda ovako
		}
	}

	// oslobadjanje memorije i vracanje rezultata
	int result = d[n][m];

	for (int i = 0; i <= n; i++) {
		delete[] d[i];
	}
	delete[] d;

	return result;
}

int main() {
	int n = 5;
	int m = 5;
	int a[5][MAXD] = {
		{2, 2, 5, 6, 2},
		{5, 1, 2, 2, 3},
		{7, 6, 7, 8, 7},
		{1, 6, 4, 2, 3},
		{3, 4, 0, 3, 5}
	};
	std::cout << zad2(a, n, m);

	return 0;
}