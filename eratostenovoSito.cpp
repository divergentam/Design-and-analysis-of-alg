#include <iostream>
#include <vector>

// 4) Naci sve proste brojeve u intervalu [1, n]
// Naivna ideja: Proci kroz sve brojeve 1, 2, 3, ..., n-2, n-1, n
// Za svaki broj i  pozvati f-ju IsPrime(i)
// Vremenska slozenost: 
//    sqrt(1) + sqrt(2) + ... + sqrt(n-1) + sqrt(n)
// <= sqrt(n) + sqrt(n) + ... + sqrt(n) + sqrt(n)
// = n * sqrt(n)
// Vremenska slozenost: O(n * sqrt(n))
// Memorijska slozenost: O(1)

// Bolja ideja: Eratostenovo sito
// 1. Podjemo od broja 1 i precrtamo ga
// 2. Idemo kroz niz i stajemo kod ne precrtanog broja
// 3. Zaokruzimoi taj broj i pproglasimo ga prostim
// 4. Iidemo kroz sve brojeve vece od trenutnog i precrtamo sve one koji su deljivi njim


// Vremenska slozenost : O(n/1 + n/2 + ... + n/(n-1) + n/n) = O(n * (1/1 + 1/2 + ... + n/n)) = O(n * logn)
// Memorijska slozenost: O(n + sqrt(n)) = O(n)
//std::vector<int> eratostenovoSito(int n) {
//	std::vector<int>  primes;
//	bool* a = new bool[n + 1]; // imamo opseg od 0 do n ukljucujuci n - to je ukupno n + 1 brojeva
//	for (int i = 1; i <= n; i++) {
//		a[i] = true;
//	}
//	a[0] = false;
//	a[1] = false;
//	for (int i = 2; i <= n; i++) {
//		if (a[i] == true) {
//			primes.push_back(i);
//			int j = 2;
//			while (i * j <= n) {
//				a[i * j] = false; // ovo su brojevi koji su deljivi sa i 
//				j++;
//			}
//		}
//	}
//	delete[] a;
//	return primes;
//}

// Vremenska slozenost: O(n * log(n))
// Memorijska slozenost: O(n)
 bool* eratostenovoSito(int n) {
	bool* a = new bool[n + 1]; // imamo opseg od 0 do n ukljucujuci n - to je ukupno n + 1 brojeva
	a[1] = false;
	for (int i = 2; i <= n; i++) {
		a[i] = true;
	}
	//a[0] = false;
	for (int i = 2; i <= n; i++) {
		if (a[i] == true) {
			int j = 2;
			while (i * j <= n) {
				a[i * j] = false; // ovo su brojevi koji su deljivi sa i 
				j++;
			}
		}
	}
	return a;
}


int main() {
	bool *a = eratostenovoSito(30);
	for (int i = 1; i <= 30; i++) {
		if (a[i]) {
			std::cout << i << " ";
		}
	}
	return 0;
}