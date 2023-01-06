#include <iostream>

void swap(double& a, double& b) {
	double temp = a;
	a = b;
	b = temp;
}

void sort(int l, int r, double a[]) {
	if (l < r) {
		double pivot = a[r];
		int count = l;
		for (int i = l; i <= r; i++) {
			if (a[i] <= pivot) {
				swap(a[i], a[count]);
				count++;
			}
		}
		pivot = count - 1;
		sort(l, pivot - 1, a);
		sort(pivot + 1, r, a);
	}
}

int solve(int n, double a[]) {
	sort(0, n - 1, a);
	int counter = 1;
	int rightInterval = a[0] + 1;
	std::cout << "[" << a[0] << ", " << rightInterval << "]";
	for (int i = 1; i < n; i++) {
		if (a[i] > rightInterval) {
			counter++;
			rightInterval = a[i] + 1;
			std::cout << ", [" << a[i] << ", " << rightInterval << "]";

		}
	}
	return counter;
}

int main() {
	int n = 6;
	double a[] = { 1.0,2.0,2.5,2.6,3.0,5.0 };

	std::cout << std::endl << solve(n, a);
	return 0;
}