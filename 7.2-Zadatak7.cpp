#include <iostream>

// d[t][i]
// 0 <= t <= W - tezina ranca
//1 <= i <= n - redni broj predmeta

int max(int a, int b) {
	return a > b ? a : b;
}

int zad7(int w[], int c[], int n, int W) {
	// formiranje matrice d dimenzija (W + 1) x (n + 1)
	int** d = new int*[W + 1];
	for (int i = 0; i <= W; i++) {
		d[i] = new int[n + 1];
	}

	// popunjavanje prvog reda nulom
	for (int j = 0; j <= n; j++) {
		d[0][j] = 0;
	}
	for (int i = 0; i <= W; i++) {
		d[i][0] = 0;
	}

	// primena rekurentne formule
	for (int t = 1; t <= W; t++) {
		for (int i = 1; i <= n; i++) {
			int v1 = d[t][i - 1];
			int v2 = (w[i - 1] <= t) ? d[t - w[i - 1]][i - 1] + c[i -1] : INT_MIN;
			d[t][i] = max(v1, v2);
		}
	}

	// oslobadjanje memorije i vracanje rezultata
	int result = d[W][n];
	for (int i = 0; i <= W; i++) {
		delete[] d[i];
	}
	delete[] d;

	return result;
}

int main() {
	int n = 3, W = 50;
	int w[3] = { 10, 45, 20 };
	int c[3] = { 45, 120, 100 };

	std::cout << zad7(w, c, n, W) << std::endl;

	return 0;
}