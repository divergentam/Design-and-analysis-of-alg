#include <iostream>

/*
Zadatak 4. Za dati prirodan broj n, naci sve parove prostih brojeva (A, B) za koje je A ≤ B i
A + B je prost broj ne veci od n. Trazi se resenje vremenske slozenosti O(n * log n).
*/

bool* eratostenovoSito(int n) {
	bool* e = new bool[n + 1];
	for (int i = 2; i <= n; i++) {
		e[i] = true;
	}
	e[1] = false;
	for (int i = 2; i <= n; i++) {
		if (e[i] == true) {
			int j = 2;
			while (j * i <= n) {
				e[j * i] = false;
				j++;
			}
		}
	}
	return e;
}

bool isPrime(int n) {
	bool prime = (n == 2) || (n > 2 && n % 2 != 0);
	int candidate = 3;
	while (prime && candidate <= sqrt(n)) {
		if (n % candidate == 0) {
			prime = false;
		}
		else{
			candidate += 2;
		}
	}
	return prime;
}

void zadatak4a(int n)
{
	for (int b = 3; b <= n - 2; b++)
	{
		if (isPrime(b) && isPrime(2 + b))
		{
			std::cout << "(" << 2 << ", " << b << ")" << std::endl;
		}
	}
}

/*
ako je m = A + B prost broj, onda m mora da je neparan broj ili je m = 2, 
a druga mogucnost nam nije bitna. Posto m mora biti neparno, to znaci da je
tacno jedan od A i B paran, a drugi neparan. Recimo da je A paran a B neparan.
Ali i A mora da bude prost, a jedini takav prost broj je 2. Znaci samo za B ostaju
da se provere mogucnosti sto je upravo i resenje zadatka.
*/

void zadatak4b(int n) {
	bool* e = eratostenovoSito(n);
	for (int i = 3; i < n - 2; i++) {
		if (e[i] == true && e[2 + i] == true) // sigurni smo da ako je e[i] prost onda e[2 + i] nije prost
		{
			std::cout << "(" << 2 << ", " << i << ")" << std::endl;
		}
	}
}

int main() {
	int n = 8;
	zadatak4b(n);

	return 0;
}