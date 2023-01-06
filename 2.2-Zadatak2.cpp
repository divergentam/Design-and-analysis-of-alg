#include <iostream>

/*
Zadatak 2. Ispitati da li se dati prirodan broj n moze predstaviti kao zbir dva slozena broja.
Trazi se resenje vremenske slozenosti O(n log n).
*/

// Za neki broj n treba da se vidi da li moze da se napise kao n = n_1 + n_2
// Tako da su i n_1 i n_2 slozeni brojevi
// ako uzmemo n_1 kao neki slozen broj onda i n_2 = n - n_1 mora da bude slozen broj
// za n_1 mozemo da uzmemo neki broj iz segmenta od [4, n - 4]
// n2 je tada = n - 4, n - 5, ..., 4 odnosno iz segmenta [n - 4, 4]

bool isPrime(int n) {
	bool prime = (n == 2) || (n > 2 && n % 2 != 0);	
	int candidate = 3;
	while (prime && candidate <= sqrt(n)) {
		if (n % candidate == 0) {
			prime = false;
		}
		else {
			candidate += 2;
		}
	}
	return prime;
}

bool zadatak2a(int n) {
	for (int i = 4; i <= n - 4; i++) {			// prolazimo n - 8 brojeva - odnosno n
		if (!isPrime(i) && !isPrime(n - 1)) {   // svaka od isPrime(n) ima slozenost O(sqrt(n) + sqrt(n)) = O(sqrt(n))
			return true;
		}
	}
	return false;
}
// Vremenska slozenost: O(n * sqrt(n))
// Memoriojska slzoenost: O(1)


bool* eratostenovoSito(int n) {
	bool* e = new bool[n + 1];
	for (int i = 2; i <= n; i++) {
		e[i] = true;
	}
	e[1] = false;
	for (int i = 2; i <= n; i++) {
		if (e[i] == true) {
			int j = 2;
			while (j * i < n) {
				e[i * j] = false;
				j++;
			}
		}
	}
	return e;
}

bool zadatak2b(int n) {
	bool* e = eratostenovoSito(n);
	for (int i = 4; i <= n - 4; i++) {
		if (e[i] == false && e[n - i] == false){
			std::cout << "DA" << std::endl;
			std::cout << "(npr. " <<  i << " + " << n - i << ")" << std::endl;
			return true;
		}
	}
	delete[]e;
	std::cout << "NE" << std::endl;
	return false;
}
// Vremenska slozenost: O(n * log(n) + n) =  O(n *(log(n) + 1)) = O(n* log(n))
// Memoriojska slzoenost: O(1)


int main() {
	zadatak2b(8);
	return 0;
}