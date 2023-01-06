#include <iostream>

int binartSearch(int a[], int num, int l, int r) {
	if (l > r) {
		return -1;
	}
	int m = (l + r) / 2;
	if (num == a[m]) {
		return m;
	}
	else if (num > a[m]){
		return binartSearch(a, num, m + 1, r);
	}
	else {
		return binartSearch(a, num, l, m - 1);
	}
}

bool solvea(int n, int a[], int m, int b[], int k) {
	int res;
	int i = 0;
	while(i < n) {
		res = k - a[i];
		int index = binartSearch(b, res, 0, m - 1);
		if (index == -1) {
			i++;
		}
		else {
			std::cout << b[index] << " + " << a[i] << std::endl;
			return true;
		}
	}
	return false;
}

bool Zadatak9a(int n, int a[], int m, int b[], int k) {
	if (m > n) {
		return solvea(n, a, m, b, k);
	}
	else {
		return solvea(m, b, n, a, k);
	}
}

bool Zadatak9b(int n, int a[], int m, int b[], int k) {
	int i = 0;
	int j = m - 1;
	while (i < n && j >= 0)  {
		if ((a[i] + b[j]) == k) {
			std::cout << a[i] << " + " << b[j] << std::endl;
			return true;
		}
		i++;
		j--;
	}
	return false;
}

int main() {
	int n = 4;
	int a[] = { 2, 10, 17, 90 };
	int m = 3;
	int b[] = { 83, 91, 100 };
	int k = 100;

	if (!Zadatak9a(n, a, m, b, k)) {
		std::cout << "Ne postoje dva broja gde jedan pripada nizu a, a drubi nizu b koji u zbiru daju broj " << k << std::endl;
	}

	if (!Zadatak9b(n, a, m, b, k)) {
		std::cout << "Ne postoje dva broja gde jedan pripada nizu a, a drubi nizu b koji u zbiru daju broj " << k << std::endl;
	}

	return 0;
}