#include <iostream>

int zad4(int n, int a[]) {
	int suma = 0;
	int brojOcena = 0;
	int* d = new int[n];

	for (int i = 0; i < n; i++) {
		d[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		d[i]++;
		suma += a[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < d[i]; j++) {
			if ((double)suma / n >= 4.5) {
				break;
			}
			suma += (5 - i);
			brojOcena++;
		}
	}
	return brojOcena;
}

int main() {
	int n = 4;
	int a[] = { 5, 3, 3, 5 };
	std::cout << zad4(n, a);
	return 0;
}