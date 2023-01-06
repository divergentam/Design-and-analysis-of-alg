#include <iostream>

/*
Zadatak 1. Ispred blagajne je poredjano n ljudi cije su visine h1, h2, . . . hn, redom. Odrediti broj
ljudi koje vidi blagajnik. Blagajnik vidi neku osobu x ukoliko su sve osobe u redu ispred osobe x
nize od osobe x. Trazi se resenje vremenske slozenosti O(n).
*/


// Vremenska slozenost: O(n^2)
// Memorijska slozenost: O(1)
int a(int n, int h[]) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		bool ok = true;
		for (int j = 0; j < i; j++) {
			if (h[j] >= h[i]) {
				ok = false;
			}
		}
		if (ok == true)
			count++;
	}
	return count;
}


// Vremenska slozenost: O(n)
// Memorijska slozenost: O(1)
int b(int n, int h[]) {
	int count = 0;
	int localmax = INT_MIN;
	for (int i = 0; i < n; i++) {
		if (h[i] > localmax) {
			count++;
			localmax = h[i];
		}
	}
	return count;
}

int main(){
	int n = 8;
	int h[8] = { 5, 5, 8, 7, 11, 12, 5, 11 };
	std::cout << "Blagajnik vidi " << a(n, h) << " osoba" << std::endl;
	std::cout << "Blagajnik vidi " << b(n, h) << " osoba" << std::endl;
}

