#include <iostream>

//MERGE SORT
// Merge sort je bolji kada u nizu imamo neke random brojeve
// U slucaju kada je pocetni niz delimicno ili skroz sortiran radi nepotrebno 
// deljenje i zauzimanje memorije a to nije potrebno pa je tad bolji SELECTION SORT

// l - index leve granice podniza
// r - index desne granice podniza


void merge(int a[], int l, int m, int r) {
	int i, j, k, nl, nr;
	// nr - broj el desnog podniza
	// nl - broj el levog podniza
	nl = m - l + 1;
	nr = r - m;
	int* la = new int[nl];
	int* ra = new int[nr];
	//kopiramo podnizove iz niza a u nizove la i ra
	for (i = 0; i < nl; i++) {
		la[i] = a[l + i];
	}
	for (i = 0; i < nr; i++) {
		ra[i] = a[m + 1 + i];
	}
	//Spajamo podnizove odnosno nizove la i ra u niz a
	i = 0;
	j = 0;
	k = l;
	while (i < nl && j < nr) {
		if (la[i] < ra[j]) {
			a[k] = la[i];
			i++;
		}
		else {
			a[k] = ra[j];
			j++;
		}
		k++;
	}
	while (i < nl) {
		a[k] = la[i];
		i++;
		k++;
	}
	while (j < nr) {
		a[k] = ra[j];
		j++;
		k++;
	}
	delete[] la;
	delete[] ra;
}

void mergeSortRec(int a[], int l, int r) {
	if (l < r) { // jedino u tom slucaju imamo bar 2 el u podnizu
		int m = (l + r) / 2;
		mergeSortRec(a, l, m);
		mergeSortRec(a, m + 1, r);
		merge(a, l, m, r);
	}
}

void mergeSort(int a[], int n) {
	mergeSortRec(a, 0, n - 1);
}
// Vremenska slozenost: O(n * logn)
// Memorijska slozenost: O(n)

void printArray(int a[], int n) {
	for (int i = 0; i < n; i++) {
		std::cout << a[i];
		std::cout << " ";
	}
	std::cout << std::endl;
}

int main() {
	int n = 6;
	int a[6] = { 6, 5, 12,10,9,1 };

	std::cout << "Pre sortiranja:" << std::endl;
	printArray(a, n);

	mergeSort(a, n);

	std::cout << "Nakon sortiranja:" << std::endl;
	printArray(a, n);

	return 0;
}

/*
QUICK SORT
-- trazi se pivot el. - najcesce se uzima poslednji el
delimo na dva podniza:
1. svi el koji su manji od pivot el.
2. svi el koji su veci ili jednaki pivot el.
*/