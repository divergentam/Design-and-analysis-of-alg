#include <iostream>

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void sort(int l[], int c[], int left, int right) {
	if (left < right) {
		int pivot = c[right];
		int count = left;
		for (int i = left; i <= right; i++) {
			if (c[i] <= pivot) {
				swap(c[i], c[count]);
				swap(l[i], l[count]);
				count++;
			}
		}
		pivot = count - 1;
		sort(l, c, left, pivot - 1);
		sort(l, c, pivot + 1, right);
	}
}

int solve(int n, int X, int l[], int c[]) {
	sort(l, c, 0, n - 1);
	int cena = 0;
	int kolikoJeUzeo = 0;
	for (int i = 0; i < n; i++) {
		if (kolikoJeUzeo == X) {
			return cena;
		}
		if (kolikoJeUzeo + l[i] <= X) {
			kolikoJeUzeo += l[i];
			cena += l[i] * c[i];
		}
		else {
			 cena += (X - kolikoJeUzeo) * c[i];
			 kolikoJeUzeo += (X - kolikoJeUzeo);
		}		
	}
}

void print(int n, int a[]) {
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << "\t";
	}
	std::cout << std::endl;
}

int main() {
	int n = 5;
	int X = 100;
	int l[5] = { 20,40,10,80,30 };
	int c[5] = { 5,9,3,8,6 };
	std::cout << solve(n, X, l, c);


	return 0;
}