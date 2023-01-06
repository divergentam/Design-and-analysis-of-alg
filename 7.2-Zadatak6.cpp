#include <iostream>

int zad6(int w[], int c[], int n, int W) {
	int* d = new int[W + 1];
	d[0] = 0;

	for (int t = 1; t <= W; t++) {
		int max = 0;
		for (int i = 0; i < n; i++) { 
			if (w[i] <= t) {
				// d[t - w[i]] - najveca cena za preostali prostor
				max = (d[t - w[i]] + c[i] > max) ? d[t - w[i]] + c[i] : max;
			}
		}
		d[t] = max;
	}
	int result = d[W];

	delete[] d;
	return result;

}

int main() {
	int n = 3, W = 50;
	int w[3] = { 10, 30, 20 };
	int c[3] = { 45, 120, 100 };
	std::cout << zad6(w, c, n, W);
}