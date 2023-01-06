#include <iostream>

//binarna pretraga treba da vrati:
// index pojavljivanja ako element postoji
// -1 ako element ne postoji

bool isSorted(int a[], int n) {
	for (int i = 1; i < n; i++) {
		if (a[i - 1] > a[i]) {
			return false;
		}
	}
	return true;
}

int searchFor(int a[], int num, int l, int r) {
	if (l > r) {
		return -1;
	}
	int m = (r + l) / 2; //sredisnji el
	if (a[m] == num) {
		return m;
	}
	else if (num < a[m]) {
		return searchFor(a, num, l, m - 1);
	}
	else {
		return searchFor(a, num, m + 1, r);
	}
}

int binanrySearch(int a[], int n, int num) {
	if (isSorted(a, n)) {
		return searchFor(a, num, 0, n - 1);
	}
	else{ 
		return -2;
	}
}



int main() {
	int n = 8;
	int a[8] = { -5, 2, 3, 4, 6, 6, 9, 10 };
	int num = 9;

	int index = binanrySearch(a, n, num);

	if (index == -2) {
		std::cout << "Niz njije sortiran!" << std::endl;
	}
	else if (index == -1) {
		std::cout << "Element " << num << " se ne nalazi u nizu!" << std::endl;
	}
	else {
		std::cout << "Element " << num << " se nalazi u nizu i ima index " << index << std::endl;
	}

	return 0;
}